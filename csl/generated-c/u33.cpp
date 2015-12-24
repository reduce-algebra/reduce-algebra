
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



// Code for evinvlexcomp

static LispObject CC_evinvlexcomp(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0013, v0014;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evinvlexcomp");
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

v0015:
    v0013 = stack[-1];
    if (v0013 == nil) goto v0016;
    v0013 = stack[0];
    if (v0013 == nil) goto v0017;
    v0013 = stack[-1];
    v0014 = qcar(v0013);
    v0013 = stack[0];
    v0013 = qcar(v0013);
    fn = elt(env, 2); // iequal
    v0013 = (*qfn2(fn))(qenv(fn), v0014, v0013);
    nil = C_nil;
    if (exception_pending()) goto v0018;
    env = stack[-3];
    if (v0013 == nil) goto v0019;
    v0013 = stack[-1];
    v0013 = qcdr(v0013);
    stack[-1] = v0013;
    v0013 = stack[0];
    v0013 = qcdr(v0013);
    stack[0] = v0013;
    goto v0015;

v0019:
    v0013 = stack[-1];
    v0014 = qcdr(v0013);
    v0013 = stack[0];
    v0013 = qcdr(v0013);
    v0013 = CC_evinvlexcomp(env, v0014, v0013);
    nil = C_nil;
    if (exception_pending()) goto v0018;
    env = stack[-3];
    stack[-2] = v0013;
    v0014 = stack[-2];
    v0013 = (LispObject)1; // 0
    fn = elt(env, 2); // iequal
    v0013 = (*qfn2(fn))(qenv(fn), v0014, v0013);
    nil = C_nil;
    if (exception_pending()) goto v0018;
    if (v0013 == nil) { LispObject res = stack[-2]; popv(4); return onevalue(res); }
    v0013 = stack[0];
    v0014 = qcar(v0013);
    v0013 = stack[-1];
    v0013 = qcar(v0013);
    if (((int32_t)(v0014)) > ((int32_t)(v0013))) goto v0020;
    v0013 = (LispObject)-15; // -1
    { popv(4); return onevalue(v0013); }

v0020:
    v0013 = (LispObject)17; // 1
    { popv(4); return onevalue(v0013); }

v0017:
    v0014 = stack[-1];
    v0013 = elt(env, 1); // (0)
    {
        popv(4);
        fn = elt(env, 3); // evlexcomp
        return (*qfn2(fn))(qenv(fn), v0014, v0013);
    }

v0016:
    v0013 = stack[0];
    if (v0013 == nil) goto v0021;
    v0013 = elt(env, 1); // (0)
    stack[-1] = v0013;
    goto v0015;

v0021:
    v0013 = (LispObject)1; // 0
    { popv(4); return onevalue(v0013); }
// error exit handlers
v0018:
    popv(4);
    return nil;
}



// Code for po!:statep

static LispObject CC_poTstatep(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0026, v0019, v0027;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for po:statep");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0027 = v0000;
// end of prologue
    v0026 = v0027;
    if (symbolp(v0026)) goto v0021;
    v0026 = qvalue(elt(env, 1)); // nil
    goto v0028;

v0028:
    if (!(v0026 == nil)) return onevalue(v0026);
    v0026 = v0027;
    if (!consp(v0026)) goto v0029;
    v0026 = v0027;
    v0026 = qcar(v0026);
    if (symbolp(v0026)) goto v0030;
    v0026 = qvalue(elt(env, 1)); // nil
    return onevalue(v0026);

v0030:
    v0026 = v0027;
    v0026 = qcar(v0026);
    if (!symbolp(v0026)) v0026 = nil;
    else { v0026 = qfastgets(v0026);
           if (v0026 != nil) { v0026 = elt(v0026, 18); // phystype
#ifdef RECORD_GET
             if (v0026 != SPID_NOPROP)
                record_get(elt(fastget_names, 18), 1);
             else record_get(elt(fastget_names, 18), 0),
                v0026 = nil; }
           else record_get(elt(fastget_names, 18), 0); }
#else
             if (v0026 == SPID_NOPROP) v0026 = nil; }}
#endif
    v0019 = elt(env, 2); // state
    v0026 = (v0026 == v0019 ? lisp_true : nil);
    return onevalue(v0026);

v0029:
    v0026 = qvalue(elt(env, 1)); // nil
    return onevalue(v0026);

v0021:
    v0026 = v0027;
    if (!symbolp(v0026)) v0019 = nil;
    else { v0019 = qfastgets(v0026);
           if (v0019 != nil) { v0019 = elt(v0019, 18); // phystype
#ifdef RECORD_GET
             if (v0019 != SPID_NOPROP)
                record_get(elt(fastget_names, 18), 1);
             else record_get(elt(fastget_names, 18), 0),
                v0019 = nil; }
           else record_get(elt(fastget_names, 18), 0); }
#else
             if (v0019 == SPID_NOPROP) v0019 = nil; }}
#endif
    v0026 = elt(env, 2); // state
    v0026 = (v0019 == v0026 ? lisp_true : nil);
    goto v0028;
}



// Code for find_buble

static LispObject CC_find_buble(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0033, v0034;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for find_buble");
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

v0035:
    v0033 = stack[0];
    if (v0033 == nil) goto v0015;
    v0034 = stack[-1];
    v0033 = stack[0];
    v0033 = qcar(v0033);
    fn = elt(env, 2); // is_buble
    v0033 = (*qfn2(fn))(qenv(fn), v0034, v0033);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    env = stack[-2];
    if (!(v0033 == nil)) { popv(3); return onevalue(v0033); }
    v0034 = stack[-1];
    v0033 = stack[0];
    v0033 = qcdr(v0033);
    stack[-1] = v0034;
    stack[0] = v0033;
    goto v0035;

v0015:
    v0033 = qvalue(elt(env, 1)); // nil
    { popv(3); return onevalue(v0033); }
// error exit handlers
v0030:
    popv(3);
    return nil;
}



// Code for assert_structstat

static LispObject CC_assert_structstat(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0060, v0061, v0062;
    LispObject fn;
    argcheck(nargs, 0, "assert_structstat");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for assert_structstat");
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
    fn = elt(env, 17); // scan
    v0060 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    env = stack[-5];
    stack[0] = v0060;
    stack[-1] = elt(env, 1); // flag
    v0060 = stack[0];
    v0060 = ncons(v0060);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    env = stack[-5];
    v0061 = Lmkquote(nil, v0060);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    env = stack[-5];
    v0060 = elt(env, 2); // (quote assert_dyntype)
    v0060 = list3(stack[-1], v0061, v0060);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    env = stack[-5];
    stack[-3] = v0060;
    fn = elt(env, 17); // scan
    v0060 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    env = stack[-5];
    v0060 = qvalue(elt(env, 3)); // cursym!*
    if (!symbolp(v0060)) v0060 = nil;
    else { v0060 = qfastgets(v0060);
           if (v0060 != nil) { v0060 = elt(v0060, 55); // delim
#ifdef RECORD_GET
             if (v0060 == SPID_NOPROP)
                record_get(elt(fastget_names, 55), 0),
                v0060 = nil;
             else record_get(elt(fastget_names, 55), 1),
                v0060 = lisp_true; }
           else record_get(elt(fastget_names, 55), 0); }
#else
             if (v0060 == SPID_NOPROP) v0060 = nil; else v0060 = lisp_true; }}
#endif
    if (v0060 == nil) goto v0064;
    v0060 = qvalue(elt(env, 4)); // !*msg
    if (v0060 == nil) { LispObject res = stack[-3]; popv(6); return onevalue(res); }
    v0062 = elt(env, 5); // "struct"
    v0061 = stack[0];
    v0060 = elt(env, 6); // "is not checked"
    v0060 = list3(v0062, v0061, v0060);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    env = stack[-5];
    fn = elt(env, 18); // lprim
    v0060 = (*qfn1(fn))(qenv(fn), v0060);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    { LispObject res = stack[-3]; popv(6); return onevalue(res); }

v0064:
    v0061 = qvalue(elt(env, 3)); // cursym!*
    v0060 = elt(env, 7); // checked
    if (v0061 == v0060) goto v0065;
    v0061 = qvalue(elt(env, 3)); // cursym!*
    v0060 = elt(env, 8); // asserted
    v0060 = Lneq(nil, v0061, v0060);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    env = stack[-5];
    goto v0027;

v0027:
    if (v0060 == nil) goto v0066;
    v0061 = elt(env, 10); // "expecting 'asserted by' in struct but found"
    v0060 = qvalue(elt(env, 3)); // cursym!*
    v0060 = list2(v0061, v0060);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    env = stack[-5];
    fn = elt(env, 19); // rederr
    v0060 = (*qfn1(fn))(qenv(fn), v0060);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    env = stack[-5];
    goto v0066;

v0066:
    fn = elt(env, 17); // scan
    v0061 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    env = stack[-5];
    v0060 = elt(env, 11); // by
    if (v0061 == v0060) goto v0067;
    v0061 = elt(env, 12); // "expecting 'by' in struct but found"
    v0060 = qvalue(elt(env, 3)); // cursym!*
    v0060 = list2(v0061, v0060);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    env = stack[-5];
    fn = elt(env, 19); // rederr
    v0060 = (*qfn1(fn))(qenv(fn), v0060);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    env = stack[-5];
    goto v0067;

v0067:
    fn = elt(env, 17); // scan
    v0060 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    env = stack[-5];
    stack[-4] = v0060;
    fn = elt(env, 17); // scan
    v0060 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    env = stack[-5];
    if (!symbolp(v0060)) v0060 = nil;
    else { v0060 = qfastgets(v0060);
           if (v0060 != nil) { v0060 = elt(v0060, 55); // delim
#ifdef RECORD_GET
             if (v0060 == SPID_NOPROP)
                record_get(elt(fastget_names, 55), 0),
                v0060 = nil;
             else record_get(elt(fastget_names, 55), 1),
                v0060 = lisp_true; }
           else record_get(elt(fastget_names, 55), 0); }
#else
             if (v0060 == SPID_NOPROP) v0060 = nil; else v0060 = lisp_true; }}
#endif
    if (!(v0060 == nil)) goto v0068;
    v0061 = elt(env, 13); // "expecting end of struct but found"
    v0060 = qvalue(elt(env, 3)); // cursym!*
    v0060 = list2(v0061, v0060);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    env = stack[-5];
    fn = elt(env, 19); // rederr
    v0060 = (*qfn1(fn))(qenv(fn), v0060);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    env = stack[-5];
    goto v0068;

v0068:
    stack[-2] = elt(env, 14); // put
    v0060 = stack[0];
    stack[-1] = Lmkquote(nil, v0060);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    env = stack[-5];
    stack[0] = elt(env, 15); // (quote assert_dyntypechk)
    v0060 = stack[-4];
    v0060 = Lmkquote(nil, v0060);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    env = stack[-5];
    v0060 = list4(stack[-2], stack[-1], stack[0], v0060);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    env = stack[-5];
    v0062 = elt(env, 16); // progn
    v0061 = v0060;
    v0060 = stack[-3];
    popv(6);
    return list3(v0062, v0061, v0060);

v0065:
    v0060 = qvalue(elt(env, 9)); // nil
    goto v0027;
// error exit handlers
v0063:
    popv(6);
    return nil;
}



// Code for subs2chk

static LispObject CC_subs2chk(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0017, v0070, v0071;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for subs2chk");
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
    v0017 = qvalue(elt(env, 1)); // subfg!*
    if (v0017 == nil) { LispObject res = stack[0]; popv(1); return onevalue(res); }
    v0017 = stack[0];
    fn = elt(env, 2); // subs2f
    v0017 = (*qfn1(fn))(qenv(fn), v0017);
    nil = C_nil;
    if (exception_pending()) goto v0072;
    v0071 = v0017;
    v0070 = qcdr(v0017);
    v0017 = (LispObject)17; // 1
    if (!(v0070 == v0017)) { LispObject res = stack[0]; popv(1); return onevalue(res); }
    v0017 = v0071;
    v0017 = qcar(v0017);
    stack[0] = v0017;
    { LispObject res = stack[0]; popv(1); return onevalue(res); }
// error exit handlers
v0072:
    popv(1);
    return nil;
}



// Code for fs!:prin

static LispObject CC_fsTprin(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0074, v0075;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for fs:prin");
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
    if (!(v0074 == nil)) goto v0021;
    v0074 = elt(env, 1); // " 0 "
    {
        popv(2);
        fn = elt(env, 4); // prin2!*
        return (*qfn1(fn))(qenv(fn), v0074);
    }

v0021:
    v0074 = stack[0];
    if (v0074 == nil) goto v0059;
    v0074 = stack[0];
    fn = elt(env, 5); // fs!:prin1
    v0074 = (*qfn1(fn))(qenv(fn), v0074);
    nil = C_nil;
    if (exception_pending()) goto v0009;
    env = stack[-1];
    v0075 = stack[0];
    v0074 = (LispObject)49; // 3
    v0074 = *(LispObject *)((char *)v0075 + (CELL-TAG_VECTOR) + ((int32_t)v0074/(16/CELL)));
    stack[0] = v0074;
    v0074 = stack[0];
    if (v0074 == nil) goto v0021;
    v0074 = elt(env, 3); // " + "
    fn = elt(env, 4); // prin2!*
    v0074 = (*qfn1(fn))(qenv(fn), v0074);
    nil = C_nil;
    if (exception_pending()) goto v0009;
    env = stack[-1];
    goto v0021;

v0059:
    v0074 = qvalue(elt(env, 2)); // nil
    { popv(2); return onevalue(v0074); }
// error exit handlers
v0009:
    popv(2);
    return nil;
}



// Code for dv_ind2var

static LispObject CC_dv_ind2var(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0078, v0079;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dv_ind2var");
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
    stack[-1] = stack[0];
    v0078 = qvalue(elt(env, 1)); // g_dvnames
    fn = elt(env, 3); // upbve
    v0078 = (*qfn1(fn))(qenv(fn), v0078);
    nil = C_nil;
    if (exception_pending()) goto v0075;
    env = stack[-2];
    v0078 = (LispObject)lesseq2(stack[-1], v0078);
    nil = C_nil;
    if (exception_pending()) goto v0075;
    v0078 = v0078 ? lisp_true : nil;
    env = stack[-2];
    if (v0078 == nil) goto v0073;
    stack[-1] = qvalue(elt(env, 1)); // g_dvnames
    v0078 = stack[0];
    v0078 = sub1(v0078);
    nil = C_nil;
    if (exception_pending()) goto v0075;
    v0078 = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v0078/(16/CELL)));
    { popv(3); return onevalue(v0078); }

v0073:
    v0079 = qvalue(elt(env, 2)); // g_dvbase
    v0078 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); // mkid
        return (*qfn2(fn))(qenv(fn), v0079, v0078);
    }
// error exit handlers
v0075:
    popv(3);
    return nil;
}



// Code for outer!-simpsqrt

static LispObject CC_outerKsimpsqrt(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0021, v0080;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for outer-simpsqrt");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0080 = v0000;
// end of prologue
    v0021 = qvalue(elt(env, 1)); // !*inside!-int!*
    if (v0021 == nil) goto v0081;
    v0021 = v0080;
    {
        fn = elt(env, 2); // proper!-simpsqrt
        return (*qfn1(fn))(qenv(fn), v0021);
    }

v0081:
    v0021 = v0080;
    {
        fn = elt(env, 3); // simpsqrt
        return (*qfn1(fn))(qenv(fn), v0021);
    }
}



// Code for msolve!-polyn

static LispObject CC_msolveKpolyn(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0120, v0121, v0122;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for msolve-polyn");
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
    push(nil);
// copy arguments values to proper place
    stack[-8] = v0001;
    stack[-9] = v0000;
// end of prologue
    v0120 = stack[-8];
    v0120 = qcar(v0120);
    stack[-10] = v0120;
    v0120 = stack[-8];
    v0120 = qcdr(v0120);
    if (v0120 == nil) goto v0021;
    v0120 = (LispObject)1; // 0
    stack[-7] = v0120;
    goto v0074;

v0074:
    v0120 = qvalue(elt(env, 1)); // current!-modulus
    v0121 = sub1(v0120);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-11];
    v0120 = stack[-7];
    v0120 = difference2(v0121, v0120);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-11];
    v0120 = Lminusp(nil, v0120);
    env = stack[-11];
    if (v0120 == nil) goto v0006;
    v0120 = qvalue(elt(env, 2)); // nil
    { popv(12); return onevalue(v0120); }

