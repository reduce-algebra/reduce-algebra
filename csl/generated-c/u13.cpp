
// $destdir/u13.c        Machine generated C code

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



// Code for use!-berlekamp

static LispObject CC_useKberlekamp(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0084, v0085, v0086, v0087, v0088, v0089, v0090;
    LispObject fn;
    LispObject v0024, v0058, v0059;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "use-berlekamp");
    va_start(aa, nargs);
    v0059 = va_arg(aa, LispObject);
    v0058 = va_arg(aa, LispObject);
    v0024 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for use-berlekamp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0024,v0058,v0059);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0059,v0058,v0024);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[-4] = v0024;
    stack[-5] = v0058;
    stack[-6] = v0059;
// end of prologue
    v0084 = qvalue(elt(env, 1)); // dpoly
    v0084 = (LispObject)((int32_t)(v0084) - 0x10);
    stack[-3] = v0084;
    v0084 = stack[-3];
    v0084 = Lmkvect(nil, v0084);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    env = stack[-8];
    stack[-7] = v0084;
    v0084 = (LispObject)1; // 0
    stack[0] = v0084;
    goto v0092;

v0092:
    v0085 = stack[-3];
    v0084 = stack[0];
    v0084 = (LispObject)(int32_t)((int32_t)v0085 - (int32_t)v0084 + TAG_FIXNUM);
    v0084 = ((intptr_t)(v0084) < 0 ? lisp_true : nil);
    if (v0084 == nil) goto v0093;
    v0087 = stack[-6];
    v0086 = stack[-5];
    v0085 = qvalue(elt(env, 3)); // poly!-vector
    v0084 = qvalue(elt(env, 1)); // dpoly
    fn = elt(env, 5); // remainder!-in!-vector
    v0084 = (*qfnn(fn))(qenv(fn), 4, v0087, v0086, v0085, v0084);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    env = stack[-8];
    stack[-5] = v0084;
    v0084 = (LispObject)1; // 0
    stack[-2] = v0084;
    v0084 = stack[-3];
    v0084 = Lmkvect(nil, v0084);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    env = stack[-8];
    stack[-1] = v0084;
    v0086 = stack[-1];
    v0085 = (LispObject)1; // 0
    v0084 = (LispObject)17; // 1
    *(LispObject *)((char *)v0086 + (CELL-TAG_VECTOR) + ((int32_t)v0085/(16/CELL))) = v0084;
    v0084 = (LispObject)17; // 1
    stack[0] = v0084;
    goto v0094;

v0094:
    v0085 = stack[-3];
    v0084 = stack[0];
    v0084 = (LispObject)(int32_t)((int32_t)v0085 - (int32_t)v0084 + TAG_FIXNUM);
    v0084 = ((intptr_t)(v0084) < 0 ? lisp_true : nil);
    if (v0084 == nil) goto v0095;
    v0085 = stack[-7];
    v0084 = stack[-3];
    {
        popv(9);
        fn = elt(env, 6); // find!-null!-space
        return (*qfn2(fn))(qenv(fn), v0085, v0084);
    }

v0095:
    v0085 = qvalue(elt(env, 4)); // current!-modulus
    v0084 = qvalue(elt(env, 1)); // dpoly
    if (((int32_t)(v0085)) > ((int32_t)(v0084))) goto v0096;
    v0084 = (LispObject)1; // 0
    v0087 = v0084;
    goto v0097;

v0097:
    v0084 = qvalue(elt(env, 4)); // current!-modulus
    v0085 = (LispObject)((int32_t)(v0084) - 0x10);
    v0084 = v0087;
    v0084 = (LispObject)(int32_t)((int32_t)v0085 - (int32_t)v0084 + TAG_FIXNUM);
    v0084 = ((intptr_t)(v0084) < 0 ? lisp_true : nil);
    if (v0084 == nil) goto v0098;
    v0084 = (LispObject)1; // 0
    v0088 = v0084;
    goto v0099;

v0099:
    v0085 = stack[-2];
    v0084 = v0088;
    v0084 = (LispObject)(int32_t)((int32_t)v0085 - (int32_t)v0084 + TAG_FIXNUM);
    v0084 = ((intptr_t)(v0084) < 0 ? lisp_true : nil);
    if (v0084 == nil) goto v0100;
    v0085 = stack[-2];
    v0084 = qvalue(elt(env, 4)); // current!-modulus
    v0084 = (LispObject)(int32_t)((int32_t)v0085 + (int32_t)v0084 - TAG_FIXNUM);
    stack[-2] = v0084;
    goto v0101;

v0101:
    v0087 = stack[-4];
    v0086 = stack[-2];
    v0085 = qvalue(elt(env, 3)); // poly!-vector
    v0084 = qvalue(elt(env, 1)); // dpoly
    fn = elt(env, 5); // remainder!-in!-vector
    v0084 = (*qfnn(fn))(qenv(fn), 4, v0087, v0086, v0085, v0084);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    env = stack[-8];
    stack[-2] = v0084;
    v0084 = (LispObject)1; // 0
    v0090 = v0084;
    goto v0102;

v0102:
    v0085 = stack[-2];
    v0084 = v0090;
    v0084 = (LispObject)(int32_t)((int32_t)v0085 - (int32_t)v0084 + TAG_FIXNUM);
    v0084 = ((intptr_t)(v0084) < 0 ? lisp_true : nil);
    if (v0084 == nil) goto v0103;
    v0085 = stack[-7];
    v0084 = stack[0];
    v0087 = *(LispObject *)((char *)v0085 + (CELL-TAG_VECTOR) + ((int32_t)v0084/(16/CELL)));
    v0086 = stack[0];
    v0085 = stack[-7];
    v0084 = stack[0];
    v0085 = *(LispObject *)((char *)v0085 + (CELL-TAG_VECTOR) + ((int32_t)v0084/(16/CELL)));
    v0084 = stack[0];
    v0085 = *(LispObject *)((char *)v0085 + (CELL-TAG_VECTOR) + ((int32_t)v0084/(16/CELL)));
    v0084 = (LispObject)17; // 1
    {   int32_t w = int_of_fixnum(v0085) - int_of_fixnum(v0084);
        if (w < 0) w += current_modulus;
        v0084 = fixnum_of_int(w);
    }
    *(LispObject *)((char *)v0087 + (CELL-TAG_VECTOR) + ((int32_t)v0086/(16/CELL))) = v0084;
    v0084 = stack[0];
    v0084 = (LispObject)((int32_t)(v0084) + 0x10);
    stack[0] = v0084;
    goto v0094;

v0103:
    v0085 = stack[-7];
    v0084 = v0090;
    v0089 = *(LispObject *)((char *)v0085 + (CELL-TAG_VECTOR) + ((int32_t)v0084/(16/CELL)));
    v0088 = stack[0];
    v0087 = stack[-1];
    v0086 = v0090;
    v0085 = stack[-4];
    v0084 = v0090;
    v0084 = *(LispObject *)((char *)v0085 + (CELL-TAG_VECTOR) + ((int32_t)v0084/(16/CELL)));
    *(LispObject *)((char *)v0087 + (CELL-TAG_VECTOR) + ((int32_t)v0086/(16/CELL))) = v0084;
    *(LispObject *)((char *)v0089 + (CELL-TAG_VECTOR) + ((int32_t)v0088/(16/CELL))) = v0084;
    v0084 = v0090;
    v0084 = (LispObject)((int32_t)(v0084) + 0x10);
    v0090 = v0084;
    goto v0102;

v0100:
    v0087 = stack[-4];
    v0085 = qvalue(elt(env, 4)); // current!-modulus
    v0084 = v0088;
    v0086 = (LispObject)(int32_t)((int32_t)v0085 + (int32_t)v0084 - TAG_FIXNUM);
    v0085 = stack[-1];
    v0084 = v0088;
    v0084 = *(LispObject *)((char *)v0085 + (CELL-TAG_VECTOR) + ((int32_t)v0084/(16/CELL)));
    *(LispObject *)((char *)v0087 + (CELL-TAG_VECTOR) + ((int32_t)v0086/(16/CELL))) = v0084;
    v0084 = v0088;
    v0084 = (LispObject)((int32_t)(v0084) + 0x10);
    v0088 = v0084;
    goto v0099;

v0098:
    v0086 = stack[-4];
    v0085 = v0087;
    v0084 = (LispObject)1; // 0
    *(LispObject *)((char *)v0086 + (CELL-TAG_VECTOR) + ((int32_t)v0085/(16/CELL))) = v0084;
    v0084 = v0087;
    v0084 = (LispObject)((int32_t)(v0084) + 0x10);
    v0087 = v0084;
    goto v0097;

v0096:
    v0088 = stack[-1];
    v0087 = stack[-2];
    v0086 = stack[-6];
    v0085 = stack[-5];
    v0084 = stack[-4];
    fn = elt(env, 7); // times!-in!-vector
    v0084 = (*qfnn(fn))(qenv(fn), 5, v0088, v0087, v0086, v0085, v0084);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    env = stack[-8];
    stack[-2] = v0084;
    goto v0101;

v0093:
    v0084 = stack[-3];
    v0084 = Lmkvect(nil, v0084);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    env = stack[-8];
    v0088 = v0084;
    v0084 = (LispObject)1; // 0
    v0087 = v0084;
    goto v0104;

v0104:
    v0085 = stack[-3];
    v0084 = v0087;
    v0084 = (LispObject)(int32_t)((int32_t)v0085 - (int32_t)v0084 + TAG_FIXNUM);
    v0084 = ((intptr_t)(v0084) < 0 ? lisp_true : nil);
    if (v0084 == nil) goto v0105;
    v0085 = stack[-7];
    v0084 = stack[0];
    v0086 = v0088;
    *(LispObject *)((char *)v0085 + (CELL-TAG_VECTOR) + ((int32_t)v0084/(16/CELL))) = v0086;
    v0084 = stack[0];
    v0084 = (LispObject)((int32_t)(v0084) + 0x10);
    stack[0] = v0084;
    goto v0092;

v0105:
    v0086 = v0088;
    v0085 = v0087;
    v0084 = (LispObject)1; // 0
    *(LispObject *)((char *)v0086 + (CELL-TAG_VECTOR) + ((int32_t)v0085/(16/CELL))) = v0084;
    v0084 = v0087;
    v0084 = (LispObject)((int32_t)(v0084) + 0x10);
    v0087 = v0084;
    goto v0104;
// error exit handlers
v0091:
    popv(9);
    return nil;
}



// Code for idsort

static LispObject CC_idsort(LispObject env,
                         LispObject v0059)
{
    LispObject nil = C_nil;
    LispObject v0107, v0108;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for idsort");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0107 = v0059;
// end of prologue
    v0108 = v0107;
    v0107 = elt(env, 1); // idcompare
    {
        fn = elt(env, 2); // sort
        return (*qfn2(fn))(qenv(fn), v0108, v0107);
    }
}



// Code for removeg1

static LispObject CC_removeg1(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0164, v0165, v0166, v0167;
    LispObject fn;
    LispObject v0024, v0058, v0059;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "removeg1");
    va_start(aa, nargs);
    v0059 = va_arg(aa, LispObject);
    v0058 = va_arg(aa, LispObject);
    v0024 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for removeg1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0024,v0058,v0059);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0059,v0058,v0024);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
// copy arguments values to proper place
    stack[-3] = v0024;
    stack[-4] = v0058;
    stack[-5] = v0059;
// end of prologue
    v0165 = stack[-5];
    v0164 = stack[-4];
    fn = elt(env, 9); // removev
    v0164 = (*qfn2(fn))(qenv(fn), v0165, v0164);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    v0165 = stack[-5];
    v0164 = stack[-3];
    fn = elt(env, 9); // removev
    v0164 = (*qfn2(fn))(qenv(fn), v0165, v0164);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    v0164 = stack[-4];
    v0164 = qcdr(v0164);
    v0165 = qcar(v0164);
    v0164 = stack[-3];
    v0164 = qcdr(v0164);
    v0164 = qcdr(v0164);
    v0164 = qcar(v0164);
    if (v0165 == v0164) goto v0169;
    v0164 = qvalue(elt(env, 1)); // nil
    goto v0170;

v0170:
    if (v0164 == nil) goto v0171;
    v0165 = qvalue(elt(env, 2)); // n!*!*2!-1
    v0164 = stack[-5];
    v0164 = qcar(v0164);
    fn = elt(env, 10); // multsq
    v0165 = (*qfn2(fn))(qenv(fn), v0165, v0164);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    v0164 = stack[-5];
    v0164 = qcdr(v0164);
    v0164 = cons(v0165, v0164);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    popv(8);
    return ncons(v0164);

v0171:
    v0164 = stack[-5];
    v0165 = qcdr(v0164);
    v0164 = stack[-4];
    v0164 = qcdr(v0164);
    v0164 = qcdr(v0164);
    v0164 = qcar(v0164);
    fn = elt(env, 11); // finde
    v0164 = (*qfn2(fn))(qenv(fn), v0165, v0164);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    stack[-6] = v0164;
    v0164 = stack[-4];
    v0164 = qcdr(v0164);
    v0165 = qcar(v0164);
    v0164 = stack[-3];
    v0164 = qcdr(v0164);
    v0164 = qcdr(v0164);
    v0164 = qcar(v0164);
    if (v0165 == v0164) goto v0172;
    v0164 = stack[-5];
    v0165 = qcdr(v0164);
    v0164 = stack[-3];
    v0164 = qcdr(v0164);
    v0164 = qcdr(v0164);
    v0164 = qcar(v0164);
    fn = elt(env, 11); // finde
    v0164 = (*qfn2(fn))(qenv(fn), v0165, v0164);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    stack[-2] = v0164;
    v0164 = stack[-4];
    v0164 = qcdr(v0164);
    v0164 = qcdr(v0164);
    v0165 = qcar(v0164);
    v0164 = stack[-3];
    v0164 = qcdr(v0164);
    v0164 = qcar(v0164);
    if (v0165 == v0164) goto v0173;
    v0164 = stack[-6];
    if (v0164 == nil) goto v0028;
    v0164 = stack[-2];
    v0164 = (v0164 == nil ? lisp_true : nil);
    goto v0174;

v0174:
    if (v0164 == nil) goto v0102;
    stack[0] = elt(env, 7); // "Invalid structure of c-graph"
    v0164 = stack[-5];
    if (v0164 == nil) goto v0027;
    v0164 = stack[-5];
    v0164 = qcdr(v0164);
    if (v0164 == nil) goto v0175;
    v0165 = elt(env, 8); // times
    v0164 = stack[-5];
    v0164 = cons(v0165, v0164);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    goto v0176;

v0176:
    v0164 = list2(stack[0], v0164);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    fn = elt(env, 12); // cerror
    v0164 = (*qfn1(fn))(qenv(fn), v0164);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    goto v0102;

v0102:
    v0164 = stack[-6];
    v0164 = qcar(v0164);
    stack[-6] = v0164;
    v0164 = stack[-2];
    v0164 = qcar(v0164);
    stack[-2] = v0164;
    v0164 = stack[-6];
    v0165 = qcdr(v0164);
    v0164 = stack[-3];
    v0164 = qcdr(v0164);
    v0164 = qcar(v0164);
    v0164 = Lrplaca(nil, v0165, v0164);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    v0164 = stack[-2];
    v0165 = qcdr(v0164);
    v0164 = stack[-4];
    v0164 = qcdr(v0164);
    v0164 = qcar(v0164);
    v0164 = Lrplaca(nil, v0165, v0164);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    v0164 = stack[-5];
    stack[0] = qcar(v0164);
    v0164 = stack[-5];
    v0164 = qcdr(v0164);
    fn = elt(env, 13); // mkcopy
    v0164 = (*qfn1(fn))(qenv(fn), v0164);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    v0164 = cons(stack[0], v0164);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    stack[-1] = v0164;
    v0164 = stack[-1];
    v0164 = qcdr(v0164);
    stack[0] = v0164;
    v0165 = stack[-6];
    v0164 = stack[0];
    v0164 = Lmember(nil, v0165, v0164);
    v0164 = qcar(v0164);
    stack[-6] = v0164;
    v0165 = stack[-2];
    v0164 = stack[0];
    v0164 = Lmember(nil, v0165, v0164);
    v0164 = qcar(v0164);
    stack[-2] = v0164;
    v0164 = stack[-6];
    v0165 = qcdr(v0164);
    v0164 = stack[-4];
    v0164 = qcdr(v0164);
    v0164 = qcar(v0164);
    v0164 = Lrplaca(nil, v0165, v0164);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    v0164 = stack[-2];
    v0165 = qcdr(v0164);
    v0164 = stack[-3];
    v0164 = qcdr(v0164);
    v0164 = qcar(v0164);
    v0164 = Lrplaca(nil, v0165, v0164);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    stack[-2] = stack[-5];
    v0165 = (LispObject)-15; // -1
    v0164 = (LispObject)17; // 1
    v0165 = cons(v0165, v0164);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    v0164 = qvalue(elt(env, 5)); // su_order
    fn = elt(env, 14); // quotsq
    v0165 = (*qfn2(fn))(qenv(fn), v0165, v0164);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    v0164 = stack[-1];
    v0164 = qcar(v0164);
    fn = elt(env, 10); // multsq
    v0165 = (*qfn2(fn))(qenv(fn), v0165, v0164);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    v0164 = stack[0];
    {
        LispObject v0177 = stack[-2];
        popv(8);
        return list2star(v0177, v0165, v0164);
    }

v0175:
    v0164 = stack[-5];
    v0164 = qcar(v0164);
    goto v0176;

v0027:
    v0164 = qvalue(elt(env, 1)); // nil
    goto v0176;

v0028:
    v0164 = qvalue(elt(env, 6)); // t
    goto v0174;

v0173:
    v0164 = stack[-2];
    if (v0164 == nil) goto v0044;
    v0164 = stack[-2];
    v0164 = qcar(v0164);
    v0165 = qcdr(v0164);
    v0164 = stack[-4];
    v0164 = qcdr(v0164);
    v0164 = qcar(v0164);
    v0164 = Lrplaca(nil, v0165, v0164);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    goto v0033;

