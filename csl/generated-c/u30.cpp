
// $destdir/u30.c        Machine generated C code

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



// Code for nconc2

static LispObject CC_nconc2(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0005, v0006, v0007;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for nconc2");
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
    v0006 = v0001;
    v0007 = v0000;
// end of prologue
    v0005 = v0007;
    if (!consp(v0005)) { popv(2); return onevalue(v0006); }
    v0005 = v0007;
    stack[0] = v0005;
    goto v0008;

v0008:
    v0005 = stack[0];
    v0005 = qcdr(v0005);
    v0005 = Lconsp(nil, v0005);
    env = stack[-1];
    if (v0005 == nil) goto v0009;
    v0005 = stack[0];
    v0005 = qcdr(v0005);
    stack[0] = v0005;
    goto v0008;

v0009:
    v0005 = stack[0];
    v0005 = Lrplacd(nil, v0005, v0006);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    { LispObject res = stack[0]; popv(2); return onevalue(res); }
// error exit handlers
v0010:
    popv(2);
    return nil;
}



// Code for formatfort

static LispObject CC_formatfort(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0042, v0043, v0044;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for formatfort");
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
    stack[-2] = qvalue(elt(env, 1)); // !*lower
    qvalue(elt(env, 1)) = nil; // !*lower
    v0042 = (LispObject)4801; // 300
    v0042 = Llinelength(nil, v0042);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-5];
    stack[-4] = v0042;
    v0042 = (LispObject)1; // 0
    qvalue(elt(env, 2)) = v0042; // !*posn!*
    v0042 = stack[0];
    stack[-1] = v0042;
    goto v0046;

v0046:
    v0042 = stack[-1];
    if (v0042 == nil) goto v0047;
    v0042 = stack[-1];
    v0042 = qcar(v0042);
    stack[0] = v0042;
    v0042 = stack[0];
    v0042 = Lconsp(nil, v0042);
    env = stack[-5];
    if (v0042 == nil) goto v0002;
    v0042 = stack[0];
    fn = elt(env, 11); // lispeval
    v0042 = (*qfn1(fn))(qenv(fn), v0042);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-5];
    goto v0048;

v0048:
    v0042 = stack[-1];
    v0042 = qcdr(v0042);
    stack[-1] = v0042;
    goto v0046;

v0002:
    v0042 = stack[0];
    v0042 = integerp(v0042);
    if (v0042 == nil) goto v0005;
    v0043 = stack[0];
    v0042 = qvalue(elt(env, 4)); // maxint
    v0042 = (LispObject)greaterp2(v0043, v0042);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    v0042 = v0042 ? lisp_true : nil;
    env = stack[-5];
    if (!(v0042 == nil)) goto v0006;
    stack[-3] = stack[0];
    v0042 = qvalue(elt(env, 4)); // maxint
    v0042 = negate(v0042);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-5];
    v0042 = (LispObject)lessp2(stack[-3], v0042);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    v0042 = v0042 ? lisp_true : nil;
    env = stack[-5];
    if (!(v0042 == nil)) goto v0006;

v0005:
    v0042 = stack[0];
    v0042 = Lexplodec(nil, v0042);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-5];
    stack[-3] = v0042;
    v0042 = stack[0];
    v0042 = Lfloatp(nil, v0042);
    env = stack[-5];
    if (v0042 == nil) goto v0049;
    v0042 = qvalue(elt(env, 5)); // !*double
    if (v0042 == nil) goto v0050;
    v0043 = elt(env, 6); // e
    v0042 = stack[-3];
    v0042 = Lmemq(nil, v0043, v0042);
    if (v0042 == nil) goto v0051;
    v0044 = elt(env, 7); // !D
    v0043 = elt(env, 6); // e
    v0042 = stack[-3];
    v0042 = Lsubst(nil, 3, v0044, v0043, v0042);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-5];
    stack[-3] = v0042;
    goto v0049;

v0049:
    stack[0] = qvalue(elt(env, 2)); // !*posn!*
    v0042 = stack[-3];
    v0042 = Llength(nil, v0042);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-5];
    v0043 = plus2(stack[0], v0042);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-5];
    v0042 = qvalue(elt(env, 10)); // fortlinelen!*
    v0042 = (LispObject)greaterp2(v0043, v0042);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    v0042 = v0042 ? lisp_true : nil;
    env = stack[-5];
    if (v0042 == nil) goto v0052;
    fn = elt(env, 12); // fortcontline
    v0042 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-5];
    goto v0052;

v0052:
    v0042 = stack[-3];
    stack[0] = v0042;
    goto v0053;

v0053:
    v0042 = stack[0];
    if (v0042 == nil) goto v0048;
    v0042 = stack[0];
    v0042 = qcar(v0042);
    fn = elt(env, 13); // pprin2
    v0042 = (*qfn1(fn))(qenv(fn), v0042);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-5];
    v0042 = stack[0];
    v0042 = qcdr(v0042);
    stack[0] = v0042;
    goto v0053;

v0051:
    v0043 = elt(env, 8); // !E
    v0042 = stack[-3];
    v0042 = Lmemq(nil, v0043, v0042);
    if (v0042 == nil) goto v0054;
    v0044 = elt(env, 7); // !D
    v0043 = elt(env, 8); // !E
    v0042 = stack[-3];
    v0042 = Lsubst(nil, 3, v0044, v0043, v0042);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-5];
    stack[-3] = v0042;
    goto v0049;

v0054:
    v0043 = stack[-3];
    v0042 = elt(env, 9); // (d !0)
    v0042 = Lappend(nil, v0043, v0042);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-5];
    stack[-3] = v0042;
    goto v0049;

v0050:
    v0043 = elt(env, 6); // e
    v0042 = stack[-3];
    v0042 = Lmemq(nil, v0043, v0042);
    if (v0042 == nil) goto v0049;
    v0044 = elt(env, 8); // !E
    v0043 = elt(env, 6); // e
    v0042 = stack[-3];
    v0042 = Lsubst(nil, 3, v0044, v0043, v0042);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-5];
    stack[-3] = v0042;
    goto v0049;

v0006:
    v0042 = stack[0];
    fn = elt(env, 14); // i2rd!*
    v0042 = (*qfn1(fn))(qenv(fn), v0042);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-5];
    v0042 = qcdr(v0042);
    stack[0] = v0042;
    goto v0005;

v0047:
    v0042 = stack[-4];
    v0042 = Llinelength(nil, v0042);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-5];
    v0042 = nil;
    qvalue(elt(env, 1)) = stack[-2]; // !*lower
    { popv(6); return onevalue(v0042); }
// error exit handlers
v0045:
    env = stack[-5];
    qvalue(elt(env, 1)) = stack[-2]; // !*lower
    popv(6);
    return nil;
}



// Code for locate_member

static LispObject CC_locate_member(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0010, v0056, v0057, v0058;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for locate_member");
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
    v0057 = v0001;
    v0058 = v0000;
// end of prologue
    v0056 = v0058;
    v0010 = v0057;
    v0010 = Lmember(nil, v0056, v0010);
    if (v0010 == nil) goto v0011;
    v0056 = v0058;
    v0010 = v0057;
    v0010 = qcar(v0010);
    if (equal(v0056, v0010)) goto v0059;
    v0010 = v0058;
    v0056 = v0057;
    v0056 = qcdr(v0056);
    v0010 = CC_locate_member(env, v0010, v0056);
    errexit();
    return add1(v0010);

v0059:
    v0010 = (LispObject)17; // 1
    return onevalue(v0010);

v0011:
    v0010 = qvalue(elt(env, 1)); // nil
    return onevalue(v0010);
}



// Code for all_defined_vertex

static LispObject CC_all_defined_vertex(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0061, v0062, v0063, v0064;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for all_defined_vertex");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0061 = v0001;
    v0062 = v0000;
// end of prologue
    v0064 = v0062;
    v0063 = qvalue(elt(env, 1)); // nil
    v0062 = qvalue(elt(env, 1)); // nil
    {
        fn = elt(env, 2); // al1_defined_vertex
        return (*qfnn(fn))(qenv(fn), 4, v0064, v0063, v0062, v0061);
    }
}



// Code for formsetq

static LispObject CC_formsetq(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0076, v0034, v0035, v0077, v0078;
    LispObject fn;
    LispObject v0013, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "formsetq");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0013 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for formsetq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0035 = v0013;
    v0077 = v0001;
    v0078 = v0000;
// end of prologue
    v0034 = v0035;
    v0076 = elt(env, 1); // symbolic
    if (v0034 == v0076) goto v0079;
    v0076 = v0078;
    v0034 = v0077;
    {
        fn = elt(env, 4); // formsetq0
        return (*qfnn(fn))(qenv(fn), 3, v0076, v0034, v0035);
    }

v0079:
    v0076 = v0078;
    v0076 = qcdr(v0076);
    v0034 = qcar(v0076);
    v0076 = elt(env, 2); // list
    if (!consp(v0034)) goto v0080;
    v0034 = qcar(v0034);
    if (!(v0034 == v0076)) goto v0080;
    v0076 = v0078;
    v0034 = v0077;
    {
        fn = elt(env, 5); // formsetq1
        return (*qfnn(fn))(qenv(fn), 3, v0076, v0034, v0035);
    }

v0080:
    v0076 = v0078;
    v0076 = qcdr(v0076);
    v0034 = qcar(v0076);
    v0076 = elt(env, 3); // cons
    if (!consp(v0034)) goto v0081;
    v0034 = qcar(v0034);
    if (!(v0034 == v0076)) goto v0081;
    v0076 = v0078;
    v0034 = v0077;
    {
        fn = elt(env, 6); // formsetq2
        return (*qfnn(fn))(qenv(fn), 3, v0076, v0034, v0035);
    }

v0081:
    v0076 = v0078;
    v0034 = v0077;
    {
        fn = elt(env, 4); // formsetq0
        return (*qfnn(fn))(qenv(fn), 3, v0076, v0034, v0035);
    }
}



// Code for length_multiindex

static LispObject CC_length_multiindex(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0082, v0079;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for length_multiindex");
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
    v0082 = v0000;
// end of prologue
    stack[0] = v0082;
    v0082 = (LispObject)1; // 0
    v0079 = v0082;
    goto v0083;

v0083:
    v0082 = stack[0];
    if (v0082 == nil) { popv(2); return onevalue(v0079); }
    v0082 = stack[0];
    v0082 = qcar(v0082);
    v0082 = plus2(v0082, v0079);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    env = stack[-1];
    v0079 = v0082;
    v0082 = stack[0];
    v0082 = qcdr(v0082);
    stack[0] = v0082;
    goto v0083;
// error exit handlers
v0084:
    popv(2);
    return nil;
}



// Code for deginvar

static LispObject CC_deginvar(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0086, v0087;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for deginvar");
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
    v0086 = stack[-1];
    fn = elt(env, 2); // wuconstantp
    v0086 = (*qfn1(fn))(qenv(fn), v0086);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-3];
    if (v0086 == nil) goto v0047;
    v0086 = (LispObject)1; // 0
    { popv(4); return onevalue(v0086); }

v0047:
    v0086 = stack[-1];
    v0086 = qcar(v0086);
    v0086 = qcar(v0086);
    v0087 = qcar(v0086);
    v0086 = stack[0];
    if (equal(v0087, v0086)) goto v0041;
    stack[-2] = qvalue(elt(env, 1)); // kord!*
    qvalue(elt(env, 1)) = nil; // kord!*
    v0086 = stack[0];
    v0086 = ncons(v0086);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-3];
    qvalue(elt(env, 1)) = v0086; // kord!*
    v0086 = stack[-1];
    fn = elt(env, 3); // reorder
    v0086 = (*qfn1(fn))(qenv(fn), v0086);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-3];
    stack[-1] = v0086;
    v0086 = stack[-1];
    v0086 = qcar(v0086);
    v0086 = qcar(v0086);
    v0087 = qcar(v0086);
    v0086 = stack[0];
    if (equal(v0087, v0086)) goto v0007;
    v0086 = (LispObject)1; // 0
    goto v0090;

v0090:
    qvalue(elt(env, 1)) = stack[-2]; // kord!*
    { popv(4); return onevalue(v0086); }

v0007:
    v0086 = stack[-1];
    v0086 = qcar(v0086);
    v0086 = qcar(v0086);
    v0086 = qcdr(v0086);
    goto v0090;

v0041:
    v0086 = stack[-1];
    v0086 = qcar(v0086);
    v0086 = qcar(v0086);
    v0086 = qcdr(v0086);
    { popv(4); return onevalue(v0086); }
// error exit handlers
v0089:
    env = stack[-3];
    qvalue(elt(env, 1)) = stack[-2]; // kord!*
    popv(4);
    return nil;
v0088:
    popv(4);
    return nil;
}



// Code for dfconst

static LispObject CC_dfconst(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0085, v0091;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dfconst");
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
    v0085 = stack[0];
    v0085 = qcar(v0085);
    if (v0085 == nil) goto v0012;
    v0085 = qvalue(elt(env, 2)); // zlist
    fn = elt(env, 3); // vp2
    v0091 = (*qfn1(fn))(qenv(fn), v0085);
    nil = C_nil;
    if (exception_pending()) goto v0075;
    env = stack[-1];
    v0085 = stack[0];
    v0085 = cons(v0091, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0075;
    popv(2);
    return ncons(v0085);

v0012:
    v0085 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0085); }
// error exit handlers
v0075:
    popv(2);
    return nil;
}



// Code for ofsf_xor

static LispObject CC_ofsf_xor(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0075, v0048, v0092;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_xor");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0048 = v0001;
    v0092 = v0000;
// end of prologue
    v0075 = v0092;
    if (!(v0075 == nil)) goto v0047;
    v0075 = v0048;
    if (!(v0075 == nil)) goto v0047;
    v0075 = qvalue(elt(env, 1)); // nil
    return onevalue(v0075);

v0047:
    v0075 = v0092;
    if (v0075 == nil) goto v0059;
    v0075 = v0048;
    goto v0008;

v0008:
    v0075 = (v0075 == nil ? lisp_true : nil);
    return onevalue(v0075);

v0059:
    v0075 = qvalue(elt(env, 1)); // nil
    goto v0008;
}



// Code for unify

static LispObject CC_unify(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0124, v0125, v0126, v0127, v0128;
    LispObject fn;
    LispObject v0108, v0083, v0011, v0012, v0004;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 5, "unify");
    va_start(aa, nargs);
    v0004 = va_arg(aa, LispObject);
    v0012 = va_arg(aa, LispObject);
    v0011 = va_arg(aa, LispObject);
    v0083 = va_arg(aa, LispObject);
    v0108 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for unify");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v0108,v0083,v0011,v0012,v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0004,v0012,v0011,v0083,v0108);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    stack[-13] = v0108;
    stack[-14] = v0083;
    v0125 = v0011;
    v0126 = v0012;
    v0124 = v0004;
// end of prologue
    stack[-15] = qvalue(elt(env, 1)); // op
    qvalue(elt(env, 1)) = nil; // op
    stack[-12] = qvalue(elt(env, 2)); // r
    qvalue(elt(env, 2)) = nil; // r
    stack[-11] = qvalue(elt(env, 3)); // p
    qvalue(elt(env, 3)) = nil; // p
    qvalue(elt(env, 1)) = v0124; // op
    v0124 = v0126;
    qvalue(elt(env, 2)) = v0124; // r
    v0124 = v0125;
    qvalue(elt(env, 3)) = v0124; // p
    v0124 = qvalue(elt(env, 2)); // r
    if (v0124 == nil) goto v0036;
    v0124 = qvalue(elt(env, 4)); // nil
    goto v0091;

