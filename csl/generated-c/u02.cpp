
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



// Code for lalr_core

static LispObject CC_lalr_core(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0007;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lalr_core");
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
    v0007 = v0000;
// end of prologue
    v0007 = qcar(v0007);
    stack[-3] = v0007;
    v0007 = stack[-3];
    if (v0007 == nil) goto v0008;
    v0007 = stack[-3];
    v0007 = qcar(v0007);
    v0007 = qcar(v0007);
    v0007 = ncons(v0007);
    nil = C_nil;
    if (exception_pending()) goto v0009;
    env = stack[-4];
    stack[-1] = v0007;
    stack[-2] = v0007;
    goto v0010;

v0010:
    v0007 = stack[-3];
    v0007 = qcdr(v0007);
    stack[-3] = v0007;
    v0007 = stack[-3];
    if (v0007 == nil) goto v0011;
    stack[0] = stack[-1];
    v0007 = stack[-3];
    v0007 = qcar(v0007);
    v0007 = qcar(v0007);
    v0007 = ncons(v0007);
    nil = C_nil;
    if (exception_pending()) goto v0009;
    env = stack[-4];
    v0007 = Lrplacd(nil, stack[0], v0007);
    nil = C_nil;
    if (exception_pending()) goto v0009;
    env = stack[-4];
    v0007 = stack[-1];
    v0007 = qcdr(v0007);
    stack[-1] = v0007;
    goto v0010;

v0011:
    v0007 = stack[-2];
    goto v0012;

v0012:
    {
        popv(5);
        fn = elt(env, 2); // lalr_remove_duplicates
        return (*qfn1(fn))(qenv(fn), v0007);
    }

v0008:
    v0007 = qvalue(elt(env, 1)); // nil
    goto v0012;
// error exit handlers
v0009:
    popv(5);
    return nil;
}



// Code for prin2x

static LispObject CC_prin2x(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0014, v0015;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for prin2x");
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
    v0014 = v0000;
// end of prologue
    v0015 = v0014;
    v0014 = qvalue(elt(env, 1)); // outl!*
    v0014 = cons(v0015, v0014);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[0];
    qvalue(elt(env, 1)) = v0014; // outl!*
    { popv(1); return onevalue(v0014); }
// error exit handlers
v0016:
    popv(1);
    return nil;
}



// Code for rl_varlat

static LispObject CC_rl_varlat(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0015;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rl_varlat");
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
    v0015 = v0000;
// end of prologue
    stack[0] = qvalue(elt(env, 1)); // rl_varlat!*
    v0015 = ncons(v0015);
    nil = C_nil;
    if (exception_pending()) goto v0008;
    env = stack[-1];
    {
        LispObject v0017 = stack[0];
        popv(2);
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(qenv(fn), v0017, v0015);
    }
// error exit handlers
v0008:
    popv(2);
    return nil;
}



// Code for reorder

static LispObject CC_reorder(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0024, v0025;
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
    goto v0001;

v0001:
    v0024 = stack[-1];
    if (!consp(v0024)) goto v0026;
    v0024 = stack[-1];
    v0024 = qcar(v0024);
    v0024 = (consp(v0024) ? nil : lisp_true);
    goto v0017;

v0017:
    if (v0024 == nil) goto v0027;
    v0024 = stack[-1];
    v0025 = v0024;
    goto v0010;

v0010:
    v0024 = stack[-2];
    if (v0024 == nil) { popv(4); return onevalue(v0025); }
    v0024 = stack[-2];
    v0024 = qcar(v0024);
    fn = elt(env, 2); // raddf
    v0024 = (*qfn2(fn))(qenv(fn), v0024, v0025);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-3];
    v0025 = v0024;
    v0024 = stack[-2];
    v0024 = qcdr(v0024);
    stack[-2] = v0024;
    goto v0010;

v0027:
    v0024 = stack[-1];
    v0024 = qcar(v0024);
    stack[0] = qcar(v0024);
    v0024 = stack[-1];
    v0024 = qcar(v0024);
    v0024 = qcdr(v0024);
    v0024 = CC_reorder(env, v0024);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-3];
    fn = elt(env, 3); // rmultpf
    v0025 = (*qfn2(fn))(qenv(fn), stack[0], v0024);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-3];
    v0024 = stack[-2];
    v0024 = cons(v0025, v0024);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-3];
    stack[-2] = v0024;
    v0024 = stack[-1];
    v0024 = qcdr(v0024);
    stack[-1] = v0024;
    goto v0001;

v0026:
    v0024 = qvalue(elt(env, 1)); // t
    goto v0017;
// error exit handlers
v0028:
    popv(4);
    return nil;
}



// Code for aconc!*

static LispObject CC_aconcH(LispObject env,
                         LispObject v0000, LispObject v0029)
{
    LispObject nil = C_nil;
    LispObject v0016, v0008;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for aconc*");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0016 = v0029;
    v0008 = v0000;
// end of prologue
    stack[0] = v0008;
    v0016 = ncons(v0016);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    {
        LispObject v0030 = stack[0];
        popv(1);
        return Lnconc(nil, v0030, v0016);
    }
// error exit handlers
v0026:
    popv(1);
    return nil;
}



// Code for !*d2q

static LispObject CC_Hd2q(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0037, v0038;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *d2q");
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
    v0037 = stack[0];
    if (is_number(v0037)) goto v0006;
    v0037 = stack[0];
    fn = elt(env, 2); // !:zerop
    v0037 = (*qfn1(fn))(qenv(fn), v0037);
    nil = C_nil;
    if (exception_pending()) goto v0039;
    env = stack[-1];
    if (v0037 == nil) goto v0007;
    v0038 = qvalue(elt(env, 1)); // nil
    v0037 = (LispObject)17; // 1
    popv(2);
    return cons(v0038, v0037);

v0007:
    v0038 = stack[0];
    v0037 = (LispObject)17; // 1
    popv(2);
    return cons(v0038, v0037);

v0006:
    v0037 = stack[0];
    v0037 = (LispObject)zerop(v0037);
    v0037 = v0037 ? lisp_true : nil;
    env = stack[-1];
    if (v0037 == nil) goto v0040;
    v0038 = qvalue(elt(env, 1)); // nil
    v0037 = (LispObject)17; // 1
    popv(2);
    return cons(v0038, v0037);

v0040:
    v0038 = stack[0];
    v0037 = (LispObject)17; // 1
    popv(2);
    return cons(v0038, v0037);
// error exit handlers
v0039:
    popv(2);
    return nil;
}



// Code for ibalp_cequal

static LispObject CC_ibalp_cequal(LispObject env,
                         LispObject v0000, LispObject v0029)
{
    LispObject nil = C_nil;
    LispObject v0061, v0062;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_cequal");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
// copy arguments values to proper place
    stack[-4] = v0029;
    stack[-5] = v0000;
// end of prologue
    v0061 = stack[-5];
    v0061 = qcar(v0061);
    stack[-3] = v0061;
    v0061 = stack[-3];
    if (v0061 == nil) goto v0036;
    v0061 = stack[-3];
    v0061 = qcar(v0061);
    v0061 = qcar(v0061);
    v0061 = ncons(v0061);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    env = stack[-7];
    stack[-1] = v0061;
    stack[-2] = v0061;
    goto v0017;

v0017:
    v0061 = stack[-3];
    v0061 = qcdr(v0061);
    stack[-3] = v0061;
    v0061 = stack[-3];
    if (v0061 == nil) goto v0064;
    stack[0] = stack[-1];
    v0061 = stack[-3];
    v0061 = qcar(v0061);
    v0061 = qcar(v0061);
    v0061 = ncons(v0061);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    env = stack[-7];
    v0061 = Lrplacd(nil, stack[0], v0061);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    env = stack[-7];
    v0061 = stack[-1];
    v0061 = qcdr(v0061);
    stack[-1] = v0061;
    goto v0017;

v0064:
    v0061 = stack[-2];
    goto v0008;

v0008:
    stack[-6] = v0061;
    v0061 = stack[-4];
    v0061 = qcar(v0061);
    stack[-3] = v0061;
    v0061 = stack[-3];
    if (v0061 == nil) goto v0065;
    v0061 = stack[-3];
    v0061 = qcar(v0061);
    v0061 = qcar(v0061);
    v0061 = ncons(v0061);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    env = stack[-7];
    stack[-1] = v0061;
    stack[-2] = v0061;
    goto v0066;

v0066:
    v0061 = stack[-3];
    v0061 = qcdr(v0061);
    stack[-3] = v0061;
    v0061 = stack[-3];
    if (v0061 == nil) goto v0067;
    stack[0] = stack[-1];
    v0061 = stack[-3];
    v0061 = qcar(v0061);
    v0061 = qcar(v0061);
    v0061 = ncons(v0061);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    env = stack[-7];
    v0061 = Lrplacd(nil, stack[0], v0061);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    env = stack[-7];
    v0061 = stack[-1];
    v0061 = qcdr(v0061);
    stack[-1] = v0061;
    goto v0066;

v0067:
    v0061 = stack[-2];
    goto v0068;

v0068:
    v0062 = stack[-6];
    fn = elt(env, 2); // lto_setequalq
    v0061 = (*qfn2(fn))(qenv(fn), v0062, v0061);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    env = stack[-7];
    if (v0061 == nil) goto v0069;
    v0061 = stack[-5];
    v0061 = qcdr(v0061);
    v0061 = qcar(v0061);
    stack[-3] = v0061;
    v0061 = stack[-3];
    if (v0061 == nil) goto v0070;
    v0061 = stack[-3];
    v0061 = qcar(v0061);
    v0061 = qcar(v0061);
    v0061 = ncons(v0061);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    env = stack[-7];
    stack[-1] = v0061;
    stack[-2] = v0061;
    goto v0071;

v0071:
    v0061 = stack[-3];
    v0061 = qcdr(v0061);
    stack[-3] = v0061;
    v0061 = stack[-3];
    if (v0061 == nil) goto v0072;
    stack[0] = stack[-1];
    v0061 = stack[-3];
    v0061 = qcar(v0061);
    v0061 = qcar(v0061);
    v0061 = ncons(v0061);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    env = stack[-7];
    v0061 = Lrplacd(nil, stack[0], v0061);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    env = stack[-7];
    v0061 = stack[-1];
    v0061 = qcdr(v0061);
    stack[-1] = v0061;
    goto v0071;

v0072:
    v0061 = stack[-2];
    goto v0073;

v0073:
    stack[-3] = v0061;
    v0061 = stack[-4];
    v0061 = qcdr(v0061);
    v0061 = qcar(v0061);
    stack[-4] = v0061;
    v0061 = stack[-4];
    if (v0061 == nil) goto v0074;
    v0061 = stack[-4];
    v0061 = qcar(v0061);
    v0061 = qcar(v0061);
    v0061 = ncons(v0061);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    env = stack[-7];
    stack[-1] = v0061;
    stack[-2] = v0061;
    goto v0075;

v0075:
    v0061 = stack[-4];
    v0061 = qcdr(v0061);
    stack[-4] = v0061;
    v0061 = stack[-4];
    if (v0061 == nil) goto v0076;
    stack[0] = stack[-1];
    v0061 = stack[-4];
    v0061 = qcar(v0061);
    v0061 = qcar(v0061);
    v0061 = ncons(v0061);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    env = stack[-7];
    v0061 = Lrplacd(nil, stack[0], v0061);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    env = stack[-7];
    v0061 = stack[-1];
    v0061 = qcdr(v0061);
    stack[-1] = v0061;
    goto v0075;

v0076:
    v0061 = stack[-2];
    goto v0077;

v0077:
    v0062 = stack[-3];
    {
        popv(8);
        fn = elt(env, 2); // lto_setequalq
        return (*qfn2(fn))(qenv(fn), v0062, v0061);
    }

v0074:
    v0061 = qvalue(elt(env, 1)); // nil
    goto v0077;

v0070:
    v0061 = qvalue(elt(env, 1)); // nil
    goto v0073;

v0069:
    v0061 = qvalue(elt(env, 1)); // nil
    { popv(8); return onevalue(v0061); }

v0065:
    v0061 = qvalue(elt(env, 1)); // nil
    goto v0068;

v0036:
    v0061 = qvalue(elt(env, 1)); // nil
    goto v0008;
// error exit handlers
v0063:
    popv(8);
    return nil;
}



// Code for !*q2a

static LispObject CC_Hq2a(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0014, v0015;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *q2a");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0014 = v0000;
// end of prologue
    v0015 = v0014;
    v0014 = qvalue(elt(env, 1)); // !*nosq
    {
        fn = elt(env, 2); // !*q2a1
        return (*qfn2(fn))(qenv(fn), v0015, v0014);
    }
}



// Code for !:onep

static LispObject CC_Tonep(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0079, v0080;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for :onep");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0079 = v0000;
// end of prologue
    v0080 = v0079;
    if (!consp(v0080)) goto v0006;
    v0080 = v0079;
    v0080 = qcar(v0080);
    if (!symbolp(v0080)) v0080 = nil;
    else { v0080 = qfastgets(v0080);
           if (v0080 != nil) { v0080 = elt(v0080, 26); // onep
#ifdef RECORD_GET
             if (v0080 != SPID_NOPROP)
                record_get(elt(fastget_names, 26), 1);
             else record_get(elt(fastget_names, 26), 0),
                v0080 = nil; }
           else record_get(elt(fastget_names, 26), 0); }
#else
             if (v0080 == SPID_NOPROP) v0080 = nil; }}
#endif
        return Lapply1(nil, v0080, v0079);

v0006:
        return Lonep(nil, v0079);
}



// Code for buchvevdivides!?

static LispObject CC_buchvevdividesW(LispObject env,
                         LispObject v0000, LispObject v0029)
{
    LispObject nil = C_nil;
    LispObject v0002, v0003, v0023;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for buchvevdivides?");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0029;
    stack[-1] = v0000;
// end of prologue
    v0003 = stack[0];
    v0002 = stack[-1];
    fn = elt(env, 4); // vevmtest!?
    v0002 = (*qfn2(fn))(qenv(fn), v0003, v0002);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-2];
    if (v0002 == nil) goto v0005;
    v0002 = qvalue(elt(env, 2)); // gmodule!*
    if (v0002 == nil) goto v0035;
    v0023 = stack[-1];
    v0003 = stack[0];
    v0002 = qvalue(elt(env, 2)); // gmodule!*
    {
        popv(3);
        fn = elt(env, 5); // gevcompatible1
        return (*qfnn(fn))(qenv(fn), 3, v0023, v0003, v0002);
    }

v0035:
    v0002 = qvalue(elt(env, 3)); // t
    { popv(3); return onevalue(v0002); }

v0005:
    v0002 = qvalue(elt(env, 1)); // nil
    { popv(3); return onevalue(v0002); }
// error exit handlers
v0032:
    popv(3);
    return nil;
}



// Code for vevmtest!?

static LispObject CC_vevmtestW(LispObject env,
                         LispObject v0000, LispObject v0029)
{
    LispObject nil = C_nil;
    LispObject v0085, v0086, v0087, v0088;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vevmtest?");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// copy arguments values to proper place
    v0086 = v0029;
    v0087 = v0000;
// end of prologue

v0005:
    v0085 = v0086;
    if (v0085 == nil) goto v0010;
    v0085 = v0087;
    if (v0085 == nil) goto v0016;
    v0085 = v0087;
    v0088 = qcar(v0085);
    v0085 = v0086;
    v0085 = qcar(v0085);
    if (((int32_t)(v0088)) < ((int32_t)(v0085))) goto v0089;
    v0085 = v0087;
    v0085 = qcdr(v0085);
    v0087 = v0085;
    v0085 = v0086;
    v0085 = qcdr(v0085);
    v0086 = v0085;
    goto v0005;

v0089:
    v0085 = qvalue(elt(env, 2)); // nil
    { popv(1); return onevalue(v0085); }

v0016:
    v0085 = v0086;
    if (v0085 == nil) goto v0079;
    v0085 = v0086;
    v0087 = qcar(v0085);
    v0085 = (LispObject)1; // 0
    if (v0087 == v0085) goto v0034;
    v0085 = qvalue(elt(env, 2)); // nil
    goto v0035;

v0035:
    if (v0085 == nil) goto v0007;
    v0085 = qvalue(elt(env, 1)); // t
    { popv(1); return onevalue(v0085); }

v0007:
    v0085 = qvalue(elt(env, 2)); // nil
    { popv(1); return onevalue(v0085); }

v0034:
    v0085 = v0086;
    v0085 = qcdr(v0085);
    fn = elt(env, 3); // vevzero!?1
    v0085 = (*qfn1(fn))(qenv(fn), v0085);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[0];
    goto v0035;

v0079:
    v0085 = qvalue(elt(env, 1)); // t
    goto v0035;

v0010:
    v0085 = qvalue(elt(env, 1)); // t
    { popv(1); return onevalue(v0085); }
// error exit handlers
v0090:
    popv(1);
    return nil;
}



