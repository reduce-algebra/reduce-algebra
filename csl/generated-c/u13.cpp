
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



// Code for pappend

static LispObject CC_pappend(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0017, v0018;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pappend");
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
    stack[0] = v0001;
    stack[-4] = v0000;
// end of prologue
    v0017 = stack[-4];
    fn = elt(env, 2); // unpkp
    v0017 = (*qfn1(fn))(qenv(fn), v0017);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-6];
    stack[-4] = v0017;
    v0017 = stack[-4];
    v0017 = Llength(nil, v0017);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-6];
    stack[-5] = v0017;
    v0017 = stack[0];
    fn = elt(env, 2); // unpkp
    v0017 = (*qfn1(fn))(qenv(fn), v0017);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-6];
    stack[0] = v0017;
    v0017 = stack[0];
    stack[-3] = v0017;
    v0017 = stack[-3];
    if (v0017 == nil) goto v0020;
    v0017 = stack[-3];
    v0017 = qcar(v0017);
    v0018 = v0017;
    v0017 = stack[-5];
    v0017 = plus2(v0018, v0017);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-6];
    v0017 = ncons(v0017);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-6];
    stack[-1] = v0017;
    stack[-2] = v0017;
    goto v0021;

v0021:
    v0017 = stack[-3];
    v0017 = qcdr(v0017);
    stack[-3] = v0017;
    v0017 = stack[-3];
    if (v0017 == nil) goto v0022;
    stack[0] = stack[-1];
    v0017 = stack[-3];
    v0017 = qcar(v0017);
    v0018 = v0017;
    v0017 = stack[-5];
    v0017 = plus2(v0018, v0017);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-6];
    v0017 = ncons(v0017);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-6];
    v0017 = Lrplacd(nil, stack[0], v0017);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-6];
    v0017 = stack[-1];
    v0017 = qcdr(v0017);
    stack[-1] = v0017;
    goto v0021;

v0022:
    v0017 = stack[-2];
    goto v0023;

v0023:
    stack[0] = v0017;
    v0018 = stack[-4];
    v0017 = stack[0];
    v0017 = Lappend(nil, v0018, v0017);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-6];
    {
        popv(7);
        fn = elt(env, 3); // pkp
        return (*qfn1(fn))(qenv(fn), v0017);
    }

v0020:
    v0017 = qvalue(elt(env, 1)); // nil
    goto v0023;
// error exit handlers
v0019:
    popv(7);
    return nil;
}



// Code for b!:extmult

static LispObject CC_bTextmult(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0047, v0048, v0049;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for b:extmult");
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
    stack[-4] = v0000;
// end of prologue
    stack[-5] = nil;
    goto v0050;

v0050:
    v0047 = stack[-4];
    if (v0047 == nil) goto v0021;
    v0047 = stack[-3];
    v0047 = (v0047 == nil ? lisp_true : nil);
    goto v0023;

v0023:
    if (v0047 == nil) goto v0016;
    v0047 = qvalue(elt(env, 2)); // nil
    stack[0] = v0047;
    goto v0051;

v0051:
    v0047 = stack[-5];
    if (v0047 == nil) { LispObject res = stack[0]; popv(7); return onevalue(res); }
    v0047 = stack[-5];
    v0047 = qcar(v0047);
    v0047 = qcar(v0047);
    stack[-4] = v0047;
    v0047 = stack[-5];
    v0047 = qcar(v0047);
    v0047 = qcdr(v0047);
    stack[-3] = v0047;
    v0047 = stack[-5];
    v0047 = qcdr(v0047);
    stack[-5] = v0047;
    v0047 = stack[-4];
    v0047 = qcar(v0047);
    v0047 = qcar(v0047);
    v0048 = qcar(v0047);
    v0047 = stack[-3];
    v0047 = qcar(v0047);
    v0047 = qcar(v0047);
    fn = elt(env, 3); // b!:ordexn
    v0047 = (*qfn2(fn))(qenv(fn), v0048, v0047);
    nil = C_nil;
    if (exception_pending()) goto v0052;
    env = stack[-6];
    stack[-1] = v0047;
    v0047 = stack[-1];
    if (v0047 == nil) goto v0053;
    v0047 = stack[-4];
    v0047 = qcar(v0047);
    v0048 = qcdr(v0047);
    v0047 = stack[-3];
    v0047 = qcar(v0047);
    v0047 = qcdr(v0047);
    fn = elt(env, 4); // multf
    v0047 = (*qfn2(fn))(qenv(fn), v0048, v0047);
    nil = C_nil;
    if (exception_pending()) goto v0052;
    env = stack[-6];
    v0048 = v0047;
    v0047 = stack[-1];
    v0047 = qcar(v0047);
    if (v0047 == nil) goto v0054;
    v0047 = v0048;
    fn = elt(env, 5); // negf
    v0047 = (*qfn1(fn))(qenv(fn), v0047);
    nil = C_nil;
    if (exception_pending()) goto v0052;
    env = stack[-6];
    v0048 = v0047;
    goto v0054;

v0054:
    v0047 = stack[-1];
    stack[-2] = qcdr(v0047);
    stack[-1] = v0048;
    v0047 = stack[-4];
    v0048 = qcdr(v0047);
    v0047 = stack[-3];
    v0047 = CC_bTextmult(env, v0048, v0047);
    nil = C_nil;
    if (exception_pending()) goto v0052;
    env = stack[-6];
    fn = elt(env, 6); // b!:extadd
    v0047 = (*qfn2(fn))(qenv(fn), stack[0], v0047);
    nil = C_nil;
    if (exception_pending()) goto v0052;
    env = stack[-6];
    v0047 = acons(stack[-2], stack[-1], v0047);
    nil = C_nil;
    if (exception_pending()) goto v0052;
    env = stack[-6];
    stack[0] = v0047;
    goto v0051;

v0053:
    v0047 = stack[-4];
    v0048 = qcdr(v0047);
    v0047 = stack[-3];
    v0048 = CC_bTextmult(env, v0048, v0047);
    nil = C_nil;
    if (exception_pending()) goto v0052;
    env = stack[-6];
    v0047 = stack[0];
    fn = elt(env, 6); // b!:extadd
    v0047 = (*qfn2(fn))(qenv(fn), v0048, v0047);
    nil = C_nil;
    if (exception_pending()) goto v0052;
    env = stack[-6];
    stack[0] = v0047;
    goto v0051;

v0016:
    v0048 = stack[-3];
    v0047 = (LispObject)17; // 1
    if (v0048 == v0047) goto v0055;
    v0049 = stack[-4];
    v0048 = stack[-3];
    v0047 = stack[-5];
    v0047 = acons(v0049, v0048, v0047);
    nil = C_nil;
    if (exception_pending()) goto v0052;
    env = stack[-6];
    stack[-5] = v0047;
    v0047 = stack[-4];
    v0047 = qcdr(v0047);
    if (v0047 == nil) goto v0056;
    v0047 = stack[-4];
    v0047 = qcar(v0047);
    v0047 = ncons(v0047);
    nil = C_nil;
    if (exception_pending()) goto v0052;
    env = stack[-6];
    stack[-4] = v0047;
    goto v0056;

v0056:
    v0047 = stack[-3];
    v0047 = qcdr(v0047);
    stack[-3] = v0047;
    goto v0050;

v0055:
    v0047 = stack[-4];
    stack[0] = v0047;
    goto v0051;

v0021:
    v0047 = qvalue(elt(env, 1)); // t
    goto v0023;
// error exit handlers
v0052:
    popv(7);
    return nil;
}



// Code for invbf

static LispObject CC_invbf(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0012, v0004, v0023;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for invbf");
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
    v0012 = v0000;
// end of prologue
    v0023 = qvalue(elt(env, 1)); // bfone!*
    v0004 = v0012;
    v0012 = qvalue(elt(env, 2)); // !:bprec!:
    fn = elt(env, 3); // divide!:
    v0012 = (*qfnn(fn))(qenv(fn), 3, v0023, v0004, v0012);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 4); // normbf
        return (*qfn1(fn))(qenv(fn), v0012);
    }
// error exit handlers
v0021:
    popv(1);
    return nil;
}



// Code for multd!*

static LispObject CC_multdH(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0060, v0055, v0061, v0016;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for multd*");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0061 = v0001;
    v0016 = v0000;
// end of prologue
    v0055 = v0016;
    v0060 = (LispObject)17; // 1
    if (v0055 == v0060) return onevalue(v0061);
    v0060 = v0016;
    v0055 = v0061;
    {
        fn = elt(env, 1); // multd
        return (*qfn2(fn))(qenv(fn), v0060, v0055);
    }
}



// Code for rl_ordatp

static LispObject CC_rl_ordatp(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0063, v0064;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rl_ordatp");
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
    v0063 = v0001;
    v0064 = v0000;
// end of prologue
    stack[0] = qvalue(elt(env, 1)); // rl_ordatp!*
    v0063 = list2(v0064, v0063);
    nil = C_nil;
    if (exception_pending()) goto v0020;
    env = stack[-1];
    {
        LispObject v0065 = stack[0];
        popv(2);
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(qenv(fn), v0065, v0063);
    }
// error exit handlers
v0020:
    popv(2);
    return nil;
}



// Code for matrixrowrd

static LispObject CC_matrixrowrd(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0065, v0058;
    LispObject fn;
    argcheck(nargs, 0, "matrixrowrd");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for matrixrowrd");
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
    v0065 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-1];
    v0058 = v0065;
    v0065 = v0058;
    if (v0065 == nil) goto v0067;
    stack[0] = v0058;
    v0065 = CC_matrixrowrd(env, 0);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    {
        LispObject v0055 = stack[0];
        popv(2);
        return cons(v0055, v0065);
    }

v0067:
    v0065 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0065); }
// error exit handlers
v0060:
    popv(2);
    return nil;
}



// Code for bind

static LispObject CC_bind(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0065, v0058;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for bind");
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
    push2(nil, nil);
// copy arguments values to proper place
    v0058 = v0001;
    v0065 = v0000;
// end of prologue
    stack[-1] = v0065;
    stack[0] = elt(env, 1); // binding
    if (!symbolp(v0065)) v0065 = nil;
    else { v0065 = qfastgets(v0065);
           if (v0065 != nil) { v0065 = elt(v0065, 13); // binding
#ifdef RECORD_GET
             if (v0065 != SPID_NOPROP)
                record_get(elt(fastget_names, 13), 1);
             else record_get(elt(fastget_names, 13), 0),
                v0065 = nil; }
           else record_get(elt(fastget_names, 13), 0); }
#else
             if (v0065 == SPID_NOPROP) v0065 = nil; }}
#endif
    v0065 = cons(v0058, v0065);
    nil = C_nil;
    if (exception_pending()) goto v0055;
    {
        LispObject v0061 = stack[-1];
        LispObject v0016 = stack[0];
        popv(2);
        return Lputprop(nil, 3, v0061, v0016, v0065);
    }
// error exit handlers
v0055:
    popv(2);
    return nil;
}



// Code for greaterp!:

static LispObject CC_greaterpT(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0099, v0100, v0101;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for greaterp:");
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
    stack[0] = v0001;
    v0101 = v0000;
// end of prologue
    v0099 = v0101;
    v0099 = qcdr(v0099);
    v0100 = qcar(v0099);
    v0099 = (LispObject)1; // 0
    if (v0100 == v0099) goto v0021;
    v0099 = stack[0];
    v0099 = qcdr(v0099);
    v0100 = qcar(v0099);
    v0099 = (LispObject)1; // 0
    if (v0100 == v0099) goto v0102;
    v0099 = v0101;
    v0099 = qcdr(v0099);
    v0100 = qcdr(v0099);
    v0099 = stack[0];
    v0099 = qcdr(v0099);
    v0099 = qcdr(v0099);
    if (equal(v0100, v0099)) goto v0103;
    v0099 = v0101;
    fn = elt(env, 2); // normbf
    stack[-1] = (*qfn1(fn))(qenv(fn), v0099);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    env = stack[-5];
    v0099 = stack[0];
    fn = elt(env, 2); // normbf
    v0099 = (*qfn1(fn))(qenv(fn), v0099);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    env = stack[-5];
    stack[0] = v0099;
    v0099 = stack[-1];
    v0099 = qcdr(v0099);
    v0100 = qcdr(v0099);
    v0099 = stack[0];
    v0099 = qcdr(v0099);
    v0099 = qcdr(v0099);
    v0101 = difference2(v0100, v0099);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    env = stack[-5];
    v0099 = stack[-1];
    v0099 = qcdr(v0099);
    v0100 = qcar(v0099);
    v0099 = stack[0];
    v0099 = qcdr(v0099);
    v0099 = qcar(v0099);
    stack[-4] = v0101;
    stack[-3] = v0100;
    stack[-2] = v0099;
    v0100 = stack[-4];
    v0099 = (LispObject)1; // 0
    if (v0100 == v0099) goto v0105;
    v0100 = (LispObject)33; // 2
    v0099 = qvalue(elt(env, 1)); // !:bprec!:
    v0099 = times2(v0100, v0099);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    env = stack[-5];
    stack[-1] = v0099;
    v0100 = stack[-4];
    v0099 = stack[-1];
    v0099 = (LispObject)greaterp2(v0100, v0099);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    v0099 = v0099 ? lisp_true : nil;
    env = stack[-5];
    if (v0099 == nil) goto v0106;
    v0100 = stack[-3];
    v0099 = (LispObject)1; // 0
        popv(6);
        return Lgreaterp(nil, v0100, v0099);

v0106:
    stack[0] = stack[-4];
    v0099 = stack[-1];
    v0099 = negate(v0099);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    env = stack[-5];
    v0099 = (LispObject)lessp2(stack[0], v0099);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    v0099 = v0099 ? lisp_true : nil;
    env = stack[-5];
    if (v0099 == nil) goto v0107;
    v0100 = stack[-2];
    v0099 = (LispObject)1; // 0
        popv(6);
        return Llessp(nil, v0100, v0099);

v0107:
    v0100 = stack[-4];
    v0099 = (LispObject)1; // 0
    v0099 = (LispObject)greaterp2(v0100, v0099);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    v0099 = v0099 ? lisp_true : nil;
    env = stack[-5];
    if (v0099 == nil) goto v0108;
    v0100 = stack[-3];
    v0099 = stack[-4];
    fn = elt(env, 3); // ashift
    v0100 = (*qfn2(fn))(qenv(fn), v0100, v0099);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    v0099 = stack[-2];
        popv(6);
        return Lgreaterp(nil, v0100, v0099);

v0108:
    stack[0] = stack[-3];
    stack[-1] = stack[-2];
    v0099 = stack[-4];
    v0099 = negate(v0099);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    env = stack[-5];
    fn = elt(env, 3); // ashift
    v0099 = (*qfn2(fn))(qenv(fn), stack[-1], v0099);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    {
        LispObject v0109 = stack[0];
        popv(6);
        return Lgreaterp(nil, v0109, v0099);
    }

v0105:
    v0100 = stack[-3];
    v0099 = stack[-2];
        popv(6);
        return Lgreaterp(nil, v0100, v0099);

v0103:
    v0099 = v0101;
    v0099 = qcdr(v0099);
    v0100 = qcar(v0099);
    v0099 = stack[0];
    v0099 = qcdr(v0099);
    v0099 = qcar(v0099);
        popv(6);
        return Lgreaterp(nil, v0100, v0099);

v0102:
    v0099 = v0101;
    v0099 = qcdr(v0099);
    v0100 = qcar(v0099);
    v0099 = (LispObject)1; // 0
        popv(6);
        return Lgreaterp(nil, v0100, v0099);

v0021:
    v0099 = stack[0];
    v0099 = qcdr(v0099);
    v0100 = qcar(v0099);
    v0099 = (LispObject)1; // 0
        popv(6);
        return Llessp(nil, v0100, v0099);
// error exit handlers
v0104:
    popv(6);
    return nil;
}



// Code for noncommuting

