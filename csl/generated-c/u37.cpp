
// $destdir/u37.c        Machine generated C code

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



// Code for rl_pnf

static LispObject CC_rl_pnf(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0003;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rl_pnf");
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
    v0003 = v0000;
// end of prologue
    stack[0] = qvalue(elt(env, 1)); // rl_pnf!*
    v0003 = ncons(v0003);
    nil = C_nil;
    if (exception_pending()) goto v0004;
    env = stack[-1];
    {
        LispObject v0005 = stack[0];
        popv(2);
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(qenv(fn), v0005, v0003);
    }
// error exit handlers
v0004:
    popv(2);
    return nil;
}



// Code for pickbasicset

static LispObject CC_pickbasicset(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0020, v0021;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pickbasicset");
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
    v0020 = qvalue(elt(env, 1)); // wuvarlist!*
    stack[-1] = v0020;
    goto v0001;

v0001:
    v0020 = stack[-1];
    if (v0020 == nil) goto v0022;
    v0020 = stack[-1];
    v0020 = qcar(v0020);
    stack[0] = v0020;
    goto v0023;

v0023:
    v0020 = stack[-2];
    if (v0020 == nil) goto v0024;
    v0020 = stack[-2];
    v0020 = qcar(v0020);
    v0020 = qcar(v0020);
    v0020 = qcar(v0020);
    v0021 = qcar(v0020);
    v0020 = stack[0];
    fn = elt(env, 3); // symbollessp
    v0020 = (*qfn2(fn))(qenv(fn), v0021, v0020);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[-4];
    if (v0020 == nil) goto v0024;
    v0020 = stack[-2];
    v0020 = qcdr(v0020);
    stack[-2] = v0020;
    goto v0023;

v0024:
    v0020 = stack[-2];
    if (v0020 == nil) goto v0026;
    v0021 = stack[0];
    v0020 = stack[-2];
    v0020 = qcar(v0020);
    v0020 = qcar(v0020);
    v0020 = qcar(v0020);
    v0020 = qcar(v0020);
    if (equal(v0021, v0020)) goto v0027;
    v0020 = qvalue(elt(env, 2)); // nil
    goto v0028;

v0028:
    if (v0020 == nil) goto v0026;
    v0020 = stack[-2];
    v0020 = qcdr(v0020);
    stack[-2] = v0020;
    goto v0024;

v0026:
    v0020 = stack[-2];
    if (v0020 == nil) goto v0029;
    v0021 = stack[0];
    v0020 = stack[-2];
    v0020 = qcar(v0020);
    v0020 = qcar(v0020);
    v0020 = qcar(v0020);
    v0020 = qcar(v0020);
    if (!(equal(v0021, v0020))) goto v0029;
    v0020 = stack[-2];
    v0021 = qcar(v0020);
    v0020 = stack[-3];
    v0020 = cons(v0021, v0020);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[-4];
    stack[-3] = v0020;
    v0020 = stack[-2];
    v0020 = qcdr(v0020);
    stack[-2] = v0020;
    goto v0029;

v0029:
    v0020 = stack[-1];
    v0020 = qcdr(v0020);
    stack[-1] = v0020;
    goto v0001;

v0027:
    v0020 = stack[-2];
    v0021 = qcar(v0020);
    v0020 = stack[-3];
    fn = elt(env, 4); // wureducedpolysp
    v0020 = (*qfn2(fn))(qenv(fn), v0021, v0020);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[-4];
    v0020 = (v0020 == nil ? lisp_true : nil);
    goto v0028;

v0022:
    v0020 = stack[-3];
        popv(5);
        return Lnreverse(nil, v0020);
// error exit handlers
v0025:
    popv(5);
    return nil;
}



// Code for dvfsf_smcpknowl

static LispObject CC_dvfsf_smcpknowl(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0004, v0005;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dvfsf_smcpknowl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0005 = v0000;
// end of prologue
    v0004 = qvalue(elt(env, 1)); // !*rlsusi
    if (v0004 == nil) goto v0002;
    v0004 = v0005;
    {
        fn = elt(env, 2); // cl_susicpknowl
        return (*qfn1(fn))(qenv(fn), v0004);
    }

v0002:
    v0004 = v0005;
    {
        fn = elt(env, 3); // cl_smcpknowl
        return (*qfn1(fn))(qenv(fn), v0004);
    }
}



// Code for determinantrd

static LispObject CC_determinantrd(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0030;
    LispObject fn;
    argcheck(nargs, 0, "determinantrd");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for determinantrd");
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
    fn = elt(env, 1); // mathml
    v0030 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    env = stack[-1];
    fn = elt(env, 2); // alg_det
    v0030 = (*qfn1(fn))(qenv(fn), v0030);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    env = stack[-1];
    stack[0] = v0030;
    fn = elt(env, 3); // lex
    v0030 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    { LispObject res = stack[0]; popv(2); return onevalue(res); }
// error exit handlers
v0031:
    popv(2);
    return nil;
}



// Code for transmat1

static LispObject CC_transmat1(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0061, v0062, v0063, v0064;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for transmat1");
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
    v0061 = stack[-6];
    v0061 = qcar(v0061);
    fn = elt(env, 6); // aeval
    v0061 = (*qfn1(fn))(qenv(fn), v0061);
    nil = C_nil;
    if (exception_pending()) goto v0065;
    env = stack[-8];
    v0061 = qcdr(v0061);
    stack[0] = v0061;
    v0061 = (LispObject)1; // 0
    stack[-5] = v0061;
    v0061 = (LispObject)1; // 0
    stack[-4] = v0061;
    v0061 = stack[-6];
    v0061 = qcar(v0061);
    fn = elt(env, 6); // aeval
    v0061 = (*qfn1(fn))(qenv(fn), v0061);
    nil = C_nil;
    if (exception_pending()) goto v0065;
    env = stack[-8];
    fn = elt(env, 7); // matlength
    v0061 = (*qfn1(fn))(qenv(fn), v0061);
    nil = C_nil;
    if (exception_pending()) goto v0065;
    env = stack[-8];
    v0061 = qcdr(v0061);
    v0062 = v0061;
    stack[-1] = qcar(v0062);
    v0062 = elt(env, 1); // spm
    v0061 = cons(v0062, v0061);
    nil = C_nil;
    if (exception_pending()) goto v0065;
    env = stack[-8];
    fn = elt(env, 8); // mkempspmat
    v0061 = (*qfn2(fn))(qenv(fn), stack[-1], v0061);
    nil = C_nil;
    if (exception_pending()) goto v0065;
    env = stack[-8];
    stack[-7] = v0061;
    v0061 = qvalue(elt(env, 2)); // nil
    v0061 = ncons(v0061);
    nil = C_nil;
    if (exception_pending()) goto v0065;
    env = stack[-8];
    v0061 = ncons(v0061);
    nil = C_nil;
    if (exception_pending()) goto v0065;
    env = stack[-8];
    stack[-2] = v0061;
    v0061 = stack[0];
    stack[-1] = v0061;
    goto v0026;

v0026:
    v0061 = stack[-1];
    if (v0061 == nil) goto v0066;
    v0061 = stack[-1];
    v0061 = qcar(v0061);
    stack[0] = v0061;
    v0061 = stack[-5];
    v0061 = add1(v0061);
    nil = C_nil;
    if (exception_pending()) goto v0065;
    env = stack[-8];
    stack[-5] = v0061;
    v0061 = stack[0];
    stack[0] = v0061;
    goto v0067;

v0067:
    v0061 = stack[0];
    if (v0061 == nil) goto v0068;
    v0061 = stack[0];
    v0061 = qcar(v0061);
    stack[-3] = v0061;
    v0061 = stack[-4];
    v0061 = add1(v0061);
    nil = C_nil;
    if (exception_pending()) goto v0065;
    env = stack[-8];
    stack[-4] = v0061;
    v0062 = stack[-3];
    v0061 = (LispObject)1; // 0
    if (v0062 == v0061) goto v0014;
    v0063 = stack[-4];
    v0062 = stack[-3];
    v0061 = stack[-2];
    v0061 = acons(v0063, v0062, v0061);
    nil = C_nil;
    if (exception_pending()) goto v0065;
    env = stack[-8];
    stack[-2] = v0061;
    goto v0014;

v0014:
    v0061 = stack[0];
    v0061 = qcdr(v0061);
    stack[0] = v0061;
    goto v0067;

v0068:
    v0061 = stack[-2];
    v0061 = Lreverse(nil, v0061);
    nil = C_nil;
    if (exception_pending()) goto v0065;
    env = stack[-8];
    stack[-2] = v0061;
    stack[0] = stack[-2];
    v0061 = qvalue(elt(env, 2)); // nil
    v0061 = ncons(v0061);
    nil = C_nil;
    if (exception_pending()) goto v0065;
    env = stack[-8];
    v0061 = ncons(v0061);
    nil = C_nil;
    if (exception_pending()) goto v0065;
    env = stack[-8];
    if (equal(stack[0], v0061)) goto v0069;
    v0062 = stack[-7];
    v0061 = stack[-5];
    v0064 = list2(v0062, v0061);
    nil = C_nil;
    if (exception_pending()) goto v0065;
    env = stack[-8];
    v0063 = stack[-2];
    v0062 = stack[-7];
    v0061 = qvalue(elt(env, 2)); // nil
    fn = elt(env, 9); // letmtr3
    v0061 = (*qfnn(fn))(qenv(fn), 4, v0064, v0063, v0062, v0061);
    nil = C_nil;
    if (exception_pending()) goto v0065;
    env = stack[-8];
    goto v0069;

v0069:
    v0061 = (LispObject)1; // 0
    stack[-4] = v0061;
    v0061 = qvalue(elt(env, 2)); // nil
    v0061 = ncons(v0061);
    nil = C_nil;
    if (exception_pending()) goto v0065;
    env = stack[-8];
    v0061 = ncons(v0061);
    nil = C_nil;
    if (exception_pending()) goto v0065;
    env = stack[-8];
    stack[-2] = v0061;
    v0061 = stack[-1];
    v0061 = qcdr(v0061);
    stack[-1] = v0061;
    goto v0026;

v0066:
    v0061 = stack[-6];
    stack[-1] = qcar(v0061);
    stack[0] = elt(env, 3); // avalue
    v0062 = elt(env, 4); // sparse
    v0061 = stack[-7];
    v0061 = list2(v0062, v0061);
    nil = C_nil;
    if (exception_pending()) goto v0065;
    env = stack[-8];
    v0061 = Lputprop(nil, 3, stack[-1], stack[0], v0061);
    nil = C_nil;
    if (exception_pending()) goto v0065;
    env = stack[-8];
    v0061 = stack[-6];
    v0063 = qcar(v0061);
    v0062 = elt(env, 5); // rtype
    v0061 = elt(env, 4); // sparse
    v0061 = Lputprop(nil, 3, v0063, v0062, v0061);
    nil = C_nil;
    if (exception_pending()) goto v0065;
    v0061 = nil;
    { popv(9); return onevalue(v0061); }
// error exit handlers
v0065:
    popv(9);
    return nil;
}



// Code for remzzzz

static LispObject CC_remzzzz(LispObject env,
                         LispObject v0000, LispObject v0070)
{
    LispObject nil = C_nil;
    LispObject v0075, v0076, v0077;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for remzzzz");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0070,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0070);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0070;
    stack[-1] = v0000;
// end of prologue
    v0077 = nil;
    goto v0051;

v0051:
    v0075 = stack[-1];
    if (v0075 == nil) goto v0004;
    v0075 = stack[-1];
    v0075 = qcar(v0075);
    v0076 = qcar(v0075);
    v0075 = stack[0];
    v0075 = qcar(v0075);
    v0075 = qcar(v0075);
    if (equal(v0076, v0075)) goto v0078;
    v0075 = stack[0];
    v0075 = qcar(v0075);
    v0076 = v0077;
    v0075 = cons(v0075, v0076);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-2];
    v0077 = v0075;
    v0075 = stack[0];
    v0075 = qcdr(v0075);
    stack[0] = v0075;
    goto v0051;

v0078:
    v0075 = stack[-1];
    v0075 = qcdr(v0075);
    stack[-1] = v0075;
    v0075 = stack[0];
    v0075 = qcdr(v0075);
    stack[0] = v0075;
    goto v0051;

v0004:
    v0076 = v0077;
    v0075 = stack[0];
    {
        popv(3);
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(qenv(fn), v0076, v0075);
    }
// error exit handlers
v0028:
    popv(3);
    return nil;
}



// Code for sc_rowscalarproduct

static LispObject CC_sc_rowscalarproduct(LispObject env,
                         LispObject v0000, LispObject v0070)
{
    LispObject nil = C_nil;
    LispObject v0086, v0087, v0016;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sc_rowscalarproduct");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0070,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0070);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-2] = v0070;
    stack[-3] = v0000;
// end of prologue
    v0086 = (LispObject)1; // 0
    fn = elt(env, 2); // sc_simp
    v0086 = (*qfn1(fn))(qenv(fn), v0086);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-5];
    stack[0] = v0086;
    v0086 = (LispObject)17; // 1
    stack[-4] = v0086;
    goto v0074;

v0074:
    v0086 = stack[-3];
    fn = elt(env, 3); // fast!-column!-dim
    v0087 = (*qfn1(fn))(qenv(fn), v0086);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-5];
    v0086 = stack[-4];
    v0086 = difference2(v0087, v0086);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-5];
    v0086 = Lminusp(nil, v0086);
    env = stack[-5];
    if (!(v0086 == nil)) { LispObject res = stack[0]; popv(6); return onevalue(res); }
    stack[-1] = stack[0];
    v0016 = stack[-3];
    v0087 = (LispObject)17; // 1
    v0086 = stack[-4];
    fn = elt(env, 4); // sc_getmat
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v0016, v0087, v0086);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-5];
    v0016 = stack[-2];
    v0087 = (LispObject)17; // 1
    v0086 = stack[-4];
    fn = elt(env, 4); // sc_getmat
    v0086 = (*qfnn(fn))(qenv(fn), 3, v0016, v0087, v0086);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-5];
    fn = elt(env, 5); // sc_multsq
    v0086 = (*qfn2(fn))(qenv(fn), stack[0], v0086);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-5];
    fn = elt(env, 6); // sc_addsq
    v0086 = (*qfn2(fn))(qenv(fn), stack[-1], v0086);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-5];
    stack[0] = v0086;
    v0086 = stack[-4];
    v0086 = add1(v0086);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-5];
    stack[-4] = v0086;
    goto v0074;
// error exit handlers
v0088:
    popv(6);
    return nil;
}



// Code for xnsiz

static LispObject CC_xnsiz(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0031, v0004;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for xnsiz");
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
    v0031 = v0000;
// end of prologue
    fn = elt(env, 2); // xnsiz1
    v0004 = (*qfn1(fn))(qenv(fn), v0031);
    nil = C_nil;
    if (exception_pending()) goto v0005;
    env = stack[0];
    v0031 = qvalue(elt(env, 1)); // !!log2of10
    v0031 = quot2(v0004, v0031);
    nil = C_nil;
    if (exception_pending()) goto v0005;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); // ceiling
        return (*qfn1(fn))(qenv(fn), v0031);
    }
// error exit handlers
v0005:
    popv(1);
    return nil;
}



// Code for rd!:difference