// Code for ordpp

static LispObject CC_ordpp(LispObject env,
                         LispObject v0000, LispObject v0029)
{
    LispObject nil = C_nil;
    LispObject v0086, v0087, v0088, v0090, v0067;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ordpp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0088 = v0029;
    v0090 = v0000;
// end of prologue
    v0086 = v0090;
    v0087 = qcar(v0086);
    v0086 = v0088;
    v0086 = qcar(v0086);
    if (v0087 == v0086) goto v0079;
    v0086 = qvalue(elt(env, 1)); // kord!*
    v0067 = v0086;
    v0086 = v0090;
    v0086 = qcar(v0086);
    v0090 = v0086;
    v0086 = v0088;
    v0086 = qcar(v0086);
    v0088 = v0086;
    goto v0001;

v0001:
    v0086 = v0067;
    if (v0086 == nil) goto v0033;
    v0087 = v0090;
    v0086 = v0067;
    v0086 = qcar(v0086);
    if (v0087 == v0086) goto v0093;
    v0087 = v0088;
    v0086 = v0067;
    v0086 = qcar(v0086);
    if (v0087 == v0086) goto v0094;
    v0086 = v0067;
    v0086 = qcdr(v0086);
    v0067 = v0086;
    goto v0001;

v0094:
    v0086 = qvalue(elt(env, 3)); // nil
    return onevalue(v0086);

v0093:
    v0086 = qvalue(elt(env, 2)); // t
    return onevalue(v0086);

v0033:
    v0086 = v0090;
    v0087 = v0088;
    {
        fn = elt(env, 4); // ordpa
        return (*qfn2(fn))(qenv(fn), v0086, v0087);
    }

v0079:
    v0086 = v0090;
    v0086 = qcdr(v0086);
    v0087 = v0088;
    v0087 = qcdr(v0087);
        return Lgreaterp(nil, v0086, v0087);
}



// Code for sublistp

static LispObject CC_sublistp(LispObject env,
                         LispObject v0000, LispObject v0029)
{
    LispObject nil = C_nil;
    LispObject v0060, v0095, v0007, v0092;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sublistp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0095 = v0029;
    v0007 = v0000;
// end of prologue

v0096:
    v0060 = v0007;
    if (v0060 == nil) goto v0005;
    v0060 = v0007;
    v0092 = qcar(v0060);
    v0060 = v0095;
    v0060 = Lmember(nil, v0092, v0060);
    if (v0060 == nil) goto v0008;
    v0060 = v0007;
    stack[0] = qcdr(v0060);
    v0060 = v0007;
    v0060 = qcar(v0060);
    v0060 = Ldelete(nil, v0060, v0095);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-1];
    v0007 = stack[0];
    v0095 = v0060;
    goto v0096;

v0008:
    v0060 = qvalue(elt(env, 2)); // nil
    { popv(2); return onevalue(v0060); }

v0005:
    v0060 = qvalue(elt(env, 1)); // t
    { popv(2); return onevalue(v0060); }
// error exit handlers
v0097:
    popv(2);
    return nil;
}



// Code for csl_normbf

static LispObject CC_csl_normbf(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0067, v0099, v0100;
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
    v0067 = stack[-2];
    v0067 = qcdr(v0067);
    v0099 = qcar(v0067);
    stack[0] = v0099;
    v0067 = (LispObject)1; // 0
    if (v0099 == v0067) goto v0014;
    v0099 = stack[0];
    v0067 = (LispObject)1; // 0
    v0067 = (LispObject)lessp2(v0099, v0067);
    nil = C_nil;
    if (exception_pending()) goto v0101;
    v0067 = v0067 ? lisp_true : nil;
    env = stack[-4];
    if (v0067 == nil) goto v0102;
    v0067 = stack[0];
    v0067 = negate(v0067);
    nil = C_nil;
    if (exception_pending()) goto v0101;
    env = stack[-4];
    stack[0] = v0067;
    v0067 = qvalue(elt(env, 2)); // t
    stack[-3] = v0067;
    goto v0102;

v0102:
    v0067 = stack[0];
    fn = elt(env, 4); // lsd
    v0067 = (*qfn1(fn))(qenv(fn), v0067);
    nil = C_nil;
    if (exception_pending()) goto v0101;
    env = stack[-4];
    stack[-1] = v0067;
    v0067 = stack[-1];
    v0067 = negate(v0067);
    nil = C_nil;
    if (exception_pending()) goto v0101;
    env = stack[-4];
    fn = elt(env, 5); // lshift
    v0067 = (*qfn2(fn))(qenv(fn), stack[0], v0067);
    nil = C_nil;
    if (exception_pending()) goto v0101;
    env = stack[-4];
    stack[0] = v0067;
    v0067 = stack[-3];
    if (v0067 == nil) goto v0039;
    v0067 = stack[0];
    v0067 = negate(v0067);
    nil = C_nil;
    if (exception_pending()) goto v0101;
    env = stack[-4];
    stack[0] = v0067;
    goto v0039;

v0039:
    v0099 = stack[-1];
    v0067 = stack[-2];
    v0067 = qcdr(v0067);
    v0067 = qcdr(v0067);
    v0067 = plus2(v0099, v0067);
    nil = C_nil;
    if (exception_pending()) goto v0101;
    env = stack[-4];
    stack[-1] = v0067;
    v0100 = elt(env, 3); // !:rd!:
    v0099 = stack[0];
    v0067 = stack[-1];
    popv(5);
    return list2star(v0100, v0099, v0067);

v0014:
    v0067 = elt(env, 1); // (!:rd!: 0 . 0)
    { popv(5); return onevalue(v0067); }
// error exit handlers
v0101:
    popv(5);
    return nil;
}



// Code for reval_without_mod

static LispObject CC_reval_without_mod(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0079, v0080, v0102;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for reval_without_mod");
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
    v0102 = v0000;
// end of prologue
    v0080 = qvalue(elt(env, 1)); // dmode!*
    v0079 = elt(env, 2); // !:mod!:
    if (v0080 == v0079) goto v0006;
    v0079 = v0102;
    {
        popv(2);
        fn = elt(env, 4); // reval
        return (*qfn1(fn))(qenv(fn), v0079);
    }

v0006:
    v0079 = qvalue(elt(env, 3)); // nil
    stack[0] = qvalue(elt(env, 1)); // dmode!*
    qvalue(elt(env, 1)) = v0079; // dmode!*
    v0079 = v0102;
    fn = elt(env, 4); // reval
    v0079 = (*qfn1(fn))(qenv(fn), v0079);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; // dmode!*
    { popv(2); return onevalue(v0079); }
// error exit handlers
v0103:
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; // dmode!*
    popv(2);
    return nil;
}



// Code for addf

static LispObject CC_addf(LispObject env,
                         LispObject v0000, LispObject v0029)
{
    LispObject nil = C_nil;
    LispObject v0116, v0117, v0118;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for addf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0029;
    stack[-1] = v0000;
// end of prologue
    stack[-2] = nil;
    goto v0012;

v0012:
    v0116 = stack[-1];
    if (v0116 == nil) goto v0015;
    v0116 = stack[0];
    if (v0116 == nil) goto v0026;
    v0116 = stack[-1];
    if (!consp(v0116)) goto v0102;
    v0116 = stack[-1];
    v0116 = qcar(v0116);
    v0116 = (consp(v0116) ? nil : lisp_true);
    goto v0080;

v0080:
    if (v0116 == nil) goto v0035;
    v0117 = stack[-1];
    v0116 = stack[0];
    fn = elt(env, 3); // addd
    v0116 = (*qfn2(fn))(qenv(fn), v0117, v0116);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-3];
    goto v0120;

v0120:
    v0117 = stack[-2];
    if (v0117 == nil) { popv(4); return onevalue(v0116); }
    v0117 = stack[-2];
    v0117 = qcdr(v0117);
    stack[-1] = v0117;
    v0117 = stack[-2];
    v0116 = Lrplacd(nil, v0117, v0116);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-3];
    v0116 = stack[-2];
    v0117 = stack[-1];
    stack[-2] = v0117;
    goto v0120;

v0035:
    v0116 = stack[0];
    if (!consp(v0116)) goto v0060;
    v0116 = stack[0];
    v0116 = qcar(v0116);
    v0116 = (consp(v0116) ? nil : lisp_true);
    goto v0022;

v0022:
    if (v0116 == nil) goto v0084;
    v0117 = stack[0];
    v0116 = stack[-1];
    fn = elt(env, 3); // addd
    v0116 = (*qfn2(fn))(qenv(fn), v0117, v0116);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-3];
    goto v0120;

v0084:
    v0116 = stack[-1];
    v0116 = qcar(v0116);
    v0117 = qcar(v0116);
    v0116 = stack[0];
    v0116 = qcar(v0116);
    v0116 = qcar(v0116);
    if (equal(v0117, v0116)) goto v0090;
    v0116 = stack[-1];
    v0116 = qcar(v0116);
    v0117 = qcar(v0116);
    v0116 = stack[0];
    v0116 = qcar(v0116);
    v0116 = qcar(v0116);
    fn = elt(env, 4); // ordpp
    v0116 = (*qfn2(fn))(qenv(fn), v0117, v0116);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-3];
    if (v0116 == nil) goto v0121;
    v0116 = stack[-1];
    v0117 = qcar(v0116);
    v0116 = stack[-2];
    v0116 = cons(v0117, v0116);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-3];
    stack[-2] = v0116;
    v0116 = stack[-1];
    v0116 = qcdr(v0116);
    stack[-1] = v0116;
    goto v0012;

v0121:
    v0116 = stack[0];
    v0117 = qcar(v0116);
    v0116 = stack[-2];
    v0116 = cons(v0117, v0116);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-3];
    stack[-2] = v0116;
    v0116 = stack[0];
    v0116 = qcdr(v0116);
    stack[0] = v0116;
    goto v0012;

v0090:
    v0116 = stack[-1];
    v0116 = qcar(v0116);
    v0117 = qcdr(v0116);
    v0116 = stack[0];
    v0116 = qcar(v0116);
    v0116 = qcdr(v0116);
    v0116 = CC_addf(env, v0117, v0116);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-3];
    v0117 = v0116;
    if (v0117 == nil) goto v0059;
    v0117 = stack[-1];
    v0117 = qcar(v0117);
    v0118 = qcar(v0117);
    v0117 = v0116;
    v0116 = stack[-2];
    v0116 = acons(v0118, v0117, v0116);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-3];
    stack[-2] = v0116;
    goto v0059;

v0059:
    v0116 = stack[-1];
    v0116 = qcdr(v0116);
    stack[-1] = v0116;
    v0116 = stack[0];
    v0116 = qcdr(v0116);
    stack[0] = v0116;
    goto v0012;

v0060:
    v0116 = qvalue(elt(env, 1)); // t
    goto v0022;

v0102:
    v0116 = qvalue(elt(env, 1)); // t
    goto v0080;

v0026:
    v0116 = stack[-1];
    goto v0120;

v0015:
    v0116 = stack[0];
    goto v0120;
// error exit handlers
v0119:
    popv(4);
    return nil;
}



// Code for mo!=sprod

static LispObject CC_moMsprod(LispObject env,
                         LispObject v0000, LispObject v0029)
{
    LispObject nil = C_nil;
    LispObject v0084, v0024, v0025;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mo=sprod");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0029;
    stack[-1] = v0000;
// end of prologue
    v0025 = nil;
    goto v0012;

v0012:
    v0084 = stack[-1];
    if (v0084 == nil) goto v0030;
    v0084 = stack[0];
    v0084 = (v0084 == nil ? lisp_true : nil);
    goto v0026;

v0026:
    if (v0084 == nil) goto v0021;
    v0084 = (LispObject)1; // 0
    goto v0013;

v0013:
    v0024 = v0025;
    if (v0024 == nil) { popv(3); return onevalue(v0084); }
    v0024 = v0025;
    v0024 = qcar(v0024);
    v0084 = (LispObject)(int32_t)((int32_t)v0024 + (int32_t)v0084 - TAG_FIXNUM);
    v0024 = v0025;
    v0024 = qcdr(v0024);
    v0025 = v0024;
    goto v0013;

v0021:
    v0084 = stack[-1];
    v0024 = qcar(v0084);
    v0084 = stack[0];
    v0084 = qcar(v0084);
    v0084 = fixnum_of_int((int32_t)(int_of_fixnum(v0024) * int_of_fixnum(v0084)));
    v0024 = v0025;
    v0084 = cons(v0084, v0024);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-2];
    v0025 = v0084;
    v0084 = stack[-1];
    v0084 = qcdr(v0084);
    stack[-1] = v0084;
    v0084 = stack[0];
    v0084 = qcdr(v0084);
    stack[0] = v0084;
    goto v0012;

v0030:
    v0084 = qvalue(elt(env, 1)); // t
    goto v0026;
// error exit handlers
v0089:
    popv(3);
    return nil;
}



// Code for reduce_pv

static LispObject CC_reduce_pv(LispObject env,
                         LispObject v0000, LispObject v0029)
{
    LispObject nil = C_nil;
    LispObject v0017, v0026, v0030;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for reduce_pv");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0017 = v0029;
    v0026 = v0000;
// end of prologue
    v0030 = v0026;
    v0026 = v0017;
    v0017 = qvalue(elt(env, 1)); // t
    {
        fn = elt(env, 2); // reduce_pv0
        return (*qfnn(fn))(qenv(fn), 3, v0030, v0026, v0017);
    }
}



// Code for !*i2mod

static LispObject CC_Hi2mod(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0005;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *i2mod");
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
    v0005 = v0000;
// end of prologue
    fn = elt(env, 1); // general!-modular!-number
    v0005 = (*qfn1(fn))(qenv(fn), v0005);
    nil = C_nil;
    if (exception_pending()) goto v0001;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); // !*modular2f
        return (*qfn1(fn))(qenv(fn), v0005);
    }
// error exit handlers
v0001:
    popv(1);
    return nil;
}



// Code for general!-modular!-plus

static LispObject CC_generalKmodularKplus(LispObject env,
                         LispObject v0000, LispObject v0029)
{
    LispObject nil = C_nil;
    LispObject v0082, v0083;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for general-modular-plus");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0082 = v0029;
    v0083 = v0000;
// end of prologue
    v0082 = plus2(v0083, v0082);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    env = stack[-1];
    stack[0] = v0082;
    v0083 = stack[0];
    v0082 = qvalue(elt(env, 1)); // current!-modulus
    v0082 = (LispObject)geq2(v0083, v0082);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    v0082 = v0082 ? lisp_true : nil;
    env = stack[-1];
    if (v0082 == nil) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    v0083 = stack[0];
    v0082 = qvalue(elt(env, 1)); // current!-modulus
    v0082 = difference2(v0083, v0082);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    stack[0] = v0082;
    { LispObject res = stack[0]; popv(2); return onevalue(res); }
// error exit handlers
v0003:
    popv(2);
    return nil;
}



// Code for lalr_first

static LispObject CC_lalr_first(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0069, v0127, v0128;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lalr_first");
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
    stack[0] = nil;
    goto v0010;

v0010:
    v0069 = stack[-1];
    if (v0069 == nil) goto v0012;
    v0069 = stack[-1];
    v0069 = qcar(v0069);
    if (is_number(v0069)) goto v0003;
    v0128 = qvalue(elt(env, 1)); // nil
    v0069 = stack[-1];
    v0127 = qcar(v0069);
    v0069 = elt(env, 0); // lalr_first
    v0069 = get(v0127, v0069);
    env = stack[-3];
    stack[0] = v0069;
    v0069 = Lmember(nil, v0128, v0069);
    goto v0078;

v0078:
    if (v0069 == nil) goto v0012;
    v0127 = qvalue(elt(env, 1)); // nil
    v0069 = stack[0];
    v0127 = Ldeleq(nil, v0127, v0069);
    env = stack[-3];
    v0069 = stack[-2];
    fn = elt(env, 2); // union
    v0069 = (*qfn2(fn))(qenv(fn), v0127, v0069);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-3];
    stack[-2] = v0069;
    v0069 = stack[-1];
    v0069 = qcdr(v0069);
    stack[-1] = v0069;
    goto v0010;

