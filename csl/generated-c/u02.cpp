
// $destdir/u02.c        Machine generated C code

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



// Code for delcp

static LispObject CC_delcp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0001;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for delcp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0001 = v0000;
// end of prologue
    if (!symbolp(v0001)) v0001 = nil;
    else { v0001 = qfastgets(v0001);
           if (v0001 != nil) { v0001 = elt(v0001, 40); // delchar
#ifdef RECORD_GET
             if (v0001 == SPID_NOPROP)
                record_get(elt(fastget_names, 40), 0),
                v0001 = nil;
             else record_get(elt(fastget_names, 40), 1),
                v0001 = lisp_true; }
           else record_get(elt(fastget_names, 40), 0); }
#else
             if (v0001 == SPID_NOPROP) v0001 = nil; else v0001 = lisp_true; }}
#endif
    return onevalue(v0001);
}



// Code for mchk

static LispObject CC_mchk(LispObject env,
                         LispObject v0000, LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0063, v0064, v0065;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mchk");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0002,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    stack[-3] = v0002;
    stack[-4] = v0000;
// end of prologue

v0066:
    v0064 = stack[-4];
    v0063 = stack[-3];
    if (equal(v0064, v0063)) goto v0067;
    v0064 = stack[-4];
    v0063 = elt(env, 2); // !*sq
    if (!consp(v0064)) goto v0068;
    v0064 = qcar(v0064);
    if (!(v0064 == v0063)) goto v0068;
    v0063 = stack[-4];
    v0063 = qcdr(v0063);
    v0063 = qcar(v0063);
    fn = elt(env, 7); // prepsqxx
    v0063 = (*qfn1(fn))(qenv(fn), v0063);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-6];
    stack[-4] = v0063;
    goto v0066;

v0068:
    v0064 = stack[-3];
    v0063 = elt(env, 2); // !*sq
    if (!consp(v0064)) goto v0070;
    v0064 = qcar(v0064);
    if (!(v0064 == v0063)) goto v0070;
    v0063 = stack[-3];
    v0063 = qcdr(v0063);
    v0063 = qcar(v0063);
    fn = elt(env, 7); // prepsqxx
    v0063 = (*qfn1(fn))(qenv(fn), v0063);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-6];
    stack[-3] = v0063;
    goto v0066;

v0070:
    v0063 = stack[-3];
    if (!consp(v0063)) goto v0071;
    v0063 = stack[-4];
    if (!consp(v0063)) goto v0072;
    v0063 = stack[-3];
    v0064 = qcar(v0063);
    v0063 = elt(env, 5); // difference
    if (v0064 == v0063) goto v0073;
    v0063 = stack[-4];
    v0063 = qcar(v0063);
    if (!symbolp(v0063)) v0063 = nil;
    else { v0063 = qfastgets(v0063);
           if (v0063 != nil) { v0063 = elt(v0063, 8); // dname
#ifdef RECORD_GET
             if (v0063 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v0063 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v0063 == SPID_NOPROP) v0063 = nil; }}
#endif
    if (!(v0063 == nil)) goto v0074;
    v0063 = stack[-3];
    v0063 = qcar(v0063);
    if (!symbolp(v0063)) v0063 = nil;
    else { v0063 = qfastgets(v0063);
           if (v0063 != nil) { v0063 = elt(v0063, 8); // dname
#ifdef RECORD_GET
             if (v0063 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v0063 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v0063 == SPID_NOPROP) v0063 = nil; }}
#endif
    if (!(v0063 == nil)) goto v0074;
    v0063 = stack[-4];
    v0064 = qcar(v0063);
    v0063 = stack[-3];
    v0063 = qcar(v0063);
    if (v0064 == v0063) goto v0075;
    v0063 = stack[-3];
    v0064 = qcar(v0063);
    v0063 = qvalue(elt(env, 3)); // frlis!*
    v0063 = Lmemq(nil, v0064, v0063);
    if (v0063 == nil) goto v0076;
    v0063 = stack[-4];
    v0065 = qcar(v0063);
    v0063 = stack[-3];
    v0064 = qcar(v0063);
    v0063 = stack[-4];
    v0063 = qcdr(v0063);
    stack[0] = Lsubst(nil, 3, v0065, v0064, v0063);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-6];
    v0063 = stack[-4];
    v0065 = qcar(v0063);
    v0063 = stack[-3];
    v0064 = qcar(v0063);
    v0063 = stack[-3];
    v0063 = qcdr(v0063);
    v0064 = Lsubst(nil, 3, v0065, v0064, v0063);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-6];
    v0063 = stack[-4];
    v0063 = qcar(v0063);
    fn = elt(env, 8); // mcharg
    v0063 = (*qfnn(fn))(qenv(fn), 3, stack[0], v0064, v0063);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-6];
    stack[-5] = v0063;
    v0063 = stack[-5];
    if (v0063 == nil) goto v0077;
    v0063 = stack[-5];
    v0063 = qcar(v0063);
    v0064 = stack[-3];
    v0065 = qcar(v0064);
    v0064 = stack[-4];
    v0064 = qcar(v0064);
    v0063 = acons(v0065, v0064, v0063);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-6];
    v0063 = ncons(v0063);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-6];
    stack[-1] = v0063;
    stack[-2] = v0063;
    goto v0078;

v0078:
    v0063 = stack[-5];
    v0063 = qcdr(v0063);
    stack[-5] = v0063;
    v0063 = stack[-5];
    if (v0063 == nil) { LispObject res = stack[-2]; popv(7); return onevalue(res); }
    stack[0] = stack[-1];
    v0063 = stack[-5];
    v0063 = qcar(v0063);
    v0064 = stack[-3];
    v0065 = qcar(v0064);
    v0064 = stack[-4];
    v0064 = qcar(v0064);
    v0063 = acons(v0065, v0064, v0063);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-6];
    v0063 = ncons(v0063);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-6];
    v0063 = Lrplacd(nil, stack[0], v0063);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-6];
    v0063 = stack[-1];
    v0063 = qcdr(v0063);
    stack[-1] = v0063;
    goto v0078;

v0077:
    v0063 = qvalue(elt(env, 1)); // nil
    { popv(7); return onevalue(v0063); }

v0076:
    v0063 = stack[-4];
    v0064 = qcar(v0063);
    v0063 = elt(env, 4); // minus
    if (v0064 == v0063) goto v0079;
    v0064 = stack[-4];
    v0063 = stack[-3];
    {
        popv(7);
        fn = elt(env, 9); // mchkopt
        return (*qfn2(fn))(qenv(fn), v0064, v0063);
    }

v0079:
    v0063 = stack[-4];
    v0063 = qcdr(v0063);
    v0064 = qcar(v0063);
    v0063 = stack[-3];
    {
        popv(7);
        fn = elt(env, 10); // mchkminus
        return (*qfn2(fn))(qenv(fn), v0064, v0063);
    }

v0075:
    v0063 = stack[-4];
    v0065 = qcdr(v0063);
    v0063 = stack[-3];
    v0064 = qcdr(v0063);
    v0063 = stack[-4];
    v0063 = qcar(v0063);
    {
        popv(7);
        fn = elt(env, 8); // mcharg
        return (*qfnn(fn))(qenv(fn), 3, v0065, v0064, v0063);
    }

v0074:
    v0063 = qvalue(elt(env, 1)); // nil
    { popv(7); return onevalue(v0063); }

v0073:
    stack[-1] = elt(env, 6); // plus
    v0063 = stack[-3];
    v0063 = qcdr(v0063);
    stack[0] = qcar(v0063);
    v0064 = elt(env, 4); // minus
    v0063 = stack[-3];
    v0063 = qcdr(v0063);
    v0063 = qcdr(v0063);
    v0063 = qcar(v0063);
    v0063 = list2(v0064, v0063);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-6];
    v0063 = list3(stack[-1], stack[0], v0063);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-6];
    stack[-3] = v0063;
    goto v0066;

v0072:
    v0063 = stack[-4];
    if (!(is_number(v0063))) goto v0080;
    v0064 = stack[-4];
    v0063 = (LispObject)1; // 0
    v0063 = (LispObject)lessp2(v0064, v0063);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    v0063 = v0063 ? lisp_true : nil;
    env = stack[-6];
    if (v0063 == nil) goto v0080;
    v0064 = stack[-3];
    v0063 = elt(env, 4); // minus
    if (!consp(v0064)) goto v0080;
    v0064 = qcar(v0064);
    if (!(v0064 == v0063)) goto v0080;
    stack[0] = elt(env, 4); // minus
    v0063 = stack[-4];
    v0063 = negate(v0063);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-6];
    v0063 = list2(stack[0], v0063);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-6];
    stack[-4] = v0063;
    goto v0066;

v0080:
    v0064 = stack[-4];
    v0063 = stack[-3];
    {
        popv(7);
        fn = elt(env, 9); // mchkopt
        return (*qfn2(fn))(qenv(fn), v0064, v0063);
    }

v0071:
    v0064 = stack[-3];
    v0063 = qvalue(elt(env, 3)); // frlis!*
    v0063 = Lmemq(nil, v0064, v0063);
    if (v0063 == nil) goto v0081;
    v0064 = stack[-3];
    v0063 = stack[-4];
    v0063 = cons(v0064, v0063);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-6];
    v0063 = ncons(v0063);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    popv(7);
    return ncons(v0063);

v0081:
    v0063 = qvalue(elt(env, 1)); // nil
    { popv(7); return onevalue(v0063); }

v0067:
    v0063 = qvalue(elt(env, 1)); // nil
    popv(7);
    return ncons(v0063);
// error exit handlers
v0069:
    popv(7);
    return nil;
}



// Code for get!+vec!+entry

static LispObject CC_getLvecLentry(LispObject env,
                         LispObject v0000, LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0084, v0085;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for get+vec+entry");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0084 = v0002;
    v0085 = v0000;
// end of prologue
    {
        fn = elt(env, 1); // nth
        return (*qfn2(fn))(qenv(fn), v0085, v0084);
    }
}



// Code for qqe_qoptailp

static LispObject CC_qqe_qoptailp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0061, v0062;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qqe_qoptailp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0061 = v0000;
// end of prologue
    v0062 = v0061;
    v0061 = elt(env, 1); // (rtail ltail)
    v0061 = Lmemq(nil, v0062, v0061);
    if (v0061 == nil) goto v0086;
    v0061 = qvalue(elt(env, 2)); // t
    return onevalue(v0061);

v0086:
    v0061 = nil;
    return onevalue(v0061);
}



// Code for ibalp_cec

static LispObject CC_ibalp_cec(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0087;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_cec");
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

v0001:
    v0087 = stack[0];
    if (v0087 == nil) goto v0088;
    v0087 = stack[0];
    v0087 = qcar(v0087);
    fn = elt(env, 2); // ibalp_emptyclausep
    v0087 = (*qfn1(fn))(qenv(fn), v0087);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-1];
    if (v0087 == nil) goto v0090;
    v0087 = stack[0];
    v0087 = qcar(v0087);
    { popv(2); return onevalue(v0087); }

v0090:
    v0087 = stack[0];
    v0087 = qcdr(v0087);
    stack[0] = v0087;
    goto v0001;

v0088:
    v0087 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0087); }
// error exit handlers
v0089:
    popv(2);
    return nil;
}



// Code for minusf

static LispObject CC_minusf(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0071, v0094;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for minusf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0071 = v0000;
// end of prologue

v0001:
    v0094 = v0071;
    if (v0094 == nil) goto v0088;
    v0094 = v0071;
    if (!consp(v0094)) goto v0061;
    v0094 = v0071;
    v0094 = qcar(v0094);
    v0094 = (consp(v0094) ? nil : lisp_true);
    goto v0085;

v0085:
    if (v0094 == nil) goto v0095;
    v0094 = v0071;
    if (!consp(v0094)) goto v0096;
    v0094 = v0071;
    v0094 = qcar(v0094);
    if (!symbolp(v0094)) v0094 = nil;
    else { v0094 = qfastgets(v0094);
           if (v0094 != nil) { v0094 = elt(v0094, 30); // minusp
#ifdef RECORD_GET
             if (v0094 != SPID_NOPROP)
                record_get(elt(fastget_names, 30), 1);
             else record_get(elt(fastget_names, 30), 0),
                v0094 = nil; }
           else record_get(elt(fastget_names, 30), 0); }
#else
             if (v0094 == SPID_NOPROP) v0094 = nil; }}
#endif
        return Lapply1(nil, v0094, v0071);

v0096:
    v0094 = v0071;
    v0071 = (LispObject)1; // 0
        return Llessp(nil, v0094, v0071);

v0095:
    v0071 = qcar(v0071);
    v0071 = qcdr(v0071);
    goto v0001;

v0061:
    v0094 = qvalue(elt(env, 2)); // t
    goto v0085;

v0088:
    v0071 = qvalue(elt(env, 1)); // nil
    return onevalue(v0071);
}



// Code for reorder

static LispObject CC_reorder(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0103, v0104;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for reorder");
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
    goto v0105;

v0105:
    v0103 = stack[-1];
    if (!consp(v0103)) goto v0061;
    v0103 = stack[-1];
    v0103 = qcar(v0103);
    v0103 = (consp(v0103) ? nil : lisp_true);
    goto v0085;

v0085:
    if (v0103 == nil) goto v0106;
    v0103 = stack[-1];
    v0104 = v0103;
    goto v0067;

v0067:
    v0103 = stack[-2];
    if (v0103 == nil) { popv(4); return onevalue(v0104); }
    v0103 = stack[-2];
    v0103 = qcar(v0103);
    fn = elt(env, 2); // raddf
    v0103 = (*qfn2(fn))(qenv(fn), v0103, v0104);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-3];
    v0104 = v0103;
    v0103 = stack[-2];
    v0103 = qcdr(v0103);
    stack[-2] = v0103;
    goto v0067;

v0106:
    v0103 = stack[-1];
    v0103 = qcar(v0103);
    stack[0] = qcar(v0103);
    v0103 = stack[-1];
    v0103 = qcar(v0103);
    v0103 = qcdr(v0103);
    v0103 = CC_reorder(env, v0103);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-3];
    fn = elt(env, 3); // rmultpf
    v0104 = (*qfn2(fn))(qenv(fn), stack[0], v0103);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-3];
    v0103 = stack[-2];
    v0103 = cons(v0104, v0103);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-3];
    stack[-2] = v0103;
    v0103 = stack[-1];
    v0103 = qcdr(v0103);
    stack[-1] = v0103;
    goto v0105;

v0061:
    v0103 = qvalue(elt(env, 1)); // t
    goto v0085;
// error exit handlers
v0107:
    popv(4);
    return nil;
}



// Code for get_token

static LispObject CC_get_token(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0068, v0110;
    argcheck(nargs, 0, "get_token");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for get_token");
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
    v0068 = qvalue(elt(env, 1)); // nil
    stack[0] = v0068;
    goto v0083;

v0083:
    v0110 = Lreadch(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-1];
    qvalue(elt(env, 2)) = v0110; // ch
    v0068 = elt(env, 3); // !>
    if (v0110 == v0068) goto v0111;
    v0110 = qvalue(elt(env, 2)); // ch
    v0068 = stack[0];
    v0068 = cons(v0110, v0068);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-1];
    stack[0] = v0068;
    goto v0083;

v0111:
    v0110 = elt(env, 4); // !$
    v0068 = stack[0];
    popv(2);
    return cons(v0110, v0068);
// error exit handlers
v0102:
    popv(2);
    return nil;
}



// Code for csl_normbf

static LispObject CC_csl_normbf(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0119, v0120, v0121;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for csl_normbf");
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
    stack[-3] = nil;
    v0119 = stack[-2];
    v0119 = qcdr(v0119);
    v0120 = qcar(v0119);
    stack[0] = v0120;
    v0119 = (LispObject)1; // 0
    if (v0120 == v0119) goto v0066;
    v0120 = stack[0];
    v0119 = (LispObject)1; // 0
    v0119 = (LispObject)lessp2(v0120, v0119);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    v0119 = v0119 ? lisp_true : nil;
    env = stack[-4];
    if (v0119 == nil) goto v0123;
    v0119 = stack[0];
    v0119 = negate(v0119);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-4];
    stack[0] = v0119;
    v0119 = qvalue(elt(env, 2)); // t
    stack[-3] = v0119;
    goto v0123;

v0123:
    v0119 = stack[0];
    fn = elt(env, 4); // lsd
    v0119 = (*qfn1(fn))(qenv(fn), v0119);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-4];
    stack[-1] = v0119;
    v0119 = stack[-1];
    v0119 = negate(v0119);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-4];
    fn = elt(env, 5); // lshift
    v0119 = (*qfn2(fn))(qenv(fn), stack[0], v0119);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-4];
    stack[0] = v0119;
    v0119 = stack[-3];
    if (v0119 == nil) goto v0124;
    v0119 = stack[0];
    v0119 = negate(v0119);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-4];
    stack[0] = v0119;
    goto v0124;