static LispObject CC_rdTdifference(LispObject env,
                         LispObject v0000, LispObject v0070)
{
    LispObject nil = C_nil;
    LispObject v0108, v0109, v0110;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rd:difference");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0070,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0070);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0070;
    stack[-2] = v0000;
// end of prologue
    v0108 = qvalue(elt(env, 1)); // nil
    stack[-3] = v0108;
    v0108 = qvalue(elt(env, 2)); // !*!*roundbf
    if (v0108 == nil) goto v0003;
    v0108 = qvalue(elt(env, 1)); // nil
    goto v0030;

v0030:
    if (v0108 == nil) goto v0068;
    v0109 = elt(env, 3); // !:rd!:
    v0108 = stack[-3];
    popv(5);
    return cons(v0109, v0108);

v0068:
    v0109 = stack[-2];
    v0108 = stack[0];
    fn = elt(env, 5); // convprc2
    v0108 = (*qfn2(fn))(qenv(fn), v0109, v0108);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    stack[-1] = v0108;
    v0108 = qvalue(elt(env, 4)); // yy!!
    stack[0] = v0108;
    v0108 = stack[-1];
    if (!consp(v0108)) goto v0052;
    v0109 = stack[-1];
    v0108 = stack[0];
    fn = elt(env, 6); // difbf
    v0108 = (*qfn2(fn))(qenv(fn), v0109, v0108);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    goto v0027;

v0027:
    stack[-2] = v0108;
    v0108 = stack[0];
    if (!consp(v0108)) goto v0112;
    v0108 = stack[0];
    fn = elt(env, 7); // minus!:
    v0108 = (*qfn1(fn))(qenv(fn), v0108);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    goto v0113;

v0113:
    fn = elt(env, 8); // rdzchk
    v0108 = (*qfnn(fn))(qenv(fn), 3, stack[-2], stack[-1], v0108);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    {
        popv(5);
        fn = elt(env, 9); // mkround
        return (*qfn1(fn))(qenv(fn), v0108);
    }

v0112:
    v0108 = stack[0];
    v0108 = negate(v0108);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    goto v0113;

v0052:
    v0109 = stack[-1];
    v0108 = stack[0];
    v0108 = difference2(v0109, v0108);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    stack[-3] = v0108;
    v0108 = stack[-3];
    fn = elt(env, 10); // fp!-infinite
    v0108 = (*qfn1(fn))(qenv(fn), v0108);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    if (v0108 == nil) goto v0061;
    fn = elt(env, 11); // rndbfon
    v0108 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    v0108 = stack[-1];
    v0108 = Lfloatp(nil, v0108);
    env = stack[-4];
    if (v0108 == nil) goto v0114;
    v0108 = stack[-1];
    fn = elt(env, 12); // fl2bf
    v0108 = (*qfn1(fn))(qenv(fn), v0108);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    stack[-2] = v0108;
    goto v0069;

v0069:
    stack[-1] = stack[-2];
    v0108 = stack[0];
    v0108 = Lfloatp(nil, v0108);
    env = stack[-4];
    if (v0108 == nil) goto v0115;
    v0108 = stack[0];
    fn = elt(env, 12); // fl2bf
    v0108 = (*qfn1(fn))(qenv(fn), v0108);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    goto v0116;

v0116:
    stack[0] = v0108;
    fn = elt(env, 6); // difbf
    v0108 = (*qfn2(fn))(qenv(fn), stack[-2], v0108);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    goto v0027;

v0115:
    v0108 = stack[0];
    if (!consp(v0108)) goto v0037;
    v0108 = stack[0];
    goto v0117;

v0117:
    fn = elt(env, 13); // normbf
    v0108 = (*qfn1(fn))(qenv(fn), v0108);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    goto v0116;

v0037:
    v0108 = stack[0];
    v0108 = integerp(v0108);
    if (v0108 == nil) goto v0118;
    v0110 = elt(env, 3); // !:rd!:
    v0109 = stack[0];
    v0108 = (LispObject)1; // 0
    v0108 = list2star(v0110, v0109, v0108);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    goto v0117;

v0118:
    v0108 = stack[0];
    fn = elt(env, 14); // read!:num
    v0108 = (*qfn1(fn))(qenv(fn), v0108);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    goto v0117;

v0114:
    v0108 = stack[-1];
    if (!consp(v0108)) goto v0021;
    v0108 = stack[-1];
    goto v0119;

v0119:
    fn = elt(env, 13); // normbf
    v0108 = (*qfn1(fn))(qenv(fn), v0108);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    stack[-2] = v0108;
    goto v0069;

v0021:
    v0108 = stack[-1];
    v0108 = integerp(v0108);
    if (v0108 == nil) goto v0040;
    v0110 = elt(env, 3); // !:rd!:
    v0109 = stack[-1];
    v0108 = (LispObject)1; // 0
    v0108 = list2star(v0110, v0109, v0108);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    goto v0119;

v0040:
    v0108 = stack[-1];
    fn = elt(env, 14); // read!:num
    v0108 = (*qfn1(fn))(qenv(fn), v0108);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    goto v0119;

v0061:
    v0108 = stack[-3];
    goto v0027;

v0003:
    v0108 = stack[-2];
    v0108 = qcdr(v0108);
    if (!consp(v0108)) goto v0120;
    v0108 = qvalue(elt(env, 1)); // nil
    goto v0030;

v0120:
    v0108 = stack[0];
    v0108 = qcdr(v0108);
    if (!consp(v0108)) goto v0121;
    v0108 = qvalue(elt(env, 1)); // nil
    goto v0030;

v0121:
    v0108 = stack[-2];
    stack[-1] = qcdr(v0108);
    v0108 = stack[0];
    v0108 = qcdr(v0108);
    fn = elt(env, 15); // safe!-fp!-minus
    v0108 = (*qfn1(fn))(qenv(fn), v0108);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    fn = elt(env, 16); // safe!-fp!-plus
    v0108 = (*qfn2(fn))(qenv(fn), stack[-1], v0108);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    stack[-3] = v0108;
    goto v0030;
// error exit handlers
v0111:
    popv(5);
    return nil;
}



// Code for indxsymp

static LispObject CC_indxsymp(LispObject env,
                         LispObject v0000, LispObject v0070)
{
    LispObject nil = C_nil;
    LispObject v0124, v0058;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for indxsymp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0070,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0070);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0070;
    stack[-1] = v0000;
// end of prologue

v0125:
    v0124 = stack[0];
    if (v0124 == nil) goto v0019;
    v0124 = stack[0];
    v0058 = qcar(v0124);
    v0124 = stack[-1];
    v0124 = Lapply1(nil, v0058, v0124);
    nil = C_nil;
    if (exception_pending()) goto v0018;
    env = stack[-2];
    if (v0124 == nil) goto v0004;
    v0058 = stack[-1];
    v0124 = stack[0];
    v0124 = qcdr(v0124);
    stack[-1] = v0058;
    stack[0] = v0124;
    goto v0125;

v0004:
    v0124 = qvalue(elt(env, 2)); // nil
    { popv(3); return onevalue(v0124); }

v0019:
    v0124 = qvalue(elt(env, 1)); // t
    { popv(3); return onevalue(v0124); }
// error exit handlers
v0018:
    popv(3);
    return nil;
}



// Code for lengthreval

static LispObject CC_lengthreval(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0116, v0136, v0137;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lengthreval");
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
    v0116 = stack[-1];
    v0136 = Llength(nil, v0116);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    env = stack[-3];
    v0116 = (LispObject)17; // 1
    if (v0136 == v0116) goto v0001;
    v0137 = elt(env, 1); // alg
    v0136 = (LispObject)177; // 11
    v0116 = elt(env, 2); // "LENGTH called with wrong number of arguments"
    fn = elt(env, 9); // rerror
    v0116 = (*qfnn(fn))(qenv(fn), 3, v0137, v0136, v0116);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    env = stack[-3];
    goto v0001;

v0001:
    v0116 = stack[-1];
    v0116 = qcar(v0116);
    stack[-1] = v0116;
    v0116 = stack[-1];
    if (!(symbolp(v0116))) goto v0107;
    v0116 = stack[-1];
    fn = elt(env, 10); // arrayp
    v0116 = (*qfn1(fn))(qenv(fn), v0116);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    env = stack[-3];
    if (v0116 == nil) goto v0107;
    v0137 = elt(env, 3); // list
    v0136 = stack[-1];
    v0116 = elt(env, 4); // dimension
    v0116 = get(v0136, v0116);
    popv(4);
    return cons(v0137, v0116);

v0107:
    v0116 = stack[-1];
    fn = elt(env, 11); // aeval
    v0116 = (*qfn1(fn))(qenv(fn), v0116);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    env = stack[-3];
    stack[-2] = v0116;
    v0116 = stack[-2];
    fn = elt(env, 12); // getrtype
    v0116 = (*qfn1(fn))(qenv(fn), v0116);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    env = stack[-3];
    v0137 = v0116;
    if (v0116 == nil) goto v0068;
    v0136 = v0137;
    v0116 = elt(env, 5); // lengthfn
    v0116 = get(v0136, v0116);
    env = stack[-3];
    stack[0] = v0116;
    if (v0116 == nil) goto v0068;
    v0136 = stack[0];
    v0116 = stack[-2];
        popv(4);
        return Lapply1(nil, v0136, v0116);

v0068:
    v0116 = stack[-2];
    if (!consp(v0116)) goto v0139;
    v0116 = stack[-2];
    v0116 = qcar(v0116);
    if (symbolp(v0116)) goto v0050;
    v0116 = qvalue(elt(env, 6)); // t
    goto v0140;

v0140:
    if (v0116 == nil) goto v0044;
    v0116 = v0137;
    if (v0116 == nil) goto v0025;
    v0116 = elt(env, 7); // "LENGTH not defined for argument of type"
    v0136 = v0137;
    v0116 = list2(v0116, v0136);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    env = stack[-3];
    fn = elt(env, 13); // lprie
    v0116 = (*qfn1(fn))(qenv(fn), v0116);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    goto v0053;

v0053:
    v0116 = nil;
    { popv(4); return onevalue(v0116); }

v0025:
    v0136 = stack[-1];
    v0116 = elt(env, 8); // "LENGTH argument"
    fn = elt(env, 14); // typerr
    v0116 = (*qfn2(fn))(qenv(fn), v0136, v0116);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    goto v0053;

v0044:
    v0136 = stack[0];
    v0116 = stack[-2];
    v0116 = qcdr(v0116);
        popv(4);
        return Lapply1(nil, v0136, v0116);

v0050:
    v0116 = stack[-2];
    v0136 = qcar(v0116);
    v0116 = elt(env, 5); // lengthfn
    v0116 = get(v0136, v0116);
    env = stack[-3];
    stack[0] = v0116;
    v0116 = (v0116 == nil ? lisp_true : nil);
    goto v0140;

v0139:
    v0116 = (LispObject)17; // 1
    { popv(4); return onevalue(v0116); }
// error exit handlers
v0138:
    popv(4);
    return nil;
}



// Code for createmonomunit

static LispObject CC_createmonomunit(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0135, v0072, v0055;
    argcheck(nargs, 0, "createmonomunit");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for createmonomunit");
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
    v0135 = (LispObject)17; // 1
    v0135 = Lmkvect(nil, v0135);
    nil = C_nil;
    if (exception_pending()) goto v0079;
    env = stack[-3];
    stack[-2] = v0135;
    v0055 = stack[-2];
    v0072 = (LispObject)1; // 0
    v0135 = (LispObject)1; // 0
    *(LispObject *)((char *)v0055 + (CELL-TAG_VECTOR) + ((int32_t)v0072/(16/CELL))) = v0135;
    stack[-1] = stack[-2];
    stack[0] = (LispObject)17; // 1
    v0135 = qvalue(elt(env, 1)); // nil
    v0135 = ncons(v0135);
    nil = C_nil;
    if (exception_pending()) goto v0079;
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v0135;
    { LispObject res = stack[-2]; popv(4); return onevalue(res); }
// error exit handlers
v0079:
    popv(4);
    return nil;
}



// Code for sfto_yun!-updecf

static LispObject CC_sfto_yunKupdecf(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0100, v0098;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sfto_yun-updecf");
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
    stack[-7] = qvalue(elt(env, 1)); // !*gcd
    qvalue(elt(env, 1)) = nil; // !*gcd
    stack[-1] = nil;
    v0100 = qvalue(elt(env, 2)); // t
    qvalue(elt(env, 1)) = v0100; // !*gcd
    v0098 = (LispObject)17; // 1
    v0100 = (LispObject)17; // 1
    v0100 = cons(v0098, v0100);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-8];
    stack[-2] = v0100;
    v0100 = stack[-6];
    v0100 = qcar(v0100);
    v0100 = qcar(v0100);
    v0100 = qcar(v0100);
    stack[-5] = v0100;
    stack[-3] = stack[-6];
    v0098 = stack[-6];
    v0100 = stack[-5];
    fn = elt(env, 3); // diff
    v0100 = (*qfn2(fn))(qenv(fn), v0098, v0100);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-8];
    stack[0] = v0100;
    fn = elt(env, 4); // sfto_gcdf
    v0100 = (*qfn2(fn))(qenv(fn), stack[-3], v0100);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-8];
    stack[-3] = v0100;
    v0098 = stack[-6];
    v0100 = stack[-3];
    fn = elt(env, 5); // quotf
    v0100 = (*qfn2(fn))(qenv(fn), v0098, v0100);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-8];
    stack[-4] = v0100;
    v0098 = stack[0];
    v0100 = stack[-3];
    fn = elt(env, 5); // quotf
    stack[0] = (*qfn2(fn))(qenv(fn), v0098, v0100);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-8];
    v0098 = stack[-4];
    v0100 = stack[-5];
    fn = elt(env, 3); // diff
    v0100 = (*qfn2(fn))(qenv(fn), v0098, v0100);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-8];
    fn = elt(env, 6); // negf
    v0100 = (*qfn1(fn))(qenv(fn), v0100);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-8];
    fn = elt(env, 7); // addf
    v0100 = (*qfn2(fn))(qenv(fn), stack[0], v0100);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-8];
    stack[-3] = v0100;
    goto v0133;

v0133:
    v0100 = stack[-1];
    v0100 = (v0100 == nil ? lisp_true : nil);
    stack[-1] = v0100;
    v0098 = stack[-4];
    v0100 = stack[-3];
    fn = elt(env, 4); // sfto_gcdf
    v0100 = (*qfn2(fn))(qenv(fn), v0098, v0100);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-8];
    stack[-6] = v0100;
    v0100 = stack[-1];
    if (v0100 == nil) goto v0151;
    stack[0] = stack[-2];
    v0100 = stack[-2];
    v0098 = qcar(v0100);
    v0100 = stack[-6];
    fn = elt(env, 8); // multf
    v0100 = (*qfn2(fn))(qenv(fn), v0098, v0100);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-8];
    fn = elt(env, 9); // setcar
    v0100 = (*qfn2(fn))(qenv(fn), stack[0], v0100);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-8];
    goto v0025;

v0025:
    v0098 = stack[-4];
    v0100 = stack[-6];
    fn = elt(env, 5); // quotf
    v0100 = (*qfn2(fn))(qenv(fn), v0098, v0100);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-8];
    stack[-4] = v0100;
    v0098 = stack[-3];
    v0100 = stack[-6];
    fn = elt(env, 5); // quotf
    stack[0] = (*qfn2(fn))(qenv(fn), v0098, v0100);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-8];
    v0098 = stack[-4];
    v0100 = stack[-5];
    fn = elt(env, 3); // diff
    v0100 = (*qfn2(fn))(qenv(fn), v0098, v0100);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-8];
    fn = elt(env, 6); // negf
    v0100 = (*qfn1(fn))(qenv(fn), v0100);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-8];
    fn = elt(env, 7); // addf
    v0100 = (*qfn2(fn))(qenv(fn), stack[0], v0100);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-8];
    stack[-3] = v0100;
    v0100 = stack[-4];
    if (!consp(v0100)) goto v0152;
    v0100 = stack[-4];
    v0100 = qcar(v0100);
    v0100 = (consp(v0100) ? nil : lisp_true);
    goto v0153;

v0153:
    if (v0100 == nil) goto v0133;
    v0100 = stack[-2];
    qvalue(elt(env, 1)) = stack[-7]; // !*gcd
    { popv(9); return onevalue(v0100); }

v0152:
    v0100 = qvalue(elt(env, 2)); // t
    goto v0153;

v0151:
    stack[0] = stack[-2];
    v0100 = stack[-2];
    v0098 = qcdr(v0100);
    v0100 = stack[-6];
    fn = elt(env, 8); // multf
    v0100 = (*qfn2(fn))(qenv(fn), v0098, v0100);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-8];
    fn = elt(env, 10); // setcdr
    v0100 = (*qfn2(fn))(qenv(fn), stack[0], v0100);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-8];
    goto v0025;
// error exit handlers
v0064:
    env = stack[-8];
    qvalue(elt(env, 1)) = stack[-7]; // !*gcd
    popv(9);
    return nil;
}



// Code for squashsqrt