v0012:
    v0069 = stack[-1];
    if (v0069 == nil) goto v0025;
    v0069 = stack[-1];
    v0069 = qcar(v0069);
    if (is_number(v0069)) goto v0099;
    v0127 = stack[0];
    v0069 = stack[-2];
    fn = elt(env, 2); // union
    v0069 = (*qfn2(fn))(qenv(fn), v0127, v0069);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    stack[-2] = v0069;
    { LispObject res = stack[-2]; popv(4); return onevalue(res); }

v0099:
    v0069 = stack[-1];
    v0069 = qcar(v0069);
    v0127 = ncons(v0069);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-3];
    v0069 = stack[-2];
    fn = elt(env, 2); // union
    v0069 = (*qfn2(fn))(qenv(fn), v0127, v0069);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    stack[-2] = v0069;
    { LispObject res = stack[-2]; popv(4); return onevalue(res); }

v0025:
    v0127 = qvalue(elt(env, 1)); // nil
    v0069 = stack[-2];
    v0069 = cons(v0127, v0069);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    stack[-2] = v0069;
    { LispObject res = stack[-2]; popv(4); return onevalue(res); }

v0003:
    v0069 = qvalue(elt(env, 1)); // nil
    goto v0078;
// error exit handlers
v0111:
    popv(4);
    return nil;
}



// Code for sort

static LispObject CC_sort(LispObject env,
                         LispObject v0000, LispObject v0029)
{
    LispObject nil = C_nil;
    LispObject v0129, v0036;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sort");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0029;
    v0129 = v0000;
// end of prologue
    v0036 = v0129;
    v0129 = qvalue(elt(env, 1)); // nil
    v0036 = Lappend(nil, v0036, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0079;
    env = stack[-1];
    v0129 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); // stable!-sortip
        return (*qfn2(fn))(qenv(fn), v0036, v0129);
    }
// error exit handlers
v0079:
    popv(2);
    return nil;
}



// Code for finde

static LispObject CC_finde(LispObject env,
                         LispObject v0000, LispObject v0029)
{
    LispObject nil = C_nil;
    LispObject v0034, v0021, v0027, v0098;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for finde");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0098 = v0029;
    v0027 = v0000;
// end of prologue

v0005:
    v0034 = v0027;
    if (v0034 == nil) goto v0010;
    v0021 = v0098;
    v0034 = v0027;
    v0034 = qcar(v0034);
    v0034 = qcdr(v0034);
    v0034 = Lmemq(nil, v0021, v0034);
    if (!(v0034 == nil)) return onevalue(v0027);
    v0034 = v0027;
    v0034 = qcdr(v0034);
    v0027 = v0034;
    goto v0005;

v0010:
    v0034 = qvalue(elt(env, 1)); // nil
    return onevalue(v0034);
}



// Code for mchk

static LispObject CC_mchk(LispObject env,
                         LispObject v0000, LispObject v0029)
{
    LispObject nil = C_nil;
    LispObject v0166, v0167, v0168;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mchk");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    stack[-3] = v0029;
    stack[-4] = v0000;
// end of prologue

v0014:
    v0167 = stack[-4];
    v0166 = stack[-3];
    if (equal(v0167, v0166)) goto v0010;
    v0167 = stack[-4];
    v0166 = elt(env, 2); // !*sq
    if (!consp(v0167)) goto v0083;
    v0167 = qcar(v0167);
    if (!(v0167 == v0166)) goto v0083;
    v0166 = stack[-4];
    v0166 = qcdr(v0166);
    v0166 = qcar(v0166);
    fn = elt(env, 7); // prepsqxx
    v0166 = (*qfn1(fn))(qenv(fn), v0166);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-6];
    stack[-4] = v0166;
    goto v0014;

v0083:
    v0167 = stack[-3];
    v0166 = elt(env, 2); // !*sq
    if (!consp(v0167)) goto v0081;
    v0167 = qcar(v0167);
    if (!(v0167 == v0166)) goto v0081;
    v0166 = stack[-3];
    v0166 = qcdr(v0166);
    v0166 = qcar(v0166);
    fn = elt(env, 7); // prepsqxx
    v0166 = (*qfn1(fn))(qenv(fn), v0166);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-6];
    stack[-3] = v0166;
    goto v0014;

v0081:
    v0166 = stack[-3];
    if (!consp(v0166)) goto v0038;
    v0166 = stack[-4];
    if (!consp(v0166)) goto v0090;
    v0166 = stack[-3];
    v0167 = qcar(v0166);
    v0166 = elt(env, 5); // difference
    if (v0167 == v0166) goto v0072;
    v0166 = stack[-4];
    v0166 = qcar(v0166);
    if (!symbolp(v0166)) v0166 = nil;
    else { v0166 = qfastgets(v0166);
           if (v0166 != nil) { v0166 = elt(v0166, 8); // dname
#ifdef RECORD_GET
             if (v0166 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v0166 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v0166 == SPID_NOPROP) v0166 = nil; }}
#endif
    if (!(v0166 == nil)) goto v0043;
    v0166 = stack[-3];
    v0166 = qcar(v0166);
    if (!symbolp(v0166)) v0166 = nil;
    else { v0166 = qfastgets(v0166);
           if (v0166 != nil) { v0166 = elt(v0166, 8); // dname
#ifdef RECORD_GET
             if (v0166 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v0166 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v0166 == SPID_NOPROP) v0166 = nil; }}
#endif
    if (!(v0166 == nil)) goto v0043;
    v0166 = stack[-4];
    v0167 = qcar(v0166);
    v0166 = stack[-3];
    v0166 = qcar(v0166);
    if (v0167 == v0166) goto v0170;
    v0166 = stack[-3];
    v0167 = qcar(v0166);
    v0166 = qvalue(elt(env, 3)); // frlis!*
    v0166 = Lmemq(nil, v0167, v0166);
    if (v0166 == nil) goto v0171;
    v0166 = stack[-4];
    v0168 = qcar(v0166);
    v0166 = stack[-3];
    v0167 = qcar(v0166);
    v0166 = stack[-4];
    v0166 = qcdr(v0166);
    stack[0] = Lsubst(nil, 3, v0168, v0167, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-6];
    v0166 = stack[-4];
    v0168 = qcar(v0166);
    v0166 = stack[-3];
    v0167 = qcar(v0166);
    v0166 = stack[-3];
    v0166 = qcdr(v0166);
    v0167 = Lsubst(nil, 3, v0168, v0167, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-6];
    v0166 = stack[-4];
    v0166 = qcar(v0166);
    fn = elt(env, 8); // mcharg
    v0166 = (*qfnn(fn))(qenv(fn), 3, stack[0], v0167, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-6];
    stack[-5] = v0166;
    v0166 = stack[-5];
    if (v0166 == nil) goto v0172;
    v0166 = stack[-5];
    v0166 = qcar(v0166);
    v0167 = stack[-3];
    v0168 = qcar(v0167);
    v0167 = stack[-4];
    v0167 = qcar(v0167);
    v0166 = acons(v0168, v0167, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-6];
    v0166 = ncons(v0166);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-6];
    stack[-1] = v0166;
    stack[-2] = v0166;
    goto v0173;

v0173:
    v0166 = stack[-5];
    v0166 = qcdr(v0166);
    stack[-5] = v0166;
    v0166 = stack[-5];
    if (v0166 == nil) { LispObject res = stack[-2]; popv(7); return onevalue(res); }
    stack[0] = stack[-1];
    v0166 = stack[-5];
    v0166 = qcar(v0166);
    v0167 = stack[-3];
    v0168 = qcar(v0167);
    v0167 = stack[-4];
    v0167 = qcar(v0167);
    v0166 = acons(v0168, v0167, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-6];
    v0166 = ncons(v0166);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-6];
    v0166 = Lrplacd(nil, stack[0], v0166);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-6];
    v0166 = stack[-1];
    v0166 = qcdr(v0166);
    stack[-1] = v0166;
    goto v0173;

v0172:
    v0166 = qvalue(elt(env, 1)); // nil
    { popv(7); return onevalue(v0166); }

v0171:
    v0166 = stack[-4];
    v0167 = qcar(v0166);
    v0166 = elt(env, 4); // minus
    if (v0167 == v0166) goto v0174;
    v0167 = stack[-4];
    v0166 = stack[-3];
    {
        popv(7);
        fn = elt(env, 9); // mchkopt
        return (*qfn2(fn))(qenv(fn), v0167, v0166);
    }

v0174:
    v0166 = stack[-4];
    v0166 = qcdr(v0166);
    v0167 = qcar(v0166);
    v0166 = stack[-3];
    {
        popv(7);
        fn = elt(env, 10); // mchkminus
        return (*qfn2(fn))(qenv(fn), v0167, v0166);
    }

v0170:
    v0166 = stack[-4];
    v0168 = qcdr(v0166);
    v0166 = stack[-3];
    v0167 = qcdr(v0166);
    v0166 = stack[-4];
    v0166 = qcar(v0166);
    {
        popv(7);
        fn = elt(env, 8); // mcharg
        return (*qfnn(fn))(qenv(fn), 3, v0168, v0167, v0166);
    }

v0043:
    v0166 = qvalue(elt(env, 1)); // nil
    { popv(7); return onevalue(v0166); }

v0072:
    stack[-1] = elt(env, 6); // plus
    v0166 = stack[-3];
    v0166 = qcdr(v0166);
    stack[0] = qcar(v0166);
    v0167 = elt(env, 4); // minus
    v0166 = stack[-3];
    v0166 = qcdr(v0166);
    v0166 = qcdr(v0166);
    v0166 = qcar(v0166);
    v0166 = list2(v0167, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-6];
    v0166 = list3(stack[-1], stack[0], v0166);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-6];
    stack[-3] = v0166;
    goto v0014;

v0090:
    v0166 = stack[-4];
    if (!(is_number(v0166))) goto v0175;
    v0167 = stack[-4];
    v0166 = (LispObject)1; // 0
    v0166 = (LispObject)lessp2(v0167, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    v0166 = v0166 ? lisp_true : nil;
    env = stack[-6];
    if (v0166 == nil) goto v0175;
    v0167 = stack[-3];
    v0166 = elt(env, 4); // minus
    if (!consp(v0167)) goto v0175;
    v0167 = qcar(v0167);
    if (!(v0167 == v0166)) goto v0175;
    stack[0] = elt(env, 4); // minus
    v0166 = stack[-4];
    v0166 = negate(v0166);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-6];
    v0166 = list2(stack[0], v0166);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-6];
    stack[-4] = v0166;
    goto v0014;

v0175:
    v0167 = stack[-4];
    v0166 = stack[-3];
    {
        popv(7);
        fn = elt(env, 9); // mchkopt
        return (*qfn2(fn))(qenv(fn), v0167, v0166);
    }

v0038:
    v0167 = stack[-3];
    v0166 = qvalue(elt(env, 3)); // frlis!*
    v0166 = Lmemq(nil, v0167, v0166);
    if (v0166 == nil) goto v0086;
    v0167 = stack[-3];
    v0166 = stack[-4];
    v0166 = cons(v0167, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-6];
    v0166 = ncons(v0166);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    popv(7);
    return ncons(v0166);

v0086:
    v0166 = qvalue(elt(env, 1)); // nil
    { popv(7); return onevalue(v0166); }

v0010:
    v0166 = qvalue(elt(env, 1)); // nil
    popv(7);
    return ncons(v0166);
// error exit handlers
v0169:
    popv(7);
    return nil;
}



// Code for quotsq

static LispObject CC_quotsq(LispObject env,
                         LispObject v0000, LispObject v0029)
{
    LispObject nil = C_nil;
    LispObject v0016, v0008;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for quotsq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0016 = v0029;
    v0008 = v0000;
// end of prologue
    stack[0] = v0008;
    fn = elt(env, 1); // invsq
    v0016 = (*qfn1(fn))(qenv(fn), v0016);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-1];
    {
        LispObject v0030 = stack[0];
        popv(2);
        fn = elt(env, 2); // multsq
        return (*qfn2(fn))(qenv(fn), v0030, v0016);
    }
// error exit handlers
v0026:
    popv(2);
    return nil;
}



// Code for tayexp!-lessp

static LispObject CC_tayexpKlessp(LispObject env,
                         LispObject v0000, LispObject v0029)
{
    LispObject nil = C_nil;
    LispObject v0083, v0002, v0003;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for tayexp-lessp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// copy arguments values to proper place
    v0002 = v0029;
    v0003 = v0000;
// end of prologue
    v0083 = v0003;
    if (!consp(v0083)) goto v0013;
    v0083 = qvalue(elt(env, 1)); // nil
    goto v0010;

v0010:
    if (v0083 == nil) goto v0034;
    v0083 = v0003;
        popv(1);
        return Llessp(nil, v0083, v0002);

v0034:
    v0083 = v0003;
    fn = elt(env, 2); // tayexp!-difference
    v0083 = (*qfn2(fn))(qenv(fn), v0083, v0002);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); // !:minusp
        return (*qfn1(fn))(qenv(fn), v0083);
    }

v0013:
    v0083 = v0002;
    v0083 = (consp(v0083) ? nil : lisp_true);
    goto v0010;
// error exit handlers
v0023:
    popv(1);
    return nil;
}



// Code for get!+vec!+entry

static LispObject CC_getLvecLentry(LispObject env,
                         LispObject v0000, LispObject v0029)
{
    LispObject nil = C_nil;
    LispObject v0008, v0017;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for get+vec+entry");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0008 = v0029;
    v0017 = v0000;
// end of prologue
    {
        fn = elt(env, 1); // nth
        return (*qfn2(fn))(qenv(fn), v0017, v0008);
    }
}



// Code for mri_floorkernelp

static LispObject CC_mri_floorkernelp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0005;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mri_floorkernelp");
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
    v0005 = v0000;
// end of prologue
    fn = elt(env, 1); // kernels
    v0005 = (*qfn1(fn))(qenv(fn), v0005);
    nil = C_nil;
    if (exception_pending()) goto v0001;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); // mri_floorp
        return (*qfn1(fn))(qenv(fn), v0005);
    }
// error exit handlers
v0001:
    popv(1);
    return nil;
}



// Code for qqe_qoptailp

static LispObject CC_qqe_qoptailp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0026, v0030;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qqe_qoptailp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0026 = v0000;
// end of prologue
    v0030 = v0026;
    v0026 = elt(env, 1); // (rtail ltail)
    v0026 = Lmemq(nil, v0030, v0026);
    if (v0026 == nil) goto v0005;
    v0026 = qvalue(elt(env, 2)); // t
    return onevalue(v0026);

v0005:
    v0026 = nil;
    return onevalue(v0026);
}



// Code for ibalp_cec

static LispObject CC_ibalp_cec(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0080;
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

v0006:
    v0080 = stack[0];
    if (v0080 == nil) goto v0012;
    v0080 = stack[0];
    v0080 = qcar(v0080);
    fn = elt(env, 2); // ibalp_emptyclausep
    v0080 = (*qfn1(fn))(qenv(fn), v0080);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-1];
    if (v0080 == nil) goto v0129;
    v0080 = stack[0];
    v0080 = qcar(v0080);
    { popv(2); return onevalue(v0080); }

v0129:
    v0080 = stack[0];
    v0080 = qcdr(v0080);
    stack[0] = v0080;
    goto v0006;

v0012:
    v0080 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0080); }
// error exit handlers
v0040:
    popv(2);
    return nil;
}



// Code for get_token

