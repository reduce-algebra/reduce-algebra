
// $destdir/u33.c        Machine generated C code

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



// Code for fnreval

static LispObject CC_fnreval(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0025, v0026;
    LispObject fn;
    LispObject v0005, v0007, v0006;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "fnreval");
    va_start(aa, nargs);
    v0006 = va_arg(aa, LispObject);
    v0007 = va_arg(aa, LispObject);
    v0005 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for fnreval");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0005,v0007,v0006);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0006,v0007,v0005);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    stack[-4] = v0005;
    stack[-1] = v0007;
    stack[0] = v0006;
// end of prologue
    stack[-2] = nil;
    goto v0027;

v0027:
    v0025 = stack[0];
    if (v0025 == nil) goto v0028;
    v0026 = stack[-1];
    v0025 = qvalue(elt(env, 1)); // t
    if (v0026 == v0025) goto v0029;
    v0025 = stack[-1];
    if (v0025 == nil) goto v0030;
    v0025 = stack[-1];
    v0025 = qcar(v0025);
    if (v0025 == nil) goto v0031;
    v0025 = stack[0];
    v0025 = qcar(v0025);
    v0026 = v0025;
    goto v0032;

v0032:
    v0025 = stack[-2];
    v0025 = cons(v0026, v0025);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[-6];
    stack[-2] = v0025;
    v0025 = stack[0];
    v0025 = qcdr(v0025);
    stack[0] = v0025;
    v0025 = stack[-1];
    v0025 = qcdr(v0025);
    stack[-1] = v0025;
    goto v0027;

v0031:
    v0025 = stack[0];
    v0026 = qcar(v0025);
    v0025 = stack[-4];
    fn = elt(env, 3); // reval1
    v0025 = (*qfn2(fn))(qenv(fn), v0026, v0025);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[-6];
    v0026 = v0025;
    goto v0032;

v0030:
    stack[-5] = stack[-2];
    v0025 = stack[0];
    stack[-3] = v0025;
    v0025 = stack[-3];
    if (v0025 == nil) goto v0034;
    v0025 = stack[-3];
    v0025 = qcar(v0025);
    v0026 = v0025;
    v0025 = stack[-4];
    fn = elt(env, 3); // reval1
    v0025 = (*qfn2(fn))(qenv(fn), v0026, v0025);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[-6];
    v0025 = ncons(v0025);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[-6];
    stack[-1] = v0025;
    stack[-2] = v0025;
    goto v0035;

v0035:
    v0025 = stack[-3];
    v0025 = qcdr(v0025);
    stack[-3] = v0025;
    v0025 = stack[-3];
    if (v0025 == nil) goto v0036;
    stack[0] = stack[-1];
    v0025 = stack[-3];
    v0025 = qcar(v0025);
    v0026 = v0025;
    v0025 = stack[-4];
    fn = elt(env, 3); // reval1
    v0025 = (*qfn2(fn))(qenv(fn), v0026, v0025);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[-6];
    v0025 = ncons(v0025);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[-6];
    v0025 = Lrplacd(nil, stack[0], v0025);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[-6];
    v0025 = stack[-1];
    v0025 = qcdr(v0025);
    stack[-1] = v0025;
    goto v0035;

v0036:
    v0025 = stack[-2];
    goto v0037;

v0037:
    {
        LispObject v0038 = stack[-5];
        popv(7);
        fn = elt(env, 4); // nreverse
        return (*qfn2(fn))(qenv(fn), v0038, v0025);
    }

v0034:
    v0025 = qvalue(elt(env, 2)); // nil
    goto v0037;

v0029:
    v0026 = stack[-2];
    v0025 = stack[0];
    {
        popv(7);
        fn = elt(env, 4); // nreverse
        return (*qfn2(fn))(qenv(fn), v0026, v0025);
    }

v0028:
    v0025 = stack[-2];
    {
        popv(7);
        fn = elt(env, 4); // nreverse
        return (*qfn1(fn))(qenv(fn), v0025);
    }
// error exit handlers
v0033:
    popv(7);
    return nil;
}



// Code for evinsert

static LispObject CC_evinsert(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0019, v0048, v0049;
    LispObject fn;
    LispObject v0046, v0005, v0007, v0006;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "evinsert");
    va_start(aa, nargs);
    v0006 = va_arg(aa, LispObject);
    v0007 = va_arg(aa, LispObject);
    v0005 = va_arg(aa, LispObject);
    v0046 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evinsert");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0046,v0005,v0007,v0006);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0006,v0007,v0005,v0046);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0046;
    stack[-1] = v0005;
    stack[-2] = v0007;
    stack[-3] = v0006;
// end of prologue
    v0049 = nil;
    goto v0050;

v0050:
    v0019 = stack[-3];
    if (v0019 == nil) goto v0051;
    v0019 = stack[0];
    v0019 = (v0019 == nil ? lisp_true : nil);
    goto v0052;

v0052:
    if (v0019 == nil) goto v0053;
    v0019 = v0049;
    {
        popv(5);
        fn = elt(env, 2); // nreverse
        return (*qfn1(fn))(qenv(fn), v0019);
    }

v0053:
    v0019 = stack[0];
    v0048 = qcar(v0019);
    v0019 = stack[-2];
    if (equal(v0048, v0019)) goto v0030;
    v0019 = stack[-3];
    v0019 = qcar(v0019);
    v0048 = v0049;
    v0019 = cons(v0019, v0048);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-4];
    v0049 = v0019;
    v0019 = stack[-3];
    v0019 = qcdr(v0019);
    stack[-3] = v0019;
    v0019 = stack[0];
    v0019 = qcdr(v0019);
    stack[0] = v0019;
    goto v0050;

v0030:
    stack[0] = v0049;
    v0048 = stack[-1];
    v0019 = stack[-3];
    v0019 = qcdr(v0019);
    v0019 = cons(v0048, v0019);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-4];
    {
        LispObject v0055 = stack[0];
        popv(5);
        fn = elt(env, 2); // nreverse
        return (*qfn2(fn))(qenv(fn), v0055, v0019);
    }

v0051:
    v0019 = qvalue(elt(env, 1)); // t
    goto v0052;
// error exit handlers
v0054:
    popv(5);
    return nil;
}



// Code for weak_xreduce1

static LispObject CC_weak_xreduce1(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0077, v0078, v0079;
    LispObject fn;
    LispObject v0005, v0007, v0006;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "weak_xreduce1");
    va_start(aa, nargs);
    v0006 = va_arg(aa, LispObject);
    v0007 = va_arg(aa, LispObject);
    v0005 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for weak_xreduce1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0005,v0007,v0006);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0006,v0007,v0005);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
// copy arguments values to proper place
    stack[-3] = v0005;
    stack[-4] = v0007;
    stack[-5] = v0006;
// end of prologue
    v0077 = stack[-4];
    stack[0] = v0077;
    goto v0052;

v0052:
    v0077 = stack[-5];
    if (v0077 == nil) { LispObject res = stack[-5]; popv(8); return onevalue(res); }
    v0077 = stack[0];
    if (v0077 == nil) { LispObject res = stack[-5]; popv(8); return onevalue(res); }
    v0077 = stack[0];
    v0077 = qcar(v0077);
    stack[-6] = v0077;
    v0077 = stack[0];
    v0077 = qcdr(v0077);
    stack[0] = v0077;
    v0077 = stack[-6];
    fn = elt(env, 8); // xval
    stack[-1] = (*qfn1(fn))(qenv(fn), v0077);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-7];
    v0077 = stack[-5];
    fn = elt(env, 8); // xval
    v0077 = (*qfn1(fn))(qenv(fn), v0077);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-7];
    fn = elt(env, 9); // xdiv
    v0077 = (*qfn2(fn))(qenv(fn), stack[-1], v0077);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-7];
    stack[-1] = v0077;
    if (v0077 == nil) goto v0052;
    v0077 = stack[-1];
    fn = elt(env, 10); // mknwedge
    v0079 = (*qfn1(fn))(qenv(fn), v0077);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-7];
    v0078 = (LispObject)17; // 1
    v0077 = (LispObject)17; // 1
    v0077 = list2star(v0079, v0078, v0077);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-7];
    v0077 = ncons(v0077);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-7];
    stack[-1] = v0077;
    v0078 = stack[-1];
    v0077 = stack[-6];
    fn = elt(env, 11); // wedgepf
    v0077 = (*qfn2(fn))(qenv(fn), v0078, v0077);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-7];
    stack[0] = v0077;
    v0077 = stack[-5];
    v0077 = qcar(v0077);
    v0078 = qcdr(v0077);
    v0077 = stack[0];
    v0077 = qcar(v0077);
    v0077 = qcdr(v0077);
    fn = elt(env, 12); // quotsq
    v0077 = (*qfn2(fn))(qenv(fn), v0078, v0077);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-7];
    stack[-2] = v0077;
    v0077 = stack[-2];
    fn = elt(env, 13); // negsq
    v0077 = (*qfn1(fn))(qenv(fn), v0077);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-7];
    fn = elt(env, 14); // multpfsq
    v0077 = (*qfn2(fn))(qenv(fn), stack[0], v0077);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-7];
    fn = elt(env, 15); // addpf
    v0077 = (*qfn2(fn))(qenv(fn), stack[-5], v0077);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-7];
    fn = elt(env, 16); // subs2pf
    v0077 = (*qfn1(fn))(qenv(fn), v0077);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-7];
    stack[-5] = v0077;
    v0077 = qvalue(elt(env, 2)); // !*trxmod
    if (v0077 == nil) goto v0081;
    stack[0] = stack[-3];
    v0078 = stack[-1];
    v0077 = stack[-2];
    fn = elt(env, 14); // multpfsq
    v0078 = (*qfn2(fn))(qenv(fn), v0078, v0077);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-7];
    v0077 = stack[-6];
    v0077 = list2(v0078, v0077);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-7];
    v0077 = ncons(v0077);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-7];
    v0077 = Lnconc(nil, stack[0], v0077);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-7];
    stack[-3] = v0077;
    goto v0081;

v0081:
    v0077 = qvalue(elt(env, 2)); // !*trxmod
    if (v0077 == nil) goto v0082;
    v0078 = elt(env, 3); // "   "
    v0077 = elt(env, 4); // first
    fn = elt(env, 17); // writepri
    v0077 = (*qfn2(fn))(qenv(fn), v0078, v0077);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-7];
    stack[0] = elt(env, 5); // wedge
    v0078 = stack[-1];
    v0077 = stack[-2];
    fn = elt(env, 14); // multpfsq
    v0077 = (*qfn2(fn))(qenv(fn), v0078, v0077);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-7];
    fn = elt(env, 18); // preppf
    stack[-1] = (*qfn1(fn))(qenv(fn), v0077);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-7];
    v0077 = stack[-6];
    fn = elt(env, 18); // preppf
    v0077 = (*qfn1(fn))(qenv(fn), v0077);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-7];
    v0077 = list3(stack[0], stack[-1], v0077);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-7];
    v0078 = Lmkquote(nil, v0077);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-7];
    v0077 = qvalue(elt(env, 1)); // nil
    fn = elt(env, 17); // writepri
    v0077 = (*qfn2(fn))(qenv(fn), v0078, v0077);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-7];
    v0078 = elt(env, 6); // " +"
    v0077 = elt(env, 7); // last
    fn = elt(env, 17); // writepri
    v0077 = (*qfn2(fn))(qenv(fn), v0078, v0077);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-7];
    goto v0082;

v0082:
    v0077 = stack[-4];
    stack[0] = v0077;
    goto v0052;
// error exit handlers
v0080:
    popv(8);
    return nil;
}



// Code for formbool

static LispObject CC_formbool(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0128, v0129, v0130, v0131, v0132;
    LispObject fn;
    LispObject v0005, v0007, v0006;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "formbool");
    va_start(aa, nargs);
    v0006 = va_arg(aa, LispObject);
    v0007 = va_arg(aa, LispObject);
    v0005 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for formbool");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0005,v0007,v0006);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0006,v0007,v0005);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    stack[-2] = v0005;
    stack[-3] = v0007;
    stack[-4] = v0006;
// end of prologue
    v0129 = stack[-2];
    v0128 = elt(env, 1); // symbolic
    if (v0129 == v0128) goto v0133;
    v0128 = stack[-4];
    if (!consp(v0128)) goto v0044;
    v0128 = stack[-4];
    v0129 = qcdr(v0128);
    v0128 = stack[-3];
    fn = elt(env, 10); // intexprlisp
    v0128 = (*qfn2(fn))(qenv(fn), v0129, v0128);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-6];
    if (v0128 == nil) goto v0135;
    v0128 = stack[-4];
    v0129 = qcar(v0128);
    v0128 = elt(env, 4); // boolfn
    v0128 = get(v0129, v0128);
    env = stack[-6];
    if (!(v0128 == nil)) { LispObject res = stack[-4]; popv(7); return onevalue(res); }

v0135:
    v0128 = stack[-4];
    v0128 = qcar(v0128);
    if (!(symbolp(v0128))) goto v0136;
    v0128 = stack[-4];
    v0129 = qcar(v0128);
    v0128 = elt(env, 4); // boolfn
    v0128 = get(v0129, v0128);
    env = stack[-6];
    if (v0128 == nil) goto v0136;
    v0128 = stack[-4];
    v0129 = qcar(v0128);
    v0128 = elt(env, 4); // boolfn
    stack[0] = get(v0129, v0128);
    env = stack[-6];
    v0128 = stack[-4];
    v0130 = qcdr(v0128);
    v0129 = stack[-3];
    v0128 = stack[-2];
    fn = elt(env, 11); // formclis
    v0128 = (*qfnn(fn))(qenv(fn), 3, v0130, v0129, v0128);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    {
        LispObject v0137 = stack[0];
        popv(7);
        return cons(v0137, v0128);
    }

v0136:
    v0128 = stack[-4];
    v0128 = qcar(v0128);
    if (!(symbolp(v0128))) goto v0138;
    v0128 = stack[-4];
    v0129 = qcar(v0128);
    v0128 = elt(env, 5); // boolean
    v0128 = Lflagp(nil, v0129, v0128);
    env = stack[-6];
    if (v0128 == nil) goto v0138;
    v0128 = stack[-4];
    stack[0] = qcar(v0128);
    v0128 = stack[-4];
    v0132 = qcdr(v0128);
    v0131 = stack[-3];
    v0130 = stack[-2];
    v0128 = stack[-4];
    v0129 = qcar(v0128);
    v0128 = elt(env, 6); // boolargs
    v0128 = Lflagp(nil, v0129, v0128);
    env = stack[-6];
    fn = elt(env, 12); // formboollis
    v0128 = (*qfnn(fn))(qenv(fn), 4, v0132, v0131, v0130, v0128);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    {
        LispObject v0139 = stack[0];
        popv(7);
        return cons(v0139, v0128);
    }

v0138:
    v0128 = stack[-4];
    v0129 = qcar(v0128);
    v0128 = elt(env, 3); // boolvalue!*
    if (v0129 == v0128) goto v0140;
    v0128 = stack[-4];
    v0129 = qcar(v0128);
    v0128 = elt(env, 8); // where
    if (v0129 == v0128) goto v0141;
    stack[0] = elt(env, 3); // boolvalue!*
    v0130 = stack[-4];
    v0129 = stack[-3];
    v0128 = stack[-2];
    fn = elt(env, 13); // formc!*
    v0128 = (*qfnn(fn))(qenv(fn), 3, v0130, v0129, v0128);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    {
        LispObject v0142 = stack[0];
        popv(7);
        return list2(v0142, v0128);
    }