v0006:
    stack[0] = stack[-9];
    v0121 = stack[-10];
    v0120 = stack[-7];
    v0120 = cons(v0121, v0120);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-11];
    v0120 = ncons(v0120);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-11];
    fn = elt(env, 3); // subf
    v0120 = (*qfn2(fn))(qenv(fn), stack[0], v0120);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-11];
    v0121 = qcar(v0120);
    v0120 = stack[-8];
    v0120 = qcdr(v0120);
    v0120 = CC_msolveKpolyn(env, v0121, v0120);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-11];
    stack[-3] = v0120;
    v0120 = stack[-3];
    if (v0120 == nil) goto v0052;
    v0120 = stack[-3];
    v0120 = qcar(v0120);
    v0122 = stack[-10];
    v0121 = stack[-7];
    v0120 = acons(v0122, v0121, v0120);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-11];
    v0120 = ncons(v0120);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-11];
    stack[-1] = v0120;
    stack[-2] = v0120;
    goto v0027;

v0027:
    v0120 = stack[-3];
    v0120 = qcdr(v0120);
    stack[-3] = v0120;
    v0120 = stack[-3];
    if (v0120 == nil) goto v0124;
    stack[0] = stack[-1];
    v0120 = stack[-3];
    v0120 = qcar(v0120);
    v0122 = stack[-10];
    v0121 = stack[-7];
    v0120 = acons(v0122, v0121, v0120);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-11];
    v0120 = ncons(v0120);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-11];
    v0120 = Lrplacd(nil, stack[0], v0120);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-11];
    v0120 = stack[-1];
    v0120 = qcdr(v0120);
    stack[-1] = v0120;
    goto v0027;

v0124:
    v0120 = stack[-2];
    goto v0019;

v0019:
    stack[-6] = v0120;
    v0120 = stack[-6];
    fn = elt(env, 4); // lastpair
    v0120 = (*qfn1(fn))(qenv(fn), v0120);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-11];
    stack[-5] = v0120;
    v0120 = stack[-7];
    v0120 = add1(v0120);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-11];
    stack[-7] = v0120;
    v0120 = stack[-5];
    if (!consp(v0120)) goto v0074;
    else goto v0061;

v0061:
    v0120 = qvalue(elt(env, 1)); // current!-modulus
    v0121 = sub1(v0120);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-11];
    v0120 = stack[-7];
    v0120 = difference2(v0121, v0120);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-11];
    v0120 = Lminusp(nil, v0120);
    env = stack[-11];
    if (!(v0120 == nil)) { LispObject res = stack[-6]; popv(12); return onevalue(res); }
    stack[-4] = stack[-5];
    stack[0] = stack[-9];
    v0121 = stack[-10];
    v0120 = stack[-7];
    v0120 = cons(v0121, v0120);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-11];
    v0120 = ncons(v0120);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-11];
    fn = elt(env, 3); // subf
    v0120 = (*qfn2(fn))(qenv(fn), stack[0], v0120);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-11];
    v0121 = qcar(v0120);
    v0120 = stack[-8];
    v0120 = qcdr(v0120);
    v0120 = CC_msolveKpolyn(env, v0121, v0120);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-11];
    stack[-3] = v0120;
    v0120 = stack[-3];
    if (v0120 == nil) goto v0125;
    v0120 = stack[-3];
    v0120 = qcar(v0120);
    v0122 = stack[-10];
    v0121 = stack[-7];
    v0120 = acons(v0122, v0121, v0120);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-11];
    v0120 = ncons(v0120);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-11];
    stack[-1] = v0120;
    stack[-2] = v0120;
    goto v0126;

v0126:
    v0120 = stack[-3];
    v0120 = qcdr(v0120);
    stack[-3] = v0120;
    v0120 = stack[-3];
    if (v0120 == nil) goto v0127;
    stack[0] = stack[-1];
    v0120 = stack[-3];
    v0120 = qcar(v0120);
    v0122 = stack[-10];
    v0121 = stack[-7];
    v0120 = acons(v0122, v0121, v0120);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-11];
    v0120 = ncons(v0120);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-11];
    v0120 = Lrplacd(nil, stack[0], v0120);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-11];
    v0120 = stack[-1];
    v0120 = qcdr(v0120);
    stack[-1] = v0120;
    goto v0126;

v0127:
    v0120 = stack[-2];
    goto v0128;

v0128:
    v0120 = Lrplacd(nil, stack[-4], v0120);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-11];
    v0120 = stack[-5];
    fn = elt(env, 4); // lastpair
    v0120 = (*qfn1(fn))(qenv(fn), v0120);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-11];
    stack[-5] = v0120;
    v0120 = stack[-7];
    v0120 = add1(v0120);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-11];
    stack[-7] = v0120;
    goto v0061;

v0125:
    v0120 = qvalue(elt(env, 2)); // nil
    goto v0128;

v0052:
    v0120 = qvalue(elt(env, 2)); // nil
    goto v0019;

v0021:
    v0121 = stack[-9];
    v0120 = stack[-8];
    v0120 = qcar(v0120);
    {
        popv(12);
        fn = elt(env, 5); // msolve!-poly1
        return (*qfn2(fn))(qenv(fn), v0121, v0120);
    }
// error exit handlers
v0123:
    popv(12);
    return nil;
}



// Code for letexprn

static LispObject CC_letexprn(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0210, v0211, v0212;
    LispObject fn;
    LispObject v0015, v0040, v0039, v0045, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 6, "letexprn");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0045 = va_arg(aa, LispObject);
    v0039 = va_arg(aa, LispObject);
    v0040 = va_arg(aa, LispObject);
    v0015 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for letexprn");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push6(v0015,v0040,v0039,v0045,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v0000,v0001,v0045,v0039,v0040,v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0015;
    stack[-2] = v0040;
    stack[-3] = v0039;
    stack[-4] = v0045;
    stack[-5] = v0001;
    stack[-6] = v0000;
// end of prologue
    v0210 = stack[-3];
    v0211 = qcdr(v0210);
    v0210 = (LispObject)17; // 1
    if (v0211 == v0210) goto v0080;
    v0210 = stack[-3];
    v0210 = qcar(v0210);
    fn = elt(env, 16); // let!-prepf
    stack[-1] = (*qfn1(fn))(qenv(fn), v0210);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-8];
    stack[0] = elt(env, 1); // times
    v0210 = stack[-3];
    v0210 = qcdr(v0210);
    fn = elt(env, 16); // let!-prepf
    v0211 = (*qfn1(fn))(qenv(fn), v0210);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-8];
    v0210 = stack[-5];
    v0212 = list3(stack[0], v0211, v0210);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-8];
    v0211 = stack[-4];
    v0210 = stack[-2];
    {
        LispObject v0214 = stack[-1];
        popv(9);
        fn = elt(env, 17); // let2
        return (*qfnn(fn))(qenv(fn), 4, v0214, v0212, v0211, v0210);
    }

v0080:
    v0210 = stack[-3];
    v0210 = qcar(v0210);
    stack[-3] = v0210;
    v0210 = qcdr(v0210);
    if (v0210 == nil) goto v0215;
    v0210 = stack[-3];
    v0210 = qcar(v0210);
    v0210 = ncons(v0210);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-8];
    fn = elt(env, 16); // let!-prepf
    stack[-1] = (*qfn1(fn))(qenv(fn), v0210);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-8];
    stack[0] = elt(env, 2); // difference
    v0210 = stack[-3];
    v0210 = qcdr(v0210);
    fn = elt(env, 16); // let!-prepf
    v0210 = (*qfn1(fn))(qenv(fn), v0210);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-8];
    v0212 = list3(stack[0], stack[-5], v0210);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-8];
    v0211 = stack[-4];
    v0210 = stack[-2];
    {
        LispObject v0216 = stack[-1];
        popv(9);
        fn = elt(env, 17); // let2
        return (*qfnn(fn))(qenv(fn), 4, v0216, v0212, v0211, v0210);
    }

v0215:
    v0210 = stack[-3];
    fn = elt(env, 18); // kernlp
    v0210 = (*qfn1(fn))(qenv(fn), v0210);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-8];
    stack[0] = v0210;
    if (v0210 == nil) goto v0066;
    v0211 = stack[0];
    v0210 = (LispObject)17; // 1
    if (v0211 == v0210) goto v0077;
    v0211 = stack[-3];
    v0210 = stack[0];
    fn = elt(env, 19); // quotf!*
    v0210 = (*qfn2(fn))(qenv(fn), v0211, v0210);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-8];
    fn = elt(env, 16); // let!-prepf
    stack[-3] = (*qfn1(fn))(qenv(fn), v0210);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-8];
    stack[-1] = elt(env, 3); // quotient
    v0210 = stack[0];
    fn = elt(env, 16); // let!-prepf
    v0210 = (*qfn1(fn))(qenv(fn), v0210);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-8];
    v0212 = list3(stack[-1], stack[-5], v0210);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-8];
    v0211 = stack[-4];
    v0210 = stack[-2];
    {
        LispObject v0217 = stack[-3];
        popv(9);
        fn = elt(env, 17); // let2
        return (*qfnn(fn))(qenv(fn), 4, v0217, v0212, v0211, v0210);
    }

v0077:
    v0210 = stack[-3];
    fn = elt(env, 20); // klistt
    v0210 = (*qfn1(fn))(qenv(fn), v0210);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-8];
    stack[-3] = v0210;
    stack[-7] = stack[-4];
    v0210 = qvalue(elt(env, 4)); // mcond!*
    if (v0210 == nil) goto v0218;
    v0210 = qvalue(elt(env, 4)); // mcond!*
    stack[0] = v0210;
    goto v0219;

v0219:
    v0211 = stack[-5];
    v0210 = qvalue(elt(env, 6)); // nil
    v0210 = list2(v0211, v0210);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-8];
    v0210 = acons(stack[-7], stack[0], v0210);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-8];
    stack[0] = v0210;
    v0210 = stack[-3];
    v0210 = qcdr(v0210);
    if (v0210 == nil) goto v0220;
    fn = elt(env, 21); // rmsubs
    v0210 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-8];
    v0211 = stack[-3];
    v0210 = stack[0];
    v0212 = cons(v0211, v0210);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-8];
    v0211 = qvalue(elt(env, 7)); // !*match
    v0210 = stack[-2];
    fn = elt(env, 22); // xadd!*
    v0210 = (*qfnn(fn))(qenv(fn), 3, v0212, v0211, v0210);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-8];
    qvalue(elt(env, 7)) = v0210; // !*match
    { popv(9); return onevalue(v0210); }

v0220:
    v0210 = stack[-4];
    if (v0210 == nil) goto v0221;
    v0210 = qvalue(elt(env, 6)); // nil
    goto v0127;

v0127:
    if (v0210 == nil) goto v0222;
    v0210 = stack[-3];
    v0210 = qcar(v0210);
    v0210 = qcar(v0210);
    stack[-3] = v0210;
    v0210 = stack[-1];
    if (v0210 == nil) goto v0223;
    v0210 = qvalue(elt(env, 6)); // nil
    goto v0088;

v0088:
    if (v0210 == nil) goto v0089;
    v0210 = stack[-3];
    if (!consp(v0210)) goto v0224;
    stack[0] = elt(env, 8); // used!*
    v0210 = stack[-3];
    fn = elt(env, 23); // fkern
    v0210 = (*qfn1(fn))(qenv(fn), v0210);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-8];
    v0210 = qcdr(v0210);
    v0210 = qcdr(v0210);
    v0210 = Lmemq(nil, stack[0], v0210);
    if (!(v0210 == nil)) goto v0225;
    v0210 = stack[-3];
    v0211 = qcar(v0210);
    v0210 = elt(env, 9); // df
    if (!(v0211 == v0210)) goto v0226;

v0225:
    fn = elt(env, 21); // rmsubs
    v0210 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-8];
    goto v0226;

v0226:
    v0212 = stack[-3];
    v0211 = stack[-5];
    v0210 = stack[-2];
    fn = elt(env, 24); // setk1
    v0210 = (*qfnn(fn))(qenv(fn), 3, v0212, v0211, v0210);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    goto v0227;

v0227:
    v0210 = nil;
    { popv(9); return onevalue(v0210); }

v0224:
    v0211 = stack[-3];
    v0210 = elt(env, 8); // used!*
    v0210 = Lflagp(nil, v0211, v0210);
    env = stack[-8];
    if (v0210 == nil) goto v0226;
    fn = elt(env, 21); // rmsubs
    v0210 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-8];
    goto v0226;

v0089:
    v0210 = stack[-3];
    if (!consp(v0210)) goto v0228;
    fn = elt(env, 21); // rmsubs
    v0210 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-8];
    v0210 = stack[-3];
    stack[-4] = qcar(v0210);
    stack[-1] = elt(env, 10); // opmtch
    v0210 = stack[-3];
    v0211 = qcdr(v0210);
    v0210 = stack[0];
    v0212 = cons(v0211, v0210);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-8];
    v0210 = stack[-3];
    v0210 = qcar(v0210);
    if (!symbolp(v0210)) v0211 = nil;
    else { v0211 = qfastgets(v0210);
           if (v0211 != nil) { v0211 = elt(v0211, 9); // opmtch
#ifdef RECORD_GET
             if (v0211 != SPID_NOPROP)
                record_get(elt(fastget_names, 9), 1);
             else record_get(elt(fastget_names, 9), 0),
                v0211 = nil; }
           else record_get(elt(fastget_names, 9), 0); }
#else
             if (v0211 == SPID_NOPROP) v0211 = nil; }}
#endif
    v0210 = stack[-2];
    fn = elt(env, 22); // xadd!*
    v0210 = (*qfnn(fn))(qenv(fn), 3, v0212, v0211, v0210);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-8];
    v0210 = Lputprop(nil, 3, stack[-4], stack[-1], v0210);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    goto v0227;

v0228:
    v0210 = stack[-6];
    {
        popv(9);
        fn = elt(env, 25); // errpri1
        return (*qfn1(fn))(qenv(fn), v0210);
    }

v0223:
    v0210 = qvalue(elt(env, 4)); // mcond!*
    if (v0210 == nil) goto v0229;
    v0211 = qvalue(elt(env, 4)); // mcond!*
    v0210 = lisp_true;
    if (v0211 == v0210) goto v0230;
    v0211 = stack[-3];
    v0210 = qvalue(elt(env, 4)); // mcond!*
    fn = elt(env, 26); // smember
    v0210 = (*qfn2(fn))(qenv(fn), v0211, v0210);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-8];
    v0210 = (v0210 == nil ? lisp_true : nil);
    goto v0088;

v0230:
    v0210 = qvalue(elt(env, 5)); // t
    goto v0088;

v0229:
    v0210 = qvalue(elt(env, 5)); // t
    goto v0088;

v0222:
    fn = elt(env, 21); // rmsubs
    v0210 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-8];
    v0211 = stack[-5];
    v0210 = (LispObject)1; // 0
    if (v0211 == v0210) goto v0231;
    v0210 = qvalue(elt(env, 6)); // nil
    goto v0232;

v0232:
    if (v0210 == nil) goto v0233;
    v0210 = stack[-3];
    v0212 = qcar(v0210);
    v0211 = qvalue(elt(env, 11)); // asymplis!*
    v0210 = stack[-2];
    fn = elt(env, 27); // xadd
    v0210 = (*qfnn(fn))(qenv(fn), 3, v0212, v0211, v0210);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-8];
    qvalue(elt(env, 11)) = v0210; // asymplis!*
    v0210 = stack[-3];
    v0210 = qcar(v0210);
    v0212 = qcar(v0210);
    v0210 = stack[-3];
    v0210 = qcar(v0210);
    v0211 = qcdr(v0210);
    v0210 = stack[0];
    v0212 = list2star(v0212, v0211, v0210);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-8];
    v0211 = qvalue(elt(env, 12)); // powlis!*
    v0210 = elt(env, 13); // replace
    fn = elt(env, 27); // xadd
    v0210 = (*qfnn(fn))(qenv(fn), 3, v0212, v0211, v0210);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-8];
    qvalue(elt(env, 12)) = v0210; // powlis!*
    goto v0227;

v0233:
    v0210 = stack[-4];
    if (!(v0210 == nil)) goto v0234;
    v0210 = stack[0];
    v0210 = qcar(v0210);
    v0211 = qcdr(v0210);
    v0210 = qvalue(elt(env, 5)); // t
    if (v0211 == v0210) goto v0235;
    v0210 = qvalue(elt(env, 5)); // t
    goto v0236;