v0091:
    if (v0124 == nil) goto v0064;
    v0125 = stack[-14];
    v0124 = stack[-13];
    fn = elt(env, 14); // resume
    v0124 = (*qfn2(fn))(qenv(fn), v0125, v0124);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-16];
    goto v0046;

v0046:
    qvalue(elt(env, 3)) = stack[-11]; // p
    qvalue(elt(env, 2)) = stack[-12]; // r
    qvalue(elt(env, 1)) = stack[-15]; // op
    { popv(17); return onevalue(v0124); }

v0064:
    v0124 = qvalue(elt(env, 2)); // r
    if (v0124 == nil) goto v0010;
    v0124 = qvalue(elt(env, 3)); // p
    if (v0124 == nil) goto v0130;
    v0124 = qvalue(elt(env, 4)); // nil
    goto v0040;

v0040:
    if (v0124 == nil) goto v0131;
    v0124 = qvalue(elt(env, 4)); // nil
    goto v0046;

v0131:
    stack[0] = nil;
    stack[-9] = nil;
    stack[-8] = qvalue(elt(env, 6)); // symm
    qvalue(elt(env, 6)) = nil; // symm
    stack[-7] = qvalue(elt(env, 7)); // comb
    qvalue(elt(env, 7)) = nil; // comb
    stack[-6] = qvalue(elt(env, 8)); // identity
    qvalue(elt(env, 8)) = nil; // identity
    stack[-5] = qvalue(elt(env, 9)); // mcontract
    qvalue(elt(env, 9)) = nil; // mcontract
    stack[-4] = qvalue(elt(env, 10)); // acontract
    qvalue(elt(env, 10)) = nil; // acontract
    stack[-3] = qvalue(elt(env, 11)); // expand
    qvalue(elt(env, 11)) = nil; // expand
    stack[-2] = qvalue(elt(env, 12)); // i
    qvalue(elt(env, 12)) = nil; // i
    stack[-1] = qvalue(elt(env, 13)); // upb
    qvalue(elt(env, 13)) = nil; // upb
    v0124 = (LispObject)1; // 0
    qvalue(elt(env, 12)) = v0124; // i
    v0124 = (LispObject)1; // 0
    qvalue(elt(env, 13)) = v0124; // upb
    v0124 = qvalue(elt(env, 2)); // r
    v0124 = qcar(v0124);
    fn = elt(env, 15); // pm!:free
    v0124 = (*qfn1(fn))(qenv(fn), v0124);
    nil = C_nil;
    if (exception_pending()) goto v0132;
    env = stack[-16];
    if (v0124 == nil) goto v0076;
    v0124 = qvalue(elt(env, 2)); // r
    v0124 = qcar(v0124);
    fn = elt(env, 16); // genp
    v0125 = (*qfn1(fn))(qenv(fn), v0124);
    nil = C_nil;
    if (exception_pending()) goto v0132;
    env = stack[-16];
    v0124 = stack[-14];
    v0124 = cons(v0125, v0124);
    nil = C_nil;
    if (exception_pending()) goto v0132;
    env = stack[-16];
    stack[-14] = v0124;
    goto v0076;

v0076:
    v0124 = qvalue(elt(env, 3)); // p
    fn = elt(env, 17); // initarg
    v0124 = (*qfn1(fn))(qenv(fn), v0124);
    nil = C_nil;
    if (exception_pending()) goto v0132;
    env = stack[-16];
    goto v0133;

v0133:
    v0124 = stack[0];
    if (v0124 == nil) goto v0134;
    v0124 = qvalue(elt(env, 4)); // nil
    goto v0135;

v0135:
    if (v0124 == nil) goto v0136;
    v0124 = qvalue(elt(env, 2)); // r
    v0124 = qcar(v0124);
    if (!consp(v0124)) goto v0137;
    v0128 = qvalue(elt(env, 1)); // op
    v0127 = qvalue(elt(env, 2)); // r
    v0126 = stack[-9];
    v0125 = stack[-14];
    v0124 = stack[-13];
    fn = elt(env, 18); // suspend
    v0124 = (*qfnn(fn))(qenv(fn), 5, v0128, v0127, v0126, v0125, v0124);
    nil = C_nil;
    if (exception_pending()) goto v0132;
    env = stack[-16];
    stack[0] = v0124;
    goto v0133;

v0137:
    v0124 = qvalue(elt(env, 2)); // r
    v0124 = qcar(v0124);
    fn = elt(env, 15); // pm!:free
    v0124 = (*qfn1(fn))(qenv(fn), v0124);
    nil = C_nil;
    if (exception_pending()) goto v0132;
    env = stack[-16];
    if (v0124 == nil) goto v0042;
    v0124 = qvalue(elt(env, 2)); // r
    v0125 = qcar(v0124);
    v0124 = stack[-9];
    v0124 = qcar(v0124);
    fn = elt(env, 19); // bind
    v0124 = (*qfn2(fn))(qenv(fn), v0125, v0124);
    nil = C_nil;
    if (exception_pending()) goto v0132;
    env = stack[-16];
    v0124 = stack[-14];
    fn = elt(env, 20); // chk
    v0124 = (*qfn1(fn))(qenv(fn), v0124);
    nil = C_nil;
    if (exception_pending()) goto v0132;
    env = stack[-16];
    stack[-10] = v0124;
    if (v0124 == nil) goto v0138;
    stack[0] = qvalue(elt(env, 1)); // op
    v0124 = qvalue(elt(env, 2)); // r
    v0124 = qcdr(v0124);
    fn = elt(env, 21); // mval
    v0127 = (*qfn1(fn))(qenv(fn), v0124);
    nil = C_nil;
    if (exception_pending()) goto v0132;
    env = stack[-16];
    v0124 = stack[-9];
    v0126 = qcdr(v0124);
    v0125 = stack[-10];
    v0124 = stack[-13];
    v0124 = CC_unify(env, 5, stack[0], v0127, v0126, v0125, v0124);
    nil = C_nil;
    if (exception_pending()) goto v0132;
    env = stack[-16];
    stack[0] = v0124;
    goto v0138;

v0138:
    v0124 = qvalue(elt(env, 2)); // r
    v0124 = qcar(v0124);
    fn = elt(env, 22); // unbind
    v0124 = (*qfn1(fn))(qenv(fn), v0124);
    nil = C_nil;
    if (exception_pending()) goto v0132;
    env = stack[-16];
    goto v0133;

v0042:
    v0124 = qvalue(elt(env, 2)); // r
    v0125 = qcar(v0124);
    v0124 = stack[-9];
    v0124 = qcar(v0124);
    fn = elt(env, 23); // meq
    v0124 = (*qfn2(fn))(qenv(fn), v0125, v0124);
    nil = C_nil;
    if (exception_pending()) goto v0132;
    env = stack[-16];
    if (v0124 == nil) goto v0133;
    stack[0] = qvalue(elt(env, 1)); // op
    v0124 = qvalue(elt(env, 2)); // r
    v0124 = qcdr(v0124);
    fn = elt(env, 21); // mval
    v0127 = (*qfn1(fn))(qenv(fn), v0124);
    nil = C_nil;
    if (exception_pending()) goto v0132;
    env = stack[-16];
    v0124 = stack[-9];
    v0126 = qcdr(v0124);
    v0125 = stack[-14];
    v0124 = stack[-13];
    v0124 = CC_unify(env, 5, stack[0], v0127, v0126, v0125, v0124);
    nil = C_nil;
    if (exception_pending()) goto v0132;
    env = stack[-16];
    stack[0] = v0124;
    goto v0133;

v0136:
    v0124 = stack[0];
    qvalue(elt(env, 13)) = stack[-1]; // upb
    qvalue(elt(env, 12)) = stack[-2]; // i
    qvalue(elt(env, 11)) = stack[-3]; // expand
    qvalue(elt(env, 10)) = stack[-4]; // acontract
    qvalue(elt(env, 9)) = stack[-5]; // mcontract
    qvalue(elt(env, 8)) = stack[-6]; // identity
    qvalue(elt(env, 7)) = stack[-7]; // comb
    qvalue(elt(env, 6)) = stack[-8]; // symm
    goto v0046;

v0134:
    v0124 = qvalue(elt(env, 3)); // p
    fn = elt(env, 24); // nextarg
    v0124 = (*qfn1(fn))(qenv(fn), v0124);
    nil = C_nil;
    if (exception_pending()) goto v0132;
    env = stack[-16];
    stack[-9] = v0124;
    goto v0135;

v0130:
    v0124 = qvalue(elt(env, 1)); // op
    fn = elt(env, 25); // ident
    v0124 = (*qfn1(fn))(qenv(fn), v0124);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-16];
    if (!(v0124 == nil)) goto v0139;
    v0124 = qvalue(elt(env, 2)); // r
    v0124 = qcar(v0124);
    fn = elt(env, 26); // mgenp
    v0124 = (*qfn1(fn))(qenv(fn), v0124);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-16];
    goto v0139;

v0139:
    v0124 = (v0124 == nil ? lisp_true : nil);
    goto v0040;

v0010:
    v0124 = elt(env, 5); // "UNIFY:pattern over-run for function "
    v0124 = Lprinc(nil, v0124);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-16];
    v0124 = qvalue(elt(env, 1)); // op
    v0124 = Lprint(nil, v0124);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-16];
    v0124 = qvalue(elt(env, 4)); // nil
    goto v0046;

v0036:
    v0124 = qvalue(elt(env, 3)); // p
    v0124 = (v0124 == nil ? lisp_true : nil);
    goto v0091;
// error exit handlers
v0132:
    env = stack[-16];
    qvalue(elt(env, 13)) = stack[-1]; // upb
    qvalue(elt(env, 12)) = stack[-2]; // i
    qvalue(elt(env, 11)) = stack[-3]; // expand
    qvalue(elt(env, 10)) = stack[-4]; // acontract
    qvalue(elt(env, 9)) = stack[-5]; // mcontract
    qvalue(elt(env, 8)) = stack[-6]; // identity
    qvalue(elt(env, 7)) = stack[-7]; // comb
    qvalue(elt(env, 6)) = stack[-8]; // symm
    qvalue(elt(env, 3)) = stack[-11]; // p
    qvalue(elt(env, 2)) = stack[-12]; // r
    qvalue(elt(env, 1)) = stack[-15]; // op
    popv(17);
    return nil;
v0129:
    env = stack[-16];
    qvalue(elt(env, 3)) = stack[-11]; // p
    qvalue(elt(env, 2)) = stack[-12]; // r
    qvalue(elt(env, 1)) = stack[-15]; // op
    popv(17);
    return nil;
}



// Code for evload

static LispObject CC_evload(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0059;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evload");
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

v0012:
    v0059 = stack[0];
    if (v0059 == nil) goto v0108;
    v0059 = stack[0];
    v0059 = qcar(v0059);
    v0059 = Lload_module(nil, v0059);
    nil = C_nil;
    if (exception_pending()) goto v0062;
    env = stack[-1];
    v0059 = stack[0];
    v0059 = qcdr(v0059);
    stack[0] = v0059;
    goto v0012;

v0108:
    v0059 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0059); }
// error exit handlers
v0062:
    popv(2);
    return nil;
}



// Code for harmonicp

static LispObject CC_harmonicp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0041, v0093;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for harmonicp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0041 = v0000;
// end of prologue
    v0093 = elt(env, 1); // fourier!-angle
    return get(v0041, v0093);
}



// Code for red!=hide

static LispObject CC_redMhide(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0098, v0097;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for red=hide");
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
    v0098 = v0000;
// end of prologue
    stack[-5] = v0098;
    v0098 = stack[-5];
    if (v0098 == nil) goto v0093;
    v0098 = stack[-5];
    v0098 = qcar(v0098);
    stack[-1] = v0098;
    stack[0] = (LispObject)-15; // -1
    v0098 = stack[-1];
    v0098 = qcar(v0098);
    fn = elt(env, 2); // mo_neg
    v0098 = (*qfn1(fn))(qenv(fn), v0098);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-6];
    fn = elt(env, 3); // mo_times_ei
    v0097 = (*qfn2(fn))(qenv(fn), stack[0], v0098);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-6];
    v0098 = stack[-1];
    v0098 = qcdr(v0098);
    v0098 = cons(v0097, v0098);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-6];
    v0098 = ncons(v0098);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-6];
    stack[-3] = v0098;
    stack[-4] = v0098;
    goto v0108;

v0108:
    v0098 = stack[-5];
    v0098 = qcdr(v0098);
    stack[-5] = v0098;
    v0098 = stack[-5];
    if (v0098 == nil) { LispObject res = stack[-4]; popv(7); return onevalue(res); }
    stack[-2] = stack[-3];
    v0098 = stack[-5];
    v0098 = qcar(v0098);
    stack[-1] = v0098;
    stack[0] = (LispObject)-15; // -1
    v0098 = stack[-1];
    v0098 = qcar(v0098);
    fn = elt(env, 2); // mo_neg
    v0098 = (*qfn1(fn))(qenv(fn), v0098);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-6];
    fn = elt(env, 3); // mo_times_ei
    v0097 = (*qfn2(fn))(qenv(fn), stack[0], v0098);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-6];
    v0098 = stack[-1];
    v0098 = qcdr(v0098);
    v0098 = cons(v0097, v0098);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-6];
    v0098 = ncons(v0098);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-6];
    v0098 = Lrplacd(nil, stack[-2], v0098);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-6];
    v0098 = stack[-3];
    v0098 = qcdr(v0098);
    stack[-3] = v0098;
    goto v0108;

v0093:
    v0098 = qvalue(elt(env, 1)); // nil
    { popv(7); return onevalue(v0098); }
// error exit handlers
v0067:
    popv(7);
    return nil;
}



// Code for reverse!-num1