v0141:
    stack[-5] = elt(env, 3); // boolvalue!*
    stack[-1] = elt(env, 8); // where
    stack[0] = elt(env, 9); // bool!-eval
    v0128 = stack[-4];
    v0128 = qcdr(v0128);
    v0130 = qcar(v0128);
    v0129 = stack[-3];
    v0128 = stack[-2];
    v0128 = CC_formbool(env, 3, v0130, v0129, v0128);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-6];
    v0128 = list2(stack[0], v0128);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-6];
    v0129 = Lmkquote(nil, v0128);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-6];
    v0128 = stack[-4];
    v0128 = qcdr(v0128);
    v0128 = qcdr(v0128);
    v0128 = qcar(v0128);
    v0130 = list3(stack[-1], v0129, v0128);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-6];
    v0129 = stack[-3];
    v0128 = stack[-2];
    fn = elt(env, 13); // formc!*
    v0128 = (*qfnn(fn))(qenv(fn), 3, v0130, v0129, v0128);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    {
        LispObject v0143 = stack[-5];
        popv(7);
        return list2(v0143, v0128);
    }

v0140:
    v0128 = elt(env, 7); // "Too many formbools"
    {
        popv(7);
        fn = elt(env, 14); // rederr
        return (*qfn1(fn))(qenv(fn), v0128);
    }

v0044:
    v0129 = stack[-4];
    v0128 = lisp_true;
    if (v0129 == v0128) { LispObject res = stack[-4]; popv(7); return onevalue(res); }
    v0128 = stack[-4];
    if (symbolp(v0128)) goto v0034;
    v0128 = qvalue(elt(env, 2)); // t
    goto v0016;

v0016:
    if (v0128 == nil) goto v0144;
    v0129 = elt(env, 3); // boolvalue!*
    v0128 = stack[-4];
    popv(7);
    return list2(v0129, v0128);

v0144:
    stack[0] = elt(env, 3); // boolvalue!*
    v0130 = stack[-4];
    v0129 = stack[-3];
    v0128 = stack[-2];
    fn = elt(env, 13); // formc!*
    v0128 = (*qfnn(fn))(qenv(fn), 3, v0130, v0129, v0128);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    {
        LispObject v0145 = stack[0];
        popv(7);
        return list2(v0145, v0128);
    }

v0034:
    v0129 = stack[-4];
    v0128 = stack[-3];
    v0128 = Latsoc(nil, v0129, v0128);
    goto v0016;

v0133:
    v0130 = stack[-4];
    v0129 = stack[-3];
    v0128 = stack[-2];
    {
        popv(7);
        fn = elt(env, 15); // formc
        return (*qfnn(fn))(qenv(fn), 3, v0130, v0129, v0128);
    }
// error exit handlers
v0134:
    popv(7);
    return nil;
}



// Code for gcdf2

static LispObject CC_gcdf2(LispObject env,
                         LispObject v0006, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0174, v0175, v0176;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gcdf2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0007,v0006);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0006,v0007);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
// copy arguments values to proper place
    stack[-4] = v0007;
    stack[-5] = v0006;
// end of prologue
    stack[-6] = qvalue(elt(env, 1)); // asymplis!*
    qvalue(elt(env, 1)) = nil; // asymplis!*
    v0174 = qvalue(elt(env, 2)); // !*anygcd
    if (v0174 == nil) goto v0052;
    v0174 = stack[-5];
    fn = elt(env, 6); // num!-exponents
    v0174 = (*qfn1(fn))(qenv(fn), v0174);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-7];
    if (v0174 == nil) goto v0024;
    v0174 = stack[-4];
    fn = elt(env, 6); // num!-exponents
    v0174 = (*qfn1(fn))(qenv(fn), v0174);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-7];
    v0174 = (v0174 == nil ? lisp_true : nil);
    goto v0047;

v0047:
    if (v0174 == nil) goto v0178;
    v0174 = (LispObject)17; // 1
    goto v0027;

v0027:
    qvalue(elt(env, 1)) = stack[-6]; // asymplis!*
    { popv(8); return onevalue(v0174); }

v0178:
    v0174 = qvalue(elt(env, 4)); // !*gcd
    if (v0174 == nil) goto v0179;
    v0175 = stack[-5];
    v0174 = stack[-4];
    fn = elt(env, 7); // kernord
    v0174 = (*qfn2(fn))(qenv(fn), v0175, v0174);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-7];
    stack[-3] = v0174;
    v0175 = Llength(nil, v0174);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-7];
    v0174 = (LispObject)17; // 1
    v0174 = (LispObject)greaterp2(v0175, v0174);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    v0174 = v0174 ? lisp_true : nil;
    env = stack[-7];
    if (v0174 == nil) goto v0179;
    v0174 = stack[-3];
    fn = elt(env, 8); // setkorder
    v0174 = (*qfn1(fn))(qenv(fn), v0174);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-7];
    v0174 = ncons(v0174);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-7];
    stack[-3] = v0174;
    v0174 = stack[-5];
    fn = elt(env, 9); // reorder
    v0174 = (*qfn1(fn))(qenv(fn), v0174);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-7];
    stack[-5] = v0174;
    v0174 = stack[-4];
    fn = elt(env, 9); // reorder
    v0174 = (*qfn1(fn))(qenv(fn), v0174);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-7];
    stack[-4] = v0174;
    goto v0144;

v0144:
    v0174 = stack[-5];
    v0174 = qcar(v0174);
    v0174 = qcar(v0174);
    v0175 = qcar(v0174);
    v0174 = stack[-4];
    v0174 = qcar(v0174);
    v0174 = qcar(v0174);
    v0174 = qcar(v0174);
    if (v0175 == v0174) goto v0049;
    v0174 = stack[-5];
    v0174 = qcar(v0174);
    v0174 = qcar(v0174);
    v0174 = qcar(v0174);
    fn = elt(env, 10); // noncomp
    v0174 = (*qfn1(fn))(qenv(fn), v0174);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-7];
    if (v0174 == nil) goto v0180;
    v0174 = stack[-4];
    v0174 = qcar(v0174);
    v0174 = qcar(v0174);
    v0174 = qcar(v0174);
    fn = elt(env, 10); // noncomp
    v0174 = (*qfn1(fn))(qenv(fn), v0174);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-7];
    if (v0174 == nil) goto v0180;
    v0176 = stack[-5];
    v0175 = stack[-4];
    v0174 = stack[-4];
    v0174 = qcar(v0174);
    v0174 = qcar(v0174);
    v0174 = qcar(v0174);
    fn = elt(env, 11); // gcdfnc
    v0174 = (*qfnn(fn))(qenv(fn), 3, v0176, v0175, v0174);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-7];
    stack[-2] = v0174;
    goto v0048;

v0048:
    v0174 = stack[-3];
    if (v0174 == nil) goto v0181;
    v0174 = stack[-3];
    v0174 = qcar(v0174);
    fn = elt(env, 8); // setkorder
    v0174 = (*qfn1(fn))(qenv(fn), v0174);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-7];
    v0174 = stack[-2];
    fn = elt(env, 9); // reorder
    v0174 = (*qfn1(fn))(qenv(fn), v0174);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-7];
    stack[-2] = v0174;
    goto v0181;

v0181:
    v0174 = stack[-2];
    goto v0027;

v0180:
    v0174 = stack[-5];
    v0174 = qcar(v0174);
    v0174 = qcar(v0174);
    v0175 = qcar(v0174);
    v0174 = stack[-4];
    v0174 = qcar(v0174);
    v0174 = qcar(v0174);
    v0174 = qcar(v0174);
    fn = elt(env, 12); // ordop
    v0174 = (*qfn2(fn))(qenv(fn), v0175, v0174);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-7];
    if (v0174 == nil) goto v0182;
    v0174 = stack[-5];
    fn = elt(env, 13); // comfac
    v0174 = (*qfn1(fn))(qenv(fn), v0174);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-7];
    v0175 = qcdr(v0174);
    v0174 = stack[-4];
    fn = elt(env, 14); // gcdf1
    v0174 = (*qfn2(fn))(qenv(fn), v0175, v0174);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-7];
    stack[-2] = v0174;
    goto v0048;

v0182:
    v0174 = stack[-4];
    fn = elt(env, 13); // comfac
    v0174 = (*qfn1(fn))(qenv(fn), v0174);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-7];
    v0175 = qcdr(v0174);
    v0174 = stack[-5];
    fn = elt(env, 14); // gcdf1
    v0174 = (*qfn2(fn))(qenv(fn), v0175, v0174);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-7];
    stack[-2] = v0174;
    goto v0048;

v0049:
    v0174 = stack[-5];
    fn = elt(env, 13); // comfac
    v0174 = (*qfn1(fn))(qenv(fn), v0174);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-7];
    stack[-1] = v0174;
    v0174 = stack[-4];
    fn = elt(env, 13); // comfac
    v0174 = (*qfn1(fn))(qenv(fn), v0174);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-7];
    stack[0] = v0174;
    v0174 = stack[-1];
    v0175 = qcdr(v0174);
    v0174 = stack[0];
    v0174 = qcdr(v0174);
    fn = elt(env, 14); // gcdf1
    v0174 = (*qfn2(fn))(qenv(fn), v0175, v0174);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-7];
    stack[-2] = v0174;
    v0174 = stack[-1];
    fn = elt(env, 15); // comfac!-to!-poly
    v0174 = (*qfn1(fn))(qenv(fn), v0174);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-7];
    fn = elt(env, 16); // quotf1
    v0174 = (*qfn2(fn))(qenv(fn), stack[-5], v0174);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-7];
    stack[-5] = v0174;
    v0174 = stack[0];
    fn = elt(env, 15); // comfac!-to!-poly
    v0174 = (*qfn1(fn))(qenv(fn), v0174);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-7];
    fn = elt(env, 16); // quotf1
    v0174 = (*qfn2(fn))(qenv(fn), stack[-4], v0174);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-7];
    stack[-4] = v0174;
    v0174 = qvalue(elt(env, 4)); // !*gcd
    if (v0174 == nil) goto v0004;
    v0175 = stack[-5];
    v0174 = stack[-4];
    fn = elt(env, 17); // gcdk
    v0175 = (*qfn2(fn))(qenv(fn), v0175, v0174);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-7];
    v0174 = stack[-2];
    fn = elt(env, 18); // multf
    v0174 = (*qfn2(fn))(qenv(fn), v0175, v0174);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-7];
    stack[-2] = v0174;
    goto v0183;

v0183:
    v0174 = stack[-1];
    v0174 = qcar(v0174);
    if (v0174 == nil) goto v0048;
    v0174 = stack[0];
    v0174 = qcar(v0174);
    if (v0174 == nil) goto v0048;
    v0174 = stack[-1];
    v0174 = qcar(v0174);
    v0175 = qcdr(v0174);
    v0174 = stack[0];
    v0174 = qcar(v0174);
    v0174 = qcdr(v0174);
    v0174 = (LispObject)greaterp2(v0175, v0174);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    v0174 = v0174 ? lisp_true : nil;
    env = stack[-7];
    if (v0174 == nil) goto v0184;
    v0174 = stack[0];
    v0175 = qcar(v0174);
    v0174 = (LispObject)17; // 1
    v0174 = cons(v0175, v0174);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-7];
    v0175 = ncons(v0174);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-7];
    v0174 = stack[-2];
    fn = elt(env, 18); // multf
    v0174 = (*qfn2(fn))(qenv(fn), v0175, v0174);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-7];
    stack[-2] = v0174;
    goto v0048;

v0184:
    v0174 = stack[-1];
    v0175 = qcar(v0174);
    v0174 = (LispObject)17; // 1
    v0174 = cons(v0175, v0174);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-7];
    v0175 = ncons(v0174);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-7];
    v0174 = stack[-2];
    fn = elt(env, 18); // multf
    v0174 = (*qfn2(fn))(qenv(fn), v0175, v0174);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-7];
    stack[-2] = v0174;
    goto v0048;

v0004:
    v0174 = stack[-4];
    if (v0174 == nil) goto v0114;
    v0175 = stack[-5];
    v0174 = stack[-4];
    fn = elt(env, 16); // quotf1
    v0174 = (*qfn2(fn))(qenv(fn), v0175, v0174);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-7];
    if (v0174 == nil) goto v0114;
    v0175 = stack[-4];
    v0174 = stack[-2];
    fn = elt(env, 18); // multf
    v0174 = (*qfn2(fn))(qenv(fn), v0175, v0174);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-7];
    stack[-2] = v0174;
    goto v0183;

v0114:
    v0174 = stack[-5];
    if (v0174 == nil) goto v0183;
    v0175 = stack[-4];
    v0174 = stack[-5];
    fn = elt(env, 16); // quotf1
    v0174 = (*qfn2(fn))(qenv(fn), v0175, v0174);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-7];
    if (v0174 == nil) goto v0183;
    v0175 = stack[-5];
    v0174 = stack[-2];
    fn = elt(env, 18); // multf
    v0174 = (*qfn2(fn))(qenv(fn), v0175, v0174);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-7];
    stack[-2] = v0174;
    goto v0183;

v0179:
    v0174 = qvalue(elt(env, 5)); // nil
    stack[-3] = v0174;
    goto v0144;

v0024:
    v0174 = qvalue(elt(env, 3)); // t
    goto v0047;

v0052:
    v0174 = qvalue(elt(env, 3)); // t
    goto v0047;
// error exit handlers
v0177:
    env = stack[-7];
    qvalue(elt(env, 1)) = stack[-6]; // asymplis!*
    popv(8);
    return nil;
}



// Code for pa_list2vect

static LispObject CC_pa_list2vect(LispObject env,
                         LispObject v0006, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0195, v0196;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pa_list2vect");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0007,v0006);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0006,v0007);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
// copy arguments values to proper place
    stack[-5] = v0007;
    stack[0] = v0006;
// end of prologue
    stack[-4] = nil;
    v0195 = (LispObject)1; // 0
    stack[-3] = v0195;
    v0195 = stack[-5];
    v0195 = sub1(v0195);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-7];
    v0195 = Lmkvect(nil, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-7];
    stack[-6] = v0195;
    v0195 = stack[0];
    stack[-2] = v0195;
    goto v0051;

v0051:
    v0195 = stack[-2];
    if (v0195 == nil) goto v0052;
    v0195 = stack[-2];
    v0195 = qcar(v0195);
    stack[0] = v0195;
    v0196 = elt(env, 2); // min
    v0195 = stack[0];
    v0195 = cons(v0196, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-7];
    fn = elt(env, 3); // eval
    v0196 = (*qfn1(fn))(qenv(fn), v0195);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-7];
    v0195 = stack[-4];
    v0195 = cons(v0196, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-7];
    stack[-4] = v0195;
    v0195 = stack[0];
    stack[-1] = v0195;
    goto v0009;

v0009:
    v0195 = stack[-1];
    if (v0195 == nil) goto v0016;
    v0195 = stack[-1];
    v0195 = qcar(v0195);
    stack[0] = stack[-6];
    v0196 = sub1(v0195);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-7];
    v0195 = stack[-4];
    v0195 = qcar(v0195);
    *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0196/(16/CELL))) = v0195;
    v0195 = stack[-1];
    v0195 = qcdr(v0195);
    stack[-1] = v0195;
    goto v0009;

v0016:
    v0195 = stack[-2];
    v0195 = qcdr(v0195);
    stack[-2] = v0195;
    goto v0051;

v0052:
    v0195 = (LispObject)17; // 1
    stack[-1] = v0195;
    goto v0124;