static LispObject CC_noncommuting(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0114, v0093, v0094, v0115;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for noncommuting");
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
    v0093 = v0001;
    v0094 = v0000;
// end of prologue
    v0115 = nil;
    v0114 = v0094;
    if (!consp(v0114)) goto v0050;
    v0114 = v0094;
    v0114 = qcar(v0114);
    goto v0067;

v0067:
    v0094 = v0114;
    v0114 = v0093;
    if (!consp(v0114)) goto v0064;
    v0114 = v0093;
    v0114 = qcar(v0114);
    goto v0063;

v0063:
    v0093 = v0114;
    v0114 = v0094;
    if (!consp(v0114)) goto v0046;
    v0114 = v0094;
    v0114 = qcar(v0114);
    if (!symbolp(v0114)) v0114 = nil;
    else { v0114 = qfastgets(v0114);
           if (v0114 != nil) { v0114 = elt(v0114, 0); // noncom
#ifdef RECORD_GET
             if (v0114 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v0114 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v0114 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v0114 == SPID_NOPROP) v0114 = nil; else v0114 = lisp_true; }}
#endif
    goto v0045;

v0045:
    if (v0114 == nil) return onevalue(v0115);
    v0114 = v0093;
    if (!consp(v0114)) goto v0116;
    v0114 = v0093;
    v0114 = qcar(v0114);
    if (!symbolp(v0114)) v0114 = nil;
    else { v0114 = qfastgets(v0114);
           if (v0114 != nil) { v0114 = elt(v0114, 0); // noncom
#ifdef RECORD_GET
             if (v0114 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v0114 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v0114 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v0114 == SPID_NOPROP) v0114 = nil; else v0114 = lisp_true; }}
#endif
    goto v0043;

v0043:
    if (v0114 == nil) return onevalue(v0115);
    v0114 = elt(env, 2); // noncommutes
    v0114 = get(v0094, v0114);
    v0114 = Lmember(nil, v0093, v0114);
    v0115 = v0114;
    return onevalue(v0115);

v0116:
    v0114 = v0093;
    if (!symbolp(v0114)) v0114 = nil;
    else { v0114 = qfastgets(v0114);
           if (v0114 != nil) { v0114 = elt(v0114, 0); // noncom
#ifdef RECORD_GET
             if (v0114 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v0114 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v0114 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v0114 == SPID_NOPROP) v0114 = nil; else v0114 = lisp_true; }}
#endif
    goto v0043;

v0046:
    v0114 = v0094;
    if (!symbolp(v0114)) v0114 = nil;
    else { v0114 = qfastgets(v0114);
           if (v0114 != nil) { v0114 = elt(v0114, 0); // noncom
#ifdef RECORD_GET
             if (v0114 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v0114 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v0114 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v0114 == SPID_NOPROP) v0114 = nil; else v0114 = lisp_true; }}
#endif
    goto v0045;

v0064:
    v0114 = v0093;
    goto v0063;

v0050:
    v0114 = v0094;
    goto v0067;
}



// Code for formprogn

static LispObject CC_formprogn(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0058, v0059, v0060;
    LispObject fn;
    LispObject v0117, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "formprogn");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0117 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for formprogn");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0117,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0117);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0058 = v0117;
    v0059 = v0001;
    v0060 = v0000;
// end of prologue
    stack[0] = elt(env, 1); // progn
    v0060 = qcdr(v0060);
    fn = elt(env, 2); // formclis
    v0058 = (*qfnn(fn))(qenv(fn), 3, v0060, v0059, v0058);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    {
        LispObject v0016 = stack[0];
        popv(1);
        return cons(v0016, v0058);
    }
// error exit handlers
v0061:
    popv(1);
    return nil;
}



// Code for flatsizec

static LispObject CC_flatsizec(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0016;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for flatsizec");
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
    v0016 = stack[0];
    if (v0016 == nil) goto v0037;
    v0016 = stack[0];
    if (!consp(v0016)) goto v0067;
    v0016 = stack[0];
    v0016 = qcar(v0016);
    stack[-1] = CC_flatsizec(env, v0016);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-2];
    v0016 = stack[0];
    v0016 = qcdr(v0016);
    v0016 = CC_flatsizec(env, v0016);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-2];
    v0016 = add1(v0016);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    {
        LispObject v0112 = stack[-1];
        popv(3);
        return plus2(v0112, v0016);
    }

v0067:
    v0016 = stack[0];
    {
        popv(3);
        fn = elt(env, 1); // widelengthc
        return (*qfn1(fn))(qenv(fn), v0016);
    }

v0037:
    v0016 = (LispObject)1; // 0
    { popv(3); return onevalue(v0016); }
// error exit handlers
v0118:
    popv(3);
    return nil;
}



// Code for crprcd2

static LispObject CC_crprcd2(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0067;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for crprcd2");
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
    v0067 = stack[-1];
    fn = elt(env, 2); // crprcd
    v0067 = (*qfn1(fn))(qenv(fn), v0067);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[-2];
    stack[-1] = v0067;
    v0067 = stack[0];
    fn = elt(env, 2); // crprcd
    v0067 = (*qfn1(fn))(qenv(fn), v0067);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[-2];
    qvalue(elt(env, 1)) = v0067; // yy!!
    { LispObject res = stack[-1]; popv(3); return onevalue(res); }
// error exit handlers
v0057:
    popv(3);
    return nil;
}



// Code for updtemplate

static LispObject CC_updtemplate(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0030, v0129, v0130;
    LispObject fn;
    LispObject v0117, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "updtemplate");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0117 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for updtemplate");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0117,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0117);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[-5] = v0117;
    v0030 = v0001;
    stack[-6] = v0000;
// end of prologue
    stack[-4] = v0030;
    v0030 = stack[-4];
    if (v0030 == nil) goto v0021;
    v0030 = stack[-4];
    v0030 = qcar(v0030);
    stack[0] = v0030;
    v0129 = stack[-6];
    v0030 = stack[0];
    v0129 = Lsubla(nil, v0129, v0030);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-8];
    stack[-7] = v0129;
    v0030 = stack[0];
    if (equal(v0129, v0030)) goto v0061;
    v0129 = stack[-7];
    v0030 = stack[-5];
    fn = elt(env, 2); // reval!-without
    v0129 = (*qfn2(fn))(qenv(fn), v0129, v0030);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-8];
    v0130 = v0129;
    v0030 = stack[-7];
    if (equal(v0129, v0030)) goto v0103;
    v0030 = v0130;
    goto v0055;

v0055:
    v0030 = ncons(v0030);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-8];
    stack[-2] = v0030;
    stack[-3] = v0030;
    goto v0013;

v0013:
    v0030 = stack[-4];
    v0030 = qcdr(v0030);
    stack[-4] = v0030;
    v0030 = stack[-4];
    if (v0030 == nil) { LispObject res = stack[-3]; popv(9); return onevalue(res); }
    stack[-1] = stack[-2];
    v0030 = stack[-4];
    v0030 = qcar(v0030);
    stack[0] = v0030;
    v0129 = stack[-6];
    v0030 = stack[0];
    v0129 = Lsubla(nil, v0129, v0030);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-8];
    stack[-7] = v0129;
    v0030 = stack[0];
    if (equal(v0129, v0030)) goto v0132;
    v0129 = stack[-7];
    v0030 = stack[-5];
    fn = elt(env, 2); // reval!-without
    v0129 = (*qfn2(fn))(qenv(fn), v0129, v0030);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-8];
    v0130 = v0129;
    v0030 = stack[-7];
    if (equal(v0129, v0030)) goto v0087;
    v0030 = v0130;
    goto v0040;

v0040:
    v0030 = ncons(v0030);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-8];
    v0030 = Lrplacd(nil, stack[-1], v0030);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-8];
    v0030 = stack[-2];
    v0030 = qcdr(v0030);
    stack[-2] = v0030;
    goto v0013;

v0087:
    v0030 = stack[-7];
    goto v0040;

v0132:
    v0030 = stack[0];
    goto v0040;

v0103:
    v0030 = stack[-7];
    goto v0055;

v0061:
    v0030 = stack[0];
    goto v0055;

v0021:
    v0030 = qvalue(elt(env, 1)); // nil
    { popv(9); return onevalue(v0030); }
// error exit handlers
v0131:
    popv(9);
    return nil;
}



// Code for qqe_simplterm

static LispObject CC_qqe_simplterm(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0133, v0010, v0097;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qqe_simplterm");
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
    v0133 = stack[0];
    if (!consp(v0133)) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    v0133 = stack[0];
    fn = elt(env, 4); // qqe_op
    v0133 = (*qfn1(fn))(qenv(fn), v0133);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-1];
    v0097 = v0133;
    v0010 = v0097;
    v0133 = elt(env, 1); // (ltail rtail)
    v0133 = Lmemq(nil, v0010, v0133);
    if (v0133 == nil) goto v0134;
    v0133 = stack[0];
    {
        popv(2);
        fn = elt(env, 5); // qqe_simplterm!-tail
        return (*qfn1(fn))(qenv(fn), v0133);
    }

v0134:
    v0010 = v0097;
    v0133 = elt(env, 2); // (lhead rhead)
    v0133 = Lmemq(nil, v0010, v0133);
    if (v0133 == nil) goto v0022;
    v0133 = stack[0];
    {
        popv(2);
        fn = elt(env, 6); // qqe_simplterm!-head
        return (*qfn1(fn))(qenv(fn), v0133);
    }

v0022:
    v0010 = v0097;
    v0133 = elt(env, 3); // (ladd radd)
    v0133 = Lmemq(nil, v0010, v0133);
    if (v0133 == nil) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    v0133 = stack[0];
    {
        popv(2);
        fn = elt(env, 7); // qqe_simplterm!-add
        return (*qfn1(fn))(qenv(fn), v0133);
    }
// error exit handlers
v0126:
    popv(2);
    return nil;
}



// Code for setunion

static LispObject CC_setunion(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0135, v0128, v0022;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for setunion");
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
    v0128 = v0000;
// end of prologue

v0036:
    v0135 = stack[0];
    if (v0135 == nil) { popv(3); return onevalue(v0128); }
    v0135 = stack[0];
    v0022 = qcar(v0135);
    v0135 = v0128;
    v0135 = Lmember(nil, v0022, v0135);
    if (v0135 == nil) goto v0016;
    v0135 = stack[0];
    v0135 = qcdr(v0135);
    stack[0] = v0135;
    goto v0036;

v0016:
    stack[-1] = v0128;
    v0135 = stack[0];
    v0135 = qcar(v0135);
    v0135 = ncons(v0135);
    nil = C_nil;
    if (exception_pending()) goto v0044;
    env = stack[-2];
    v0135 = Lappend(nil, stack[-1], v0135);
    nil = C_nil;
    if (exception_pending()) goto v0044;
    env = stack[-2];
    v0128 = v0135;
    v0135 = stack[0];
    v0135 = qcdr(v0135);
    stack[0] = v0135;
    goto v0036;
// error exit handlers
v0044:
    popv(3);
    return nil;
}



// Code for ibalp_clausep

static LispObject CC_ibalp_clausep(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0045, v0046;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_clausep");
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
    v0045 = stack[0];
    fn = elt(env, 3); // ibalp_litp
    v0045 = (*qfn1(fn))(qenv(fn), v0045);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    env = stack[-1];
    if (!(v0045 == nil)) { popv(2); return onevalue(v0045); }
    v0045 = stack[0];
    if (!consp(v0045)) goto v0063;
    v0045 = stack[0];
    v0045 = qcar(v0045);
    v0046 = v0045;
    goto v0013;

v0013:
    v0045 = elt(env, 1); // or
    if (v0046 == v0045) goto v0050;
    v0045 = qvalue(elt(env, 2)); // nil
    { popv(2); return onevalue(v0045); }

v0050:
    v0045 = stack[0];
    v0045 = qcdr(v0045);
    {
        popv(2);
        fn = elt(env, 4); // ibalp_litlp
        return (*qfn1(fn))(qenv(fn), v0045);
    }

v0063:
    v0045 = stack[0];
    v0046 = v0045;
    goto v0013;
// error exit handlers
v0015:
    popv(2);
    return nil;
}



// Code for opmtch

static LispObject CC_opmtch(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0081, v0143, v0144;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for opmtch");
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
    stack[-5] = v0000;
// end of prologue
    stack[-6] = nil;
    v0081 = stack[-5];
    v0081 = qcar(v0081);
    if (!symbolp(v0081)) v0081 = nil;
    else { v0081 = qfastgets(v0081);
           if (v0081 != nil) { v0081 = elt(v0081, 9); // opmtch
#ifdef RECORD_GET
             if (v0081 != SPID_NOPROP)
                record_get(elt(fastget_names, 9), 1);
             else record_get(elt(fastget_names, 9), 0),
                v0081 = nil; }
           else record_get(elt(fastget_names, 9), 0); }
#else
             if (v0081 == SPID_NOPROP) v0081 = nil; }}
#endif
    stack[-4] = v0081;
    if (v0081 == nil) goto v0013;
    v0081 = qvalue(elt(env, 2)); // subfg!*
    if (v0081 == nil) goto v0064;
    v0081 = qvalue(elt(env, 3)); // !*uncached
    if (v0081 == nil) goto v0145;
    v0081 = qvalue(elt(env, 1)); // nil
    goto v0055;

v0055:
    if (v0081 == nil) goto v0011;
    v0081 = stack[-6];
    v0081 = qcdr(v0081);
    { popv(8); return onevalue(v0081); }

v0011:
    v0081 = stack[-5];
    v0081 = qcdr(v0081);
    stack[-3] = v0081;
    v0081 = stack[-3];
    if (v0081 == nil) goto v0133;
    v0081 = stack[-3];
    v0081 = qcar(v0081);
    fn = elt(env, 5); // emtch
    v0081 = (*qfn1(fn))(qenv(fn), v0081);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-7];
    v0081 = ncons(v0081);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-7];
    stack[-1] = v0081;
    stack[-2] = v0081;
    goto v0146;

v0146:
    v0081 = stack[-3];
    v0081 = qcdr(v0081);
    stack[-3] = v0081;
    v0081 = stack[-3];
    if (v0081 == nil) goto v0096;
    stack[0] = stack[-1];
    v0081 = stack[-3];
    v0081 = qcar(v0081);
    fn = elt(env, 5); // emtch
    v0081 = (*qfn1(fn))(qenv(fn), v0081);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-7];
    v0081 = ncons(v0081);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-7];
    v0081 = Lrplacd(nil, stack[0], v0081);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-7];
    v0081 = stack[-1];
    v0081 = qcdr(v0081);
    stack[-1] = v0081;
    goto v0146;

v0096:
    v0081 = stack[-2];
    goto v0056;

v0056:
    stack[0] = v0081;
    goto v0067;

v0067:
    v0081 = stack[-4];
    if (v0081 == nil) goto v0062;
    v0144 = stack[0];
    v0081 = stack[-4];
    v0081 = qcar(v0081);
    v0143 = qcar(v0081);
    v0081 = stack[-5];
    v0081 = qcar(v0081);
    fn = elt(env, 6); // mcharg
    v0081 = (*qfnn(fn))(qenv(fn), 3, v0144, v0143, v0081);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-7];
    stack[-1] = v0081;
    goto v0050;

v0050:
    v0081 = stack[-1];
    if (v0081 == nil) goto v0147;
    v0081 = stack[-1];
    v0143 = qcar(v0081);
    v0081 = stack[-4];
    v0081 = qcar(v0081);
    v0081 = qcdr(v0081);
    v0081 = qcar(v0081);
    v0081 = qcdr(v0081);
    v0081 = Lsubla(nil, v0143, v0081);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-7];
    fn = elt(env, 7); // lispeval
    v0081 = (*qfn1(fn))(qenv(fn), v0081);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-7];
    if (v0081 == nil) goto v0148;
    v0081 = stack[-1];
    v0143 = qcar(v0081);
    v0081 = stack[-4];
    v0081 = qcar(v0081);
    v0081 = qcdr(v0081);
    v0081 = qcdr(v0081);
    v0081 = qcar(v0081);
    v0081 = Lsubla(nil, v0143, v0081);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-7];
    stack[-6] = v0081;
    goto v0062;

v0062:
    v0081 = qvalue(elt(env, 3)); // !*uncached
    if (!(v0081 == nil)) { LispObject res = stack[-6]; popv(8); return onevalue(res); }
    stack[0] = qvalue(elt(env, 4)); // alglist!*
    v0144 = stack[-5];
    v0143 = stack[-6];
    v0081 = qvalue(elt(env, 4)); // alglist!*
    v0081 = qcdr(v0081);
    v0081 = acons(v0144, v0143, v0081);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-7];
    v0081 = Lrplacd(nil, stack[0], v0081);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    { LispObject res = stack[-6]; popv(8); return onevalue(res); }