v0033:
    v0165 = qvalue(elt(env, 2)); // n!*!*2!-1
    v0164 = qvalue(elt(env, 5)); // su_order
    fn = elt(env, 14); // quotsq
    v0165 = (*qfn2(fn))(qenv(fn), v0165, v0164);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    v0164 = stack[-5];
    v0164 = qcar(v0164);
    fn = elt(env, 10); // multsq
    v0165 = (*qfn2(fn))(qenv(fn), v0165, v0164);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    v0164 = stack[-5];
    v0164 = qcdr(v0164);
    v0164 = cons(v0165, v0164);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    popv(8);
    return ncons(v0164);

v0044:
    v0167 = elt(env, 3); // "Free edge"
    v0164 = stack[-3];
    v0164 = qcdr(v0164);
    v0164 = qcdr(v0164);
    v0166 = qcar(v0164);
    v0165 = elt(env, 4); // "in vertex"
    v0164 = stack[-3];
    v0164 = list4(v0167, v0166, v0165, v0164);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    fn = elt(env, 12); // cerror
    v0164 = (*qfn1(fn))(qenv(fn), v0164);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    goto v0033;

v0172:
    v0164 = stack[-6];
    if (v0164 == nil) goto v0095;
    v0164 = stack[-6];
    v0164 = qcar(v0164);
    v0165 = qcdr(v0164);
    v0164 = stack[-3];
    v0164 = qcdr(v0164);
    v0164 = qcar(v0164);
    v0164 = Lrplaca(nil, v0165, v0164);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    goto v0178;

v0178:
    v0165 = qvalue(elt(env, 2)); // n!*!*2!-1
    v0164 = qvalue(elt(env, 5)); // su_order
    fn = elt(env, 14); // quotsq
    v0165 = (*qfn2(fn))(qenv(fn), v0165, v0164);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    v0164 = stack[-5];
    v0164 = qcar(v0164);
    fn = elt(env, 10); // multsq
    v0165 = (*qfn2(fn))(qenv(fn), v0165, v0164);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    v0164 = stack[-5];
    v0164 = qcdr(v0164);
    v0164 = cons(v0165, v0164);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    popv(8);
    return ncons(v0164);

v0095:
    v0167 = elt(env, 3); // "Free edge"
    v0164 = stack[-4];
    v0164 = qcdr(v0164);
    v0164 = qcdr(v0164);
    v0166 = qcar(v0164);
    v0165 = elt(env, 4); // "in vertex"
    v0164 = stack[-4];
    v0164 = list4(v0167, v0166, v0165, v0164);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    fn = elt(env, 12); // cerror
    v0164 = (*qfn1(fn))(qenv(fn), v0164);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    goto v0178;

v0169:
    v0164 = stack[-4];
    v0164 = qcdr(v0164);
    v0164 = qcdr(v0164);
    v0165 = qcar(v0164);
    v0164 = stack[-3];
    v0164 = qcdr(v0164);
    v0164 = qcar(v0164);
    v0164 = (v0165 == v0164 ? lisp_true : nil);
    goto v0170;
// error exit handlers
v0168:
    popv(8);
    return nil;
}



// Code for rd!:minus

static LispObject CC_rdTminus(LispObject env,
                         LispObject v0059)
{
    LispObject nil = C_nil;
    LispObject v0180, v0181;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rd:minus");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0059);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0059);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0181 = v0059;
// end of prologue
    v0180 = v0181;
    v0180 = qcdr(v0180);
    if (!consp(v0180)) goto v0106;
    v0180 = v0181;
    {
        popv(1);
        fn = elt(env, 2); // minus!:
        return (*qfn1(fn))(qenv(fn), v0180);
    }

v0106:
    stack[0] = elt(env, 1); // !:rd!:
    v0180 = v0181;
    v0180 = qcdr(v0180);
    fn = elt(env, 3); // safe!-fp!-minus
    v0180 = (*qfn1(fn))(qenv(fn), v0180);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    {
        LispObject v0182 = stack[0];
        popv(1);
        return cons(v0182, v0180);
    }
// error exit handlers
v0161:
    popv(1);
    return nil;
}



// Code for wedget2

static LispObject CC_wedget2(LispObject env,
                         LispObject v0059, LispObject v0058)
{
    LispObject nil = C_nil;
    LispObject v0195, v0196, v0197;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for wedget2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0058,v0059);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0059,v0058);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0058;
    stack[-1] = v0059;
// end of prologue
    v0195 = stack[-1];
    v0196 = qcar(v0195);
    v0195 = (LispObject)17; // 1
    if (v0196 == v0195) goto v0163;
    v0195 = stack[0];
    v0195 = qcar(v0195);
    v0196 = qcar(v0195);
    v0195 = (LispObject)17; // 1
    if (v0196 == v0195) goto v0198;
    v0195 = stack[-1];
    v0197 = qcar(v0195);
    v0195 = stack[0];
    v0196 = qcar(v0195);
    v0195 = qvalue(elt(env, 1)); // nil
    fn = elt(env, 2); // wedgek2
    stack[-2] = (*qfnn(fn))(qenv(fn), 3, v0197, v0196, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-3];
    v0195 = stack[-1];
    v0196 = qcdr(v0195);
    v0195 = stack[0];
    v0195 = qcdr(v0195);
    fn = elt(env, 3); // multsq
    v0195 = (*qfn2(fn))(qenv(fn), v0196, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-3];
    {
        LispObject v0064 = stack[-2];
        popv(4);
        fn = elt(env, 4); // multpfsq
        return (*qfn2(fn))(qenv(fn), v0064, v0195);
    }

v0198:
    v0195 = stack[-1];
    v0195 = qcar(v0195);
    stack[-2] = ncons(v0195);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-3];
    v0195 = stack[-1];
    v0196 = qcdr(v0195);
    v0195 = stack[0];
    v0195 = qcdr(v0195);
    fn = elt(env, 3); // multsq
    v0195 = (*qfn2(fn))(qenv(fn), v0196, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-3];
    v0195 = cons(stack[-2], v0195);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    popv(4);
    return ncons(v0195);

v0163:
    v0195 = stack[0];
    stack[-2] = qcar(v0195);
    v0195 = stack[-1];
    v0196 = qcdr(v0195);
    v0195 = stack[0];
    v0195 = qcdr(v0195);
    fn = elt(env, 3); // multsq
    v0195 = (*qfn2(fn))(qenv(fn), v0196, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-3];
    v0195 = cons(stack[-2], v0195);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    popv(4);
    return ncons(v0195);
// error exit handlers
v0199:
    popv(4);
    return nil;
}



// Code for wtchk

static LispObject CC_wtchk(LispObject env,
                         LispObject v0059, LispObject v0058)
{
    LispObject nil = C_nil;
    LispObject v0207, v0208, v0209;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for wtchk");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0058,v0059);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0059,v0058);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0058;
    stack[-2] = v0059;
// end of prologue
    v0207 = stack[-1];
    if (v0207 == nil) { LispObject res = stack[-2]; popv(5); return onevalue(res); }
    v0207 = stack[-2];
    stack[-3] = ncons(v0207);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-4];
    stack[0] = elt(env, 1); // k!*
    v0208 = stack[-1];
    v0207 = stack[-2];
    v0207 = qcar(v0207);
    v0207 = qcdr(v0207);
    v0207 = times2(v0208, v0207);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-4];
    fn = elt(env, 3); // to
    v0208 = (*qfn2(fn))(qenv(fn), stack[0], v0207);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-4];
    v0207 = (LispObject)17; // 1
    v0207 = cons(v0208, v0207);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-4];
    v0207 = ncons(v0207);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-4];
    fn = elt(env, 4); // quotf
    v0207 = (*qfn2(fn))(qenv(fn), stack[-3], v0207);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-4];
    v0208 = v0207;
    v0207 = v0208;
    if (v0207 == nil) goto v0190;
    v0207 = v0208;
    v0207 = qcar(v0207);
    { popv(5); return onevalue(v0207); }

v0190:
    v0209 = elt(env, 2); // "weight confusion"
    v0208 = stack[-2];
    v0207 = stack[-1];
    v0207 = list3(v0209, v0208, v0207);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-4];
    {
        popv(5);
        fn = elt(env, 5); // errach
        return (*qfn1(fn))(qenv(fn), v0207);
    }
// error exit handlers
v0183:
    popv(5);
    return nil;
}



// Code for form

static LispObject CC_form(LispObject env,
                         LispObject v0059)
{
    LispObject nil = C_nil;
    LispObject v0221, v0222, v0223;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for form");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0059);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0059);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// copy arguments values to proper place
    v0222 = v0059;
// end of prologue
    v0221 = v0222;
    if (!consp(v0221)) goto v0224;
    v0221 = v0222;
    v0223 = qcar(v0221);
    v0221 = elt(env, 1); // always_nform
    v0221 = Lflagp(nil, v0223, v0221);
    env = stack[0];
    goto v0030;

v0030:
    if (v0221 == nil) goto v0002;
    v0221 = v0222;
    {
        popv(1);
        fn = elt(env, 11); // n_form
        return (*qfn1(fn))(qenv(fn), v0221);
    }

v0002:
    v0221 = qvalue(elt(env, 3)); // !*rlisp88
    if (v0221 == nil) goto v0082;
    v0223 = qvalue(elt(env, 5)); // !*mode
    v0221 = elt(env, 6); // symbolic
    if (v0223 == v0221) goto v0225;
    v0221 = qvalue(elt(env, 7)); // t
    goto v0206;

v0206:
    if (v0221 == nil) goto v0226;
    v0222 = elt(env, 9); // "algebraic expression"
    v0221 = elt(env, 10); // "Rlisp88 form"
    {
        popv(1);
        fn = elt(env, 12); // typerr
        return (*qfn2(fn))(qenv(fn), v0222, v0221);
    }

v0226:
    v0223 = v0222;
    v0222 = qvalue(elt(env, 4)); // !*vars!*
    v0221 = qvalue(elt(env, 5)); // !*mode
    {
        popv(1);
        fn = elt(env, 13); // form1
        return (*qfnn(fn))(qenv(fn), 3, v0223, v0222, v0221);
    }

v0225:
    v0221 = v0222;
    if (!symbolp(v0221)) v0221 = nil;
    else { v0221 = qfastgets(v0221);
           if (v0221 != nil) { v0221 = elt(v0221, 48); // modefn
#ifdef RECORD_GET
             if (v0221 == SPID_NOPROP)
                record_get(elt(fastget_names, 48), 0),
                v0221 = nil;
             else record_get(elt(fastget_names, 48), 1),
                v0221 = lisp_true; }
           else record_get(elt(fastget_names, 48), 0); }
#else
             if (v0221 == SPID_NOPROP) v0221 = nil; else v0221 = lisp_true; }}
#endif
    if (v0221 == nil) goto v0072;
    v0223 = v0222;
    v0221 = elt(env, 6); // symbolic
    v0221 = (v0223 == v0221 ? lisp_true : nil);
    v0221 = (v0221 == nil ? lisp_true : nil);
    goto v0200;

v0200:
    if (v0221 == nil) goto v0188;
    v0221 = qvalue(elt(env, 7)); // t
    goto v0206;

v0188:
    v0223 = v0222;
    v0221 = elt(env, 8); // modefn
    v0221 = Lflagpcar(nil, v0223, v0221);
    env = stack[0];
    if (v0221 == nil) goto v0189;
    v0221 = v0222;
    v0223 = qcar(v0221);
    v0221 = elt(env, 6); // symbolic
    v0221 = (v0223 == v0221 ? lisp_true : nil);
    v0221 = (v0221 == nil ? lisp_true : nil);
    goto v0206;

v0189:
    v0221 = qvalue(elt(env, 2)); // nil
    goto v0206;

v0072:
    v0221 = qvalue(elt(env, 2)); // nil
    goto v0200;

v0082:
    v0223 = v0222;
    v0222 = qvalue(elt(env, 4)); // !*vars!*
    v0221 = qvalue(elt(env, 5)); // !*mode
    {
        popv(1);
        fn = elt(env, 13); // form1
        return (*qfnn(fn))(qenv(fn), 3, v0223, v0222, v0221);
    }

v0224:
    v0221 = qvalue(elt(env, 2)); // nil
    goto v0030;
}



// Code for mo!=revlexcomp

static LispObject CC_moMrevlexcomp(LispObject env,
                         LispObject v0059, LispObject v0058)
{
    LispObject nil = C_nil;
    LispObject v0206;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mo=revlexcomp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0058,v0059);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0059,v0058);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0058;
    stack[-1] = v0059;
// end of prologue
    v0206 = stack[-1];
    stack[-2] = Llength(nil, v0206);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-3];
    v0206 = stack[0];
    v0206 = Llength(nil, v0206);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-3];
    if (((int32_t)(stack[-2])) > ((int32_t)(v0206))) goto v0002;
    v0206 = stack[0];
    stack[-2] = Llength(nil, v0206);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-3];
    v0206 = stack[-1];
    v0206 = Llength(nil, v0206);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-3];
    if (((int32_t)(stack[-2])) > ((int32_t)(v0206))) goto v0163;
    v0206 = stack[-1];
    stack[-1] = Lreverse(nil, v0206);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-3];
    v0206 = stack[0];
    v0206 = Lreverse(nil, v0206);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-3];
    fn = elt(env, 1); // mo!=degcomp
    v0206 = (*qfn2(fn))(qenv(fn), stack[-1], v0206);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    popv(4);
    return negate(v0206);

v0163:
    v0206 = (LispObject)17; // 1
    { popv(4); return onevalue(v0206); }

v0002:
    v0206 = (LispObject)-15; // -1
    { popv(4); return onevalue(v0206); }
// error exit handlers
v0169:
    popv(4);
    return nil;
}



// Code for dd

static LispObject CC_dd(LispObject env,
                         LispObject v0059, LispObject v0058)
{
    LispObject nil = C_nil;
    LispObject v0011, v0153, v0232;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dd");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0058,v0059);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0059,v0058);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0058;
    stack[-2] = v0059;
// end of prologue
    v0153 = stack[0];
    v0011 = stack[-2];
    fn = elt(env, 6); // dquot
    v0011 = (*qfn2(fn))(qenv(fn), v0153, v0011);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-4];
    v0232 = v0011;
    v0011 = v0232;
    if (v0011 == nil) goto v0161;
    v0153 = qvalue(elt(env, 1)); // ordering
    v0011 = elt(env, 2); // lex
    if (v0153 == v0011) goto v0218;
    v0011 = v0232;
    v0011 = qcdr(v0011);
    v0232 = v0011;
    goto v0218;

v0218:
    v0011 = v0232;
    fn = elt(env, 7); // leftzeros
    v0011 = (*qfn1(fn))(qenv(fn), v0011);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-4];
    stack[-3] = v0011;
    v0011 = qvalue(elt(env, 3)); // nc!*
    if (v0011 == nil) goto v0200;
    v0011 = qvalue(elt(env, 5)); // nil
    goto v0234;

v0234:
    if (v0011 == nil) goto v0158;
    v0011 = (LispObject)49; // 3
    { popv(5); return onevalue(v0011); }

v0158:
    v0011 = qvalue(elt(env, 3)); // nc!*
    if (v0011 == nil) goto v0064;
    stack[0] = stack[-3];
    v0011 = qvalue(elt(env, 4)); // varlist!*
    v0011 = Llength(nil, v0011);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-4];
    v0153 = qvalue(elt(env, 3)); // nc!*
    v0011 = (LispObject)(int32_t)((int32_t)v0011 - (int32_t)v0153 + TAG_FIXNUM);
    if (((int32_t)(stack[0])) < ((int32_t)(v0011))) goto v0064;
    v0011 = (LispObject)65; // 4
    { popv(5); return onevalue(v0011); }

v0064:
    v0011 = (LispObject)33; // 2
    { popv(5); return onevalue(v0011); }

v0200:
    stack[-1] = stack[-3];
    v0011 = qvalue(elt(env, 4)); // varlist!*
    stack[0] = Llength(nil, v0011);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-4];
    v0011 = stack[-2];
    fn = elt(env, 8); // class
    v0011 = (*qfn1(fn))(qenv(fn), v0011);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-4];
    v0011 = (LispObject)(int32_t)((int32_t)stack[0] - (int32_t)v0011 + TAG_FIXNUM);
    v0011 = ((intptr_t)stack[-1] < (intptr_t)v0011) ? lisp_true : nil;
    v0011 = (v0011 == nil ? lisp_true : nil);
    goto v0234;

v0161:
    v0153 = stack[-2];
    v0011 = stack[0];
    fn = elt(env, 9); // dless
    v0011 = (*qfn2(fn))(qenv(fn), v0153, v0011);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    if (v0011 == nil) goto v0193;
    v0011 = (LispObject)17; // 1
    { popv(5); return onevalue(v0011); }

v0193:
    v0011 = (LispObject)1; // 0
    { popv(5); return onevalue(v0011); }
// error exit handlers
v0233:
    popv(5);
    return nil;
}



// Code for noncomperm

static LispObject CC_noncomperm(LispObject env,
                         LispObject v0059)
{
    LispObject nil = C_nil;
    LispObject v0063, v0239, v0210;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for noncomperm");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0059);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0059);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    stack[-4] = v0059;
// end of prologue
    v0063 = stack[-4];
    if (v0063 == nil) goto v0003;
    v0063 = stack[-4];
    stack[-5] = v0063;
    goto v0162;

v0162:
    v0063 = stack[-5];
    if (v0063 == nil) goto v0093;
    v0063 = stack[-5];
    v0063 = qcar(v0063);
    stack[0] = v0063;
    v0239 = stack[0];
    v0063 = stack[-4];
    fn = elt(env, 3); // noncomdel
    v0063 = (*qfn2(fn))(qenv(fn), v0239, v0063);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-6];
    v0210 = v0063;
    v0239 = v0210;
    v0063 = elt(env, 2); // failed
    if (v0239 == v0063) goto v0205;
    v0063 = v0210;
    v0239 = CC_noncomperm(env, v0063);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-6];
    v0063 = stack[0];
    fn = elt(env, 4); // mapcons
    v0063 = (*qfn2(fn))(qenv(fn), v0239, v0063);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-6];
    goto v0219;

v0219:
    stack[-3] = v0063;
    v0063 = stack[-3];
    fn = elt(env, 5); // lastpair
    v0063 = (*qfn1(fn))(qenv(fn), v0063);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-6];
    stack[-2] = v0063;
    v0063 = stack[-5];
    v0063 = qcdr(v0063);
    stack[-5] = v0063;
    v0063 = stack[-2];
    if (!consp(v0063)) goto v0162;
    else goto v0163;

