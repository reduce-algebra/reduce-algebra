
// $destdir/u53.c        Machine generated C code

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



// Code for new_provev

static LispObject CC_new_provev(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0008, v0009, v0010, v0011;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for new_provev");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0010 = v0001;
    v0011 = v0000;
// end of prologue
    v0009 = v0011;
    v0008 = v0010;
    v0008 = Lmember(nil, v0009, v0008);
    if (v0008 == nil) goto v0012;
    v0008 = v0011;
    v0008 = qcdr(v0008);
    v0008 = qcar(v0008);
    v0009 = qcar(v0008);
    v0008 = v0010;
    v0008 = Lassoc(nil, v0009, v0008);
    if (v0008 == nil) return onevalue(v0010);
    v0008 = v0011;
    v0008 = qcdr(v0008);
    v0008 = qcar(v0008);
    v0009 = qcdr(v0008);
    v0008 = v0010;
    v0008 = Lassoc(nil, v0009, v0008);
    if (v0008 == nil) return onevalue(v0010);
    v0008 = qvalue(elt(env, 1)); // nil
    return onevalue(v0008);

v0012:
    v0008 = qvalue(elt(env, 1)); // nil
    return onevalue(v0008);
}



// Code for !*ex2sf

static LispObject CC_Hex2sf(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0019, v0020;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *ex2sf");
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
    goto v0012;

v0012:
    v0019 = stack[-1];
    if (v0019 == nil) goto v0021;
    v0019 = stack[-1];
    v0019 = qcar(v0019);
    v0019 = qcar(v0019);
    v0019 = qcar(v0019);
    if (v0019 == nil) goto v0022;
    v0019 = stack[-1];
    v0019 = qcar(v0019);
    v0019 = qcar(v0019);
    v0020 = qcar(v0019);
    v0019 = (LispObject)17; // 1
    fn = elt(env, 1); // to
    stack[0] = (*qfn2(fn))(qenv(fn), v0020, v0019);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[-3];
    v0019 = stack[-1];
    v0019 = qcar(v0019);
    v0019 = qcdr(v0019);
    fn = elt(env, 2); // subs2chk
    v0020 = (*qfn1(fn))(qenv(fn), v0019);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[-3];
    v0019 = stack[-2];
    v0019 = acons(stack[0], v0020, v0019);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[-3];
    stack[-2] = v0019;
    v0019 = stack[-1];
    v0019 = qcdr(v0019);
    stack[-1] = v0019;
    goto v0012;

v0022:
    stack[0] = stack[-2];
    v0019 = stack[-1];
    v0019 = qcar(v0019);
    v0019 = qcdr(v0019);
    fn = elt(env, 2); // subs2chk
    v0019 = (*qfn1(fn))(qenv(fn), v0019);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[-3];
    {
        LispObject v0024 = stack[0];
        popv(4);
        fn = elt(env, 3); // nreverse
        return (*qfn2(fn))(qenv(fn), v0024, v0019);
    }

v0021:
    v0019 = stack[-2];
    {
        popv(4);
        fn = elt(env, 3); // nreverse
        return (*qfn1(fn))(qenv(fn), v0019);
    }
// error exit handlers
v0023:
    popv(4);
    return nil;
}



// Code for lf!=tovarlessp

static LispObject CC_lfMtovarlessp(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0028, v0029;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lf=tovarlessp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
// copy arguments values to proper place
    v0028 = v0001;
    v0029 = v0000;
// end of prologue
    fn = elt(env, 1); // mo_compare
    v0029 = (*qfn2(fn))(qenv(fn), v0029, v0028);
    errexit();
    v0028 = (LispObject)17; // 1
    v0028 = (v0029 == v0028 ? lisp_true : nil);
    return onevalue(v0028);
}



// Code for pa_vect2list

static LispObject CC_pa_vect2list(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0052, v0053;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pa_vect2list");
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
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[-6] = v0000;
// end of prologue
    v0052 = stack[-6];
    v0052 = qcdr(v0052);
    fn = elt(env, 2); // upbve
    v0052 = (*qfn1(fn))(qenv(fn), v0052);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-8];
    v0052 = sub1(v0052);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-8];
    v0052 = Lmkvect(nil, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-8];
    stack[-7] = v0052;
    v0052 = (LispObject)17; // 1
    stack[-4] = v0052;
    goto v0017;

v0017:
    v0052 = stack[-6];
    v0052 = qcdr(v0052);
    fn = elt(env, 2); // upbve
    v0053 = (*qfn1(fn))(qenv(fn), v0052);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-8];
    v0052 = stack[-4];
    v0052 = difference2(v0053, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-8];
    v0052 = Lminusp(nil, v0052);
    env = stack[-8];
    if (v0052 == nil) goto v0055;
    v0052 = stack[-6];
    v0052 = qcar(v0052);
    stack[-4] = v0052;
    v0052 = stack[-4];
    if (v0052 == nil) goto v0056;
    v0052 = stack[-4];
    v0052 = qcar(v0052);
    stack[0] = stack[-7];
    v0052 = sub1(v0052);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-8];
    v0052 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0052/(16/CELL)));
    fn = elt(env, 3); // ordn
    v0052 = (*qfn1(fn))(qenv(fn), v0052);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-8];
    v0052 = ncons(v0052);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-8];
    stack[-2] = v0052;
    stack[-3] = v0052;
    goto v0057;

v0057:
    v0052 = stack[-4];
    v0052 = qcdr(v0052);
    stack[-4] = v0052;
    v0052 = stack[-4];
    if (v0052 == nil) { LispObject res = stack[-3]; popv(9); return onevalue(res); }
    stack[-1] = stack[-2];
    v0052 = stack[-4];
    v0052 = qcar(v0052);
    stack[0] = stack[-7];
    v0052 = sub1(v0052);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-8];
    v0052 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0052/(16/CELL)));
    fn = elt(env, 3); // ordn
    v0052 = (*qfn1(fn))(qenv(fn), v0052);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-8];
    v0052 = ncons(v0052);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-8];
    v0052 = Lrplacd(nil, stack[-1], v0052);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-8];
    v0052 = stack[-2];
    v0052 = qcdr(v0052);
    stack[-2] = v0052;
    goto v0057;

v0056:
    v0052 = qvalue(elt(env, 1)); // nil
    { popv(9); return onevalue(v0052); }

v0055:
    v0052 = stack[-6];
    stack[0] = qcdr(v0052);
    v0052 = stack[-4];
    v0052 = sub1(v0052);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-8];
    v0052 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0052/(16/CELL)));
    stack[-5] = v0052;
    stack[-3] = stack[-7];
    v0052 = stack[-5];
    stack[-2] = sub1(v0052);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-8];
    stack[-1] = stack[-4];
    stack[0] = stack[-7];
    v0052 = stack[-5];
    v0052 = sub1(v0052);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-8];
    v0052 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0052/(16/CELL)));
    v0052 = cons(stack[-1], v0052);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-8];
    *(LispObject *)((char *)stack[-3] + (CELL-TAG_VECTOR) + ((int32_t)stack[-2]/(16/CELL))) = v0052;
    v0052 = stack[-4];
    v0052 = add1(v0052);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-8];
    stack[-4] = v0052;
    goto v0017;
// error exit handlers
v0054:
    popv(9);
    return nil;
}



// Code for modroots1

static LispObject CC_modroots1(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0103, v0104, v0105;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for modroots1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
// copy arguments values to proper place
    stack[-1] = v0001;
    stack[-10] = v0000;
// end of prologue
    v0103 = stack[-1];
    v0103 = qcdr(v0103);
    if (v0103 == nil) goto v0106;
    stack[-7] = nil;
    v0103 = stack[-1];
    v0103 = qcar(v0103);
    stack[-11] = v0103;
    v0103 = stack[-1];
    v0103 = qcdr(v0103);
    stack[-1] = v0103;
    v0104 = stack[-10];
    v0103 = stack[-1];
    v0103 = CC_modroots1(env, v0104, v0103);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-12];
    stack[0] = v0103;
    v0103 = stack[0];
    if (v0103 == nil) goto v0009;
    v0103 = stack[-10];
    v0103 = qcar(v0103);
    v0103 = qcar(v0103);
    v0103 = qcar(v0103);
    stack[-6] = v0103;
    v0103 = elt(env, 2); // g
    v0103 = Lgensym1(nil, v0103);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-12];
    stack[-5] = v0103;
    v0103 = stack[-1];
    stack[-1] = v0103;
    v0103 = (LispObject)17; // 1
    v0104 = v0103;
    goto v0043;

v0043:
    v0103 = stack[-1];
    if (v0103 == nil) goto v0108;
    v0103 = stack[-1];
    v0103 = qcar(v0103);
    v0103 = times2(v0103, v0104);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-12];
    v0104 = v0103;
    v0103 = stack[-1];
    v0103 = qcdr(v0103);
    stack[-1] = v0103;
    goto v0043;

v0108:
    v0103 = v0104;
    stack[-9] = v0103;
    v0104 = stack[-11];
    v0103 = stack[-9];
    v0103 = times2(v0104, v0103);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-12];
    stack[-8] = v0103;
    v0103 = stack[0];
    stack[-4] = v0103;
    goto v0109;

v0109:
    v0103 = stack[-4];
    if (v0103 == nil) { LispObject res = stack[-7]; popv(13); return onevalue(res); }
    v0103 = stack[-4];
    v0103 = qcar(v0103);
    stack[-3] = v0103;
    stack[-2] = stack[-10];
    stack[-1] = stack[-6];
    stack[0] = elt(env, 3); // plus
    v0105 = elt(env, 4); // times
    v0104 = stack[-5];
    v0103 = stack[-9];
    v0104 = list3(v0105, v0104, v0103);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-12];
    v0103 = stack[-3];
    v0103 = list2(v0104, v0103);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-12];
    v0103 = list2star(stack[-1], stack[0], v0103);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-12];
    v0103 = ncons(v0103);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-12];
    fn = elt(env, 6); // subf
    v0103 = (*qfn2(fn))(qenv(fn), stack[-2], v0103);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-12];
    v0103 = qcar(v0103);
    v0104 = v0103;
    v0103 = stack[-11];
    fn = elt(env, 7); // reduce!-mod!-p!*
    v0105 = (*qfn2(fn))(qenv(fn), v0104, v0103);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-12];
    v0104 = stack[-11];
    v0103 = qvalue(elt(env, 5)); // t
    fn = elt(env, 8); // modroots2
    v0103 = (*qfnn(fn))(qenv(fn), 3, v0105, v0104, v0103);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-12];
    stack[-2] = v0103;
    goto v0110;

v0110:
    v0103 = stack[-2];
    if (v0103 == nil) goto v0111;
    v0103 = stack[-2];
    v0103 = qcar(v0103);
    stack[-1] = v0103;
    v0104 = stack[-1];
    v0103 = stack[-9];
    v0104 = times2(v0104, v0103);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-12];
    v0103 = stack[-3];
    v0104 = plus2(v0104, v0103);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-12];
    v0103 = stack[-8];
    fn = elt(env, 9); // modp
    v0103 = (*qfn2(fn))(qenv(fn), v0104, v0103);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-12];
    stack[-1] = v0103;
    stack[0] = stack[-10];
    v0104 = stack[-6];
    v0103 = stack[-1];
    v0103 = cons(v0104, v0103);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-12];
    v0103 = ncons(v0103);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-12];
    fn = elt(env, 6); // subf
    v0103 = (*qfn2(fn))(qenv(fn), stack[0], v0103);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-12];
    v0104 = qcar(v0103);
    v0103 = stack[-8];
    fn = elt(env, 7); // reduce!-mod!-p!*
    v0103 = (*qfn2(fn))(qenv(fn), v0104, v0103);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-12];
    if (v0103 == nil) goto v0112;
    v0103 = qvalue(elt(env, 1)); // nil
    goto v0113;

v0113:
    if (v0103 == nil) goto v0114;
    v0104 = stack[-1];
    v0103 = stack[-7];
    v0103 = cons(v0104, v0103);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-12];
    stack[-7] = v0103;
    goto v0114;

v0114:
    v0103 = stack[-2];
    v0103 = qcdr(v0103);
    stack[-2] = v0103;
    goto v0110;

v0112:
    v0104 = stack[-1];
    v0103 = stack[-7];
    v0103 = Lmember(nil, v0104, v0103);
    v0103 = (v0103 == nil ? lisp_true : nil);
    goto v0113;

v0111:
    v0103 = stack[-4];
    v0103 = qcdr(v0103);
    stack[-4] = v0103;
    goto v0109;

v0009:
    v0103 = qvalue(elt(env, 1)); // nil
    { popv(13); return onevalue(v0103); }

v0106:
    v0105 = stack[-10];
    v0103 = stack[-1];
    v0104 = qcar(v0103);
    v0103 = qvalue(elt(env, 1)); // nil
    {
        popv(13);
        fn = elt(env, 8); // modroots2
        return (*qfnn(fn))(qenv(fn), 3, v0105, v0104, v0103);
    }
// error exit handlers
v0107:
    popv(13);
    return nil;
}



// Code for simprad

static LispObject CC_simprad(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0150, v0151;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for simprad");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    stack[-3] = v0001;
    stack[0] = v0000;
// end of prologue
    v0150 = qvalue(elt(env, 1)); // !*reduced
    if (v0150 == nil) goto v0051;
    v0150 = stack[0];
    v0151 = qcar(v0150);
    v0150 = stack[-3];
    fn = elt(env, 7); // radfa
    stack[-1] = (*qfn2(fn))(qenv(fn), v0151, v0150);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-6];
    v0150 = stack[0];
    v0151 = qcdr(v0150);
    v0150 = stack[-3];
    fn = elt(env, 7); // radfa
    v0150 = (*qfn2(fn))(qenv(fn), v0151, v0150);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-6];
    fn = elt(env, 8); // invsq
    v0150 = (*qfn1(fn))(qenv(fn), v0150);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-6];
    {
        LispObject v0153 = stack[-1];
        popv(7);
        fn = elt(env, 9); // multsq
        return (*qfn2(fn))(qenv(fn), v0153, v0150);
    }