v0148:
    v0081 = stack[-1];
    v0081 = qcdr(v0081);
    stack[-1] = v0081;
    goto v0050;

v0147:
    v0081 = stack[-4];
    v0081 = qcdr(v0081);
    stack[-4] = v0081;
    goto v0067;

v0133:
    v0081 = qvalue(elt(env, 1)); // nil
    goto v0056;

v0145:
    v0143 = stack[-5];
    v0081 = qvalue(elt(env, 4)); // alglist!*
    v0081 = qcdr(v0081);
    v0081 = Lassoc(nil, v0143, v0081);
    stack[-6] = v0081;
    goto v0055;

v0064:
    v0081 = qvalue(elt(env, 1)); // nil
    { popv(8); return onevalue(v0081); }

v0013:
    v0081 = qvalue(elt(env, 1)); // nil
    { popv(8); return onevalue(v0081); }
// error exit handlers
v0080:
    popv(8);
    return nil;
}



// Code for termordp!!

static LispObject CC_termordpB(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0061, v0016, v0134;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for termordp!");
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
    v0134 = v0000;
// end of prologue
    v0016 = v0134;
    v0061 = stack[0];
    if (equal(v0016, v0061)) goto v0059;
    v0061 = v0134;
    fn = elt(env, 2); // guesspftype
    stack[-1] = (*qfn1(fn))(qenv(fn), v0061);
    nil = C_nil;
    if (exception_pending()) goto v0112;
    env = stack[-2];
    v0061 = stack[0];
    fn = elt(env, 2); // guesspftype
    v0061 = (*qfn1(fn))(qenv(fn), v0061);
    nil = C_nil;
    if (exception_pending()) goto v0112;
    env = stack[-2];
    {
        LispObject v0045 = stack[-1];
        popv(3);
        fn = elt(env, 3); // termordp
        return (*qfn2(fn))(qenv(fn), v0045, v0061);
    }

v0059:
    v0061 = qvalue(elt(env, 1)); // nil
    { popv(3); return onevalue(v0061); }
// error exit handlers
v0112:
    popv(3);
    return nil;
}



// Code for !*sqprint

static LispObject CC_Hsqprint(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0026;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *sqprint");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0026 = v0000;
// end of prologue
    v0026 = qcdr(v0026);
    v0026 = qcar(v0026);
    {
        fn = elt(env, 1); // sqprint
        return (*qfn1(fn))(qenv(fn), v0026);
    }
}



// Code for all_edge

static LispObject CC_all_edge(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0128, v0022, v0127;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for all_edge");
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
    v0127 = nil;
    goto v0026;

v0026:
    v0128 = stack[0];
    if (v0128 == nil) goto v0050;
    v0022 = stack[-1];
    v0128 = stack[0];
    v0128 = qcar(v0128);
    v0128 = qcar(v0128);
    if (v0022 == v0128) goto v0055;
    v0128 = stack[0];
    v0128 = qcdr(v0128);
    stack[0] = v0128;
    goto v0026;

v0055:
    v0128 = stack[0];
    v0128 = qcar(v0128);
    v0022 = v0127;
    v0128 = cons(v0128, v0022);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-2];
    v0127 = v0128;
    v0128 = stack[0];
    v0128 = qcdr(v0128);
    stack[0] = v0128;
    goto v0026;

v0050:
    v0128 = v0127;
    {
        popv(3);
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(qenv(fn), v0128);
    }
// error exit handlers
v0042:
    popv(3);
    return nil;
}



// Code for simp!-sign

static LispObject CC_simpKsign(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0026;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for simp-sign");
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
    v0026 = v0000;
// end of prologue
    v0026 = qcar(v0026);
    fn = elt(env, 1); // reval
    v0026 = (*qfn1(fn))(qenv(fn), v0026);
    nil = C_nil;
    if (exception_pending()) goto v0113;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); // simp!-sign1
        return (*qfn1(fn))(qenv(fn), v0026);
    }
// error exit handlers
v0113:
    popv(1);
    return nil;
}



// Code for procstat

static LispObject CC_procstat(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0009;
    LispObject fn;
    argcheck(nargs, 0, "procstat");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for procstat");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// end of prologue
    v0009 = qvalue(elt(env, 1)); // nil
    {
        fn = elt(env, 2); // procstat1
        return (*qfn1(fn))(qenv(fn), v0009);
    }
}



// Code for gperm0

static LispObject CC_gperm0(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0065, v0058;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gperm0");
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
    v0058 = v0000;
// end of prologue
    v0065 = v0058;
    if (v0065 == nil) goto v0037;
    v0065 = v0058;
    stack[0] = qcdr(v0065);
    v0065 = v0058;
    v0065 = qcar(v0065);
    v0065 = ncons(v0065);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-1];
    v0065 = ncons(v0065);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-1];
    {
        LispObject v0055 = stack[0];
        popv(2);
        fn = elt(env, 2); // gperm3
        return (*qfn2(fn))(qenv(fn), v0055, v0065);
    }

v0037:
    v0065 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0065); }
// error exit handlers
v0060:
    popv(2);
    return nil;
}



// Code for ord2

static LispObject CC_ord2(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0045, v0046;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ord2");
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
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0001;
    stack[-1] = v0000;
// end of prologue
    v0046 = stack[-1];
    v0045 = stack[0];
    fn = elt(env, 1); // ordp
    v0045 = (*qfn2(fn))(qenv(fn), v0046, v0045);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    if (v0045 == nil) goto v0055;
    v0046 = stack[-1];
    v0045 = stack[0];
    popv(2);
    return list2(v0046, v0045);

v0055:
    v0046 = stack[0];
    v0045 = stack[-1];
    popv(2);
    return list2(v0046, v0045);
// error exit handlers
v0142:
    popv(2);
    return nil;
}



// Code for mri_pasf2mriat

static LispObject CC_mri_pasf2mriat(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0021, v0063, v0064;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mri_pasf2mriat");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0021 = v0001;
    v0063 = v0000;
// end of prologue
    v0064 = v0063;
    v0064 = qcar(v0064);
    v0063 = qcdr(v0063);
    v0063 = qcar(v0063);
    {
        fn = elt(env, 1); // mri_0mk2
        return (*qfnn(fn))(qenv(fn), 3, v0064, v0063, v0021);
    }
}



// Code for qqe_id!-nyt!-branchq

static LispObject CC_qqe_idKnytKbranchq(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0060;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qqe_id-nyt-branchq");
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
    v0060 = stack[0];
    if (!consp(v0060)) goto v0037;
    v0060 = stack[0];
    v0060 = qcar(v0060);
    fn = elt(env, 1); // qqe_qopaddp
    v0060 = (*qfn1(fn))(qenv(fn), v0060);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-1];
    if (!(v0060 == nil)) { popv(2); return onevalue(v0060); }
    v0060 = stack[0];
    v0060 = qcar(v0060);
    {
        popv(2);
        fn = elt(env, 2); // qqe_qoptailp
        return (*qfn1(fn))(qenv(fn), v0060);
    }

v0037:
    v0060 = stack[0];
    fn = elt(env, 3); // qqe_qtidp
    v0060 = (*qfn1(fn))(qenv(fn), v0060);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-1];
    if (!(v0060 == nil)) { popv(2); return onevalue(v0060); }
    v0060 = stack[0];
    {
        popv(2);
        fn = elt(env, 4); // qqe_nytidp
        return (*qfn1(fn))(qenv(fn), v0060);
    }
// error exit handlers
v0061:
    popv(2);
    return nil;
}



// Code for ibalp_redclause

static LispObject CC_ibalp_redclause(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0135, v0128;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_redclause");
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
    stack[0] = nil;
    v0135 = stack[-1];
    v0135 = qcar(v0135);
    stack[-2] = v0135;
    goto v0062;

v0062:
    v0135 = stack[-2];
    if (v0135 == nil) { LispObject res = stack[0]; popv(4); return onevalue(res); }
    v0135 = stack[0];
    if (!(v0135 == nil)) { LispObject res = stack[0]; popv(4); return onevalue(res); }
    v0135 = stack[-2];
    v0128 = qcar(v0135);
    v0135 = stack[-1];
    v0135 = qcdr(v0135);
    v0135 = qcar(v0135);
    fn = elt(env, 3); // ibalp_vmember
    v0135 = (*qfn2(fn))(qenv(fn), v0128, v0135);
    nil = C_nil;
    if (exception_pending()) goto v0044;
    env = stack[-3];
    if (v0135 == nil) goto v0020;
    v0135 = qvalue(elt(env, 2)); // t
    stack[0] = v0135;
    goto v0020;

v0020:
    v0135 = stack[-2];
    v0135 = qcdr(v0135);
    stack[-2] = v0135;
    goto v0062;
// error exit handlers
v0044:
    popv(4);
    return nil;
}



// Code for sfto_reorder

static LispObject CC_sfto_reorder(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0012;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sfto_reorder");
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
    v0012 = v0001;
    stack[0] = v0000;
// end of prologue
    v0012 = ncons(v0012);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    env = stack[-2];
    fn = elt(env, 1); // setkorder
    v0012 = (*qfn1(fn))(qenv(fn), v0012);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    env = stack[-2];
    stack[-1] = v0012;
    v0012 = stack[0];
    fn = elt(env, 2); // reorder
    v0012 = (*qfn1(fn))(qenv(fn), v0012);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    env = stack[-2];
    stack[0] = v0012;
    v0012 = stack[-1];
    fn = elt(env, 1); // setkorder
    v0012 = (*qfn1(fn))(qenv(fn), v0012);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    { LispObject res = stack[0]; popv(3); return onevalue(res); }
// error exit handlers
v0021:
    popv(3);
    return nil;
}



// Code for exchk1

static LispObject CC_exchk1(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0166, v0167, v0168, v0169;
    LispObject fn;
    LispObject v0009, v0117, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "exchk1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0117 = va_arg(aa, LispObject);
    v0009 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for exchk1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0009,v0117,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0001,v0117,v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    stack[-1] = v0009;
    stack[-2] = v0117;
    stack[-3] = v0001;
    stack[-4] = v0000;
// end of prologue

v0067:
    v0166 = stack[-4];
    if (v0166 == nil) goto v0020;
    v0166 = stack[-4];
    v0166 = qcar(v0166);
    v0167 = qcar(v0166);
    v0166 = elt(env, 1); // expt
    if (!consp(v0167)) goto v0077;
    v0167 = qcar(v0167);
    if (!(v0167 == v0166)) goto v0077;
    v0168 = elt(env, 2); // times
    v0166 = stack[-4];
    v0166 = qcar(v0166);
    v0167 = qcdr(v0166);
    v0166 = stack[-4];
    v0166 = qcar(v0166);
    v0166 = qcar(v0166);
    v0166 = qcdr(v0166);
    v0166 = qcdr(v0166);
    v0166 = qcar(v0166);
    v0166 = list3(v0168, v0167, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-6];
    fn = elt(env, 3); // simpexpon
    v0166 = (*qfn1(fn))(qenv(fn), v0166);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-6];
    stack[-5] = v0166;
    v0166 = stack[-4];
    v0166 = qcar(v0166);
    v0166 = qcar(v0166);
    v0166 = qcdr(v0166);
    v0166 = qcar(v0166);
    if (is_number(v0166)) goto v0003;
    v0166 = stack[-4];
    v0166 = qcar(v0166);
    v0166 = qcar(v0166);
    v0166 = qcdr(v0166);
    v0167 = qcar(v0166);
    v0166 = stack[-2];
    v0166 = Lassoc(nil, v0167, v0166);
    v0167 = v0166;
    if (v0167 == nil) goto v0049;
    stack[0] = v0166;
    v0167 = stack[-5];
    v0166 = qcdr(v0166);
    fn = elt(env, 4); // addsq
    v0166 = (*qfn2(fn))(qenv(fn), v0167, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-6];
    v0166 = Lrplacd(nil, stack[0], v0166);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-6];
    goto v0171;

v0171:
    v0166 = stack[-4];
    v0169 = qcdr(v0166);
    v0168 = stack[-3];
    v0167 = stack[-2];
    v0166 = stack[-1];
    stack[-4] = v0169;
    stack[-3] = v0168;
    stack[-2] = v0167;
    stack[-1] = v0166;
    goto v0067;

v0049:
    v0166 = stack[-4];
    v0166 = qcar(v0166);
    v0166 = qcar(v0166);
    v0166 = qcdr(v0166);
    v0168 = qcar(v0166);
    v0167 = stack[-5];
    v0166 = stack[-2];
    v0166 = acons(v0168, v0167, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-6];
    stack[-2] = v0166;
    goto v0171;

v0003:
    v0167 = stack[-5];
    v0166 = stack[-1];
    fn = elt(env, 5); // assoc2
    v0166 = (*qfn2(fn))(qenv(fn), v0167, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-6];
    v0167 = v0166;
    if (v0167 == nil) goto v0119;
    stack[0] = v0166;
    v0167 = qcar(v0166);
    v0166 = stack[-4];
    v0166 = qcar(v0166);
    v0166 = qcar(v0166);
    v0166 = qcdr(v0166);
    v0166 = qcar(v0166);
    v0166 = times2(v0167, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-6];
    v0166 = Lrplaca(nil, stack[0], v0166);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-6];
    goto v0171;

v0119:
    v0166 = stack[-4];
    v0166 = qcar(v0166);
    v0166 = qcar(v0166);
    v0166 = qcdr(v0166);
    v0168 = qcar(v0166);
    v0167 = stack[-5];
    v0166 = stack[-1];
    v0166 = acons(v0168, v0167, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-6];
    stack[-1] = v0166;
    goto v0171;

v0077:
    v0166 = stack[-4];
    v0166 = qcar(v0166);
    v0167 = qcdr(v0166);
    v0166 = (LispObject)17; // 1
    if (v0167 == v0166) goto v0172;
    v0166 = stack[-4];
    v0166 = qcdr(v0166);
    stack[-5] = v0166;
    stack[0] = elt(env, 1); // expt
    v0166 = stack[-4];
    v0166 = qcar(v0166);
    v0166 = qcar(v0166);
    fn = elt(env, 6); // sqchk
    v0167 = (*qfn1(fn))(qenv(fn), v0166);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-6];
    v0166 = stack[-4];
    v0166 = qcar(v0166);
    v0166 = qcdr(v0166);
    v0167 = list3(stack[0], v0167, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-6];
    v0166 = stack[-3];
    v0166 = cons(v0167, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-6];
    stack[-3] = v0166;
    v0166 = stack[-5];
    stack[-4] = v0166;
    goto v0067;

v0172:
    v0166 = stack[-4];
    v0166 = qcdr(v0166);
    stack[-5] = v0166;
    v0166 = stack[-4];
    v0166 = qcar(v0166);
    v0166 = qcar(v0166);
    fn = elt(env, 6); // sqchk
    v0167 = (*qfn1(fn))(qenv(fn), v0166);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-6];
    v0166 = stack[-3];
    v0166 = cons(v0167, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-6];
    stack[-3] = v0166;
    v0166 = stack[-5];
    stack[-4] = v0166;
    goto v0067;

v0020:
    v0167 = stack[-1];
    v0166 = stack[-2];
    v0167 = Lappend(nil, v0167, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-6];
    v0166 = stack[-3];
    {
        popv(7);
        fn = elt(env, 7); // exchk2
        return (*qfn2(fn))(qenv(fn), v0167, v0166);
    }
// error exit handlers
v0170:
    popv(7);
    return nil;
}



// Code for find_sub_df

static LispObject CC_find_sub_df(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0112, v0045;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for find_sub_df");
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

v0173:
    v0112 = stack[0];
    if (v0112 == nil) goto v0036;
    v0045 = stack[-1];
    v0112 = stack[0];
    v0112 = qcar(v0112);
    fn = elt(env, 2); // is_sub_df
    v0112 = (*qfn2(fn))(qenv(fn), v0045, v0112);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    env = stack[-2];
    if (!(v0112 == nil)) { popv(3); return onevalue(v0112); }
    v0045 = stack[-1];
    v0112 = stack[0];
    v0112 = qcdr(v0112);
    stack[-1] = v0045;
    stack[0] = v0112;
    goto v0173;

v0036:
    v0112 = qvalue(elt(env, 1)); // nil
    { popv(3); return onevalue(v0112); }
// error exit handlers
v0015:
    popv(3);
    return nil;
}



