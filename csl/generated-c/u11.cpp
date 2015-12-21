
// $destdir/u11.c        Machine generated C code

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



// Code for subs3f1

static LispObject CC_subs3f1(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0027, v0028, v0029;
    LispObject fn;
    LispObject v0017, v0018, v0002;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "subs3f1");
    va_start(aa, nargs);
    v0002 = va_arg(aa, LispObject);
    v0018 = va_arg(aa, LispObject);
    v0017 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for subs3f1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0017,v0018,v0002);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0002,v0018,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0017;
    stack[-1] = v0018;
    stack[-2] = v0002;
// end of prologue
    v0028 = qvalue(elt(env, 1)); // nil
    v0027 = (LispObject)17; // 1
    v0027 = cons(v0028, v0027);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    env = stack[-4];
    stack[-3] = v0027;
    goto v0031;

v0031:
    v0027 = stack[-2];
    if (v0027 == nil) { LispObject res = stack[-3]; popv(5); return onevalue(res); }
    v0027 = stack[-2];
    if (!consp(v0027)) goto v0032;
    v0027 = stack[-2];
    v0027 = qcar(v0027);
    v0027 = (consp(v0027) ? nil : lisp_true);
    goto v0033;

v0033:
    if (v0027 == nil) goto v0034;
    stack[0] = stack[-3];
    v0028 = stack[-2];
    v0027 = (LispObject)17; // 1
    v0027 = cons(v0028, v0027);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    env = stack[-4];
    {
        LispObject v0035 = stack[0];
        popv(5);
        fn = elt(env, 7); // addsq
        return (*qfn2(fn))(qenv(fn), v0035, v0027);
    }

v0034:
    v0027 = stack[0];
    if (v0027 == nil) goto v0036;
    v0027 = stack[-2];
    v0027 = qcar(v0027);
    v0027 = qcdr(v0027);
    if (!consp(v0027)) goto v0037;
    v0027 = stack[-2];
    v0027 = qcar(v0027);
    v0027 = qcdr(v0027);
    v0027 = qcar(v0027);
    v0027 = (consp(v0027) ? nil : lisp_true);
    goto v0038;

v0038:
    if (v0027 == nil) goto v0036;
    v0027 = stack[-2];
    v0027 = qcar(v0027);
    v0028 = ncons(v0027);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    env = stack[-4];
    v0027 = (LispObject)17; // 1
    v0027 = cons(v0028, v0027);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    env = stack[-4];
    v0029 = v0027;
    goto v0039;

v0039:
    v0027 = stack[-3];
    v0028 = v0029;
    fn = elt(env, 7); // addsq
    v0027 = (*qfn2(fn))(qenv(fn), v0027, v0028);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    env = stack[-4];
    stack[-3] = v0027;
    v0027 = stack[-2];
    v0027 = qcdr(v0027);
    stack[-2] = v0027;
    goto v0031;

v0036:
    v0027 = stack[-2];
    v0028 = qcar(v0027);
    v0027 = stack[-1];
    fn = elt(env, 8); // subs3t
    v0027 = (*qfn2(fn))(qenv(fn), v0028, v0027);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    env = stack[-4];
    v0029 = v0027;
    v0027 = stack[0];
    if (v0027 == nil) goto v0040;
    v0027 = qvalue(elt(env, 3)); // mchfg!*
    v0027 = (v0027 == nil ? lisp_true : nil);
    goto v0041;

v0041:
    if (!(v0027 == nil)) goto v0039;
    v0027 = qvalue(elt(env, 1)); // nil
    qvalue(elt(env, 3)) = v0027; // mchfg!*
    v0027 = v0029;
    v0028 = qcar(v0027);
    v0027 = stack[-2];
    if (equal(v0028, v0027)) goto v0042;
    v0027 = qvalue(elt(env, 1)); // nil
    goto v0043;

v0043:
    if (v0027 == nil) goto v0044;
    v0028 = stack[-2];
    v0027 = (LispObject)17; // 1
    v0027 = cons(v0028, v0027);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    env = stack[-4];
    v0029 = v0027;
    goto v0039;

v0044:
    v0027 = qvalue(elt(env, 4)); // !*resubs
    if (v0027 == nil) goto v0039;
    v0027 = qvalue(elt(env, 5)); // !*sub2
    if (!(v0027 == nil)) goto v0045;
    v0027 = qvalue(elt(env, 6)); // powlis1!*
    if (!(v0027 == nil)) goto v0045;

v0046:
    v0027 = v0029;
    fn = elt(env, 9); // subs3q
    v0027 = (*qfn1(fn))(qenv(fn), v0027);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    env = stack[-4];
    v0029 = v0027;
    goto v0039;

v0045:
    v0027 = v0029;
    fn = elt(env, 10); // subs2q
    v0027 = (*qfn1(fn))(qenv(fn), v0027);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    env = stack[-4];
    v0029 = v0027;
    goto v0046;

v0042:
    v0027 = v0029;
    v0028 = qcdr(v0027);
    v0027 = (LispObject)17; // 1
    v0027 = (v0028 == v0027 ? lisp_true : nil);
    goto v0043;

v0040:
    v0027 = qvalue(elt(env, 2)); // t
    goto v0041;

v0037:
    v0027 = qvalue(elt(env, 2)); // t
    goto v0038;

v0032:
    v0027 = qvalue(elt(env, 2)); // t
    goto v0033;
// error exit handlers
v0030:
    popv(5);
    return nil;
}



// Code for mkzl

static LispObject CC_mkzl(LispObject env,
                         LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0049, v0050;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mkzl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0002);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0002;
// end of prologue
    stack[-1] = nil;
    goto v0051;

v0051:
    v0050 = stack[0];
    v0049 = (LispObject)17; // 1
    if (v0050 == v0049) goto v0031;
    v0050 = (LispObject)1; // 0
    v0049 = stack[-1];
    v0049 = cons(v0050, v0049);
    nil = C_nil;
    if (exception_pending()) goto v0052;
    env = stack[-2];
    stack[-1] = v0049;
    v0049 = stack[0];
    v0049 = sub1(v0049);
    nil = C_nil;
    if (exception_pending()) goto v0052;
    env = stack[-2];
    stack[0] = v0049;
    goto v0051;

v0031:
    v0049 = stack[-1];
    {
        popv(3);
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(qenv(fn), v0049);
    }
// error exit handlers
v0052:
    popv(3);
    return nil;
}



// Code for intexprnp

static LispObject CC_intexprnp(LispObject env,
                         LispObject v0002, LispObject v0018)
{
    LispObject nil = C_nil;
    LispObject v0058, v0059, v0060, v0015;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for intexprnp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0018,v0002);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0002,v0018);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// copy arguments values to proper place
    v0059 = v0018;
    v0060 = v0002;
// end of prologue
    v0058 = qvalue(elt(env, 1)); // !*revalp
    if (v0058 == nil) goto v0006;
    v0058 = v0060;
    if (!consp(v0058)) goto v0061;
    v0058 = v0060;
    v0058 = qcar(v0058);
    if (symbolp(v0058)) goto v0062;
    v0058 = qvalue(elt(env, 2)); // nil
    { popv(1); return onevalue(v0058); }

v0062:
    v0058 = v0060;
    v0015 = qcar(v0058);
    v0058 = elt(env, 4); // intfn
    v0058 = Lflagp(nil, v0015, v0058);
    env = stack[0];
    if (v0058 == nil) goto v0036;
    v0058 = v0060;
    v0058 = qcdr(v0058);
    {
        popv(1);
        fn = elt(env, 5); // intexprlisp
        return (*qfn2(fn))(qenv(fn), v0058, v0059);
    }

v0036:
    v0058 = qvalue(elt(env, 2)); // nil
    { popv(1); return onevalue(v0058); }

v0061:
    v0058 = v0060;
    if (is_number(v0058)) goto v0063;
    v0058 = v0060;
    v0058 = Latsoc(nil, v0058, v0059);
    v0060 = v0058;
    if (v0058 == nil) goto v0064;
    v0058 = v0060;
    v0058 = qcdr(v0058);
    v0059 = elt(env, 3); // integer
    v0058 = (v0058 == v0059 ? lisp_true : nil);
    { popv(1); return onevalue(v0058); }

v0064:
    v0058 = qvalue(elt(env, 2)); // nil
    { popv(1); return onevalue(v0058); }

v0063:
    v0058 = v0060;
    v0058 = integerp(v0058);
    { popv(1); return onevalue(v0058); }

v0006:
    v0058 = qvalue(elt(env, 2)); // nil
    { popv(1); return onevalue(v0058); }
}



// Code for rat_numrn

static LispObject CC_rat_numrn(LispObject env,
                         LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0065, v0063;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rat_numrn");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0065 = v0002;
// end of prologue
    v0063 = v0065;
    v0063 = qcar(v0063);
    if (v0063 == nil) goto v0005;
    v0065 = qcar(v0065);
    return onevalue(v0065);

v0005:
    v0065 = (LispObject)1; // 0
    return onevalue(v0065);
}



// Code for poly!-abs

static LispObject CC_polyKabs(LispObject env,
                         LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0065;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for poly-abs");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0002);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0002;
// end of prologue
    v0065 = stack[0];
    fn = elt(env, 1); // poly!-minusp
    v0065 = (*qfn1(fn))(qenv(fn), v0065);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-1];
    if (v0065 == nil) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    v0065 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); // negf
        return (*qfn1(fn))(qenv(fn), v0065);
    }
// error exit handlers
v0047:
    popv(2);
    return nil;
}



// Code for sub_math

static LispObject CC_sub_math(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0073, v0074;
    LispObject fn;
    argcheck(nargs, 0, "sub_math");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sub_math");
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
    stack[-1] = nil;
    v0074 = qvalue(elt(env, 1)); // char
    v0073 = elt(env, 2); // (a p p l y)
    if (equal(v0074, v0073)) goto v0075;
    v0074 = qvalue(elt(env, 1)); // char
    v0073 = elt(env, 5); // (v e c t o r)
    if (equal(v0074, v0073)) goto v0057;
    v0073 = qvalue(elt(env, 1)); // char
    fn = elt(env, 9); // compress!*
    v0074 = (*qfn1(fn))(qenv(fn), v0073);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-2];
    v0073 = qvalue(elt(env, 8)); // rdelems!*
    v0073 = Lassoc(nil, v0074, v0073);
    stack[0] = v0073;
    if (v0073 == nil) { LispObject res = stack[-1]; popv(3); return onevalue(res); }
    v0073 = stack[0];
    v0073 = qcdr(v0073);
    v0074 = qcar(v0073);
    v0073 = nil;
    fn = elt(env, 10); // apply
    v0073 = (*qfn2(fn))(qenv(fn), v0074, v0073);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-2];
    stack[-1] = v0073;
    v0073 = qvalue(elt(env, 1)); // char
    fn = elt(env, 9); // compress!*
    v0074 = (*qfn1(fn))(qenv(fn), v0073);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-2];
    v0073 = stack[0];
    v0073 = qcdr(v0073);
    v0073 = qcdr(v0073);
    v0073 = qcar(v0073);
    if (equal(v0074, v0073)) { LispObject res = stack[-1]; popv(3); return onevalue(res); }
    v0073 = stack[0];
    v0073 = qcdr(v0073);
    v0073 = qcdr(v0073);
    v0073 = qcdr(v0073);
    v0074 = qcar(v0073);
    v0073 = (LispObject)33; // 2
    fn = elt(env, 11); // errorml
    v0073 = (*qfn2(fn))(qenv(fn), v0074, v0073);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    { LispObject res = stack[-1]; popv(3); return onevalue(res); }

v0057:
    fn = elt(env, 12); // vectorrd
    v0073 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-2];
    stack[-1] = v0073;
    v0074 = qvalue(elt(env, 1)); // char
    v0073 = elt(env, 6); // (!/ v e c t o r)
    if (equal(v0074, v0073)) { LispObject res = stack[-1]; popv(3); return onevalue(res); }
    v0074 = elt(env, 7); // "</vector>"
    v0073 = (LispObject)33; // 2
    fn = elt(env, 11); // errorml
    v0073 = (*qfn2(fn))(qenv(fn), v0074, v0073);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    { LispObject res = stack[-1]; popv(3); return onevalue(res); }

v0075:
    fn = elt(env, 13); // applyml
    v0073 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-2];
    stack[-1] = v0073;
    v0074 = qvalue(elt(env, 1)); // char
    v0073 = elt(env, 3); // (!/ a p p l y)
    if (equal(v0074, v0073)) { LispObject res = stack[-1]; popv(3); return onevalue(res); }
    v0074 = elt(env, 4); // "</apply>"
    v0073 = (LispObject)49; // 3
    fn = elt(env, 11); // errorml
    v0073 = (*qfn2(fn))(qenv(fn), v0074, v0073);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    { LispObject res = stack[-1]; popv(3); return onevalue(res); }
// error exit handlers
v0076:
    popv(3);
    return nil;
}



// Code for vevlcm

static LispObject CC_vevlcm(LispObject env,
                         LispObject v0002, LispObject v0018)
{
    LispObject nil = C_nil;
    LispObject v0081, v0082, v0058;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vevlcm");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0018,v0002);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0002,v0018);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0018;
    stack[-1] = v0002;
// end of prologue
    v0058 = nil;
    goto v0031;

v0031:
    v0081 = stack[-1];
    if (v0081 == nil) goto v0075;
    v0081 = stack[0];
    if (v0081 == nil) goto v0075;
    v0081 = stack[-1];
    v0082 = qcar(v0081);
    v0081 = stack[0];
    v0081 = qcar(v0081);
    if (((int32_t)(v0082)) > ((int32_t)(v0081))) goto v0034;
    v0081 = stack[0];
    v0081 = qcar(v0081);
    goto v0083;

v0083:
    v0082 = v0058;
    v0081 = cons(v0081, v0082);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    env = stack[-2];
    v0058 = v0081;
    v0081 = stack[-1];
    v0081 = qcdr(v0081);
    stack[-1] = v0081;
    v0081 = stack[0];
    v0081 = qcdr(v0081);
    stack[0] = v0081;
    goto v0031;

v0034:
    v0081 = stack[-1];
    v0081 = qcar(v0081);
    goto v0083;

v0075:
    v0081 = v0058;
    v0081 = Lnreverse(nil, v0081);
    env = stack[-2];
    v0058 = v0081;
    v0081 = stack[-1];
    if (v0081 == nil) goto v0084;
    v0082 = v0058;
    v0081 = stack[-1];
    v0081 = Lnconc(nil, v0082, v0081);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    v0058 = v0081;
    { popv(3); return onevalue(v0058); }

v0084:
    v0081 = stack[0];
    if (v0081 == nil) { popv(3); return onevalue(v0058); }
    v0082 = v0058;
    v0081 = stack[0];
    v0081 = Lnconc(nil, v0082, v0081);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    v0058 = v0081;
    { popv(3); return onevalue(v0058); }
// error exit handlers
v0015:
    popv(3);
    return nil;
}



// Code for vdpzero

static LispObject CC_vdpzero(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0077;
    LispObject fn;
    argcheck(nargs, 0, "vdpzero");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vdpzero");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// end of prologue
    v0077 = (LispObject)1; // 0
    {
        fn = elt(env, 1); // a2vdp
        return (*qfn1(fn))(qenv(fn), v0077);
    }
}



// Code for mksgnsq

static LispObject CC_mksgnsq(LispObject env,
                         LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0023, v0084, v0088;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mksgnsq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0002);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0084 = v0002;
// end of prologue
    v0023 = v0084;
    fn = elt(env, 1); // evenfree
    v0023 = (*qfn1(fn))(qenv(fn), v0023);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-1];
    v0084 = v0023;
    if (v0023 == nil) goto v0061;
    v0088 = v0084;
    v0023 = (LispObject)17; // 1
    if (v0088 == v0023) goto v0034;
    stack[0] = (LispObject)-15; // -1
    v0023 = (LispObject)17; // 1
    v0023 = cons(v0084, v0023);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-1];
    fn = elt(env, 2); // mk!*sq
    v0023 = (*qfn1(fn))(qenv(fn), v0023);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-1];
    v0023 = list2(stack[0], v0023);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 3); // simpexpt
        return (*qfn1(fn))(qenv(fn), v0023);
    }

v0034:
    v0084 = (LispObject)-15; // -1
    v0023 = (LispObject)17; // 1
    popv(2);
    return cons(v0084, v0023);

v0061:
    v0084 = (LispObject)17; // 1
    v0023 = (LispObject)17; // 1
    popv(2);
    return cons(v0084, v0023);
// error exit handlers
v0069:
    popv(2);
    return nil;
}



// Code for !*kp2f

static LispObject CC_Hkp2f(LispObject env,
                         LispObject v0002, LispObject v0018)
{
    LispObject nil = C_nil;
    LispObject v0024, v0033;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *kp2f");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0018,v0002);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0002,v0018);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0018;
    stack[-1] = v0002;
// end of prologue
    v0033 = stack[0];
    v0024 = (LispObject)1; // 0
    v0024 = (LispObject)greaterp2(v0033, v0024);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    v0024 = v0024 ? lisp_true : nil;
    env = stack[-2];
    if (v0024 == nil) goto v0080;
    v0033 = stack[-1];
    v0024 = stack[0];
    fn = elt(env, 1); // mksq
    v0024 = (*qfn2(fn))(qenv(fn), v0033, v0024);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    v0024 = qcar(v0024);
    { popv(3); return onevalue(v0024); }

v0080:
    v0024 = (LispObject)17; // 1
    { popv(3); return onevalue(v0024); }
// error exit handlers
v0049:
    popv(3);
    return nil;
}



// Code for assert_typesyntaxp