static LispObject CC_reverseKnum1(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0157, v0158;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for reverse-num1");
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
    stack[-2] = v0001;
    stack[0] = v0000;
// end of prologue
    v0158 = stack[0];
    v0157 = (LispObject)1; // 0
    if (v0158 == v0157) goto v0011;
    v0158 = stack[-2];
    v0157 = (LispObject)17; // 1
    if (v0158 == v0157) { LispObject res = stack[0]; popv(5); return onevalue(res); }
    v0158 = stack[-2];
    v0157 = (LispObject)33; // 2
    if (v0158 == v0157) goto v0159;
    v0158 = stack[-2];
    v0157 = (LispObject)49; // 3
    if (v0158 == v0157) goto v0037;
    v0158 = stack[-2];
    v0157 = (LispObject)65; // 4
    if (v0158 == v0157) goto v0065;
    stack[-1] = (LispObject)33; // 2
    v0158 = stack[-2];
    v0157 = (LispObject)33; // 2
    v0157 = quot2(v0158, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0160;
    env = stack[-4];
    v0157 = Lexpt(nil, stack[-1], v0157);
    nil = C_nil;
    if (exception_pending()) goto v0160;
    env = stack[-4];
    stack[-3] = v0157;
    v0158 = stack[0];
    v0157 = stack[-3];
    v0157 = Ldivide(nil, v0158, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0160;
    env = stack[-4];
    stack[-1] = v0157;
    v0157 = stack[-2];
    v0157 = Levenp(nil, v0157);
    env = stack[-4];
    if (!(v0157 == nil)) goto v0161;
    v0158 = stack[-3];
    v0157 = (LispObject)33; // 2
    v0157 = times2(v0158, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0160;
    env = stack[-4];
    stack[-3] = v0157;
    goto v0161;

v0161:
    v0157 = stack[-1];
    stack[0] = qcdr(v0157);
    v0158 = stack[-2];
    v0157 = (LispObject)33; // 2
    v0157 = quot2(v0158, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0160;
    env = stack[-4];
    v0158 = CC_reverseKnum1(env, stack[0], v0157);
    nil = C_nil;
    if (exception_pending()) goto v0160;
    env = stack[-4];
    v0157 = stack[-3];
    stack[0] = times2(v0158, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0160;
    env = stack[-4];
    v0157 = stack[-1];
    stack[-1] = qcar(v0157);
    v0157 = stack[-2];
    v0158 = add1(v0157);
    nil = C_nil;
    if (exception_pending()) goto v0160;
    env = stack[-4];
    v0157 = (LispObject)33; // 2
    v0157 = quot2(v0158, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0160;
    env = stack[-4];
    v0157 = CC_reverseKnum1(env, stack[-1], v0157);
    nil = C_nil;
    if (exception_pending()) goto v0160;
    {
        LispObject v0112 = stack[0];
        popv(5);
        return plus2(v0112, v0157);
    }

v0065:
    v0158 = qvalue(elt(env, 1)); // reverse!-num!-table!*
    v0157 = stack[0];
    v0157 = *(LispObject *)((char *)v0158 + (CELL-TAG_VECTOR) + ((int32_t)v0157/(16/CELL)));
    { popv(5); return onevalue(v0157); }

v0037:
    stack[-1] = qvalue(elt(env, 1)); // reverse!-num!-table!*
    v0158 = (LispObject)33; // 2
    v0157 = stack[0];
    v0157 = times2(v0158, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0160;
    v0157 = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v0157/(16/CELL)));
    { popv(5); return onevalue(v0157); }

v0159:
    stack[-1] = qvalue(elt(env, 1)); // reverse!-num!-table!*
    v0158 = (LispObject)65; // 4
    v0157 = stack[0];
    v0157 = times2(v0158, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0160;
    v0157 = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v0157/(16/CELL)));
    { popv(5); return onevalue(v0157); }

v0011:
    v0157 = (LispObject)1; // 0
    { popv(5); return onevalue(v0157); }
// error exit handlers
v0160:
    popv(5);
    return nil;
}



// Code for mksf

static LispObject CC_mksf(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0163, v0164, v0072;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mksf");
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
    v0164 = stack[0];
    v0163 = (LispObject)17; // 1
    fn = elt(env, 3); // mksq
    v0163 = (*qfn2(fn))(qenv(fn), v0164, v0163);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-1];
    v0072 = v0163;
    v0163 = v0072;
    v0164 = qcdr(v0163);
    v0163 = (LispObject)17; // 1
    if (v0164 == v0163) goto v0008;
    v0163 = qvalue(elt(env, 1)); // t
    qvalue(elt(env, 2)) = v0163; // !*sub2
    v0164 = stack[0];
    v0163 = (LispObject)17; // 1
    fn = elt(env, 4); // mksp
    v0164 = (*qfn2(fn))(qenv(fn), v0164, v0163);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-1];
    v0163 = (LispObject)17; // 1
    v0163 = cons(v0164, v0163);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    popv(2);
    return ncons(v0163);

v0008:
    v0163 = v0072;
    v0163 = qcar(v0163);
    { popv(2); return onevalue(v0163); }
// error exit handlers
v0074:
    popv(2);
    return nil;
}



// Code for sfto_fsub1

static LispObject CC_sfto_fsub1(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0114, v0172;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sfto_fsub1");
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
    stack[-1] = v0001;
    stack[-2] = v0000;
// end of prologue
    v0114 = stack[-2];
    if (!consp(v0114)) goto v0008;
    v0114 = stack[-2];
    v0114 = qcar(v0114);
    v0114 = (consp(v0114) ? nil : lisp_true);
    goto v0060;

v0060:
    if (!(v0114 == nil)) { LispObject res = stack[-2]; popv(5); return onevalue(res); }
    v0114 = stack[-2];
    v0114 = qcar(v0114);
    v0114 = qcar(v0114);
    v0114 = qcar(v0114);
    stack[0] = v0114;
    goto v0084;

v0084:
    v0114 = stack[-1];
    if (v0114 == nil) goto v0090;
    v0114 = stack[-1];
    v0114 = qcar(v0114);
    v0172 = qcar(v0114);
    v0114 = stack[0];
    if (equal(v0172, v0114)) goto v0089;
    v0114 = stack[-1];
    v0114 = qcar(v0114);
    v0172 = qcar(v0114);
    v0114 = stack[0];
    fn = elt(env, 3); // ordop
    v0114 = (*qfn2(fn))(qenv(fn), v0172, v0114);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    goto v0056;

v0056:
    if (v0114 == nil) goto v0090;
    v0114 = stack[-1];
    v0114 = qcdr(v0114);
    stack[-1] = v0114;
    goto v0084;

v0090:
    v0114 = stack[-1];
    if (v0114 == nil) { LispObject res = stack[-2]; popv(5); return onevalue(res); }
    v0114 = stack[-2];
    v0172 = qcdr(v0114);
    v0114 = stack[-1];
    v0114 = CC_sfto_fsub1(env, v0172, v0114);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    stack[-3] = v0114;
    v0114 = stack[-1];
    v0114 = qcar(v0114);
    v0172 = qcar(v0114);
    v0114 = stack[0];
    if (v0172 == v0114) goto v0033;
    v0114 = stack[-2];
    v0114 = qcar(v0114);
    v0172 = qcdr(v0114);
    v0114 = stack[-1];
    v0114 = CC_sfto_fsub1(env, v0172, v0114);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    stack[0] = v0114;
    v0114 = stack[-2];
    v0114 = qcar(v0114);
    v0114 = qcar(v0114);
    v0172 = qcar(v0114);
    v0114 = stack[-2];
    v0114 = qcar(v0114);
    v0114 = qcar(v0114);
    v0114 = qcdr(v0114);
    fn = elt(env, 4); // to
    v0172 = (*qfn2(fn))(qenv(fn), v0172, v0114);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    v0114 = (LispObject)17; // 1
    v0114 = cons(v0172, v0114);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    v0114 = ncons(v0114);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    v0172 = stack[0];
    fn = elt(env, 5); // multf
    v0172 = (*qfn2(fn))(qenv(fn), v0172, v0114);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    v0114 = stack[-3];
    {
        popv(5);
        fn = elt(env, 6); // addf
        return (*qfn2(fn))(qenv(fn), v0172, v0114);
    }

v0033:
    v0114 = stack[-2];
    v0114 = qcar(v0114);
    v0172 = qcdr(v0114);
    v0114 = stack[-1];
    v0114 = qcdr(v0114);
    v0114 = CC_sfto_fsub1(env, v0172, v0114);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    stack[0] = v0114;
    v0114 = stack[-1];
    v0114 = qcar(v0114);
    v0172 = qcdr(v0114);
    v0114 = stack[-2];
    v0114 = qcar(v0114);
    v0114 = qcar(v0114);
    v0114 = qcdr(v0114);
    fn = elt(env, 7); // exptf
    v0114 = (*qfn2(fn))(qenv(fn), v0172, v0114);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    v0172 = stack[0];
    fn = elt(env, 5); // multf
    v0172 = (*qfn2(fn))(qenv(fn), v0172, v0114);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    v0114 = stack[-3];
    {
        popv(5);
        fn = elt(env, 6); // addf
        return (*qfn2(fn))(qenv(fn), v0172, v0114);
    }

v0089:
    v0114 = qvalue(elt(env, 2)); // nil
    goto v0056;

v0008:
    v0114 = qvalue(elt(env, 1)); // t
    goto v0060;
// error exit handlers
v0111:
    popv(5);
    return nil;
}



// Code for sfto_updecf

static LispObject CC_sfto_updecf(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0063, v0064;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sfto_updecf");
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
    v0064 = v0000;
// end of prologue
    v0063 = qvalue(elt(env, 1)); // !*sfto_yun
    if (v0063 == nil) goto v0011;
    v0063 = v0064;
    {
        popv(1);
        fn = elt(env, 4); // sfto_yun!-updecf
        return (*qfn1(fn))(qenv(fn), v0063);
    }

v0011:
    v0063 = qvalue(elt(env, 2)); // !*sfto_musser
    if (v0063 == nil) goto v0060;
    v0063 = v0064;
    {
        popv(1);
        fn = elt(env, 5); // sfto_musser!-updecf
        return (*qfn1(fn))(qenv(fn), v0063);
    }

v0060:
    v0063 = elt(env, 3); // "sfto_updecf: select a decomposition method"
    v0063 = ncons(v0063);
    nil = C_nil;
    if (exception_pending()) goto v0085;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 6); // rederr
        return (*qfn1(fn))(qenv(fn), v0063);
    }
// error exit handlers
v0085:
    popv(1);
    return nil;
}



// Code for vunion

static LispObject CC_vunion(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0152, v0136;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vunion");
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
    stack[-1] = v0001;
    stack[-2] = v0000;
// end of prologue
    v0152 = stack[-2];
    if (v0152 == nil) { LispObject res = stack[-1]; popv(5); return onevalue(res); }
    v0152 = stack[-2];
    v0152 = qcar(v0152);
    v0136 = qcar(v0152);
    v0152 = stack[-1];
    v0152 = Lassoc(nil, v0136, v0152);
    stack[-3] = v0152;
    if (v0152 == nil) goto v0048;
    v0152 = stack[-2];
    v0152 = qcar(v0152);
    v0136 = qcdr(v0152);
    v0152 = stack[-3];
    v0152 = qcdr(v0152);
    v0152 = (LispObject)greaterp2(v0136, v0152);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    v0152 = v0152 ? lisp_true : nil;
    env = stack[-4];
    if (v0152 == nil) goto v0154;
    v0152 = stack[-2];
    stack[0] = qcar(v0152);
    v0152 = stack[-2];
    stack[-2] = qcdr(v0152);
    v0136 = stack[-3];
    v0152 = stack[-1];
    v0152 = Ldelete(nil, v0136, v0152);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    env = stack[-4];
    v0152 = CC_vunion(env, stack[-2], v0152);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    {
        LispObject v0121 = stack[0];
        popv(5);
        return cons(v0121, v0152);
    }

v0154:
    stack[0] = stack[-3];
    v0152 = stack[-2];
    stack[-2] = qcdr(v0152);
    v0136 = stack[-3];
    v0152 = stack[-1];
    v0152 = Ldelete(nil, v0136, v0152);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    env = stack[-4];
    v0152 = CC_vunion(env, stack[-2], v0152);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    {
        LispObject v0135 = stack[0];
        popv(5);
        return cons(v0135, v0152);
    }

v0048:
    v0152 = stack[-2];
    stack[0] = qcar(v0152);
    v0152 = stack[-2];
    v0136 = qcdr(v0152);
    v0152 = stack[-1];
    v0152 = CC_vunion(env, v0136, v0152);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    {
        LispObject v0134 = stack[0];
        popv(5);
        return cons(v0134, v0152);
    }
// error exit handlers
v0153:
    popv(5);
    return nil;
}



// Code for formboollis

static LispObject CC_formboollis(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0088, v0089, v0156;
    LispObject fn;
    LispObject v0004, v0013, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "formboollis");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0013 = va_arg(aa, LispObject);
    v0004 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for formboollis");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0004,v0013,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0001,v0013,v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0004;
    stack[-1] = v0013;
    stack[-2] = v0001;
    stack[-3] = v0000;
// end of prologue
    stack[-4] = nil;
    goto v0140;

v0140:
    v0088 = stack[-3];
    if (v0088 == nil) goto v0093;
    v0088 = stack[0];
    if (v0088 == nil) goto v0073;
    v0088 = stack[-3];
    v0156 = qcar(v0088);
    v0089 = stack[-2];
    v0088 = stack[-1];
    fn = elt(env, 1); // formbool
    v0089 = (*qfnn(fn))(qenv(fn), 3, v0156, v0089, v0088);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-5];
    v0088 = stack[-4];
    v0088 = cons(v0089, v0088);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-5];
    stack[-4] = v0088;
    goto v0041;

v0041:
    v0088 = stack[-3];
    v0088 = qcdr(v0088);
    stack[-3] = v0088;
    goto v0140;

v0073:
    v0088 = stack[-3];
    v0156 = qcar(v0088);
    v0089 = stack[-2];
    v0088 = stack[-1];
    fn = elt(env, 2); // formc!*
    v0089 = (*qfnn(fn))(qenv(fn), 3, v0156, v0089, v0088);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-5];
    v0088 = stack[-4];
    v0088 = cons(v0089, v0088);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-5];
    stack[-4] = v0088;
    goto v0041;

v0093:
    v0088 = stack[-4];
    {
        popv(6);
        fn = elt(env, 3); // reversip!*
        return (*qfn1(fn))(qenv(fn), v0088);
    }
// error exit handlers
v0068:
    popv(6);
    return nil;
}



// Code for width

static LispObject CC_width(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0155, v0175, v0176;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for width");
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
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0001;
    v0175 = v0000;
// end of prologue
    v0176 = v0175;
    v0155 = elt(env, 1); // textag
    v0155 = get(v0176, v0155);
    env = stack[-2];
    stack[-1] = v0155;
    v0155 = stack[-1];
    if (!(v0155 == nil)) goto v0162;
    v0155 = elt(env, 2); // "cannot find item "
    v0175 = list2(v0155, v0175);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-2];
    v0155 = elt(env, 3); // fatal
    fn = elt(env, 5); // tri!-error
    v0155 = (*qfn2(fn))(qenv(fn), v0175, v0155);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-2];
    goto v0162;

v0162:
    v0175 = stack[0];
    v0155 = (LispObject)1; // 0
    v0155 = (LispObject)greaterp2(v0175, v0155);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    v0155 = v0155 ? lisp_true : nil;
    env = stack[-2];
    if (v0155 == nil) goto v0005;
    v0155 = stack[-1];
    v0155 = qcdr(v0155);
    if (v0155 == nil) goto v0005;
    v0155 = stack[-1];
    v0155 = qcdr(v0155);
    stack[-1] = v0155;
    v0155 = stack[0];
    v0155 = sub1(v0155);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-2];
    stack[0] = v0155;
    goto v0162;

v0005:
    v0155 = stack[-1];
    v0155 = qcar(v0155);
    if (!(v0155 == nil)) { popv(3); return onevalue(v0155); }
    v0155 = (LispObject)1; // 0
    { popv(3); return onevalue(v0155); }
// error exit handlers
v0068:
    popv(3);
    return nil;
}



// Code for get_char_group

static LispObject CC_get_char_group(LispObject env,
                         LispObject v0000)
{
    LispObject v0083;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for get_char_group");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0083 = v0000;
// end of prologue
    v0083 = qcar(v0083);
    return onevalue(v0083);
}



// Code for cl_susiupdknowl2

static LispObject CC_cl_susiupdknowl2(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0183, v0184, v0185;
    LispObject fn;
    LispObject v0013, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "cl_susiupdknowl2");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0013 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cl_susiupdknowl2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0013,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0013);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[-4] = v0013;
    stack[-5] = v0001;
    stack[-6] = v0000;
// end of prologue
    stack[-3] = nil;
    stack[-1] = nil;
    stack[0] = nil;
    v0183 = stack[-5];
    stack[-2] = v0183;
    goto v0059;