static LispObject CC_squashsqrt(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0108, v0109, v0110;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for squashsqrt");
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

v0125:
    v0108 = qvalue(elt(env, 1)); // sqrtflag
    if (v0108 == nil) goto v0001;
    v0108 = stack[-1];
    if (!consp(v0108)) goto v0120;
    v0108 = stack[-1];
    v0108 = qcar(v0108);
    v0108 = qcar(v0108);
    v0108 = qcar(v0108);
    v0108 = (consp(v0108) ? nil : lisp_true);
    goto v0022;

v0022:
    if (!(v0108 == nil)) { LispObject res = stack[-1]; popv(4); return onevalue(res); }
    v0108 = stack[-1];
    v0108 = qcar(v0108);
    v0108 = qcar(v0108);
    v0108 = qcar(v0108);
    v0109 = qcar(v0108);
    v0108 = elt(env, 3); // sqrt
    if (v0109 == v0108) goto v0024;
    v0108 = qvalue(elt(env, 4)); // nil
    goto v0056;

v0056:
    if (v0108 == nil) goto v0165;
    v0108 = stack[-1];
    v0108 = qcdr(v0108);
    stack[0] = CC_squashsqrt(env, v0108);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-3];
    v0108 = stack[-1];
    v0108 = qcar(v0108);
    v0108 = qcar(v0108);
    v0110 = qcar(v0108);
    v0108 = stack[-1];
    v0108 = qcar(v0108);
    v0109 = qcdr(v0108);
    v0108 = stack[-1];
    v0108 = qcar(v0108);
    v0108 = qcar(v0108);
    v0108 = qcdr(v0108);
    fn = elt(env, 6); // !*multfsqrt
    v0108 = (*qfnn(fn))(qenv(fn), 3, v0110, v0109, v0108);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-3];
    {
        LispObject v0111 = stack[0];
        popv(4);
        fn = elt(env, 7); // addf
        return (*qfn2(fn))(qenv(fn), v0111, v0108);
    }

v0165:
    v0108 = stack[-1];
    v0108 = qcar(v0108);
    v0108 = qcar(v0108);
    v0108 = qcar(v0108);
    v0109 = qcar(v0108);
    v0108 = elt(env, 5); // expt
    if (v0109 == v0108) goto v0103;
    v0108 = qvalue(elt(env, 4)); // nil
    goto v0102;

v0102:
    if (v0108 == nil) goto v0100;
    v0108 = stack[-1];
    v0108 = qcdr(v0108);
    stack[0] = CC_squashsqrt(env, v0108);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-3];
    v0108 = stack[-1];
    v0108 = qcar(v0108);
    v0108 = qcar(v0108);
    v0110 = qcar(v0108);
    v0108 = stack[-1];
    v0108 = qcar(v0108);
    v0109 = qcdr(v0108);
    v0108 = stack[-1];
    v0108 = qcar(v0108);
    v0108 = qcar(v0108);
    v0108 = qcdr(v0108);
    fn = elt(env, 8); // !*multfexpt
    v0108 = (*qfnn(fn))(qenv(fn), 3, v0110, v0109, v0108);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-3];
    {
        LispObject v0167 = stack[0];
        popv(4);
        fn = elt(env, 7); // addf
        return (*qfn2(fn))(qenv(fn), v0167, v0108);
    }

v0100:
    v0108 = stack[-1];
    v0108 = qcar(v0108);
    v0108 = qcdr(v0108);
    v0108 = CC_squashsqrt(env, v0108);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-3];
    v0109 = v0108;
    v0108 = v0109;
    if (v0108 == nil) goto v0063;
    v0108 = stack[-1];
    v0108 = qcar(v0108);
    stack[-2] = qcar(v0108);
    stack[0] = v0109;
    v0108 = stack[-1];
    v0108 = qcdr(v0108);
    v0108 = CC_squashsqrt(env, v0108);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    {
        LispObject v0168 = stack[-2];
        LispObject v0169 = stack[0];
        popv(4);
        return acons(v0168, v0169, v0108);
    }

v0063:
    v0108 = stack[-1];
    v0108 = qcdr(v0108);
    stack[-1] = v0108;
    goto v0125;

v0103:
    v0108 = stack[-1];
    v0108 = qcar(v0108);
    v0108 = qcar(v0108);
    v0108 = qcar(v0108);
    v0108 = qcdr(v0108);
    v0108 = qcdr(v0108);
    v0108 = qcar(v0108);
    fn = elt(env, 9); // prefix!-rational!-numberp
    v0108 = (*qfn1(fn))(qenv(fn), v0108);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-3];
    if (v0108 == nil) goto v0069;
    v0108 = stack[-1];
    v0108 = qcar(v0108);
    v0108 = qcar(v0108);
    v0109 = qcdr(v0108);
    v0108 = stack[-1];
    v0108 = qcar(v0108);
    v0108 = qcar(v0108);
    v0108 = qcar(v0108);
    v0108 = qcdr(v0108);
    v0108 = qcdr(v0108);
    v0108 = qcar(v0108);
    v0108 = qcdr(v0108);
    v0108 = qcdr(v0108);
    v0108 = qcar(v0108);
    v0108 = (LispObject)geq2(v0109, v0108);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    v0108 = v0108 ? lisp_true : nil;
    env = stack[-3];
    goto v0102;

v0069:
    v0108 = qvalue(elt(env, 4)); // nil
    goto v0102;

v0024:
    v0108 = stack[-1];
    v0108 = qcar(v0108);
    v0108 = qcar(v0108);
    v0109 = qcdr(v0108);
    v0108 = (LispObject)17; // 1
    v0108 = (LispObject)greaterp2(v0109, v0108);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    v0108 = v0108 ? lisp_true : nil;
    env = stack[-3];
    goto v0056;

v0120:
    v0108 = qvalue(elt(env, 2)); // t
    goto v0022;

v0001:
    v0108 = qvalue(elt(env, 2)); // t
    goto v0022;
// error exit handlers
v0166:
    popv(4);
    return nil;
}



// Code for rl_onp

static LispObject CC_rl_onp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0142;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rl_onp");
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
    v0142 = elt(env, 1); // !*
    stack[-1] = Lexplode(nil, v0142);
    nil = C_nil;
    if (exception_pending()) goto v0011;
    env = stack[-2];
    v0142 = stack[0];
    v0142 = Lexplode(nil, v0142);
    nil = C_nil;
    if (exception_pending()) goto v0011;
    env = stack[-2];
    v0142 = Lappend(nil, stack[-1], v0142);
    nil = C_nil;
    if (exception_pending()) goto v0011;
    env = stack[-2];
    v0142 = Lcompress(nil, v0142);
    nil = C_nil;
    if (exception_pending()) goto v0011;
    env = stack[-2];
    v0142 = Lintern(nil, v0142);
    nil = C_nil;
    if (exception_pending()) goto v0011;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 2); // eval
        return (*qfn1(fn))(qenv(fn), v0142);
    }
// error exit handlers
v0011:
    popv(3);
    return nil;
}



// Code for termorder1

static LispObject CC_termorder1(LispObject env,
                         LispObject v0000, LispObject v0070)
{
    LispObject nil = C_nil;
    LispObject v0015, v0170;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for termorder1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0070,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0070);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0070;
    stack[-1] = v0000;
// end of prologue

v0019:
    v0015 = stack[-1];
    if (v0015 == nil) goto v0001;
    v0015 = stack[-1];
    v0015 = (LispObject)zerop(v0015);
    v0015 = v0015 ? lisp_true : nil;
    env = stack[-2];
    if (v0015 == nil) goto v0004;
    v0015 = stack[0];
    v0015 = (LispObject)zerop(v0015);
    v0015 = v0015 ? lisp_true : nil;
    env = stack[-2];
    if (v0015 == nil) goto v0004;
    v0015 = (LispObject)1; // 0
    { popv(3); return onevalue(v0015); }

v0004:
    v0015 = stack[-1];
    v0015 = (LispObject)zerop(v0015);
    v0015 = v0015 ? lisp_true : nil;
    env = stack[-2];
    if (v0015 == nil) goto v0122;
    v0015 = (LispObject)-15; // -1
    { popv(3); return onevalue(v0015); }

v0122:
    v0015 = stack[0];
    v0015 = (LispObject)zerop(v0015);
    v0015 = v0015 ? lisp_true : nil;
    env = stack[-2];
    if (v0015 == nil) goto v0079;
    v0015 = (LispObject)17; // 1
    { popv(3); return onevalue(v0015); }

v0079:
    v0015 = stack[-1];
    v0170 = qcar(v0015);
    v0015 = stack[0];
    v0015 = qcar(v0015);
    v0015 = (LispObject)lessp2(v0170, v0015);
    nil = C_nil;
    if (exception_pending()) goto v0087;
    v0015 = v0015 ? lisp_true : nil;
    env = stack[-2];
    if (v0015 == nil) goto v0071;
    v0015 = (LispObject)-15; // -1
    { popv(3); return onevalue(v0015); }

v0071:
    v0015 = stack[-1];
    v0170 = qcar(v0015);
    v0015 = stack[0];
    v0015 = qcar(v0015);
    v0015 = (LispObject)greaterp2(v0170, v0015);
    nil = C_nil;
    if (exception_pending()) goto v0087;
    v0015 = v0015 ? lisp_true : nil;
    env = stack[-2];
    if (v0015 == nil) goto v0091;
    v0015 = (LispObject)17; // 1
    { popv(3); return onevalue(v0015); }

v0091:
    v0015 = stack[-1];
    v0015 = qcdr(v0015);
    stack[-1] = v0015;
    v0015 = stack[0];
    v0015 = qcdr(v0015);
    stack[0] = v0015;
    goto v0019;

v0001:
    v0015 = (LispObject)1; // 0
    { popv(3); return onevalue(v0015); }
// error exit handlers
v0087:
    popv(3);
    return nil;
}



// Code for vdp_make

static LispObject CC_vdp_make(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0141, v0085, v0121;
    LispObject v0008, v0070, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "vdp_make");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0070 = va_arg(aa, LispObject);
    v0008 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vdp_make");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0008,v0070,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0070,v0008);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    v0141 = v0008;
    v0085 = v0070;
    v0121 = v0000;
// end of prologue
    stack[-2] = elt(env, 1); // vdp
    stack[-1] = v0085;
    stack[0] = v0121;
    v0085 = v0141;
    v0141 = qvalue(elt(env, 2)); // nil
    v0141 = list2(v0085, v0141);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    {
        LispObject v0073 = stack[-2];
        LispObject v0107 = stack[-1];
        LispObject v0079 = stack[0];
        popv(3);
        return list3star(v0073, v0107, v0079, v0141);
    }
// error exit handlers
v0056:
    popv(3);
    return nil;
}



// Code for sfto_subfwd

static LispObject CC_sfto_subfwd(LispObject env,
                         LispObject v0000, LispObject v0070)
{
    LispObject nil = C_nil;
    LispObject v0148, v0009;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sfto_subfwd");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0070,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0070);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0070;
    stack[-2] = v0000;
// end of prologue
    v0148 = stack[-2];
    if (!consp(v0148)) goto v0005;
    v0148 = stack[-2];
    v0148 = qcar(v0148);
    v0148 = (consp(v0148) ? nil : lisp_true);
    goto v0004;

v0004:
    if (!(v0148 == nil)) { LispObject res = stack[-2]; popv(5); return onevalue(res); }
    v0148 = stack[-2];
    v0148 = qcar(v0148);
    v0148 = qcar(v0148);
    v0009 = qcar(v0148);
    v0148 = stack[-1];
    v0148 = Latsoc(nil, v0009, v0148);
    v0009 = v0148;
    if (v0009 == nil) goto v0077;
    v0009 = stack[-2];
    v0009 = qcar(v0009);
    v0009 = qcar(v0009);
    v0009 = qcdr(v0009);
    v0148 = qcdr(v0148);
    v0148 = quot2(v0009, v0148);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-4];
    goto v0087;

v0087:
    v0009 = stack[-2];
    v0009 = qcar(v0009);
    v0009 = qcar(v0009);
    v0009 = qcar(v0009);
    fn = elt(env, 2); // to
    stack[-3] = (*qfn2(fn))(qenv(fn), v0009, v0148);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-4];
    v0148 = stack[-2];
    v0148 = qcar(v0148);
    v0009 = qcdr(v0148);
    v0148 = stack[-1];
    stack[0] = CC_sfto_subfwd(env, v0009, v0148);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-4];
    v0148 = stack[-2];
    v0009 = qcdr(v0148);
    v0148 = stack[-1];
    v0148 = CC_sfto_subfwd(env, v0009, v0148);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    {
        LispObject v0149 = stack[-3];
        LispObject v0131 = stack[0];
        popv(5);
        return acons(v0149, v0131, v0148);
    }

v0077:
    v0148 = stack[-2];
    v0148 = qcar(v0148);
    v0148 = qcar(v0148);
    v0148 = qcdr(v0148);
    goto v0087;

v0005:
    v0148 = qvalue(elt(env, 1)); // t
    goto v0004;
// error exit handlers
v0010:
    popv(5);
    return nil;
}



// Code for omattrir

static LispObject CC_omattrir(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0027, v0176, v0132;
    LispObject fn;
    argcheck(nargs, 0, "omattrir");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for omattrir");
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
    fn = elt(env, 6); // lex
    v0027 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[-2];
    fn = elt(env, 7); // omatpir
    v0027 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[-2];
    stack[-1] = v0027;
    fn = elt(env, 6); // lex
    v0027 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[-2];
    fn = elt(env, 8); // omobj
    v0027 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[-2];
    stack[0] = v0027;
    fn = elt(env, 6); // lex
    v0027 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[-2];
    v0027 = elt(env, 1); // (!/ o m a t t r)
    fn = elt(env, 9); // checktag
    v0027 = (*qfn1(fn))(qenv(fn), v0027);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[-2];
    v0027 = stack[-1];
    v0027 = Lconsp(nil, v0027);
    env = stack[-2];
    if (v0027 == nil) goto v0004;
    v0027 = stack[-1];
    v0027 = qcar(v0027);
    v0027 = qcdr(v0027);
    v0176 = qcar(v0027);
    v0027 = elt(env, 2); // csymbol
    if (!(v0176 == v0027)) goto v0004;
    v0176 = stack[0];
    v0027 = qvalue(elt(env, 3)); // nil
    v0132 = qvalue(elt(env, 3)); // nil
    popv(3);
    return list2star(v0176, v0027, v0132);

v0004:
    v0027 = stack[0];
    if (is_number(v0027)) goto v0083;
    v0132 = elt(env, 5); // ci
    v0176 = stack[-1];
    v0027 = stack[0];
    popv(3);
    return list3(v0132, v0176, v0027);

v0083:
    v0132 = elt(env, 4); // cn
    v0176 = stack[-1];
    v0027 = stack[0];
    popv(3);
    return list3(v0132, v0176, v0027);
// error exit handlers
v0174:
    popv(3);
    return nil;
}



// Code for reduceroots

static LispObject CC_reduceroots(LispObject env,
                         LispObject v0000, LispObject v0070)
{
    LispObject nil = C_nil;
    LispObject v0026, v0024, v0071;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for reduceroots");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0070,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0070);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0070;
    stack[-1] = v0000;
// end of prologue
    v0026 = nil;
    goto v0001;

v0001:
    v0024 = stack[-1];
    if (v0024 == nil) { popv(3); return onevalue(v0026); }
    v0024 = stack[0];
    v0071 = qcar(v0024);
    v0024 = elt(env, 2); // sqrt
    if (!consp(v0071)) goto v0120;
    v0071 = qcar(v0071);
    if (!(v0071 == v0024)) goto v0120;
    v0071 = stack[-1];
    v0024 = stack[0];
    v0024 = qcar(v0024);
    fn = elt(env, 3); // tryreduction
    v0026 = (*qfnn(fn))(qenv(fn), 3, v0071, v0024, v0026);
    nil = C_nil;
    if (exception_pending()) goto v0075;
    env = stack[-2];
    goto v0120;

v0120:
    v0024 = stack[-1];
    v0024 = qcdr(v0024);
    stack[-1] = v0024;
    v0024 = stack[0];
    v0024 = qcdr(v0024);
    stack[0] = v0024;
    goto v0001;
// error exit handlers
v0075:
    popv(3);
    return nil;
}



// Code for f2dip1

static LispObject CC_f2dip1(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0173, v0147, v0148, v0009, v0050;
    LispObject fn;
    LispObject v0008, v0070, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "f2dip1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0070 = va_arg(aa, LispObject);
    v0008 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for f2dip1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0008,v0070,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0070,v0008);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0008;
    stack[-1] = v0070;
    stack[-2] = v0000;