static LispObject CC_assert_typesyntaxp(LispObject env,
                         LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0065, v0063;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for assert_typesyntaxp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0063 = v0002;
// end of prologue
    v0065 = qvalue(elt(env, 1)); // !*assert
    if (v0065 == nil) goto v0061;
    v0065 = v0063;
    {
        fn = elt(env, 2); // assert_dyntypep
        return (*qfn1(fn))(qenv(fn), v0065);
    }

v0061:
    v0065 = v0063;
        return Lsymbolp(nil, v0065);
}



// Code for simptimes

static LispObject CC_simptimes(LispObject env,
                         LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0095, v0076;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for simptimes");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0002);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0002;
// end of prologue
    stack[-2] = nil;
    v0095 = stack[-1];
    if (v0095 == nil) goto v0048;
    v0076 = qvalue(elt(env, 1)); // tstack!*
    v0095 = (LispObject)1; // 0
    if (v0076 == v0095) goto v0096;
    v0095 = qvalue(elt(env, 2)); // t
    goto v0033;

v0033:
    if (!(v0095 == nil)) goto v0097;
    v0095 = qvalue(elt(env, 3)); // mul!*
    stack[-2] = v0095;
    v0095 = qvalue(elt(env, 4)); // nil
    qvalue(elt(env, 3)) = v0095; // mul!*
    goto v0097;

v0097:
    v0095 = qvalue(elt(env, 1)); // tstack!*
    v0095 = add1(v0095);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-3];
    qvalue(elt(env, 1)) = v0095; // tstack!*
    v0095 = stack[-1];
    fn = elt(env, 6); // simpcar
    v0095 = (*qfn1(fn))(qenv(fn), v0095);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-3];
    stack[0] = v0095;
    goto v0075;

v0075:
    v0095 = stack[-1];
    v0095 = qcdr(v0095);
    stack[-1] = v0095;
    v0095 = stack[0];
    v0095 = qcar(v0095);
    if (v0095 == nil) goto v0061;
    v0095 = stack[-1];
    if (v0095 == nil) goto v0031;
    v0095 = stack[-1];
    fn = elt(env, 6); // simpcar
    v0095 = (*qfn1(fn))(qenv(fn), v0095);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-3];
    fn = elt(env, 7); // multsq
    v0095 = (*qfn2(fn))(qenv(fn), stack[0], v0095);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-3];
    stack[0] = v0095;
    goto v0075;

v0031:
    v0095 = qvalue(elt(env, 3)); // mul!*
    if (v0095 == nil) goto v0081;
    v0076 = qvalue(elt(env, 1)); // tstack!*
    v0095 = (LispObject)17; // 1
    v0095 = (LispObject)greaterp2(v0076, v0095);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    v0095 = v0095 ? lisp_true : nil;
    env = stack[-3];
    goto v0036;

v0036:
    if (!(v0095 == nil)) goto v0061;
    v0095 = qvalue(elt(env, 3)); // mul!*
    v0076 = qcar(v0095);
    v0095 = stack[0];
    v0095 = Lapply1(nil, v0076, v0095);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-3];
    stack[0] = v0095;
    v0095 = qvalue(elt(env, 4)); // nil
    v0095 = ncons(v0095);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-3];
    qvalue(elt(env, 5)) = v0095; // alglist!*
    v0095 = qvalue(elt(env, 3)); // mul!*
    v0095 = qcdr(v0095);
    qvalue(elt(env, 3)) = v0095; // mul!*
    goto v0031;

v0061:
    v0095 = qvalue(elt(env, 1)); // tstack!*
    v0095 = sub1(v0095);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-3];
    qvalue(elt(env, 1)) = v0095; // tstack!*
    v0076 = qvalue(elt(env, 1)); // tstack!*
    v0095 = (LispObject)1; // 0
    if (!(v0076 == v0095)) { LispObject res = stack[0]; popv(4); return onevalue(res); }
    v0095 = stack[-2];
    qvalue(elt(env, 3)) = v0095; // mul!*
    { LispObject res = stack[0]; popv(4); return onevalue(res); }

v0081:
    v0095 = qvalue(elt(env, 2)); // t
    goto v0036;

v0096:
    v0095 = qvalue(elt(env, 3)); // mul!*
    v0095 = (v0095 == nil ? lisp_true : nil);
    goto v0033;

v0048:
    v0076 = (LispObject)17; // 1
    v0095 = (LispObject)17; // 1
    popv(4);
    return cons(v0076, v0095);
// error exit handlers
v0098:
    popv(4);
    return nil;
}



// Code for red!-ratios1

static LispObject CC_redKratios1(LispObject env,
                         LispObject v0002, LispObject v0018)
{
    LispObject nil = C_nil;
    LispObject v0085, v0071, v0020, v0021;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for red-ratios1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0018,v0002);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0002,v0018);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0018;
    stack[-1] = v0002;
// end of prologue

v0101:
    v0085 = stack[-1];
    if (v0085 == nil) goto v0006;
    v0085 = stack[-1];
    v0021 = qcdr(v0085);
    v0085 = stack[0];
    v0020 = qcdr(v0085);
    v0085 = stack[-1];
    v0071 = qcar(v0085);
    v0085 = stack[0];
    v0085 = qcar(v0085);
    fn = elt(env, 2); // red!-ratios2
    v0085 = (*qfnn(fn))(qenv(fn), 4, v0021, v0020, v0071, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-2];
    if (!(v0085 == nil)) { popv(3); return onevalue(v0085); }
    v0085 = stack[-1];
    v0071 = qcdr(v0085);
    v0085 = stack[0];
    v0085 = qcdr(v0085);
    stack[-1] = v0071;
    stack[0] = v0085;
    goto v0101;

v0006:
    v0085 = qvalue(elt(env, 1)); // nil
    { popv(3); return onevalue(v0085); }
// error exit handlers
v0102:
    popv(3);
    return nil;
}



// Code for pdif

static LispObject CC_pdif(LispObject env,
                         LispObject v0002, LispObject v0018)
{
    LispObject nil = C_nil;
    LispObject v0103, v0065;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pdif");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0018,v0002);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0002,v0018);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0103 = v0018;
    v0065 = v0002;
// end of prologue
    stack[0] = v0065;
    fn = elt(env, 1); // pneg
    v0103 = (*qfn1(fn))(qenv(fn), v0103);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-1];
    {
        LispObject v0048 = stack[0];
        popv(2);
        fn = elt(env, 2); // psum
        return (*qfn2(fn))(qenv(fn), v0048, v0103);
    }
// error exit handlers
v0047:
    popv(2);
    return nil;
}



// Code for artimes!:

static LispObject CC_artimesT(LispObject env,
                         LispObject v0002, LispObject v0018)
{
    LispObject nil = C_nil;
    LispObject v0034, v0024, v0033;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for artimes:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0018,v0002);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0002,v0018);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    v0024 = v0018;
    v0033 = v0002;
// end of prologue
    stack[-2] = qvalue(elt(env, 1)); // dmode!*
    qvalue(elt(env, 1)) = nil; // dmode!*
    stack[-1] = qvalue(elt(env, 2)); // !*exp
    qvalue(elt(env, 2)) = nil; // !*exp
    v0034 = qvalue(elt(env, 3)); // t
    qvalue(elt(env, 2)) = v0034; // !*exp
    stack[0] = elt(env, 4); // !:ar!:
    v0034 = v0033;
    v0034 = qcdr(v0034);
    v0024 = qcdr(v0024);
    fn = elt(env, 5); // multf
    v0034 = (*qfn2(fn))(qenv(fn), v0034, v0024);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-3];
    fn = elt(env, 6); // reducepowers
    v0034 = (*qfn1(fn))(qenv(fn), v0034);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-3];
    v0034 = cons(stack[0], v0034);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-3];
    qvalue(elt(env, 2)) = stack[-1]; // !*exp
    qvalue(elt(env, 1)) = stack[-2]; // dmode!*
    { popv(4); return onevalue(v0034); }
// error exit handlers
v0050:
    env = stack[-3];
    qvalue(elt(env, 2)) = stack[-1]; // !*exp
    qvalue(elt(env, 1)) = stack[-2]; // dmode!*
    popv(4);
    return nil;
}



// Code for qqe_arg!-check!-b

static LispObject CC_qqe_argKcheckKb(LispObject env,
                         LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0070;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qqe_arg-check-b");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0002);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0002;
// end of prologue
    v0070 = stack[0];
    fn = elt(env, 3); // qqe_id!-nyt!-branchb
    v0070 = (*qfn1(fn))(qenv(fn), v0070);
    nil = C_nil;
    if (exception_pending()) goto v0062;
    env = stack[-1];
    if (v0070 == nil) goto v0097;
    v0070 = stack[0];
    if (!consp(v0070)) goto v0047;
    v0070 = qvalue(elt(env, 1)); // nil
    goto v0063;

v0063:
    if (v0070 == nil) goto v0103;
    v0070 = stack[0];
    fn = elt(env, 4); // qqe_qtidp
    v0070 = (*qfn1(fn))(qenv(fn), v0070);
    nil = C_nil;
    if (exception_pending()) goto v0062;
    env = stack[-1];
    if (v0070 == nil) goto v0024;
    v0070 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0070); }

v0024:
    v0070 = stack[0];
    fn = elt(env, 5); // qqe_nytidp
    v0070 = (*qfn1(fn))(qenv(fn), v0070);
    nil = C_nil;
    if (exception_pending()) goto v0062;
    env = stack[-1];
    if (v0070 == nil) goto v0100;
    v0070 = stack[0];
    fn = elt(env, 6); // qqe_btid
    v0070 = (*qfn1(fn))(qenv(fn), v0070);
    nil = C_nil;
    if (exception_pending()) goto v0062;
    env = stack[-1];
    v0070 = stack[0];
    fn = elt(env, 7); // qqe_add2rollbackids
    v0070 = (*qfn1(fn))(qenv(fn), v0070);
    nil = C_nil;
    if (exception_pending()) goto v0062;
    env = stack[-1];
    v0070 = qvalue(elt(env, 2)); // t
    { popv(2); return onevalue(v0070); }

v0100:
    v0070 = qvalue(elt(env, 2)); // t
    { popv(2); return onevalue(v0070); }

v0103:
    v0070 = stack[0];
    if (!consp(v0070)) goto v0023;
    v0070 = stack[0];
    fn = elt(env, 8); // qqe_arg!-check
    v0070 = (*qfn1(fn))(qenv(fn), v0070);
    nil = C_nil;
    if (exception_pending()) goto v0062;
    env = stack[-1];
    v0070 = qvalue(elt(env, 2)); // t
    { popv(2); return onevalue(v0070); }

v0023:
    v0070 = qvalue(elt(env, 2)); // t
    { popv(2); return onevalue(v0070); }

v0047:
    v0070 = stack[0];
    v0070 = (is_number(v0070) ? lisp_true : nil);
    v0070 = (v0070 == nil ? lisp_true : nil);
    goto v0063;

v0097:
    v0070 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0070); }
// error exit handlers
v0062:
    popv(2);
    return nil;
}



// Code for rl_susitf

static LispObject CC_rl_susitf(LispObject env,
                         LispObject v0002, LispObject v0018)
{
    LispObject nil = C_nil;
    LispObject v0026, v0104;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rl_susitf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0018,v0002);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0002,v0018);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0026 = v0018;
    v0104 = v0002;
// end of prologue
    stack[0] = qvalue(elt(env, 1)); // rl_susitf!*
    v0026 = list2(v0104, v0026);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-1];
    {
        LispObject v0089 = stack[0];
        popv(2);
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(qenv(fn), v0089, v0026);
    }
// error exit handlers
v0083:
    popv(2);
    return nil;
}



// Code for sfto_mvartest

static LispObject CC_sfto_mvartest(LispObject env,
                         LispObject v0002, LispObject v0018)
{
    LispObject nil = C_nil;
    LispObject v0050, v0105, v0072;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sfto_mvartest");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0105 = v0018;
    v0072 = v0002;
// end of prologue
    v0050 = v0072;
    if (!consp(v0050)) goto v0061;
    v0050 = v0072;
    v0050 = qcar(v0050);
    v0050 = (consp(v0050) ? nil : lisp_true);
    goto v0031;

v0031:
    if (v0050 == nil) goto v0026;
    v0050 = qvalue(elt(env, 2)); // nil
    return onevalue(v0050);

v0026:
    v0050 = v0072;
    v0050 = qcar(v0050);
    v0050 = qcar(v0050);
    v0050 = qcar(v0050);
    v0050 = (v0050 == v0105 ? lisp_true : nil);
    return onevalue(v0050);

v0061:
    v0050 = qvalue(elt(env, 1)); // t
    goto v0031;
}



// Code for powers1

static LispObject CC_powers1(LispObject env,
                         LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0107, v0083;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for powers1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0002);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0107 = v0002;
// end of prologue
    stack[0] = v0107;
    v0083 = v0107;
    v0107 = qvalue(elt(env, 1)); // nil
    fn = elt(env, 2); // powers3
    v0083 = (*qfn2(fn))(qenv(fn), v0083, v0107);
    nil = C_nil;
    if (exception_pending()) goto v0087;
    env = stack[-1];
    v0107 = qvalue(elt(env, 1)); // nil
    {
        LispObject v0080 = stack[0];
        popv(2);
        fn = elt(env, 3); // powers2
        return (*qfnn(fn))(qenv(fn), 3, v0080, v0083, v0107);
    }
// error exit handlers
v0087:
    popv(2);
    return nil;
}



// Code for terpri!*

static LispObject CC_terpriH(LispObject env,
                         LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0059, v0060, v0015;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for terpri*");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0002);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0002;
// end of prologue
    v0059 = qvalue(elt(env, 1)); // outputhandler!*
    if (v0059 == nil) goto v0061;
    v0060 = qvalue(elt(env, 1)); // outputhandler!*
    v0015 = elt(env, 2); // terpri
    v0059 = stack[0];
        popv(3);
        return Lapply2(nil, 3, v0060, v0015, v0059);

v0061:
    v0059 = qvalue(elt(env, 3)); // testing!-width!*
    if (v0059 == nil) goto v0087;
    v0059 = qvalue(elt(env, 4)); // t
    qvalue(elt(env, 5)) = v0059; // overflowed!*
    { popv(3); return onevalue(v0059); }

v0087:
    v0059 = qvalue(elt(env, 6)); // !*fort
    if (v0059 == nil) goto v0024;
    v0059 = stack[0];
    {
        popv(3);
        fn = elt(env, 15); // fterpri
        return (*qfn1(fn))(qenv(fn), v0059);
    }

v0024:
    v0059 = qvalue(elt(env, 7)); // !*nat
    if (v0059 == nil) goto v0075;
    v0059 = qvalue(elt(env, 8)); // pline!*
    if (v0059 == nil) goto v0075;
    v0059 = qvalue(elt(env, 8)); // pline!*
    v0059 = Lreverse(nil, v0059);
    nil = C_nil;
    if (exception_pending()) goto v0109;
    env = stack[-2];
    qvalue(elt(env, 8)) = v0059; // pline!*
    v0059 = qvalue(elt(env, 9)); // ymax!*
    stack[-1] = v0059;
    goto v0086;

v0086:
    v0060 = stack[-1];
    v0059 = qvalue(elt(env, 10)); // ymin!*
    v0059 = difference2(v0060, v0059);
    nil = C_nil;
    if (exception_pending()) goto v0109;
    env = stack[-2];
    v0059 = Lminusp(nil, v0059);
    env = stack[-2];
    if (v0059 == nil) goto v0038;
    v0059 = qvalue(elt(env, 11)); // nil
    qvalue(elt(env, 8)) = v0059; // pline!*
    goto v0075;

v0075:
    v0059 = stack[0];
    if (v0059 == nil) goto v0110;
    v0059 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0109;
    env = stack[-2];
    goto v0110;

v0110:
    v0059 = qvalue(elt(env, 12)); // orig!*
    qvalue(elt(env, 13)) = v0059; // posn!*
    v0059 = (LispObject)1; // 0
    qvalue(elt(env, 10)) = v0059; // ymin!*
    qvalue(elt(env, 9)) = v0059; // ymax!*
    qvalue(elt(env, 14)) = v0059; // ycoord!*
    v0059 = nil;
    { popv(3); return onevalue(v0059); }

v0038:
    v0060 = qvalue(elt(env, 8)); // pline!*
    v0059 = stack[-1];
    fn = elt(env, 16); // scprint
    v0059 = (*qfn2(fn))(qenv(fn), v0060, v0059);
    nil = C_nil;
    if (exception_pending()) goto v0109;
    env = stack[-2];
    v0059 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0109;
    env = stack[-2];
    v0059 = stack[-1];
    v0059 = sub1(v0059);
    nil = C_nil;
    if (exception_pending()) goto v0109;
    env = stack[-2];
    stack[-1] = v0059;
    goto v0086;
// error exit handlers
v0109:
    popv(3);
    return nil;
}



// Code for rd!:minus

static LispObject CC_rdTminus(LispObject env,
                         LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0089, v0087;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rd:minus");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0002);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0087 = v0002;
// end of prologue
    v0089 = v0087;
    v0089 = qcdr(v0089);
    if (!consp(v0089)) goto v0061;
    v0089 = v0087;
    {
        popv(1);
        fn = elt(env, 2); // minus!:
        return (*qfn1(fn))(qenv(fn), v0089);
    }

v0061:
    stack[0] = elt(env, 1); // !:rd!:
    v0089 = v0087;
    v0089 = qcdr(v0089);
    fn = elt(env, 3); // safe!-fp!-minus
    v0089 = (*qfn1(fn))(qenv(fn), v0089);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    {
        LispObject v0034 = stack[0];
        popv(1);
        return cons(v0034, v0089);
    }
// error exit handlers
v0099:
    popv(1);
    return nil;
}



// Code for spquotematrix

static LispObject CC_spquotematrix(LispObject env,
                         LispObject v0002)
{
    LispObject v0077;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for spquotematrix");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0077 = v0002;
// end of prologue
    v0077 = elt(env, 1); // sparse
    return onevalue(v0077);
}