v0059:
    v0183 = stack[-2];
    if (v0183 == nil) goto v0186;
    v0183 = stack[-2];
    v0183 = qcar(v0183);
    stack[-7] = v0183;
    v0183 = stack[-2];
    v0183 = qcdr(v0183);
    stack[-2] = v0183;
    v0184 = stack[-7];
    v0183 = stack[-6];
    fn = elt(env, 4); // rl_susibin
    v0183 = (*qfn2(fn))(qenv(fn), v0184, v0183);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-8];
    stack[-3] = v0183;
    v0184 = stack[-3];
    v0183 = elt(env, 2); // false
    if (v0184 == v0183) goto v0007;
    v0185 = stack[-3];
    v0184 = stack[-5];
    v0183 = stack[-7];
    fn = elt(env, 5); // cl_susiinter
    v0183 = (*qfnn(fn))(qenv(fn), 3, v0185, v0184, v0183);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-8];
    stack[-3] = v0183;
    v0184 = stack[0];
    v0183 = stack[-3];
    v0183 = qcdr(v0183);
    v0183 = qcar(v0183);
    v0183 = Lnconc(nil, v0184, v0183);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-8];
    stack[0] = v0183;
    v0183 = stack[-3];
    v0183 = qcar(v0183);
    stack[-5] = v0183;
    v0183 = stack[-3];
    v0183 = qcdr(v0183);
    v0183 = qcdr(v0183);
    v0183 = qcar(v0183);
    if (!(v0183 == nil)) goto v0101;

v0101:
    v0183 = stack[-3];
    v0183 = qcdr(v0183);
    v0183 = qcdr(v0183);
    v0183 = qcdr(v0183);
    v0183 = qcar(v0183);
    if (v0183 == nil) goto v0059;
    v0183 = qvalue(elt(env, 3)); // t
    stack[-1] = v0183;
    v0183 = qvalue(elt(env, 1)); // nil
    stack[-2] = v0183;
    goto v0059;

v0007:
    v0183 = qvalue(elt(env, 1)); // nil
    stack[-2] = v0183;
    goto v0059;

v0186:
    v0184 = stack[-3];
    v0183 = elt(env, 2); // false
    if (v0184 == v0183) goto v0170;
    v0183 = stack[-1];
    if (!(v0183 == nil)) goto v0026;
    v0184 = stack[-6];
    v0183 = stack[-5];
    v0183 = cons(v0184, v0183);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-8];
    stack[-5] = v0183;
    goto v0026;

v0026:
    v0183 = stack[0];
    if (v0183 == nil) { LispObject res = stack[-5]; popv(9); return onevalue(res); }
    v0183 = stack[0];
    v0185 = qcar(v0183);
    v0184 = stack[-5];
    v0183 = stack[-4];
    v0183 = CC_cl_susiupdknowl2(env, 3, v0185, v0184, v0183);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-8];
    stack[-5] = v0183;
    v0184 = stack[-5];
    v0183 = elt(env, 2); // false
    if (v0184 == v0183) goto v0187;
    v0183 = stack[0];
    v0183 = qcdr(v0183);
    stack[0] = v0183;
    goto v0026;

v0187:
    v0183 = qvalue(elt(env, 1)); // nil
    stack[0] = v0183;
    goto v0026;

v0170:
    v0183 = elt(env, 2); // false
    { popv(9); return onevalue(v0183); }
// error exit handlers
v0165:
    popv(9);
    return nil;
}



// Code for ev_sum

static LispObject CC_ev_sum(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0055, v0010, v0056;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ev_sum");
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
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0001;
    stack[-1] = v0000;
// end of prologue
    v0056 = nil;
    goto v0140;

v0140:
    v0055 = stack[-1];
    if (v0055 == nil) goto v0108;
    v0055 = stack[-1];
    v0010 = qcar(v0055);
    v0055 = stack[0];
    v0055 = qcar(v0055);
    v0055 = (LispObject)(int32_t)((int32_t)v0010 + (int32_t)v0055 - TAG_FIXNUM);
    v0010 = v0056;
    v0055 = cons(v0055, v0010);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-2];
    v0056 = v0055;
    v0055 = stack[-1];
    v0055 = qcdr(v0055);
    stack[-1] = v0055;
    v0055 = stack[0];
    v0055 = qcdr(v0055);
    stack[0] = v0055;
    goto v0140;

v0108:
    v0055 = v0056;
        popv(3);
        return Lnreverse(nil, v0055);
// error exit handlers
v0162:
    popv(3);
    return nil;
}



// Code for semanticml

static LispObject CC_semanticml(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0067, v0076;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for semanticml");
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
    v0067 = stack[0];
    v0076 = Llength(nil, v0067);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[-1];
    v0067 = (LispObject)17; // 1
    v0067 = (LispObject)greaterp2(v0076, v0067);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    v0067 = v0067 ? lisp_true : nil;
    env = stack[-1];
    if (v0067 == nil) goto v0011;
    v0067 = elt(env, 1); // "<apply>"
    fn = elt(env, 15); // printout
    v0067 = (*qfn1(fn))(qenv(fn), v0067);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[-1];
    v0067 = qvalue(elt(env, 2)); // t
    fn = elt(env, 16); // indent!*
    v0067 = (*qfn1(fn))(qenv(fn), v0067);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[-1];
    v0067 = elt(env, 3); // "<fn>"
    fn = elt(env, 15); // printout
    v0067 = (*qfn1(fn))(qenv(fn), v0067);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[-1];
    v0067 = qvalue(elt(env, 2)); // t
    fn = elt(env, 16); // indent!*
    v0067 = (*qfn1(fn))(qenv(fn), v0067);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[-1];
    goto v0011;

v0011:
    v0067 = elt(env, 5); // "<semantic>"
    fn = elt(env, 15); // printout
    v0067 = (*qfn1(fn))(qenv(fn), v0067);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[-1];
    v0067 = qvalue(elt(env, 2)); // t
    fn = elt(env, 16); // indent!*
    v0067 = (*qfn1(fn))(qenv(fn), v0067);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[-1];
    v0067 = elt(env, 6); // "<ci><mo>"
    fn = elt(env, 15); // printout
    v0067 = (*qfn1(fn))(qenv(fn), v0067);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[-1];
    v0067 = stack[0];
    v0067 = qcar(v0067);
    v0067 = qcar(v0067);
    v0067 = Lprinc(nil, v0067);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[-1];
    v0067 = elt(env, 7); // "</mo></ci>"
    v0067 = Lprinc(nil, v0067);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[-1];
    v0067 = elt(env, 8); // "<annotation-xml encoding=""OpenMath"">"
    fn = elt(env, 15); // printout
    v0067 = (*qfn1(fn))(qenv(fn), v0067);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[-1];
    v0067 = qvalue(elt(env, 2)); // t
    fn = elt(env, 16); // indent!*
    v0067 = (*qfn1(fn))(qenv(fn), v0067);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[-1];
    v0067 = elt(env, 9); // "<"
    fn = elt(env, 15); // printout
    v0067 = (*qfn1(fn))(qenv(fn), v0067);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[-1];
    v0067 = stack[0];
    v0067 = qcar(v0067);
    v0067 = qcdr(v0067);
    v0067 = qcar(v0067);
    fn = elt(env, 17); // mathml_list2string
    v0067 = (*qfn1(fn))(qenv(fn), v0067);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[-1];
    v0067 = elt(env, 10); // ">"
    v0067 = Lprinc(nil, v0067);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[-1];
    v0067 = qvalue(elt(env, 4)); // nil
    fn = elt(env, 16); // indent!*
    v0067 = (*qfn1(fn))(qenv(fn), v0067);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[-1];
    v0067 = elt(env, 11); // "</annotation-xml>"
    fn = elt(env, 15); // printout
    v0067 = (*qfn1(fn))(qenv(fn), v0067);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[-1];
    v0067 = qvalue(elt(env, 4)); // nil
    fn = elt(env, 16); // indent!*
    v0067 = (*qfn1(fn))(qenv(fn), v0067);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[-1];
    v0067 = elt(env, 12); // "</semantic>"
    fn = elt(env, 15); // printout
    v0067 = (*qfn1(fn))(qenv(fn), v0067);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[-1];
    v0067 = stack[0];
    v0076 = Llength(nil, v0067);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[-1];
    v0067 = (LispObject)17; // 1
    v0067 = (LispObject)greaterp2(v0076, v0067);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    v0067 = v0067 ? lisp_true : nil;
    env = stack[-1];
    if (v0067 == nil) goto v0071;
    v0067 = qvalue(elt(env, 4)); // nil
    fn = elt(env, 16); // indent!*
    v0067 = (*qfn1(fn))(qenv(fn), v0067);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[-1];
    v0067 = elt(env, 13); // "</fn>"
    fn = elt(env, 15); // printout
    v0067 = (*qfn1(fn))(qenv(fn), v0067);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[-1];
    v0067 = stack[0];
    v0067 = qcdr(v0067);
    fn = elt(env, 18); // multi_elem
    v0067 = (*qfn1(fn))(qenv(fn), v0067);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[-1];
    v0067 = qvalue(elt(env, 4)); // nil
    fn = elt(env, 16); // indent!*
    v0067 = (*qfn1(fn))(qenv(fn), v0067);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[-1];
    v0067 = elt(env, 14); // "</apply>"
    fn = elt(env, 15); // printout
    v0067 = (*qfn1(fn))(qenv(fn), v0067);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    goto v0071;

v0071:
    v0067 = nil;
    { popv(2); return onevalue(v0067); }
// error exit handlers
v0035:
    popv(2);
    return nil;
}



// Code for exptplus

static LispObject CC_exptplus(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0040, v0130, v0080;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for exptplus");
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
    v0130 = v0001;
    v0080 = v0000;
// end of prologue
    v0040 = v0080;
    if (!consp(v0040)) goto v0011;
    v0040 = v0130;
    if (!consp(v0040)) goto v0055;
    v0040 = elt(env, 1); // "Bad exponent sum"
    {
        fn = elt(env, 2); // interr
        return (*qfn1(fn))(qenv(fn), v0040);
    }

v0055:
    v0040 = v0080;
    v0040 = qcar(v0040);
    v0040 = plus2(v0040, v0130);
    errexit();
    return ncons(v0040);

v0011:
    v0040 = v0130;
    if (!consp(v0040)) goto v0060;
    v0040 = v0080;
    v0130 = qcar(v0130);
    v0040 = plus2(v0040, v0130);
    errexit();
    return ncons(v0040);

v0060:
    v0040 = v0080;
    return plus2(v0040, v0130);
}



// Code for derad

static LispObject CC_derad(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0187, v0119, v0120;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for derad");
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
    goto v0083;

v0083:
    v0187 = stack[0];
    if (v0187 == nil) goto v0046;
    v0187 = stack[0];
    v0187 = qcar(v0187);
    if (is_number(v0187)) goto v0092;
    v0119 = stack[-1];
    v0187 = stack[0];
    v0187 = qcar(v0187);
    if (equal(v0119, v0187)) goto v0006;
    v0119 = stack[-1];
    v0187 = stack[0];
    v0187 = qcar(v0187);
    fn = elt(env, 1); // ordp
    v0187 = (*qfn2(fn))(qenv(fn), v0119, v0187);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-3];
    if (v0187 == nil) goto v0025;
    v0119 = stack[-1];
    v0187 = stack[0];
    v0187 = cons(v0119, v0187);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-3];
    {
        LispObject v0178 = stack[-2];
        popv(4);
        fn = elt(env, 2); // nreverse
        return (*qfn2(fn))(qenv(fn), v0178, v0187);
    }

v0025:
    v0187 = stack[0];
    v0119 = qcar(v0187);
    v0187 = stack[-2];
    v0187 = cons(v0119, v0187);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-3];
    stack[-2] = v0187;
    v0187 = stack[0];
    v0187 = qcdr(v0187);
    stack[0] = v0187;
    goto v0083;

v0006:
    v0187 = stack[0];
    v0187 = qcdr(v0187);
    if (v0187 == nil) goto v0189;
    v0187 = stack[0];
    v0187 = qcdr(v0187);
    v0187 = qcar(v0187);
    if (!(is_number(v0187))) goto v0189;
    v0187 = stack[0];
    v0187 = qcdr(v0187);
    v0187 = qcar(v0187);
    v0119 = add1(v0187);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-3];
    v0187 = stack[0];
    v0187 = qcdr(v0187);
    v0187 = qcdr(v0187);
    v0187 = list2star(stack[-1], v0119, v0187);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-3];
    {
        LispObject v0177 = stack[-2];
        popv(4);
        fn = elt(env, 2); // nreverse
        return (*qfn2(fn))(qenv(fn), v0177, v0187);
    }

v0189:
    v0120 = stack[-1];
    v0119 = (LispObject)33; // 2
    v0187 = stack[0];
    v0187 = qcdr(v0187);
    v0187 = list2star(v0120, v0119, v0187);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-3];
    {
        LispObject v0021 = stack[-2];
        popv(4);
        fn = elt(env, 2); // nreverse
        return (*qfn2(fn))(qenv(fn), v0021, v0187);
    }

v0092:
    v0187 = stack[0];
    v0119 = qcar(v0187);
    v0187 = stack[-2];
    v0187 = cons(v0119, v0187);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-3];
    stack[-2] = v0187;
    v0187 = stack[0];
    v0187 = qcdr(v0187);
    stack[0] = v0187;
    goto v0083;

v0046:
    stack[0] = stack[-2];
    v0187 = stack[-1];
    v0187 = ncons(v0187);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-3];
    {
        LispObject v0019 = stack[0];
        popv(4);
        fn = elt(env, 2); // nreverse
        return (*qfn2(fn))(qenv(fn), v0019, v0187);
    }
// error exit handlers
v0161:
    popv(4);
    return nil;
}



// Code for evalvars

static LispObject CC_evalvars(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0186, v0033;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evalvars");
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
    v0186 = stack[-1];
    if (v0186 == nil) goto v0140;
    v0186 = stack[-1];
    v0186 = qcar(v0186);
    if (!consp(v0186)) goto v0061;
    v0186 = stack[-1];
    v0186 = qcar(v0186);
    v0033 = qcar(v0186);
    v0186 = elt(env, 2); // intfn
    v0186 = Lflagp(nil, v0033, v0186);
    env = stack[-3];
    goto v0059;

v0059:
    if (v0186 == nil) goto v0074;
    v0186 = stack[-1];
    v0033 = qcar(v0186);
    v0186 = stack[-2];
    v0186 = cons(v0033, v0186);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    env = stack[-3];
    stack[-2] = v0186;
    v0186 = stack[-1];
    v0186 = qcdr(v0186);
    stack[-1] = v0186;
    goto v0011;

v0074:
    v0186 = stack[-1];
    v0186 = qcar(v0186);
    v0186 = qcar(v0186);
    if (!symbolp(v0186)) v0033 = nil;
    else { v0033 = qfastgets(v0186);
           if (v0033 != nil) { v0033 = elt(v0033, 2); // rtype
#ifdef RECORD_GET
             if (v0033 != SPID_NOPROP)
                record_get(elt(fastget_names, 2), 1);
             else record_get(elt(fastget_names, 2), 0),
                v0033 = nil; }
           else record_get(elt(fastget_names, 2), 0); }
#else
             if (v0033 == SPID_NOPROP) v0033 = nil; }}