v0051:
    stack[-4] = nil;
    v0150 = qvalue(elt(env, 2)); // !*rationalize
    if (v0150 == nil) goto v0154;
    v0150 = stack[0];
    v0151 = qcdr(v0150);
    v0150 = (LispObject)17; // 1
    v0150 = list2(v0151, v0150);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-6];
    stack[-1] = v0150;
    v0150 = stack[0];
    stack[-2] = qcar(v0150);
    v0150 = stack[0];
    stack[0] = qcdr(v0150);
    v0150 = stack[-3];
    v0150 = sub1(v0150);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-6];
    fn = elt(env, 10); // exptf
    v0150 = (*qfn2(fn))(qenv(fn), stack[0], v0150);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-6];
    fn = elt(env, 11); // multf
    v0151 = (*qfn2(fn))(qenv(fn), stack[-2], v0150);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-6];
    v0150 = (LispObject)17; // 1
    v0150 = cons(v0151, v0150);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-6];
    stack[0] = v0150;
    goto v0039;

v0039:
    v0151 = stack[-3];
    v0150 = (LispObject)33; // 2
    if (v0151 == v0150) goto v0155;
    v0150 = qvalue(elt(env, 3)); // nil
    goto v0156;

v0156:
    if (v0150 == nil) goto v0157;
    v0150 = qvalue(elt(env, 4)); // t
    stack[-4] = v0150;
    v0150 = stack[0];
    v0150 = qcar(v0150);
    fn = elt(env, 12); // negf
    v0151 = (*qfn1(fn))(qenv(fn), v0150);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-6];
    v0150 = stack[-3];
    fn = elt(env, 13); // radf
    v0150 = (*qfn2(fn))(qenv(fn), v0151, v0150);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-6];
    stack[-2] = v0150;
    goto v0158;

v0158:
    stack[-5] = elt(env, 5); // quotient
    v0150 = stack[-2];
    v0150 = qcdr(v0150);
    fn = elt(env, 14); // retimes
    stack[0] = (*qfn1(fn))(qenv(fn), v0150);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-6];
    v0150 = stack[-1];
    v0150 = qcdr(v0150);
    fn = elt(env, 14); // retimes
    v0150 = (*qfn1(fn))(qenv(fn), v0150);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-6];
    v0150 = list3(stack[-5], stack[0], v0150);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-6];
    fn = elt(env, 15); // simp
    v0150 = (*qfn1(fn))(qenv(fn), v0150);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-6];
    stack[-5] = v0150;
    v0150 = stack[-5];
    v0150 = qcar(v0150);
    if (!consp(v0150)) goto v0083;
    v0150 = stack[-5];
    v0150 = qcar(v0150);
    v0150 = qcar(v0150);
    v0150 = (consp(v0150) ? nil : lisp_true);
    goto v0159;

v0159:
    if (v0150 == nil) goto v0160;
    v0150 = stack[-5];
    v0150 = qcdr(v0150);
    if (!consp(v0150)) goto v0161;
    v0150 = stack[-5];
    v0150 = qcdr(v0150);
    v0150 = qcar(v0150);
    v0150 = (consp(v0150) ? nil : lisp_true);
    goto v0162;

v0162:
    if (v0150 == nil) goto v0163;
    v0150 = stack[-5];
    v0150 = qcar(v0150);
    fn = elt(env, 16); // prepf
    v0151 = (*qfn1(fn))(qenv(fn), v0150);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-6];
    v0150 = stack[-3];
    fn = elt(env, 17); // mkrootsq
    stack[0] = (*qfn2(fn))(qenv(fn), v0151, v0150);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-6];
    v0150 = stack[-5];
    v0150 = qcdr(v0150);
    fn = elt(env, 16); // prepf
    v0151 = (*qfn1(fn))(qenv(fn), v0150);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-6];
    v0150 = stack[-3];
    fn = elt(env, 17); // mkrootsq
    v0150 = (*qfn2(fn))(qenv(fn), v0151, v0150);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-6];
    fn = elt(env, 8); // invsq
    v0150 = (*qfn1(fn))(qenv(fn), v0150);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-6];
    fn = elt(env, 9); // multsq
    v0150 = (*qfn2(fn))(qenv(fn), stack[0], v0150);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-6];
    stack[-5] = v0150;
    goto v0164;

v0164:
    v0150 = qvalue(elt(env, 6)); // !*precise
    if (v0150 == nil) goto v0165;
    v0150 = stack[-3];
    v0150 = Levenp(nil, v0150);
    env = stack[-6];
    if (v0150 == nil) goto v0165;
    v0150 = stack[-2];
    v0151 = qcar(v0150);
    v0150 = (LispObject)17; // 1
    v0150 = cons(v0151, v0150);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-6];
    stack[0] = v0150;
    goto v0166;

v0166:
    v0151 = (LispObject)17; // 1
    v0150 = stack[-1];
    v0150 = qcar(v0150);
    v0150 = cons(v0151, v0150);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-6];
    fn = elt(env, 9); // multsq
    v0151 = (*qfn2(fn))(qenv(fn), stack[0], v0150);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-6];
    v0150 = stack[-5];
    fn = elt(env, 9); // multsq
    v0150 = (*qfn2(fn))(qenv(fn), v0151, v0150);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-6];
    stack[-5] = v0150;
    v0150 = stack[-4];
    if (v0150 == nil) { LispObject res = stack[-5]; popv(7); return onevalue(res); }
    stack[0] = stack[-5];
    v0151 = (LispObject)-15; // -1
    v0150 = (LispObject)33; // 2
    fn = elt(env, 17); // mkrootsq
    v0150 = (*qfn2(fn))(qenv(fn), v0151, v0150);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-6];
    fn = elt(env, 9); // multsq
    v0150 = (*qfn2(fn))(qenv(fn), stack[0], v0150);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    stack[-5] = v0150;
    { LispObject res = stack[-5]; popv(7); return onevalue(res); }

v0165:
    v0150 = stack[-2];
    v0151 = qcar(v0150);
    v0150 = (LispObject)17; // 1
    v0150 = cons(v0151, v0150);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-6];
    stack[0] = v0150;
    goto v0166;

v0163:
    v0150 = stack[-4];
    if (v0150 == nil) goto v0064;
    v0150 = qvalue(elt(env, 3)); // nil
    stack[-4] = v0150;
    v0150 = stack[-5];
    fn = elt(env, 18); // negsq
    v0150 = (*qfn1(fn))(qenv(fn), v0150);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-6];
    stack[-5] = v0150;
    goto v0064;

v0064:
    v0150 = stack[-5];
    fn = elt(env, 19); // prepsq
    v0151 = (*qfn1(fn))(qenv(fn), v0150);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-6];
    v0150 = stack[-3];
    fn = elt(env, 17); // mkrootsq
    v0150 = (*qfn2(fn))(qenv(fn), v0151, v0150);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-6];
    stack[-5] = v0150;
    goto v0164;

v0161:
    v0150 = qvalue(elt(env, 4)); // t
    goto v0162;

v0160:
    v0150 = qvalue(elt(env, 3)); // nil
    goto v0162;

v0083:
    v0150 = qvalue(elt(env, 4)); // t
    goto v0159;

v0157:
    v0150 = stack[0];
    v0151 = qcar(v0150);
    v0150 = stack[-3];
    fn = elt(env, 13); // radf
    v0150 = (*qfn2(fn))(qenv(fn), v0151, v0150);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-6];
    stack[-2] = v0150;
    goto v0158;

v0155:
    v0150 = stack[0];
    v0150 = qcar(v0150);
    fn = elt(env, 20); // minusf
    v0150 = (*qfn1(fn))(qenv(fn), v0150);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-6];
    goto v0156;

v0154:
    v0150 = stack[0];
    v0151 = qcdr(v0150);
    v0150 = stack[-3];
    fn = elt(env, 13); // radf
    v0150 = (*qfn2(fn))(qenv(fn), v0151, v0150);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-6];
    stack[-1] = v0150;
    goto v0039;
// error exit handlers
v0152:
    popv(7);
    return nil;
}



// Code for crn!:zerop

static LispObject CC_crnTzerop(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0050, v0146, v0147;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for crn:zerop");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0147 = v0000;
// end of prologue
    v0050 = v0147;
    v0050 = qcdr(v0050);
    v0050 = qcar(v0050);
    v0146 = qcar(v0050);
    v0050 = (LispObject)1; // 0
    if (v0146 == v0050) goto v0025;
    v0050 = qvalue(elt(env, 1)); // nil
    return onevalue(v0050);

v0025:
    v0050 = v0147;
    v0050 = qcdr(v0050);
    v0050 = qcdr(v0050);
    v0146 = qcar(v0050);
    v0050 = (LispObject)1; // 0
    v0050 = (v0146 == v0050 ? lisp_true : nil);
    return onevalue(v0050);
}



// Code for odd_action

static LispObject CC_odd_action(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0086, v0087, v0173;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for odd_action");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0001;
    stack[-7] = v0000;
// end of prologue
    v0087 = qvalue(elt(env, 1)); // nil
    v0086 = (LispObject)17; // 1
    v0086 = cons(v0087, v0086);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-9];
    stack[-1] = v0086;
    v0086 = stack[0];
    stack[-4] = v0086;
    goto v0149;

v0149:
    v0086 = stack[-4];
    if (v0086 == nil) { LispObject res = stack[-1]; popv(10); return onevalue(res); }
    v0086 = stack[-4];
    v0086 = qcar(v0086);
    v0087 = v0086;
    v0086 = v0087;
    v0086 = qcar(v0086);
    stack[-6] = v0086;
    v0086 = v0087;
    v0087 = qcdr(v0086);
    v0086 = (LispObject)17; // 1
    v0086 = cons(v0087, v0086);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-9];
    stack[-5] = v0086;
    v0086 = qvalue(elt(env, 2)); // t
    stack[-8] = v0086;
    v0086 = stack[-6];
    v0086 = qcdr(v0086);
    stack[-3] = v0086;
    goto v0010;

v0010:
    v0086 = stack[-3];
    if (v0086 == nil) goto v0009;
    v0086 = stack[-3];
    v0086 = qcar(v0086);
    stack[0] = v0086;
    v0086 = stack[-8];
    v0086 = (v0086 == nil ? lisp_true : nil);
    stack[-8] = v0086;
    v0087 = stack[0];
    v0086 = stack[-6];
    v0086 = Ldelete(nil, v0087, v0086);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-9];
    fn = elt(env, 3); // !*a2k
    v0086 = (*qfn1(fn))(qenv(fn), v0086);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-9];
    v0173 = v0086;
    v0087 = stack[0];
    v0086 = stack[-7];
    v0086 = Lassoc(nil, v0087, v0086);
    stack[-2] = stack[-1];
    stack[-1] = v0086;
    stack[0] = v0173;
    v0086 = stack[-8];
    if (v0086 == nil) goto v0174;
    v0086 = stack[-5];
    fn = elt(env, 4); // negsq
    v0086 = (*qfn1(fn))(qenv(fn), v0086);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-9];
    goto v0175;

v0175:
    fn = elt(env, 5); // component_action
    v0086 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v0086);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-9];
    fn = elt(env, 6); // addsq
    v0086 = (*qfn2(fn))(qenv(fn), stack[-2], v0086);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-9];
    stack[-1] = v0086;
    v0086 = stack[-3];
    v0086 = qcdr(v0086);
    stack[-3] = v0086;
    goto v0010;

v0174:
    v0086 = stack[-5];
    goto v0175;

v0009:
    v0086 = stack[-4];
    v0086 = qcdr(v0086);
    stack[-4] = v0086;
    goto v0149;
// error exit handlers
v0089:
    popv(10);
    return nil;
}



// Code for gd_applyscheme

static LispObject CC_gd_applyscheme(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0177, v0023, v0024;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gd_applyscheme");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-2] = v0001;
    stack[-3] = v0000;
// end of prologue
    stack[-4] = nil;
    v0177 = (LispObject)1; // 0
    stack[-1] = v0177;
    v0177 = stack[-2];
    stack[0] = v0177;
    goto v0178;

v0178:
    v0177 = stack[0];
    if (v0177 == nil) goto v0010;
    v0177 = stack[-1];
    v0177 = add1(v0177);
    nil = C_nil;
    if (exception_pending()) goto v0044;
    env = stack[-5];
    stack[-1] = v0177;
    v0023 = elt(env, 2); // a
    v0177 = stack[-1];
    fn = elt(env, 3); // mkid
    v0024 = (*qfn2(fn))(qenv(fn), v0023, v0177);
    nil = C_nil;
    if (exception_pending()) goto v0044;
    env = stack[-5];
    v0177 = stack[-2];
    v0023 = qcar(v0177);
    v0177 = stack[-4];
    v0177 = acons(v0024, v0023, v0177);
    nil = C_nil;
    if (exception_pending()) goto v0044;
    env = stack[-5];
    stack[-4] = v0177;
    v0177 = stack[-2];
    v0177 = qcdr(v0177);
    stack[-2] = v0177;
    v0177 = stack[0];
    v0177 = qcdr(v0177);
    stack[0] = v0177;
    goto v0178;

v0010:
    stack[0] = stack[-4];
    v0023 = stack[-3];
    v0177 = stack[-1];
    fn = elt(env, 4); // gd_getscheme
    v0177 = (*qfn2(fn))(qenv(fn), v0023, v0177);
    nil = C_nil;
    if (exception_pending()) goto v0044;
    {
        LispObject v0179 = stack[0];
        popv(6);
        return Lsublis(nil, v0179, v0177);
    }
// error exit handlers
v0044:
    popv(6);
    return nil;
}



// Code for ps!:constmult!-erule

static LispObject CC_psTconstmultKerule(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0085, v0082, v0017;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ps:constmult-erule");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0082 = v0001;
    v0017 = v0000;
// end of prologue
    v0085 = v0017;
    v0085 = qcdr(v0085);
    stack[0] = qcar(v0085);
    v0085 = v0017;
    v0085 = qcdr(v0085);
    v0085 = qcdr(v0085);
    v0085 = qcar(v0085);
    fn = elt(env, 1); // ps!:evaluate
    v0085 = (*qfn2(fn))(qenv(fn), v0085, v0082);
    nil = C_nil;
    if (exception_pending()) goto v0004;
    env = stack[-1];
    {
        LispObject v0005 = stack[0];
        popv(2);
        fn = elt(env, 2); // multsq
        return (*qfn2(fn))(qenv(fn), v0005, v0085);
    }
// error exit handlers
v0004:
    popv(2);
    return nil;
}