// Code for wedget2

static LispObject CC_wedget2(LispObject env,
                         LispObject v0002, LispObject v0018)
{
    LispObject nil = C_nil;
    LispObject v0090, v0091, v0046;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for wedget2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0018,v0002);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0002,v0018);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0018;
    stack[-1] = v0002;
// end of prologue
    v0090 = stack[-1];
    v0091 = qcar(v0090);
    v0090 = (LispObject)17; // 1
    if (v0091 == v0090) goto v0025;
    v0090 = stack[0];
    v0090 = qcar(v0090);
    v0091 = qcar(v0090);
    v0090 = (LispObject)17; // 1
    if (v0091 == v0090) goto v0113;
    v0090 = stack[-1];
    v0046 = qcar(v0090);
    v0090 = stack[0];
    v0091 = qcar(v0090);
    v0090 = qvalue(elt(env, 1)); // nil
    fn = elt(env, 2); // wedgek2
    stack[-2] = (*qfnn(fn))(qenv(fn), 3, v0046, v0091, v0090);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-3];
    v0090 = stack[-1];
    v0091 = qcdr(v0090);
    v0090 = stack[0];
    v0090 = qcdr(v0090);
    fn = elt(env, 3); // multsq
    v0090 = (*qfn2(fn))(qenv(fn), v0091, v0090);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-3];
    {
        LispObject v0114 = stack[-2];
        popv(4);
        fn = elt(env, 4); // multpfsq
        return (*qfn2(fn))(qenv(fn), v0114, v0090);
    }

v0113:
    v0090 = stack[-1];
    v0090 = qcar(v0090);
    stack[-2] = ncons(v0090);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-3];
    v0090 = stack[-1];
    v0091 = qcdr(v0090);
    v0090 = stack[0];
    v0090 = qcdr(v0090);
    fn = elt(env, 3); // multsq
    v0090 = (*qfn2(fn))(qenv(fn), v0091, v0090);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-3];
    v0090 = cons(stack[-2], v0090);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    popv(4);
    return ncons(v0090);

v0025:
    v0090 = stack[0];
    stack[-2] = qcar(v0090);
    v0090 = stack[-1];
    v0091 = qcdr(v0090);
    v0090 = stack[0];
    v0090 = qcdr(v0090);
    fn = elt(env, 3); // multsq
    v0090 = (*qfn2(fn))(qenv(fn), v0091, v0090);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-3];
    v0090 = cons(stack[-2], v0090);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    popv(4);
    return ncons(v0090);
// error exit handlers
v0043:
    popv(4);
    return nil;
}



// Code for gfrsq

static LispObject CC_gfrsq(LispObject env,
                         LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0051, v0106;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gfrsq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0051 = v0002;
// end of prologue
    v0106 = v0051;
    {
        fn = elt(env, 1); // gfdot
        return (*qfn2(fn))(qenv(fn), v0106, v0051);
    }
}



// Code for fortranop

static LispObject CC_fortranop(LispObject env,
                         LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0063, v0047, v0048;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for fortranop");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0002);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
// copy arguments values to proper place
    v0048 = v0002;
// end of prologue
    v0047 = v0048;
    v0063 = elt(env, 1); // !*fortranop!*
    v0063 = get(v0047, v0063);
    if (v0063 == nil) return onevalue(v0048);
    else return onevalue(v0063);
}



// Code for deletemult!*

static LispObject CC_deletemultH(LispObject env,
                         LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0088, v0070, v0069;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for deletemult*");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0002);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0002;
// end of prologue
    v0088 = stack[0];
    if (v0088 == nil) { LispObject res = stack[0]; popv(4); return onevalue(res); }
    v0088 = stack[0];
    v0088 = qcar(v0088);
    v0088 = ncons(v0088);
    nil = C_nil;
    if (exception_pending()) goto v0037;
    env = stack[-3];
    stack[-2] = v0088;
    v0088 = stack[0];
    v0088 = qcdr(v0088);
    stack[0] = v0088;
    v0088 = stack[0];
    stack[-1] = v0088;
    goto v0104;

v0104:
    v0088 = stack[-1];
    if (v0088 == nil) { LispObject res = stack[-2]; popv(4); return onevalue(res); }
    v0088 = stack[-1];
    v0088 = qcar(v0088);
    v0069 = v0088;
    v0070 = v0069;
    v0088 = stack[-2];
    v0088 = Lmember(nil, v0070, v0088);
    if (!(v0088 == nil)) goto v0049;
    stack[0] = stack[-2];
    v0088 = v0069;
    v0088 = ncons(v0088);
    nil = C_nil;
    if (exception_pending()) goto v0037;
    env = stack[-3];
    v0088 = Lnconc(nil, stack[0], v0088);
    nil = C_nil;
    if (exception_pending()) goto v0037;
    env = stack[-3];
    goto v0049;

v0049:
    v0088 = stack[-1];
    v0088 = qcdr(v0088);
    stack[-1] = v0088;
    goto v0104;
// error exit handlers
v0037:
    popv(4);
    return nil;
}



// Code for rnconc

static LispObject CC_rnconc(LispObject env,
                         LispObject v0002, LispObject v0018)
{
    LispObject nil = C_nil;
    LispObject v0070, v0069;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rnconc");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0018,v0002);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0002,v0018);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0018;
    stack[-1] = v0002;
// end of prologue
    v0070 = stack[-1];
    if (v0070 == nil) { LispObject res = stack[0]; popv(3); return onevalue(res); }
    v0070 = qvalue(elt(env, 1)); // !*ncmp
    if (v0070 == nil) goto v0033;
    v0070 = stack[-1];
    fn = elt(env, 3); // noncomfp1
    v0070 = (*qfn1(fn))(qenv(fn), v0070);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-2];
    if (v0070 == nil) goto v0033;
    v0070 = stack[0];
    fn = elt(env, 3); // noncomfp1
    v0070 = (*qfn1(fn))(qenv(fn), v0070);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-2];
    if (v0070 == nil) goto v0033;
    v0069 = stack[-1];
    v0070 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); // addf
        return (*qfn2(fn))(qenv(fn), v0069, v0070);
    }

v0033:
    v0070 = stack[-1];
    v0069 = v0070;
    goto v0057;

v0057:
    v0070 = v0069;
    v0070 = qcdr(v0070);
    if (v0070 == nil) goto v0115;
    v0070 = v0069;
    v0070 = qcdr(v0070);
    v0069 = v0070;
    goto v0057;

v0115:
    v0070 = stack[0];
    v0070 = Lrplacd(nil, v0069, v0070);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    { LispObject res = stack[-1]; popv(3); return onevalue(res); }
// error exit handlers
v0038:
    popv(3);
    return nil;
}



// Code for aminusp!:

static LispObject CC_aminuspT(LispObject env,
                         LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0037, v0078;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for aminusp:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0002);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0002;
// end of prologue
    stack[-2] = nil;
    v0037 = qvalue(elt(env, 1)); // !*modular
    if (v0037 == nil) goto v0083;
    v0078 = elt(env, 2); // modular
    v0037 = qvalue(elt(env, 3)); // nil
    fn = elt(env, 7); // setdmode
    v0037 = (*qfn2(fn))(qenv(fn), v0078, v0037);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-3];
    stack[-2] = v0037;
    goto v0083;

v0083:
    stack[0] = elt(env, 4); // aminusp!:1
    v0037 = stack[-1];
    v0037 = Lmkquote(nil, v0037);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-3];
    v0037 = list2(stack[0], v0037);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-3];
    fn = elt(env, 8); // errorset2
    v0037 = (*qfn1(fn))(qenv(fn), v0037);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-3];
    stack[0] = v0037;
    v0037 = stack[-2];
    if (v0037 == nil) goto v0117;
    v0078 = elt(env, 2); // modular
    v0037 = qvalue(elt(env, 5)); // t
    fn = elt(env, 7); // setdmode
    v0037 = (*qfn2(fn))(qenv(fn), v0078, v0037);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-3];
    goto v0117;

v0117:
    v0037 = stack[0];
    fn = elt(env, 9); // errorp
    v0037 = (*qfn1(fn))(qenv(fn), v0037);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-3];
    if (v0037 == nil) goto v0069;
    v0078 = stack[-1];
    v0037 = elt(env, 6); // "arithmetic expression"
    fn = elt(env, 10); // typerr
    v0037 = (*qfn2(fn))(qenv(fn), v0078, v0037);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    v0037 = nil;
    { popv(4); return onevalue(v0037); }

v0069:
    v0037 = stack[0];
    v0037 = qcar(v0037);
    { popv(4); return onevalue(v0037); }
// error exit handlers
v0108:
    popv(4);
    return nil;
}



// Code for pv_times3

static LispObject CC_pv_times3(LispObject env,
                         LispObject v0002, LispObject v0018)
{
    LispObject nil = C_nil;
    LispObject v0032, v0117;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pv_times3");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0018,v0002);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0002,v0018);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0018;
    stack[-1] = v0002;
// end of prologue
    v0032 = stack[-1];
    v0117 = qcar(v0032);
    v0032 = stack[0];
    v0032 = qcar(v0032);
    stack[-2] = times2(v0117, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0072;
    env = stack[-3];
    v0032 = stack[-1];
    v0117 = qcdr(v0032);
    v0032 = stack[0];
    v0032 = qcdr(v0032);
    fn = elt(env, 1); // pappend
    v0032 = (*qfn2(fn))(qenv(fn), v0117, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0072;
    {
        LispObject v0052 = stack[-2];
        popv(4);
        return cons(v0052, v0032);
    }
// error exit handlers
v0072:
    popv(4);
    return nil;
}



// Code for freeof

static LispObject CC_freeof(LispObject env,
                         LispObject v0002, LispObject v0018)
{
    LispObject nil = C_nil;
    LispObject v0117, v0049, v0050;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for freeof");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0018,v0002);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0002,v0018);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0018;
    stack[-1] = v0002;
// end of prologue
    v0049 = stack[0];
    v0117 = stack[-1];
    fn = elt(env, 2); // smember
    v0117 = (*qfn2(fn))(qenv(fn), v0049, v0117);
    nil = C_nil;
    if (exception_pending()) goto v0052;
    env = stack[-2];
    if (!(v0117 == nil)) goto v0005;
    v0049 = stack[0];
    v0117 = stack[-1];
    v0050 = qvalue(elt(env, 1)); // depl!*
    v0117 = Lassoc(nil, v0117, v0050);
    v0117 = Lmember(nil, v0049, v0117);
    goto v0005;

v0005:
    v0117 = (v0117 == nil ? lisp_true : nil);
    { popv(3); return onevalue(v0117); }
// error exit handlers
v0052:
    popv(3);
    return nil;
}



// Code for qqe_ofsf_varlterm

static LispObject CC_qqe_ofsf_varlterm(LispObject env,
                         LispObject v0002, LispObject v0018)
{
    LispObject nil = C_nil;
    LispObject v0110, v0053, v0054, v0036;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qqe_ofsf_varlterm");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0018,v0002);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0002,v0018);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0054 = v0018;
    v0036 = v0002;
// end of prologue
    v0110 = v0036;
    if (!consp(v0110)) goto v0106;
    v0110 = qvalue(elt(env, 1)); // nil
    goto v0051;

v0051:
    if (v0110 == nil) goto v0031;
    v0110 = v0036;
    v0053 = v0054;
    fn = elt(env, 3); // lto_insertq
    v0110 = (*qfn2(fn))(qenv(fn), v0110, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    v0054 = v0110;
    { popv(2); return onevalue(v0054); }

v0031:
    v0110 = v0036;
    if (!consp(v0110)) { popv(2); return onevalue(v0054); }
    v0110 = v0036;
    v0110 = qcdr(v0110);
    stack[0] = v0110;
    goto v0102;

v0102:
    v0110 = stack[0];
    if (v0110 == nil) { popv(2); return onevalue(v0054); }
    v0110 = stack[0];
    v0110 = qcar(v0110);
    v0053 = v0054;
    v0110 = CC_qqe_ofsf_varlterm(env, v0110, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-1];
    v0054 = v0110;
    v0110 = stack[0];
    v0110 = qcdr(v0110);
    stack[0] = v0110;
    goto v0102;

v0106:
    v0110 = v0036;
    if (symbolp(v0110)) goto v0089;
    v0110 = qvalue(elt(env, 1)); // nil
    goto v0051;

v0089:
    v0053 = v0036;
    v0110 = elt(env, 2); // qepsilon
    v0110 = (v0053 == v0110 ? lisp_true : nil);
    v0110 = (v0110 == nil ? lisp_true : nil);
    goto v0051;
// error exit handlers
v0082:
    popv(2);
    return nil;
}



// Code for rl_smcpknowl

static LispObject CC_rl_smcpknowl(LispObject env,
                         LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0106;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rl_smcpknowl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0002);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0106 = v0002;
// end of prologue
    stack[0] = qvalue(elt(env, 1)); // rl_smcpknowl!*
    v0106 = ncons(v0106);
    nil = C_nil;
    if (exception_pending()) goto v0065;
    env = stack[-1];
    {
        LispObject v0063 = stack[0];
        popv(2);
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(qenv(fn), v0063, v0106);
    }
// error exit handlers
v0065:
    popv(2);
    return nil;
}



// Code for ibalp_hassimple

static LispObject CC_ibalp_hassimple(LispObject env,
                         LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0100, v0085;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_hassimple");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0002);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    v0100 = v0002;
// end of prologue
    stack[-1] = nil;
    stack[0] = v0100;
    goto v0061;

v0061:
    v0100 = stack[0];
    if (v0100 == nil) { LispObject res = stack[-1]; popv(3); return onevalue(res); }
    v0100 = stack[-1];
    if (!(v0100 == nil)) { LispObject res = stack[-1]; popv(3); return onevalue(res); }
    v0100 = stack[0];
    v0100 = qcar(v0100);
    v0085 = qcar(v0100);
    v0100 = stack[0];
    v0100 = qcar(v0100);
    v0100 = qcdr(v0100);
    v0100 = qcar(v0100);
    fn = elt(env, 2); // ibalp_commonlenisone
    v0100 = (*qfn2(fn))(qenv(fn), v0085, v0100);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    env = stack[-2];
    if (v0100 == nil) goto v0107;
    v0100 = stack[0];
    v0100 = qcar(v0100);
    stack[-1] = v0100;
    goto v0107;

v0107:
    v0100 = stack[0];
    v0100 = qcdr(v0100);
    stack[0] = v0100;
    goto v0061;
// error exit handlers
v0021:
    popv(3);
    return nil;
}



// Code for unbind

static LispObject CC_unbind(LispObject env,
                         LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0047, v0048, v0025;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for unbind");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0048 = v0002;
// end of prologue
    v0047 = v0048;
    v0025 = elt(env, 1); // binding
    if (!symbolp(v0048)) v0048 = nil;
    else { v0048 = qfastgets(v0048);
           if (v0048 != nil) { v0048 = elt(v0048, 13); // binding
#ifdef RECORD_GET
             if (v0048 != SPID_NOPROP)
                record_get(elt(fastget_names, 13), 1);
             else record_get(elt(fastget_names, 13), 0),
                v0048 = nil; }
           else record_get(elt(fastget_names, 13), 0); }
#else
             if (v0048 == SPID_NOPROP) v0048 = nil; }}
#endif
    v0048 = qcdr(v0048);
        return Lputprop(nil, 3, v0047, v0025, v0048);
}



// Code for groebcpcompless!?

static LispObject CC_groebcpcomplessW(LispObject env,
                         LispObject v0002, LispObject v0018)
{
    LispObject nil = C_nil;
    LispObject v0073, v0074, v0123, v0095;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for groebcpcompless?");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0018,v0002);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0002,v0018);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0018;
    stack[-1] = v0002;
// end of prologue
    v0073 = qvalue(elt(env, 1)); // !*gsugar
    if (v0073 == nil) goto v0124;
    v0073 = stack[-1];
    v0073 = qcdr(v0073);
    v0073 = qcdr(v0073);
    v0073 = qcdr(v0073);
    v0074 = qcar(v0073);
    v0073 = stack[0];
    v0073 = qcdr(v0073);
    v0073 = qcdr(v0073);
    v0073 = qcdr(v0073);
    v0073 = qcar(v0073);
    stack[-2] = difference2(v0074, v0073);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    env = stack[-3];
    v0073 = stack[-1];
    v0074 = qcar(v0073);
    v0073 = stack[0];
    v0073 = qcar(v0073);
    fn = elt(env, 3); // vevcomp
    v0073 = (*qfn2(fn))(qenv(fn), v0074, v0073);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    env = stack[-3];
    v0095 = stack[-2];
    v0123 = v0073;
    v0074 = v0095;
    v0073 = (LispObject)1; // 0
    if (v0074 == v0073) goto v0062;
    v0074 = v0095;
    v0073 = (LispObject)1; // 0
        popv(4);
        return Llessp(nil, v0074, v0073);

v0062:
    v0074 = v0123;
    v0073 = (LispObject)1; // 0
    if (v0074 == v0073) goto v0016;
    v0074 = v0123;
    v0073 = (LispObject)1; // 0
        popv(4);
        return Llessp(nil, v0074, v0073);

v0016:
    v0073 = stack[-1];
    v0073 = qcdr(v0073);
    v0073 = qcdr(v0073);
    v0074 = qcar(v0073);
    v0073 = elt(env, 2); // number
    fn = elt(env, 4); // vdpgetprop
    stack[-1] = (*qfn2(fn))(qenv(fn), v0074, v0073);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    env = stack[-3];
    v0073 = stack[0];
    v0073 = qcdr(v0073);
    v0073 = qcdr(v0073);
    v0074 = qcar(v0073);
    v0073 = elt(env, 2); // number
    fn = elt(env, 4); // vdpgetprop
    v0073 = (*qfn2(fn))(qenv(fn), v0074, v0073);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    {
        LispObject v0098 = stack[-1];
        popv(4);
        return Llessp(nil, v0098, v0073);
    }

v0124:
    v0073 = stack[-1];
    v0074 = qcar(v0073);
    v0073 = stack[0];
    v0073 = qcar(v0073);
    {
        popv(4);
        fn = elt(env, 5); // vevcompless!?
        return (*qfn2(fn))(qenv(fn), v0074, v0073);
    }
// error exit handlers
v0125:
    popv(4);
    return nil;
}