// end of prologue
    v0173 = stack[-2];
    if (v0173 == nil) goto v0051;
    v0173 = stack[-2];
    if (!consp(v0173)) goto v0005;
    v0173 = stack[-2];
    v0173 = qcar(v0173);
    v0173 = (consp(v0173) ? nil : lisp_true);
    goto v0004;

v0004:
    if (v0173 == nil) goto v0175;
    v0173 = stack[0];
    v0173 = (is_number(v0173) ? lisp_true : nil);
    if (!(v0173 == nil)) goto v0054;
    v0173 = stack[0];
    fn = elt(env, 3); // f2dip11
    v0173 = (*qfn1(fn))(qenv(fn), v0173);
    nil = C_nil;
    if (exception_pending()) goto v0149;
    env = stack[-4];
    goto v0054;

v0054:
    v0173 = stack[-2];
    fn = elt(env, 4); // bcfd
    v0173 = (*qfn1(fn))(qenv(fn), v0173);
    nil = C_nil;
    if (exception_pending()) goto v0149;
    env = stack[-4];
    fn = elt(env, 5); // bcprod
    v0173 = (*qfn2(fn))(qenv(fn), stack[0], v0173);
    nil = C_nil;
    if (exception_pending()) goto v0149;
    env = stack[-4];
    v0147 = qvalue(elt(env, 1)); // nil
    {
        LispObject v0131 = stack[-1];
        popv(5);
        return list2star(v0131, v0173, v0147);
    }

v0175:
    v0173 = stack[-2];
    v0173 = qcar(v0173);
    v0173 = qcar(v0173);
    v0050 = qcar(v0173);
    v0173 = stack[-2];
    v0173 = qcar(v0173);
    v0173 = qcar(v0173);
    v0009 = qcdr(v0173);
    v0173 = stack[-2];
    v0173 = qcar(v0173);
    v0148 = qcdr(v0173);
    v0147 = stack[-1];
    v0173 = stack[0];
    fn = elt(env, 6); // f2dip2
    stack[-3] = (*qfnn(fn))(qenv(fn), 5, v0050, v0009, v0148, v0147, v0173);
    nil = C_nil;
    if (exception_pending()) goto v0149;
    env = stack[-4];
    v0173 = stack[-2];
    v0148 = qcdr(v0173);
    v0147 = stack[-1];
    v0173 = stack[0];
    v0173 = CC_f2dip1(env, 3, v0148, v0147, v0173);
    nil = C_nil;
    if (exception_pending()) goto v0149;
    env = stack[-4];
    {
        LispObject v0095 = stack[-3];
        popv(5);
        fn = elt(env, 7); // dipsum
        return (*qfn2(fn))(qenv(fn), v0095, v0173);
    }

v0005:
    v0173 = qvalue(elt(env, 2)); // t
    goto v0004;

v0051:
    v0173 = qvalue(elt(env, 1)); // nil
    { popv(5); return onevalue(v0173); }
// error exit handlers
v0149:
    popv(5);
    return nil;
}



// Code for add_item

static LispObject CC_add_item(LispObject env,
                         LispObject v0000, LispObject v0070)
{
    LispObject nil = C_nil;
    LispObject v0068, v0067;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for add_item");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0070,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0070);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0070;
    stack[-1] = v0000;
// end of prologue

v0019:
    v0068 = stack[0];
    v0068 = qcdr(v0068);
    if (v0068 == nil) goto v0004;
    v0068 = stack[0];
    v0068 = qcar(v0068);
    v0067 = qcar(v0068);
    v0068 = stack[-1];
    v0068 = qcar(v0068);
    fn = elt(env, 3); // monordp
    v0068 = (*qfn2(fn))(qenv(fn), v0067, v0068);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-3];
    if (v0068 == nil) goto v0092;
    v0068 = stack[0];
    v0068 = qcdr(v0068);
    v0068 = qcar(v0068);
    stack[0] = v0068;
    goto v0019;

v0092:
    v0068 = stack[0];
    v0068 = qcdr(v0068);
    v0068 = qcdr(v0068);
    stack[0] = v0068;
    goto v0019;

v0004:
    v0067 = stack[0];
    v0068 = stack[-1];
    fn = elt(env, 4); // setcar
    v0068 = (*qfn2(fn))(qenv(fn), v0067, v0068);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-3];
    stack[-2] = stack[0];
    stack[-1] = elt(env, 1); // !*xset!*
    stack[0] = qvalue(elt(env, 2)); // nil
    v0068 = elt(env, 1); // !*xset!*
    v0068 = ncons(v0068);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-3];
    v0068 = acons(stack[-1], stack[0], v0068);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-3];
    fn = elt(env, 5); // setcdr
    v0068 = (*qfn2(fn))(qenv(fn), stack[-2], v0068);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-3];
    v0068 = qvalue(elt(env, 2)); // nil
    { popv(4); return onevalue(v0068); }
// error exit handlers
v0086:
    popv(4);
    return nil;
}



// Code for fl2bf

static LispObject CC_fl2bf(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0092, v0091;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for fl2bf");
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
    v0092 = stack[-1];
    fn = elt(env, 4); // fp!-finite
    v0092 = (*qfn1(fn))(qenv(fn), v0092);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-3];
    if (v0092 == nil) goto v0057;
    v0092 = stack[-1];
    fn = elt(env, 5); // frexp
    v0092 = (*qfn1(fn))(qenv(fn), v0092);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-3];
    stack[-2] = v0092;
    v0092 = stack[-2];
    v0092 = qcdr(v0092);
    stack[-1] = v0092;
    v0092 = stack[-2];
    v0092 = qcar(v0092);
    stack[-2] = v0092;
    stack[0] = stack[-1];
    v0091 = (LispObject)33; // 2
    v0092 = qvalue(elt(env, 2)); // !!nbfpd
    v0092 = Lexpt(nil, v0091, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-3];
    v0092 = times2(stack[0], v0092);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-3];
    v0092 = Ltruncate(nil, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-3];
    stack[-1] = v0092;
    stack[0] = elt(env, 3); // !:rd!:
    v0091 = stack[-2];
    v0092 = qvalue(elt(env, 2)); // !!nbfpd
    v0092 = difference2(v0091, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-3];
    v0092 = list2star(stack[0], stack[-1], v0092);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-3];
    {
        popv(4);
        fn = elt(env, 6); // normbf
        return (*qfn1(fn))(qenv(fn), v0092);
    }

v0057:
    v0092 = elt(env, 1); // "Floating point infinity or NaN"
    {
        popv(4);
        fn = elt(env, 7); // rederr
        return (*qfn1(fn))(qenv(fn), v0092);
    }
// error exit handlers
v0068:
    popv(4);
    return nil;
}



// Code for spp

static LispObject CC_spp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0005, v0142;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for spp");
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
    v0142 = v0005;
    v0142 = Lconsp(nil, v0142);
    env = stack[0];
    if (v0142 == nil) goto v0057;
    v0005 = qcar(v0005);
    {
        popv(1);
        fn = elt(env, 2); // kernelp
        return (*qfn1(fn))(qenv(fn), v0005);
    }

v0057:
    v0005 = qvalue(elt(env, 1)); // nil
    { popv(1); return onevalue(v0005); }
}



// Code for calc_coeffmap_

static LispObject CC_calc_coeffmap_(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0026, v0024, v0071;
    LispObject fn;
    LispObject v0008, v0070, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "calc_coeffmap_");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0070 = va_arg(aa, LispObject);
    v0008 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for calc_coeffmap_");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0008,v0070,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0070,v0008);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0008;
    stack[-2] = v0070;
    v0026 = v0000;
// end of prologue
    v0024 = v0026;
    v0026 = stack[-1];
    fn = elt(env, 2); // calc_map_
    v0026 = (*qfn2(fn))(qenv(fn), v0024, v0026);
    nil = C_nil;
    if (exception_pending()) goto v0077;
    env = stack[-4];
    v0071 = v0026;
    v0024 = v0071;
    v0026 = (LispObject)1; // 0
    if (v0024 == v0026) goto v0142;
    stack[-3] = elt(env, 1); // times
    stack[0] = v0071;
    v0024 = stack[-2];
    v0026 = stack[-1];
    fn = elt(env, 3); // calc_coeff
    v0026 = (*qfn2(fn))(qenv(fn), v0024, v0026);
    nil = C_nil;
    if (exception_pending()) goto v0077;
    {
        LispObject v0106 = stack[-3];
        LispObject v0012 = stack[0];
        popv(5);
        return list2star(v0106, v0012, v0026);
    }

v0142:
    v0026 = (LispObject)1; // 0
    { popv(5); return onevalue(v0026); }
// error exit handlers
v0077:
    popv(5);
    return nil;
}



// Code for fs!:minusp

static LispObject CC_fsTminusp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0081, v0054, v0164;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for fs:minusp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0054 = v0000;
// end of prologue

v0057:
    v0081 = v0054;
    if (v0081 == nil) goto v0022;
    v0164 = v0054;
    v0081 = (LispObject)49; // 3
    v0081 = *(LispObject *)((char *)v0164 + (CELL-TAG_VECTOR) + ((int32_t)v0081/(16/CELL)));
    if (v0081 == nil) goto v0084;
    v0081 = (LispObject)49; // 3
    v0081 = *(LispObject *)((char *)v0054 + (CELL-TAG_VECTOR) + ((int32_t)v0081/(16/CELL)));
    v0054 = v0081;
    goto v0057;

v0084:
    v0081 = (LispObject)1; // 0
    v0081 = *(LispObject *)((char *)v0054 + (CELL-TAG_VECTOR) + ((int32_t)v0081/(16/CELL)));
    v0081 = qcar(v0081);
    {
        fn = elt(env, 2); // minusf
        return (*qfn1(fn))(qenv(fn), v0081);
    }

v0022:
    v0081 = qvalue(elt(env, 1)); // nil
    return onevalue(v0081);
}



// Code for ra_intequiv0

static LispObject CC_ra_intequiv0(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0153, v0152, v0179, v0160;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ra_intequiv0");
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
    v0153 = stack[-3];
    fn = elt(env, 3); // ra_zerop
    v0153 = (*qfn1(fn))(qenv(fn), v0153);
    nil = C_nil;
    if (exception_pending()) goto v0180;
    env = stack[-5];
    if (v0153 == nil) goto v0002;
    v0153 = (LispObject)1; // 0
    { popv(6); return onevalue(v0153); }

v0002:
    v0153 = stack[-3];
    fn = elt(env, 4); // ra_f
    v0153 = (*qfn1(fn))(qenv(fn), v0153);
    nil = C_nil;
    if (exception_pending()) goto v0180;
    env = stack[-5];
    stack[-4] = v0153;
    v0153 = stack[-4];
    v0153 = qcar(v0153);
    v0153 = qcar(v0153);
    v0152 = qcdr(v0153);
    v0153 = (LispObject)17; // 1
    v0153 = Leqn(nil, v0152, v0153);
    nil = C_nil;
    if (exception_pending()) goto v0180;
    env = stack[-5];
    if (v0153 == nil) goto v0011;
    v0153 = stack[-4];
    v0153 = qcar(v0153);
    v0152 = qcdr(v0153);
    v0153 = (LispObject)17; // 1
    v0153 = Leqn(nil, v0152, v0153);
    nil = C_nil;
    if (exception_pending()) goto v0180;
    env = stack[-5];
    if (v0153 == nil) goto v0011;
    v0153 = stack[-4];
    v0153 = qcdr(v0153);
    {
        popv(6);
        fn = elt(env, 5); // negf
        return (*qfn1(fn))(qenv(fn), v0153);
    }

v0011:
    v0153 = stack[-3];
    fn = elt(env, 6); // ra_iv
    v0153 = (*qfn1(fn))(qenv(fn), v0153);
    nil = C_nil;
    if (exception_pending()) goto v0180;
    env = stack[-5];
    fn = elt(env, 7); // riv_l
    v0153 = (*qfn1(fn))(qenv(fn), v0153);
    nil = C_nil;
    if (exception_pending()) goto v0180;
    env = stack[-5];
    stack[-2] = v0153;
    v0153 = stack[-3];
    fn = elt(env, 6); // ra_iv
    v0153 = (*qfn1(fn))(qenv(fn), v0153);
    nil = C_nil;
    if (exception_pending()) goto v0180;
    env = stack[-5];
    fn = elt(env, 8); // riv_u
    v0153 = (*qfn1(fn))(qenv(fn), v0153);
    nil = C_nil;
    if (exception_pending()) goto v0180;
    env = stack[-5];
    stack[-1] = v0153;
    goto v0087;

v0087:
    stack[0] = stack[-1];
    v0153 = stack[-2];
    fn = elt(env, 9); // negsq
    v0153 = (*qfn1(fn))(qenv(fn), v0153);
    nil = C_nil;
    if (exception_pending()) goto v0180;
    env = stack[-5];
    fn = elt(env, 10); // addsq
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v0153);
    nil = C_nil;
    if (exception_pending()) goto v0180;
    env = stack[-5];
    v0152 = (LispObject)17; // 1
    v0153 = (LispObject)17; // 1
    v0153 = cons(v0152, v0153);
    nil = C_nil;
    if (exception_pending()) goto v0180;
    env = stack[-5];
    fn = elt(env, 11); // sfto_greaterq
    v0153 = (*qfn2(fn))(qenv(fn), stack[0], v0153);
    nil = C_nil;
    if (exception_pending()) goto v0180;
    env = stack[-5];
    if (v0153 == nil) goto v0181;
    v0160 = stack[-4];
    v0179 = stack[-2];
    v0152 = stack[-1];
    v0153 = (LispObject)17; // 1
    fn = elt(env, 12); // ra_refine1
    v0153 = (*qfnn(fn))(qenv(fn), 4, v0160, v0179, v0152, v0153);
    nil = C_nil;
    if (exception_pending()) goto v0180;
    env = stack[-5];
    v0152 = v0153;
    v0153 = v0152;
    v0153 = qcar(v0153);
    stack[-2] = v0153;
    v0153 = v0152;
    v0153 = qcdr(v0153);
    stack[-1] = v0153;
    goto v0087;

v0181:
    v0153 = stack[-2];
    fn = elt(env, 13); // sfto_floorq
    v0153 = (*qfn1(fn))(qenv(fn), v0153);
    nil = C_nil;
    if (exception_pending()) goto v0180;
    env = stack[-5];
    v0152 = qcar(v0153);
    v0153 = (LispObject)17; // 1
    fn = elt(env, 14); // addf
    v0153 = (*qfn2(fn))(qenv(fn), v0152, v0153);
    nil = C_nil;
    if (exception_pending()) goto v0180;
    env = stack[-5];
    stack[0] = v0153;
    v0152 = stack[0];
    v0153 = (LispObject)17; // 1
    v0152 = cons(v0152, v0153);
    nil = C_nil;
    if (exception_pending()) goto v0180;
    env = stack[-5];
    v0153 = stack[-1];
    fn = elt(env, 15); // sfto_lessq
    v0153 = (*qfn2(fn))(qenv(fn), v0152, v0153);
    nil = C_nil;
    if (exception_pending()) goto v0180;
    env = stack[-5];
    if (v0153 == nil) { LispObject res = stack[-3]; popv(6); return onevalue(res); }
    stack[-1] = stack[-4];
    v0152 = elt(env, 2); // x
    v0153 = stack[0];
    v0153 = cons(v0152, v0153);
    nil = C_nil;
    if (exception_pending()) goto v0180;
    env = stack[-5];
    v0153 = ncons(v0153);
    nil = C_nil;
    if (exception_pending()) goto v0180;
    env = stack[-5];
    fn = elt(env, 16); // sfto_fsub1
    v0153 = (*qfn2(fn))(qenv(fn), stack[-1], v0153);
    nil = C_nil;
    if (exception_pending()) goto v0180;
    if (!(v0153 == nil)) { LispObject res = stack[-3]; popv(6); return onevalue(res); }
    v0153 = stack[0];
    if (!(v0153 == nil)) { popv(6); return onevalue(v0153); }
    v0153 = (LispObject)1; // 0
    { popv(6); return onevalue(v0153); }
// error exit handlers
v0180:
    popv(6);
    return nil;
}



