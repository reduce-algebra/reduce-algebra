
// $destdir/u14.c        Machine generated C code

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



// Code for xread1

static LispObject CC_xread1(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0227, v0228, v0229;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for xread1");
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
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-7] = v0000;
// end of prologue
    stack[-8] = nil;
    stack[-6] = nil;
    stack[-5] = nil;
    stack[-4] = nil;
    stack[-2] = nil;
    stack[-1] = nil;
    v0227 = qvalue(elt(env, 1)); // commentlist!*
    if (v0227 == nil) goto v0230;
    v0227 = qvalue(elt(env, 1)); // commentlist!*
    stack[-1] = v0227;
    v0227 = qvalue(elt(env, 2)); // nil
    qvalue(elt(env, 1)) = v0227; // commentlist!*
    goto v0230;

v0230:
    v0227 = qvalue(elt(env, 3)); // cursym!*
    stack[-3] = v0227;
    goto v0231;

v0231:
    v0227 = stack[-3];
    if (!(symbolp(v0227))) goto v0232;
    v0228 = stack[-3];
    v0227 = elt(env, 4); // !*lpar!*
    if (v0228 == v0227) goto v0233;
    v0228 = stack[-3];
    v0227 = elt(env, 5); // !*rpar!*
    if (v0228 == v0227) goto v0234;
    v0227 = stack[-3];
    if (!symbolp(v0227)) v0227 = nil;
    else { v0227 = qfastgets(v0227);
           if (v0227 != nil) { v0227 = elt(v0227, 23); // infix
#ifdef RECORD_GET
             if (v0227 != SPID_NOPROP)
                record_get(elt(fastget_names, 23), 1);
             else record_get(elt(fastget_names, 23), 0),
                v0227 = nil; }
           else record_get(elt(fastget_names, 23), 0); }
#else
             if (v0227 == SPID_NOPROP) v0227 = nil; }}
#endif
    stack[-4] = v0227;
    if (!(v0227 == nil)) goto v0235;
    v0227 = stack[-3];
    if (!symbolp(v0227)) v0227 = nil;
    else { v0227 = qfastgets(v0227);
           if (v0227 != nil) { v0227 = elt(v0227, 55); // delim
#ifdef RECORD_GET
             if (v0227 == SPID_NOPROP)
                record_get(elt(fastget_names, 55), 0),
                v0227 = nil;
             else record_get(elt(fastget_names, 55), 1),
                v0227 = lisp_true; }
           else record_get(elt(fastget_names, 55), 0); }
#else
             if (v0227 == SPID_NOPROP) v0227 = nil; else v0227 = lisp_true; }}
#endif
    if (v0227 == nil) goto v0236;
    v0228 = qvalue(elt(env, 3)); // cursym!*
    v0227 = elt(env, 42); // !*semicol!*
    if (v0228 == v0227) goto v0237;
    fn = elt(env, 50); // eolcheck
    v0227 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    goto v0237;

v0237:
    v0228 = stack[-3];
    v0227 = elt(env, 43); // !*colon!*
    if (v0228 == v0227) goto v0239;
    v0227 = qvalue(elt(env, 2)); // nil
    goto v0240;

v0240:
    if (!(v0227 == nil)) goto v0241;
    v0228 = stack[-3];
    v0227 = elt(env, 46); // nodel
    v0227 = Lflagp(nil, v0228, v0227);
    env = stack[-9];
    if (v0227 == nil) goto v0242;
    v0227 = stack[-7];
    if (v0227 == nil) goto v0243;
    v0228 = stack[-7];
    v0227 = elt(env, 23); // group
    if (v0228 == v0227) goto v0244;
    v0227 = qvalue(elt(env, 2)); // nil
    goto v0245;

v0245:
    if (!(v0227 == nil)) goto v0241;
    v0227 = stack[-7];
    if (!(symbolp(v0227))) goto v0246;
    v0228 = stack[-7];
    v0227 = elt(env, 18); // paren
    if (v0228 == v0227) goto v0247;
    v0228 = stack[-7];
    v0227 = elt(env, 17); // struct
    v0227 = Lflagp(nil, v0228, v0227);
    env = stack[-9];
    goto v0248;