v0236:
    if (!(v0210 == nil)) goto v0234;
    v0210 = stack[-2];
    if (v0210 == nil) goto v0237;
    v0210 = qvalue(elt(env, 6)); // nil
    goto v0238;

v0238:
    if (v0210 == nil) goto v0239;
    v0210 = stack[-3];
    v0210 = qcar(v0210);
    v0211 = qcar(v0210);
    v0210 = qvalue(elt(env, 11)); // asymplis!*
    fn = elt(env, 28); // delasc
    v0210 = (*qfn2(fn))(qenv(fn), v0211, v0210);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-8];
    qvalue(elt(env, 11)) = v0210; // asymplis!*
    goto v0227;

v0239:
    v0210 = stack[-3];
    v0210 = qcar(v0210);
    v0212 = qcar(v0210);
    v0210 = stack[-3];
    v0210 = qcar(v0210);
    v0211 = qcdr(v0210);
    v0210 = stack[0];
    v0212 = list2star(v0212, v0211, v0210);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-8];
    v0211 = qvalue(elt(env, 12)); // powlis!*
    v0210 = stack[-2];
    fn = elt(env, 27); // xadd
    v0210 = (*qfnn(fn))(qenv(fn), 3, v0212, v0211, v0210);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-8];
    qvalue(elt(env, 12)) = v0210; // powlis!*
    v0210 = stack[-2];
    if (v0210 == nil) goto v0227;
    v0210 = stack[-3];
    v0210 = qcar(v0210);
    v0211 = qcar(v0210);
    v0210 = qvalue(elt(env, 11)); // asymplis!*
    fn = elt(env, 28); // delasc
    v0210 = (*qfn2(fn))(qenv(fn), v0211, v0210);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-8];
    qvalue(elt(env, 11)) = v0210; // asymplis!*
    goto v0227;

v0237:
    v0210 = stack[-3];
    v0210 = qcar(v0210);
    v0211 = qcar(v0210);
    v0210 = qvalue(elt(env, 11)); // asymplis!*
    v0210 = Lassoc(nil, v0211, v0210);
    v0211 = v0210;
    if (v0210 == nil) goto v0240;
    v0210 = stack[-3];
    v0210 = qcar(v0210);
    v0210 = (equal(v0211, v0210) ? lisp_true : nil);
    goto v0238;

v0240:
    v0210 = qvalue(elt(env, 6)); // nil
    goto v0238;

v0234:
    v0210 = stack[-3];
    v0211 = qcar(v0210);
    v0210 = stack[0];
    v0212 = cons(v0211, v0210);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-8];
    v0211 = qvalue(elt(env, 15)); // powlis1!*
    v0210 = stack[-2];
    fn = elt(env, 27); // xadd
    v0210 = (*qfnn(fn))(qenv(fn), 3, v0212, v0211, v0210);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-8];
    qvalue(elt(env, 15)) = v0210; // powlis1!*
    goto v0227;

v0235:
    v0210 = qvalue(elt(env, 14)); // frasc!*
    goto v0236;

v0231:
    v0210 = stack[-4];
    if (v0210 == nil) goto v0241;
    v0210 = qvalue(elt(env, 6)); // nil
    goto v0232;

v0241:
    v0210 = stack[-1];
    v0210 = (v0210 == nil ? lisp_true : nil);
    goto v0232;

v0221:
    v0210 = stack[-3];
    v0210 = qcar(v0210);
    v0211 = qcdr(v0210);
    v0210 = (LispObject)17; // 1
    v0210 = (v0211 == v0210 ? lisp_true : nil);
    goto v0127;

v0218:
    v0210 = qvalue(elt(env, 5)); // t
    stack[0] = v0210;
    goto v0219;

v0066:
    v0210 = stack[-3];
    fn = elt(env, 29); // term!-split
    v0210 = (*qfn1(fn))(qenv(fn), v0210);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-8];
    stack[0] = v0210;
    v0210 = stack[0];
    v0210 = qcar(v0210);
    fn = elt(env, 16); // let!-prepf
    stack[-3] = (*qfn1(fn))(qenv(fn), v0210);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-8];
    stack[-1] = elt(env, 2); // difference
    v0210 = stack[0];
    v0210 = qcdr(v0210);
    fn = elt(env, 16); // let!-prepf
    v0210 = (*qfn1(fn))(qenv(fn), v0210);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-8];
    v0212 = list3(stack[-1], stack[-5], v0210);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-8];
    v0211 = stack[-4];
    v0210 = stack[-2];
    {
        LispObject v0242 = stack[-3];
        popv(9);
        fn = elt(env, 17); // let2
        return (*qfnn(fn))(qenv(fn), 4, v0242, v0212, v0211, v0210);
    }
// error exit handlers
v0213:
    popv(9);
    return nil;
}



// Code for vector!-to!-poly

static LispObject CC_vectorKtoKpoly(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0018, v0247, v0113;
    LispObject fn;
    LispObject v0045, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "vector-to-poly");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0045 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vector-to-poly");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0045,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0045);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0045;
    stack[-2] = v0001;
    stack[-3] = v0000;
// end of prologue
    v0247 = stack[-2];
    v0018 = (LispObject)1; // 0
    if (((int32_t)(v0247)) < ((int32_t)(v0018))) goto v0081;
    v0247 = stack[-3];
    v0018 = (LispObject)1; // 0
    v0018 = *(LispObject *)((char *)v0247 + (CELL-TAG_VECTOR) + ((int32_t)v0018/(16/CELL)));
    fn = elt(env, 2); // !*n2f
    v0018 = (*qfn1(fn))(qenv(fn), v0018);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-5];
    stack[-4] = v0018;
    v0018 = (LispObject)17; // 1
    stack[0] = v0018;
    goto v0248;

v0248:
    v0247 = stack[-2];
    v0018 = stack[0];
    v0018 = difference2(v0247, v0018);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-5];
    v0018 = Lminusp(nil, v0018);
    env = stack[-5];
    if (!(v0018 == nil)) { LispObject res = stack[-4]; popv(6); return onevalue(res); }
    v0247 = stack[-3];
    v0018 = stack[0];
    v0247 = *(LispObject *)((char *)v0247 + (CELL-TAG_VECTOR) + ((int32_t)v0018/(16/CELL)));
    v0018 = (LispObject)1; // 0
    if (v0247 == v0018) goto v0109;
    v0247 = stack[-1];
    v0018 = stack[0];
    fn = elt(env, 3); // to
    v0113 = (*qfn2(fn))(qenv(fn), v0247, v0018);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-5];
    v0247 = stack[-3];
    v0018 = stack[0];
    v0247 = *(LispObject *)((char *)v0247 + (CELL-TAG_VECTOR) + ((int32_t)v0018/(16/CELL)));
    v0018 = stack[-4];
    v0018 = acons(v0113, v0247, v0018);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-5];
    stack[-4] = v0018;
    goto v0109;

v0109:
    v0018 = stack[0];
    v0018 = add1(v0018);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-5];
    stack[0] = v0018;
    goto v0248;

v0081:
    v0018 = qvalue(elt(env, 1)); // nil
    { popv(6); return onevalue(v0018); }
// error exit handlers
v0202:
    popv(6);
    return nil;
}



// Code for rl_transform

static LispObject CC_rl_transform(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0010, v0057, v0022, v0209, v0029, v0110, v0109;
    LispObject fn;
    LispObject v0028, v0015, v0040, v0039, v0045, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 7, "rl_transform");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0045 = va_arg(aa, LispObject);
    v0039 = va_arg(aa, LispObject);
    v0040 = va_arg(aa, LispObject);
    v0015 = va_arg(aa, LispObject);
    v0028 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rl_transform");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push6(v0028,v0015,v0040,v0039,v0045,v0001);
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v0000,v0001,v0045,v0039,v0040,v0015);
        pop(v0028);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    v0010 = v0028;
    v0057 = v0015;
    v0022 = v0040;
    v0209 = v0039;
    v0029 = v0045;
    v0110 = v0001;
    v0109 = v0000;
// end of prologue
    stack[-3] = qvalue(elt(env, 1)); // rl_transform!*
    stack[-2] = v0109;
    stack[-1] = v0110;
    stack[0] = v0029;
    v0010 = list4(v0209, v0022, v0057, v0010);
    nil = C_nil;
    if (exception_pending()) goto v0250;
    env = stack[-4];
    v0010 = list3star(stack[-2], stack[-1], stack[0], v0010);
    nil = C_nil;
    if (exception_pending()) goto v0250;
    env = stack[-4];
    {
        LispObject v0064 = stack[-3];
        popv(5);
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(qenv(fn), v0064, v0010);
    }
// error exit handlers
v0250:
    popv(5);
    return nil;
}



// Code for plusdf

static LispObject CC_plusdf(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0256, v0257, v0258;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for plusdf");
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
    stack[0] = nil;
    goto v0028;

v0028:
    v0256 = stack[-2];
    if (v0256 == nil) goto v0021;
    v0256 = stack[-1];
    if (v0256 == nil) goto v0017;
    v0256 = stack[-2];
    v0256 = qcar(v0256);
    v0257 = qcar(v0256);
    v0256 = stack[-1];
    v0256 = qcar(v0256);
    v0256 = qcar(v0256);
    if (equal(v0257, v0256)) goto v0209;
    v0256 = stack[-2];
    v0256 = qcar(v0256);
    v0257 = qcar(v0256);
    v0256 = stack[-1];
    v0256 = qcar(v0256);
    v0256 = qcar(v0256);
    fn = elt(env, 1); // orddf
    v0256 = (*qfn2(fn))(qenv(fn), v0257, v0256);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-4];
    if (v0256 == nil) goto v0108;
    v0256 = stack[-2];
    v0257 = qcar(v0256);
    v0256 = stack[0];
    v0256 = cons(v0257, v0256);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-4];
    stack[0] = v0256;
    v0256 = stack[-2];
    v0256 = qcdr(v0256);
    stack[-2] = v0256;
    goto v0028;

v0108:
    v0256 = stack[-1];
    v0257 = qcar(v0256);
    v0256 = stack[0];
    v0256 = cons(v0257, v0256);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-4];
    stack[0] = v0256;
    v0256 = stack[-1];
    v0256 = qcdr(v0256);
    stack[-1] = v0256;
    goto v0028;

v0209:
    stack[-3] = stack[0];
    v0256 = stack[-2];
    v0256 = qcar(v0256);
    v0257 = qcdr(v0256);
    v0256 = stack[-1];
    v0256 = qcar(v0256);
    v0256 = qcdr(v0256);
    fn = elt(env, 2); // !*addsq
    stack[0] = (*qfn2(fn))(qenv(fn), v0257, v0256);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-4];
    v0256 = stack[-2];
    v0257 = qcdr(v0256);
    v0256 = stack[-1];
    v0256 = qcdr(v0256);
    v0256 = CC_plusdf(env, v0257, v0256);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-4];
    v0257 = stack[0];
    v0258 = v0257;
    v0258 = qcar(v0258);
    if (v0258 == nil) goto v0109;
    v0258 = stack[-2];
    v0258 = qcar(v0258);
    v0258 = qcar(v0258);
    v0256 = acons(v0258, v0257, v0256);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-4];
    goto v0109;

v0109:
    {
        LispObject v0038 = stack[-3];
        popv(5);
        fn = elt(env, 3); // nreverse
        return (*qfn2(fn))(qenv(fn), v0038, v0256);
    }

v0017:
    v0257 = stack[0];
    v0256 = stack[-2];
    {
        popv(5);
        fn = elt(env, 3); // nreverse
        return (*qfn2(fn))(qenv(fn), v0257, v0256);
    }

v0021:
    v0257 = stack[0];
    v0256 = stack[-1];
    {
        popv(5);
        fn = elt(env, 3); // nreverse
        return (*qfn2(fn))(qenv(fn), v0257, v0256);
    }
// error exit handlers
v0036:
    popv(5);
    return nil;
}



// Code for get!*inverse

static LispObject CC_getHinverse(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0033, v0034, v0078;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for get*inverse");
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
    v0034 = v0001;
    v0033 = v0000;
// end of prologue
    v0078 = v0033;
    v0033 = elt(env, 1); // inverse
    v0033 = get(v0078, v0033);
    env = stack[-1];
    v0078 = v0033;
    v0033 = v0078;
    v0033 = qcdr(v0033);
    stack[0] = qcar(v0033);
    v0033 = v0034;
    v0034 = v0078;
    v0034 = qcar(v0034);
    fn = elt(env, 2); // give!*position
    v0033 = (*qfn2(fn))(qenv(fn), v0033, v0034);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    env = stack[-1];
    {
        LispObject v0074 = stack[0];
        popv(2);
        fn = elt(env, 3); // nth
        return (*qfn2(fn))(qenv(fn), v0074, v0033);
    }
// error exit handlers
v0030:
    popv(2);
    return nil;
}



// Code for pasf_anegrel

static LispObject CC_pasf_anegrel(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0084, v0017, v0070;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pasf_anegrel");
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
    v0070 = v0000;
// end of prologue
    v0017 = v0070;
    v0084 = elt(env, 1); // ((equal . equal) (neq . neq) (leq . geq) (geq . leq) (lessp . greaterp) (greaterp . lessp) (cong . cong) (ncong . ncong))
    v0084 = Latsoc(nil, v0017, v0084);
    v0084 = qcdr(v0084);
    if (!(v0084 == nil)) { popv(1); return onevalue(v0084); }
    v0084 = elt(env, 2); // "pasf_anegrel: unknown operator "
    v0017 = v0070;
    v0084 = list2(v0084, v0017);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); // rederr
        return (*qfn1(fn))(qenv(fn), v0084);
    }
// error exit handlers
v0071:
    popv(1);
    return nil;
}



// Code for aex_subrat1

static LispObject CC_aex_subrat1(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0009, v0023, v0010;
    LispObject fn;
    LispObject v0045, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "aex_subrat1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0045 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for aex_subrat1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0045,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0045);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0045;
    stack[-1] = v0001;
    stack[-2] = v0000;
// end of prologue
    v0009 = stack[-2];
    fn = elt(env, 1); // aex_ex
    v0009 = (*qfn1(fn))(qenv(fn), v0009);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-3];
    v0010 = qcar(v0009);
    v0023 = stack[-1];
    v0009 = stack[0];
    fn = elt(env, 2); // sfto_qsubhor1
    v0009 = (*qfnn(fn))(qenv(fn), 3, v0010, v0023, v0009);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-3];
    stack[-1] = v0009;
    v0009 = qcar(v0009);
    fn = elt(env, 3); // kernels
    stack[0] = (*qfn1(fn))(qenv(fn), v0009);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-3];
    v0009 = stack[-2];
    fn = elt(env, 4); // aex_ctx
    v0009 = (*qfn1(fn))(qenv(fn), v0009);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-3];
    fn = elt(env, 5); // ctx_filter
    v0009 = (*qfn2(fn))(qenv(fn), stack[0], v0009);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-3];
    {
        LispObject v0110 = stack[-1];
        popv(4);
        fn = elt(env, 6); // aex_mk
        return (*qfn2(fn))(qenv(fn), v0110, v0009);
    }
// error exit handlers
v0029:
    popv(4);
    return nil;
}



// Code for cgp_lbc

static LispObject CC_cgp_lbc(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0015;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cgp_lbc");
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
    v0015 = v0000;
// end of prologue
    fn = elt(env, 1); // cgp_rp
    v0015 = (*qfn1(fn))(qenv(fn), v0015);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); // dip_lbc
        return (*qfn1(fn))(qenv(fn), v0015);
    }
// error exit handlers
v0028:
    popv(1);
    return nil;
}



// Code for listrd

static LispObject CC_listrd(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0051, v0262, v0018;
    LispObject fn;
    argcheck(nargs, 0, "listrd");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for listrd");
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
    v0262 = qvalue(elt(env, 1)); // atts
    v0051 = elt(env, 2); // (o r d e r)
    fn = elt(env, 11); // search_att
    v0051 = (*qfn2(fn))(qenv(fn), v0262, v0051);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-2];
    stack[-1] = v0051;
    v0051 = elt(env, 3); // (t y p e != l i s t !$)
    qvalue(elt(env, 1)) = v0051; // atts
    stack[0] = elt(env, 4); // list
    fn = elt(env, 12); // stats_getargs
    v0051 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-2];
    v0051 = cons(stack[0], v0051);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-2];
    v0262 = v0051;
    stack[0] = v0262;
    v0018 = stack[-1];
    v0262 = elt(env, 5); // (l e x i c o g r a p h i c)
    if (!(equal(v0018, v0262))) goto v0027;
    v0262 = elt(env, 6); // sortlist
    v0018 = v0051;
    v0051 = elt(env, 7); // lexog
    v0051 = list3(v0262, v0018, v0051);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-2];
    fn = elt(env, 13); // aeval
    v0051 = (*qfn1(fn))(qenv(fn), v0051);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-2];
    goto v0027;