// Code for redpar

static LispObject CC_redpar(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0020, v0176;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for redpar");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0001;
    stack[-1] = v0000;
// end of prologue
    stack[-2] = nil;
    goto v0021;

v0021:
    v0020 = stack[0];
    if (v0020 == nil) goto v0013;
    v0020 = stack[0];
    v0176 = qcar(v0020);
    v0020 = stack[-1];
    v0020 = Lmember(nil, v0176, v0020);
    if (v0020 == nil) goto v0003;
    v0020 = stack[0];
    v0176 = qcar(v0020);
    v0020 = stack[-1];
    v0020 = Ldelete(nil, v0176, v0020);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-3];
    stack[-1] = v0020;
    goto v0025;

v0025:
    v0020 = stack[0];
    v0020 = qcdr(v0020);
    stack[0] = v0020;
    goto v0021;

v0003:
    v0020 = stack[0];
    v0176 = qcar(v0020);
    v0020 = stack[-2];
    v0020 = cons(v0176, v0020);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-3];
    stack[-2] = v0020;
    goto v0025;

v0013:
    stack[0] = stack[-1];
    v0020 = stack[-2];
    v0020 = Lreverse(nil, v0020);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    {
        LispObject v0181 = stack[0];
        popv(4);
        return list2(v0181, v0020);
    }
// error exit handlers
v0024:
    popv(4);
    return nil;
}



// Code for implicitdec

static LispObject CC_implicitdec(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0046, v0143;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for implicitdec");
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
    v0046 = qvalue(elt(env, 1)); // nil
    stack[0] = v0046;
    v0143 = qvalue(elt(env, 1)); // nil
    v0046 = elt(env, 2); // !*decs!*
    fn = elt(env, 3); // symtabget
    v0046 = (*qfn2(fn))(qenv(fn), v0143, v0046);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-3];
    stack[-2] = v0046;
    goto v0102;

v0102:
    v0046 = stack[0];
    if (v0046 == nil) goto v0082;
    v0046 = qvalue(elt(env, 1)); // nil
    goto v0085;

v0085:
    if (v0046 == nil) { LispObject res = stack[0]; popv(4); return onevalue(res); }
    v0046 = stack[-2];
    v0046 = qcar(v0046);
    v0046 = qcdr(v0046);
    v0046 = qcar(v0046);
    fn = elt(env, 4); // isimplicit
    v0046 = (*qfn1(fn))(qenv(fn), v0046);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-3];
    if (v0046 == nil) goto v0051;
    v0143 = stack[-1];
    v0046 = stack[-2];
    v0046 = qcar(v0046);
    v0046 = qcar(v0046);
    fn = elt(env, 5); // firstmatch
    v0046 = (*qfn2(fn))(qenv(fn), v0143, v0046);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-3];
    if (v0046 == nil) goto v0051;
    stack[0] = stack[-1];
    v0046 = stack[-2];
    v0046 = qcar(v0046);
    v0046 = qcdr(v0046);
    v0046 = qcar(v0046);
    fn = elt(env, 6); // implicittype
    v0046 = (*qfn1(fn))(qenv(fn), v0046);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-3];
    v0046 = list2(stack[0], v0046);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-3];
    stack[0] = v0046;
    goto v0051;

v0051:
    v0046 = stack[-2];
    v0046 = qcdr(v0046);
    stack[-2] = v0046;
    goto v0102;

v0082:
    v0046 = stack[-2];
    goto v0085;
// error exit handlers
v0182:
    popv(4);
    return nil;
}



// Code for dipcontenti1

static LispObject CC_dipcontenti1(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0183, v0182, v0035;
    LispObject fn;
    LispObject v0015, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "dipcontenti1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0015 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dipcontenti1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0015,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0015;
    stack[-1] = v0001;
    v0182 = v0000;
// end of prologue

v0184:
    v0183 = stack[0];
    if (v0183 == nil) goto v0006;
    v0183 = stack[0];
    v0183 = qcdr(v0183);
    v0183 = qcar(v0183);
    fn = elt(env, 1); // vbcgcd
    v0183 = (*qfn2(fn))(qenv(fn), v0182, v0183);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-3];
    stack[-2] = v0183;
    v0183 = stack[-1];
    if (v0183 == nil) goto v0051;
    v0183 = stack[0];
    v0182 = qcar(v0183);
    v0183 = stack[-1];
    fn = elt(env, 2); // dipcontevmin
    v0183 = (*qfn2(fn))(qenv(fn), v0182, v0183);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-3];
    stack[-1] = v0183;
    goto v0051;

v0051:
    v0183 = stack[-2];
    fn = elt(env, 3); // bcone!?
    v0183 = (*qfn1(fn))(qenv(fn), v0183);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-3];
    if (v0183 == nil) goto v0176;
    v0183 = stack[-1];
    if (!(v0183 == nil)) goto v0176;
    v0183 = stack[-2];
    popv(4);
    return ncons(v0183);

v0176:
    v0182 = stack[-2];
    v0035 = stack[-1];
    v0183 = stack[0];
    v0183 = qcdr(v0183);
    v0183 = qcdr(v0183);
    stack[-1] = v0035;
    stack[0] = v0183;
    goto v0184;

v0006:
    v0183 = stack[-1];
    popv(4);
    return cons(v0182, v0183);
// error exit handlers
v0185:
    popv(4);
    return nil;
}



// Code for remove_root_item

static LispObject CC_remove_root_item(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0179, v0183;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for remove_root_item");
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
    v0179 = stack[-1];
    v0179 = qcdr(v0179);
    v0179 = qcar(v0179);
    stack[-2] = v0179;
    v0179 = stack[-1];
    v0179 = qcar(v0179);
    stack[0] = v0179;
    v0183 = stack[-1];
    v0179 = stack[-1];
    v0179 = qcdr(v0179);
    v0179 = qcdr(v0179);
    v0179 = qcar(v0179);
    fn = elt(env, 2); // setcar
    v0179 = (*qfn2(fn))(qenv(fn), v0183, v0179);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-3];
    v0183 = stack[-1];
    v0179 = stack[-1];
    v0179 = qcdr(v0179);
    v0179 = qcdr(v0179);
    v0179 = qcdr(v0179);
    fn = elt(env, 3); // setcdr
    v0179 = (*qfn2(fn))(qenv(fn), v0183, v0179);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-3];
    v0179 = stack[-2];
    v0179 = qcdr(v0179);
    if (v0179 == nil) { LispObject res = stack[0]; popv(4); return onevalue(res); }
    else goto v0048;

v0048:
    v0179 = stack[-1];
    v0179 = qcdr(v0179);
    if (v0179 == nil) goto v0042;
    v0179 = stack[-1];
    v0179 = qcdr(v0179);
    v0179 = qcar(v0179);
    stack[-1] = v0179;
    goto v0048;

v0042:
    v0183 = stack[-1];
    v0179 = stack[-2];
    v0179 = qcar(v0179);
    fn = elt(env, 2); // setcar
    v0179 = (*qfn2(fn))(qenv(fn), v0183, v0179);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-3];
    v0183 = stack[-1];
    v0179 = stack[-2];
    v0179 = qcdr(v0179);
    fn = elt(env, 3); // setcdr
    v0179 = (*qfn2(fn))(qenv(fn), v0183, v0179);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    { LispObject res = stack[0]; popv(4); return onevalue(res); }
// error exit handlers
v0036:
    popv(4);
    return nil;
}



// Code for bfdivide

static LispObject CC_bfdivide(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0050, v0146, v0147;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for bfdivide");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// copy arguments values to proper place
    v0146 = v0001;
    v0147 = v0000;
// end of prologue
    v0050 = v0147;
    if (!consp(v0050)) goto v0186;
    v0050 = qvalue(elt(env, 1)); // !:bprec!:
    fn = elt(env, 2); // divide!:
    v0050 = (*qfnn(fn))(qenv(fn), 3, v0147, v0146, v0050);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); // normbf
        return (*qfn1(fn))(qenv(fn), v0050);
    }

v0186:
    v0050 = v0147;
    popv(1);
    return quot2(v0050, v0146);
// error exit handlers
v0051:
    popv(1);
    return nil;
}



// Code for ev!-tades

static LispObject CC_evKtades(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0011, v0016, v0013;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ev-tades");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0001;
    stack[-1] = v0000;
// end of prologue
    stack[-2] = nil;
    goto v0171;

v0171:
    v0011 = stack[-1];
    if (v0011 == nil) goto v0007;
    v0013 = qvalue(elt(env, 1)); // ndim!*
    v0011 = stack[-1];
    v0016 = qcar(v0011);
    v0011 = stack[0];
    v0011 = Lassoc(nil, v0016, v0011);
    v0011 = qcdr(v0011);
    fn = elt(env, 2); // binc
    v0016 = (*qfn2(fn))(qenv(fn), v0013, v0011);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[-3];
    v0011 = stack[-2];
    v0011 = cons(v0016, v0011);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[-3];
    stack[-2] = v0011;
    v0011 = stack[-1];
    v0011 = qcdr(v0011);
    stack[-1] = v0011;
    goto v0171;

v0007:
    stack[0] = stack[-2];
    v0011 = (LispObject)17; // 1
    v0011 = ncons(v0011);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[-3];
    {
        LispObject v0180 = stack[0];
        popv(4);
        fn = elt(env, 3); // nreverse
        return (*qfn2(fn))(qenv(fn), v0180, v0011);
    }
// error exit handlers
v0014:
    popv(4);
    return nil;
}



// Code for !*sf2ex

static LispObject CC_Hsf2ex(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0056, v0167, v0168;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *sf2ex");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0001;
    stack[-1] = v0000;
// end of prologue
    stack[-2] = nil;
    goto v0171;

v0171:
    v0056 = stack[-1];
    if (v0056 == nil) goto v0186;
    v0056 = stack[-1];
    if (!consp(v0056)) goto v0149;
    v0056 = stack[-1];
    v0056 = qcar(v0056);
    v0056 = (consp(v0056) ? nil : lisp_true);
    goto v0148;

v0148:
    if (v0056 == nil) goto v0188;
    v0056 = qvalue(elt(env, 1)); // t
    goto v0102;

v0102:
    if (v0056 == nil) goto v0108;
    stack[0] = stack[-2];
    v0056 = qvalue(elt(env, 2)); // nil
    v0167 = ncons(v0056);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-3];
    v0056 = stack[-1];
    v0056 = cons(v0167, v0056);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-3];
    v0056 = ncons(v0056);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-3];
    {
        LispObject v0040 = stack[0];
        popv(4);
        fn = elt(env, 3); // nreverse
        return (*qfn2(fn))(qenv(fn), v0040, v0056);
    }

v0108:
    v0056 = stack[-1];
    v0056 = qcar(v0056);
    v0056 = qcar(v0056);
    v0056 = qcar(v0056);
    v0168 = ncons(v0056);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-3];
    v0056 = stack[-1];
    v0056 = qcar(v0056);
    v0167 = qcdr(v0056);
    v0056 = stack[-2];
    v0056 = acons(v0168, v0167, v0056);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-3];
    stack[-2] = v0056;
    v0056 = stack[-1];
    v0056 = qcdr(v0056);
    stack[-1] = v0056;
    goto v0171;

v0188:
    v0056 = stack[-1];
    v0056 = qcar(v0056);
    v0056 = qcar(v0056);
    v0167 = qcar(v0056);
    v0056 = stack[0];
    v0056 = Lmemq(nil, v0167, v0056);
    v0056 = (v0056 == nil ? lisp_true : nil);
    goto v0102;

v0149:
    v0056 = qvalue(elt(env, 1)); // t
    goto v0148;

v0186:
    v0056 = stack[-2];
    {
        popv(4);
        fn = elt(env, 3); // nreverse
        return (*qfn1(fn))(qenv(fn), v0056);
    }
// error exit handlers
v0097:
    popv(4);
    return nil;
}



// Code for dp_prod

static LispObject CC_dp_prod(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0055, v0128;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dp_prod");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0001;
    stack[-1] = v0000;
// end of prologue
    v0055 = stack[-1];
    stack[-2] = Llength(nil, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    env = stack[-3];
    v0055 = stack[0];
    v0055 = Llength(nil, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    env = stack[-3];
    v0055 = (LispObject)lesseq2(stack[-2], v0055);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    v0055 = v0055 ? lisp_true : nil;
    env = stack[-3];
    if (v0055 == nil) goto v0005;
    v0128 = stack[-1];
    v0055 = stack[0];
    {
        popv(4);
        fn = elt(env, 1); // dp!=prod
        return (*qfn2(fn))(qenv(fn), v0128, v0055);
    }

v0005:
    v0128 = stack[0];
    v0055 = stack[-1];
    {
        popv(4);
        fn = elt(env, 1); // dp!=prod
        return (*qfn2(fn))(qenv(fn), v0128, v0055);
    }
// error exit handlers
v0003:
    popv(4);
    return nil;
}



// Code for boolean!-eval2

static LispObject CC_booleanKeval2(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0192, v0193, v0194;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for boolean-eval2");
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

v0106:
    v0193 = stack[0];
    v0192 = elt(env, 1); // boolean
    if (!consp(v0193)) goto v0004;
    v0193 = qcar(v0193);
    if (!(v0193 == v0192)) goto v0004;
    v0192 = stack[0];
    v0192 = qcdr(v0192);
    v0192 = qcar(v0192);
    stack[0] = v0192;
    goto v0106;

v0004:
    v0193 = stack[0];
    v0192 = elt(env, 2); // and
    if (!consp(v0193)) goto v0049;
    v0193 = qcar(v0193);
    if (!(v0193 == v0192)) goto v0049;
    v0192 = qvalue(elt(env, 3)); // t
    goto v0085;

v0085:
    if (v0192 == nil) goto v0086;
    v0192 = stack[0];
    stack[-4] = qcar(v0192);
    v0192 = stack[0];
    v0192 = qcdr(v0192);
    stack[-3] = v0192;
    v0192 = stack[-3];
    if (v0192 == nil) goto v0185;
    v0192 = stack[-3];
    v0192 = qcar(v0192);
    v0192 = CC_booleanKeval2(env, v0192);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-5];
    v0192 = ncons(v0192);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-5];
    stack[-1] = v0192;
    stack[-2] = v0192;
    goto v0182;

v0182:
    v0192 = stack[-3];
    v0192 = qcdr(v0192);
    stack[-3] = v0192;
    v0192 = stack[-3];
    if (v0192 == nil) goto v0175;
    stack[0] = stack[-1];
    v0192 = stack[-3];
    v0192 = qcar(v0192);
    v0192 = CC_booleanKeval2(env, v0192);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-5];
    v0192 = ncons(v0192);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-5];
    v0192 = Lrplacd(nil, stack[0], v0192);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-5];
    v0192 = stack[-1];
    v0192 = qcdr(v0192);
    stack[-1] = v0192;
    goto v0182;