// Code for mkinds

static LispObject CC_mkinds(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0044, v0042;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mkinds");
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
    v0042 = stack[0];
    v0044 = (LispObject)1; // 0
    if (v0042 == v0044) goto v0036;
    v0042 = stack[-1];
    v0044 = stack[0];
    v0044 = cons(v0042, v0044);
    nil = C_nil;
    if (exception_pending()) goto v0146;
    env = stack[-3];
    stack[-2] = v0044;
    v0044 = stack[0];
    v0044 = sub1(v0044);
    nil = C_nil;
    if (exception_pending()) goto v0146;
    env = stack[-3];
    v0044 = CC_mkinds(env, stack[-1], v0044);
    nil = C_nil;
    if (exception_pending()) goto v0146;
    {
        LispObject v0174 = stack[-2];
        popv(4);
        return cons(v0174, v0044);
    }

v0036:
    v0044 = qvalue(elt(env, 1)); // nil
    { popv(4); return onevalue(v0044); }
// error exit handlers
v0146:
    popv(4);
    return nil;
}



// Code for assert_uninstall_all

static LispObject CC_assert_uninstall_all(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0009;
    LispObject fn;
    argcheck(nargs, 0, "assert_uninstall_all");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for assert_uninstall_all");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// end of prologue
    v0009 = qvalue(elt(env, 1)); // assert_functionl!*
    {
        fn = elt(env, 2); // assert_uninstall
        return (*qfn1(fn))(qenv(fn), v0009);
    }
}



// Code for nzeros

static LispObject CC_nzeros(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0118, v0112;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for nzeros");
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
    goto v0062;

v0062:
    v0112 = stack[0];
    v0118 = (LispObject)1; // 0
    if (v0112 == v0118) goto v0067;
    v0112 = (LispObject)1; // 0
    v0118 = stack[-1];
    v0118 = cons(v0112, v0118);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[-2];
    stack[-1] = v0118;
    v0118 = stack[0];
    v0118 = sub1(v0118);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[-2];
    stack[0] = v0118;
    goto v0062;

v0067:
    v0118 = stack[-1];
    {
        popv(3);
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(qenv(fn), v0118);
    }
// error exit handlers
v0014:
    popv(3);
    return nil;
}



// Code for subsetp

static LispObject CC_subsetp(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0015, v0142, v0102, v0135;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for subsetp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0142 = v0001;
    v0102 = v0000;
// end of prologue

v0173:
    v0015 = v0102;
    if (v0015 == nil) goto v0036;
    v0015 = v0102;
    v0135 = qcar(v0015);
    v0015 = v0142;
    v0015 = Lmember(nil, v0135, v0015);
    if (v0015 == nil) goto v0013;
    v0015 = v0102;
    v0102 = qcdr(v0015);
    v0015 = v0142;
    v0142 = v0015;
    goto v0173;

v0013:
    v0015 = qvalue(elt(env, 2)); // nil
    return onevalue(v0015);

v0036:
    v0015 = qvalue(elt(env, 1)); // t
    return onevalue(v0015);
}



// Code for wi_new

static LispObject CC_wi_new(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0134, v0145;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for wi_new");
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
    v0134 = qvalue(elt(env, 1)); // wi_number
    v0134 = add1(v0134);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[-4];
    qvalue(elt(env, 1)) = v0134; // wi_number
    v0145 = elt(env, 2); // !:
    v0134 = qvalue(elt(env, 1)); // wi_number
    fn = elt(env, 4); // mkid
    v0134 = (*qfn2(fn))(qenv(fn), v0145, v0134);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[-4];
    v0134 = Lintern(nil, v0134);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[-4];
    stack[-3] = v0134;
    stack[-1] = stack[-3];
    stack[0] = elt(env, 3); // windex
    v0134 = stack[-2];
    v0134 = ncons(v0134);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[-4];
    v0134 = Lputprop(nil, 3, stack[-1], stack[0], v0134);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    { LispObject res = stack[-3]; popv(5); return onevalue(res); }
// error exit handlers
v0014:
    popv(5);
    return nil;
}



// Code for simpatom

static LispObject CC_simpatom(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0195, v0196, v0197;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for simpatom");
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
    v0195 = stack[-1];
    if (v0195 == nil) goto v0067;
    v0195 = stack[-1];
    if (is_number(v0195)) goto v0065;
    v0195 = stack[-1];
    v0195 = Lstringp(nil, v0195);
    env = stack[-3];
    if (v0195 == nil) goto v0121;
    v0196 = elt(env, 5); // "String"
    v0195 = stack[-1];
    v0196 = list2(v0196, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-3];
    v0195 = elt(env, 6); // "identifier"
    {
        popv(4);
        fn = elt(env, 13); // typerr
        return (*qfn2(fn))(qenv(fn), v0196, v0195);
    }

v0121:
    v0195 = stack[-1];
    if (!symbolp(v0195)) v0195 = nil;
    else { v0195 = qfastgets(v0195);
           if (v0195 != nil) { v0195 = elt(v0195, 17); // share
#ifdef RECORD_GET
             if (v0195 == SPID_NOPROP)
                record_get(elt(fastget_names, 17), 0),
                v0195 = nil;
             else record_get(elt(fastget_names, 17), 1),
                v0195 = lisp_true; }
           else record_get(elt(fastget_names, 17), 0); }
#else
             if (v0195 == SPID_NOPROP) v0195 = nil; else v0195 = lisp_true; }}
#endif
    if (v0195 == nil) goto v0199;
    v0195 = stack[-1];
    fn = elt(env, 14); // lispeval
    v0195 = (*qfn1(fn))(qenv(fn), v0195);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-3];
    v0197 = v0195;
    v0196 = v0197;
    v0195 = stack[-1];
    if (v0196 == v0195) goto v0200;
    v0195 = v0197;
    {
        popv(4);
        fn = elt(env, 15); // simp
        return (*qfn1(fn))(qenv(fn), v0195);
    }

v0200:
    v0196 = stack[-1];
    v0195 = (LispObject)17; // 1
    {
        popv(4);
        fn = elt(env, 16); // mksq
        return (*qfn2(fn))(qenv(fn), v0196, v0195);
    }

v0199:
    v0195 = stack[-1];
    if (!symbolp(v0195)) v0195 = nil;
    else { v0195 = qfastgets(v0195);
           if (v0195 != nil) { v0195 = elt(v0195, 56); // idvalfn
#ifdef RECORD_GET
             if (v0195 != SPID_NOPROP)
                record_get(elt(fastget_names, 56), 1);
             else record_get(elt(fastget_names, 56), 0),
                v0195 = nil; }
           else record_get(elt(fastget_names, 56), 0); }
#else
             if (v0195 == SPID_NOPROP) v0195 = nil; }}
#endif
    stack[-2] = v0195;
    if (v0195 == nil) goto v0144;
    v0196 = stack[-2];
    v0195 = stack[-1];
        popv(4);
        return Lapply1(nil, v0196, v0195);

v0144:
    v0195 = qvalue(elt(env, 7)); // !*numval
    if (v0195 == nil) goto v0201;
    v0195 = qvalue(elt(env, 2)); // dmode!*
    if (v0195 == nil) goto v0201;
    v0196 = stack[-1];
    v0195 = elt(env, 8); // constant
    v0195 = Lflagp(nil, v0196, v0195);
    env = stack[-3];
    if (v0195 == nil) goto v0202;
    v0196 = stack[-1];
    v0195 = qvalue(elt(env, 2)); // dmode!*
    v0195 = get(v0196, v0195);
    env = stack[-3];
    stack[-2] = v0195;
    if (v0195 == nil) goto v0068;
    stack[0] = elt(env, 9); // lispapply
    v0195 = stack[-2];
    v0196 = Lmkquote(nil, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-3];
    v0195 = qvalue(elt(env, 1)); // nil
    v0196 = list3(stack[0], v0196, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-3];
    v0195 = qvalue(elt(env, 1)); // nil
    fn = elt(env, 17); // errorset!*
    v0195 = (*qfn2(fn))(qenv(fn), v0196, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-3];
    stack[-2] = v0195;
    fn = elt(env, 18); // errorp
    v0195 = (*qfn1(fn))(qenv(fn), v0195);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-3];
    if (v0195 == nil) goto v0169;
    v0195 = qvalue(elt(env, 1)); // nil
    goto v0203;

v0203:
    if (v0195 == nil) goto v0201;
    v0195 = stack[-2];
    {
        popv(4);
        fn = elt(env, 19); // !*d2q
        return (*qfn1(fn))(qenv(fn), v0195);
    }

v0201:
    v0195 = stack[-1];
    fn = elt(env, 20); // getrtype
    v0195 = (*qfn1(fn))(qenv(fn), v0195);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-3];
    if (v0195 == nil) goto v0204;
    v0196 = stack[-1];
    v0195 = elt(env, 12); // scalar
    fn = elt(env, 13); // typerr
    v0195 = (*qfn2(fn))(qenv(fn), v0196, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    v0195 = nil;
    { popv(4); return onevalue(v0195); }

v0204:
    v0196 = stack[-1];
    v0195 = (LispObject)17; // 1
    {
        popv(4);
        fn = elt(env, 16); // mksq
        return (*qfn2(fn))(qenv(fn), v0196, v0195);
    }

v0169:
    v0195 = stack[-2];
    v0196 = qcar(v0195);
    stack[-2] = v0196;
    v0195 = elt(env, 10); // !:rd!:
    if (!consp(v0196)) goto v0166;
    v0196 = qcar(v0196);
    if (!(v0196 == v0195)) goto v0166;
    v0195 = stack[-2];
    v0195 = qcdr(v0195);
    fn = elt(env, 21); // complexp
    v0195 = (*qfn1(fn))(qenv(fn), v0195);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-3];
    v0195 = (v0195 == nil ? lisp_true : nil);
    goto v0203;

v0166:
    v0195 = qvalue(elt(env, 11)); // t
    goto v0203;

v0068:
    v0195 = qvalue(elt(env, 1)); // nil
    goto v0203;

v0202:
    v0195 = qvalue(elt(env, 1)); // nil
    goto v0203;

v0065:
    v0196 = stack[-1];
    v0195 = (LispObject)1; // 0
    if (v0196 == v0195) goto v0145;
    v0195 = stack[-1];
    v0195 = integerp(v0195);
    if (v0195 == nil) goto v0142;
    v0196 = qvalue(elt(env, 2)); // dmode!*
    v0195 = elt(env, 3); // !:mod!:
    if (v0196 == v0195) goto v0097;
    v0195 = qvalue(elt(env, 1)); // nil
    goto v0043;

v0043:
    if (v0195 == nil) goto v0044;
    v0196 = qvalue(elt(env, 1)); // nil
    v0195 = (LispObject)17; // 1
    popv(4);
    return cons(v0196, v0195);

v0044:
    v0195 = qvalue(elt(env, 2)); // dmode!*
    if (!symbolp(v0195)) v0195 = nil;
    else { v0195 = qfastgets(v0195);
           if (v0195 != nil) { v0195 = elt(v0195, 5); // convert
#ifdef RECORD_GET
             if (v0195 == SPID_NOPROP)
                record_get(elt(fastget_names, 5), 0),
                v0195 = nil;
             else record_get(elt(fastget_names, 5), 1),
                v0195 = lisp_true; }
           else record_get(elt(fastget_names, 5), 0); }
#else
             if (v0195 == SPID_NOPROP) v0195 = nil; else v0195 = lisp_true; }}
#endif
    if (v0195 == nil) goto v0092;
    v0196 = stack[-1];
    v0195 = (LispObject)17; // 1
    v0195 = Lneq(nil, v0196, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-3];
    goto v0093;

v0093:
    if (v0195 == nil) goto v0148;
    v0195 = qvalue(elt(env, 2)); // dmode!*
    if (!symbolp(v0195)) v0196 = nil;
    else { v0196 = qfastgets(v0195);
           if (v0196 != nil) { v0196 = elt(v0196, 34); // i2d
#ifdef RECORD_GET
             if (v0196 != SPID_NOPROP)
                record_get(elt(fastget_names, 34), 1);
             else record_get(elt(fastget_names, 34), 0),
                v0196 = nil; }
           else record_get(elt(fastget_names, 34), 0); }
#else
             if (v0196 == SPID_NOPROP) v0196 = nil; }}
#endif
    v0195 = stack[-1];
    v0195 = Lapply1(nil, v0196, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-3];
    {
        popv(4);
        fn = elt(env, 19); // !*d2q
        return (*qfn1(fn))(qenv(fn), v0195);
    }

v0148:
    v0196 = stack[-1];
    v0195 = (LispObject)17; // 1
    popv(4);
    return cons(v0196, v0195);

v0092:
    v0195 = qvalue(elt(env, 1)); // nil
    goto v0093;

v0097:
    v0196 = qvalue(elt(env, 4)); // current!-modulus
    v0195 = (LispObject)17; // 1
    v0195 = (v0196 == v0195 ? lisp_true : nil);
    goto v0043;

v0142:
    v0195 = stack[-1];
    {
        popv(4);
        fn = elt(env, 22); // rd!:simp
        return (*qfn1(fn))(qenv(fn), v0195);
    }

v0145:
    v0196 = qvalue(elt(env, 1)); // nil
    v0195 = (LispObject)17; // 1
    popv(4);
    return cons(v0196, v0195);

v0067:
    v0196 = qvalue(elt(env, 1)); // nil
    v0195 = (LispObject)17; // 1
    popv(4);
    return cons(v0196, v0195);
// error exit handlers
v0198:
    popv(4);
    return nil;
}



// Code for nb

static LispObject CC_nb(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0057;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for nb");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0057 = v0000;
// end of prologue
    if (v0057 == nil) goto v0067;
    v0057 = (LispObject)17; // 1
    return onevalue(v0057);

v0067:
    v0057 = (LispObject)-15; // -1
    return onevalue(v0057);
}



// Code for rl_smupdknowl

static LispObject CC_rl_smupdknowl(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0055, v0061, v0016, v0134;
    LispObject fn;
    LispObject v0009, v0117, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "rl_smupdknowl");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0117 = va_arg(aa, LispObject);
    v0009 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rl_smupdknowl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0009,v0117,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0001,v0117,v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0055 = v0009;
    v0061 = v0117;
    v0016 = v0001;
    v0134 = v0000;
// end of prologue
    stack[0] = qvalue(elt(env, 1)); // rl_smupdknowl!*
    v0055 = list4(v0134, v0016, v0061, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-1];
    {
        LispObject v0112 = stack[0];
        popv(2);
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(qenv(fn), v0112, v0055);
    }
// error exit handlers
v0118:
    popv(2);
    return nil;
}



// Code for ibalp_simpterm

static LispObject CC_ibalp_simpterm(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0205, v0206;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_simpterm");
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

v0173:
    v0205 = stack[0];
    if (!consp(v0205)) goto v0113;
    v0205 = stack[0];
    v0205 = qcar(v0205);
    stack[-1] = v0205;
    v0205 = stack[-1];
    fn = elt(env, 3); // ibalp_boolfp
    v0205 = (*qfn1(fn))(qenv(fn), v0205);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-5];
    if (v0205 == nil) goto v0004;
    stack[-4] = stack[-1];
    v0205 = stack[0];
    v0205 = qcdr(v0205);
    stack[-3] = v0205;
    v0205 = stack[-3];
    if (v0205 == nil) goto v0142;
    v0205 = stack[-3];
    v0205 = qcar(v0205);
    v0205 = CC_ibalp_simpterm(env, v0205);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-5];
    v0205 = ncons(v0205);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-5];
    stack[-1] = v0205;
    stack[-2] = v0205;
    goto v0112;

v0112:
    v0205 = stack[-3];
    v0205 = qcdr(v0205);
    stack[-3] = v0205;
    v0205 = stack[-3];
    if (v0205 == nil) goto v0005;
    stack[0] = stack[-1];
    v0205 = stack[-3];
    v0205 = qcar(v0205);
    v0205 = CC_ibalp_simpterm(env, v0205);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-5];
    v0205 = ncons(v0205);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-5];
    v0205 = Lrplacd(nil, stack[0], v0205);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-5];
    v0205 = stack[-1];
    v0205 = qcdr(v0205);
    stack[-1] = v0205;
    goto v0112;

v0005:
    v0205 = stack[-2];
    goto v0059;