#endif
    v0186 = elt(env, 3); // setelemfn
    v0186 = get(v0033, v0186);
    env = stack[-3];
    if (v0186 == nil) goto v0096;
    v0186 = stack[-1];
    v0186 = qcar(v0186);
    stack[0] = qcar(v0186);
    v0186 = stack[-1];
    v0186 = qcar(v0186);
    v0186 = qcdr(v0186);
    fn = elt(env, 4); // revlis_without_mode
    v0033 = (*qfn1(fn))(qenv(fn), v0186);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    env = stack[-3];
    v0186 = stack[-2];
    v0186 = acons(stack[0], v0033, v0186);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    env = stack[-3];
    stack[-2] = v0186;
    v0186 = stack[-1];
    v0186 = qcdr(v0186);
    stack[-1] = v0186;
    goto v0011;

v0096:
    v0186 = stack[-1];
    v0186 = qcar(v0186);
    stack[0] = qcar(v0186);
    v0186 = stack[-1];
    v0186 = qcar(v0186);
    v0186 = qcdr(v0186);
    fn = elt(env, 5); // revlis
    v0033 = (*qfn1(fn))(qenv(fn), v0186);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    env = stack[-3];
    v0186 = stack[-2];
    v0186 = acons(stack[0], v0033, v0186);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    env = stack[-3];
    stack[-2] = v0186;
    v0186 = stack[-1];
    v0186 = qcdr(v0186);
    stack[-1] = v0186;
    goto v0011;

v0061:
    v0186 = qvalue(elt(env, 1)); // t
    goto v0059;

v0140:
    v0186 = stack[-2];
    {
        popv(4);
        fn = elt(env, 6); // nreverse
        return (*qfn1(fn))(qenv(fn), v0186);
    }
// error exit handlers
v0173:
    popv(4);
    return nil;
}



// Code for vdp2a

static LispObject CC_vdp2a(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0140;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vdp2a");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0140 = v0000;
// end of prologue
    v0140 = qcdr(v0140);
    v0140 = qcdr(v0140);
    v0140 = qcdr(v0140);
    v0140 = qcar(v0140);
    {
        fn = elt(env, 1); // dip2a
        return (*qfn1(fn))(qenv(fn), v0140);
    }
}



// Code for gfplusn

static LispObject CC_gfplusn(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0164, v0072;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gfplusn");
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
    v0164 = stack[-1];
    v0164 = qcar(v0164);
    if (!consp(v0164)) goto v0041;
    v0164 = stack[-1];
    v0072 = qcar(v0164);
    v0164 = stack[0];
    v0164 = qcar(v0164);
    fn = elt(env, 1); // plus!:
    stack[-2] = (*qfn2(fn))(qenv(fn), v0072, v0164);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-3];
    v0164 = stack[-1];
    v0072 = qcdr(v0164);
    v0164 = stack[0];
    v0164 = qcdr(v0164);
    fn = elt(env, 1); // plus!:
    v0164 = (*qfn2(fn))(qenv(fn), v0072, v0164);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    {
        LispObject v0130 = stack[-2];
        popv(4);
        return cons(v0130, v0164);
    }

v0041:
    v0072 = stack[-1];
    v0164 = stack[0];
    {
        popv(4);
        fn = elt(env, 2); // gffplus
        return (*qfn2(fn))(qenv(fn), v0072, v0164);
    }
// error exit handlers
v0040:
    popv(4);
    return nil;
}



// Code for repartsq

static LispObject CC_repartsq(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0101, v0099, v0081, v0098;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for repartsq");
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
    v0101 = stack[0];
    v0101 = qcar(v0101);
    fn = elt(env, 1); // splitcomplex
    stack[-1] = (*qfn1(fn))(qenv(fn), v0101);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-4];
    v0101 = stack[0];
    v0101 = qcdr(v0101);
    fn = elt(env, 1); // splitcomplex
    v0101 = (*qfn1(fn))(qenv(fn), v0101);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-4];
    v0081 = stack[-1];
    v0099 = v0101;
    v0101 = v0081;
    v0101 = qcar(v0101);
    v0098 = qcdr(v0081);
    v0081 = v0099;
    v0081 = qcar(v0081);
    v0099 = qcdr(v0099);
    stack[-3] = v0098;
    stack[-2] = v0081;
    stack[-1] = v0099;
    v0099 = v0101;
    v0101 = stack[-2];
    fn = elt(env, 2); // multsq
    stack[0] = (*qfn2(fn))(qenv(fn), v0099, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-4];
    v0099 = stack[-3];
    v0101 = stack[-1];
    fn = elt(env, 2); // multsq
    v0101 = (*qfn2(fn))(qenv(fn), v0099, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-4];
    fn = elt(env, 3); // addsq
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v0101);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-4];
    v0099 = stack[-2];
    v0101 = stack[-2];
    fn = elt(env, 2); // multsq
    stack[-2] = (*qfn2(fn))(qenv(fn), v0099, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-4];
    v0099 = stack[-1];
    v0101 = stack[-1];
    fn = elt(env, 2); // multsq
    v0101 = (*qfn2(fn))(qenv(fn), v0099, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-4];
    fn = elt(env, 3); // addsq
    v0101 = (*qfn2(fn))(qenv(fn), stack[-2], v0101);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-4];
    fn = elt(env, 4); // invsq
    v0101 = (*qfn1(fn))(qenv(fn), v0101);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-4];
    {
        LispObject v0065 = stack[0];
        popv(5);
        fn = elt(env, 2); // multsq
        return (*qfn2(fn))(qenv(fn), v0065, v0101);
    }
// error exit handlers
v0154:
    popv(5);
    return nil;
}



// Code for clogsq!*

static LispObject CC_clogsqH(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0062, v0063;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for clogsq*");
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
    v0062 = v0000;
// end of prologue
    stack[-3] = qvalue(elt(env, 1)); // !*div
    qvalue(elt(env, 1)) = nil; // !*div
    stack[-2] = qvalue(elt(env, 2)); // !*combinelogs
    qvalue(elt(env, 2)) = nil; // !*combinelogs
    stack[-1] = qvalue(elt(env, 3)); // !*expandlogs
    qvalue(elt(env, 3)) = nil; // !*expandlogs
    v0063 = qvalue(elt(env, 4)); // t
    qvalue(elt(env, 3)) = v0063; // !*expandlogs
    qvalue(elt(env, 1)) = v0063; // !*div
    v0063 = qvalue(elt(env, 4)); // t
    stack[0] = qvalue(elt(env, 5)); // !*uncached
    qvalue(elt(env, 5)) = v0063; // !*uncached
    fn = elt(env, 7); // prepsq
    v0062 = (*qfn1(fn))(qenv(fn), v0062);
    nil = C_nil;
    if (exception_pending()) goto v0075;
    env = stack[-4];
    fn = elt(env, 8); // simp
    v0062 = (*qfn1(fn))(qenv(fn), v0062);
    nil = C_nil;
    if (exception_pending()) goto v0075;
    env = stack[-4];
    qvalue(elt(env, 5)) = stack[0]; // !*uncached
    v0063 = qvalue(elt(env, 6)); // nil
    qvalue(elt(env, 3)) = v0063; // !*expandlogs
    fn = elt(env, 9); // prepsq!*
    v0062 = (*qfn1(fn))(qenv(fn), v0062);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-4];
    fn = elt(env, 10); // comblog
    v0062 = (*qfn1(fn))(qenv(fn), v0062);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-4];
    fn = elt(env, 11); // simp!*
    v0062 = (*qfn1(fn))(qenv(fn), v0062);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-4];
    qvalue(elt(env, 3)) = stack[-1]; // !*expandlogs
    qvalue(elt(env, 2)) = stack[-2]; // !*combinelogs
    qvalue(elt(env, 1)) = stack[-3]; // !*div
    { popv(5); return onevalue(v0062); }
// error exit handlers
v0048:
    env = stack[-4];
    qvalue(elt(env, 3)) = stack[-1]; // !*expandlogs
    qvalue(elt(env, 2)) = stack[-2]; // !*combinelogs
    qvalue(elt(env, 1)) = stack[-3]; // !*div
    popv(5);
    return nil;
v0075:
    env = stack[-4];
    qvalue(elt(env, 5)) = stack[0]; // !*uncached
    qvalue(elt(env, 3)) = stack[-1]; // !*expandlogs
    qvalue(elt(env, 2)) = stack[-2]; // !*combinelogs
    qvalue(elt(env, 1)) = stack[-3]; // !*div
    popv(5);
    return nil;
}



// Code for assert_stat!-parse

static LispObject CC_assert_statKparse(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0189, v0190, v0146;
    LispObject fn;
    argcheck(nargs, 0, "assert_stat-parse");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for assert_stat-parse");
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
    fn = elt(env, 9); // scan
    v0189 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-3];
    stack[-2] = v0189;
    fn = elt(env, 9); // scan
    v0190 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-3];
    v0189 = elt(env, 1); // !*colon!*
    if (v0190 == v0189) goto v0140;
    v0190 = elt(env, 2); // "expecting ':' in assert but found"
    v0189 = qvalue(elt(env, 3)); // cursym!*
    v0189 = list2(v0190, v0189);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-3];
    fn = elt(env, 10); // rederr
    v0189 = (*qfn1(fn))(qenv(fn), v0189);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-3];
    goto v0140;

v0140:
    fn = elt(env, 11); // assert_stat1
    v0189 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-3];
    stack[-1] = v0189;
    fn = elt(env, 9); // scan
    v0190 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-3];
    v0189 = elt(env, 4); // difference
    if (v0190 == v0189) goto v0073;
    v0189 = qvalue(elt(env, 5)); // t
    goto v0003;

v0003:
    if (v0189 == nil) goto v0079;
    v0190 = elt(env, 7); // "expecting '->' in assert but found"
    v0189 = qvalue(elt(env, 3)); // cursym!*
    v0189 = list2(v0190, v0189);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-3];
    fn = elt(env, 10); // rederr
    v0189 = (*qfn1(fn))(qenv(fn), v0189);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-3];
    goto v0079;

v0079:
    fn = elt(env, 9); // scan
    v0189 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-3];
    stack[0] = v0189;
    fn = elt(env, 9); // scan
    v0189 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-3];
    if (!symbolp(v0189)) v0189 = nil;
    else { v0189 = qfastgets(v0189);
           if (v0189 != nil) { v0189 = elt(v0189, 55); // delim
#ifdef RECORD_GET
             if (v0189 == SPID_NOPROP)
                record_get(elt(fastget_names, 55), 0),
                v0189 = nil;
             else record_get(elt(fastget_names, 55), 1),
                v0189 = lisp_true; }
           else record_get(elt(fastget_names, 55), 0); }
#else
             if (v0189 == SPID_NOPROP) v0189 = nil; else v0189 = lisp_true; }}
#endif
    if (!(v0189 == nil)) goto v0102;
    v0190 = elt(env, 8); // "expecting end of assert but found"
    v0189 = qvalue(elt(env, 3)); // cursym!*
    v0189 = list2(v0190, v0189);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-3];
    fn = elt(env, 10); // rederr
    v0189 = (*qfn1(fn))(qenv(fn), v0189);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    goto v0102;

v0102:
    v0146 = stack[-2];
    v0190 = stack[-1];
    v0189 = stack[0];
    popv(4);
    return list3(v0146, v0190, v0189);

v0073:
    fn = elt(env, 9); // scan
    v0190 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-3];
    v0189 = elt(env, 6); // greaterp
    v0189 = Lneq(nil, v0190, v0189);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-3];
    goto v0003;
// error exit handlers
v0186:
    popv(4);
    return nil;
}



// Code for mv!-pow!-!>

static LispObject CC_mvKpowKS(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0010, v0056, v0057, v0058;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mv-pow->");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0056 = v0001;
    v0057 = v0000;
// end of prologue

v0011:
    v0010 = v0057;
    if (v0010 == nil) goto v0140;
    v0010 = v0057;
    v0058 = qcar(v0010);
    v0010 = v0056;
    v0010 = qcar(v0010);
    if (equal(v0058, v0010)) goto v0047;
    v0010 = v0057;
    v0010 = qcar(v0010);
    v0056 = qcar(v0056);
        return Lgreaterp(nil, v0010, v0056);

v0047:
    v0010 = v0057;
    v0010 = qcdr(v0010);
    v0057 = v0010;
    v0010 = v0056;
    v0010 = qcdr(v0010);
    v0056 = v0010;
    goto v0011;

v0140:
    v0010 = qvalue(elt(env, 1)); // nil
    return onevalue(v0010);
}



// Code for symbol

static LispObject CC_symbol(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0101, v0099, v0081;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for symbol");
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
    v0099 = v0000;
// end of prologue
    v0101 = qvalue(elt(env, 1)); // !*utf8
    if (v0101 == nil) goto v0176;
    v0101 = qvalue(elt(env, 2)); // !*utf82d
    if (v0101 == nil) goto v0074;
    v0081 = v0099;
    v0101 = elt(env, 3); // utf8_2d!-symbol!-character
    v0101 = get(v0081, v0101);
    env = stack[0];
    if (!(v0101 == nil)) { popv(1); return onevalue(v0101); }
    v0081 = v0099;
    v0101 = elt(env, 4); // utf8_symbol!-character
    v0101 = get(v0081, v0101);
    env = stack[0];
    if (!(v0101 == nil)) { popv(1); return onevalue(v0101); }
    v0101 = v0099;
    v0099 = elt(env, 5); // symbol!-character
    popv(1);
    return get(v0101, v0099);

v0074:
    v0081 = v0099;
    v0101 = elt(env, 4); // utf8_symbol!-character
    v0101 = get(v0081, v0101);
    env = stack[0];
    if (!(v0101 == nil)) { popv(1); return onevalue(v0101); }
    v0101 = v0099;
    v0099 = elt(env, 5); // symbol!-character
    popv(1);
    return get(v0101, v0099);

v0176:
    v0101 = v0099;
    v0099 = elt(env, 5); // symbol!-character
    popv(1);
    return get(v0101, v0099);
}



// Code for general!-ordered!-gcd!-mod!-p

static LispObject CC_generalKorderedKgcdKmodKp(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0102, v0154;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for general-ordered-gcd-mod-p");
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
    v0102 = (LispObject)1; // 0
    stack[-2] = v0102;
    goto v0094;

v0094:
    v0154 = stack[-1];
    v0102 = stack[0];
    fn = elt(env, 3); // general!-reduce!-degree!-mod!-p
    v0102 = (*qfn2(fn))(qenv(fn), v0154, v0102);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-3];
    stack[-1] = v0102;
    v0102 = stack[-1];
    if (v0102 == nil) goto v0062;
    v0102 = stack[-2];
    v0102 = add1(v0102);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-3];
    stack[-2] = v0102;
    v0102 = stack[-1];
    if (!consp(v0102)) goto v0084;
    v0102 = stack[-1];
    v0102 = qcar(v0102);
    v0102 = (consp(v0102) ? nil : lisp_true);
    goto v0090;

v0090:
    if (v0102 == nil) goto v0080;
    v0154 = qvalue(elt(env, 2)); // reduction!-count
    v0102 = stack[-2];
    v0102 = plus2(v0154, v0102);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-3];
    qvalue(elt(env, 2)) = v0102; // reduction!-count
    v0102 = (LispObject)17; // 1
    { popv(4); return onevalue(v0102); }