v0175:
    v0192 = stack[-2];
    goto v0024;

v0024:
    {
        LispObject v0083 = stack[-4];
        popv(6);
        return cons(v0083, v0192);
    }

v0185:
    v0192 = qvalue(elt(env, 6)); // nil
    goto v0024;

v0086:
    v0192 = qvalue(elt(env, 3)); // t
    stack[-1] = qvalue(elt(env, 7)); // !*protfg
    qvalue(elt(env, 7)) = v0192; // !*protfg
    v0194 = stack[0];
    v0193 = qvalue(elt(env, 6)); // nil
    v0192 = elt(env, 8); // algebraic
    fn = elt(env, 11); // formbool
    v0194 = (*qfnn(fn))(qenv(fn), 3, v0194, v0193, v0192);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    env = stack[-5];
    v0193 = qvalue(elt(env, 6)); // nil
    v0192 = qvalue(elt(env, 6)); // nil
    fn = elt(env, 12); // errorset
    v0192 = (*qfnn(fn))(qenv(fn), 3, v0194, v0193, v0192);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    env = stack[-5];
    stack[-2] = v0192;
    qvalue(elt(env, 7)) = stack[-1]; // !*protfg
    v0192 = stack[-2];
    fn = elt(env, 13); // errorp
    v0192 = (*qfn1(fn))(qenv(fn), v0192);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-5];
    if (v0192 == nil) goto v0138;
    v0192 = qvalue(elt(env, 3)); // t
    qvalue(elt(env, 9)) = v0192; // bool!-break!*
    v0192 = qvalue(elt(env, 6)); // nil
    qvalue(elt(env, 10)) = v0192; // erfg!*
    { LispObject res = stack[0]; popv(6); return onevalue(res); }

v0138:
    v0192 = stack[-2];
    v0192 = qcar(v0192);
    { popv(6); return onevalue(v0192); }

v0049:
    v0193 = stack[0];
    v0192 = elt(env, 4); // or
    if (!consp(v0193)) goto v0042;
    v0193 = qcar(v0193);
    if (!(v0193 == v0192)) goto v0042;
    v0192 = qvalue(elt(env, 3)); // t
    goto v0085;

v0042:
    v0193 = stack[0];
    v0192 = elt(env, 5); // not
    v0192 = Leqcar(nil, v0193, v0192);
    env = stack[-5];
    goto v0085;
// error exit handlers
v0084:
    env = stack[-5];
    qvalue(elt(env, 7)) = stack[-1]; // !*protfg
    popv(6);
    return nil;
v0159:
    popv(6);
    return nil;
}



// Code for sqlessp

static LispObject CC_sqlessp(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0082, v0017;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sqlessp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0082 = v0001;
    v0017 = v0000;
// end of prologue
    stack[0] = v0017;
    fn = elt(env, 2); // negsq
    v0082 = (*qfn1(fn))(qenv(fn), v0082);
    nil = C_nil;
    if (exception_pending()) goto v0004;
    env = stack[-1];
    fn = elt(env, 3); // addsq
    v0082 = (*qfn2(fn))(qenv(fn), stack[0], v0082);
    nil = C_nil;
    if (exception_pending()) goto v0004;
    env = stack[-1];
    v0082 = qcar(v0082);
    v0017 = v0082;
    v0082 = v0017;
    if (v0082 == nil) goto v0025;
    v0082 = v0017;
    {
        popv(2);
        fn = elt(env, 4); // !:minusp
        return (*qfn1(fn))(qenv(fn), v0082);
    }

v0025:
    v0082 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0082); }
// error exit handlers
v0004:
    popv(2);
    return nil;
}



// Code for gfminus

static LispObject CC_gfminus(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0026;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gfminus");
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
    v0026 = stack[0];
    v0026 = qcar(v0026);
    fn = elt(env, 1); // bfminus
    stack[-1] = (*qfn1(fn))(qenv(fn), v0026);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-2];
    v0026 = stack[0];
    v0026 = qcdr(v0026);
    fn = elt(env, 1); // bfminus
    v0026 = (*qfn1(fn))(qenv(fn), v0026);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    {
        LispObject v0028 = stack[-1];
        popv(3);
        return cons(v0028, v0026);
    }
// error exit handlers
v0102:
    popv(3);
    return nil;
}



// Code for gcd!-mod!-p

static LispObject CC_gcdKmodKp(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0144, v0185, v0057, v0098;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gcd-mod-p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0057 = v0001;
    v0098 = v0000;
// end of prologue
    v0144 = (LispObject)1; // 0
    qvalue(elt(env, 1)) = v0144; // reduction!-count
    v0144 = v0098;
    if (v0144 == nil) goto v0171;
    v0144 = v0057;
    if (v0144 == nil) goto v0178;
    v0144 = v0098;
    if (!consp(v0144)) goto v0022;
    v0144 = v0098;
    v0144 = qcar(v0144);
    v0144 = (consp(v0144) ? nil : lisp_true);
    goto v0029;

v0029:
    if (v0144 == nil) goto v0102;
    v0144 = (LispObject)17; // 1
    return onevalue(v0144);

v0102:
    v0144 = v0057;
    if (!consp(v0144)) goto v0188;
    v0144 = v0057;
    v0144 = qcar(v0144);
    v0144 = (consp(v0144) ? nil : lisp_true);
    goto v0051;

v0051:
    if (v0144 == nil) goto v0008;
    v0144 = (LispObject)17; // 1
    return onevalue(v0144);

v0008:
    v0144 = v0098;
    v0144 = qcar(v0144);
    v0144 = qcar(v0144);
    v0185 = qcdr(v0144);
    v0144 = v0057;
    v0144 = qcar(v0144);
    v0144 = qcar(v0144);
    v0144 = qcdr(v0144);
    if (((int32_t)(v0185)) > ((int32_t)(v0144))) goto v0176;
    v0144 = v0057;
    v0185 = v0098;
    {
        fn = elt(env, 3); // ordered!-gcd!-mod!-p
        return (*qfn2(fn))(qenv(fn), v0144, v0185);
    }

v0176:
    v0144 = v0098;
    v0185 = v0057;
    {
        fn = elt(env, 3); // ordered!-gcd!-mod!-p
        return (*qfn2(fn))(qenv(fn), v0144, v0185);
    }

v0188:
    v0144 = qvalue(elt(env, 2)); // t
    goto v0051;

v0022:
    v0144 = qvalue(elt(env, 2)); // t
    goto v0029;

v0178:
    v0144 = v0098;
    {
        fn = elt(env, 4); // monic!-mod!-p
        return (*qfn1(fn))(qenv(fn), v0144);
    }

v0171:
    v0144 = v0057;
    {
        fn = elt(env, 4); // monic!-mod!-p
        return (*qfn1(fn))(qenv(fn), v0144);
    }
}



// Code for gcdlist1

static LispObject CC_gcdlist1(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0211, v0212, v0115;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gcdlist1");
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
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0000;
// end of prologue
    stack[-6] = qvalue(elt(env, 1)); // reduction!-count
    qvalue(elt(env, 1)) = nil; // reduction!-count
    v0211 = stack[0];
    v0211 = qcar(v0211);
    v0211 = qcdr(v0211);
    stack[-4] = v0211;
    stack[-2] = v0211;
    v0211 = stack[0];
    v0211 = qcdr(v0211);
    stack[-3] = v0211;
    goto v0025;

v0025:
    v0211 = stack[-3];
    if (v0211 == nil) goto v0027;
    v0211 = stack[-3];
    v0211 = qcar(v0211);
    stack[-1] = v0211;
    v0212 = stack[-2];
    v0211 = stack[-1];
    v0211 = qcdr(v0211);
    fn = elt(env, 4); // vunion
    v0211 = (*qfn2(fn))(qenv(fn), v0212, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-7];
    stack[-2] = v0211;
    v0212 = stack[-4];
    v0211 = stack[-1];
    v0211 = qcdr(v0211);
    fn = elt(env, 5); // vintersection
    v0211 = (*qfn2(fn))(qenv(fn), v0212, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-7];
    stack[-4] = v0211;
    v0211 = stack[-3];
    v0211 = qcdr(v0211);
    stack[-3] = v0211;
    goto v0025;

v0027:
    v0211 = stack[-4];
    if (v0211 == nil) goto v0016;
    v0211 = stack[-4];
    stack[-1] = v0211;
    goto v0099;

v0099:
    v0211 = stack[-1];
    if (v0211 == nil) goto v0057;
    v0211 = stack[-1];
    v0211 = qcar(v0211);
    v0212 = v0211;
    v0211 = stack[-2];
    fn = elt(env, 6); // vdelete
    v0211 = (*qfn2(fn))(qenv(fn), v0212, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-7];
    stack[-2] = v0211;
    v0211 = stack[-1];
    v0211 = qcdr(v0211);
    stack[-1] = v0211;
    goto v0099;

v0057:
    v0212 = stack[-4];
    v0211 = elt(env, 3); // lesspcdr
    fn = elt(env, 7); // sort
    v0211 = (*qfn2(fn))(qenv(fn), v0212, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-7];
    stack[-4] = v0211;
    v0211 = stack[-4];
    v0211 = qcar(v0211);
    v0212 = qcdr(v0211);
    v0211 = (LispObject)17; // 1
    if (v0212 == v0211) goto v0213;
    v0211 = stack[-2];
    if (v0211 == nil) goto v0060;
    v0212 = stack[-2];
    v0211 = stack[-4];
    v0211 = Lappend(nil, v0212, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-7];
    fn = elt(env, 8); // mapcarcar
    v0211 = (*qfn1(fn))(qenv(fn), v0211);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-7];
    fn = elt(env, 9); // setkorder
    v0211 = (*qfn1(fn))(qenv(fn), v0211);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-7];
    stack[-5] = v0211;
    v0211 = qvalue(elt(env, 2)); // nil
    stack[-4] = v0211;
    v0211 = stack[0];
    stack[-1] = v0211;
    goto v0074;

v0074:
    v0211 = stack[-1];
    if (v0211 == nil) goto v0077;
    v0211 = stack[-1];
    v0211 = qcar(v0211);
    v0211 = qcar(v0211);
    fn = elt(env, 10); // reorder
    stack[0] = (*qfn1(fn))(qenv(fn), v0211);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-7];
    v0211 = stack[-2];
    fn = elt(env, 8); // mapcarcar
    v0212 = (*qfn1(fn))(qenv(fn), v0211);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-7];
    v0211 = stack[-4];
    fn = elt(env, 11); // split!-wrt!-variables
    v0211 = (*qfnn(fn))(qenv(fn), 3, stack[0], v0212, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-7];
    stack[-4] = v0211;
    v0211 = stack[-1];
    v0211 = qcdr(v0211);
    stack[-1] = v0211;
    goto v0074;

v0077:
    v0211 = stack[-5];
    fn = elt(env, 9); // setkorder
    v0211 = (*qfn1(fn))(qenv(fn), v0211);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-7];
    v0211 = stack[-4];
    stack[-5] = v0211;
    v0211 = stack[-5];
    if (v0211 == nil) goto v0062;
    v0211 = stack[-5];
    v0211 = qcar(v0211);
    stack[-1] = v0211;
    v0211 = stack[-1];
    fn = elt(env, 10); // reorder
    stack[0] = (*qfn1(fn))(qenv(fn), v0211);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-7];
    v0212 = stack[-1];
    v0211 = qvalue(elt(env, 2)); // nil
    fn = elt(env, 12); // total!-degree!-in!-powers
    v0211 = (*qfn2(fn))(qenv(fn), v0212, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-7];
    v0211 = cons(stack[0], v0211);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-7];
    v0211 = ncons(v0211);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-7];
    stack[-3] = v0211;
    stack[-4] = v0211;
    goto v0214;

v0214:
    v0211 = stack[-5];
    v0211 = qcdr(v0211);
    stack[-5] = v0211;
    v0211 = stack[-5];
    if (v0211 == nil) goto v0215;
    stack[-2] = stack[-3];
    v0211 = stack[-5];
    v0211 = qcar(v0211);
    stack[-1] = v0211;
    v0211 = stack[-1];
    fn = elt(env, 10); // reorder
    stack[0] = (*qfn1(fn))(qenv(fn), v0211);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-7];
    v0212 = stack[-1];
    v0211 = qvalue(elt(env, 2)); // nil
    fn = elt(env, 12); // total!-degree!-in!-powers
    v0211 = (*qfn2(fn))(qenv(fn), v0212, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-7];
    v0211 = cons(stack[0], v0211);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-7];
    v0211 = ncons(v0211);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-7];
    v0211 = Lrplacd(nil, stack[-2], v0211);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-7];
    v0211 = stack[-3];
    v0211 = qcdr(v0211);
    stack[-3] = v0211;
    goto v0214;

v0215:
    v0211 = stack[-4];
    goto v0112;

v0112:
    v0211 = CC_gcdlist1(env, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-7];
    goto v0186;

v0186:
    qvalue(elt(env, 1)) = stack[-6]; // reduction!-count
    { popv(8); return onevalue(v0211); }

v0062:
    v0211 = qvalue(elt(env, 2)); // nil
    goto v0112;

v0060:
    v0212 = stack[0];
    v0211 = stack[-4];
    fn = elt(env, 13); // gcdlist2
    v0211 = (*qfn2(fn))(qenv(fn), v0212, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-7];
    goto v0186;