v0027:
    v0018 = stack[-1];
    v0262 = elt(env, 8); // (n u m e r i c)
    if (equal(v0018, v0262)) goto v0056;
    v0018 = elt(env, 6); // sortlist
    v0262 = v0051;
    v0051 = elt(env, 10); // pred
    v0051 = list3(v0018, v0262, v0051);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-2];
    fn = elt(env, 13); // aeval
    v0051 = (*qfn1(fn))(qenv(fn), v0051);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    goto v0109;

v0109:
    v0262 = v0051;
    if (!(v0262 == nil)) { popv(3); return onevalue(v0051); }
    v0051 = stack[0];
    { popv(3); return onevalue(v0051); }

v0056:
    v0018 = elt(env, 6); // sortlist
    v0262 = v0051;
    v0051 = elt(env, 9); // numer
    v0051 = list3(v0018, v0262, v0051);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-2];
    fn = elt(env, 13); // aeval
    v0051 = (*qfn1(fn))(qenv(fn), v0051);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    goto v0109;
// error exit handlers
v0111:
    popv(3);
    return nil;
}



// Code for delyzz

static LispObject CC_delyzz(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0010, v0057, v0022;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for delyzz");
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
    v0022 = nil;
    goto v0260;

v0260:
    v0057 = stack[-1];
    v0010 = stack[0];
    v0010 = qcar(v0010);
    v0010 = qcar(v0010);
    if (equal(v0057, v0010)) goto v0076;
    v0010 = stack[0];
    v0010 = qcar(v0010);
    v0057 = v0022;
    v0010 = cons(v0010, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-2];
    v0022 = v0010;
    v0010 = stack[0];
    v0010 = qcdr(v0010);
    stack[0] = v0010;
    goto v0260;

v0076:
    v0057 = v0022;
    v0010 = stack[0];
    v0010 = qcdr(v0010);
    {
        popv(3);
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(qenv(fn), v0057, v0010);
    }
// error exit handlers
v0110:
    popv(3);
    return nil;
}



// Code for unplus

static LispObject CC_unplus(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0207, v0066, v0114;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for unplus");
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
    v0114 = nil;
    goto v0015;

v0015:
    v0207 = stack[-1];
    if (!consp(v0207)) goto v0077;
    v0207 = stack[-1];
    v0066 = qcar(v0207);
    v0207 = elt(env, 1); // plus
    if (v0066 == v0207) goto v0069;
    v0207 = stack[-1];
    v0207 = qcar(v0207);
    if (!consp(v0207)) goto v0079;
    v0207 = stack[-1];
    v0066 = qcar(v0207);
    v0207 = elt(env, 1); // plus
    v0207 = Leqcar(nil, v0066, v0207);
    env = stack[-3];
    v0207 = (v0207 == nil ? lisp_true : nil);
    goto v0078;

v0078:
    if (v0207 == nil) goto v0206;
    v0207 = stack[-1];
    v0207 = qcar(v0207);
    v0066 = v0114;
    v0207 = cons(v0207, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-3];
    v0114 = v0207;
    v0207 = stack[-1];
    v0207 = qcdr(v0207);
    stack[-1] = v0207;
    goto v0015;

v0206:
    stack[-2] = v0114;
    v0207 = stack[-1];
    v0207 = qcar(v0207);
    stack[0] = qcdr(v0207);
    v0207 = stack[-1];
    v0207 = qcdr(v0207);
    v0207 = CC_unplus(env, v0207);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-3];
    v0207 = Lappend(nil, stack[0], v0207);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-3];
    {
        LispObject v0051 = stack[-2];
        popv(4);
        fn = elt(env, 3); // nreverse
        return (*qfn2(fn))(qenv(fn), v0051, v0207);
    }

v0079:
    v0207 = qvalue(elt(env, 2)); // t
    goto v0078;

v0069:
    v0207 = stack[-1];
    v0207 = qcdr(v0207);
    stack[-1] = v0207;
    goto v0015;

v0077:
    v0066 = v0114;
    v0207 = stack[-1];
    {
        popv(4);
        fn = elt(env, 3); // nreverse
        return (*qfn2(fn))(qenv(fn), v0066, v0207);
    }
// error exit handlers
v0050:
    popv(4);
    return nil;
}



// Code for convprc2

static LispObject CC_convprc2(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0014, v0050, v0051;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for convprc2");
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
    v0014 = stack[-1];
    fn = elt(env, 4); // convprec
    v0014 = (*qfn1(fn))(qenv(fn), v0014);
    nil = C_nil;
    if (exception_pending()) goto v0247;
    env = stack[-2];
    stack[-1] = v0014;
    v0014 = stack[0];
    fn = elt(env, 4); // convprec
    v0014 = (*qfn1(fn))(qenv(fn), v0014);
    nil = C_nil;
    if (exception_pending()) goto v0247;
    env = stack[-2];
    qvalue(elt(env, 1)) = v0014; // yy!!
    v0014 = qvalue(elt(env, 2)); // !*roundbf
    if (v0014 == nil) { LispObject res = stack[-1]; popv(3); return onevalue(res); }
    v0014 = qvalue(elt(env, 1)); // yy!!
    v0050 = v0014;
    v0050 = Lfloatp(nil, v0050);
    env = stack[-2];
    if (v0050 == nil) goto v0031;
    fn = elt(env, 5); // fl2bf
    v0014 = (*qfn1(fn))(qenv(fn), v0014);
    nil = C_nil;
    if (exception_pending()) goto v0247;
    env = stack[-2];
    goto v0249;

v0249:
    qvalue(elt(env, 1)) = v0014; // yy!!
    v0014 = stack[-1];
    v0014 = Lfloatp(nil, v0014);
    env = stack[-2];
    if (v0014 == nil) goto v0008;
    v0014 = stack[-1];
    {
        popv(3);
        fn = elt(env, 5); // fl2bf
        return (*qfn1(fn))(qenv(fn), v0014);
    }

v0008:
    v0014 = stack[-1];
    if (!consp(v0014)) goto v0117;
    v0014 = stack[-1];
    goto v0246;

v0246:
    {
        popv(3);
        fn = elt(env, 6); // normbf
        return (*qfn1(fn))(qenv(fn), v0014);
    }

v0117:
    v0014 = stack[-1];
    v0014 = integerp(v0014);
    if (v0014 == nil) goto v0067;
    v0051 = elt(env, 3); // !:rd!:
    v0050 = stack[-1];
    v0014 = (LispObject)1; // 0
    v0014 = list2star(v0051, v0050, v0014);
    nil = C_nil;
    if (exception_pending()) goto v0247;
    env = stack[-2];
    goto v0246;

v0067:
    v0014 = stack[-1];
    fn = elt(env, 7); // read!:num
    v0014 = (*qfn1(fn))(qenv(fn), v0014);
    nil = C_nil;
    if (exception_pending()) goto v0247;
    env = stack[-2];
    goto v0246;

v0031:
    v0050 = v0014;
    if (!(!consp(v0050))) goto v0071;
    v0050 = v0014;
    v0050 = integerp(v0050);
    if (v0050 == nil) goto v0029;
    v0051 = elt(env, 3); // !:rd!:
    v0050 = v0014;
    v0014 = (LispObject)1; // 0
    v0014 = list2star(v0051, v0050, v0014);
    nil = C_nil;
    if (exception_pending()) goto v0247;
    env = stack[-2];
    goto v0071;

v0071:
    fn = elt(env, 6); // normbf
    v0014 = (*qfn1(fn))(qenv(fn), v0014);
    nil = C_nil;
    if (exception_pending()) goto v0247;
    env = stack[-2];
    goto v0249;

v0029:
    fn = elt(env, 7); // read!:num
    v0014 = (*qfn1(fn))(qenv(fn), v0014);
    nil = C_nil;
    if (exception_pending()) goto v0247;
    env = stack[-2];
    goto v0071;
// error exit handlers
v0247:
    popv(3);
    return nil;
}



// Code for color!-roads

static LispObject CC_colorKroads(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0264, v0041, v0042;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for color-roads");
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
    stack[-4] = v0001;
    v0042 = v0000;
// end of prologue
    v0264 = stack[-4];
    v0264 = qcar(v0264);
    v0041 = qcar(v0264);
    v0264 = v0042;
    v0264 = Lassoc(nil, v0041, v0264);
    v0264 = qcdr(v0264);
    stack[-1] = v0264;
    v0264 = stack[-4];
    v0264 = qcdr(v0264);
    v0264 = qcar(v0264);
    v0041 = qcar(v0264);
    v0264 = v0042;
    v0264 = Lassoc(nil, v0041, v0264);
    v0264 = qcdr(v0264);
    stack[0] = v0264;
    v0264 = stack[-4];
    v0264 = qcdr(v0264);
    v0264 = qcdr(v0264);
    v0264 = qcar(v0264);
    v0264 = qcar(v0264);
    v0041 = v0042;
    v0264 = Lassoc(nil, v0264, v0041);
    v0264 = qcdr(v0264);
    stack[-5] = v0264;
    stack[-2] = stack[-1];
    v0041 = stack[0];
    v0264 = stack[-5];
    v0264 = plus2(v0041, v0264);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[-6];
    v0041 = plus2(stack[-2], v0264);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[-6];
    v0264 = (LispObject)33; // 2
    v0264 = quot2(v0041, v0264);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[-6];
    stack[-2] = v0264;
    v0041 = stack[-2];
    v0264 = stack[-1];
    v0264 = difference2(v0041, v0264);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[-6];
    stack[-1] = v0264;
    v0041 = stack[-2];
    v0264 = stack[0];
    v0264 = difference2(v0041, v0264);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[-6];
    stack[0] = v0264;
    v0041 = stack[-2];
    v0264 = stack[-5];
    v0264 = difference2(v0041, v0264);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[-6];
    stack[-5] = v0264;
    v0264 = stack[-4];
    v0264 = qcar(v0264);
    stack[-3] = qcar(v0264);
    stack[-2] = stack[-1];
    v0264 = stack[-4];
    v0264 = qcdr(v0264);
    v0264 = qcar(v0264);
    stack[-1] = qcar(v0264);
    v0264 = stack[-4];
    v0264 = qcdr(v0264);
    v0264 = qcdr(v0264);
    v0264 = qcar(v0264);
    v0041 = qcar(v0264);
    v0264 = stack[-5];
    v0264 = cons(v0041, v0264);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[-6];
    v0264 = ncons(v0264);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[-6];
    v0264 = acons(stack[-1], stack[0], v0264);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    {
        LispObject v0265 = stack[-3];
        LispObject v0266 = stack[-2];
        popv(7);
        return acons(v0265, v0266, v0264);
    }
// error exit handlers
v0196:
    popv(7);
    return nil;
}



// Code for realvaluedp

static LispObject CC_realvaluedp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0004, v0005, v0119;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for realvaluedp");
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
    v0005 = v0000;
// end of prologue
    v0004 = v0005;
    if (!consp(v0004)) goto v0040;
    v0004 = v0005;
    v0119 = qcar(v0004);
    stack[0] = v0119;
    v0004 = elt(env, 2); // alwaysrealvalued
    v0004 = Lflagp(nil, v0119, v0004);
    env = stack[-1];
    if (v0004 == nil) goto v0026;
    v0004 = qvalue(elt(env, 3)); // t
    { popv(2); return onevalue(v0004); }

v0026:
    v0119 = stack[0];
    v0004 = elt(env, 1); // realvalued
    v0004 = Lflagp(nil, v0119, v0004);
    env = stack[-1];
    if (v0004 == nil) goto v0006;
    v0004 = v0005;
    v0004 = qcdr(v0004);
    fn = elt(env, 6); // realvaluedlist
    v0004 = (*qfn1(fn))(qenv(fn), v0004);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-1];
    goto v0209;

v0209:
    if (!(v0004 == nil)) { popv(2); return onevalue(v0004); }
    v0004 = stack[0];
    v0005 = elt(env, 5); // !:rd!:
    v0004 = (v0004 == v0005 ? lisp_true : nil);
    { popv(2); return onevalue(v0004); }

v0006:
    v0004 = qvalue(elt(env, 4)); // nil
    goto v0209;

v0040:
    v0004 = v0005;
    v0004 = (is_number(v0004) ? lisp_true : nil);
    if (!(v0004 == nil)) { popv(2); return onevalue(v0004); }
    v0004 = v0005;
    v0005 = elt(env, 1); // realvalued
        popv(2);
        return Lflagp(nil, v0004, v0005);
// error exit handlers
v0115:
    popv(2);
    return nil;
}



// Code for subeval1

static LispObject CC_subeval1(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0048, v0049, v0202;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for subeval1");
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

v0081:
    v0048 = stack[-2];
    if (v0048 == nil) goto v0016;
    v0048 = stack[-2];
    v0048 = qcar(v0048);
    v0049 = qcar(v0048);
    v0048 = stack[-2];
    v0048 = qcar(v0048);
    v0048 = qcdr(v0048);
    if (!(equal(v0049, v0048))) goto v0016;
    v0048 = stack[-2];
    v0048 = qcdr(v0048);
    stack[-2] = v0048;
    goto v0081;

v0016:
    v0048 = stack[-2];
    if (v0048 == nil) { LispObject res = stack[-1]; popv(5); return onevalue(res); }
    v0048 = stack[-1];
    fn = elt(env, 7); // getrtype
    v0048 = (*qfn1(fn))(qenv(fn), v0048);
    nil = C_nil;
    if (exception_pending()) goto v0268;
    env = stack[-4];
    v0202 = v0048;
    if (v0048 == nil) goto v0066;
    v0049 = v0202;
    v0048 = elt(env, 2); // subfn
    v0048 = get(v0049, v0048);
    env = stack[-4];
    v0049 = v0048;
    if (v0048 == nil) goto v0054;
    v0202 = v0049;
    v0049 = stack[-2];
    v0048 = stack[-1];
        popv(5);
        return Lapply2(nil, 3, v0202, v0049, v0048);

v0054:
    stack[-3] = elt(env, 3); // alg
    stack[0] = (LispObject)369; // 23
    v0048 = elt(env, 4); // "No substitution defined for type"
    v0049 = v0202;
    v0048 = list2(v0048, v0049);
    nil = C_nil;
    if (exception_pending()) goto v0268;
    env = stack[-4];
    fn = elt(env, 8); // rerror
    v0048 = (*qfnn(fn))(qenv(fn), 3, stack[-3], stack[0], v0048);
    nil = C_nil;
    if (exception_pending()) goto v0268;
    env = stack[-4];
    goto v0066;

v0066:
    v0048 = stack[-1];
    fn = elt(env, 9); // simp
    v0049 = (*qfn1(fn))(qenv(fn), v0048);
    nil = C_nil;
    if (exception_pending()) goto v0268;
    env = stack[-4];
    v0048 = stack[-2];
    fn = elt(env, 10); // subsq
    v0048 = (*qfn2(fn))(qenv(fn), v0049, v0048);
    nil = C_nil;
    if (exception_pending()) goto v0268;
    env = stack[-4];
    stack[-2] = v0048;
    v0048 = qvalue(elt(env, 5)); // t
    stack[0] = qvalue(elt(env, 6)); // !*sub2
    qvalue(elt(env, 6)) = v0048; // !*sub2
    v0048 = stack[-2];
    fn = elt(env, 11); // subs2
    v0048 = (*qfn1(fn))(qenv(fn), v0048);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    env = stack[-4];
    stack[-2] = v0048;
    qvalue(elt(env, 6)) = stack[0]; // !*sub2
    v0048 = stack[-2];
    {
        popv(5);
        fn = elt(env, 12); // mk!*sq
        return (*qfn1(fn))(qenv(fn), v0048);
    }
// error exit handlers
v0253:
    env = stack[-4];
    qvalue(elt(env, 6)) = stack[0]; // !*sub2
    popv(5);
    return nil;
v0268:
    popv(5);
    return nil;
}



// Code for ratfunpri1