v0163:
    v0063 = stack[-5];
    if (v0063 == nil) { LispObject res = stack[-3]; popv(7); return onevalue(res); }
    stack[-1] = stack[-2];
    v0063 = stack[-5];
    v0063 = qcar(v0063);
    stack[0] = v0063;
    v0239 = stack[0];
    v0063 = stack[-4];
    fn = elt(env, 3); // noncomdel
    v0063 = (*qfn2(fn))(qenv(fn), v0239, v0063);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-6];
    v0210 = v0063;
    v0239 = v0210;
    v0063 = elt(env, 2); // failed
    if (v0239 == v0063) goto v0195;
    v0063 = v0210;
    v0239 = CC_noncomperm(env, v0063);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-6];
    v0063 = stack[0];
    fn = elt(env, 4); // mapcons
    v0063 = (*qfn2(fn))(qenv(fn), v0239, v0063);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-6];
    goto v0156;

v0156:
    v0063 = Lrplacd(nil, stack[-1], v0063);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-6];
    v0063 = stack[-2];
    fn = elt(env, 5); // lastpair
    v0063 = (*qfn1(fn))(qenv(fn), v0063);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-6];
    stack[-2] = v0063;
    v0063 = stack[-5];
    v0063 = qcdr(v0063);
    stack[-5] = v0063;
    goto v0163;

v0195:
    v0063 = qvalue(elt(env, 1)); // nil
    goto v0156;

v0205:
    v0063 = qvalue(elt(env, 1)); // nil
    goto v0219;

v0093:
    v0063 = qvalue(elt(env, 1)); // nil
    { popv(7); return onevalue(v0063); }

v0003:
    v0063 = stack[-4];
    popv(7);
    return ncons(v0063);
// error exit handlers
v0240:
    popv(7);
    return nil;
}



// Code for horner!-rule

static LispObject CC_hornerKrule(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0251, v0252, v0253, v0254;
    LispObject fn;
    LispObject v0231, v0024, v0058, v0059;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "horner-rule");
    va_start(aa, nargs);
    v0059 = va_arg(aa, LispObject);
    v0058 = va_arg(aa, LispObject);
    v0024 = va_arg(aa, LispObject);
    v0231 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for horner-rule");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0231,v0024,v0058,v0059);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0059,v0058,v0024,v0231);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    stack[-1] = v0231;
    stack[-2] = v0024;
    stack[-3] = v0058;
    stack[-4] = v0059;
// end of prologue

v0255:
    v0251 = stack[-2];
    if (!consp(v0251)) goto v0108;
    v0251 = stack[-2];
    v0251 = qcar(v0251);
    v0251 = (consp(v0251) ? nil : lisp_true);
    goto v0107;

v0107:
    if (v0251 == nil) goto v0202;
    v0251 = stack[-1];
    v0251 = qcar(v0251);
    v0251 = qcdr(v0251);
    v0251 = (LispObject)zerop(v0251);
    v0251 = v0251 ? lisp_true : nil;
    env = stack[-6];
    if (v0251 == nil) goto v0193;
    v0251 = stack[-2];
    {
        popv(7);
        fn = elt(env, 2); // !*d2n
        return (*qfn1(fn))(qenv(fn), v0251);
    }

v0193:
    v0251 = stack[-2];
    fn = elt(env, 2); // !*d2n
    stack[0] = (*qfn1(fn))(qenv(fn), v0251);
    nil = C_nil;
    if (exception_pending()) goto v0256;
    env = stack[-6];
    stack[-2] = stack[-4];
    v0251 = stack[-1];
    v0251 = qcar(v0251);
    v0252 = qcdr(v0251);
    v0251 = stack[-3];
    v0251 = Lexpt(nil, v0252, v0251);
    nil = C_nil;
    if (exception_pending()) goto v0256;
    env = stack[-6];
    v0251 = times2(stack[-2], v0251);
    nil = C_nil;
    if (exception_pending()) goto v0256;
    {
        LispObject v0257 = stack[0];
        popv(7);
        return plus2(v0257, v0251);
    }

v0202:
    v0251 = stack[-2];
    v0251 = qcar(v0251);
    v0251 = qcar(v0251);
    v0252 = qcar(v0251);
    v0251 = stack[-1];
    v0251 = qcar(v0251);
    v0251 = qcar(v0251);
    if (equal(v0252, v0251)) goto v0239;
    v0251 = stack[-1];
    v0251 = qcar(v0251);
    v0251 = qcdr(v0251);
    v0251 = (LispObject)zerop(v0251);
    v0251 = v0251 ? lisp_true : nil;
    env = stack[-6];
    if (v0251 == nil) goto v0196;
    v0252 = stack[-2];
    v0251 = stack[-1];
    v0251 = qcdr(v0251);
    {
        popv(7);
        fn = elt(env, 3); // evaluate!-in!-order
        return (*qfn2(fn))(qenv(fn), v0252, v0251);
    }

v0196:
    v0252 = stack[-2];
    v0251 = stack[-1];
    v0251 = qcdr(v0251);
    fn = elt(env, 3); // evaluate!-in!-order
    stack[0] = (*qfn2(fn))(qenv(fn), v0252, v0251);
    nil = C_nil;
    if (exception_pending()) goto v0256;
    env = stack[-6];
    stack[-2] = stack[-4];
    v0251 = stack[-1];
    v0251 = qcar(v0251);
    v0252 = qcdr(v0251);
    v0251 = stack[-3];
    v0251 = Lexpt(nil, v0252, v0251);
    nil = C_nil;
    if (exception_pending()) goto v0256;
    env = stack[-6];
    v0251 = times2(stack[-2], v0251);
    nil = C_nil;
    if (exception_pending()) goto v0256;
    {
        LispObject v0043 = stack[0];
        popv(7);
        return plus2(v0043, v0251);
    }

v0239:
    v0251 = stack[-2];
    v0251 = qcar(v0251);
    v0251 = qcar(v0251);
    v0251 = qcdr(v0251);
    stack[-5] = v0251;
    v0251 = stack[-1];
    v0251 = qcar(v0251);
    v0251 = qcdr(v0251);
    v0251 = (LispObject)zerop(v0251);
    v0251 = v0251 ? lisp_true : nil;
    env = stack[-6];
    if (v0251 == nil) goto v0144;
    v0251 = stack[-2];
    v0251 = qcar(v0251);
    v0252 = qcdr(v0251);
    v0251 = stack[-1];
    v0251 = qcdr(v0251);
    fn = elt(env, 3); // evaluate!-in!-order
    v0251 = (*qfn2(fn))(qenv(fn), v0252, v0251);
    nil = C_nil;
    if (exception_pending()) goto v0256;
    env = stack[-6];
    v0254 = v0251;
    goto v0060;

v0060:
    v0253 = stack[-5];
    v0251 = stack[-2];
    v0252 = qcdr(v0251);
    v0251 = stack[-1];
    stack[-4] = v0254;
    stack[-3] = v0253;
    stack[-2] = v0252;
    stack[-1] = v0251;
    goto v0255;

v0144:
    v0251 = stack[-2];
    v0251 = qcar(v0251);
    v0252 = qcdr(v0251);
    v0251 = stack[-1];
    v0251 = qcdr(v0251);
    fn = elt(env, 3); // evaluate!-in!-order
    stack[0] = (*qfn2(fn))(qenv(fn), v0252, v0251);
    nil = C_nil;
    if (exception_pending()) goto v0256;
    env = stack[-6];
    v0251 = stack[-1];
    v0251 = qcar(v0251);
    v0253 = qcdr(v0251);
    v0252 = stack[-3];
    v0251 = stack[-5];
    v0251 = (LispObject)(int32_t)((int32_t)v0252 - (int32_t)v0251 + TAG_FIXNUM);
    v0251 = Lexpt(nil, v0253, v0251);
    nil = C_nil;
    if (exception_pending()) goto v0256;
    env = stack[-6];
    v0251 = times2(stack[-4], v0251);
    nil = C_nil;
    if (exception_pending()) goto v0256;
    env = stack[-6];
    v0251 = plus2(stack[0], v0251);
    nil = C_nil;
    if (exception_pending()) goto v0256;
    env = stack[-6];
    v0254 = v0251;
    goto v0060;

v0108:
    v0251 = qvalue(elt(env, 1)); // t
    goto v0107;
// error exit handlers
v0256:
    popv(7);
    return nil;
}



// Code for lex_unicode_alphabetic

static LispObject CC_lex_unicode_alphabetic(LispObject env,
                         LispObject v0059)
{
    LispObject nil = C_nil;
    LispObject v0081, v0190;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lex_unicode_alphabetic");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0059);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0059);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0059;
// end of prologue
    v0190 = stack[0];
    v0081 = (LispObject)1041; // 65
    v0081 = (LispObject)geq2(v0190, v0081);
    nil = C_nil;
    if (exception_pending()) goto v0158;
    v0081 = v0081 ? lisp_true : nil;
    env = stack[-1];
    if (v0081 == nil) goto v0030;
    v0190 = stack[0];
    v0081 = (LispObject)1441; // 90
    v0081 = (LispObject)lesseq2(v0190, v0081);
    nil = C_nil;
    if (exception_pending()) goto v0158;
    v0081 = v0081 ? lisp_true : nil;
    env = stack[-1];
    goto v0074;

v0074:
    if (!(v0081 == nil)) { popv(2); return onevalue(v0081); }
    v0190 = stack[0];
    v0081 = (LispObject)1553; // 97
    v0081 = (LispObject)geq2(v0190, v0081);
    nil = C_nil;
    if (exception_pending()) goto v0158;
    v0081 = v0081 ? lisp_true : nil;
    env = stack[-1];
    if (v0081 == nil) goto v0083;
    v0190 = stack[0];
    v0081 = (LispObject)1953; // 122
        popv(2);
        return Lleq(nil, v0190, v0081);

v0083:
    v0081 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0081); }

v0030:
    v0081 = qvalue(elt(env, 1)); // nil
    goto v0074;
// error exit handlers
v0158:
    popv(2);
    return nil;
}



// Code for exceeds!-order

static LispObject CC_exceedsKorder(LispObject env,
                         LispObject v0059, LispObject v0058)
{
    LispObject nil = C_nil;
    LispObject v0078, v0076;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for exceeds-order");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0058,v0059);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0059,v0058);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0058;
    stack[-1] = v0059;
// end of prologue

v0255:
    v0078 = stack[-1];
    if (v0078 == nil) goto v0002;
    v0078 = stack[0];
    v0078 = qcar(v0078);
    stack[-2] = v0078;
    v0078 = (LispObject)1; // 0
    v0076 = v0078;
    goto v0161;

v0161:
    v0078 = stack[-2];
    if (v0078 == nil) goto v0170;
    v0078 = stack[-2];
    v0078 = qcar(v0078);
    fn = elt(env, 3); // tayexp!-plus2
    v0078 = (*qfn2(fn))(qenv(fn), v0078, v0076);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-3];
    v0076 = v0078;
    v0078 = stack[-2];
    v0078 = qcdr(v0078);
    stack[-2] = v0078;
    goto v0161;

v0170:
    v0078 = v0076;
    v0076 = v0078;
    v0078 = stack[-1];
    v0078 = qcar(v0078);
    fn = elt(env, 4); // tayexp!-lessp
    v0078 = (*qfn2(fn))(qenv(fn), v0076, v0078);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-3];
    if (v0078 == nil) goto v0194;
    v0078 = stack[-1];
    v0076 = qcdr(v0078);
    v0078 = stack[0];
    v0078 = qcdr(v0078);
    stack[-1] = v0076;
    stack[0] = v0078;
    goto v0255;

v0194:
    v0078 = qvalue(elt(env, 2)); // t
    { popv(4); return onevalue(v0078); }

v0002:
    v0078 = qvalue(elt(env, 1)); // nil
    { popv(4); return onevalue(v0078); }
// error exit handlers
v0209:
    popv(4);
    return nil;
}



// Code for minusp!:

static LispObject CC_minuspT(LispObject env,
                         LispObject v0059)
{
    LispObject nil = C_nil;
    LispObject v0219, v0205, v0227;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for minusp:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0227 = v0059;
// end of prologue
    v0205 = v0227;
    v0219 = elt(env, 1); // !:rd!:
    if (!consp(v0205)) goto v0180;
    v0205 = qcar(v0205);
    if (!(v0205 == v0219)) goto v0180;
    v0219 = v0227;
    v0219 = qcdr(v0219);
    v0219 = (consp(v0219) ? nil : lisp_true);
    v0219 = (v0219 == nil ? lisp_true : nil);
    goto v0030;

v0030:
    if (v0219 == nil) goto v0238;
    v0219 = v0227;
    v0219 = qcdr(v0219);
    v0205 = qcar(v0219);
    v0219 = (LispObject)1; // 0
        return Llessp(nil, v0205, v0219);

v0238:
    v0219 = qvalue(elt(env, 2)); // nil
    return onevalue(v0219);

v0180:
    v0219 = qvalue(elt(env, 2)); // nil
    goto v0030;
}



// Code for isimplicit

static LispObject CC_isimplicit(LispObject env,
                         LispObject v0059)
{
    LispObject nil = C_nil;
    LispObject v0205, v0227, v0160;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for isimplicit");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0059);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0059);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0059;
// end of prologue
    v0205 = elt(env, 1); // implicit! 
    v0205 = Lexplode(nil, v0205);
    nil = C_nil;
    if (exception_pending()) goto v0192;
    env = stack[-2];
    stack[-1] = v0205;
    v0205 = stack[0];
    v0205 = Lexplode(nil, v0205);
    nil = C_nil;
    if (exception_pending()) goto v0192;
    v0227 = v0205;
    v0205 = lisp_true;
    v0160 = v0205;
    goto v0179;

v0179:
    v0205 = v0160;
    if (v0205 == nil) { popv(3); return onevalue(v0160); }
    v0205 = stack[-1];
    if (v0205 == nil) { popv(3); return onevalue(v0160); }
    v0205 = v0227;
    v0160 = qcar(v0205);
    v0205 = stack[-1];
    v0205 = qcar(v0205);
    v0205 = (equal(v0160, v0205) ? lisp_true : nil);
    v0160 = v0205;
    v0205 = stack[-1];
    v0205 = qcdr(v0205);
    stack[-1] = v0205;
    v0205 = v0227;
    v0205 = qcdr(v0205);
    v0227 = v0205;
    goto v0179;
// error exit handlers
v0192:
    popv(3);
    return nil;
}



// Code for dipprodin1

static LispObject CC_dipprodin1(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0202, v0200;
    LispObject fn;
    LispObject v0024, v0058, v0059;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "dipprodin1");
    va_start(aa, nargs);
    v0059 = va_arg(aa, LispObject);
    v0058 = va_arg(aa, LispObject);
    v0024 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dipprodin1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0024,v0058,v0059);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0059,v0058,v0024);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0024;
    stack[-1] = v0058;
    stack[-2] = v0059;
// end of prologue
    stack[-3] = nil;
    goto v0030;

v0030:
    v0202 = stack[0];
    if (v0202 == nil) goto v0179;
    v0200 = stack[-1];
    v0202 = stack[0];
    v0202 = qcar(v0202);
    fn = elt(env, 2); // evsum
    v0200 = (*qfn2(fn))(qenv(fn), v0200, v0202);
    nil = C_nil;
    if (exception_pending()) goto v0230;
    env = stack[-4];
    v0202 = stack[-3];
    v0202 = cons(v0200, v0202);
    nil = C_nil;
    if (exception_pending()) goto v0230;
    env = stack[-4];
    stack[-3] = v0202;
    v0200 = stack[-2];
    v0202 = stack[0];
    v0202 = qcdr(v0202);
    v0202 = qcar(v0202);
    fn = elt(env, 3); // bcprod
    v0200 = (*qfn2(fn))(qenv(fn), v0200, v0202);
    nil = C_nil;
    if (exception_pending()) goto v0230;
    env = stack[-4];
    v0202 = stack[-3];
    v0202 = cons(v0200, v0202);
    nil = C_nil;
    if (exception_pending()) goto v0230;
    env = stack[-4];
    stack[-3] = v0202;
    v0202 = stack[0];
    v0202 = qcdr(v0202);
    v0202 = qcdr(v0202);
    stack[0] = v0202;
    goto v0030;

v0179:
    v0200 = stack[-3];
    v0202 = qvalue(elt(env, 1)); // dipzero
    {
        popv(5);
        fn = elt(env, 4); // nreverse
        return (*qfn2(fn))(qenv(fn), v0200, v0202);
    }
// error exit handlers
v0230:
    popv(5);
    return nil;
}



// Code for set!-ordp

static LispObject CC_setKordp(LispObject env,
                         LispObject v0059, LispObject v0058)
{
    LispObject nil = C_nil;
    LispObject v0082, v0083, v0170;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for set-ordp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0083 = v0058;
    v0170 = v0059;
// end of prologue
    v0082 = v0170;
    if (!(is_number(v0082))) goto v0180;
    v0082 = v0083;
    if (!(is_number(v0082))) goto v0180;
    v0082 = v0170;
        return Llessp(nil, v0082, v0083);

v0180:
    v0082 = v0170;
    {
        fn = elt(env, 1); // ordp
        return (*qfn2(fn))(qenv(fn), v0082, v0083);
    }
}



// Code for scalopp

static LispObject CC_scalopp(LispObject env,
                         LispObject v0059)
{
    LispObject nil = C_nil;
    LispObject v0267, v0244, v0142;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for scalopp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0059);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0059);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-3] = v0059;
// end of prologue
    v0267 = stack[-3];
    if (symbolp(v0267)) goto v0194;
    v0267 = qvalue(elt(env, 1)); // nil
    goto v0074;

v0074:
    if (!(v0267 == nil)) { popv(6); return onevalue(v0267); }
    v0267 = stack[-3];
    if (!consp(v0267)) goto v0268;
    v0267 = stack[-3];
    v0267 = qcar(v0267);
    if (!symbolp(v0267)) v0244 = nil;
    else { v0244 = qfastgets(v0267);
           if (v0244 != nil) { v0244 = elt(v0244, 18); // phystype
#ifdef RECORD_GET
             if (v0244 != SPID_NOPROP)
                record_get(elt(fastget_names, 18), 1);
             else record_get(elt(fastget_names, 18), 0),
                v0244 = nil; }
           else record_get(elt(fastget_names, 18), 0); }