v0124:
    v0196 = stack[-5];
    v0195 = stack[-1];
    v0195 = difference2(v0196, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-7];
    v0195 = Lminusp(nil, v0195);
    env = stack[-7];
    if (v0195 == nil) goto v0198;
    v0195 = stack[-4];
    v0196 = Lreverse(nil, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    v0195 = stack[-6];
    popv(8);
    return cons(v0196, v0195);

v0198:
    stack[0] = stack[-6];
    v0195 = stack[-1];
    v0195 = sub1(v0195);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-7];
    v0195 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0195/(16/CELL)));
    if (!(v0195 == nil)) goto v0013;
    v0196 = stack[-3];
    v0195 = (LispObject)1; // 0
    if (!(v0196 == v0195)) goto v0082;
    v0195 = stack[-1];
    stack[-3] = v0195;
    v0196 = stack[-3];
    v0195 = stack[-4];
    v0195 = cons(v0196, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-7];
    stack[-4] = v0195;
    goto v0082;

v0082:
    stack[0] = stack[-6];
    v0195 = stack[-1];
    v0196 = sub1(v0195);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-7];
    v0195 = stack[-3];
    *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0196/(16/CELL))) = v0195;
    goto v0013;

v0013:
    v0195 = stack[-1];
    v0195 = add1(v0195);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-7];
    stack[-1] = v0195;
    goto v0124;
// error exit handlers
v0197:
    popv(8);
    return nil;
}



// Code for get!-current!-representation

static LispObject CC_getKcurrentKrepresentation(LispObject env,
                         LispObject v0006)
{
    LispObject nil = C_nil;
    LispObject v0028, v0199;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for get-current-representation");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0028 = v0006;
// end of prologue
    v0199 = elt(env, 1); // currep
    return get(v0028, v0199);
}



// Code for read!-comment1

static LispObject CC_readKcomment1(LispObject env,
                         LispObject v0006)
{
    LispObject nil = C_nil;
    LispObject v0200, v0170;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for read-comment1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0006);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0006);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    v0200 = v0006;
// end of prologue
    stack[-1] = qvalue(elt(env, 1)); // !*lower
    qvalue(elt(env, 1)) = nil; // !*lower
    stack[0] = qvalue(elt(env, 2)); // !*raise
    qvalue(elt(env, 2)) = nil; // !*raise
    v0200 = qvalue(elt(env, 3)); // nil
    qvalue(elt(env, 4)) = v0200; // named!-character!*
    goto v0071;

v0071:
    v0200 = qvalue(elt(env, 4)); // named!-character!*
    if (!(v0200 == nil)) goto v0028;
    v0200 = qvalue(elt(env, 5)); // crchar!*
    fn = elt(env, 9); // id2string
    v0200 = (*qfn1(fn))(qenv(fn), v0200);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    env = stack[-2];
    fn = elt(env, 10); // string!-length
    v0170 = (*qfn1(fn))(qenv(fn), v0200);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    env = stack[-2];
    v0200 = (LispObject)17; // 1
    if (v0170 == v0200) goto v0201;
    v0200 = qvalue(elt(env, 6)); // t
    goto v0133;

v0133:
    if (!(v0200 == nil)) goto v0028;
    v0200 = elt(env, 8); // ! 
    qvalue(elt(env, 5)) = v0200; // crchar!*
    fn = elt(env, 11); // condterpri
    v0200 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    env = stack[-2];
    v0200 = nil;
    qvalue(elt(env, 2)) = stack[0]; // !*raise
    qvalue(elt(env, 1)) = stack[-1]; // !*lower
    { popv(3); return onevalue(v0200); }

v0028:
    v0200 = qvalue(elt(env, 3)); // nil
    qvalue(elt(env, 4)) = v0200; // named!-character!*
    fn = elt(env, 12); // readch1
    v0200 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    env = stack[-2];
    qvalue(elt(env, 5)) = v0200; // crchar!*
    goto v0071;

v0201:
    v0200 = qvalue(elt(env, 5)); // crchar!*
    fn = elt(env, 13); // delcp
    v0200 = (*qfn1(fn))(qenv(fn), v0200);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    env = stack[-2];
    if (v0200 == nil) goto v0044;
    v0170 = qvalue(elt(env, 5)); // crchar!*
    v0200 = qvalue(elt(env, 7)); // !$eol!$
    v0200 = (v0170 == v0200 ? lisp_true : nil);
    goto v0133;

v0044:
    v0200 = qvalue(elt(env, 6)); // t
    goto v0133;
// error exit handlers
v0125:
    env = stack[-2];
    qvalue(elt(env, 2)) = stack[0]; // !*raise
    qvalue(elt(env, 1)) = stack[-1]; // !*lower
    popv(3);
    return nil;
}



// Code for mri_2ofsfat

static LispObject CC_mri_2ofsfat(LispObject env,
                         LispObject v0006)
{
    LispObject nil = C_nil;
    LispObject v0051, v0133;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mri_2ofsfat");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0006);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0006);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0006;
// end of prologue
    v0051 = stack[0];
    fn = elt(env, 2); // mri_op
    stack[-1] = (*qfn1(fn))(qenv(fn), v0051);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-2];
    v0051 = stack[0];
    fn = elt(env, 3); // mri_arg2l
    v0051 = (*qfn1(fn))(qenv(fn), v0051);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-2];
    v0133 = qvalue(elt(env, 1)); // nil
    {
        LispObject v0173 = stack[-1];
        popv(3);
        return list3(v0173, v0051, v0133);
    }
// error exit handlers
v0202:
    popv(3);
    return nil;
}



// Code for repr_new

static LispObject CC_repr_new(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0126, v0037, v0076, v0008;
    LispObject fn;
    LispObject v0046, v0005, v0007, v0006;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "repr_new");
    va_start(aa, nargs);
    v0006 = va_arg(aa, LispObject);
    v0007 = va_arg(aa, LispObject);
    v0005 = va_arg(aa, LispObject);
    v0046 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for repr_new");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0046,v0005,v0007,v0006);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0006,v0007,v0005,v0046);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    v0126 = v0046;
    v0037 = v0005;
    v0076 = v0007;
    v0008 = v0006;
// end of prologue
    stack[-3] = v0008;
    stack[-2] = v0076;
    stack[-1] = v0037;
    stack[0] = v0126;
    v0126 = v0037;
    if (v0126 == nil) goto v0053;
    v0126 = v0037;
    v0126 = qcar(v0126);
    v0126 = qcdr(v0126);
    goto v0024;

v0024:
    v0126 = list2(stack[0], v0126);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    {
        LispObject v0035 = stack[-3];
        LispObject v0042 = stack[-2];
        LispObject v0205 = stack[-1];
        popv(5);
        return list3star(v0035, v0042, v0205, v0126);
    }

v0053:
    v0126 = elt(env, 1); // "repr_new : invalid coefficient list"
    v0126 = ncons(v0126);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-4];
    fn = elt(env, 2); // rederr
    v0126 = (*qfn1(fn))(qenv(fn), v0126);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-4];
    goto v0024;
// error exit handlers
v0169:
    popv(5);
    return nil;
}



// Code for transposerd

static LispObject CC_transposerd(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0203, v0204;
    LispObject fn;
    argcheck(nargs, 0, "transposerd");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for transposerd");
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
    fn = elt(env, 2); // mathml
    v0203 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    env = stack[-1];
    v0204 = elt(env, 1); // tp
    v0203 = list2(v0204, v0203);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    env = stack[-1];
    fn = elt(env, 3); // aeval
    v0203 = (*qfn1(fn))(qenv(fn), v0203);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    env = stack[-1];
    stack[0] = v0203;
    fn = elt(env, 4); // lex
    v0203 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    { LispObject res = stack[0]; popv(2); return onevalue(res); }
// error exit handlers
v0173:
    popv(2);
    return nil;
}



// Code for znumrnil

static LispObject CC_znumrnil(LispObject env,
                         LispObject v0006)
{
    LispObject nil = C_nil;
    LispObject v0202, v0173;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for znumrnil");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0006);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0006);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0006;
// end of prologue
    v0202 = stack[0];
    fn = elt(env, 2); // znumr
    v0202 = (*qfn1(fn))(qenv(fn), v0202);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-1];
    if (v0202 == nil) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    v0173 = qvalue(elt(env, 1)); // nil
    v0202 = (LispObject)17; // 1
    popv(2);
    return cons(v0173, v0202);
// error exit handlers
v0024:
    popv(2);
    return nil;
}



// Code for dip2a

static LispObject CC_dip2a(LispObject env,
                         LispObject v0006)
{
    LispObject nil = C_nil;
    LispObject v0047, v0052;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dip2a");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0006);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0006);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// copy arguments values to proper place
    v0052 = v0006;
// end of prologue
    v0047 = v0052;
    if (v0047 == nil) goto v0002;
    v0047 = v0052;
    fn = elt(env, 1); // dip2a1
    v0047 = (*qfn1(fn))(qenv(fn), v0047);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); // dipreplus
        return (*qfn1(fn))(qenv(fn), v0047);
    }

v0002:
    v0047 = (LispObject)1; // 0
    { popv(1); return onevalue(v0047); }
// error exit handlers
v0051:
    popv(1);
    return nil;
}



// Code for mod!-dump1

static LispObject CC_modKdump1(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0016, v0009, v0169;
    LispObject fn;
    LispObject v0005, v0007, v0006;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "mod-dump1");
    va_start(aa, nargs);
    v0006 = va_arg(aa, LispObject);
    v0007 = va_arg(aa, LispObject);
    v0005 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mod-dump1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0005,v0007,v0006);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0006,v0007,v0005);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0005;
    stack[-2] = v0007;
    stack[-3] = v0006;
// end of prologue
    stack[-4] = nil;
    goto v0027;

v0027:
    v0016 = stack[-1];
    if (v0016 == nil) goto v0028;
    v0016 = stack[-1];
    v0016 = qcar(v0016);
    stack[0] = qcar(v0016);
    v0169 = stack[-3];
    v0009 = stack[-2];
    v0016 = stack[-1];
    v0016 = qcar(v0016);
    v0016 = qcdr(v0016);
    fn = elt(env, 1); // l!-subst
    v0009 = (*qfnn(fn))(qenv(fn), 3, v0169, v0009, v0016);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-5];
    v0016 = stack[-4];
    v0016 = acons(stack[0], v0009, v0016);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-5];
    stack[-4] = v0016;
    v0016 = stack[-1];
    v0016 = qcdr(v0016);
    stack[-1] = v0016;
    goto v0027;

v0028:
    v0016 = stack[-4];
    {
        popv(6);
        fn = elt(env, 2); // nreverse
        return (*qfn1(fn))(qenv(fn), v0016);
    }
// error exit handlers
v0200:
    popv(6);
    return nil;
}



// Code for !*g2lex

static LispObject CC_Hg2lex(LispObject env,
                         LispObject v0006)
{
    LispObject nil = C_nil;
    LispObject v0008, v0015;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *g2lex");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0006);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0006);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    v0008 = v0006;
// end of prologue
    v0015 = nil;
    stack[-1] = v0008;
    goto v0050;

v0050:
    v0008 = stack[-1];
    if (v0008 == nil) { popv(3); return onevalue(v0015); }
    v0008 = stack[-1];
    v0008 = qcar(v0008);
    stack[0] = v0015;
    v0015 = v0008;
    v0015 = qcar(v0015);
    v0015 = qcdr(v0015);
    v0008 = qcdr(v0008);
    v0008 = cons(v0015, v0008);
    nil = C_nil;
    if (exception_pending()) goto v0009;
    env = stack[-2];
    v0008 = ncons(v0008);
    nil = C_nil;
    if (exception_pending()) goto v0009;
    env = stack[-2];
    fn = elt(env, 2); // psum
    v0008 = (*qfn2(fn))(qenv(fn), stack[0], v0008);
    nil = C_nil;
    if (exception_pending()) goto v0009;
    env = stack[-2];
    v0015 = v0008;
    v0008 = stack[-1];
    v0008 = qcdr(v0008);
    stack[-1] = v0008;
    goto v0050;
// error exit handlers
v0009:
    popv(3);
    return nil;
}



// Code for appn

static LispObject CC_appn(LispObject env,
                         LispObject v0006, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0205, v0043;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for appn");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0007,v0006);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0006,v0007);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0007;
    stack[-1] = v0006;
// end of prologue
    stack[-2] = nil;
    goto v0052;

v0052:
    v0043 = stack[0];
    v0205 = (LispObject)17; // 1
    if (v0043 == v0205) goto v0050;
    v0043 = stack[-1];
    v0205 = stack[-2];
    v0205 = cons(v0043, v0205);
    nil = C_nil;
    if (exception_pending()) goto v0171;
    env = stack[-3];
    stack[-2] = v0205;
    v0205 = stack[0];
    v0205 = sub1(v0205);
    nil = C_nil;
    if (exception_pending()) goto v0171;
    env = stack[-3];
    stack[0] = v0205;
    goto v0052;

v0050:
    v0205 = stack[-1];
    v0043 = v0205;
    goto v0178;

v0178:
    v0205 = stack[-2];
    if (v0205 == nil) { popv(4); return onevalue(v0043); }
    v0205 = stack[-2];
    v0205 = qcar(v0205);
    v0205 = Lappend(nil, v0205, v0043);
    nil = C_nil;
    if (exception_pending()) goto v0171;
    env = stack[-3];
    v0043 = v0205;
    v0205 = stack[-2];
    v0205 = qcdr(v0205);
    stack[-2] = v0205;
    goto v0178;
// error exit handlers
v0171:
    popv(4);
    return nil;
}



// Code for change!+int!+to!+sq

static LispObject CC_changeLintLtoLsq(LispObject env,
                         LispObject v0006)
{
    LispObject nil = C_nil;
    LispObject v0172, v0047;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for change+int+to+sq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0172 = v0006;
// end of prologue
    v0047 = v0172;
    v0172 = (LispObject)17; // 1
    return cons(v0047, v0172);
}



// Code for repr_ldeg

static LispObject CC_repr_ldeg(LispObject env,
                         LispObject v0006)
{
    LispObject v0050;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for repr_ldeg");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0050 = v0006;
// end of prologue
    v0050 = qcdr(v0050);
    v0050 = qcdr(v0050);
    v0050 = qcdr(v0050);
    v0050 = qcdr(v0050);
    v0050 = qcar(v0050);
    return onevalue(v0050);
}



// Code for ofsf_smwcpknowl

static LispObject CC_ofsf_smwcpknowl(LispObject env,
                         LispObject v0006)
{
    LispObject nil = C_nil;
    LispObject v0047, v0052;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_smwcpknowl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0052 = v0006;
// end of prologue
    v0047 = qvalue(elt(env, 1)); // !*rlsusi
    if (v0047 == nil) goto v0178;
    v0047 = v0052;
    {
        fn = elt(env, 2); // cl_susicpknowl
        return (*qfn1(fn))(qenv(fn), v0047);
    }

v0178:
    v0047 = v0052;
    {
        fn = elt(env, 3); // ofsf_smcpknowl
        return (*qfn1(fn))(qenv(fn), v0047);
    }
}



// Code for symbolsrd

static LispObject CC_symbolsrd(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0106, v0105, v0077;
    LispObject fn;
    argcheck(nargs, 0, "symbolsrd");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for symbolsrd");
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
    push5(nil, nil, nil, nil, nil);
// end of prologue
    stack[-4] = nil;
    fn = elt(env, 9); // lex
    v0106 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-5];
    v0105 = qvalue(elt(env, 2)); // char
    v0106 = elt(env, 3); // (b v a r)
    if (equal(v0105, v0106)) goto v0202;
    v0105 = elt(env, 5); // "<bvar>"
    v0106 = (LispObject)225; // 14
    fn = elt(env, 10); // errorml
    v0106 = (*qfn2(fn))(qenv(fn), v0105, v0106);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-5];
    goto v0215;