v0213:
    v0212 = stack[-4];
    v0211 = stack[-2];
    v0211 = Lappend(nil, v0212, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-7];
    fn = elt(env, 8); // mapcarcar
    v0211 = (*qfn1(fn))(qenv(fn), v0211);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-7];
    stack[-5] = v0211;
    v0211 = stack[-5];
    fn = elt(env, 9); // setkorder
    v0211 = (*qfn1(fn))(qenv(fn), v0211);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-7];
    stack[-4] = v0211;
    v0211 = stack[0];
    stack[-3] = v0211;
    v0211 = stack[-3];
    if (v0211 == nil) goto v0032;
    v0211 = stack[-3];
    v0211 = qcar(v0211);
    v0211 = qcar(v0211);
    fn = elt(env, 10); // reorder
    v0211 = (*qfn1(fn))(qenv(fn), v0211);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-7];
    v0211 = ncons(v0211);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-7];
    stack[-1] = v0211;
    stack[-2] = v0211;
    goto v0089;

v0089:
    v0211 = stack[-3];
    v0211 = qcdr(v0211);
    stack[-3] = v0211;
    v0211 = stack[-3];
    if (v0211 == nil) goto v0078;
    stack[0] = stack[-1];
    v0211 = stack[-3];
    v0211 = qcar(v0211);
    v0211 = qcar(v0211);
    fn = elt(env, 10); // reorder
    v0211 = (*qfn1(fn))(qenv(fn), v0211);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-7];
    v0211 = ncons(v0211);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-7];
    v0211 = Lrplacd(nil, stack[0], v0211);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-7];
    v0211 = stack[-1];
    v0211 = qcdr(v0211);
    stack[-1] = v0211;
    goto v0089;

v0078:
    v0211 = stack[-2];
    v0115 = v0211;
    goto v0173;

v0173:
    v0212 = qvalue(elt(env, 2)); // nil
    v0211 = stack[-5];
    fn = elt(env, 14); // gcdlist3
    v0211 = (*qfnn(fn))(qenv(fn), 3, v0115, v0212, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-7];
    stack[0] = v0211;
    v0211 = stack[-4];
    fn = elt(env, 9); // setkorder
    v0211 = (*qfn1(fn))(qenv(fn), v0211);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-7];
    v0211 = stack[0];
    fn = elt(env, 10); // reorder
    v0211 = (*qfn1(fn))(qenv(fn), v0211);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-7];
    goto v0186;

v0032:
    v0211 = qvalue(elt(env, 2)); // nil
    v0115 = v0211;
    goto v0173;

v0016:
    v0211 = (LispObject)17; // 1
    goto v0186;
// error exit handlers
v0118:
    env = stack[-7];
    qvalue(elt(env, 1)) = stack[-6]; // reduction!-count
    popv(8);
    return nil;
}



// Code for get_rep_of_generator

static LispObject CC_get_rep_of_generator(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0056, v0167, v0168;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for get_rep_of_generator");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    v0168 = v0001;
    stack[-2] = v0000;
// end of prologue
    stack[-1] = nil;
    v0167 = stack[-2];
    v0056 = elt(env, 1); // id
    if (v0167 == v0056) goto v0106;
    v0056 = qvalue(elt(env, 2)); // nil
    stack[-3] = v0056;
    v0056 = v0168;
    stack[0] = v0056;
    goto v0070;

v0070:
    v0056 = stack[-3];
    if (v0056 == nil) goto v0003;
    v0056 = qvalue(elt(env, 2)); // nil
    goto v0055;

v0055:
    if (v0056 == nil) goto v0005;
    v0056 = stack[0];
    v0056 = qcar(v0056);
    v0167 = qcar(v0056);
    v0056 = stack[-2];
    if (!(equal(v0167, v0056))) goto v0042;
    v0056 = qvalue(elt(env, 3)); // t
    stack[-3] = v0056;
    v0056 = stack[0];
    v0056 = qcar(v0056);
    v0056 = qcdr(v0056);
    v0056 = qcar(v0056);
    stack[-1] = v0056;
    goto v0042;

v0042:
    v0056 = stack[0];
    v0056 = qcdr(v0056);
    stack[0] = v0056;
    goto v0070;

v0005:
    v0056 = stack[-3];
    if (!(v0056 == nil)) { LispObject res = stack[-1]; popv(5); return onevalue(res); }
    v0056 = elt(env, 4); // " error in get rep of generators"
    fn = elt(env, 5); // rederr
    v0056 = (*qfn1(fn))(qenv(fn), v0056);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    v0056 = nil;
    { popv(5); return onevalue(v0056); }

v0003:
    v0056 = stack[0];
    v0167 = Llength(nil, v0056);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-4];
    v0056 = (LispObject)1; // 0
    v0056 = (LispObject)greaterp2(v0167, v0056);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    v0056 = v0056 ? lisp_true : nil;
    env = stack[-4];
    goto v0055;

v0106:
    v0056 = v0168;
    v0056 = qcar(v0056);
    v0056 = qcdr(v0056);
    v0056 = qcar(v0056);
    fn = elt(env, 6); // get!+row!+nr
    v0056 = (*qfn1(fn))(qenv(fn), v0056);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-4];
    {
        popv(5);
        fn = elt(env, 7); // mk!+unit!+mat
        return (*qfn1(fn))(qenv(fn), v0056);
    }
// error exit handlers
v0040:
    popv(5);
    return nil;
}



// Code for tidysqrt

static LispObject CC_tidysqrt(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0188, v0055;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for tidysqrt");
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
    v0188 = stack[0];
    v0188 = qcar(v0188);
    fn = elt(env, 2); // tidysqrtf
    v0188 = (*qfn1(fn))(qenv(fn), v0188);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-2];
    stack[-1] = v0188;
    v0188 = stack[-1];
    if (v0188 == nil) goto v0027;
    v0188 = stack[0];
    v0188 = qcdr(v0188);
    fn = elt(env, 2); // tidysqrtf
    v0188 = (*qfn1(fn))(qenv(fn), v0188);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-2];
    stack[0] = stack[-1];
    fn = elt(env, 3); // invsq
    v0188 = (*qfn1(fn))(qenv(fn), v0188);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-2];
    {
        LispObject v0002 = stack[0];
        popv(3);
        fn = elt(env, 4); // multsq
        return (*qfn2(fn))(qenv(fn), v0002, v0188);
    }

v0027:
    v0055 = qvalue(elt(env, 1)); // nil
    v0188 = (LispObject)17; // 1
    popv(3);
    return cons(v0055, v0188);
// error exit handlers
v0119:
    popv(3);
    return nil;
}



// Code for validrule

static LispObject CC_validrule(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0027, v0025;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for validrule");
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
    v0027 = v0000;
// end of prologue
    fn = elt(env, 2); // validrule1
    v0027 = (*qfn1(fn))(qenv(fn), v0027);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[0];
    v0025 = v0027;
    v0027 = v0025;
    if (v0027 == nil) goto v0169;
    v0027 = v0025;
    popv(1);
    return ncons(v0027);

v0169:
    v0027 = qvalue(elt(env, 1)); // nil
    { popv(1); return onevalue(v0027); }
// error exit handlers
v0102:
    popv(1);
    return nil;
}



// Code for cflot

static LispObject CC_cflot(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0028, v0029;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cflot");
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
    v0029 = v0028;
    v0029 = Lfloatp(nil, v0029);
    env = stack[0];
    if (!(v0029 == nil)) { popv(1); return onevalue(v0028); }
    v0029 = v0028;
    if (!consp(v0029)) goto v0186;
    {
        popv(1);
        fn = elt(env, 1); // bf2flr
        return (*qfn1(fn))(qenv(fn), v0028);
    }

v0186:
        popv(1);
        return Lfloat(nil, v0028);
}



// Code for ext_edges

static LispObject CC_ext_edges(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0043, v0177;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ext_edges");
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
    goto v0012;

v0012:
    v0043 = stack[0];
    if (v0043 == nil) goto v0021;
    v0043 = stack[0];
    v0043 = qcar(v0043);
    v0177 = qcar(v0043);
    v0043 = stack[0];
    v0043 = qcdr(v0043);
    v0043 = Lassoc(nil, v0177, v0043);
    if (!(v0043 == nil)) goto v0002;
    v0043 = stack[0];
    v0043 = qcar(v0043);
    v0177 = qcar(v0043);
    v0043 = qvalue(elt(env, 1)); // !_0edge
    v0043 = qcar(v0043);
    if (v0177 == v0043) goto v0002;
    v0043 = stack[0];
    v0177 = qcar(v0043);
    v0043 = stack[-1];
    v0043 = cons(v0177, v0043);
    nil = C_nil;
    if (exception_pending()) goto v0181;
    env = stack[-2];
    stack[-1] = v0043;
    v0043 = stack[0];
    v0043 = qcdr(v0043);
    stack[0] = v0043;
    goto v0012;

v0002:
    v0043 = stack[0];
    v0177 = qcar(v0043);
    v0043 = stack[0];
    v0043 = qcdr(v0043);
    fn = elt(env, 2); // delete_edge
    v0043 = (*qfn2(fn))(qenv(fn), v0177, v0043);
    nil = C_nil;
    if (exception_pending()) goto v0181;
    env = stack[-2];
    stack[0] = v0043;
    goto v0012;

v0021:
    v0043 = stack[-1];
    {
        popv(3);
        fn = elt(env, 3); // nreverse
        return (*qfn1(fn))(qenv(fn), v0043);
    }
// error exit handlers
v0181:
    popv(3);
    return nil;
}



// Code for restore_props

static LispObject CC_restore_props(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0042, v0145, v0014;
    argcheck(nargs, 0, "restore_props");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for restore_props");
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
    push2(nil, nil);
// end of prologue
    v0042 = qvalue(elt(env, 1)); // props!*
    stack[-1] = v0042;
    goto v0047;

v0047:
    v0042 = stack[-1];
    if (v0042 == nil) goto v0021;
    v0042 = stack[-1];
    v0042 = qcar(v0042);
    stack[0] = v0042;
    v0042 = stack[0];
    v0042 = qcdr(v0042);
    v0042 = Lconsp(nil, v0042);
    env = stack[-2];
    if (v0042 == nil) goto v0048;
    v0042 = stack[0];
    v0014 = qcar(v0042);
    v0042 = stack[0];
    v0042 = qcdr(v0042);
    v0145 = qcar(v0042);
    v0042 = stack[0];
    v0042 = qcdr(v0042);
    v0042 = qcdr(v0042);
    v0042 = Lputprop(nil, 3, v0014, v0145, v0042);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-2];
    goto v0025;

v0025:
    v0042 = stack[-1];
    v0042 = qcdr(v0042);
    stack[-1] = v0042;
    goto v0047;

v0048:
    v0042 = stack[0];
    v0042 = qcar(v0042);
    v0145 = ncons(v0042);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-2];
    v0042 = stack[0];
    v0042 = qcdr(v0042);
    v0042 = Lflag(nil, v0145, v0042);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-2];
    goto v0025;

v0021:
    v0042 = qvalue(elt(env, 2)); // nil
    { popv(3); return onevalue(v0042); }
// error exit handlers
v0019:
    popv(3);
    return nil;
}



// Code for lf!=less

static LispObject CC_lfMless(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0085, v0082, v0017;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lf=less");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0001;
    v0082 = v0000;
// end of prologue
    v0017 = elt(env, 1); // cali
    v0085 = elt(env, 2); // varlessp
    stack[-2] = get(v0017, v0085);
    env = stack[-3];
    v0085 = v0082;
    fn = elt(env, 3); // lf!=lvar
    stack[0] = (*qfn1(fn))(qenv(fn), v0085);
    nil = C_nil;
    if (exception_pending()) goto v0070;
    env = stack[-3];
    v0085 = stack[-1];
    fn = elt(env, 3); // lf!=lvar
    v0085 = (*qfn1(fn))(qenv(fn), v0085);
    nil = C_nil;
    if (exception_pending()) goto v0070;
    {
        LispObject v0050 = stack[-2];
        LispObject v0146 = stack[0];
        popv(4);
        return Lapply2(nil, 3, v0050, v0146, v0085);
    }
// error exit handlers
v0070:
    popv(4);
    return nil;
}



// Code for zfactor

static LispObject CC_zfactor(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0106, v0178;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for zfactor");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0106 = v0000;
// end of prologue
    v0178 = v0106;
    v0106 = qvalue(elt(env, 1)); // t
    {
        fn = elt(env, 2); // zfactor1
        return (*qfn2(fn))(qenv(fn), v0178, v0106);
    }
}



// Code for bfprin0x

static LispObject CC_bfprin0x(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0128, v0125, v0119;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for bfprin0x");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// copy arguments values to proper place
    v0125 = v0001;
    v0128 = v0000;
// end of prologue
    fn = elt(env, 1); // bfexplode0x
    v0128 = (*qfn2(fn))(qenv(fn), v0128, v0125);
    nil = C_nil;
    if (exception_pending()) goto v0002;
    env = stack[0];
    v0125 = v0128;
    v0125 = qcdr(v0125);
    v0125 = qcar(v0125);
    v0119 = v0128;
    v0119 = qcdr(v0119);
    v0119 = qcdr(v0119);
    v0119 = qcar(v0119);
    v0128 = qcar(v0128);
    {
        popv(1);
        fn = elt(env, 2); // bfprin!:lst
        return (*qfnn(fn))(qenv(fn), 3, v0128, v0125, v0119);
    }
// error exit handlers
v0002:
    popv(1);
    return nil;
}



// Code for mkg1

static LispObject CC_mkg1(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0048, v0049, v0100, v0101;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mkg1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// copy arguments values to proper place
    v0049 = v0001;
    v0100 = v0000;
// end of prologue
    v0101 = v0049;
    v0048 = elt(env, 1); // nospur
    v0048 = Lflagp(nil, v0101, v0048);
    env = stack[0];
    if (v0048 == nil) goto v0102;
    v0048 = elt(env, 2); // g
    v0048 = list2star(v0048, v0049, v0100);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); // mksf
        return (*qfn1(fn))(qenv(fn), v0048);
    }

v0102:
    v0048 = elt(env, 2); // g
    v0048 = list2star(v0048, v0049, v0100);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); // mksf
        return (*qfn1(fn))(qenv(fn), v0048);
    }