v0080:
    v0102 = stack[-1];
    v0102 = qcar(v0102);
    v0102 = qcar(v0102);
    v0154 = qcdr(v0102);
    v0102 = stack[0];
    v0102 = qcar(v0102);
    v0102 = qcar(v0102);
    v0102 = qcdr(v0102);
    v0102 = (LispObject)lessp2(v0154, v0102);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    v0102 = v0102 ? lisp_true : nil;
    env = stack[-3];
    if (v0102 == nil) goto v0094;
    v0154 = qvalue(elt(env, 2)); // reduction!-count
    v0102 = stack[-2];
    v0102 = plus2(v0154, v0102);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-3];
    qvalue(elt(env, 2)) = v0102; // reduction!-count
    v0102 = (LispObject)1; // 0
    stack[-2] = v0102;
    v0102 = stack[-1];
    v0154 = v0102;
    v0102 = stack[0];
    stack[-1] = v0102;
    v0102 = v0154;
    stack[0] = v0102;
    goto v0094;

v0084:
    v0102 = qvalue(elt(env, 1)); // t
    goto v0090;

v0062:
    v0102 = stack[0];
    {
        popv(4);
        fn = elt(env, 4); // general!-monic!-mod!-p
        return (*qfn1(fn))(qenv(fn), v0102);
    }
// error exit handlers
v0076:
    popv(4);
    return nil;
}



// Code for chkrn!*

static LispObject CC_chkrnH(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0047, v0046;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for chkrn*");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0046 = v0000;
// end of prologue
    v0047 = qvalue(elt(env, 1)); // !*!*roundbf
    if (!(v0047 == nil)) return onevalue(v0046);
    v0047 = v0046;
    {
        fn = elt(env, 2); // bf2flck
        return (*qfn1(fn))(qenv(fn), v0047);
    }
}



// Code for ra_l

static LispObject CC_ra_l(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0011;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ra_l");
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
    v0011 = v0000;
// end of prologue
    fn = elt(env, 1); // ra_iv
    v0011 = (*qfn1(fn))(qenv(fn), v0011);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); // riv_l
        return (*qfn1(fn))(qenv(fn), v0011);
    }
// error exit handlers
v0083:
    popv(1);
    return nil;
}



// Code for ofsf_siatsubf

static LispObject CC_ofsf_siatsubf(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0026, v0027, v0192;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_siatsubf");
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
    v0026 = stack[-1];
    if (!consp(v0026)) goto v0060;
    v0026 = stack[-1];
    v0026 = qcar(v0026);
    v0026 = (consp(v0026) ? nil : lisp_true);
    goto v0046;

v0046:
    if (v0026 == nil) goto v0002;
    v0027 = stack[-1];
    v0026 = (LispObject)17; // 1
    popv(4);
    return cons(v0027, v0026);

v0002:
    v0026 = stack[-1];
    v0027 = qcdr(v0026);
    v0026 = stack[0];
    v0026 = CC_ofsf_siatsubf(env, v0027, v0026);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-3];
    stack[-2] = v0026;
    v0026 = stack[-1];
    v0026 = qcar(v0026);
    v0027 = qcdr(v0026);
    v0026 = stack[0];
    v0026 = CC_ofsf_siatsubf(env, v0027, v0026);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-3];
    v0027 = v0026;
    v0026 = stack[-1];
    v0026 = qcar(v0026);
    v0026 = qcar(v0026);
    v0192 = qcar(v0026);
    v0026 = stack[0];
    v0026 = Latsoc(nil, v0192, v0026);
    v0192 = v0026;
    if (v0026 == nil) goto v0031;
    stack[0] = v0027;
    v0026 = v0192;
    v0027 = qcdr(v0026);
    v0026 = stack[-1];
    v0026 = qcar(v0026);
    v0026 = qcar(v0026);
    v0026 = qcdr(v0026);
    fn = elt(env, 2); // exptsq
    v0026 = (*qfn2(fn))(qenv(fn), v0027, v0026);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-3];
    fn = elt(env, 3); // multsq
    v0027 = (*qfn2(fn))(qenv(fn), stack[0], v0026);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-3];
    v0026 = stack[-2];
    {
        popv(4);
        fn = elt(env, 4); // addsq
        return (*qfn2(fn))(qenv(fn), v0027, v0026);
    }

v0031:
    stack[0] = v0027;
    v0026 = stack[-1];
    v0026 = qcar(v0026);
    v0026 = qcar(v0026);
    v0027 = qcar(v0026);
    v0026 = stack[-1];
    v0026 = qcar(v0026);
    v0026 = qcar(v0026);
    v0026 = qcdr(v0026);
    fn = elt(env, 5); // ofsf_pow2q
    v0026 = (*qfn2(fn))(qenv(fn), v0027, v0026);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-3];
    fn = elt(env, 3); // multsq
    v0027 = (*qfn2(fn))(qenv(fn), stack[0], v0026);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-3];
    v0026 = stack[-2];
    {
        popv(4);
        fn = elt(env, 4); // addsq
        return (*qfn2(fn))(qenv(fn), v0027, v0026);
    }

v0060:
    v0026 = qvalue(elt(env, 1)); // t
    goto v0046;
// error exit handlers
v0188:
    popv(4);
    return nil;
}



// Code for cl_simpl

static LispObject CC_cl_simpl(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0154, v0065, v0066, v0067;
    LispObject fn;
    LispObject v0013, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "cl_simpl");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0013 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cl_simpl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0013,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0013);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-2] = v0013;
    v0065 = v0001;
    stack[-3] = v0000;
// end of prologue
    v0154 = qvalue(elt(env, 1)); // !*rlsism
    if (v0154 == nil) goto v0046;
    v0154 = v0065;
    fn = elt(env, 6); // cl_sitheo
    v0154 = (*qfn1(fn))(qenv(fn), v0154);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-5];
    v0065 = v0154;
    v0066 = v0065;
    v0154 = elt(env, 3); // inctheo
    if (v0066 == v0154) goto v0090;
    stack[-4] = elt(env, 4); // and
    stack[-1] = v0065;
    stack[0] = qvalue(elt(env, 2)); // nil
    v0154 = stack[-2];
    v0154 = add1(v0154);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-5];
    fn = elt(env, 7); // rl_smupdknowl
    v0154 = (*qfnn(fn))(qenv(fn), 4, stack[-4], stack[-1], stack[0], v0154);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-5];
    v0065 = v0154;
    v0066 = v0065;
    v0154 = elt(env, 5); // false
    if (v0066 == v0154) goto v0087;
    v0067 = stack[-3];
    v0066 = v0065;
    v0065 = stack[-2];
    v0154 = qvalue(elt(env, 2)); // nil
    {
        popv(6);
        fn = elt(env, 8); // cl_simpl1
        return (*qfnn(fn))(qenv(fn), 4, v0067, v0066, v0065, v0154);
    }

v0087:
    v0154 = elt(env, 3); // inctheo
    { popv(6); return onevalue(v0154); }

v0090:
    v0154 = elt(env, 3); // inctheo
    { popv(6); return onevalue(v0154); }

v0046:
    v0067 = stack[-3];
    v0066 = qvalue(elt(env, 2)); // nil
    v0065 = stack[-2];
    v0154 = qvalue(elt(env, 2)); // nil
    {
        popv(6);
        fn = elt(env, 8); // cl_simpl1
        return (*qfnn(fn))(qenv(fn), 4, v0067, v0066, v0065, v0154);
    }
// error exit handlers
v0189:
    popv(6);
    return nil;
}



// Code for ev_revgradlexcomp

static LispObject CC_ev_revgradlexcomp(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0099, v0081;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ev_revgradlexcomp");
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
    stack[-1] = v0001;
    stack[-2] = v0000;
// end of prologue

v0193:
    v0099 = stack[-2];
    if (v0099 == nil) goto v0094;
    v0099 = stack[-2];
    v0081 = qcar(v0099);
    v0099 = stack[-1];
    v0099 = qcar(v0099);
    fn = elt(env, 1); // iequal
    v0099 = (*qfn2(fn))(qenv(fn), v0081, v0099);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-4];
    if (v0099 == nil) goto v0060;
    v0099 = stack[-2];
    v0081 = qcdr(v0099);
    v0099 = stack[-1];
    v0099 = qcdr(v0099);
    stack[-2] = v0081;
    stack[-1] = v0099;
    goto v0193;

v0060:
    v0099 = stack[-2];
    fn = elt(env, 2); // ev_tdeg
    v0099 = (*qfn1(fn))(qenv(fn), v0099);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-4];
    stack[-3] = v0099;
    v0099 = stack[-1];
    fn = elt(env, 2); // ev_tdeg
    v0099 = (*qfn1(fn))(qenv(fn), v0099);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-4];
    stack[0] = v0099;
    v0081 = stack[-3];
    v0099 = stack[0];
    fn = elt(env, 1); // iequal
    v0099 = (*qfn2(fn))(qenv(fn), v0081, v0099);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-4];
    if (v0099 == nil) goto v0175;
    v0081 = stack[-2];
    v0099 = stack[-1];
    {
        popv(5);
        fn = elt(env, 3); // ev_invlexcomp
        return (*qfn2(fn))(qenv(fn), v0081, v0099);
    }

v0175:
    v0081 = stack[-3];
    v0099 = stack[0];
    if (((int32_t)(v0081)) > ((int32_t)(v0099))) goto v0156;
    v0099 = (LispObject)-15; // -1
    { popv(5); return onevalue(v0099); }

v0156:
    v0099 = (LispObject)17; // 1
    { popv(5); return onevalue(v0099); }

v0094:
    v0099 = (LispObject)1; // 0
    { popv(5); return onevalue(v0099); }
// error exit handlers
v0102:
    popv(5);
    return nil;
}



// Code for matrix_rows

static LispObject CC_matrix_rows(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0006, v0007;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for matrix_rows");
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
    v0006 = stack[0];
    if (v0006 == nil) goto v0011;
    v0006 = elt(env, 1); // "<matrixrow>"
    fn = elt(env, 5); // printout
    v0006 = (*qfn1(fn))(qenv(fn), v0006);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-1];
    v0007 = qvalue(elt(env, 2)); // indent
    v0006 = (LispObject)49; // 3
    v0006 = plus2(v0007, v0006);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-1];
    qvalue(elt(env, 2)) = v0006; // indent
    v0006 = stack[0];
    v0006 = qcar(v0006);
    fn = elt(env, 6); // row
    v0006 = (*qfn1(fn))(qenv(fn), v0006);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-1];
    v0007 = qvalue(elt(env, 2)); // indent
    v0006 = (LispObject)49; // 3
    v0006 = difference2(v0007, v0006);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-1];
    qvalue(elt(env, 2)) = v0006; // indent
    v0006 = elt(env, 3); // "</matrixrow>"
    fn = elt(env, 5); // printout
    v0006 = (*qfn1(fn))(qenv(fn), v0006);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-1];
    v0006 = stack[0];
    v0006 = qcdr(v0006);
    v0006 = CC_matrix_rows(env, v0006);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    goto v0011;

v0011:
    v0006 = nil;
    { popv(2); return onevalue(v0006); }
// error exit handlers
v0010:
    popv(2);
    return nil;
}



// Code for sc_getrow

static LispObject CC_sc_getrow(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0047, v0046;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sc_getrow");
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
    v0047 = v0001;
    v0046 = v0000;
// end of prologue
    stack[0] = v0046;
    v0047 = sub1(v0047);
    nil = C_nil;
    if (exception_pending()) goto v0008;
    env = stack[-1];
    {
        LispObject v0059 = stack[0];
        popv(2);
        fn = elt(env, 1); // sc_igetv
        return (*qfn2(fn))(qenv(fn), v0059, v0047);
    }
// error exit handlers
v0008:
    popv(2);
    return nil;
}



// Code for gparg1p

static LispObject CC_gparg1p(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0036;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gparg1p");
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

v0193:
    v0036 = stack[0];
    if (v0036 == nil) goto v0012;
    v0036 = stack[0];
    v0036 = qcar(v0036);
    fn = elt(env, 3); // gpargp
    v0036 = (*qfn1(fn))(qenv(fn), v0036);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-1];
    if (v0036 == nil) goto v0047;
    v0036 = stack[0];
    v0036 = qcdr(v0036);
    stack[0] = v0036;
    goto v0193;

v0047:
    v0036 = qvalue(elt(env, 2)); // nil
    { popv(2); return onevalue(v0036); }

v0012:
    v0036 = qvalue(elt(env, 1)); // t
    { popv(2); return onevalue(v0036); }
// error exit handlers
v0048:
    popv(2);
    return nil;
}



// Code for indordn

static LispObject CC_indordn(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0058, v0162;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for indordn");
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
    v0162 = v0000;
// end of prologue
    v0058 = v0162;
    if (v0058 == nil) goto v0012;
    v0058 = v0162;
    v0058 = qcdr(v0058);
    if (v0058 == nil) { popv(2); return onevalue(v0162); }
    v0058 = v0162;
    v0058 = qcdr(v0058);
    v0058 = qcdr(v0058);
    if (v0058 == nil) goto v0063;
    v0058 = v0162;
    stack[0] = qcar(v0058);
    v0058 = v0162;
    v0058 = qcdr(v0058);
    v0058 = CC_indordn(env, v0058);
    nil = C_nil;
    if (exception_pending()) goto v0164;
    env = stack[-1];
    {
        LispObject v0072 = stack[0];
        popv(2);
        fn = elt(env, 2); // indordad
        return (*qfn2(fn))(qenv(fn), v0072, v0058);
    }

v0063:
    v0058 = v0162;
    v0058 = qcar(v0058);
    v0162 = qcdr(v0162);
    v0162 = qcar(v0162);
    {
        popv(2);
        fn = elt(env, 3); // indord2
        return (*qfn2(fn))(qenv(fn), v0058, v0162);
    }

v0012:
    v0058 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0058); }
// error exit handlers
v0164:
    popv(2);
    return nil;
}



// Code for one!-entryp

static LispObject CC_oneKentryp(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0164, v0072;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for one-entryp");
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
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0001;
    stack[-1] = v0000;
// end of prologue

v0011:
    v0164 = stack[0];
    if (!consp(v0164)) goto v0140;
    v0072 = stack[-1];
    v0164 = stack[0];
    v0164 = qcar(v0164);
    v0164 = Lsmemq(nil, v0072, v0164);
    nil = C_nil;
    if (exception_pending()) goto v0039;
    env = stack[-2];
    if (v0164 == nil) goto v0057;
    v0072 = stack[-1];
    v0164 = stack[0];
    v0164 = qcdr(v0164);
    v0164 = Lsmemq(nil, v0072, v0164);
    nil = C_nil;
    if (exception_pending()) goto v0039;
    env = stack[-2];
    if (v0164 == nil) goto v0007;
    v0164 = qvalue(elt(env, 2)); // nil
    { popv(3); return onevalue(v0164); }

v0007:
    v0164 = stack[0];
    v0164 = qcar(v0164);
    stack[0] = v0164;
    goto v0011;

v0057:
    v0164 = stack[0];
    v0164 = qcdr(v0164);
    stack[0] = v0164;
    goto v0011;

v0140:
    v0164 = qvalue(elt(env, 1)); // t
    { popv(3); return onevalue(v0164); }
// error exit handlers
v0039:
    popv(3);
    return nil;
}



// Code for modp

static LispObject CC_modp(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0159, v0005;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for modp");
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
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0001;
    stack[-1] = v0000;
// end of prologue
    v0005 = stack[-1];
    v0159 = stack[0];
    v0159 = Cremainder(v0005, v0159);
    nil = C_nil;
    if (exception_pending()) goto v0055;
    env = stack[-2];
    stack[-1] = v0159;
    v0005 = stack[-1];
    v0159 = (LispObject)1; // 0
    v0159 = (LispObject)lessp2(v0005, v0159);
    nil = C_nil;
    if (exception_pending()) goto v0055;
    v0159 = v0159 ? lisp_true : nil;
    if (v0159 == nil) { LispObject res = stack[-1]; popv(3); return onevalue(res); }
    v0005 = stack[-1];
    v0159 = stack[0];
    popv(3);
    return plus2(v0005, v0159);
// error exit handlers
v0055:
    popv(3);
    return nil;
}