v0248:
    if (v0227 == nil) goto v0246;
    v0228 = elt(env, 48); // "Too few right parentheses"
    v0227 = qvalue(elt(env, 2)); // nil
    fn = elt(env, 51); // symerr
    v0227 = (*qfn2(fn))(qenv(fn), v0228, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    goto v0246;

v0246:
    v0227 = stack[-4];
    if (v0227 == nil) goto v0249;
    v0228 = elt(env, 21); // "Improper delimiter"
    v0227 = qvalue(elt(env, 2)); // nil
    fn = elt(env, 51); // symerr
    v0227 = (*qfn2(fn))(qenv(fn), v0228, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    goto v0250;

v0250:
    v0227 = (LispObject)1; // 0
    stack[-4] = v0227;
    goto v0251;

v0251:
    v0227 = stack[-6];
    if (!(v0227 == nil)) goto v0252;
    v0228 = elt(env, 21); // "Improper delimiter"
    v0227 = qvalue(elt(env, 2)); // nil
    fn = elt(env, 51); // symerr
    v0227 = (*qfn2(fn))(qenv(fn), v0228, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    goto v0252;

v0252:
    v0227 = stack[-6];
    v0228 = qcar(v0227);
    v0227 = stack[-3];
    fn = elt(env, 52); // mkvar
    v0227 = (*qfn2(fn))(qenv(fn), v0228, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    stack[0] = v0227;
    goto v0253;

v0253:
    v0227 = stack[-6];
    v0227 = qcdr(v0227);
    stack[-6] = v0227;
    v0227 = stack[-6];
    if (v0227 == nil) goto v0254;
    v0227 = stack[-6];
    v0227 = qcar(v0227);
    if (!consp(v0227)) goto v0255;
    v0227 = qvalue(elt(env, 2)); // nil
    goto v0256;

v0256:
    if (v0227 == nil) goto v0257;
    v0228 = elt(env, 28); // "Missing operator"
    v0227 = qvalue(elt(env, 2)); // nil
    fn = elt(env, 51); // symerr
    v0227 = (*qfn2(fn))(qenv(fn), v0228, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    goto v0257;

v0257:
    v0227 = stack[-6];
    v0228 = qcar(v0227);
    v0227 = stack[0];
    v0227 = list2(v0228, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    stack[0] = v0227;
    goto v0253;

v0255:
    v0227 = stack[-6];
    v0227 = qcar(v0227);
    v0227 = Lsymbolp(nil, v0227);
    env = stack[-9];
    v0227 = (v0227 == nil ? lisp_true : nil);
    goto v0256;

v0254:
    v0228 = stack[0];
    v0227 = stack[-8];
    v0227 = cons(v0228, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    stack[-8] = v0227;
    goto v0258;

v0258:
    v0227 = stack[-5];
    if (v0227 == nil) goto v0259;
    v0227 = stack[-8];
    if (v0227 == nil) goto v0260;
    v0227 = stack[-8];
    v0228 = qcdr(v0227);
    v0227 = elt(env, 27); // !*!*un!*!*
    if (!consp(v0228)) goto v0261;
    v0228 = qcar(v0228);
    if (!(v0228 == v0227)) goto v0261;
    v0227 = stack[-5];
    v0227 = qcdr(v0227);
    if (v0227 == nil) goto v0262;
    v0228 = stack[-4];
    v0227 = stack[-5];
    v0227 = qcar(v0227);
    v0227 = qcar(v0227);
    v0227 = (LispObject)geq2(v0228, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    v0227 = v0227 ? lisp_true : nil;
    env = stack[-9];
    if (v0227 == nil) goto v0263;
    v0228 = stack[-4];
    v0227 = stack[-5];
    v0227 = qcdr(v0227);
    v0227 = qcar(v0227);
    v0227 = qcar(v0227);
    v0227 = (LispObject)lesseq2(v0228, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    v0227 = v0227 ? lisp_true : nil;
    env = stack[-9];
    goto v0264;

v0264:
    if (v0227 == nil) goto v0260;
    v0228 = elt(env, 29); // "Please use parentheses around use of the unary operator"
    v0227 = qvalue(elt(env, 2)); // nil
    fn = elt(env, 51); // symerr
    v0227 = (*qfn2(fn))(qenv(fn), v0228, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    goto v0265;

v0265:
    v0229 = stack[-4];
    v0228 = stack[-3];
    v0227 = stack[-5];
    v0227 = acons(v0229, v0228, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    stack[-5] = v0227;
    v0228 = stack[-3];
    v0227 = elt(env, 19); // !*comma!*
    if (!(v0228 == v0227)) goto v0266;
    v0227 = stack[-5];
    v0227 = qcdr(v0227);
    if (!(v0227 == nil)) goto v0267;
    v0227 = stack[-7];
    if (v0227 == nil) goto v0268;
    v0228 = stack[-7];
    v0227 = elt(env, 31); // (lambda paren)
    v0227 = Lmemq(nil, v0228, v0227);
    if (!(v0227 == nil)) goto v0269;
    v0228 = stack[-7];
    v0227 = elt(env, 17); // struct
    v0227 = Lflagp(nil, v0228, v0227);
    env = stack[-9];
    goto v0269;

v0269:
    if (!(v0227 == nil)) goto v0267;

v0270:
    v0227 = stack[-8];
    v0227 = qcdr(v0227);
    if (v0227 == nil) goto v0271;
    v0227 = elt(env, 49); // "Please send hearn@rand.org your program!!"
    v0227 = Lprint(nil, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    v0228 = elt(env, 21); // "Improper delimiter"
    v0227 = qvalue(elt(env, 2)); // nil
    fn = elt(env, 51); // symerr
    v0227 = (*qfn2(fn))(qenv(fn), v0228, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    v0227 = nil;
    { popv(10); return onevalue(v0227); }

v0271:
    v0227 = stack[-8];
    v0228 = qcar(v0227);
    v0227 = stack[-1];
    {
        popv(10);
        fn = elt(env, 53); // xcomment
        return (*qfn2(fn))(qenv(fn), v0228, v0227);
    }

v0267:
    fn = elt(env, 54); // scan
    v0227 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    stack[-3] = v0227;
    goto v0231;

v0268:
    v0227 = qvalue(elt(env, 22)); // t
    goto v0269;

v0266:
    v0227 = stack[-2];
    stack[-3] = v0227;
    goto v0231;

v0260:
    v0228 = stack[-4];
    v0227 = stack[-5];
    v0227 = qcar(v0227);
    v0227 = qcar(v0227);
    v0227 = (LispObject)lessp2(v0228, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    v0227 = v0227 ? lisp_true : nil;
    env = stack[-9];
    if (!(v0227 == nil)) goto v0272;
    v0228 = stack[-4];
    v0227 = stack[-5];
    v0227 = qcar(v0227);
    v0227 = qcar(v0227);
    if (equal(v0228, v0227)) goto v0273;
    v0227 = qvalue(elt(env, 2)); // nil
    goto v0274;

v0274:
    if (v0227 == nil) goto v0265;
    else goto v0272;

v0272:
    v0227 = stack[-8];
    v0227 = qcdr(v0227);
    v0228 = qcar(v0227);
    v0227 = elt(env, 32); // not
    if (!consp(v0228)) goto v0275;
    v0228 = qcar(v0228);
    if (!(v0228 == v0227)) goto v0275;
    v0227 = stack[-5];
    v0227 = qcar(v0227);
    v0228 = qcar(v0227);
    v0227 = elt(env, 33); // member
    if (!symbolp(v0227)) v0227 = nil;
    else { v0227 = qfastgets(v0227);
           if (v0227 != nil) { v0227 = elt(v0227, 23); // infix
#ifdef RECORD_GET
             if (v0227 != SPID_NOPROP)
                record_get(elt(fastget_names, 23), 1);
             else record_get(elt(fastget_names, 23), 0),
                v0227 = nil; }
           else record_get(elt(fastget_names, 23), 0); }
#else
             if (v0227 == SPID_NOPROP) v0227 = nil; }}
#endif
    v0227 = (LispObject)geq2(v0228, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    v0227 = v0227 ? lisp_true : nil;
    env = stack[-9];
    goto v0276;

v0276:
    if (v0227 == nil) goto v0277;
    v0228 = elt(env, 34); // "NOT"
    v0227 = elt(env, 35); // "infix operator"
    fn = elt(env, 55); // typerr
    v0227 = (*qfn2(fn))(qenv(fn), v0228, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    goto v0277;

v0277:
    v0227 = stack[-8];
    v0227 = qcdr(v0227);
    v0228 = qcar(v0227);
    v0227 = elt(env, 27); // !*!*un!*!*
    if (v0228 == v0227) goto v0278;
    v0227 = stack[-5];
    v0227 = qcar(v0227);
    stack[0] = qcdr(v0227);
    v0227 = stack[-8];
    v0228 = qcar(v0227);
    v0227 = stack[-5];
    v0227 = qcar(v0227);
    v0227 = qcdr(v0227);
    if (!consp(v0228)) goto v0279;
    v0228 = qcar(v0228);
    if (!(v0228 == v0227)) goto v0279;
    v0227 = stack[-5];
    v0227 = qcar(v0227);
    v0227 = qcdr(v0227);
    if (!symbolp(v0227)) v0227 = nil;
    else { v0227 = qfastgets(v0227);
           if (v0227 != nil) { v0227 = elt(v0227, 35); // nary
#ifdef RECORD_GET
             if (v0227 == SPID_NOPROP)
                record_get(elt(fastget_names, 35), 0),
                v0227 = nil;
             else record_get(elt(fastget_names, 35), 1),
                v0227 = lisp_true; }
           else record_get(elt(fastget_names, 35), 0); }
#else
             if (v0227 == SPID_NOPROP) v0227 = nil; else v0227 = lisp_true; }}
#endif
    goto v0280;

v0280:
    if (v0227 == nil) goto v0281;
    v0227 = stack[-8];
    v0227 = qcdr(v0227);
    v0228 = qcar(v0227);
    v0227 = stack[-8];
    v0227 = qcar(v0227);
    v0227 = qcdr(v0227);
    v0227 = cons(v0228, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    goto v0282;

v0282:
    v0227 = cons(stack[0], v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    stack[0] = v0227;
    goto v0283;

v0283:
    v0227 = stack[-5];
    v0227 = qcdr(v0227);
    stack[-5] = v0227;
    v0228 = stack[0];
    v0227 = stack[-8];
    v0227 = qcdr(v0227);
    v0227 = qcdr(v0227);
    v0227 = cons(v0228, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    stack[-8] = v0227;
    goto v0258;

v0281:
    v0227 = stack[-8];
    v0227 = qcdr(v0227);
    v0228 = qcar(v0227);
    v0227 = stack[-8];
    v0227 = qcar(v0227);
    v0227 = list2(v0228, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    goto v0282;

v0279:
    v0227 = qvalue(elt(env, 2)); // nil
    goto v0280;

v0278:
    v0227 = stack[-8];
    v0228 = qcar(v0227);
    v0227 = elt(env, 27); // !*!*un!*!*
    if (v0228 == v0227) goto v0265;
    v0227 = stack[-5];
    v0227 = qcar(v0227);
    v0228 = qcdr(v0227);
    v0227 = stack[-8];
    v0227 = qcar(v0227);
    v0227 = list2(v0228, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    stack[0] = v0227;
    goto v0283;

v0275:
    v0227 = qvalue(elt(env, 2)); // nil
    goto v0276;

v0273:
    v0228 = stack[-3];
    v0227 = stack[-5];
    v0227 = qcar(v0227);
    v0227 = qcdr(v0227);
    if (v0228 == v0227) goto v0284;
    v0227 = qvalue(elt(env, 2)); // nil
    goto v0285;

v0285:
    if (v0227 == nil) goto v0286;
    v0227 = qvalue(elt(env, 22)); // t
    goto v0274;

v0286:
    v0227 = stack[-5];
    v0227 = qcar(v0227);
    v0227 = qcdr(v0227);
    if (!symbolp(v0227)) v0227 = nil;
    else { v0227 = qfastgets(v0227);
           if (v0227 != nil) { v0227 = elt(v0227, 49); // alt
#ifdef RECORD_GET
             if (v0227 != SPID_NOPROP)
                record_get(elt(fastget_names, 49), 1);
             else record_get(elt(fastget_names, 49), 0),
                v0227 = nil; }
           else record_get(elt(fastget_names, 49), 0); }
#else
             if (v0227 == SPID_NOPROP) v0227 = nil; }}
#endif
    goto v0274;

v0284:
    v0227 = stack[-3];
    if (!symbolp(v0227)) v0227 = nil;
    else { v0227 = qfastgets(v0227);
           if (v0227 != nil) { v0227 = elt(v0227, 35); // nary
#ifdef RECORD_GET
             if (v0227 == SPID_NOPROP)
                record_get(elt(fastget_names, 35), 0),
                v0227 = nil;
             else record_get(elt(fastget_names, 35), 1),
                v0227 = lisp_true; }
           else record_get(elt(fastget_names, 35), 0); }
#else
             if (v0227 == SPID_NOPROP) v0227 = nil; else v0227 = lisp_true; }}
#endif
    if (v0227 == nil) goto v0287;
    v0227 = qvalue(elt(env, 2)); // nil
    goto v0285;

v0287:
    v0228 = stack[-3];
    v0227 = elt(env, 30); // right
    v0227 = Lflagp(nil, v0228, v0227);
    env = stack[-9];
    v0227 = (v0227 == nil ? lisp_true : nil);
    goto v0285;

v0263:
    v0227 = qvalue(elt(env, 2)); // nil
    goto v0264;

v0262:
    v0227 = qvalue(elt(env, 2)); // nil
    goto v0264;

v0261:
    v0227 = qvalue(elt(env, 2)); // nil
    goto v0264;

v0259:
    v0228 = stack[-4];
    v0227 = (LispObject)1; // 0
    if (v0228 == v0227) goto v0270;
    else goto v0265;

v0249:
    v0227 = stack[-8];
    if (v0227 == nil) goto v0288;
    v0227 = qvalue(elt(env, 2)); // nil
    goto v0289;

v0289:
    if (v0227 == nil) goto v0250;
    v0228 = qvalue(elt(env, 2)); // nil
    v0227 = stack[-1];
    {
        popv(10);
        fn = elt(env, 53); // xcomment
        return (*qfn2(fn))(qenv(fn), v0228, v0227);
    }

v0288:
    v0227 = stack[-6];
    if (v0227 == nil) goto v0290;
    v0227 = qvalue(elt(env, 2)); // nil
    goto v0289;

v0290:
    v0227 = stack[-5];
    v0227 = (v0227 == nil ? lisp_true : nil);
    goto v0289;

v0247:
    v0227 = qvalue(elt(env, 22)); // t
    goto v0248;

v0241:
    v0228 = elt(env, 21); // "Improper delimiter"
    v0227 = qvalue(elt(env, 2)); // nil
    fn = elt(env, 51); // symerr
    v0227 = (*qfn2(fn))(qenv(fn), v0228, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    goto v0246;

v0244:
    v0228 = stack[-3];
    v0227 = elt(env, 47); // (!*rsqbkt!* !*rcbkt!* !*rsqb!*)
    v0227 = Lmemq(nil, v0228, v0227);
    v0227 = (v0227 == nil ? lisp_true : nil);
    goto v0245;

v0243:
    v0227 = qvalue(elt(env, 22)); // t
    goto v0245;

v0242:
    v0227 = qvalue(elt(env, 2)); // nil
    goto v0245;

v0239:
    v0228 = stack[-7];
    v0227 = elt(env, 44); // for
    if (v0228 == v0227) goto v0291;
    v0227 = qvalue(elt(env, 45)); // !*blockp
    if (v0227 == nil) goto v0292;
    v0227 = stack[-6];
    if (v0227 == nil) goto v0293;
    v0227 = stack[-6];
    v0227 = qcar(v0227);
    if (!consp(v0227)) goto v0294;
    v0227 = qvalue(elt(env, 22)); // t
    goto v0240;

v0294:
    v0227 = stack[-6];
    v0227 = qcdr(v0227);
    goto v0240;

v0293:
    v0227 = qvalue(elt(env, 22)); // t
    goto v0240;

v0292:
    v0227 = qvalue(elt(env, 22)); // t
    goto v0240;

v0291:
    v0227 = qvalue(elt(env, 2)); // nil
    goto v0240;

v0236:
    v0227 = stack[-3];
    if (!symbolp(v0227)) v0227 = nil;
    else { v0227 = qfastgets(v0227);
           if (v0227 != nil) { v0227 = elt(v0227, 36); // stat
#ifdef RECORD_GET
             if (v0227 != SPID_NOPROP)
                record_get(elt(fastget_names, 36), 1);
             else record_get(elt(fastget_names, 36), 0),
                v0227 = nil; }
           else record_get(elt(fastget_names, 36), 0); }
#else
             if (v0227 == SPID_NOPROP) v0227 = nil; }}
#endif
    stack[-4] = v0227;
    if (v0227 == nil) goto v0295;
    v0228 = stack[-4];
    v0227 = elt(env, 36); // endstat
    if (v0228 == v0227) goto v0296;
    fn = elt(env, 50); // eolcheck
    v0227 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    goto v0296;

v0296:
    v0228 = stack[-3];
    v0227 = elt(env, 37); // go
    v0227 = Lflagp(nil, v0228, v0227);
    env = stack[-9];
    if (v0227 == nil) goto v0297;
    v0227 = qvalue(elt(env, 22)); // t
    goto v0298;

v0298:
    if (v0227 == nil) goto v0232;
    v0228 = stack[-3];
    v0227 = elt(env, 40); // procedure
    if (v0228 == v0227) goto v0299;
    v0227 = qvalue(elt(env, 2)); // nil
    goto v0300;

v0300:
    if (v0227 == nil) goto v0301;
    v0227 = stack[-6];
    if (v0227 == nil) goto v0302;
    v0227 = stack[-6];
    v0227 = qcdr(v0227);
    if (!(v0227 == nil)) goto v0303;
    v0227 = qvalue(elt(env, 6)); // !*reduce4
    if (!(v0227 == nil)) goto v0303;
    v0227 = stack[-6];
    v0227 = qcar(v0227);
    fn = elt(env, 56); // procstat1
    v0227 = (*qfn1(fn))(qenv(fn), v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    v0227 = ncons(v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    stack[-6] = v0227;
    goto v0304;

v0304:
    v0227 = qvalue(elt(env, 2)); // nil
    stack[-4] = v0227;
    goto v0230;

v0303:
    v0228 = elt(env, 41); // "proc form"
    v0227 = qvalue(elt(env, 2)); // nil
    fn = elt(env, 51); // symerr
    v0227 = (*qfn2(fn))(qenv(fn), v0228, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    goto v0304;

v0302:
    v0227 = qvalue(elt(env, 2)); // nil
    fn = elt(env, 56); // procstat1
    v0227 = (*qfn1(fn))(qenv(fn), v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    v0227 = ncons(v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    stack[-6] = v0227;
    goto v0304;

v0301:
    v0228 = stack[-4];
    v0227 = qvalue(elt(env, 2)); // nil
    fn = elt(env, 57); // lispapply
    v0228 = (*qfn2(fn))(qenv(fn), v0228, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    v0227 = stack[-6];
    v0227 = cons(v0228, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    stack[-6] = v0227;
    goto v0304;

v0299:
    v0227 = qvalue(elt(env, 6)); // !*reduce4
    goto v0300;

v0232:
    v0227 = qvalue(elt(env, 2)); // nil
    stack[-4] = v0227;
    goto v0305;

v0305:
    v0228 = stack[-3];
    v0227 = stack[-6];
    v0227 = cons(v0228, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    stack[-6] = v0227;
    v0227 = stack[-3];
    fn = elt(env, 58); // toknump
    v0227 = (*qfn1(fn))(qenv(fn), v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    if (v0227 == nil) goto v0306;
    v0228 = stack[-2];
    v0227 = qvalue(elt(env, 9)); // !$eol!$
    if (v0228 == v0227) goto v0307;
    v0227 = qvalue(elt(env, 10)); // nxtsym!*
    fn = elt(env, 59); // chknewnam
    v0227 = (*qfn1(fn))(qenv(fn), v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    stack[-2] = v0227;
    if (symbolp(v0227)) goto v0308;
    v0227 = qvalue(elt(env, 2)); // nil
    goto v0309;

v0309:
    if (v0227 == nil) goto v0306;
    v0227 = elt(env, 13); // times
    qvalue(elt(env, 3)) = v0227; // cursym!*
    v0227 = qvalue(elt(env, 2)); // nil
    qvalue(elt(env, 14)) = v0227; // curescaped!*
    goto v0230;

v0306:
    v0228 = stack[-7];
    v0227 = elt(env, 15); // proc
    if (v0228 == v0227) goto v0310;
    v0227 = qvalue(elt(env, 2)); // nil
    goto v0311;

v0311:
    if (v0227 == nil) goto v0267;
    v0228 = elt(env, 16); // "Syntax error in procedure header"
    v0227 = qvalue(elt(env, 2)); // nil
    fn = elt(env, 51); // symerr
    v0227 = (*qfn2(fn))(qenv(fn), v0228, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    goto v0267;

v0310:
    v0227 = stack[-6];
    v0228 = Llength(nil, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    v0227 = (LispObject)33; // 2
    v0227 = (LispObject)greaterp2(v0228, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    v0227 = v0227 ? lisp_true : nil;
    env = stack[-9];
    goto v0311;

v0308:
    v0227 = stack[-2];
    if (!symbolp(v0227)) v0227 = nil;
    else { v0227 = qfastgets(v0227);
           if (v0227 != nil) { v0227 = elt(v0227, 55); // delim
#ifdef RECORD_GET
             if (v0227 == SPID_NOPROP)
                record_get(elt(fastget_names, 55), 0),
                v0227 = nil;
             else record_get(elt(fastget_names, 55), 1),
                v0227 = lisp_true; }
           else record_get(elt(fastget_names, 55), 0); }
#else
             if (v0227 == SPID_NOPROP) v0227 = nil; else v0227 = lisp_true; }}
#endif
    if (v0227 == nil) goto v0312;
    v0227 = qvalue(elt(env, 2)); // nil
    goto v0309;

v0312:
    v0227 = stack[-2];
    if (!symbolp(v0227)) v0227 = nil;
    else { v0227 = qfastgets(v0227);
           if (v0227 != nil) { v0227 = elt(v0227, 11); // switch!*
#ifdef RECORD_GET
             if (v0227 != SPID_NOPROP)
                record_get(elt(fastget_names, 11), 1);
             else record_get(elt(fastget_names, 11), 0),
                v0227 = nil; }
           else record_get(elt(fastget_names, 11), 0); }
#else
             if (v0227 == SPID_NOPROP) v0227 = nil; }}
#endif
    if (v0227 == nil) goto v0313;
    v0228 = stack[-2];
    v0227 = elt(env, 11); // !(
    if (v0228 == v0227) goto v0313;
    v0227 = qvalue(elt(env, 2)); // nil
    goto v0309;

v0313:
    v0227 = stack[-2];
    if (!symbolp(v0227)) v0227 = nil;
    else { v0227 = qfastgets(v0227);
           if (v0227 != nil) { v0227 = elt(v0227, 23); // infix
#ifdef RECORD_GET
             if (v0227 != SPID_NOPROP)
                record_get(elt(fastget_names, 23), 1);
             else record_get(elt(fastget_names, 23), 0),
                v0227 = nil; }
           else record_get(elt(fastget_names, 23), 0); }
#else
             if (v0227 == SPID_NOPROP) v0227 = nil; }}
#endif
    if (v0227 == nil) goto v0314;
    v0227 = qvalue(elt(env, 2)); // nil
    goto v0309;

v0314:
    v0227 = qvalue(elt(env, 12)); // !*eoldelimp
    if (v0227 == nil) goto v0315;
    v0228 = stack[-2];
    v0227 = qvalue(elt(env, 9)); // !$eol!$
    v0227 = (v0228 == v0227 ? lisp_true : nil);
    goto v0316;

v0316:
    v0227 = (v0227 == nil ? lisp_true : nil);
    goto v0309;

v0315:
    v0227 = qvalue(elt(env, 2)); // nil
    goto v0316;

v0307:
    v0227 = qvalue(elt(env, 2)); // nil
    goto v0309;

v0297:
    v0228 = stack[-7];
    v0227 = elt(env, 15); // proc
    if (v0228 == v0227) goto v0317;
    v0228 = stack[-4];
    v0227 = elt(env, 38); // endstatfn
    v0227 = Lflagp(nil, v0228, v0227);
    env = stack[-9];
    if (v0227 == nil) goto v0318;
    v0227 = qvalue(elt(env, 22)); // t
    goto v0298;

v0318:
    v0227 = qvalue(elt(env, 10)); // nxtsym!*
    fn = elt(env, 60); // delcp
    v0227 = (*qfn1(fn))(qenv(fn), v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    if (v0227 == nil) goto v0319;
    v0227 = qvalue(elt(env, 2)); // nil
    goto v0298;

v0319:
    v0228 = qvalue(elt(env, 10)); // nxtsym!*
    v0227 = elt(env, 39); // !,
    v0227 = (v0228 == v0227 ? lisp_true : nil);
    v0227 = (v0227 == nil ? lisp_true : nil);
    goto v0298;

v0317:
    v0227 = qvalue(elt(env, 2)); // nil
    goto v0298;

v0295:
    v0227 = qvalue(elt(env, 6)); // !*reduce4
    if (v0227 == nil) goto v0320;
    v0227 = qvalue(elt(env, 2)); // nil
    goto v0321;

v0321:
    if (v0227 == nil) goto v0232;
    v0228 = elt(env, 8); // decstat
    v0227 = qvalue(elt(env, 2)); // nil
    fn = elt(env, 57); // lispapply
    v0228 = (*qfn2(fn))(qenv(fn), v0228, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    v0227 = stack[-6];
    v0227 = cons(v0228, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    stack[-6] = v0227;
    goto v0230;

v0320:
    v0228 = stack[-3];
    v0227 = elt(env, 7); // type
    v0227 = Lflagp(nil, v0228, v0227);
    env = stack[-9];
    goto v0321;

v0235:
    fn = elt(env, 50); // eolcheck
    v0227 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    v0228 = stack[-3];
    v0227 = elt(env, 19); // !*comma!*
    if (v0228 == v0227) goto v0322;
    fn = elt(env, 54); // scan
    v0227 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    stack[-2] = v0227;
    if (!consp(v0227)) goto v0323;
    v0227 = qvalue(elt(env, 22)); // t
    goto v0324;

v0324:
    if (!(v0227 == nil)) goto v0325;
    v0228 = stack[-2];
    v0227 = elt(env, 5); // !*rpar!*
    if (v0228 == v0227) goto v0326;
    v0228 = stack[-2];
    v0227 = elt(env, 19); // !*comma!*
    if (v0228 == v0227) goto v0327;
    v0227 = stack[-2];
    if (!symbolp(v0227)) v0227 = nil;
    else { v0227 = qfastgets(v0227);
           if (v0227 != nil) { v0227 = elt(v0227, 55); // delim
#ifdef RECORD_GET
             if (v0227 == SPID_NOPROP)
                record_get(elt(fastget_names, 55), 0),
                v0227 = nil;
             else record_get(elt(fastget_names, 55), 1),
                v0227 = lisp_true; }
           else record_get(elt(fastget_names, 55), 0); }
#else
             if (v0227 == SPID_NOPROP) v0227 = nil; else v0227 = lisp_true; }}
#endif
    goto v0328;

v0328:
    if (v0227 == nil) goto v0329;
    v0227 = stack[-4];
    if (v0227 == nil) goto v0330;
    v0227 = qvalue(elt(env, 2)); // nil
    stack[-4] = v0227;
    goto v0330;

v0330:
    v0228 = stack[-3];
    v0227 = stack[-6];
    v0227 = cons(v0228, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    stack[-6] = v0227;
    goto v0266;

v0329:
    v0228 = stack[-2];
    v0227 = elt(env, 4); // !*lpar!*
    if (v0228 == v0227) goto v0331;
    v0227 = qvalue(elt(env, 2)); // nil
    goto v0332;

v0332:
    if (!(v0227 == nil)) goto v0231;

v0325:
    v0227 = stack[-6];
    if (!(v0227 == nil)) goto v0251;
    v0228 = stack[-3];
    v0227 = elt(env, 25); // unary
    v0227 = get(v0228, v0227);
    env = stack[-9];
    stack[-3] = v0227;
    if (!(v0227 == nil)) goto v0333;
    v0228 = elt(env, 26); // "Redundant operator"
    v0227 = qvalue(elt(env, 2)); // nil
    fn = elt(env, 51); // symerr
    v0227 = (*qfn2(fn))(qenv(fn), v0228, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    goto v0333;

v0333:
    v0228 = elt(env, 27); // !*!*un!*!*
    v0227 = stack[-8];
    v0227 = cons(v0228, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    stack[-8] = v0227;
    goto v0265;

v0331:
    fn = elt(env, 50); // eolcheck
    v0227 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    if (v0227 == nil) goto v0334;
    v0227 = qvalue(elt(env, 2)); // nil
    goto v0332;

v0334:
    v0227 = elt(env, 18); // paren
    fn = elt(env, 61); // xread
    v0227 = (*qfn1(fn))(qenv(fn), v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    stack[-2] = v0227;
    if (!consp(v0227)) goto v0335;
    v0227 = stack[-2];
    v0228 = qcar(v0227);
    v0227 = elt(env, 19); // !*comma!*
    if (v0228 == v0227) goto v0336;
    v0227 = qvalue(elt(env, 2)); // nil
    goto v0332;

v0336:
    v0228 = stack[-3];
    v0227 = stack[-2];
    v0227 = qcdr(v0227);
    v0227 = cons(v0228, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    stack[-3] = v0227;
    goto v0332;

v0335:
    v0227 = qvalue(elt(env, 2)); // nil
    goto v0332;

v0327:
    v0227 = qvalue(elt(env, 22)); // t
    goto v0328;

v0326:
    v0227 = qvalue(elt(env, 22)); // t
    goto v0328;

v0323:
    v0227 = stack[-2];
    fn = elt(env, 58); // toknump
    v0227 = (*qfn1(fn))(qenv(fn), v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    goto v0324;

v0322:
    v0227 = qvalue(elt(env, 22)); // t
    goto v0324;

v0234:
    v0227 = stack[-7];
    if (v0227 == nil) goto v0337;
    v0228 = stack[-7];
    v0227 = elt(env, 23); // group
    if (v0228 == v0227) goto v0338;
    v0228 = stack[-7];
    v0227 = elt(env, 15); // proc
    v0227 = (v0228 == v0227 ? lisp_true : nil);
    goto v0339;

v0339:
    if (v0227 == nil) goto v0246;
    v0228 = elt(env, 24); // "Too many right parentheses"
    v0227 = qvalue(elt(env, 2)); // nil
    fn = elt(env, 51); // symerr
    v0227 = (*qfn2(fn))(qenv(fn), v0228, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    goto v0235;

v0338:
    v0227 = qvalue(elt(env, 22)); // t
    goto v0339;

v0337:
    v0227 = qvalue(elt(env, 22)); // t
    goto v0339;

v0233:
    fn = elt(env, 50); // eolcheck
    v0227 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    v0227 = qvalue(elt(env, 2)); // nil
    stack[-4] = v0227;
    fn = elt(env, 54); // scan
    v0228 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    v0227 = elt(env, 5); // !*rpar!*
    if (v0228 == v0227) goto v0340;
    v0228 = stack[-6];
    v0227 = elt(env, 17); // struct
    v0227 = Lflagpcar(nil, v0228, v0227);
    env = stack[-9];
    if (v0227 == nil) goto v0341;
    v0227 = stack[-6];
    v0227 = qcar(v0227);
    v0227 = CC_xread1(env, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    stack[-3] = v0227;
    goto v0342;

v0342:
    v0228 = stack[-7];
    v0227 = elt(env, 17); // struct
    v0227 = Lflagp(nil, v0228, v0227);
    env = stack[-9];
    if (v0227 == nil) goto v0343;
    v0227 = stack[-3];
    fn = elt(env, 62); // remcomma
    v0227 = (*qfn1(fn))(qenv(fn), v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    stack[-3] = v0227;
    goto v0305;

v0343:
    v0228 = stack[-3];
    v0227 = elt(env, 19); // !*comma!*
    if (!consp(v0228)) goto v0305;
    v0228 = qcar(v0228);
    if (!(v0228 == v0227)) goto v0305;
    v0227 = stack[-6];
    if (v0227 == nil) goto v0344;
    v0227 = stack[-6];
    v0229 = qcar(v0227);
    v0227 = stack[-3];
    v0228 = qcdr(v0227);
    v0227 = stack[-6];
    v0227 = qcdr(v0227);
    v0227 = acons(v0229, v0228, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    stack[-6] = v0227;
    goto v0267;

v0344:
    v0228 = stack[-7];
    v0227 = elt(env, 20); // lambda
    if (v0228 == v0227) goto v0305;
    v0228 = elt(env, 21); // "Improper delimiter"
    v0227 = qvalue(elt(env, 2)); // nil
    fn = elt(env, 51); // symerr
    v0227 = (*qfn2(fn))(qenv(fn), v0228, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    goto v0267;

v0341:
    v0227 = elt(env, 18); // paren
    v0227 = CC_xread1(env, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    stack[-3] = v0227;
    goto v0342;

v0340:
    v0227 = stack[-6];
    if (v0227 == nil) goto v0267;
    v0227 = stack[-6];
    v0227 = qcar(v0227);
    v0228 = ncons(v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    v0227 = stack[-6];
    v0227 = qcdr(v0227);
    v0227 = cons(v0228, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    stack[-6] = v0227;
    goto v0267;
// error exit handlers
v0238:
    popv(10);
    return nil;
}



// Code for qqe_number!-of!-adds!-in!-qterm

static LispObject CC_qqe_numberKofKaddsKinKqterm(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0345, v0346;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qqe_number-of-adds-in-qterm");
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

v0011:
    v0345 = stack[0];
    if (!consp(v0345)) goto v0155;
    v0345 = stack[0];
    fn = elt(env, 2); // qqe_op
    v0346 = (*qfn1(fn))(qenv(fn), v0345);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    env = stack[-1];
    v0345 = elt(env, 1); // (ladd radd)
    v0345 = Lmemq(nil, v0346, v0345);
    if (v0345 == nil) goto v0347;
    v0345 = stack[0];
    fn = elt(env, 3); // qqe_arg2r
    v0345 = (*qfn1(fn))(qenv(fn), v0345);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    env = stack[-1];
    v0345 = CC_qqe_numberKofKaddsKinKqterm(env, v0345);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    popv(2);
    return add1(v0345);

v0347:
    v0345 = stack[0];
    fn = elt(env, 4); // qqe_arg2l
    v0345 = (*qfn1(fn))(qenv(fn), v0345);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    env = stack[-1];
    stack[0] = v0345;
    goto v0011;

v0155:
    v0345 = (LispObject)1; // 0
    { popv(2); return onevalue(v0345); }
// error exit handlers
v0270:
    popv(2);
    return nil;
}



// Code for diffp1

static LispObject CC_diffp1(LispObject env,
                         LispObject v0000, LispObject v0348)
{
    LispObject nil = C_nil;
    LispObject v0226, v0354, v0355;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for diffp1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0348,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0348);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    v0226 = v0348;
    v0355 = v0000;
// end of prologue
    v0354 = v0355;
    v0354 = qcar(v0354);
    if (v0354 == v0226) goto v0340;
    v0226 = qvalue(elt(env, 1)); // nil
    { popv(3); return onevalue(v0226); }

v0340:
    v0226 = v0355;
    v0354 = qcdr(v0226);
    v0226 = (LispObject)17; // 1
    if (v0354 == v0226) goto v0267;
    v0226 = v0355;
    stack[-1] = qcdr(v0226);
    v0226 = v0355;
    stack[0] = qcar(v0226);
    v0226 = v0355;
    v0226 = qcdr(v0226);
    v0226 = sub1(v0226);
    nil = C_nil;
    if (exception_pending()) goto v0356;
    env = stack[-2];
    fn = elt(env, 2); // to
    v0354 = (*qfn2(fn))(qenv(fn), stack[0], v0226);
    nil = C_nil;
    if (exception_pending()) goto v0356;
    env = stack[-2];
    v0226 = (LispObject)17; // 1
    v0226 = cons(v0354, v0226);
    nil = C_nil;
    if (exception_pending()) goto v0356;
    env = stack[-2];
    v0226 = ncons(v0226);
    nil = C_nil;
    if (exception_pending()) goto v0356;
    env = stack[-2];
    {
        LispObject v0357 = stack[-1];
        popv(3);
        fn = elt(env, 3); // multd
        return (*qfn2(fn))(qenv(fn), v0357, v0226);
    }

v0267:
    v0226 = (LispObject)17; // 1
    { popv(3); return onevalue(v0226); }
// error exit handlers
v0356:
    popv(3);
    return nil;
}



// Code for sf_member

static LispObject CC_sf_member(LispObject env,
                         LispObject v0000, LispObject v0348)
{
    LispObject nil = C_nil;
    LispObject v0354, v0355;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sf_member");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0348,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0348);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0348;
    stack[-1] = v0000;
// end of prologue

v0360:
    v0354 = stack[0];
    if (!consp(v0354)) goto v0005;
    v0354 = stack[0];
    v0354 = qcar(v0354);
    v0354 = (consp(v0354) ? nil : lisp_true);
    goto v0071;

v0071:
    if (v0354 == nil) goto v0361;
    v0354 = qvalue(elt(env, 2)); // nil
    { popv(3); return onevalue(v0354); }

v0361:
    v0355 = stack[-1];
    v0354 = stack[0];
    v0354 = qcar(v0354);
    v0354 = qcar(v0354);
    v0354 = qcar(v0354);
    fn = elt(env, 3); // mvar_member
    v0354 = (*qfn2(fn))(qenv(fn), v0355, v0354);
    nil = C_nil;
    if (exception_pending()) goto v0356;
    env = stack[-2];
    if (!(v0354 == nil)) { popv(3); return onevalue(v0354); }
    v0355 = stack[-1];
    v0354 = stack[0];
    v0354 = qcar(v0354);
    v0354 = qcdr(v0354);
    v0354 = CC_sf_member(env, v0355, v0354);
    nil = C_nil;
    if (exception_pending()) goto v0356;
    env = stack[-2];
    if (!(v0354 == nil)) { popv(3); return onevalue(v0354); }
    v0355 = stack[-1];
    v0354 = stack[0];
    v0354 = qcdr(v0354);
    stack[-1] = v0355;
    stack[0] = v0354;
    goto v0360;

v0005:
    v0354 = qvalue(elt(env, 1)); // t
    goto v0071;
// error exit handlers
v0356:
    popv(3);
    return nil;
}



// Code for nary

static LispObject CC_nary(LispObject env,
                         LispObject v0000, LispObject v0348)
{
    LispObject nil = C_nil;
    LispObject v0364, v0365;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for nary");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0348,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0348);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0348;
    stack[-1] = v0000;
// end of prologue
    v0364 = stack[-1];
    v0365 = qcar(v0364);
    v0364 = elt(env, 1); // e
    if (v0365 == v0364) goto v0325;
    v0364 = qvalue(elt(env, 3)); // nil
    goto v0366;

v0366:
    if (v0364 == nil) goto v0358;
    v0364 = stack[-1];
    v0365 = qcdr(v0364);
    v0364 = elt(env, 4); // exp
    fn = elt(env, 10); // unary
    v0364 = (*qfn2(fn))(qenv(fn), v0365, v0364);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    goto v0030;

v0030:
    v0364 = nil;
    { popv(3); return onevalue(v0364); }

v0358:
    v0364 = elt(env, 5); // "<apply>"
    fn = elt(env, 11); // printout
    v0364 = (*qfn1(fn))(qenv(fn), v0364);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-2];
    v0364 = elt(env, 6); // "<"
    v0364 = Lprinc(nil, v0364);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-2];
    v0364 = stack[0];
    v0364 = Lprinc(nil, v0364);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-2];
    v0364 = stack[-1];
    v0365 = qcar(v0364);
    v0364 = elt(env, 7); // "/"
    fn = elt(env, 12); // attributesml
    v0364 = (*qfn2(fn))(qenv(fn), v0365, v0364);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-2];
    v0364 = qvalue(elt(env, 8)); // t
    fn = elt(env, 13); // indent!*
    v0364 = (*qfn1(fn))(qenv(fn), v0364);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-2];
    v0364 = stack[-1];
    v0364 = qcdr(v0364);
    fn = elt(env, 14); // multi_elem
    v0364 = (*qfn1(fn))(qenv(fn), v0364);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-2];
    v0364 = qvalue(elt(env, 3)); // nil
    fn = elt(env, 13); // indent!*
    v0364 = (*qfn1(fn))(qenv(fn), v0364);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-2];
    v0364 = elt(env, 9); // "</apply>"
    fn = elt(env, 11); // printout
    v0364 = (*qfn1(fn))(qenv(fn), v0364);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    goto v0030;

v0325:
    v0365 = stack[0];
    v0364 = elt(env, 2); // power
    v0364 = (v0365 == v0364 ? lisp_true : nil);
    goto v0366;
// error exit handlers
v0236:
    popv(3);
    return nil;
}



// Code for sacar

static LispObject CC_sacar(LispObject env,
                         LispObject v0000, LispObject v0348)
{
    LispObject nil = C_nil;
    LispObject v0226, v0354;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sacar");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0348,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0348);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0348;
    stack[-1] = v0000;
// end of prologue
    v0226 = stack[0];
    if (!consp(v0226)) goto v0015;
    v0354 = stack[-1];
    v0226 = stack[0];
    v0226 = qcar(v0226);
    if (v0354 == v0226) goto v0231;
    v0226 = qvalue(elt(env, 1)); // nil
    goto v0230;

v0230:
    if (v0226 == nil) goto v0362;
    v0226 = stack[0];
    popv(4);
    return ncons(v0226);

v0362:
    v0354 = stack[-1];
    v0226 = stack[0];
    v0226 = qcar(v0226);
    stack[-2] = CC_sacar(env, v0354, v0226);
    nil = C_nil;
    if (exception_pending()) goto v0356;
    env = stack[-3];
    v0354 = stack[-1];
    v0226 = stack[0];
    v0226 = qcdr(v0226);
    v0226 = CC_sacar(env, v0354, v0226);
    nil = C_nil;
    if (exception_pending()) goto v0356;
    {
        LispObject v0357 = stack[-2];
        popv(4);
        return Lappend(nil, v0357, v0226);
    }

v0231:
    v0226 = stack[0];
    v0226 = qcdr(v0226);
    goto v0230;

v0015:
    v0226 = qvalue(elt(env, 1)); // nil
    { popv(4); return onevalue(v0226); }
// error exit handlers
v0356:
    popv(4);
    return nil;
}



// Code for spband_matrix

static LispObject CC_spband_matrix(LispObject env,
                         LispObject v0000, LispObject v0348)
{
    LispObject nil = C_nil;
    LispObject v0399, v0400, v0189;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for spband_matrix");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0348,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0348);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-7] = v0348;
    stack[-8] = v0000;
// end of prologue
    stack[0] = stack[-7];
    v0189 = elt(env, 1); // spm
    v0400 = stack[-7];
    v0399 = stack[-7];
    v0399 = list3(v0189, v0400, v0399);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-10];
    fn = elt(env, 9); // mkempspmat
    v0399 = (*qfn2(fn))(qenv(fn), stack[0], v0399);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-10];
    stack[-9] = v0399;
    v0399 = stack[-7];
    v0399 = integerp(v0399);
    if (!(v0399 == nil)) goto v0402;
    v0399 = elt(env, 2); // "Error in spband_matrix(second argument): should be an integer."
    fn = elt(env, 10); // rederr
    v0399 = (*qfn1(fn))(qenv(fn), v0399);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-10];
    goto v0402;

v0402:
    v0399 = stack[-8];
    if (!consp(v0399)) goto v0351;
    v0399 = stack[-8];
    v0400 = qcar(v0399);
    v0399 = elt(env, 3); // list
    if (v0400 == v0399) goto v0403;
    v0399 = elt(env, 4); // "Error in spband_matrix(first argument): should be single value or list."
    fn = elt(env, 10); // rederr
    v0399 = (*qfn1(fn))(qenv(fn), v0399);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-10];
    goto v0404;

v0404:
    v0399 = stack[-8];
    v0399 = Llength(nil, v0399);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-10];
    stack[-4] = v0399;
    v0399 = stack[-4];
    v0399 = Levenp(nil, v0399);
    env = stack[-10];
    if (v0399 == nil) goto v0405;
    v0399 = elt(env, 5); // "Error in spband matrix(first argument): number of elements must be odd."
    fn = elt(env, 10); // rederr
    v0399 = (*qfn1(fn))(qenv(fn), v0399);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-10];
    goto v0405;

v0405:
    stack[0] = elt(env, 6); // quotient
    v0399 = stack[-4];
    v0400 = add1(v0399);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-10];
    v0399 = (LispObject)33; // 2
    v0399 = list3(stack[0], v0400, v0399);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-10];
    fn = elt(env, 11); // reval
    v0399 = (*qfn1(fn))(qenv(fn), v0399);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-10];
    stack[-3] = v0399;
    v0399 = stack[-3];
    v0399 = integerp(v0399);
    if (v0399 == nil) goto v0406;
    v0399 = stack[-3];
    v0400 = v0399;
    goto v0407;

v0407:
    v0399 = stack[-7];
    v0399 = (LispObject)greaterp2(v0400, v0399);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    v0399 = v0399 ? lisp_true : nil;
    env = stack[-10];
    if (v0399 == nil) goto v0408;
    v0399 = elt(env, 7); // "Error in spband_matrix: too many elements. Band matrix is overflowing."
    fn = elt(env, 10); // rederr
    v0399 = (*qfn1(fn))(qenv(fn), v0399);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-10];
    goto v0408;

v0408:
    v0399 = (LispObject)33; // 2
    stack[-5] = v0399;
    v0399 = (LispObject)17; // 1
    stack[-2] = v0399;
    goto v0409;

v0409:
    v0400 = stack[-7];
    v0399 = stack[-2];
    v0399 = difference2(v0400, v0399);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-10];
    v0399 = Lminusp(nil, v0399);
    env = stack[-10];
    if (!(v0399 == nil)) { LispObject res = stack[-9]; popv(11); return onevalue(res); }
    v0400 = stack[-2];
    v0399 = stack[-3];
    v0399 = (LispObject)lesseq2(v0400, v0399);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    v0399 = v0399 ? lisp_true : nil;
    env = stack[-10];
    if (v0399 == nil) goto v0410;
    v0399 = (LispObject)17; // 1
    stack[-6] = v0399;
    goto v0206;

v0206:
    v0400 = stack[-3];
    v0399 = stack[-2];
    v0400 = difference2(v0400, v0399);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-10];
    v0399 = stack[-6];
    v0400 = plus2(v0400, v0399);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-10];
    v0399 = (LispObject)1; // 0
    v0399 = (LispObject)greaterp2(v0400, v0399);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    v0399 = v0399 ? lisp_true : nil;
    env = stack[-10];
    if (v0399 == nil) goto v0411;
    v0400 = stack[-6];
    v0399 = stack[-7];
    v0399 = (LispObject)lesseq2(v0400, v0399);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    v0399 = v0399 ? lisp_true : nil;
    env = stack[-10];
    if (v0399 == nil) goto v0411;
    v0400 = stack[-3];
    v0399 = stack[-2];
    v0400 = difference2(v0400, v0399);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-10];
    v0399 = stack[-6];
    v0400 = plus2(v0400, v0399);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-10];
    v0399 = stack[-4];
    v0399 = (LispObject)lesseq2(v0400, v0399);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    v0399 = v0399 ? lisp_true : nil;
    env = stack[-10];
    if (v0399 == nil) goto v0411;
    v0189 = stack[-9];
    v0400 = stack[-2];
    v0399 = stack[-6];
    stack[-1] = list3(v0189, v0400, v0399);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-10];
    stack[0] = stack[-8];
    v0400 = stack[-3];
    v0399 = stack[-2];
    v0400 = difference2(v0400, v0399);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-10];
    v0399 = stack[-6];
    v0399 = plus2(v0400, v0399);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-10];
    fn = elt(env, 12); // nth
    v0189 = (*qfn2(fn))(qenv(fn), stack[0], v0399);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-10];
    v0400 = stack[-9];
    v0399 = qvalue(elt(env, 8)); // nil
    fn = elt(env, 13); // letmtr3
    v0399 = (*qfnn(fn))(qenv(fn), 4, stack[-1], v0189, v0400, v0399);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-10];
    v0399 = stack[-6];
    v0399 = add1(v0399);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-10];
    stack[-6] = v0399;
    goto v0206;

v0411:
    v0400 = stack[-2];
    v0399 = stack[-3];
    v0399 = (LispObject)greaterp2(v0400, v0399);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    v0399 = v0399 ? lisp_true : nil;
    env = stack[-10];
    if (v0399 == nil) goto v0191;
    v0399 = stack[-5];
    v0399 = add1(v0399);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-10];
    stack[-5] = v0399;
    goto v0191;

v0191:
    v0399 = stack[-2];
    v0399 = add1(v0399);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-10];
    stack[-2] = v0399;
    goto v0409;

v0410:
    v0399 = stack[-5];
    stack[-6] = v0399;
    goto v0206;

v0406:
    v0399 = stack[-3];
    fn = elt(env, 11); // reval
    v0399 = (*qfn1(fn))(qenv(fn), v0399);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-10];
    v0400 = v0399;
    goto v0407;

v0403:
    v0399 = stack[-8];
    v0399 = qcdr(v0399);
    stack[-8] = v0399;
    goto v0404;

v0351:
    v0399 = stack[-8];
    v0399 = ncons(v0399);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-10];
    stack[-8] = v0399;
    goto v0404;
// error exit handlers
v0401:
    popv(11);
    return nil;
}