// Code for assert_dyntypep

static LispObject CC_assert_dyntypep(LispObject env,
                         LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0026, v0104;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for assert_dyntypep");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0104 = v0002;
// end of prologue
    v0026 = v0104;
    if (symbolp(v0026)) goto v0106;
    v0026 = qvalue(elt(env, 1)); // nil
    return onevalue(v0026);

v0106:
    v0026 = v0104;
    v0104 = elt(env, 2); // assert_dyntype
        return Lflagp(nil, v0026, v0104);
}



// Code for mo!=revlexcomp

static LispObject CC_moMrevlexcomp(LispObject env,
                         LispObject v0002, LispObject v0018)
{
    LispObject nil = C_nil;
    LispObject v0085;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mo=revlexcomp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0018,v0002);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0002,v0018);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0018;
    stack[-1] = v0002;
// end of prologue
    v0085 = stack[-1];
    stack[-2] = Llength(nil, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-3];
    v0085 = stack[0];
    v0085 = Llength(nil, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-3];
    if (((int32_t)(stack[-2])) > ((int32_t)(v0085))) goto v0006;
    v0085 = stack[0];
    stack[-2] = Llength(nil, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-3];
    v0085 = stack[-1];
    v0085 = Llength(nil, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-3];
    if (((int32_t)(stack[-2])) > ((int32_t)(v0085))) goto v0025;
    v0085 = stack[-1];
    stack[-1] = Lreverse(nil, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-3];
    v0085 = stack[0];
    v0085 = Lreverse(nil, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-3];
    fn = elt(env, 1); // mo!=degcomp
    v0085 = (*qfn2(fn))(qenv(fn), stack[-1], v0085);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    popv(4);
    return negate(v0085);

v0025:
    v0085 = (LispObject)17; // 1
    { popv(4); return onevalue(v0085); }

v0006:
    v0085 = (LispObject)-15; // -1
    { popv(4); return onevalue(v0085); }
// error exit handlers
v0122:
    popv(4);
    return nil;
}



// Code for wtchk

static LispObject CC_wtchk(LispObject env,
                         LispObject v0002, LispObject v0018)
{
    LispObject nil = C_nil;
    LispObject v0092, v0093, v0126;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for wtchk");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0018,v0002);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0002,v0018);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0018;
    stack[-2] = v0002;
// end of prologue
    v0092 = stack[-1];
    if (v0092 == nil) { LispObject res = stack[-2]; popv(5); return onevalue(res); }
    v0092 = stack[-2];
    stack[-3] = ncons(v0092);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-4];
    stack[0] = elt(env, 1); // k!*
    v0093 = stack[-1];
    v0092 = stack[-2];
    v0092 = qcar(v0092);
    v0092 = qcdr(v0092);
    v0092 = times2(v0093, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-4];
    fn = elt(env, 3); // to
    v0093 = (*qfn2(fn))(qenv(fn), stack[0], v0092);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-4];
    v0092 = (LispObject)17; // 1
    v0092 = cons(v0093, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-4];
    v0092 = ncons(v0092);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-4];
    fn = elt(env, 4); // quotf
    v0092 = (*qfn2(fn))(qenv(fn), stack[-3], v0092);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-4];
    v0093 = v0092;
    v0092 = v0093;
    if (v0092 == nil) goto v0023;
    v0092 = v0093;
    v0092 = qcar(v0092);
    { popv(5); return onevalue(v0092); }

v0023:
    v0126 = elt(env, 2); // "weight confusion"
    v0093 = stack[-2];
    v0092 = stack[-1];
    v0092 = list3(v0126, v0093, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-4];
    {
        popv(5);
        fn = elt(env, 5); // errach
        return (*qfn1(fn))(qenv(fn), v0092);
    }
// error exit handlers
v0054:
    popv(5);
    return nil;
}



// Code for qqe_qprefix!-var

static LispObject CC_qqe_qprefixKvar(LispObject env,
                         LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0094, v0064;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qqe_qprefix-var");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0002);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0002;
// end of prologue

v0097:
    v0094 = stack[0];
    if (v0094 == nil) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    v0094 = stack[0];
    if (!consp(v0094)) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    v0094 = stack[0];
    fn = elt(env, 3); // qqe_op
    v0064 = (*qfn1(fn))(qenv(fn), v0094);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-1];
    v0094 = elt(env, 2); // (ltail rtail lhead rhead)
    v0094 = Lmemq(nil, v0064, v0094);
    if (v0094 == nil) goto v0049;
    v0094 = stack[0];
    fn = elt(env, 4); // qqe_arg2l
    v0094 = (*qfn1(fn))(qenv(fn), v0094);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-1];
    stack[0] = v0094;
    goto v0097;

v0049:
    v0094 = stack[0];
    fn = elt(env, 5); // qqe_arg2r
    v0094 = (*qfn1(fn))(qenv(fn), v0094);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-1];
    stack[0] = v0094;
    goto v0097;
// error exit handlers
v0116:
    popv(2);
    return nil;
}



// Code for quotodd

static LispObject CC_quotodd(LispObject env,
                         LispObject v0002, LispObject v0018)
{
    LispObject nil = C_nil;
    LispObject v0057, v0094, v0064;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for quotodd");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0018,v0002);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0002,v0018);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// copy arguments values to proper place
    v0094 = v0018;
    v0064 = v0002;
// end of prologue
    v0057 = v0064;
    if (!consp(v0057)) goto v0061;
    v0057 = qvalue(elt(env, 1)); // nil
    goto v0031;

v0031:
    if (v0057 == nil) goto v0032;
    v0057 = v0064;
    fn = elt(env, 2); // mkrn
    v0057 = (*qfn2(fn))(qenv(fn), v0057, v0094);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); // int!-equiv!-chk
        return (*qfn1(fn))(qenv(fn), v0057);
    }

v0032:
    v0057 = v0064;
    {
        popv(1);
        fn = elt(env, 4); // lowest!-terms
        return (*qfn2(fn))(qenv(fn), v0057, v0094);
    }

v0061:
    v0057 = v0094;
    v0057 = (consp(v0057) ? nil : lisp_true);
    goto v0031;
// error exit handlers
v0096:
    popv(1);
    return nil;
}



// Code for ps!:prepfn!:

static LispObject CC_psTprepfnT(LispObject env,
                         LispObject v0002)
{
    LispObject v0077;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ps:prepfn:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0077 = v0002;
// end of prologue
    return onevalue(v0077);
}



// Code for minusp!:

static LispObject CC_minuspT(LispObject env,
                         LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0064, v0096, v0116;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for minusp:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0116 = v0002;
// end of prologue
    v0096 = v0116;
    v0064 = elt(env, 1); // !:rd!:
    if (!consp(v0096)) goto v0089;
    v0096 = qcar(v0096);
    if (!(v0096 == v0064)) goto v0089;
    v0064 = v0116;
    v0064 = qcdr(v0064);
    v0064 = (consp(v0064) ? nil : lisp_true);
    v0064 = (v0064 == nil ? lisp_true : nil);
    goto v0075;

v0075:
    if (v0064 == nil) goto v0052;
    v0064 = v0116;
    v0064 = qcdr(v0064);
    v0096 = qcar(v0064);
    v0064 = (LispObject)1; // 0
        return Llessp(nil, v0096, v0064);

v0052:
    v0064 = qvalue(elt(env, 2)); // nil
    return onevalue(v0064);

v0089:
    v0064 = qvalue(elt(env, 2)); // nil
    goto v0075;
}



// Code for listdiff

static LispObject CC_listdiff(LispObject env,
                         LispObject v0002, LispObject v0018)
{
    LispObject nil = C_nil;
    LispObject v0032, v0117;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for listdiff");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0018,v0002);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0002,v0018);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0018;
    v0032 = v0002;
// end of prologue

v0006:
    v0117 = stack[0];
    if (v0117 == nil) { popv(2); return onevalue(v0032); }
    v0117 = v0032;
    if (v0117 == nil) goto v0103;
    v0117 = stack[0];
    v0117 = qcar(v0117);
    v0032 = Ldelete(nil, v0117, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-1];
    v0117 = stack[0];
    v0117 = qcdr(v0117);
    stack[0] = v0117;
    goto v0006;

v0103:
    v0032 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0032); }
// error exit handlers
v0050:
    popv(2);
    return nil;
}



// Code for set!-ordp

static LispObject CC_setKordp(LispObject env,
                         LispObject v0002, LispObject v0018)
{
    LispObject nil = C_nil;
    LispObject v0032, v0117, v0049;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for set-ordp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0117 = v0018;
    v0049 = v0002;
// end of prologue
    v0032 = v0049;
    if (!(is_number(v0032))) goto v0089;
    v0032 = v0117;
    if (!(is_number(v0032))) goto v0089;
    v0032 = v0049;
        return Llessp(nil, v0032, v0117);

v0089:
    v0032 = v0049;
    {
        fn = elt(env, 1); // ordp
        return (*qfn2(fn))(qenv(fn), v0032, v0117);
    }
}



// Code for scalopp

static LispObject CC_scalopp(LispObject env,
                         LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0141, v0142, v0143;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for scalopp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0002);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-3] = v0002;
// end of prologue
    v0141 = stack[-3];
    if (symbolp(v0141)) goto v0065;
    v0141 = qvalue(elt(env, 1)); // nil
    goto v0097;

v0097:
    if (!(v0141 == nil)) { popv(6); return onevalue(v0141); }
    v0141 = stack[-3];
    if (!consp(v0141)) goto v0144;
    v0141 = stack[-3];
    v0141 = qcar(v0141);
    if (!symbolp(v0141)) v0142 = nil;
    else { v0142 = qfastgets(v0141);
           if (v0142 != nil) { v0142 = elt(v0142, 18); // phystype
#ifdef RECORD_GET
             if (v0142 != SPID_NOPROP)
                record_get(elt(fastget_names, 18), 1);
             else record_get(elt(fastget_names, 18), 0),
                v0142 = nil; }
           else record_get(elt(fastget_names, 18), 0); }
#else
             if (v0142 == SPID_NOPROP) v0142 = nil; }}
#endif
    v0141 = elt(env, 2); // scalar
    if (v0142 == v0141) goto v0032;
    v0141 = stack[-3];
    v0141 = qcar(v0141);
    if (!symbolp(v0141)) v0142 = nil;
    else { v0142 = qfastgets(v0141);
           if (v0142 != nil) { v0142 = elt(v0142, 18); // phystype
#ifdef RECORD_GET
             if (v0142 != SPID_NOPROP)
                record_get(elt(fastget_names, 18), 1);
             else record_get(elt(fastget_names, 18), 0),
                v0142 = nil; }
           else record_get(elt(fastget_names, 18), 0); }
#else
             if (v0142 == SPID_NOPROP) v0142 = nil; }}
#endif
    v0141 = elt(env, 4); // vector
    if (v0142 == v0141) goto v0102;
    v0141 = qvalue(elt(env, 1)); // nil
    goto v0113;

v0113:
    if (!(v0141 == nil)) { popv(6); return onevalue(v0141); }
    v0141 = stack[-3];
    v0141 = qcar(v0141);
    if (!symbolp(v0141)) v0142 = nil;
    else { v0142 = qfastgets(v0141);
           if (v0142 != nil) { v0142 = elt(v0142, 18); // phystype
#ifdef RECORD_GET
             if (v0142 != SPID_NOPROP)
                record_get(elt(fastget_names, 18), 1);
             else record_get(elt(fastget_names, 18), 0),
                v0142 = nil; }
           else record_get(elt(fastget_names, 18), 0); }
#else
             if (v0142 == SPID_NOPROP) v0142 = nil; }}
#endif
    v0141 = elt(env, 5); // tensor
    if (v0142 == v0141) goto v0067;
    v0141 = qvalue(elt(env, 1)); // nil
    { popv(6); return onevalue(v0141); }

v0067:
    v0141 = stack[-3];
    v0141 = qcdr(v0141);
    v0143 = Llength(nil, v0141);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-5];
    v0141 = stack[-3];
    v0142 = qcar(v0141);
    v0141 = elt(env, 6); // tensdimen
    v0141 = get(v0142, v0141);
    env = stack[-5];
    v0141 = (LispObject)geq2(v0143, v0141);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    v0141 = v0141 ? lisp_true : nil;
    env = stack[-5];
    if (v0141 == nil) goto v0016;
    v0141 = (LispObject)17; // 1
    stack[-4] = v0141;
    v0141 = stack[-3];
    v0142 = qcar(v0141);
    v0141 = elt(env, 6); // tensdimen
    v0142 = get(v0142, v0141);
    env = stack[-5];
    v0141 = stack[-4];
    v0141 = difference2(v0142, v0141);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-5];
    v0141 = Lminusp(nil, v0141);
    env = stack[-5];
    if (v0141 == nil) goto v0045;
    v0141 = qvalue(elt(env, 1)); // nil
    goto v0146;

v0146:
    {
        popv(6);
        fn = elt(env, 7); // areallindices
        return (*qfn1(fn))(qenv(fn), v0141);
    }

v0045:
    v0141 = stack[-3];
    v0142 = qcdr(v0141);
    v0141 = stack[-4];
    fn = elt(env, 8); // nth
    v0141 = (*qfn2(fn))(qenv(fn), v0142, v0141);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-5];
    v0141 = ncons(v0141);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-5];
    stack[-1] = v0141;
    stack[-2] = v0141;
    goto v0147;

v0147:
    v0141 = stack[-4];
    v0141 = add1(v0141);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-5];
    stack[-4] = v0141;
    v0141 = stack[-3];
    v0142 = qcar(v0141);
    v0141 = elt(env, 6); // tensdimen
    v0142 = get(v0142, v0141);
    env = stack[-5];
    v0141 = stack[-4];
    v0141 = difference2(v0142, v0141);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-5];
    v0141 = Lminusp(nil, v0141);
    env = stack[-5];
    if (v0141 == nil) goto v0148;
    v0141 = stack[-2];
    goto v0146;

v0148:
    stack[0] = stack[-1];
    v0141 = stack[-3];
    v0142 = qcdr(v0141);
    v0141 = stack[-4];
    fn = elt(env, 8); // nth
    v0141 = (*qfn2(fn))(qenv(fn), v0142, v0141);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-5];
    v0141 = ncons(v0141);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-5];
    v0141 = Lrplacd(nil, stack[0], v0141);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-5];
    v0141 = stack[-1];
    v0141 = qcdr(v0141);
    stack[-1] = v0141;
    goto v0147;

v0016:
    v0141 = qvalue(elt(env, 1)); // nil
    { popv(6); return onevalue(v0141); }

v0102:
    v0141 = stack[-3];
    v0141 = qcdr(v0141);
    v0141 = qcar(v0141);
    fn = elt(env, 9); // isanindex
    v0141 = (*qfn1(fn))(qenv(fn), v0141);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-5];
    goto v0113;

v0032:
    v0141 = qvalue(elt(env, 3)); // t
    { popv(6); return onevalue(v0141); }

v0144:
    v0141 = qvalue(elt(env, 1)); // nil
    { popv(6); return onevalue(v0141); }

v0065:
    v0141 = stack[-3];
    if (!symbolp(v0141)) v0142 = nil;
    else { v0142 = qfastgets(v0141);
           if (v0142 != nil) { v0142 = elt(v0142, 18); // phystype
#ifdef RECORD_GET
             if (v0142 != SPID_NOPROP)
                record_get(elt(fastget_names, 18), 1);
             else record_get(elt(fastget_names, 18), 0),
                v0142 = nil; }
           else record_get(elt(fastget_names, 18), 0); }
#else
             if (v0142 == SPID_NOPROP) v0142 = nil; }}
#endif
    v0141 = elt(env, 2); // scalar
    v0141 = (v0142 == v0141 ? lisp_true : nil);
    goto v0097;
// error exit handlers
v0145:
    popv(6);
    return nil;
}



// Code for form

static LispObject CC_form(LispObject env,
                         LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0151, v0152, v0153;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for form");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0002);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// copy arguments values to proper place
    v0152 = v0002;
// end of prologue
    v0151 = v0152;
    if (!consp(v0151)) goto v0107;
    v0151 = v0152;
    v0153 = qcar(v0151);
    v0151 = elt(env, 1); // always_nform
    v0151 = Lflagp(nil, v0153, v0151);
    env = stack[0];
    goto v0075;

v0075:
    if (v0151 == nil) goto v0006;
    v0151 = v0152;
    {
        popv(1);
        fn = elt(env, 11); // n_form
        return (*qfn1(fn))(qenv(fn), v0151);
    }

v0006:
    v0151 = qvalue(elt(env, 3)); // !*rlisp88
    if (v0151 == nil) goto v0032;
    v0153 = qvalue(elt(env, 5)); // !*mode
    v0151 = elt(env, 6); // symbolic
    if (v0153 == v0151) goto v0084;
    v0151 = qvalue(elt(env, 7)); // t
    goto v0085;

v0085:
    if (v0151 == nil) goto v0123;
    v0152 = elt(env, 9); // "algebraic expression"
    v0151 = elt(env, 10); // "Rlisp88 form"
    {
        popv(1);
        fn = elt(env, 12); // typerr
        return (*qfn2(fn))(qenv(fn), v0152, v0151);
    }

v0123:
    v0153 = v0152;
    v0152 = qvalue(elt(env, 4)); // !*vars!*
    v0151 = qvalue(elt(env, 5)); // !*mode
    {
        popv(1);
        fn = elt(env, 13); // form1
        return (*qfnn(fn))(qenv(fn), 3, v0153, v0152, v0151);
    }

v0084:
    v0151 = v0152;
    if (!symbolp(v0151)) v0151 = nil;
    else { v0151 = qfastgets(v0151);
           if (v0151 != nil) { v0151 = elt(v0151, 48); // modefn
#ifdef RECORD_GET
             if (v0151 == SPID_NOPROP)
                record_get(elt(fastget_names, 48), 0),
                v0151 = nil;
             else record_get(elt(fastget_names, 48), 1),
                v0151 = lisp_true; }
           else record_get(elt(fastget_names, 48), 0); }
#else
             if (v0151 == SPID_NOPROP) v0151 = nil; else v0151 = lisp_true; }}