static LispObject CC_get_token(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0083, v0002;
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
    v0083 = qvalue(elt(env, 1)); // nil
    stack[0] = v0083;
    goto v0016;

v0016:
    v0002 = Lreadch(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[-1];
    qvalue(elt(env, 2)) = v0002; // ch
    v0083 = elt(env, 3); // !>
    if (v0002 == v0083) goto v0034;
    v0002 = qvalue(elt(env, 2)); // ch
    v0083 = stack[0];
    v0083 = cons(v0002, v0083);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[-1];
    stack[0] = v0083;
    goto v0016;

v0034:
    v0002 = elt(env, 4); // !$
    v0083 = stack[0];
    popv(2);
    return cons(v0002, v0083);
// error exit handlers
v0023:
    popv(2);
    return nil;
}



// Code for xsimp

static LispObject CC_xsimp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0005;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for xsimp");
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
    v0005 = v0000;
// end of prologue
    fn = elt(env, 1); // simp!*
    v0005 = (*qfn1(fn))(qenv(fn), v0005);
    nil = C_nil;
    if (exception_pending()) goto v0001;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); // expchk
        return (*qfn1(fn))(qenv(fn), v0005);
    }
// error exit handlers
v0001:
    popv(1);
    return nil;
}



// Code for prepsqxx

static LispObject CC_prepsqxx(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0005;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for prepsqxx");
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
    v0005 = v0000;
// end of prologue
    fn = elt(env, 1); // prepsqx
    v0005 = (*qfn1(fn))(qenv(fn), v0005);
    nil = C_nil;
    if (exception_pending()) goto v0001;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); // negnumberchk
        return (*qfn1(fn))(qenv(fn), v0005);
    }
// error exit handlers
v0001:
    popv(1);
    return nil;
}



// Code for makelist

static LispObject CC_makelist(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0014, v0015;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for makelist");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0014 = v0000;
// end of prologue
    v0015 = elt(env, 1); // list
    return cons(v0015, v0014);
}



// Code for i2rd!*

static LispObject CC_i2rdH(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0005;
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
    v0005 = v0000;
// end of prologue
    fn = elt(env, 1); // chkint!*
    v0005 = (*qfn1(fn))(qenv(fn), v0005);
    nil = C_nil;
    if (exception_pending()) goto v0001;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); // mkround
        return (*qfn1(fn))(qenv(fn), v0005);
    }
// error exit handlers
v0001:
    popv(1);
    return nil;
}



// Code for collectindices_reversed

static LispObject CC_collectindices_reversed(LispObject env,
                         LispObject v0000, LispObject v0029)
{
    LispObject nil = C_nil;
    LispObject v0093, v0097;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for collectindices_reversed");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0029;
    stack[-1] = v0000;
// end of prologue
    v0093 = stack[-1];
    if (!(!consp(v0093))) goto v0034;
    v0093 = stack[-1];
    fn = elt(env, 2); // isanindex
    v0093 = (*qfn1(fn))(qenv(fn), v0093);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    if (v0093 == nil) { LispObject res = stack[0]; popv(3); return onevalue(res); }
    v0097 = stack[-1];
    v0093 = stack[0];
    popv(3);
    return cons(v0097, v0093);

v0034:
    v0093 = stack[-1];
    if (v0093 == nil) { LispObject res = stack[0]; popv(3); return onevalue(res); }
    v0093 = stack[-1];
    v0097 = qcar(v0093);
    v0093 = stack[0];
    v0093 = CC_collectindices_reversed(env, v0097, v0093);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    env = stack[-2];
    stack[0] = v0093;
    v0093 = stack[-1];
    v0093 = qcdr(v0093);
    stack[-1] = v0093;
    goto v0034;
// error exit handlers
v0031:
    popv(3);
    return nil;
}



// Code for aeval!*

static LispObject CC_aevalH(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0017, v0026;
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
    v0017 = qvalue(elt(env, 1)); // nil
    v0017 = ncons(v0017);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-1];
    qvalue(elt(env, 2)) = v0017; // alglist!*
    v0026 = stack[0];
    v0017 = qvalue(elt(env, 1)); // nil
    {
        popv(2);
        fn = elt(env, 3); // reval1
        return (*qfn2(fn))(qenv(fn), v0026, v0017);
    }
// error exit handlers
v0078:
    popv(2);
    return nil;
}



// Code for adddm

static LispObject CC_adddm(LispObject env,
                         LispObject v0000, LispObject v0029)
{
    LispObject nil = C_nil;
    LispObject v0089, v0028, v0115;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for adddm");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// copy arguments values to proper place
    v0028 = v0029;
    v0115 = v0000;
// end of prologue
    v0089 = v0115;
    if (!consp(v0089)) goto v0013;
    v0089 = qvalue(elt(env, 1)); // nil
    goto v0010;

v0010:
    if (v0089 == nil) goto v0065;
    v0089 = v0115;
    v0089 = plus2(v0089, v0028);
    nil = C_nil;
    if (exception_pending()) goto v0085;
    env = stack[0];
    v0028 = qvalue(elt(env, 2)); // dmode!*
    if (v0028 == nil) goto v0098;
    v0028 = qvalue(elt(env, 2)); // dmode!*
    if (!symbolp(v0028)) v0028 = nil;
    else { v0028 = qfastgets(v0028);
           if (v0028 != nil) { v0028 = elt(v0028, 5); // convert
#ifdef RECORD_GET
             if (v0028 == SPID_NOPROP)
                record_get(elt(fastget_names, 5), 0),
                v0028 = nil;
             else record_get(elt(fastget_names, 5), 1),
                v0028 = lisp_true; }
           else record_get(elt(fastget_names, 5), 0); }
#else
             if (v0028 == SPID_NOPROP) v0028 = nil; else v0028 = lisp_true; }}
#endif
    v0028 = (v0028 == nil ? lisp_true : nil);
    goto v0027;

v0027:
    if (v0028 == nil) goto v0092;
    {
        popv(1);
        fn = elt(env, 5); // !*n2f
        return (*qfn1(fn))(qenv(fn), v0089);
    }

v0092:
    v0028 = qvalue(elt(env, 2)); // dmode!*
    if (!symbolp(v0028)) v0028 = nil;
    else { v0028 = qfastgets(v0028);
           if (v0028 != nil) { v0028 = elt(v0028, 34); // i2d
#ifdef RECORD_GET
             if (v0028 != SPID_NOPROP)
                record_get(elt(fastget_names, 34), 1);
             else record_get(elt(fastget_names, 34), 0),
                v0028 = nil; }
           else record_get(elt(fastget_names, 34), 0); }
#else
             if (v0028 == SPID_NOPROP) v0028 = nil; }}
#endif
    v0089 = Lapply1(nil, v0028, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0085;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 6); // int!-equiv!-chk
        return (*qfn1(fn))(qenv(fn), v0089);
    }

v0098:
    v0028 = qvalue(elt(env, 3)); // t
    goto v0027;

v0065:
    v0089 = elt(env, 4); // plus
    {
        popv(1);
        fn = elt(env, 7); // dcombine
        return (*qfnn(fn))(qenv(fn), 3, v0115, v0028, v0089);
    }

v0013:
    v0089 = v0028;
    v0089 = (consp(v0089) ? nil : lisp_true);
    goto v0010;
// error exit handlers
v0085:
    popv(1);
    return nil;
}



// Code for angles!-equal

static LispObject CC_anglesKequal(LispObject env,
                         LispObject v0000, LispObject v0029)
{
    LispObject nil = C_nil;
    LispObject v0097, v0178, v0009;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for angles-equal");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0029;
    stack[-1] = v0000;
// end of prologue
    v0097 = (LispObject)1; // 0
    stack[-2] = v0097;
    goto v0078;

v0078:
    v0178 = stack[-1];
    v0097 = stack[-2];
    v0009 = *(LispObject *)((char *)v0178 + (CELL-TAG_VECTOR) + ((int32_t)v0097/(16/CELL)));
    v0178 = stack[0];
    v0097 = stack[-2];
    v0097 = *(LispObject *)((char *)v0178 + (CELL-TAG_VECTOR) + ((int32_t)v0097/(16/CELL)));
    if (equal(v0009, v0097)) goto v0013;
    v0097 = qvalue(elt(env, 1)); // nil
    { popv(4); return onevalue(v0097); }

v0013:
    v0097 = stack[-2];
    v0097 = add1(v0097);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[-3];
    stack[-2] = v0097;
    v0178 = stack[-2];
    v0097 = (LispObject)129; // 8
    v0097 = (LispObject)lessp2(v0178, v0097);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    v0097 = v0097 ? lisp_true : nil;
    env = stack[-3];
    if (!(v0097 == nil)) goto v0078;
    v0097 = qvalue(elt(env, 2)); // t
    { popv(4); return onevalue(v0097); }
// error exit handlers
v0057:
    popv(4);
    return nil;
}



// Code for cali_bc_prod

static LispObject CC_cali_bc_prod(LispObject env,
                         LispObject v0000, LispObject v0029)
{
    LispObject nil = C_nil;
    LispObject v0016, v0008;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cali_bc_prod");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// copy arguments values to proper place
    v0016 = v0029;
    v0008 = v0000;
// end of prologue
    fn = elt(env, 1); // multf
    v0016 = (*qfn2(fn))(qenv(fn), v0008, v0016);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); // bc!=simp
        return (*qfn1(fn))(qenv(fn), v0016);
    }
// error exit handlers
v0017:
    popv(1);
    return nil;
}



// Code for sieve_pv

static LispObject CC_sieve_pv(LispObject env,
                         LispObject v0000, LispObject v0029)
{
    LispObject nil = C_nil;
    LispObject v0017, v0026, v0030;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sieve_pv");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0017 = v0029;
    v0026 = v0000;
// end of prologue
    v0030 = v0026;
    v0026 = v0017;
    v0017 = qvalue(elt(env, 1)); // t
    {
        fn = elt(env, 2); // sieve_pv0
        return (*qfnn(fn))(qenv(fn), 3, v0030, v0026, v0017);
    }
}



// Code for rnonep!:

static LispObject CC_rnonepT(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0126, v0034, v0021;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rnonep:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0021 = v0000;
// end of prologue
    v0126 = v0021;
    v0126 = qcdr(v0126);
    v0034 = qcar(v0126);
    v0126 = (LispObject)17; // 1
    if (v0034 == v0126) goto v0026;
    v0126 = qvalue(elt(env, 1)); // nil
    return onevalue(v0126);

v0026:
    v0126 = v0021;
    v0126 = qcdr(v0126);
    v0034 = qcdr(v0126);
    v0126 = (LispObject)17; // 1
    v0126 = (v0034 == v0126 ? lisp_true : nil);
    return onevalue(v0126);
}



// Code for multiply!-by!-constant!-mod!-p

static LispObject CC_multiplyKbyKconstantKmodKp(LispObject env,
                         LispObject v0000, LispObject v0029)
{
    LispObject nil = C_nil;
    LispObject v0052, v0054, v0053;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for multiply-by-constant-mod-p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0029;
    stack[-2] = v0000;
// end of prologue
    stack[-3] = nil;
    v0052 = stack[-2];
    if (v0052 == nil) goto v0013;
    v0054 = stack[-1];
    v0052 = (LispObject)17; // 1
    if (v0054 == v0052) { LispObject res = stack[-2]; popv(5); return onevalue(res); }
    else goto v0103;

v0103:
    v0052 = stack[-2];
    if (!consp(v0052)) goto v0098;
    v0052 = stack[-2];
    v0052 = qcar(v0052);
    v0052 = (consp(v0052) ? nil : lisp_true);
    goto v0027;

v0027:
    if (v0052 == nil) goto v0022;
    v0052 = stack[-2];
    if (v0052 == nil) goto v0181;
    v0054 = stack[-2];
    v0052 = stack[-1];
    v0052 = Lmodular_times(nil, v0054, v0052);
    env = stack[-4];
    fn = elt(env, 3); // !*n2f
    v0052 = (*qfn1(fn))(qenv(fn), v0052);
    nil = C_nil;
    if (exception_pending()) goto v0175;
    env = stack[-4];
    stack[-2] = v0052;
    goto v0181;

v0181:
    v0052 = stack[-3];
    if (v0052 == nil) { LispObject res = stack[-2]; popv(5); return onevalue(res); }
    v0052 = stack[-3];
    v0052 = qcdr(v0052);
    stack[0] = v0052;
    v0054 = stack[-3];
    v0052 = stack[-2];
    v0052 = Lrplacd(nil, v0054, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0175;
    env = stack[-4];
    v0052 = stack[-3];
    stack[-2] = v0052;
    v0052 = stack[0];
    stack[-3] = v0052;
    goto v0181;

v0022:
    v0052 = stack[-2];
    v0052 = qcar(v0052);
    v0054 = qcdr(v0052);
    v0052 = stack[-1];
    v0052 = CC_multiplyKbyKconstantKmodKp(env, v0054, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0175;
    env = stack[-4];
    stack[0] = v0052;
    v0052 = stack[0];
    if (v0052 == nil) goto v0037;
    v0052 = stack[-2];
    v0052 = qcar(v0052);
    v0053 = qcar(v0052);
    v0054 = stack[0];
    v0052 = stack[-3];
    v0052 = acons(v0053, v0054, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0175;
    env = stack[-4];
    stack[-3] = v0052;
    goto v0037;

v0037:
    v0052 = stack[-2];
    v0052 = qcdr(v0052);
    stack[-2] = v0052;
    goto v0103;

v0098:
    v0052 = qvalue(elt(env, 2)); // t
    goto v0027;

v0013:
    v0052 = qvalue(elt(env, 1)); // nil
    { popv(5); return onevalue(v0052); }
// error exit handlers
v0175:
    popv(5);
    return nil;
}



// Code for list2wideid

static LispObject CC_list2wideid(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0005;
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
    v0005 = v0000;
// end of prologue
    fn = elt(env, 1); // list2widestring
    v0005 = (*qfn1(fn))(qenv(fn), v0005);
    errexit();
        return Lintern(nil, v0005);
}



// Code for sfto_dcontentf

static LispObject CC_sfto_dcontentf(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0014, v0015;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sfto_dcontentf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0014 = v0000;
// end of prologue
    v0015 = v0014;
    v0014 = qvalue(elt(env, 1)); // nil
    {
        fn = elt(env, 2); // sfto_dcontentf1
        return (*qfn2(fn))(qenv(fn), v0015, v0014);
    }
}



// Code for monomclone

static LispObject CC_monomclone(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0090, v0067, v0099, v0100;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for monomclone");
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
    v0090 = stack[0];
    if (v0090 == nil) goto v0006;
    stack[-2] = nil;
    v0090 = (LispObject)17; // 1
    v0090 = Lmkvect(nil, v0090);
    nil = C_nil;
    if (exception_pending()) goto v0101;
    env = stack[-4];
    stack[-3] = v0090;
    v0100 = stack[-3];
    v0099 = (LispObject)1; // 0
    v0067 = stack[0];
    v0090 = (LispObject)1; // 0
    v0090 = *(LispObject *)((char *)v0067 + (CELL-TAG_VECTOR) + ((int32_t)v0090/(16/CELL)));
    *(LispObject *)((char *)v0100 + (CELL-TAG_VECTOR) + ((int32_t)v0099/(16/CELL))) = v0090;
    v0067 = stack[0];
    v0090 = (LispObject)17; // 1
    v0090 = *(LispObject *)((char *)v0067 + (CELL-TAG_VECTOR) + ((int32_t)v0090/(16/CELL)));
    stack[0] = v0090;
    goto v0060;

v0060:
    v0090 = stack[0];
    if (v0090 == nil) goto v0084;
    v0090 = stack[0];
    v0067 = qcar(v0090);
    v0090 = stack[-2];
    v0090 = cons(v0067, v0090);
    nil = C_nil;
    if (exception_pending()) goto v0101;
    env = stack[-4];
    stack[-2] = v0090;
    v0090 = stack[0];
    v0090 = qcdr(v0090);
    stack[0] = v0090;
    goto v0060;

v0084:
    stack[-1] = stack[-3];
    stack[0] = (LispObject)17; // 1
    v0090 = stack[-2];
    v0090 = Lreverse(nil, v0090);
    nil = C_nil;
    if (exception_pending()) goto v0101;
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v0090;
    { LispObject res = stack[-3]; popv(5); return onevalue(res); }

v0006:
    v0090 = qvalue(elt(env, 1)); // nil
    { popv(5); return onevalue(v0090); }
// error exit handlers
v0101:
    popv(5);
    return nil;
}



// Code for arrayp

static LispObject CC_arrayp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0015, v0016;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for arrayp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0015 = v0000;
// end of prologue
    if (!symbolp(v0015)) v0015 = nil;
    else { v0015 = qfastgets(v0015);
           if (v0015 != nil) { v0015 = elt(v0015, 2); // rtype
#ifdef RECORD_GET
             if (v0015 != SPID_NOPROP)
                record_get(elt(fastget_names, 2), 1);
             else record_get(elt(fastget_names, 2), 0),
                v0015 = nil; }
           else record_get(elt(fastget_names, 2), 0); }
#else
             if (v0015 == SPID_NOPROP) v0015 = nil; }}
#endif
    v0016 = elt(env, 1); // array
    v0015 = (v0015 == v0016 ? lisp_true : nil);
    return onevalue(v0015);
}