#else
             if (v0244 == SPID_NOPROP) v0244 = nil; }}
#endif
    v0267 = elt(env, 2); // scalar
    if (v0244 == v0267) goto v0082;
    v0267 = stack[-3];
    v0267 = qcar(v0267);
    if (!symbolp(v0267)) v0244 = nil;
    else { v0244 = qfastgets(v0267);
           if (v0244 != nil) { v0244 = elt(v0244, 18); // phystype
#ifdef RECORD_GET
             if (v0244 != SPID_NOPROP)
                record_get(elt(fastget_names, 18), 1);
             else record_get(elt(fastget_names, 18), 0),
                v0244 = nil; }
           else record_get(elt(fastget_names, 18), 0); }
#else
             if (v0244 == SPID_NOPROP) v0244 = nil; }}
#endif
    v0267 = elt(env, 4); // vector
    if (v0244 == v0267) goto v0269;
    v0267 = qvalue(elt(env, 1)); // nil
    goto v0198;

v0198:
    if (!(v0267 == nil)) { popv(6); return onevalue(v0267); }
    v0267 = stack[-3];
    v0267 = qcar(v0267);
    if (!symbolp(v0267)) v0244 = nil;
    else { v0244 = qfastgets(v0267);
           if (v0244 != nil) { v0244 = elt(v0244, 18); // phystype
#ifdef RECORD_GET
             if (v0244 != SPID_NOPROP)
                record_get(elt(fastget_names, 18), 1);
             else record_get(elt(fastget_names, 18), 0),
                v0244 = nil; }
           else record_get(elt(fastget_names, 18), 0); }
#else
             if (v0244 == SPID_NOPROP) v0244 = nil; }}
#endif
    v0267 = elt(env, 5); // tensor
    if (v0244 == v0267) goto v0187;
    v0267 = qvalue(elt(env, 1)); // nil
    { popv(6); return onevalue(v0267); }

v0187:
    v0267 = stack[-3];
    v0267 = qcdr(v0267);
    v0142 = Llength(nil, v0267);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-5];
    v0267 = stack[-3];
    v0244 = qcar(v0267);
    v0267 = elt(env, 6); // tensdimen
    v0267 = get(v0244, v0267);
    env = stack[-5];
    v0267 = (LispObject)geq2(v0142, v0267);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    v0267 = v0267 ? lisp_true : nil;
    env = stack[-5];
    if (v0267 == nil) goto v0171;
    v0267 = (LispObject)17; // 1
    stack[-4] = v0267;
    v0267 = stack[-3];
    v0244 = qcar(v0267);
    v0267 = elt(env, 6); // tensdimen
    v0244 = get(v0244, v0267);
    env = stack[-5];
    v0267 = stack[-4];
    v0267 = difference2(v0244, v0267);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-5];
    v0267 = Lminusp(nil, v0267);
    env = stack[-5];
    if (v0267 == nil) goto v0270;
    v0267 = qvalue(elt(env, 1)); // nil
    goto v0271;

v0271:
    {
        popv(6);
        fn = elt(env, 7); // areallindices
        return (*qfn1(fn))(qenv(fn), v0267);
    }

v0270:
    v0267 = stack[-3];
    v0244 = qcdr(v0267);
    v0267 = stack[-4];
    fn = elt(env, 8); // nth
    v0267 = (*qfn2(fn))(qenv(fn), v0244, v0267);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-5];
    v0267 = ncons(v0267);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-5];
    stack[-1] = v0267;
    stack[-2] = v0267;
    goto v0272;

v0272:
    v0267 = stack[-4];
    v0267 = add1(v0267);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-5];
    stack[-4] = v0267;
    v0267 = stack[-3];
    v0244 = qcar(v0267);
    v0267 = elt(env, 6); // tensdimen
    v0244 = get(v0244, v0267);
    env = stack[-5];
    v0267 = stack[-4];
    v0267 = difference2(v0244, v0267);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-5];
    v0267 = Lminusp(nil, v0267);
    env = stack[-5];
    if (v0267 == nil) goto v0144;
    v0267 = stack[-2];
    goto v0271;

v0144:
    stack[0] = stack[-1];
    v0267 = stack[-3];
    v0244 = qcdr(v0267);
    v0267 = stack[-4];
    fn = elt(env, 8); // nth
    v0267 = (*qfn2(fn))(qenv(fn), v0244, v0267);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-5];
    v0267 = ncons(v0267);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-5];
    v0267 = Lrplacd(nil, stack[0], v0267);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-5];
    v0267 = stack[-1];
    v0267 = qcdr(v0267);
    stack[-1] = v0267;
    goto v0272;

v0171:
    v0267 = qvalue(elt(env, 1)); // nil
    { popv(6); return onevalue(v0267); }

v0269:
    v0267 = stack[-3];
    v0267 = qcdr(v0267);
    v0267 = qcar(v0267);
    fn = elt(env, 9); // isanindex
    v0267 = (*qfn1(fn))(qenv(fn), v0267);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-5];
    goto v0198;

v0082:
    v0267 = qvalue(elt(env, 3)); // t
    { popv(6); return onevalue(v0267); }

v0268:
    v0267 = qvalue(elt(env, 1)); // nil
    { popv(6); return onevalue(v0267); }

v0194:
    v0267 = stack[-3];
    if (!symbolp(v0267)) v0244 = nil;
    else { v0244 = qfastgets(v0267);
           if (v0244 != nil) { v0244 = elt(v0244, 18); // phystype
#ifdef RECORD_GET
             if (v0244 != SPID_NOPROP)
                record_get(elt(fastget_names, 18), 1);
             else record_get(elt(fastget_names, 18), 0),
                v0244 = nil; }
           else record_get(elt(fastget_names, 18), 0); }
#else
             if (v0244 == SPID_NOPROP) v0244 = nil; }}
#endif
    v0267 = elt(env, 2); // scalar
    v0267 = (v0244 == v0267 ? lisp_true : nil);
    goto v0074;
// error exit handlers
v0045:
    popv(6);
    return nil;
}



// Code for lengthcdr

static LispObject CC_lengthcdr(LispObject env,
                         LispObject v0059)
{
    LispObject nil = C_nil;
    LispObject v0002;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lengthcdr");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0002 = v0059;
// end of prologue
    v0002 = qcdr(v0002);
        return Llength(nil, v0002);
}



// Code for red!-ratios2

static LispObject CC_redKratios2(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0271, v0272, v0212, v0213;
    LispObject fn;
    LispObject v0231, v0024, v0058, v0059;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "red-ratios2");
    va_start(aa, nargs);
    v0059 = va_arg(aa, LispObject);
    v0058 = va_arg(aa, LispObject);
    v0024 = va_arg(aa, LispObject);
    v0231 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for red-ratios2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0231,v0024,v0058,v0059);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0059,v0058,v0024,v0231);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    stack[-1] = v0231;
    stack[-2] = v0024;
    stack[-3] = v0058;
    stack[-4] = v0059;
// end of prologue

v0255:
    v0271 = stack[-4];
    if (v0271 == nil) goto v0108;
    v0272 = stack[-2];
    v0271 = stack[-3];
    v0271 = qcar(v0271);
    stack[0] = times2(v0272, v0271);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-6];
    stack[-5] = stack[0];
    v0272 = stack[-1];
    v0271 = stack[-4];
    v0271 = qcar(v0271);
    v0271 = times2(v0272, v0271);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-6];
    if (equal(stack[0], v0271)) goto v0269;
    v0271 = qvalue(elt(env, 1)); // nil
    goto v0220;

v0220:
    if (v0271 == nil) goto v0172;
    v0272 = stack[-1];
    v0271 = stack[-2];
    {
        popv(7);
        fn = elt(env, 2); // red!-lowest!-terms
        return (*qfn2(fn))(qenv(fn), v0272, v0271);
    }

v0172:
    v0271 = stack[-4];
    v0213 = qcdr(v0271);
    v0271 = stack[-3];
    v0212 = qcdr(v0271);
    v0272 = stack[-2];
    v0271 = stack[-1];
    stack[-4] = v0213;
    stack[-3] = v0212;
    stack[-2] = v0272;
    stack[-1] = v0271;
    goto v0255;

v0269:
    v0272 = stack[-5];
    v0271 = (LispObject)1; // 0
    if (v0272 == v0271) goto v0157;
    v0272 = stack[-1];
    v0271 = stack[-2];
    v0272 = Lgcd(nil, v0272, v0271);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-6];
    v0271 = stack[-1];
    v0272 = Cremainder(v0272, v0271);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-6];
    v0271 = (LispObject)1; // 0
    v0271 = (v0272 == v0271 ? lisp_true : nil);
    goto v0220;

v0157:
    v0271 = qvalue(elt(env, 1)); // nil
    goto v0220;

v0108:
    v0271 = qvalue(elt(env, 1)); // nil
    { popv(7); return onevalue(v0271); }
// error exit handlers
v0274:
    popv(7);
    return nil;
}



// Code for mo_neg

static LispObject CC_mo_neg(LispObject env,
                         LispObject v0059)
{
    LispObject nil = C_nil;
    LispObject v0172;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mo_neg");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0059);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0059);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-2] = v0059;
// end of prologue
    v0172 = stack[-2];
    v0172 = qcar(v0172);
    stack[-4] = v0172;
    v0172 = stack[-4];
    if (v0172 == nil) goto v0220;
    v0172 = stack[-4];
    v0172 = qcar(v0172);
    v0172 = negate(v0172);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    env = stack[-5];
    v0172 = ncons(v0172);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    env = stack[-5];
    stack[-1] = v0172;
    stack[-3] = v0172;
    goto v0194;

v0194:
    v0172 = stack[-4];
    v0172 = qcdr(v0172);
    stack[-4] = v0172;
    v0172 = stack[-4];
    if (v0172 == nil) goto v0204;
    stack[0] = stack[-1];
    v0172 = stack[-4];
    v0172 = qcar(v0172);
    v0172 = negate(v0172);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    env = stack[-5];
    v0172 = ncons(v0172);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    env = stack[-5];
    v0172 = Lrplacd(nil, stack[0], v0172);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    env = stack[-5];
    v0172 = stack[-1];
    v0172 = qcdr(v0172);
    stack[-1] = v0172;
    goto v0194;

v0204:
    v0172 = stack[-3];
    stack[-4] = v0172;
    goto v0002;

v0002:
    v0172 = stack[-2];
    v0172 = qcdr(v0172);
    stack[-3] = v0172;
    v0172 = stack[-3];
    if (v0172 == nil) goto v0201;
    v0172 = stack[-3];
    v0172 = qcar(v0172);
    v0172 = negate(v0172);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    env = stack[-5];
    v0172 = ncons(v0172);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    env = stack[-5];
    stack[-1] = v0172;
    stack[-2] = v0172;
    goto v0234;

v0234:
    v0172 = stack[-3];
    v0172 = qcdr(v0172);
    stack[-3] = v0172;
    v0172 = stack[-3];
    if (v0172 == nil) goto v0073;
    stack[0] = stack[-1];
    v0172 = stack[-3];
    v0172 = qcar(v0172);
    v0172 = negate(v0172);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    env = stack[-5];
    v0172 = ncons(v0172);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    env = stack[-5];
    v0172 = Lrplacd(nil, stack[0], v0172);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    env = stack[-5];
    v0172 = stack[-1];
    v0172 = qcdr(v0172);
    stack[-1] = v0172;
    goto v0234;

v0073:
    v0172 = stack[-2];
    goto v0074;

v0074:
    {
        LispObject v0215 = stack[-4];
        popv(6);
        return cons(v0215, v0172);
    }

v0201:
    v0172 = qvalue(elt(env, 1)); // nil
    goto v0074;

v0220:
    v0172 = qvalue(elt(env, 1)); // nil
    stack[-4] = v0172;
    goto v0002;
// error exit handlers
v0229:
    popv(6);
    return nil;
}



// Code for b!:ordexn

static LispObject CC_bTordexn(LispObject env,
                         LispObject v0059, LispObject v0058)
{
    LispObject nil = C_nil;
    LispObject v0197, v0264;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for b:ordexn");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0058,v0059);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0059,v0058);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0058;
    stack[-2] = v0059;
// end of prologue
    stack[0] = nil;
    stack[-3] = nil;
    goto v0106;

v0106:
    v0197 = stack[-1];
    if (v0197 == nil) goto v0025;
    v0264 = stack[-2];
    v0197 = stack[-1];
    v0197 = qcar(v0197);
    v0197 = (LispObject)lessp2(v0264, v0197);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    v0197 = v0197 ? lisp_true : nil;
    env = stack[-4];
    if (v0197 == nil) goto v0025;
    v0197 = stack[-1];
    v0264 = qcar(v0197);
    v0197 = stack[-3];
    v0197 = cons(v0264, v0197);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-4];
    stack[-3] = v0197;
    v0197 = stack[-1];
    v0197 = qcdr(v0197);
    stack[-1] = v0197;
    v0197 = stack[0];
    v0197 = (v0197 == nil ? lisp_true : nil);
    stack[0] = v0197;
    goto v0106;

v0025:
    v0197 = stack[-1];
    if (v0197 == nil) goto v0158;
    v0264 = stack[-2];
    v0197 = stack[-1];
    v0197 = qcar(v0197);
    v0197 = Leqn(nil, v0264, v0197);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-4];
    if (v0197 == nil) goto v0070;
    v0197 = qvalue(elt(env, 1)); // nil
    { popv(5); return onevalue(v0197); }

v0070:
    v0264 = stack[-2];
    v0197 = stack[-3];
    v0197 = cons(v0264, v0197);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-4];
    v0264 = Lnreverse(nil, v0197);
    env = stack[-4];
    v0197 = stack[-1];
    v0197 = Lnconc(nil, v0264, v0197);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    {
        LispObject v0065 = stack[0];
        popv(5);
        return cons(v0065, v0197);
    }

v0158:
    v0264 = stack[-2];
    v0197 = stack[-3];
    v0197 = cons(v0264, v0197);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-4];
    v0197 = Lnreverse(nil, v0197);
    {
        LispObject v0011 = stack[0];
        popv(5);
        return cons(v0011, v0197);
    }
// error exit handlers
v0066:
    popv(5);
    return nil;
}



// Code for rl_simpl

static LispObject CC_rl_simpl(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0180, v0181, v0092;
    LispObject fn;
    LispObject v0024, v0058, v0059;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "rl_simpl");
    va_start(aa, nargs);
    v0059 = va_arg(aa, LispObject);
    v0058 = va_arg(aa, LispObject);
    v0024 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rl_simpl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0024,v0058,v0059);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0059,v0058,v0024);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0180 = v0024;
    v0181 = v0058;
    v0092 = v0059;
// end of prologue
    stack[0] = qvalue(elt(env, 1)); // rl_simpl!*
    v0180 = list3(v0092, v0181, v0180);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-1];
    {
        LispObject v0236 = stack[0];
        popv(2);
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(qenv(fn), v0236, v0180);
    }
// error exit handlers
v0182:
    popv(2);
    return nil;
}



// Code for qqe_ofsf_simplat1

static LispObject CC_qqe_ofsf_simplat1(LispObject env,
                         LispObject v0059, LispObject v0058)
{
    LispObject nil = C_nil;
    LispObject v0227, v0160;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qqe_ofsf_simplat1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0058,v0059);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0059,v0058);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0058;
    stack[-1] = v0059;
// end of prologue
    v0160 = stack[-1];
    v0227 = stack[0];
    fn = elt(env, 2); // qqe_simplat1
    v0227 = (*qfn2(fn))(qenv(fn), v0160, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    env = stack[-3];
    stack[-2] = v0227;
    v0160 = stack[-2];
    v0227 = elt(env, 1); // (true false)
    v0227 = Lmemq(nil, v0160, v0227);
    if (!(v0227 == nil)) { LispObject res = stack[-2]; popv(4); return onevalue(res); }
    v0227 = stack[-1];
    fn = elt(env, 3); // qqe_op
    v0227 = (*qfn1(fn))(qenv(fn), v0227);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    env = stack[-3];
    fn = elt(env, 4); // qqe_rqopp
    v0227 = (*qfn1(fn))(qenv(fn), v0227);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    env = stack[-3];
    if (!(v0227 == nil)) { LispObject res = stack[-2]; popv(4); return onevalue(res); }
    v0160 = stack[-2];
    v0227 = stack[0];
    {
        popv(4);
        fn = elt(env, 5); // ofsf_simplat1
        return (*qfn2(fn))(qenv(fn), v0160, v0227);
    }
// error exit handlers
v0104:
    popv(4);
    return nil;
}



// Code for rl_negateat

static LispObject CC_rl_negateat(LispObject env,
                         LispObject v0059)
{
    LispObject nil = C_nil;
    LispObject v0108;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rl_negateat");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0059);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0059);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0108 = v0059;
// end of prologue
    stack[0] = qvalue(elt(env, 1)); // rl_negateat!*
    v0108 = ncons(v0108);
    nil = C_nil;
    if (exception_pending()) goto v0194;
    env = stack[-1];
    {
        LispObject v0179 = stack[0];
        popv(2);
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(qenv(fn), v0179, v0108);
    }
// error exit handlers
v0194:
    popv(2);
    return nil;
}



// Code for rl_simpbop

static LispObject CC_rl_simpbop(LispObject env,
                         LispObject v0059)
{
    LispObject nil = C_nil;
    LispObject v0225, v0158;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rl_simpbop");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0059);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0059);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    v0158 = v0059;
// end of prologue
    v0225 = v0158;
    stack[-4] = qcar(v0225);
    v0225 = v0158;
    v0225 = qcdr(v0225);
    stack[-3] = v0225;
    v0225 = stack[-3];
    if (v0225 == nil) goto v0224;
    v0225 = stack[-3];
    v0225 = qcar(v0225);
    fn = elt(env, 2); // rl_simp1
    v0225 = (*qfn1(fn))(qenv(fn), v0225);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-5];
    v0225 = ncons(v0225);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-5];
    stack[-1] = v0225;
    stack[-2] = v0225;
    goto v0075;