// Code for bcplus!?

static LispObject CC_bcplusW(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0325, v0361;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for bcplus?");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0325 = v0000;
// end of prologue
    v0325 = qcar(v0325);
    v0361 = v0325;
    v0325 = v0361;
    if (is_number(v0325)) goto v0267;
    v0325 = qvalue(elt(env, 1)); // nil
    return onevalue(v0325);

v0267:
    v0325 = (LispObject)1; // 0
        return Lgreaterp(nil, v0361, v0325);
}



// Code for list!+list

static LispObject CC_listLlist(LispObject env,
                         LispObject v0000, LispObject v0348)
{
    LispObject nil = C_nil;
    LispObject v0350, v0368;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for list+list");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0348,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0348);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0348;
    stack[-1] = v0000;
// end of prologue
    stack[-2] = nil;
    goto v0030;

v0030:
    v0350 = stack[-1];
    if (v0350 == nil) goto v0005;
    v0350 = stack[-1];
    v0368 = qcar(v0350);
    v0350 = stack[0];
    v0350 = qcar(v0350);
    fn = elt(env, 1); // !:plus
    v0368 = (*qfn2(fn))(qenv(fn), v0368, v0350);
    nil = C_nil;
    if (exception_pending()) goto v0413;
    env = stack[-3];
    v0350 = stack[-2];
    v0350 = cons(v0368, v0350);
    nil = C_nil;
    if (exception_pending()) goto v0413;
    env = stack[-3];
    stack[-2] = v0350;
    v0350 = stack[-1];
    v0350 = qcdr(v0350);
    stack[-1] = v0350;
    v0350 = stack[0];
    v0350 = qcdr(v0350);
    stack[0] = v0350;
    goto v0030;

v0005:
    v0350 = stack[-2];
    {
        popv(4);
        fn = elt(env, 2); // nreverse
        return (*qfn1(fn))(qenv(fn), v0350);
    }
// error exit handlers
v0413:
    popv(4);
    return nil;
}