// Code for comfac!-to!-poly

static LispObject CC_comfacKtoKpoly(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0017, v0026;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for comfac-to-poly");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0017 = v0000;
// end of prologue
    v0026 = v0017;
    v0026 = qcar(v0026);
    if (v0026 == nil) goto v0006;
    return ncons(v0017);

v0006:
    v0017 = qcdr(v0017);
    return onevalue(v0017);
}



// Code for mtchk

static LispObject CC_mtchk(LispObject env,
                         LispObject v0000, LispObject v0029)
{
    LispObject nil = C_nil;
    LispObject v0195, v0196, v0148, v0197;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mtchk");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    stack[-8] = v0029;
    stack[-9] = v0000;
// end of prologue
    stack[-4] = nil;
    stack[-3] = nil;
    v0195 = stack[-9];
    v0195 = qcar(v0195);
    fn = elt(env, 1); // noncomp
    v0195 = (*qfn1(fn))(qenv(fn), v0195);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    env = stack[-11];
    stack[-10] = v0195;
    goto v0016;

v0016:
    v0195 = stack[-8];
    if (v0195 == nil) { LispObject res = stack[-4]; popv(12); return onevalue(res); }
    v0195 = stack[-8];
    v0195 = qcar(v0195);
    stack[-7] = v0195;
    v0195 = stack[-7];
    v0195 = qcar(v0195);
    stack[-6] = v0195;
    goto v0008;

v0008:
    v0195 = stack[-6];
    if (v0195 == nil) goto v0030;
    v0197 = stack[-9];
    v0195 = stack[-6];
    v0148 = qcar(v0195);
    v0195 = stack[-7];
    v0195 = qcdr(v0195);
    v0195 = qcar(v0195);
    v0196 = qcar(v0195);
    v0195 = stack[-7];
    v0195 = qcdr(v0195);
    v0195 = qcar(v0195);
    v0195 = qcdr(v0195);
    fn = elt(env, 2); // mtchp1
    v0195 = (*qfnn(fn))(qenv(fn), 4, v0197, v0148, v0196, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    env = stack[-11];
    stack[-5] = v0195;
    goto v0017;

v0017:
    v0195 = stack[-5];
    if (v0195 == nil) goto v0026;
    v0195 = stack[-5];
    stack[0] = qcar(v0195);
    v0195 = stack[-6];
    v0196 = qcar(v0195);
    v0195 = stack[-7];
    v0195 = qcar(v0195);
    v0195 = Ldelete(nil, v0196, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    env = stack[-11];
    stack[-2] = Lsubla(nil, stack[0], v0195);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    env = stack[-11];
    v0195 = stack[-5];
    v0196 = qcar(v0195);
    v0195 = stack[-7];
    v0195 = qcdr(v0195);
    v0195 = qcar(v0195);
    stack[-1] = Lsubla(nil, v0196, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    env = stack[-11];
    v0195 = stack[-5];
    v0196 = qcar(v0195);
    v0195 = stack[-7];
    v0195 = qcdr(v0195);
    v0195 = qcdr(v0195);
    v0195 = qcar(v0195);
    stack[0] = Lsubla(nil, v0196, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    env = stack[-11];
    v0195 = stack[-5];
    v0196 = qcar(v0195);
    v0195 = stack[-6];
    v0195 = qcar(v0195);
    v0196 = Lsubla(nil, v0196, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    env = stack[-11];
    v0195 = stack[-7];
    v0195 = qcdr(v0195);
    v0195 = qcdr(v0195);
    v0195 = qcdr(v0195);
    v0195 = qcar(v0195);
    v0195 = cons(v0196, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    env = stack[-11];
    v0195 = list2(stack[0], v0195);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    env = stack[-11];
    v0195 = list2star(stack[-2], stack[-1], v0195);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    env = stack[-11];
    stack[0] = v0195;
    v0195 = qcar(v0195);
    if (v0195 == nil) goto v0198;
    v0196 = stack[0];
    v0195 = stack[-4];
    v0195 = cons(v0196, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    env = stack[-11];
    stack[-4] = v0195;
    v0195 = stack[-3];
    if (!(v0195 == nil)) goto v0123;
    v0195 = stack[-4];
    stack[-3] = v0195;
    goto v0123;

v0123:
    v0195 = stack[-5];
    v0195 = qcdr(v0195);
    stack[-5] = v0195;
    goto v0017;

v0198:
    v0195 = stack[-5];
    v0196 = qcar(v0195);
    v0195 = stack[-7];
    v0195 = qcdr(v0195);
    v0195 = qcar(v0195);
    v0195 = qcdr(v0195);
    v0195 = Lsubla(nil, v0196, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    env = stack[-11];
    fn = elt(env, 3); // lispeval
    v0195 = (*qfn1(fn))(qenv(fn), v0195);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    env = stack[-11];
    if (v0195 == nil) goto v0123;
    v0195 = stack[0];
    popv(12);
    return ncons(v0195);

v0026:
    v0195 = stack[-10];
    if (v0195 == nil) goto v0159;
    v0195 = stack[-7];
    v0195 = qcdr(v0195);
    v0195 = qcdr(v0195);
    v0195 = qcdr(v0195);
    v0195 = qcar(v0195);
    if (v0195 == nil) goto v0030;
    v0195 = stack[-6];
    fn = elt(env, 4); // nocp
    v0195 = (*qfn1(fn))(qenv(fn), v0195);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    env = stack[-11];
    if (!(v0195 == nil)) goto v0078;

v0030:
    v0195 = stack[-4];
    if (v0195 == nil) goto v0199;
    stack[0] = stack[-3];
    v0195 = stack[-7];
    v0195 = ncons(v0195);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    env = stack[-11];
    v0195 = Lrplacd(nil, stack[0], v0195);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    env = stack[-11];
    v0195 = stack[-3];
    v0195 = qcdr(v0195);
    stack[-3] = v0195;
    goto v0078;

v0078:
    v0195 = stack[-8];
    v0195 = qcdr(v0195);
    stack[-8] = v0195;
    goto v0016;

v0199:
    v0195 = stack[-7];
    v0195 = ncons(v0195);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    env = stack[-11];
    stack[-3] = v0195;
    stack[-4] = v0195;
    goto v0078;

v0159:
    v0195 = stack[-6];
    v0195 = qcdr(v0195);
    stack[-6] = v0195;
    goto v0008;
// error exit handlers
v0153:
    popv(12);
    return nil;
}



// Code for sfp

static LispObject CC_sfp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0017, v0026;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sfp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0026 = v0000;
// end of prologue
    v0017 = v0026;
    if (!consp(v0017)) goto v0015;
    v0017 = v0026;
    v0017 = qcar(v0017);
    v0017 = (consp(v0017) ? nil : lisp_true);
    v0017 = (v0017 == nil ? lisp_true : nil);
    return onevalue(v0017);

v0015:
    v0017 = qvalue(elt(env, 1)); // nil
    return onevalue(v0017);
}



// Code for exptchksq

static LispObject CC_exptchksq(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0102;
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
    v0102 = qvalue(elt(env, 1)); // !*combineexpt
    if (v0102 == nil) { LispObject res = stack[0]; popv(3); return onevalue(res); }
    v0102 = stack[0];
    v0102 = qcar(v0102);
    fn = elt(env, 2); // exptchk
    stack[-1] = (*qfn1(fn))(qenv(fn), v0102);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-2];
    v0102 = stack[0];
    v0102 = qcdr(v0102);
    fn = elt(env, 2); // exptchk
    v0102 = (*qfn1(fn))(qenv(fn), v0102);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-2];
    fn = elt(env, 3); // invsq
    v0102 = (*qfn1(fn))(qenv(fn), v0102);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-2];
    {
        LispObject v0011 = stack[-1];
        popv(3);
        fn = elt(env, 4); // multsq
        return (*qfn2(fn))(qenv(fn), v0011, v0102);
    }
// error exit handlers
v0176:
    popv(3);
    return nil;
}



// Code for setcar

static LispObject CC_setcar(LispObject env,
                         LispObject v0000, LispObject v0029)
{
    LispObject nil = C_nil;
    LispObject v0016, v0008;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for setcar");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0029;
    v0016 = v0000;
// end of prologue
    v0008 = v0016;
    v0016 = stack[0];
    v0016 = Lrplaca(nil, v0008, v0016);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    { LispObject res = stack[0]; popv(1); return onevalue(res); }
// error exit handlers
v0026:
    popv(1);
    return nil;
}



// Code for aex_ctx

static LispObject CC_aex_ctx(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0014, v0015;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for aex_ctx");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0014 = v0000;
// end of prologue
    v0015 = v0014;
    v0014 = (LispObject)49; // 3
    {
        fn = elt(env, 1); // nth
        return (*qfn2(fn))(qenv(fn), v0015, v0014);
    }
}



// Code for attributes

static LispObject CC_attributes(LispObject env,
                         LispObject v0000, LispObject v0029)
{
    LispObject nil = C_nil;
    LispObject v0019, v0065;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for attributes");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0029;
    v0019 = v0000;
// end of prologue
    v0019 = Llength(nil, v0019);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    env = stack[-3];
    stack[-2] = v0019;
    v0019 = (LispObject)17; // 1
    stack[0] = v0019;
    goto v0036;

v0036:
    v0065 = stack[-2];
    v0019 = stack[0];
    v0019 = difference2(v0065, v0019);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    env = stack[-3];
    v0019 = Lminusp(nil, v0019);
    env = stack[-3];
    if (!(v0019 == nil)) goto v0003;
    v0019 = stack[-1];
    v0019 = qcdr(v0019);
    stack[-1] = v0019;
    v0019 = stack[0];
    v0019 = add1(v0019);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    env = stack[-3];
    stack[0] = v0019;
    goto v0036;

v0003:
    v0019 = stack[-1];
    v0065 = qcar(v0019);
    v0019 = elt(env, 2); // ! 
    if (v0065 == v0019) goto v0082;
    v0065 = stack[-1];
    v0019 = elt(env, 3); // (!$)
    if (equal(v0065, v0019)) goto v0178;
    v0019 = stack[-1];
    qvalue(elt(env, 4)) = v0019; // atts
    goto v0178;

v0178:
    v0019 = nil;
    { popv(4); return onevalue(v0019); }

v0082:
    v0019 = stack[-1];
    v0019 = qcdr(v0019);
    stack[-1] = v0019;
    goto v0003;
// error exit handlers
v0091:
    popv(4);
    return nil;
}



// Code for c!:ordexn

static LispObject CC_cTordexn(LispObject env,
                         LispObject v0000, LispObject v0029)
{
    LispObject nil = C_nil;
    LispObject v0052, v0054;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for c:ordexn");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0029;
    stack[-2] = v0000;
// end of prologue
    stack[0] = nil;
    stack[-3] = nil;
    goto v0012;

v0012:
    v0052 = stack[-1];
    if (v0052 == nil) goto v0080;
    v0054 = stack[-2];
    v0052 = stack[-1];
    v0052 = qcar(v0052);
    if (equal(v0054, v0052)) goto v0064;
    v0052 = stack[-2];
    v0052 = Lconsp(nil, v0052);
    env = stack[-4];
    if (v0052 == nil) goto v0093;
    v0052 = stack[-1];
    v0052 = qcar(v0052);
    v0052 = Lconsp(nil, v0052);
    env = stack[-4];
    goto v0098;

v0098:
    if (v0052 == nil) goto v0065;
    v0052 = qvalue(elt(env, 2)); // nil
    { popv(5); return onevalue(v0052); }

v0065:
    v0054 = stack[-2];
    v0052 = stack[-1];
    v0052 = qcar(v0052);
    fn = elt(env, 3); // c!:ordxp
    v0052 = (*qfn2(fn))(qenv(fn), v0054, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0191;
    env = stack[-4];
    if (v0052 == nil) goto v0201;
    v0054 = stack[-2];
    v0052 = stack[-3];
    v0052 = cons(v0054, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0191;
    env = stack[-4];
    v0054 = Lreverse(nil, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0191;
    env = stack[-4];
    v0052 = stack[-1];
    v0052 = Lappend(nil, v0054, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0191;
    {
        LispObject v0175 = stack[0];
        popv(5);
        return cons(v0175, v0052);
    }

v0201:
    v0052 = stack[-1];
    v0054 = qcar(v0052);
    v0052 = stack[-3];
    v0052 = cons(v0054, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0191;
    env = stack[-4];
    stack[-3] = v0052;
    v0052 = stack[-1];
    v0052 = qcdr(v0052);
    stack[-1] = v0052;
    v0052 = stack[0];
    v0052 = (v0052 == nil ? lisp_true : nil);
    stack[0] = v0052;
    goto v0012;

v0093:
    v0052 = qvalue(elt(env, 2)); // nil
    goto v0098;

v0064:
    v0052 = qvalue(elt(env, 1)); // t
    goto v0098;

v0080:
    v0054 = stack[-2];
    v0052 = stack[-3];
    v0052 = cons(v0054, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0191;
    env = stack[-4];
    v0052 = Lreverse(nil, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0191;
    {
        LispObject v0202 = stack[0];
        popv(5);
        return cons(v0202, v0052);
    }
// error exit handlers
v0191:
    popv(5);
    return nil;
}



// Code for constp

static LispObject CC_constp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0103, v0176;
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
    v0103 = v0000;
// end of prologue
    v0176 = v0103;
    v0176 = (is_number(v0176) ? lisp_true : nil);
    if (!(v0176 == nil)) { popv(1); return onevalue(v0176); }
    v0176 = v0103;
    v0176 = Lconsp(nil, v0176);
    env = stack[0];
    if (v0176 == nil) goto v0013;
    v0103 = qcar(v0103);
    v0176 = qvalue(elt(env, 2)); // domainlist!*
    v0103 = Lmemq(nil, v0103, v0176);
    { popv(1); return onevalue(v0103); }

v0013:
    v0103 = qvalue(elt(env, 1)); // nil
    { popv(1); return onevalue(v0103); }
}



// Code for bczero!?

static LispObject CC_bczeroW(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0035, v0079;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for bczero?");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0035 = v0000;
// end of prologue
    v0079 = qvalue(elt(env, 1)); // !*grmod!*
    if (v0079 == nil) goto v0026;
    v0079 = v0035;
    v0035 = (LispObject)1; // 0
        return Leqn(nil, v0079, v0035);

v0026:
    v0035 = qcar(v0035);
    v0035 = (v0035 == nil ? lisp_true : nil);
    return onevalue(v0035);
}



// Code for multpfsq

static LispObject CC_multpfsq(LispObject env,
                         LispObject v0000, LispObject v0029)
{
    LispObject nil = C_nil;
    LispObject v0178, v0009;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for multpfsq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0029;
    stack[-2] = v0000;
// end of prologue
    stack[-3] = nil;
    goto v0001;

v0001:
    v0178 = stack[-2];
    if (v0178 == nil) goto v0008;
    v0178 = stack[-1];
    v0178 = qcar(v0178);
    v0178 = (v0178 == nil ? lisp_true : nil);
    goto v0016;

v0016:
    if (v0178 == nil) goto v0011;
    v0178 = stack[-3];
    {
        popv(5);
        fn = elt(env, 2); // nreverse
        return (*qfn1(fn))(qenv(fn), v0178);
    }

v0011:
    v0178 = stack[-2];
    v0178 = qcar(v0178);
    stack[0] = qcar(v0178);
    v0178 = stack[-2];
    v0178 = qcar(v0178);
    v0009 = qcdr(v0178);
    v0178 = stack[-1];
    fn = elt(env, 3); // multsq
    v0009 = (*qfn2(fn))(qenv(fn), v0009, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0039;
    env = stack[-4];
    v0178 = stack[-3];
    v0178 = acons(stack[0], v0009, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0039;
    env = stack[-4];
    stack[-3] = v0178;
    v0178 = stack[-2];
    v0178 = qcdr(v0178);
    stack[-2] = v0178;
    goto v0001;

v0008:
    v0178 = qvalue(elt(env, 1)); // t
    goto v0016;
// error exit handlers
v0039:
    popv(5);
    return nil;
}



// Code for negnumberchk

static LispObject CC_negnumberchk(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0098, v0064, v0081;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for negnumberchk");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0081 = v0000;
// end of prologue
    v0064 = v0081;
    v0098 = elt(env, 1); // minus
    if (!consp(v0064)) goto v0080;
    v0064 = qcar(v0064);
    if (!(v0064 == v0098)) goto v0080;
    v0098 = v0081;
    v0098 = qcdr(v0098);
    v0098 = qcar(v0098);
    v0098 = (is_number(v0098) ? lisp_true : nil);
    goto v0012;

v0012:
    if (v0098 == nil) return onevalue(v0081);
    v0098 = v0081;
    v0098 = qcdr(v0098);
    v0098 = qcar(v0098);
    return negate(v0098);

v0080:
    v0098 = qvalue(elt(env, 2)); // nil
    goto v0012;
}



// Code for order!:

static LispObject CC_orderT(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0064, v0081;
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
    v0064 = stack[0];
    v0064 = qcdr(v0064);
    v0081 = qcar(v0064);
    v0064 = (LispObject)1; // 0
    if (v0081 == v0064) goto v0006;
    v0064 = stack[0];
    v0064 = qcdr(v0064);
    v0064 = qcar(v0064);
    v0064 = Labsval(nil, v0064);
    nil = C_nil;
    if (exception_pending()) goto v0002;
    env = stack[-2];
    fn = elt(env, 1); // msd
    stack[-1] = (*qfn1(fn))(qenv(fn), v0064);
    nil = C_nil;
    if (exception_pending()) goto v0002;
    env = stack[-2];
    v0064 = stack[0];
    v0064 = qcdr(v0064);
    v0064 = qcdr(v0064);
    v0064 = sub1(v0064);
    nil = C_nil;
    if (exception_pending()) goto v0002;
    {
        LispObject v0003 = stack[-1];
        popv(3);
        return plus2(v0003, v0064);
    }

v0006:
    v0064 = (LispObject)1; // 0
    { popv(3); return onevalue(v0064); }
// error exit handlers
v0002:
    popv(3);
    return nil;
}



// Code for sinitl

static LispObject CC_sinitl(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0016;
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
    v0016 = v0000;
// end of prologue
    stack[0] = v0016;
    if (!symbolp(v0016)) v0016 = nil;
    else { v0016 = qfastgets(v0016);
           if (v0016 != nil) { v0016 = elt(v0016, 47); // initl
#ifdef RECORD_GET
             if (v0016 != SPID_NOPROP)
                record_get(elt(fastget_names, 47), 1);
             else record_get(elt(fastget_names, 47), 0),
                v0016 = nil; }
           else record_get(elt(fastget_names, 47), 0); }
#else
             if (v0016 == SPID_NOPROP) v0016 = nil; }}
#endif
    fn = elt(env, 1); // eval
    v0016 = (*qfn1(fn))(qenv(fn), v0016);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    {
        LispObject v0026 = stack[0];
        popv(1);
        return Lset(nil, v0026, v0016);
    }
// error exit handlers
v0017:
    popv(1);
    return nil;
}



// Code for smemqlp

static LispObject CC_smemqlp(LispObject env,
                         LispObject v0000, LispObject v0029)
{
    LispObject nil = C_nil;
    LispObject v0084, v0024;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for smemqlp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0029;
    stack[-1] = v0000;
// end of prologue

v0096:
    v0084 = stack[0];
    if (v0084 == nil) goto v0013;
    v0084 = stack[0];
    v0084 = (is_number(v0084) ? lisp_true : nil);
    goto v0010;

v0010:
    if (v0084 == nil) goto v0001;
    v0084 = qvalue(elt(env, 2)); // nil
    { popv(3); return onevalue(v0084); }

v0001:
    v0084 = stack[0];
    if (!consp(v0084)) goto v0079;
    v0084 = stack[0];
    v0024 = qcar(v0084);
    v0084 = elt(env, 3); // quote
    if (v0024 == v0084) goto v0034;
    v0024 = stack[-1];
    v0084 = stack[0];
    v0084 = qcar(v0084);
    v0084 = CC_smemqlp(env, v0024, v0084);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-2];
    if (!(v0084 == nil)) { popv(3); return onevalue(v0084); }
    v0024 = stack[-1];
    v0084 = stack[0];
    v0084 = qcdr(v0084);
    stack[-1] = v0024;
    stack[0] = v0084;
    goto v0096;

v0034:
    v0084 = qvalue(elt(env, 2)); // nil
    { popv(3); return onevalue(v0084); }

v0079:
    v0024 = stack[0];
    v0084 = stack[-1];
    v0084 = Lmemq(nil, v0024, v0084);
    { popv(3); return onevalue(v0084); }

v0013:
    v0084 = qvalue(elt(env, 1)); // t
    goto v0010;
// error exit handlers
v0177:
    popv(3);
    return nil;
}



// Code for pappl0

static LispObject CC_pappl0(LispObject env,
                         LispObject v0000, LispObject v0029)
{
    LispObject nil = C_nil;
    LispObject v0008, v0017;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pappl0");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0008 = v0029;
    v0017 = v0000;
// end of prologue
    stack[0] = v0017;
    fn = elt(env, 1); // unpkp
    v0008 = (*qfn1(fn))(qenv(fn), v0008);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    env = stack[-1];
    fn = elt(env, 2); // pappl
    v0008 = (*qfn2(fn))(qenv(fn), stack[0], v0008);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 3); // pkp
        return (*qfn1(fn))(qenv(fn), v0008);
    }
// error exit handlers
v0030:
    popv(2);
    return nil;
}



// Code for remainder!-in!-vector

static LispObject CC_remainderKinKvector(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0213, v0155, v0156, v0214, v0041, v0042, v0061, v0062, v0215, v0173;
    LispObject fn;
    LispObject v0004, v0020, v0029, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "remainder-in-vector");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0029 = va_arg(aa, LispObject);
    v0020 = va_arg(aa, LispObject);
    v0004 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for remainder-in-vector");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0004,v0020,v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0029,v0020,v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0004;
    stack[-1] = v0020;
    stack[-2] = v0029;
    stack[-3] = v0000;
// end of prologue
    v0155 = stack[0];
    v0213 = (LispObject)1; // 0
    if (v0155 == v0213) goto v0008;
    v0155 = stack[0];
    v0213 = (LispObject)-15; // -1
    if (!(v0155 == v0213)) goto v0082;
    v0213 = elt(env, 1); // "Attempt to divide by zero"
    fn = elt(env, 3); // errorf
    v0213 = (*qfn1(fn))(qenv(fn), v0213);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-4];
    goto v0082;

v0082:
    v0155 = stack[-1];
    v0213 = stack[0];
    v0213 = *(LispObject *)((char *)v0155 + (CELL-TAG_VECTOR) + ((int32_t)v0213/(16/CELL)));
    v0213 = Lmodular_reciprocal(nil, v0213);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-4];
    {   int32_t w = int_of_fixnum(v0213);
        if (w != 0) w = current_modulus - w;
        v0213 = fixnum_of_int(w);
    }
    v0062 = v0213;
    v0213 = stack[0];
    v0213 = (LispObject)((int32_t)(v0213) - 0x10);
    v0215 = v0213;
    goto v0123;

v0123:
    v0155 = stack[-2];
    v0213 = stack[0];
    v0155 = (LispObject)(int32_t)((int32_t)v0155 - (int32_t)v0213 + TAG_FIXNUM);
    v0173 = v0155;
    v0213 = (LispObject)1; // 0
    if (((int32_t)(v0155)) < ((int32_t)(v0213))) { LispObject res = stack[-2]; popv(5); return onevalue(res); }
    v0156 = v0062;
    v0155 = stack[-3];
    v0213 = stack[-2];
    v0213 = *(LispObject *)((char *)v0155 + (CELL-TAG_VECTOR) + ((int32_t)v0213/(16/CELL)));
    v0213 = Lmodular_times(nil, v0156, v0213);
    env = stack[-4];
    v0061 = v0213;
    v0213 = (LispObject)1; // 0
    v0042 = v0213;
    goto v0164;

v0164:
    v0155 = v0215;
    v0213 = v0042;
    v0213 = (LispObject)(int32_t)((int32_t)v0155 - (int32_t)v0213 + TAG_FIXNUM);
    v0213 = ((intptr_t)(v0213) < 0 ? lisp_true : nil);
    if (v0213 == nil) goto v0110;
    v0213 = stack[-2];
    v0213 = (LispObject)((int32_t)(v0213) - 0x10);
    stack[-2] = v0213;
    goto v0117;

v0117:
    v0155 = stack[-2];
    v0213 = (LispObject)1; // 0
    if (((int32_t)(v0155)) < ((int32_t)(v0213))) goto v0217;
    v0155 = stack[-3];
    v0213 = stack[-2];
    v0155 = *(LispObject *)((char *)v0155 + (CELL-TAG_VECTOR) + ((int32_t)v0213/(16/CELL)));
    v0213 = (LispObject)1; // 0
    v0213 = (v0155 == v0213 ? lisp_true : nil);
    goto v0218;

v0218:
    if (v0213 == nil) goto v0123;
    v0213 = stack[-2];
    v0213 = (LispObject)((int32_t)(v0213) - 0x10);
    stack[-2] = v0213;
    goto v0117;

v0217:
    v0213 = qvalue(elt(env, 2)); // nil
    goto v0218;

v0110:
    v0041 = stack[-3];
    v0155 = v0042;
    v0213 = v0173;
    v0214 = (LispObject)(int32_t)((int32_t)v0155 + (int32_t)v0213 - TAG_FIXNUM);
    v0156 = stack[-3];
    v0155 = v0042;
    v0213 = v0173;
    v0213 = (LispObject)(int32_t)((int32_t)v0155 + (int32_t)v0213 - TAG_FIXNUM);
    v0156 = *(LispObject *)((char *)v0156 + (CELL-TAG_VECTOR) + ((int32_t)v0213/(16/CELL)));
    v0155 = stack[-1];
    v0213 = v0042;
    v0155 = *(LispObject *)((char *)v0155 + (CELL-TAG_VECTOR) + ((int32_t)v0213/(16/CELL)));
    v0213 = v0061;
    v0213 = Lmodular_times(nil, v0155, v0213);
    env = stack[-4];
    {   int32_t w = int_of_fixnum(v0156) + int_of_fixnum(v0213);
        if (w >= current_modulus) w -= current_modulus;
        v0213 = fixnum_of_int(w);
    }
    *(LispObject *)((char *)v0041 + (CELL-TAG_VECTOR) + ((int32_t)v0214/(16/CELL))) = v0213;
    v0213 = v0042;
    v0213 = (LispObject)((int32_t)(v0213) + 0x10);
    v0042 = v0213;
    goto v0164;

v0008:
    v0213 = (LispObject)-15; // -1
    { popv(5); return onevalue(v0213); }
// error exit handlers
v0216:
    popv(5);
    return nil;
}



// Code for cl_atmlc

static LispObject CC_cl_atmlc(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0015, v0016;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cl_atmlc");
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
    v0015 = v0000;
// end of prologue
    v0016 = v0015;
    v0015 = (LispObject)17; // 1
    v0015 = cons(v0016, v0015);
    errexit();
    return ncons(v0015);
}



// Code for setcdr

static LispObject CC_setcdr(LispObject env,
                         LispObject v0000, LispObject v0029)
{
    LispObject nil = C_nil;
    LispObject v0016, v0008;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for setcdr");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0029;
    v0016 = v0000;
// end of prologue
    v0008 = v0016;
    v0016 = stack[0];
    v0016 = Lrplacd(nil, v0008, v0016);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    { LispObject res = stack[0]; popv(1); return onevalue(res); }
// error exit handlers
v0026:
    popv(1);
    return nil;
}



// Code for remove!-free!-vars!-l

static LispObject CC_removeKfreeKvarsKl(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0056, v0186;
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
    goto v0012;

v0012:
    v0056 = stack[-2];
    if (!consp(v0056)) goto v0026;
    v0056 = stack[-2];
    v0186 = qcar(v0056);
    v0056 = elt(env, 3); // !*sq
    if (v0186 == v0056) goto v0085;
    v0186 = stack[-2];
    v0056 = stack[-1];
    v0056 = cons(v0186, v0056);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-4];
    stack[-1] = v0056;
    v0056 = stack[-2];
    v0056 = qcar(v0056);
    fn = elt(env, 4); // remove!-free!-vars
    v0186 = (*qfn1(fn))(qenv(fn), v0056);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-4];
    v0056 = stack[-3];
    v0056 = cons(v0186, v0056);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-4];
    stack[-3] = v0056;
    v0056 = stack[-2];
    v0056 = qcdr(v0056);
    stack[-2] = v0056;
    goto v0012;

v0085:
    v0056 = stack[-2];
    v0056 = qcdr(v0056);
    v0056 = qcar(v0056);
    fn = elt(env, 5); // prepsq!*
    v0056 = (*qfn1(fn))(qenv(fn), v0056);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-4];
    stack[-2] = v0056;
    v0056 = qvalue(elt(env, 2)); // t
    stack[0] = v0056;
    goto v0012;

v0026:
    v0056 = stack[-3];
    if (v0056 == nil) { LispObject res = stack[-2]; popv(5); return onevalue(res); }
    v0056 = stack[0];
    if (v0056 == nil) goto v0027;
    v0056 = stack[-3];
    v0186 = qcar(v0056);
    v0056 = stack[-2];
    v0056 = cons(v0186, v0056);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-4];
    stack[-2] = v0056;
    goto v0102;