v0215:
    v0105 = qvalue(elt(env, 2)); // char
    v0106 = elt(env, 6); // (l o w l i m i t)
    if (equal(v0105, v0106)) goto v0048;
    v0106 = qvalue(elt(env, 1)); // nil
    stack[-3] = v0106;
    goto v0014;

v0014:
    v0105 = qvalue(elt(env, 2)); // char
    v0106 = elt(env, 7); // (i n t e r v a l)
    if (equal(v0105, v0106)) goto v0156;
    v0106 = qvalue(elt(env, 1)); // nil
    stack[-2] = v0106;
    goto v0032;

v0032:
    v0105 = qvalue(elt(env, 2)); // char
    v0106 = elt(env, 8); // (c o n d i t i o n)
    if (equal(v0105, v0106)) goto v0216;
    v0106 = qvalue(elt(env, 1)); // nil
    stack[0] = v0106;
    goto v0122;

v0122:
    fn = elt(env, 11); // mathml2
    v0106 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-5];
    stack[-1] = v0106;
    fn = elt(env, 9); // lex
    v0106 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-5];
    v0106 = stack[-3];
    if (v0106 == nil) goto v0166;
    v0077 = stack[-4];
    v0105 = stack[-3];
    v0106 = stack[-1];
    popv(6);
    return list3(v0077, v0105, v0106);

v0166:
    v0106 = stack[-2];
    if (v0106 == nil) goto v0187;
    v0077 = stack[-4];
    v0105 = stack[-2];
    v0106 = stack[-1];
    popv(6);
    return list3(v0077, v0105, v0106);

v0187:
    v0106 = stack[0];
    if (v0106 == nil) goto v0059;
    v0077 = stack[-4];
    v0105 = stack[0];
    v0106 = stack[-1];
    popv(6);
    return list3(v0077, v0105, v0106);

v0059:
    v0105 = stack[-4];
    v0077 = qvalue(elt(env, 1)); // nil
    v0106 = stack[-1];
    popv(6);
    return list3(v0105, v0077, v0106);

v0216:
    fn = elt(env, 12); // conditionrd
    v0106 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-5];
    stack[0] = v0106;
    fn = elt(env, 9); // lex
    v0106 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-5];
    goto v0122;

v0156:
    fn = elt(env, 13); // intervalrd
    v0106 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-5];
    stack[-2] = v0106;
    fn = elt(env, 9); // lex
    v0106 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-5];
    goto v0032;

v0048:
    fn = elt(env, 14); // lowupperlimitrd
    v0106 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-5];
    stack[-3] = v0106;
    fn = elt(env, 9); // lex
    v0106 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-5];
    goto v0014;

v0202:
    fn = elt(env, 15); // bvarrd
    v0106 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-5];
    stack[-4] = v0106;
    v0106 = stack[-4];
    v0106 = qcdr(v0106);
    v0106 = qcdr(v0106);
    v0105 = qcar(v0106);
    v0106 = (LispObject)17; // 1
    if (v0105 == v0106) goto v0022;
    v0105 = elt(env, 4); // ""
    v0106 = (LispObject)209; // 13
    fn = elt(env, 10); // errorml
    v0106 = (*qfn2(fn))(qenv(fn), v0105, v0106);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-5];
    goto v0021;

v0021:
    fn = elt(env, 9); // lex
    v0106 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-5];
    goto v0215;

v0022:
    v0106 = stack[-4];
    stack[-4] = v0106;
    goto v0021;
// error exit handlers
v0214:
    popv(6);
    return nil;
}



// Code for init

static LispObject CC_init(LispObject env,
                         LispObject v0006)
{
    LispObject nil = C_nil;
    LispObject v0241, v0174, v0175, v0176;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for init");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0006);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0006);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0006;
// end of prologue
    v0241 = qvalue(elt(env, 1)); // rowmin
    stack[-2] = v0241;
    goto v0133;

v0133:
    v0174 = qvalue(elt(env, 2)); // rowmax
    v0241 = stack[-2];
    v0241 = difference2(v0174, v0241);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-3];
    v0241 = Lminusp(nil, v0241);
    env = stack[-3];
    if (v0241 == nil) goto v0201;
    v0174 = qvalue(elt(env, 5)); // maxvar
    v0241 = stack[-1];
    if (equal(v0174, v0241)) goto v0077;
    v0174 = (LispObject)33; // 2
    v0241 = stack[-1];
    v0241 = times2(v0174, v0241);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-3];
    v0241 = Lmkvect(nil, v0241);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-3];
    qvalue(elt(env, 4)) = v0241; // codmat
    goto v0105;

v0105:
    v0241 = qvalue(elt(env, 14)); // kvarlst
    if (v0241 == nil) goto v0092;
    v0241 = qvalue(elt(env, 14)); // kvarlst
    v0176 = v0241;
    goto v0153;

v0153:
    v0241 = v0176;
    if (v0241 == nil) goto v0092;
    v0241 = v0176;
    v0241 = qcar(v0241);
    v0175 = v0241;
    v0241 = v0175;
    v0241 = qcdr(v0241);
    v0174 = qcar(v0241);
    v0241 = elt(env, 14); // kvarlst
    v0241 = Lremprop(nil, v0174, v0241);
    env = stack[-3];
    v0241 = v0175;
    v0241 = qcdr(v0241);
    v0174 = qcar(v0241);
    v0241 = elt(env, 11); // nex
    v0241 = Lremprop(nil, v0174, v0241);
    env = stack[-3];
    v0241 = v0176;
    v0241 = qcdr(v0241);
    v0176 = v0241;
    goto v0153;

v0092:
    v0241 = elt(env, 19); // (plus minus difference times expt sqrt)
    v0175 = v0241;
    goto v0243;

v0243:
    v0241 = v0175;
    if (v0241 == nil) goto v0244;
    v0241 = v0175;
    v0241 = qcar(v0241);
    v0174 = v0241;
    v0241 = elt(env, 14); // kvarlst
    v0241 = Lremprop(nil, v0174, v0241);
    env = stack[-3];
    v0241 = v0175;
    v0241 = qcdr(v0241);
    v0175 = v0241;
    goto v0243;

v0244:
    v0241 = qvalue(elt(env, 3)); // nil
    qvalue(elt(env, 20)) = v0241; // avarlst
    qvalue(elt(env, 21)) = v0241; // codbexl!*
    qvalue(elt(env, 14)) = v0241; // kvarlst
    qvalue(elt(env, 22)) = v0241; // prevlst
    qvalue(elt(env, 8)) = v0241; // varlst!+
    qvalue(elt(env, 9)) = v0241; // varlst!*
    v0241 = qvalue(elt(env, 3)); // nil
    qvalue(elt(env, 23)) = v0241; // preprefixlist
    qvalue(elt(env, 24)) = v0241; // malst
    v0241 = qvalue(elt(env, 3)); // nil
    qvalue(elt(env, 25)) = v0241; // prefixlist
    v0241 = (LispObject)-15; // -1
    qvalue(elt(env, 2)) = v0241; // rowmax
    v0241 = stack[-1];
    qvalue(elt(env, 5)) = v0241; // maxvar
    v0241 = (LispObject)1; // 0
    qvalue(elt(env, 1)) = v0241; // rowmin
    v0176 = (LispObject)1; // 0
    v0175 = (LispObject)1; // 0
    v0174 = (LispObject)1; // 0
    v0241 = (LispObject)1; // 0
    v0241 = list4(v0176, v0175, v0174, v0241);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-3];
    qvalue(elt(env, 26)) = v0241; // ops
    v0241 = nil;
    { popv(4); return onevalue(v0241); }

v0077:
    v0241 = (LispObject)1; // 0
    stack[0] = v0241;
    goto v0245;

v0245:
    v0174 = (LispObject)33; // 2
    v0241 = stack[-1];
    v0174 = times2(v0174, v0241);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-3];
    v0241 = stack[0];
    v0241 = difference2(v0174, v0241);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-3];
    v0241 = Lminusp(nil, v0241);
    env = stack[-3];
    if (!(v0241 == nil)) goto v0105;
    v0175 = qvalue(elt(env, 4)); // codmat
    v0174 = stack[0];
    v0241 = qvalue(elt(env, 3)); // nil
    *(LispObject *)((char *)v0175 + (CELL-TAG_VECTOR) + ((int32_t)v0174/(16/CELL))) = v0241;
    v0241 = stack[0];
    v0241 = add1(v0241);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-3];
    stack[0] = v0241;
    goto v0245;

v0201:
    stack[0] = qvalue(elt(env, 4)); // codmat
    v0174 = qvalue(elt(env, 5)); // maxvar
    v0241 = stack[-2];
    v0241 = plus2(v0174, v0241);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-3];
    v0241 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0241/(16/CELL)));
    if (v0241 == nil) goto v0029;
    stack[0] = qvalue(elt(env, 4)); // codmat
    v0174 = qvalue(elt(env, 5)); // maxvar
    v0241 = stack[-2];
    v0241 = plus2(v0174, v0241);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-3];
    v0174 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0241/(16/CELL)));
    v0241 = (LispObject)49; // 3
    v0241 = *(LispObject *)((char *)v0174 + (CELL-TAG_VECTOR) + ((int32_t)v0241/(16/CELL)));
    v0175 = v0241;
    if (is_number(v0241)) goto v0029;
    v0174 = v0175;
    v0241 = elt(env, 6); // npcdvar
    v0241 = Lremprop(nil, v0174, v0241);
    env = stack[-3];
    v0174 = v0175;
    v0241 = elt(env, 7); // nvarlst
    v0241 = Lremprop(nil, v0174, v0241);
    env = stack[-3];
    v0174 = v0175;
    v0241 = elt(env, 8); // varlst!+
    v0241 = Lremprop(nil, v0174, v0241);
    env = stack[-3];
    v0174 = v0175;
    v0241 = elt(env, 9); // varlst!*
    v0241 = Lremprop(nil, v0174, v0241);
    env = stack[-3];
    v0174 = v0175;
    v0241 = elt(env, 10); // rowindex
    v0241 = Lremprop(nil, v0174, v0241);
    env = stack[-3];
    v0174 = v0175;
    v0241 = elt(env, 11); // nex
    v0241 = Lremprop(nil, v0174, v0241);
    env = stack[-3];
    v0174 = v0175;
    v0241 = elt(env, 12); // inlhs
    v0241 = Lremprop(nil, v0174, v0241);
    env = stack[-3];
    v0174 = v0175;
    v0241 = elt(env, 13); // rowocc
    v0241 = Lremprop(nil, v0174, v0241);
    env = stack[-3];
    v0174 = v0175;
    v0241 = elt(env, 14); // kvarlst
    v0241 = Lremprop(nil, v0174, v0241);
    env = stack[-3];
    v0174 = v0175;
    v0241 = elt(env, 15); // alias
    v0241 = Lremprop(nil, v0174, v0241);
    env = stack[-3];
    v0174 = v0175;
    v0241 = elt(env, 16); // finalalias
    v0241 = Lremprop(nil, v0174, v0241);
    env = stack[-3];
    v0174 = v0175;
    v0241 = elt(env, 17); // aliaslist
    v0241 = Lremprop(nil, v0174, v0241);
    env = stack[-3];
    v0174 = v0175;
    v0241 = elt(env, 18); // inalias
    v0241 = Lremprop(nil, v0174, v0241);
    env = stack[-3];
    goto v0029;

v0029:
    v0241 = stack[-2];
    v0241 = add1(v0241);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-3];
    stack[-2] = v0241;
    goto v0133;
// error exit handlers
v0242:
    popv(4);
    return nil;
}



// Code for evzero

static LispObject CC_evzero(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0209, v0030;
    argcheck(nargs, 0, "evzero");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evzero");
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
    v0209 = (LispObject)17; // 1
    stack[0] = v0209;
    goto v0051;

v0051:
    v0209 = qvalue(elt(env, 1)); // dipvars!*
    v0030 = Llength(nil, v0209);
    nil = C_nil;
    if (exception_pending()) goto v0037;
    env = stack[-2];
    v0209 = stack[0];
    v0209 = difference2(v0030, v0209);
    nil = C_nil;
    if (exception_pending()) goto v0037;
    env = stack[-2];
    v0209 = Lminusp(nil, v0209);
    env = stack[-2];
    if (!(v0209 == nil)) { LispObject res = stack[-1]; popv(3); return onevalue(res); }
    v0030 = (LispObject)1; // 0
    v0209 = stack[-1];
    v0209 = cons(v0030, v0209);
    nil = C_nil;
    if (exception_pending()) goto v0037;
    env = stack[-2];
    stack[-1] = v0209;
    v0209 = stack[0];
    v0209 = add1(v0209);
    nil = C_nil;
    if (exception_pending()) goto v0037;
    env = stack[-2];
    stack[0] = v0209;
    goto v0051;
// error exit handlers
v0037:
    popv(3);
    return nil;
}



// Code for get!:const

static LispObject CC_getTconst(LispObject env,
                         LispObject v0006, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0012, v0013;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for get:const");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0007,v0006);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0006,v0007);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0007;
    stack[-1] = v0006;
// end of prologue
    v0012 = stack[-1];
    if (!consp(v0012)) goto v0178;
    v0012 = qvalue(elt(env, 1)); // nil
    goto v0050;

v0050:
    if (v0012 == nil) goto v0135;
    v0013 = stack[-1];
    v0012 = elt(env, 2); // save!:c
    v0012 = get(v0013, v0012);
    env = stack[-2];
    stack[-1] = v0012;
    v0012 = stack[-1];
    if (v0012 == nil) goto v0205;
    v0012 = stack[-1];
    v0013 = qcar(v0012);
    v0012 = stack[0];
    v0012 = (LispObject)lessp2(v0013, v0012);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    v0012 = v0012 ? lisp_true : nil;
    env = stack[-2];
    goto v0042;

v0042:
    if (v0012 == nil) goto v0048;
    v0012 = elt(env, 4); // not_found
    { popv(3); return onevalue(v0012); }

v0048:
    v0012 = stack[-1];
    v0013 = qcar(v0012);
    v0012 = stack[0];
    if (equal(v0013, v0012)) goto v0018;
    v0012 = stack[-1];
    v0013 = qcdr(v0012);
    v0012 = stack[0];
    {
        popv(3);
        fn = elt(env, 5); // round!:mt
        return (*qfn2(fn))(qenv(fn), v0013, v0012);
    }

v0018:
    v0012 = stack[-1];
    v0012 = qcdr(v0012);
    { popv(3); return onevalue(v0012); }

v0205:
    v0012 = qvalue(elt(env, 3)); // t
    goto v0042;

v0135:
    v0012 = elt(env, 0); // get!:const
    {
        popv(3);
        fn = elt(env, 6); // bflerrmsg
        return (*qfn1(fn))(qenv(fn), v0012);
    }

v0178:
    v0012 = stack[0];
    v0012 = integerp(v0012);
    if (v0012 == nil) goto v0052;
    v0013 = stack[0];
    v0012 = (LispObject)1; // 0
    v0012 = (LispObject)greaterp2(v0013, v0012);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    v0012 = v0012 ? lisp_true : nil;
    env = stack[-2];
    goto v0050;

v0052:
    v0012 = qvalue(elt(env, 1)); // nil
    goto v0050;
// error exit handlers
v0198:
    popv(3);
    return nil;
}



// Code for r2speclist1