// Code for poly!-to!-vector

static LispObject CC_polyKtoKvector(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0040, v0130, v0080, v0174;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for poly-to-vector");
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
    push2(nil, nil);
// copy arguments values to proper place
    v0080 = v0000;
// end of prologue

v0012:
    v0040 = v0080;
    if (!consp(v0040)) goto v0093;
    v0040 = v0080;
    v0040 = qcar(v0040);
    v0040 = (consp(v0040) ? nil : lisp_true);
    goto v0041;

v0041:
    if (v0040 == nil) goto v0003;
    stack[-1] = qvalue(elt(env, 2)); // poly!-vector
    stack[0] = (LispObject)1; // 0
    v0040 = v0080;
    fn = elt(env, 3); // !*d2n
    v0040 = (*qfn1(fn))(qenv(fn), v0040);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v0040;
    { popv(2); return onevalue(v0040); }

v0003:
    v0174 = qvalue(elt(env, 2)); // poly!-vector
    v0040 = v0080;
    v0040 = qcar(v0040);
    v0040 = qcar(v0040);
    v0130 = qcdr(v0040);
    v0040 = v0080;
    v0040 = qcar(v0040);
    v0040 = qcdr(v0040);
    *(LispObject *)((char *)v0174 + (CELL-TAG_VECTOR) + ((int32_t)v0130/(16/CELL))) = v0040;
    v0040 = v0080;
    v0040 = qcdr(v0040);
    v0080 = v0040;
    goto v0012;

v0093:
    v0040 = qvalue(elt(env, 1)); // t
    goto v0041;
// error exit handlers
v0086:
    popv(2);
    return nil;
}



// Code for formbool

static LispObject CC_formbool(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0218, v0219, v0220, v0221, v0222;
    LispObject fn;
    LispObject v0013, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "formbool");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0013 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for formbool");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0013,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0013);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    stack[-2] = v0013;
    stack[-3] = v0001;
    stack[-4] = v0000;
// end of prologue
    v0219 = stack[-2];
    v0218 = elt(env, 1); // symbolic
    if (v0219 == v0218) goto v0059;
    v0218 = stack[-4];
    if (!consp(v0218)) goto v0003;
    v0218 = stack[-4];
    v0219 = qcdr(v0218);
    v0218 = stack[-3];
    fn = elt(env, 10); // intexprlisp
    v0218 = (*qfn2(fn))(qenv(fn), v0219, v0218);
    nil = C_nil;
    if (exception_pending()) goto v0223;
    env = stack[-6];
    if (v0218 == nil) goto v0077;
    v0218 = stack[-4];
    v0219 = qcar(v0218);
    v0218 = elt(env, 4); // boolfn
    v0218 = get(v0219, v0218);
    env = stack[-6];
    if (!(v0218 == nil)) { LispObject res = stack[-4]; popv(7); return onevalue(res); }

v0077:
    v0218 = stack[-4];
    v0218 = qcar(v0218);
    if (!(symbolp(v0218))) goto v0135;
    v0218 = stack[-4];
    v0219 = qcar(v0218);
    v0218 = elt(env, 4); // boolfn
    v0218 = get(v0219, v0218);
    env = stack[-6];
    if (v0218 == nil) goto v0135;
    v0218 = stack[-4];
    v0219 = qcar(v0218);
    v0218 = elt(env, 4); // boolfn
    stack[0] = get(v0219, v0218);
    env = stack[-6];
    v0218 = stack[-4];
    v0220 = qcdr(v0218);
    v0219 = stack[-3];
    v0218 = stack[-2];
    fn = elt(env, 11); // formclis
    v0218 = (*qfnn(fn))(qenv(fn), 3, v0220, v0219, v0218);
    nil = C_nil;
    if (exception_pending()) goto v0223;
    {
        LispObject v0224 = stack[0];
        popv(7);
        return cons(v0224, v0218);
    }

v0135:
    v0218 = stack[-4];
    v0218 = qcar(v0218);
    if (!(symbolp(v0218))) goto v0225;
    v0218 = stack[-4];
    v0219 = qcar(v0218);
    v0218 = elt(env, 5); // boolean
    v0218 = Lflagp(nil, v0219, v0218);
    env = stack[-6];
    if (v0218 == nil) goto v0225;
    v0218 = stack[-4];
    stack[0] = qcar(v0218);
    v0218 = stack[-4];
    v0222 = qcdr(v0218);
    v0221 = stack[-3];
    v0220 = stack[-2];
    v0218 = stack[-4];
    v0219 = qcar(v0218);
    v0218 = elt(env, 6); // boolargs
    v0218 = Lflagp(nil, v0219, v0218);
    env = stack[-6];
    fn = elt(env, 12); // formboollis
    v0218 = (*qfnn(fn))(qenv(fn), 4, v0222, v0221, v0220, v0218);
    nil = C_nil;
    if (exception_pending()) goto v0223;
    {
        LispObject v0226 = stack[0];
        popv(7);
        return cons(v0226, v0218);
    }

v0225:
    v0218 = stack[-4];
    v0219 = qcar(v0218);
    v0218 = elt(env, 3); // boolvalue!*
    if (v0219 == v0218) goto v0227;
    v0218 = stack[-4];
    v0219 = qcar(v0218);
    v0218 = elt(env, 8); // where
    if (v0219 == v0218) goto v0105;
    stack[0] = elt(env, 3); // boolvalue!*
    v0220 = stack[-4];
    v0219 = stack[-3];
    v0218 = stack[-2];
    fn = elt(env, 13); // formc!*
    v0218 = (*qfnn(fn))(qenv(fn), 3, v0220, v0219, v0218);
    nil = C_nil;
    if (exception_pending()) goto v0223;
    {
        LispObject v0228 = stack[0];
        popv(7);
        return list2(v0228, v0218);
    }

v0105:
    stack[-5] = elt(env, 3); // boolvalue!*
    stack[-1] = elt(env, 8); // where
    stack[0] = elt(env, 9); // bool!-eval
    v0218 = stack[-4];
    v0218 = qcdr(v0218);
    v0220 = qcar(v0218);
    v0219 = stack[-3];
    v0218 = stack[-2];
    v0218 = CC_formbool(env, 3, v0220, v0219, v0218);
    nil = C_nil;
    if (exception_pending()) goto v0223;
    env = stack[-6];
    v0218 = list2(stack[0], v0218);
    nil = C_nil;
    if (exception_pending()) goto v0223;
    env = stack[-6];
    v0219 = Lmkquote(nil, v0218);
    nil = C_nil;
    if (exception_pending()) goto v0223;
    env = stack[-6];
    v0218 = stack[-4];
    v0218 = qcdr(v0218);
    v0218 = qcdr(v0218);
    v0218 = qcar(v0218);
    v0220 = list3(stack[-1], v0219, v0218);
    nil = C_nil;
    if (exception_pending()) goto v0223;
    env = stack[-6];
    v0219 = stack[-3];
    v0218 = stack[-2];
    fn = elt(env, 13); // formc!*
    v0218 = (*qfnn(fn))(qenv(fn), 3, v0220, v0219, v0218);
    nil = C_nil;
    if (exception_pending()) goto v0223;
    {
        LispObject v0229 = stack[-5];
        popv(7);
        return list2(v0229, v0218);
    }

v0227:
    v0218 = elt(env, 7); // "Too many formbools"
    {
        popv(7);
        fn = elt(env, 14); // rederr
        return (*qfn1(fn))(qenv(fn), v0218);
    }

v0003:
    v0219 = stack[-4];
    v0218 = lisp_true;
    if (v0219 == v0218) { LispObject res = stack[-4]; popv(7); return onevalue(res); }
    v0218 = stack[-4];
    if (symbolp(v0218)) goto v0130;
    v0218 = qvalue(elt(env, 2)); // t
    goto v0163;

v0163:
    if (v0218 == nil) goto v0069;
    v0219 = elt(env, 3); // boolvalue!*
    v0218 = stack[-4];
    popv(7);
    return list2(v0219, v0218);

v0069:
    stack[0] = elt(env, 3); // boolvalue!*
    v0220 = stack[-4];
    v0219 = stack[-3];
    v0218 = stack[-2];
    fn = elt(env, 13); // formc!*
    v0218 = (*qfnn(fn))(qenv(fn), 3, v0220, v0219, v0218);
    nil = C_nil;
    if (exception_pending()) goto v0223;
    {
        LispObject v0230 = stack[0];
        popv(7);
        return list2(v0230, v0218);
    }

v0130:
    v0219 = stack[-4];
    v0218 = stack[-3];
    v0218 = Latsoc(nil, v0219, v0218);
    goto v0163;

v0059:
    v0220 = stack[-4];
    v0219 = stack[-3];
    v0218 = stack[-2];
    {
        popv(7);
        fn = elt(env, 15); // formc
        return (*qfnn(fn))(qenv(fn), 3, v0220, v0219, v0218);
    }
// error exit handlers
v0223:
    popv(7);
    return nil;
}



// Code for monomgetfirstmultivar

static LispObject CC_monomgetfirstmultivar(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0079, v0090, v0084;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for monomgetfirstmultivar");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0090 = v0000;
// end of prologue
    v0084 = v0090;
    v0079 = (LispObject)17; // 1
    v0079 = *(LispObject *)((char *)v0084 + (CELL-TAG_VECTOR) + ((int32_t)v0079/(16/CELL)));
    v0079 = qcar(v0079);
    if (v0079 == nil) goto v0092;
    v0079 = (LispObject)17; // 1
    v0079 = *(LispObject *)((char *)v0090 + (CELL-TAG_VECTOR) + ((int32_t)v0079/(16/CELL)));
    v0079 = qcar(v0079);
    return onevalue(v0079);

v0092:
    v0079 = (LispObject)17; // 1
    return onevalue(v0079);
}



// Code for ofsf_simplat1

static LispObject CC_ofsf_simplat1(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0237, v0212, v0213;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_simplat1");
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
    stack[-2] = v0001;
    v0213 = v0000;
// end of prologue
    v0237 = v0213;
    v0237 = qcar(v0237);
    stack[-3] = v0237;
    v0212 = stack[-3];
    v0237 = elt(env, 1); // (equal neq leq geq lessp greaterp)
    v0237 = Lmemq(nil, v0212, v0237);
    if (v0237 == nil) goto v0093;
    v0237 = v0213;
    v0237 = qcdr(v0237);
    v0237 = qcar(v0237);
    stack[-1] = v0237;
    v0237 = stack[-1];
    if (!consp(v0237)) goto v0084;
    v0237 = stack[-1];
    v0237 = qcar(v0237);
    v0237 = (consp(v0237) ? nil : lisp_true);
    goto v0090;

v0090:
    if (v0237 == nil) goto v0087;
    v0212 = stack[-3];
    v0237 = stack[-1];
    fn = elt(env, 13); // ofsf_evalatp
    v0237 = (*qfn2(fn))(qenv(fn), v0212, v0237);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-4];
    if (v0237 == nil) goto v0174;
    v0237 = elt(env, 4); // true
    { popv(5); return onevalue(v0237); }

v0174:
    v0237 = elt(env, 5); // false
    { popv(5); return onevalue(v0237); }

v0087:
    stack[0] = stack[-1];
    v0237 = stack[-1];
    fn = elt(env, 14); // sfto_dcontentf
    v0237 = (*qfn1(fn))(qenv(fn), v0237);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-4];
    fn = elt(env, 15); // quotf
    v0237 = (*qfn2(fn))(qenv(fn), stack[0], v0237);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-4];
    stack[-1] = v0237;
    v0237 = stack[-1];
    fn = elt(env, 16); // minusf
    v0237 = (*qfn1(fn))(qenv(fn), v0237);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-4];
    if (v0237 == nil) goto v0176;
    v0237 = stack[-1];
    fn = elt(env, 17); // negf
    v0237 = (*qfn1(fn))(qenv(fn), v0237);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-4];
    stack[-1] = v0237;
    v0237 = stack[-3];
    fn = elt(env, 18); // ofsf_anegrel
    v0237 = (*qfn1(fn))(qenv(fn), v0237);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-4];
    stack[-3] = v0237;
    goto v0176;

v0176:
    v0237 = qvalue(elt(env, 6)); // !*rlsiatadv
    if (v0237 == nil) goto v0154;
    v0212 = stack[-3];
    v0237 = elt(env, 7); // equal
    if (v0212 == v0237) goto v0152;
    v0212 = stack[-3];
    v0237 = elt(env, 8); // neq
    if (v0212 == v0237) goto v0239;
    v0212 = stack[-3];
    v0237 = elt(env, 9); // leq
    if (v0212 == v0237) goto v0119;
    v0212 = stack[-3];
    v0237 = elt(env, 10); // geq
    if (v0212 == v0237) goto v0115;
    v0212 = stack[-3];
    v0237 = elt(env, 11); // lessp
    if (v0212 == v0237) goto v0157;
    v0212 = stack[-3];
    v0237 = elt(env, 12); // greaterp
    if (v0212 == v0237) goto v0227;
    v0237 = nil;
    { popv(5); return onevalue(v0237); }

v0227:
    v0212 = stack[-1];
    v0237 = stack[-2];
    {
        popv(5);
        fn = elt(env, 19); // ofsf_simplgreaterp
        return (*qfn2(fn))(qenv(fn), v0212, v0237);
    }

v0157:
    v0212 = stack[-1];
    v0237 = stack[-2];
    {
        popv(5);
        fn = elt(env, 20); // ofsf_simpllessp
        return (*qfn2(fn))(qenv(fn), v0212, v0237);
    }

v0115:
    v0212 = stack[-1];
    v0237 = stack[-2];
    {
        popv(5);
        fn = elt(env, 21); // ofsf_simplgeq
        return (*qfn2(fn))(qenv(fn), v0212, v0237);
    }

v0119:
    v0212 = stack[-1];
    v0237 = stack[-2];
    {
        popv(5);
        fn = elt(env, 22); // ofsf_simplleq
        return (*qfn2(fn))(qenv(fn), v0212, v0237);
    }

v0239:
    v0212 = stack[-1];
    v0237 = stack[-2];
    {
        popv(5);
        fn = elt(env, 23); // ofsf_simplneq
        return (*qfn2(fn))(qenv(fn), v0212, v0237);
    }

v0152:
    v0212 = stack[-1];
    v0237 = stack[-2];
    {
        popv(5);
        fn = elt(env, 24); // ofsf_simplequal
        return (*qfn2(fn))(qenv(fn), v0212, v0237);
    }

v0154:
    v0212 = stack[-3];
    v0237 = stack[-1];
    v0213 = qvalue(elt(env, 2)); // nil
    popv(5);
    return list3(v0212, v0237, v0213);

v0084:
    v0237 = qvalue(elt(env, 3)); // t
    goto v0090;

v0093:
    v0237 = qvalue(elt(env, 2)); // nil
    { popv(5); return onevalue(v0237); }
// error exit handlers
v0238:
    popv(5);
    return nil;
}



// Code for containerml