// Code for mk!+scal!+mult!+mat

static LispObject CC_mkLscalLmultLmat(LispObject env,
                         LispObject v0000, LispObject v0070)
{
    LispObject nil = C_nil;
    LispObject v0185, v0186;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mk+scal+mult+mat");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0070,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0070);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0070;
    stack[-8] = v0000;
// end of prologue
    v0185 = stack[0];
    fn = elt(env, 5); // matrix!+p
    v0185 = (*qfn1(fn))(qenv(fn), v0185);
    nil = C_nil;
    if (exception_pending()) goto v0187;
    env = stack[-10];
    if (!(v0185 == nil)) goto v0030;
    v0185 = elt(env, 1); // "no matrix in add"
    fn = elt(env, 6); // rederr
    v0185 = (*qfn1(fn))(qenv(fn), v0185);
    nil = C_nil;
    if (exception_pending()) goto v0187;
    env = stack[-10];
    goto v0030;

v0030:
    v0185 = stack[0];
    stack[-9] = v0185;
    v0185 = stack[-9];
    if (v0185 == nil) goto v0085;
    v0185 = stack[-9];
    v0185 = qcar(v0185);
    stack[-4] = v0185;
    v0185 = stack[-4];
    if (v0185 == nil) goto v0164;
    v0185 = stack[-4];
    v0185 = qcar(v0185);
    v0186 = stack[-8];
    fn = elt(env, 7); // multsq
    v0185 = (*qfn2(fn))(qenv(fn), v0186, v0185);
    nil = C_nil;
    if (exception_pending()) goto v0187;
    env = stack[-10];
    v0186 = v0185;
    v0185 = qvalue(elt(env, 3)); // t
    stack[0] = qvalue(elt(env, 4)); // !*sub2
    qvalue(elt(env, 4)) = v0185; // !*sub2
    v0185 = v0186;
    fn = elt(env, 8); // subs2
    v0185 = (*qfn1(fn))(qenv(fn), v0185);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-10];
    v0186 = v0185;
    qvalue(elt(env, 4)) = stack[0]; // !*sub2
    v0185 = v0186;
    v0185 = ncons(v0185);
    nil = C_nil;
    if (exception_pending()) goto v0187;
    env = stack[-10];
    stack[-2] = v0185;
    stack[-3] = v0185;
    goto v0017;

v0017:
    v0185 = stack[-4];
    v0185 = qcdr(v0185);
    stack[-4] = v0185;
    v0185 = stack[-4];
    if (v0185 == nil) goto v0016;
    stack[-1] = stack[-2];
    v0185 = stack[-4];
    v0185 = qcar(v0185);
    v0186 = stack[-8];
    fn = elt(env, 7); // multsq
    v0185 = (*qfn2(fn))(qenv(fn), v0186, v0185);
    nil = C_nil;
    if (exception_pending()) goto v0187;
    env = stack[-10];
    v0186 = v0185;
    v0185 = qvalue(elt(env, 3)); // t
    stack[0] = qvalue(elt(env, 4)); // !*sub2
    qvalue(elt(env, 4)) = v0185; // !*sub2
    v0185 = v0186;
    fn = elt(env, 8); // subs2
    v0185 = (*qfn1(fn))(qenv(fn), v0185);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-10];
    v0186 = v0185;
    qvalue(elt(env, 4)) = stack[0]; // !*sub2
    v0185 = v0186;
    v0185 = ncons(v0185);
    nil = C_nil;
    if (exception_pending()) goto v0187;
    env = stack[-10];
    v0185 = Lrplacd(nil, stack[-1], v0185);
    nil = C_nil;
    if (exception_pending()) goto v0187;
    env = stack[-10];
    v0185 = stack[-2];
    v0185 = qcdr(v0185);
    stack[-2] = v0185;
    goto v0017;

v0016:
    v0185 = stack[-3];
    goto v0059;

v0059:
    v0185 = ncons(v0185);
    nil = C_nil;
    if (exception_pending()) goto v0187;
    env = stack[-10];
    stack[-6] = v0185;
    stack[-7] = v0185;
    goto v0122;

v0122:
    v0185 = stack[-9];
    v0185 = qcdr(v0185);
    stack[-9] = v0185;
    v0185 = stack[-9];
    if (v0185 == nil) { LispObject res = stack[-7]; popv(11); return onevalue(res); }
    stack[-5] = stack[-6];
    v0185 = stack[-9];
    v0185 = qcar(v0185);
    stack[-4] = v0185;
    v0185 = stack[-4];
    if (v0185 == nil) goto v0188;
    v0185 = stack[-4];
    v0185 = qcar(v0185);
    v0186 = stack[-8];
    fn = elt(env, 7); // multsq
    v0185 = (*qfn2(fn))(qenv(fn), v0186, v0185);
    nil = C_nil;
    if (exception_pending()) goto v0187;
    env = stack[-10];
    v0186 = v0185;
    v0185 = qvalue(elt(env, 3)); // t
    stack[0] = qvalue(elt(env, 4)); // !*sub2
    qvalue(elt(env, 4)) = v0185; // !*sub2
    v0185 = v0186;
    fn = elt(env, 8); // subs2
    v0185 = (*qfn1(fn))(qenv(fn), v0185);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-10];
    v0186 = v0185;
    qvalue(elt(env, 4)) = stack[0]; // !*sub2
    v0185 = v0186;
    v0185 = ncons(v0185);
    nil = C_nil;
    if (exception_pending()) goto v0187;
    env = stack[-10];
    stack[-2] = v0185;
    stack[-3] = v0185;
    goto v0146;

v0146:
    v0185 = stack[-4];
    v0185 = qcdr(v0185);
    stack[-4] = v0185;
    v0185 = stack[-4];
    if (v0185 == nil) goto v0157;
    stack[-1] = stack[-2];
    v0185 = stack[-4];
    v0185 = qcar(v0185);
    v0186 = stack[-8];
    fn = elt(env, 7); // multsq
    v0185 = (*qfn2(fn))(qenv(fn), v0186, v0185);
    nil = C_nil;
    if (exception_pending()) goto v0187;
    env = stack[-10];
    v0186 = v0185;
    v0185 = qvalue(elt(env, 3)); // t
    stack[0] = qvalue(elt(env, 4)); // !*sub2
    qvalue(elt(env, 4)) = v0185; // !*sub2
    v0185 = v0186;
    fn = elt(env, 8); // subs2
    v0185 = (*qfn1(fn))(qenv(fn), v0185);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-10];
    v0186 = v0185;
    qvalue(elt(env, 4)) = stack[0]; // !*sub2
    v0185 = v0186;
    v0185 = ncons(v0185);
    nil = C_nil;
    if (exception_pending()) goto v0187;
    env = stack[-10];
    v0185 = Lrplacd(nil, stack[-1], v0185);
    nil = C_nil;
    if (exception_pending()) goto v0187;
    env = stack[-10];
    v0185 = stack[-2];
    v0185 = qcdr(v0185);
    stack[-2] = v0185;
    goto v0146;

v0157:
    v0185 = stack[-3];
    goto v0145;

v0145:
    v0185 = ncons(v0185);
    nil = C_nil;
    if (exception_pending()) goto v0187;
    env = stack[-10];
    v0185 = Lrplacd(nil, stack[-5], v0185);
    nil = C_nil;
    if (exception_pending()) goto v0187;
    env = stack[-10];
    v0185 = stack[-6];
    v0185 = qcdr(v0185);
    stack[-6] = v0185;
    goto v0122;

v0188:
    v0185 = qvalue(elt(env, 2)); // nil
    goto v0145;

v0164:
    v0185 = qvalue(elt(env, 2)); // nil
    goto v0059;

v0085:
    v0185 = qvalue(elt(env, 2)); // nil
    { popv(11); return onevalue(v0185); }
// error exit handlers
v0189:
    env = stack[-10];
    qvalue(elt(env, 4)) = stack[0]; // !*sub2
    popv(11);
    return nil;
v0156:
    env = stack[-10];
    qvalue(elt(env, 4)) = stack[0]; // !*sub2
    popv(11);
    return nil;
v0154:
    env = stack[-10];
    qvalue(elt(env, 4)) = stack[0]; // !*sub2
    popv(11);
    return nil;
v0155:
    env = stack[-10];
    qvalue(elt(env, 4)) = stack[0]; // !*sub2
    popv(11);
    return nil;
v0187:
    popv(11);
    return nil;
}



// Code for degree!-order

static LispObject CC_degreeKorder(LispObject env,
                         LispObject v0000, LispObject v0070)
{
    LispObject nil = C_nil;
    LispObject v0083, v0075, v0076;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for degree-order");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0075 = v0070;
    v0076 = v0000;
// end of prologue
    v0083 = v0076;
    if (!consp(v0083)) goto v0002;
    v0083 = v0076;
    v0083 = qcar(v0083);
    v0083 = (consp(v0083) ? nil : lisp_true);
    goto v0001;

v0001:
    if (v0083 == nil) goto v0051;
    v0083 = qvalue(elt(env, 1)); // t
    return onevalue(v0083);

v0051:
    v0083 = v0075;
    if (!consp(v0083)) goto v0123;
    v0083 = v0075;
    v0083 = qcar(v0083);
    v0083 = (consp(v0083) ? nil : lisp_true);
    goto v0122;

v0122:
    if (v0083 == nil) goto v0124;
    v0083 = qvalue(elt(env, 2)); // nil
    return onevalue(v0083);

v0124:
    v0083 = v0076;
    v0083 = qcar(v0083);
    v0083 = qcar(v0083);
    v0083 = qcdr(v0083);
    v0075 = qcar(v0075);
    v0075 = qcar(v0075);
    v0075 = qcdr(v0075);
        return Llessp(nil, v0083, v0075);

v0123:
    v0083 = qvalue(elt(env, 1)); // t
    goto v0122;

v0002:
    v0083 = qvalue(elt(env, 1)); // t
    goto v0001;
}



// Code for fnom

static LispObject CC_fnom(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0164;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for fnom");
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
    v0164 = elt(env, 1); // "<OMA>"
    fn = elt(env, 13); // printout
    v0164 = (*qfn1(fn))(qenv(fn), v0164);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-1];
    v0164 = qvalue(elt(env, 2)); // t
    fn = elt(env, 14); // indent!*
    v0164 = (*qfn1(fn))(qenv(fn), v0164);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-1];
    v0164 = elt(env, 3); // "<OMATTR>"
    fn = elt(env, 13); // printout
    v0164 = (*qfn1(fn))(qenv(fn), v0164);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-1];
    v0164 = qvalue(elt(env, 2)); // t
    fn = elt(env, 14); // indent!*
    v0164 = (*qfn1(fn))(qenv(fn), v0164);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-1];
    v0164 = elt(env, 4); // "<OMATP>"
    fn = elt(env, 13); // printout
    v0164 = (*qfn1(fn))(qenv(fn), v0164);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-1];
    v0164 = qvalue(elt(env, 2)); // t
    fn = elt(env, 14); // indent!*
    v0164 = (*qfn1(fn))(qenv(fn), v0164);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-1];
    v0164 = elt(env, 5); // "<OMS cd=""typmml"" name=""type""/>"
    fn = elt(env, 13); // printout
    v0164 = (*qfn1(fn))(qenv(fn), v0164);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-1];
    v0164 = elt(env, 6); // "<OMS cd=""typmml"" name="""
    fn = elt(env, 13); // printout
    v0164 = (*qfn1(fn))(qenv(fn), v0164);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-1];
    v0164 = elt(env, 7); // "fn_type"
    v0164 = Lprinc(nil, v0164);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-1];
    v0164 = elt(env, 8); // """/>"
    v0164 = Lprinc(nil, v0164);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-1];
    v0164 = qvalue(elt(env, 9)); // nil
    fn = elt(env, 14); // indent!*
    v0164 = (*qfn1(fn))(qenv(fn), v0164);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-1];
    v0164 = elt(env, 10); // "</OMATP>"
    fn = elt(env, 13); // printout
    v0164 = (*qfn1(fn))(qenv(fn), v0164);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-1];
    v0164 = stack[0];
    v0164 = qcar(v0164);
    fn = elt(env, 15); // objectom
    v0164 = (*qfn1(fn))(qenv(fn), v0164);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-1];
    v0164 = qvalue(elt(env, 9)); // nil
    fn = elt(env, 14); // indent!*
    v0164 = (*qfn1(fn))(qenv(fn), v0164);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-1];
    v0164 = elt(env, 11); // "</OMATTR>"
    fn = elt(env, 13); // printout
    v0164 = (*qfn1(fn))(qenv(fn), v0164);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-1];
    v0164 = stack[0];
    v0164 = qcdr(v0164);
    v0164 = qcdr(v0164);
    fn = elt(env, 16); // multiom
    v0164 = (*qfn1(fn))(qenv(fn), v0164);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-1];
    v0164 = qvalue(elt(env, 9)); // nil
    fn = elt(env, 14); // indent!*
    v0164 = (*qfn1(fn))(qenv(fn), v0164);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-1];
    v0164 = elt(env, 12); // "</OMA>"
    fn = elt(env, 13); // printout
    v0164 = (*qfn1(fn))(qenv(fn), v0164);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    v0164 = nil;
    { popv(2); return onevalue(v0164); }
// error exit handlers
v0026:
    popv(2);
    return nil;
}



// Code for look_for_substitute

static LispObject CC_look_for_substitute(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0094, v0165, v0173;
    LispObject fn;
    LispObject v0008, v0070, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "look_for_substitute");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0070 = va_arg(aa, LispObject);
    v0008 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for look_for_substitute");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0008,v0070,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0070,v0008);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0008;
    stack[-1] = v0070;
    stack[-2] = v0000;
// end of prologue

v0125:
    v0094 = qvalue(elt(env, 1)); // !*nointsubst
    if (v0094 == nil) goto v0030;
    v0094 = qvalue(elt(env, 2)); // nil
    { popv(4); return onevalue(v0094); }

v0030:
    v0094 = stack[0];
    if (!consp(v0094)) goto v0171;
    v0173 = stack[-2];
    v0165 = stack[-1];
    v0094 = stack[0];
    fn = elt(env, 3); // look_for_exponential
    v0094 = (*qfnn(fn))(qenv(fn), 3, v0173, v0165, v0094);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-3];
    v0165 = v0094;
    if (!(v0094 == nil)) { popv(4); return onevalue(v0165); }
    v0173 = stack[-2];
    v0165 = stack[-1];
    v0094 = stack[0];
    fn = elt(env, 4); // look_for_rational
    v0094 = (*qfnn(fn))(qenv(fn), 3, v0173, v0165, v0094);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-3];
    v0165 = v0094;
    if (!(v0094 == nil)) { popv(4); return onevalue(v0165); }
    v0173 = stack[-2];
    v0165 = stack[-1];
    v0094 = stack[0];
    fn = elt(env, 5); // look_for_quad
    v0094 = (*qfnn(fn))(qenv(fn), 3, v0173, v0165, v0094);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-3];
    v0165 = v0094;
    if (!(v0094 == nil)) { popv(4); return onevalue(v0165); }
    v0173 = stack[-2];
    v0165 = stack[-1];
    v0094 = stack[0];
    v0094 = qcar(v0094);
    v0094 = CC_look_for_substitute(env, 3, v0173, v0165, v0094);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-3];
    v0165 = v0094;
    if (!(v0094 == nil)) { popv(4); return onevalue(v0165); }
    v0173 = stack[-2];
    v0165 = stack[-1];
    v0094 = stack[0];
    v0094 = qcdr(v0094);
    stack[-2] = v0173;
    stack[-1] = v0165;
    stack[0] = v0094;
    goto v0125;

v0171:
    v0094 = qvalue(elt(env, 2)); // nil
    { popv(4); return onevalue(v0094); }
// error exit handlers
v0050:
    popv(4);
    return nil;
}



// Code for aceq

static LispObject CC_aceq(LispObject env,
                         LispObject v0000, LispObject v0070)
{
    LispObject nil = C_nil;
    LispObject v0163, v0026, v0024, v0071;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for aceq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0070,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0070);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0026 = v0070;
    v0024 = v0000;
// end of prologue