v0059:
    {
        LispObject v0207 = stack[-4];
        popv(6);
        return cons(v0207, v0205);
    }

v0142:
    v0205 = qvalue(elt(env, 1)); // nil
    goto v0059;

v0004:
    v0205 = stack[0];
    fn = elt(env, 4); // reval
    v0205 = (*qfn1(fn))(qenv(fn), v0205);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-5];
    stack[0] = v0205;
    v0206 = stack[0];
    v0205 = stack[-1];
    if (!consp(v0206)) goto v0002;
    v0206 = qcar(v0206);
    if (!(v0206 == v0205)) goto v0002;
    v0206 = stack[-1];
    v0205 = elt(env, 2); // "Boolean function"
    fn = elt(env, 5); // typerr
    v0205 = (*qfn2(fn))(qenv(fn), v0206, v0205);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-5];
    goto v0002;

v0002:
    v0205 = stack[0];
    stack[0] = v0205;
    goto v0173;

v0113:
    v0205 = stack[0];
    {
        popv(6);
        fn = elt(env, 6); // ibalp_simpatom
        return (*qfn1(fn))(qenv(fn), v0205);
    }
// error exit handlers
v0038:
    popv(6);
    return nil;
}



// Code for cgp_number

static LispObject CC_cgp_number(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0062, v0057;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cgp_number");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0062 = v0000;
// end of prologue
    v0057 = v0062;
    v0062 = (LispObject)81; // 5
    {
        fn = elt(env, 1); // nth
        return (*qfn2(fn))(qenv(fn), v0057, v0062);
    }
}



// Code for omsir

static LispObject CC_omsir(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0216, v0079;
    LispObject fn;
    argcheck(nargs, 0, "omsir");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for omsir");
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
    push(nil);
// end of prologue
    stack[-1] = nil;
    v0216 = qvalue(elt(env, 1)); // nil
    stack[-2] = v0216;
    v0079 = qvalue(elt(env, 2)); // atts
    v0216 = elt(env, 3); // name
    fn = elt(env, 12); // find
    v0216 = (*qfn2(fn))(qenv(fn), v0079, v0216);
    nil = C_nil;
    if (exception_pending()) goto v0217;
    env = stack[-6];
    v0216 = Lintern(nil, v0216);
    nil = C_nil;
    if (exception_pending()) goto v0217;
    env = stack[-6];
    stack[-5] = v0216;
    v0079 = qvalue(elt(env, 2)); // atts
    v0216 = elt(env, 4); // cd
    fn = elt(env, 12); // find
    v0216 = (*qfn2(fn))(qenv(fn), v0079, v0216);
    nil = C_nil;
    if (exception_pending()) goto v0217;
    env = stack[-6];
    v0216 = Lintern(nil, v0216);
    nil = C_nil;
    if (exception_pending()) goto v0217;
    env = stack[-6];
    stack[-3] = v0216;
    v0216 = stack[-5];
    v0079 = Lexplode(nil, v0216);
    nil = C_nil;
    if (exception_pending()) goto v0217;
    env = stack[-6];
    v0216 = elt(env, 5); // (v e c t o r)
    if (equal(v0079, v0216)) goto v0045;
    v0216 = stack[-5];
    v0079 = Lintern(nil, v0216);
    nil = C_nil;
    if (exception_pending()) goto v0217;
    env = stack[-6];
    v0216 = qvalue(elt(env, 7)); // mmleq!*
    v0216 = Lmember(nil, v0079, v0216);
    stack[-4] = v0216;
    goto v0112;

v0112:
    v0216 = stack[-4];
    if (!(v0216 == nil)) goto v0097;
    v0079 = stack[-5];
    v0216 = qvalue(elt(env, 8)); // special_cases!*
    v0216 = Lassoc(nil, v0079, v0216);
    stack[-4] = v0216;
    if (v0216 == nil) goto v0073;
    v0216 = stack[-4];
    v0216 = Lreverse(nil, v0216);
    nil = C_nil;
    if (exception_pending()) goto v0217;
    env = stack[-6];
    v0216 = qcar(v0216);
    stack[-2] = v0216;
    v0216 = stack[-2];
    if (v0216 == nil) goto v0019;
    v0216 = stack[-2];
    v0216 = ncons(v0216);
    nil = C_nil;
    if (exception_pending()) goto v0217;
    env = stack[-6];
    stack[-2] = v0216;
    goto v0019;

v0019:
    v0216 = stack[-4];
    v0216 = Lreverse(nil, v0216);
    nil = C_nil;
    if (exception_pending()) goto v0217;
    env = stack[-6];
    v0216 = qcdr(v0216);
    stack[0] = qcar(v0216);
    v0216 = stack[-4];
    v0216 = qcdr(v0216);
    v0216 = Lreverse(nil, v0216);
    nil = C_nil;
    if (exception_pending()) goto v0217;
    env = stack[-6];
    v0216 = qcdr(v0216);
    v0216 = qcdr(v0216);
    v0216 = Lreverse(nil, v0216);
    nil = C_nil;
    if (exception_pending()) goto v0217;
    env = stack[-6];
    v0216 = cons(stack[0], v0216);
    nil = C_nil;
    if (exception_pending()) goto v0217;
    env = stack[-6];
    stack[-4] = v0216;
    goto v0097;

v0097:
    v0216 = stack[-4];
    if (v0216 == nil) goto v0031;
    v0216 = stack[-4];
    v0079 = qcar(v0216);
    v0216 = qvalue(elt(env, 10)); // valid_om!*
    v0216 = Lassoc(nil, v0079, v0216);
    stack[-1] = v0216;
    goto v0031;

v0031:
    v0216 = stack[-1];
    if (v0216 == nil) goto v0139;
    v0216 = stack[-1];
    v0216 = qcdr(v0216);
    v0216 = qcar(v0216);
    stack[-1] = v0216;
    goto v0139;

v0139:
    v0216 = stack[-4];
    if (v0216 == nil) goto v0053;
    v0079 = stack[-3];
    v0216 = stack[-1];
    v0216 = (v0216 == nil ? lisp_true : nil);
    v0216 = (equal(v0079, v0216) ? lisp_true : nil);
    goto v0024;

v0024:
    if (v0216 == nil) goto v0081;
    v0216 = stack[-5];
    {
        popv(7);
        fn = elt(env, 13); // encodeir
        return (*qfn1(fn))(qenv(fn), v0216);
    }

v0081:
    v0216 = stack[-4];
    v0079 = qcar(v0216);
    v0216 = stack[-2];
    popv(7);
    return list2(v0079, v0216);

v0053:
    v0216 = qvalue(elt(env, 11)); // t
    goto v0024;

v0073:
    v0079 = stack[-5];
    v0216 = qvalue(elt(env, 9)); // special_cases2!*
    v0079 = Lassoc(nil, v0079, v0216);
    v0216 = v0079;
    if (v0079 == nil) goto v0097;
    v0079 = v0216;
    v0079 = qcdr(v0079);
    v0079 = qcar(v0079);
    v0216 = qcdr(v0216);
    v0216 = qcdr(v0216);
    {
        popv(7);
        fn = elt(env, 14); // apply
        return (*qfn2(fn))(qenv(fn), v0079, v0216);
    }

v0045:
    v0216 = elt(env, 6); // (vectorml linalg1)
    stack[-4] = v0216;
    goto v0112;
// error exit handlers
v0217:
    popv(7);
    return nil;
}



// Code for maprin

static LispObject CC_maprin(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0134, v0145, v0118;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for maprin");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0145 = v0000;
// end of prologue
    v0134 = qvalue(elt(env, 1)); // outputhandler!*
    if (v0134 == nil) goto v0036;
    v0134 = qvalue(elt(env, 1)); // outputhandler!*
    v0118 = elt(env, 0); // maprin
        return Lapply2(nil, 3, v0134, v0118, v0145);

v0036:
    v0134 = qvalue(elt(env, 2)); // overflowed!*
    if (v0134 == nil) goto v0059;
    v0134 = nil;
    return onevalue(v0134);

v0059:
    v0134 = (LispObject)1; // 0
    {
        fn = elt(env, 3); // maprint
        return (*qfn2(fn))(qenv(fn), v0145, v0134);
    }
}



// Code for redcodmat

static LispObject CC_redcodmat(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0059, v0060;
    LispObject fn;
    argcheck(nargs, 0, "redcodmat");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for redcodmat");
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
    v0059 = qvalue(elt(env, 1)); // rowmin
    stack[0] = v0059;
    goto v0011;

v0011:
    v0060 = qvalue(elt(env, 2)); // rowmax
    v0059 = stack[0];
    v0059 = difference2(v0060, v0059);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-1];
    v0059 = Lminusp(nil, v0059);
    env = stack[-1];
    if (v0059 == nil) goto v0113;
    v0059 = qvalue(elt(env, 3)); // nil
    { popv(2); return onevalue(v0059); }

v0113:
    v0059 = stack[0];
    fn = elt(env, 4); // testred
    v0059 = (*qfn1(fn))(qenv(fn), v0059);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-1];
    v0059 = stack[0];
    v0059 = add1(v0059);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-1];
    stack[0] = v0059;
    goto v0011;
// error exit handlers
v0061:
    popv(2);
    return nil;
}



// Code for xord_gradlex

static LispObject CC_xord_gradlex(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0126, v0098;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for xord_gradlex");
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
    v0126 = stack[-1];
    v0098 = qcar(v0126);
    v0126 = (LispObject)17; // 1
    if (v0098 == v0126) goto v0036;
    v0126 = stack[0];
    v0098 = qcar(v0126);
    v0126 = (LispObject)17; // 1
    if (v0098 == v0126) goto v0023;
    v0126 = stack[-1];
    stack[-2] = Llength(nil, v0126);
    nil = C_nil;
    if (exception_pending()) goto v0008;
    env = stack[-3];
    v0126 = stack[0];
    v0126 = Llength(nil, v0126);
    nil = C_nil;
    if (exception_pending()) goto v0008;
    env = stack[-3];
    if (equal(stack[-2], v0126)) goto v0135;
    v0126 = stack[-1];
    stack[-1] = Llength(nil, v0126);
    nil = C_nil;
    if (exception_pending()) goto v0008;
    env = stack[-3];
    v0126 = stack[0];
    v0126 = Llength(nil, v0126);
    nil = C_nil;
    if (exception_pending()) goto v0008;
    {
        LispObject v0218 = stack[-1];
        popv(4);
        return Lgreaterp(nil, v0218, v0126);
    }

v0135:
    v0098 = stack[-1];
    v0126 = stack[0];
    {
        popv(4);
        fn = elt(env, 3); // xord_lex
        return (*qfn2(fn))(qenv(fn), v0098, v0126);
    }

v0023:
    v0126 = qvalue(elt(env, 2)); // t
    { popv(4); return onevalue(v0126); }

v0036:
    v0126 = qvalue(elt(env, 1)); // nil
    { popv(4); return onevalue(v0126); }
// error exit handlers
v0008:
    popv(4);
    return nil;
}



// Code for symbid

static LispObject CC_symbid(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0089, v0090, v0192, v0105;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for symbid");
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
    v0192 = v0001;
    stack[0] = v0000;
// end of prologue
    v0089 = qvalue(elt(env, 1)); // fname!*
    if (v0089 == nil) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    v0090 = qvalue(elt(env, 2)); // ftype!*
    v0089 = elt(env, 3); // (macro smacro inline)
    v0089 = Lmemq(nil, v0090, v0089);
    if (v0089 == nil) goto v0060;
    v0089 = qvalue(elt(env, 8)); // nil
    goto v0057;

v0057:
    if (v0089 == nil) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    v0105 = elt(env, 9); // "nonlocal use of undeclared variable"
    v0192 = stack[0];
    v0090 = elt(env, 10); // "in procedure"
    v0089 = qvalue(elt(env, 1)); // fname!*
    v0089 = list4(v0105, v0192, v0090, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-1];
    fn = elt(env, 11); // lprim
    v0089 = (*qfn1(fn))(qenv(fn), v0089);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    { LispObject res = stack[0]; popv(2); return onevalue(res); }

v0060:
    v0089 = stack[0];
    v0090 = v0192;
    v0089 = Latsoc(nil, v0089, v0090);
    if (!(v0089 == nil)) goto v0058;
    v0089 = stack[0];
    v0089 = Lsymbol_specialp(nil, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-1];
    if (!(v0089 == nil)) goto v0058;
    v0089 = stack[0];
    v0089 = Lsymbol_globalp(nil, v0089);
    env = stack[-1];
    if (!(v0089 == nil)) goto v0058;
    v0089 = stack[0];
    if (v0089 == nil) goto v0042;
    v0090 = stack[0];
    v0089 = qvalue(elt(env, 4)); // t
    if (v0090 == v0089) goto v0215;
    v0089 = stack[0];
    if (!symbolp(v0089)) v0089 = nil;
    else { v0089 = qfastgets(v0089);
           if (v0089 != nil) { v0089 = elt(v0089, 17); // share
#ifdef RECORD_GET
             if (v0089 == SPID_NOPROP)
                record_get(elt(fastget_names, 17), 0),
                v0089 = nil;
             else record_get(elt(fastget_names, 17), 1),
                v0089 = lisp_true; }
           else record_get(elt(fastget_names, 17), 0); }
#else
             if (v0089 == SPID_NOPROP) v0089 = nil; else v0089 = lisp_true; }}
#endif
    if (v0089 == nil) goto v0221;
    v0089 = qvalue(elt(env, 4)); // t
    goto v0058;

v0058:
    v0089 = (v0089 == nil ? lisp_true : nil);
    goto v0057;

v0221:
    v0089 = qvalue(elt(env, 5)); // !*comp
    if (!(v0089 == nil)) goto v0058;
    v0089 = qvalue(elt(env, 6)); // !*cref
    if (!(v0089 == nil)) goto v0058;
    v0090 = stack[0];
    v0089 = elt(env, 7); // constant!?
    v0089 = get(v0090, v0089);
    env = stack[-1];
    goto v0058;

v0215:
    v0089 = qvalue(elt(env, 4)); // t
    goto v0058;

v0042:
    v0089 = qvalue(elt(env, 4)); // t
    goto v0058;
// error exit handlers
v0121:
    popv(2);
    return nil;
}



// Code for getmatelem

static LispObject CC_getmatelem(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0226, v0227, v0228;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for getmatelem");
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

v0062:
    v0226 = stack[-2];
    v0227 = Llength(nil, v0226);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-4];
    v0226 = (LispObject)49; // 3
    if (v0227 == v0226) goto v0113;
    v0227 = stack[-2];
    v0226 = elt(env, 1); // "matrix element"
    fn = elt(env, 9); // typerr
    v0226 = (*qfn2(fn))(qenv(fn), v0227, v0226);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-4];
    goto v0113;

v0113:
    v0226 = stack[-2];
    v0226 = qcar(v0226);
    if (!symbolp(v0226)) v0226 = nil;
    else { v0226 = qfastgets(v0226);
           if (v0226 != nil) { v0226 = elt(v0226, 4); // avalue
#ifdef RECORD_GET
             if (v0226 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v0226 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v0226 == SPID_NOPROP) v0226 = nil; }}
#endif
    stack[-3] = v0226;
    v0226 = stack[-3];
    if (v0226 == nil) goto v0014;
    v0226 = stack[-3];
    v0227 = qcar(v0226);
    v0226 = elt(env, 3); // matrix
    v0226 = (v0227 == v0226 ? lisp_true : nil);
    v0226 = (v0226 == nil ? lisp_true : nil);
    goto v0046;

v0046:
    if (v0226 == nil) goto v0008;
    v0226 = stack[-2];
    v0227 = qcar(v0226);
    v0226 = elt(env, 4); // "matrix"
    fn = elt(env, 9); // typerr
    v0226 = (*qfn2(fn))(qenv(fn), v0227, v0226);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-4];
    goto v0145;

v0145:
    v0226 = stack[-2];
    v0226 = qcdr(v0226);
    v0226 = qcar(v0226);
    fn = elt(env, 10); // reval_without_mod
    v0226 = (*qfn1(fn))(qenv(fn), v0226);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-4];
    stack[0] = v0226;
    v0226 = stack[0];
    v0226 = integerp(v0226);
    if (v0226 == nil) goto v0160;
    v0227 = stack[0];
    v0226 = (LispObject)1; // 0
    v0226 = (LispObject)lesseq2(v0227, v0226);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    v0226 = v0226 ? lisp_true : nil;
    env = stack[-4];
    goto v0161;