v0102:
    v0056 = stack[-1];
    v0056 = qcdr(v0056);
    stack[-1] = v0056;
    v0056 = stack[-3];
    v0056 = qcdr(v0056);
    stack[-3] = v0056;
    goto v0026;

v0027:
    v0056 = stack[-1];
    v0056 = qcar(v0056);
    v0186 = qcar(v0056);
    v0056 = stack[-3];
    v0056 = qcar(v0056);
    if (equal(v0186, v0056)) goto v0034;
    v0056 = stack[-3];
    v0186 = qcar(v0056);
    v0056 = stack[-2];
    v0056 = cons(v0186, v0056);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-4];
    stack[-2] = v0056;
    v0056 = qvalue(elt(env, 2)); // t
    stack[0] = v0056;
    goto v0102;

v0034:
    v0056 = stack[-1];
    v0056 = qcar(v0056);
    stack[-2] = v0056;
    goto v0102;
// error exit handlers
v0073:
    popv(5);
    return nil;
}



// Code for get!+vec!+dim

static LispObject CC_getLvecLdim(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0001;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for get+vec+dim");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0001 = v0000;
// end of prologue
        return Llength(nil, v0001);
}



// Code for qqe_qopaddp

static LispObject CC_qqe_qopaddp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0026, v0030;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qqe_qopaddp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0026 = v0000;
// end of prologue
    v0030 = v0026;
    v0026 = elt(env, 1); // (ladd radd)
    v0026 = Lmemq(nil, v0030, v0026);
    if (v0026 == nil) goto v0005;
    v0026 = qvalue(elt(env, 2)); // t
    return onevalue(v0026);

v0005:
    v0026 = nil;
    return onevalue(v0026);
}



// Code for delq