#endif
    if (v0151 == nil) goto v0036;
    v0153 = v0152;
    v0151 = elt(env, 6); // symbolic
    v0151 = (v0153 == v0151 ? lisp_true : nil);
    v0151 = (v0151 == nil ? lisp_true : nil);
    goto v0037;

v0037:
    if (v0151 == nil) goto v0068;
    v0151 = qvalue(elt(env, 7)); // t
    goto v0085;

v0068:
    v0153 = v0152;
    v0151 = elt(env, 8); // modefn
    v0151 = Lflagpcar(nil, v0153, v0151);
    env = stack[0];
    if (v0151 == nil) goto v0112;
    v0151 = v0152;
    v0153 = qcar(v0151);
    v0151 = elt(env, 6); // symbolic
    v0151 = (v0153 == v0151 ? lisp_true : nil);
    v0151 = (v0151 == nil ? lisp_true : nil);
    goto v0085;

v0112:
    v0151 = qvalue(elt(env, 2)); // nil
    goto v0085;

v0036:
    v0151 = qvalue(elt(env, 2)); // nil
    goto v0037;

v0032:
    v0153 = v0152;
    v0152 = qvalue(elt(env, 4)); // !*vars!*
    v0151 = qvalue(elt(env, 5)); // !*mode
    {
        popv(1);
        fn = elt(env, 13); // form1
        return (*qfnn(fn))(qenv(fn), 3, v0153, v0152, v0151);
    }

v0107:
    v0151 = qvalue(elt(env, 2)); // nil
    goto v0075;
}



// Code for red!-ratios2

static LispObject CC_redKratios2(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0146, v0147, v0012, v0013;
    LispObject fn;
    LispObject v0077, v0017, v0018, v0002;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "red-ratios2");
    va_start(aa, nargs);
    v0002 = va_arg(aa, LispObject);
    v0018 = va_arg(aa, LispObject);
    v0017 = va_arg(aa, LispObject);
    v0077 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for red-ratios2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0077,v0017,v0018,v0002);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0002,v0018,v0017,v0077);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    stack[-1] = v0077;
    stack[-2] = v0017;
    stack[-3] = v0018;
    stack[-4] = v0002;
// end of prologue

v0101:
    v0146 = stack[-4];
    if (v0146 == nil) goto v0106;
    v0147 = stack[-2];
    v0146 = stack[-3];
    v0146 = qcar(v0146);
    stack[0] = times2(v0147, v0146);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-6];
    stack[-5] = stack[0];
    v0147 = stack[-1];
    v0146 = stack[-4];
    v0146 = qcar(v0146);
    v0146 = times2(v0147, v0146);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-6];
    if (equal(stack[0], v0146)) goto v0102;
    v0146 = qvalue(elt(env, 1)); // nil
    goto v0026;

v0026:
    if (v0146 == nil) goto v0155;
    v0147 = stack[-1];
    v0146 = stack[-2];
    {
        popv(7);
        fn = elt(env, 2); // red!-lowest!-terms
        return (*qfn2(fn))(qenv(fn), v0147, v0146);
    }

v0155:
    v0146 = stack[-4];
    v0013 = qcdr(v0146);
    v0146 = stack[-3];
    v0012 = qcdr(v0146);
    v0147 = stack[-2];
    v0146 = stack[-1];
    stack[-4] = v0013;
    stack[-3] = v0012;
    stack[-2] = v0147;
    stack[-1] = v0146;
    goto v0101;

v0102:
    v0147 = stack[-5];
    v0146 = (LispObject)1; // 0
    if (v0147 == v0146) goto v0058;
    v0147 = stack[-1];
    v0146 = stack[-2];
    v0147 = Lgcd(nil, v0147, v0146);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-6];
    v0146 = stack[-1];
    v0147 = Cremainder(v0147, v0146);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-6];
    v0146 = (LispObject)1; // 0
    v0146 = (v0147 == v0146 ? lisp_true : nil);
    goto v0026;

v0058:
    v0146 = qvalue(elt(env, 1)); // nil
    goto v0026;

v0106:
    v0146 = qvalue(elt(env, 1)); // nil
    { popv(7); return onevalue(v0146); }
// error exit handlers
v0010:
    popv(7);
    return nil;
}



// Code for cali_bc_zero!?

static LispObject CC_cali_bc_zeroW(LispObject env,
                         LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0096, v0116, v0100;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cali_bc_zero?");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0002);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// copy arguments values to proper place
    v0116 = v0002;
// end of prologue
    v0096 = v0116;
    if (v0096 == nil) goto v0031;
    v0100 = v0116;
    v0096 = (LispObject)1; // 0
    v0096 = (v0100 == v0096 ? lisp_true : nil);
    goto v0075;

v0075:
    if (v0096 == nil) goto v0006;
    v0096 = qvalue(elt(env, 1)); // t
    { popv(1); return onevalue(v0096); }

v0006:
    v0096 = qvalue(elt(env, 2)); // !*hardzerotest
    if (v0096 == nil) goto v0057;
    v0096 = v0116;
    v0096 = Lconsp(nil, v0096);
    env = stack[0];
    if (v0096 == nil) goto v0057;
    v0096 = v0116;
    fn = elt(env, 4); // prepf
    v0096 = (*qfn1(fn))(qenv(fn), v0096);
    nil = C_nil;
    if (exception_pending()) goto v0085;
    env = stack[0];
    fn = elt(env, 5); // simp
    v0096 = (*qfn1(fn))(qenv(fn), v0096);
    nil = C_nil;
    if (exception_pending()) goto v0085;
    env = stack[0];
    v0096 = qcar(v0096);
    fn = elt(env, 6); // bc!=simp
    v0096 = (*qfn1(fn))(qenv(fn), v0096);
    nil = C_nil;
    if (exception_pending()) goto v0085;
    v0096 = (v0096 == nil ? lisp_true : nil);
    { popv(1); return onevalue(v0096); }

v0057:
    v0096 = qvalue(elt(env, 3)); // nil
    { popv(1); return onevalue(v0096); }

v0031:
    v0096 = qvalue(elt(env, 1)); // t
    goto v0075;
// error exit handlers
v0085:
    popv(1);
    return nil;
}



// Code for dd

static LispObject CC_dd(LispObject env,
                         LispObject v0002, LispObject v0018)
{
    LispObject nil = C_nil;
    LispObject v0132, v0131, v0127;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dd");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0018,v0002);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0002,v0018);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0018;
    stack[-2] = v0002;
// end of prologue
    v0131 = stack[0];
    v0132 = stack[-2];
    fn = elt(env, 6); // dquot
    v0132 = (*qfn2(fn))(qenv(fn), v0131, v0132);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-4];
    v0127 = v0132;
    v0132 = v0127;
    if (v0132 == nil) goto v0099;
    v0131 = qvalue(elt(env, 1)); // ordering
    v0132 = elt(env, 2); // lex
    if (v0131 == v0132) goto v0094;
    v0132 = v0127;
    v0132 = qcdr(v0132);
    v0127 = v0132;
    goto v0094;

v0094:
    v0132 = v0127;
    fn = elt(env, 7); // leftzeros
    v0132 = (*qfn1(fn))(qenv(fn), v0132);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-4];
    stack[-3] = v0132;
    v0132 = qvalue(elt(env, 3)); // nc!*
    if (v0132 == nil) goto v0037;
    v0132 = qvalue(elt(env, 5)); // nil
    goto v0069;

v0069:
    if (v0132 == nil) goto v0088;
    v0132 = (LispObject)49; // 3
    { popv(5); return onevalue(v0132); }

v0088:
    v0132 = qvalue(elt(env, 3)); // nc!*
    if (v0132 == nil) goto v0114;
    stack[0] = stack[-3];
    v0132 = qvalue(elt(env, 4)); // varlist!*
    v0132 = Llength(nil, v0132);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-4];
    v0131 = qvalue(elt(env, 3)); // nc!*
    v0132 = (LispObject)(int32_t)((int32_t)v0132 - (int32_t)v0131 + TAG_FIXNUM);
    if (((int32_t)(stack[0])) < ((int32_t)(v0132))) goto v0114;
    v0132 = (LispObject)65; // 4
    { popv(5); return onevalue(v0132); }

v0114:
    v0132 = (LispObject)33; // 2
    { popv(5); return onevalue(v0132); }

v0037:
    stack[-1] = stack[-3];
    v0132 = qvalue(elt(env, 4)); // varlist!*
    stack[0] = Llength(nil, v0132);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-4];
    v0132 = stack[-2];
    fn = elt(env, 8); // class
    v0132 = (*qfn1(fn))(qenv(fn), v0132);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-4];
    v0132 = (LispObject)(int32_t)((int32_t)stack[0] - (int32_t)v0132 + TAG_FIXNUM);
    v0132 = ((intptr_t)stack[-1] < (intptr_t)v0132) ? lisp_true : nil;
    v0132 = (v0132 == nil ? lisp_true : nil);
    goto v0069;

v0099:
    v0131 = stack[-2];
    v0132 = stack[0];
    fn = elt(env, 9); // dless
    v0132 = (*qfn2(fn))(qenv(fn), v0131, v0132);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    if (v0132 == nil) goto v0105;
    v0132 = (LispObject)17; // 1
    { popv(5); return onevalue(v0132); }

v0105:
    v0132 = (LispObject)1; // 0
    { popv(5); return onevalue(v0132); }
// error exit handlers
v0042:
    popv(5);
    return nil;
}



// Code for general!-modular!-reciprocal

static LispObject CC_generalKmodularKreciprocal(LispObject env,
                         LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0088, v0070, v0069, v0062;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for general-modular-reciprocal");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0002);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0002;
// end of prologue
    v0088 = qvalue(elt(env, 1)); // !*balanced_mod
    if (v0088 == nil) goto v0100;
    v0070 = stack[0];
    v0088 = (LispObject)1; // 0
    v0088 = (LispObject)lessp2(v0070, v0088);
    nil = C_nil;
    if (exception_pending()) goto v0037;
    v0088 = v0088 ? lisp_true : nil;
    env = stack[-2];
    if (v0088 == nil) goto v0100;
    stack[-1] = qvalue(elt(env, 2)); // current!-modulus
    v0070 = stack[0];
    v0088 = qvalue(elt(env, 2)); // current!-modulus
    v0069 = plus2(v0070, v0088);
    nil = C_nil;
    if (exception_pending()) goto v0037;
    env = stack[-2];
    v0070 = (LispObject)1; // 0
    v0088 = (LispObject)17; // 1
    {
        LispObject v0078 = stack[-1];
        popv(3);
        fn = elt(env, 3); // general!-reciprocal!-by!-gcd
        return (*qfnn(fn))(qenv(fn), 4, v0078, v0069, v0070, v0088);
    }

v0100:
    v0062 = qvalue(elt(env, 2)); // current!-modulus
    v0069 = stack[0];
    v0070 = (LispObject)1; // 0
    v0088 = (LispObject)17; // 1
    {
        popv(3);
        fn = elt(env, 3); // general!-reciprocal!-by!-gcd
        return (*qfnn(fn))(qenv(fn), 4, v0062, v0069, v0070, v0088);
    }
// error exit handlers
v0037:
    popv(3);
    return nil;
}



// Code for horner!-rule

static LispObject CC_hornerKrule(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0168, v0169, v0170, v0171;
    LispObject fn;
    LispObject v0077, v0017, v0018, v0002;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "horner-rule");
    va_start(aa, nargs);
    v0002 = va_arg(aa, LispObject);
    v0018 = va_arg(aa, LispObject);
    v0017 = va_arg(aa, LispObject);
    v0077 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for horner-rule");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0077,v0017,v0018,v0002);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0002,v0018,v0017,v0077);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    stack[-1] = v0077;
    stack[-2] = v0017;
    stack[-3] = v0018;
    stack[-4] = v0002;
// end of prologue

v0101:
    v0168 = stack[-2];
    if (!consp(v0168)) goto v0106;
    v0168 = stack[-2];
    v0168 = qcar(v0168);
    v0168 = (consp(v0168) ? nil : lisp_true);
    goto v0051;

v0051:
    if (v0168 == nil) goto v0038;
    v0168 = stack[-1];
    v0168 = qcar(v0168);
    v0168 = qcdr(v0168);
    v0168 = (LispObject)zerop(v0168);
    v0168 = v0168 ? lisp_true : nil;
    env = stack[-6];
    if (v0168 == nil) goto v0105;
    v0168 = stack[-2];
    {
        popv(7);
        fn = elt(env, 2); // !*d2n
        return (*qfn1(fn))(qenv(fn), v0168);
    }

v0105:
    v0168 = stack[-2];
    fn = elt(env, 2); // !*d2n
    stack[0] = (*qfn1(fn))(qenv(fn), v0168);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    env = stack[-6];
    stack[-2] = stack[-4];
    v0168 = stack[-1];
    v0168 = qcar(v0168);
    v0169 = qcdr(v0168);
    v0168 = stack[-3];
    v0168 = Lexpt(nil, v0169, v0168);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    env = stack[-6];
    v0168 = times2(stack[-2], v0168);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    {
        LispObject v0173 = stack[0];
        popv(7);
        return plus2(v0173, v0168);
    }

v0038:
    v0168 = stack[-2];
    v0168 = qcar(v0168);
    v0168 = qcar(v0168);
    v0169 = qcar(v0168);
    v0168 = stack[-1];
    v0168 = qcar(v0168);
    v0168 = qcar(v0168);
    if (equal(v0169, v0168)) goto v0098;
    v0168 = stack[-1];
    v0168 = qcar(v0168);
    v0168 = qcdr(v0168);
    v0168 = (LispObject)zerop(v0168);
    v0168 = v0168 ? lisp_true : nil;
    env = stack[-6];
    if (v0168 == nil) goto v0091;
    v0169 = stack[-2];
    v0168 = stack[-1];
    v0168 = qcdr(v0168);
    {
        popv(7);
        fn = elt(env, 3); // evaluate!-in!-order
        return (*qfn2(fn))(qenv(fn), v0169, v0168);
    }

v0091:
    v0169 = stack[-2];
    v0168 = stack[-1];
    v0168 = qcdr(v0168);
    fn = elt(env, 3); // evaluate!-in!-order
    stack[0] = (*qfn2(fn))(qenv(fn), v0169, v0168);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    env = stack[-6];
    stack[-2] = stack[-4];
    v0168 = stack[-1];
    v0168 = qcar(v0168);
    v0169 = qcdr(v0168);
    v0168 = stack[-3];
    v0168 = Lexpt(nil, v0169, v0168);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    env = stack[-6];
    v0168 = times2(stack[-2], v0168);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    {
        LispObject v0174 = stack[0];
        popv(7);
        return plus2(v0174, v0168);
    }

v0098:
    v0168 = stack[-2];
    v0168 = qcar(v0168);
    v0168 = qcar(v0168);
    v0168 = qcdr(v0168);
    stack[-5] = v0168;
    v0168 = stack[-1];
    v0168 = qcar(v0168);
    v0168 = qcdr(v0168);
    v0168 = (LispObject)zerop(v0168);
    v0168 = v0168 ? lisp_true : nil;
    env = stack[-6];
    if (v0168 == nil) goto v0148;
    v0168 = stack[-2];
    v0168 = qcar(v0168);
    v0169 = qcdr(v0168);
    v0168 = stack[-1];
    v0168 = qcdr(v0168);
    fn = elt(env, 3); // evaluate!-in!-order
    v0168 = (*qfn2(fn))(qenv(fn), v0169, v0168);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    env = stack[-6];
    v0171 = v0168;
    goto v0175;

v0175:
    v0170 = stack[-5];
    v0168 = stack[-2];
    v0169 = qcdr(v0168);
    v0168 = stack[-1];
    stack[-4] = v0171;
    stack[-3] = v0170;
    stack[-2] = v0169;
    stack[-1] = v0168;
    goto v0101;

v0148:
    v0168 = stack[-2];
    v0168 = qcar(v0168);
    v0169 = qcdr(v0168);
    v0168 = stack[-1];
    v0168 = qcdr(v0168);
    fn = elt(env, 3); // evaluate!-in!-order
    stack[0] = (*qfn2(fn))(qenv(fn), v0169, v0168);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    env = stack[-6];
    v0168 = stack[-1];
    v0168 = qcar(v0168);
    v0170 = qcdr(v0168);
    v0169 = stack[-3];
    v0168 = stack[-5];
    v0168 = (LispObject)(int32_t)((int32_t)v0169 - (int32_t)v0168 + TAG_FIXNUM);
    v0168 = Lexpt(nil, v0170, v0168);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    env = stack[-6];
    v0168 = times2(stack[-4], v0168);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    env = stack[-6];
    v0168 = plus2(stack[0], v0168);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    env = stack[-6];
    v0171 = v0168;
    goto v0175;

v0106:
    v0168 = qvalue(elt(env, 1)); // t
    goto v0051;
// error exit handlers
v0172:
    popv(7);
    return nil;
}



// Code for ckrn