static LispObject CC_r2speclist1(LispObject env,
                         LispObject v0006)
{
    LispObject nil = C_nil;
    LispObject v0017, v0016, v0009;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for r2speclist1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0017 = v0006;
// end of prologue
    v0009 = v0017;
    v0016 = elt(env, 1); // times
    if (!consp(v0009)) goto v0030;
    v0009 = qcar(v0009);
    if (!(v0009 == v0016)) goto v0030;
    v0016 = v0017;
    v0016 = qcdr(v0016);
    v0009 = qcar(v0016);
    v0016 = v0017;
    v0016 = qcdr(v0016);
    v0016 = qcdr(v0016);
    v0016 = qcar(v0016);
    v0017 = qcdr(v0017);
    v0017 = qcdr(v0017);
    v0017 = qcdr(v0017);
    {
        fn = elt(env, 2); // r2speclist2
        return (*qfnn(fn))(qenv(fn), 3, v0009, v0016, v0017);
    }

v0030:
    v0016 = (LispObject)17; // 1
    return cons(v0016, v0017);
}



// Code for ratnump

static LispObject CC_ratnump(LispObject env,
                         LispObject v0006)
{
    LispObject nil = C_nil;
    LispObject v0194, v0044, v0045;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ratnump");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0006);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0006);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// copy arguments values to proper place
    v0044 = v0006;
// end of prologue
    v0194 = v0044;
    fn = elt(env, 4); // simp!*
    v0194 = (*qfn1(fn))(qenv(fn), v0194);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[0];
    v0044 = v0194;
    v0194 = qcar(v0194);
    if (!consp(v0194)) goto v0050;
    v0194 = v0044;
    v0194 = qcar(v0194);
    v0045 = qcar(v0194);
    v0194 = elt(env, 2); // !:rn!:
    v0194 = (v0045 == v0194 ? lisp_true : nil);
    goto v0027;

v0027:
    if (v0194 == nil) goto v0201;
    v0194 = v0044;
    v0194 = qcdr(v0194);
    v0194 = (consp(v0194) ? nil : lisp_true);
    { popv(1); return onevalue(v0194); }

v0201:
    v0194 = qvalue(elt(env, 3)); // nil
    { popv(1); return onevalue(v0194); }

v0050:
    v0194 = qvalue(elt(env, 1)); // t
    goto v0027;
// error exit handlers
v0209:
    popv(1);
    return nil;
}



// Code for simpdfp

static LispObject CC_simpdfp(LispObject env,
                         LispObject v0006)
{
    LispObject nil = C_nil;
    LispObject v0264, v0265, v0266, v0267, v0268;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for simpdfp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0006);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0006);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    stack[0] = v0006;
// end of prologue
    v0264 = stack[0];
    v0265 = Llength(nil, v0264);
    nil = C_nil;
    if (exception_pending()) goto v0269;
    env = stack[-6];
    v0264 = (LispObject)33; // 2
    v0264 = (LispObject)lessp2(v0265, v0264);
    nil = C_nil;
    if (exception_pending()) goto v0269;
    v0264 = v0264 ? lisp_true : nil;
    env = stack[-6];
    if (v0264 == nil) goto v0172;
    v0265 = elt(env, 2); // dfp
    v0264 = stack[0];
    v0265 = cons(v0265, v0264);
    nil = C_nil;
    if (exception_pending()) goto v0269;
    env = stack[-6];
    v0264 = elt(env, 11); // "generic differential"
    fn = elt(env, 12); // typerr
    v0264 = (*qfn2(fn))(qenv(fn), v0265, v0264);
    nil = C_nil;
    if (exception_pending()) goto v0269;
    v0264 = nil;
    { popv(7); return onevalue(v0264); }

v0172:
    v0264 = stack[0];
    v0264 = qcar(v0264);
    fn = elt(env, 13); // reval
    v0264 = (*qfn1(fn))(qenv(fn), v0264);
    nil = C_nil;
    if (exception_pending()) goto v0269;
    env = stack[-6];
    stack[-5] = v0264;
    v0264 = stack[-5];
    v0264 = Lconsp(nil, v0264);
    env = stack[-6];
    if (v0264 == nil) goto v0207;
    v0264 = stack[-5];
    v0264 = qcar(v0264);
    stack[-1] = v0264;
    v0264 = stack[0];
    v0264 = qcdr(v0264);
    v0264 = qcar(v0264);
    fn = elt(env, 13); // reval
    v0264 = (*qfn1(fn))(qenv(fn), v0264);
    nil = C_nil;
    if (exception_pending()) goto v0269;
    env = stack[-6];
    v0268 = v0264;
    v0265 = v0268;
    v0264 = qvalue(elt(env, 1)); // frlis!*
    v0264 = Lmember(nil, v0265, v0264);
    if (v0264 == nil) goto v0032;
    v0264 = qvalue(elt(env, 4)); // nil
    goto v0191;

v0191:
    if (v0264 == nil) goto v0270;
    stack[-4] = v0268;
    v0264 = stack[0];
    v0264 = qcdr(v0264);
    v0264 = qcdr(v0264);
    stack[-3] = v0264;
    v0264 = stack[-3];
    if (v0264 == nil) goto v0165;
    v0264 = stack[-3];
    v0264 = qcar(v0264);
    fn = elt(env, 13); // reval
    v0264 = (*qfn1(fn))(qenv(fn), v0264);
    nil = C_nil;
    if (exception_pending()) goto v0269;
    env = stack[-6];
    v0264 = ncons(v0264);
    nil = C_nil;
    if (exception_pending()) goto v0269;
    env = stack[-6];
    stack[-1] = v0264;
    stack[-2] = v0264;
    goto v0121;

v0121:
    v0264 = stack[-3];
    v0264 = qcdr(v0264);
    stack[-3] = v0264;
    v0264 = stack[-3];
    if (v0264 == nil) goto v0186;
    stack[0] = stack[-1];
    v0264 = stack[-3];
    v0264 = qcar(v0264);
    fn = elt(env, 13); // reval
    v0264 = (*qfn1(fn))(qenv(fn), v0264);
    nil = C_nil;
    if (exception_pending()) goto v0269;
    env = stack[-6];
    v0264 = ncons(v0264);
    nil = C_nil;
    if (exception_pending()) goto v0269;
    env = stack[-6];
    v0264 = Lrplacd(nil, stack[0], v0264);
    nil = C_nil;
    if (exception_pending()) goto v0269;
    env = stack[-6];
    v0264 = stack[-1];
    v0264 = qcdr(v0264);
    stack[-1] = v0264;
    goto v0121;

v0186:
    v0264 = stack[-2];
    goto v0166;

v0166:
    v0264 = cons(stack[-4], v0264);
    nil = C_nil;
    if (exception_pending()) goto v0269;
    env = stack[-6];
    v0268 = v0264;
    stack[0] = elt(env, 3); // list
    v0265 = v0268;
    v0264 = qvalue(elt(env, 4)); // nil
    fn = elt(env, 14); // dfp!-normalize
    v0264 = (*qfn2(fn))(qenv(fn), v0265, v0264);
    nil = C_nil;
    if (exception_pending()) goto v0269;
    env = stack[-6];
    v0264 = cons(stack[0], v0264);
    nil = C_nil;
    if (exception_pending()) goto v0269;
    env = stack[-6];
    v0268 = v0264;
    v0265 = elt(env, 2); // dfp
    v0264 = stack[-5];
    v0266 = v0268;
    v0264 = list3(v0265, v0264, v0266);
    nil = C_nil;
    if (exception_pending()) goto v0269;
    env = stack[-6];
    {
        popv(7);
        fn = elt(env, 15); // simp
        return (*qfn1(fn))(qenv(fn), v0264);
    }

v0165:
    v0264 = qvalue(elt(env, 4)); // nil
    goto v0166;

v0270:
    v0265 = stack[-1];
    v0264 = elt(env, 5); // generic_function
    v0264 = get(v0265, v0264);
    env = stack[-6];
    v0267 = v0264;
    v0264 = qvalue(elt(env, 6)); // t
    v0265 = v0267;
    if (v0265 == nil) goto v0229;
    v0266 = v0268;
    v0265 = elt(env, 3); // list
    if (!consp(v0266)) goto v0229;
    v0266 = qcar(v0266);
    if (!(v0266 == v0265)) goto v0229;
    v0265 = v0268;
    v0265 = qcdr(v0265);
    v0266 = v0265;
    goto v0101;

v0101:
    v0265 = v0266;
    if (v0265 == nil) goto v0229;
    v0265 = v0266;
    v0265 = qcar(v0265);
    if (v0264 == nil) goto v0152;
    v0264 = v0267;
    v0264 = Lmember(nil, v0265, v0264);
    goto v0271;

v0271:
    v0265 = v0266;
    v0265 = qcdr(v0265);
    v0266 = v0265;
    goto v0101;

v0152:
    v0264 = qvalue(elt(env, 4)); // nil
    goto v0271;

v0229:
    if (v0264 == nil) goto v0272;
    v0265 = v0268;
    v0264 = elt(env, 7); // (list)
    if (equal(v0265, v0264)) goto v0273;
    v0264 = v0267;
    if (v0264 == nil) goto v0274;
    v0265 = stack[-1];
    v0264 = elt(env, 8); // dfp_commute
    v0264 = Lflagp(nil, v0265, v0264);
    env = stack[-6];
    if (v0264 == nil) goto v0274;
    v0264 = v0267;
    stack[-1] = qvalue(elt(env, 9)); // kord!*
    qvalue(elt(env, 9)) = v0264; // kord!*
    stack[0] = elt(env, 3); // list
    v0264 = v0268;
    v0265 = qcdr(v0264);
    v0264 = elt(env, 10); // ordp
    fn = elt(env, 16); // sort
    v0264 = (*qfn2(fn))(qenv(fn), v0265, v0264);
    nil = C_nil;
    if (exception_pending()) goto v0275;
    env = stack[-6];
    v0264 = cons(stack[0], v0264);
    nil = C_nil;
    if (exception_pending()) goto v0275;
    env = stack[-6];
    v0268 = v0264;
    qvalue(elt(env, 9)) = stack[-1]; // kord!*
    goto v0274;

v0274:
    v0265 = elt(env, 2); // dfp
    v0264 = stack[-5];
    v0266 = v0268;
    v0264 = list3(v0265, v0264, v0266);
    nil = C_nil;
    if (exception_pending()) goto v0269;
    env = stack[-6];
    stack[0] = v0264;
    v0265 = stack[0];
    v0264 = (LispObject)17; // 1
    {
        popv(7);
        fn = elt(env, 17); // mksq
        return (*qfn2(fn))(qenv(fn), v0265, v0264);
    }

v0273:
    v0265 = stack[-5];
    v0264 = (LispObject)17; // 1
    {
        popv(7);
        fn = elt(env, 17); // mksq
        return (*qfn2(fn))(qenv(fn), v0265, v0264);
    }

v0272:
    v0265 = qvalue(elt(env, 4)); // nil
    v0264 = (LispObject)17; // 1
    popv(7);
    return cons(v0265, v0264);

v0032:
    v0265 = v0268;
    v0264 = elt(env, 3); // list
    v0264 = Leqcar(nil, v0265, v0264);
    env = stack[-6];
    v0264 = (v0264 == nil ? lisp_true : nil);
    goto v0191;

v0207:
    v0264 = stack[0];
    v0264 = qcdr(v0264);
    v0265 = qcar(v0264);
    v0264 = qvalue(elt(env, 1)); // frlis!*
    v0264 = Lmember(nil, v0265, v0264);
    if (v0264 == nil) goto v0019;
    v0265 = elt(env, 2); // dfp
    v0264 = stack[0];
    v0265 = cons(v0265, v0264);
    nil = C_nil;
    if (exception_pending()) goto v0269;
    env = stack[-6];
    v0264 = (LispObject)17; // 1
    {
        popv(7);
        fn = elt(env, 17); // mksq
        return (*qfn2(fn))(qenv(fn), v0265, v0264);
    }

v0019:
    v0265 = stack[-5];
    v0264 = stack[0];
    v0264 = qcdr(v0264);
    v0264 = qcar(v0264);
    v0264 = qcdr(v0264);
    v0264 = cons(v0265, v0264);
    nil = C_nil;
    if (exception_pending()) goto v0269;
    env = stack[-6];
    {
        popv(7);
        fn = elt(env, 18); // simpdf
        return (*qfn1(fn))(qenv(fn), v0264);
    }
// error exit handlers
v0275:
    env = stack[-6];
    qvalue(elt(env, 9)) = stack[-1]; // kord!*
    popv(7);
    return nil;
v0269:
    popv(7);
    return nil;
}



// Code for equiv!-coeffs

static LispObject CC_equivKcoeffs(LispObject env,
                         LispObject v0006, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0011, v0156;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for equiv-coeffs");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0007,v0006);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0006,v0007);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0007;
    stack[-1] = v0006;
// end of prologue
    stack[-2] = nil;
    goto v0071;

v0071:
    v0011 = stack[-1];
    if (v0011 == nil) goto v0047;
    v0011 = stack[0];
    if (v0011 == nil) goto v0024;
    v0011 = stack[-1];
    v0011 = qcar(v0011);
    v0156 = qcar(v0011);
    v0011 = stack[0];
    v0011 = qcar(v0011);
    v0011 = qcar(v0011);
    if (equal(v0156, v0011)) goto v0008;
    v0011 = stack[-1];
    v0011 = qcar(v0011);
    v0156 = qcar(v0011);
    v0011 = stack[0];
    v0011 = qcar(v0011);
    v0011 = qcar(v0011);
    fn = elt(env, 1); // mv!-pow!-!>
    v0011 = (*qfn2(fn))(qenv(fn), v0156, v0011);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-3];
    if (v0011 == nil) goto v0054;
    v0011 = stack[-1];
    v0011 = qcdr(v0011);
    stack[-1] = v0011;
    goto v0071;

v0054:
    v0156 = (LispObject)1; // 0
    v0011 = stack[-2];
    v0011 = cons(v0156, v0011);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-3];
    stack[-2] = v0011;
    v0011 = stack[0];
    v0011 = qcdr(v0011);
    stack[0] = v0011;
    goto v0071;

v0008:
    v0011 = stack[-1];
    v0011 = qcar(v0011);
    v0156 = qcdr(v0011);
    v0011 = stack[-2];
    v0011 = cons(v0156, v0011);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-3];
    stack[-2] = v0011;
    v0011 = stack[-1];
    v0011 = qcdr(v0011);
    stack[-1] = v0011;
    v0011 = stack[0];
    v0011 = qcdr(v0011);
    stack[0] = v0011;
    goto v0071;

v0024:
    v0011 = stack[-2];
    {
        popv(4);
        fn = elt(env, 2); // nreverse
        return (*qfn1(fn))(qenv(fn), v0011);
    }

v0047:
    stack[-1] = stack[-2];
    v0011 = stack[0];
    v0011 = Llength(nil, v0011);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-3];
    fn = elt(env, 3); // nzeros
    v0011 = (*qfn1(fn))(qenv(fn), v0011);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-3];
    {
        LispObject v0135 = stack[-1];
        popv(4);
        fn = elt(env, 2); // nreverse
        return (*qfn2(fn))(qenv(fn), v0135, v0011);
    }
// error exit handlers
v0069:
    popv(4);
    return nil;
}



// Code for groeb!=testc1

static LispObject CC_groebMtestc1(LispObject env,
                         LispObject v0006)
{
    LispObject nil = C_nil;
    LispObject v0015, v0017;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for groeb=testc1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0006);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0006);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0006;