static LispObject CC_delq(LispObject env,
                         LispObject v0000, LispObject v0029)
{
    LispObject nil = C_nil;
    LispObject v0178, v0009, v0031;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for delq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0029;
    stack[-1] = v0000;
// end of prologue
    v0031 = nil;
    goto v0001;

v0001:
    v0178 = stack[0];
    if (v0178 == nil) goto v0007;
    v0178 = stack[0];
    v0009 = qcar(v0178);
    v0178 = stack[-1];
    if (v0009 == v0178) goto v0103;
    v0178 = stack[0];
    v0178 = qcar(v0178);
    v0009 = v0031;
    v0178 = cons(v0178, v0009);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[-2];
    v0031 = v0178;
    v0178 = stack[0];
    v0178 = qcdr(v0178);
    stack[0] = v0178;
    goto v0001;

v0103:
    v0009 = v0031;
    v0178 = stack[0];
    v0178 = qcdr(v0178);
    {
        popv(3);
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(qenv(fn), v0009, v0178);
    }

v0007:
    v0178 = v0031;
    {
        popv(3);
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(qenv(fn), v0178);
    }
// error exit handlers
v0057:
    popv(3);
    return nil;
}



// Code for notstring

static LispObject CC_notstring(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0007, v0092, v0093;
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
    v0007 = v0000;
// end of prologue
    v0092 = elt(env, 1); // ! 
    fn = elt(env, 5); // delall
    v0007 = (*qfn2(fn))(qenv(fn), v0092, v0007);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[0];
    v0093 = v0007;
    v0007 = v0093;
    v0092 = qcar(v0007);
    v0007 = elt(env, 2); // !"
    if (v0092 == v0007) goto v0023;
    v0007 = v0093;
    v0007 = Lreverse(nil, v0007);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[0];
    v0092 = qcar(v0007);
    v0007 = elt(env, 2); // !"
    v0007 = Lneq(nil, v0092, v0007);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[0];
    goto v0129;

v0129:
    if (v0007 == nil) goto v0022;
    v0007 = qvalue(elt(env, 4)); // t
    { popv(1); return onevalue(v0007); }

v0022:
    v0007 = qvalue(elt(env, 3)); // nil
    { popv(1); return onevalue(v0007); }

v0023:
    v0007 = qvalue(elt(env, 3)); // nil
    goto v0129;
// error exit handlers
v0097:
    popv(1);
    return nil;
}



// Code for bcprod

static LispObject CC_bcprod(LispObject env,
                         LispObject v0000, LispObject v0029)
{
    LispObject nil = C_nil;
    LispObject v0032, v0022, v0060;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for bcprod");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0029;
    stack[-1] = v0000;
// end of prologue
    v0032 = qvalue(elt(env, 1)); // !*grmod!*
    if (v0032 == nil) goto v0102;
    v0022 = stack[-1];
    v0032 = stack[0];
    v0032 = times2(v0022, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 3); // bcfi
        return (*qfn1(fn))(qenv(fn), v0032);
    }

v0102:
    v0060 = stack[-1];
    v0022 = stack[0];
    v0032 = elt(env, 2); // times
    fn = elt(env, 4); // bcint2op
    v0032 = (*qfnn(fn))(qenv(fn), 3, v0060, v0022, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-2];
    if (!(v0032 == nil)) { popv(3); return onevalue(v0032); }
    v0022 = stack[-1];
    v0032 = stack[0];
    fn = elt(env, 5); // multsq
    v0032 = (*qfn2(fn))(qenv(fn), v0022, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 6); // bccheckz
        return (*qfn1(fn))(qenv(fn), v0032);
    }
// error exit handlers
v0092:
    popv(3);
    return nil;
}



// Code for fast!-row!-dim

static LispObject CC_fastKrowKdim(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0005;
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
    v0005 = v0000;
// end of prologue
    v0005 = Lupbv(nil, v0005);
    errexit();
    return add1(v0005);
}



// Code for evmatrixcomp1

static LispObject CC_evmatrixcomp1(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0090, v0067, v0099;
    LispObject fn;
    LispObject v0020, v0029, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "evmatrixcomp1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0029 = va_arg(aa, LispObject);
    v0020 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evmatrixcomp1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0020,v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0029,v0020);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0020;
    stack[-2] = v0029;
    stack[-3] = v0000;
// end of prologue

v0096:
    v0090 = stack[-1];
    if (v0090 == nil) goto v0001;
    v0099 = stack[-3];
    v0090 = stack[-1];
    v0067 = qcar(v0090);
    v0090 = (LispObject)1; // 0
    fn = elt(env, 1); // evmatrixcomp2
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v0099, v0067, v0090);
    nil = C_nil;
    if (exception_pending()) goto v0101;
    env = stack[-5];
    v0099 = stack[-2];
    v0090 = stack[-1];
    v0067 = qcar(v0090);
    v0090 = (LispObject)1; // 0
    fn = elt(env, 1); // evmatrixcomp2
    v0090 = (*qfnn(fn))(qenv(fn), 3, v0099, v0067, v0090);
    nil = C_nil;
    if (exception_pending()) goto v0101;
    env = stack[-5];
    stack[-4] = stack[0];
    stack[0] = v0090;
    v0067 = stack[-4];
    v0090 = stack[0];
    fn = elt(env, 2); // iequal
    v0090 = (*qfn2(fn))(qenv(fn), v0067, v0090);
    nil = C_nil;
    if (exception_pending()) goto v0101;
    env = stack[-5];
    if (v0090 == nil) goto v0024;
    v0099 = stack[-3];
    v0067 = stack[-2];
    v0090 = stack[-1];
    v0090 = qcdr(v0090);
    stack[-3] = v0099;
    stack[-2] = v0067;
    stack[-1] = v0090;
    goto v0096;

v0024:
    v0067 = stack[-4];
    v0090 = stack[0];
    if (((int32_t)(v0067)) > ((int32_t)(v0090))) goto v0065;
    v0090 = (LispObject)-15; // -1
    { popv(6); return onevalue(v0090); }

v0065:
    v0090 = (LispObject)17; // 1
    { popv(6); return onevalue(v0090); }

v0001:
    v0090 = (LispObject)1; // 0
    { popv(6); return onevalue(v0090); }
// error exit handlers
v0101:
    popv(6);
    return nil;
}



// Code for monordp

static LispObject CC_monordp(LispObject env,
                         LispObject v0000, LispObject v0029)
{
    LispObject nil = C_nil;
    LispObject v0079, v0080, v0102, v0040;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for monordp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
// copy arguments values to proper place
    v0102 = v0029;
    v0040 = v0000;
// end of prologue
    v0080 = elt(env, 1); // wedge
    v0079 = elt(env, 2); // xorder
    v0079 = get(v0080, v0079);
    v0080 = v0040;
        return Lapply2(nil, 3, v0079, v0080, v0102);
}



// Code for getphystype!*sq

static LispObject CC_getphystypeHsq(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0001;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for getphystype*sq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0001 = v0000;
// end of prologue
    v0001 = qcar(v0001);
    v0001 = qcar(v0001);
    {
        fn = elt(env, 1); // getphystypesf
        return (*qfn1(fn))(qenv(fn), v0001);
    }
}



// Code for mo!=modiv1

static LispObject CC_moMmodiv1(LispObject env,
                         LispObject v0000, LispObject v0029)
{
    LispObject nil = C_nil;
    LispObject v0023, v0122;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mo=modiv1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0029;
    stack[-1] = v0000;
// end of prologue

v0005:
    v0023 = stack[-1];
    if (v0023 == nil) goto v0010;
    v0023 = stack[0];
    if (v0023 == nil) goto v0016;
    v0023 = stack[-1];
    v0122 = qcar(v0023);
    v0023 = stack[0];
    v0023 = qcar(v0023);
    v0023 = (LispObject)lesseq2(v0122, v0023);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    v0023 = v0023 ? lisp_true : nil;
    env = stack[-2];
    if (v0023 == nil) goto v0083;
    v0023 = stack[-1];
    v0023 = qcdr(v0023);
    stack[-1] = v0023;
    v0023 = stack[0];
    v0023 = qcdr(v0023);
    stack[0] = v0023;
    goto v0005;

v0083:
    v0023 = qvalue(elt(env, 2)); // nil
    { popv(3); return onevalue(v0023); }

v0016:
    v0023 = qvalue(elt(env, 2)); // nil
    { popv(3); return onevalue(v0023); }

v0010:
    v0023 = qvalue(elt(env, 1)); // t
    { popv(3); return onevalue(v0023); }
// error exit handlers
v0022:
    popv(3);
    return nil;
}



// Code for unpkp

static LispObject CC_unpkp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0219, v0187, v0220;
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
    v0219 = stack[-1];
    if (!(!consp(v0219))) { LispObject res = stack[-1]; popv(4); return onevalue(res); }
    v0219 = stack[-1];
    v0219 = Lexplode(nil, v0219);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-3];
    stack[-1] = v0219;
    v0219 = stack[-1];
    v0187 = Llength(nil, v0219);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-3];
    v0219 = (LispObject)161; // 10
    v0219 = (LispObject)geq2(v0187, v0219);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    v0219 = v0219 ? lisp_true : nil;
    env = stack[-3];
    stack[0] = v0219;
    v0219 = stack[0];
    if (v0219 == nil) goto v0060;
    v0219 = stack[-1];
    v0219 = Llength(nil, v0219);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-3];
    v0219 = Levenp(nil, v0219);
    env = stack[-3];
    if (!(v0219 == nil)) goto v0060;
    v0187 = elt(env, 1); // !0
    v0219 = stack[-1];
    v0219 = cons(v0187, v0219);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-3];
    stack[-1] = v0219;
    goto v0060;

v0060:
    v0219 = stack[-1];
    if (v0219 == nil) goto v0022;
    v0219 = stack[0];
    if (v0219 == nil) goto v0052;
    v0219 = stack[-1];
    v0187 = qcar(v0219);
    v0219 = qvalue(elt(env, 3)); // diglist!*
    v0219 = Lassoc(nil, v0187, v0219);
    v0219 = qcdr(v0219);
    v0187 = v0219;
    v0219 = stack[-1];
    v0219 = qcdr(v0219);
    stack[-1] = v0219;
    v0219 = (LispObject)161; // 10
    v0220 = times2(v0187, v0219);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-3];
    v0219 = stack[-1];
    v0187 = qcar(v0219);
    v0219 = qvalue(elt(env, 3)); // diglist!*
    v0219 = Lassoc(nil, v0187, v0219);
    v0219 = qcdr(v0219);
    v0187 = plus2(v0220, v0219);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-3];
    v0219 = stack[-2];
    v0219 = cons(v0187, v0219);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-3];
    stack[-2] = v0219;
    goto v0031;

v0031:
    v0219 = stack[-1];
    v0219 = qcdr(v0219);
    stack[-1] = v0219;
    goto v0060;

v0052:
    v0219 = stack[-1];
    v0187 = qcar(v0219);
    v0219 = qvalue(elt(env, 3)); // diglist!*
    v0219 = Lassoc(nil, v0187, v0219);
    v0187 = qcdr(v0219);
    v0219 = stack[-2];
    v0219 = cons(v0187, v0219);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-3];
    stack[-2] = v0219;
    goto v0031;

v0022:
    v0219 = stack[-2];
        popv(4);
        return Lnreverse(nil, v0219);
// error exit handlers
v0107:
    popv(4);
    return nil;
}



// Code for modtimes!:

static LispObject CC_modtimesT(LispObject env,
                         LispObject v0000, LispObject v0029)
{
    LispObject nil = C_nil;
    LispObject v0017, v0026;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for modtimes:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// copy arguments values to proper place
    v0017 = v0029;
    v0026 = v0000;
// end of prologue
    v0026 = qcdr(v0026);
    v0017 = qcdr(v0017);
    fn = elt(env, 1); // general!-modular!-times
    v0017 = (*qfn2(fn))(qenv(fn), v0026, v0017);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); // !*modular2f
        return (*qfn1(fn))(qenv(fn), v0017);
    }
// error exit handlers
v0030:
    popv(1);
    return nil;
}



// Code for lesspcar

static LispObject CC_lesspcar(LispObject env,
                         LispObject v0000, LispObject v0029)
{
    LispObject nil = C_nil;
    LispObject v0008, v0017;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lesspcar");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0008 = v0029;
    v0017 = v0000;
// end of prologue
    v0017 = qcar(v0017);
    v0008 = qcar(v0008);
        return Llessp(nil, v0017, v0008);
}



// Code for monomisdivisibleby

static LispObject CC_monomisdivisibleby(LispObject env,
                         LispObject v0000, LispObject v0029)
{
    LispObject nil = C_nil;
    LispObject v0192, v0193, v0212;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for monomisdivisibleby");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    v0212 = v0029;
    v0192 = v0000;
// end of prologue
    v0193 = v0192;
    v0192 = (LispObject)17; // 1
    v0192 = *(LispObject *)((char *)v0193 + (CELL-TAG_VECTOR) + ((int32_t)v0192/(16/CELL)));
    stack[-1] = v0192;
    v0193 = v0212;
    v0192 = (LispObject)17; // 1
    v0192 = *(LispObject *)((char *)v0193 + (CELL-TAG_VECTOR) + ((int32_t)v0192/(16/CELL)));
    stack[0] = v0192;
    goto v0103;

v0103:
    v0192 = stack[-1];
    v0192 = qcar(v0192);
    if (v0192 == nil) goto v0040;
    v0192 = stack[0];
    v0192 = qcar(v0192);
    if (v0192 == nil) goto v0040;
    v0192 = stack[-1];
    v0193 = qcar(v0192);
    v0192 = stack[0];
    v0192 = qcar(v0192);
    if (equal(v0193, v0192)) goto v0023;
    v0192 = stack[-1];
    v0193 = qcar(v0192);
    v0192 = stack[0];
    v0192 = qcar(v0192);
    v0192 = (LispObject)greaterp2(v0193, v0192);
    nil = C_nil;
    if (exception_pending()) goto v0180;
    v0192 = v0192 ? lisp_true : nil;
    env = stack[-2];
    if (v0192 == nil) goto v0115;
    v0192 = stack[-1];
    v0192 = qcdr(v0192);
    stack[-1] = v0192;
    goto v0103;

v0115:
    v0192 = qvalue(elt(env, 1)); // nil
    v0192 = ncons(v0192);
    nil = C_nil;
    if (exception_pending()) goto v0180;
    env = stack[-2];
    stack[-1] = v0192;
    goto v0103;

v0023:
    v0192 = stack[-1];
    v0192 = qcdr(v0192);
    stack[-1] = v0192;
    v0192 = stack[0];
    v0192 = qcdr(v0192);
    stack[0] = v0192;
    goto v0103;

v0040:
    v0192 = stack[0];
    v0192 = qcar(v0192);
    v0192 = (v0192 == nil ? lisp_true : nil);
    { popv(3); return onevalue(v0192); }
// error exit handlers
v0180:
    popv(3);
    return nil;
}



// Code for powers0

static LispObject CC_powers0(LispObject env,
                         LispObject v0000, LispObject v0029)
{
    LispObject nil = C_nil;
    LispObject v0205, v0108, v0070;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for powers0");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0029;
    stack[-1] = v0000;
// end of prologue

v0096:
    v0205 = stack[-1];
    if (v0205 == nil) goto v0013;
    v0205 = stack[-1];
    if (!consp(v0205)) goto v0078;
    v0205 = stack[-1];
    v0205 = qcar(v0205);
    v0205 = (consp(v0205) ? nil : lisp_true);
    goto v0010;

v0010:
    if (!(v0205 == nil)) { LispObject res = stack[0]; popv(4); return onevalue(res); }
    v0205 = stack[-1];
    v0205 = qcar(v0205);
    v0205 = qcar(v0205);
    v0108 = qcar(v0205);
    v0205 = stack[0];
    v0108 = Latsoc(nil, v0108, v0205);
    v0205 = v0108;
    if (v0108 == nil) goto v0101;
    v0108 = stack[-1];
    v0108 = qcar(v0108);
    v0108 = qcar(v0108);
    v0108 = qcdr(v0108);
    v0205 = qcdr(v0205);
    v0205 = (LispObject)greaterp2(v0108, v0205);
    nil = C_nil;
    if (exception_pending()) goto v0221;
    v0205 = v0205 ? lisp_true : nil;
    env = stack[-3];
    if (v0205 == nil) goto v0068;
    v0205 = stack[-1];
    v0205 = qcar(v0205);
    v0205 = qcar(v0205);
    v0070 = qcar(v0205);
    v0205 = stack[-1];
    v0205 = qcar(v0205);
    v0205 = qcar(v0205);
    v0108 = qcdr(v0205);
    v0205 = stack[0];
    fn = elt(env, 2); // repasc
    v0205 = (*qfnn(fn))(qenv(fn), 3, v0070, v0108, v0205);
    nil = C_nil;
    if (exception_pending()) goto v0221;
    env = stack[-3];
    stack[0] = v0205;
    goto v0068;

v0068:
    v0205 = stack[-1];
    stack[-2] = qcdr(v0205);
    v0205 = stack[-1];
    v0205 = qcar(v0205);
    v0108 = qcdr(v0205);
    v0205 = stack[0];
    v0205 = CC_powers0(env, v0108, v0205);
    nil = C_nil;
    if (exception_pending()) goto v0221;
    env = stack[-3];
    stack[-1] = stack[-2];
    stack[0] = v0205;
    goto v0096;

v0101:
    v0205 = stack[-1];
    v0205 = qcar(v0205);
    v0205 = qcar(v0205);
    v0070 = qcar(v0205);
    v0205 = stack[-1];
    v0205 = qcar(v0205);
    v0205 = qcar(v0205);
    v0108 = qcdr(v0205);
    v0205 = stack[0];
    v0205 = acons(v0070, v0108, v0205);
    nil = C_nil;
    if (exception_pending()) goto v0221;
    env = stack[-3];
    stack[0] = v0205;
    goto v0068;

v0078:
    v0205 = qvalue(elt(env, 1)); // t
    goto v0010;

v0013:
    v0205 = qvalue(elt(env, 1)); // t
    goto v0010;
// error exit handlers
v0221:
    popv(4);
    return nil;
}