static LispObject CC_ratfunpri1(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0160, v0161, v0309;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ratfunpri1");
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
    stack[0] = v0000;
// end of prologue
    v0161 = qvalue(elt(env, 1)); // spare!*
    v0160 = (LispObject)33; // 2
    v0160 = plus2(v0161, v0160);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    env = stack[-8];
    qvalue(elt(env, 1)) = v0160; // spare!*
    v0160 = stack[0];
    v0160 = qcdr(v0160);
    v0309 = qcar(v0160);
    v0161 = (LispObject)1; // 0
    v0160 = qvalue(elt(env, 2)); // nil
    fn = elt(env, 15); // layout!-formula
    v0160 = (*qfnn(fn))(qenv(fn), 3, v0309, v0161, v0160);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    env = stack[-8];
    stack[-7] = v0160;
    if (v0160 == nil) goto v0167;
    v0160 = stack[0];
    v0160 = qcdr(v0160);
    v0160 = qcdr(v0160);
    v0309 = qcar(v0160);
    v0161 = (LispObject)1; // 0
    v0160 = qvalue(elt(env, 2)); // nil
    fn = elt(env, 15); // layout!-formula
    v0160 = (*qfnn(fn))(qenv(fn), 3, v0309, v0161, v0160);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    env = stack[-8];
    stack[-6] = v0160;
    if (v0160 == nil) goto v0167;
    v0161 = qvalue(elt(env, 1)); // spare!*
    v0160 = (LispObject)33; // 2
    v0160 = difference2(v0161, v0160);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    env = stack[-8];
    qvalue(elt(env, 1)) = v0160; // spare!*
    stack[0] = (LispObject)33; // 2
    v0160 = stack[-7];
    v0160 = qcar(v0160);
    v0161 = qcdr(v0160);
    v0160 = stack[-6];
    v0160 = qcar(v0160);
    v0160 = qcdr(v0160);
    fn = elt(env, 16); // max
    v0160 = (*qfn2(fn))(qenv(fn), v0161, v0160);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    env = stack[-8];
    v0160 = plus2(stack[0], v0160);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    env = stack[-8];
    stack[-2] = v0160;
    stack[0] = stack[-2];
    v0160 = qvalue(elt(env, 2)); // nil
    v0161 = Llinelength(nil, v0160);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    env = stack[-8];
    v0160 = qvalue(elt(env, 1)); // spare!*
    v0161 = difference2(v0161, v0160);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    env = stack[-8];
    v0160 = qvalue(elt(env, 3)); // posn!*
    v0160 = difference2(v0161, v0160);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    env = stack[-8];
    v0160 = (LispObject)greaterp2(stack[0], v0160);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    v0160 = v0160 ? lisp_true : nil;
    env = stack[-8];
    if (v0160 == nil) goto v0252;
    v0160 = qvalue(elt(env, 4)); // t
    fn = elt(env, 17); // terpri!*
    v0160 = (*qfn1(fn))(qenv(fn), v0160);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    env = stack[-8];
    goto v0252;

v0252:
    v0160 = stack[-7];
    v0160 = qcar(v0160);
    v0161 = qcdr(v0160);
    v0160 = stack[-6];
    v0160 = qcar(v0160);
    v0160 = qcdr(v0160);
    v0160 = difference2(v0161, v0160);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    env = stack[-8];
    stack[-1] = v0160;
    v0161 = stack[-1];
    v0160 = (LispObject)1; // 0
    v0160 = (LispObject)greaterp2(v0161, v0160);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    v0160 = v0160 ? lisp_true : nil;
    env = stack[-8];
    if (v0160 == nil) goto v0311;
    v0160 = (LispObject)1; // 0
    stack[0] = v0160;
    v0161 = stack[-1];
    v0160 = (LispObject)33; // 2
    v0160 = quot2(v0161, v0160);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    env = stack[-8];
    stack[-3] = v0160;
    goto v0312;

v0312:
    v0160 = stack[-7];
    v0160 = qcdr(v0160);
    v0161 = qcdr(v0160);
    v0160 = stack[-7];
    v0160 = qcdr(v0160);
    v0160 = qcar(v0160);
    v0160 = difference2(v0161, v0160);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    env = stack[-8];
    v0160 = add1(v0160);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    env = stack[-8];
    stack[-5] = v0160;
    v0160 = stack[-6];
    v0160 = qcdr(v0160);
    v0161 = qcdr(v0160);
    v0160 = stack[-6];
    v0160 = qcdr(v0160);
    v0160 = qcar(v0160);
    v0160 = difference2(v0161, v0160);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    env = stack[-8];
    v0160 = add1(v0160);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    env = stack[-8];
    stack[-4] = v0160;
    stack[-1] = stack[0];
    stack[0] = qvalue(elt(env, 3)); // posn!*
    v0161 = (LispObject)17; // 1
    v0160 = qvalue(elt(env, 5)); // orig!*
    v0160 = difference2(v0161, v0160);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    env = stack[-8];
    v0160 = plus2(stack[0], v0160);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    env = stack[-8];
    stack[0] = plus2(stack[-1], v0160);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    env = stack[-8];
    v0161 = (LispObject)17; // 1
    v0160 = stack[-7];
    v0160 = qcdr(v0160);
    v0160 = qcar(v0160);
    v0161 = difference2(v0161, v0160);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    env = stack[-8];
    v0160 = qvalue(elt(env, 6)); // ycoord!*
    v0161 = plus2(v0161, v0160);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    env = stack[-8];
    v0160 = stack[-7];
    v0160 = qcar(v0160);
    v0160 = qcar(v0160);
    fn = elt(env, 18); // update!-pline
    stack[-1] = (*qfnn(fn))(qenv(fn), 3, stack[0], v0161, v0160);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    env = stack[-8];
    stack[0] = qvalue(elt(env, 3)); // posn!*
    v0161 = (LispObject)17; // 1
    v0160 = qvalue(elt(env, 5)); // orig!*
    v0160 = difference2(v0161, v0160);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    env = stack[-8];
    v0160 = plus2(stack[0], v0160);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    env = stack[-8];
    stack[0] = plus2(stack[-3], v0160);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    env = stack[-8];
    v0161 = qvalue(elt(env, 6)); // ycoord!*
    v0160 = stack[-6];
    v0160 = qcdr(v0160);
    v0160 = qcdr(v0160);
    v0160 = difference2(v0161, v0160);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    env = stack[-8];
    v0161 = sub1(v0160);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    env = stack[-8];
    v0160 = stack[-6];
    v0160 = qcar(v0160);
    v0160 = qcar(v0160);
    fn = elt(env, 18); // update!-pline
    v0161 = (*qfnn(fn))(qenv(fn), 3, stack[0], v0161, v0160);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    env = stack[-8];
    v0160 = qvalue(elt(env, 7)); // pline!*
    v0160 = Lappend(nil, v0161, v0160);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    env = stack[-8];
    v0160 = Lappend(nil, stack[-1], v0160);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    env = stack[-8];
    qvalue(elt(env, 7)) = v0160; // pline!*
    stack[0] = qvalue(elt(env, 8)); // ymin!*
    v0161 = qvalue(elt(env, 6)); // ycoord!*
    v0160 = stack[-4];
    v0160 = difference2(v0161, v0160);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    env = stack[-8];
    fn = elt(env, 19); // min
    v0160 = (*qfn2(fn))(qenv(fn), stack[0], v0160);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    env = stack[-8];
    qvalue(elt(env, 8)) = v0160; // ymin!*
    stack[0] = qvalue(elt(env, 9)); // ymax!*
    v0161 = qvalue(elt(env, 6)); // ycoord!*
    v0160 = stack[-5];
    v0160 = plus2(v0161, v0160);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    env = stack[-8];
    fn = elt(env, 16); // max
    v0160 = (*qfn2(fn))(qenv(fn), stack[0], v0160);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    env = stack[-8];
    qvalue(elt(env, 9)) = v0160; // ymax!*
    v0160 = elt(env, 10); // bar
    fn = elt(env, 20); // symbol
    v0160 = (*qfn1(fn))(qenv(fn), v0160);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    env = stack[-8];
    stack[-1] = v0160;
    v0160 = (LispObject)17; // 1
    stack[0] = v0160;
    goto v0313;

v0313:
    v0161 = stack[-2];
    v0160 = stack[0];
    v0160 = difference2(v0161, v0160);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    env = stack[-8];
    v0160 = Lminusp(nil, v0160);
    env = stack[-8];
    if (!(v0160 == nil)) goto v0012;
    v0160 = stack[-1];
    fn = elt(env, 21); // prin2!*
    v0160 = (*qfn1(fn))(qenv(fn), v0160);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    env = stack[-8];
    v0160 = stack[0];
    v0160 = add1(v0160);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    env = stack[-8];
    stack[0] = v0160;
    goto v0313;

v0012:
    v0160 = nil;
    { popv(9); return onevalue(v0160); }

v0311:
    v0160 = stack[-1];
    v0161 = negate(v0160);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    env = stack[-8];
    v0160 = (LispObject)33; // 2
    v0160 = quot2(v0161, v0160);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    env = stack[-8];
    stack[0] = v0160;
    v0160 = (LispObject)1; // 0
    stack[-3] = v0160;
    goto v0312;

v0167:
    v0161 = qvalue(elt(env, 1)); // spare!*
    v0160 = (LispObject)33; // 2
    v0160 = difference2(v0161, v0160);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    env = stack[-8];
    qvalue(elt(env, 1)) = v0160; // spare!*
    v0160 = stack[0];
    v0160 = qcdr(v0160);
    stack[0] = v0160;
    v0160 = elt(env, 11); // quotient
    if (!symbolp(v0160)) v0160 = nil;
    else { v0160 = qfastgets(v0160);
           if (v0160 != nil) { v0160 = elt(v0160, 23); // infix
#ifdef RECORD_GET
             if (v0160 != SPID_NOPROP)
                record_get(elt(fastget_names, 23), 1);
             else record_get(elt(fastget_names, 23), 0),
                v0160 = nil; }
           else record_get(elt(fastget_names, 23), 0); }
#else
             if (v0160 == SPID_NOPROP) v0160 = nil; }}
#endif
    stack[-2] = v0160;
    v0160 = qvalue(elt(env, 12)); // p!*!*
    if (v0160 == nil) goto v0314;
    v0161 = qvalue(elt(env, 12)); // p!*!*
    v0160 = stack[-2];
    v0160 = (LispObject)greaterp2(v0161, v0160);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    v0160 = v0160 ? lisp_true : nil;
    env = stack[-8];
    stack[-1] = v0160;
    goto v0315;

v0315:
    v0160 = stack[-1];
    if (v0160 == nil) goto v0316;
    v0160 = elt(env, 13); // "("
    fn = elt(env, 21); // prin2!*
    v0160 = (*qfn1(fn))(qenv(fn), v0160);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    env = stack[-8];
    goto v0316;

v0316:
    v0160 = stack[0];
    v0161 = qcar(v0160);
    v0160 = stack[-2];
    fn = elt(env, 22); // maprint
    v0160 = (*qfn2(fn))(qenv(fn), v0161, v0160);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    env = stack[-8];
    v0160 = elt(env, 11); // quotient
    fn = elt(env, 23); // oprin
    v0160 = (*qfn1(fn))(qenv(fn), v0160);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    env = stack[-8];
    v0160 = stack[0];
    v0160 = qcdr(v0160);
    v0160 = qcar(v0160);
    fn = elt(env, 24); // negnumberchk
    v0161 = (*qfn1(fn))(qenv(fn), v0160);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    env = stack[-8];
    v0160 = stack[-2];
    fn = elt(env, 22); // maprint
    v0160 = (*qfn2(fn))(qenv(fn), v0161, v0160);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    env = stack[-8];
    v0160 = stack[-1];
    if (v0160 == nil) goto v0012;
    v0160 = elt(env, 14); // ")"
    fn = elt(env, 21); // prin2!*
    v0160 = (*qfn1(fn))(qenv(fn), v0160);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    goto v0012;

v0314:
    v0160 = qvalue(elt(env, 2)); // nil
    stack[-1] = v0160;
    goto v0315;
// error exit handlers
v0310:
    popv(9);
    return nil;
}



// Code for dp_neworder

static LispObject CC_dp_neworder(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0065, v0004;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dp_neworder");
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
    v0065 = v0000;
// end of prologue
    stack[-4] = v0065;
    v0065 = stack[-4];
    if (v0065 == nil) goto v0058;
    v0065 = stack[-4];
    v0065 = qcar(v0065);
    stack[0] = v0065;
    v0065 = stack[0];
    v0065 = qcar(v0065);
    fn = elt(env, 3); // mo_neworder
    v0004 = (*qfn1(fn))(qenv(fn), v0065);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-5];
    v0065 = stack[0];
    v0065 = qcdr(v0065);
    v0065 = cons(v0004, v0065);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-5];
    v0065 = ncons(v0065);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-5];
    stack[-2] = v0065;
    stack[-3] = v0065;
    goto v0021;

v0021:
    v0065 = stack[-4];
    v0065 = qcdr(v0065);
    stack[-4] = v0065;
    v0065 = stack[-4];
    if (v0065 == nil) goto v0009;
    stack[-1] = stack[-2];
    v0065 = stack[-4];
    v0065 = qcar(v0065);
    stack[0] = v0065;
    v0065 = stack[0];
    v0065 = qcar(v0065);
    fn = elt(env, 3); // mo_neworder
    v0004 = (*qfn1(fn))(qenv(fn), v0065);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-5];
    v0065 = stack[0];
    v0065 = qcdr(v0065);
    v0065 = cons(v0004, v0065);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-5];
    v0065 = ncons(v0065);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-5];
    v0065 = Lrplacd(nil, stack[-1], v0065);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-5];
    v0065 = stack[-2];
    v0065 = qcdr(v0065);
    stack[-2] = v0065;
    goto v0021;

v0009:
    v0065 = stack[-3];
    v0004 = v0065;
    goto v0015;

v0015:
    v0065 = elt(env, 2); // dp!=mocompare
    {
        popv(6);
        fn = elt(env, 4); // sort
        return (*qfn2(fn))(qenv(fn), v0004, v0065);
    }

v0058:
    v0065 = qvalue(elt(env, 1)); // nil
    v0004 = v0065;
    goto v0015;
// error exit handlers
v0116:
    popv(6);
    return nil;
}



// Code for !*f2di