v0051:
    v0163 = v0024;
    if (v0163 == nil) goto v0002;
    v0163 = v0026;
    if (v0163 == nil) goto v0005;
    v0163 = v0024;
    v0071 = qcar(v0163);
    v0163 = v0026;
    v0163 = Lmember(nil, v0071, v0163);
    if (v0163 == nil) goto v0081;
    v0163 = v0024;
    v0163 = qcdr(v0163);
    stack[0] = v0163;
    v0163 = v0024;
    v0163 = qcar(v0163);
    v0163 = Ldelete(nil, v0163, v0026);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-1];
    v0026 = v0163;
    v0163 = stack[0];
    v0024 = v0163;
    goto v0051;

v0081:
    v0163 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0163); }

v0005:
    v0163 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0163); }

v0002:
    v0163 = v0026;
    v0163 = (v0163 == nil ? lisp_true : nil);
    { popv(2); return onevalue(v0163); }
// error exit handlers
v0083:
    popv(2);
    return nil;
}



// Code for xremf

static LispObject CC_xremf(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0226, v0227, v0228;
    LispObject fn;
    LispObject v0008, v0070, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "xremf");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0070 = va_arg(aa, LispObject);
    v0008 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for xremf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0008,v0070,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0070,v0008);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-5] = v0008;
    stack[-6] = v0070;
    stack[-7] = v0000;
// end of prologue
    stack[-1] = nil;
    v0226 = (LispObject)1; // 0
    stack[-8] = v0226;
    v0226 = stack[-6];
    if (!consp(v0226)) goto v0122;
    v0226 = stack[-6];
    v0226 = qcar(v0226);
    v0226 = (consp(v0226) ? nil : lisp_true);
    goto v0023;

v0023:
    if (v0226 == nil) goto v0171;
    v0227 = stack[-7];
    v0226 = stack[-6];
    fn = elt(env, 3); // qremd
    v0226 = (*qfn2(fn))(qenv(fn), v0227, v0226);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    v0226 = qcdr(v0226);
    popv(10);
    return ncons(v0226);

v0171:
    v0226 = stack[-7];
    fn = elt(env, 4); // termsf
    v0226 = (*qfn1(fn))(qenv(fn), v0226);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    env = stack[-9];
    stack[0] = v0226;
    goto v0134;

v0134:
    v0227 = stack[-5];
    v0226 = (LispObject)1; // 0
    v0226 = (LispObject)lesseq2(v0227, v0226);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    v0226 = v0226 ? lisp_true : nil;
    env = stack[-9];
    if (v0226 == nil) goto v0024;
    v0226 = qvalue(elt(env, 2)); // nil
    { popv(10); return onevalue(v0226); }

v0024:
    v0226 = stack[-7];
    if (!consp(v0226)) goto v0082;
    v0226 = stack[-7];
    v0226 = qcar(v0226);
    v0226 = (consp(v0226) ? nil : lisp_true);
    goto v0053;

v0053:
    if (v0226 == nil) goto v0104;
    v0227 = stack[-1];
    v0226 = stack[-7];
    fn = elt(env, 5); // addf
    v0226 = (*qfn2(fn))(qenv(fn), v0227, v0226);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    popv(10);
    return ncons(v0226);

v0104:
    v0226 = stack[-7];
    v0226 = qcar(v0226);
    v0226 = qcar(v0226);
    v0227 = qcar(v0226);
    v0226 = stack[-6];
    v0226 = qcar(v0226);
    v0226 = qcar(v0226);
    v0226 = qcar(v0226);
    if (v0227 == v0226) goto v0131;
    v0226 = stack[-7];
    v0226 = qcar(v0226);
    v0226 = qcar(v0226);
    v0227 = qcar(v0226);
    v0226 = stack[-6];
    v0226 = qcar(v0226);
    v0226 = qcar(v0226);
    v0226 = qcar(v0226);
    fn = elt(env, 6); // ordop
    v0226 = (*qfn2(fn))(qenv(fn), v0227, v0226);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    env = stack[-9];
    if (v0226 == nil) goto v0230;
    v0227 = stack[-5];
    v0226 = stack[-8];
    v0226 = plus2(v0227, v0226);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    env = stack[-9];
    stack[-5] = v0226;
    v0226 = stack[-7];
    v0226 = qcar(v0226);
    v0228 = qcdr(v0226);
    v0227 = stack[-6];
    v0226 = stack[-5];
    v0226 = CC_xremf(env, 3, v0228, v0227, v0226);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    env = stack[-9];
    stack[-3] = v0226;
    v0226 = stack[-3];
    if (v0226 == nil) goto v0231;
    v0226 = stack[-7];
    v0226 = qcar(v0226);
    v0227 = qcar(v0226);
    v0226 = (LispObject)17; // 1
    v0226 = cons(v0227, v0226);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    env = stack[-9];
    v0227 = ncons(v0226);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    env = stack[-9];
    v0226 = stack[-3];
    v0226 = qcar(v0226);
    fn = elt(env, 7); // multf
    v0226 = (*qfn2(fn))(qenv(fn), v0227, v0226);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    env = stack[-9];
    fn = elt(env, 5); // addf
    v0226 = (*qfn2(fn))(qenv(fn), stack[-1], v0226);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    env = stack[-9];
    stack[-1] = v0226;
    v0226 = stack[-1];
    fn = elt(env, 4); // termsf
    v0226 = (*qfn1(fn))(qenv(fn), v0226);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    env = stack[-9];
    stack[-8] = v0226;
    v0227 = stack[-5];
    v0226 = stack[-8];
    v0226 = difference2(v0227, v0226);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    env = stack[-9];
    stack[-5] = v0226;
    v0226 = stack[-7];
    v0226 = qcdr(v0226);
    stack[-7] = v0226;
    goto v0134;

v0231:
    v0226 = qvalue(elt(env, 2)); // nil
    { popv(10); return onevalue(v0226); }

v0230:
    v0227 = stack[-1];
    v0226 = stack[-7];
    fn = elt(env, 5); // addf
    v0226 = (*qfn2(fn))(qenv(fn), v0227, v0226);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    popv(10);
    return ncons(v0226);

v0131:
    v0226 = stack[-7];
    v0226 = qcar(v0226);
    v0226 = qcar(v0226);
    v0227 = qcdr(v0226);
    v0226 = stack[-6];
    v0226 = qcar(v0226);
    v0226 = qcar(v0226);
    v0226 = qcdr(v0226);
    v0227 = difference2(v0227, v0226);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    env = stack[-9];
    stack[-4] = v0227;
    v0226 = (LispObject)1; // 0
    v0226 = (LispObject)lessp2(v0227, v0226);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    v0226 = v0226 ? lisp_true : nil;
    env = stack[-9];
    if (v0226 == nil) goto v0128;
    v0227 = stack[-1];
    v0226 = stack[-7];
    fn = elt(env, 5); // addf
    v0226 = (*qfn2(fn))(qenv(fn), v0227, v0226);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    popv(10);
    return ncons(v0226);

v0128:
    v0226 = stack[-7];
    v0226 = qcar(v0226);
    v0227 = qcdr(v0226);
    v0226 = stack[-6];
    v0226 = qcar(v0226);
    v0226 = qcdr(v0226);
    fn = elt(env, 8); // qremf
    v0226 = (*qfn2(fn))(qenv(fn), v0227, v0226);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    env = stack[-9];
    stack[-3] = v0226;
    v0226 = stack[-7];
    v0226 = qcar(v0226);
    v0227 = qcar(v0226);
    v0226 = (LispObject)17; // 1
    v0226 = cons(v0227, v0226);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    env = stack[-9];
    v0227 = ncons(v0226);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    env = stack[-9];
    v0226 = stack[-3];
    v0226 = qcdr(v0226);
    fn = elt(env, 7); // multf
    v0226 = (*qfn2(fn))(qenv(fn), v0227, v0226);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    env = stack[-9];
    stack[-2] = v0226;
    v0227 = stack[-5];
    v0226 = stack[-8];
    v0226 = plus2(v0227, v0226);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    env = stack[-9];
    stack[-5] = v0226;
    v0227 = stack[-1];
    v0226 = stack[-2];
    fn = elt(env, 5); // addf
    v0226 = (*qfn2(fn))(qenv(fn), v0227, v0226);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    env = stack[-9];
    stack[-1] = v0226;
    v0226 = stack[-1];
    fn = elt(env, 4); // termsf
    v0226 = (*qfn1(fn))(qenv(fn), v0226);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    env = stack[-9];
    stack[-8] = v0226;
    v0227 = stack[-5];
    v0226 = stack[-8];
    v0227 = difference2(v0227, v0226);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    env = stack[-9];
    v0226 = stack[0];
    v0226 = plus2(v0227, v0226);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    env = stack[-9];
    stack[-5] = v0226;
    v0226 = stack[-3];
    v0226 = qcar(v0226);
    if (v0226 == nil) goto v0232;
    stack[0] = stack[-7];
    v0227 = stack[-4];
    v0226 = (LispObject)1; // 0
    if (v0227 == v0226) goto v0233;
    v0226 = stack[-7];
    v0226 = qcar(v0226);
    v0226 = qcar(v0226);
    v0227 = qcar(v0226);
    v0226 = stack[-4];
    fn = elt(env, 9); // to
    v0227 = (*qfn2(fn))(qenv(fn), v0227, v0226);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    env = stack[-9];
    v0226 = (LispObject)17; // 1
    v0226 = cons(v0227, v0226);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    env = stack[-9];
    v0227 = ncons(v0226);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    env = stack[-9];
    v0226 = stack[-6];
    fn = elt(env, 7); // multf
    v0226 = (*qfn2(fn))(qenv(fn), v0227, v0226);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    env = stack[-9];
    stack[-4] = v0226;
    goto v0234;

v0234:
    v0226 = stack[-3];
    v0226 = qcar(v0226);
    fn = elt(env, 10); // negf
    v0226 = (*qfn1(fn))(qenv(fn), v0226);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    env = stack[-9];
    fn = elt(env, 7); // multf
    v0226 = (*qfn2(fn))(qenv(fn), stack[-4], v0226);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    env = stack[-9];
    fn = elt(env, 5); // addf
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v0226);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    env = stack[-9];
    v0226 = stack[-2];
    fn = elt(env, 10); // negf
    v0226 = (*qfn1(fn))(qenv(fn), v0226);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    env = stack[-9];
    fn = elt(env, 5); // addf
    v0226 = (*qfn2(fn))(qenv(fn), stack[0], v0226);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    env = stack[-9];
    goto v0235;

v0235:
    stack[-7] = v0226;
    v0226 = stack[-7];
    fn = elt(env, 4); // termsf
    v0226 = (*qfn1(fn))(qenv(fn), v0226);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    env = stack[-9];
    stack[0] = v0226;
    v0227 = stack[-5];
    v0226 = stack[0];
    v0226 = difference2(v0227, v0226);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    env = stack[-9];
    stack[-5] = v0226;
    goto v0134;

v0233:
    v0226 = stack[-6];
    stack[-4] = v0226;
    goto v0234;

v0232:
    v0226 = stack[-7];
    v0226 = qcdr(v0226);
    goto v0235;

v0082:
    v0226 = qvalue(elt(env, 1)); // t
    goto v0053;

v0122:
    v0226 = qvalue(elt(env, 1)); // t
    goto v0023;
// error exit handlers
v0229:
    popv(10);
    return nil;
}



// Code for solvealgdepends

static LispObject CC_solvealgdepends(LispObject env,
                         LispObject v0000, LispObject v0070)
{
    LispObject nil = C_nil;
    LispObject v0236, v0052;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for solvealgdepends");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0070,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0070);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0070;
    stack[-1] = v0000;
// end of prologue

v0003:
    v0052 = stack[-1];
    v0236 = stack[0];
    if (equal(v0052, v0236)) goto v0002;
    v0236 = stack[-1];
    if (!consp(v0236)) goto v0074;
    v0052 = stack[-1];
    v0236 = elt(env, 3); // root_of
    if (!consp(v0052)) goto v0082;
    v0052 = qcar(v0052);
    if (!(v0052 == v0236)) goto v0082;
    v0052 = stack[0];
    v0236 = stack[-1];
    v0236 = qcdr(v0236);
    v0236 = qcdr(v0236);
    v0236 = qcar(v0236);
    if (equal(v0052, v0236)) goto v0080;
    v0236 = stack[-1];
    v0236 = qcdr(v0236);
    v0236 = qcar(v0236);
    stack[-1] = v0236;
    goto v0003;

v0080:
    v0236 = qvalue(elt(env, 2)); // nil
    { popv(3); return onevalue(v0236); }

v0082:
    v0236 = stack[-1];
    v0052 = qcar(v0236);
    v0236 = stack[0];
    v0236 = CC_solvealgdepends(env, v0052, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0130;
    env = stack[-2];
    v0052 = v0236;
    if (!(v0236 == nil)) { popv(3); return onevalue(v0052); }
    v0236 = stack[-1];
    v0052 = qcdr(v0236);
    v0236 = stack[0];
    v0236 = CC_solvealgdepends(env, v0052, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0130;
    env = stack[-2];
    v0052 = v0236;
    if (!(v0236 == nil)) { popv(3); return onevalue(v0052); }
    v0236 = qvalue(elt(env, 2)); // nil
    { popv(3); return onevalue(v0236); }

v0074:
    v0236 = qvalue(elt(env, 2)); // nil
    { popv(3); return onevalue(v0236); }

v0002:
    v0236 = qvalue(elt(env, 1)); // t
    { popv(3); return onevalue(v0236); }
// error exit handlers
v0130:
    popv(3);
    return nil;
}



// Code for bfrsq

static LispObject CC_bfrsq(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0053, v0082;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for bfrsq");
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
    v0082 = v0000;
// end of prologue
    v0053 = v0082;
    v0053 = qcar(v0053);
    v0082 = qcdr(v0082);
    stack[-1] = v0082;
    v0082 = v0053;
    if (!consp(v0082)) goto v0078;
    v0082 = v0053;
    fn = elt(env, 1); // csl_timbf
    stack[0] = (*qfn2(fn))(qenv(fn), v0082, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    env = stack[-2];
    v0082 = stack[-1];
    v0053 = stack[-1];
    fn = elt(env, 1); // csl_timbf
    v0053 = (*qfn2(fn))(qenv(fn), v0082, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    env = stack[-2];
    {
        LispObject v0170 = stack[0];
        popv(3);
        fn = elt(env, 2); // plubf
        return (*qfn2(fn))(qenv(fn), v0170, v0053);
    }

v0078:
    v0082 = v0053;
    stack[0] = times2(v0082, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    env = stack[-2];
    v0082 = stack[-1];
    v0053 = stack[-1];
    v0053 = times2(v0082, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    {
        LispObject v0161 = stack[0];
        popv(3);
        return plus2(v0161, v0053);
    }
// error exit handlers
v0015:
    popv(3);
    return nil;
}



// Code for oddext

static LispObject CC_oddext(LispObject env,
                         LispObject v0070)
{
    LispObject nil = C_nil;
    LispObject v0027, v0176;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for oddext");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0070);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0070);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    v0027 = v0070;
// end of prologue
    stack[-2] = qvalue(elt(env, 1)); // odd_var
    qvalue(elt(env, 1)) = nil; // odd_var
    qvalue(elt(env, 1)) = v0027; // odd_var
    v0176 = qvalue(elt(env, 1)); // odd_var
    v0027 = qvalue(elt(env, 2)); // all_parametric_odd!*
    v0027 = Lmember(nil, v0176, v0027);
    if (v0027 == nil) goto v0124;
    stack[0] = elt(env, 3); // ext
    v0176 = qvalue(elt(env, 1)); // odd_var
    v0027 = qvalue(elt(env, 2)); // all_parametric_odd!*
    fn = elt(env, 7); // cde_position
    v0027 = (*qfn2(fn))(qenv(fn), v0176, v0027);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[-3];
    v0027 = list2(stack[0], v0027);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[-3];
    goto v0019;

v0019:
    qvalue(elt(env, 1)) = stack[-2]; // odd_var
    { popv(4); return onevalue(v0027); }

v0124:
    v0176 = qvalue(elt(env, 1)); // odd_var
    v0027 = qvalue(elt(env, 4)); // all_principal_odd!*
    v0027 = Lmember(nil, v0176, v0027);
    if (v0027 == nil) goto v0086;
    stack[-1] = elt(env, 3); // ext
    stack[0] = qvalue(elt(env, 5)); // n_all_parametric_ext
    v0176 = qvalue(elt(env, 1)); // odd_var
    v0027 = qvalue(elt(env, 4)); // all_principal_odd!*
    fn = elt(env, 7); // cde_position
    v0027 = (*qfn2(fn))(qenv(fn), v0176, v0027);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[-3];
    v0027 = plus2(stack[0], v0027);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[-3];
    v0027 = list2(stack[-1], v0027);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[-3];
    goto v0019;

v0086:
    v0027 = elt(env, 6); // "the argument of oddext must be an odd variable"
    fn = elt(env, 8); // rederr
    v0027 = (*qfn1(fn))(qenv(fn), v0027);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[-3];
    goto v0019;
// error exit handlers
v0174:
    env = stack[-3];
    qvalue(elt(env, 1)) = stack[-2]; // odd_var
    popv(4);
    return nil;
}



// Code for ra_intequiv

static LispObject CC_ra_intequiv(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0003;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ra_intequiv");
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
    v0003 = v0000;
// end of prologue
    stack[0] = elt(env, 1); // ra_intequiv0
    v0003 = ncons(v0003);
    nil = C_nil;
    if (exception_pending()) goto v0004;
    env = stack[-1];
    {
        LispObject v0005 = stack[0];
        popv(2);
        fn = elt(env, 2); // ra_wrapper
        return (*qfn2(fn))(qenv(fn), v0005, v0003);
    }
// error exit handlers
v0004:
    popv(2);
    return nil;
}



// Code for factor!-prim!-f

static LispObject CC_factorKprimKf(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0243, v0244, v0245;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for factor-prim-f");
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
    v0243 = qvalue(elt(env, 1)); // ncmp!*
    if (v0243 == nil) goto v0002;
    stack[0] = (LispObject)17; // 1
    v0244 = stack[-2];
    v0243 = (LispObject)17; // 1
    v0243 = cons(v0244, v0243);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    {
        LispObject v0246 = stack[0];
        popv(5);
        return list2(v0246, v0243);
    }

v0002:
    v0243 = qvalue(elt(env, 2)); // dmode!*
    if (v0243 == nil) goto v0056;
    v0244 = qvalue(elt(env, 2)); // dmode!*
    v0243 = elt(env, 3); // sqfrfactorfn
    v0243 = get(v0244, v0243);
    env = stack[-4];
    stack[-1] = v0243;
    if (v0243 == nil) goto v0056;
    v0243 = qvalue(elt(env, 4)); // !*factor
    if (v0243 == nil) goto v0053;
    v0244 = stack[-1];
    v0243 = stack[-2];
    v0243 = Lapply1(nil, v0244, v0243);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-4];
    stack[0] = v0243;
    goto v0072;

v0072:
    v0243 = stack[-1];
    if (v0243 == nil) goto v0247;
    v0245 = stack[-1];
    v0244 = qvalue(elt(env, 2)); // dmode!*
    v0243 = elt(env, 6); // factorfn
    v0243 = get(v0244, v0243);
    env = stack[-4];
    if (v0245 == v0243) { LispObject res = stack[0]; popv(5); return onevalue(res); }
    else goto v0247;

v0247:
    v0243 = stack[0];
    v0243 = qcar(v0243);
    v0243 = ncons(v0243);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-4];
    stack[-3] = v0243;
    v0243 = stack[0];
    v0243 = qcdr(v0243);
    stack[0] = v0243;
    goto v0248;

v0248:
    v0243 = stack[0];
    if (v0243 == nil) { LispObject res = stack[-3]; popv(5); return onevalue(res); }
    v0243 = stack[0];
    v0243 = qcar(v0243);
    fn = elt(env, 7); // factor!-prim!-sqfree!-f
    v0244 = (*qfn1(fn))(qenv(fn), v0243);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-4];
    v0243 = stack[-3];
    fn = elt(env, 8); // fac!-merge
    v0243 = (*qfn2(fn))(qenv(fn), v0244, v0243);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-4];
    stack[-3] = v0243;
    v0243 = stack[0];
    v0243 = qcdr(v0243);
    stack[0] = v0243;
    goto v0248;

v0053:
    stack[0] = (LispObject)17; // 1
    v0244 = stack[-2];
    v0243 = (LispObject)17; // 1
    v0243 = cons(v0244, v0243);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-4];
    v0243 = list2(stack[0], v0243);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-4];
    stack[0] = v0243;
    goto v0072;

v0056:
    v0243 = qvalue(elt(env, 2)); // dmode!*
    if (!symbolp(v0243)) v0243 = nil;
    else { v0243 = qfastgets(v0243);
           if (v0243 != nil) { v0243 = elt(v0243, 3); // field
#ifdef RECORD_GET
             if (v0243 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v0243 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v0243 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v0243 == SPID_NOPROP) v0243 = nil; else v0243 = lisp_true; }}
#endif
    if (v0243 == nil) goto v0102;
    v0243 = stack[-2];
    fn = elt(env, 9); // lnc
    v0244 = (*qfn1(fn))(qenv(fn), v0243);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-4];
    stack[-3] = v0244;
    v0243 = (LispObject)17; // 1
    v0243 = Lneq(nil, v0244, v0243);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-4];
    goto v0013;