v0161:
    if (v0226 == nil) goto v0229;
    v0227 = stack[0];
    v0226 = elt(env, 8); // "positive integer"
    fn = elt(env, 9); // typerr
    v0226 = (*qfn2(fn))(qenv(fn), v0227, v0226);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-4];
    goto v0229;

v0229:
    v0226 = stack[-3];
    v0227 = qcdr(v0226);
    v0226 = stack[0];
    fn = elt(env, 11); // nth
    v0226 = (*qfn2(fn))(qenv(fn), v0227, v0226);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-4];
    stack[-3] = v0226;
    v0226 = stack[-2];
    v0226 = qcdr(v0226);
    v0226 = qcdr(v0226);
    v0226 = qcar(v0226);
    fn = elt(env, 10); // reval_without_mod
    v0226 = (*qfn1(fn))(qenv(fn), v0226);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-4];
    stack[0] = v0226;
    v0226 = stack[0];
    v0226 = integerp(v0226);
    if (v0226 == nil) goto v0138;
    v0227 = stack[0];
    v0226 = (LispObject)1; // 0
    v0226 = (LispObject)lesseq2(v0227, v0226);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    v0226 = v0226 ? lisp_true : nil;
    env = stack[-4];
    goto v0199;

v0199:
    if (v0226 == nil) goto v0165;
    v0227 = stack[0];
    v0226 = elt(env, 8); // "positive integer"
    fn = elt(env, 9); // typerr
    v0226 = (*qfn2(fn))(qenv(fn), v0227, v0226);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-4];
    goto v0165;

v0165:
    v0227 = stack[-3];
    v0226 = stack[0];
    {
        popv(5);
        fn = elt(env, 11); // nth
        return (*qfn2(fn))(qenv(fn), v0227, v0226);
    }

v0138:
    v0226 = qvalue(elt(env, 2)); // t
    goto v0199;

v0160:
    v0226 = qvalue(elt(env, 2)); // t
    goto v0161;

v0008:
    v0226 = stack[-3];
    v0226 = qcdr(v0226);
    v0227 = qcar(v0226);
    stack[-3] = v0227;
    v0226 = elt(env, 5); // mat
    if (!consp(v0227)) goto v0051;
    v0227 = qcar(v0227);
    if (v0227 == v0226) goto v0145;
    else goto v0051;

v0051:
    v0226 = stack[-3];
    if (symbolp(v0226)) goto v0094;
    stack[-1] = elt(env, 3); // matrix
    stack[0] = (LispObject)17; // 1
    v0228 = elt(env, 6); // "Matrix"
    v0226 = stack[-2];
    v0227 = qcar(v0226);
    v0226 = elt(env, 7); // "not set"
    v0226 = list3(v0228, v0227, v0226);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-4];
    fn = elt(env, 12); // rerror
    v0226 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v0226);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-4];
    goto v0145;

v0094:
    v0227 = stack[-3];
    v0226 = stack[-2];
    v0226 = qcdr(v0226);
    v0226 = cons(v0227, v0226);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-4];
    stack[-2] = v0226;
    goto v0062;

v0014:
    v0226 = qvalue(elt(env, 2)); // t
    goto v0046;
// error exit handlers
v0179:
    popv(5);
    return nil;
}



// Code for dl_get2

static LispObject CC_dl_get2(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0142, v0102, v0135;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dl_get2");
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
    v0142 = v0001;
    v0102 = v0000;
// end of prologue

v0026:
    v0135 = v0102;
    if (v0135 == nil) { popv(2); return onevalue(v0142); }
    v0135 = v0102;
    v0135 = qcar(v0135);
    if (!symbolp(v0135)) v0135 = nil;
    else { v0135 = qfastgets(v0135);
           if (v0135 != nil) { v0135 = elt(v0135, 32); // dummy
#ifdef RECORD_GET
             if (v0135 != SPID_NOPROP)
                record_get(elt(fastget_names, 32), 1);
             else record_get(elt(fastget_names, 32), 0),
                v0135 = nil; }
           else record_get(elt(fastget_names, 32), 0); }
#else
             if (v0135 == SPID_NOPROP) v0135 = nil; }}
#endif
    if (v0135 == nil) goto v0045;
    v0135 = v0102;
    v0135 = qcdr(v0135);
    stack[0] = v0135;
    v0135 = qcar(v0102);
    v0102 = v0142;
    v0142 = qvalue(elt(env, 1)); // nil
    fn = elt(env, 2); // di_insert
    v0142 = (*qfnn(fn))(qenv(fn), 3, v0135, v0102, v0142);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-1];
    v0102 = stack[0];
    goto v0026;

v0045:
    v0102 = qcdr(v0102);
    goto v0026;
// error exit handlers
v0022:
    popv(2);
    return nil;
}



// Code for degree!-in!-variable

static LispObject CC_degreeKinKvariable(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0017, v0018;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for degree-in-variable");
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
    v0017 = stack[-1];
    if (!consp(v0017)) goto v0050;
    v0017 = stack[-1];
    v0017 = qcar(v0017);
    v0017 = (consp(v0017) ? nil : lisp_true);
    goto v0067;

v0067:
    if (v0017 == nil) goto v0020;
    v0017 = (LispObject)1; // 0
    { popv(4); return onevalue(v0017); }

v0020:
    v0017 = stack[-1];
    v0017 = qcar(v0017);
    v0018 = qcdr(v0017);
    v0017 = (LispObject)1; // 0
    if (v0018 == v0017) goto v0064;
    v0018 = stack[0];
    v0017 = stack[-1];
    v0017 = qcar(v0017);
    v0017 = qcar(v0017);
    v0017 = qcar(v0017);
    if (equal(v0018, v0017)) goto v0112;
    v0017 = stack[-1];
    v0017 = qcar(v0017);
    v0018 = qcdr(v0017);
    v0017 = stack[0];
    stack[-2] = CC_degreeKinKvariable(env, v0018, v0017);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-3];
    v0017 = stack[-1];
    v0018 = qcdr(v0017);
    v0017 = stack[0];
    v0017 = CC_degreeKinKvariable(env, v0018, v0017);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-3];
    {
        LispObject v0230 = stack[-2];
        popv(4);
        fn = elt(env, 3); // max
        return (*qfn2(fn))(qenv(fn), v0230, v0017);
    }

v0112:
    v0017 = stack[-1];
    v0017 = qcar(v0017);
    v0017 = qcar(v0017);
    v0017 = qcdr(v0017);
    { popv(4); return onevalue(v0017); }

v0064:
    v0017 = elt(env, 2); // "Polynomial with a zero coefficient found"
    {
        popv(4);
        fn = elt(env, 4); // errorf
        return (*qfn1(fn))(qenv(fn), v0017);
    }

v0050:
    v0017 = qvalue(elt(env, 1)); // t
    goto v0067;
// error exit handlers
v0115:
    popv(4);
    return nil;
}



// Code for delete_from_alglist

static LispObject CC_delete_from_alglist(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0066, v0020;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for delete_from_alglist");
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
    v0020 = v0000;
// end of prologue
    v0066 = stack[0];
    if (v0066 == nil) goto v0036;
    v0066 = stack[0];
    fn = elt(env, 2); // remhash
    v0066 = (*qfn2(fn))(qenv(fn), v0020, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    { LispObject res = stack[0]; popv(1); return onevalue(res); }

v0036:
    v0066 = qvalue(elt(env, 1)); // nil
    { popv(1); return onevalue(v0066); }
// error exit handlers
v0058:
    popv(1);
    return nil;
}



// Code for tmsf

static LispObject CC_tmsf(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0119, v0089, v0090;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for tmsf");
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
    v0119 = (LispObject)1; // 0
    v0090 = v0119;
    goto v0050;

v0050:
    v0119 = stack[-1];
    if (!consp(v0119)) goto v0023;
    v0119 = stack[-1];
    v0119 = qcar(v0119);
    v0119 = (consp(v0119) ? nil : lisp_true);
    goto v0004;

v0004:
    if (v0119 == nil) goto v0061;
    v0119 = stack[-1];
    if (v0119 == nil) { popv(4); return onevalue(v0090); }
    v0119 = v0090;
    popv(4);
    return add1(v0119);

v0061:
    stack[-2] = v0090;
    v0119 = stack[-1];
    v0119 = qcar(v0119);
    v0119 = qcar(v0119);
    v0119 = qcar(v0119);
    stack[0] = v0119;
    fn = elt(env, 3); // sfp
    v0119 = (*qfn1(fn))(qenv(fn), v0119);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-3];
    if (v0119 == nil) goto v0174;
    v0119 = stack[0];
    v0119 = CC_tmsf(env, v0119);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-3];
    stack[0] = v0119;
    goto v0015;

v0015:
    v0119 = stack[-1];
    v0119 = qcar(v0119);
    v0119 = qcdr(v0119);
    fn = elt(env, 4); // tmsf!*
    v0119 = (*qfn1(fn))(qenv(fn), v0119);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-3];
    v0119 = plus2(stack[0], v0119);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-3];
    v0119 = plus2(stack[-2], v0119);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-3];
    v0090 = v0119;
    v0119 = stack[-1];
    v0119 = qcar(v0119);
    v0119 = qcar(v0119);
    v0089 = qcdr(v0119);
    v0119 = (LispObject)17; // 1
    if (v0089 == v0119) goto v0126;
    v0119 = stack[-1];
    v0119 = qcar(v0119);
    v0119 = qcar(v0119);
    v0089 = qcdr(v0119);
    v0119 = (LispObject)33; // 2
    if (v0089 == v0119) goto v0002;
    v0089 = v0090;
    v0119 = (LispObject)33; // 2
    v0119 = plus2(v0089, v0119);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-3];
    v0090 = v0119;
    goto v0126;

v0126:
    v0119 = stack[-1];
    v0119 = qcdr(v0119);
    stack[-1] = v0119;
    goto v0050;

v0002:
    v0119 = v0090;
    v0119 = add1(v0119);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-3];
    v0090 = v0119;
    goto v0126;

v0174:
    v0119 = (LispObject)17; // 1
    stack[0] = v0119;
    goto v0015;

v0023:
    v0119 = qvalue(elt(env, 1)); // t
    goto v0004;
// error exit handlers
v0121:
    popv(4);
    return nil;
}



// Code for sq2sspl

static LispObject CC_sq2sspl(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0103, v0007;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sq2sspl");
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
    goto v0113;

v0113:
    v0103 = stack[-1];
    if (!consp(v0103)) goto v0023;
    v0103 = stack[-1];
    v0103 = qcar(v0103);
    v0103 = (consp(v0103) ? nil : lisp_true);
    goto v0004;

v0004:
    if (v0103 == nil) goto v0112;
    v0103 = stack[-1];
    v0007 = v0103;
    goto v0050;

v0050:
    v0103 = stack[-2];
    if (v0103 == nil) { popv(4); return onevalue(v0007); }
    v0103 = stack[-2];
    v0103 = qcar(v0103);
    v0103 = Lappend(nil, v0103, v0007);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-3];
    v0007 = v0103;
    v0103 = stack[-2];
    v0103 = qcdr(v0103);
    stack[-2] = v0103;
    goto v0050;

v0112:
    v0103 = stack[-1];
    v0007 = qcar(v0103);
    v0103 = stack[0];
    fn = elt(env, 2); // sq2sstm
    v0007 = (*qfn2(fn))(qenv(fn), v0007, v0103);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-3];
    v0103 = stack[-2];
    v0103 = cons(v0007, v0103);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-3];
    stack[-2] = v0103;
    v0103 = stack[-1];
    v0103 = qcdr(v0103);
    stack[-1] = v0103;
    goto v0113;

v0023:
    v0103 = qvalue(elt(env, 1)); // t
    goto v0004;
// error exit handlers
v0110:
    popv(4);
    return nil;
}



// Code for ibalp_lenisone

static LispObject CC_ibalp_lenisone(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0013, v0012;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_lenisone");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0012 = v0000;
// end of prologue
    v0013 = v0012;
    if (v0013 == nil) goto v0037;
    v0013 = v0012;
    v0013 = qcdr(v0013);
    v0013 = (v0013 == nil ? lisp_true : nil);
    return onevalue(v0013);

v0037:
    v0013 = qvalue(elt(env, 1)); // nil
    return onevalue(v0013);
}



// Code for vdp_zero!?

static LispObject CC_vdp_zeroW(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0036;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vdp_zero?");
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
    v0036 = v0000;
// end of prologue
    fn = elt(env, 1); // vdp_poly
    v0036 = (*qfn1(fn))(qenv(fn), v0036);
    errexit();
    v0036 = (v0036 == nil ? lisp_true : nil);
    return onevalue(v0036);
}



// Code for attributesml

static LispObject CC_attributesml(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0115, v0230;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for attributesml");
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
    v0115 = stack[-1];
    if (v0115 == nil) goto v0113;
    v0115 = elt(env, 2); // " "
    v0115 = Lprinc(nil, v0115);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-2];
    v0115 = stack[-1];
    v0115 = qcar(v0115);
    v0115 = qcar(v0115);
    v0115 = Lprinc(nil, v0115);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-2];
    v0115 = elt(env, 3); // "="""
    v0115 = Lprinc(nil, v0115);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-2];
    v0115 = stack[-1];
    v0115 = qcar(v0115);
    v0230 = qcar(v0115);
    v0115 = elt(env, 4); // definitionurl
    if (v0230 == v0115) goto v0103;
    v0115 = stack[-1];
    v0115 = qcar(v0115);
    v0115 = qcdr(v0115);
    v0230 = qcar(v0115);
    v0115 = elt(env, 5); // vectorml
    if (v0230 == v0115) goto v0135;
    v0115 = stack[-1];
    v0115 = qcar(v0115);
    v0115 = qcdr(v0115);
    v0115 = qcar(v0115);
    v0115 = Lprinc(nil, v0115);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-2];
    goto v0060;

v0060:
    v0115 = elt(env, 8); // """"
    v0115 = Lprinc(nil, v0115);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-2];
    v0115 = stack[-1];
    v0230 = qcdr(v0115);
    v0115 = stack[0];
    v0115 = CC_attributesml(env, v0230, v0115);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    goto v0026;

v0026:
    v0115 = nil;
    { popv(3); return onevalue(v0115); }

v0135:
    v0115 = elt(env, 6); // "vector"
    v0115 = Lprinc(nil, v0115);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-2];
    goto v0060;

v0103:
    v0115 = stack[-1];
    v0115 = qcar(v0115);
    v0115 = qcdr(v0115);
    v0115 = qcar(v0115);
    fn = elt(env, 9); // mathml_list2string
    v0115 = (*qfn1(fn))(qenv(fn), v0115);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-2];
    goto v0060;

v0113:
    v0115 = stack[0];
    v0115 = Lprinc(nil, v0115);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-2];
    v0115 = elt(env, 1); // ">"
    v0115 = Lprinc(nil, v0115);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    goto v0026;
// error exit handlers
v0040:
    popv(3);
    return nil;
}



// Code for findnewvars

static LispObject CC_findnewvars(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0214;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for findnewvars");
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
    v0214 = stack[0];
    if (!consp(v0214)) goto v0037;
    v0214 = stack[0];
    stack[-3] = v0214;
    goto v0060;

v0060:
    v0214 = stack[-3];
    if (v0214 == nil) goto v0145;
    v0214 = stack[-3];
    v0214 = qcar(v0214);
    v0214 = CC_findnewvars(env, v0214);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-4];
    stack[-2] = v0214;
    v0214 = stack[-2];
    fn = elt(env, 2); // lastpair
    v0214 = (*qfn1(fn))(qenv(fn), v0214);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-4];
    stack[-1] = v0214;
    v0214 = stack[-3];
    v0214 = qcdr(v0214);
    stack[-3] = v0214;
    v0214 = stack[-1];
    if (!consp(v0214)) goto v0060;
    else goto v0055;

v0055:
    v0214 = stack[-3];
    if (v0214 == nil) { LispObject res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v0214 = stack[-3];
    v0214 = qcar(v0214);
    v0214 = CC_findnewvars(env, v0214);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-4];
    v0214 = Lrplacd(nil, stack[0], v0214);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-4];
    v0214 = stack[-1];
    fn = elt(env, 2); // lastpair
    v0214 = (*qfn1(fn))(qenv(fn), v0214);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-4];
    stack[-1] = v0214;
    v0214 = stack[-3];
    v0214 = qcdr(v0214);
    stack[-3] = v0214;
    goto v0055;