// error exit handlers
v0172:
    popv(1);
    return nil;
}



// Code for cde_mkset

static LispObject CC_cde_mkset(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0101, v0172, v0008;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cde_mkset");
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
    v0008 = nil;
    goto v0012;

v0012:
    v0101 = stack[0];
    if (v0101 == nil) goto v0003;
    v0101 = stack[0];
    v0172 = qcar(v0101);
    v0101 = stack[0];
    v0101 = qcdr(v0101);
    v0101 = Lmember(nil, v0172, v0101);
    if (v0101 == nil) goto v0050;
    v0101 = stack[0];
    v0101 = qcdr(v0101);
    stack[0] = v0101;
    goto v0012;

v0050:
    v0101 = stack[0];
    v0101 = qcar(v0101);
    v0172 = v0008;
    v0101 = cons(v0101, v0172);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-1];
    v0008 = v0101;
    v0101 = stack[0];
    v0101 = qcdr(v0101);
    stack[0] = v0101;
    goto v0012;

v0003:
    v0101 = v0008;
    {
        popv(2);
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(qenv(fn), v0101);
    }
// error exit handlers
v0010:
    popv(2);
    return nil;
}



// Code for monomispommaretdivisibleby

static LispObject CC_monomispommaretdivisibleby(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0086, v0087, v0173;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for monomispommaretdivisibleby");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    v0173 = v0001;
    v0086 = v0000;
// end of prologue
    stack[0] = nil;
    v0087 = v0086;
    v0086 = (LispObject)17; // 1
    v0086 = *(LispObject *)((char *)v0087 + (CELL-TAG_VECTOR) + ((int32_t)v0086/(16/CELL)));
    stack[-2] = v0086;
    v0087 = v0173;
    v0086 = (LispObject)17; // 1
    v0086 = *(LispObject *)((char *)v0087 + (CELL-TAG_VECTOR) + ((int32_t)v0086/(16/CELL)));
    stack[-1] = v0086;
    goto v0018;

v0018:
    v0086 = stack[-2];
    v0086 = qcar(v0086);
    if (v0086 == nil) goto v0013;
    v0086 = stack[-2];
    v0087 = qcar(v0086);
    v0086 = stack[-1];
    v0086 = qcar(v0086);
    v0086 = (LispObject)greaterp2(v0087, v0086);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    v0086 = v0086 ? lisp_true : nil;
    env = stack[-3];
    if (v0086 == nil) goto v0013;
    v0086 = stack[-2];
    v0086 = qcdr(v0086);
    stack[-2] = v0086;
    goto v0018;

v0013:
    v0086 = stack[0];
    if (v0086 == nil) goto v0019;
    v0086 = qvalue(elt(env, 1)); // nil
    goto v0099;

v0099:
    if (v0086 == nil) goto v0016;
    v0086 = stack[-2];
    v0087 = qcar(v0086);
    v0086 = stack[-1];
    v0086 = qcar(v0086);
    if (equal(v0087, v0086)) goto v0040;
    v0086 = qvalue(elt(env, 2)); // t
    stack[0] = v0086;
    goto v0013;

v0040:
    v0086 = stack[-2];
    v0086 = qcdr(v0086);
    stack[-2] = v0086;
    v0086 = stack[-1];
    v0086 = qcdr(v0086);
    stack[-1] = v0086;
    goto v0013;

v0016:
    v0086 = stack[-2];
    v0086 = qcar(v0086);
    if (v0086 == nil) goto v0213;
    v0086 = qvalue(elt(env, 1)); // nil
    { popv(4); return onevalue(v0086); }

v0213:
    v0086 = stack[-1];
    v0086 = qcar(v0086);
    v0086 = (v0086 == nil ? lisp_true : nil);
    { popv(4); return onevalue(v0086); }

v0019:
    v0086 = stack[-2];
    v0086 = qcar(v0086);
    if (v0086 == nil) goto v0023;
    v0086 = stack[-1];
    v0086 = qcar(v0086);
    goto v0099;

v0023:
    v0086 = qvalue(elt(env, 1)); // nil
    goto v0099;
// error exit handlers
v0031:
    popv(4);
    return nil;
}



// Code for preptaylor!*2

static LispObject CC_preptaylorH2(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0141, v0156, v0155;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for preptaylor*2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0001;
    stack[-1] = v0000;
// end of prologue
    v0141 = stack[-1];
    v0141 = qcdr(v0141);
    fn = elt(env, 4); // prepsq!*
    v0141 = (*qfn1(fn))(qenv(fn), v0141);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-3];
    v0155 = v0141;
    v0156 = (LispObject)1; // 0
    if (v0155 == v0156) goto v0186;
    v0155 = v0141;
    v0156 = elt(env, 2); // quotient
    if (!consp(v0155)) goto v0014;
    v0155 = qcar(v0155);
    if (!(v0155 == v0156)) goto v0014;
    v0156 = v0141;
    v0156 = qcdr(v0156);
    v0155 = qcar(v0156);
    v0156 = elt(env, 3); // minus
    v0156 = Leqcar(nil, v0155, v0156);
    env = stack[-3];
    goto v0188;

v0188:
    if (v0156 == nil) goto v0154;
    stack[-2] = elt(env, 3); // minus
    v0155 = elt(env, 2); // quotient
    v0156 = v0141;
    v0156 = qcdr(v0156);
    v0156 = qcar(v0156);
    v0156 = qcdr(v0156);
    v0156 = qcar(v0156);
    v0141 = qcdr(v0141);
    v0141 = qcdr(v0141);
    v0141 = qcar(v0141);
    v0141 = list3(v0155, v0156, v0141);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-3];
    v0141 = list2(stack[-2], v0141);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-3];
    stack[-2] = v0141;
    goto v0219;

v0219:
    v0141 = stack[-1];
    v0156 = qcar(v0141);
    v0141 = stack[0];
    fn = elt(env, 5); // preptaycoeff
    v0141 = (*qfn2(fn))(qenv(fn), v0156, v0141);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-3];
    v0141 = cons(stack[-2], v0141);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-3];
    fn = elt(env, 6); // retimes
    v0141 = (*qfn1(fn))(qenv(fn), v0141);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    popv(4);
    return ncons(v0141);

v0154:
    stack[-2] = v0141;
    goto v0219;

v0014:
    v0156 = qvalue(elt(env, 1)); // nil
    goto v0188;

v0186:
    v0141 = qvalue(elt(env, 1)); // nil
    { popv(4); return onevalue(v0141); }
// error exit handlers
v0213:
    popv(4);
    return nil;
}



// Code for absodeg

static LispObject CC_absodeg(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0057, v0098;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for absodeg");
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
    v0057 = v0000;
// end of prologue
    v0098 = v0057;
    v0098 = Lconsp(nil, v0098);
    env = stack[-5];
    if (v0098 == nil) goto v0047;
    stack[-4] = elt(env, 1); // plus
    stack[-3] = v0057;
    v0057 = stack[-3];
    if (v0057 == nil) goto v0005;
    v0057 = stack[-3];
    v0057 = qcar(v0057);
    v0098 = v0057;
    v0057 = v0098;
    v0057 = integerp(v0057);
    if (v0057 == nil) goto v0101;
    v0057 = v0098;
    v0057 = sub1(v0057);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-5];
    goto v0125;

v0125:
    v0057 = ncons(v0057);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-5];
    stack[-1] = v0057;
    stack[-2] = v0057;
    goto v0082;

v0082:
    v0057 = stack[-3];
    v0057 = qcdr(v0057);
    stack[-3] = v0057;
    v0057 = stack[-3];
    if (v0057 == nil) goto v0013;
    stack[0] = stack[-1];
    v0057 = stack[-3];
    v0057 = qcar(v0057);
    v0098 = v0057;
    v0057 = v0098;
    v0057 = integerp(v0057);
    if (v0057 == nil) goto v0035;
    v0057 = v0098;
    v0057 = sub1(v0057);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-5];
    goto v0045;

v0045:
    v0057 = ncons(v0057);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-5];
    v0057 = Lrplacd(nil, stack[0], v0057);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-5];
    v0057 = stack[-1];
    v0057 = qcdr(v0057);
    stack[-1] = v0057;
    goto v0082;

v0035:
    v0057 = (LispObject)17; // 1
    goto v0045;

v0013:
    v0057 = stack[-2];
    goto v0025;

v0025:
    v0057 = cons(stack[-4], v0057);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-5];
    {
        popv(6);
        fn = elt(env, 3); // eval
        return (*qfn1(fn))(qenv(fn), v0057);
    }

v0101:
    v0057 = (LispObject)17; // 1
    goto v0125;

v0005:
    v0057 = qvalue(elt(env, 2)); // nil
    goto v0025;

v0047:
    v0057 = (LispObject)1; // 0
    { popv(6); return onevalue(v0057); }
// error exit handlers
v0168:
    popv(6);
    return nil;
}



// Code for mri_irsplit

static LispObject CC_mri_irsplit(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0187, v0218, v0154;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mri_irsplit");
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
    v0154 = v0000;
// end of prologue
    v0218 = v0154;
    v0187 = elt(env, 1); // floor
    if (!consp(v0218)) goto v0018;
    v0218 = qcar(v0218);
    if (!(v0218 == v0187)) goto v0018;
    v0187 = v0154;
    v0187 = qcdr(v0187);
    v0187 = qcar(v0187);
    fn = elt(env, 2); // simp
    v0187 = (*qfn1(fn))(qenv(fn), v0187);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-2];
    v0187 = qcar(v0187);
    fn = elt(env, 3); // mri_simplfloor
    v0187 = (*qfn1(fn))(qenv(fn), v0187);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-2];
    fn = elt(env, 4); // mri_irsplit1
    v0187 = (*qfn1(fn))(qenv(fn), v0187);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-2];
    v0218 = v0187;
    v0187 = v0218;
    stack[-1] = qcar(v0187);
    v0187 = v0218;
    v0187 = qcdr(v0187);
    if (v0187 == nil) goto v0041;
    stack[0] = elt(env, 1); // floor
    v0187 = v0218;
    v0187 = qcdr(v0187);
    fn = elt(env, 5); // prepf
    v0187 = (*qfn1(fn))(qenv(fn), v0187);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-2];
    v0187 = list2(stack[0], v0187);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-2];
    fn = elt(env, 6); // !*a2k
    v0218 = (*qfn1(fn))(qenv(fn), v0187);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-2];
    v0187 = (LispObject)17; // 1
    fn = elt(env, 7); // to
    v0218 = (*qfn2(fn))(qenv(fn), v0218, v0187);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-2];
    v0187 = (LispObject)17; // 1
    v0187 = cons(v0218, v0187);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-2];
    v0187 = ncons(v0187);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    goto v0172;

v0172:
    {
        LispObject v0219 = stack[-1];
        popv(3);
        return cons(v0219, v0187);
    }

v0041:
    v0187 = nil;
    goto v0172;

v0018:
    v0218 = v0154;
    v0187 = (LispObject)17; // 1
    fn = elt(env, 7); // to
    v0218 = (*qfn2(fn))(qenv(fn), v0218, v0187);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-2];
    v0187 = (LispObject)17; // 1
    v0187 = cons(v0218, v0187);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-2];
    v0187 = ncons(v0187);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    popv(3);
    return ncons(v0187);
// error exit handlers
v0168:
    popv(3);
    return nil;
}



// Code for vdp_putprop

static LispObject CC_vdp_putprop(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0099, v0019, v0020, v0176, v0043;
    LispObject v0015, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "vdp_putprop");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0015 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vdp_putprop");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0015,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    v0020 = v0015;
    v0176 = v0001;
    stack[0] = v0000;
// end of prologue
    v0099 = stack[0];
    v0099 = qcdr(v0099);
    v0099 = qcdr(v0099);
    v0099 = qcdr(v0099);
    v0099 = qcdr(v0099);
    v0019 = v0099;
    v0043 = v0176;
    v0099 = v0019;
    v0099 = qcar(v0099);
    v0099 = Latsoc(nil, v0043, v0099);
    v0043 = v0099;
    v0099 = v0043;
    if (v0099 == nil) goto v0119;
    v0099 = v0043;
    v0019 = v0020;
    v0099 = Lrplacd(nil, v0099, v0019);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    { LispObject res = stack[0]; popv(3); return onevalue(res); }

v0119:
    stack[-1] = v0019;
    v0099 = v0176;
    v0019 = qcar(v0019);
    v0099 = acons(v0099, v0020, v0019);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-2];
    v0099 = Lrplaca(nil, stack[-1], v0099);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    { LispObject res = stack[0]; popv(3); return onevalue(res); }
// error exit handlers
v0024:
    popv(3);
    return nil;
}



// Code for cd_ordatp

static LispObject CC_cd_ordatp(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0182, v0035, v0037, v0036;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cd_ordatp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0037 = v0001;
    v0036 = v0000;
// end of prologue
    v0182 = v0036;
    v0035 = qcar(v0182);
    v0182 = elt(env, 1); // neq
    if (v0035 == v0182) goto v0029;
    v0182 = qvalue(elt(env, 3)); // nil
    goto v0021;

v0021:
    if (v0182 == nil) goto v0119;
    v0182 = qvalue(elt(env, 4)); // t
    return onevalue(v0182);

v0119:
    v0182 = v0036;
    v0035 = qcar(v0182);
    v0182 = elt(env, 2); // equal
    if (v0035 == v0182) goto v0008;
    v0182 = qvalue(elt(env, 3)); // nil
    goto v0055;

v0055:
    if (v0182 == nil) goto v0177;
    v0182 = qvalue(elt(env, 3)); // nil
    return onevalue(v0182);

v0177:
    v0182 = v0036;
    v0182 = qcdr(v0182);
    v0182 = qcar(v0182);
    v0035 = v0037;
    v0035 = qcdr(v0035);
    v0035 = qcar(v0035);
    {
        fn = elt(env, 5); // ordp
        return (*qfn2(fn))(qenv(fn), v0182, v0035);
    }

v0008:
    v0182 = v0037;
    v0035 = qcar(v0182);
    v0182 = elt(env, 1); // neq
    v0182 = (v0035 == v0182 ? lisp_true : nil);
    goto v0055;

v0029:
    v0182 = v0037;
    v0035 = qcar(v0182);
    v0182 = elt(env, 2); // equal
    v0182 = (v0035 == v0182 ? lisp_true : nil);
    goto v0021;
}