v0124:
    v0120 = stack[-1];
    v0119 = stack[-2];
    v0119 = qcdr(v0119);
    v0119 = qcdr(v0119);
    v0119 = plus2(v0120, v0119);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-4];
    stack[-1] = v0119;
    v0121 = elt(env, 3); // !:rd!:
    v0120 = stack[0];
    v0119 = stack[-1];
    popv(5);
    return list2star(v0121, v0120, v0119);

v0066:
    v0119 = elt(env, 1); // (!:rd!: 0 . 0)
    { popv(5); return onevalue(v0119); }
// error exit handlers
v0122:
    popv(5);
    return nil;
}



// Code for !*q2a

static LispObject CC_Hq2a(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0066, v0082;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *q2a");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0066 = v0000;
// end of prologue
    v0082 = v0066;
    v0066 = qvalue(elt(env, 1)); // !*nosq
    {
        fn = elt(env, 2); // !*q2a1
        return (*qfn2(fn))(qenv(fn), v0082, v0066);
    }
}



// Code for i2rd!*

static LispObject CC_i2rdH(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0086;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for i2rd*");
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
    v0086 = v0000;
// end of prologue
    fn = elt(env, 1); // chkint!*
    v0086 = (*qfn1(fn))(qenv(fn), v0086);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); // mkround
        return (*qfn1(fn))(qenv(fn), v0086);
    }
// error exit handlers
v0105:
    popv(1);
    return nil;
}



// Code for addf

static LispObject CC_addf(LispObject env,
                         LispObject v0000, LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0135, v0136, v0137;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for addf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0002,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0002;
    stack[-1] = v0000;
// end of prologue
    stack[-2] = nil;
    goto v0088;

v0088:
    v0135 = stack[-1];
    if (v0135 == nil) goto v0082;
    v0135 = stack[0];
    if (v0135 == nil) goto v0061;
    v0135 = stack[-1];
    if (!consp(v0135)) goto v0123;
    v0135 = stack[-1];
    v0135 = qcar(v0135);
    v0135 = (consp(v0135) ? nil : lisp_true);
    goto v0087;

v0087:
    if (v0135 == nil) goto v0118;
    v0136 = stack[-1];
    v0135 = stack[0];
    fn = elt(env, 3); // addd
    v0135 = (*qfn2(fn))(qenv(fn), v0136, v0135);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-3];
    goto v0138;

v0138:
    v0136 = stack[-2];
    if (v0136 == nil) { popv(4); return onevalue(v0135); }
    v0136 = stack[-2];
    v0136 = qcdr(v0136);
    stack[-1] = v0136;
    v0136 = stack[-2];
    v0135 = Lrplacd(nil, v0136, v0135);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-3];
    v0135 = stack[-2];
    v0136 = stack[-1];
    stack[-2] = v0136;
    goto v0138;

v0118:
    v0135 = stack[0];
    if (!consp(v0135)) goto v0139;
    v0135 = stack[0];
    v0135 = qcar(v0135);
    v0135 = (consp(v0135) ? nil : lisp_true);
    goto v0100;

v0100:
    if (v0135 == nil) goto v0140;
    v0136 = stack[0];
    v0135 = stack[-1];
    fn = elt(env, 3); // addd
    v0135 = (*qfn2(fn))(qenv(fn), v0136, v0135);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-3];
    goto v0138;

v0140:
    v0135 = stack[-1];
    v0135 = qcar(v0135);
    v0136 = qcar(v0135);
    v0135 = stack[0];
    v0135 = qcar(v0135);
    v0135 = qcar(v0135);
    if (equal(v0136, v0135)) goto v0072;
    v0135 = stack[-1];
    v0135 = qcar(v0135);
    v0136 = qcar(v0135);
    v0135 = stack[0];
    v0135 = qcar(v0135);
    v0135 = qcar(v0135);
    fn = elt(env, 4); // ordpp
    v0135 = (*qfn2(fn))(qenv(fn), v0136, v0135);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-3];
    if (v0135 == nil) goto v0141;
    v0135 = stack[-1];
    v0136 = qcar(v0135);
    v0135 = stack[-2];
    v0135 = cons(v0136, v0135);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-3];
    stack[-2] = v0135;
    v0135 = stack[-1];
    v0135 = qcdr(v0135);
    stack[-1] = v0135;
    goto v0088;

v0141:
    v0135 = stack[0];
    v0136 = qcar(v0135);
    v0135 = stack[-2];
    v0135 = cons(v0136, v0135);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-3];
    stack[-2] = v0135;
    v0135 = stack[0];
    v0135 = qcdr(v0135);
    stack[0] = v0135;
    goto v0088;

v0072:
    v0135 = stack[-1];
    v0135 = qcar(v0135);
    v0136 = qcdr(v0135);
    v0135 = stack[0];
    v0135 = qcar(v0135);
    v0135 = qcdr(v0135);
    v0135 = CC_addf(env, v0136, v0135);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-3];
    v0136 = v0135;
    if (v0136 == nil) goto v0142;
    v0136 = stack[-1];
    v0136 = qcar(v0136);
    v0137 = qcar(v0136);
    v0136 = v0135;
    v0135 = stack[-2];
    v0135 = acons(v0137, v0136, v0135);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-3];
    stack[-2] = v0135;
    goto v0142;

v0142:
    v0135 = stack[-1];
    v0135 = qcdr(v0135);
    stack[-1] = v0135;
    v0135 = stack[0];
    v0135 = qcdr(v0135);
    stack[0] = v0135;
    goto v0088;

v0139:
    v0135 = qvalue(elt(env, 1)); // t
    goto v0100;

v0123:
    v0135 = qvalue(elt(env, 1)); // t
    goto v0087;

v0061:
    v0135 = stack[-1];
    goto v0138;

v0082:
    v0135 = stack[0];
    goto v0138;
// error exit handlers
v0036:
    popv(4);
    return nil;
}



// Code for aeval!*

static LispObject CC_aevalH(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0085, v0061;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for aeval*");
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
    v0085 = qvalue(elt(env, 1)); // nil
    v0085 = ncons(v0085);
    nil = C_nil;
    if (exception_pending()) goto v0109;
    env = stack[-1];
    qvalue(elt(env, 2)) = v0085; // alglist!*
    v0061 = stack[0];
    v0085 = qvalue(elt(env, 1)); // nil
    {
        popv(2);
        fn = elt(env, 3); // reval1
        return (*qfn2(fn))(qenv(fn), v0061, v0085);
    }
// error exit handlers
v0109:
    popv(2);
    return nil;
}



// Code for adddm

static LispObject CC_adddm(LispObject env,
                         LispObject v0000, LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0147, v0107, v0053;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for adddm");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0002,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// copy arguments values to proper place
    v0107 = v0002;
    v0053 = v0000;
// end of prologue
    v0147 = v0053;
    if (!consp(v0147)) goto v0125;
    v0147 = qvalue(elt(env, 1)); // nil
    goto v0067;

v0067:
    if (v0147 == nil) goto v0148;
    v0147 = v0053;
    v0147 = plus2(v0147, v0107);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[0];
    v0107 = qvalue(elt(env, 2)); // dmode!*
    if (v0107 == nil) goto v0115;
    v0107 = qvalue(elt(env, 2)); // dmode!*
    if (!symbolp(v0107)) v0107 = nil;
    else { v0107 = qfastgets(v0107);
           if (v0107 != nil) { v0107 = elt(v0107, 5); // convert
#ifdef RECORD_GET
             if (v0107 == SPID_NOPROP)
                record_get(elt(fastget_names, 5), 0),
                v0107 = nil;
             else record_get(elt(fastget_names, 5), 1),
                v0107 = lisp_true; }
           else record_get(elt(fastget_names, 5), 0); }
#else
             if (v0107 == SPID_NOPROP) v0107 = nil; else v0107 = lisp_true; }}
#endif
    v0107 = (v0107 == nil ? lisp_true : nil);
    goto v0106;

v0106:
    if (v0107 == nil) goto v0149;
    {
        popv(1);
        fn = elt(env, 5); // !*n2f
        return (*qfn1(fn))(qenv(fn), v0147);
    }

v0149:
    v0107 = qvalue(elt(env, 2)); // dmode!*
    if (!symbolp(v0107)) v0107 = nil;
    else { v0107 = qfastgets(v0107);
           if (v0107 != nil) { v0107 = elt(v0107, 34); // i2d
#ifdef RECORD_GET
             if (v0107 != SPID_NOPROP)
                record_get(elt(fastget_names, 34), 1);
             else record_get(elt(fastget_names, 34), 0),
                v0107 = nil; }
           else record_get(elt(fastget_names, 34), 0); }
#else
             if (v0107 == SPID_NOPROP) v0107 = nil; }}
#endif
    v0147 = Lapply1(nil, v0107, v0147);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 6); // int!-equiv!-chk
        return (*qfn1(fn))(qenv(fn), v0147);
    }

v0115:
    v0107 = qvalue(elt(env, 3)); // t
    goto v0106;

v0148:
    v0147 = elt(env, 4); // plus
    {
        popv(1);
        fn = elt(env, 7); // dcombine
        return (*qfnn(fn))(qenv(fn), 3, v0053, v0107, v0147);
    }

v0125:
    v0147 = v0107;
    v0147 = (consp(v0147) ? nil : lisp_true);
    goto v0067;
// error exit handlers
v0054:
    popv(1);
    return nil;
}



// Code for mo!=sprod

static LispObject CC_moMsprod(LispObject env,
                         LispObject v0000, LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0140, v0103, v0104;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mo=sprod");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0002,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0002;
    stack[-1] = v0000;
// end of prologue
    v0104 = nil;
    goto v0088;

v0088:
    v0140 = stack[-1];
    if (v0140 == nil) goto v0062;
    v0140 = stack[0];
    v0140 = (v0140 == nil ? lisp_true : nil);
    goto v0061;

v0061:
    if (v0140 == nil) goto v0096;
    v0140 = (LispObject)1; // 0
    goto v0125;

v0125:
    v0103 = v0104;
    if (v0103 == nil) { popv(3); return onevalue(v0140); }
    v0103 = v0104;
    v0103 = qcar(v0103);
    v0140 = (LispObject)(int32_t)((int32_t)v0103 + (int32_t)v0140 - TAG_FIXNUM);
    v0103 = v0104;
    v0103 = qcdr(v0103);
    v0104 = v0103;
    goto v0125;

v0096:
    v0140 = stack[-1];
    v0103 = qcar(v0140);
    v0140 = stack[0];
    v0140 = qcar(v0140);
    v0140 = fixnum_of_int((int32_t)(int_of_fixnum(v0103) * int_of_fixnum(v0140)));
    v0103 = v0104;
    v0140 = cons(v0140, v0103);
    nil = C_nil;
    if (exception_pending()) goto v0147;
    env = stack[-2];
    v0104 = v0140;
    v0140 = stack[-1];
    v0140 = qcdr(v0140);
    stack[-1] = v0140;
    v0140 = stack[0];
    v0140 = qcdr(v0140);
    stack[0] = v0140;
    goto v0088;

v0062:
    v0140 = qvalue(elt(env, 1)); // t
    goto v0061;
// error exit handlers
v0147:
    popv(3);
    return nil;
}



// Code for sieve_pv

static LispObject CC_sieve_pv(LispObject env,
                         LispObject v0000, LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0085, v0061, v0062;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sieve_pv");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0085 = v0002;
    v0061 = v0000;
// end of prologue
    v0062 = v0061;
    v0061 = v0085;
    v0085 = qvalue(elt(env, 1)); // t
    {
        fn = elt(env, 2); // sieve_pv0
        return (*qfnn(fn))(qenv(fn), 3, v0062, v0061, v0085);
    }
}



// Code for general!-modular!-plus

static LispObject CC_generalKmodularKplus(LispObject env,
                         LispObject v0000, LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0093, v0068;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for general-modular-plus");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0002,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0093 = v0002;
    v0068 = v0000;
// end of prologue
    v0093 = plus2(v0068, v0093);
    nil = C_nil;
    if (exception_pending()) goto v0101;
    env = stack[-1];
    stack[0] = v0093;
    v0068 = stack[0];
    v0093 = qvalue(elt(env, 1)); // current!-modulus
    v0093 = (LispObject)geq2(v0068, v0093);
    nil = C_nil;
    if (exception_pending()) goto v0101;
    v0093 = v0093 ? lisp_true : nil;
    env = stack[-1];
    if (v0093 == nil) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    v0068 = stack[0];
    v0093 = qvalue(elt(env, 1)); // current!-modulus
    v0093 = difference2(v0068, v0093);
    nil = C_nil;
    if (exception_pending()) goto v0101;
    stack[0] = v0093;
    { LispObject res = stack[0]; popv(2); return onevalue(res); }
// error exit handlers
v0101:
    popv(2);
    return nil;
}



// Code for multiply!-by!-constant!-mod!-p

static LispObject CC_multiplyKbyKconstantKmodKp(LispObject env,
                         LispObject v0000, LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0156, v0047, v0048;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for multiply-by-constant-mod-p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0002,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0002;
    stack[-2] = v0000;
// end of prologue
    stack[-3] = nil;
    v0156 = stack[-2];
    if (v0156 == nil) goto v0125;
    v0047 = stack[-1];
    v0156 = (LispObject)17; // 1
    if (v0047 == v0156) { LispObject res = stack[-2]; popv(5); return onevalue(res); }
    else goto v0146;

v0146:
    v0156 = stack[-2];
    if (!consp(v0156)) goto v0115;
    v0156 = stack[-2];
    v0156 = qcar(v0156);
    v0156 = (consp(v0156) ? nil : lisp_true);
    goto v0106;

v0106:
    if (v0156 == nil) goto v0100;
    v0156 = stack[-2];
    if (v0156 == nil) goto v0157;
    v0047 = stack[-2];
    v0156 = stack[-1];
    v0156 = Lmodular_times(nil, v0047, v0156);
    env = stack[-4];
    fn = elt(env, 3); // !*n2f
    v0156 = (*qfn1(fn))(qenv(fn), v0156);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-4];
    stack[-2] = v0156;
    goto v0157;

v0157:
    v0156 = stack[-3];
    if (v0156 == nil) { LispObject res = stack[-2]; popv(5); return onevalue(res); }
    v0156 = stack[-3];
    v0156 = qcdr(v0156);
    stack[0] = v0156;
    v0047 = stack[-3];
    v0156 = stack[-2];
    v0156 = Lrplacd(nil, v0047, v0156);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-4];
    v0156 = stack[-3];
    stack[-2] = v0156;
    v0156 = stack[0];
    stack[-3] = v0156;
    goto v0157;

v0100:
    v0156 = stack[-2];
    v0156 = qcar(v0156);
    v0047 = qcdr(v0156);
    v0156 = stack[-1];
    v0156 = CC_multiplyKbyKconstantKmodKp(env, v0047, v0156);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-4];
    stack[0] = v0156;
    v0156 = stack[0];
    if (v0156 == nil) goto v0158;
    v0156 = stack[-2];
    v0156 = qcar(v0156);
    v0048 = qcar(v0156);
    v0047 = stack[0];
    v0156 = stack[-3];
    v0156 = acons(v0048, v0047, v0156);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-4];
    stack[-3] = v0156;
    goto v0158;

v0158:
    v0156 = stack[-2];
    v0156 = qcdr(v0156);
    stack[-2] = v0156;
    goto v0146;

v0115:
    v0156 = qvalue(elt(env, 2)); // t
    goto v0106;

v0125:
    v0156 = qvalue(elt(env, 1)); // nil
    { popv(5); return onevalue(v0156); }
// error exit handlers
v0080:
    popv(5);
    return nil;
}



// Code for mtchk

static LispObject CC_mtchk(LispObject env,
                         LispObject v0000, LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0175, v0176, v0024, v0177;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mtchk");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0002,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    stack[-8] = v0002;
    stack[-9] = v0000;
// end of prologue
    stack[-4] = nil;
    stack[-3] = nil;
    v0175 = stack[-9];
    v0175 = qcar(v0175);
    fn = elt(env, 1); // noncomp
    v0175 = (*qfn1(fn))(qenv(fn), v0175);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-11];
    stack[-10] = v0175;
    goto v0083;

v0083:
    v0175 = stack[-8];
    if (v0175 == nil) { LispObject res = stack[-4]; popv(12); return onevalue(res); }
    v0175 = stack[-8];
    v0175 = qcar(v0175);
    stack[-7] = v0175;
    v0175 = stack[-7];
    v0175 = qcar(v0175);
    stack[-6] = v0175;
    goto v0084;