v0145:
    v0214 = qvalue(elt(env, 1)); // nil
    { popv(5); return onevalue(v0214); }

v0037:
    v0214 = stack[0];
    fn = elt(env, 3); // genp
    v0214 = (*qfn1(fn))(qenv(fn), v0214);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-4];
    if (v0214 == nil) goto v0004;
    v0214 = stack[0];
    popv(5);
    return ncons(v0214);

v0004:
    v0214 = qvalue(elt(env, 1)); // nil
    { popv(5); return onevalue(v0214); }
// error exit handlers
v0017:
    popv(5);
    return nil;
}



// Code for bcquot

static LispObject CC_bcquot(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0007, v0008, v0218;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for bcquot");
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
    v0007 = qvalue(elt(env, 1)); // !*grmod!*
    if (v0007 == nil) goto v0026;
    v0007 = stack[0];
    v0007 = Lmodular_reciprocal(nil, v0007);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-2];
    v0007 = times2(stack[-1], v0007);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 4); // bcfi
        return (*qfn1(fn))(qenv(fn), v0007);
    }

v0026:
    v0007 = qvalue(elt(env, 2)); // !*vdpinteger
    if (v0007 == nil) goto v0010;
    v0218 = stack[-1];
    v0008 = stack[0];
    v0007 = elt(env, 3); // quotientx
    fn = elt(env, 5); // bcint2op
    v0007 = (*qfnn(fn))(qenv(fn), 3, v0218, v0008, v0007);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-2];
    if (!(v0007 == nil)) { popv(3); return onevalue(v0007); }
    v0007 = stack[-1];
    v0008 = qcar(v0007);
    v0007 = stack[0];
    v0007 = qcar(v0007);
    fn = elt(env, 6); // quotfx
    v0008 = (*qfn2(fn))(qenv(fn), v0008, v0007);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    v0007 = (LispObject)17; // 1
    popv(3);
    return cons(v0008, v0007);

v0010:
    v0008 = stack[-1];
    v0007 = stack[0];
    {
        popv(3);
        fn = elt(env, 7); // quotsq
        return (*qfn2(fn))(qenv(fn), v0008, v0007);
    }
// error exit handlers
v0111:
    popv(3);
    return nil;
}



// Code for guesspftype

static LispObject CC_guesspftype(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0044, v0042;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for guesspftype");
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
    if (!consp(v0044)) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    v0044 = stack[0];
    v0042 = qcar(v0044);
    v0044 = elt(env, 1); // (wedge d partdf hodge innerprod liedf)
    v0044 = Lmemq(nil, v0042, v0044);
    if (!(v0044 == nil)) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    v0044 = stack[0];
    v0044 = qcdr(v0044);
    v0042 = Llength(nil, v0044);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-1];
    v0044 = stack[0];
    v0044 = qcar(v0044);
    if (!symbolp(v0044)) v0044 = nil;
    else { v0044 = qfastgets(v0044);
           if (v0044 != nil) { v0044 = elt(v0044, 25); // ifdegree
#ifdef RECORD_GET
             if (v0044 != SPID_NOPROP)
                record_get(elt(fastget_names, 25), 1);
             else record_get(elt(fastget_names, 25), 0),
                v0044 = nil; }
           else record_get(elt(fastget_names, 25), 0); }
#else
             if (v0044 == SPID_NOPROP) v0044 = nil; }}
#endif
    v0044 = Lassoc(nil, v0042, v0044);
    if (v0044 == nil) goto v0128;
    v0044 = stack[0];
    v0044 = qcdr(v0044);
    fn = elt(env, 2); // xvarlistp
    v0044 = (*qfn1(fn))(qenv(fn), v0044);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-1];
    if (v0044 == nil) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    else goto v0128;

v0128:
    v0044 = stack[0];
    {
        popv(2);
        fn = elt(env, 3); // mknwedge
        return (*qfn1(fn))(qenv(fn), v0044);
    }
// error exit handlers
v0116:
    popv(2);
    return nil;
}



// Code for listeval

static LispObject CC_listeval(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0079, v0080, v0189;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for listeval");
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
    stack[0] = v0000;
// end of prologue
    v0079 = qvalue(elt(env, 1)); // simpcount!*
    v0080 = add1(v0079);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-5];
    qvalue(elt(env, 1)) = v0080; // simpcount!*
    v0079 = qvalue(elt(env, 2)); // simplimit!*
    v0079 = (LispObject)greaterp2(v0080, v0079);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    v0079 = v0079 ? lisp_true : nil;
    env = stack[-5];
    if (v0079 == nil) goto v0037;
    v0079 = (LispObject)1; // 0
    qvalue(elt(env, 1)) = v0079; // simpcount!*
    v0189 = elt(env, 3); // rlisp
    v0080 = (LispObject)289; // 18
    v0079 = elt(env, 4); // "Simplification recursion too deep"
    fn = elt(env, 9); // rerror
    v0079 = (*qfnn(fn))(qenv(fn), 3, v0189, v0080, v0079);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-5];
    goto v0037;

v0037:
    v0079 = stack[0];
    if (!consp(v0079)) goto v0145;
    v0079 = stack[0];
    v0080 = qcar(v0079);
    v0079 = elt(env, 5); // list
    if (v0080 == v0079) goto v0111;
    v0079 = stack[0];
    v0080 = qcar(v0079);
    v0079 = elt(env, 7); // listfn
    v0079 = get(v0080, v0079);
    env = stack[-5];
    v0080 = v0079;
    v0079 = v0080;
    if (v0079 == nil) goto v0136;
    v0189 = v0080;
    v0079 = stack[0];
    v0080 = qcdr(v0079);
    v0079 = stack[-3];
    v0079 = Lapply2(nil, 3, v0189, v0080, v0079);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-5];
    goto v0134;

v0134:
    stack[0] = v0079;
    v0079 = qvalue(elt(env, 1)); // simpcount!*
    v0079 = sub1(v0079);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-5];
    qvalue(elt(env, 1)) = v0079; // simpcount!*
    { LispObject res = stack[0]; popv(6); return onevalue(res); }

v0136:
    v0189 = elt(env, 3); // rlisp
    v0080 = (LispObject)305; // 19
    v0079 = elt(env, 8); // "Illegal operation on lists"
    fn = elt(env, 9); // rerror
    v0079 = (*qfnn(fn))(qenv(fn), 3, v0189, v0080, v0079);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-5];
    goto v0134;

v0111:
    v0079 = stack[0];
    v0079 = qcdr(v0079);
    stack[-4] = v0079;
    v0079 = stack[-4];
    if (v0079 == nil) goto v0091;
    v0079 = stack[-4];
    v0079 = qcar(v0079);
    v0080 = v0079;
    v0079 = stack[-3];
    fn = elt(env, 10); // reval1
    v0079 = (*qfn2(fn))(qenv(fn), v0080, v0079);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-5];
    v0079 = ncons(v0079);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-5];
    stack[-1] = v0079;
    stack[-2] = v0079;
    goto v0019;

v0019:
    v0079 = stack[-4];
    v0079 = qcdr(v0079);
    stack[-4] = v0079;
    v0079 = stack[-4];
    if (v0079 == nil) goto v0147;
    stack[0] = stack[-1];
    v0079 = stack[-4];
    v0079 = qcar(v0079);
    v0080 = v0079;
    v0079 = stack[-3];
    fn = elt(env, 10); // reval1
    v0079 = (*qfn2(fn))(qenv(fn), v0080, v0079);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-5];
    v0079 = ncons(v0079);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-5];
    v0079 = Lrplacd(nil, stack[0], v0079);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-5];
    v0079 = stack[-1];
    v0079 = qcdr(v0079);
    stack[-1] = v0079;
    goto v0019;

v0147:
    v0079 = stack[-2];
    goto v0123;

v0123:
    fn = elt(env, 11); // makelist
    v0079 = (*qfn1(fn))(qenv(fn), v0079);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-5];
    goto v0134;

v0091:
    v0079 = qvalue(elt(env, 6)); // nil
    goto v0123;

v0145:
    v0079 = stack[0];
    if (!symbolp(v0079)) v0079 = nil;
    else { v0079 = qfastgets(v0079);
           if (v0079 != nil) { v0079 = elt(v0079, 4); // avalue
#ifdef RECORD_GET
             if (v0079 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v0079 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v0079 == SPID_NOPROP) v0079 = nil; }}
#endif
    v0080 = v0079;
    v0079 = stack[0];
    if (!symbolp(v0079)) v0079 = nil;
    else { v0079 = qfastgets(v0079);
           if (v0079 != nil) { v0079 = elt(v0079, 17); // share
#ifdef RECORD_GET
             if (v0079 == SPID_NOPROP)
                record_get(elt(fastget_names, 17), 0),
                v0079 = nil;
             else record_get(elt(fastget_names, 17), 1),
                v0079 = lisp_true; }
           else record_get(elt(fastget_names, 17), 0); }
#else
             if (v0079 == SPID_NOPROP) v0079 = nil; else v0079 = lisp_true; }}
#endif
    if (v0079 == nil) goto v0042;
    v0079 = stack[0];
    fn = elt(env, 12); // eval
    v0079 = (*qfn1(fn))(qenv(fn), v0079);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-5];
    v0080 = v0079;
    goto v0135;

v0135:
    v0079 = stack[-3];
    v0079 = CC_listeval(env, v0080, v0079);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-5];
    goto v0134;

v0042:
    v0079 = v0080;
    if (v0079 == nil) goto v0098;
    v0079 = v0080;
    v0079 = qcdr(v0079);
    v0079 = qcar(v0079);
    v0080 = v0079;
    goto v0135;

v0098:
    v0080 = stack[0];
    v0079 = elt(env, 5); // list
    fn = elt(env, 13); // typerr
    v0079 = (*qfn2(fn))(qenv(fn), v0080, v0079);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-5];
    v0080 = v0079;
    goto v0135;
// error exit handlers
v0076:
    popv(6);
    return nil;
}



// Code for actual_alst

static LispObject CC_actual_alst(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0022, v0127, v0219;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for actual_alst");
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
    v0219 = nil;
    goto v0026;

v0026:
    v0022 = stack[-1];
    if (v0022 == nil) goto v0050;
    v0022 = stack[-1];
    v0022 = qcar(v0022);
    v0127 = qcar(v0022);
    v0022 = stack[0];
    v0022 = Lmemq(nil, v0127, v0022);
    if (v0022 == nil) goto v0142;
    v0022 = stack[-1];
    v0022 = qcar(v0022);
    v0127 = v0219;
    v0022 = cons(v0022, v0127);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-2];
    v0219 = v0022;
    v0022 = stack[-1];
    v0022 = qcdr(v0022);
    stack[-1] = v0022;
    goto v0026;

v0142:
    v0022 = stack[-1];
    v0022 = qcdr(v0022);
    stack[-1] = v0022;
    goto v0026;

v0050:
    v0022 = v0219;
    {
        popv(3);
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(qenv(fn), v0022);
    }
// error exit handlers
v0043:
    popv(3);
    return nil;
}



// Code for mkprogn

static LispObject CC_mkprogn(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0128, v0022, v0127, v0219;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mkprogn");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0127 = v0001;
    v0219 = v0000;
// end of prologue
    v0022 = v0127;
    v0128 = elt(env, 1); // progn
    if (!consp(v0022)) goto v0145;
    v0022 = qcar(v0022);
    if (!(v0022 == v0128)) goto v0145;
    v0128 = elt(env, 1); // progn
    v0022 = v0219;
    v0127 = qcdr(v0127);
    return list2star(v0128, v0022, v0127);

v0145:
    v0128 = elt(env, 1); // progn
    v0022 = v0219;
    return list3(v0128, v0022, v0127);
}



// Code for pv_times1

static LispObject CC_pv_times1(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0118, v0112, v0045;
    LispObject fn;
    LispObject v0117, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "pv_times1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0117 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pv_times1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0117,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0117);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    v0112 = v0117;
    stack[0] = v0001;
    v0118 = v0000;
// end of prologue

v0113:
    v0045 = v0118;
    if (v0045 == nil) { popv(3); return onevalue(v0112); }
    v0045 = v0118;
    v0045 = qcdr(v0045);
    stack[-1] = v0045;
    v0045 = qcar(v0118);
    v0118 = stack[0];
    fn = elt(env, 1); // pv_times2
    v0118 = (*qfnn(fn))(qenv(fn), 3, v0045, v0118, v0112);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    env = stack[-2];
    v0112 = v0118;
    v0118 = stack[-1];
    goto v0113;
// error exit handlers
v0015:
    popv(3);
    return nil;
}



// Code for remove!-free!-vars!*

static LispObject CC_removeKfreeKvarsH(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0026, v0113;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for remove-free-vars*");
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
    v0113 = v0000;
// end of prologue
    v0026 = qvalue(elt(env, 1)); // t
    stack[0] = qvalue(elt(env, 2)); // !*!*noremove!*!*
    qvalue(elt(env, 2)) = v0026; // !*!*noremove!*!*
    v0026 = v0113;
    fn = elt(env, 3); // remove!-free!-vars
    v0026 = (*qfn1(fn))(qenv(fn), v0026);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; // !*!*noremove!*!*
    { popv(2); return onevalue(v0026); }
// error exit handlers
v0050:
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; // !*!*noremove!*!*
    popv(2);
    return nil;
}



// Code for dvfsf_mk2

static LispObject CC_dvfsf_mk2(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0004, v0023, v0021;
    LispObject v0117, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "dvfsf_mk2");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0117 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dvfsf_mk2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0004 = v0117;
    v0023 = v0001;
    v0021 = v0000;
// end of prologue
    return list3(v0021, v0023, v0004);
}



// Code for constsml

static LispObject CC_constsml(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0040, v0132;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for constsml");
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
    v0040 = stack[0];
    if (!(is_number(v0040))) goto v0036;
    v0040 = elt(env, 1); // "<cn"
    fn = elt(env, 13); // printout
    v0040 = (*qfn1(fn))(qenv(fn), v0040);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    env = stack[-1];
    v0040 = stack[0];
    v0040 = Lfloatp(nil, v0040);
    env = stack[-1];
    if (v0040 == nil) goto v0012;
    v0040 = elt(env, 2); // " type=""real""> "
    v0040 = Lprinc(nil, v0040);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    env = stack[-1];
    goto v0011;

v0011:
    v0040 = stack[0];
    v0040 = Lprinc(nil, v0040);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    env = stack[-1];
    v0040 = elt(env, 5); // " </cn>"
    v0040 = Lprinc(nil, v0040);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    env = stack[-1];
    goto v0036;

v0036:
    v0040 = stack[0];
    if (!(symbolp(v0040))) goto v0046;
    v0040 = stack[0];
    v0132 = Lintern(nil, v0040);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    env = stack[-1];
    v0040 = qvalue(elt(env, 6)); // constants!*
    v0040 = Lmember(nil, v0132, v0040);
    if (v0040 == nil) goto v0125;
    v0040 = elt(env, 7); // "<cn type=""constant""> "
    fn = elt(env, 13); // printout
    v0040 = (*qfn1(fn))(qenv(fn), v0040);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    env = stack[-1];
    v0040 = stack[0];
    v0040 = Lprinc(nil, v0040);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    env = stack[-1];
    v0040 = elt(env, 5); // " </cn>"
    v0040 = Lprinc(nil, v0040);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    goto v0046;

v0046:
    v0040 = nil;
    { popv(2); return onevalue(v0040); }

v0125:
    v0040 = elt(env, 8); // "<ci"
    fn = elt(env, 13); // printout
    v0040 = (*qfn1(fn))(qenv(fn), v0040);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    env = stack[-1];
    v0040 = stack[0];
    fn = elt(env, 14); // listp
    v0040 = (*qfn1(fn))(qenv(fn), v0040);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    env = stack[-1];
    if (v0040 == nil) goto v0218;
    v0040 = elt(env, 9); // " type=""list""> "
    v0040 = Lprinc(nil, v0040);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    env = stack[-1];
    goto v0007;

v0007:
    v0040 = stack[0];
    v0040 = Lprinc(nil, v0040);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    env = stack[-1];
    v0040 = elt(env, 11); // " </ci>"
    v0040 = Lprinc(nil, v0040);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    goto v0046;

v0218:
    v0040 = stack[0];
    v0040 = Lsimple_vectorp(nil, v0040);
    env = stack[-1];
    if (v0040 == nil) goto v0017;
    v0040 = elt(env, 10); // " type=""vector""> "
    v0040 = Lprinc(nil, v0040);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    env = stack[-1];
    goto v0007;

v0017:
    v0040 = elt(env, 4); // "> "
    v0040 = Lprinc(nil, v0040);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    env = stack[-1];
    goto v0007;

v0012:
    v0040 = stack[0];
    v0040 = integerp(v0040);
    if (v0040 == nil) goto v0060;
    v0040 = elt(env, 3); // " type=""integer""> "
    v0040 = Lprinc(nil, v0040);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    env = stack[-1];
    goto v0011;

v0060:
    v0040 = elt(env, 4); // "> "
    v0040 = Lprinc(nil, v0040);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    env = stack[-1];
    goto v0011;
// error exit handlers
v0041:
    popv(2);
    return nil;
}