static LispObject CC_Hf2di(LispObject env,
                         LispObject v0001, LispObject v0045)
{
    LispObject nil = C_nil;
    LispObject v0326, v0327;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *f2di");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0045,v0001);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0001,v0045);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
// copy arguments values to proper place
    v0326 = v0045;
    stack[-5] = v0001;
// end of prologue
    stack[-6] = qvalue(elt(env, 1)); // varlist!*
    qvalue(elt(env, 1)) = nil; // varlist!*
    qvalue(elt(env, 1)) = v0326; // varlist!*
    v0326 = stack[-5];
    if (v0326 == nil) goto v0259;
    v0326 = stack[-5];
    if (!consp(v0326)) goto v0024;
    v0326 = stack[-5];
    v0326 = qcar(v0326);
    v0326 = (consp(v0326) ? nil : lisp_true);
    goto v0058;

v0058:
    if (v0326 == nil) goto v0013;
    v0326 = qvalue(elt(env, 1)); // varlist!*
    stack[-3] = v0326;
    v0326 = stack[-3];
    if (v0326 == nil) goto v0022;
    v0326 = (LispObject)1; // 0
    v0326 = ncons(v0326);
    nil = C_nil;
    if (exception_pending()) goto v0223;
    env = stack[-7];
    stack[-1] = v0326;
    stack[-2] = v0326;
    goto v0009;

v0009:
    v0326 = stack[-3];
    v0326 = qcdr(v0326);
    stack[-3] = v0326;
    v0326 = stack[-3];
    if (v0326 == nil) goto v0261;
    stack[0] = stack[-1];
    v0326 = (LispObject)1; // 0
    v0326 = ncons(v0326);
    nil = C_nil;
    if (exception_pending()) goto v0223;
    env = stack[-7];
    v0326 = Lrplacd(nil, stack[0], v0326);
    nil = C_nil;
    if (exception_pending()) goto v0223;
    env = stack[-7];
    v0326 = stack[-1];
    v0326 = qcdr(v0326);
    stack[-1] = v0326;
    goto v0009;

v0261:
    v0326 = stack[-2];
    goto v0248;

v0248:
    fn = elt(env, 4); // addgt
    v0327 = (*qfn1(fn))(qenv(fn), v0326);
    nil = C_nil;
    if (exception_pending()) goto v0223;
    env = stack[-7];
    v0326 = stack[-5];
    v0326 = cons(v0327, v0326);
    nil = C_nil;
    if (exception_pending()) goto v0223;
    env = stack[-7];
    v0326 = ncons(v0326);
    nil = C_nil;
    if (exception_pending()) goto v0223;
    env = stack[-7];
    goto v0028;

v0028:
    qvalue(elt(env, 1)) = stack[-6]; // varlist!*
    { popv(8); return onevalue(v0326); }

v0022:
    v0326 = qvalue(elt(env, 2)); // nil
    goto v0248;

v0013:
    v0326 = stack[-5];
    v0326 = qcar(v0326);
    v0326 = qcar(v0326);
    v0327 = qcar(v0326);
    v0326 = qvalue(elt(env, 1)); // varlist!*
    v0326 = Lmember(nil, v0327, v0326);
    if (v0326 == nil) goto v0328;
    v0326 = stack[-5];
    v0326 = qcar(v0326);
    v0327 = qcdr(v0326);
    v0326 = qvalue(elt(env, 1)); // varlist!*
    stack[-4] = CC_Hf2di(env, v0327, v0326);
    nil = C_nil;
    if (exception_pending()) goto v0223;
    env = stack[-7];
    v0326 = qvalue(elt(env, 1)); // varlist!*
    stack[-3] = v0326;
    v0326 = stack[-3];
    if (v0326 == nil) goto v0108;
    v0326 = stack[-3];
    v0326 = qcar(v0326);
    v0327 = v0326;
    v0326 = stack[-5];
    v0326 = qcar(v0326);
    v0326 = qcar(v0326);
    v0326 = qcar(v0326);
    if (equal(v0327, v0326)) goto v0256;
    v0326 = (LispObject)1; // 0
    goto v0329;

v0329:
    v0326 = ncons(v0326);
    nil = C_nil;
    if (exception_pending()) goto v0223;
    env = stack[-7];
    stack[-1] = v0326;
    stack[-2] = v0326;
    goto v0330;

v0330:
    v0326 = stack[-3];
    v0326 = qcdr(v0326);
    stack[-3] = v0326;
    v0326 = stack[-3];
    if (v0326 == nil) goto v0128;
    stack[0] = stack[-1];
    v0326 = stack[-3];
    v0326 = qcar(v0326);
    v0327 = v0326;
    v0326 = stack[-5];
    v0326 = qcar(v0326);
    v0326 = qcar(v0326);
    v0326 = qcar(v0326);
    if (equal(v0327, v0326)) goto v0306;
    v0326 = (LispObject)1; // 0
    goto v0331;

v0331:
    v0326 = ncons(v0326);
    nil = C_nil;
    if (exception_pending()) goto v0223;
    env = stack[-7];
    v0326 = Lrplacd(nil, stack[0], v0326);
    nil = C_nil;
    if (exception_pending()) goto v0223;
    env = stack[-7];
    v0326 = stack[-1];
    v0326 = qcdr(v0326);
    stack[-1] = v0326;
    goto v0330;

v0306:
    v0326 = stack[-5];
    v0326 = qcar(v0326);
    v0326 = qcar(v0326);
    v0326 = qcdr(v0326);
    goto v0331;

v0128:
    v0326 = stack[-2];
    goto v0332;

v0332:
    fn = elt(env, 4); // addgt
    v0326 = (*qfn1(fn))(qenv(fn), v0326);
    nil = C_nil;
    if (exception_pending()) goto v0223;
    env = stack[-7];
    fn = elt(env, 5); // pdmult
    v0326 = (*qfn2(fn))(qenv(fn), stack[-4], v0326);
    nil = C_nil;
    if (exception_pending()) goto v0223;
    env = stack[-7];
    stack[0] = v0326;
    goto v0333;

v0333:
    v0326 = stack[-5];
    v0327 = qcdr(v0326);
    v0326 = qvalue(elt(env, 1)); // varlist!*
    v0326 = CC_Hf2di(env, v0327, v0326);
    nil = C_nil;
    if (exception_pending()) goto v0223;
    env = stack[-7];
    fn = elt(env, 6); // psum
    v0326 = (*qfn2(fn))(qenv(fn), stack[0], v0326);
    nil = C_nil;
    if (exception_pending()) goto v0223;
    env = stack[-7];
    goto v0028;

v0256:
    v0326 = stack[-5];
    v0326 = qcar(v0326);
    v0326 = qcar(v0326);
    v0326 = qcdr(v0326);
    goto v0329;

v0108:
    v0326 = qvalue(elt(env, 2)); // nil
    goto v0332;

v0328:
    v0326 = stack[-5];
    v0326 = qcar(v0326);
    v0327 = qcdr(v0326);
    v0326 = qvalue(elt(env, 1)); // varlist!*
    stack[0] = CC_Hf2di(env, v0327, v0326);
    nil = C_nil;
    if (exception_pending()) goto v0223;
    env = stack[-7];
    v0326 = stack[-5];
    v0326 = qcar(v0326);
    v0327 = qcar(v0326);
    v0326 = (LispObject)17; // 1
    v0326 = cons(v0327, v0326);
    nil = C_nil;
    if (exception_pending()) goto v0223;
    env = stack[-7];
    v0326 = ncons(v0326);
    nil = C_nil;
    if (exception_pending()) goto v0223;
    env = stack[-7];
    fn = elt(env, 7); // pcmult
    v0326 = (*qfn2(fn))(qenv(fn), stack[0], v0326);
    nil = C_nil;
    if (exception_pending()) goto v0223;
    env = stack[-7];
    stack[0] = v0326;
    goto v0333;

v0024:
    v0326 = qvalue(elt(env, 3)); // t
    goto v0058;

v0259:
    v0326 = qvalue(elt(env, 2)); // nil
    goto v0028;
// error exit handlers
v0223:
    env = stack[-7];
    qvalue(elt(env, 1)) = stack[-6]; // varlist!*
    popv(8);
    return nil;
}



// Code for list_is_all_free

static LispObject CC_list_is_all_free(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0076;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for list_is_all_free");
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

v0040:
    v0076 = stack[0];
    if (v0076 == nil) goto v0137;
    v0076 = stack[0];
    v0076 = qcar(v0076);
    fn = elt(env, 3); // nodum_varp
    v0076 = (*qfn1(fn))(qenv(fn), v0076);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    env = stack[-1];
    if (v0076 == nil) goto v0024;
    v0076 = stack[0];
    v0076 = qcdr(v0076);
    stack[0] = v0076;
    goto v0040;

v0024:
    v0076 = qvalue(elt(env, 2)); // nil
    { popv(2); return onevalue(v0076); }

v0137:
    v0076 = qvalue(elt(env, 1)); // t
    { popv(2); return onevalue(v0076); }
// error exit handlers
v0084:
    popv(2);
    return nil;
}



// Code for msolve!-poly1

static LispObject CC_msolveKpoly1(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0347, v0348, v0349;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for msolve-poly1");
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
    push2(nil, nil);
// copy arguments values to proper place
    stack[-4] = v0001;
    stack[-5] = v0000;
// end of prologue
    v0347 = stack[-5];
    if (!consp(v0347)) goto v0249;
    v0347 = stack[-5];
    v0347 = qcar(v0347);
    v0347 = (consp(v0347) ? nil : lisp_true);
    goto v0080;

v0080:
    if (!(v0347 == nil)) goto v0013;
    v0347 = stack[-5];
    v0347 = qcar(v0347);
    v0347 = qcar(v0347);
    v0348 = qcdr(v0347);
    v0347 = (LispObject)17; // 1
    if (!(v0348 == v0347)) goto v0013;
    v0347 = stack[-5];
    v0347 = qcar(v0347);
    v0347 = qcdr(v0347);
    fn = elt(env, 6); // safe!-modrecip
    v0347 = (*qfn1(fn))(qenv(fn), v0347);
    nil = C_nil;
    if (exception_pending()) goto v0350;
    env = stack[-7];
    stack[0] = v0347;
    v0347 = qvalue(elt(env, 2)); // nil
    qvalue(elt(env, 3)) = v0347; // erfg!*
    v0347 = stack[0];
    if (v0347 == nil) goto v0013;
    v0347 = stack[-5];
    v0347 = qcdr(v0347);
    fn = elt(env, 7); // negf
    v0347 = (*qfn1(fn))(qenv(fn), v0347);
    nil = C_nil;
    if (exception_pending()) goto v0350;
    env = stack[-7];
    fn = elt(env, 8); // multf
    v0347 = (*qfn2(fn))(qenv(fn), stack[0], v0347);
    nil = C_nil;
    if (exception_pending()) goto v0350;
    env = stack[-7];
    fn = elt(env, 9); // moduntag
    v0347 = (*qfn1(fn))(qenv(fn), v0347);
    nil = C_nil;
    if (exception_pending()) goto v0350;
    env = stack[-7];
    stack[0] = v0347;
    v0347 = stack[0];
    if (v0347 == nil) goto v0006;
    v0348 = stack[0];
    v0347 = (LispObject)1; // 0
    v0347 = (LispObject)lessp2(v0348, v0347);
    nil = C_nil;
    if (exception_pending()) goto v0350;
    v0347 = v0347 ? lisp_true : nil;
    env = stack[-7];
    if (!(v0347 == nil)) goto v0056;
    v0348 = stack[0];
    v0347 = qvalue(elt(env, 4)); // current!-modulus
    v0347 = (LispObject)greaterp2(v0348, v0347);
    nil = C_nil;
    if (exception_pending()) goto v0350;
    v0347 = v0347 ? lisp_true : nil;
    env = stack[-7];
    if (!(v0347 == nil)) goto v0056;

v0006:
    v0347 = stack[0];
    v0347 = ncons(v0347);
    nil = C_nil;
    if (exception_pending()) goto v0350;
    env = stack[-7];
    stack[0] = v0347;
    goto v0016;

v0016:
    v0347 = stack[0];
    stack[-5] = v0347;
    v0347 = stack[-5];
    if (v0347 == nil) goto v0351;
    v0347 = stack[-5];
    v0347 = qcar(v0347);
    stack[0] = stack[-4];
    fn = elt(env, 10); // prepf
    v0347 = (*qfn1(fn))(qenv(fn), v0347);
    nil = C_nil;
    if (exception_pending()) goto v0350;
    env = stack[-7];
    v0347 = cons(stack[0], v0347);
    nil = C_nil;
    if (exception_pending()) goto v0350;
    env = stack[-7];
    v0347 = ncons(v0347);
    nil = C_nil;
    if (exception_pending()) goto v0350;
    env = stack[-7];
    v0347 = ncons(v0347);
    nil = C_nil;
    if (exception_pending()) goto v0350;
    env = stack[-7];
    stack[-2] = v0347;
    stack[-3] = v0347;
    goto v0122;

v0122:
    v0347 = stack[-5];
    v0347 = qcdr(v0347);
    stack[-5] = v0347;
    v0347 = stack[-5];
    if (v0347 == nil) { LispObject res = stack[-3]; popv(8); return onevalue(res); }
    stack[-1] = stack[-2];
    v0347 = stack[-5];
    v0347 = qcar(v0347);
    stack[0] = stack[-4];
    fn = elt(env, 10); // prepf
    v0347 = (*qfn1(fn))(qenv(fn), v0347);
    nil = C_nil;
    if (exception_pending()) goto v0350;
    env = stack[-7];
    v0347 = cons(stack[0], v0347);
    nil = C_nil;
    if (exception_pending()) goto v0350;
    env = stack[-7];
    v0347 = ncons(v0347);
    nil = C_nil;
    if (exception_pending()) goto v0350;
    env = stack[-7];
    v0347 = ncons(v0347);
    nil = C_nil;
    if (exception_pending()) goto v0350;
    env = stack[-7];
    v0347 = Lrplacd(nil, stack[-1], v0347);
    nil = C_nil;
    if (exception_pending()) goto v0350;
    env = stack[-7];
    v0347 = stack[-2];
    v0347 = qcdr(v0347);
    stack[-2] = v0347;
    goto v0122;

v0351:
    v0347 = qvalue(elt(env, 2)); // nil
    { popv(8); return onevalue(v0347); }

v0056:
    v0347 = stack[0];
    fn = elt(env, 11); // general!-modular!-number
    v0347 = (*qfn1(fn))(qenv(fn), v0347);
    nil = C_nil;
    if (exception_pending()) goto v0350;
    env = stack[-7];
    stack[0] = v0347;
    goto v0006;

v0013:
    v0349 = stack[-5];
    v0348 = stack[-4];
    v0347 = (LispObject)1; // 0
    fn = elt(env, 12); // lowestdeg
    v0347 = (*qfnn(fn))(qenv(fn), 3, v0349, v0348, v0347);
    nil = C_nil;
    if (exception_pending()) goto v0350;
    env = stack[-7];
    stack[-6] = v0347;
    v0348 = stack[-6];
    v0347 = (LispObject)1; // 0
    v0347 = (LispObject)greaterp2(v0348, v0347);
    nil = C_nil;
    if (exception_pending()) goto v0350;
    v0347 = v0347 ? lisp_true : nil;
    env = stack[-7];
    if (v0347 == nil) goto v0048;
    stack[0] = stack[-5];
    v0349 = elt(env, 5); // expt
    v0348 = stack[-4];
    v0347 = stack[-6];
    v0347 = list3(v0349, v0348, v0347);
    nil = C_nil;
    if (exception_pending()) goto v0350;
    env = stack[-7];
    fn = elt(env, 13); // simp
    v0347 = (*qfn1(fn))(qenv(fn), v0347);
    nil = C_nil;
    if (exception_pending()) goto v0350;
    env = stack[-7];
    v0347 = qcar(v0347);
    fn = elt(env, 14); // quotf
    v0347 = (*qfn2(fn))(qenv(fn), stack[0], v0347);
    nil = C_nil;
    if (exception_pending()) goto v0350;
    env = stack[-7];
    stack[-5] = v0347;
    goto v0048;

v0048:
    v0347 = stack[-5];
    fn = elt(env, 9); // moduntag
    v0347 = (*qfn1(fn))(qenv(fn), v0347);
    nil = C_nil;
    if (exception_pending()) goto v0350;
    env = stack[-7];
    fn = elt(env, 15); // general!-reduce!-mod!-p
    v0347 = (*qfn1(fn))(qenv(fn), v0347);
    nil = C_nil;
    if (exception_pending()) goto v0350;
    env = stack[-7];
    stack[-5] = v0347;
    v0347 = (LispObject)17; // 1
    stack[-3] = v0347;
    goto v0197;

v0197:
    v0347 = qvalue(elt(env, 4)); // current!-modulus
    v0348 = sub1(v0347);
    nil = C_nil;
    if (exception_pending()) goto v0350;
    env = stack[-7];
    v0347 = stack[-3];
    v0347 = difference2(v0348, v0347);
    nil = C_nil;
    if (exception_pending()) goto v0350;
    env = stack[-7];
    v0347 = Lminusp(nil, v0347);
    env = stack[-7];
    if (v0347 == nil) goto v0091;
    v0347 = qvalue(elt(env, 2)); // nil
    goto v0258;

v0258:
    stack[0] = v0347;
    v0348 = stack[-6];
    v0347 = (LispObject)1; // 0
    v0347 = (LispObject)greaterp2(v0348, v0347);
    nil = C_nil;
    if (exception_pending()) goto v0350;
    v0347 = v0347 ? lisp_true : nil;
    env = stack[-7];
    if (v0347 == nil) goto v0016;
    v0347 = qvalue(elt(env, 2)); // nil
    v0347 = ncons(v0347);
    nil = C_nil;
    if (exception_pending()) goto v0350;
    env = stack[-7];
    v0347 = Lappend(nil, stack[0], v0347);
    nil = C_nil;
    if (exception_pending()) goto v0350;
    env = stack[-7];
    stack[0] = v0347;
    goto v0016;

v0091:
    v0349 = stack[-5];
    v0348 = stack[-4];
    v0347 = stack[-3];
    fn = elt(env, 16); // general!-evaluate!-mod!-p
    v0347 = (*qfnn(fn))(qenv(fn), 3, v0349, v0348, v0347);
    nil = C_nil;
    if (exception_pending()) goto v0350;
    env = stack[-7];
    if (v0347 == nil) goto v0128;
    v0347 = nil;
    goto v0200;

v0200:
    stack[-2] = v0347;
    v0347 = stack[-2];
    fn = elt(env, 17); // lastpair
    v0347 = (*qfn1(fn))(qenv(fn), v0347);
    nil = C_nil;
    if (exception_pending()) goto v0350;
    env = stack[-7];
    stack[-1] = v0347;
    v0347 = stack[-3];
    v0347 = add1(v0347);
    nil = C_nil;
    if (exception_pending()) goto v0350;
    env = stack[-7];
    stack[-3] = v0347;
    v0347 = stack[-1];
    if (!consp(v0347)) goto v0197;
    else goto v0103;

v0103:
    v0347 = qvalue(elt(env, 4)); // current!-modulus
    v0348 = sub1(v0347);
    nil = C_nil;
    if (exception_pending()) goto v0350;
    env = stack[-7];
    v0347 = stack[-3];
    v0347 = difference2(v0348, v0347);
    nil = C_nil;
    if (exception_pending()) goto v0350;
    env = stack[-7];
    v0347 = Lminusp(nil, v0347);
    env = stack[-7];
    if (v0347 == nil) goto v0352;
    v0347 = stack[-2];
    goto v0258;

v0352:
    stack[0] = stack[-1];
    v0349 = stack[-5];
    v0348 = stack[-4];
    v0347 = stack[-3];
    fn = elt(env, 16); // general!-evaluate!-mod!-p
    v0347 = (*qfnn(fn))(qenv(fn), 3, v0349, v0348, v0347);
    nil = C_nil;
    if (exception_pending()) goto v0350;
    env = stack[-7];
    if (v0347 == nil) goto v0353;
    v0347 = nil;
    goto v0097;

v0097:
    v0347 = Lrplacd(nil, stack[0], v0347);
    nil = C_nil;
    if (exception_pending()) goto v0350;
    env = stack[-7];
    v0347 = stack[-1];
    fn = elt(env, 17); // lastpair
    v0347 = (*qfn1(fn))(qenv(fn), v0347);
    nil = C_nil;
    if (exception_pending()) goto v0350;
    env = stack[-7];
    stack[-1] = v0347;
    v0347 = stack[-3];
    v0347 = add1(v0347);
    nil = C_nil;
    if (exception_pending()) goto v0350;
    env = stack[-7];
    stack[-3] = v0347;
    goto v0103;

v0353:
    v0347 = stack[-3];
    v0347 = ncons(v0347);
    nil = C_nil;
    if (exception_pending()) goto v0350;
    env = stack[-7];
    goto v0097;

v0128:
    v0347 = stack[-3];
    v0347 = ncons(v0347);
    nil = C_nil;
    if (exception_pending()) goto v0350;
    env = stack[-7];
    goto v0200;

v0249:
    v0347 = qvalue(elt(env, 1)); // t
    goto v0080;
// error exit handlers
v0350:
    popv(8);
    return nil;
}