v0084:
    v0175 = stack[-6];
    if (v0175 == nil) goto v0062;
    v0177 = stack[-9];
    v0175 = stack[-6];
    v0024 = qcar(v0175);
    v0175 = stack[-7];
    v0175 = qcdr(v0175);
    v0175 = qcar(v0175);
    v0176 = qcar(v0175);
    v0175 = stack[-7];
    v0175 = qcdr(v0175);
    v0175 = qcar(v0175);
    v0175 = qcdr(v0175);
    fn = elt(env, 2); // mtchp1
    v0175 = (*qfnn(fn))(qenv(fn), 4, v0177, v0024, v0176, v0175);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-11];
    stack[-5] = v0175;
    goto v0085;

v0085:
    v0175 = stack[-5];
    if (v0175 == nil) goto v0061;
    v0175 = stack[-5];
    stack[0] = qcar(v0175);
    v0175 = stack[-6];
    v0176 = qcar(v0175);
    v0175 = stack[-7];
    v0175 = qcar(v0175);
    v0175 = Ldelete(nil, v0176, v0175);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-11];
    stack[-2] = Lsubla(nil, stack[0], v0175);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-11];
    v0175 = stack[-5];
    v0176 = qcar(v0175);
    v0175 = stack[-7];
    v0175 = qcdr(v0175);
    v0175 = qcar(v0175);
    stack[-1] = Lsubla(nil, v0176, v0175);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-11];
    v0175 = stack[-5];
    v0176 = qcar(v0175);
    v0175 = stack[-7];
    v0175 = qcdr(v0175);
    v0175 = qcdr(v0175);
    v0175 = qcar(v0175);
    stack[0] = Lsubla(nil, v0176, v0175);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-11];
    v0175 = stack[-5];
    v0176 = qcar(v0175);
    v0175 = stack[-6];
    v0175 = qcar(v0175);
    v0176 = Lsubla(nil, v0176, v0175);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-11];
    v0175 = stack[-7];
    v0175 = qcdr(v0175);
    v0175 = qcdr(v0175);
    v0175 = qcdr(v0175);
    v0175 = qcar(v0175);
    v0175 = cons(v0176, v0175);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-11];
    v0175 = list2(stack[0], v0175);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-11];
    v0175 = list2star(stack[-2], stack[-1], v0175);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-11];
    stack[0] = v0175;
    v0175 = qcar(v0175);
    if (v0175 == nil) goto v0178;
    v0176 = stack[0];
    v0175 = stack[-4];
    v0175 = cons(v0176, v0175);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-11];
    stack[-4] = v0175;
    v0175 = stack[-3];
    if (!(v0175 == nil)) goto v0151;
    v0175 = stack[-4];
    stack[-3] = v0175;
    goto v0151;

v0151:
    v0175 = stack[-5];
    v0175 = qcdr(v0175);
    stack[-5] = v0175;
    goto v0085;

v0178:
    v0175 = stack[-5];
    v0176 = qcar(v0175);
    v0175 = stack[-7];
    v0175 = qcdr(v0175);
    v0175 = qcar(v0175);
    v0175 = qcdr(v0175);
    v0175 = Lsubla(nil, v0176, v0175);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-11];
    fn = elt(env, 3); // lispeval
    v0175 = (*qfn1(fn))(qenv(fn), v0175);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-11];
    if (v0175 == nil) goto v0151;
    v0175 = stack[0];
    popv(12);
    return ncons(v0175);

v0061:
    v0175 = stack[-10];
    if (v0175 == nil) goto v0037;
    v0175 = stack[-7];
    v0175 = qcdr(v0175);
    v0175 = qcdr(v0175);
    v0175 = qcdr(v0175);
    v0175 = qcar(v0175);
    if (v0175 == nil) goto v0062;
    v0175 = stack[-6];
    fn = elt(env, 4); // nocp
    v0175 = (*qfn1(fn))(qenv(fn), v0175);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-11];
    if (!(v0175 == nil)) goto v0109;

v0062:
    v0175 = stack[-4];
    if (v0175 == nil) goto v0179;
    stack[0] = stack[-3];
    v0175 = stack[-7];
    v0175 = ncons(v0175);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-11];
    v0175 = Lrplacd(nil, stack[0], v0175);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-11];
    v0175 = stack[-3];
    v0175 = qcdr(v0175);
    stack[-3] = v0175;
    goto v0109;

v0109:
    v0175 = stack[-8];
    v0175 = qcdr(v0175);
    stack[-8] = v0175;
    goto v0083;

v0179:
    v0175 = stack[-7];
    v0175 = ncons(v0175);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-11];
    stack[-3] = v0175;
    stack[-4] = v0175;
    goto v0109;

v0037:
    v0175 = stack[-6];
    v0175 = qcdr(v0175);
    stack[-6] = v0175;
    goto v0084;
// error exit handlers
v0029:
    popv(12);
    return nil;
}



// Code for quotsq

static LispObject CC_quotsq(LispObject env,
                         LispObject v0000, LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0083, v0084;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for quotsq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0002,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0083 = v0002;
    v0084 = v0000;
// end of prologue
    stack[0] = v0084;
    fn = elt(env, 1); // invsq
    v0083 = (*qfn1(fn))(qenv(fn), v0083);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-1];
    {
        LispObject v0062 = stack[0];
        popv(2);
        fn = elt(env, 2); // multsq
        return (*qfn2(fn))(qenv(fn), v0062, v0083);
    }
// error exit handlers
v0061:
    popv(2);
    return nil;
}



// Code for exptchksq

static LispObject CC_exptchksq(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0123;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for exptchksq");
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
    v0123 = qvalue(elt(env, 1)); // !*combineexpt
    if (v0123 == nil) { LispObject res = stack[0]; popv(3); return onevalue(res); }
    v0123 = stack[0];
    v0123 = qcar(v0123);
    fn = elt(env, 2); // exptchk
    stack[-1] = (*qfn1(fn))(qenv(fn), v0123);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-2];
    v0123 = stack[0];
    v0123 = qcdr(v0123);
    fn = elt(env, 2); // exptchk
    v0123 = (*qfn1(fn))(qenv(fn), v0123);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-2];
    fn = elt(env, 3); // invsq
    v0123 = (*qfn1(fn))(qenv(fn), v0123);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-2];
    {
        LispObject v0060 = stack[-1];
        popv(3);
        fn = elt(env, 4); // multsq
        return (*qfn2(fn))(qenv(fn), v0060, v0123);
    }
// error exit handlers
v0108:
    popv(3);
    return nil;
}



// Code for setcar

static LispObject CC_setcar(LispObject env,
                         LispObject v0000, LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0083, v0084;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for setcar");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0002,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0002;
    v0083 = v0000;
// end of prologue
    v0084 = v0083;
    v0083 = stack[0];
    v0083 = Lrplaca(nil, v0084, v0083);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    { LispObject res = stack[0]; popv(1); return onevalue(res); }
// error exit handlers
v0061:
    popv(1);
    return nil;
}



// Code for aex_ctx

static LispObject CC_aex_ctx(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0066, v0082;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for aex_ctx");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0066 = v0000;
// end of prologue
    v0082 = v0066;
    v0066 = (LispObject)49; // 3
    {
        fn = elt(env, 1); // nth
        return (*qfn2(fn))(qenv(fn), v0082, v0066);
    }
}



// Code for notstring

static LispObject CC_notstring(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0114, v0149, v0091;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for notstring");
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
    v0114 = v0000;
// end of prologue
    v0149 = elt(env, 1); // ! 
    fn = elt(env, 5); // delall
    v0114 = (*qfn2(fn))(qenv(fn), v0149, v0114);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[0];
    v0091 = v0114;
    v0114 = v0091;
    v0149 = qcar(v0114);
    v0114 = elt(env, 2); // !"
    if (v0149 == v0114) goto v0102;
    v0114 = v0091;
    v0114 = Lreverse(nil, v0114);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[0];
    v0149 = qcar(v0114);
    v0114 = elt(env, 2); // !"
    v0114 = Lneq(nil, v0149, v0114);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[0];
    goto v0090;

v0090:
    if (v0114 == nil) goto v0100;
    v0114 = qvalue(elt(env, 4)); // t
    { popv(1); return onevalue(v0114); }

v0100:
    v0114 = qvalue(elt(env, 3)); // nil
    { popv(1); return onevalue(v0114); }

v0102:
    v0114 = qvalue(elt(env, 3)); // nil
    goto v0090;
// error exit handlers
v0095:
    popv(1);
    return nil;
}



// Code for constp

static LispObject CC_constp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0146, v0108;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for constp");
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
    v0146 = v0000;
// end of prologue
    v0108 = v0146;
    v0108 = (is_number(v0108) ? lisp_true : nil);
    if (!(v0108 == nil)) { popv(1); return onevalue(v0108); }
    v0108 = v0146;
    v0108 = Lconsp(nil, v0108);
    env = stack[0];
    if (v0108 == nil) goto v0125;
    v0146 = qcar(v0146);
    v0108 = qvalue(elt(env, 2)); // domainlist!*
    v0146 = Lmemq(nil, v0146, v0108);
    { popv(1); return onevalue(v0146); }

v0125:
    v0146 = qvalue(elt(env, 1)); // nil
    { popv(1); return onevalue(v0146); }
}



// Code for bczero!?

static LispObject CC_bczeroW(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0118, v0134;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for bczero?");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0118 = v0000;
// end of prologue
    v0134 = qvalue(elt(env, 1)); // !*grmod!*
    if (v0134 == nil) goto v0061;
    v0134 = v0118;
    v0118 = (LispObject)1; // 0
        return Leqn(nil, v0134, v0118);

v0061:
    v0118 = qcar(v0118);
    v0118 = (v0118 == nil ? lisp_true : nil);
    return onevalue(v0118);
}



// Code for fast!-row!-dim

static LispObject CC_fastKrowKdim(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0086;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for fast-row-dim");
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
    v0086 = v0000;
// end of prologue
    v0086 = Lupbv(nil, v0086);
    errexit();
    return add1(v0086);
}



// Code for makelist

static LispObject CC_makelist(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0066, v0082;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for makelist");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0066 = v0000;
// end of prologue
    v0082 = elt(env, 1); // list
    return cons(v0082, v0066);
}



// Code for sinitl

static LispObject CC_sinitl(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0083;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sinitl");
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
    v0083 = v0000;
// end of prologue
    stack[0] = v0083;
    if (!symbolp(v0083)) v0083 = nil;
    else { v0083 = qfastgets(v0083);
           if (v0083 != nil) { v0083 = elt(v0083, 47); // initl
#ifdef RECORD_GET
             if (v0083 != SPID_NOPROP)
                record_get(elt(fastget_names, 47), 1);
             else record_get(elt(fastget_names, 47), 0),
                v0083 = nil; }
           else record_get(elt(fastget_names, 47), 0); }
#else
             if (v0083 == SPID_NOPROP) v0083 = nil; }}
#endif
    fn = elt(env, 1); // eval
    v0083 = (*qfn1(fn))(qenv(fn), v0083);
    nil = C_nil;
    if (exception_pending()) goto v0085;
    {
        LispObject v0061 = stack[0];
        popv(1);
        return Lset(nil, v0061, v0083);
    }
// error exit handlers
v0085:
    popv(1);
    return nil;
}



// Code for smemqlp

static LispObject CC_smemqlp(LispObject env,
                         LispObject v0000, LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0140, v0103;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for smemqlp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0002,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0002;
    stack[-1] = v0000;
// end of prologue

v0180:
    v0140 = stack[0];
    if (v0140 == nil) goto v0125;
    v0140 = stack[0];
    v0140 = (is_number(v0140) ? lisp_true : nil);
    goto v0067;

v0067:
    if (v0140 == nil) goto v0105;
    v0140 = qvalue(elt(env, 2)); // nil
    { popv(3); return onevalue(v0140); }

v0105:
    v0140 = stack[0];
    if (!consp(v0140)) goto v0134;
    v0140 = stack[0];
    v0103 = qcar(v0140);
    v0140 = elt(env, 3); // quote
    if (v0103 == v0140) goto v0111;
    v0103 = stack[-1];
    v0140 = stack[0];
    v0140 = qcar(v0140);
    v0140 = CC_smemqlp(env, v0103, v0140);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-2];
    if (!(v0140 == nil)) { popv(3); return onevalue(v0140); }
    v0103 = stack[-1];
    v0140 = stack[0];
    v0140 = qcdr(v0140);
    stack[-1] = v0103;
    stack[0] = v0140;
    goto v0180;

v0111:
    v0140 = qvalue(elt(env, 2)); // nil
    { popv(3); return onevalue(v0140); }

v0134:
    v0103 = stack[0];
    v0140 = stack[-1];
    v0140 = Lmemq(nil, v0103, v0140);
    { popv(3); return onevalue(v0140); }

v0125:
    v0140 = qvalue(elt(env, 1)); // t
    goto v0067;
// error exit handlers
v0144:
    popv(3);
    return nil;
}



// Code for aeval

static LispObject CC_aeval(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0066, v0082;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for aeval");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0066 = v0000;
// end of prologue
    v0082 = v0066;
    v0066 = qvalue(elt(env, 1)); // nil
    {
        fn = elt(env, 2); // reval1
        return (*qfn2(fn))(qenv(fn), v0082, v0066);
    }
}



// Code for angles!-equal

static LispObject CC_anglesKequal(LispObject env,
                         LispObject v0000, LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0095, v0154, v0155;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for angles-equal");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0002,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0002;
    stack[-1] = v0000;
// end of prologue
    v0095 = (LispObject)1; // 0
    stack[-2] = v0095;
    goto v0109;

v0109:
    v0154 = stack[-1];
    v0095 = stack[-2];
    v0155 = *(LispObject *)((char *)v0154 + (CELL-TAG_VECTOR) + ((int32_t)v0095/(16/CELL)));
    v0154 = stack[0];
    v0095 = stack[-2];
    v0095 = *(LispObject *)((char *)v0154 + (CELL-TAG_VECTOR) + ((int32_t)v0095/(16/CELL)));
    if (equal(v0155, v0095)) goto v0125;
    v0095 = qvalue(elt(env, 1)); // nil
    { popv(4); return onevalue(v0095); }

v0125:
    v0095 = stack[-2];
    v0095 = add1(v0095);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-3];
    stack[-2] = v0095;
    v0154 = stack[-2];
    v0095 = (LispObject)129; // 8
    v0095 = (LispObject)lessp2(v0154, v0095);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    v0095 = v0095 ? lisp_true : nil;
    env = stack[-3];
    if (!(v0095 == nil)) goto v0109;
    v0095 = qvalue(elt(env, 2)); // t
    { popv(4); return onevalue(v0095); }
// error exit handlers
v0094:
    popv(4);
    return nil;
}



// Code for multd

static LispObject CC_multd(LispObject env,
                         LispObject v0000, LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0133, v0183;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for multd");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0002,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0002;
    stack[-2] = v0000;
// end of prologue
    stack[-3] = nil;
    goto v0105;

v0105:
    v0133 = stack[-1];
    if (v0133 == nil) goto v0125;
    v0183 = stack[-1];
    v0133 = (LispObject)17; // 1
    if (v0183 == v0133) goto v0089;
    v0133 = stack[-1];
    if (!consp(v0133)) goto v0093;
    v0133 = stack[-1];
    v0133 = qcar(v0133);
    v0133 = (consp(v0133) ? nil : lisp_true);
    goto v0070;

v0070:
    if (v0133 == nil) goto v0148;
    stack[0] = stack[-3];
    v0183 = stack[-2];
    v0133 = stack[-1];
    fn = elt(env, 2); // multdm
    v0133 = (*qfn2(fn))(qenv(fn), v0183, v0133);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-4];
    {
        LispObject v0051 = stack[0];
        popv(5);
        fn = elt(env, 3); // nreverse
        return (*qfn2(fn))(qenv(fn), v0051, v0133);
    }

v0148:
    v0133 = stack[-1];
    v0133 = qcar(v0133);
    stack[0] = qcar(v0133);
    v0183 = stack[-2];
    v0133 = stack[-1];
    v0133 = qcar(v0133);
    v0133 = qcdr(v0133);
    v0183 = CC_multd(env, v0183, v0133);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-4];
    v0133 = stack[-3];
    v0133 = acons(stack[0], v0183, v0133);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-4];
    stack[-3] = v0133;
    v0133 = stack[-1];
    v0133 = qcdr(v0133);
    stack[-1] = v0133;
    goto v0105;

v0093:
    v0133 = qvalue(elt(env, 1)); // t
    goto v0070;

v0089:
    v0183 = stack[-3];
    v0133 = stack[-2];
    {
        popv(5);
        fn = elt(env, 3); // nreverse
        return (*qfn2(fn))(qenv(fn), v0183, v0133);
    }

v0125:
    v0133 = stack[-3];
    {
        popv(5);
        fn = elt(env, 3); // nreverse
        return (*qfn1(fn))(qenv(fn), v0133);
    }
// error exit handlers
v0184:
    popv(5);
    return nil;
}



// Code for negnumberchk