// Code for ldt!-tvar

static LispObject CC_ldtKtvar(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0059, v0060, v0055;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ldt-tvar");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0059 = v0000;
// end of prologue
    v0059 = qcar(v0059);
    v0059 = qcar(v0059);
    v0060 = v0059;
    v0059 = v0060;
    v0055 = elt(env, 1); // df
    if (!consp(v0059)) return onevalue(v0060);
    v0059 = qcar(v0059);
    if (!(v0059 == v0055)) return onevalue(v0060);
    v0059 = v0060;
    v0059 = qcdr(v0059);
    v0059 = qcar(v0059);
    return onevalue(v0059);
}



// Code for dm!-gt

static LispObject CC_dmKgt(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0011, v0013;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dm-gt");
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
    v0013 = v0001;
    v0011 = v0000;
// end of prologue
    fn = elt(env, 1); // dm!-difference
    v0011 = (*qfn2(fn))(qenv(fn), v0013, v0011);
    nil = C_nil;
    if (exception_pending()) goto v0012;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); // !:minusp
        return (*qfn1(fn))(qenv(fn), v0011);
    }
// error exit handlers
v0012:
    popv(1);
    return nil;
}



// Code for modminusp!:

static LispObject CC_modminuspT(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0055, v0061;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for modminusp:");
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
    v0055 = v0000;
// end of prologue
    v0061 = qvalue(elt(env, 1)); // !*balanced_mod
    if (v0061 == nil) goto v0058;
    v0061 = (LispObject)33; // 2
    v0055 = qcdr(v0055);
    v0055 = times2(v0061, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[0];
    v0061 = qvalue(elt(env, 2)); // current!-modulus
        popv(1);
        return Lgreaterp(nil, v0055, v0061);

v0058:
    v0055 = qvalue(elt(env, 3)); // nil
    { popv(1); return onevalue(v0055); }
// error exit handlers
v0016:
    popv(1);
    return nil;
}



// Code for vbcgcd

static LispObject CC_vbcgcd(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0031, v0029;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vbcgcd");
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
    v0029 = stack[-1];
    v0031 = (LispObject)-1599; // -100
    fn = elt(env, 4); // vbcsize
    v0031 = (*qfn2(fn))(qenv(fn), v0029, v0031);
    nil = C_nil;
    if (exception_pending()) goto v0130;
    env = stack[-2];
    if (v0031 == nil) goto v0011;
    v0029 = stack[0];
    v0031 = (LispObject)-1599; // -100
    fn = elt(env, 4); // vbcsize
    v0031 = (*qfn2(fn))(qenv(fn), v0029, v0031);
    nil = C_nil;
    if (exception_pending()) goto v0130;
    env = stack[-2];
    v0031 = (v0031 == nil ? lisp_true : nil);
    goto v0057;

v0057:
    if (v0031 == nil) goto v0219;
    v0031 = elt(env, 2); // (1 . 1)
    { popv(3); return onevalue(v0031); }

v0219:
    v0031 = stack[-1];
    v0029 = qcdr(v0031);
    v0031 = (LispObject)17; // 1
    if (v0029 == v0031) goto v0005;
    v0031 = qvalue(elt(env, 3)); // nil
    goto v0128;

v0128:
    if (v0031 == nil) goto v0054;
    v0031 = stack[-1];
    v0031 = qcar(v0031);
    v0031 = integerp(v0031);
    if (v0031 == nil) goto v0038;
    v0031 = stack[0];
    v0031 = qcar(v0031);
    v0031 = integerp(v0031);
    if (v0031 == nil) goto v0038;
    v0031 = stack[-1];
    v0029 = qcar(v0031);
    v0031 = stack[0];
    v0031 = qcar(v0031);
    v0029 = Lgcd(nil, v0029, v0031);
    nil = C_nil;
    if (exception_pending()) goto v0130;
    v0031 = (LispObject)17; // 1
    popv(3);
    return cons(v0029, v0031);

v0038:
    v0031 = stack[-1];
    v0029 = qcar(v0031);
    v0031 = stack[0];
    v0031 = qcar(v0031);
    fn = elt(env, 5); // gcdf!*
    v0029 = (*qfn2(fn))(qenv(fn), v0029, v0031);
    nil = C_nil;
    if (exception_pending()) goto v0130;
    v0031 = (LispObject)17; // 1
    popv(3);
    return cons(v0029, v0031);

v0054:
    v0029 = (LispObject)17; // 1
    v0031 = (LispObject)17; // 1
    popv(3);
    return cons(v0029, v0031);

v0005:
    v0031 = stack[0];
    v0029 = qcdr(v0031);
    v0031 = (LispObject)17; // 1
    v0031 = (v0029 == v0031 ? lisp_true : nil);
    goto v0128;

v0011:
    v0031 = qvalue(elt(env, 1)); // t
    goto v0057;
// error exit handlers
v0130:
    popv(3);
    return nil;
}



// Code for removeindices

static LispObject CC_removeindices(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0223, v0232;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for removeindices");
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
    v0223 = elt(env, 0); // removeindices
    if (!symbolp(v0223)) v0223 = nil;
    else { v0223 = qfastgets(v0223);
           if (v0223 != nil) { v0223 = elt(v0223, 53); // tracing
#ifdef RECORD_GET
             if (v0223 == SPID_NOPROP)
                record_get(elt(fastget_names, 53), 0),
                v0223 = nil;
             else record_get(elt(fastget_names, 53), 1),
                v0223 = lisp_true; }
           else record_get(elt(fastget_names, 53), 0); }
#else
             if (v0223 == SPID_NOPROP) v0223 = nil; else v0223 = lisp_true; }}
#endif
    if (v0223 == nil) goto v0113;
    stack[-4] = elt(env, 0); // removeindices
    stack[-1] = elt(env, 1); // "u= "
    stack[0] = stack[-3];
    v0232 = elt(env, 2); // " x= "
    v0223 = stack[-2];
    v0223 = list2(v0232, v0223);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-5];
    v0223 = list3star(stack[-4], stack[-1], stack[0], v0223);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-5];
    fn = elt(env, 6); // trwrite
    v0223 = (*qfn1(fn))(qenv(fn), v0223);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-5];
    goto v0113;

v0113:
    v0223 = stack[-2];
    if (v0223 == nil) goto v0128;
    v0223 = stack[-3];
    v0223 = Lsymbolp(nil, v0223);
    env = stack[-5];
    if (!(v0223 == nil)) goto v0135;
    v0223 = stack[-3];
    fn = elt(env, 7); // !*physopp
    v0223 = (*qfn1(fn))(qenv(fn), v0223);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-5];
    v0223 = (v0223 == nil ? lisp_true : nil);
    goto v0135;

v0135:
    if (!(v0223 == nil)) { LispObject res = stack[-3]; popv(6); return onevalue(res); }
    v0223 = stack[-2];
    if (!(symbolp(v0223))) goto v0098;
    v0223 = stack[-2];
    fn = elt(env, 8); // isanindex
    v0223 = (*qfn1(fn))(qenv(fn), v0223);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-5];
    if (!(v0223 == nil)) goto v0098;

v0002:
    v0232 = elt(env, 0); // removeindices
    v0223 = elt(env, 4); // "invalid arguments to removeindices"
    fn = elt(env, 9); // rederr2
    v0223 = (*qfn2(fn))(qenv(fn), v0232, v0223);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-5];
    goto v0097;

v0097:
    v0223 = stack[-3];
    v0223 = qcar(v0223);
    stack[0] = v0223;
    v0223 = stack[-3];
    v0223 = qcdr(v0223);
    stack[-3] = v0223;
    v0223 = stack[-3];
    if (v0223 == nil) { LispObject res = stack[0]; popv(6); return onevalue(res); }
    v0223 = stack[-2];
    if (symbolp(v0223)) goto v0205;
    v0223 = stack[-2];
    stack[-1] = v0223;
    goto v0212;

v0212:
    v0223 = stack[-1];
    if (v0223 == nil) goto v0132;
    v0223 = stack[-1];
    v0223 = qcar(v0223);
    v0232 = v0223;
    v0223 = stack[-3];
    v0223 = Ldelete(nil, v0232, v0223);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-5];
    stack[-3] = v0223;
    v0223 = stack[-1];
    v0223 = qcdr(v0223);
    stack[-1] = v0223;
    goto v0212;

v0132:
    v0223 = stack[-3];
    if (v0223 == nil) { LispObject res = stack[0]; popv(6); return onevalue(res); }
    v0232 = stack[0];
    v0223 = stack[-3];
    popv(6);
    return cons(v0232, v0223);

v0205:
    v0232 = stack[-2];
    v0223 = stack[-3];
    v0223 = Ldelete(nil, v0232, v0223);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    stack[-3] = v0223;
    goto v0132;

v0098:
    v0223 = stack[-2];
    fn = elt(env, 10); // idlistp
    v0223 = (*qfn1(fn))(qenv(fn), v0223);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-5];
    if (v0223 == nil) goto v0097;
    v0223 = stack[-2];
    fn = elt(env, 11); // areallindices
    v0223 = (*qfn1(fn))(qenv(fn), v0223);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-5];
    if (v0223 == nil) goto v0002;
    else goto v0097;

v0128:
    v0223 = qvalue(elt(env, 3)); // t
    goto v0135;
// error exit handlers
v0082:
    popv(6);
    return nil;
}



setup_type const u13_setup[] =
{
    {"pappend",                 too_few_2,      CC_pappend,    wrong_no_2},
    {"b:extmult",               too_few_2,      CC_bTextmult,  wrong_no_2},
    {"invbf",                   CC_invbf,       too_many_1,    wrong_no_1},
    {"multd*",                  too_few_2,      CC_multdH,     wrong_no_2},
    {"rl_ordatp",               too_few_2,      CC_rl_ordatp,  wrong_no_2},
    {"matrixrowrd",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_matrixrowrd},
    {"bind",                    too_few_2,      CC_bind,       wrong_no_2},
    {"greaterp:",               too_few_2,      CC_greaterpT,  wrong_no_2},
    {"noncommuting",            too_few_2,      CC_noncommuting,wrong_no_2},
    {"formprogn",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_formprogn},
    {"flatsizec",               CC_flatsizec,   too_many_1,    wrong_no_1},
    {"crprcd2",                 too_few_2,      CC_crprcd2,    wrong_no_2},
    {"updtemplate",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_updtemplate},
    {"qqe_simplterm",           CC_qqe_simplterm,too_many_1,   wrong_no_1},
    {"setunion",                too_few_2,      CC_setunion,   wrong_no_2},
    {"ibalp_clausep",           CC_ibalp_clausep,too_many_1,   wrong_no_1},
    {"opmtch",                  CC_opmtch,      too_many_1,    wrong_no_1},
    {"termordp!",               too_few_2,      CC_termordpB,  wrong_no_2},
    {"*sqprint",                CC_Hsqprint,    too_many_1,    wrong_no_1},
    {"all_edge",                too_few_2,      CC_all_edge,   wrong_no_2},
    {"simp-sign",               CC_simpKsign,   too_many_1,    wrong_no_1},
    {"procstat",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_procstat},
    {"gperm0",                  CC_gperm0,      too_many_1,    wrong_no_1},
    {"ord2",                    too_few_2,      CC_ord2,       wrong_no_2},
    {"mri_pasf2mriat",          too_few_2,      CC_mri_pasf2mriat,wrong_no_2},
    {"qqe_id-nyt-branchq",      CC_qqe_idKnytKbranchq,too_many_1,wrong_no_1},
    {"ibalp_redclause",         CC_ibalp_redclause,too_many_1, wrong_no_1},
    {"sfto_reorder",            too_few_2,      CC_sfto_reorder,wrong_no_2},
    {"exchk1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_exchk1},
    {"find_sub_df",             too_few_2,      CC_find_sub_df,wrong_no_2},
    {"mkinds",                  too_few_2,      CC_mkinds,     wrong_no_2},
    {"assert_uninstall_all",    wrong_no_na,    wrong_no_nb,   (n_args *)CC_assert_uninstall_all},
    {"nzeros",                  CC_nzeros,      too_many_1,    wrong_no_1},
    {"subsetp",                 too_few_2,      CC_subsetp,    wrong_no_2},
    {"wi_new",                  CC_wi_new,      too_many_1,    wrong_no_1},
    {"simpatom",                CC_simpatom,    too_many_1,    wrong_no_1},
    {"nb",                      CC_nb,          too_many_1,    wrong_no_1},
    {"rl_smupdknowl",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_rl_smupdknowl},
    {"ibalp_simpterm",          CC_ibalp_simpterm,too_many_1,  wrong_no_1},
    {"cgp_number",              CC_cgp_number,  too_many_1,    wrong_no_1},
    {"omsir",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_omsir},
    {"maprin",                  CC_maprin,      too_many_1,    wrong_no_1},
    {"redcodmat",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_redcodmat},
    {"xord_gradlex",            too_few_2,      CC_xord_gradlex,wrong_no_2},
    {"symbid",                  too_few_2,      CC_symbid,     wrong_no_2},
    {"getmatelem",              CC_getmatelem,  too_many_1,    wrong_no_1},
    {"dl_get2",                 too_few_2,      CC_dl_get2,    wrong_no_2},
    {"degree-in-variable",      too_few_2,      CC_degreeKinKvariable,wrong_no_2},
    {"delete_from_alglist",     too_few_2,      CC_delete_from_alglist,wrong_no_2},
    {"tmsf",                    CC_tmsf,        too_many_1,    wrong_no_1},
    {"sq2sspl",                 too_few_2,      CC_sq2sspl,    wrong_no_2},
    {"ibalp_lenisone",          CC_ibalp_lenisone,too_many_1,  wrong_no_1},
    {"vdp_zero?",               CC_vdp_zeroW,   too_many_1,    wrong_no_1},
    {"attributesml",            too_few_2,      CC_attributesml,wrong_no_2},
    {"findnewvars",             CC_findnewvars, too_many_1,    wrong_no_1},
    {"bcquot",                  too_few_2,      CC_bcquot,     wrong_no_2},
    {"guesspftype",             CC_guesspftype, too_many_1,    wrong_no_1},
    {"listeval",                too_few_2,      CC_listeval,   wrong_no_2},
    {"actual_alst",             too_few_2,      CC_actual_alst,wrong_no_2},
    {"mkprogn",                 too_few_2,      CC_mkprogn,    wrong_no_2},
    {"pv_times1",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_pv_times1},
    {"remove-free-vars*",       CC_removeKfreeKvarsH,too_many_1,wrong_no_1},
    {"dvfsf_mk2",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_dvfsf_mk2},
    {"constsml",                CC_constsml,    too_many_1,    wrong_no_1},
    {"ldt-tvar",                CC_ldtKtvar,    too_many_1,    wrong_no_1},
    {"dm-gt",                   too_few_2,      CC_dmKgt,      wrong_no_2},
    {"modminusp:",              CC_modminuspT,  too_many_1,    wrong_no_1},
    {"vbcgcd",                  too_few_2,      CC_vbcgcd,     wrong_no_2},
    {"removeindices",           too_few_2,      CC_removeindices,wrong_no_2},
    {NULL, (one_args *)"u13", (two_args *)"3574 8013131 3035304", 0}
};

// end of generated code