// end of prologue
    v0017 = stack[0];
    v0015 = (LispObject)81; // 5
    fn = elt(env, 1); // nth
    v0015 = (*qfn2(fn))(qenv(fn), v0017, v0015);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-2];
    fn = elt(env, 2); // bas_dpoly
    v0015 = (*qfn1(fn))(qenv(fn), v0015);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-2];
    fn = elt(env, 3); // dp_lmon
    stack[-1] = (*qfn1(fn))(qenv(fn), v0015);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-2];
    v0017 = stack[0];
    v0015 = (LispObject)65; // 4
    fn = elt(env, 1); // nth
    v0015 = (*qfn2(fn))(qenv(fn), v0017, v0015);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-2];
    fn = elt(env, 2); // bas_dpoly
    v0015 = (*qfn1(fn))(qenv(fn), v0015);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-2];
    fn = elt(env, 3); // dp_lmon
    v0015 = (*qfn1(fn))(qenv(fn), v0015);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-2];
    fn = elt(env, 4); // mo_sum
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[-1], v0015);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-2];
    v0017 = stack[0];
    v0015 = (LispObject)49; // 3
    fn = elt(env, 1); // nth
    v0015 = (*qfn2(fn))(qenv(fn), v0017, v0015);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-2];
    {
        LispObject v0035 = stack[-1];
        popv(3);
        fn = elt(env, 5); // mo_equal!?
        return (*qfn2(fn))(qenv(fn), v0035, v0015);
    }
// error exit handlers
v0169:
    popv(3);
    return nil;
}



// Code for lesspcar

static LispObject CC_lesspcar(LispObject env,
                         LispObject v0006, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0047, v0052;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lesspcar");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0047 = v0007;
    v0052 = v0006;
// end of prologue
    v0052 = qcar(v0052);
    v0047 = qcar(v0047);
        return Llessp(nil, v0052, v0047);
}



// Code for simpquot

static LispObject CC_simpquot(LispObject env,
                         LispObject v0006)
{
    LispObject nil = C_nil;
    LispObject v0278, v0279, v0270;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for simpquot");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0006);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0006);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0006;
// end of prologue
    v0278 = stack[-1];
    fn = elt(env, 9); // simpcar
    stack[0] = (*qfn1(fn))(qenv(fn), v0278);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-3];
    v0278 = stack[-1];
    v0278 = qcdr(v0278);
    v0278 = qcar(v0278);
    fn = elt(env, 10); // simp
    v0278 = (*qfn1(fn))(qenv(fn), v0278);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-3];
    stack[-2] = stack[0];
    stack[0] = v0278;
    v0278 = stack[0];
    v0278 = qcar(v0278);
    if (v0278 == nil) goto v0172;
    v0279 = qvalue(elt(env, 4)); // dmode!*
    v0278 = elt(env, 5); // (!:rd!: !:cr!:)
    v0278 = Lmemq(nil, v0279, v0278);
    if (v0278 == nil) goto v0063;
    v0278 = stack[0];
    v0278 = qcar(v0278);
    if (!consp(v0278)) goto v0193;
    v0278 = stack[0];
    v0278 = qcar(v0278);
    v0278 = qcar(v0278);
    v0278 = (consp(v0278) ? nil : lisp_true);
    goto v0179;

v0179:
    if (v0278 == nil) goto v0025;
    v0278 = stack[0];
    v0278 = qcdr(v0278);
    if (!consp(v0278)) goto v0010;
    v0278 = stack[0];
    v0278 = qcdr(v0278);
    v0278 = qcar(v0278);
    v0278 = (consp(v0278) ? nil : lisp_true);
    goto v0280;

v0280:
    if (v0278 == nil) goto v0082;
    v0278 = stack[-2];
    v0278 = qcdr(v0278);
    if (!consp(v0278)) goto v0122;
    v0278 = stack[-2];
    v0278 = qcdr(v0278);
    v0278 = qcar(v0278);
    v0278 = (consp(v0278) ? nil : lisp_true);
    goto v0081;

v0081:
    if (v0278 == nil) goto v0004;
    v0278 = stack[0];
    v0278 = qcdr(v0278);
    fn = elt(env, 11); // !:onep
    v0278 = (*qfn1(fn))(qenv(fn), v0278);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-3];
    if (v0278 == nil) goto v0136;
    v0278 = stack[-2];
    v0278 = qcdr(v0278);
    fn = elt(env, 11); // !:onep
    v0278 = (*qfn1(fn))(qenv(fn), v0278);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-3];
    goto v0261;

v0261:
    if (v0278 == nil) goto v0063;
    v0278 = stack[-2];
    v0278 = qcar(v0278);
    if (v0278 == nil) goto v0120;
    v0278 = stack[-2];
    v0279 = qcar(v0278);
    v0278 = stack[0];
    v0278 = qcar(v0278);
    fn = elt(env, 12); // divd
    v0278 = (*qfn2(fn))(qenv(fn), v0279, v0278);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    v0279 = v0278;
    goto v0281;

v0281:
    v0278 = (LispObject)17; // 1
    popv(4);
    return cons(v0279, v0278);

v0120:
    v0278 = qvalue(elt(env, 7)); // nil
    v0279 = v0278;
    goto v0281;

v0063:
    stack[0] = stack[-2];
    v0278 = stack[-1];
    v0278 = qcdr(v0278);
    fn = elt(env, 13); // simprecip
    v0278 = (*qfn1(fn))(qenv(fn), v0278);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-3];
    fn = elt(env, 14); // multsq
    v0278 = (*qfn2(fn))(qenv(fn), stack[0], v0278);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-3];
    stack[-1] = v0278;
    v0278 = qvalue(elt(env, 8)); // !*modular
    if (v0278 == nil) { LispObject res = stack[-1]; popv(4); return onevalue(res); }
    v0278 = stack[-1];
    v0278 = qcdr(v0278);
    if (!(v0278 == nil)) { LispObject res = stack[-1]; popv(4); return onevalue(res); }
    v0270 = elt(env, 1); // alg
    v0279 = (LispObject)3217; // 201
    v0278 = elt(env, 3); // "Zero divisor"
    fn = elt(env, 15); // rerror
    v0278 = (*qfnn(fn))(qenv(fn), 3, v0270, v0279, v0278);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    { LispObject res = stack[-1]; popv(4); return onevalue(res); }

v0136:
    v0278 = qvalue(elt(env, 7)); // nil
    goto v0261;

v0004:
    v0278 = qvalue(elt(env, 7)); // nil
    goto v0261;

v0122:
    v0278 = qvalue(elt(env, 6)); // t
    goto v0081;

v0082:
    v0278 = qvalue(elt(env, 7)); // nil
    goto v0261;

v0010:
    v0278 = qvalue(elt(env, 6)); // t
    goto v0280;

v0025:
    v0278 = qvalue(elt(env, 7)); // nil
    goto v0261;

v0193:
    v0278 = qvalue(elt(env, 6)); // t
    goto v0179;

v0172:
    v0278 = stack[-2];
    v0278 = qcar(v0278);
    if (v0278 == nil) goto v0023;
    v0270 = elt(env, 1); // alg
    v0279 = (LispObject)321; // 20
    v0278 = elt(env, 3); // "Zero divisor"
    {
        popv(4);
        fn = elt(env, 15); // rerror
        return (*qfnn(fn))(qenv(fn), 3, v0270, v0279, v0278);
    }

v0023:
    v0270 = elt(env, 1); // alg
    v0279 = (LispObject)305; // 19
    v0278 = elt(env, 2); // "0/0 formed"
    {
        popv(4);
        fn = elt(env, 15); // rerror
        return (*qfnn(fn))(qenv(fn), 3, v0270, v0279, v0278);
    }
// error exit handlers
v0110:
    popv(4);
    return nil;
}



// Code for make!-image

static LispObject CC_makeKimage(LispObject env,
                         LispObject v0006, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0014, v0068, v0069;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for make-image");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0007,v0006);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0006,v0007);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0007;
    stack[-1] = v0006;
// end of prologue
    v0014 = stack[-1];
    if (!consp(v0014)) goto v0178;
    v0014 = stack[-1];
    v0014 = qcar(v0014);
    v0014 = (consp(v0014) ? nil : lisp_true);
    goto v0050;

v0050:
    if (!(v0014 == nil)) { LispObject res = stack[-1]; popv(4); return onevalue(res); }
    v0014 = stack[-1];
    v0014 = qcar(v0014);
    v0014 = qcar(v0014);
    v0068 = qcar(v0014);
    v0014 = qvalue(elt(env, 2)); // m!-image!-variable
    if (equal(v0068, v0014)) goto v0044;
    v0068 = stack[-1];
    v0014 = stack[0];
    fn = elt(env, 3); // evaluate!-in!-order
    v0014 = (*qfn2(fn))(qenv(fn), v0068, v0014);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-3];
    {
        popv(4);
        fn = elt(env, 4); // !*n2f
        return (*qfn1(fn))(qenv(fn), v0014);
    }

v0044:
    v0014 = stack[-1];
    v0014 = qcar(v0014);
    v0068 = qcdr(v0014);
    v0014 = stack[0];
    fn = elt(env, 3); // evaluate!-in!-order
    v0014 = (*qfn2(fn))(qenv(fn), v0068, v0014);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-3];
    fn = elt(env, 4); // !*n2f
    stack[-2] = (*qfn1(fn))(qenv(fn), v0014);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-3];
    v0014 = stack[-1];
    v0068 = qcdr(v0014);
    v0014 = stack[0];
    v0014 = CC_makeKimage(env, v0068, v0014);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    v0068 = stack[-2];
    v0069 = v0068;
    if (v0069 == nil) { popv(4); return onevalue(v0014); }
    v0069 = stack[-1];
    v0069 = qcar(v0069);
    v0069 = qcar(v0069);
    popv(4);
    return acons(v0069, v0068, v0014);

v0178:
    v0014 = qvalue(elt(env, 1)); // t
    goto v0050;
// error exit handlers
v0213:
    popv(4);
    return nil;
}



// Code for mk!+resimp!+mat

static LispObject CC_mkLresimpLmat(LispObject env,
                         LispObject v0006)
{
    LispObject nil = C_nil;
    LispObject v0165;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mk+resimp+mat");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0006);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0006);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
// copy arguments values to proper place
    v0165 = v0006;
// end of prologue
    stack[-7] = v0165;
    v0165 = stack[-7];
    if (v0165 == nil) goto v0133;
    v0165 = stack[-7];
    v0165 = qcar(v0165);
    stack[-3] = v0165;
    v0165 = stack[-3];
    if (v0165 == nil) goto v0044;
    v0165 = stack[-3];
    v0165 = qcar(v0165);
    fn = elt(env, 2); // resimp
    v0165 = (*qfn1(fn))(qenv(fn), v0165);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-8];
    v0165 = ncons(v0165);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-8];
    stack[-1] = v0165;
    stack[-2] = v0165;
    goto v0201;

v0201:
    v0165 = stack[-3];
    v0165 = qcdr(v0165);
    stack[-3] = v0165;
    v0165 = stack[-3];
    if (v0165 == nil) goto v0035;
    stack[0] = stack[-1];
    v0165 = stack[-3];
    v0165 = qcar(v0165);
    fn = elt(env, 2); // resimp
    v0165 = (*qfn1(fn))(qenv(fn), v0165);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-8];
    v0165 = ncons(v0165);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-8];
    v0165 = Lrplacd(nil, stack[0], v0165);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-8];
    v0165 = stack[-1];
    v0165 = qcdr(v0165);
    stack[-1] = v0165;
    goto v0201;

v0035:
    v0165 = stack[-2];
    goto v0206;

v0206:
    v0165 = ncons(v0165);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-8];
    stack[-5] = v0165;
    stack[-6] = v0165;
    goto v0172;

v0172:
    v0165 = stack[-7];
    v0165 = qcdr(v0165);
    stack[-7] = v0165;
    v0165 = stack[-7];
    if (v0165 == nil) { LispObject res = stack[-6]; popv(9); return onevalue(res); }
    stack[-4] = stack[-5];
    v0165 = stack[-7];
    v0165 = qcar(v0165);
    stack[-3] = v0165;
    v0165 = stack[-3];
    if (v0165 == nil) goto v0070;
    v0165 = stack[-3];
    v0165 = qcar(v0165);
    fn = elt(env, 2); // resimp
    v0165 = (*qfn1(fn))(qenv(fn), v0165);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-8];
    v0165 = ncons(v0165);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-8];
    stack[-1] = v0165;
    stack[-2] = v0165;
    goto v0192;

v0192:
    v0165 = stack[-3];
    v0165 = qcdr(v0165);
    stack[-3] = v0165;
    v0165 = stack[-3];
    if (v0165 == nil) goto v0067;
    stack[0] = stack[-1];
    v0165 = stack[-3];
    v0165 = qcar(v0165);
    fn = elt(env, 2); // resimp
    v0165 = (*qfn1(fn))(qenv(fn), v0165);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-8];
    v0165 = ncons(v0165);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-8];
    v0165 = Lrplacd(nil, stack[0], v0165);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-8];
    v0165 = stack[-1];
    v0165 = qcdr(v0165);
    stack[-1] = v0165;
    goto v0192;

v0067:
    v0165 = stack[-2];
    goto v0191;

v0191:
    v0165 = ncons(v0165);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-8];
    v0165 = Lrplacd(nil, stack[-4], v0165);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-8];
    v0165 = stack[-5];
    v0165 = qcdr(v0165);
    stack[-5] = v0165;
    goto v0172;

v0070:
    v0165 = qvalue(elt(env, 1)); // nil
    goto v0191;

v0044:
    v0165 = qvalue(elt(env, 1)); // nil
    goto v0206;

v0133:
    v0165 = qvalue(elt(env, 1)); // nil
    { popv(9); return onevalue(v0165); }
// error exit handlers
v0120:
    popv(9);
    return nil;
}



// Code for diffrd

static LispObject CC_diffrd(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0016, v0009, v0169;
    LispObject fn;
    argcheck(nargs, 0, "diffrd");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for diffrd");
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
    fn = elt(env, 4); // lex
    v0016 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-3];
    v0009 = qvalue(elt(env, 1)); // char
    v0016 = elt(env, 2); // (b v a r)
    if (equal(v0009, v0016)) goto v0028;
    v0016 = qvalue(elt(env, 3)); // nil
    stack[-2] = v0016;
    v0016 = qvalue(elt(env, 3)); // nil
    stack[-1] = v0016;
    goto v0178;

v0178:
    fn = elt(env, 5); // mathml2
    v0016 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-3];
    stack[0] = v0016;
    fn = elt(env, 4); // lex
    v0016 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-3];
    v0169 = stack[0];
    v0009 = stack[-2];
    v0016 = stack[-1];
    {
        popv(4);
        fn = elt(env, 6); // alg_df
        return (*qfnn(fn))(qenv(fn), 3, v0169, v0009, v0016);
    }

v0028:
    fn = elt(env, 7); // bvarrd
    v0016 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-3];
    stack[-2] = v0016;
    v0016 = stack[-2];
    v0016 = qcdr(v0016);
    v0016 = qcar(v0016);
    stack[-1] = v0016;
    v0016 = stack[-2];
    v0016 = qcar(v0016);
    stack[-2] = v0016;
    fn = elt(env, 4); // lex
    v0016 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-3];
    goto v0178;
// error exit handlers
v0043:
    popv(4);
    return nil;
}



// Code for simpsqrtsq

static LispObject CC_simpsqrtsq(LispObject env,
                         LispObject v0006)
{
    LispObject nil = C_nil;
    LispObject v0052;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for simpsqrtsq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0006);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0006);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0006;