static LispObject CC_negnumberchk(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0115, v0116, v0070;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for negnumberchk");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0070 = v0000;
// end of prologue
    v0116 = v0070;
    v0115 = elt(env, 1); // minus
    if (!consp(v0116)) goto v0087;
    v0116 = qcar(v0116);
    if (!(v0116 == v0115)) goto v0087;
    v0115 = v0070;
    v0115 = qcdr(v0115);
    v0115 = qcar(v0115);
    v0115 = (is_number(v0115) ? lisp_true : nil);
    goto v0088;

v0088:
    if (v0115 == nil) return onevalue(v0070);
    v0115 = v0070;
    v0115 = qcdr(v0115);
    v0115 = qcar(v0115);
    return negate(v0115);

v0087:
    v0115 = qvalue(elt(env, 2)); // nil
    goto v0088;
}



// Code for pappl0

static LispObject CC_pappl0(LispObject env,
                         LispObject v0000, LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0084, v0085;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pappl0");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0002,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0084 = v0002;
    v0085 = v0000;
// end of prologue
    stack[0] = v0085;
    fn = elt(env, 1); // unpkp
    v0084 = (*qfn1(fn))(qenv(fn), v0084);
    nil = C_nil;
    if (exception_pending()) goto v0062;
    env = stack[-1];
    fn = elt(env, 2); // pappl
    v0084 = (*qfn2(fn))(qenv(fn), stack[0], v0084);
    nil = C_nil;
    if (exception_pending()) goto v0062;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 3); // pkp
        return (*qfn1(fn))(qenv(fn), v0084);
    }
// error exit handlers
v0062:
    popv(2);
    return nil;
}



// Code for rnonep!:

static LispObject CC_rnonepT(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0059, v0111, v0096;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rnonep:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0096 = v0000;
// end of prologue
    v0059 = v0096;
    v0059 = qcdr(v0059);
    v0111 = qcar(v0059);
    v0059 = (LispObject)17; // 1
    if (v0111 == v0059) goto v0061;
    v0059 = qvalue(elt(env, 1)); // nil
    return onevalue(v0059);

v0061:
    v0059 = v0096;
    v0059 = qcdr(v0059);
    v0111 = qcdr(v0059);
    v0059 = (LispObject)17; // 1
    v0059 = (v0111 == v0059 ? lisp_true : nil);
    return onevalue(v0059);
}



// Code for modtimes!:

static LispObject CC_modtimesT(LispObject env,
                         LispObject v0000, LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0085, v0061;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for modtimes:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0002,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// copy arguments values to proper place
    v0085 = v0002;
    v0061 = v0000;
// end of prologue
    v0061 = qcdr(v0061);
    v0085 = qcdr(v0085);
    fn = elt(env, 1); // general!-modular!-times
    v0085 = (*qfn2(fn))(qenv(fn), v0061, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0062;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); // !*modular2f
        return (*qfn1(fn))(qenv(fn), v0085);
    }
// error exit handlers
v0062:
    popv(1);
    return nil;
}



// Code for remainder!-in!-vector

static LispObject CC_remainderKinKvector(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0199, v0031, v0032, v0200, v0015, v0017, v0016, v0201, v0202, v0078;
    LispObject fn;
    LispObject v0098, v0099, v0002, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "remainder-in-vector");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0002 = va_arg(aa, LispObject);
    v0099 = va_arg(aa, LispObject);
    v0098 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for remainder-in-vector");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0098,v0099,v0002,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0002,v0099,v0098);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0098;
    stack[-1] = v0099;
    stack[-2] = v0002;
    stack[-3] = v0000;
// end of prologue
    v0031 = stack[0];
    v0199 = (LispObject)1; // 0
    if (v0031 == v0199) goto v0084;
    v0031 = stack[0];
    v0199 = (LispObject)-15; // -1
    if (!(v0031 == v0199)) goto v0093;
    v0199 = elt(env, 1); // "Attempt to divide by zero"
    fn = elt(env, 3); // errorf
    v0199 = (*qfn1(fn))(qenv(fn), v0199);
    nil = C_nil;
    if (exception_pending()) goto v0203;
    env = stack[-4];
    goto v0093;

v0093:
    v0031 = stack[-1];
    v0199 = stack[0];
    v0199 = *(LispObject *)((char *)v0031 + (CELL-TAG_VECTOR) + ((int32_t)v0199/(16/CELL)));
    v0199 = Lmodular_reciprocal(nil, v0199);
    nil = C_nil;
    if (exception_pending()) goto v0203;
    env = stack[-4];
    {   int32_t w = int_of_fixnum(v0199);
        if (w != 0) w = current_modulus - w;
        v0199 = fixnum_of_int(w);
    }
    v0201 = v0199;
    v0199 = stack[0];
    v0199 = (LispObject)((int32_t)(v0199) - 0x10);
    v0202 = v0199;
    goto v0151;

v0151:
    v0031 = stack[-2];
    v0199 = stack[0];
    v0031 = (LispObject)(int32_t)((int32_t)v0031 - (int32_t)v0199 + TAG_FIXNUM);
    v0078 = v0031;
    v0199 = (LispObject)1; // 0
    if (((int32_t)(v0031)) < ((int32_t)(v0199))) { LispObject res = stack[-2]; popv(5); return onevalue(res); }
    v0032 = v0201;
    v0031 = stack[-3];
    v0199 = stack[-2];
    v0199 = *(LispObject *)((char *)v0031 + (CELL-TAG_VECTOR) + ((int32_t)v0199/(16/CELL)));
    v0199 = Lmodular_times(nil, v0032, v0199);
    env = stack[-4];
    v0016 = v0199;
    v0199 = (LispObject)1; // 0
    v0017 = v0199;
    goto v0051;

v0051:
    v0031 = v0202;
    v0199 = v0017;
    v0199 = (LispObject)(int32_t)((int32_t)v0031 - (int32_t)v0199 + TAG_FIXNUM);
    v0199 = ((intptr_t)(v0199) < 0 ? lisp_true : nil);
    if (v0199 == nil) goto v0049;
    v0199 = stack[-2];
    v0199 = (LispObject)((int32_t)(v0199) - 0x10);
    stack[-2] = v0199;
    goto v0136;

v0136:
    v0031 = stack[-2];
    v0199 = (LispObject)1; // 0
    if (((int32_t)(v0031)) < ((int32_t)(v0199))) goto v0204;
    v0031 = stack[-3];
    v0199 = stack[-2];
    v0031 = *(LispObject *)((char *)v0031 + (CELL-TAG_VECTOR) + ((int32_t)v0199/(16/CELL)));
    v0199 = (LispObject)1; // 0
    v0199 = (v0031 == v0199 ? lisp_true : nil);
    goto v0205;

v0205:
    if (v0199 == nil) goto v0151;
    v0199 = stack[-2];
    v0199 = (LispObject)((int32_t)(v0199) - 0x10);
    stack[-2] = v0199;
    goto v0136;

v0204:
    v0199 = qvalue(elt(env, 2)); // nil
    goto v0205;

v0049:
    v0015 = stack[-3];
    v0031 = v0017;
    v0199 = v0078;
    v0200 = (LispObject)(int32_t)((int32_t)v0031 + (int32_t)v0199 - TAG_FIXNUM);
    v0032 = stack[-3];
    v0031 = v0017;
    v0199 = v0078;
    v0199 = (LispObject)(int32_t)((int32_t)v0031 + (int32_t)v0199 - TAG_FIXNUM);
    v0032 = *(LispObject *)((char *)v0032 + (CELL-TAG_VECTOR) + ((int32_t)v0199/(16/CELL)));
    v0031 = stack[-1];
    v0199 = v0017;
    v0031 = *(LispObject *)((char *)v0031 + (CELL-TAG_VECTOR) + ((int32_t)v0199/(16/CELL)));
    v0199 = v0016;
    v0199 = Lmodular_times(nil, v0031, v0199);
    env = stack[-4];
    {   int32_t w = int_of_fixnum(v0032) + int_of_fixnum(v0199);
        if (w >= current_modulus) w -= current_modulus;
        v0199 = fixnum_of_int(w);
    }
    *(LispObject *)((char *)v0015 + (CELL-TAG_VECTOR) + ((int32_t)v0200/(16/CELL))) = v0199;
    v0199 = v0017;
    v0199 = (LispObject)((int32_t)(v0199) + 0x10);
    v0017 = v0199;
    goto v0051;

v0084:
    v0199 = (LispObject)-15; // -1
    { popv(5); return onevalue(v0199); }
// error exit handlers
v0203:
    popv(5);
    return nil;
}



// Code for remove!-free!-vars!-l

static LispObject CC_removeKfreeKvarsKl(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0206, v0163;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for remove-free-vars-l");
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
    stack[-3] = nil;
    stack[-1] = nil;
    stack[0] = nil;
    goto v0088;

v0088:
    v0206 = stack[-2];
    if (!consp(v0206)) goto v0061;
    v0206 = stack[-2];
    v0163 = qcar(v0206);
    v0206 = elt(env, 3); // !*sq
    if (v0163 == v0206) goto v0054;
    v0163 = stack[-2];
    v0206 = stack[-1];
    v0206 = cons(v0163, v0206);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    env = stack[-4];
    stack[-1] = v0206;
    v0206 = stack[-2];
    v0206 = qcar(v0206);
    fn = elt(env, 4); // remove!-free!-vars
    v0163 = (*qfn1(fn))(qenv(fn), v0206);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    env = stack[-4];
    v0206 = stack[-3];
    v0206 = cons(v0163, v0206);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    env = stack[-4];
    stack[-3] = v0206;
    v0206 = stack[-2];
    v0206 = qcdr(v0206);
    stack[-2] = v0206;
    goto v0088;

v0054:
    v0206 = stack[-2];
    v0206 = qcdr(v0206);
    v0206 = qcar(v0206);
    fn = elt(env, 5); // prepsq!*
    v0206 = (*qfn1(fn))(qenv(fn), v0206);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    env = stack[-4];
    stack[-2] = v0206;
    v0206 = qvalue(elt(env, 2)); // t
    stack[0] = v0206;
    goto v0088;

v0061:
    v0206 = stack[-3];
    if (v0206 == nil) { LispObject res = stack[-2]; popv(5); return onevalue(res); }
    v0206 = stack[0];
    if (v0206 == nil) goto v0106;
    v0206 = stack[-3];
    v0163 = qcar(v0206);
    v0206 = stack[-2];
    v0206 = cons(v0163, v0206);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    env = stack[-4];
    stack[-2] = v0206;
    goto v0123;

v0123:
    v0206 = stack[-1];
    v0206 = qcdr(v0206);
    stack[-1] = v0206;
    v0206 = stack[-3];
    v0206 = qcdr(v0206);
    stack[-3] = v0206;
    goto v0061;

v0106:
    v0206 = stack[-1];
    v0206 = qcar(v0206);
    v0163 = qcar(v0206);
    v0206 = stack[-3];
    v0206 = qcar(v0206);
    if (equal(v0163, v0206)) goto v0111;
    v0206 = stack[-3];
    v0163 = qcar(v0206);
    v0206 = stack[-2];
    v0206 = cons(v0163, v0206);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    env = stack[-4];
    stack[-2] = v0206;
    v0206 = qvalue(elt(env, 2)); // t
    stack[0] = v0206;
    goto v0123;

v0111:
    v0206 = stack[-1];
    v0206 = qcar(v0206);
    stack[-2] = v0206;
    goto v0123;
// error exit handlers
v0207:
    popv(5);
    return nil;
}



// Code for get!+vec!+dim

static LispObject CC_getLvecLdim(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0105;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for get+vec+dim");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0105 = v0000;
// end of prologue
        return Llength(nil, v0105);
}



// Code for qqe_qopaddp

static LispObject CC_qqe_qopaddp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0061, v0062;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qqe_qopaddp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0061 = v0000;
// end of prologue
    v0062 = v0061;
    v0061 = elt(env, 1); // (ladd radd)
    v0061 = Lmemq(nil, v0062, v0061);
    if (v0061 == nil) goto v0086;
    v0061 = qvalue(elt(env, 2)); // t
    return onevalue(v0061);

v0086:
    v0061 = nil;
    return onevalue(v0061);
}



// Code for pasf_susitf

static LispObject CC_pasf_susitf(LispObject env,
                         LispObject v0000, LispObject v0002)
{
    LispObject v0001, v0086;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pasf_susitf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0001 = v0002;
    v0086 = v0000;
// end of prologue
    return onevalue(v0086);
}



// Code for delq

static LispObject CC_delq(LispObject env,
                         LispObject v0000, LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0154, v0155, v0145;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for delq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0002,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0002;
    stack[-1] = v0000;
// end of prologue
    v0145 = nil;
    goto v0105;

v0105:
    v0154 = stack[0];
    if (v0154 == nil) goto v0114;
    v0154 = stack[0];
    v0155 = qcar(v0154);
    v0154 = stack[-1];
    if (v0155 == v0154) goto v0146;
    v0154 = stack[0];
    v0154 = qcar(v0154);
    v0155 = v0145;
    v0154 = cons(v0154, v0155);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-2];
    v0145 = v0154;
    v0154 = stack[0];
    v0154 = qcdr(v0154);
    stack[0] = v0154;
    goto v0105;

v0146:
    v0155 = v0145;
    v0154 = stack[0];
    v0154 = qcdr(v0154);
    {
        popv(3);
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(qenv(fn), v0155, v0154);
    }

v0114:
    v0154 = v0145;
    {
        popv(3);
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(qenv(fn), v0154);
    }
// error exit handlers
v0094:
    popv(3);
    return nil;
}



// Code for sfto_dcontentf

static LispObject CC_sfto_dcontentf(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0066, v0082;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sfto_dcontentf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0066 = v0000;
// end of prologue
    v0082 = v0066;
    v0066 = qvalue(elt(env, 1)); // nil
    {
        fn = elt(env, 2); // sfto_dcontentf1
        return (*qfn2(fn))(qenv(fn), v0082, v0066);
    }
}



// Code for attributes

static LispObject CC_attributes(LispObject env,
                         LispObject v0000, LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0097, v0148;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for attributes");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0002,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0002;
    v0097 = v0000;
// end of prologue
    v0097 = Llength(nil, v0097);
    nil = C_nil;
    if (exception_pending()) goto v0143;
    env = stack[-3];
    stack[-2] = v0097;
    v0097 = (LispObject)17; // 1
    stack[0] = v0097;
    goto v0117;

v0117:
    v0148 = stack[-2];
    v0097 = stack[0];
    v0097 = difference2(v0148, v0097);
    nil = C_nil;
    if (exception_pending()) goto v0143;
    env = stack[-3];
    v0097 = Lminusp(nil, v0097);
    env = stack[-3];
    if (!(v0097 == nil)) goto v0101;
    v0097 = stack[-1];
    v0097 = qcdr(v0097);
    stack[-1] = v0097;
    v0097 = stack[0];
    v0097 = add1(v0097);
    nil = C_nil;
    if (exception_pending()) goto v0143;
    env = stack[-3];
    stack[0] = v0097;
    goto v0117;

v0101:
    v0097 = stack[-1];
    v0148 = qcar(v0097);
    v0097 = elt(env, 2); // ! 
    if (v0148 == v0097) goto v0093;
    v0148 = stack[-1];
    v0097 = elt(env, 3); // (!$)
    if (equal(v0148, v0097)) goto v0154;
    v0097 = stack[-1];
    qvalue(elt(env, 4)) = v0097; // atts
    goto v0154;

v0154:
    v0097 = nil;
    { popv(4); return onevalue(v0097); }

v0093:
    v0097 = stack[-1];
    v0097 = qcdr(v0097);
    stack[-1] = v0097;
    goto v0101;
// error exit handlers
v0143:
    popv(4);
    return nil;
}



// Code for c!:ordexn

static LispObject CC_cTordexn(LispObject env,
                         LispObject v0000, LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0156, v0047;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for c:ordexn");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0002,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0002;
    stack[-2] = v0000;
// end of prologue
    stack[0] = nil;
    stack[-3] = nil;
    goto v0088;

v0088:
    v0156 = stack[-1];
    if (v0156 == nil) goto v0087;
    v0047 = stack[-2];
    v0156 = stack[-1];
    v0156 = qcar(v0156);
    if (equal(v0047, v0156)) goto v0116;
    v0156 = stack[-2];
    v0156 = Lconsp(nil, v0156);
    env = stack[-4];
    if (v0156 == nil) goto v0091;
    v0156 = stack[-1];
    v0156 = qcar(v0156);
    v0156 = Lconsp(nil, v0156);
    env = stack[-4];
    goto v0115;

v0115:
    if (v0156 == nil) goto v0148;
    v0156 = qvalue(elt(env, 2)); // nil
    { popv(5); return onevalue(v0156); }

v0148:
    v0047 = stack[-2];
    v0156 = stack[-1];
    v0156 = qcar(v0156);
    fn = elt(env, 3); // c!:ordxp
    v0156 = (*qfn2(fn))(qenv(fn), v0047, v0156);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-4];
    if (v0156 == nil) goto v0208;
    v0047 = stack[-2];
    v0156 = stack[-3];
    v0156 = cons(v0047, v0156);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-4];
    v0047 = Lreverse(nil, v0156);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-4];
    v0156 = stack[-1];
    v0156 = Lappend(nil, v0047, v0156);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    {
        LispObject v0080 = stack[0];
        popv(5);
        return cons(v0080, v0156);
    }