v0075:
    v0225 = stack[-3];
    v0225 = qcdr(v0225);
    stack[-3] = v0225;
    v0225 = stack[-3];
    if (v0225 == nil) goto v0237;
    stack[0] = stack[-1];
    v0225 = stack[-3];
    v0225 = qcar(v0225);
    fn = elt(env, 2); // rl_simp1
    v0225 = (*qfn1(fn))(qenv(fn), v0225);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-5];
    v0225 = ncons(v0225);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-5];
    v0225 = Lrplacd(nil, stack[0], v0225);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-5];
    v0225 = stack[-1];
    v0225 = qcdr(v0225);
    stack[-1] = v0225;
    goto v0075;

v0237:
    v0225 = stack[-2];
    goto v0074;

v0074:
    {
        LispObject v0201 = stack[-4];
        popv(6);
        return cons(v0201, v0225);
    }

v0224:
    v0225 = qvalue(elt(env, 1)); // nil
    goto v0074;
// error exit handlers
v0200:
    popv(6);
    return nil;
}



// Code for numeric!-content

static LispObject CC_numericKcontent(LispObject env,
                         LispObject v0059)
{
    LispObject nil = C_nil;
    LispObject v0200, v0201, v0077;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for numeric-content");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0059);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0059);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0059;
// end of prologue

v0003:
    v0200 = stack[0];
    if (!consp(v0200)) goto v0108;
    v0200 = stack[0];
    v0200 = qcar(v0200);
    v0200 = (consp(v0200) ? nil : lisp_true);
    goto v0107;

v0107:
    if (v0200 == nil) goto v0025;
    v0200 = stack[0];
    {
        popv(3);
        fn = elt(env, 2); // absf
        return (*qfn1(fn))(qenv(fn), v0200);
    }

v0025:
    v0200 = stack[0];
    v0200 = qcdr(v0200);
    if (v0200 == nil) goto v0180;
    v0200 = stack[0];
    v0200 = qcar(v0200);
    v0200 = qcdr(v0200);
    v0200 = CC_numericKcontent(env, v0200);
    nil = C_nil;
    if (exception_pending()) goto v0230;
    env = stack[-2];
    v0077 = v0200;
    v0201 = v0077;
    v0200 = (LispObject)17; // 1
    if (v0201 == v0200) { popv(3); return onevalue(v0077); }
    stack[-1] = v0077;
    v0200 = stack[0];
    v0200 = qcdr(v0200);
    v0200 = CC_numericKcontent(env, v0200);
    nil = C_nil;
    if (exception_pending()) goto v0230;
    env = stack[-2];
    fn = elt(env, 3); // gcddd
    v0200 = (*qfn2(fn))(qenv(fn), stack[-1], v0200);
    nil = C_nil;
    if (exception_pending()) goto v0230;
    v0077 = v0200;
    { popv(3); return onevalue(v0077); }

v0180:
    v0200 = stack[0];
    v0200 = qcar(v0200);
    v0200 = qcdr(v0200);
    stack[0] = v0200;
    goto v0003;

v0108:
    v0200 = qvalue(elt(env, 1)); // t
    goto v0107;
// error exit handlers
v0230:
    popv(3);
    return nil;
}



// Code for bc2a

static LispObject CC_bc2a(LispObject env,
                         LispObject v0059)
{
    LispObject nil = C_nil;
    LispObject v0228, v0194;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for bc2a");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0194 = v0059;
// end of prologue
    v0228 = qvalue(elt(env, 1)); // !*grmod!*
    if (!(v0228 == nil)) return onevalue(v0194);
    v0228 = v0194;
    {
        fn = elt(env, 2); // prepsq
        return (*qfn1(fn))(qenv(fn), v0228);
    }
}



// Code for !*kp2f

static LispObject CC_Hkp2f(LispObject env,
                         LispObject v0059, LispObject v0058)
{
    LispObject nil = C_nil;
    LispObject v0236, v0259;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *kp2f");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0058,v0059);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0059,v0058);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0058;
    stack[-1] = v0059;
// end of prologue
    v0259 = stack[0];
    v0236 = (LispObject)1; // 0
    v0236 = (LispObject)greaterp2(v0259, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    v0236 = v0236 ? lisp_true : nil;
    env = stack[-2];
    if (v0236 == nil) goto v0092;
    v0259 = stack[-1];
    v0236 = stack[0];
    fn = elt(env, 1); // mksq
    v0236 = (*qfn2(fn))(qenv(fn), v0259, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    v0236 = qcar(v0236);
    { popv(3); return onevalue(v0236); }

v0092:
    v0236 = (LispObject)17; // 1
    { popv(3); return onevalue(v0236); }
// error exit handlers
v0170:
    popv(3);
    return nil;
}



// Code for map__edges

static LispObject CC_map__edges(LispObject env,
                         LispObject v0059)
{
    LispObject nil = C_nil;
    LispObject v0191, v0192;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for map__edges");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0059);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0059);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0059;
// end of prologue
    stack[-1] = nil;
    goto v0074;

v0074:
    v0191 = stack[0];
    if (v0191 == nil) goto v0030;
    v0191 = stack[0];
    v0192 = qcar(v0191);
    v0191 = stack[-1];
    v0191 = cons(v0192, v0191);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-2];
    stack[-1] = v0191;
    v0191 = stack[0];
    v0191 = qcdr(v0191);
    stack[0] = v0191;
    goto v0074;

v0030:
    v0191 = qvalue(elt(env, 1)); // nil
    v0192 = v0191;
    goto v0025;

v0025:
    v0191 = stack[-1];
    if (v0191 == nil) { popv(3); return onevalue(v0192); }
    v0191 = stack[-1];
    v0191 = qcar(v0191);
    fn = elt(env, 2); // union_edges
    v0191 = (*qfn2(fn))(qenv(fn), v0191, v0192);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-2];
    v0192 = v0191;
    v0191 = stack[-1];
    v0191 = qcdr(v0191);
    stack[-1] = v0191;
    goto v0025;
// error exit handlers
v0198:
    popv(3);
    return nil;
}



// Code for assert_typesyntaxp

static LispObject CC_assert_typesyntaxp(LispObject env,
                         LispObject v0059)
{
    LispObject nil = C_nil;
    LispObject v0194, v0179;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for assert_typesyntaxp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0179 = v0059;
// end of prologue
    v0194 = qvalue(elt(env, 1)); // !*assert
    if (v0194 == nil) goto v0106;
    v0194 = v0179;
    {
        fn = elt(env, 2); // assert_dyntypep
        return (*qfn1(fn))(qenv(fn), v0194);
    }

v0106:
    v0194 = v0179;
        return Lsymbolp(nil, v0194);
}



// Code for cali_bc_zero!?

static LispObject CC_cali_bc_zeroW(LispObject env,
                         LispObject v0059)
{
    LispObject nil = C_nil;
    LispObject v0205, v0227, v0160;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cali_bc_zero?");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0059);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0059);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// copy arguments values to proper place
    v0227 = v0059;
// end of prologue
    v0205 = v0227;
    if (v0205 == nil) goto v0025;
    v0160 = v0227;
    v0205 = (LispObject)1; // 0
    v0205 = (v0160 == v0205 ? lisp_true : nil);
    goto v0030;

v0030:
    if (v0205 == nil) goto v0002;
    v0205 = qvalue(elt(env, 1)); // t
    { popv(1); return onevalue(v0205); }

v0002:
    v0205 = qvalue(elt(env, 2)); // !*hardzerotest
    if (v0205 == nil) goto v0079;
    v0205 = v0227;
    v0205 = Lconsp(nil, v0205);
    env = stack[0];
    if (v0205 == nil) goto v0079;
    v0205 = v0227;
    fn = elt(env, 4); // prepf
    v0205 = (*qfn1(fn))(qenv(fn), v0205);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[0];
    fn = elt(env, 5); // simp
    v0205 = (*qfn1(fn))(qenv(fn), v0205);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[0];
    v0205 = qcar(v0205);
    fn = elt(env, 6); // bc!=simp
    v0205 = (*qfn1(fn))(qenv(fn), v0205);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    v0205 = (v0205 == nil ? lisp_true : nil);
    { popv(1); return onevalue(v0205); }

v0079:
    v0205 = qvalue(elt(env, 3)); // nil
    { popv(1); return onevalue(v0205); }

v0025:
    v0205 = qvalue(elt(env, 1)); // t
    goto v0030;
// error exit handlers
v0206:
    popv(1);
    return nil;
}



// Code for gperm3

static LispObject CC_gperm3(LispObject env,
                         LispObject v0059, LispObject v0058)
{
    LispObject nil = C_nil;
    LispObject v0083, v0170, v0204;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gperm3");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0058,v0059);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0059,v0058);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0170 = v0058;
    v0083 = v0059;
// end of prologue

v0074:
    v0204 = v0083;
    if (v0204 == nil) { popv(2); return onevalue(v0170); }
    v0204 = v0083;
    v0204 = qcdr(v0204);
    stack[0] = v0204;
    v0204 = v0170;
    v0170 = qcar(v0083);
    v0083 = qvalue(elt(env, 1)); // nil
    fn = elt(env, 2); // gperm2
    v0083 = (*qfnn(fn))(qenv(fn), 3, v0204, v0170, v0083);
    nil = C_nil;
    if (exception_pending()) goto v0237;
    env = stack[-1];
    v0170 = v0083;
    v0083 = stack[0];
    goto v0074;
// error exit handlers
v0237:
    popv(2);
    return nil;
}



// Code for general!-modular!-reciprocal

static LispObject CC_generalKmodularKreciprocal(LispObject env,
                         LispObject v0059)
{
    LispObject nil = C_nil;
    LispObject v0158, v0105, v0234, v0159;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for general-modular-reciprocal");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0059);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0059);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0059;
// end of prologue
    v0158 = qvalue(elt(env, 1)); // !*balanced_mod
    if (v0158 == nil) goto v0160;
    v0105 = stack[0];
    v0158 = (LispObject)1; // 0
    v0158 = (LispObject)lessp2(v0105, v0158);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    v0158 = v0158 ? lisp_true : nil;
    env = stack[-2];
    if (v0158 == nil) goto v0160;
    stack[-1] = qvalue(elt(env, 2)); // current!-modulus
    v0105 = stack[0];
    v0158 = qvalue(elt(env, 2)); // current!-modulus
    v0234 = plus2(v0105, v0158);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-2];
    v0105 = (LispObject)1; // 0
    v0158 = (LispObject)17; // 1
    {
        LispObject v0201 = stack[-1];
        popv(3);
        fn = elt(env, 3); // general!-reciprocal!-by!-gcd
        return (*qfnn(fn))(qenv(fn), 4, v0201, v0234, v0105, v0158);
    }

v0160:
    v0159 = qvalue(elt(env, 2)); // current!-modulus
    v0234 = stack[0];
    v0105 = (LispObject)1; // 0
    v0158 = (LispObject)17; // 1
    {
        popv(3);
        fn = elt(env, 3); // general!-reciprocal!-by!-gcd
        return (*qfnn(fn))(qenv(fn), 4, v0159, v0234, v0105, v0158);
    }
// error exit handlers
v0200:
    popv(3);
    return nil;
}



// Code for difference!-mod!-p

static LispObject CC_differenceKmodKp(LispObject env,
                         LispObject v0059, LispObject v0058)
{
    LispObject nil = C_nil;
    LispObject v0228, v0194;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for difference-mod-p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0058,v0059);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0059,v0058);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0228 = v0058;
    v0194 = v0059;
// end of prologue
    stack[0] = v0194;
    fn = elt(env, 1); // minus!-mod!-p
    v0228 = (*qfn1(fn))(qenv(fn), v0228);
    nil = C_nil;
    if (exception_pending()) goto v0075;
    env = stack[-1];
    {
        LispObject v0162 = stack[0];
        popv(2);
        fn = elt(env, 2); // plus!-mod!-p
        return (*qfn2(fn))(qenv(fn), v0162, v0228);
    }
// error exit handlers
v0075:
    popv(2);
    return nil;
}



// Code for outdefr

static LispObject CC_outdefr(LispObject env,
                         LispObject v0059, LispObject v0058)
{
    LispObject nil = C_nil;
    LispObject v0181, v0092, v0161, v0182;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for outdefr");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0181 = v0058;
    v0092 = v0059;
// end of prologue
    v0161 = v0092;
    v0182 = qcar(v0161);
    v0161 = v0092;
    v0161 = qcdr(v0161);
    v0161 = qcar(v0161);
    v0092 = qcdr(v0092);
    v0092 = qcdr(v0092);
    v0092 = qcar(v0092);
    {
        fn = elt(env, 1); // outref
        return (*qfnn(fn))(qenv(fn), 4, v0182, v0161, v0092, v0181);
    }
}



// Code for ofsf_entry2at1

static LispObject CC_ofsf_entry2at1(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0205, v0227, v0160;
    LispObject fn;
    LispObject v0024, v0058, v0059;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "ofsf_entry2at1");
    va_start(aa, nargs);
    v0059 = va_arg(aa, LispObject);
    v0058 = va_arg(aa, LispObject);
    v0024 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_entry2at1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0024,v0058,v0059);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0059,v0058,v0024);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0024;
    stack[-1] = v0058;
    v0205 = v0059;
// end of prologue
    v0227 = stack[-1];
    v0160 = qcar(v0227);
    v0227 = v0205;
    v0205 = elt(env, 1); // and
    v0205 = (v0227 == v0205 ? lisp_true : nil);
    fn = elt(env, 3); // ofsf_clnegrel
    stack[-2] = (*qfn2(fn))(qenv(fn), v0160, v0205);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    env = stack[-3];
    v0227 = stack[0];
    v0205 = stack[-1];
    v0205 = qcdr(v0205);
    fn = elt(env, 4); // addsq
    v0205 = (*qfn2(fn))(qenv(fn), v0227, v0205);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    env = stack[-3];
    v0205 = qcar(v0205);
    v0227 = qvalue(elt(env, 2)); // nil
    {
        LispObject v0169 = stack[-2];
        popv(4);
        return list3(v0169, v0205, v0227);
    }
// error exit handlers
v0104:
    popv(4);
    return nil;
}



// Code for rl_smmkatl

static LispObject CC_rl_smmkatl(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0182, v0236, v0259, v0082;
    LispObject fn;
    LispObject v0231, v0024, v0058, v0059;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "rl_smmkatl");
    va_start(aa, nargs);
    v0059 = va_arg(aa, LispObject);
    v0058 = va_arg(aa, LispObject);
    v0024 = va_arg(aa, LispObject);
    v0231 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rl_smmkatl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0231,v0024,v0058,v0059);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0059,v0058,v0024,v0231);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0182 = v0231;
    v0236 = v0024;
    v0259 = v0058;
    v0082 = v0059;
// end of prologue
    stack[0] = qvalue(elt(env, 1)); // rl_smmkatl!*
    v0182 = list4(v0082, v0259, v0236, v0182);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-1];
    {
        LispObject v0204 = stack[0];
        popv(2);
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(qenv(fn), v0204, v0182);
    }
// error exit handlers
v0170:
    popv(2);
    return nil;
}



// Code for removeg2

static LispObject CC_removeg2(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0278, v0140, v0279, v0256;
    LispObject fn;
    LispObject v0024, v0058, v0059;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "removeg2");
    va_start(aa, nargs);
    v0059 = va_arg(aa, LispObject);
    v0058 = va_arg(aa, LispObject);
    v0024 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for removeg2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0024,v0058,v0059);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0059,v0058,v0024);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
// copy arguments values to proper place
    stack[-3] = v0024;
    stack[-4] = v0058;
    stack[-5] = v0059;
// end of prologue
    v0278 = stack[-4];
    v0278 = qcdr(v0278);
    v0278 = qcdr(v0278);
    v0278 = qcdr(v0278);
    v0278 = qcar(v0278);
    v0140 = v0278;
    v0278 = stack[-3];
    v0279 = qcar(v0278);
    v0278 = elt(env, 1); // g3
    if (v0279 == v0278) goto v0238;
    v0278 = qvalue(elt(env, 2)); // t
    goto v0093;

v0093:
    if (v0278 == nil) goto v0078;
    v0256 = elt(env, 3); // "Edge"
    v0279 = v0140;
    v0140 = elt(env, 4); // "is absent in vertex"
    v0278 = stack[-3];
    v0278 = list4(v0256, v0279, v0140, v0278);
    nil = C_nil;
    if (exception_pending()) goto v0280;
    env = stack[-7];
    fn = elt(env, 6); // cerror
    v0278 = (*qfn1(fn))(qenv(fn), v0278);
    nil = C_nil;
    if (exception_pending()) goto v0280;
    env = stack[-7];
    goto v0163;