// Code for rank

static LispObject CC_rank(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0056, v0186;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rank");
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
    v0056 = qvalue(elt(env, 1)); // !*mcd
    if (v0056 == nil) goto v0015;
    v0056 = stack[-2];
    v0056 = qcar(v0056);
    v0056 = qcar(v0056);
    v0056 = qcdr(v0056);
    { popv(5); return onevalue(v0056); }

v0015:
    v0056 = stack[-2];
    v0056 = qcar(v0056);
    v0056 = qcar(v0056);
    v0056 = qcdr(v0056);
    stack[-1] = v0056;
    v0056 = stack[-2];
    v0056 = qcar(v0056);
    v0056 = qcar(v0056);
    v0056 = qcar(v0056);
    stack[0] = v0056;
    goto v0129;

v0129:
    v0056 = stack[-2];
    v0056 = qcar(v0056);
    v0056 = qcar(v0056);
    v0056 = qcdr(v0056);
    stack[-3] = v0056;
    v0056 = stack[-2];
    v0056 = qcdr(v0056);
    if (v0056 == nil) goto v0122;
    v0056 = stack[-2];
    v0056 = qcdr(v0056);
    stack[-2] = v0056;
    v0186 = stack[-2];
    v0056 = stack[0];
    fn = elt(env, 2); // degr
    v0186 = (*qfn2(fn))(qenv(fn), v0186, v0056);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-4];
    v0056 = (LispObject)1; // 0
    if (!(v0186 == v0056)) goto v0129;
    v0186 = stack[-3];
    v0056 = (LispObject)1; // 0
    v0056 = (LispObject)lessp2(v0186, v0056);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    v0056 = v0056 ? lisp_true : nil;
    env = stack[-4];
    if (v0056 == nil) { LispObject res = stack[-1]; popv(5); return onevalue(res); }
    v0186 = stack[-1];
    v0056 = (LispObject)1; // 0
    v0056 = (LispObject)lessp2(v0186, v0056);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    v0056 = v0056 ? lisp_true : nil;
    if (v0056 == nil) goto v0201;
    v0056 = stack[-3];
    popv(5);
    return negate(v0056);

v0201:
    v0186 = stack[-1];
    v0056 = stack[-3];
    popv(5);
    return difference2(v0186, v0056);

v0122:
    v0186 = stack[-1];
    v0056 = stack[-3];
    popv(5);
    return difference2(v0186, v0056);
// error exit handlers
v0073:
    popv(5);
    return nil;
}



// Code for sizchk

static LispObject CC_sizchk(LispObject env,
                         LispObject v0000, LispObject v0029)
{
    LispObject nil = C_nil;
    LispObject v0032, v0022;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sizchk");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0029;
    stack[-1] = v0000;
// end of prologue
    stack[-2] = nil;
    goto v0001;

v0001:
    v0032 = stack[-1];
    if (v0032 == nil) goto v0013;
    v0032 = stack[-1];
    v0032 = qcar(v0032);
    v0032 = qcar(v0032);
    v0022 = Llength(nil, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-3];
    v0032 = stack[0];
    v0032 = (LispObject)greaterp2(v0022, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    v0032 = v0032 ? lisp_true : nil;
    env = stack[-3];
    if (v0032 == nil) goto v0098;
    v0032 = stack[-1];
    v0032 = qcdr(v0032);
    stack[-1] = v0032;
    goto v0001;

v0098:
    v0032 = stack[-1];
    v0022 = qcar(v0032);
    v0032 = stack[-2];
    v0032 = cons(v0022, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-3];
    stack[-2] = v0032;
    v0032 = stack[-1];
    v0032 = qcdr(v0032);
    stack[-1] = v0032;
    goto v0001;

v0013:
    v0032 = stack[-2];
    {
        popv(4);
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(qenv(fn), v0032);
    }
// error exit handlers
v0092:
    popv(4);
    return nil;
}



// Code for qqe_qopheadp

static LispObject CC_qqe_qopheadp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0014, v0015;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qqe_qopheadp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0014 = v0000;
// end of prologue
    v0015 = elt(env, 1); // (lhead rhead)
    v0014 = Lmemq(nil, v0014, v0015);
    return onevalue(v0014);
}



// Code for pasf_susitf

static LispObject CC_pasf_susitf(LispObject env,
                         LispObject v0000, LispObject v0029)
{
    LispObject v0006, v0005;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pasf_susitf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0006 = v0029;
    v0005 = v0000;
// end of prologue
    return onevalue(v0005);
}



// Code for get_content

static LispObject CC_get_content(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0114, v0058;
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
    v0114 = qvalue(elt(env, 1)); // nil
    stack[0] = v0114;
    goto v0030;

v0030:
    v0058 = Lreadch(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0181;
    env = stack[-1];
    qvalue(elt(env, 2)) = v0058; // ch
    v0114 = elt(env, 3); // !<
    if (v0058 == v0114) goto v0027;
    v0058 = qvalue(elt(env, 2)); // ch
    v0114 = qvalue(elt(env, 4)); // !$eof!$
    v0114 = Lneq(nil, v0058, v0114);
    nil = C_nil;
    if (exception_pending()) goto v0181;
    env = stack[-1];
    goto v0008;

v0008:
    if (v0114 == nil) goto v0001;
    v0058 = qvalue(elt(env, 2)); // ch
    v0114 = qvalue(elt(env, 5)); // space
    if (equal(v0058, v0114)) goto v0018;
    v0114 = qvalue(elt(env, 2)); // ch
    fn = elt(env, 7); // string2list
    v0114 = (*qfn1(fn))(qenv(fn), v0114);
    nil = C_nil;
    if (exception_pending()) goto v0181;
    env = stack[-1];
    v0058 = qcar(v0114);
    v0114 = (LispObject)161; // 10
    v0114 = (LispObject)greaterp2(v0058, v0114);
    nil = C_nil;
    if (exception_pending()) goto v0181;
    v0114 = v0114 ? lisp_true : nil;
    env = stack[-1];
    goto v0122;

v0122:
    if (v0114 == nil) goto v0030;
    v0058 = qvalue(elt(env, 2)); // ch
    v0114 = stack[0];
    v0114 = cons(v0058, v0114);
    nil = C_nil;
    if (exception_pending()) goto v0181;
    env = stack[-1];
    stack[0] = v0114;
    goto v0030;

v0018:
    v0114 = qvalue(elt(env, 1)); // nil
    goto v0122;

v0001:
    v0114 = stack[0];
    if (v0114 == nil) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    v0058 = elt(env, 6); // !$
    v0114 = stack[0];
    v0114 = cons(v0058, v0114);
    nil = C_nil;
    if (exception_pending()) goto v0181;
    stack[0] = v0114;
    { LispObject res = stack[0]; popv(2); return onevalue(res); }

v0027:
    v0114 = qvalue(elt(env, 1)); // nil
    goto v0008;
// error exit handlers
v0181:
    popv(2);
    return nil;
}



setup_type const u02_setup[] =
{
    {"lalr_core",               CC_lalr_core,   too_many_1,    wrong_no_1},
    {"prin2x",                  CC_prin2x,      too_many_1,    wrong_no_1},
    {"rl_varlat",               CC_rl_varlat,   too_many_1,    wrong_no_1},
    {"reorder",                 CC_reorder,     too_many_1,    wrong_no_1},
    {"aconc*",                  too_few_2,      CC_aconcH,     wrong_no_2},
    {"*d2q",                    CC_Hd2q,        too_many_1,    wrong_no_1},
    {"ibalp_cequal",            too_few_2,      CC_ibalp_cequal,wrong_no_2},
    {"*q2a",                    CC_Hq2a,        too_many_1,    wrong_no_1},
    {":onep",                   CC_Tonep,       too_many_1,    wrong_no_1},
    {"buchvevdivides?",         too_few_2,      CC_buchvevdividesW,wrong_no_2},
    {"vevmtest?",               too_few_2,      CC_vevmtestW,  wrong_no_2},
    {"ordpp",                   too_few_2,      CC_ordpp,      wrong_no_2},
    {"sublistp",                too_few_2,      CC_sublistp,   wrong_no_2},
    {"csl_normbf",              CC_csl_normbf,  too_many_1,    wrong_no_1},
    {"reval_without_mod",       CC_reval_without_mod,too_many_1,wrong_no_1},
    {"addf",                    too_few_2,      CC_addf,       wrong_no_2},
    {"mo=sprod",                too_few_2,      CC_moMsprod,   wrong_no_2},
    {"reduce_pv",               too_few_2,      CC_reduce_pv,  wrong_no_2},
    {"*i2mod",                  CC_Hi2mod,      too_many_1,    wrong_no_1},
    {"general-modular-plus",    too_few_2,      CC_generalKmodularKplus,wrong_no_2},
    {"lalr_first",              CC_lalr_first,  too_many_1,    wrong_no_1},
    {"sort",                    too_few_2,      CC_sort,       wrong_no_2},
    {"finde",                   too_few_2,      CC_finde,      wrong_no_2},
    {"mchk",                    too_few_2,      CC_mchk,       wrong_no_2},
    {"quotsq",                  too_few_2,      CC_quotsq,     wrong_no_2},
    {"tayexp-lessp",            too_few_2,      CC_tayexpKlessp,wrong_no_2},
    {"get+vec+entry",           too_few_2,      CC_getLvecLentry,wrong_no_2},
    {"mri_floorkernelp",        CC_mri_floorkernelp,too_many_1,wrong_no_1},
    {"qqe_qoptailp",            CC_qqe_qoptailp,too_many_1,    wrong_no_1},
    {"ibalp_cec",               CC_ibalp_cec,   too_many_1,    wrong_no_1},
    {"get_token",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_get_token},
    {"xsimp",                   CC_xsimp,       too_many_1,    wrong_no_1},
    {"prepsqxx",                CC_prepsqxx,    too_many_1,    wrong_no_1},
    {"makelist",                CC_makelist,    too_many_1,    wrong_no_1},
    {"i2rd*",                   CC_i2rdH,       too_many_1,    wrong_no_1},
    {"collectindices_reversed", too_few_2,      CC_collectindices_reversed,wrong_no_2},
    {"aeval*",                  CC_aevalH,      too_many_1,    wrong_no_1},
    {"adddm",                   too_few_2,      CC_adddm,      wrong_no_2},
    {"angles-equal",            too_few_2,      CC_anglesKequal,wrong_no_2},
    {"cali_bc_prod",            too_few_2,      CC_cali_bc_prod,wrong_no_2},
    {"sieve_pv",                too_few_2,      CC_sieve_pv,   wrong_no_2},
    {"rnonep:",                 CC_rnonepT,     too_many_1,    wrong_no_1},
    {"multiply-by-constant-mod-p",too_few_2,    CC_multiplyKbyKconstantKmodKp,wrong_no_2},
    {"list2wideid",             CC_list2wideid, too_many_1,    wrong_no_1},
    {"sfto_dcontentf",          CC_sfto_dcontentf,too_many_1,  wrong_no_1},
    {"monomclone",              CC_monomclone,  too_many_1,    wrong_no_1},
    {"arrayp",                  CC_arrayp,      too_many_1,    wrong_no_1},
    {"comfac-to-poly",          CC_comfacKtoKpoly,too_many_1,  wrong_no_1},
    {"mtchk",                   too_few_2,      CC_mtchk,      wrong_no_2},
    {"sfp",                     CC_sfp,         too_many_1,    wrong_no_1},
    {"exptchksq",               CC_exptchksq,   too_many_1,    wrong_no_1},
    {"setcar",                  too_few_2,      CC_setcar,     wrong_no_2},
    {"aex_ctx",                 CC_aex_ctx,     too_many_1,    wrong_no_1},
    {"attributes",              too_few_2,      CC_attributes, wrong_no_2},
    {"c:ordexn",                too_few_2,      CC_cTordexn,   wrong_no_2},
    {"constp",                  CC_constp,      too_many_1,    wrong_no_1},
    {"bczero?",                 CC_bczeroW,     too_many_1,    wrong_no_1},
    {"multpfsq",                too_few_2,      CC_multpfsq,   wrong_no_2},
    {"negnumberchk",            CC_negnumberchk,too_many_1,    wrong_no_1},
    {"order:",                  CC_orderT,      too_many_1,    wrong_no_1},
    {"sinitl",                  CC_sinitl,      too_many_1,    wrong_no_1},
    {"smemqlp",                 too_few_2,      CC_smemqlp,    wrong_no_2},
    {"pappl0",                  too_few_2,      CC_pappl0,     wrong_no_2},
    {"remainder-in-vector",     wrong_no_na,    wrong_no_nb,   (n_args *)CC_remainderKinKvector},
    {"cl_atmlc",                CC_cl_atmlc,    too_many_1,    wrong_no_1},
    {"setcdr",                  too_few_2,      CC_setcdr,     wrong_no_2},
    {"remove-free-vars-l",      CC_removeKfreeKvarsKl,too_many_1,wrong_no_1},
    {"get+vec+dim",             CC_getLvecLdim, too_many_1,    wrong_no_1},
    {"qqe_qopaddp",             CC_qqe_qopaddp, too_many_1,    wrong_no_1},
    {"delq",                    too_few_2,      CC_delq,       wrong_no_2},
    {"notstring",               CC_notstring,   too_many_1,    wrong_no_1},
    {"bcprod",                  too_few_2,      CC_bcprod,     wrong_no_2},
    {"fast-row-dim",            CC_fastKrowKdim,too_many_1,    wrong_no_1},
    {"evmatrixcomp1",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_evmatrixcomp1},
    {"monordp",                 too_few_2,      CC_monordp,    wrong_no_2},
    {"getphystype*sq",          CC_getphystypeHsq,too_many_1,  wrong_no_1},
    {"mo=modiv1",               too_few_2,      CC_moMmodiv1,  wrong_no_2},
    {"unpkp",                   CC_unpkp,       too_many_1,    wrong_no_1},
    {"modtimes:",               too_few_2,      CC_modtimesT,  wrong_no_2},
    {"lesspcar",                too_few_2,      CC_lesspcar,   wrong_no_2},
    {"monomisdivisibleby",      too_few_2,      CC_monomisdivisibleby,wrong_no_2},
    {"powers0",                 too_few_2,      CC_powers0,    wrong_no_2},
    {"rank",                    CC_rank,        too_many_1,    wrong_no_1},
    {"sizchk",                  too_few_2,      CC_sizchk,     wrong_no_2},
    {"qqe_qopheadp",            CC_qqe_qopheadp,too_many_1,    wrong_no_1},
    {"pasf_susitf",             too_few_2,      CC_pasf_susitf,wrong_no_2},
    {"get_content",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_get_content},
    {NULL, (one_args *)"u02", (two_args *)"11968 1310030 7519739", 0}
};

// end of generated code