v0208:
    v0156 = stack[-1];
    v0047 = qcar(v0156);
    v0156 = stack[-3];
    v0156 = cons(v0047, v0156);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-4];
    stack[-3] = v0156;
    v0156 = stack[-1];
    v0156 = qcdr(v0156);
    stack[-1] = v0156;
    v0156 = stack[0];
    v0156 = (v0156 == nil ? lisp_true : nil);
    stack[0] = v0156;
    goto v0088;

v0091:
    v0156 = qvalue(elt(env, 2)); // nil
    goto v0115;

v0116:
    v0156 = qvalue(elt(env, 1)); // t
    goto v0115;

v0087:
    v0047 = stack[-2];
    v0156 = stack[-3];
    v0156 = cons(v0047, v0156);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-4];
    v0156 = Lreverse(nil, v0156);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    {
        LispObject v0197 = stack[0];
        popv(5);
        return cons(v0197, v0156);
    }
// error exit handlers
v0169:
    popv(5);
    return nil;
}



// Code for bcprod

static LispObject CC_bcprod(LispObject env,
                         LispObject v0000, LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0057, v0100, v0139;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for bcprod");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0002,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0002;
    stack[-1] = v0000;
// end of prologue
    v0057 = qvalue(elt(env, 1)); // !*grmod!*
    if (v0057 == nil) goto v0123;
    v0100 = stack[-1];
    v0057 = stack[0];
    v0057 = times2(v0100, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0149;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 3); // bcfi
        return (*qfn1(fn))(qenv(fn), v0057);
    }

v0123:
    v0139 = stack[-1];
    v0100 = stack[0];
    v0057 = elt(env, 2); // times
    fn = elt(env, 4); // bcint2op
    v0057 = (*qfnn(fn))(qenv(fn), 3, v0139, v0100, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0149;
    env = stack[-2];
    if (!(v0057 == nil)) { popv(3); return onevalue(v0057); }
    v0100 = stack[-1];
    v0057 = stack[0];
    fn = elt(env, 5); // multsq
    v0057 = (*qfn2(fn))(qenv(fn), v0100, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0149;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 6); // bccheckz
        return (*qfn1(fn))(qenv(fn), v0057);
    }
// error exit handlers
v0149:
    popv(3);
    return nil;
}



// Code for evmatrixcomp1

static LispObject CC_evmatrixcomp1(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0072, v0119, v0120;
    LispObject fn;
    LispObject v0099, v0002, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "evmatrixcomp1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0002 = va_arg(aa, LispObject);
    v0099 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evmatrixcomp1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0099,v0002,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0002,v0099);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0099;
    stack[-2] = v0002;
    stack[-3] = v0000;
// end of prologue

v0180:
    v0072 = stack[-1];
    if (v0072 == nil) goto v0105;
    v0120 = stack[-3];
    v0072 = stack[-1];
    v0119 = qcar(v0072);
    v0072 = (LispObject)1; // 0
    fn = elt(env, 1); // evmatrixcomp2
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v0120, v0119, v0072);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-5];
    v0120 = stack[-2];
    v0072 = stack[-1];
    v0119 = qcar(v0072);
    v0072 = (LispObject)1; // 0
    fn = elt(env, 1); // evmatrixcomp2
    v0072 = (*qfnn(fn))(qenv(fn), 3, v0120, v0119, v0072);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-5];
    stack[-4] = stack[0];
    stack[0] = v0072;
    v0119 = stack[-4];
    v0072 = stack[0];
    fn = elt(env, 2); // iequal
    v0072 = (*qfn2(fn))(qenv(fn), v0119, v0072);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-5];
    if (v0072 == nil) goto v0103;
    v0120 = stack[-3];
    v0119 = stack[-2];
    v0072 = stack[-1];
    v0072 = qcdr(v0072);
    stack[-3] = v0120;
    stack[-2] = v0119;
    stack[-1] = v0072;
    goto v0180;

v0103:
    v0119 = stack[-4];
    v0072 = stack[0];
    if (((int32_t)(v0119)) > ((int32_t)(v0072))) goto v0148;
    v0072 = (LispObject)-15; // -1
    { popv(6); return onevalue(v0072); }

v0148:
    v0072 = (LispObject)17; // 1
    { popv(6); return onevalue(v0072); }

v0105:
    v0072 = (LispObject)1; // 0
    { popv(6); return onevalue(v0072); }
// error exit handlers
v0122:
    popv(6);
    return nil;
}



// Code for multpfsq

static LispObject CC_multpfsq(LispObject env,
                         LispObject v0000, LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0154, v0155;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for multpfsq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0002,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0002;
    stack[-2] = v0000;
// end of prologue
    stack[-3] = nil;
    goto v0105;

v0105:
    v0154 = stack[-2];
    if (v0154 == nil) goto v0084;
    v0154 = stack[-1];
    v0154 = qcar(v0154);
    v0154 = (v0154 == nil ? lisp_true : nil);
    goto v0083;

v0083:
    if (v0154 == nil) goto v0060;
    v0154 = stack[-3];
    {
        popv(5);
        fn = elt(env, 2); // nreverse
        return (*qfn1(fn))(qenv(fn), v0154);
    }

v0060:
    v0154 = stack[-2];
    v0154 = qcar(v0154);
    stack[0] = qcar(v0154);
    v0154 = stack[-2];
    v0154 = qcar(v0154);
    v0155 = qcdr(v0154);
    v0154 = stack[-1];
    fn = elt(env, 3); // multsq
    v0155 = (*qfn2(fn))(qenv(fn), v0155, v0154);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-4];
    v0154 = stack[-3];
    v0154 = acons(stack[0], v0155, v0154);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-4];
    stack[-3] = v0154;
    v0154 = stack[-2];
    v0154 = qcdr(v0154);
    stack[-2] = v0154;
    goto v0105;

v0084:
    v0154 = qvalue(elt(env, 1)); // t
    goto v0083;
// error exit handlers
v0124:
    popv(5);
    return nil;
}



// Code for arrayp

static LispObject CC_arrayp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0082, v0083;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for arrayp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0082 = v0000;
// end of prologue
    if (!symbolp(v0082)) v0082 = nil;
    else { v0082 = qfastgets(v0082);
           if (v0082 != nil) { v0082 = elt(v0082, 2); // rtype
#ifdef RECORD_GET
             if (v0082 != SPID_NOPROP)
                record_get(elt(fastget_names, 2), 1);
             else record_get(elt(fastget_names, 2), 0),
                v0082 = nil; }
           else record_get(elt(fastget_names, 2), 0); }
#else
             if (v0082 == SPID_NOPROP) v0082 = nil; }}
#endif
    v0083 = elt(env, 1); // array
    v0082 = (v0082 == v0083 ? lisp_true : nil);
    return onevalue(v0082);
}



// Code for order!:

static LispObject CC_orderT(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0116, v0070;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for order:");
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
    v0116 = stack[0];
    v0116 = qcdr(v0116);
    v0070 = qcar(v0116);
    v0116 = (LispObject)1; // 0
    if (v0070 == v0116) goto v0001;
    v0116 = stack[0];
    v0116 = qcdr(v0116);
    v0116 = qcar(v0116);
    v0116 = Labsval(nil, v0116);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-2];
    fn = elt(env, 1); // msd
    stack[-1] = (*qfn1(fn))(qenv(fn), v0116);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-2];
    v0116 = stack[0];
    v0116 = qcdr(v0116);
    v0116 = qcdr(v0116);
    v0116 = sub1(v0116);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    {
        LispObject v0101 = stack[-1];
        popv(3);
        return plus2(v0101, v0116);
    }

v0001:
    v0116 = (LispObject)1; // 0
    { popv(3); return onevalue(v0116); }
// error exit handlers
v0110:
    popv(3);
    return nil;
}



// Code for !*collectphysops_reversed

static LispObject CC_Hcollectphysops_reversed(LispObject env,
                         LispObject v0000, LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0150, v0058;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *collectphysops_reversed");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0002,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0002;
    stack[-1] = v0000;
// end of prologue
    v0150 = stack[-1];
    fn = elt(env, 2); // physopp
    v0150 = (*qfn1(fn))(qenv(fn), v0150);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-2];
    if (v0150 == nil) goto v0134;
    v0058 = stack[-1];
    v0150 = stack[0];
    popv(3);
    return cons(v0058, v0150);

v0134:
    v0150 = stack[-1];
    if (!consp(v0150)) { LispObject res = stack[0]; popv(3); return onevalue(res); }
    v0150 = stack[-1];
    v0058 = qcar(v0150);
    v0150 = stack[0];
    v0150 = CC_Hcollectphysops_reversed(env, v0058, v0150);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-2];
    stack[0] = v0150;
    v0150 = stack[-1];
    v0150 = qcdr(v0150);
    stack[-1] = v0150;
    goto v0134;
// error exit handlers
v0139:
    popv(3);
    return nil;
}



// Code for list2wideid

static LispObject CC_list2wideid(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0086;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for list2wideid");
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
    v0086 = v0000;
// end of prologue
    fn = elt(env, 1); // list2widestring
    v0086 = (*qfn1(fn))(qenv(fn), v0086);
    errexit();
        return Lintern(nil, v0086);
}



// Code for mo!=modiv1

static LispObject CC_moMmodiv1(LispObject env,
                         LispObject v0000, LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0102, v0150;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mo=modiv1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0002,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0002;
    stack[-1] = v0000;
// end of prologue

v0086:
    v0102 = stack[-1];
    if (v0102 == nil) goto v0067;
    v0102 = stack[0];
    if (v0102 == nil) goto v0083;
    v0102 = stack[-1];
    v0150 = qcar(v0102);
    v0102 = stack[0];
    v0102 = qcar(v0102);
    v0102 = (LispObject)lesseq2(v0150, v0102);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    v0102 = v0102 ? lisp_true : nil;
    env = stack[-2];
    if (v0102 == nil) goto v0068;
    v0102 = stack[-1];
    v0102 = qcdr(v0102);
    stack[-1] = v0102;
    v0102 = stack[0];
    v0102 = qcdr(v0102);
    stack[0] = v0102;
    goto v0086;

v0068:
    v0102 = qvalue(elt(env, 2)); // nil
    { popv(3); return onevalue(v0102); }

v0083:
    v0102 = qvalue(elt(env, 2)); // nil
    { popv(3); return onevalue(v0102); }

v0067:
    v0102 = qvalue(elt(env, 1)); // t
    { popv(3); return onevalue(v0102); }
// error exit handlers
v0100:
    popv(3);
    return nil;
}



// Code for unpkp

static LispObject CC_unpkp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0211, v0165, v0212;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for unpkp");
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
    v0211 = stack[-1];
    if (!(!consp(v0211))) { LispObject res = stack[-1]; popv(4); return onevalue(res); }
    v0211 = stack[-1];
    v0211 = Lexplode(nil, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-3];
    stack[-1] = v0211;
    v0211 = stack[-1];
    v0165 = Llength(nil, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-3];
    v0211 = (LispObject)161; // 10
    v0211 = (LispObject)geq2(v0165, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    v0211 = v0211 ? lisp_true : nil;
    env = stack[-3];
    stack[0] = v0211;
    v0211 = stack[0];
    if (v0211 == nil) goto v0139;
    v0211 = stack[-1];
    v0211 = Llength(nil, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-3];
    v0211 = Levenp(nil, v0211);
    env = stack[-3];
    if (!(v0211 == nil)) goto v0139;
    v0165 = elt(env, 1); // !0
    v0211 = stack[-1];
    v0211 = cons(v0165, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-3];
    stack[-1] = v0211;
    goto v0139;

v0139:
    v0211 = stack[-1];
    if (v0211 == nil) goto v0100;
    v0211 = stack[0];
    if (v0211 == nil) goto v0156;
    v0211 = stack[-1];
    v0165 = qcar(v0211);
    v0211 = qvalue(elt(env, 3)); // diglist!*
    v0211 = Lassoc(nil, v0165, v0211);
    v0211 = qcdr(v0211);
    v0165 = v0211;
    v0211 = stack[-1];
    v0211 = qcdr(v0211);
    stack[-1] = v0211;
    v0211 = (LispObject)161; // 10
    v0212 = times2(v0165, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-3];
    v0211 = stack[-1];
    v0165 = qcar(v0211);
    v0211 = qvalue(elt(env, 3)); // diglist!*
    v0211 = Lassoc(nil, v0165, v0211);
    v0211 = qcdr(v0211);
    v0165 = plus2(v0212, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-3];
    v0211 = stack[-2];
    v0211 = cons(v0165, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-3];
    stack[-2] = v0211;
    goto v0145;

v0145:
    v0211 = stack[-1];
    v0211 = qcdr(v0211);
    stack[-1] = v0211;
    goto v0139;

v0156:
    v0211 = stack[-1];
    v0165 = qcar(v0211);
    v0211 = qvalue(elt(env, 3)); // diglist!*
    v0211 = Lassoc(nil, v0165, v0211);
    v0165 = qcdr(v0211);
    v0211 = stack[-2];
    v0211 = cons(v0165, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-3];
    stack[-2] = v0211;
    goto v0145;

v0100:
    v0211 = stack[-2];
        popv(4);
        return Lnreverse(nil, v0211);
// error exit handlers
v0043:
    popv(4);
    return nil;
}



// Code for noncomp1

static LispObject CC_noncomp1(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0057, v0100, v0139;
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
    v0100 = v0000;
// end of prologue
    v0057 = v0100;
    v0057 = Lconsp(nil, v0057);
    env = stack[0];
    if (v0057 == nil) goto v0001;
    v0057 = v0100;
    v0057 = qcar(v0057);
    v0057 = Lconsp(nil, v0057);
    env = stack[0];
    if (v0057 == nil) goto v0090;
    v0057 = v0100;
    {
        popv(1);
        fn = elt(env, 4); // noncomfp
        return (*qfn1(fn))(qenv(fn), v0057);
    }

v0090:
    v0057 = v0100;
    v0139 = qcar(v0057);
    v0057 = elt(env, 2); // taylor!*
    if (v0139 == v0057) goto v0062;
    v0057 = v0100;
    v0057 = qcar(v0057);
    if (!symbolp(v0057)) v0057 = nil;
    else { v0057 = qfastgets(v0057);
           if (v0057 != nil) { v0057 = elt(v0057, 0); // noncom
#ifdef RECORD_GET
             if (v0057 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v0057 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v0057 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v0057 == SPID_NOPROP) v0057 = nil; else v0057 = lisp_true; }}
#endif
    if (v0057 == nil) goto v0110;
    v0057 = qvalue(elt(env, 3)); // t
    { popv(1); return onevalue(v0057); }

v0110:
    v0057 = v0100;
    v0057 = qcdr(v0057);
    {
        popv(1);
        fn = elt(env, 5); // noncomlistp
        return (*qfn1(fn))(qenv(fn), v0057);
    }

v0062:
    v0057 = qvalue(elt(env, 1)); // nil
    { popv(1); return onevalue(v0057); }

v0001:
    v0057 = qvalue(elt(env, 1)); // nil
    { popv(1); return onevalue(v0057); }
}



// Code for sizchk