// Code for reduce!-mod!-eigf

static LispObject CC_reduceKmodKeigf(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0079, v0030;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for reduce-mod-eigf");
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
    v0079 = v0000;
// end of prologue
    v0030 = qvalue(elt(env, 1)); // !*sub2
    stack[-2] = qvalue(elt(env, 1)); // !*sub2
    qvalue(elt(env, 1)) = v0030; // !*sub2
    v0030 = v0079;
    v0030 = qcar(v0030);
    stack[0] = qcar(v0030);
    v0030 = v0079;
    v0030 = qcdr(v0030);
    v0079 = qcar(v0079);
    v0079 = qcdr(v0079);
    v0079 = cons(v0030, v0079);
    nil = C_nil;
    if (exception_pending()) goto v0009;
    env = stack[-3];
    fn = elt(env, 2); // cancel
    v0079 = (*qfn1(fn))(qenv(fn), v0079);
    nil = C_nil;
    if (exception_pending()) goto v0009;
    env = stack[-3];
    fn = elt(env, 3); // negsq
    v0079 = (*qfn1(fn))(qenv(fn), v0079);
    nil = C_nil;
    if (exception_pending()) goto v0009;
    env = stack[-3];
    v0030 = cons(stack[0], v0079);
    nil = C_nil;
    if (exception_pending()) goto v0009;
    env = stack[-3];
    v0079 = stack[-1];
    fn = elt(env, 4); // reduce!-eival!-powers
    v0079 = (*qfn2(fn))(qenv(fn), v0030, v0079);
    nil = C_nil;
    if (exception_pending()) goto v0009;
    env = stack[-3];
    fn = elt(env, 5); // subs2
    v0079 = (*qfn1(fn))(qenv(fn), v0079);
    nil = C_nil;
    if (exception_pending()) goto v0009;
    env = stack[-3];
    qvalue(elt(env, 1)) = stack[-2]; // !*sub2
    { popv(4); return onevalue(v0079); }
// error exit handlers
v0009:
    env = stack[-3];
    qvalue(elt(env, 1)) = stack[-2]; // !*sub2
    popv(4);
    return nil;
}



// Code for ofsf_smcpknowl

static LispObject CC_ofsf_smcpknowl(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0115, v0255;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_smcpknowl");
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
    v0115 = v0000;
// end of prologue
    stack[-4] = v0115;
    v0115 = stack[-4];
    if (v0115 == nil) goto v0260;
    v0115 = stack[-4];
    v0115 = qcar(v0115);
    v0255 = v0115;
    v0115 = v0255;
    stack[0] = qcar(v0115);
    v0115 = v0255;
    v0255 = qcdr(v0115);
    v0115 = qvalue(elt(env, 1)); // nil
    v0115 = Lappend(nil, v0255, v0115);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    env = stack[-5];
    v0115 = cons(stack[0], v0115);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    env = stack[-5];
    v0115 = ncons(v0115);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    env = stack[-5];
    stack[-2] = v0115;
    stack[-3] = v0115;
    goto v0137;

v0137:
    v0115 = stack[-4];
    v0115 = qcdr(v0115);
    stack[-4] = v0115;
    v0115 = stack[-4];
    if (v0115 == nil) { LispObject res = stack[-3]; popv(6); return onevalue(res); }
    stack[-1] = stack[-2];
    v0115 = stack[-4];
    v0115 = qcar(v0115);
    v0255 = v0115;
    v0115 = v0255;
    stack[0] = qcar(v0115);
    v0115 = v0255;
    v0255 = qcdr(v0115);
    v0115 = qvalue(elt(env, 1)); // nil
    v0115 = Lappend(nil, v0255, v0115);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    env = stack[-5];
    v0115 = cons(stack[0], v0115);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    env = stack[-5];
    v0115 = ncons(v0115);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    env = stack[-5];
    v0115 = Lrplacd(nil, stack[-1], v0115);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    env = stack[-5];
    v0115 = stack[-2];
    v0115 = qcdr(v0115);
    stack[-2] = v0115;
    goto v0137;

v0260:
    v0115 = qvalue(elt(env, 1)); // nil
    { popv(6); return onevalue(v0115); }
// error exit handlers
v0003:
    popv(6);
    return nil;
}



// Code for domainvalchk

static LispObject CC_domainvalchk(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0065, v0004, v0005;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for domainvalchk");
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
    v0004 = qvalue(elt(env, 1)); // dmode!*
    v0065 = elt(env, 0); // domainvalchk
    v0065 = get(v0004, v0065);
    env = stack[-3];
    stack[-2] = v0065;
    if (v0065 == nil) goto v0016;
    v0005 = stack[-2];
    v0004 = stack[-1];
    v0065 = stack[0];
        popv(4);
        return Lapply2(nil, 3, v0005, v0004, v0065);

v0016:
    v0065 = stack[0];
    v0065 = Lreverse(nil, v0065);
    nil = C_nil;
    if (exception_pending()) goto v0255;
    env = stack[-3];
    stack[0] = v0065;
    goto v0028;

v0028:
    v0065 = stack[0];
    if (v0065 == nil) goto v0075;
    v0065 = stack[0];
    v0065 = qcar(v0065);
    v0004 = qcdr(v0065);
    v0065 = (LispObject)17; // 1
    if (v0004 == v0065) goto v0008;
    v0065 = qvalue(elt(env, 2)); // nil
    { popv(4); return onevalue(v0065); }

v0008:
    v0065 = stack[0];
    v0065 = qcar(v0065);
    fn = elt(env, 3); // mk!*sq
    v0004 = (*qfn1(fn))(qenv(fn), v0065);
    nil = C_nil;
    if (exception_pending()) goto v0255;
    env = stack[-3];
    v0065 = stack[-2];
    v0065 = cons(v0004, v0065);
    nil = C_nil;
    if (exception_pending()) goto v0255;
    env = stack[-3];
    stack[-2] = v0065;
    v0065 = stack[0];
    v0065 = qcdr(v0065);
    stack[0] = v0065;
    goto v0028;

v0075:
    v0004 = stack[-1];
    v0065 = stack[-2];
    {
        popv(4);
        fn = elt(env, 4); // valuechk
        return (*qfn2(fn))(qenv(fn), v0004, v0065);
    }
// error exit handlers
v0255:
    popv(4);
    return nil;
}



// Code for cl_susicpknowl

static LispObject CC_cl_susicpknowl(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0056, v0245;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cl_susicpknowl");
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
    v0056 = v0000;
// end of prologue
    stack[-3] = v0056;
    v0056 = stack[-3];
    if (v0056 == nil) goto v0260;
    v0056 = stack[-3];
    v0056 = qcar(v0056);
    v0245 = v0056;
    v0245 = qcar(v0245);
    v0056 = qcdr(v0056);
    v0056 = cons(v0245, v0056);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-4];
    v0056 = ncons(v0056);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-4];
    stack[-1] = v0056;
    stack[-2] = v0056;
    goto v0137;

v0137:
    v0056 = stack[-3];
    v0056 = qcdr(v0056);
    stack[-3] = v0056;
    v0056 = stack[-3];
    if (v0056 == nil) { LispObject res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v0056 = stack[-3];
    v0056 = qcar(v0056);
    v0245 = v0056;
    v0245 = qcar(v0245);
    v0056 = qcdr(v0056);
    v0056 = cons(v0245, v0056);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-4];
    v0056 = ncons(v0056);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-4];
    v0056 = Lrplacd(nil, stack[0], v0056);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-4];
    v0056 = stack[-1];
    v0056 = qcdr(v0056);
    stack[-1] = v0056;
    goto v0137;

v0260:
    v0056 = qvalue(elt(env, 1)); // nil
    { popv(5); return onevalue(v0056); }
// error exit handlers
v0206:
    popv(5);
    return nil;
}



// Code for fnrd

static LispObject CC_fnrd(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0248, v0009;
    LispObject fn;
    argcheck(nargs, 0, "fnrd");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for fnrd");
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
    stack[0] = nil;
    fn = elt(env, 3); // lex
    v0248 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-1];
    v0009 = qvalue(elt(env, 1)); // char
    v0248 = elt(env, 2); // (c i)
    if (equal(v0009, v0248)) goto v0070;
    v0248 = qvalue(elt(env, 1)); // char
    v0009 = Lcompress(nil, v0248);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-1];
    v0248 = (LispObject)321; // 20
    fn = elt(env, 4); // errorml
    v0248 = (*qfn2(fn))(qenv(fn), v0009, v0248);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-1];
    goto v0028;

v0028:
    v0248 = stack[0];
    if (!(!consp(v0248))) goto v0011;
    v0248 = stack[0];
    v0248 = ncons(v0248);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-1];
    fn = elt(env, 5); // operator
    v0248 = (*qfn1(fn))(qenv(fn), v0248);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-1];
    fn = elt(env, 6); // aeval
    v0248 = (*qfn1(fn))(qenv(fn), v0248);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-1];
    goto v0011;

v0011:
    fn = elt(env, 3); // lex
    v0248 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    { LispObject res = stack[0]; popv(2); return onevalue(res); }

v0070:
    fn = elt(env, 7); // mathml2
    v0248 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-1];
    stack[0] = v0248;
    goto v0028;
// error exit handlers
v0010:
    popv(2);
    return nil;
}



// Code for noncomexpf

static LispObject CC_noncomexpf(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0075;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for noncomexpf");
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

v0035:
    v0075 = stack[0];
    if (!consp(v0075)) goto v0016;
    v0075 = stack[0];
    v0075 = qcar(v0075);
    v0075 = (consp(v0075) ? nil : lisp_true);
    goto v0137;

v0137:
    if (v0075 == nil) goto v0040;
    v0075 = qvalue(elt(env, 2)); // nil
    { popv(2); return onevalue(v0075); }

v0040:
    v0075 = stack[0];
    v0075 = qcar(v0075);
    v0075 = qcar(v0075);
    v0075 = qcar(v0075);
    fn = elt(env, 3); // noncomp
    v0075 = (*qfn1(fn))(qenv(fn), v0075);
    nil = C_nil;
    if (exception_pending()) goto v0009;
    env = stack[-1];
    if (!(v0075 == nil)) { popv(2); return onevalue(v0075); }
    v0075 = stack[0];
    v0075 = qcar(v0075);
    v0075 = qcdr(v0075);
    v0075 = CC_noncomexpf(env, v0075);
    nil = C_nil;
    if (exception_pending()) goto v0009;
    env = stack[-1];
    if (!(v0075 == nil)) { popv(2); return onevalue(v0075); }
    v0075 = stack[0];
    v0075 = qcdr(v0075);
    stack[0] = v0075;
    goto v0035;

v0016:
    v0075 = qvalue(elt(env, 1)); // t
    goto v0137;
// error exit handlers
v0009:
    popv(2);
    return nil;
}



// Code for vdpilcomb1

static LispObject CC_vdpilcomb1(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0208, v0052, v0053, v0003, v0067, v0002;
    LispObject fn;
    LispObject v0015, v0040, v0039, v0045, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 6, "vdpilcomb1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0045 = va_arg(aa, LispObject);
    v0039 = va_arg(aa, LispObject);
    v0040 = va_arg(aa, LispObject);
    v0015 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vdpilcomb1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push6(v0015,v0040,v0039,v0045,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v0000,v0001,v0045,v0039,v0040,v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    stack[-1] = v0015;
    v0208 = v0040;
    stack[-2] = v0039;
    stack[-3] = v0045;
    v0052 = v0001;
    stack[-4] = v0000;
// end of prologue
    v0053 = stack[-4];
    v0053 = qcdr(v0053);
    v0053 = qcdr(v0053);
    v0053 = qcdr(v0053);
    v0002 = qcar(v0053);
    v0067 = v0052;
    v0003 = stack[-3];
    v0052 = stack[-2];
    v0052 = qcdr(v0052);
    v0052 = qcdr(v0052);
    v0052 = qcdr(v0052);
    v0053 = qcar(v0052);
    v0052 = v0208;
    v0208 = stack[-1];
    fn = elt(env, 2); // dipilcomb1
    v0208 = (*qfnn(fn))(qenv(fn), 6, v0002, v0067, v0003, v0053, v0052, v0208);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-6];
    fn = elt(env, 3); // dip2vdp
    v0208 = (*qfn1(fn))(qenv(fn), v0208);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-6];
    stack[-5] = v0208;
    v0208 = qvalue(elt(env, 1)); // !*gsugar
    if (v0208 == nil) { LispObject res = stack[-5]; popv(7); return onevalue(res); }
    stack[0] = stack[-5];
    v0208 = stack[-4];
    fn = elt(env, 4); // gsugar
    stack[-4] = (*qfn1(fn))(qenv(fn), v0208);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-6];
    v0208 = stack[-3];
    fn = elt(env, 5); // vevtdeg
    v0208 = (*qfn1(fn))(qenv(fn), v0208);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-6];
    stack[-3] = plus2(stack[-4], v0208);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-6];
    v0208 = stack[-2];
    fn = elt(env, 4); // gsugar
    stack[-2] = (*qfn1(fn))(qenv(fn), v0208);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-6];
    v0208 = stack[-1];
    fn = elt(env, 5); // vevtdeg
    v0208 = (*qfn1(fn))(qenv(fn), v0208);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-6];
    v0208 = plus2(stack[-2], v0208);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-6];
    fn = elt(env, 6); // max
    v0208 = (*qfn2(fn))(qenv(fn), stack[-3], v0208);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-6];
    fn = elt(env, 7); // gsetsugar
    v0208 = (*qfn2(fn))(qenv(fn), stack[0], v0208);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    { LispObject res = stack[-5]; popv(7); return onevalue(res); }
// error exit handlers
v0050:
    popv(7);
    return nil;
}



// Code for color!-strand

static LispObject CC_colorKstrand(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0009, v0023, v0010;
    LispObject fn;
    LispObject v0045, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "color-strand");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0045 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for color-strand");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0045,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0045);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0045;
    stack[-1] = v0001;
    stack[-2] = v0000;
// end of prologue
    stack[-3] = nil;
    goto v0137;