static LispObject CC_ckrn(LispObject env,
                         LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0069, v0062;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ckrn");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0002);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0002;
// end of prologue
    v0069 = qvalue(elt(env, 1)); // dmode!*
    if (!symbolp(v0069)) v0069 = nil;
    else { v0069 = qfastgets(v0069);
           if (v0069 != nil) { v0069 = elt(v0069, 3); // field
#ifdef RECORD_GET
             if (v0069 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v0069 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v0069 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v0069 == SPID_NOPROP) v0069 = nil; else v0069 = lisp_true; }}
#endif
    if (v0069 == nil) goto v0083;
    v0062 = qvalue(elt(env, 1)); // dmode!*
    v0069 = elt(env, 2); // (!:rd!: !:cr!:)
    v0069 = Lmemq(nil, v0062, v0069);
    v0069 = (v0069 == nil ? lisp_true : nil);
    goto v0075;

v0075:
    if (v0069 == nil) goto v0023;
    v0069 = stack[0];
    fn = elt(env, 4); // lnc
    v0069 = (*qfn1(fn))(qenv(fn), v0069);
    nil = C_nil;
    if (exception_pending()) goto v0037;
    env = stack[-2];
    stack[-1] = v0069;
    v0062 = stack[0];
    fn = elt(env, 5); // quotfd
    v0069 = (*qfn2(fn))(qenv(fn), v0062, v0069);
    nil = C_nil;
    if (exception_pending()) goto v0037;
    env = stack[-2];
    fn = elt(env, 6); // ckrn1
    v0069 = (*qfn1(fn))(qenv(fn), v0069);
    nil = C_nil;
    if (exception_pending()) goto v0037;
    env = stack[-2];
    fn = elt(env, 7); // multf
    v0069 = (*qfn2(fn))(qenv(fn), stack[-1], v0069);
    nil = C_nil;
    if (exception_pending()) goto v0037;
    v0062 = v0069;
    if (!(v0062 == nil)) { popv(3); return onevalue(v0069); }
    v0069 = (LispObject)17; // 1
    { popv(3); return onevalue(v0069); }

v0023:
    v0069 = stack[0];
    {
        popv(3);
        fn = elt(env, 6); // ckrn1
        return (*qfn1(fn))(qenv(fn), v0069);
    }

v0083:
    v0069 = qvalue(elt(env, 3)); // nil
    goto v0075;
// error exit handlers
v0037:
    popv(3);
    return nil;
}



// Code for rl_negateat

static LispObject CC_rl_negateat(LispObject env,
                         LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0106;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rl_negateat");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0002);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0106 = v0002;
// end of prologue
    stack[0] = qvalue(elt(env, 1)); // rl_negateat!*
    v0106 = ncons(v0106);
    nil = C_nil;
    if (exception_pending()) goto v0065;
    env = stack[-1];
    {
        LispObject v0063 = stack[0];
        popv(2);
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(qenv(fn), v0063, v0106);
    }
// error exit handlers
v0065:
    popv(2);
    return nil;
}



// Code for rl_simpbop

static LispObject CC_rl_simpbop(LispObject env,
                         LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0084, v0088;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rl_simpbop");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0002);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    v0088 = v0002;
// end of prologue
    v0084 = v0088;
    stack[-4] = qcar(v0084);
    v0084 = v0088;
    v0084 = qcdr(v0084);
    stack[-3] = v0084;
    v0084 = stack[-3];
    if (v0084 == nil) goto v0107;
    v0084 = stack[-3];
    v0084 = qcar(v0084);
    fn = elt(env, 2); // rl_simp1
    v0084 = (*qfn1(fn))(qenv(fn), v0084);
    nil = C_nil;
    if (exception_pending()) goto v0037;
    env = stack[-5];
    v0084 = ncons(v0084);
    nil = C_nil;
    if (exception_pending()) goto v0037;
    env = stack[-5];
    stack[-1] = v0084;
    stack[-2] = v0084;
    goto v0047;

v0047:
    v0084 = stack[-3];
    v0084 = qcdr(v0084);
    stack[-3] = v0084;
    v0084 = stack[-3];
    if (v0084 == nil) goto v0072;
    stack[0] = stack[-1];
    v0084 = stack[-3];
    v0084 = qcar(v0084);
    fn = elt(env, 2); // rl_simp1
    v0084 = (*qfn1(fn))(qenv(fn), v0084);
    nil = C_nil;
    if (exception_pending()) goto v0037;
    env = stack[-5];
    v0084 = ncons(v0084);
    nil = C_nil;
    if (exception_pending()) goto v0037;
    env = stack[-5];
    v0084 = Lrplacd(nil, stack[0], v0084);
    nil = C_nil;
    if (exception_pending()) goto v0037;
    env = stack[-5];
    v0084 = stack[-1];
    v0084 = qcdr(v0084);
    stack[-1] = v0084;
    goto v0047;

v0072:
    v0084 = stack[-2];
    goto v0097;

v0097:
    {
        LispObject v0078 = stack[-4];
        popv(6);
        return cons(v0078, v0084);
    }

v0107:
    v0084 = qvalue(elt(env, 1)); // nil
    goto v0097;
// error exit handlers
v0037:
    popv(6);
    return nil;
}



// Code for numeric!-content

static LispObject CC_numericKcontent(LispObject env,
                         LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0037, v0078, v0079;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for numeric-content");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0002);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0002;
// end of prologue

v0005:
    v0037 = stack[0];
    if (!consp(v0037)) goto v0106;
    v0037 = stack[0];
    v0037 = qcar(v0037);
    v0037 = (consp(v0037) ? nil : lisp_true);
    goto v0051;

v0051:
    if (v0037 == nil) goto v0031;
    v0037 = stack[0];
    {
        popv(3);
        fn = elt(env, 2); // absf
        return (*qfn1(fn))(qenv(fn), v0037);
    }

v0031:
    v0037 = stack[0];
    v0037 = qcdr(v0037);
    if (v0037 == nil) goto v0089;
    v0037 = stack[0];
    v0037 = qcar(v0037);
    v0037 = qcdr(v0037);
    v0037 = CC_numericKcontent(env, v0037);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-2];
    v0079 = v0037;
    v0078 = v0079;
    v0037 = (LispObject)17; // 1
    if (v0078 == v0037) { popv(3); return onevalue(v0079); }
    stack[-1] = v0079;
    v0037 = stack[0];
    v0037 = qcdr(v0037);
    v0037 = CC_numericKcontent(env, v0037);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-2];
    fn = elt(env, 3); // gcddd
    v0037 = (*qfn2(fn))(qenv(fn), stack[-1], v0037);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    v0079 = v0037;
    { popv(3); return onevalue(v0079); }

v0089:
    v0037 = stack[0];
    v0037 = qcar(v0037);
    v0037 = qcdr(v0037);
    stack[0] = v0037;
    goto v0005;

v0106:
    v0037 = qvalue(elt(env, 1)); // t
    goto v0051;
// error exit handlers
v0108:
    popv(3);
    return nil;
}



// Code for ps!:get!-term

static LispObject CC_psTgetKterm(LispObject env,
                         LispObject v0002, LispObject v0018)
{
    LispObject nil = C_nil;
    LispObject v0153, v0176, v0138;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ps:get-term");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0018,v0002);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0002,v0018);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0018;
    stack[-2] = v0002;
// end of prologue
    v0153 = stack[-2];
    fn = elt(env, 4); // ps!:order
    stack[0] = (*qfn1(fn))(qenv(fn), v0153);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-4];
    v0153 = stack[-2];
    fn = elt(env, 5); // ps!:last!-term
    v0153 = (*qfn1(fn))(qenv(fn), v0153);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-4];
    stack[-3] = stack[0];
    stack[0] = v0153;
    v0176 = stack[-1];
    v0153 = stack[-3];
    v0153 = (LispObject)lessp2(v0176, v0153);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    v0153 = v0153 ? lisp_true : nil;
    env = stack[-4];
    if (v0153 == nil) goto v0050;
    v0176 = qvalue(elt(env, 1)); // nil
    v0153 = (LispObject)17; // 1
    popv(5);
    return cons(v0176, v0153);

v0050:
    v0176 = stack[-1];
    v0153 = stack[0];
    v0153 = (LispObject)greaterp2(v0176, v0153);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    v0153 = v0153 ? lisp_true : nil;
    env = stack[-4];
    if (v0153 == nil) goto v0022;
    v0153 = qvalue(elt(env, 1)); // nil
    { popv(5); return onevalue(v0153); }

v0022:
    v0176 = stack[-1];
    v0153 = stack[-3];
    stack[0] = difference2(v0176, v0153);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-4];
    v0153 = stack[-2];
    if (!consp(v0153)) goto v0056;
    v0153 = stack[-2];
    v0176 = qcar(v0153);
    v0153 = elt(env, 3); // !:ps!:
    if (v0176 == v0153) goto v0068;
    v0153 = stack[-2];
    v0153 = qcar(v0153);
    if (!symbolp(v0153)) v0153 = nil;
    else { v0153 = qfastgets(v0153);
           if (v0153 != nil) { v0153 = elt(v0153, 8); // dname
#ifdef RECORD_GET
             if (v0153 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v0153 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v0153 == SPID_NOPROP) v0153 = nil; }}
#endif
    goto v0055;

v0055:
    if (v0153 == nil) goto v0114;
    v0138 = (LispObject)1; // 0
    v0176 = stack[-2];
    v0153 = (LispObject)17; // 1
    v0153 = list2star(v0138, v0176, v0153);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-4];
    v0153 = ncons(v0153);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-4];
    goto v0102;

v0102:
    v0153 = Lassoc(nil, stack[0], v0153);
    v0176 = v0153;
    v0153 = v0176;
    if (v0153 == nil) goto v0125;
    v0153 = v0176;
    v0153 = qcdr(v0153);
    { popv(5); return onevalue(v0153); }

v0125:
    v0176 = qvalue(elt(env, 1)); // nil
    v0153 = (LispObject)17; // 1
    popv(5);
    return cons(v0176, v0153);

v0114:
    v0176 = stack[-2];
    v0153 = (LispObject)81; // 5
    fn = elt(env, 6); // ps!:getv
    v0153 = (*qfn2(fn))(qenv(fn), v0176, v0153);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-4];
    goto v0102;

v0068:
    v0153 = qvalue(elt(env, 1)); // nil
    goto v0055;

v0056:
    v0153 = qvalue(elt(env, 2)); // t
    goto v0055;
// error exit handlers
v0177:
    popv(5);
    return nil;
}



// Code for isimplicit

static LispObject CC_isimplicit(LispObject env,
                         LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0096, v0116, v0100;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for isimplicit");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0002);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0002;
// end of prologue
    v0096 = elt(env, 1); // implicit! 
    v0096 = Lexplode(nil, v0096);
    nil = C_nil;
    if (exception_pending()) goto v0020;
    env = stack[-2];
    stack[-1] = v0096;
    v0096 = stack[0];
    v0096 = Lexplode(nil, v0096);
    nil = C_nil;
    if (exception_pending()) goto v0020;
    v0116 = v0096;
    v0096 = lisp_true;
    v0100 = v0096;
    goto v0063;

v0063:
    v0096 = v0100;
    if (v0096 == nil) { popv(3); return onevalue(v0100); }
    v0096 = stack[-1];
    if (v0096 == nil) { popv(3); return onevalue(v0100); }
    v0096 = v0116;
    v0100 = qcar(v0096);
    v0096 = stack[-1];
    v0096 = qcar(v0096);
    v0096 = (equal(v0100, v0096) ? lisp_true : nil);
    v0100 = v0096;
    v0096 = stack[-1];
    v0096 = qcdr(v0096);
    stack[-1] = v0096;
    v0096 = v0116;
    v0096 = qcdr(v0096);
    v0116 = v0096;
    goto v0063;
// error exit handlers
v0020:
    popv(3);
    return nil;
}



// Code for getmat

static LispObject CC_getmat(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0079, v0055, v0056;
    LispObject fn;
    LispObject v0017, v0018, v0002;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "getmat");
    va_start(aa, nargs);
    v0002 = va_arg(aa, LispObject);
    v0018 = va_arg(aa, LispObject);
    v0017 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for getmat");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0017,v0018,v0002);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0002,v0018,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0017;
    stack[-1] = v0018;
    stack[-2] = v0002;
// end of prologue
    v0079 = qvalue(elt(env, 1)); // !*modular
    if (v0079 == nil) goto v0006;
    v0079 = elt(env, 2); // modular
    v0079 = ncons(v0079);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-3];
    fn = elt(env, 6); // off
    v0079 = (*qfn1(fn))(qenv(fn), v0079);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-3];
    v0079 = elt(env, 3); // mod_was_on
    v0079 = ncons(v0079);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-3];
    fn = elt(env, 7); // on
    v0079 = (*qfn1(fn))(qenv(fn), v0079);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-3];
    goto v0006;

v0006:
    v0079 = stack[-1];
    v0079 = integerp(v0079);
    if (v0079 == nil) goto v0087;
    v0079 = stack[-1];
    goto v0025;

v0025:
    stack[-1] = v0079;
    v0079 = stack[0];
    v0079 = integerp(v0079);
    if (v0079 == nil) goto v0072;
    v0079 = stack[0];
    goto v0033;

v0033:
    stack[0] = v0079;
    v0079 = qvalue(elt(env, 5)); // !*mod_was_on
    if (v0079 == nil) goto v0023;
    v0079 = elt(env, 2); // modular
    v0079 = ncons(v0079);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-3];
    fn = elt(env, 7); // on
    v0079 = (*qfn1(fn))(qenv(fn), v0079);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-3];
    v0079 = elt(env, 3); // mod_was_on
    v0079 = ncons(v0079);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-3];
    fn = elt(env, 6); // off
    v0079 = (*qfn1(fn))(qenv(fn), v0079);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-3];
    goto v0023;

v0023:
    v0056 = stack[-2];
    v0055 = stack[-1];
    v0079 = stack[0];
    v0079 = list3(v0056, v0055, v0079);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-3];
    {
        popv(4);
        fn = elt(env, 8); // unchecked_getmatelem
        return (*qfn1(fn))(qenv(fn), v0079);
    }

v0072:
    v0079 = stack[0];
    fn = elt(env, 9); // reval
    v0079 = (*qfn1(fn))(qenv(fn), v0079);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-3];
    goto v0033;

v0087:
    v0079 = stack[-1];
    fn = elt(env, 9); // reval
    v0079 = (*qfn1(fn))(qenv(fn), v0079);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-3];
    goto v0025;
// error exit handlers
v0126:
    popv(4);
    return nil;
}



// Code for dipprodin1

static LispObject CC_dipprodin1(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0038, v0037;
    LispObject fn;
    LispObject v0017, v0018, v0002;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "dipprodin1");
    va_start(aa, nargs);
    v0002 = va_arg(aa, LispObject);
    v0018 = va_arg(aa, LispObject);
    v0017 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dipprodin1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0017,v0018,v0002);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0002,v0018,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0017;
    stack[-1] = v0018;
    stack[-2] = v0002;
// end of prologue
    stack[-3] = nil;
    goto v0075;

v0075:
    v0038 = stack[0];
    if (v0038 == nil) goto v0063;
    v0037 = stack[-1];
    v0038 = stack[0];
    v0038 = qcar(v0038);
    fn = elt(env, 2); // evsum
    v0037 = (*qfn2(fn))(qenv(fn), v0037, v0038);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-4];
    v0038 = stack[-3];
    v0038 = cons(v0037, v0038);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-4];
    stack[-3] = v0038;
    v0037 = stack[-2];
    v0038 = stack[0];
    v0038 = qcdr(v0038);
    v0038 = qcar(v0038);
    fn = elt(env, 3); // bcprod
    v0037 = (*qfn2(fn))(qenv(fn), v0037, v0038);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-4];
    v0038 = stack[-3];
    v0038 = cons(v0037, v0038);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-4];
    stack[-3] = v0038;
    v0038 = stack[0];
    v0038 = qcdr(v0038);
    v0038 = qcdr(v0038);
    stack[0] = v0038;
    goto v0075;

v0063:
    v0037 = stack[-3];
    v0038 = qvalue(elt(env, 1)); // dipzero
    {
        popv(5);
        fn = elt(env, 4); // nreverse
        return (*qfn2(fn))(qenv(fn), v0037, v0038);
    }
// error exit handlers
v0108:
    popv(5);
    return nil;
}



// Code for sc_minussq

static LispObject CC_sc_minussq(LispObject env,
                         LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0006;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sc_minussq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0006 = v0002;
// end of prologue
    v0006 = qcar(v0006);
    {
        fn = elt(env, 1); // minusf
        return (*qfn1(fn))(qenv(fn), v0006);
    }
}



// Code for vevdif

static LispObject CC_vevdif(LispObject env,
                         LispObject v0002, LispObject v0018)
{
    LispObject nil = C_nil;
    LispObject v0149, v0150, v0151;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vevdif");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0018,v0002);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0002,v0018);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    stack[-3] = v0018;
    stack[-4] = v0002;
// end of prologue
    stack[-5] = nil;
    v0150 = nil;
    v0149 = stack[-4];
    stack[-1] = v0149;
    v0149 = stack[-3];
    stack[0] = v0149;
    goto v0063;

v0063:
    v0149 = stack[-1];
    if (v0149 == nil) goto v0065;
    v0149 = stack[0];
    if (v0149 == nil) goto v0065;
    v0149 = v0150;
    if (!(v0149 == nil)) goto v0065;
    v0149 = stack[-1];
    v0150 = qcar(v0149);
    v0149 = stack[0];
    v0149 = qcar(v0149);
    v0149 = (LispObject)(int32_t)((int32_t)v0150 - (int32_t)v0149 + TAG_FIXNUM);
    stack[-2] = v0149;
    v0150 = stack[-2];
    v0149 = stack[-5];
    v0149 = cons(v0150, v0149);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-6];
    stack[-5] = v0149;
    v0150 = stack[-2];
    v0149 = (LispObject)1; // 0
    v0149 = ((intptr_t)v0150 < (intptr_t)v0149) ? lisp_true : nil;
    v0150 = v0149;
    v0149 = stack[-1];
    v0149 = qcdr(v0149);
    stack[-1] = v0149;
    v0149 = stack[0];
    v0149 = qcdr(v0149);
    stack[0] = v0149;
    goto v0063;