v0013:
    if (v0243 == nil) goto v0088;
    stack[0] = stack[-3];
    v0243 = stack[-3];
    fn = elt(env, 10); // !:recip
    v0244 = (*qfn1(fn))(qenv(fn), v0243);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-4];
    v0243 = stack[-2];
    fn = elt(env, 11); // multd
    v0243 = (*qfn2(fn))(qenv(fn), v0244, v0243);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-4];
    fn = elt(env, 12); // sqfrf
    v0243 = (*qfn1(fn))(qenv(fn), v0243);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-4];
    v0243 = cons(stack[0], v0243);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-4];
    stack[0] = v0243;
    goto v0072;

v0088:
    v0243 = qvalue(elt(env, 2)); // dmode!*
    if (!symbolp(v0243)) v0243 = nil;
    else { v0243 = qfastgets(v0243);
           if (v0243 != nil) { v0243 = elt(v0243, 27); // units
#ifdef RECORD_GET
             if (v0243 != SPID_NOPROP)
                record_get(elt(fastget_names, 27), 1);
             else record_get(elt(fastget_names, 27), 0),
                v0243 = nil; }
           else record_get(elt(fastget_names, 27), 0); }
#else
             if (v0243 == SPID_NOPROP) v0243 = nil; }}
#endif
    stack[-3] = v0243;
    if (v0243 == nil) goto v0144;
    v0243 = stack[-2];
    fn = elt(env, 9); // lnc
    v0244 = (*qfn1(fn))(qenv(fn), v0243);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-4];
    v0245 = v0244;
    v0243 = stack[-3];
    v0243 = Lassoc(nil, v0244, v0243);
    stack[-3] = v0243;
    if (v0243 == nil) goto v0144;
    stack[0] = v0245;
    v0243 = stack[-3];
    v0244 = qcdr(v0243);
    v0243 = stack[-2];
    fn = elt(env, 11); // multd
    v0243 = (*qfn2(fn))(qenv(fn), v0244, v0243);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-4];
    fn = elt(env, 12); // sqfrf
    v0243 = (*qfn1(fn))(qenv(fn), v0243);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-4];
    v0243 = cons(stack[0], v0243);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-4];
    stack[0] = v0243;
    goto v0072;

v0144:
    stack[0] = (LispObject)17; // 1
    v0243 = stack[-2];
    fn = elt(env, 12); // sqfrf
    v0243 = (*qfn1(fn))(qenv(fn), v0243);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-4];
    v0243 = cons(stack[0], v0243);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-4];
    stack[0] = v0243;
    goto v0072;

v0102:
    v0243 = qvalue(elt(env, 5)); // nil
    goto v0013;
// error exit handlers
v0169:
    popv(5);
    return nil;
}



// Code for ofsf_updsignvar

static LispObject CC_ofsf_updsignvar(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0162, v0104, v0105, v0139, v0150, v0236, v0052, v0029;
    LispObject v0051, v0019, v0057, v0060, v0008, v0070, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 7, "ofsf_updsignvar");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0070 = va_arg(aa, LispObject);
    v0008 = va_arg(aa, LispObject);
    v0060 = va_arg(aa, LispObject);
    v0057 = va_arg(aa, LispObject);
    v0019 = va_arg(aa, LispObject);
    v0051 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_updsignvar");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0105 = v0051;
    v0139 = v0019;
    v0150 = v0057;
    v0236 = v0060;
    v0052 = v0008;
    v0162 = v0070;
    v0029 = v0000;
// end of prologue
    v0104 = v0029;
    v0162 = Lmemq(nil, v0104, v0162);
    if (v0162 == nil) goto v0123;
    v0162 = elt(env, 1); // equal
    return onevalue(v0162);

v0123:
    v0162 = v0029;
    v0104 = v0052;
    v0162 = Lmemq(nil, v0162, v0104);
    if (v0162 == nil) goto v0079;
    v0162 = elt(env, 2); // greaterp
    return onevalue(v0162);

v0079:
    v0162 = v0029;
    v0104 = v0236;
    v0162 = Lmemq(nil, v0162, v0104);
    if (v0162 == nil) goto v0026;
    v0162 = elt(env, 3); // lessp
    return onevalue(v0162);

v0026:
    v0162 = v0029;
    v0104 = v0150;
    v0162 = Lmemq(nil, v0162, v0104);
    if (v0162 == nil) goto v0092;
    v0162 = elt(env, 4); // geq
    return onevalue(v0162);

v0092:
    v0162 = v0029;
    v0104 = v0139;
    v0162 = Lmemq(nil, v0162, v0104);
    if (v0162 == nil) goto v0087;
    v0162 = elt(env, 5); // leq
    return onevalue(v0162);

v0087:
    v0162 = v0029;
    v0104 = v0105;
    v0162 = Lmemq(nil, v0162, v0104);
    if (v0162 == nil) goto v0013;
    v0162 = elt(env, 6); // neq
    return onevalue(v0162);

v0013:
    v0162 = elt(env, 7); // unknown
    return onevalue(v0162);
}



// Code for make!-modular!-symmetric

static LispObject CC_makeKmodularKsymmetric(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0014, v0184, v0162;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for make-modular-symmetric");
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
    v0014 = stack[0];
    if (v0014 == nil) goto v0057;
    v0014 = stack[0];
    if (!consp(v0014)) goto v0031;
    v0014 = stack[0];
    v0014 = qcar(v0014);
    v0014 = (consp(v0014) ? nil : lisp_true);
    goto v0003;

v0003:
    if (v0014 == nil) goto v0026;
    v0184 = stack[0];
    v0014 = qvalue(elt(env, 3)); // modulus!/2
    v0014 = (LispObject)greaterp2(v0184, v0014);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    v0014 = v0014 ? lisp_true : nil;
    env = stack[-2];
    if (v0014 == nil) { LispObject res = stack[0]; popv(3); return onevalue(res); }
    v0184 = stack[0];
    v0014 = qvalue(elt(env, 4)); // current!-modulus
    v0014 = difference2(v0184, v0014);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 5); // !*n2f
        return (*qfn1(fn))(qenv(fn), v0014);
    }

v0026:
    v0014 = stack[0];
    v0014 = qcar(v0014);
    v0014 = qcdr(v0014);
    stack[-1] = CC_makeKmodularKsymmetric(env, v0014);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-2];
    v0014 = stack[0];
    v0014 = qcdr(v0014);
    v0014 = CC_makeKmodularKsymmetric(env, v0014);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    v0184 = stack[-1];
    v0162 = v0184;
    if (v0162 == nil) { popv(3); return onevalue(v0014); }
    v0162 = stack[0];
    v0162 = qcar(v0162);
    v0162 = qcar(v0162);
    popv(3);
    return acons(v0162, v0184, v0014);

v0031:
    v0014 = qvalue(elt(env, 2)); // t
    goto v0003;

v0057:
    v0014 = qvalue(elt(env, 1)); // nil
    { popv(3); return onevalue(v0014); }
// error exit handlers
v0139:
    popv(3);
    return nil;
}



// Code for vectorrd

static LispObject CC_vectorrd(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0120, v0171;
    LispObject fn;
    argcheck(nargs, 0, "vectorrd");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vectorrd");
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
// end of prologue
    fn = elt(env, 3); // matrixrowrd
    v0120 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0011;
    env = stack[0];
    v0171 = elt(env, 2); // mat
    v0120 = list2(v0171, v0120);
    nil = C_nil;
    if (exception_pending()) goto v0011;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 4); // aeval
        return (*qfn1(fn))(qenv(fn), v0120);
    }
// error exit handlers
v0011:
    popv(1);
    return nil;
}



// Code for genexp

static LispObject CC_genexp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0078;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for genexp");
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

v0125:
    v0078 = stack[0];
    if (!consp(v0078)) goto v0057;
    v0078 = stack[0];
    v0078 = qcar(v0078);
    v0078 = CC_genexp(env, v0078);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-1];
    if (!(v0078 == nil)) { popv(2); return onevalue(v0078); }
    v0078 = stack[0];
    v0078 = qcdr(v0078);
    stack[0] = v0078;
    goto v0125;

v0057:
    v0078 = stack[0];
    {
        popv(2);
        fn = elt(env, 1); // genp
        return (*qfn1(fn))(qenv(fn), v0078);
    }
// error exit handlers
v0122:
    popv(2);
    return nil;
}



// Code for simp_without_resimp

static LispObject CC_simp_without_resimp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0051, v0022;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for simp_without_resimp");
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
    v0022 = v0000;
// end of prologue
    v0051 = qvalue(elt(env, 1)); // nil
    stack[0] = qvalue(elt(env, 2)); // !*resimp
    qvalue(elt(env, 2)) = v0051; // !*resimp
    v0051 = v0022;
    fn = elt(env, 3); // simp
    v0051 = (*qfn1(fn))(qenv(fn), v0051);
    nil = C_nil;
    if (exception_pending()) goto v0002;
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; // !*resimp
    { popv(2); return onevalue(v0051); }
// error exit handlers
v0002:
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; // !*resimp
    popv(2);
    return nil;
}



// Code for sc_columnscalarproduct

static LispObject CC_sc_columnscalarproduct(LispObject env,
                         LispObject v0000, LispObject v0070)
{
    LispObject nil = C_nil;
    LispObject v0086, v0087, v0016;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sc_columnscalarproduct");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0070,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0070);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-2] = v0070;
    stack[-3] = v0000;
// end of prologue
    v0086 = (LispObject)1; // 0
    fn = elt(env, 2); // sc_simp
    v0086 = (*qfn1(fn))(qenv(fn), v0086);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-5];
    stack[0] = v0086;
    v0086 = (LispObject)17; // 1
    stack[-4] = v0086;
    goto v0074;

v0074:
    v0086 = stack[-3];
    fn = elt(env, 3); // fast!-row!-dim
    v0087 = (*qfn1(fn))(qenv(fn), v0086);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-5];
    v0086 = stack[-4];
    v0086 = difference2(v0087, v0086);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-5];
    v0086 = Lminusp(nil, v0086);
    env = stack[-5];
    if (!(v0086 == nil)) { LispObject res = stack[0]; popv(6); return onevalue(res); }
    stack[-1] = stack[0];
    v0016 = stack[-3];
    v0087 = stack[-4];
    v0086 = (LispObject)17; // 1
    fn = elt(env, 4); // sc_getmat
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v0016, v0087, v0086);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-5];
    v0016 = stack[-2];
    v0087 = stack[-4];
    v0086 = (LispObject)17; // 1
    fn = elt(env, 4); // sc_getmat
    v0086 = (*qfnn(fn))(qenv(fn), 3, v0016, v0087, v0086);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-5];
    fn = elt(env, 5); // sc_multsq
    v0086 = (*qfn2(fn))(qenv(fn), stack[0], v0086);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-5];
    fn = elt(env, 6); // sc_addsq
    v0086 = (*qfn2(fn))(qenv(fn), stack[-1], v0086);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-5];
    stack[0] = v0086;
    v0086 = stack[-4];
    v0086 = add1(v0086);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-5];
    stack[-4] = v0086;
    goto v0074;
// error exit handlers
v0088:
    popv(6);
    return nil;
}



// Code for simpunion