v0137:
    v0009 = stack[-1];
    if (v0009 == nil) goto v0259;
    v0023 = stack[-2];
    v0009 = stack[-1];
    v0009 = qcar(v0009);
    fn = elt(env, 1); // color!-roads
    v0010 = (*qfn2(fn))(qenv(fn), v0023, v0009);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-4];
    v0023 = stack[0];
    v0009 = stack[-3];
    v0009 = acons(v0010, v0023, v0009);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-4];
    stack[-3] = v0009;
    v0009 = stack[-1];
    v0009 = qcdr(v0009);
    stack[-1] = v0009;
    v0009 = stack[0];
    v0009 = add1(v0009);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-4];
    stack[0] = v0009;
    goto v0137;

v0259:
    v0009 = stack[-3];
    {
        popv(5);
        fn = elt(env, 2); // nreverse
        return (*qfn1(fn))(qenv(fn), v0009);
    }
// error exit handlers
v0110:
    popv(5);
    return nil;
}



// Code for mo!=zero

static LispObject CC_moMzero(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0072, v0011, v0012;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mo=zero");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0011 = v0000;
// end of prologue

v0035:
    v0072 = v0011;
    if (v0072 == nil) goto v0040;
    v0072 = v0011;
    v0012 = qcar(v0072);
    v0072 = (LispObject)1; // 0
    if (v0012 == v0072) goto v0077;
    v0072 = qvalue(elt(env, 2)); // nil
    return onevalue(v0072);

v0077:
    v0072 = v0011;
    v0072 = qcdr(v0072);
    v0011 = v0072;
    goto v0035;

v0040:
    v0072 = qvalue(elt(env, 1)); // t
    return onevalue(v0072);
}



// Code for dfprintfn

static LispObject CC_dfprintfn(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0267, v0007, v0261;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dfprintfn");
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
    v0267 = v0000;
// end of prologue
    v0007 = qvalue(elt(env, 1)); // !*nat
    if (v0007 == nil) goto v0016;
    v0007 = qvalue(elt(env, 3)); // !*fort
    if (!(v0007 == nil)) goto v0137;
    v0007 = qvalue(elt(env, 4)); // !*dfprint
    v0007 = (v0007 == nil ? lisp_true : nil);
    goto v0137;

v0137:
    if (v0007 == nil) goto v0079;
    v0267 = elt(env, 5); // failed
    { popv(1); return onevalue(v0267); }

v0079:
    v0007 = elt(env, 6); // !!df!!
    v0267 = qcdr(v0267);
    v0261 = cons(v0007, v0267);
    nil = C_nil;
    if (exception_pending()) goto v0008;
    env = stack[0];
    v0007 = (LispObject)1; // 0
    v0267 = qvalue(elt(env, 7)); // nil
    fn = elt(env, 8); // layout!-formula
    v0267 = (*qfnn(fn))(qenv(fn), 3, v0261, v0007, v0267);
    nil = C_nil;
    if (exception_pending()) goto v0008;
    env = stack[0];
    v0007 = v0267;
    v0267 = v0007;
    if (v0267 == nil) goto v0110;
    v0267 = v0007;
    fn = elt(env, 9); // putpline
    v0267 = (*qfn1(fn))(qenv(fn), v0267);
    nil = C_nil;
    if (exception_pending()) goto v0008;
    v0267 = nil;
    { popv(1); return onevalue(v0267); }

v0110:
    v0267 = elt(env, 5); // failed
    { popv(1); return onevalue(v0267); }

v0016:
    v0007 = qvalue(elt(env, 2)); // t
    goto v0137;
// error exit handlers
v0008:
    popv(1);
    return nil;
}



// Code for clean_numid

static LispObject CC_clean_numid(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0034, v0078;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for clean_numid");
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
    v0034 = stack[0];
    if (v0034 == nil) goto v0016;
    v0034 = stack[0];
    v0034 = qcar(v0034);
    fn = elt(env, 1); // !*id2num
    v0034 = (*qfn1(fn))(qenv(fn), v0034);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-2];
    if (v0034 == nil) goto v0084;
    v0034 = stack[0];
    v0034 = qcdr(v0034);
    stack[0] = v0034;
    goto v0015;

v0084:
    v0034 = stack[0];
    v0078 = qcar(v0034);
    v0034 = stack[-1];
    v0034 = cons(v0078, v0034);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-2];
    stack[-1] = v0034;
    v0034 = stack[0];
    v0034 = qcdr(v0034);
    stack[0] = v0034;
    goto v0015;

v0016:
    v0034 = stack[-1];
    {
        popv(3);
        fn = elt(env, 2); // nreverse
        return (*qfn1(fn))(qenv(fn), v0034);
    }
// error exit handlers
v0074:
    popv(3);
    return nil;
}



// Code for dummyp

static LispObject CC_dummyp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0051, v0262, v0018;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dummyp");
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
    v0051 = (LispObject)1; // 0
    stack[-2] = v0051;
    v0051 = stack[-3];
    if (symbolp(v0051)) goto v0259;
    v0051 = qvalue(elt(env, 1)); // nil
    { popv(6); return onevalue(v0051); }

v0259:
    v0051 = (LispObject)17; // 1
    stack[-4] = v0051;
    goto v0017;

v0017:
    stack[0] = stack[-4];
    v0051 = qvalue(elt(env, 2)); // g_dvnames
    fn = elt(env, 4); // upbve
    v0051 = (*qfn1(fn))(qenv(fn), v0051);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-5];
    v0051 = (LispObject)lesseq2(stack[0], v0051);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    v0051 = v0051 ? lisp_true : nil;
    env = stack[-5];
    if (v0051 == nil) goto v0118;
    stack[-1] = stack[-3];
    stack[0] = qvalue(elt(env, 2)); // g_dvnames
    v0051 = stack[-4];
    v0051 = sub1(v0051);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-5];
    v0051 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0051/(16/CELL)));
    if (equal(stack[-1], v0051)) goto v0079;
    v0051 = stack[-4];
    v0051 = add1(v0051);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-5];
    stack[-4] = v0051;
    goto v0017;

v0079:
    v0051 = stack[-4];
    stack[-2] = v0051;
    v0051 = qvalue(elt(env, 2)); // g_dvnames
    fn = elt(env, 4); // upbve
    v0051 = (*qfn1(fn))(qenv(fn), v0051);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-5];
    v0051 = add1(v0051);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-5];
    stack[-4] = v0051;
    goto v0017;

v0118:
    v0262 = stack[-2];
    v0051 = (LispObject)1; // 0
    if (!(v0262 == v0051)) { LispObject res = stack[-2]; popv(6); return onevalue(res); }
    v0051 = stack[-3];
    fn = elt(env, 5); // ad_splitname
    v0051 = (*qfn1(fn))(qenv(fn), v0051);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-5];
    v0262 = v0051;
    v0051 = v0262;
    v0051 = qcar(v0051);
    v0018 = qvalue(elt(env, 3)); // g_dvbase
    if (v0051 == v0018) goto v0116;
    v0051 = nil;
    { popv(6); return onevalue(v0051); }

v0116:
    v0051 = v0262;
    v0051 = qcdr(v0051);
    { popv(6); return onevalue(v0051); }
// error exit handlers
v0048:
    popv(6);
    return nil;
}



// Code for difbf

static LispObject CC_difbf(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0185, v0351, v0230;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for difbf");
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
    stack[-6] = v0001;
    stack[-7] = v0000;
// end of prologue
    v0185 = stack[-7];
    v0185 = qcdr(v0185);
    v0351 = qcar(v0185);
    stack[-8] = v0351;
    v0185 = (LispObject)1; // 0
    if (v0351 == v0185) goto v0080;
    v0185 = stack[-6];
    v0185 = qcdr(v0185);
    v0351 = qcar(v0185);
    stack[-5] = v0351;
    v0185 = (LispObject)1; // 0
    if (v0351 == v0185) goto v0011;
    v0185 = stack[-7];
    v0185 = qcdr(v0185);
    v0351 = qcdr(v0185);
    stack[-4] = v0351;
    v0185 = stack[-6];
    v0185 = qcdr(v0185);
    v0185 = qcdr(v0185);
    stack[-3] = v0185;
    v0351 = difference2(v0351, v0185);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-9];
    stack[-2] = v0351;
    v0185 = (LispObject)1; // 0
    if (v0351 == v0185) goto v0117;
    stack[-1] = stack[-2];
    v0185 = stack[-8];
    v0185 = Labsval(nil, v0185);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-9];
    fn = elt(env, 3); // msd
    stack[0] = (*qfn1(fn))(qenv(fn), v0185);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-9];
    v0185 = stack[-5];
    v0185 = Labsval(nil, v0185);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-9];
    fn = elt(env, 3); // msd
    v0185 = (*qfn1(fn))(qenv(fn), v0185);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-9];
    v0185 = difference2(stack[0], v0185);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-9];
    v0185 = plus2(stack[-1], v0185);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-9];
    stack[-1] = v0185;
    v0185 = qvalue(elt(env, 2)); // !:bprec!:
    v0185 = add1(v0185);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-9];
    stack[0] = v0185;
    v0351 = stack[-1];
    v0185 = stack[0];
    v0185 = (LispObject)greaterp2(v0351, v0185);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    v0185 = v0185 ? lisp_true : nil;
    env = stack[-9];
    if (v0185 == nil) goto v0361;
    v0185 = stack[-7];
    goto v0260;

v0260:
    stack[-2] = v0185;
    v0185 = stack[-2];
    v0185 = qcdr(v0185);
    v0185 = qcar(v0185);
    v0230 = v0185;
    v0351 = v0230;
    v0185 = (LispObject)1; // 0
    if (v0351 == v0185) goto v0319;
    v0351 = v0230;
    v0185 = qvalue(elt(env, 2)); // !:bprec!:
    fn = elt(env, 4); // inorm
    v0185 = (*qfn2(fn))(qenv(fn), v0351, v0185);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-9];
    v0230 = v0185;
    stack[-1] = elt(env, 1); // !:rd!:
    v0185 = v0230;
    stack[0] = qcar(v0185);
    v0185 = v0230;
    v0351 = qcdr(v0185);
    v0185 = stack[-2];
    v0185 = qcdr(v0185);
    v0185 = qcdr(v0185);
    v0185 = plus2(v0351, v0185);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    {
        LispObject v0362 = stack[-1];
        LispObject v0363 = stack[0];
        popv(10);
        return list2star(v0362, v0363, v0185);
    }

v0319:
    v0230 = elt(env, 1); // !:rd!:
    v0351 = (LispObject)1; // 0
    v0185 = (LispObject)1; // 0
    popv(10);
    return list2star(v0230, v0351, v0185);

v0361:
    v0185 = stack[0];
    v0185 = negate(v0185);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-9];
    v0185 = (LispObject)lessp2(stack[-1], v0185);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    v0185 = v0185 ? lisp_true : nil;
    env = stack[-9];
    if (v0185 == nil) goto v0256;
    v0185 = stack[-6];
    fn = elt(env, 5); // minus!:
    v0185 = (*qfn1(fn))(qenv(fn), v0185);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-9];
    goto v0260;

v0256:
    v0351 = stack[-2];
    v0185 = (LispObject)1; // 0
    v0185 = (LispObject)greaterp2(v0351, v0185);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    v0185 = v0185 ? lisp_true : nil;
    env = stack[-9];
    if (v0185 == nil) goto v0344;
    stack[0] = elt(env, 1); // !:rd!:
    v0351 = stack[-8];
    v0185 = stack[-2];
    fn = elt(env, 6); // ashift
    v0351 = (*qfn2(fn))(qenv(fn), v0351, v0185);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-9];
    v0185 = stack[-5];
    v0351 = difference2(v0351, v0185);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-9];
    v0185 = stack[-3];
    v0185 = list2star(stack[0], v0351, v0185);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-9];
    goto v0260;

v0344:
    stack[0] = elt(env, 1); // !:rd!:
    stack[-1] = stack[-8];
    stack[-3] = stack[-5];
    v0185 = stack[-2];
    v0185 = negate(v0185);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-9];
    fn = elt(env, 6); // ashift
    v0185 = (*qfn2(fn))(qenv(fn), stack[-3], v0185);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-9];
    v0351 = difference2(stack[-1], v0185);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-9];
    v0185 = stack[-4];
    v0185 = list2star(stack[0], v0351, v0185);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-9];
    goto v0260;

v0117:
    stack[0] = elt(env, 1); // !:rd!:
    v0351 = stack[-8];
    v0185 = stack[-5];
    v0351 = difference2(v0351, v0185);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-9];
    v0185 = stack[-4];
    v0185 = list2star(stack[0], v0351, v0185);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-9];
    goto v0260;

v0011:
    v0185 = stack[-7];
    goto v0260;

v0080:
    v0185 = stack[-6];
    fn = elt(env, 5); // minus!:
    v0185 = (*qfn1(fn))(qenv(fn), v0185);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-9];
    goto v0260;
// error exit handlers
v0293:
    popv(10);
    return nil;
}



setup_type const u33_setup[] =
{
    {"evinvlexcomp",            too_few_2,      CC_evinvlexcomp,wrong_no_2},
    {"po:statep",               CC_poTstatep,   too_many_1,    wrong_no_1},
    {"find_buble",              too_few_2,      CC_find_buble, wrong_no_2},
    {"assert_structstat",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_assert_structstat},
    {"subs2chk",                CC_subs2chk,    too_many_1,    wrong_no_1},
    {"fs:prin",                 CC_fsTprin,     too_many_1,    wrong_no_1},
    {"dv_ind2var",              CC_dv_ind2var,  too_many_1,    wrong_no_1},
    {"outer-simpsqrt",          CC_outerKsimpsqrt,too_many_1,  wrong_no_1},
    {"msolve-polyn",            too_few_2,      CC_msolveKpolyn,wrong_no_2},
    {"letexprn",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_letexprn},
    {"vector-to-poly",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_vectorKtoKpoly},
    {"rl_transform",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_rl_transform},
    {"plusdf",                  too_few_2,      CC_plusdf,     wrong_no_2},
    {"get*inverse",             too_few_2,      CC_getHinverse,wrong_no_2},
    {"pasf_anegrel",            CC_pasf_anegrel,too_many_1,    wrong_no_1},
    {"aex_subrat1",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_aex_subrat1},
    {"cgp_lbc",                 CC_cgp_lbc,     too_many_1,    wrong_no_1},
    {"listrd",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_listrd},
    {"delyzz",                  too_few_2,      CC_delyzz,     wrong_no_2},
    {"unplus",                  CC_unplus,      too_many_1,    wrong_no_1},
    {"convprc2",                too_few_2,      CC_convprc2,   wrong_no_2},
    {"color-roads",             too_few_2,      CC_colorKroads,wrong_no_2},
    {"realvaluedp",             CC_realvaluedp, too_many_1,    wrong_no_1},
    {"subeval1",                too_few_2,      CC_subeval1,   wrong_no_2},
    {"ratfunpri1",              CC_ratfunpri1,  too_many_1,    wrong_no_1},
    {"dp_neworder",             CC_dp_neworder, too_many_1,    wrong_no_1},
    {"*f2di",                   too_few_2,      CC_Hf2di,      wrong_no_2},
    {"list_is_all_free",        CC_list_is_all_free,too_many_1,wrong_no_1},
    {"msolve-poly1",            too_few_2,      CC_msolveKpoly1,wrong_no_2},
    {"reduce-mod-eigf",         too_few_2,      CC_reduceKmodKeigf,wrong_no_2},
    {"ofsf_smcpknowl",          CC_ofsf_smcpknowl,too_many_1,  wrong_no_1},
    {"domainvalchk",            too_few_2,      CC_domainvalchk,wrong_no_2},
    {"cl_susicpknowl",          CC_cl_susicpknowl,too_many_1,  wrong_no_1},
    {"fnrd",                    wrong_no_na,    wrong_no_nb,   (n_args *)CC_fnrd},
    {"noncomexpf",              CC_noncomexpf,  too_many_1,    wrong_no_1},
    {"vdpilcomb1",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_vdpilcomb1},
    {"color-strand",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_colorKstrand},
    {"mo=zero",                 CC_moMzero,     too_many_1,    wrong_no_1},
    {"dfprintfn",               CC_dfprintfn,   too_many_1,    wrong_no_1},
    {"clean_numid",             CC_clean_numid, too_many_1,    wrong_no_1},
    {"dummyp",                  CC_dummyp,      too_many_1,    wrong_no_1},
    {"difbf",                   too_few_2,      CC_difbf,      wrong_no_2},
    {NULL, (one_args *)"u33", (two_args *)"19394 6636748 6906193", 0}
};

// end of generated code