v0065:
    v0149 = v0150;
    if (!(v0149 == nil)) goto v0038;
    v0149 = stack[0];
    if (v0149 == nil) goto v0123;
    v0149 = stack[0];
    if (v0149 == nil) goto v0179;
    v0149 = stack[0];
    v0150 = qcar(v0149);
    v0149 = (LispObject)1; // 0
    if (v0150 == v0149) goto v0058;
    v0149 = qvalue(elt(env, 1)); // nil
    goto v0126;

v0126:
    if (!(v0149 == nil)) goto v0123;

v0038:
    v0149 = stack[-4];
    v0149 = Lprint(nil, v0149);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-6];
    v0149 = stack[-3];
    v0149 = Lprint(nil, v0149);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-6];
    v0149 = elt(env, 3); // backtrace
    fn = elt(env, 6); // getd
    v0149 = (*qfn1(fn))(qenv(fn), v0149);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-6];
    if (v0149 == nil) goto v0124;
    fn = elt(env, 3); // backtrace
    v0149 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-6];
    goto v0124;

v0124:
    v0151 = elt(env, 4); // dipoly
    v0150 = (LispObject)81; // 5
    v0149 = elt(env, 5); // "Vevdif, difference would be < 0"
    {
        popv(7);
        fn = elt(env, 7); // rerror
        return (*qfnn(fn))(qenv(fn), 3, v0151, v0150, v0149);
    }

v0123:
    v0149 = stack[-5];
    v0150 = Lnreverse(nil, v0149);
    v0149 = stack[-1];
        popv(7);
        return Lnconc(nil, v0150, v0149);

v0058:
    v0149 = stack[0];
    v0149 = qcdr(v0149);
    fn = elt(env, 8); // vevzero!?1
    v0149 = (*qfn1(fn))(qenv(fn), v0149);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-6];
    goto v0126;

v0179:
    v0149 = qvalue(elt(env, 2)); // t
    goto v0126;
// error exit handlers
v0178:
    popv(7);
    return nil;
}



// Code for evalneq

static LispObject CC_evalneq(LispObject env,
                         LispObject v0002, LispObject v0018)
{
    LispObject nil = C_nil;
    LispObject v0103, v0065;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evalneq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0018,v0002);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0002,v0018);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
// copy arguments values to proper place
    v0103 = v0018;
    v0065 = v0002;
// end of prologue
    fn = elt(env, 1); // evalequal
    v0103 = (*qfn2(fn))(qenv(fn), v0065, v0103);
    errexit();
    v0103 = (v0103 == nil ? lisp_true : nil);
    return onevalue(v0103);
}



// Code for lengthcdr

static LispObject CC_lengthcdr(LispObject env,
                         LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0006;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lengthcdr");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0006 = v0002;
// end of prologue
    v0006 = qcdr(v0006);
        return Llength(nil, v0006);
}



// Code for mo_neg

static LispObject CC_mo_neg(LispObject env,
                         LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0155;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mo_neg");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0002);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-2] = v0002;
// end of prologue
    v0155 = stack[-2];
    v0155 = qcar(v0155);
    stack[-4] = v0155;
    v0155 = stack[-4];
    if (v0155 == nil) goto v0026;
    v0155 = stack[-4];
    v0155 = qcar(v0155);
    v0155 = negate(v0155);
    nil = C_nil;
    if (exception_pending()) goto v0044;
    env = stack[-5];
    v0155 = ncons(v0155);
    nil = C_nil;
    if (exception_pending()) goto v0044;
    env = stack[-5];
    stack[-1] = v0155;
    stack[-3] = v0155;
    goto v0065;

v0065:
    v0155 = stack[-4];
    v0155 = qcdr(v0155);
    stack[-4] = v0155;
    v0155 = stack[-4];
    if (v0155 == nil) goto v0050;
    stack[0] = stack[-1];
    v0155 = stack[-4];
    v0155 = qcar(v0155);
    v0155 = negate(v0155);
    nil = C_nil;
    if (exception_pending()) goto v0044;
    env = stack[-5];
    v0155 = ncons(v0155);
    nil = C_nil;
    if (exception_pending()) goto v0044;
    env = stack[-5];
    v0155 = Lrplacd(nil, stack[0], v0155);
    nil = C_nil;
    if (exception_pending()) goto v0044;
    env = stack[-5];
    v0155 = stack[-1];
    v0155 = qcdr(v0155);
    stack[-1] = v0155;
    goto v0065;

v0050:
    v0155 = stack[-3];
    stack[-4] = v0155;
    goto v0006;

v0006:
    v0155 = stack[-2];
    v0155 = qcdr(v0155);
    stack[-3] = v0155;
    v0155 = stack[-3];
    if (v0155 == nil) goto v0078;
    v0155 = stack[-3];
    v0155 = qcar(v0155);
    v0155 = negate(v0155);
    nil = C_nil;
    if (exception_pending()) goto v0044;
    env = stack[-5];
    v0155 = ncons(v0155);
    nil = C_nil;
    if (exception_pending()) goto v0044;
    env = stack[-5];
    stack[-1] = v0155;
    stack[-2] = v0155;
    goto v0069;

v0069:
    v0155 = stack[-3];
    v0155 = qcdr(v0155);
    stack[-3] = v0155;
    v0155 = stack[-3];
    if (v0155 == nil) goto v0081;
    stack[0] = stack[-1];
    v0155 = stack[-3];
    v0155 = qcar(v0155);
    v0155 = negate(v0155);
    nil = C_nil;
    if (exception_pending()) goto v0044;
    env = stack[-5];
    v0155 = ncons(v0155);
    nil = C_nil;
    if (exception_pending()) goto v0044;
    env = stack[-5];
    v0155 = Lrplacd(nil, stack[0], v0155);
    nil = C_nil;
    if (exception_pending()) goto v0044;
    env = stack[-5];
    v0155 = stack[-1];
    v0155 = qcdr(v0155);
    stack[-1] = v0155;
    goto v0069;

v0081:
    v0155 = stack[-2];
    goto v0097;

v0097:
    {
        LispObject v0009 = stack[-4];
        popv(6);
        return cons(v0009, v0155);
    }

v0078:
    v0155 = qvalue(elt(env, 1)); // nil
    goto v0097;

v0026:
    v0155 = qvalue(elt(env, 1)); // nil
    stack[-4] = v0155;
    goto v0006;
// error exit handlers
v0044:
    popv(6);
    return nil;
}



// Code for gperm3

static LispObject CC_gperm3(LispObject env,
                         LispObject v0002, LispObject v0018)
{
    LispObject nil = C_nil;
    LispObject v0117, v0049, v0050;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gperm3");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0018,v0002);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0002,v0018);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0049 = v0018;
    v0117 = v0002;
// end of prologue

v0097:
    v0050 = v0117;
    if (v0050 == nil) { popv(2); return onevalue(v0049); }
    v0050 = v0117;
    v0050 = qcdr(v0050);
    stack[0] = v0050;
    v0050 = v0049;
    v0049 = qcar(v0117);
    v0117 = qvalue(elt(env, 1)); // nil
    fn = elt(env, 2); // gperm2
    v0117 = (*qfnn(fn))(qenv(fn), 3, v0050, v0049, v0117);
    nil = C_nil;
    if (exception_pending()) goto v0072;
    env = stack[-1];
    v0049 = v0117;
    v0117 = stack[0];
    goto v0097;
// error exit handlers
v0072:
    popv(2);
    return nil;
}



// Code for noncomperm

static LispObject CC_noncomperm(LispObject env,
                         LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0125, v0098, v0137;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for noncomperm");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0002);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    stack[-4] = v0002;
// end of prologue
    v0125 = stack[-4];
    if (v0125 == nil) goto v0005;
    v0125 = stack[-4];
    stack[-5] = v0125;
    goto v0048;

v0048:
    v0125 = stack[-5];
    if (v0125 == nil) goto v0083;
    v0125 = stack[-5];
    v0125 = qcar(v0125);
    stack[0] = v0125;
    v0098 = stack[0];
    v0125 = stack[-4];
    fn = elt(env, 3); // noncomdel
    v0125 = (*qfn2(fn))(qenv(fn), v0098, v0125);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    env = stack[-6];
    v0137 = v0125;
    v0098 = v0137;
    v0125 = elt(env, 2); // failed
    if (v0098 == v0125) goto v0096;
    v0125 = v0137;
    v0098 = CC_noncomperm(env, v0125);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    env = stack[-6];
    v0125 = stack[0];
    fn = elt(env, 4); // mapcons
    v0125 = (*qfn2(fn))(qenv(fn), v0098, v0125);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    env = stack[-6];
    goto v0064;

v0064:
    stack[-3] = v0125;
    v0125 = stack[-3];
    fn = elt(env, 5); // lastpair
    v0125 = (*qfn1(fn))(qenv(fn), v0125);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    env = stack[-6];
    stack[-2] = v0125;
    v0125 = stack[-5];
    v0125 = qcdr(v0125);
    stack[-5] = v0125;
    v0125 = stack[-2];
    if (!consp(v0125)) goto v0048;
    else goto v0025;

v0025:
    v0125 = stack[-5];
    if (v0125 == nil) { LispObject res = stack[-3]; popv(7); return onevalue(res); }
    stack[-1] = stack[-2];
    v0125 = stack[-5];
    v0125 = qcar(v0125);
    stack[0] = v0125;
    v0098 = stack[0];
    v0125 = stack[-4];
    fn = elt(env, 3); // noncomdel
    v0125 = (*qfn2(fn))(qenv(fn), v0098, v0125);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    env = stack[-6];
    v0137 = v0125;
    v0098 = v0137;
    v0125 = elt(env, 2); // failed
    if (v0098 == v0125) goto v0090;
    v0125 = v0137;
    v0098 = CC_noncomperm(env, v0125);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    env = stack[-6];
    v0125 = stack[0];
    fn = elt(env, 4); // mapcons
    v0125 = (*qfn2(fn))(qenv(fn), v0098, v0125);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    env = stack[-6];
    goto v0060;

v0060:
    v0125 = Lrplacd(nil, stack[-1], v0125);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    env = stack[-6];
    v0125 = stack[-2];
    fn = elt(env, 5); // lastpair
    v0125 = (*qfn1(fn))(qenv(fn), v0125);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    env = stack[-6];
    stack[-2] = v0125;
    v0125 = stack[-5];
    v0125 = qcdr(v0125);
    stack[-5] = v0125;
    goto v0025;

v0090:
    v0125 = qvalue(elt(env, 1)); // nil
    goto v0060;

v0096:
    v0125 = qvalue(elt(env, 1)); // nil
    goto v0064;

v0083:
    v0125 = qvalue(elt(env, 1)); // nil
    { popv(7); return onevalue(v0125); }

v0005:
    v0125 = stack[-4];
    popv(7);
    return ncons(v0125);
// error exit handlers
v0138:
    popv(7);
    return nil;
}



// Code for diff

static LispObject CC_diff(LispObject env,
                         LispObject v0002, LispObject v0018)
{
    LispObject nil = C_nil;
    LispObject v0154, v0124;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for diff");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0018,v0002);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0002,v0018);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-2] = v0018;
    stack[-3] = v0002;
// end of prologue
    stack[-4] = nil;
    goto v0075;

v0075:
    v0154 = stack[-3];
    if (!consp(v0154)) goto v0048;
    v0154 = stack[-3];
    v0154 = qcar(v0154);
    v0154 = (consp(v0154) ? nil : lisp_true);
    goto v0047;

v0047:
    if (v0154 == nil) goto v0021;
    v0154 = qvalue(elt(env, 2)); // nil
    v0124 = v0154;
    goto v0061;

v0061:
    v0154 = stack[-4];
    if (v0154 == nil) { popv(6); return onevalue(v0124); }
    v0154 = stack[-4];
    v0154 = qcar(v0154);
    fn = elt(env, 3); // addf
    v0154 = (*qfn2(fn))(qenv(fn), v0154, v0124);
    nil = C_nil;
    if (exception_pending()) goto v0012;
    env = stack[-5];
    v0124 = v0154;
    v0154 = stack[-4];
    v0154 = qcdr(v0154);
    stack[-4] = v0154;
    goto v0061;

v0021:
    v0154 = stack[-3];
    v0154 = qcar(v0154);
    v0124 = qcar(v0154);
    v0154 = (LispObject)17; // 1
    v0154 = cons(v0124, v0154);
    nil = C_nil;
    if (exception_pending()) goto v0012;
    env = stack[-5];
    stack[0] = ncons(v0154);
    nil = C_nil;
    if (exception_pending()) goto v0012;
    env = stack[-5];
    v0154 = stack[-3];
    v0154 = qcar(v0154);
    v0124 = qcdr(v0154);
    v0154 = stack[-2];
    v0154 = CC_diff(env, v0124, v0154);
    nil = C_nil;
    if (exception_pending()) goto v0012;
    env = stack[-5];
    fn = elt(env, 4); // multf
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[0], v0154);
    nil = C_nil;
    if (exception_pending()) goto v0012;
    env = stack[-5];
    v0154 = stack[-3];
    v0154 = qcar(v0154);
    stack[0] = qcdr(v0154);
    v0154 = stack[-3];
    v0154 = qcar(v0154);
    v0124 = qcar(v0154);
    v0154 = stack[-2];
    fn = elt(env, 5); // diffp1
    v0154 = (*qfn2(fn))(qenv(fn), v0124, v0154);
    nil = C_nil;
    if (exception_pending()) goto v0012;
    env = stack[-5];
    fn = elt(env, 4); // multf
    v0154 = (*qfn2(fn))(qenv(fn), stack[0], v0154);
    nil = C_nil;
    if (exception_pending()) goto v0012;
    env = stack[-5];
    fn = elt(env, 3); // addf
    v0124 = (*qfn2(fn))(qenv(fn), stack[-1], v0154);
    nil = C_nil;
    if (exception_pending()) goto v0012;
    env = stack[-5];
    v0154 = stack[-4];
    v0154 = cons(v0124, v0154);
    nil = C_nil;
    if (exception_pending()) goto v0012;
    env = stack[-5];
    stack[-4] = v0154;
    v0154 = stack[-3];
    v0154 = qcdr(v0154);
    stack[-3] = v0154;
    goto v0075;

v0048:
    v0154 = qvalue(elt(env, 1)); // t
    goto v0047;
// error exit handlers
v0012:
    popv(6);
    return nil;
}



// Code for ibalp_simpatom

static LispObject CC_ibalp_simpatom(LispObject env,
                         LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0147, v0012;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_simpatom");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0002);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0002;
// end of prologue
    v0012 = stack[0];
    v0147 = (LispObject)1; // 0
    if (v0012 == v0147) goto v0106;
    v0012 = stack[0];
    v0147 = (LispObject)17; // 1
    v0147 = (v0012 == v0147 ? lisp_true : nil);
    goto v0051;

v0051:
    if (!(v0147 == nil)) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    v0147 = stack[0];
    if (symbolp(v0147)) goto v0072;
    v0147 = stack[0];
    if (!(v0147 == nil)) goto v0062;
    v0012 = elt(env, 3); // "nil"
    v0147 = elt(env, 4); // "Boolean term"
    fn = elt(env, 7); // typerr
    v0147 = (*qfn2(fn))(qenv(fn), v0012, v0147);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-1];
    goto v0062;

v0062:
    v0147 = stack[0];
    if (!(is_number(v0147))) goto v0121;
    v0012 = elt(env, 5); // "number"
    v0147 = stack[0];
    v0012 = list2(v0012, v0147);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-1];
    v0147 = elt(env, 4); // "Boolean term"
    fn = elt(env, 7); // typerr
    v0147 = (*qfn2(fn))(qenv(fn), v0012, v0147);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-1];
    goto v0121;

v0121:
    v0147 = stack[0];
    v0147 = Lstringp(nil, v0147);
    env = stack[-1];
    if (v0147 == nil) goto v0120;
    v0012 = elt(env, 6); // "string"
    v0147 = stack[0];
    v0012 = list2(v0012, v0147);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-1];
    v0147 = elt(env, 4); // "Boolean term"
    fn = elt(env, 7); // typerr
    v0147 = (*qfn2(fn))(qenv(fn), v0012, v0147);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    goto v0120;

v0120:
    v0147 = nil;
    { popv(2); return onevalue(v0147); }

v0072:
    v0147 = stack[0];
    fn = elt(env, 8); // rl_gettype
    v0147 = (*qfn1(fn))(qenv(fn), v0147);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-1];
    if (v0147 == nil) goto v0113;
    v0147 = stack[0];
    fn = elt(env, 9); // reval
    v0147 = (*qfn1(fn))(qenv(fn), v0147);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 10); // ibalp_simpterm
        return (*qfn1(fn))(qenv(fn), v0147);
    }

v0113:
    v0147 = stack[0];
    v0012 = ncons(v0147);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-1];
    v0147 = elt(env, 2); // used!*
    v0147 = Lflag(nil, v0012, v0147);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    { LispObject res = stack[0]; popv(2); return onevalue(res); }

v0106:
    v0147 = qvalue(elt(env, 1)); // t
    goto v0051;
// error exit handlers
v0042:
    popv(2);
    return nil;
}



// Code for mathml2

static LispObject CC_mathml2(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0097;
    LispObject fn;
    argcheck(nargs, 0, "mathml2");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mathml2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// end of prologue
    {
        fn = elt(env, 2); // sub_math
        return (*qfnn(fn))(qenv(fn), 0);
    }
}