// Code for expttermp1

static LispObject CC_expttermp1(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0143, v0044, v0179, v0183;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for expttermp1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0044 = v0001;
    v0179 = v0000;
// end of prologue

v0184:
    v0143 = v0044;
    if (v0143 == nil) goto v0012;
    v0183 = v0179;
    v0143 = v0044;
    v0143 = qcar(v0143);
    if (equal(v0183, v0143)) goto v0007;
    v0143 = v0044;
    v0183 = qcar(v0143);
    v0143 = elt(env, 3); // expt
    if (!consp(v0183)) goto v0145;
    v0183 = qcar(v0183);
    if (!(v0183 == v0143)) goto v0145;
    v0183 = v0179;
    v0143 = v0044;
    v0143 = qcar(v0143);
    v0143 = qcdr(v0143);
    v0143 = qcar(v0143);
    v0143 = (equal(v0183, v0143) ? lisp_true : nil);
    goto v0146;

v0146:
    if (v0143 == nil) goto v0023;
    v0143 = qvalue(elt(env, 2)); // t
    return onevalue(v0143);

v0023:
    v0143 = v0044;
    v0143 = qcdr(v0143);
    v0044 = v0143;
    goto v0184;

v0145:
    v0143 = qvalue(elt(env, 1)); // nil
    goto v0146;

v0007:
    v0143 = qvalue(elt(env, 2)); // t
    return onevalue(v0143);

v0012:
    v0143 = qvalue(elt(env, 1)); // nil
    return onevalue(v0143);
}



// Code for vdplsortin

static LispObject CC_vdplsortin(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0082, v0017, v0018;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vdplsortin");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0001;
    v0017 = v0000;
// end of prologue
    v0082 = stack[0];
    if (v0082 == nil) goto v0012;
    v0018 = v0017;
    v0017 = stack[0];
    v0082 = stack[0];
    fn = elt(env, 1); // vdplsortin1
    v0082 = (*qfnn(fn))(qenv(fn), 3, v0018, v0017, v0082);
    nil = C_nil;
    if (exception_pending()) goto v0005;
    { LispObject res = stack[0]; popv(1); return onevalue(res); }

v0012:
    v0082 = v0017;
    popv(1);
    return ncons(v0082);
// error exit handlers
v0005:
    popv(1);
    return nil;
}



// Code for xreduce1

static LispObject CC_xreduce1(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0119, v0002, v0003;
    LispObject fn;
    LispObject v0015, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "xreduce1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0015 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for xreduce1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0015,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0015;
    stack[-1] = v0001;
    stack[-2] = v0000;
// end of prologue
    stack[-3] = nil;
    goto v0007;

v0007:
    v0003 = stack[-2];
    v0002 = stack[-1];
    v0119 = stack[0];
    fn = elt(env, 1); // weak_xreduce1
    v0119 = (*qfnn(fn))(qenv(fn), 3, v0003, v0002, v0119);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    env = stack[-4];
    stack[-2] = v0119;
    if (v0119 == nil) goto v0188;
    v0119 = stack[-2];
    v0002 = qcar(v0119);
    v0119 = stack[-3];
    v0119 = cons(v0002, v0119);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    env = stack[-4];
    stack[-3] = v0119;
    v0119 = stack[-2];
    v0119 = qcdr(v0119);
    stack[-2] = v0119;
    goto v0007;

v0188:
    v0119 = stack[-3];
    {
        popv(5);
        fn = elt(env, 2); // nreverse
        return (*qfn1(fn))(qenv(fn), v0119);
    }
// error exit handlers
v0172:
    popv(5);
    return nil;
}



// Code for quotient!:

static LispObject CC_quotientT(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0223, v0224;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for quotient:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-3] = v0001;
    stack[-2] = v0000;
// end of prologue

v0007:
    v0223 = stack[-2];
    v0223 = qcdr(v0223);
    v0224 = qcdr(v0223);
    stack[-1] = v0224;
    v0223 = stack[-3];
    v0223 = qcdr(v0223);
    v0223 = qcdr(v0223);
    stack[0] = v0223;
    if (equal(v0224, v0223)) goto v0017;
    v0224 = stack[-1];
    v0223 = stack[0];
    v0223 = (LispObject)greaterp2(v0224, v0223);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    v0223 = v0223 ? lisp_true : nil;
    env = stack[-5];
    if (v0223 == nil) goto v0075;
    v0224 = stack[-1];
    v0223 = stack[0];
    v0223 = difference2(v0224, v0223);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-5];
    stack[-4] = v0223;
    stack[-1] = elt(env, 1); // !:rd!:
    v0223 = stack[-2];
    v0223 = qcdr(v0223);
    v0224 = qcar(v0223);
    v0223 = stack[-4];
    fn = elt(env, 2); // ashift
    stack[0] = (*qfn2(fn))(qenv(fn), v0224, v0223);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-5];
    v0223 = stack[-2];
    v0223 = qcdr(v0223);
    v0224 = qcdr(v0223);
    v0223 = stack[-4];
    v0223 = difference2(v0224, v0223);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-5];
    v0224 = list2star(stack[-1], stack[0], v0223);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-5];
    v0223 = stack[-3];
    stack[-2] = v0224;
    stack[-3] = v0223;
    goto v0007;

v0075:
    stack[-4] = stack[-2];
    v0224 = stack[0];
    v0223 = stack[-1];
    v0223 = difference2(v0224, v0223);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-5];
    stack[-2] = v0223;
    stack[-1] = elt(env, 1); // !:rd!:
    v0223 = stack[-3];
    v0223 = qcdr(v0223);
    v0224 = qcar(v0223);
    v0223 = stack[-2];
    fn = elt(env, 2); // ashift
    stack[0] = (*qfn2(fn))(qenv(fn), v0224, v0223);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-5];
    v0223 = stack[-3];
    v0223 = qcdr(v0223);
    v0224 = qcdr(v0223);
    v0223 = stack[-2];
    v0223 = difference2(v0224, v0223);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-5];
    v0223 = list2star(stack[-1], stack[0], v0223);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-5];
    stack[-2] = stack[-4];
    stack[-3] = v0223;
    goto v0007;

v0017:
    stack[0] = elt(env, 1); // !:rd!:
    v0223 = stack[-2];
    v0223 = qcdr(v0223);
    v0224 = qcar(v0223);
    v0223 = stack[-3];
    v0223 = qcdr(v0223);
    v0223 = qcar(v0223);
    v0224 = quot2(v0224, v0223);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    v0223 = (LispObject)1; // 0
    {
        LispObject v0225 = stack[0];
        popv(6);
        return list2star(v0225, v0224, v0223);
    }
// error exit handlers
v0162:
    popv(6);
    return nil;
}



// Code for depend1

static LispObject CC_depend1(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0033, v0091, v0228;
    LispObject fn;
    LispObject v0015, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "depend1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0015 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for depend1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0015,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0015;
    stack[-1] = v0001;
    stack[-2] = v0000;
// end of prologue
    v0033 = stack[-2];
    fn = elt(env, 4); // !*a2k
    v0033 = (*qfn1(fn))(qenv(fn), v0033);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-4];
    stack[-2] = v0033;
    v0033 = stack[-1];
    fn = elt(env, 4); // !*a2k
    v0033 = (*qfn1(fn))(qenv(fn), v0033);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-4];
    stack[-1] = v0033;
    v0091 = stack[-2];
    v0033 = stack[-1];
    if (v0091 == v0033) goto v0026;
    v0091 = stack[-2];
    v0033 = qvalue(elt(env, 2)); // depl!*
    v0033 = Lassoc(nil, v0091, v0033);
    stack[-3] = v0033;
    v0033 = stack[-3];
    if (v0033 == nil) goto v0055;
    v0033 = stack[0];
    if (v0033 == nil) goto v0108;
    v0033 = stack[-3];
    stack[0] = qcar(v0033);
    v0033 = stack[-1];
    v0091 = ncons(v0033);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-4];
    v0033 = stack[-3];
    v0033 = qcdr(v0033);
    fn = elt(env, 5); // union
    v0091 = (*qfn2(fn))(qenv(fn), v0091, v0033);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-4];
    v0033 = qvalue(elt(env, 2)); // depl!*
    fn = elt(env, 6); // repasc
    v0033 = (*qfnn(fn))(qenv(fn), 3, stack[0], v0091, v0033);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-4];
    qvalue(elt(env, 2)) = v0033; // depl!*
    goto v0051;

v0051:
    v0033 = nil;
    { popv(5); return onevalue(v0033); }

v0108:
    v0091 = stack[-1];
    v0033 = stack[-3];
    v0033 = qcdr(v0033);
    v0091 = Ldelete(nil, v0091, v0033);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-4];
    v0033 = v0091;
    if (v0091 == nil) goto v0096;
    v0091 = stack[-3];
    v0228 = qcar(v0091);
    v0091 = v0033;
    v0033 = qvalue(elt(env, 2)); // depl!*
    fn = elt(env, 6); // repasc
    v0033 = (*qfnn(fn))(qenv(fn), 3, v0228, v0091, v0033);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-4];
    qvalue(elt(env, 2)) = v0033; // depl!*
    goto v0051;

v0096:
    v0091 = stack[-3];
    v0033 = qvalue(elt(env, 2)); // depl!*
    v0033 = Ldelete(nil, v0091, v0033);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-4];
    qvalue(elt(env, 2)) = v0033; // depl!*
    goto v0051;

v0055:
    v0033 = stack[0];
    if (v0033 == nil) goto v0213;
    v0091 = stack[-2];
    v0033 = stack[-1];
    v0091 = list2(v0091, v0033);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-4];
    v0033 = qvalue(elt(env, 2)); // depl!*
    v0033 = cons(v0091, v0033);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-4];
    qvalue(elt(env, 2)) = v0033; // depl!*
    goto v0051;

v0213:
    v0228 = stack[-2];
    v0091 = elt(env, 3); // "has no prior dependence on"
    v0033 = stack[-1];
    v0033 = list3(v0228, v0091, v0033);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-4];
    fn = elt(env, 7); // lprim
    v0033 = (*qfn1(fn))(qenv(fn), v0033);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    goto v0051;

v0026:
    v0033 = qvalue(elt(env, 1)); // nil
    { popv(5); return onevalue(v0033); }
// error exit handlers
v0190:
    popv(5);
    return nil;
}



// Code for mo_deletecomp

static LispObject CC_mo_deletecomp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0172, v0008;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mo_deletecomp");
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
    v0172 = v0000;
// end of prologue
    v0008 = v0172;
    v0008 = qcar(v0008);
    if (v0008 == nil) { popv(2); return onevalue(v0172); }
    v0008 = v0172;
    v0008 = qcar(v0008);
    v0008 = qcdr(v0008);
    if (v0008 == nil) goto v0027;
    v0008 = (LispObject)1; // 0
    v0172 = qcar(v0172);
    v0172 = qcdr(v0172);
    v0172 = cons(v0008, v0172);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-1];
    stack[0] = v0172;
    fn = elt(env, 2); // mo!=deglist
    v0172 = (*qfn1(fn))(qenv(fn), v0172);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    {
        LispObject v0011 = stack[0];
        popv(2);
        return cons(v0011, v0172);
    }

v0027:
    stack[0] = qvalue(elt(env, 1)); // nil
    v0172 = qvalue(elt(env, 1)); // nil
    fn = elt(env, 2); // mo!=deglist
    v0172 = (*qfn1(fn))(qenv(fn), v0172);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    {
        LispObject v0016 = stack[0];
        popv(2);
        return cons(v0016, v0172);
    }
// error exit handlers
v0010:
    popv(2);
    return nil;
}



// Code for sep_tens_from_other