v0163:
    stack[-3] = v0278;
    v0140 = stack[-3];
    v0278 = elt(env, 5); // qg
    v0278 = Lrplaca(nil, v0140, v0278);
    nil = C_nil;
    if (exception_pending()) goto v0280;
    env = stack[-7];
    v0278 = stack[-5];
    stack[0] = qcar(v0278);
    v0278 = stack[-5];
    v0278 = qcdr(v0278);
    fn = elt(env, 7); // mkcopy
    v0278 = (*qfn1(fn))(qenv(fn), v0278);
    nil = C_nil;
    if (exception_pending()) goto v0280;
    env = stack[-7];
    v0278 = cons(stack[0], v0278);
    nil = C_nil;
    if (exception_pending()) goto v0280;
    env = stack[-7];
    stack[-6] = v0278;
    v0140 = stack[-4];
    v0278 = stack[-6];
    v0278 = Lmember(nil, v0140, v0278);
    v0278 = qcar(v0278);
    stack[-1] = v0278;
    v0140 = stack[-3];
    v0278 = stack[-6];
    v0278 = Lmember(nil, v0140, v0278);
    v0278 = qcar(v0278);
    stack[0] = v0278;
    v0278 = stack[-4];
    v0278 = qcdr(v0278);
    v0278 = qcdr(v0278);
    v0278 = qcar(v0278);
    stack[-2] = v0278;
    v0278 = stack[-4];
    v0278 = qcdr(v0278);
    v0140 = qcdr(v0278);
    v0278 = stack[-4];
    v0278 = qcdr(v0278);
    v0278 = qcdr(v0278);
    v0278 = qcdr(v0278);
    v0278 = qcar(v0278);
    v0278 = Lrplaca(nil, v0140, v0278);
    nil = C_nil;
    if (exception_pending()) goto v0280;
    env = stack[-7];
    v0278 = stack[-4];
    v0278 = qcdr(v0278);
    v0278 = qcdr(v0278);
    v0140 = qcdr(v0278);
    v0278 = stack[-3];
    v0278 = qcdr(v0278);
    v0278 = qcdr(v0278);
    v0278 = qcar(v0278);
    v0278 = Lrplaca(nil, v0140, v0278);
    nil = C_nil;
    if (exception_pending()) goto v0280;
    env = stack[-7];
    v0278 = stack[-3];
    v0278 = qcdr(v0278);
    v0140 = qcdr(v0278);
    v0278 = stack[-2];
    v0278 = Lrplaca(nil, v0140, v0278);
    nil = C_nil;
    if (exception_pending()) goto v0280;
    env = stack[-7];
    v0278 = stack[-1];
    v0278 = qcdr(v0278);
    v0278 = qcar(v0278);
    stack[-2] = v0278;
    v0278 = stack[-1];
    v0140 = qcdr(v0278);
    v0278 = stack[-1];
    v0278 = qcdr(v0278);
    v0278 = qcdr(v0278);
    v0278 = qcdr(v0278);
    v0278 = qcar(v0278);
    v0278 = Lrplaca(nil, v0140, v0278);
    nil = C_nil;
    if (exception_pending()) goto v0280;
    env = stack[-7];
    v0278 = stack[-1];
    v0278 = qcdr(v0278);
    v0278 = qcdr(v0278);
    v0140 = qcdr(v0278);
    v0278 = stack[0];
    v0278 = qcdr(v0278);
    v0278 = qcdr(v0278);
    v0278 = qcar(v0278);
    v0278 = Lrplaca(nil, v0140, v0278);
    nil = C_nil;
    if (exception_pending()) goto v0280;
    env = stack[-7];
    v0278 = stack[0];
    v0278 = qcdr(v0278);
    v0140 = qcdr(v0278);
    v0278 = stack[0];
    v0278 = qcdr(v0278);
    v0278 = qcar(v0278);
    v0278 = Lrplaca(nil, v0140, v0278);
    nil = C_nil;
    if (exception_pending()) goto v0280;
    env = stack[-7];
    v0278 = stack[0];
    v0140 = qcdr(v0278);
    v0278 = stack[-2];
    v0278 = Lrplaca(nil, v0140, v0278);
    nil = C_nil;
    if (exception_pending()) goto v0280;
    env = stack[-7];
    stack[0] = stack[-5];
    v0278 = stack[-6];
    v0278 = qcar(v0278);
    fn = elt(env, 8); // negsq
    v0140 = (*qfn1(fn))(qenv(fn), v0278);
    nil = C_nil;
    if (exception_pending()) goto v0280;
    v0278 = stack[-6];
    v0278 = qcdr(v0278);
    {
        LispObject v0281 = stack[0];
        popv(8);
        return list2star(v0281, v0140, v0278);
    }

v0078:
    v0278 = stack[-3];
    fn = elt(env, 9); // revv0
    v0278 = (*qfn2(fn))(qenv(fn), v0278, v0140);
    nil = C_nil;
    if (exception_pending()) goto v0280;
    env = stack[-7];
    goto v0163;

v0238:
    v0279 = v0140;
    v0278 = stack[-3];
    v0278 = qcdr(v0278);
    v0278 = Lmemq(nil, v0279, v0278);
    v0278 = (v0278 == nil ? lisp_true : nil);
    goto v0093;
// error exit handlers
v0280:
    popv(8);
    return nil;
}



// Code for ibalp_simpatom

static LispObject CC_ibalp_simpatom(LispObject env,
                         LispObject v0059)
{
    LispObject nil = C_nil;
    LispObject v0272, v0212;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_simpatom");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0059);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0059);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0059;
// end of prologue
    v0212 = stack[0];
    v0272 = (LispObject)1; // 0
    if (v0212 == v0272) goto v0108;
    v0212 = stack[0];
    v0272 = (LispObject)17; // 1
    v0272 = (v0212 == v0272 ? lisp_true : nil);
    goto v0107;

v0107:
    if (!(v0272 == nil)) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    v0272 = stack[0];
    if (symbolp(v0272)) goto v0237;
    v0272 = stack[0];
    if (!(v0272 == nil)) goto v0159;
    v0212 = elt(env, 3); // "nil"
    v0272 = elt(env, 4); // "Boolean term"
    fn = elt(env, 7); // typerr
    v0272 = (*qfn2(fn))(qenv(fn), v0212, v0272);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-1];
    goto v0159;

v0159:
    v0272 = stack[0];
    if (!(is_number(v0272))) goto v0216;
    v0212 = elt(env, 5); // "number"
    v0272 = stack[0];
    v0212 = list2(v0212, v0272);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-1];
    v0272 = elt(env, 4); // "Boolean term"
    fn = elt(env, 7); // typerr
    v0272 = (*qfn2(fn))(qenv(fn), v0212, v0272);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-1];
    goto v0216;

v0216:
    v0272 = stack[0];
    v0272 = Lstringp(nil, v0272);
    env = stack[-1];
    if (v0272 == nil) goto v0070;
    v0212 = elt(env, 6); // "string"
    v0272 = stack[0];
    v0212 = list2(v0212, v0272);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-1];
    v0272 = elt(env, 4); // "Boolean term"
    fn = elt(env, 7); // typerr
    v0272 = (*qfn2(fn))(qenv(fn), v0212, v0272);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    goto v0070;

v0070:
    v0272 = nil;
    { popv(2); return onevalue(v0272); }

v0237:
    v0272 = stack[0];
    fn = elt(env, 8); // rl_gettype
    v0272 = (*qfn1(fn))(qenv(fn), v0272);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-1];
    if (v0272 == nil) goto v0198;
    v0272 = stack[0];
    fn = elt(env, 9); // reval
    v0272 = (*qfn1(fn))(qenv(fn), v0272);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 10); // ibalp_simpterm
        return (*qfn1(fn))(qenv(fn), v0272);
    }

v0198:
    v0272 = stack[0];
    v0212 = ncons(v0272);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-1];
    v0272 = elt(env, 2); // used!*
    v0272 = Lflag(nil, v0212, v0272);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    { LispObject res = stack[0]; popv(2); return onevalue(res); }

v0108:
    v0272 = qvalue(elt(env, 1)); // t
    goto v0107;
// error exit handlers
v0233:
    popv(2);
    return nil;
}



// Code for mathml2

static LispObject CC_mathml2(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0074;
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



// Code for testredh

static LispObject CC_testredh(LispObject env,
                         LispObject v0059)
{
    LispObject nil = C_nil;
    LispObject v0230, v0207;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for testredh");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0059);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0059);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0059;
// end of prologue
    stack[-1] = qvalue(elt(env, 1)); // codmat
    v0207 = qvalue(elt(env, 2)); // maxvar
    v0230 = stack[0];
    v0230 = plus2(v0207, v0230);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-2];
    v0207 = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v0230/(16/CELL)));
    v0230 = (LispObject)1; // 0
    v0230 = *(LispObject *)((char *)v0207 + (CELL-TAG_VECTOR) + ((int32_t)v0230/(16/CELL)));
    if (v0230 == nil) goto v0002;
    stack[-1] = qvalue(elt(env, 1)); // codmat
    v0207 = qvalue(elt(env, 2)); // maxvar
    v0230 = stack[0];
    v0230 = plus2(v0207, v0230);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-2];
    v0207 = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v0230/(16/CELL)));
    v0230 = (LispObject)17; // 1
    v0230 = *(LispObject *)((char *)v0207 + (CELL-TAG_VECTOR) + ((int32_t)v0230/(16/CELL)));
    v0230 = qcar(v0230);
    v0207 = qcar(v0230);
    v0230 = (LispObject)33; // 2
    v0230 = (LispObject)lessp2(v0207, v0230);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    v0230 = v0230 ? lisp_true : nil;
    env = stack[-2];
    if (v0230 == nil) goto v0002;
    v0230 = stack[0];
    fn = elt(env, 3); // rowdel
    v0230 = (*qfn1(fn))(qenv(fn), v0230);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-2];
    v0230 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); // testredzz
        return (*qfn1(fn))(qenv(fn), v0230);
    }

v0002:
    v0230 = nil;
    { popv(3); return onevalue(v0230); }
// error exit handlers
v0155:
    popv(3);
    return nil;
}



// Code for sc_minussq

static LispObject CC_sc_minussq(LispObject env,
                         LispObject v0059)
{
    LispObject nil = C_nil;
    LispObject v0002;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sc_minussq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0002 = v0059;
// end of prologue
    v0002 = qcar(v0002);
    {
        fn = elt(env, 1); // minusf
        return (*qfn1(fn))(qenv(fn), v0002);
    }
}



// Code for vevdif

static LispObject CC_vevdif(LispObject env,
                         LispObject v0059, LispObject v0058)
{
    LispObject nil = C_nil;
    LispObject v0152, v0211, v0221;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vevdif");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0058,v0059);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0059,v0058);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    stack[-3] = v0058;
    stack[-4] = v0059;
// end of prologue
    stack[-5] = nil;
    v0211 = nil;
    v0152 = stack[-4];
    stack[-1] = v0152;
    v0152 = stack[-3];
    stack[0] = v0152;
    goto v0179;

v0179:
    v0152 = stack[-1];
    if (v0152 == nil) goto v0194;
    v0152 = stack[0];
    if (v0152 == nil) goto v0194;
    v0152 = v0211;
    if (!(v0152 == nil)) goto v0194;
    v0152 = stack[-1];
    v0211 = qcar(v0152);
    v0152 = stack[0];
    v0152 = qcar(v0152);
    v0152 = (LispObject)(int32_t)((int32_t)v0211 - (int32_t)v0152 + TAG_FIXNUM);
    stack[-2] = v0152;
    v0211 = stack[-2];
    v0152 = stack[-5];
    v0152 = cons(v0211, v0152);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-6];
    stack[-5] = v0152;
    v0211 = stack[-2];
    v0152 = (LispObject)1; // 0
    v0152 = ((intptr_t)v0211 < (intptr_t)v0152) ? lisp_true : nil;
    v0211 = v0152;
    v0152 = stack[-1];
    v0152 = qcdr(v0152);
    stack[-1] = v0152;
    v0152 = stack[0];
    v0152 = qcdr(v0152);
    stack[0] = v0152;
    goto v0179;

v0194:
    v0152 = v0211;
    if (!(v0152 == nil)) goto v0202;
    v0152 = stack[0];
    if (v0152 == nil) goto v0226;
    v0152 = stack[0];
    if (v0152 == nil) goto v0155;
    v0152 = stack[0];
    v0211 = qcar(v0152);
    v0152 = (LispObject)1; // 0
    if (v0211 == v0152) goto v0157;
    v0152 = qvalue(elt(env, 1)); // nil
    goto v0209;

v0209:
    if (!(v0152 == nil)) goto v0226;

v0202:
    v0152 = stack[-4];
    v0152 = Lprint(nil, v0152);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-6];
    v0152 = stack[-3];
    v0152 = Lprint(nil, v0152);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-6];
    v0152 = elt(env, 3); // backtrace
    fn = elt(env, 6); // getd
    v0152 = (*qfn1(fn))(qenv(fn), v0152);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-6];
    if (v0152 == nil) goto v0065;
    fn = elt(env, 3); // backtrace
    v0152 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-6];
    goto v0065;

v0065:
    v0221 = elt(env, 4); // dipoly
    v0211 = (LispObject)81; // 5
    v0152 = elt(env, 5); // "Vevdif, difference would be < 0"
    {
        popv(7);
        fn = elt(env, 7); // rerror
        return (*qfnn(fn))(qenv(fn), 3, v0221, v0211, v0152);
    }

v0226:
    v0152 = stack[-5];
    v0211 = Lnreverse(nil, v0152);
    v0152 = stack[-1];
        popv(7);
        return Lnconc(nil, v0211, v0152);

v0157:
    v0152 = stack[0];
    v0152 = qcdr(v0152);
    fn = elt(env, 8); // vevzero!?1
    v0152 = (*qfn1(fn))(qenv(fn), v0152);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-6];
    goto v0209;

v0155:
    v0152 = qvalue(elt(env, 2)); // t
    goto v0209;
// error exit handlers
v0282:
    popv(7);
    return nil;
}



// Code for mksgnsq

static LispObject CC_mksgnsq(LispObject env,
                         LispObject v0059)
{
    LispObject nil = C_nil;
    LispObject v0190, v0225, v0158;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mksgnsq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0059);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0059);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0225 = v0059;
// end of prologue
    v0190 = v0225;
    fn = elt(env, 1); // evenfree
    v0190 = (*qfn1(fn))(qenv(fn), v0190);
    nil = C_nil;
    if (exception_pending()) goto v0234;
    env = stack[-1];
    v0225 = v0190;
    if (v0190 == nil) goto v0106;
    v0158 = v0225;
    v0190 = (LispObject)17; // 1
    if (v0158 == v0190) goto v0182;
    stack[0] = (LispObject)-15; // -1
    v0190 = (LispObject)17; // 1
    v0190 = cons(v0225, v0190);
    nil = C_nil;
    if (exception_pending()) goto v0234;
    env = stack[-1];
    fn = elt(env, 2); // mk!*sq
    v0190 = (*qfn1(fn))(qenv(fn), v0190);
    nil = C_nil;
    if (exception_pending()) goto v0234;
    env = stack[-1];
    v0190 = list2(stack[0], v0190);
    nil = C_nil;
    if (exception_pending()) goto v0234;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 3); // simpexpt
        return (*qfn1(fn))(qenv(fn), v0190);
    }

v0182:
    v0225 = (LispObject)-15; // -1
    v0190 = (LispObject)17; // 1
    popv(2);
    return cons(v0225, v0190);

v0106:
    v0225 = (LispObject)17; // 1
    v0190 = (LispObject)17; // 1
    popv(2);
    return cons(v0225, v0190);
// error exit handlers
v0234:
    popv(2);
    return nil;
}



// Code for rnconc

static LispObject CC_rnconc(LispObject env,
                         LispObject v0059, LispObject v0058)
{
    LispObject nil = C_nil;
    LispObject v0105, v0234;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rnconc");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0058,v0059);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0059,v0058);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0058;
    stack[-1] = v0059;
// end of prologue
    v0105 = stack[-1];
    if (v0105 == nil) { LispObject res = stack[0]; popv(3); return onevalue(res); }
    v0105 = qvalue(elt(env, 1)); // !*ncmp
    if (v0105 == nil) goto v0259;
    v0105 = stack[-1];
    fn = elt(env, 3); // noncomfp1
    v0105 = (*qfn1(fn))(qenv(fn), v0105);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-2];
    if (v0105 == nil) goto v0259;
    v0105 = stack[0];
    fn = elt(env, 3); // noncomfp1
    v0105 = (*qfn1(fn))(qenv(fn), v0105);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-2];
    if (v0105 == nil) goto v0259;
    v0234 = stack[-1];
    v0105 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); // addf
        return (*qfn2(fn))(qenv(fn), v0234, v0105);
    }

v0259:
    v0105 = stack[-1];
    v0234 = v0105;
    goto v0079;

v0079:
    v0105 = v0234;
    v0105 = qcdr(v0105);
    if (v0105 == nil) goto v0258;
    v0105 = v0234;
    v0105 = qcdr(v0105);
    v0234 = v0105;
    goto v0079;

v0258:
    v0105 = stack[0];
    v0105 = Lrplacd(nil, v0234, v0105);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    { LispObject res = stack[-1]; popv(3); return onevalue(res); }
// error exit handlers
v0202:
    popv(3);
    return nil;
}



// Code for formclis

static LispObject CC_formclis(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0079, v0218, v0219;
    LispObject fn;
    LispObject v0024, v0058, v0059;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "formclis");
    va_start(aa, nargs);
    v0059 = va_arg(aa, LispObject);
    v0058 = va_arg(aa, LispObject);
    v0024 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for formclis");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0024,v0058,v0059);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0059,v0058,v0024);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0024;
    stack[-1] = v0058;
    stack[-2] = v0059;
// end of prologue
    stack[-3] = nil;
    goto v0030;

v0030:
    v0079 = stack[-2];
    if (v0079 == nil) goto v0107;
    v0079 = stack[-2];
    v0219 = qcar(v0079);
    v0218 = stack[-1];
    v0079 = stack[0];
    fn = elt(env, 1); // formc
    v0218 = (*qfnn(fn))(qenv(fn), 3, v0219, v0218, v0079);
    nil = C_nil;
    if (exception_pending()) goto v0191;
    env = stack[-4];
    v0079 = stack[-3];
    v0079 = cons(v0218, v0079);
    nil = C_nil;
    if (exception_pending()) goto v0191;
    env = stack[-4];
    stack[-3] = v0079;
    v0079 = stack[-2];
    v0079 = qcdr(v0079);
    stack[-2] = v0079;
    goto v0030;

v0107:
    v0079 = stack[-3];
    {
        popv(5);
        fn = elt(env, 2); // reversip!*
        return (*qfn1(fn))(qenv(fn), v0079);
    }
// error exit handlers
v0191:
    popv(5);
    return nil;
}



// Code for evalneq

static LispObject CC_evalneq(LispObject env,
                         LispObject v0059, LispObject v0058)
{
    LispObject nil = C_nil;
    LispObject v0228, v0194;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evalneq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0058,v0059);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0059,v0058);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
// copy arguments values to proper place
    v0228 = v0058;
    v0194 = v0059;
// end of prologue
    fn = elt(env, 1); // evalequal
    v0228 = (*qfn2(fn))(qenv(fn), v0194, v0228);
    errexit();
    v0228 = (v0228 == nil ? lisp_true : nil);
    return onevalue(v0228);
}



// Code for dp_times_bcmo

static LispObject CC_dp_times_bcmo(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0070, v0067;
    LispObject fn;
    LispObject v0024, v0058, v0059;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "dp_times_bcmo");
    va_start(aa, nargs);
    v0059 = va_arg(aa, LispObject);
    v0058 = va_arg(aa, LispObject);
    v0024 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dp_times_bcmo");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0024,v0058,v0059);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0059,v0058,v0024);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
// copy arguments values to proper place
    v0070 = v0024;
    stack[-5] = v0058;
    stack[-6] = v0059;