static LispObject CC_containerml(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0162, v0163;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for containerml");
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
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0001;
    stack[-1] = v0000;
// end of prologue
    v0163 = stack[0];
    v0162 = elt(env, 1); // integer_interval
    if (!(v0163 == v0162)) goto v0083;
    v0162 = elt(env, 2); // interval
    stack[0] = v0162;
    goto v0083;

v0083:
    v0162 = elt(env, 3); // "<"
    fn = elt(env, 9); // printout
    v0162 = (*qfn1(fn))(qenv(fn), v0162);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-2];
    v0162 = stack[0];
    v0162 = Lprinc(nil, v0162);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-2];
    v0162 = stack[-1];
    v0163 = qcar(v0162);
    v0162 = elt(env, 4); // ""
    fn = elt(env, 10); // attributesml
    v0162 = (*qfn2(fn))(qenv(fn), v0163, v0162);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-2];
    v0162 = qvalue(elt(env, 5)); // t
    fn = elt(env, 11); // indent!*
    v0162 = (*qfn1(fn))(qenv(fn), v0162);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-2];
    v0162 = stack[-1];
    v0162 = qcdr(v0162);
    fn = elt(env, 12); // multi_elem
    v0162 = (*qfn1(fn))(qenv(fn), v0162);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-2];
    v0162 = qvalue(elt(env, 6)); // nil
    fn = elt(env, 11); // indent!*
    v0162 = (*qfn1(fn))(qenv(fn), v0162);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-2];
    v0162 = elt(env, 7); // "</"
    fn = elt(env, 9); // printout
    v0162 = (*qfn1(fn))(qenv(fn), v0162);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-2];
    v0162 = stack[0];
    v0162 = Lprinc(nil, v0162);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-2];
    v0162 = elt(env, 8); // ">"
    v0162 = Lprinc(nil, v0162);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    v0162 = nil;
    { popv(3); return onevalue(v0162); }
// error exit handlers
v0073:
    popv(3);
    return nil;
}



// Code for add_minus

static LispObject CC_add_minus(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0232, v0160;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for add_minus");
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
    v0232 = stack[-1];
    if (!consp(v0232)) { LispObject res = stack[-1]; popv(4); return onevalue(res); }
    v0232 = stack[-1];
    v0160 = qcar(v0232);
    v0232 = elt(env, 1); // !:rd!:
    if (v0160 == v0232) goto v0048;
    v0232 = qvalue(elt(env, 2)); // nil
    goto v0046;

v0046:
    if (!(v0232 == nil)) { LispObject res = stack[-1]; popv(4); return onevalue(res); }
    v0232 = stack[-1];
    v0160 = qcar(v0232);
    v0232 = elt(env, 1); // !:rd!:
    if (v0160 == v0232) goto v0080;
    v0232 = qvalue(elt(env, 2)); // nil
    goto v0056;

v0056:
    if (v0232 == nil) goto v0034;
    stack[-2] = elt(env, 3); // minus
    stack[0] = elt(env, 1); // !:rd!:
    v0232 = stack[-1];
    v0232 = qcdr(v0232);
    v0232 = Labsval(nil, v0232);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-3];
    v0232 = cons(stack[0], v0232);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    {
        LispObject v0241 = stack[-2];
        popv(4);
        return list2(v0241, v0232);
    }

v0034:
    v0232 = stack[-1];
    v0160 = qcar(v0232);
    v0232 = elt(env, 3); // minus
    if (v0160 == v0232) goto v0067;
    v0232 = qvalue(elt(env, 2)); // nil
    goto v0066;

v0066:
    if (!(v0232 == nil)) { LispObject res = stack[-1]; popv(4); return onevalue(res); }
    v0232 = stack[-1];
    v0160 = qcar(v0232);
    v0232 = elt(env, 3); // minus
    if (v0160 == v0232) goto v0151;
    v0232 = qvalue(elt(env, 2)); // nil
    goto v0133;

v0133:
    if (v0232 == nil) goto v0116;
    stack[0] = elt(env, 1); // !:rd!:
    v0232 = stack[-1];
    v0232 = qcdr(v0232);
    v0232 = qcar(v0232);
    v0232 = qcdr(v0232);
    v0232 = Labsval(nil, v0232);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    {
        LispObject v0242 = stack[0];
        popv(4);
        return cons(v0242, v0232);
    }

v0116:
    v0232 = stack[-1];
    v0160 = qcar(v0232);
    v0232 = elt(env, 3); // minus
    if (v0160 == v0232) { LispObject res = stack[-1]; popv(4); return onevalue(res); }
    v0232 = stack[-1];
    v0160 = qcdr(v0232);
    v0232 = (LispObject)1; // 0
    v0232 = (LispObject)lessp2(v0160, v0232);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    v0232 = v0232 ? lisp_true : nil;
    env = stack[-3];
    if (v0232 == nil) { LispObject res = stack[-1]; popv(4); return onevalue(res); }
    stack[-2] = elt(env, 3); // minus
    stack[0] = elt(env, 1); // !:rd!:
    v0232 = stack[-1];
    v0232 = qcdr(v0232);
    v0232 = Labsval(nil, v0232);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-3];
    v0232 = cons(stack[0], v0232);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    {
        LispObject v0243 = stack[-2];
        popv(4);
        return list2(v0243, v0232);
    }

v0151:
    v0232 = stack[-1];
    v0232 = qcdr(v0232);
    v0232 = qcar(v0232);
    v0160 = qcdr(v0232);
    v0232 = (LispObject)1; // 0
    v0232 = (LispObject)lessp2(v0160, v0232);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    v0232 = v0232 ? lisp_true : nil;
    env = stack[-3];
    goto v0133;

v0067:
    v0232 = stack[-1];
    v0232 = qcdr(v0232);
    v0232 = qcar(v0232);
    v0232 = (is_number(v0232) ? lisp_true : nil);
    goto v0066;

v0080:
    v0232 = stack[-1];
    v0160 = qcdr(v0232);
    v0232 = (LispObject)1; // 0
    v0232 = (LispObject)lessp2(v0160, v0232);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    v0232 = v0232 ? lisp_true : nil;
    env = stack[-3];
    goto v0056;

v0048:
    v0232 = stack[-1];
    v0160 = qcdr(v0232);
    v0232 = (LispObject)1; // 0
    v0232 = (LispObject)geq2(v0160, v0232);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    v0232 = v0232 ? lisp_true : nil;
    env = stack[-3];
    goto v0046;
// error exit handlers
v0216:
    popv(4);
    return nil;
}



// Code for insoccs

static LispObject CC_insoccs(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0100, v0101;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for insoccs");
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
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0001;
    stack[-1] = v0000;
// end of prologue
    v0100 = stack[-1];
    if (symbolp(v0100)) goto v0075;
    v0100 = stack[-1];
    fn = elt(env, 2); // subscriptedvarp
    v0100 = (*qfn1(fn))(qenv(fn), v0100);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-2];
    if (!(v0100 == nil)) goto v0075;
    v0100 = stack[-1];
    v0100 = Lconsp(nil, v0100);
    env = stack[-2];
    if (v0100 == nil) goto v0083;
    v0100 = stack[-1];
    v0100 = qcar(v0100);
    fn = elt(env, 2); // subscriptedvarp
    v0100 = (*qfn1(fn))(qenv(fn), v0100);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-2];
    if (!(v0100 == nil)) goto v0075;

v0083:
    v0100 = stack[-1];
    if (symbolp(v0100)) goto v0162;
    v0100 = stack[-1];
    fn = elt(env, 3); // constp
    v0100 = (*qfn1(fn))(qenv(fn), v0100);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-2];
    v0100 = (v0100 == nil ? lisp_true : nil);
    goto v0006;

v0006:
    if (v0100 == nil) { LispObject res = stack[0]; popv(3); return onevalue(res); }
    v0100 = stack[-1];
    v0100 = qcdr(v0100);
    stack[-1] = v0100;
    goto v0039;

v0039:
    v0100 = stack[-1];
    if (v0100 == nil) { LispObject res = stack[0]; popv(3); return onevalue(res); }
    v0100 = stack[-1];
    v0100 = qcar(v0100);
    v0101 = v0100;
    v0100 = stack[0];
    v0100 = CC_insoccs(env, v0101, v0100);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-2];
    stack[0] = v0100;
    v0100 = stack[-1];
    v0100 = qcdr(v0100);
    stack[-1] = v0100;
    goto v0039;

v0162:
    v0100 = qvalue(elt(env, 1)); // nil
    goto v0006;

v0075:
    v0101 = stack[0];
    v0100 = stack[-1];
    fn = elt(env, 4); // insertocc
    v0100 = (*qfn2(fn))(qenv(fn), v0101, v0100);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-2];
    stack[0] = v0100;
    goto v0083;
// error exit handlers
v0098:
    popv(3);
    return nil;
}



// Code for overall_factor

static LispObject CC_overall_factor(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0006, v0007;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for overall_factor");
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

v0193:
    v0006 = stack[0];
    if (v0006 == nil) goto v0011;
    stack[-2] = stack[-1];
    v0006 = stack[0];
    fn = elt(env, 3); // xval
    v0006 = (*qfn1(fn))(qenv(fn), v0006);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[-3];
    v0006 = Lmemq(nil, stack[-2], v0006);
    if (v0006 == nil) goto v0046;
    v0007 = stack[-1];
    v0006 = stack[0];
    v0006 = qcdr(v0006);
    stack[-1] = v0007;
    stack[0] = v0006;
    goto v0193;

v0046:
    v0006 = qvalue(elt(env, 2)); // nil
    { popv(4); return onevalue(v0006); }

v0011:
    v0006 = qvalue(elt(env, 1)); // t
    { popv(4); return onevalue(v0006); }
// error exit handlers
v0057:
    popv(4);
    return nil;
}



// Code for testchar1

static LispObject CC_testchar1(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0074, v0039;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for testchar1");
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
    v0074 = stack[0];
    v0074 = integerp(v0074);
    if (!(v0074 == nil)) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    v0074 = stack[0];
    v0074 = Lexplodec(nil, v0074);
    nil = C_nil;
    if (exception_pending()) goto v0130;
    env = stack[-1];
    v0074 = qcdr(v0074);
    if (v0074 == nil) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    v0039 = stack[0];
    v0074 = qvalue(elt(env, 1)); // nochar!*
    v0074 = Lmember(nil, v0039, v0074);
    if (!(v0074 == nil)) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    v0039 = stack[0];
    v0074 = qvalue(elt(env, 2)); // nochar1!*
    v0074 = Lmember(nil, v0039, v0074);
    if (!(v0074 == nil)) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    v0039 = stack[0];
    v0074 = qvalue(elt(env, 2)); // nochar1!*
    v0074 = cons(v0039, v0074);
    nil = C_nil;
    if (exception_pending()) goto v0130;
    env = stack[-1];
    qvalue(elt(env, 2)) = v0074; // nochar1!*
    { LispObject res = stack[0]; popv(2); return onevalue(res); }
// error exit handlers
v0130:
    popv(2);
    return nil;
}



setup_type const u30_setup[] =
{
    {"nconc2",                  too_few_2,      CC_nconc2,     wrong_no_2},
    {"formatfort",              CC_formatfort,  too_many_1,    wrong_no_1},
    {"locate_member",           too_few_2,      CC_locate_member,wrong_no_2},
    {"all_defined_vertex",      too_few_2,      CC_all_defined_vertex,wrong_no_2},
    {"formsetq",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_formsetq},
    {"length_multiindex",       CC_length_multiindex,too_many_1,wrong_no_1},
    {"deginvar",                too_few_2,      CC_deginvar,   wrong_no_2},
    {"dfconst",                 CC_dfconst,     too_many_1,    wrong_no_1},
    {"ofsf_xor",                too_few_2,      CC_ofsf_xor,   wrong_no_2},
    {"unify",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_unify},
    {"evload",                  CC_evload,      too_many_1,    wrong_no_1},
    {"harmonicp",               CC_harmonicp,   too_many_1,    wrong_no_1},
    {"red=hide",                CC_redMhide,    too_many_1,    wrong_no_1},
    {"reverse-num1",            too_few_2,      CC_reverseKnum1,wrong_no_2},
    {"mksf",                    CC_mksf,        too_many_1,    wrong_no_1},
    {"sfto_fsub1",              too_few_2,      CC_sfto_fsub1, wrong_no_2},
    {"sfto_updecf",             CC_sfto_updecf, too_many_1,    wrong_no_1},
    {"vunion",                  too_few_2,      CC_vunion,     wrong_no_2},
    {"formboollis",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_formboollis},
    {"width",                   too_few_2,      CC_width,      wrong_no_2},
    {"get_char_group",          CC_get_char_group,too_many_1,  wrong_no_1},
    {"cl_susiupdknowl2",        wrong_no_na,    wrong_no_nb,   (n_args *)CC_cl_susiupdknowl2},
    {"ev_sum",                  too_few_2,      CC_ev_sum,     wrong_no_2},
    {"semanticml",              CC_semanticml,  too_many_1,    wrong_no_1},
    {"exptplus",                too_few_2,      CC_exptplus,   wrong_no_2},
    {"derad",                   too_few_2,      CC_derad,      wrong_no_2},
    {"evalvars",                CC_evalvars,    too_many_1,    wrong_no_1},
    {"vdp2a",                   CC_vdp2a,       too_many_1,    wrong_no_1},
    {"gfplusn",                 too_few_2,      CC_gfplusn,    wrong_no_2},
    {"repartsq",                CC_repartsq,    too_many_1,    wrong_no_1},
    {"clogsq*",                 CC_clogsqH,     too_many_1,    wrong_no_1},
    {"assert_stat-parse",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_assert_statKparse},
    {"mv-pow->",                too_few_2,      CC_mvKpowKS,   wrong_no_2},
    {"symbol",                  CC_symbol,      too_many_1,    wrong_no_1},
    {"general-ordered-gcd-mod-p",too_few_2,     CC_generalKorderedKgcdKmodKp,wrong_no_2},
    {"chkrn*",                  CC_chkrnH,      too_many_1,    wrong_no_1},
    {"ra_l",                    CC_ra_l,        too_many_1,    wrong_no_1},
    {"ofsf_siatsubf",           too_few_2,      CC_ofsf_siatsubf,wrong_no_2},
    {"cl_simpl",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_cl_simpl},
    {"ev_revgradlexcomp",       too_few_2,      CC_ev_revgradlexcomp,wrong_no_2},
    {"matrix_rows",             CC_matrix_rows, too_many_1,    wrong_no_1},
    {"sc_getrow",               too_few_2,      CC_sc_getrow,  wrong_no_2},
    {"gparg1p",                 CC_gparg1p,     too_many_1,    wrong_no_1},
    {"indordn",                 CC_indordn,     too_many_1,    wrong_no_1},
    {"one-entryp",              too_few_2,      CC_oneKentryp, wrong_no_2},
    {"modp",                    too_few_2,      CC_modp,       wrong_no_2},
    {"poly-to-vector",          CC_polyKtoKvector,too_many_1,  wrong_no_1},
    {"formbool",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_formbool},
    {"monomgetfirstmultivar",   CC_monomgetfirstmultivar,too_many_1,wrong_no_1},
    {"ofsf_simplat1",           too_few_2,      CC_ofsf_simplat1,wrong_no_2},
    {"containerml",             too_few_2,      CC_containerml,wrong_no_2},
    {"add_minus",               CC_add_minus,   too_many_1,    wrong_no_1},
    {"insoccs",                 too_few_2,      CC_insoccs,    wrong_no_2},
    {"overall_factor",          too_few_2,      CC_overall_factor,wrong_no_2},
    {"testchar1",               CC_testchar1,   too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u30", (two_args *)"23034 6750551 4859800", 0}
};

// end of generated code