// Code for physopaeval

static LispObject CC_physopaeval(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0395, v0417, v0418;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for physopaeval");
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
    v0395 = stack[0];
    fn = elt(env, 4); // physopp
    v0395 = (*qfn1(fn))(qenv(fn), v0395);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-1];
    if (v0395 == nil) goto v0071;
    v0395 = stack[0];
    if (!symbolp(v0395)) v0395 = nil;
    else { v0395 = qfastgets(v0395);
           if (v0395 != nil) { v0395 = elt(v0395, 46); // rvalue
#ifdef RECORD_GET
             if (v0395 != SPID_NOPROP)
                record_get(elt(fastget_names, 46), 1);
             else record_get(elt(fastget_names, 46), 0),
                v0395 = nil; }
           else record_get(elt(fastget_names, 46), 0); }
#else
             if (v0395 == SPID_NOPROP) v0395 = nil; }}
#endif
    v0418 = v0395;
    if (v0395 == nil) goto v0232;
    v0395 = v0418;
    v0417 = qcar(v0395);
    v0395 = elt(env, 1); // !*sq
    if (!(v0417 == v0395)) { popv(2); return onevalue(v0418); }
    v0395 = v0418;
    v0395 = qcdr(v0395);
    v0395 = qcar(v0395);
    {
        popv(2);
        fn = elt(env, 5); // !*q2a
        return (*qfn1(fn))(qenv(fn), v0395);
    }

v0232:
    v0395 = stack[0];
    if (!consp(v0395)) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    v0395 = stack[0];
    v0417 = qcar(v0395);
    v0395 = elt(env, 2); // psimpfn
    v0395 = get(v0417, v0395);
    env = stack[-1];
    v0418 = v0395;
    if (v0395 == nil) goto v0358;
    v0417 = v0418;
    v0395 = stack[0];
        popv(2);
        return Lapply1(nil, v0417, v0395);

v0358:
    v0395 = stack[0];
    v0395 = qcar(v0395);
    if (!symbolp(v0395)) v0395 = nil;
    else { v0395 = qfastgets(v0395);
           if (v0395 != nil) { v0395 = elt(v0395, 9); // opmtch
#ifdef RECORD_GET
             if (v0395 != SPID_NOPROP)
                record_get(elt(fastget_names, 9), 1);
             else record_get(elt(fastget_names, 9), 0),
                v0395 = nil; }
           else record_get(elt(fastget_names, 9), 0); }
#else
             if (v0395 == SPID_NOPROP) v0395 = nil; }}
#endif
    if (v0395 == nil) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    v0395 = stack[0];
    fn = elt(env, 6); // opmtch!*
    v0395 = (*qfn1(fn))(qenv(fn), v0395);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    v0418 = v0395;
    if (v0395 == nil) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    else { popv(2); return onevalue(v0418); }

v0071:
    v0395 = stack[0];
    if (!consp(v0395)) goto v0419;
    v0395 = stack[0];
    v0417 = qcar(v0395);
    v0395 = elt(env, 1); // !*sq
    v0395 = (v0417 == v0395 ? lisp_true : nil);
    goto v0295;

v0295:
    if (v0395 == nil) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    v0395 = stack[0];
    v0395 = qcdr(v0395);
    v0395 = qcar(v0395);
    {
        popv(2);
        fn = elt(env, 5); // !*q2a
        return (*qfn1(fn))(qenv(fn), v0395);
    }

v0419:
    v0395 = qvalue(elt(env, 3)); // nil
    goto v0295;
// error exit handlers
v0216:
    popv(2);
    return nil;
}



// Code for copyd

static LispObject CC_copyd(LispObject env,
                         LispObject v0000, LispObject v0348)
{
    LispObject nil = C_nil;
    LispObject v0427, v0428, v0395;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for copyd");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0348,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0348);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0348;
    stack[-2] = v0000;
// end of prologue
    v0427 = stack[-1];
    fn = elt(env, 5); // getd
    v0427 = (*qfn1(fn))(qenv(fn), v0427);
    nil = C_nil;
    if (exception_pending()) goto v0429;
    env = stack[-4];
    v0428 = v0427;
    if (v0428 == nil) goto v0233;
    v0395 = stack[-2];
    v0428 = v0427;
    v0428 = qcar(v0428);
    v0427 = qcdr(v0427);
    fn = elt(env, 6); // putd
    v0427 = (*qfnn(fn))(qenv(fn), 3, v0395, v0428, v0427);
    nil = C_nil;
    if (exception_pending()) goto v0429;
    env = stack[-4];
    v0427 = stack[-1];
    if (!symbolp(v0427)) v0427 = nil;
    else { v0427 = qfastgets(v0427);
           if (v0427 != nil) { v0427 = elt(v0427, 1); // lose
#ifdef RECORD_GET
             if (v0427 == SPID_NOPROP)
                record_get(elt(fastget_names, 1), 0),
                v0427 = nil;
             else record_get(elt(fastget_names, 1), 1),
                v0427 = lisp_true; }
           else record_get(elt(fastget_names, 1), 0); }
#else
             if (v0427 == SPID_NOPROP) v0427 = nil; else v0427 = lisp_true; }}
#endif
    if (v0427 == nil) goto v0405;
    v0427 = stack[-2];
    v0428 = ncons(v0427);
    nil = C_nil;
    if (exception_pending()) goto v0429;
    env = stack[-4];
    v0427 = elt(env, 4); // lose
    v0427 = Lflag(nil, v0428, v0427);
    nil = C_nil;
    if (exception_pending()) goto v0429;
    env = stack[-4];
    goto v0405;

v0405:
    v0428 = stack[-1];
    v0427 = elt(env, 1); // !*savedef
    v0428 = get(v0428, v0427);
    env = stack[-4];
    v0427 = v0428;
    if (v0428 == nil) { LispObject res = stack[-2]; popv(5); return onevalue(res); }
    v0395 = stack[-2];
    v0428 = elt(env, 1); // !*savedef
    v0427 = Lputprop(nil, 3, v0395, v0428, v0427);
    nil = C_nil;
    if (exception_pending()) goto v0429;
    { LispObject res = stack[-2]; popv(5); return onevalue(res); }

v0233:
    v0428 = qvalue(elt(env, 1)); // !*savedef
    v0427 = elt(env, 1); // !*savedef
    if (v0428 == v0427) goto v0405;
    stack[-3] = elt(env, 2); // rlisp
    stack[0] = (LispObject)17; // 1
    v0428 = stack[-1];
    v0427 = elt(env, 3); // "has no definition in copyd"
    v0427 = list2(v0428, v0427);
    nil = C_nil;
    if (exception_pending()) goto v0429;
    env = stack[-4];
    fn = elt(env, 7); // rerror
    v0427 = (*qfnn(fn))(qenv(fn), 3, stack[-3], stack[0], v0427);
    nil = C_nil;
    if (exception_pending()) goto v0429;
    env = stack[-4];
    goto v0405;
// error exit handlers
v0429:
    popv(5);
    return nil;
}



// Code for dpmat_coldegs

static LispObject CC_dpmat_coldegs(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0366, v0370;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dpmat_coldegs");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0366 = v0000;
// end of prologue
    v0370 = v0366;
    v0366 = (LispObject)81; // 5
    {
        fn = elt(env, 1); // nth
        return (*qfn2(fn))(qenv(fn), v0370, v0366);
    }
}



// Code for general!-reduce!-degree!-mod!-p

static LispObject CC_generalKreduceKdegreeKmodKp(LispObject env,
                         LispObject v0000, LispObject v0348)
{
    LispObject nil = C_nil;
    LispObject v0395, v0417, v0418;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for general-reduce-degree-mod-p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0348,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0348);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0348;
    stack[-1] = v0000;
// end of prologue
    v0395 = stack[-1];
    v0395 = qcar(v0395);
    v0395 = qcdr(v0395);
    fn = elt(env, 1); // general!-modular!-minus
    v0417 = (*qfn1(fn))(qenv(fn), v0395);
    nil = C_nil;
    if (exception_pending()) goto v0433;
    env = stack[-3];
    v0395 = stack[0];
    v0395 = qcar(v0395);
    v0395 = qcdr(v0395);
    fn = elt(env, 2); // general!-modular!-quotient
    v0395 = (*qfn2(fn))(qenv(fn), v0417, v0395);
    nil = C_nil;
    if (exception_pending()) goto v0433;
    env = stack[-3];
    stack[-2] = v0395;
    v0395 = stack[-1];
    v0395 = qcar(v0395);
    v0395 = qcar(v0395);
    v0417 = qcdr(v0395);
    v0395 = stack[0];
    v0395 = qcar(v0395);
    v0395 = qcar(v0395);
    v0395 = qcdr(v0395);
    v0395 = (LispObject)(int32_t)((int32_t)v0417 - (int32_t)v0395 + TAG_FIXNUM);
    v0418 = v0395;
    v0417 = v0418;
    v0395 = (LispObject)1; // 0
    if (v0417 == v0395) goto v0369;
    v0395 = stack[-1];
    stack[-1] = qcdr(v0395);
    v0395 = stack[0];
    v0395 = qcar(v0395);
    v0395 = qcar(v0395);
    v0395 = qcar(v0395);
    v0417 = v0418;
    fn = elt(env, 3); // mksp
    v0417 = (*qfn2(fn))(qenv(fn), v0395, v0417);
    nil = C_nil;
    if (exception_pending()) goto v0433;
    env = stack[-3];
    v0395 = stack[-2];
    v0417 = cons(v0417, v0395);
    nil = C_nil;
    if (exception_pending()) goto v0433;
    env = stack[-3];
    v0395 = stack[0];
    v0395 = qcdr(v0395);
    fn = elt(env, 4); // general!-times!-term!-mod!-p
    v0395 = (*qfn2(fn))(qenv(fn), v0417, v0395);
    nil = C_nil;
    if (exception_pending()) goto v0433;
    env = stack[-3];
    {
        LispObject v0406 = stack[-1];
        popv(4);
        fn = elt(env, 5); // general!-plus!-mod!-p
        return (*qfn2(fn))(qenv(fn), v0406, v0395);
    }

v0369:
    v0395 = stack[-1];
    stack[-1] = qcdr(v0395);
    v0395 = stack[0];
    v0417 = qcdr(v0395);
    v0395 = stack[-2];
    fn = elt(env, 6); // general!-multiply!-by!-constant!-mod!-p
    v0395 = (*qfn2(fn))(qenv(fn), v0417, v0395);
    nil = C_nil;
    if (exception_pending()) goto v0433;
    env = stack[-3];
    {
        LispObject v0434 = stack[-1];
        popv(4);
        fn = elt(env, 5); // general!-plus!-mod!-p
        return (*qfn2(fn))(qenv(fn), v0434, v0395);
    }
// error exit handlers
v0433:
    popv(4);
    return nil;
}



// Code for exptcompare

static LispObject CC_exptcompare(LispObject env,
                         LispObject v0000, LispObject v0348)
{
    LispObject nil = C_nil;
    LispObject v0363, v0358, v0413;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for exptcompare");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0358 = v0348;
    v0413 = v0000;
// end of prologue
    v0363 = v0413;
    if (!consp(v0363)) goto v0015;
    v0363 = v0358;
    if (!consp(v0363)) goto v0251;
    v0363 = v0413;
    v0363 = qcar(v0363);
    v0358 = qcar(v0358);
        return Lgreaterp(nil, v0363, v0358);

v0251:
    v0363 = qvalue(elt(env, 2)); // t
    return onevalue(v0363);

v0015:
    v0363 = v0358;
    if (!consp(v0363)) goto v0232;
    v0363 = qvalue(elt(env, 1)); // nil
    return onevalue(v0363);

v0232:
    v0363 = v0413;
        return Lgreaterp(nil, v0363, v0358);
}



// Code for sf2ss

static LispObject CC_sf2ss(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0359, v0425;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sf2ss");
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
    v0359 = stack[-1];
    if (!consp(v0359)) goto v0230;
    v0359 = stack[-1];
    v0359 = qcar(v0359);
    v0359 = (consp(v0359) ? nil : lisp_true);
    goto v0370;

v0370:
    if (!(v0359 == nil)) { LispObject res = stack[-1]; popv(4); return onevalue(res); }
    v0359 = stack[-1];
    fn = elt(env, 2); // searchpl
    v0359 = (*qfn1(fn))(qenv(fn), v0359);
    nil = C_nil;
    if (exception_pending()) goto v0355;
    env = stack[-3];
    stack[-2] = v0359;
    v0359 = stack[-2];
    fn = elt(env, 3); // qsort
    stack[0] = (*qfn1(fn))(qenv(fn), v0359);
    nil = C_nil;
    if (exception_pending()) goto v0355;
    env = stack[-3];
    v0359 = stack[-2];
    v0359 = Llength(nil, v0359);
    nil = C_nil;
    if (exception_pending()) goto v0355;
    env = stack[-3];
    v0359 = cons(stack[0], v0359);
    nil = C_nil;
    if (exception_pending()) goto v0355;
    env = stack[-3];
    stack[0] = v0359;
    v0425 = stack[-1];
    fn = elt(env, 4); // sq2sspl
    v0425 = (*qfn2(fn))(qenv(fn), v0425, v0359);
    nil = C_nil;
    if (exception_pending()) goto v0355;
    env = stack[-3];
    v0359 = (LispObject)17; // 1
    v0359 = list2star(stack[0], v0425, v0359);
    nil = C_nil;
    if (exception_pending()) goto v0355;
    env = stack[-3];
    {
        popv(4);
        fn = elt(env, 5); // lx2xx
        return (*qfn1(fn))(qenv(fn), v0359);
    }

v0230:
    v0359 = qvalue(elt(env, 1)); // t
    goto v0370;
// error exit handlers
v0355:
    popv(4);
    return nil;
}



// Code for ibalp_initwl