// end of prologue
    stack[-7] = v0070;
    v0070 = stack[-7];
    if (v0070 == nil) goto v0194;
    v0070 = stack[-7];
    v0070 = qcar(v0070);
    stack[-1] = v0070;
    v0067 = stack[-5];
    v0070 = stack[-1];
    v0070 = qcar(v0070);
    fn = elt(env, 2); // mo_sum
    stack[0] = (*qfn2(fn))(qenv(fn), v0067, v0070);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    env = stack[-8];
    v0067 = stack[-6];
    v0070 = stack[-1];
    v0070 = qcdr(v0070);
    fn = elt(env, 3); // cali_bc_prod
    v0070 = (*qfn2(fn))(qenv(fn), v0067, v0070);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    env = stack[-8];
    v0070 = cons(stack[0], v0070);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    env = stack[-8];
    v0070 = ncons(v0070);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    env = stack[-8];
    stack[-3] = v0070;
    stack[-4] = v0070;
    goto v0106;

v0106:
    v0070 = stack[-7];
    v0070 = qcdr(v0070);
    stack[-7] = v0070;
    v0070 = stack[-7];
    if (v0070 == nil) { LispObject res = stack[-4]; popv(9); return onevalue(res); }
    stack[-2] = stack[-3];
    v0070 = stack[-7];
    v0070 = qcar(v0070);
    stack[-1] = v0070;
    v0067 = stack[-5];
    v0070 = stack[-1];
    v0070 = qcar(v0070);
    fn = elt(env, 2); // mo_sum
    stack[0] = (*qfn2(fn))(qenv(fn), v0067, v0070);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    env = stack[-8];
    v0067 = stack[-6];
    v0070 = stack[-1];
    v0070 = qcdr(v0070);
    fn = elt(env, 3); // cali_bc_prod
    v0070 = (*qfn2(fn))(qenv(fn), v0067, v0070);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    env = stack[-8];
    v0070 = cons(stack[0], v0070);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    env = stack[-8];
    v0070 = ncons(v0070);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    env = stack[-8];
    v0070 = Lrplacd(nil, stack[-2], v0070);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    env = stack[-8];
    v0070 = stack[-3];
    v0070 = qcdr(v0070);
    stack[-3] = v0070;
    goto v0106;

v0194:
    v0070 = qvalue(elt(env, 1)); // nil
    { popv(9); return onevalue(v0070); }
// error exit handlers
v0229:
    popv(9);
    return nil;
}



// Code for pv_intequiv

static LispObject CC_pv_intequiv(LispObject env,
                         LispObject v0059)
{
    LispObject nil = C_nil;
    LispObject v0194, v0179;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pv_intequiv");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0179 = v0059;
// end of prologue
    v0194 = v0179;
    v0194 = qcdr(v0194);
    if (!consp(v0194)) goto v0003;
    v0194 = qvalue(elt(env, 1)); // nil
    return onevalue(v0194);

v0003:
    v0194 = v0179;
    v0194 = qcdr(v0194);
    return onevalue(v0194);
}



// Code for remcomma

static LispObject CC_remcomma(LispObject env,
                         LispObject v0059)
{
    LispObject nil = C_nil;
    LispObject v0224, v0093, v0180;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for remcomma");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0093 = v0059;
// end of prologue
    v0224 = v0093;
    v0180 = elt(env, 1); // !*comma!*
    if (!consp(v0224)) goto v0162;
    v0224 = qcar(v0224);
    if (!(v0224 == v0180)) goto v0162;
    v0224 = v0093;
    v0224 = qcdr(v0224);
    return onevalue(v0224);

v0162:
    v0224 = v0093;
    return ncons(v0224);
}



// Code for polynommultiplybyvariable

static LispObject CC_polynommultiplybyvariable(LispObject env,
                         LispObject v0059, LispObject v0058)
{
    LispObject nil = C_nil;
    LispObject v0235, v0094;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for polynommultiplybyvariable");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0058,v0059);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0059,v0058);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0058;
    stack[-2] = v0059;
// end of prologue
    stack[-3] = nil;
    v0235 = stack[-2];
    stack[0] = v0235;
    goto v0107;

v0107:
    v0235 = stack[0];
    v0235 = qcar(v0235);
    if (v0235 == nil) goto v0072;
    v0235 = stack[0];
    v0094 = qcar(v0235);
    v0235 = stack[-1];
    fn = elt(env, 2); // monomgetvariabledegree
    v0094 = (*qfn2(fn))(qenv(fn), v0094, v0235);
    nil = C_nil;
    if (exception_pending()) goto v0062;
    env = stack[-4];
    v0235 = (LispObject)1; // 0
    v0235 = Leqn(nil, v0094, v0235);
    nil = C_nil;
    if (exception_pending()) goto v0062;
    env = stack[-4];
    if (v0235 == nil) goto v0208;
    v0235 = stack[0];
    v0094 = qcar(v0235);
    v0235 = stack[-3];
    v0235 = cons(v0094, v0235);
    nil = C_nil;
    if (exception_pending()) goto v0062;
    env = stack[-4];
    stack[-3] = v0235;
    v0094 = stack[0];
    v0235 = stack[0];
    v0235 = qcdr(v0235);
    v0235 = qcar(v0235);
    v0094 = Lrplaca(nil, v0094, v0235);
    nil = C_nil;
    if (exception_pending()) goto v0062;
    env = stack[-4];
    v0235 = stack[0];
    v0235 = qcdr(v0235);
    v0235 = qcdr(v0235);
    v0235 = Lrplacd(nil, v0094, v0235);
    nil = C_nil;
    if (exception_pending()) goto v0062;
    env = stack[-4];
    goto v0107;

v0208:
    v0235 = stack[0];
    v0235 = qcdr(v0235);
    stack[0] = v0235;
    goto v0107;

v0072:
    v0094 = qvalue(elt(env, 1)); // nil
    v0235 = stack[-3];
    v0235 = cons(v0094, v0235);
    nil = C_nil;
    if (exception_pending()) goto v0062;
    env = stack[-4];
    stack[-3] = v0235;
    v0235 = stack[-3];
    v0235 = Lreverse(nil, v0235);
    nil = C_nil;
    if (exception_pending()) goto v0062;
    env = stack[-4];
    stack[-3] = v0235;
    v0235 = stack[-3];
    stack[0] = v0235;
    goto v0184;

v0184:
    v0235 = stack[0];
    v0235 = qcar(v0235);
    if (v0235 == nil) goto v0153;
    v0235 = stack[0];
    v0094 = qcar(v0235);
    v0235 = stack[-1];
    fn = elt(env, 3); // monommultiplybyvariable
    v0235 = (*qfn2(fn))(qenv(fn), v0094, v0235);
    nil = C_nil;
    if (exception_pending()) goto v0062;
    env = stack[-4];
    v0235 = stack[0];
    v0235 = qcdr(v0235);
    stack[0] = v0235;
    goto v0184;

v0153:
    v0094 = stack[-2];
    v0235 = stack[-3];
    fn = elt(env, 4); // polynomadd
    v0235 = (*qfn2(fn))(qenv(fn), v0094, v0235);
    nil = C_nil;
    if (exception_pending()) goto v0062;
    v0235 = nil;
    { popv(5); return onevalue(v0235); }
// error exit handlers
v0062:
    popv(5);
    return nil;
}



// Code for sfto_tsqsumf

static LispObject CC_sfto_tsqsumf(LispObject env,
                         LispObject v0059)
{
    LispObject nil = C_nil;
    LispObject v0201;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sfto_tsqsumf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0059);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0059);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0059;
// end of prologue

v0003:
    v0201 = stack[0];
    if (!consp(v0201)) goto v0108;
    v0201 = stack[0];
    v0201 = qcar(v0201);
    v0201 = (consp(v0201) ? nil : lisp_true);
    goto v0107;

v0107:
    if (v0201 == nil) goto v0237;
    v0201 = stack[0];
    if (v0201 == nil) goto v0180;
    v0201 = stack[0];
    fn = elt(env, 5); // minusf
    v0201 = (*qfn1(fn))(qenv(fn), v0201);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-1];
    if (v0201 == nil) goto v0182;
    v0201 = qvalue(elt(env, 4)); // nil
    { popv(2); return onevalue(v0201); }

v0182:
    v0201 = elt(env, 3); // stsq
    { popv(2); return onevalue(v0201); }

v0180:
    v0201 = elt(env, 2); // tsq
    { popv(2); return onevalue(v0201); }

v0237:
    v0201 = stack[0];
    v0201 = qcar(v0201);
    v0201 = qcar(v0201);
    v0201 = qcdr(v0201);
    v0201 = Levenp(nil, v0201);
    env = stack[-1];
    if (v0201 == nil) goto v0266;
    v0201 = stack[0];
    v0201 = qcar(v0201);
    v0201 = qcdr(v0201);
    v0201 = CC_sfto_tsqsumf(env, v0201);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-1];
    if (v0201 == nil) goto v0105;
    v0201 = stack[0];
    v0201 = qcdr(v0201);
    stack[0] = v0201;
    goto v0003;

v0105:
    v0201 = qvalue(elt(env, 4)); // nil
    { popv(2); return onevalue(v0201); }

v0266:
    v0201 = qvalue(elt(env, 4)); // nil
    { popv(2); return onevalue(v0201); }

v0108:
    v0201 = qvalue(elt(env, 1)); // t
    goto v0107;
// error exit handlers
v0078:
    popv(2);
    return nil;
}



// Code for quotfail1

static LispObject CC_quotfail1(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0193, v0237, v0238;
    LispObject fn;
    LispObject v0024, v0058, v0059;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "quotfail1");
    va_start(aa, nargs);
    v0059 = va_arg(aa, LispObject);
    v0058 = va_arg(aa, LispObject);
    v0024 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for quotfail1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0024,v0058,v0059);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0059,v0058,v0024);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0024;
    v0237 = v0058;
    v0238 = v0059;
// end of prologue
    v0193 = v0238;
    if (v0193 == nil) goto v0074;
    v0193 = v0238;
    fn = elt(env, 2); // quotf
    v0193 = (*qfn2(fn))(qenv(fn), v0193, v0237);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-1];
    v0237 = v0193;
    v0193 = v0237;
    if (!(v0193 == nil)) { popv(2); return onevalue(v0237); }
    v0193 = stack[0];
    fn = elt(env, 3); // errorf
    v0193 = (*qfn1(fn))(qenv(fn), v0193);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    v0193 = nil;
    { popv(2); return onevalue(v0193); }

v0074:
    v0193 = qvalue(elt(env, 1)); // polyzero
    { popv(2); return onevalue(v0193); }
// error exit handlers
v0218:
    popv(2);
    return nil;
}



// Code for ckrn

static LispObject CC_ckrn(LispObject env,
                         LispObject v0059)
{
    LispObject nil = C_nil;
    LispObject v0234, v0159;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ckrn");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0059);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0059);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0059;
// end of prologue
    v0234 = qvalue(elt(env, 1)); // dmode!*
    if (!symbolp(v0234)) v0234 = nil;
    else { v0234 = qfastgets(v0234);
           if (v0234 != nil) { v0234 = elt(v0234, 3); // field
#ifdef RECORD_GET
             if (v0234 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v0234 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v0234 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v0234 == SPID_NOPROP) v0234 = nil; else v0234 = lisp_true; }}
#endif
    if (v0234 == nil) goto v0093;
    v0159 = qvalue(elt(env, 1)); // dmode!*
    v0234 = elt(env, 2); // (!:rd!: !:cr!:)
    v0234 = Lmemq(nil, v0159, v0234);
    v0234 = (v0234 == nil ? lisp_true : nil);
    goto v0030;

v0030:
    if (v0234 == nil) goto v0190;
    v0234 = stack[0];
    fn = elt(env, 4); // lnc
    v0234 = (*qfn1(fn))(qenv(fn), v0234);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-2];
    stack[-1] = v0234;
    v0159 = stack[0];
    fn = elt(env, 5); // quotfd
    v0234 = (*qfn2(fn))(qenv(fn), v0159, v0234);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-2];
    fn = elt(env, 6); // ckrn1
    v0234 = (*qfn1(fn))(qenv(fn), v0234);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-2];
    fn = elt(env, 7); // multf
    v0234 = (*qfn2(fn))(qenv(fn), stack[-1], v0234);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    v0159 = v0234;
    if (!(v0159 == nil)) { popv(3); return onevalue(v0234); }
    v0234 = (LispObject)17; // 1
    { popv(3); return onevalue(v0234); }

v0190:
    v0234 = stack[0];
    {
        popv(3);
        fn = elt(env, 6); // ckrn1
        return (*qfn1(fn))(qenv(fn), v0234);
    }

v0093:
    v0234 = qvalue(elt(env, 3)); // nil
    goto v0030;
// error exit handlers
v0200:
    popv(3);
    return nil;
}



// Code for ibalp_clauselp

static LispObject CC_ibalp_clauselp(LispObject env,
                         LispObject v0059)
{
    LispObject nil = C_nil;
    LispObject v0181;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_clauselp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0059);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0059);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0059;
// end of prologue

v0255:
    v0181 = stack[0];
    if (v0181 == nil) goto v0003;
    v0181 = stack[0];
    v0181 = qcar(v0181);
    fn = elt(env, 3); // ibalp_clausep
    v0181 = (*qfn1(fn))(qenv(fn), v0181);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-1];
    if (v0181 == nil) goto v0228;
    v0181 = stack[0];
    v0181 = qcdr(v0181);
    stack[0] = v0181;
    goto v0255;

v0228:
    v0181 = qvalue(elt(env, 2)); // nil
    { popv(2); return onevalue(v0181); }

v0003:
    v0181 = qvalue(elt(env, 1)); // t
    { popv(2); return onevalue(v0181); }
// error exit handlers
v0161:
    popv(2);
    return nil;
}



// Code for cgp_ci

static LispObject CC_cgp_ci(LispObject env,
                         LispObject v0059)
{
    LispObject nil = C_nil;
    LispObject v0107, v0108;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cgp_ci");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0107 = v0059;
// end of prologue
    v0108 = v0107;
    v0107 = (LispObject)97; // 6
    {
        fn = elt(env, 1); // nth
        return (*qfn2(fn))(qenv(fn), v0108, v0107);
    }
}



// Code for c!:subs2multf

static LispObject CC_cTsubs2multf(LispObject env,
                         LispObject v0059, LispObject v0058)
{
    LispObject nil = C_nil;
    LispObject v0258, v0080, v0081;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for c:subs2multf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0058,v0059);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0059,v0058);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0080 = v0058;
    v0081 = v0059;
// end of prologue
    v0258 = qvalue(elt(env, 1)); // !*sub2
    stack[0] = qvalue(elt(env, 1)); // !*sub2
    qvalue(elt(env, 1)) = v0258; // !*sub2
    v0258 = v0081;
    fn = elt(env, 4); // multf
    v0080 = (*qfn2(fn))(qenv(fn), v0258, v0080);
    nil = C_nil;
    if (exception_pending()) goto v0225;
    env = stack[-1];
    v0258 = (LispObject)17; // 1
    v0258 = cons(v0080, v0258);
    nil = C_nil;
    if (exception_pending()) goto v0225;
    env = stack[-1];
    fn = elt(env, 5); // subs2
    v0258 = (*qfn1(fn))(qenv(fn), v0258);
    nil = C_nil;
    if (exception_pending()) goto v0225;
    env = stack[-1];
    v0081 = v0258;
    v0258 = v0081;
    v0080 = qcdr(v0258);
    v0258 = (LispObject)17; // 1
    if (v0080 == v0258) goto v0104;
    v0081 = elt(env, 2); // matrix
    v0080 = (LispObject)225; // 14
    v0258 = elt(env, 3); // "Sub error in glnrsolve"
    fn = elt(env, 6); // rerror
    v0258 = (*qfnn(fn))(qenv(fn), 3, v0081, v0080, v0258);
    nil = C_nil;
    if (exception_pending()) goto v0225;
    env = stack[-1];
    goto v0181;

v0181:
    qvalue(elt(env, 1)) = stack[0]; // !*sub2
    { popv(2); return onevalue(v0258); }

v0104:
    v0258 = v0081;
    v0258 = qcar(v0258);
    goto v0181;
// error exit handlers
v0225:
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; // !*sub2
    popv(2);
    return nil;
}



// Code for getmat

static LispObject CC_getmat(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0077, v0078, v0076;
    LispObject fn;
    LispObject v0024, v0058, v0059;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "getmat");
    va_start(aa, nargs);
    v0059 = va_arg(aa, LispObject);
    v0058 = va_arg(aa, LispObject);
    v0024 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for getmat");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0024,v0058,v0059);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0059,v0058,v0024);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0024;
    stack[-1] = v0058;
    stack[-2] = v0059;
// end of prologue
    v0077 = qvalue(elt(env, 1)); // !*modular
    if (v0077 == nil) goto v0002;
    v0077 = elt(env, 2); // modular
    v0077 = ncons(v0077);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-3];
    fn = elt(env, 6); // off
    v0077 = (*qfn1(fn))(qenv(fn), v0077);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-3];
    v0077 = elt(env, 3); // mod_was_on
    v0077 = ncons(v0077);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-3];
    fn = elt(env, 7); // on
    v0077 = (*qfn1(fn))(qenv(fn), v0077);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-3];
    goto v0002;

v0002:
    v0077 = stack[-1];
    v0077 = integerp(v0077);
    if (v0077 == nil) goto v0181;
    v0077 = stack[-1];
    goto v0163;

v0163:
    stack[-1] = v0077;
    v0077 = stack[0];
    v0077 = integerp(v0077);
    if (v0077 == nil) goto v0237;
    v0077 = stack[0];
    goto v0259;

v0259:
    stack[0] = v0077;
    v0077 = qvalue(elt(env, 5)); // !*mod_was_on
    if (v0077 == nil) goto v0190;
    v0077 = elt(env, 2); // modular
    v0077 = ncons(v0077);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-3];
    fn = elt(env, 7); // on
    v0077 = (*qfn1(fn))(qenv(fn), v0077);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-3];
    v0077 = elt(env, 3); // mod_was_on
    v0077 = ncons(v0077);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-3];
    fn = elt(env, 6); // off
    v0077 = (*qfn1(fn))(qenv(fn), v0077);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-3];
    goto v0190;