// end of prologue
    v0052 = stack[0];
    v0052 = qcar(v0052);
    fn = elt(env, 1); // simpsqrt2
    stack[-1] = (*qfn1(fn))(qenv(fn), v0052);
    nil = C_nil;
    if (exception_pending()) goto v0203;
    env = stack[-2];
    v0052 = stack[0];
    v0052 = qcdr(v0052);
    fn = elt(env, 1); // simpsqrt2
    v0052 = (*qfn1(fn))(qenv(fn), v0052);
    nil = C_nil;
    if (exception_pending()) goto v0203;
    {
        LispObject v0204 = stack[-1];
        popv(3);
        return cons(v0204, v0052);
    }
// error exit handlers
v0203:
    popv(3);
    return nil;
}



// Code for ps!:times!-erule

static LispObject CC_psTtimesKerule(LispObject env,
                         LispObject v0006, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0038, v0119;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ps:times-erule");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0007,v0006);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0006,v0007);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-8] = v0007;
    v0119 = v0006;
// end of prologue
    v0038 = v0119;
    v0038 = qcdr(v0038);
    v0038 = qcar(v0038);
    stack[-9] = v0038;
    v0038 = v0119;
    v0038 = qcdr(v0038);
    v0038 = qcdr(v0038);
    v0038 = qcar(v0038);
    stack[-7] = v0038;
    v0119 = qvalue(elt(env, 1)); // nil
    v0038 = (LispObject)17; // 1
    v0038 = cons(v0119, v0038);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-10];
    stack[0] = v0038;
    v0038 = stack[-9];
    fn = elt(env, 3); // ps!:order
    v0038 = (*qfn1(fn))(qenv(fn), v0038);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-10];
    stack[-6] = v0038;
    v0038 = qvalue(elt(env, 2)); // ps
    fn = elt(env, 3); // ps!:order
    v0038 = (*qfn1(fn))(qenv(fn), v0038);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-10];
    stack[-5] = v0038;
    v0038 = stack[-7];
    fn = elt(env, 3); // ps!:order
    v0038 = (*qfn1(fn))(qenv(fn), v0038);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-10];
    stack[-4] = v0038;
    v0038 = (LispObject)1; // 0
    stack[-3] = v0038;
    goto v0205;

v0205:
    v0119 = stack[-8];
    v0038 = stack[-5];
    v0119 = difference2(v0119, v0038);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-10];
    v0038 = stack[-3];
    v0038 = difference2(v0119, v0038);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-10];
    v0038 = Lminusp(nil, v0038);
    env = stack[-10];
    if (!(v0038 == nil)) { LispObject res = stack[0]; popv(11); return onevalue(res); }
    v0119 = stack[-8];
    v0038 = stack[-6];
    v0119 = difference2(v0119, v0038);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-10];
    v0038 = stack[-3];
    v0119 = difference2(v0119, v0038);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-10];
    v0038 = stack[-4];
    v0038 = (LispObject)geq2(v0119, v0038);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    v0038 = v0038 ? lisp_true : nil;
    env = stack[-10];
    if (v0038 == nil) goto v0261;
    stack[-2] = stack[0];
    stack[0] = stack[-9];
    v0119 = stack[-3];
    v0038 = stack[-6];
    v0038 = plus2(v0119, v0038);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-10];
    fn = elt(env, 4); // ps!:evaluate
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[0], v0038);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-10];
    stack[0] = stack[-7];
    v0119 = stack[-8];
    v0038 = stack[-6];
    v0119 = difference2(v0119, v0038);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-10];
    v0038 = stack[-3];
    v0038 = difference2(v0119, v0038);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-10];
    fn = elt(env, 4); // ps!:evaluate
    v0038 = (*qfn2(fn))(qenv(fn), stack[0], v0038);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-10];
    fn = elt(env, 5); // multsq
    v0038 = (*qfn2(fn))(qenv(fn), stack[-1], v0038);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-10];
    fn = elt(env, 6); // addsq
    v0038 = (*qfn2(fn))(qenv(fn), stack[-2], v0038);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-10];
    stack[0] = v0038;
    goto v0261;

v0261:
    v0038 = stack[-3];
    v0038 = add1(v0038);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-10];
    stack[-3] = v0038;
    goto v0205;
// error exit handlers
v0118:
    popv(11);
    return nil;
}



// Code for findelem2

static LispObject CC_findelem2(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0261, v0039, v0040, v0239, v0179;
    LispObject v0005, v0007, v0006;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "findelem2");
    va_start(aa, nargs);
    v0006 = va_arg(aa, LispObject);
    v0007 = va_arg(aa, LispObject);
    v0005 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for findelem2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0005,v0007,v0006);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0006,v0007,v0005);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// copy arguments values to proper place
    v0261 = v0005;
    v0039 = v0007;
    v0040 = v0006;
// end of prologue
    v0239 = v0040;
    v0239 = Lconsp(nil, v0239);
    env = stack[0];
    if (v0239 == nil) goto v0209;
    v0239 = v0040;
    v0239 = qcar(v0239);
    v0179 = elt(env, 1); // sparsemat
    if (!(v0239 == v0179)) goto v0209;
    v0040 = qcdr(v0040);
    v0040 = qcar(v0040);
    goto v0209;

v0209:
    v0039 = *(LispObject *)((char *)v0040 + (CELL-TAG_VECTOR) + ((int32_t)v0039/(16/CELL)));
    v0261 = Latsoc(nil, v0261, v0039);
    v0039 = v0261;
    v0261 = v0039;
    if (v0261 == nil) goto v0043;
    v0261 = v0039;
    v0261 = qcdr(v0261);
    { popv(1); return onevalue(v0261); }

v0043:
    v0261 = (LispObject)1; // 0
    { popv(1); return onevalue(v0261); }
}



// Code for evweightedcomp1

static LispObject CC_evweightedcomp1(LispObject env,
                         LispObject v0006, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0052, v0051, v0133;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evweightedcomp1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0052 = v0007;
    v0051 = v0006;
// end of prologue
    v0133 = (LispObject)1; // 0
    {
        fn = elt(env, 1); // evweightedcomp2
        return (*qfnn(fn))(qenv(fn), 3, v0133, v0051, v0052);
    }
}



// Code for gbfdiff

static LispObject CC_gbfdiff(LispObject env,
                         LispObject v0006, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0201, v0021;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gbfdiff");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0007,v0006);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0006,v0007);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0007;
    stack[-1] = v0006;
// end of prologue
    v0201 = stack[-1];
    v0021 = qcar(v0201);
    v0201 = stack[0];
    v0201 = qcar(v0201);
    fn = elt(env, 1); // difbf
    stack[-2] = (*qfn2(fn))(qenv(fn), v0021, v0201);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-3];
    v0201 = stack[-1];
    v0021 = qcdr(v0201);
    v0201 = stack[0];
    v0201 = qcdr(v0201);
    fn = elt(env, 1); // difbf
    v0201 = (*qfn2(fn))(qenv(fn), v0021, v0201);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    {
        LispObject v0209 = stack[-2];
        popv(4);
        return cons(v0209, v0201);
    }
// error exit handlers
v0045:
    popv(4);
    return nil;
}



// Code for cvitimes2

static LispObject CC_cvitimes2(LispObject env,
                         LispObject v0006, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0179, v0193, v0018, v0019;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cvitimes2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0018 = v0007;
    v0019 = v0006;
// end of prologue
    v0193 = v0019;
    v0179 = (LispObject)1; // 0
    if (v0193 == v0179) goto v0178;
    v0193 = v0018;
    v0179 = (LispObject)1; // 0
    v0179 = (v0193 == v0179 ? lisp_true : nil);
    goto v0050;

v0050:
    if (v0179 == nil) goto v0194;
    v0179 = (LispObject)1; // 0
    return onevalue(v0179);

v0194:
    v0193 = v0019;
    v0179 = (LispObject)17; // 1
    if (v0193 == v0179) return onevalue(v0018);
    v0193 = v0018;
    v0179 = (LispObject)17; // 1
    if (v0193 == v0179) return onevalue(v0019);
    v0179 = elt(env, 2); // times
    v0193 = v0019;
    return list3(v0179, v0193, v0018);

v0178:
    v0179 = qvalue(elt(env, 1)); // t
    goto v0050;
}



// Code for evalletsub

static LispObject CC_evalletsub(LispObject env,
                         LispObject v0006, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0022, v0194, v0044;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evalletsub");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0007,v0006);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0006,v0007);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0022 = v0007;
    stack[0] = v0006;
// end of prologue
    v0194 = stack[0];
    fn = elt(env, 3); // evalletsub2
    v0022 = (*qfn2(fn))(qenv(fn), v0194, v0022);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-1];
    stack[0] = v0022;
    fn = elt(env, 4); // errorp
    v0022 = (*qfn1(fn))(qenv(fn), v0022);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-1];
    if (v0022 == nil) goto v0053;
    v0044 = elt(env, 1); // alg
    v0194 = (LispObject)385; // 24
    v0022 = elt(env, 2); // "Invalid simplification"
    {
        popv(2);
        fn = elt(env, 5); // rerror
        return (*qfnn(fn))(qenv(fn), 3, v0044, v0194, v0022);
    }

v0053:
    v0022 = stack[0];
    v0022 = qcar(v0022);
    { popv(2); return onevalue(v0022); }
// error exit handlers
v0209:
    popv(2);
    return nil;
}



// Code for revalpart

static LispObject CC_revalpart(LispObject env,
                         LispObject v0006)
{
    LispObject nil = C_nil;
    LispObject v0305, v0306, v0307, v0308, v0309;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for revalpart");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0006);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0006);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0006;
// end of prologue
    v0305 = stack[0];
    if (v0305 == nil) goto v0050;
    stack[-7] = qvalue(elt(env, 3)); // !*intstr
    qvalue(elt(env, 3)) = nil; // !*intstr
    stack[-6] = nil;
    v0305 = qvalue(elt(env, 4)); // t
    qvalue(elt(env, 3)) = v0305; // !*intstr
    v0305 = stack[0];
    v0305 = qcar(v0305);
    fn = elt(env, 12); // getrtype
    v0306 = (*qfn1(fn))(qenv(fn), v0305);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    env = stack[-8];
    stack[-3] = v0306;
    v0305 = elt(env, 5); // list
    if (v0306 == v0305) goto v0021;
    v0305 = stack[0];
    v0305 = qcar(v0305);
    fn = elt(env, 13); // reval
    v0305 = (*qfn1(fn))(qenv(fn), v0305);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    env = stack[-8];
    goto v0201;

v0201:
    stack[-5] = v0305;
    v0305 = qvalue(elt(env, 7)); // nil
    qvalue(elt(env, 3)) = v0305; // !*intstr
    v0305 = stack[0];
    v0305 = qcdr(v0305);
    stack[-4] = v0305;
    goto v0011;

v0011:
    v0305 = stack[-4];
    if (v0305 == nil) goto v0010;
    stack[-2] = nil;
    stack[-1] = nil;
    v0306 = stack[-5];
    v0305 = elt(env, 8); // !*hold
    v0305 = Leqcar(nil, v0306, v0305);
    env = stack[-8];
    stack[0] = v0305;
    v0305 = stack[-5];
    if (!consp(v0305)) goto v0067;
    v0305 = stack[-4];
    v0305 = qcar(v0305);
    fn = elt(env, 13); // reval
    v0305 = (*qfn1(fn))(qenv(fn), v0305);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    env = stack[-8];
    stack[-2] = v0305;
    if (is_number(v0305)) goto v0058;
    v0309 = elt(env, 9); // "Invalid argument"
    v0305 = stack[-4];
    v0308 = qcar(v0305);
    v0307 = elt(env, 10); // "to part"
    v0306 = qvalue(elt(env, 7)); // nil
    v0305 = qvalue(elt(env, 4)); // t
    fn = elt(env, 14); // msgpri
    v0305 = (*qfnn(fn))(qenv(fn), 5, v0309, v0308, v0307, v0306, v0305);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    env = stack[-8];
    goto v0284;

v0284:
    v0305 = stack[0];
    if (v0305 == nil) goto v0311;
    v0305 = stack[-1];
    v0305 = qcar(v0305);
    stack[-1] = v0305;
    v0305 = stack[-1];
    if (!consp(v0305)) goto v0312;
    v0305 = stack[-1];
    v0305 = qcdr(v0305);
    stack[-1] = v0305;
    goto v0311;

v0311:
    v0305 = stack[-6];
    if (!(v0305 == nil)) goto v0100;
    v0305 = stack[-1];
    v0306 = Llength(nil, v0305);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    env = stack[-8];
    v0305 = stack[-2];
    v0305 = (LispObject)lessp2(v0306, v0305);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    v0305 = v0305 ? lisp_true : nil;
    env = stack[-8];
    if (v0305 == nil) goto v0094;
    v0306 = stack[-5];
    v0305 = stack[-4];
    v0305 = qcar(v0305);
    fn = elt(env, 15); // parterr2
    v0305 = (*qfn2(fn))(qenv(fn), v0306, v0305);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    env = stack[-8];
    v0305 = qvalue(elt(env, 4)); // t
    stack[-6] = v0305;
    goto v0100;

v0100:
    v0305 = stack[-6];
    if (v0305 == nil) goto v0313;
    v0305 = qvalue(elt(env, 7)); // nil
    goto v0314;

v0314:
    stack[-4] = v0305;
    goto v0011;

v0313:
    v0305 = stack[-4];
    v0305 = qcdr(v0305);
    goto v0314;

v0094:
    v0305 = stack[0];
    if (v0305 == nil) goto v0250;
    v0306 = stack[-1];
    v0305 = stack[-2];
    fn = elt(env, 16); // nth
    v0305 = (*qfn2(fn))(qenv(fn), v0306, v0305);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    env = stack[-8];
    stack[-5] = v0305;
    v0305 = stack[-5];
    if (!consp(v0305)) goto v0217;
    v0306 = stack[-5];
    v0305 = elt(env, 8); // !*hold
    v0305 = Leqcar(nil, v0306, v0305);
    env = stack[-8];
    v0305 = (v0305 == nil ? lisp_true : nil);
    goto v0139;

v0139:
    if (v0305 == nil) goto v0100;
    v0306 = elt(env, 8); // !*hold
    v0305 = stack[-5];
    v0305 = list2(v0306, v0305);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    env = stack[-8];
    stack[-5] = v0305;
    goto v0100;

v0217:
    v0305 = qvalue(elt(env, 7)); // nil
    goto v0139;

v0250:
    v0306 = stack[-1];
    v0305 = stack[-2];
    fn = elt(env, 16); // nth
    v0305 = (*qfn2(fn))(qenv(fn), v0306, v0305);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    env = stack[-8];
    stack[0] = v0305;
    v0305 = stack[0];
    fn = elt(env, 12); // getrtype
    v0306 = (*qfn1(fn))(qenv(fn), v0305);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    env = stack[-8];
    v0305 = elt(env, 5); // list
    if (v0306 == v0305) goto v0249;
    v0305 = qvalue(elt(env, 7)); // nil
    goto v0248;

v0248:
    if (v0305 == nil) goto v0315;
    v0305 = stack[0];
    fn = elt(env, 17); // listeval0
    v0305 = (*qfn1(fn))(qenv(fn), v0305);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    env = stack[-8];
    goto v0316;

v0316:
    stack[-5] = v0305;
    goto v0100;

v0315:
    v0306 = stack[-3];
    v0305 = elt(env, 5); // list
    if (v0306 == v0305) goto v0317;
    v0305 = stack[0];
    goto v0316;

v0317:
    v0305 = qvalue(elt(env, 4)); // t
    qvalue(elt(env, 3)) = v0305; // !*intstr
    v0305 = stack[0];
    fn = elt(env, 13); // reval
    v0305 = (*qfn1(fn))(qenv(fn), v0305);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    env = stack[-8];
    stack[0] = v0305;
    v0305 = qvalue(elt(env, 7)); // nil
    stack[-3] = v0305;
    qvalue(elt(env, 3)) = v0305; // !*intstr
    v0305 = stack[0];
    goto v0316;

v0249:
    v0305 = elt(env, 5); // list
    stack[-3] = v0305;
    goto v0248;

v0312:
    v0306 = stack[-5];
    v0305 = stack[-4];
    v0305 = qcar(v0305);
    fn = elt(env, 15); // parterr2
    v0305 = (*qfn2(fn))(qenv(fn), v0306, v0305);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    env = stack[-8];
    v0305 = qvalue(elt(env, 4)); // t
    stack[-6] = v0305;
    goto v0311;

v0058:
    v0305 = stack[-5];
    v0306 = qcar(v0305);
    v0305 = elt(env, 11); // partop
    v0305 = get(v0306, v0305);
    env = stack[-8];
    stack[-1] = v0305;
    if (v0305 == nil) goto v0113;
    v0307 = stack[-1];
    v0306 = stack[-5];
    v0305 = stack[-2];
    v0305 = Lapply2(nil, 3, v0307, v0306, v0305);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    env = stack[-8];
    stack[-5] = v0305;
    v0305 = stack[-4];
    v0305 = qcdr(v0305);
    stack[-4] = v0305;
    goto v0011;

v0113:
    v0306 = stack[-2];
    v0305 = (LispObject)1; // 0
    if (v0306 == v0305) goto v0059;
    v0306 = stack[-2];
    v0305 = (LispObject)1; // 0
    v0305 = (LispObject)lessp2(v0306, v0305);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    v0305 = v0305 ? lisp_true : nil;
    env = stack[-8];
    if (v0305 == nil) goto v0271;
    v0305 = stack[-2];
    v0305 = negate(v0305);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    env = stack[-8];
    stack[-2] = v0305;
    v0305 = stack[-5];
    v0305 = qcdr(v0305);
    v0305 = Lreverse(nil, v0305);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    env = stack[-8];
    stack[-1] = v0305;
    goto v0284;

v0271:
    v0305 = stack[-5];
    v0305 = qcdr(v0305);
    stack[-1] = v0305;
    goto v0284;

v0059:
    v0305 = stack[-5];
    v0305 = qcar(v0305);
    stack[0] = v0305;
    v0305 = stack[0];
    fn = elt(env, 12); // getrtype
    v0306 = (*qfn1(fn))(qenv(fn), v0305);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    env = stack[-8];
    v0305 = elt(env, 5); // list
    if (v0306 == v0305) goto v0214;
    v0305 = qvalue(elt(env, 7)); // nil
    goto v0318;

v0318:
    if (v0305 == nil) goto v0138;
    v0305 = stack[0];
    fn = elt(env, 17); // listeval0
    v0305 = (*qfn1(fn))(qenv(fn), v0305);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    env = stack[-8];
    goto v0078;

v0078:
    stack[-5] = v0305;
    v0305 = qvalue(elt(env, 7)); // nil
    stack[-4] = v0305;
    goto v0011;

v0138:
    v0306 = stack[-3];
    v0305 = elt(env, 5); // list
    if (v0306 == v0305) goto v0140;
    v0305 = stack[0];
    goto v0078;

v0140:
    v0305 = qvalue(elt(env, 4)); // t
    qvalue(elt(env, 3)) = v0305; // !*intstr
    v0305 = stack[0];
    fn = elt(env, 13); // reval
    v0305 = (*qfn1(fn))(qenv(fn), v0305);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    env = stack[-8];
    stack[0] = v0305;
    v0305 = qvalue(elt(env, 7)); // nil
    stack[-3] = v0305;
    qvalue(elt(env, 3)) = v0305; // !*intstr
    v0305 = stack[0];
    goto v0078;

v0214:
    v0305 = elt(env, 5); // list
    stack[-3] = v0305;
    goto v0318;

v0067:
    v0306 = stack[-5];
    v0305 = stack[-4];
    v0305 = qcar(v0305);
    fn = elt(env, 15); // parterr2
    v0305 = (*qfn2(fn))(qenv(fn), v0306, v0305);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    env = stack[-8];
    v0305 = qvalue(elt(env, 4)); // t
    stack[-6] = v0305;
    goto v0284;

v0010:
    v0305 = stack[-6];
    if (v0305 == nil) goto v0319;
    v0305 = (LispObject)1; // 0
    goto v0208;

v0208:
    qvalue(elt(env, 3)) = stack[-7]; // !*intstr
    { popv(9); return onevalue(v0305); }

v0319:
    v0305 = stack[-5];
    fn = elt(env, 13); // reval
    v0305 = (*qfn1(fn))(qenv(fn), v0305);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    env = stack[-8];
    goto v0208;

v0021:
    v0305 = stack[0];
    v0305 = qcar(v0305);
    if (!consp(v0305)) goto v0040;
    v0305 = stack[0];
    v0305 = qcar(v0305);
    v0306 = qcar(v0305);
    v0305 = elt(env, 6); // listfn
    v0305 = get(v0306, v0305);
    env = stack[-8];
    goto v0169;

v0169:
    if (v0305 == nil) goto v0048;
    v0305 = stack[0];
    v0305 = qcar(v0305);
    fn = elt(env, 13); // reval
    v0305 = (*qfn1(fn))(qenv(fn), v0305);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    env = stack[-8];
    goto v0201;

v0048:
    v0305 = stack[0];
    v0305 = qcar(v0305);
    fn = elt(env, 17); // listeval0
    v0305 = (*qfn1(fn))(qenv(fn), v0305);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    env = stack[-8];
    goto v0201;

v0040:
    v0305 = qvalue(elt(env, 7)); // nil
    goto v0169;

v0050:
    v0307 = elt(env, 1); // alg
    v0306 = (LispObject)3217; // 201
    v0305 = elt(env, 2); // "part called without arguments"
    {
        popv(9);
        fn = elt(env, 18); // rerror
        return (*qfnn(fn))(qenv(fn), 3, v0307, v0306, v0305);
    }
// error exit handlers
v0310:
    env = stack[-8];
    qvalue(elt(env, 3)) = stack[-7]; // !*intstr
    popv(9);
    return nil;
}