static LispObject CC_ibalp_initwl(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0378, v0448;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_initwl");
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
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    v0378 = v0000;
// end of prologue
    stack[-4] = nil;
    stack[-2] = v0378;
    goto v0366;

v0366:
    v0378 = stack[-2];
    if (v0378 == nil) { LispObject res = stack[-4]; popv(7); return onevalue(res); }
    v0378 = stack[-2];
    v0378 = qcar(v0378);
    stack[-1] = v0378;
    v0378 = (LispObject)1; // 0
    stack[-5] = v0378;
    v0378 = stack[-1];
    v0378 = qcar(v0378);
    stack[-3] = v0378;
    goto v0349;

v0349:
    v0448 = stack[-5];
    v0378 = (LispObject)33; // 2
    v0378 = Leqn(nil, v0448, v0378);
    nil = C_nil;
    if (exception_pending()) goto v0449;
    env = stack[-6];
    if (v0378 == nil) goto v0270;
    v0378 = qvalue(elt(env, 1)); // nil
    goto v0246;

v0246:
    if (v0378 == nil) goto v0253;
    v0378 = stack[-1];
    v0378 = qcdr(v0378);
    v0378 = qcdr(v0378);
    v0378 = qcdr(v0378);
    v0378 = qcdr(v0378);
    v0378 = qcdr(v0378);
    stack[0] = qcdr(v0378);
    v0378 = stack[-3];
    v0448 = qcar(v0378);
    v0378 = stack[-1];
    v0378 = qcdr(v0378);
    v0378 = qcdr(v0378);
    v0378 = qcdr(v0378);
    v0378 = qcdr(v0378);
    v0378 = qcdr(v0378);
    v0378 = qcdr(v0378);
    v0378 = qcar(v0378);
    v0378 = cons(v0448, v0378);
    nil = C_nil;
    if (exception_pending()) goto v0449;
    env = stack[-6];
    fn = elt(env, 2); // setcar
    v0378 = (*qfn2(fn))(qenv(fn), stack[0], v0378);
    nil = C_nil;
    if (exception_pending()) goto v0449;
    env = stack[-6];
    v0378 = stack[-3];
    v0378 = qcar(v0378);
    v0378 = qcdr(v0378);
    v0378 = qcdr(v0378);
    v0378 = qcdr(v0378);
    v0378 = qcdr(v0378);
    v0378 = qcdr(v0378);
    v0378 = qcdr(v0378);
    v0378 = qcdr(v0378);
    v0378 = qcdr(v0378);
    v0378 = qcdr(v0378);
    stack[0] = qcdr(v0378);
    v0448 = stack[-1];
    v0378 = stack[-3];
    v0378 = qcar(v0378);
    v0378 = qcdr(v0378);
    v0378 = qcdr(v0378);
    v0378 = qcdr(v0378);
    v0378 = qcdr(v0378);
    v0378 = qcdr(v0378);
    v0378 = qcdr(v0378);
    v0378 = qcdr(v0378);
    v0378 = qcdr(v0378);
    v0378 = qcdr(v0378);
    v0378 = qcdr(v0378);
    v0378 = qcar(v0378);
    v0378 = cons(v0448, v0378);
    nil = C_nil;
    if (exception_pending()) goto v0449;
    env = stack[-6];
    fn = elt(env, 2); // setcar
    v0378 = (*qfn2(fn))(qenv(fn), stack[0], v0378);
    nil = C_nil;
    if (exception_pending()) goto v0449;
    env = stack[-6];
    v0378 = stack[-5];
    v0378 = add1(v0378);
    nil = C_nil;
    if (exception_pending()) goto v0449;
    env = stack[-6];
    stack[-5] = v0378;
    v0378 = stack[-3];
    v0378 = qcdr(v0378);
    stack[-3] = v0378;
    goto v0349;

v0253:
    v0378 = stack[-1];
    v0378 = qcdr(v0378);
    v0378 = qcar(v0378);
    stack[-3] = v0378;
    goto v0450;

v0450:
    v0448 = stack[-5];
    v0378 = (LispObject)33; // 2
    v0378 = Leqn(nil, v0448, v0378);
    nil = C_nil;
    if (exception_pending()) goto v0449;
    env = stack[-6];
    if (v0378 == nil) goto v0451;
    v0378 = qvalue(elt(env, 1)); // nil
    goto v0394;

v0394:
    if (v0378 == nil) goto v0376;
    v0378 = stack[-1];
    v0378 = qcdr(v0378);
    v0378 = qcdr(v0378);
    v0378 = qcdr(v0378);
    v0378 = qcdr(v0378);
    v0378 = qcdr(v0378);
    stack[0] = qcdr(v0378);
    v0378 = stack[-3];
    v0448 = qcar(v0378);
    v0378 = stack[-1];
    v0378 = qcdr(v0378);
    v0378 = qcdr(v0378);
    v0378 = qcdr(v0378);
    v0378 = qcdr(v0378);
    v0378 = qcdr(v0378);
    v0378 = qcdr(v0378);
    v0378 = qcar(v0378);
    v0378 = cons(v0448, v0378);
    nil = C_nil;
    if (exception_pending()) goto v0449;
    env = stack[-6];
    fn = elt(env, 2); // setcar
    v0378 = (*qfn2(fn))(qenv(fn), stack[0], v0378);
    nil = C_nil;
    if (exception_pending()) goto v0449;
    env = stack[-6];
    v0378 = stack[-3];
    v0378 = qcar(v0378);
    v0378 = qcdr(v0378);
    v0378 = qcdr(v0378);
    v0378 = qcdr(v0378);
    v0378 = qcdr(v0378);
    v0378 = qcdr(v0378);
    v0378 = qcdr(v0378);
    v0378 = qcdr(v0378);
    v0378 = qcdr(v0378);
    v0378 = qcdr(v0378);
    stack[0] = qcdr(v0378);
    v0448 = stack[-1];
    v0378 = stack[-3];
    v0378 = qcar(v0378);
    v0378 = qcdr(v0378);
    v0378 = qcdr(v0378);
    v0378 = qcdr(v0378);
    v0378 = qcdr(v0378);
    v0378 = qcdr(v0378);
    v0378 = qcdr(v0378);
    v0378 = qcdr(v0378);
    v0378 = qcdr(v0378);
    v0378 = qcdr(v0378);
    v0378 = qcdr(v0378);
    v0378 = qcar(v0378);
    v0378 = cons(v0448, v0378);
    nil = C_nil;
    if (exception_pending()) goto v0449;
    env = stack[-6];
    fn = elt(env, 2); // setcar
    v0378 = (*qfn2(fn))(qenv(fn), stack[0], v0378);
    nil = C_nil;
    if (exception_pending()) goto v0449;
    env = stack[-6];
    v0378 = stack[-5];
    v0378 = add1(v0378);
    nil = C_nil;
    if (exception_pending()) goto v0449;
    env = stack[-6];
    stack[-5] = v0378;
    v0378 = stack[-3];
    v0378 = qcdr(v0378);
    stack[-3] = v0378;
    goto v0450;

v0376:
    v0448 = stack[-5];
    v0378 = (LispObject)33; // 2
    v0378 = (LispObject)lessp2(v0448, v0378);
    nil = C_nil;
    if (exception_pending()) goto v0449;
    v0378 = v0378 ? lisp_true : nil;
    env = stack[-6];
    if (v0378 == nil) goto v0201;
    v0448 = stack[-1];
    v0378 = stack[-4];
    v0378 = cons(v0448, v0378);
    nil = C_nil;
    if (exception_pending()) goto v0449;
    env = stack[-6];
    stack[-4] = v0378;
    goto v0201;

v0201:
    v0378 = stack[-2];
    v0378 = qcdr(v0378);
    stack[-2] = v0378;
    goto v0366;

v0451:
    v0378 = stack[-3];
    goto v0394;

v0270:
    v0378 = stack[-3];
    goto v0246;
// error exit handlers
v0449:
    popv(7);
    return nil;
}



// Code for ofsf_clnegrel

static LispObject CC_ofsf_clnegrel(LispObject env,
                         LispObject v0000, LispObject v0348)
{
    LispObject nil = C_nil;
    LispObject v0231, v0232;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_clnegrel");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0231 = v0348;
    v0232 = v0000;
// end of prologue
    if (!(v0231 == nil)) return onevalue(v0232);
    v0231 = v0232;
    {
        fn = elt(env, 1); // ofsf_lnegrel
        return (*qfn1(fn))(qenv(fn), v0231);
    }
}



// Code for variablesir

static LispObject CC_variablesir(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0404, v0351;
    LispObject fn;
    argcheck(nargs, 0, "variablesir");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for variablesir");
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
    v0351 = qvalue(elt(env, 1)); // char
    v0404 = elt(env, 2); // (!/ o m b v a r)
    if (equal(v0351, v0404)) goto v0030;
    fn = elt(env, 4); // omvir
    v0404 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0369;
    env = stack[-1];
    stack[0] = v0404;
    fn = elt(env, 5); // lex
    v0404 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0369;
    env = stack[-1];
    v0404 = CC_variablesir(env, 0);
    nil = C_nil;
    if (exception_pending()) goto v0369;
    v0351 = stack[0];
    if (v0351 == nil) goto v0253;
    v0351 = stack[0];
    popv(2);
    return cons(v0351, v0404);

v0253:
    v0351 = stack[0];
        popv(2);
        return Lappend(nil, v0351, v0404);

v0030:
    v0404 = nil;
    { popv(2); return onevalue(v0404); }
// error exit handlers
v0369:
    popv(2);
    return nil;
}



// Code for inshisto

static LispObject CC_inshisto(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0464, v0465, v0443;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for inshisto");
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
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-3] = v0000;
// end of prologue
    stack[0] = qvalue(elt(env, 1)); // codmat
    v0465 = qvalue(elt(env, 2)); // maxvar
    v0464 = stack[-3];
    v0464 = plus2(v0465, v0464);
    nil = C_nil;
    if (exception_pending()) goto v0466;
    env = stack[-5];
    v0465 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0464/(16/CELL)));
    v0464 = (LispObject)1; // 0
    v0464 = *(LispObject *)((char *)v0465 + (CELL-TAG_VECTOR) + ((int32_t)v0464/(16/CELL)));
    if (v0464 == nil) goto v0015;
    v0465 = stack[-3];
    v0464 = (LispObject)1; // 0
    v0464 = (LispObject)geq2(v0465, v0464);
    nil = C_nil;
    if (exception_pending()) goto v0466;
    v0464 = v0464 ? lisp_true : nil;
    env = stack[-5];
    if (v0464 == nil) goto v0015;
    stack[0] = qvalue(elt(env, 3)); // codhisto
    stack[-1] = qvalue(elt(env, 1)); // codmat
    v0465 = qvalue(elt(env, 2)); // maxvar
    v0464 = stack[-3];
    v0464 = plus2(v0465, v0464);
    nil = C_nil;
    if (exception_pending()) goto v0466;
    env = stack[-5];
    v0465 = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v0464/(16/CELL)));
    v0464 = (LispObject)17; // 1
    v0464 = *(LispObject *)((char *)v0465 + (CELL-TAG_VECTOR) + ((int32_t)v0464/(16/CELL)));
    v0465 = qcdr(v0464);
    v0464 = (LispObject)3201; // 200
    fn = elt(env, 6); // min
    v0464 = (*qfn2(fn))(qenv(fn), v0465, v0464);
    nil = C_nil;
    if (exception_pending()) goto v0466;
    env = stack[-5];
    stack[-2] = v0464;
    v0464 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0464/(16/CELL)));
    stack[-4] = v0464;
    if (v0464 == nil) goto v0467;
    stack[0] = qvalue(elt(env, 1)); // codmat
    v0465 = qvalue(elt(env, 2)); // maxvar
    v0464 = stack[-4];
    v0464 = plus2(v0465, v0464);
    nil = C_nil;
    if (exception_pending()) goto v0466;
    env = stack[-5];
    v0465 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0464/(16/CELL)));
    v0464 = (LispObject)113; // 7
    v0465 = *(LispObject *)((char *)v0465 + (CELL-TAG_VECTOR) + ((int32_t)v0464/(16/CELL)));
    v0464 = stack[-3];
    v0464 = Lrplaca(nil, v0465, v0464);
    nil = C_nil;
    if (exception_pending()) goto v0466;
    env = stack[-5];
    goto v0394;

v0394:
    stack[0] = qvalue(elt(env, 1)); // codmat
    v0465 = qvalue(elt(env, 2)); // maxvar
    v0464 = stack[-3];
    v0464 = plus2(v0465, v0464);
    nil = C_nil;
    if (exception_pending()) goto v0466;
    env = stack[-5];
    stack[-1] = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0464/(16/CELL)));
    stack[0] = (LispObject)113; // 7
    v0465 = qvalue(elt(env, 5)); // nil
    v0464 = stack[-4];
    v0464 = cons(v0465, v0464);
    nil = C_nil;
    if (exception_pending()) goto v0466;
    env = stack[-5];
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v0464;
    v0443 = qvalue(elt(env, 3)); // codhisto
    v0465 = stack[-2];
    v0464 = stack[-3];
    *(LispObject *)((char *)v0443 + (CELL-TAG_VECTOR) + ((int32_t)v0465/(16/CELL))) = v0464;
    v0464 = nil;
    { popv(6); return onevalue(v0464); }

v0467:
    v0465 = stack[-2];
    v0464 = qvalue(elt(env, 4)); // headhisto
    v0464 = (LispObject)greaterp2(v0465, v0464);
    nil = C_nil;
    if (exception_pending()) goto v0466;
    v0464 = v0464 ? lisp_true : nil;
    env = stack[-5];
    if (v0464 == nil) goto v0394;
    v0464 = stack[-2];
    qvalue(elt(env, 4)) = v0464; // headhisto
    goto v0394;

v0015:
    v0464 = nil;
    { popv(6); return onevalue(v0464); }
// error exit handlers
v0466:
    popv(6);
    return nil;
}



// Code for onoff

static LispObject CC_onoff(LispObject env,
                         LispObject v0000, LispObject v0348)
{
    LispObject nil = C_nil;
    LispObject v0472, v0202, v0309;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for onoff");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0348,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0348);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-2] = v0348;
    stack[0] = v0000;
// end of prologue
    v0472 = stack[0];
    if (symbolp(v0472)) goto v0366;
    v0202 = stack[0];
    v0472 = elt(env, 1); // "switch"
    fn = elt(env, 10); // typerr
    v0472 = (*qfn2(fn))(qenv(fn), v0202, v0472);
    nil = C_nil;
    if (exception_pending()) goto v0450;
    env = stack[-4];
    goto v0473;

v0473:
    stack[-1] = elt(env, 4); // !*
    v0472 = stack[0];
    v0472 = Lexplodec(nil, v0472);
    nil = C_nil;
    if (exception_pending()) goto v0450;
    env = stack[-4];
    v0472 = cons(stack[-1], v0472);
    nil = C_nil;
    if (exception_pending()) goto v0450;
    env = stack[-4];
    fn = elt(env, 11); // list2string
    v0472 = (*qfn1(fn))(qenv(fn), v0472);
    nil = C_nil;
    if (exception_pending()) goto v0450;
    env = stack[-4];
    v0472 = Lintern(nil, v0472);
    nil = C_nil;
    if (exception_pending()) goto v0450;
    env = stack[-4];
    stack[-3] = v0472;
    v0472 = qvalue(elt(env, 5)); // !*switchcheck
    if (v0472 == nil) goto v0236;
    v0472 = stack[-3];
    fn = elt(env, 12); // lispeval
    v0202 = (*qfn1(fn))(qenv(fn), v0472);
    nil = C_nil;
    if (exception_pending()) goto v0450;
    env = stack[-4];
    v0472 = stack[-2];
    if (!(v0202 == v0472)) goto v0236;
    v0472 = qvalue(elt(env, 6)); // nil
    { popv(5); return onevalue(v0472); }

v0236:
    v0309 = stack[-2];
    v0202 = stack[0];
    v0472 = elt(env, 7); // simpfg
    v0472 = get(v0202, v0472);
    env = stack[-4];
    v0472 = Latsoc(nil, v0309, v0472);
    v0202 = v0472;
    if (v0472 == nil) goto v0425;
    stack[-1] = elt(env, 8); // progn
    v0472 = v0202;
    stack[0] = qcdr(v0472);
    v0472 = qvalue(elt(env, 6)); // nil
    v0472 = ncons(v0472);
    nil = C_nil;
    if (exception_pending()) goto v0450;
    env = stack[-4];
    v0472 = Lappend(nil, stack[0], v0472);
    nil = C_nil;
    if (exception_pending()) goto v0450;
    env = stack[-4];
    v0472 = cons(stack[-1], v0472);
    nil = C_nil;
    if (exception_pending()) goto v0450;
    env = stack[-4];
    fn = elt(env, 12); // lispeval
    v0472 = (*qfn1(fn))(qenv(fn), v0472);
    nil = C_nil;
    if (exception_pending()) goto v0450;
    env = stack[-4];
    goto v0425;

v0425:
    v0472 = stack[-2];
    if (v0472 == nil) goto v0460;
    v0202 = stack[-3];
    v0472 = elt(env, 9); // !*raise
    if (!(v0202 == v0472)) goto v0460;
    v0472 = elt(env, 9); // !*raise
    stack[-3] = v0472;
    goto v0460;

v0460:
    v0202 = stack[-3];
    v0472 = stack[-2];
    v0472 = Lset(nil, v0202, v0472);
    nil = C_nil;
    if (exception_pending()) goto v0450;
    v0472 = nil;
    { popv(5); return onevalue(v0472); }

v0366:
    v0472 = stack[0];
    if (!symbolp(v0472)) v0472 = nil;
    else { v0472 = qfastgets(v0472);
           if (v0472 != nil) { v0472 = elt(v0472, 51); // switch
#ifdef RECORD_GET
             if (v0472 == SPID_NOPROP)
                record_get(elt(fastget_names, 51), 0),
                v0472 = nil;
             else record_get(elt(fastget_names, 51), 1),
                v0472 = lisp_true; }
           else record_get(elt(fastget_names, 51), 0); }
#else
             if (v0472 == SPID_NOPROP) v0472 = nil; else v0472 = lisp_true; }}
#endif
    if (!(v0472 == nil)) goto v0473;
    stack[-3] = elt(env, 2); // rlisp
    stack[-1] = (LispObject)401; // 25
    v0202 = stack[0];
    v0472 = elt(env, 3); // "not defined as switch"
    v0472 = list2(v0202, v0472);
    nil = C_nil;
    if (exception_pending()) goto v0450;
    env = stack[-4];
    fn = elt(env, 13); // rerror
    v0472 = (*qfnn(fn))(qenv(fn), 3, stack[-3], stack[-1], v0472);
    nil = C_nil;
    if (exception_pending()) goto v0450;
    env = stack[-4];
    goto v0473;
// error exit handlers
v0450:
    popv(5);
    return nil;
}



// Code for unchecked_getmatelem