static LispObject CC_sizchk(LispObject env,
                         LispObject v0000, LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0057, v0100;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sizchk");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0002,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0002;
    stack[-1] = v0000;
// end of prologue
    stack[-2] = nil;
    goto v0105;

v0105:
    v0057 = stack[-1];
    if (v0057 == nil) goto v0125;
    v0057 = stack[-1];
    v0057 = qcar(v0057);
    v0057 = qcar(v0057);
    v0100 = Llength(nil, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0149;
    env = stack[-3];
    v0057 = stack[0];
    v0057 = (LispObject)greaterp2(v0100, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0149;
    v0057 = v0057 ? lisp_true : nil;
    env = stack[-3];
    if (v0057 == nil) goto v0115;
    v0057 = stack[-1];
    v0057 = qcdr(v0057);
    stack[-1] = v0057;
    goto v0105;

v0115:
    v0057 = stack[-1];
    v0100 = qcar(v0057);
    v0057 = stack[-2];
    v0057 = cons(v0100, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0149;
    env = stack[-3];
    stack[-2] = v0057;
    v0057 = stack[-1];
    v0057 = qcdr(v0057);
    stack[-1] = v0057;
    goto v0105;

v0125:
    v0057 = stack[-2];
    {
        popv(4);
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(qenv(fn), v0057);
    }
// error exit handlers
v0149:
    popv(4);
    return nil;
}



// Code for gcdfd1

static LispObject CC_gcdfd1(LispObject env,
                         LispObject v0000, LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0149, v0091;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gcdfd1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0002,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0002;
    v0149 = v0000;
// end of prologue

v0086:
    v0091 = stack[0];
    if (v0091 == nil) { popv(2); return onevalue(v0149); }
    v0091 = stack[0];
    if (!consp(v0091)) goto v0062;
    v0091 = stack[0];
    v0091 = qcar(v0091);
    v0091 = (consp(v0091) ? nil : lisp_true);
    goto v0061;

v0061:
    if (v0091 == nil) goto v0068;
    v0091 = v0149;
    v0149 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); // gcddd
        return (*qfn2(fn))(qenv(fn), v0091, v0149);
    }

v0068:
    v0091 = v0149;
    v0149 = stack[0];
    v0149 = qcar(v0149);
    v0149 = qcdr(v0149);
    v0149 = CC_gcdfd1(env, v0091, v0149);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-1];
    v0091 = stack[0];
    v0091 = qcdr(v0091);
    stack[0] = v0091;
    goto v0086;

v0062:
    v0091 = qvalue(elt(env, 1)); // t
    goto v0061;
// error exit handlers
v0154:
    popv(2);
    return nil;
}



// Code for subs2f

static LispObject CC_subs2f(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0181, v0132, v0122;
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
    v0132 = qvalue(elt(env, 1)); // simpcount!*
    v0181 = qvalue(elt(env, 2)); // simplimit!*
    v0181 = (LispObject)greaterp2(v0132, v0181);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    v0181 = v0181 ? lisp_true : nil;
    env = stack[-2];
    if (v0181 == nil) goto v0105;
    v0181 = (LispObject)1; // 0
    qvalue(elt(env, 1)) = v0181; // simpcount!*
    v0122 = elt(env, 3); // poly
    v0132 = (LispObject)337; // 21
    v0181 = elt(env, 4); // "Simplification recursion too deep"
    fn = elt(env, 9); // rerror
    v0181 = (*qfnn(fn))(qenv(fn), 3, v0122, v0132, v0181);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-2];
    goto v0105;

v0105:
    v0181 = qvalue(elt(env, 1)); // simpcount!*
    v0181 = add1(v0181);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-2];
    qvalue(elt(env, 1)) = v0181; // simpcount!*
    v0181 = qvalue(elt(env, 5)); // nil
    qvalue(elt(env, 6)) = v0181; // !*sub2
    v0181 = stack[0];
    fn = elt(env, 10); // subs2f1
    v0181 = (*qfn1(fn))(qenv(fn), v0181);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-2];
    stack[-1] = v0181;
    v0181 = qvalue(elt(env, 6)); // !*sub2
    if (!(v0181 == nil)) goto v0101;
    v0181 = qvalue(elt(env, 7)); // powlis1!*
    if (!(v0181 == nil)) goto v0101;

v0093:
    v0181 = qvalue(elt(env, 1)); // simpcount!*
    v0181 = sub1(v0181);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-2];
    qvalue(elt(env, 1)) = v0181; // simpcount!*
    { LispObject res = stack[-1]; popv(3); return onevalue(res); }

v0101:
    v0181 = qvalue(elt(env, 8)); // !*resubs
    if (v0181 == nil) goto v0093;
    v0181 = stack[-1];
    v0132 = qcar(v0181);
    v0181 = stack[0];
    if (equal(v0132, v0181)) goto v0097;
    v0181 = qvalue(elt(env, 5)); // nil
    goto v0154;

v0154:
    if (v0181 == nil) goto v0112;
    v0181 = qvalue(elt(env, 5)); // nil
    qvalue(elt(env, 6)) = v0181; // !*sub2
    goto v0093;

v0112:
    v0181 = stack[-1];
    fn = elt(env, 11); // subs2q
    v0181 = (*qfn1(fn))(qenv(fn), v0181);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-2];
    stack[-1] = v0181;
    goto v0093;

v0097:
    v0181 = stack[-1];
    v0132 = qcdr(v0181);
    v0181 = (LispObject)17; // 1
    v0181 = (v0132 == v0181 ? lisp_true : nil);
    goto v0154;
// error exit handlers
v0183:
    popv(3);
    return nil;
}



// Code for qqe_qopheadp

static LispObject CC_qqe_qopheadp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0066, v0082;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qqe_qopheadp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0066 = v0000;
// end of prologue
    v0082 = elt(env, 1); // (lhead rhead)
    v0066 = Lmemq(nil, v0066, v0082);
    return onevalue(v0066);
}



// Code for absf

static LispObject CC_absf(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0084;
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
    v0084 = stack[0];
    fn = elt(env, 1); // minusf
    v0084 = (*qfn1(fn))(qenv(fn), v0084);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-1];
    if (v0084 == nil) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    v0084 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); // negf
        return (*qfn1(fn))(qenv(fn), v0084);
    }
// error exit handlers
v0061:
    popv(2);
    return nil;
}



// Code for get_content

static LispObject CC_get_content(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0133, v0183;
    LispObject fn;
    argcheck(nargs, 0, "get_content");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for get_content");
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
    v0133 = qvalue(elt(env, 1)); // nil
    stack[0] = v0133;
    goto v0062;

v0062:
    v0183 = Lreadch(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    env = stack[-1];
    qvalue(elt(env, 2)) = v0183; // ch
    v0133 = elt(env, 3); // !<
    if (v0183 == v0133) goto v0106;
    v0183 = qvalue(elt(env, 2)); // ch
    v0133 = qvalue(elt(env, 4)); // !$eof!$
    v0133 = Lneq(nil, v0183, v0133);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    env = stack[-1];
    goto v0084;

v0084:
    if (v0133 == nil) goto v0105;
    v0183 = qvalue(elt(env, 2)); // ch
    v0133 = qvalue(elt(env, 5)); // space
    if (equal(v0183, v0133)) goto v0056;
    v0133 = qvalue(elt(env, 2)); // ch
    fn = elt(env, 7); // string2list
    v0133 = (*qfn1(fn))(qenv(fn), v0133);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    env = stack[-1];
    v0183 = qcar(v0133);
    v0133 = (LispObject)161; // 10
    v0133 = (LispObject)greaterp2(v0183, v0133);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    v0133 = v0133 ? lisp_true : nil;
    env = stack[-1];
    goto v0150;

v0150:
    if (v0133 == nil) goto v0062;
    v0183 = qvalue(elt(env, 2)); // ch
    v0133 = stack[0];
    v0133 = cons(v0183, v0133);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    env = stack[-1];
    stack[0] = v0133;
    goto v0062;

v0056:
    v0133 = qvalue(elt(env, 1)); // nil
    goto v0150;

v0105:
    v0133 = stack[0];
    if (v0133 == nil) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    v0183 = elt(env, 6); // !$
    v0133 = stack[0];
    v0133 = cons(v0183, v0133);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    stack[0] = v0133;
    { LispObject res = stack[0]; popv(2); return onevalue(res); }

v0106:
    v0133 = qvalue(elt(env, 1)); // nil
    goto v0084;
// error exit handlers
v0157:
    popv(2);
    return nil;
}



// Code for !:zerop

static LispObject CC_Tzerop(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0102, v0150, v0058;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for :zerop");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0058 = v0000;
// end of prologue
    v0102 = v0058;
    if (v0102 == nil) goto v0067;
    v0150 = v0058;
    v0102 = (LispObject)1; // 0
    v0102 = (v0150 == v0102 ? lisp_true : nil);
    goto v0088;

v0088:
    if (v0102 == nil) goto v0086;
    v0102 = qvalue(elt(env, 1)); // t
    return onevalue(v0102);

v0086:
    v0102 = v0058;
    if (!consp(v0102)) goto v0123;
    v0102 = v0058;
    v0102 = qcar(v0102);
    if (!symbolp(v0102)) v0102 = nil;
    else { v0102 = qfastgets(v0102);
           if (v0102 != nil) { v0102 = elt(v0102, 15); // zerop
#ifdef RECORD_GET
             if (v0102 != SPID_NOPROP)
                record_get(elt(fastget_names, 15), 1);
             else record_get(elt(fastget_names, 15), 0),
                v0102 = nil; }
           else record_get(elt(fastget_names, 15), 0); }
#else
             if (v0102 == SPID_NOPROP) v0102 = nil; }}
#endif
    v0150 = v0058;
        return Lapply1(nil, v0102, v0150);

v0123:
    v0102 = qvalue(elt(env, 2)); // nil
    return onevalue(v0102);

v0067:
    v0102 = qvalue(elt(env, 1)); // t
    goto v0088;
}



// Code for evcompless!?

static LispObject CC_evcomplessW(LispObject env,
                         LispObject v0000, LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0090, v0117;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evcompless?");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0002,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0117 = v0002;
    v0090 = v0000;
// end of prologue
    stack[0] = (LispObject)17; // 1
    fn = elt(env, 1); // evcomp
    v0090 = (*qfn2(fn))(qenv(fn), v0117, v0090);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    v0090 = (stack[0] == v0090 ? lisp_true : nil);
    { popv(1); return onevalue(v0090); }
// error exit handlers
v0134:
    popv(1);
    return nil;
}



// Code for rd!:zerop

static LispObject CC_rdTzerop(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0123, v0089;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rd:zerop");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0123 = v0000;
// end of prologue
    v0089 = v0123;
    v0089 = qcdr(v0089);
    if (!consp(v0089)) goto v0001;
    v0123 = qcdr(v0123);
    v0089 = qcar(v0123);
    v0123 = (LispObject)1; // 0
    v0123 = (v0089 == v0123 ? lisp_true : nil);
    return onevalue(v0123);

v0001:
    v0123 = qcdr(v0123);
        return Lzerop(nil, v0123);
}



// Code for monordp

static LispObject CC_monordp(LispObject env,
                         LispObject v0000, LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0134, v0087, v0123, v0089;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for monordp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0002,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
// copy arguments values to proper place
    v0123 = v0002;
    v0089 = v0000;
// end of prologue
    v0087 = elt(env, 1); // wedge
    v0134 = elt(env, 2); // xorder
    v0134 = get(v0087, v0134);
    v0087 = v0089;
        return Lapply2(nil, 3, v0134, v0087, v0123);
}



// Code for union_edges

static LispObject CC_union_edges(LispObject env,
                         LispObject v0000, LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0060, v0059, v0111;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for union_edges");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0002,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0060 = v0002;
    v0059 = v0000;
// end of prologue

v0105:
    v0111 = v0059;
    if (v0111 == nil) { popv(2); return onevalue(v0060); }
    v0111 = v0059;
    v0111 = qcdr(v0111);
    stack[0] = v0111;
    v0059 = qcar(v0059);
    fn = elt(env, 1); // union_edge
    v0060 = (*qfn2(fn))(qenv(fn), v0059, v0060);
    nil = C_nil;
    if (exception_pending()) goto v0106;
    env = stack[-1];
    v0059 = stack[0];
    goto v0105;
// error exit handlers
v0106:
    popv(2);
    return nil;
}



// Code for errorp

static LispObject CC_errorp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0083, v0084;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for errorp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0084 = v0000;
// end of prologue
    v0083 = v0084;
    if (!consp(v0083)) goto v0001;
    v0083 = v0084;
    v0083 = qcdr(v0083);
    return onevalue(v0083);

v0001:
    v0083 = qvalue(elt(env, 1)); // t
    return onevalue(v0083);
}



// Code for cdiv

static LispObject CC_cdiv(LispObject env,
                         LispObject v0000, LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0084, v0085;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cdiv");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0002,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// copy arguments values to proper place
    v0084 = v0002;
    v0085 = v0000;
// end of prologue
    v0084 = cons(v0085, v0084);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[0];
    fn = elt(env, 1); // resimp
    v0084 = (*qfn1(fn))(qenv(fn), v0084);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    v0084 = qcar(v0084);
    { popv(1); return onevalue(v0084); }
// error exit handlers
v0061:
    popv(1);
    return nil;
}



// Code for add_prin_char

static LispObject CC_add_prin_char(LispObject env,
                         LispObject v0000, LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0151, v0055, v0056;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for add_prin_char");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0002,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0002;
    stack[-1] = v0000;
// end of prologue
    v0151 = qvalue(elt(env, 1)); // !*nat
    if (v0151 == nil) goto v0086;
    v0056 = qvalue(elt(env, 2)); // posn!*
    v0055 = stack[0];
    v0151 = qvalue(elt(env, 3)); // ycoord!*
    v0056 = acons(v0056, v0055, v0151);
    nil = C_nil;
    if (exception_pending()) goto v0140;
    env = stack[-2];
    v0055 = stack[-1];
    v0151 = qvalue(elt(env, 4)); // pline!*
    v0151 = acons(v0056, v0055, v0151);
    nil = C_nil;
    if (exception_pending()) goto v0140;
    env = stack[-2];
    qvalue(elt(env, 4)) = v0151; // pline!*
    v0151 = stack[0];
    qvalue(elt(env, 2)) = v0151; // posn!*
    { popv(3); return onevalue(v0151); }

v0086:
    v0151 = stack[-1];
    v0151 = Lstringp(nil, v0151);
    env = stack[-2];
    if (!(v0151 == nil)) goto v0066;
    v0151 = stack[-1];
    if (!symbolp(v0151)) v0151 = nil;
    else { v0151 = qfastgets(v0151);
           if (v0151 != nil) { v0151 = elt(v0151, 11); // switch!*
#ifdef RECORD_GET
             if (v0151 != SPID_NOPROP)
                record_get(elt(fastget_names, 11), 1);
             else record_get(elt(fastget_names, 11), 0),
                v0151 = nil; }
           else record_get(elt(fastget_names, 11), 0); }
#else
             if (v0151 == SPID_NOPROP) v0151 = nil; }}
#endif
    if (!(v0151 == nil)) goto v0066;
    v0151 = stack[-1];
    v0151 = Ldigitp(nil, v0151);
    env = stack[-2];
    if (!(v0151 == nil)) goto v0066;
    v0151 = stack[-1];
    v0151 = Lexplodec(nil, v0151);
    nil = C_nil;
    if (exception_pending()) goto v0140;
    v0151 = qcar(v0151);
    if (!symbolp(v0151)) v0151 = nil;
    else { v0151 = qfastgets(v0151);
           if (v0151 != nil) { v0151 = elt(v0151, 11); // switch!*
#ifdef RECORD_GET
             if (v0151 != SPID_NOPROP)
                record_get(elt(fastget_names, 11), 1);
             else record_get(elt(fastget_names, 11), 0),
                v0151 = nil; }
           else record_get(elt(fastget_names, 11), 0); }
#else
             if (v0151 == SPID_NOPROP) v0151 = nil; }}
#endif
    if (!(v0151 == nil)) goto v0066;
    v0151 = stack[-1];
        popv(3);
        return Lprin(nil, v0151);

v0066:
    v0151 = stack[-1];
        popv(3);
        return Lprinc(nil, v0151);
// error exit handlers
v0140:
    popv(3);
    return nil;
}



// Code for pv_sort2

static LispObject CC_pv_sort2(LispObject env,
                         LispObject v0000, LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0083, v0084;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pv_sort2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0002,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0002;
    v0083 = v0000;
// end of prologue
    v0084 = v0083;
    v0083 = stack[0];
    fn = elt(env, 1); // pv_sort2a
    v0083 = (*qfn2(fn))(qenv(fn), v0084, v0083);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    { LispObject res = stack[0]; popv(1); return onevalue(res); }
// error exit handlers
v0061:
    popv(1);
    return nil;
}



// Code for !*i2rn

static LispObject CC_Hi2rn(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0084, v0085, v0061;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *i2rn");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0084 = v0000;
// end of prologue
    v0061 = elt(env, 1); // !:rn!:
    v0085 = v0084;
    v0084 = (LispObject)17; // 1
    return list2star(v0061, v0085, v0084);
}



// Code for plus!-mod!-p