static LispObject CC_sep_tens_from_other(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0231, v0206;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sep_tens_from_other");
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
    stack[-4] = nil;
    v0231 = (LispObject)17; // 1
    fn = elt(env, 3); // !*n2f
    v0231 = (*qfn1(fn))(qenv(fn), v0231);
    nil = C_nil;
    if (exception_pending()) goto v0232;
    env = stack[-5];
    stack[-2] = v0231;
    goto v0021;

v0021:
    v0231 = stack[-3];
    if (is_number(v0231)) goto v0102;
    v0231 = stack[-3];
    v0231 = qcar(v0231);
    v0231 = qcar(v0231);
    v0231 = qcar(v0231);
    if (!consp(v0231)) goto v0003;
    v0231 = stack[-3];
    v0231 = qcar(v0231);
    v0231 = qcar(v0231);
    v0231 = qcar(v0231);
    v0206 = qcar(v0231);
    v0231 = elt(env, 1); // translate1
    v0231 = get(v0206, v0231);
    env = stack[-5];
    stack[-1] = v0231;
    if (v0231 == nil) goto v0176;
    v0231 = stack[-3];
    fn = elt(env, 4); // fullcopy
    v0231 = (*qfn1(fn))(qenv(fn), v0231);
    nil = C_nil;
    if (exception_pending()) goto v0232;
    env = stack[-5];
    stack[-3] = v0231;
    v0231 = stack[-3];
    v0231 = qcar(v0231);
    stack[0] = qcar(v0231);
    v0206 = stack[-1];
    v0231 = stack[-3];
    v0231 = qcar(v0231);
    v0231 = qcar(v0231);
    v0231 = qcar(v0231);
    v0231 = Lapply1(nil, v0206, v0231);
    nil = C_nil;
    if (exception_pending()) goto v0232;
    env = stack[-5];
    fn = elt(env, 5); // setcar
    v0231 = (*qfn2(fn))(qenv(fn), stack[0], v0231);
    nil = C_nil;
    if (exception_pending()) goto v0232;
    env = stack[-5];
    goto v0176;

v0176:
    v0231 = stack[-3];
    v0231 = qcar(v0231);
    v0231 = qcar(v0231);
    v0231 = qcar(v0231);
    stack[0] = v0231;
    fn = elt(env, 6); // tensorp
    v0231 = (*qfn1(fn))(qenv(fn), v0231);
    nil = C_nil;
    if (exception_pending()) goto v0232;
    env = stack[-5];
    if (v0231 == nil) goto v0225;
    v0231 = stack[0];
    fn = elt(env, 7); // no_dum_varp
    v0231 = (*qfn1(fn))(qenv(fn), v0231);
    nil = C_nil;
    if (exception_pending()) goto v0232;
    env = stack[-5];
    if (v0231 == nil) goto v0087;
    v0231 = stack[0];
    v0231 = qcar(v0231);
    if (!symbolp(v0231)) v0231 = nil;
    else { v0231 = qfastgets(v0231);
           if (v0231 != nil) { v0231 = elt(v0231, 0); // noncom
#ifdef RECORD_GET
             if (v0231 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v0231 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v0231 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v0231 == SPID_NOPROP) v0231 = nil; else v0231 = lisp_true; }}
#endif
    goto v0086;

v0086:
    if (v0231 == nil) goto v0158;
    v0231 = stack[-3];
    v0231 = qcar(v0231);
    v0231 = qcar(v0231);
    v0206 = qcar(v0231);
    v0231 = stack[-4];
    v0231 = cons(v0206, v0231);
    nil = C_nil;
    if (exception_pending()) goto v0232;
    env = stack[-5];
    stack[-4] = v0231;
    goto v0006;

v0006:
    v0231 = stack[-3];
    v0231 = qcar(v0231);
    v0231 = qcdr(v0231);
    stack[-3] = v0231;
    goto v0021;

v0158:
    stack[0] = stack[-2];
    v0231 = stack[-3];
    v0231 = qcar(v0231);
    v0206 = qcar(v0231);
    v0231 = (LispObject)17; // 1
    v0231 = cons(v0206, v0231);
    nil = C_nil;
    if (exception_pending()) goto v0232;
    env = stack[-5];
    v0231 = ncons(v0231);
    nil = C_nil;
    if (exception_pending()) goto v0232;
    env = stack[-5];
    fn = elt(env, 8); // multf
    v0231 = (*qfn2(fn))(qenv(fn), stack[0], v0231);
    nil = C_nil;
    if (exception_pending()) goto v0232;
    env = stack[-5];
    stack[-2] = v0231;
    goto v0006;

v0087:
    v0231 = qvalue(elt(env, 2)); // t
    goto v0086;

v0225:
    stack[0] = stack[-2];
    v0231 = stack[-3];
    v0231 = qcar(v0231);
    v0206 = qcar(v0231);
    v0231 = (LispObject)17; // 1
    v0231 = cons(v0206, v0231);
    nil = C_nil;
    if (exception_pending()) goto v0232;
    env = stack[-5];
    v0231 = ncons(v0231);
    nil = C_nil;
    if (exception_pending()) goto v0232;
    env = stack[-5];
    fn = elt(env, 8); // multf
    v0231 = (*qfn2(fn))(qenv(fn), stack[0], v0231);
    nil = C_nil;
    if (exception_pending()) goto v0232;
    env = stack[-5];
    stack[-2] = v0231;
    goto v0006;

v0003:
    stack[0] = stack[-2];
    v0231 = stack[-3];
    v0231 = qcar(v0231);
    v0206 = qcar(v0231);
    v0231 = (LispObject)17; // 1
    v0231 = cons(v0206, v0231);
    nil = C_nil;
    if (exception_pending()) goto v0232;
    env = stack[-5];
    v0231 = ncons(v0231);
    nil = C_nil;
    if (exception_pending()) goto v0232;
    env = stack[-5];
    fn = elt(env, 8); // multf
    v0231 = (*qfn2(fn))(qenv(fn), stack[0], v0231);
    nil = C_nil;
    if (exception_pending()) goto v0232;
    env = stack[-5];
    stack[-2] = v0231;
    goto v0006;

v0102:
    v0231 = stack[-4];
    stack[0] = Lnreverse(nil, v0231);
    env = stack[-5];
    stack[-1] = stack[-2];
    v0231 = stack[-3];
    fn = elt(env, 3); // !*n2f
    v0231 = (*qfn1(fn))(qenv(fn), v0231);
    nil = C_nil;
    if (exception_pending()) goto v0232;
    env = stack[-5];
    fn = elt(env, 8); // multf
    v0231 = (*qfn2(fn))(qenv(fn), stack[-1], v0231);
    nil = C_nil;
    if (exception_pending()) goto v0232;
    {
        LispObject v0160 = stack[0];
        popv(6);
        return list2(v0160, v0231);
    }
// error exit handlers
v0232:
    popv(6);
    return nil;
}



// Code for sfto_redx

static LispObject CC_sfto_redx(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0149, v0085;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sfto_redx");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0085 = v0000;
// end of prologue
    v0149 = v0085;
    if (!consp(v0149)) goto v0021;
    v0149 = v0085;
    v0149 = qcar(v0149);
    v0149 = (consp(v0149) ? nil : lisp_true);
    goto v0169;

v0169:
    if (v0149 == nil) goto v0028;
    v0149 = qvalue(elt(env, 2)); // nil
    return onevalue(v0149);

v0028:
    v0149 = v0085;
    v0149 = qcdr(v0149);
    return onevalue(v0149);

v0021:
    v0149 = qvalue(elt(env, 1)); // t
    goto v0169;
}



// Code for force!-lc

static LispObject CC_forceKlc(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0102, v0028, v0029;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for force-lc");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0102 = v0001;
    v0028 = v0000;
// end of prologue
    v0029 = v0028;
    v0029 = qcar(v0029);
    v0029 = qcar(v0029);
    v0028 = qcdr(v0028);
    return acons(v0029, v0102, v0028);
}



// Code for compute!:intlog

static LispObject CC_computeTintlog(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0188, v0055, v0128;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for compute:intlog");
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
    v0055 = stack[0];
    v0188 = qvalue(elt(env, 2)); // intlog!:rem
    v0188 = Latsoc(nil, v0055, v0188);
    stack[-1] = v0188;
    if (v0188 == nil) goto v0028;
    v0188 = stack[-1];
    v0188 = qcdr(v0188);
    { popv(3); return onevalue(v0188); }

v0028:
    v0188 = stack[0];
    fn = elt(env, 3); // compute!:intlog1
    v0188 = (*qfn1(fn))(qenv(fn), v0188);
    nil = C_nil;
    if (exception_pending()) goto v0002;
    env = stack[-2];
    stack[-1] = v0188;
    v0128 = stack[0];
    v0055 = stack[-1];
    v0188 = qvalue(elt(env, 2)); // intlog!:rem
    v0188 = acons(v0128, v0055, v0188);
    nil = C_nil;
    if (exception_pending()) goto v0002;
    env = stack[-2];
    qvalue(elt(env, 2)) = v0188; // intlog!:rem
    { LispObject res = stack[-1]; popv(3); return onevalue(res); }
// error exit handlers
v0002:
    popv(3);
    return nil;
}



// Code for product!-set2

static LispObject CC_productKset2(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0145, v0014;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for product-set2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-3] = v0001;
    v0145 = v0000;
// end of prologue
    stack[-4] = nil;
    stack[-2] = v0145;
    goto v0186;

v0186:
    v0145 = stack[-2];
    if (v0145 == nil) { LispObject res = stack[-4]; popv(6); return onevalue(res); }
    v0145 = stack[-2];
    v0145 = qcar(v0145);
    stack[-1] = v0145;
    v0145 = stack[-3];
    stack[0] = v0145;
    goto v0085;

v0085:
    v0145 = stack[0];
    if (v0145 == nil) goto v0149;
    v0145 = stack[0];
    v0145 = qcar(v0145);
    v0014 = stack[-1];
    v0014 = list2(v0014, v0145);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-5];
    v0145 = stack[-4];
    v0145 = cons(v0014, v0145);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-5];
    stack[-4] = v0145;
    v0145 = stack[0];
    v0145 = qcdr(v0145);
    stack[0] = v0145;
    goto v0085;

v0149:
    v0145 = stack[-2];
    v0145 = qcdr(v0145);
    stack[-2] = v0145;
    goto v0186;
// error exit handlers
v0043:
    popv(6);
    return nil;
}



// Code for vdpenumerate

static LispObject CC_vdpenumerate(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0016, v0013, v0041;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vdpenumerate");
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
    v0016 = stack[0];
    if (v0016 == nil) goto v0021;
    v0016 = stack[0];
    v0016 = qcdr(v0016);
    v0016 = qcdr(v0016);
    v0016 = qcdr(v0016);
    v0016 = qcar(v0016);
    v0016 = (v0016 == nil ? lisp_true : nil);
    goto v0169;

v0169:
    if (!(v0016 == nil)) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    v0016 = stack[0];
    fn = elt(env, 4); // vdpsave
    v0016 = (*qfn1(fn))(qenv(fn), v0016);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-1];
    stack[0] = v0016;
    v0013 = stack[0];
    v0016 = elt(env, 2); // number
    fn = elt(env, 5); // vdpgetprop
    v0016 = (*qfn2(fn))(qenv(fn), v0013, v0016);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-1];
    if (!(v0016 == nil)) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    v0041 = stack[0];
    v0013 = elt(env, 2); // number
    v0016 = qvalue(elt(env, 3)); // pcount!*
    v0016 = (LispObject)((int32_t)(v0016) + 0x10);
    qvalue(elt(env, 3)) = v0016; // pcount!*
    fn = elt(env, 6); // vdpputprop
    v0016 = (*qfnn(fn))(qenv(fn), 3, v0041, v0013, v0016);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    stack[0] = v0016;
    { LispObject res = stack[0]; popv(2); return onevalue(res); }

v0021:
    v0016 = qvalue(elt(env, 1)); // t
    goto v0169;
// error exit handlers
v0145:
    popv(2);
    return nil;
}



setup_type const u53_setup[] =
{
    {"new_provev",              too_few_2,      CC_new_provev, wrong_no_2},
    {"*ex2sf",                  CC_Hex2sf,      too_many_1,    wrong_no_1},
    {"lf=tovarlessp",           too_few_2,      CC_lfMtovarlessp,wrong_no_2},
    {"pa_vect2list",            CC_pa_vect2list,too_many_1,    wrong_no_1},
    {"modroots1",               too_few_2,      CC_modroots1,  wrong_no_2},
    {"simprad",                 too_few_2,      CC_simprad,    wrong_no_2},
    {"crn:zerop",               CC_crnTzerop,   too_many_1,    wrong_no_1},
    {"odd_action",              too_few_2,      CC_odd_action, wrong_no_2},
    {"gd_applyscheme",          too_few_2,      CC_gd_applyscheme,wrong_no_2},
    {"ps:constmult-erule",      too_few_2,      CC_psTconstmultKerule,wrong_no_2},
    {"redpar",                  too_few_2,      CC_redpar,     wrong_no_2},
    {"implicitdec",             CC_implicitdec, too_many_1,    wrong_no_1},
    {"dipcontenti1",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_dipcontenti1},
    {"remove_root_item",        CC_remove_root_item,too_many_1,wrong_no_1},
    {"bfdivide",                too_few_2,      CC_bfdivide,   wrong_no_2},
    {"ev-tades",                too_few_2,      CC_evKtades,   wrong_no_2},
    {"*sf2ex",                  too_few_2,      CC_Hsf2ex,     wrong_no_2},
    {"dp_prod",                 too_few_2,      CC_dp_prod,    wrong_no_2},
    {"boolean-eval2",           CC_booleanKeval2,too_many_1,   wrong_no_1},
    {"sqlessp",                 too_few_2,      CC_sqlessp,    wrong_no_2},
    {"gfminus",                 CC_gfminus,     too_many_1,    wrong_no_1},
    {"gcd-mod-p",               too_few_2,      CC_gcdKmodKp,  wrong_no_2},
    {"gcdlist1",                CC_gcdlist1,    too_many_1,    wrong_no_1},
    {"get_rep_of_generator",    too_few_2,      CC_get_rep_of_generator,wrong_no_2},
    {"tidysqrt",                CC_tidysqrt,    too_many_1,    wrong_no_1},
    {"validrule",               CC_validrule,   too_many_1,    wrong_no_1},
    {"cflot",                   CC_cflot,       too_many_1,    wrong_no_1},
    {"ext_edges",               CC_ext_edges,   too_many_1,    wrong_no_1},
    {"restore_props",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_restore_props},
    {"lf=less",                 too_few_2,      CC_lfMless,    wrong_no_2},
    {"zfactor",                 CC_zfactor,     too_many_1,    wrong_no_1},
    {"bfprin0x",                too_few_2,      CC_bfprin0x,   wrong_no_2},
    {"mkg1",                    too_few_2,      CC_mkg1,       wrong_no_2},
    {"cde_mkset",               CC_cde_mkset,   too_many_1,    wrong_no_1},
    {"monomispommaretdivisibleby",too_few_2,    CC_monomispommaretdivisibleby,wrong_no_2},
    {"preptaylor*2",            too_few_2,      CC_preptaylorH2,wrong_no_2},
    {"absodeg",                 CC_absodeg,     too_many_1,    wrong_no_1},
    {"mri_irsplit",             CC_mri_irsplit, too_many_1,    wrong_no_1},
    {"vdp_putprop",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_vdp_putprop},
    {"cd_ordatp",               too_few_2,      CC_cd_ordatp,  wrong_no_2},
    {"expttermp1",              too_few_2,      CC_expttermp1, wrong_no_2},
    {"vdplsortin",              too_few_2,      CC_vdplsortin, wrong_no_2},
    {"xreduce1",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_xreduce1},
    {"quotient:",               too_few_2,      CC_quotientT,  wrong_no_2},
    {"depend1",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_depend1},
    {"mo_deletecomp",           CC_mo_deletecomp,too_many_1,   wrong_no_1},
    {"sep_tens_from_other",     CC_sep_tens_from_other,too_many_1,wrong_no_1},
    {"sfto_redx",               CC_sfto_redx,   too_many_1,    wrong_no_1},
    {"force-lc",                too_few_2,      CC_forceKlc,   wrong_no_2},
    {"compute:intlog",          CC_computeTintlog,too_many_1,  wrong_no_1},
    {"product-set2",            too_few_2,      CC_productKset2,wrong_no_2},
    {"vdpenumerate",            CC_vdpenumerate,too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u53", (two_args *)"2335 1370051 4906676", 0}
};

// end of generated code