static LispObject CC_unchecked_getmatelem(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0475, v0223, v0224;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for unchecked_getmatelem");
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
    v0475 = stack[-1];
    v0223 = qcar(v0475);
    v0224 = v0223;
    v0475 = elt(env, 1); // mat
    if (!consp(v0223)) goto v0234;
    v0223 = qcar(v0223);
    if (!(v0223 == v0475)) goto v0234;
    v0475 = v0224;
    v0223 = qcdr(v0475);
    v0475 = stack[-1];
    v0475 = qcdr(v0475);
    v0475 = qcar(v0475);
    fn = elt(env, 5); // nth
    v0223 = (*qfn2(fn))(qenv(fn), v0223, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0424;
    env = stack[-3];
    v0475 = stack[-1];
    v0475 = qcdr(v0475);
    v0475 = qcdr(v0475);
    v0475 = qcar(v0475);
    {
        popv(4);
        fn = elt(env, 5); // nth
        return (*qfn2(fn))(qenv(fn), v0223, v0475);
    }

v0234:
    stack[-2] = elt(env, 2); // matrix
    stack[0] = (LispObject)17; // 1
    v0224 = elt(env, 3); // "Matrix"
    v0475 = stack[-1];
    v0223 = qcar(v0475);
    v0475 = elt(env, 4); // "not set"
    v0475 = list3(v0224, v0223, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0424;
    env = stack[-3];
    fn = elt(env, 6); // rerror
    v0475 = (*qfnn(fn))(qenv(fn), 3, stack[-2], stack[0], v0475);
    nil = C_nil;
    if (exception_pending()) goto v0424;
    v0475 = nil;
    { popv(4); return onevalue(v0475); }
// error exit handlers
v0424:
    popv(4);
    return nil;
}



// Code for vdpred

static LispObject CC_vdpred(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0419, v0408;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vdpred");
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
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-3] = v0000;
// end of prologue
    v0419 = stack[-3];
    v0419 = qcdr(v0419);
    v0419 = qcdr(v0419);
    v0419 = qcdr(v0419);
    v0419 = qcar(v0419);
    v0419 = qcdr(v0419);
    v0419 = qcdr(v0419);
    stack[-4] = v0419;
    v0419 = stack[-4];
    if (v0419 == nil) goto v0234;
    stack[-2] = elt(env, 1); // vdp
    v0419 = stack[-4];
    stack[-1] = qcar(v0419);
    v0419 = stack[-4];
    v0419 = qcdr(v0419);
    stack[0] = qcar(v0419);
    v0408 = stack[-4];
    v0419 = qvalue(elt(env, 2)); // nil
    v0419 = list2(v0408, v0419);
    nil = C_nil;
    if (exception_pending()) goto v0407;
    env = stack[-5];
    v0419 = list3star(stack[-2], stack[-1], stack[0], v0419);
    nil = C_nil;
    if (exception_pending()) goto v0407;
    env = stack[-5];
    stack[-4] = v0419;
    v0419 = qvalue(elt(env, 3)); // !*gsugar
    if (v0419 == nil) { LispObject res = stack[-4]; popv(6); return onevalue(res); }
    v0408 = stack[-3];
    v0419 = elt(env, 4); // sugar
    fn = elt(env, 5); // vdpgetprop
    v0408 = (*qfn2(fn))(qenv(fn), v0408, v0419);
    nil = C_nil;
    if (exception_pending()) goto v0407;
    env = stack[-5];
    v0419 = v0408;
    if (v0408 == nil) { LispObject res = stack[-4]; popv(6); return onevalue(res); }
    v0408 = stack[-4];
    fn = elt(env, 6); // gsetsugar
    v0419 = (*qfn2(fn))(qenv(fn), v0408, v0419);
    nil = C_nil;
    if (exception_pending()) goto v0407;
    { LispObject res = stack[-4]; popv(6); return onevalue(res); }

v0234:
    stack[-2] = elt(env, 1); // vdp
    stack[-1] = qvalue(elt(env, 2)); // nil
    v0419 = qvalue(elt(env, 2)); // nil
    stack[0] = ncons(v0419);
    nil = C_nil;
    if (exception_pending()) goto v0407;
    env = stack[-5];
    v0408 = qvalue(elt(env, 2)); // nil
    v0419 = qvalue(elt(env, 2)); // nil
    v0419 = list2(v0408, v0419);
    nil = C_nil;
    if (exception_pending()) goto v0407;
    {
        LispObject v0427 = stack[-2];
        LispObject v0428 = stack[-1];
        LispObject v0395 = stack[0];
        popv(6);
        return list3star(v0427, v0428, v0395, v0419);
    }
// error exit handlers
v0407:
    popv(6);
    return nil;
}



// Code for prinfit

static LispObject CC_prinfit(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0365, v0424, v0476;
    LispObject fn;
    LispObject v0006, v0348, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "prinfit");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0348 = va_arg(aa, LispObject);
    v0006 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for prinfit");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0006,v0348,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0348,v0006);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0006;
    stack[-1] = v0348;
    stack[-2] = v0000;
// end of prologue
    v0365 = qvalue(elt(env, 1)); // !*nat
    if (v0365 == nil) goto v0231;
    v0365 = qvalue(elt(env, 3)); // testing!-width!*
    goto v0230;

v0230:
    if (v0365 == nil) goto v0349;
    v0365 = stack[0];
    if (v0365 == nil) goto v0416;
    v0365 = stack[0];
    fn = elt(env, 4); // oprin
    v0365 = (*qfn1(fn))(qenv(fn), v0365);
    nil = C_nil;
    if (exception_pending()) goto v0414;
    env = stack[-3];
    goto v0416;

v0416:
    v0424 = stack[-2];
    v0365 = stack[-1];
    {
        popv(4);
        fn = elt(env, 5); // maprint
        return (*qfn2(fn))(qenv(fn), v0424, v0365);
    }

v0349:
    v0476 = stack[-2];
    v0424 = stack[-1];
    v0365 = stack[0];
    fn = elt(env, 6); // layout!-formula
    v0365 = (*qfnn(fn))(qenv(fn), 3, v0476, v0424, v0365);
    nil = C_nil;
    if (exception_pending()) goto v0414;
    env = stack[-3];
    v0424 = v0365;
    v0365 = v0424;
    if (v0365 == nil) goto v0474;
    v0365 = v0424;
    fn = elt(env, 7); // putpline
    v0365 = (*qfn1(fn))(qenv(fn), v0365);
    nil = C_nil;
    if (exception_pending()) goto v0414;
    v0365 = nil;
    { popv(4); return onevalue(v0365); }

v0474:
    v0365 = stack[0];
    if (v0365 == nil) goto v0477;
    v0365 = stack[0];
    fn = elt(env, 4); // oprin
    v0365 = (*qfn1(fn))(qenv(fn), v0365);
    nil = C_nil;
    if (exception_pending()) goto v0414;
    env = stack[-3];
    goto v0477;

v0477:
    v0424 = stack[-2];
    v0365 = stack[-1];
    {
        popv(4);
        fn = elt(env, 5); // maprint
        return (*qfn2(fn))(qenv(fn), v0424, v0365);
    }

v0231:
    v0365 = qvalue(elt(env, 2)); // t
    goto v0230;
// error exit handlers
v0414:
    popv(4);
    return nil;
}



// Code for cstimes

static LispObject CC_cstimes(LispObject env,
                         LispObject v0000, LispObject v0348)
{
    LispObject nil = C_nil;
    LispObject v0432, v0356, v0357, v0475;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cstimes");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0348,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0348);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0356 = v0348;
    v0357 = v0000;
// end of prologue

v0030:
    v0432 = v0357;
    if (v0432 == nil) goto v0005;
    v0432 = v0357;
    v0475 = qcar(v0432);
    v0432 = (LispObject)17; // 1
    if (v0475 == v0432) goto v0426;
    v0432 = v0357;
    v0432 = qcdr(v0432);
    stack[0] = v0432;
    v0432 = v0357;
    v0432 = qcar(v0432);
    v0432 = cons(v0432, v0356);
    nil = C_nil;
    if (exception_pending()) goto v0224;
    env = stack[-1];
    v0356 = v0432;
    v0432 = stack[0];
    v0357 = v0432;
    goto v0030;

v0426:
    v0432 = v0357;
    v0432 = qcdr(v0432);
    v0357 = v0432;
    goto v0030;

v0005:
    v0432 = v0356;
    if (v0432 == nil) goto v0232;
    v0432 = v0356;
    v0432 = qcdr(v0432);
    if (v0432 == nil) goto v0340;
    v0432 = elt(env, 1); // times
    popv(2);
    return cons(v0432, v0356);

v0340:
    v0432 = v0356;
    v0432 = qcar(v0432);
    { popv(2); return onevalue(v0432); }

v0232:
    v0432 = (LispObject)17; // 1
    { popv(2); return onevalue(v0432); }
// error exit handlers
v0224:
    popv(2);
    return nil;
}



// Code for sqp

static LispObject CC_sqp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0251;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sqp");
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
    v0251 = stack[0];
    v0251 = Lconsp(nil, v0251);
    env = stack[-1];
    if (v0251 == nil) goto v0011;
    v0251 = stack[0];
    v0251 = qcar(v0251);
    fn = elt(env, 2); // sfpx
    v0251 = (*qfn1(fn))(qenv(fn), v0251);
    nil = C_nil;
    if (exception_pending()) goto v0347;
    env = stack[-1];
    if (v0251 == nil) goto v0231;
    v0251 = stack[0];
    v0251 = qcdr(v0251);
    {
        popv(2);
        fn = elt(env, 2); // sfpx
        return (*qfn1(fn))(qenv(fn), v0251);
    }

v0231:
    v0251 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0251); }

v0011:
    v0251 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0251); }
// error exit handlers
v0347:
    popv(2);
    return nil;
}



// Code for b!:extadd

static LispObject CC_bTextadd(LispObject env,
                         LispObject v0000, LispObject v0348)
{
    LispObject nil = C_nil;
    LispObject v0472, v0202, v0309;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for b:extadd");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0348,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0348);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0348;
    stack[-1] = v0000;
// end of prologue
    stack[-2] = nil;
    goto v0071;

v0071:
    v0472 = stack[-1];
    if (v0472 == nil) goto v0230;
    v0472 = stack[0];
    if (v0472 == nil) goto v0267;
    v0472 = stack[-1];
    v0472 = qcar(v0472);
    v0202 = qcar(v0472);
    v0472 = stack[0];
    v0472 = qcar(v0472);
    v0472 = qcar(v0472);
    if (equal(v0202, v0472)) goto v0426;
    v0472 = stack[-1];
    v0472 = qcar(v0472);
    v0202 = qcar(v0472);
    v0472 = stack[0];
    v0472 = qcar(v0472);
    v0472 = qcar(v0472);
    fn = elt(env, 2); // b!:ordexp
    v0472 = (*qfn2(fn))(qenv(fn), v0202, v0472);
    nil = C_nil;
    if (exception_pending()) goto v0480;
    env = stack[-3];
    if (v0472 == nil) goto v0407;
    v0472 = stack[-1];
    v0202 = qcar(v0472);
    v0472 = stack[-2];
    v0472 = cons(v0202, v0472);
    nil = C_nil;
    if (exception_pending()) goto v0480;
    env = stack[-3];
    stack[-2] = v0472;
    v0472 = stack[-1];
    v0472 = qcdr(v0472);
    stack[-1] = v0472;
    goto v0071;

v0407:
    v0472 = stack[0];
    v0202 = qcar(v0472);
    v0472 = stack[-2];
    v0472 = cons(v0202, v0472);
    nil = C_nil;
    if (exception_pending()) goto v0480;
    env = stack[-3];
    stack[-2] = v0472;
    v0472 = stack[0];
    v0472 = qcdr(v0472);
    stack[0] = v0472;
    goto v0071;

v0426:
    v0472 = stack[-1];
    v0472 = qcar(v0472);
    v0202 = qcdr(v0472);
    v0472 = stack[0];
    v0472 = qcar(v0472);
    v0472 = qcdr(v0472);
    fn = elt(env, 3); // addf
    v0472 = (*qfn2(fn))(qenv(fn), v0202, v0472);
    nil = C_nil;
    if (exception_pending()) goto v0480;
    env = stack[-3];
    v0202 = v0472;
    if (v0202 == nil) goto v0369;
    v0202 = stack[-1];
    v0202 = qcar(v0202);
    v0309 = qcar(v0202);
    v0202 = v0472;
    v0472 = stack[-2];
    v0472 = acons(v0309, v0202, v0472);
    nil = C_nil;
    if (exception_pending()) goto v0480;
    env = stack[-3];
    stack[-2] = v0472;
    goto v0369;

v0369:
    v0472 = stack[-1];
    v0472 = qcdr(v0472);
    stack[-1] = v0472;
    v0472 = stack[0];
    v0472 = qcdr(v0472);
    stack[0] = v0472;
    goto v0071;

v0267:
    v0472 = stack[-1];
    v0202 = v0472;
    goto v0463;

v0463:
    v0472 = stack[-2];
    if (v0472 == nil) { popv(4); return onevalue(v0202); }
    v0472 = stack[-2];
    v0472 = qcdr(v0472);
    stack[-1] = v0472;
    v0472 = stack[-2];
    v0472 = Lrplacd(nil, v0472, v0202);
    nil = C_nil;
    if (exception_pending()) goto v0480;
    env = stack[-3];
    v0472 = stack[-2];
    v0202 = v0472;
    v0472 = stack[-1];
    stack[-2] = v0472;
    goto v0463;

v0230:
    v0472 = stack[0];
    v0202 = v0472;
    goto v0463;
// error exit handlers
v0480:
    popv(4);
    return nil;
}



// Code for qqe_simplat1

static LispObject CC_qqe_simplat1(LispObject env,
                         LispObject v0000, LispObject v0348)
{
    LispObject nil = C_nil;
    LispObject v0359, v0425, v0225;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qqe_simplat1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0348,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0348);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0348;
    stack[-1] = v0000;
// end of prologue
    v0359 = stack[-1];
    fn = elt(env, 3); // qqe_op
    v0359 = (*qfn1(fn))(qenv(fn), v0359);
    nil = C_nil;
    if (exception_pending()) goto v0355;
    env = stack[-2];
    v0225 = v0359;
    v0425 = v0225;
    v0359 = elt(env, 1); // (qequal qneq)
    v0359 = Lmemq(nil, v0425, v0359);
    if (v0359 == nil) goto v0234;
    v0425 = v0225;
    v0359 = elt(env, 2); // qequal
    if (v0425 == v0359) goto v0349;
    v0425 = stack[-1];
    v0359 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); // qqe_simplqneq
        return (*qfn2(fn))(qenv(fn), v0425, v0359);
    }

v0349:
    v0425 = stack[-1];
    v0359 = stack[0];
    {
        popv(3);
        fn = elt(env, 5); // qqe_simplqequal
        return (*qfn2(fn))(qenv(fn), v0425, v0359);
    }

v0234:
    v0425 = stack[-1];
    v0359 = stack[0];
    {
        popv(3);
        fn = elt(env, 6); // qqe_simplbtat
        return (*qfn2(fn))(qenv(fn), v0425, v0359);
    }
// error exit handlers
v0355:
    popv(3);
    return nil;
}



// Code for rl_simp1

static LispObject CC_rl_simp1(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0489, v0490, v0491, v0492;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rl_simp1");
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
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0000;
// end of prologue

v0360:
    v0489 = qvalue(elt(env, 1)); // rl_cid!*
    if (!(v0489 == nil)) goto v0155;
    v0489 = elt(env, 2); // "select a context"
    v0489 = ncons(v0489);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-5];
    fn = elt(env, 12); // rederr
    v0489 = (*qfn1(fn))(qenv(fn), v0489);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-5];
    goto v0155;

v0155:
    v0489 = stack[0];
    if (!consp(v0489)) goto v0267;
    v0489 = qvalue(elt(env, 3)); // t
    stack[-1] = qvalue(elt(env, 4)); // !*strict_argcount
    qvalue(elt(env, 4)) = v0489; // !*strict_argcount
    v0489 = stack[0];
    fn = elt(env, 13); // argnochk
    v0489 = (*qfn1(fn))(qenv(fn), v0489);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-5];
    qvalue(elt(env, 4)) = stack[-1]; // !*strict_argcount
    v0489 = stack[0];
    v0490 = qcar(v0489);
    v0489 = elt(env, 5); // rl_simpfn
    v0489 = get(v0490, v0489);
    env = stack[-5];
    v0490 = v0489;
    if (v0489 == nil) goto v0476;
    v0489 = v0490;
    if (!symbolp(v0489)) v0489 = nil;
    else { v0489 = qfastgets(v0489);
           if (v0489 != nil) { v0489 = elt(v0489, 62); // full
#ifdef RECORD_GET
             if (v0489 == SPID_NOPROP)
                record_get(elt(fastget_names, 62), 0),
                v0489 = nil;
             else record_get(elt(fastget_names, 62), 1),
                v0489 = lisp_true; }
           else record_get(elt(fastget_names, 62), 0); }
#else
             if (v0489 == SPID_NOPROP) v0489 = nil; else v0489 = lisp_true; }}
#endif
    if (v0489 == nil) goto v0226;
    stack[-1] = v0490;
    v0489 = stack[0];
    v0489 = ncons(v0489);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-5];
    {
        LispObject v0187 = stack[-1];
        popv(6);
        fn = elt(env, 14); // apply
        return (*qfn2(fn))(qenv(fn), v0187, v0489);
    }

v0226:
    stack[-1] = v0490;
    v0489 = stack[0];
    v0489 = qcdr(v0489);
    v0489 = ncons(v0489);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-5];
    {
        LispObject v0493 = stack[-1];
        popv(6);
        fn = elt(env, 14); // apply
        return (*qfn2(fn))(qenv(fn), v0493, v0489);
    }

v0476:
    v0489 = stack[0];
    v0491 = qcar(v0489);
    v0489 = qvalue(elt(env, 1)); // rl_cid!*
    v0490 = qcar(v0489);
    v0489 = elt(env, 6); // simpfnname
    v0489 = get(v0490, v0489);
    env = stack[-5];
    v0489 = get(v0491, v0489);
    env = stack[-5];
    v0490 = v0489;
    if (v0489 == nil) goto v0494;
    v0489 = v0490;
    if (!symbolp(v0489)) v0489 = nil;
    else { v0489 = qfastgets(v0489);
           if (v0489 != nil) { v0489 = elt(v0489, 62); // full
#ifdef RECORD_GET
             if (v0489 == SPID_NOPROP)
                record_get(elt(fastget_names, 62), 0),
                v0489 = nil;
             else record_get(elt(fastget_names, 62), 1),
                v0489 = lisp_true; }
           else record_get(elt(fastget_names, 62), 0); }