static LispObject CC_plusKmodKp(LispObject env,
                         LispObject v0000, LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0224, v0225, v0226;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for plus-mod-p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0002,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0002;
    stack[-1] = v0000;
// end of prologue
    stack[-2] = nil;
    goto v0067;

v0067:
    v0224 = stack[-1];
    if (v0224 == nil) goto v0083;
    v0224 = stack[0];
    if (v0224 == nil) goto v0062;
    v0224 = stack[-1];
    if (!consp(v0224)) goto v0089;
    v0224 = stack[-1];
    v0224 = qcar(v0224);
    v0224 = (consp(v0224) ? nil : lisp_true);
    goto v0123;

v0123:
    if (v0224 == nil) goto v0134;
    v0224 = stack[0];
    if (!consp(v0224)) goto v0102;
    v0224 = stack[0];
    v0224 = qcar(v0224);
    v0224 = (consp(v0224) ? nil : lisp_true);
    goto v0101;

v0101:
    if (v0224 == nil) goto v0056;
    v0225 = stack[-1];
    v0224 = stack[0];
    {   int32_t w = int_of_fixnum(v0225) + int_of_fixnum(v0224);
        if (w >= current_modulus) w -= current_modulus;
        v0224 = fixnum_of_int(w);
    }
    fn = elt(env, 3); // !*n2f
    v0224 = (*qfn1(fn))(qenv(fn), v0224);
    nil = C_nil;
    if (exception_pending()) goto v0020;
    env = stack[-3];
    v0225 = v0224;
    goto v0027;

v0027:
    v0224 = stack[-2];
    if (v0224 == nil) { popv(4); return onevalue(v0225); }
    v0224 = stack[-2];
    v0224 = qcdr(v0224);
    stack[-1] = v0224;
    v0224 = stack[-2];
    v0224 = Lrplacd(nil, v0224, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0020;
    env = stack[-3];
    v0224 = stack[-2];
    v0225 = v0224;
    v0224 = stack[-1];
    stack[-2] = v0224;
    goto v0027;

v0056:
    v0224 = stack[0];
    v0225 = qcar(v0224);
    v0224 = stack[-2];
    v0224 = cons(v0225, v0224);
    nil = C_nil;
    if (exception_pending()) goto v0020;
    env = stack[-3];
    stack[-2] = v0224;
    v0224 = stack[0];
    v0224 = qcdr(v0224);
    stack[0] = v0224;
    goto v0067;

v0102:
    v0224 = qvalue(elt(env, 1)); // t
    goto v0101;

v0134:
    v0224 = stack[0];
    if (!consp(v0224)) goto v0112;
    v0224 = stack[0];
    v0224 = qcar(v0224);
    v0224 = (consp(v0224) ? nil : lisp_true);
    goto v0113;

v0113:
    if (v0224 == nil) goto v0208;
    v0224 = stack[-1];
    v0225 = qcar(v0224);
    v0224 = stack[-2];
    v0224 = cons(v0225, v0224);
    nil = C_nil;
    if (exception_pending()) goto v0020;
    env = stack[-3];
    stack[-2] = v0224;
    v0224 = stack[-1];
    v0224 = qcdr(v0224);
    stack[-1] = v0224;
    goto v0067;

v0208:
    v0224 = stack[-1];
    v0224 = qcar(v0224);
    v0225 = qcar(v0224);
    v0224 = stack[0];
    v0224 = qcar(v0224);
    v0224 = qcar(v0224);
    if (equal(v0225, v0224)) goto v0156;
    v0224 = stack[-1];
    v0224 = qcar(v0224);
    v0224 = qcar(v0224);
    v0225 = qcar(v0224);
    v0224 = stack[0];
    v0224 = qcar(v0224);
    v0224 = qcar(v0224);
    v0224 = qcar(v0224);
    if (equal(v0225, v0224)) goto v0227;
    v0224 = qvalue(elt(env, 2)); // nil
    goto v0228;

v0228:
    if (!(v0224 == nil)) goto v0175;
    v0224 = stack[-1];
    v0224 = qcar(v0224);
    v0224 = qcar(v0224);
    v0225 = qcar(v0224);
    v0224 = stack[0];
    v0224 = qcar(v0224);
    v0224 = qcar(v0224);
    v0224 = qcar(v0224);
    if (equal(v0225, v0224)) goto v0229;
    v0224 = stack[-1];
    v0224 = qcar(v0224);
    v0224 = qcar(v0224);
    v0225 = qcar(v0224);
    v0224 = stack[0];
    v0224 = qcar(v0224);
    v0224 = qcar(v0224);
    v0224 = qcar(v0224);
    fn = elt(env, 4); // ordop
    v0224 = (*qfn2(fn))(qenv(fn), v0225, v0224);
    nil = C_nil;
    if (exception_pending()) goto v0020;
    env = stack[-3];
    goto v0230;

v0230:
    if (!(v0224 == nil)) goto v0175;
    v0224 = stack[0];
    v0225 = qcar(v0224);
    v0224 = stack[-2];
    v0224 = cons(v0225, v0224);
    nil = C_nil;
    if (exception_pending()) goto v0020;
    env = stack[-3];
    stack[-2] = v0224;
    v0224 = stack[0];
    v0224 = qcdr(v0224);
    stack[0] = v0224;
    goto v0067;

v0175:
    v0224 = stack[-1];
    v0225 = qcar(v0224);
    v0224 = stack[-2];
    v0224 = cons(v0225, v0224);
    nil = C_nil;
    if (exception_pending()) goto v0020;
    env = stack[-3];
    stack[-2] = v0224;
    v0224 = stack[-1];
    v0224 = qcdr(v0224);
    stack[-1] = v0224;
    goto v0067;

v0229:
    v0224 = qvalue(elt(env, 2)); // nil
    goto v0230;

v0227:
    v0224 = stack[-1];
    v0224 = qcar(v0224);
    v0224 = qcar(v0224);
    v0225 = qcdr(v0224);
    v0224 = stack[0];
    v0224 = qcar(v0224);
    v0224 = qcar(v0224);
    v0224 = qcdr(v0224);
    v0224 = ((intptr_t)v0225 > (intptr_t)v0224) ? lisp_true : nil;
    goto v0228;

v0156:
    v0224 = stack[-1];
    v0224 = qcar(v0224);
    v0225 = qcdr(v0224);
    v0224 = stack[0];
    v0224 = qcar(v0224);
    v0224 = qcdr(v0224);
    v0224 = CC_plusKmodKp(env, v0225, v0224);
    nil = C_nil;
    if (exception_pending()) goto v0020;
    env = stack[-3];
    v0225 = v0224;
    if (v0225 == nil) goto v0045;
    v0225 = stack[-1];
    v0225 = qcar(v0225);
    v0226 = qcar(v0225);
    v0225 = v0224;
    v0224 = stack[-2];
    v0224 = acons(v0226, v0225, v0224);
    nil = C_nil;
    if (exception_pending()) goto v0020;
    env = stack[-3];
    stack[-2] = v0224;
    goto v0045;

v0045:
    v0224 = stack[-1];
    v0224 = qcdr(v0224);
    stack[-1] = v0224;
    v0224 = stack[0];
    v0224 = qcdr(v0224);
    stack[0] = v0224;
    goto v0067;

v0112:
    v0224 = qvalue(elt(env, 1)); // t
    goto v0113;

v0089:
    v0224 = qvalue(elt(env, 1)); // t
    goto v0123;

v0062:
    v0224 = stack[-1];
    v0225 = v0224;
    goto v0027;

v0083:
    v0224 = stack[0];
    v0225 = v0224;
    goto v0027;
// error exit handlers
v0020:
    popv(4);
    return nil;
}



// Code for striptag

static LispObject CC_striptag(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0083, v0084;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for striptag");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0083 = v0000;
// end of prologue
    v0084 = v0083;
    if (!consp(v0084)) return onevalue(v0083);
    v0083 = qcdr(v0083);
    return onevalue(v0083);
}



// Code for printout

static LispObject CC_printout(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0132, v0122;
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
    v0132 = qvalue(elt(env, 1)); // !*web
    if (!(v0132 == nil)) goto v0086;
    v0132 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-2];
    goto v0086;

v0086:
    v0132 = qvalue(elt(env, 1)); // !*web
    if (!(v0132 == nil)) goto v0082;
    v0132 = (LispObject)17; // 1
    stack[-1] = v0132;
    goto v0108;

v0108:
    v0122 = qvalue(elt(env, 2)); // indent
    v0132 = stack[-1];
    v0132 = difference2(v0122, v0132);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-2];
    v0132 = Lminusp(nil, v0132);
    env = stack[-2];
    if (!(v0132 == nil)) goto v0082;
    v0132 = elt(env, 4); // " "
    v0132 = Lprinc(nil, v0132);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-2];
    v0132 = stack[-1];
    v0132 = add1(v0132);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-2];
    stack[-1] = v0132;
    goto v0108;

v0082:
    v0132 = stack[0];
    v0132 = Lconsp(nil, v0132);
    env = stack[-2];
    if (v0132 == nil) goto v0121;
    v0132 = stack[0];
    v0122 = qcar(v0132);
    v0132 = elt(env, 5); // !:rd!:
    if (v0122 == v0132) goto v0154;
    v0132 = stack[0];
    v0122 = qcar(v0132);
    v0132 = elt(env, 7); // !:rn!:
    v0132 = (v0122 == v0132 ? lisp_true : nil);
    goto v0095;

v0095:
    if (v0132 == nil) goto v0112;
    v0132 = stack[0];
    fn = elt(env, 8); // ma_print
    v0132 = (*qfn1(fn))(qenv(fn), v0132);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    goto v0102;

v0102:
    v0132 = nil;
    { popv(3); return onevalue(v0132); }

v0112:
    v0132 = stack[0];
    v0132 = Lprinc(nil, v0132);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    goto v0102;

v0154:
    v0132 = qvalue(elt(env, 6)); // t
    goto v0095;

v0121:
    v0132 = stack[0];
    v0132 = Lprinc(nil, v0132);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    goto v0102;
// error exit handlers
v0183:
    popv(3);
    return nil;
}



// Code for initcomb

static LispObject CC_initcomb(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0001;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for initcomb");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0001 = v0000;
// end of prologue
    return ncons(v0001);
}



// Code for evmatrixcomp

static LispObject CC_evmatrixcomp(LispObject env,
                         LispObject v0000, LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0085, v0061, v0062;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evmatrixcomp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0085 = v0002;
    v0061 = v0000;
// end of prologue
    v0062 = v0061;
    v0061 = v0085;
    v0085 = qvalue(elt(env, 1)); // vdpmatrix!*
    {
        fn = elt(env, 2); // evmatrixcomp1
        return (*qfnn(fn))(qenv(fn), 3, v0062, v0061, v0085);
    }
}



// Code for wedgepf2

static LispObject CC_wedgepf2(LispObject env,
                         LispObject v0000, LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0148, v0140;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for wedgepf2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0002,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0002;
    stack[-2] = v0000;
// end of prologue
    v0148 = stack[-2];
    if (v0148 == nil) goto v0125;
    v0148 = stack[-1];
    v0148 = (v0148 == nil ? lisp_true : nil);
    goto v0067;

v0067:
    if (v0148 == nil) goto v0060;
    v0148 = qvalue(elt(env, 2)); // nil
    { popv(5); return onevalue(v0148); }

v0060:
    v0148 = stack[-2];
    v0140 = qcar(v0148);
    v0148 = stack[-1];
    v0148 = qcar(v0148);
    fn = elt(env, 3); // wedget2
    stack[-3] = (*qfn2(fn))(qenv(fn), v0140, v0148);
    nil = C_nil;
    if (exception_pending()) goto v0147;
    env = stack[-4];
    v0148 = stack[-2];
    v0148 = qcar(v0148);
    v0140 = ncons(v0148);
    nil = C_nil;
    if (exception_pending()) goto v0147;
    env = stack[-4];
    v0148 = stack[-1];
    v0148 = qcdr(v0148);
    stack[0] = CC_wedgepf2(env, v0140, v0148);
    nil = C_nil;
    if (exception_pending()) goto v0147;
    env = stack[-4];
    v0148 = stack[-2];
    v0140 = qcdr(v0148);
    v0148 = stack[-1];
    v0148 = CC_wedgepf2(env, v0140, v0148);
    nil = C_nil;
    if (exception_pending()) goto v0147;
    env = stack[-4];
    fn = elt(env, 4); // addpf
    v0148 = (*qfn2(fn))(qenv(fn), stack[0], v0148);
    nil = C_nil;
    if (exception_pending()) goto v0147;
    env = stack[-4];
    {
        LispObject v0107 = stack[-3];
        popv(5);
        fn = elt(env, 4); // addpf
        return (*qfn2(fn))(qenv(fn), v0107, v0148);
    }

v0125:
    v0148 = qvalue(elt(env, 1)); // t
    goto v0067;
// error exit handlers
v0147:
    popv(5);
    return nil;
}



// Code for pprin2

static LispObject CC_pprin2(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0087, v0123;
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
    v0123 = stack[0];
    v0087 = qvalue(elt(env, 1)); // !*pprinbuf!*
    v0087 = cons(v0123, v0087);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-2];
    qvalue(elt(env, 1)) = v0087; // !*pprinbuf!*
    stack[-1] = qvalue(elt(env, 2)); // !*posn!*
    v0087 = stack[0];
    v0087 = Lexplodec(nil, v0087);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-2];
    v0087 = Llength(nil, v0087);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-2];
    v0087 = plus2(stack[-1], v0087);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-2];
    qvalue(elt(env, 2)) = v0087; // !*posn!*
    v0087 = nil;
    { popv(3); return onevalue(v0087); }
// error exit handlers
v0108:
    popv(3);
    return nil;
}



// Code for opmtch!*

static LispObject CC_opmtchH(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0083, v0084;
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
    v0084 = v0000;
// end of prologue
    v0083 = qvalue(elt(env, 1)); // subfg!*
    stack[0] = v0083;
    v0083 = qvalue(elt(env, 2)); // t
    qvalue(elt(env, 1)) = v0083; // subfg!*
    v0083 = v0084;
    fn = elt(env, 3); // opmtch
    v0083 = (*qfn1(fn))(qenv(fn), v0083);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-1];
    v0084 = v0083;
    v0083 = stack[0];
    qvalue(elt(env, 1)) = v0083; // subfg!*
    { popv(2); return onevalue(v0084); }
// error exit handlers
v0061:
    popv(2);
    return nil;
}



// Code for timesip

static LispObject CC_timesip(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0108, v0060, v0059;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for timesip");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0059 = v0000;
// end of prologue
    v0060 = v0059;
    v0108 = elt(env, 1); // times
    if (!consp(v0060)) goto v0123;
    v0060 = qcar(v0060);
    if (!(v0060 == v0108)) goto v0123;
    v0108 = elt(env, 2); // i
    v0060 = v0059;
    v0060 = qcdr(v0060);
    v0108 = Lmemq(nil, v0108, v0060);
    return onevalue(v0108);

v0123:
    v0108 = qvalue(elt(env, 3)); // nil
    return onevalue(v0108);
}



// Code for fs!:timestermterm

static LispObject CC_fsTtimestermterm(LispObject env,
                         LispObject v0000, LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0069, v0262, v0263;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for fs:timestermterm");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0002,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-6] = v0002;
    stack[-7] = v0000;
// end of prologue
    v0069 = (LispObject)113; // 7
    v0069 = Lmkvect(nil, v0069);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-9];
    stack[-8] = v0069;
    v0262 = stack[-7];
    v0069 = (LispObject)33; // 2
    v0069 = *(LispObject *)((char *)v0262 + (CELL-TAG_VECTOR) + ((int32_t)v0069/(16/CELL)));
    stack[-4] = v0069;
    v0262 = stack[-6];
    v0069 = (LispObject)33; // 2
    v0069 = *(LispObject *)((char *)v0262 + (CELL-TAG_VECTOR) + ((int32_t)v0069/(16/CELL)));
    stack[-3] = v0069;
    v0069 = (LispObject)1; // 0
    stack[-2] = v0069;
    goto v0150;

v0150:
    v0262 = (LispObject)113; // 7
    v0069 = stack[-2];
    v0069 = difference2(v0262, v0069);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-9];
    v0069 = Lminusp(nil, v0069);
    env = stack[-9];
    if (v0069 == nil) goto v0091;
    v0069 = (LispObject)113; // 7
    v0069 = Lmkvect(nil, v0069);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-9];
    stack[-5] = v0069;
    v0069 = (LispObject)1; // 0
    stack[-2] = v0069;
    goto v0209;