v0190:
    v0076 = stack[-2];
    v0078 = stack[-1];
    v0077 = stack[0];
    v0077 = list3(v0076, v0078, v0077);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-3];
    {
        popv(4);
        fn = elt(env, 8); // unchecked_getmatelem
        return (*qfn1(fn))(qenv(fn), v0077);
    }

v0237:
    v0077 = stack[0];
    fn = elt(env, 9); // reval
    v0077 = (*qfn1(fn))(qenv(fn), v0077);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-3];
    goto v0259;

v0181:
    v0077 = stack[-1];
    fn = elt(env, 9); // reval
    v0077 = (*qfn1(fn))(qenv(fn), v0077);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-3];
    goto v0163;
// error exit handlers
v0209:
    popv(4);
    return nil;
}



// Code for lid

static LispObject CC_lid(LispObject env,
                         LispObject v0059)
{
    LispObject nil = C_nil;
    LispObject v0228, v0194;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lid");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0228 = v0059;
// end of prologue
    v0194 = v0228;
    if (!consp(v0194)) return onevalue(v0228);
    v0228 = qcar(v0228);
    return onevalue(v0228);
}



// Code for physop!-multf

static LispObject CC_physopKmultf(LispObject env,
                         LispObject v0059, LispObject v0058)
{
    LispObject nil = C_nil;
    LispObject v0313, v0314, v0315;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for physop-multf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0058,v0059);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0059,v0058);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0058;
    stack[-2] = v0059;
// end of prologue
    stack[-3] = nil;
    goto v0030;

v0030:
    v0313 = stack[-2];
    if (v0313 == nil) goto v0179;
    v0313 = stack[-1];
    v0313 = (v0313 == nil ? lisp_true : nil);
    goto v0194;

v0194:
    if (v0313 == nil) goto v0161;
    v0313 = qvalue(elt(env, 2)); // nil
    { popv(5); return onevalue(v0313); }

v0161:
    v0314 = stack[-2];
    v0313 = (LispObject)17; // 1
    if (v0314 == v0313) { LispObject res = stack[-1]; popv(5); return onevalue(res); }
    v0314 = stack[-1];
    v0313 = (LispObject)17; // 1
    if (v0314 == v0313) { LispObject res = stack[-2]; popv(5); return onevalue(res); }
    v0313 = stack[-2];
    if (!consp(v0313)) goto v0198;
    v0313 = stack[-2];
    v0313 = qcar(v0313);
    v0313 = (consp(v0313) ? nil : lisp_true);
    goto v0169;

v0169:
    if (v0313 == nil) goto v0192;
    v0314 = stack[-2];
    v0313 = stack[-1];
    {
        popv(5);
        fn = elt(env, 10); // multd
        return (*qfn2(fn))(qenv(fn), v0314, v0313);
    }

v0192:
    v0313 = stack[-1];
    if (!consp(v0313)) goto v0209;
    v0313 = stack[-1];
    v0313 = qcar(v0313);
    v0313 = (consp(v0313) ? nil : lisp_true);
    goto v0208;

v0208:
    if (v0313 == nil) goto v0230;
    v0314 = stack[-1];
    v0313 = stack[-2];
    {
        popv(5);
        fn = elt(env, 10); // multd
        return (*qfn2(fn))(qenv(fn), v0314, v0313);
    }

v0230:
    v0313 = qvalue(elt(env, 3)); // !*exp
    if (!(v0313 == nil)) goto v0106;
    v0313 = qvalue(elt(env, 4)); // ncmp!*
    if (!(v0313 == nil)) goto v0106;
    v0313 = qvalue(elt(env, 5)); // wtl!*
    if (!(v0313 == nil)) goto v0106;
    v0313 = stack[-3];
    if (!(v0313 == nil)) goto v0106;
    v0313 = stack[-2];
    fn = elt(env, 11); // mkprod
    v0313 = (*qfn1(fn))(qenv(fn), v0313);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-4];
    stack[-2] = v0313;
    v0313 = stack[-1];
    fn = elt(env, 11); // mkprod
    v0313 = (*qfn1(fn))(qenv(fn), v0313);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-4];
    stack[-1] = v0313;
    v0313 = qvalue(elt(env, 1)); // t
    stack[-3] = v0313;
    goto v0030;

v0106:
    v0313 = stack[-2];
    v0313 = qcar(v0313);
    v0313 = qcar(v0313);
    v0313 = qcar(v0313);
    stack[-3] = v0313;
    v0313 = stack[-1];
    v0313 = qcar(v0313);
    v0313 = qcar(v0313);
    v0313 = qcar(v0313);
    stack[0] = v0313;
    v0313 = stack[-1];
    fn = elt(env, 12); // noncomp2f
    v0313 = (*qfn1(fn))(qenv(fn), v0313);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-4];
    if (v0313 == nil) goto v0317;
    v0313 = stack[-3];
    if (!consp(v0313)) goto v0063;
    v0313 = stack[-3];
    v0313 = qcar(v0313);
    if (!symbolp(v0313)) v0313 = nil;
    else { v0313 = qfastgets(v0313);
           if (v0313 != nil) { v0313 = elt(v0313, 0); // noncom
#ifdef RECORD_GET
             if (v0313 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v0313 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v0313 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v0313 == SPID_NOPROP) v0313 = nil; else v0313 = lisp_true; }}
#endif
    goto v0062;

v0062:
    if (!(v0313 == nil)) goto v0060;
    v0313 = qvalue(elt(env, 6)); // !*!*processed
    if (!(v0313 == nil)) goto v0317;

v0060:
    v0314 = stack[-2];
    v0313 = stack[-1];
    {
        popv(5);
        fn = elt(env, 13); // physop!-multfnc
        return (*qfn2(fn))(qenv(fn), v0314, v0313);
    }

v0317:
    v0314 = stack[-3];
    v0313 = stack[0];
    fn = elt(env, 14); // physop!-ordop
    v0313 = (*qfn2(fn))(qenv(fn), v0314, v0313);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-4];
    if (v0313 == nil) goto v0100;
    v0314 = stack[-3];
    v0313 = stack[0];
    if (equal(v0314, v0313)) goto v0100;
    v0313 = stack[-2];
    v0313 = qcar(v0313);
    v0314 = qcdr(v0313);
    v0313 = stack[-1];
    v0313 = CC_physopKmultf(env, v0314, v0313);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-4];
    stack[-3] = v0313;
    v0313 = stack[-2];
    v0314 = qcdr(v0313);
    v0313 = stack[-1];
    v0313 = CC_physopKmultf(env, v0314, v0313);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    stack[0] = v0313;
    v0313 = stack[-3];
    if (v0313 == nil) { LispObject res = stack[0]; popv(5); return onevalue(res); }
    v0313 = stack[-2];
    v0313 = qcar(v0313);
    v0315 = qcar(v0313);
    v0314 = stack[-3];
    v0313 = stack[0];
    popv(5);
    return acons(v0315, v0314, v0313);

v0100:
    v0314 = stack[-3];
    v0313 = stack[0];
    if (equal(v0314, v0313)) goto v0318;
    v0313 = qvalue(elt(env, 2)); // nil
    goto v0248;

v0248:
    if (v0313 == nil) goto v0122;
    stack[0] = stack[-3];
    v0313 = stack[-2];
    v0313 = qcar(v0313);
    v0313 = qcar(v0313);
    v0314 = qcdr(v0313);
    v0313 = stack[-1];
    v0313 = qcar(v0313);
    v0313 = qcar(v0313);
    v0313 = qcdr(v0313);
    v0313 = plus2(v0314, v0313);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-4];
    fn = elt(env, 15); // mkspm
    v0313 = (*qfn2(fn))(qenv(fn), stack[0], v0313);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-4];
    stack[-3] = v0313;
    v0313 = stack[-2];
    v0314 = qcdr(v0313);
    v0313 = stack[-1];
    stack[0] = CC_physopKmultf(env, v0314, v0313);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-4];
    v0313 = stack[-2];
    v0313 = qcar(v0313);
    v0314 = ncons(v0313);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-4];
    v0313 = stack[-1];
    v0313 = qcdr(v0313);
    v0313 = CC_physopKmultf(env, v0314, v0313);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-4];
    fn = elt(env, 16); // addf
    v0313 = (*qfn2(fn))(qenv(fn), stack[0], v0313);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-4];
    stack[0] = v0313;
    v0313 = stack[-3];
    if (v0313 == nil) goto v0319;
    v0313 = stack[-2];
    v0313 = qcar(v0313);
    v0314 = qcdr(v0313);
    v0313 = stack[-1];
    v0313 = qcar(v0313);
    v0313 = qcdr(v0313);
    v0313 = CC_physopKmultf(env, v0314, v0313);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-4];
    stack[-2] = v0313;
    v0313 = (v0313 == nil ? lisp_true : nil);
    goto v0320;

v0320:
    if (v0313 == nil) goto v0321;
    v0313 = qvalue(elt(env, 1)); // t
    qvalue(elt(env, 8)) = v0313; // !*asymp!*
    { LispObject res = stack[0]; popv(5); return onevalue(res); }

v0321:
    v0314 = stack[-3];
    v0313 = (LispObject)17; // 1
    if (v0314 == v0313) goto v0322;
    v0313 = qvalue(elt(env, 9)); // !*mcd
    if (v0313 == nil) goto v0124;
    v0315 = stack[-3];
    v0314 = stack[-2];
    v0313 = stack[0];
    popv(5);
    return acons(v0315, v0314, v0313);

v0124:
    v0314 = stack[-3];
    v0313 = stack[-2];
    v0313 = cons(v0314, v0313);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-4];
    v0314 = ncons(v0313);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-4];
    v0313 = stack[0];
    {
        popv(5);
        fn = elt(env, 16); // addf
        return (*qfn2(fn))(qenv(fn), v0314, v0313);
    }

v0322:
    v0314 = stack[-2];
    v0313 = stack[0];
    {
        popv(5);
        fn = elt(env, 16); // addf
        return (*qfn2(fn))(qenv(fn), v0314, v0313);
    }

v0319:
    v0313 = qvalue(elt(env, 1)); // t
    goto v0320;

v0122:
    v0314 = stack[-2];
    v0313 = stack[-1];
    v0313 = qcar(v0313);
    v0313 = qcdr(v0313);
    v0313 = CC_physopKmultf(env, v0314, v0313);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-4];
    stack[-3] = v0313;
    v0314 = stack[-2];
    v0313 = stack[-1];
    v0313 = qcdr(v0313);
    v0313 = CC_physopKmultf(env, v0314, v0313);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    stack[0] = v0313;
    v0313 = stack[-3];
    if (v0313 == nil) { LispObject res = stack[0]; popv(5); return onevalue(res); }
    v0313 = stack[-1];
    v0313 = qcar(v0313);
    v0315 = qcar(v0313);
    v0314 = stack[-3];
    v0313 = stack[0];
    popv(5);
    return acons(v0315, v0314, v0313);

v0318:
    v0313 = stack[-3];
    fn = elt(env, 17); // physopp
    v0313 = (*qfn1(fn))(qenv(fn), v0313);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-4];
    if (v0313 == nil) goto v0140;
    v0313 = qvalue(elt(env, 7)); // !*contract2
    goto v0248;

v0140:
    v0313 = qvalue(elt(env, 1)); // t
    goto v0248;

v0063:
    v0313 = stack[-3];
    if (!symbolp(v0313)) v0313 = nil;
    else { v0313 = qfastgets(v0313);
           if (v0313 != nil) { v0313 = elt(v0313, 0); // noncom
#ifdef RECORD_GET
             if (v0313 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v0313 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v0313 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v0313 == SPID_NOPROP) v0313 = nil; else v0313 = lisp_true; }}
#endif
    goto v0062;

v0209:
    v0313 = qvalue(elt(env, 1)); // t
    goto v0208;

v0198:
    v0313 = qvalue(elt(env, 1)); // t
    goto v0169;

v0179:
    v0313 = qvalue(elt(env, 1)); // t
    goto v0194;
// error exit handlers
v0316:
    popv(5);
    return nil;
}



// Code for defined_edge

static LispObject CC_defined_edge(LispObject env,
                         LispObject v0059, LispObject v0058)
{
    LispObject nil = C_nil;
    LispObject v0237, v0238, v0079;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for defined_edge");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0058,v0059);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0059,v0058);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0058;
    v0079 = v0059;
// end of prologue
    v0237 = v0079;
    v0238 = qcar(v0237);
    v0237 = qvalue(elt(env, 1)); // old_edge_list
    v0237 = Lassoc(nil, v0238, v0237);
    if (!(v0237 == nil)) { popv(2); return onevalue(v0237); }
    v0237 = v0079;
    v0238 = qcar(v0237);
    v0237 = qvalue(elt(env, 2)); // new_edge_list
    fn = elt(env, 4); // all_edge
    v0079 = (*qfn2(fn))(qenv(fn), v0238, v0237);
    nil = C_nil;
    if (exception_pending()) goto v0219;
    env = stack[-1];
    v0238 = qvalue(elt(env, 3)); // nil
    v0237 = stack[0];
    {
        popv(2);
        fn = elt(env, 5); // defined_all_edge
        return (*qfnn(fn))(qenv(fn), 3, v0079, v0238, v0237);
    }
// error exit handlers
v0219:
    popv(2);
    return nil;
}



setup_type const u13_setup[] =
{
    {"use-berlekamp",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_useKberlekamp},
    {"idsort",                  CC_idsort,      too_many_1,    wrong_no_1},
    {"removeg1",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_removeg1},
    {"rd:minus",                CC_rdTminus,    too_many_1,    wrong_no_1},
    {"wedget2",                 too_few_2,      CC_wedget2,    wrong_no_2},
    {"wtchk",                   too_few_2,      CC_wtchk,      wrong_no_2},
    {"form",                    CC_form,        too_many_1,    wrong_no_1},
    {"mo=revlexcomp",           too_few_2,      CC_moMrevlexcomp,wrong_no_2},
    {"dd",                      too_few_2,      CC_dd,         wrong_no_2},
    {"noncomperm",              CC_noncomperm,  too_many_1,    wrong_no_1},
    {"horner-rule",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_hornerKrule},
    {"lex_unicode_alphabetic",  CC_lex_unicode_alphabetic,too_many_1,wrong_no_1},
    {"exceeds-order",           too_few_2,      CC_exceedsKorder,wrong_no_2},
    {"minusp:",                 CC_minuspT,     too_many_1,    wrong_no_1},
    {"isimplicit",              CC_isimplicit,  too_many_1,    wrong_no_1},
    {"dipprodin1",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_dipprodin1},
    {"set-ordp",                too_few_2,      CC_setKordp,   wrong_no_2},
    {"scalopp",                 CC_scalopp,     too_many_1,    wrong_no_1},
    {"lengthcdr",               CC_lengthcdr,   too_many_1,    wrong_no_1},
    {"red-ratios2",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_redKratios2},
    {"mo_neg",                  CC_mo_neg,      too_many_1,    wrong_no_1},
    {"b:ordexn",                too_few_2,      CC_bTordexn,   wrong_no_2},
    {"rl_simpl",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_rl_simpl},
    {"qqe_ofsf_simplat1",       too_few_2,      CC_qqe_ofsf_simplat1,wrong_no_2},
    {"rl_negateat",             CC_rl_negateat, too_many_1,    wrong_no_1},
    {"rl_simpbop",              CC_rl_simpbop,  too_many_1,    wrong_no_1},
    {"numeric-content",         CC_numericKcontent,too_many_1, wrong_no_1},
    {"bc2a",                    CC_bc2a,        too_many_1,    wrong_no_1},
    {"*kp2f",                   too_few_2,      CC_Hkp2f,      wrong_no_2},
    {"map__edges",              CC_map__edges,  too_many_1,    wrong_no_1},
    {"assert_typesyntaxp",      CC_assert_typesyntaxp,too_many_1,wrong_no_1},
    {"cali_bc_zero?",           CC_cali_bc_zeroW,too_many_1,   wrong_no_1},
    {"gperm3",                  too_few_2,      CC_gperm3,     wrong_no_2},
    {"general-modular-reciprocal",CC_generalKmodularKreciprocal,too_many_1,wrong_no_1},
    {"difference-mod-p",        too_few_2,      CC_differenceKmodKp,wrong_no_2},
    {"outdefr",                 too_few_2,      CC_outdefr,    wrong_no_2},
    {"ofsf_entry2at1",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_entry2at1},
    {"rl_smmkatl",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_rl_smmkatl},
    {"removeg2",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_removeg2},
    {"ibalp_simpatom",          CC_ibalp_simpatom,too_many_1,  wrong_no_1},
    {"mathml2",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_mathml2},
    {"testredh",                CC_testredh,    too_many_1,    wrong_no_1},
    {"sc_minussq",              CC_sc_minussq,  too_many_1,    wrong_no_1},
    {"vevdif",                  too_few_2,      CC_vevdif,     wrong_no_2},
    {"mksgnsq",                 CC_mksgnsq,     too_many_1,    wrong_no_1},
    {"rnconc",                  too_few_2,      CC_rnconc,     wrong_no_2},
    {"formclis",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_formclis},
    {"evalneq",                 too_few_2,      CC_evalneq,    wrong_no_2},
    {"dp_times_bcmo",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_dp_times_bcmo},
    {"pv_intequiv",             CC_pv_intequiv, too_many_1,    wrong_no_1},
    {"remcomma",                CC_remcomma,    too_many_1,    wrong_no_1},
    {"polynommultiplybyvariable",too_few_2,     CC_polynommultiplybyvariable,wrong_no_2},
    {"sfto_tsqsumf",            CC_sfto_tsqsumf,too_many_1,    wrong_no_1},
    {"quotfail1",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_quotfail1},
    {"ckrn",                    CC_ckrn,        too_many_1,    wrong_no_1},
    {"ibalp_clauselp",          CC_ibalp_clauselp,too_many_1,  wrong_no_1},
    {"cgp_ci",                  CC_cgp_ci,      too_many_1,    wrong_no_1},
    {"c:subs2multf",            too_few_2,      CC_cTsubs2multf,wrong_no_2},
    {"getmat",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_getmat},
    {"lid",                     CC_lid,         too_many_1,    wrong_no_1},
    {"physop-multf",            too_few_2,      CC_physopKmultf,wrong_no_2},
    {"defined_edge",            too_few_2,      CC_defined_edge,wrong_no_2},
    {NULL, (one_args *)"u13", (two_args *)"6363 7733544 6830140", 0}
};

// end of generated code