#else
             if (v0489 == SPID_NOPROP) v0489 = nil; else v0489 = lisp_true; }}
#endif
    if (v0489 == nil) goto v0433;
    stack[-1] = v0490;
    v0489 = stack[0];
    v0489 = ncons(v0489);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-5];
    {
        LispObject v0495 = stack[-1];
        popv(6);
        fn = elt(env, 14); // apply
        return (*qfn2(fn))(qenv(fn), v0495, v0489);
    }

v0433:
    stack[-1] = v0490;
    v0489 = stack[0];
    v0489 = qcdr(v0489);
    v0489 = ncons(v0489);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-5];
    {
        LispObject v0496 = stack[-1];
        popv(6);
        fn = elt(env, 14); // apply
        return (*qfn2(fn))(qenv(fn), v0496, v0489);
    }

v0494:
    v0489 = stack[0];
    v0489 = qcar(v0489);
    if (!symbolp(v0489)) v0489 = nil;
    else { v0489 = qfastgets(v0489);
           if (v0489 != nil) { v0489 = elt(v0489, 45); // psopfn
#ifdef RECORD_GET
             if (v0489 != SPID_NOPROP)
                record_get(elt(fastget_names, 45), 1);
             else record_get(elt(fastget_names, 45), 0),
                v0489 = nil; }
           else record_get(elt(fastget_names, 45), 0); }
#else
             if (v0489 == SPID_NOPROP) v0489 = nil; }}
#endif
    v0490 = v0489;
    if (v0489 == nil) goto v0446;
    v0489 = stack[0];
    v0489 = qcdr(v0489);
    v0489 = Lapply1(nil, v0490, v0489);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-5];
    stack[-1] = v0489;
    v0490 = stack[-1];
    v0489 = stack[0];
    if (equal(v0490, v0489)) goto v0446;
    v0489 = stack[-1];
    stack[0] = v0489;
    goto v0360;

v0446:
    v0489 = stack[0];
    v0489 = qcar(v0489);
    if (!symbolp(v0489)) v0489 = nil;
    else { v0489 = qfastgets(v0489);
           if (v0489 != nil) { v0489 = elt(v0489, 59); // opfn
#ifdef RECORD_GET
             if (v0489 == SPID_NOPROP)
                record_get(elt(fastget_names, 59), 0),
                v0489 = nil;
             else record_get(elt(fastget_names, 59), 1),
                v0489 = lisp_true; }
           else record_get(elt(fastget_names, 59), 0); }
#else
             if (v0489 == SPID_NOPROP) v0489 = nil; else v0489 = lisp_true; }}
#endif
    if (v0489 == nil) goto v0393;
    v0489 = stack[0];
    stack[-4] = qcar(v0489);
    v0489 = stack[0];
    v0489 = qcdr(v0489);
    stack[-3] = v0489;
    v0489 = stack[-3];
    if (v0489 == nil) goto v0211;
    v0489 = stack[-3];
    v0489 = qcar(v0489);
    fn = elt(env, 15); // reval
    v0489 = (*qfn1(fn))(qenv(fn), v0489);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-5];
    v0489 = ncons(v0489);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-5];
    stack[-1] = v0489;
    stack[-2] = v0489;
    goto v0453;

v0453:
    v0489 = stack[-3];
    v0489 = qcdr(v0489);
    stack[-3] = v0489;
    v0489 = stack[-3];
    if (v0489 == nil) goto v0497;
    stack[0] = stack[-1];
    v0489 = stack[-3];
    v0489 = qcar(v0489);
    fn = elt(env, 15); // reval
    v0489 = (*qfn1(fn))(qenv(fn), v0489);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-5];
    v0489 = ncons(v0489);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-5];
    v0489 = Lrplacd(nil, stack[0], v0489);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-5];
    v0489 = stack[-1];
    v0489 = qcdr(v0489);
    stack[-1] = v0489;
    goto v0453;

v0497:
    v0489 = stack[-2];
    goto v0205;

v0205:
    fn = elt(env, 14); // apply
    v0489 = (*qfn2(fn))(qenv(fn), stack[-4], v0489);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-5];
    stack[0] = v0489;
    goto v0360;

v0211:
    v0489 = qvalue(elt(env, 7)); // nil
    goto v0205;

v0393:
    v0489 = stack[0];
    v0489 = qcar(v0489);
    if (!symbolp(v0489)) v0489 = nil;
    else { v0489 = qfastgets(v0489);
           if (v0489 != nil) { v0489 = elt(v0489, 44); // prepfn2
#ifdef RECORD_GET
             if (v0489 != SPID_NOPROP)
                record_get(elt(fastget_names, 44), 1);
             else record_get(elt(fastget_names, 44), 0),
                v0489 = nil; }
           else record_get(elt(fastget_names, 44), 0); }
#else
             if (v0489 == SPID_NOPROP) v0489 = nil; }}
#endif
    v0490 = v0489;
    if (v0489 == nil) goto v0498;
    stack[-1] = v0490;
    v0489 = stack[0];
    v0489 = ncons(v0489);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-5];
    fn = elt(env, 14); // apply
    v0489 = (*qfn2(fn))(qenv(fn), stack[-1], v0489);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-5];
    stack[0] = v0489;
    goto v0360;

v0498:
    v0489 = stack[0];
    v0489 = qcar(v0489);
    fn = elt(env, 16); // ioto_form2str
    v0489 = (*qfn1(fn))(qenv(fn), v0489);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-5];
    stack[-1] = v0489;
    v0489 = stack[0];
    v0489 = qcar(v0489);
    if (!symbolp(v0489)) v0489 = nil;
    else { v0489 = qfastgets(v0489);
           if (v0489 != nil) { v0489 = elt(v0489, 37); // prtch
#ifdef RECORD_GET
             if (v0489 != SPID_NOPROP)
                record_get(elt(fastget_names, 37), 1);
             else record_get(elt(fastget_names, 37), 0),
                v0489 = nil; }
           else record_get(elt(fastget_names, 37), 0); }
#else
             if (v0489 == SPID_NOPROP) v0489 = nil; }}
#endif
    v0490 = v0489;
    if (v0489 == nil) goto v0499;
    v0489 = v0490;
    fn = elt(env, 16); // ioto_form2str
    v0492 = (*qfn1(fn))(qenv(fn), v0489);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-5];
    v0491 = elt(env, 8); // " ("
    v0490 = stack[-1];
    v0489 = elt(env, 9); // ")"
    v0489 = list4(v0492, v0491, v0490, v0489);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-5];
    fn = elt(env, 17); // lto_sconcat
    v0489 = (*qfn1(fn))(qenv(fn), v0489);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-5];
    stack[-1] = v0489;
    goto v0499;

v0499:
    v0490 = stack[-1];
    v0489 = elt(env, 10); // "predicate"
    fn = elt(env, 18); // redmsg
    v0489 = (*qfn2(fn))(qenv(fn), v0490, v0489);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-5];
    v0489 = stack[0];
    v0492 = qcar(v0489);
    v0489 = qvalue(elt(env, 1)); // rl_cid!*
    v0490 = qcar(v0489);
    v0489 = elt(env, 6); // simpfnname
    v0491 = get(v0490, v0489);
    env = stack[-5];
    v0489 = qvalue(elt(env, 1)); // rl_cid!*
    v0490 = qcar(v0489);
    v0489 = elt(env, 11); // simpdefault
    v0489 = get(v0490, v0489);
    env = stack[-5];
    v0489 = Lputprop(nil, 3, v0492, v0491, v0489);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-5];
    v0489 = stack[0];
    stack[0] = v0489;
    goto v0360;

v0267:
    v0489 = stack[0];
    {
        popv(6);
        fn = elt(env, 19); // rl_simpatom
        return (*qfn1(fn))(qenv(fn), v0489);
    }
// error exit handlers
v0188:
    env = stack[-5];
    qvalue(elt(env, 4)) = stack[-1]; // !*strict_argcount
    popv(6);
    return nil;
v0401:
    popv(6);
    return nil;
}



// Code for aex_simplenullp

static LispObject CC_aex_simplenullp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0030;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for aex_simplenullp");
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
    v0030 = v0000;
// end of prologue
    fn = elt(env, 1); // aex_ex
    v0030 = (*qfn1(fn))(qenv(fn), v0030);
    errexit();
    v0030 = qcar(v0030);
    v0030 = (v0030 == nil ? lisp_true : nil);
    return onevalue(v0030);
}



// Code for variableom