v0209:
    v0262 = (LispObject)113; // 7
    v0069 = stack[-2];
    v0069 = difference2(v0262, v0069);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-9];
    v0069 = Lminusp(nil, v0069);
    env = stack[-9];
    if (v0069 == nil) goto v0049;
    v0262 = stack[-7];
    v0069 = (LispObject)1; // 0
    v0263 = *(LispObject *)((char *)v0262 + (CELL-TAG_VECTOR) + ((int32_t)v0069/(16/CELL)));
    v0262 = stack[-6];
    v0069 = (LispObject)1; // 0
    v0069 = *(LispObject *)((char *)v0262 + (CELL-TAG_VECTOR) + ((int32_t)v0069/(16/CELL)));
    fn = elt(env, 5); // multsq
    v0069 = (*qfn2(fn))(qenv(fn), v0263, v0069);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-9];
    stack[0] = v0069;
    v0262 = stack[0];
    v0069 = elt(env, 2); // (1 . 2)
    fn = elt(env, 5); // multsq
    v0069 = (*qfn2(fn))(qenv(fn), v0262, v0069);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-9];
    stack[0] = v0069;
    v0069 = stack[0];
    v0069 = qcar(v0069);
    if (v0069 == nil) goto v0265;
    v0262 = stack[-7];
    v0069 = (LispObject)17; // 1
    v0262 = *(LispObject *)((char *)v0262 + (CELL-TAG_VECTOR) + ((int32_t)v0069/(16/CELL)));
    v0069 = elt(env, 3); // sin
    if (v0262 == v0069) goto v0031;
    v0262 = stack[-6];
    v0069 = (LispObject)17; // 1
    v0262 = *(LispObject *)((char *)v0262 + (CELL-TAG_VECTOR) + ((int32_t)v0069/(16/CELL)));
    v0069 = elt(env, 3); // sin
    if (v0262 == v0069) goto v0266;
    v0263 = elt(env, 4); // cos
    v0262 = stack[-8];
    v0069 = stack[0];
    fn = elt(env, 6); // make!-term
    stack[-1] = (*qfnn(fn))(qenv(fn), 3, v0263, v0262, v0069);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-9];
    v0263 = elt(env, 4); // cos
    v0262 = stack[-5];
    v0069 = stack[0];
    fn = elt(env, 6); // make!-term
    v0069 = (*qfnn(fn))(qenv(fn), 3, v0263, v0262, v0069);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-9];
    {
        LispObject v0267 = stack[-1];
        popv(10);
        fn = elt(env, 7); // fs!:plus
        return (*qfn2(fn))(qenv(fn), v0267, v0069);
    }

v0266:
    v0263 = elt(env, 3); // sin
    v0262 = stack[-8];
    v0069 = stack[0];
    fn = elt(env, 6); // make!-term
    stack[-2] = (*qfnn(fn))(qenv(fn), 3, v0263, v0262, v0069);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-9];
    stack[-1] = elt(env, 3); // sin
    stack[-3] = stack[-5];
    v0069 = stack[0];
    fn = elt(env, 8); // negsq
    v0069 = (*qfn1(fn))(qenv(fn), v0069);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-9];
    fn = elt(env, 6); // make!-term
    v0069 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[-3], v0069);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-9];
    {
        LispObject v0268 = stack[-2];
        popv(10);
        fn = elt(env, 7); // fs!:plus
        return (*qfn2(fn))(qenv(fn), v0268, v0069);
    }

v0031:
    v0262 = stack[-6];
    v0069 = (LispObject)17; // 1
    v0262 = *(LispObject *)((char *)v0262 + (CELL-TAG_VECTOR) + ((int32_t)v0069/(16/CELL)));
    v0069 = elt(env, 3); // sin
    if (v0262 == v0069) goto v0176;
    v0263 = elt(env, 3); // sin
    v0262 = stack[-8];
    v0069 = stack[0];
    fn = elt(env, 6); // make!-term
    stack[-1] = (*qfnn(fn))(qenv(fn), 3, v0263, v0262, v0069);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-9];
    v0263 = elt(env, 3); // sin
    v0262 = stack[-5];
    v0069 = stack[0];
    fn = elt(env, 6); // make!-term
    v0069 = (*qfnn(fn))(qenv(fn), 3, v0263, v0262, v0069);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-9];
    {
        LispObject v0269 = stack[-1];
        popv(10);
        fn = elt(env, 7); // fs!:plus
        return (*qfn2(fn))(qenv(fn), v0269, v0069);
    }

v0176:
    stack[-1] = elt(env, 4); // cos
    stack[-2] = stack[-8];
    v0069 = stack[0];
    fn = elt(env, 8); // negsq
    v0069 = (*qfn1(fn))(qenv(fn), v0069);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-9];
    fn = elt(env, 6); // make!-term
    stack[-1] = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[-2], v0069);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-9];
    v0263 = elt(env, 4); // cos
    v0262 = stack[-5];
    v0069 = stack[0];
    fn = elt(env, 6); // make!-term
    v0069 = (*qfnn(fn))(qenv(fn), 3, v0263, v0262, v0069);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-9];
    {
        LispObject v0270 = stack[-1];
        popv(10);
        fn = elt(env, 7); // fs!:plus
        return (*qfn2(fn))(qenv(fn), v0270, v0069);
    }

v0265:
    v0069 = qvalue(elt(env, 1)); // nil
    { popv(10); return onevalue(v0069); }

v0049:
    stack[-1] = stack[-5];
    stack[0] = stack[-2];
    v0262 = stack[-4];
    v0069 = stack[-2];
    v0263 = *(LispObject *)((char *)v0262 + (CELL-TAG_VECTOR) + ((int32_t)v0069/(16/CELL)));
    v0262 = stack[-3];
    v0069 = stack[-2];
    v0069 = *(LispObject *)((char *)v0262 + (CELL-TAG_VECTOR) + ((int32_t)v0069/(16/CELL)));
    v0069 = difference2(v0263, v0069);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-9];
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v0069;
    v0069 = stack[-2];
    v0069 = add1(v0069);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-9];
    stack[-2] = v0069;
    goto v0209;

v0091:
    stack[-1] = stack[-8];
    stack[0] = stack[-2];
    v0262 = stack[-4];
    v0069 = stack[-2];
    v0263 = *(LispObject *)((char *)v0262 + (CELL-TAG_VECTOR) + ((int32_t)v0069/(16/CELL)));
    v0262 = stack[-3];
    v0069 = stack[-2];
    v0069 = *(LispObject *)((char *)v0262 + (CELL-TAG_VECTOR) + ((int32_t)v0069/(16/CELL)));
    v0069 = plus2(v0263, v0069);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-9];
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v0069;
    v0069 = stack[-2];
    v0069 = add1(v0069);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-9];
    stack[-2] = v0069;
    goto v0150;
// error exit handlers
v0264:
    popv(10);
    return nil;
}



// Code for mo_vdivides!?

static LispObject CC_mo_vdividesW(LispObject env,
                         LispObject v0000, LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0059, v0111;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mo_vdivides?");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0002,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0002;
    stack[-1] = v0000;
// end of prologue
    v0059 = stack[-1];
    fn = elt(env, 2); // mo_comp
    stack[-2] = (*qfn1(fn))(qenv(fn), v0059);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-3];
    v0059 = stack[0];
    fn = elt(env, 2); // mo_comp
    v0059 = (*qfn1(fn))(qenv(fn), v0059);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-3];
    v0059 = Leqn(nil, stack[-2], v0059);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-3];
    if (v0059 == nil) goto v0086;
    v0111 = stack[-1];
    v0059 = stack[0];
    {
        popv(4);
        fn = elt(env, 3); // mo_divides!?
        return (*qfn2(fn))(qenv(fn), v0111, v0059);
    }

v0086:
    v0059 = qvalue(elt(env, 1)); // nil
    { popv(4); return onevalue(v0059); }
// error exit handlers
v0116:
    popv(4);
    return nil;
}



// Code for dless

static LispObject CC_dless(LispObject env,
                         LispObject v0000, LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0183, v0142, v0157;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dless");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0002,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    v0157 = v0002;
    stack[0] = v0000;
// end of prologue
    v0142 = qvalue(elt(env, 1)); // ordering
    v0183 = elt(env, 2); // lex
    if (v0142 == v0183) goto v0061;
    v0183 = stack[0];
    v0142 = qcar(v0183);
    v0183 = v0157;
    v0183 = qcar(v0183);
    if (((int32_t)(v0142)) < ((int32_t)(v0183))) goto v0087;
    v0183 = stack[0];
    v0142 = qcar(v0183);
    v0183 = v0157;
    v0183 = qcar(v0183);
    if (((int32_t)(v0142)) > ((int32_t)(v0183))) goto v0070;
    v0142 = qvalue(elt(env, 1)); // ordering
    v0183 = elt(env, 5); // glex
    if (v0142 == v0183) goto v0124;
    v0142 = qvalue(elt(env, 1)); // ordering
    v0183 = elt(env, 6); // grev
    if (v0142 == v0183) goto v0072;
    v0183 = nil;
    { popv(3); return onevalue(v0183); }

v0072:
    v0183 = v0157;
    v0183 = qcdr(v0183);
    stack[-1] = Lreverse(nil, v0183);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-2];
    v0183 = stack[0];
    v0183 = qcdr(v0183);
    v0183 = Lreverse(nil, v0183);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-2];
    {
        LispObject v0051 = stack[-1];
        popv(3);
        fn = elt(env, 7); // dlesslex
        return (*qfn2(fn))(qenv(fn), v0051, v0183);
    }

v0124:
    v0183 = stack[0];
    v0183 = qcdr(v0183);
    v0142 = v0157;
    v0142 = qcdr(v0142);
    {
        popv(3);
        fn = elt(env, 7); // dlesslex
        return (*qfn2(fn))(qenv(fn), v0183, v0142);
    }

v0070:
    v0183 = qvalue(elt(env, 4)); // nil
    { popv(3); return onevalue(v0183); }

v0087:
    v0183 = qvalue(elt(env, 3)); // t
    { popv(3); return onevalue(v0183); }

v0061:
    v0183 = stack[0];
    v0142 = v0157;
    {
        popv(3);
        fn = elt(env, 7); // dlesslex
        return (*qfn2(fn))(qenv(fn), v0183, v0142);
    }
// error exit handlers
v0184:
    popv(3);
    return nil;
}



setup_type const u02_setup[] =
{
    {"delcp",                   CC_delcp,       too_many_1,    wrong_no_1},
    {"mchk",                    too_few_2,      CC_mchk,       wrong_no_2},
    {"get+vec+entry",           too_few_2,      CC_getLvecLentry,wrong_no_2},
    {"qqe_qoptailp",            CC_qqe_qoptailp,too_many_1,    wrong_no_1},
    {"ibalp_cec",               CC_ibalp_cec,   too_many_1,    wrong_no_1},
    {"minusf",                  CC_minusf,      too_many_1,    wrong_no_1},
    {"reorder",                 CC_reorder,     too_many_1,    wrong_no_1},
    {"get_token",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_get_token},
    {"csl_normbf",              CC_csl_normbf,  too_many_1,    wrong_no_1},
    {"*q2a",                    CC_Hq2a,        too_many_1,    wrong_no_1},
    {"i2rd*",                   CC_i2rdH,       too_many_1,    wrong_no_1},
    {"addf",                    too_few_2,      CC_addf,       wrong_no_2},
    {"aeval*",                  CC_aevalH,      too_many_1,    wrong_no_1},
    {"adddm",                   too_few_2,      CC_adddm,      wrong_no_2},
    {"mo=sprod",                too_few_2,      CC_moMsprod,   wrong_no_2},
    {"sieve_pv",                too_few_2,      CC_sieve_pv,   wrong_no_2},
    {"general-modular-plus",    too_few_2,      CC_generalKmodularKplus,wrong_no_2},
    {"multiply-by-constant-mod-p",too_few_2,    CC_multiplyKbyKconstantKmodKp,wrong_no_2},
    {"mtchk",                   too_few_2,      CC_mtchk,      wrong_no_2},
    {"quotsq",                  too_few_2,      CC_quotsq,     wrong_no_2},
    {"exptchksq",               CC_exptchksq,   too_many_1,    wrong_no_1},
    {"setcar",                  too_few_2,      CC_setcar,     wrong_no_2},
    {"aex_ctx",                 CC_aex_ctx,     too_many_1,    wrong_no_1},
    {"notstring",               CC_notstring,   too_many_1,    wrong_no_1},
    {"constp",                  CC_constp,      too_many_1,    wrong_no_1},
    {"bczero?",                 CC_bczeroW,     too_many_1,    wrong_no_1},
    {"fast-row-dim",            CC_fastKrowKdim,too_many_1,    wrong_no_1},
    {"makelist",                CC_makelist,    too_many_1,    wrong_no_1},
    {"sinitl",                  CC_sinitl,      too_many_1,    wrong_no_1},
    {"smemqlp",                 too_few_2,      CC_smemqlp,    wrong_no_2},
    {"aeval",                   CC_aeval,       too_many_1,    wrong_no_1},
    {"angles-equal",            too_few_2,      CC_anglesKequal,wrong_no_2},
    {"multd",                   too_few_2,      CC_multd,      wrong_no_2},
    {"negnumberchk",            CC_negnumberchk,too_many_1,    wrong_no_1},
    {"pappl0",                  too_few_2,      CC_pappl0,     wrong_no_2},
    {"rnonep:",                 CC_rnonepT,     too_many_1,    wrong_no_1},
    {"modtimes:",               too_few_2,      CC_modtimesT,  wrong_no_2},
    {"remainder-in-vector",     wrong_no_na,    wrong_no_nb,   (n_args *)CC_remainderKinKvector},
    {"remove-free-vars-l",      CC_removeKfreeKvarsKl,too_many_1,wrong_no_1},
    {"get+vec+dim",             CC_getLvecLdim, too_many_1,    wrong_no_1},
    {"qqe_qopaddp",             CC_qqe_qopaddp, too_many_1,    wrong_no_1},
    {"pasf_susitf",             too_few_2,      CC_pasf_susitf,wrong_no_2},
    {"delq",                    too_few_2,      CC_delq,       wrong_no_2},
    {"sfto_dcontentf",          CC_sfto_dcontentf,too_many_1,  wrong_no_1},
    {"attributes",              too_few_2,      CC_attributes, wrong_no_2},
    {"c:ordexn",                too_few_2,      CC_cTordexn,   wrong_no_2},
    {"bcprod",                  too_few_2,      CC_bcprod,     wrong_no_2},
    {"evmatrixcomp1",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_evmatrixcomp1},
    {"multpfsq",                too_few_2,      CC_multpfsq,   wrong_no_2},
    {"arrayp",                  CC_arrayp,      too_many_1,    wrong_no_1},
    {"order:",                  CC_orderT,      too_many_1,    wrong_no_1},
    {"*collectphysops_reversed",too_few_2,      CC_Hcollectphysops_reversed,wrong_no_2},
    {"list2wideid",             CC_list2wideid, too_many_1,    wrong_no_1},
    {"mo=modiv1",               too_few_2,      CC_moMmodiv1,  wrong_no_2},
    {"unpkp",                   CC_unpkp,       too_many_1,    wrong_no_1},
    {"noncomp1",                CC_noncomp1,    too_many_1,    wrong_no_1},
    {"sizchk",                  too_few_2,      CC_sizchk,     wrong_no_2},
    {"gcdfd1",                  too_few_2,      CC_gcdfd1,     wrong_no_2},
    {"subs2f",                  CC_subs2f,      too_many_1,    wrong_no_1},
    {"qqe_qopheadp",            CC_qqe_qopheadp,too_many_1,    wrong_no_1},
    {"absf",                    CC_absf,        too_many_1,    wrong_no_1},
    {"get_content",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_get_content},
    {":zerop",                  CC_Tzerop,      too_many_1,    wrong_no_1},
    {"evcompless?",             too_few_2,      CC_evcomplessW,wrong_no_2},
    {"rd:zerop",                CC_rdTzerop,    too_many_1,    wrong_no_1},
    {"monordp",                 too_few_2,      CC_monordp,    wrong_no_2},
    {"union_edges",             too_few_2,      CC_union_edges,wrong_no_2},
    {"errorp",                  CC_errorp,      too_many_1,    wrong_no_1},
    {"cdiv",                    too_few_2,      CC_cdiv,       wrong_no_2},
    {"add_prin_char",           too_few_2,      CC_add_prin_char,wrong_no_2},
    {"pv_sort2",                too_few_2,      CC_pv_sort2,   wrong_no_2},
    {"*i2rn",                   CC_Hi2rn,       too_many_1,    wrong_no_1},
    {"plus-mod-p",              too_few_2,      CC_plusKmodKp, wrong_no_2},
    {"striptag",                CC_striptag,    too_many_1,    wrong_no_1},
    {"printout",                CC_printout,    too_many_1,    wrong_no_1},
    {"initcomb",                CC_initcomb,    too_many_1,    wrong_no_1},
    {"evmatrixcomp",            too_few_2,      CC_evmatrixcomp,wrong_no_2},
    {"wedgepf2",                too_few_2,      CC_wedgepf2,   wrong_no_2},
    {"pprin2",                  CC_pprin2,      too_many_1,    wrong_no_1},
    {"opmtch*",                 CC_opmtchH,     too_many_1,    wrong_no_1},
    {"timesip",                 CC_timesip,     too_many_1,    wrong_no_1},
    {"fs:timestermterm",        too_few_2,      CC_fsTtimestermterm,wrong_no_2},
    {"mo_vdivides?",            too_few_2,      CC_mo_vdividesW,wrong_no_2},
    {"dless",                   too_few_2,      CC_dless,      wrong_no_2},
    {NULL, (one_args *)"u02", (two_args *)"14279 6474604 8426151", 0}
};

// end of generated code