// Code for formclis

static LispObject CC_formclis(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0057, v0094, v0064;
    LispObject fn;
    LispObject v0017, v0018, v0002;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "formclis");
    va_start(aa, nargs);
    v0002 = va_arg(aa, LispObject);
    v0018 = va_arg(aa, LispObject);
    v0017 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for formclis");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0017,v0018,v0002);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0002,v0018,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0017;
    stack[-1] = v0018;
    stack[-2] = v0002;
// end of prologue
    stack[-3] = nil;
    goto v0075;

v0075:
    v0057 = stack[-2];
    if (v0057 == nil) goto v0051;
    v0057 = stack[-2];
    v0064 = qcar(v0057);
    v0094 = stack[-1];
    v0057 = stack[0];
    fn = elt(env, 1); // formc
    v0094 = (*qfnn(fn))(qenv(fn), 3, v0064, v0094, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    env = stack[-4];
    v0057 = stack[-3];
    v0057 = cons(v0094, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    env = stack[-4];
    stack[-3] = v0057;
    v0057 = stack[-2];
    v0057 = qcdr(v0057);
    stack[-2] = v0057;
    goto v0075;

v0051:
    v0057 = stack[-3];
    {
        popv(5);
        fn = elt(env, 2); // reversip!*
        return (*qfn1(fn))(qenv(fn), v0057);
    }
// error exit handlers
v0071:
    popv(5);
    return nil;
}



// Code for rmplus

static LispObject CC_rmplus(LispObject env,
                         LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0107, v0083, v0089;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rmplus");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0083 = v0002;
// end of prologue
    v0107 = v0083;
    v0089 = elt(env, 1); // plus
    if (!consp(v0107)) goto v0048;
    v0107 = qcar(v0107);
    if (!(v0107 == v0089)) goto v0048;
    v0107 = v0083;
    v0107 = qcdr(v0107);
    return onevalue(v0107);

v0048:
    v0107 = v0083;
    return ncons(v0107);
}



// Code for dp_times_bcmo

static LispObject CC_dp_times_bcmo(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0120, v0118;
    LispObject fn;
    LispObject v0017, v0018, v0002;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "dp_times_bcmo");
    va_start(aa, nargs);
    v0002 = va_arg(aa, LispObject);
    v0018 = va_arg(aa, LispObject);
    v0017 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dp_times_bcmo");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0017,v0018,v0002);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0002,v0018,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
// copy arguments values to proper place
    v0120 = v0017;
    stack[-5] = v0018;
    stack[-6] = v0002;
// end of prologue
    stack[-7] = v0120;
    v0120 = stack[-7];
    if (v0120 == nil) goto v0065;
    v0120 = stack[-7];
    v0120 = qcar(v0120);
    stack[-1] = v0120;
    v0118 = stack[-5];
    v0120 = stack[-1];
    v0120 = qcar(v0120);
    fn = elt(env, 2); // mo_sum
    stack[0] = (*qfn2(fn))(qenv(fn), v0118, v0120);
    nil = C_nil;
    if (exception_pending()) goto v0044;
    env = stack[-8];
    v0118 = stack[-6];
    v0120 = stack[-1];
    v0120 = qcdr(v0120);
    fn = elt(env, 3); // cali_bc_prod
    v0120 = (*qfn2(fn))(qenv(fn), v0118, v0120);
    nil = C_nil;
    if (exception_pending()) goto v0044;
    env = stack[-8];
    v0120 = cons(stack[0], v0120);
    nil = C_nil;
    if (exception_pending()) goto v0044;
    env = stack[-8];
    v0120 = ncons(v0120);
    nil = C_nil;
    if (exception_pending()) goto v0044;
    env = stack[-8];
    stack[-3] = v0120;
    stack[-4] = v0120;
    goto v0061;

v0061:
    v0120 = stack[-7];
    v0120 = qcdr(v0120);
    stack[-7] = v0120;
    v0120 = stack[-7];
    if (v0120 == nil) { LispObject res = stack[-4]; popv(9); return onevalue(res); }
    stack[-2] = stack[-3];
    v0120 = stack[-7];
    v0120 = qcar(v0120);
    stack[-1] = v0120;
    v0118 = stack[-5];
    v0120 = stack[-1];
    v0120 = qcar(v0120);
    fn = elt(env, 2); // mo_sum
    stack[0] = (*qfn2(fn))(qenv(fn), v0118, v0120);
    nil = C_nil;
    if (exception_pending()) goto v0044;
    env = stack[-8];
    v0118 = stack[-6];
    v0120 = stack[-1];
    v0120 = qcdr(v0120);
    fn = elt(env, 3); // cali_bc_prod
    v0120 = (*qfn2(fn))(qenv(fn), v0118, v0120);
    nil = C_nil;
    if (exception_pending()) goto v0044;
    env = stack[-8];
    v0120 = cons(stack[0], v0120);
    nil = C_nil;
    if (exception_pending()) goto v0044;
    env = stack[-8];
    v0120 = ncons(v0120);
    nil = C_nil;
    if (exception_pending()) goto v0044;
    env = stack[-8];
    v0120 = Lrplacd(nil, stack[-2], v0120);
    nil = C_nil;
    if (exception_pending()) goto v0044;
    env = stack[-8];
    v0120 = stack[-3];
    v0120 = qcdr(v0120);
    stack[-3] = v0120;
    goto v0061;

v0065:
    v0120 = qvalue(elt(env, 1)); // nil
    { popv(9); return onevalue(v0120); }
// error exit handlers
v0044:
    popv(9);
    return nil;
}



// Code for pv_intequiv

static LispObject CC_pv_intequiv(LispObject env,
                         LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0065, v0063;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pv_intequiv");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0063 = v0002;
// end of prologue
    v0065 = v0063;
    v0065 = qcdr(v0065);
    if (!consp(v0065)) goto v0005;
    v0065 = qvalue(elt(env, 1)); // nil
    return onevalue(v0065);

v0005:
    v0065 = v0063;
    v0065 = qcdr(v0065);
    return onevalue(v0065);
}



// Code for qqe_ofsf_simplat1

static LispObject CC_qqe_ofsf_simplat1(LispObject env,
                         LispObject v0002, LispObject v0018)
{
    LispObject nil = C_nil;
    LispObject v0116, v0100;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qqe_ofsf_simplat1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0018,v0002);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0002,v0018);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0018;
    stack[-1] = v0002;
// end of prologue
    v0100 = stack[-1];
    v0116 = stack[0];
    fn = elt(env, 2); // qqe_simplat1
    v0116 = (*qfn2(fn))(qenv(fn), v0100, v0116);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    env = stack[-3];
    stack[-2] = v0116;
    v0100 = stack[-2];
    v0116 = elt(env, 1); // (true false)
    v0116 = Lmemq(nil, v0100, v0116);
    if (!(v0116 == nil)) { LispObject res = stack[-2]; popv(4); return onevalue(res); }
    v0116 = stack[-1];
    fn = elt(env, 3); // qqe_op
    v0116 = (*qfn1(fn))(qenv(fn), v0116);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    env = stack[-3];
    fn = elt(env, 4); // qqe_rqopp
    v0116 = (*qfn1(fn))(qenv(fn), v0116);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    env = stack[-3];
    if (!(v0116 == nil)) { LispObject res = stack[-2]; popv(4); return onevalue(res); }
    v0100 = stack[-2];
    v0116 = stack[0];
    {
        popv(4);
        fn = elt(env, 5); // ofsf_simplat1
        return (*qfn2(fn))(qenv(fn), v0100, v0116);
    }
// error exit handlers
v0021:
    popv(4);
    return nil;
}



// Code for xread

static LispObject CC_xread(LispObject env,
                         LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0089, v0087;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for xread");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0002);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0002;
// end of prologue

v0005:
    fn = elt(env, 4); // scan
    v0089 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[-1];
    v0089 = qvalue(elt(env, 1)); // !*eoldelimp
    if (v0089 == nil) goto v0075;
    v0087 = qvalue(elt(env, 2)); // cursym!*
    v0089 = elt(env, 3); // !*semicol!*
    if (v0087 == v0089) goto v0005;
    else goto v0075;

v0075:
    v0089 = stack[0];
    {
        popv(2);
        fn = elt(env, 5); // xread1
        return (*qfn1(fn))(qenv(fn), v0089);
    }
// error exit handlers
v0099:
    popv(2);
    return nil;
}



// Code for aex_varl

static LispObject CC_aex_varl(LispObject env,
                         LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0097;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for aex_varl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0002);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// copy arguments values to proper place
    v0097 = v0002;
// end of prologue
    fn = elt(env, 1); // aex_ex
    v0097 = (*qfn1(fn))(qenv(fn), v0097);
    nil = C_nil;
    if (exception_pending()) goto v0075;
    env = stack[0];
    v0097 = qcar(v0097);
    {
        popv(1);
        fn = elt(env, 2); // kernels
        return (*qfn1(fn))(qenv(fn), v0097);
    }
// error exit handlers
v0075:
    popv(1);
    return nil;
}



// Code for bc2a

static LispObject CC_bc2a(LispObject env,
                         LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0103, v0065;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for bc2a");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0065 = v0002;
// end of prologue
    v0103 = qvalue(elt(env, 1)); // !*grmod!*
    if (!(v0103 == nil)) return onevalue(v0065);
    v0103 = v0065;
    {
        fn = elt(env, 2); // prepsq
        return (*qfn1(fn))(qenv(fn), v0103);
    }
}



// Code for evenfree

static LispObject CC_evenfree(LispObject env,
                         LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0020, v0021;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evenfree");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0002);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0002;
// end of prologue
    v0020 = stack[0];
    if (v0020 == nil) goto v0005;
    v0020 = stack[0];
    if (is_number(v0020)) goto v0065;
    v0020 = stack[0];
    v0020 = qcar(v0020);
    v0021 = ncons(v0020);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-2];
    v0020 = (LispObject)33; // 2
    fn = elt(env, 2); // qremd
    v0020 = (*qfn2(fn))(qenv(fn), v0021, v0020);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-2];
    v0020 = qcdr(v0020);
    fn = elt(env, 3); // absf
    stack[-1] = (*qfn1(fn))(qenv(fn), v0020);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-2];
    v0020 = stack[0];
    v0020 = qcdr(v0020);
    v0020 = CC_evenfree(env, v0020);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-2];
    {
        LispObject v0115 = stack[-1];
        popv(3);
        fn = elt(env, 4); // addf
        return (*qfn2(fn))(qenv(fn), v0115, v0020);
    }

v0065:
    v0021 = stack[0];
    v0020 = (LispObject)33; // 2
    fn = elt(env, 2); // qremd
    v0020 = (*qfn2(fn))(qenv(fn), v0021, v0020);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-2];
    v0020 = qcdr(v0020);
    {
        popv(3);
        fn = elt(env, 3); // absf
        return (*qfn1(fn))(qenv(fn), v0020);
    }

v0005:
    v0020 = qvalue(elt(env, 1)); // nil
    { popv(3); return onevalue(v0020); }
// error exit handlers
v0102:
    popv(3);
    return nil;
}



setup_type const u11_setup[] =
{
    {"subs3f1",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_subs3f1},
    {"mkzl",                    CC_mkzl,        too_many_1,    wrong_no_1},
    {"intexprnp",               too_few_2,      CC_intexprnp,  wrong_no_2},
    {"rat_numrn",               CC_rat_numrn,   too_many_1,    wrong_no_1},
    {"poly-abs",                CC_polyKabs,    too_many_1,    wrong_no_1},
    {"sub_math",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_sub_math},
    {"vevlcm",                  too_few_2,      CC_vevlcm,     wrong_no_2},
    {"vdpzero",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_vdpzero},
    {"mksgnsq",                 CC_mksgnsq,     too_many_1,    wrong_no_1},
    {"*kp2f",                   too_few_2,      CC_Hkp2f,      wrong_no_2},
    {"assert_typesyntaxp",      CC_assert_typesyntaxp,too_many_1,wrong_no_1},
    {"simptimes",               CC_simptimes,   too_many_1,    wrong_no_1},
    {"red-ratios1",             too_few_2,      CC_redKratios1,wrong_no_2},
    {"pdif",                    too_few_2,      CC_pdif,       wrong_no_2},
    {"artimes:",                too_few_2,      CC_artimesT,   wrong_no_2},
    {"qqe_arg-check-b",         CC_qqe_argKcheckKb,too_many_1, wrong_no_1},
    {"rl_susitf",               too_few_2,      CC_rl_susitf,  wrong_no_2},
    {"sfto_mvartest",           too_few_2,      CC_sfto_mvartest,wrong_no_2},
    {"powers1",                 CC_powers1,     too_many_1,    wrong_no_1},
    {"terpri*",                 CC_terpriH,     too_many_1,    wrong_no_1},
    {"rd:minus",                CC_rdTminus,    too_many_1,    wrong_no_1},
    {"spquotematrix",           CC_spquotematrix,too_many_1,   wrong_no_1},
    {"wedget2",                 too_few_2,      CC_wedget2,    wrong_no_2},
    {"gfrsq",                   CC_gfrsq,       too_many_1,    wrong_no_1},
    {"fortranop",               CC_fortranop,   too_many_1,    wrong_no_1},
    {"deletemult*",             CC_deletemultH, too_many_1,    wrong_no_1},
    {"rnconc",                  too_few_2,      CC_rnconc,     wrong_no_2},
    {"aminusp:",                CC_aminuspT,    too_many_1,    wrong_no_1},
    {"pv_times3",               too_few_2,      CC_pv_times3,  wrong_no_2},
    {"freeof",                  too_few_2,      CC_freeof,     wrong_no_2},
    {"qqe_ofsf_varlterm",       too_few_2,      CC_qqe_ofsf_varlterm,wrong_no_2},
    {"rl_smcpknowl",            CC_rl_smcpknowl,too_many_1,    wrong_no_1},
    {"ibalp_hassimple",         CC_ibalp_hassimple,too_many_1, wrong_no_1},
    {"unbind",                  CC_unbind,      too_many_1,    wrong_no_1},
    {"groebcpcompless?",        too_few_2,      CC_groebcpcomplessW,wrong_no_2},
    {"assert_dyntypep",         CC_assert_dyntypep,too_many_1, wrong_no_1},
    {"mo=revlexcomp",           too_few_2,      CC_moMrevlexcomp,wrong_no_2},
    {"wtchk",                   too_few_2,      CC_wtchk,      wrong_no_2},
    {"qqe_qprefix-var",         CC_qqe_qprefixKvar,too_many_1, wrong_no_1},
    {"quotodd",                 too_few_2,      CC_quotodd,    wrong_no_2},
    {"ps:prepfn:",              CC_psTprepfnT,  too_many_1,    wrong_no_1},
    {"minusp:",                 CC_minuspT,     too_many_1,    wrong_no_1},
    {"listdiff",                too_few_2,      CC_listdiff,   wrong_no_2},
    {"set-ordp",                too_few_2,      CC_setKordp,   wrong_no_2},
    {"scalopp",                 CC_scalopp,     too_many_1,    wrong_no_1},
    {"form",                    CC_form,        too_many_1,    wrong_no_1},
    {"red-ratios2",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_redKratios2},
    {"cali_bc_zero?",           CC_cali_bc_zeroW,too_many_1,   wrong_no_1},
    {"dd",                      too_few_2,      CC_dd,         wrong_no_2},
    {"general-modular-reciprocal",CC_generalKmodularKreciprocal,too_many_1,wrong_no_1},
    {"horner-rule",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_hornerKrule},
    {"ckrn",                    CC_ckrn,        too_many_1,    wrong_no_1},
    {"rl_negateat",             CC_rl_negateat, too_many_1,    wrong_no_1},
    {"rl_simpbop",              CC_rl_simpbop,  too_many_1,    wrong_no_1},
    {"numeric-content",         CC_numericKcontent,too_many_1, wrong_no_1},
    {"ps:get-term",             too_few_2,      CC_psTgetKterm,wrong_no_2},
    {"isimplicit",              CC_isimplicit,  too_many_1,    wrong_no_1},
    {"getmat",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_getmat},
    {"dipprodin1",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_dipprodin1},
    {"sc_minussq",              CC_sc_minussq,  too_many_1,    wrong_no_1},
    {"vevdif",                  too_few_2,      CC_vevdif,     wrong_no_2},
    {"evalneq",                 too_few_2,      CC_evalneq,    wrong_no_2},
    {"lengthcdr",               CC_lengthcdr,   too_many_1,    wrong_no_1},
    {"mo_neg",                  CC_mo_neg,      too_many_1,    wrong_no_1},
    {"gperm3",                  too_few_2,      CC_gperm3,     wrong_no_2},
    {"noncomperm",              CC_noncomperm,  too_many_1,    wrong_no_1},
    {"diff",                    too_few_2,      CC_diff,       wrong_no_2},
    {"ibalp_simpatom",          CC_ibalp_simpatom,too_many_1,  wrong_no_1},
    {"mathml2",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_mathml2},
    {"formclis",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_formclis},
    {"rmplus",                  CC_rmplus,      too_many_1,    wrong_no_1},
    {"dp_times_bcmo",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_dp_times_bcmo},
    {"pv_intequiv",             CC_pv_intequiv, too_many_1,    wrong_no_1},
    {"qqe_ofsf_simplat1",       too_few_2,      CC_qqe_ofsf_simplat1,wrong_no_2},
    {"xread",                   CC_xread,       too_many_1,    wrong_no_1},
    {"aex_varl",                CC_aex_varl,    too_many_1,    wrong_no_1},
    {"bc2a",                    CC_bc2a,        too_many_1,    wrong_no_1},
    {"evenfree",                CC_evenfree,    too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u11", (two_args *)"17841 6914617 8124126", 0}
};

// end of generated code