static LispObject CC_variableom(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0225, v0226;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for variableom");
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
    v0225 = stack[0];
    v0226 = Lintern(nil, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0477;
    env = stack[-2];
    v0225 = qvalue(elt(env, 1)); // constantsom!*
    v0225 = Lassoc(nil, v0226, v0225);
    stack[-1] = v0225;
    v0225 = stack[-1];
    if (v0225 == nil) goto v0362;
    v0225 = elt(env, 2); // "<OMS "
    fn = elt(env, 9); // printout
    v0225 = (*qfn1(fn))(qenv(fn), v0225);
    nil = C_nil;
    if (exception_pending()) goto v0477;
    env = stack[-2];
    v0225 = elt(env, 3); // "cd="""
    v0225 = Lprinc(nil, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0477;
    env = stack[-2];
    v0225 = stack[-1];
    v0225 = qcdr(v0225);
    v0225 = qcar(v0225);
    v0225 = Lprinc(nil, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0477;
    env = stack[-2];
    v0225 = elt(env, 4); // """ "
    v0225 = Lprinc(nil, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0477;
    env = stack[-2];
    v0225 = elt(env, 5); // "name="""
    v0225 = Lprinc(nil, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0477;
    env = stack[-2];
    v0225 = stack[-1];
    v0225 = qcdr(v0225);
    v0225 = qcdr(v0225);
    v0225 = qcar(v0225);
    v0225 = Lprinc(nil, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0477;
    env = stack[-2];
    v0225 = elt(env, 6); // """/>"
    v0225 = Lprinc(nil, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0477;
    goto v0452;

v0452:
    v0225 = nil;
    { popv(3); return onevalue(v0225); }

v0362:
    v0225 = stack[0];
    if (v0225 == nil) goto v0452;
    v0225 = elt(env, 8); // "<OMV "
    fn = elt(env, 9); // printout
    v0225 = (*qfn1(fn))(qenv(fn), v0225);
    nil = C_nil;
    if (exception_pending()) goto v0477;
    env = stack[-2];
    v0225 = elt(env, 5); // "name="""
    v0225 = Lprinc(nil, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0477;
    env = stack[-2];
    v0225 = stack[0];
    v0225 = Lprinc(nil, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0477;
    env = stack[-2];
    v0225 = elt(env, 6); // """/>"
    v0225 = Lprinc(nil, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0477;
    goto v0452;
// error exit handlers
v0477:
    popv(3);
    return nil;
}



// Code for groebcplistsortin

static LispObject CC_groebcplistsortin(LispObject env,
                         LispObject v0000, LispObject v0348)
{
    LispObject nil = C_nil;
    LispObject v0325, v0361;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for groebcplistsortin");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0348,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0348);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0348;
    v0361 = v0000;
// end of prologue
    v0325 = stack[0];
    if (v0325 == nil) goto v0015;
    v0325 = stack[0];
    fn = elt(env, 1); // groebcplistsortin1
    v0325 = (*qfn2(fn))(qenv(fn), v0361, v0325);
    nil = C_nil;
    if (exception_pending()) goto v0251;
    { LispObject res = stack[0]; popv(1); return onevalue(res); }

v0015:
    v0325 = v0361;
    popv(1);
    return ncons(v0325);
// error exit handlers
v0251:
    popv(1);
    return nil;
}



// Code for groebbuchcrit4t

static LispObject CC_groebbuchcrit4t(LispObject env,
                         LispObject v0000, LispObject v0348)
{
    LispObject nil = C_nil;
    LispObject v0425, v0225;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for groebbuchcrit4t");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0348,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0348);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0348;
    stack[-1] = v0000;
// end of prologue

v0015:
    v0425 = stack[-1];
    if (v0425 == nil) goto v0230;
    v0425 = stack[0];
    v0425 = (v0425 == nil ? lisp_true : nil);
    goto v0370;

v0370:
    if (v0425 == nil) goto v0258;
    v0425 = qvalue(elt(env, 2)); // nil
    { popv(3); return onevalue(v0425); }

v0258:
    v0425 = stack[-1];
    v0225 = qcar(v0425);
    v0425 = (LispObject)1; // 0
    if (v0225 == v0425) goto v0351;
    v0425 = stack[0];
    v0225 = qcar(v0425);
    v0425 = (LispObject)1; // 0
    v0425 = Lneq(nil, v0225, v0425);
    nil = C_nil;
    if (exception_pending()) goto v0355;
    env = stack[-2];
    goto v0251;

v0251:
    if (v0425 == nil) goto v0474;
    v0425 = qvalue(elt(env, 1)); // t
    { popv(3); return onevalue(v0425); }

v0474:
    v0425 = stack[-1];
    v0425 = qcdr(v0425);
    stack[-1] = v0425;
    v0425 = stack[0];
    v0425 = qcdr(v0425);
    stack[0] = v0425;
    goto v0015;

v0351:
    v0425 = qvalue(elt(env, 2)); // nil
    goto v0251;

v0230:
    v0425 = qvalue(elt(env, 1)); // t
    goto v0370;
// error exit handlers
v0355:
    popv(3);
    return nil;
}



// Code for !*pf2wedgepf

static LispObject CC_Hpf2wedgepf(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0270, v0426, v0402;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *pf2wedgepf");
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
    stack[-1] = nil;
    goto v0015;

v0015:
    v0270 = stack[0];
    if (v0270 == nil) goto v0071;
    v0270 = stack[0];
    v0270 = qcar(v0270);
    v0270 = qcar(v0270);
    fn = elt(env, 1); // wedgefax
    v0402 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-2];
    v0270 = stack[0];
    v0270 = qcar(v0270);
    v0426 = qcdr(v0270);
    v0270 = stack[-1];
    v0270 = acons(v0402, v0426, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-2];
    stack[-1] = v0270;
    v0270 = stack[0];
    v0270 = qcdr(v0270);
    stack[0] = v0270;
    goto v0015;

v0071:
    v0270 = stack[-1];
    {
        popv(3);
        fn = elt(env, 2); // nreverse
        return (*qfn1(fn))(qenv(fn), v0270);
    }
// error exit handlers
v0368:
    popv(3);
    return nil;
}



// Code for deleteall

static LispObject CC_deleteall(LispObject env,
                         LispObject v0000, LispObject v0348)
{
    LispObject nil = C_nil;
    LispObject v0368, v0362, v0363, v0358;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for deleteall");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0348,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0348);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0348;
    stack[-1] = v0000;
// end of prologue
    v0363 = nil;
    goto v0155;

v0155:
    v0368 = stack[0];
    if (v0368 == nil) { popv(4); return onevalue(v0363); }
    v0368 = stack[0];
    v0368 = qcar(v0368);
    v0358 = v0368;
    v0368 = stack[0];
    v0368 = qcdr(v0368);
    stack[0] = v0368;
    v0362 = v0358;
    v0368 = stack[-1];
    if (equal(v0362, v0368)) goto v0155;
    stack[-2] = v0363;
    v0368 = v0358;
    v0368 = ncons(v0368);
    nil = C_nil;
    if (exception_pending()) goto v0473;
    env = stack[-3];
    v0368 = Lnconc(nil, stack[-2], v0368);
    nil = C_nil;
    if (exception_pending()) goto v0473;
    env = stack[-3];
    v0363 = v0368;
    goto v0155;
// error exit handlers
v0473:
    popv(4);
    return nil;
}



// Code for lesspcdr

static LispObject CC_lesspcdr(LispObject env,
                         LispObject v0000, LispObject v0348)
{
    LispObject nil = C_nil;
    LispObject v0231, v0232;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lesspcdr");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0231 = v0348;
    v0232 = v0000;
// end of prologue
    v0232 = qcdr(v0232);
    v0231 = qcdr(v0231);
        return Llessp(nil, v0232, v0231);
}



// Code for command

static LispObject CC_command(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0183, v0184, v0510, v0511;
    LispObject fn;
    argcheck(nargs, 0, "command");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for command");
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
    push3(nil, nil, nil);
// end of prologue
    stack[-2] = qvalue(elt(env, 1)); // errmsg!*
    qvalue(elt(env, 1)) = nil; // errmsg!*
    stack[-1] = qvalue(elt(env, 2)); // loopdelimslist!*
    qvalue(elt(env, 2)) = nil; // loopdelimslist!*
    v0183 = qvalue(elt(env, 3)); // !*demo
    if (v0183 == nil) goto v0232;
    v0183 = qvalue(elt(env, 4)); // ifl!*
    if (v0183 == nil) goto v0232;
    fn = elt(env, 29); // commdemo
    v0183 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0512;
    env = stack[-3];
    goto v0155;

v0155:
    qvalue(elt(env, 2)) = stack[-1]; // loopdelimslist!*
    qvalue(elt(env, 1)) = stack[-2]; // errmsg!*
    { popv(4); return onevalue(v0183); }

v0232:
    v0183 = qvalue(elt(env, 5)); // !*slin
    if (v0183 == nil) goto v0251;
    v0183 = qvalue(elt(env, 7)); // !*reduce4
    goto v0266;

v0266:
    if (!(v0183 == nil)) goto v0071;
    fn = elt(env, 30); // setcloc!*
    v0183 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0512;
    env = stack[-3];
    v0183 = qvalue(elt(env, 8)); // lreadfn!*
    if (v0183 == nil) goto v0473;
    v0184 = qvalue(elt(env, 8)); // lreadfn!*
    v0183 = qvalue(elt(env, 9)); // nil
    fn = elt(env, 31); // lispapply
    v0183 = (*qfn2(fn))(qenv(fn), v0184, v0183);
    nil = C_nil;
    if (exception_pending()) goto v0512;
    env = stack[-3];
    goto v0270;

v0270:
    stack[0] = v0183;
    goto v0005;

v0005:
    v0183 = qvalue(elt(env, 7)); // !*reduce4
    if (v0183 == nil) goto v0223;
    v0183 = qvalue(elt(env, 25)); // !*debug
    if (v0183 == nil) goto v0343;
    v0183 = elt(env, 26); // "Parse: "
    v0183 = Lprinc(nil, v0183);
    nil = C_nil;
    if (exception_pending()) goto v0512;
    env = stack[-3];
    v0183 = stack[0];
    fn = elt(env, 32); // prettyprint
    v0183 = (*qfn1(fn))(qenv(fn), v0183);
    nil = C_nil;
    if (exception_pending()) goto v0512;
    env = stack[-3];
    goto v0343;

v0343:
    v0184 = qvalue(elt(env, 18)); // key!*
    v0183 = elt(env, 27); // !*semicol!*
    if (v0184 == v0183) goto v0071;
    v0183 = qvalue(elt(env, 7)); // !*reduce4
    if (v0183 == nil) goto v0496;
    v0183 = stack[0];
    fn = elt(env, 33); // n_form
    v0183 = (*qfn1(fn))(qenv(fn), v0183);
    nil = C_nil;
    if (exception_pending()) goto v0512;
    env = stack[-3];
    stack[0] = v0183;
    goto v0495;

v0495:
    v0183 = qvalue(elt(env, 25)); // !*debug
    if (v0183 == nil) goto v0185;
    v0183 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0512;
    env = stack[-3];
    v0183 = elt(env, 28); // "Form: "
    v0183 = Lprinc(nil, v0183);
    nil = C_nil;
    if (exception_pending()) goto v0512;
    env = stack[-3];
    v0183 = stack[0];
    fn = elt(env, 32); // prettyprint
    v0183 = (*qfn1(fn))(qenv(fn), v0183);
    nil = C_nil;
    if (exception_pending()) goto v0512;
    env = stack[-3];
    goto v0185;

v0185:
    v0183 = stack[0];
    goto v0155;

v0496:
    v0183 = stack[0];
    fn = elt(env, 34); // form
    v0183 = (*qfn1(fn))(qenv(fn), v0183);
    nil = C_nil;
    if (exception_pending()) goto v0512;
    env = stack[-3];
    stack[0] = v0183;
    goto v0495;

v0071:
    fn = elt(env, 35); // readch1
    v0183 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0512;
    env = stack[-3];
    qvalue(elt(env, 10)) = v0183; // crchar!*
    v0184 = qvalue(elt(env, 10)); // crchar!*
    v0183 = qvalue(elt(env, 11)); // !$eol!$
    if (equal(v0184, v0183)) goto v0071;
    fn = elt(env, 36); // command1
    v0183 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0512;
    env = stack[-3];
    stack[0] = v0183;
    goto v0005;

v0223:
    v0183 = qvalue(elt(env, 12)); // !*struct
    if (v0183 == nil) goto v0357;
    v0183 = stack[0];
    fn = elt(env, 37); // structchk
    v0183 = (*qfn1(fn))(qenv(fn), v0183);
    nil = C_nil;
    if (exception_pending()) goto v0512;
    env = stack[-3];
    stack[0] = v0183;
    goto v0357;

v0357:
    v0183 = qvalue(elt(env, 13)); // !*pret
    if (v0183 == nil) goto v0430;
    v0183 = stack[0];
    if (!consp(v0183)) goto v0220;
    v0183 = stack[0];
    v0184 = qcar(v0183);
    v0183 = elt(env, 14); // (in out shut)
    v0183 = Lmemq(nil, v0184, v0183);
    v0183 = (v0183 == nil ? lisp_true : nil);
    goto v0513;

v0513:
    if (v0183 == nil) goto v0430;
    v0183 = stack[0];
    if (v0183 == nil) goto v0406;
    v0183 = qvalue(elt(env, 9)); // nil
    goto v0445;

v0445:
    if (v0183 == nil) goto v0214;
    v0183 = elt(env, 16); // end
    fn = elt(env, 38); // rprint
    v0183 = (*qfn1(fn))(qenv(fn), v0183);
    nil = C_nil;
    if (exception_pending()) goto v0512;
    env = stack[-3];
    goto v0430;

v0430:
    v0183 = qvalue(elt(env, 5)); // !*slin
    if (v0183 == nil) goto v0409;
    v0184 = elt(env, 17); // symbolic
    v0183 = stack[0];
    v0183 = list2(v0184, v0183);
    nil = C_nil;
    if (exception_pending()) goto v0512;
    env = stack[-3];
    goto v0155;

v0409:
    v0183 = stack[0];
    fn = elt(env, 34); // form
    v0183 = (*qfn1(fn))(qenv(fn), v0183);
    nil = C_nil;
    if (exception_pending()) goto v0512;
    env = stack[-3];
    v0184 = v0183;
    v0183 = qvalue(elt(env, 18)); // key!*
    if (!symbolp(v0183)) v0183 = nil;
    else { v0183 = qfastgets(v0183);
           if (v0183 != nil) { v0183 = elt(v0183, 48); // modefn
#ifdef RECORD_GET
             if (v0183 == SPID_NOPROP)
                record_get(elt(fastget_names, 48), 0),
                v0183 = nil;
             else record_get(elt(fastget_names, 48), 1),
                v0183 = lisp_true; }
           else record_get(elt(fastget_names, 48), 0); }
#else
             if (v0183 == SPID_NOPROP) v0183 = nil; else v0183 = lisp_true; }}
#endif
    if (v0183 == nil) goto v0514;
    v0183 = qvalue(elt(env, 18)); // key!*
    goto v0380;

v0380:
    stack[0] = v0183;
    v0511 = v0184;
    v0510 = qvalue(elt(env, 9)); // nil
    v0184 = elt(env, 17); // symbolic
    fn = elt(env, 39); // convertmode1
    v0183 = (*qfnn(fn))(qenv(fn), 4, v0511, v0510, v0184, v0183);
    nil = C_nil;
    if (exception_pending()) goto v0512;
    env = stack[-3];
    v0183 = list2(stack[0], v0183);
    nil = C_nil;
    if (exception_pending()) goto v0512;
    env = stack[-3];
    goto v0155;

v0514:
    v0183 = v0184;
    if (!consp(v0183)) goto v0379;
    v0183 = v0184;
    v0510 = qcar(v0183);
    v0183 = elt(env, 19); // quote
    if (v0510 == v0183) goto v0484;
    v0183 = v0184;
    v0183 = qcar(v0183);
    if (!(symbolp(v0183))) goto v0443;
    v0183 = v0184;
    v0510 = qcar(v0183);
    v0183 = elt(env, 20); // nochange
    v0183 = Lflagp(nil, v0510, v0183);
    env = stack[-3];
    if (v0183 == nil) goto v0439;
    v0183 = qvalue(elt(env, 6)); // t
    goto v0515;

v0515:
    if (v0183 == nil) goto v0443;
    v0183 = v0184;
    v0510 = qcar(v0183);
    v0183 = elt(env, 23); // (setq setel setf)
    v0183 = Lmemq(nil, v0510, v0183);
    if (v0183 == nil) goto v0201;
    v0183 = v0184;
    v0183 = qcdr(v0183);
    v0183 = qcdr(v0183);
    v0510 = qcar(v0183);
    v0183 = elt(env, 19); // quote
    v0183 = Leqcar(nil, v0510, v0183);
    env = stack[-3];
    goto v0204;

v0204:
    if (v0183 == nil) goto v0482;
    v0183 = elt(env, 17); // symbolic
    goto v0380;

v0482:
    v0183 = qvalue(elt(env, 24)); // !*mode
    goto v0380;

v0201:
    v0183 = qvalue(elt(env, 9)); // nil
    goto v0204;

v0443:
    v0183 = qvalue(elt(env, 6)); // t
    goto v0204;

v0439:
    v0183 = v0184;
    v0510 = qcar(v0183);
    v0183 = elt(env, 21); // intfn
    v0183 = Lflagp(nil, v0510, v0183);
    env = stack[-3];
    if (v0183 == nil) goto v0516;
    v0183 = qvalue(elt(env, 6)); // t
    goto v0515;

v0516:
    v0183 = v0184;
    v0510 = qcar(v0183);
    v0183 = elt(env, 22); // list
    v0183 = (v0510 == v0183 ? lisp_true : nil);
    goto v0515;

v0484:
    v0183 = qvalue(elt(env, 9)); // nil
    goto v0204;

v0379:
    v0183 = qvalue(elt(env, 9)); // nil
    goto v0204;

v0214:
    v0183 = stack[0];
    fn = elt(env, 38); // rprint
    v0183 = (*qfn1(fn))(qenv(fn), v0183);
    nil = C_nil;
    if (exception_pending()) goto v0512;
    env = stack[-3];
    v0183 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0512;
    env = stack[-3];
    goto v0430;

v0406:
    v0184 = qvalue(elt(env, 15)); // cursym!*
    v0183 = elt(env, 16); // end
    v0183 = (v0184 == v0183 ? lisp_true : nil);
    goto v0445;

v0220:
    v0183 = qvalue(elt(env, 6)); // t
    goto v0513;

v0473:
    v0183 = Lread(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0512;
    env = stack[-3];
    goto v0270;

v0251:
    v0183 = qvalue(elt(env, 6)); // t
    goto v0266;
// error exit handlers
v0512:
    env = stack[-3];
    qvalue(elt(env, 2)) = stack[-1]; // loopdelimslist!*
    qvalue(elt(env, 1)) = stack[-2]; // errmsg!*
    popv(4);
    return nil;
}



// Code for mo_from_a

static LispObject CC_mo_from_a(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0218, v0219;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mo_from_a");
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
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-3] = v0000;
// end of prologue
    stack[0] = stack[-3];
    v0218 = qvalue(elt(env, 1)); // cali!=basering
    fn = elt(env, 4); // ring_all_names
    v0218 = (*qfn1(fn))(qenv(fn), v0218);
    nil = C_nil;
    if (exception_pending()) goto v0467;
    env = stack[-5];
    v0218 = Lmember(nil, stack[0], v0218);
    if (v0218 == nil) goto v0267;
    v0218 = qvalue(elt(env, 1)); // cali!=basering
    fn = elt(env, 4); // ring_all_names
    v0218 = (*qfn1(fn))(qenv(fn), v0218);
    nil = C_nil;
    if (exception_pending()) goto v0467;
    env = stack[-5];
    stack[-4] = v0218;
    v0218 = stack[-4];
    if (v0218 == nil) goto v0363;
    v0218 = stack[-4];
    v0218 = qcar(v0218);
    v0219 = v0218;
    v0218 = stack[-3];
    if (equal(v0219, v0218)) goto v0415;
    v0218 = (LispObject)1; // 0
    goto v0403;

v0403:
    v0218 = ncons(v0218);
    nil = C_nil;
    if (exception_pending()) goto v0467;
    env = stack[-5];
    stack[-1] = v0218;
    stack[-2] = v0218;
    goto v0402;

v0402:
    v0218 = stack[-4];
    v0218 = qcdr(v0218);
    stack[-4] = v0218;
    v0218 = stack[-4];
    if (v0218 == nil) goto v0364;
    stack[0] = stack[-1];
    v0218 = stack[-4];
    v0218 = qcar(v0218);
    v0219 = v0218;
    v0218 = stack[-3];
    if (equal(v0219, v0218)) goto v0398;
    v0218 = (LispObject)1; // 0
    goto v0423;

v0423:
    v0218 = ncons(v0218);
    nil = C_nil;
    if (exception_pending()) goto v0467;
    env = stack[-5];
    v0218 = Lrplacd(nil, stack[0], v0218);
    nil = C_nil;
    if (exception_pending()) goto v0467;
    env = stack[-5];
    v0218 = stack[-1];
    v0218 = qcdr(v0218);
    stack[-1] = v0218;
    goto v0402;

v0398:
    v0218 = (LispObject)17; // 1
    goto v0423;

v0364:
    v0218 = stack[-2];
    goto v0426;

v0426:
    fn = elt(env, 5); // mo!=shorten
    v0218 = (*qfn1(fn))(qenv(fn), v0218);
    nil = C_nil;
    if (exception_pending()) goto v0467;
    env = stack[-5];
    stack[0] = v0218;
    fn = elt(env, 6); // mo!=deglist
    v0218 = (*qfn1(fn))(qenv(fn), v0218);
    nil = C_nil;
    if (exception_pending()) goto v0467;
    {
        LispObject v0470 = stack[0];
        popv(6);
        return cons(v0470, v0218);
    }

v0415:
    v0218 = (LispObject)17; // 1
    goto v0403;

v0363:
    v0218 = qvalue(elt(env, 3)); // nil
    goto v0426;

v0267:
    v0219 = stack[-3];
    v0218 = elt(env, 2); // "dpoly variable"
    {
        popv(6);
        fn = elt(env, 7); // typerr
        return (*qfn2(fn))(qenv(fn), v0219, v0218);
    }
// error exit handlers
v0467:
    popv(6);
    return nil;
}



// Code for class

static LispObject CC_class(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0349, v0350;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for class");
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
    v0349 = stack[0];
    fn = elt(env, 3); // ord
    v0350 = (*qfn1(fn))(qenv(fn), v0349);
    nil = C_nil;
    if (exception_pending()) goto v0362;
    env = stack[-1];
    v0349 = (LispObject)1; // 0
    if (v0350 == v0349) goto v0011;
    v0350 = qvalue(elt(env, 1)); // ordering
    v0349 = elt(env, 2); // lex
    if (v0350 == v0349) goto v0325;
    v0349 = stack[0];
    v0349 = qcdr(v0349);
    goto v0235;

v0235:
    v0349 = Lreverse(nil, v0349);
    nil = C_nil;
    if (exception_pending()) goto v0362;
    env = stack[-1];
    fn = elt(env, 4); // leftzeros
    v0349 = (*qfn1(fn))(qenv(fn), v0349);
    nil = C_nil;
    if (exception_pending()) goto v0362;
    v0349 = (LispObject)((int32_t)(v0349) + 0x10);
    { popv(2); return onevalue(v0349); }

v0325:
    v0349 = stack[0];
    goto v0235;

v0011:
    v0349 = (LispObject)1; // 0
    { popv(2); return onevalue(v0349); }
// error exit handlers
v0362:
    popv(2);
    return nil;
}



setup_type const u14_setup[] =
{
    {"xread1",                  CC_xread1,      too_many_1,    wrong_no_1},
    {"qqe_number-of-adds-in-qterm",CC_qqe_numberKofKaddsKinKqterm,too_many_1,wrong_no_1},
    {"diffp1",                  too_few_2,      CC_diffp1,     wrong_no_2},
    {"sf_member",               too_few_2,      CC_sf_member,  wrong_no_2},
    {"nary",                    too_few_2,      CC_nary,       wrong_no_2},
    {"sacar",                   too_few_2,      CC_sacar,      wrong_no_2},
    {"spband_matrix",           too_few_2,      CC_spband_matrix,wrong_no_2},
    {"bcplus?",                 CC_bcplusW,     too_many_1,    wrong_no_1},
    {"list+list",               too_few_2,      CC_listLlist,  wrong_no_2},
    {"physopaeval",             CC_physopaeval, too_many_1,    wrong_no_1},
    {"copyd",                   too_few_2,      CC_copyd,      wrong_no_2},
    {"dpmat_coldegs",           CC_dpmat_coldegs,too_many_1,   wrong_no_1},
    {"general-reduce-degree-mod-p",too_few_2,   CC_generalKreduceKdegreeKmodKp,wrong_no_2},
    {"exptcompare",             too_few_2,      CC_exptcompare,wrong_no_2},
    {"sf2ss",                   CC_sf2ss,       too_many_1,    wrong_no_1},
    {"ibalp_initwl",            CC_ibalp_initwl,too_many_1,    wrong_no_1},
    {"ofsf_clnegrel",           too_few_2,      CC_ofsf_clnegrel,wrong_no_2},
    {"variablesir",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_variablesir},
    {"inshisto",                CC_inshisto,    too_many_1,    wrong_no_1},
    {"onoff",                   too_few_2,      CC_onoff,      wrong_no_2},
    {"unchecked_getmatelem",    CC_unchecked_getmatelem,too_many_1,wrong_no_1},
    {"vdpred",                  CC_vdpred,      too_many_1,    wrong_no_1},
    {"prinfit",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_prinfit},
    {"cstimes",                 too_few_2,      CC_cstimes,    wrong_no_2},
    {"sqp",                     CC_sqp,         too_many_1,    wrong_no_1},
    {"b:extadd",                too_few_2,      CC_bTextadd,   wrong_no_2},
    {"qqe_simplat1",            too_few_2,      CC_qqe_simplat1,wrong_no_2},
    {"rl_simp1",                CC_rl_simp1,    too_many_1,    wrong_no_1},
    {"aex_simplenullp",         CC_aex_simplenullp,too_many_1, wrong_no_1},
    {"variableom",              CC_variableom,  too_many_1,    wrong_no_1},
    {"groebcplistsortin",       too_few_2,      CC_groebcplistsortin,wrong_no_2},
    {"groebbuchcrit4t",         too_few_2,      CC_groebbuchcrit4t,wrong_no_2},
    {"*pf2wedgepf",             CC_Hpf2wedgepf, too_many_1,    wrong_no_1},
    {"deleteall",               too_few_2,      CC_deleteall,  wrong_no_2},
    {"lesspcdr",                too_few_2,      CC_lesspcdr,   wrong_no_2},
    {"command",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_command},
    {"mo_from_a",               CC_mo_from_a,   too_many_1,    wrong_no_1},
    {"class",                   CC_class,       too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u14", (two_args *)"10952 4616164 8481441", 0}
};

// end of generated code