static LispObject CC_simpunion(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0174, v0013, v0014;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for simpunion");
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
    v0174 = v0000;
// end of prologue
    v0013 = elt(env, 1); // union
    fn = elt(env, 3); // applysetop
    v0174 = (*qfn2(fn))(qenv(fn), v0013, v0174);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-1];
    v0014 = v0174;
    v0174 = v0014;
    v0013 = qcar(v0174);
    v0174 = elt(env, 1); // union
    if (v0013 == v0174) goto v0071;
    v0174 = v0014;
    v0013 = v0174;
    goto v0121;

v0121:
    v0174 = (LispObject)17; // 1
    fn = elt(env, 4); // mksp
    v0013 = (*qfn2(fn))(qenv(fn), v0013, v0174);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-1];
    v0174 = (LispObject)17; // 1
    v0174 = cons(v0013, v0174);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-1];
    v0013 = ncons(v0174);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    v0174 = (LispObject)17; // 1
    popv(2);
    return cons(v0013, v0174);

v0071:
    v0174 = qvalue(elt(env, 2)); // empty_set
    v0013 = v0014;
    v0013 = qcdr(v0013);
    v0174 = Ldelete(nil, v0174, v0013);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-1];
    v0014 = v0174;
    v0174 = qcdr(v0174);
    if (v0174 == nil) goto v0161;
    stack[0] = elt(env, 1); // union
    v0174 = v0014;
    fn = elt(env, 5); // ordn
    v0174 = (*qfn1(fn))(qenv(fn), v0174);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-1];
    v0174 = cons(stack[0], v0174);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-1];
    goto v0164;

v0164:
    v0013 = v0174;
    goto v0121;

v0161:
    v0174 = v0014;
    v0174 = qcar(v0174);
    goto v0164;
// error exit handlers
v0162:
    popv(2);
    return nil;
}



// Code for gfplus

static LispObject CC_gfplus(LispObject env,
                         LispObject v0000, LispObject v0070)
{
    LispObject nil = C_nil;
    LispObject v0121, v0135, v0072;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gfplus");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0135 = v0070;
    v0072 = v0000;
// end of prologue
    v0121 = v0072;
    v0121 = qcar(v0121);
    if (!consp(v0121)) goto v0030;
    v0121 = v0072;
    {
        fn = elt(env, 1); // gbfplus
        return (*qfn2(fn))(qenv(fn), v0121, v0135);
    }

v0030:
    v0121 = v0072;
    {
        fn = elt(env, 2); // gffplus
        return (*qfn2(fn))(qenv(fn), v0121, v0135);
    }
}



// Code for getupper

static LispObject CC_getupper(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0003, v0031;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for getupper");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0003 = v0000;
// end of prologue
    v0031 = qvalue(elt(env, 1)); // metricu!*
    v0003 = Latsoc(nil, v0003, v0031);
    v0003 = qcdr(v0003);
    return onevalue(v0003);
}



// Code for s_world_names

static LispObject CC_s_world_names(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0026;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for s_world_names");
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
    v0026 = v0000;
// end of prologue
    v0026 = qcar(v0026);
    stack[-3] = v0026;
    v0026 = stack[-3];
    if (v0026 == nil) goto v0031;
    v0026 = stack[-3];
    v0026 = qcar(v0026);
    v0026 = qcar(v0026);
    v0026 = ncons(v0026);
    nil = C_nil;
    if (exception_pending()) goto v0075;
    env = stack[-4];
    stack[-1] = v0026;
    stack[-2] = v0026;
    goto v0022;

v0022:
    v0026 = stack[-3];
    v0026 = qcdr(v0026);
    stack[-3] = v0026;
    v0026 = stack[-3];
    if (v0026 == nil) { LispObject res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v0026 = stack[-3];
    v0026 = qcar(v0026);
    v0026 = qcar(v0026);
    v0026 = ncons(v0026);
    nil = C_nil;
    if (exception_pending()) goto v0075;
    env = stack[-4];
    v0026 = Lrplacd(nil, stack[0], v0026);
    nil = C_nil;
    if (exception_pending()) goto v0075;
    env = stack[-4];
    v0026 = stack[-1];
    v0026 = qcdr(v0026);
    stack[-1] = v0026;
    goto v0022;

v0031:
    v0026 = qvalue(elt(env, 1)); // nil
    { popv(5); return onevalue(v0026); }
// error exit handlers
v0075:
    popv(5);
    return nil;
}



// Code for mkimpart

static LispObject CC_mkimpart(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0024, v0071;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mkimpart");
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
    v0024 = stack[0];
    fn = elt(env, 3); // realvaluedp
    v0024 = (*qfn1(fn))(qenv(fn), v0024);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-1];
    if (v0024 == nil) goto v0019;
    v0071 = qvalue(elt(env, 1)); // nil
    v0024 = (LispObject)17; // 1
    popv(2);
    return cons(v0071, v0024);

v0019:
    v0024 = stack[0];
    fn = elt(env, 4); // sfp
    v0024 = (*qfn1(fn))(qenv(fn), v0024);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-1];
    if (v0024 == nil) goto v0059;
    v0071 = stack[0];
    v0024 = (LispObject)17; // 1
    v0024 = cons(v0071, v0024);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 5); // impartsq
        return (*qfn1(fn))(qenv(fn), v0024);
    }

v0059:
    v0071 = elt(env, 2); // impart
    v0024 = stack[0];
    v0071 = list2(v0071, v0024);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-1];
    v0024 = (LispObject)17; // 1
    {
        popv(2);
        fn = elt(env, 6); // mksq
        return (*qfn2(fn))(qenv(fn), v0071, v0024);
    }
// error exit handlers
v0083:
    popv(2);
    return nil;
}



// Code for reduce

static LispObject CC_reduce(LispObject env,
                         LispObject v0000, LispObject v0070)
{
    LispObject nil = C_nil;
    LispObject v0092, v0091, v0175;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for reduce");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0070,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0070);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0070;
    v0092 = v0000;
// end of prologue
    stack[0] = v0092;
    v0092 = qvalue(elt(env, 1)); // !*yyy
    if (v0092 == nil) goto v0002;
    v0091 = stack[0];
    v0092 = stack[-1];
    fn = elt(env, 3); // reduce!-ratios
    v0092 = (*qfn2(fn))(qenv(fn), v0091, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-3];
    stack[0] = v0092;
    goto v0002;

v0002:
    v0092 = stack[-1];
    fn = elt(env, 4); // set!-weights
    v0092 = (*qfn1(fn))(qenv(fn), v0092);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-3];
    stack[-2] = v0092;
    v0092 = qvalue(elt(env, 2)); // !*xxx
    if (v0092 == nil) goto v0084;
    v0175 = stack[0];
    v0091 = stack[-1];
    v0092 = stack[-2];
    fn = elt(env, 5); // reduce!-columns
    v0092 = (*qfnn(fn))(qenv(fn), 3, v0175, v0091, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-3];
    stack[0] = v0092;
    goto v0084;

v0084:
    v0092 = qvalue(elt(env, 2)); // !*xxx
    if (v0092 == nil) { LispObject res = stack[0]; popv(4); return onevalue(res); }
    v0175 = stack[0];
    v0091 = stack[-1];
    v0092 = stack[-2];
    fn = elt(env, 6); // reduce!-weights
    v0092 = (*qfnn(fn))(qenv(fn), 3, v0175, v0091, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    stack[0] = v0092;
    { LispObject res = stack[0]; popv(4); return onevalue(res); }
// error exit handlers
v0067:
    popv(4);
    return nil;
}



// Code for fs!:minusp!:

static LispObject CC_fsTminuspT(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0019;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for fs:minusp:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0019 = v0000;
// end of prologue
    v0019 = qcdr(v0019);
    {
        fn = elt(env, 1); // fs!:minusp
        return (*qfn1(fn))(qenv(fn), v0019);
    }
}



// Code for cali!=min

static LispObject CC_caliMmin(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0091, v0175, v0053;
    LispObject fn;
    LispObject v0008, v0070, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "cali=min");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0070 = va_arg(aa, LispObject);
    v0008 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cali=min");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0008,v0070,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0070,v0008);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0008;
    stack[-1] = v0070;
    stack[-2] = v0000;
// end of prologue

v0051:
    v0091 = stack[-1];
    if (v0091 == nil) { LispObject res = stack[-2]; popv(4); return onevalue(res); }
    v0053 = stack[-2];
    v0091 = stack[-1];
    v0175 = qcar(v0091);
    v0091 = stack[0];
    fn = elt(env, 1); // listtest
    v0091 = (*qfnn(fn))(qenv(fn), 3, v0053, v0175, v0091);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    env = stack[-3];
    if (!(v0091 == nil)) goto v0004;
    v0091 = stack[-1];
    v0053 = qcdr(v0091);
    v0091 = stack[-1];
    v0175 = qcar(v0091);
    v0091 = stack[0];
    fn = elt(env, 1); // listtest
    v0091 = (*qfnn(fn))(qenv(fn), 3, v0053, v0175, v0091);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    env = stack[-3];
    if (!(v0091 == nil)) goto v0004;
    v0091 = stack[-1];
    v0175 = qcar(v0091);
    v0091 = stack[-2];
    v0091 = cons(v0175, v0091);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    env = stack[-3];
    stack[-2] = v0091;
    v0091 = stack[-1];
    v0091 = qcdr(v0091);
    stack[-1] = v0091;
    goto v0051;

v0004:
    v0091 = stack[-1];
    v0091 = qcdr(v0091);
    stack[-1] = v0091;
    goto v0051;
// error exit handlers
v0015:
    popv(4);
    return nil;
}



// Code for fd2q

static LispObject CC_fd2q(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0105, v0139;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for fd2q");
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

v0057:
    v0105 = stack[0];
    if (!consp(v0105)) goto v0003;
    v0105 = stack[0];
    v0139 = qcar(v0105);
    v0105 = elt(env, 1); // !:ar!:
    if (v0139 == v0105) goto v0011;
    v0105 = stack[0];
    v0139 = qcar(v0105);
    v0105 = elt(env, 2); // !:rn!:
    if (v0139 == v0105) goto v0055;
    v0105 = stack[0];
    v0105 = qcar(v0105);
    v0139 = qcar(v0105);
    v0105 = (LispObject)17; // 1
    v0105 = cons(v0139, v0105);
    nil = C_nil;
    if (exception_pending()) goto v0052;
    env = stack[-2];
    v0139 = ncons(v0105);
    nil = C_nil;
    if (exception_pending()) goto v0052;
    env = stack[-2];
    v0105 = (LispObject)17; // 1
    stack[-1] = cons(v0139, v0105);
    nil = C_nil;
    if (exception_pending()) goto v0052;
    env = stack[-2];
    v0105 = stack[0];
    v0105 = qcar(v0105);
    v0105 = qcdr(v0105);
    v0105 = CC_fd2q(env, v0105);
    nil = C_nil;
    if (exception_pending()) goto v0052;
    env = stack[-2];
    fn = elt(env, 3); // multsq
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[-1], v0105);
    nil = C_nil;
    if (exception_pending()) goto v0052;
    env = stack[-2];
    v0105 = stack[0];
    v0105 = qcdr(v0105);
    v0105 = CC_fd2q(env, v0105);
    nil = C_nil;
    if (exception_pending()) goto v0052;
    env = stack[-2];
    {
        LispObject v0029 = stack[-1];
        popv(3);
        fn = elt(env, 4); // addsq
        return (*qfn2(fn))(qenv(fn), v0029, v0105);
    }

v0055:
    v0105 = stack[0];
    v0105 = qcdr(v0105);
    { popv(3); return onevalue(v0105); }

v0011:
    v0105 = stack[0];
    v0105 = qcdr(v0105);
    stack[0] = v0105;
    goto v0057;

v0003:
    v0139 = stack[0];
    v0105 = (LispObject)17; // 1
    popv(3);
    return cons(v0139, v0105);
// error exit handlers
v0052:
    popv(3);
    return nil;
}



setup_type const u37_setup[] =
{
    {"rl_pnf",                  CC_rl_pnf,      too_many_1,    wrong_no_1},
    {"pickbasicset",            CC_pickbasicset,too_many_1,    wrong_no_1},
    {"dvfsf_smcpknowl",         CC_dvfsf_smcpknowl,too_many_1, wrong_no_1},
    {"determinantrd",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_determinantrd},
    {"transmat1",               CC_transmat1,   too_many_1,    wrong_no_1},
    {"remzzzz",                 too_few_2,      CC_remzzzz,    wrong_no_2},
    {"sc_rowscalarproduct",     too_few_2,      CC_sc_rowscalarproduct,wrong_no_2},
    {"xnsiz",                   CC_xnsiz,       too_many_1,    wrong_no_1},
    {"rd:difference",           too_few_2,      CC_rdTdifference,wrong_no_2},
    {"indxsymp",                too_few_2,      CC_indxsymp,   wrong_no_2},
    {"lengthreval",             CC_lengthreval, too_many_1,    wrong_no_1},
    {"createmonomunit",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_createmonomunit},
    {"sfto_yun-updecf",         CC_sfto_yunKupdecf,too_many_1, wrong_no_1},
    {"squashsqrt",              CC_squashsqrt,  too_many_1,    wrong_no_1},
    {"rl_onp",                  CC_rl_onp,      too_many_1,    wrong_no_1},
    {"termorder1",              too_few_2,      CC_termorder1, wrong_no_2},
    {"vdp_make",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_vdp_make},
    {"sfto_subfwd",             too_few_2,      CC_sfto_subfwd,wrong_no_2},
    {"omattrir",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_omattrir},
    {"reduceroots",             too_few_2,      CC_reduceroots,wrong_no_2},
    {"f2dip1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_f2dip1},
    {"add_item",                too_few_2,      CC_add_item,   wrong_no_2},
    {"fl2bf",                   CC_fl2bf,       too_many_1,    wrong_no_1},
    {"spp",                     CC_spp,         too_many_1,    wrong_no_1},
    {"calc_coeffmap_",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_calc_coeffmap_},
    {"fs:minusp",               CC_fsTminusp,   too_many_1,    wrong_no_1},
    {"ra_intequiv0",            CC_ra_intequiv0,too_many_1,    wrong_no_1},
    {"mk+scal+mult+mat",        too_few_2,      CC_mkLscalLmultLmat,wrong_no_2},
    {"degree-order",            too_few_2,      CC_degreeKorder,wrong_no_2},
    {"fnom",                    CC_fnom,        too_many_1,    wrong_no_1},
    {"look_for_substitute",     wrong_no_na,    wrong_no_nb,   (n_args *)CC_look_for_substitute},
    {"aceq",                    too_few_2,      CC_aceq,       wrong_no_2},
    {"xremf",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_xremf},
    {"solvealgdepends",         too_few_2,      CC_solvealgdepends,wrong_no_2},
    {"bfrsq",                   CC_bfrsq,       too_many_1,    wrong_no_1},
    {"oddext",                  CC_oddext,      too_many_1,    wrong_no_1},
    {"ra_intequiv",             CC_ra_intequiv, too_many_1,    wrong_no_1},
    {"factor-prim-f",           CC_factorKprimKf,too_many_1,   wrong_no_1},
    {"ofsf_updsignvar",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_updsignvar},
    {"make-modular-symmetric",  CC_makeKmodularKsymmetric,too_many_1,wrong_no_1},
    {"vectorrd",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_vectorrd},
    {"genexp",                  CC_genexp,      too_many_1,    wrong_no_1},
    {"simp_without_resimp",     CC_simp_without_resimp,too_many_1,wrong_no_1},
    {"sc_columnscalarproduct",  too_few_2,      CC_sc_columnscalarproduct,wrong_no_2},
    {"simpunion",               CC_simpunion,   too_many_1,    wrong_no_1},
    {"gfplus",                  too_few_2,      CC_gfplus,     wrong_no_2},
    {"getupper",                CC_getupper,    too_many_1,    wrong_no_1},
    {"s_world_names",           CC_s_world_names,too_many_1,   wrong_no_1},
    {"mkimpart",                CC_mkimpart,    too_many_1,    wrong_no_1},
    {"reduce",                  too_few_2,      CC_reduce,     wrong_no_2},
    {"fs:minusp:",              CC_fsTminuspT,  too_many_1,    wrong_no_1},
    {"cali=min",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_caliMmin},
    {"fd2q",                    CC_fd2q,        too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u37", (two_args *)"11032 8307829 4264705", 0}
};

// end of generated code