// Code for simp!-prop!-dist

static LispObject CC_simpKpropKdist(LispObject env,
                         LispObject v0006)
{
    LispObject nil = C_nil;
    LispObject v0281, v0065, v0033;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for simp-prop-dist");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0006);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0006);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    v0065 = v0006;
// end of prologue
    v0033 = v0065;
    v0281 = elt(env, 1); // plus
    if (!consp(v0033)) goto v0133;
    v0033 = qcar(v0033);
    if (!(v0033 == v0281)) goto v0133;
    v0281 = v0065;
    v0281 = qcdr(v0281);
    v0065 = v0281;
    goto v0046;

v0046:
    v0281 = v0065;
    stack[-3] = v0281;
    v0281 = stack[-3];
    if (v0281 == nil) goto v0201;
    v0281 = stack[-3];
    v0281 = qcar(v0281);
    v0033 = v0281;
    v0065 = v0033;
    v0281 = elt(env, 3); // times
    if (!consp(v0065)) goto v0034;
    v0065 = qcar(v0065);
    if (!(v0065 == v0281)) goto v0034;
    v0281 = v0033;
    v0281 = qcdr(v0281);
    goto v0126;

v0126:
    v0033 = v0281;
    v0281 = v0033;
    v0281 = qcar(v0281);
    if (!(is_number(v0281))) goto v0193;
    v0281 = v0033;
    v0281 = qcdr(v0281);
    v0033 = v0281;
    goto v0193;

v0193:
    v0065 = v0033;
    v0281 = elt(env, 4); // lambda_u4r91xr6oyea
    fn = elt(env, 6); // sort
    v0281 = (*qfn2(fn))(qenv(fn), v0065, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0320;
    env = stack[-4];
    v0281 = ncons(v0281);
    nil = C_nil;
    if (exception_pending()) goto v0320;
    env = stack[-4];
    stack[-1] = v0281;
    stack[-2] = v0281;
    goto v0029;

v0029:
    v0281 = stack[-3];
    v0281 = qcdr(v0281);
    stack[-3] = v0281;
    v0281 = stack[-3];
    if (v0281 == nil) goto v0072;
    stack[0] = stack[-1];
    v0281 = stack[-3];
    v0281 = qcar(v0281);
    v0033 = v0281;
    v0065 = v0033;
    v0281 = elt(env, 3); // times
    if (!consp(v0065)) goto v0000;
    v0065 = qcar(v0065);
    if (!(v0065 == v0281)) goto v0000;
    v0281 = v0033;
    v0281 = qcdr(v0281);
    goto v0213;

v0213:
    v0033 = v0281;
    v0281 = v0033;
    v0281 = qcar(v0281);
    if (!(is_number(v0281))) goto v0167;
    v0281 = v0033;
    v0281 = qcdr(v0281);
    v0033 = v0281;
    goto v0167;

v0167:
    v0065 = v0033;
    v0281 = elt(env, 4); // lambda_u4r91xr6oyea
    fn = elt(env, 6); // sort
    v0281 = (*qfn2(fn))(qenv(fn), v0065, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0320;
    env = stack[-4];
    v0281 = ncons(v0281);
    nil = C_nil;
    if (exception_pending()) goto v0320;
    env = stack[-4];
    v0281 = Lrplacd(nil, stack[0], v0281);
    nil = C_nil;
    if (exception_pending()) goto v0320;
    env = stack[-4];
    v0281 = stack[-1];
    v0281 = qcdr(v0281);
    stack[-1] = v0281;
    goto v0029;

v0000:
    v0281 = v0033;
    v0281 = ncons(v0281);
    nil = C_nil;
    if (exception_pending()) goto v0320;
    env = stack[-4];
    goto v0213;

v0072:
    v0281 = stack[-2];
    goto v0127;

v0127:
    v0065 = v0281;
    v0281 = elt(env, 5); // simp!-prop!-order
    {
        popv(5);
        fn = elt(env, 6); // sort
        return (*qfn2(fn))(qenv(fn), v0065, v0281);
    }

v0034:
    v0281 = v0033;
    v0281 = ncons(v0281);
    nil = C_nil;
    if (exception_pending()) goto v0320;
    env = stack[-4];
    goto v0126;

v0201:
    v0281 = qvalue(elt(env, 2)); // nil
    goto v0127;

v0133:
    v0281 = v0065;
    v0281 = ncons(v0281);
    nil = C_nil;
    if (exception_pending()) goto v0320;
    env = stack[-4];
    v0065 = v0281;
    goto v0046;
// error exit handlers
v0320:
    popv(5);
    return nil;
}



// Code for lambda_u4r91xr6oyea

static LispObject CC_lambda_u4r91xr6oyea(LispObject env,
                         LispObject v0006, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0051, v0133;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lambda_u4r91xr6oyea");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0051 = v0007;
    v0133 = v0006;
// end of prologue
    v0133 = qcdr(v0133);
    v0133 = qcar(v0133);
    v0051 = qcdr(v0051);
    v0051 = qcar(v0051);
    {
        fn = elt(env, 1); // ordp
        return (*qfn2(fn))(qenv(fn), v0133, v0051);
    }
}



// Code for lambda_u4r91xr6oyea

static LispObject CC1_lambda_u4r91xr6oyea(LispObject env,
                         LispObject v0006, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0051, v0133;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lambda_u4r91xr6oyea");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0051 = v0007;
    v0133 = v0006;
// end of prologue
    v0133 = qcdr(v0133);
    v0133 = qcar(v0133);
    v0051 = qcdr(v0051);
    v0051 = qcar(v0051);
    {
        fn = elt(env, 1); // ordp
        return (*qfn2(fn))(qenv(fn), v0133, v0051);
    }
}



setup_type const u33_setup[] =
{
    {"fnreval",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_fnreval},
    {"evinsert",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_evinsert},
    {"weak_xreduce1",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_weak_xreduce1},
    {"formbool",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_formbool},
    {"gcdf2",                   too_few_2,      CC_gcdf2,      wrong_no_2},
    {"pa_list2vect",            too_few_2,      CC_pa_list2vect,wrong_no_2},
    {"get-current-representation",CC_getKcurrentKrepresentation,too_many_1,wrong_no_1},
    {"read-comment1",           CC_readKcomment1,too_many_1,   wrong_no_1},
    {"mri_2ofsfat",             CC_mri_2ofsfat, too_many_1,    wrong_no_1},
    {"repr_new",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_repr_new},
    {"transposerd",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_transposerd},
    {"znumrnil",                CC_znumrnil,    too_many_1,    wrong_no_1},
    {"dip2a",                   CC_dip2a,       too_many_1,    wrong_no_1},
    {"mod-dump1",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_modKdump1},
    {"*g2lex",                  CC_Hg2lex,      too_many_1,    wrong_no_1},
    {"appn",                    too_few_2,      CC_appn,       wrong_no_2},
    {"change+int+to+sq",        CC_changeLintLtoLsq,too_many_1,wrong_no_1},
    {"repr_ldeg",               CC_repr_ldeg,   too_many_1,    wrong_no_1},
    {"ofsf_smwcpknowl",         CC_ofsf_smwcpknowl,too_many_1, wrong_no_1},
    {"symbolsrd",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_symbolsrd},
    {"init",                    CC_init,        too_many_1,    wrong_no_1},
    {"evzero",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_evzero},
    {"get:const",               too_few_2,      CC_getTconst,  wrong_no_2},
    {"r2speclist1",             CC_r2speclist1, too_many_1,    wrong_no_1},
    {"ratnump",                 CC_ratnump,     too_many_1,    wrong_no_1},
    {"simpdfp",                 CC_simpdfp,     too_many_1,    wrong_no_1},
    {"equiv-coeffs",            too_few_2,      CC_equivKcoeffs,wrong_no_2},
    {"groeb=testc1",            CC_groebMtestc1,too_many_1,    wrong_no_1},
    {"lesspcar",                too_few_2,      CC_lesspcar,   wrong_no_2},
    {"simpquot",                CC_simpquot,    too_many_1,    wrong_no_1},
    {"make-image",              too_few_2,      CC_makeKimage, wrong_no_2},
    {"mk+resimp+mat",           CC_mkLresimpLmat,too_many_1,   wrong_no_1},
    {"diffrd",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_diffrd},
    {"simpsqrtsq",              CC_simpsqrtsq,  too_many_1,    wrong_no_1},
    {"ps:times-erule",          too_few_2,      CC_psTtimesKerule,wrong_no_2},
    {"findelem2",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_findelem2},
    {"evweightedcomp1",         too_few_2,      CC_evweightedcomp1,wrong_no_2},
    {"gbfdiff",                 too_few_2,      CC_gbfdiff,    wrong_no_2},
    {"cvitimes2",               too_few_2,      CC_cvitimes2,  wrong_no_2},
    {"evalletsub",              too_few_2,      CC_evalletsub, wrong_no_2},
    {"revalpart",               CC_revalpart,   too_many_1,    wrong_no_1},
    {"simp-prop-dist",          CC_simpKpropKdist,too_many_1,  wrong_no_1},
    {"lambda_u4r91xr6oyea",     too_few_2,      CC_lambda_u4r91xr6oyea,wrong_no_2},
    {"lambda_u4r91xr6oyea",     too_few_2,      CC1_lambda_u4r91xr6oyea,wrong_no_2},
    {NULL, (one_args *)"u33", (two_args *)"6657 8056562 7615728", 0}
};

// end of generated code
