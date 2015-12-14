
// $destdir\u30.c        Machine generated C code

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
#define CSL_IGNORE(x) (x = x)
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
#ifdef NILSEG_EXTERNS
#define nil_as_base
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
#else 
#define nil_as_base LispObject nil = C_nil;
#define byteflip BASE[12]
#define codefringe BASE[13]
#define codelimit (*(LispObject volatile *)&BASE[14])
extern LispObject * volatile stacklimit;
#define fringe BASE[18]
#define heaplimit (*(LispObject volatile *)&BASE[19])
#define vheaplimit (*(LispObject volatile *)&BASE[20])
#define vfringe BASE[21]
#define miscflags BASE[22]
#define nwork BASE[24]
#define exit_count BASE[26]
#define gensym_ser BASE[27]
#define print_precision BASE[28]
#define current_modulus BASE[29]
#define fastget_size BASE[30]
#define package_bits BASE[31]
#define modulus_is_large BASE[32]
#define current_package BASE[52]
#define B_reg BASE[53]
#define codevec BASE[54]
#define litvec BASE[55]
#define exit_tag BASE[56]
#define exit_value BASE[57]
#define catch_tags BASE[58]
#define lisp_package BASE[59]
#define boffo BASE[60]
#define charvec BASE[61]
#define sys_hash_table BASE[62]
#define help_index BASE[63]
#define gensym_base BASE[64]
#define err_table BASE[65]
#define supervisor BASE[66]
#define startfn BASE[67]
#define faslvec BASE[68]
#define tracedfn BASE[69]
#define prompt_thing BASE[70]
#define faslgensyms BASE[71]
#define cl_symbols BASE[72]
#define active_stream BASE[73]
#define current_module BASE[74]
#define native_defs BASE[75]
#define append_symbol BASE[90]
#define applyhook BASE[91]
#define cfunarg BASE[92]
#define comma_at_symbol BASE[93]
#define comma_symbol BASE[94]
#define compiler_symbol BASE[95]
#define comp_symbol BASE[96]
#define cons_symbol BASE[97]
#define echo_symbol BASE[98]
#define emsg_star BASE[99]
#define evalhook BASE[100]
#define eval_symbol BASE[101]
#define expr_symbol BASE[102]
#define features_symbol BASE[103]
#define fexpr_symbol BASE[104]
#define funarg BASE[105]
#define function_symbol BASE[106]
#define lambda BASE[107]
#define lisp_true BASE[108]
#define lower_symbol BASE[109]
#define macroexpand_hook BASE[110]
#define macro_symbol BASE[111]
#define opt_key BASE[112]
#define prinl_symbol BASE[113]
#define progn_symbol BASE[114]
#define quote_symbol BASE[115]
#define raise_symbol BASE[116]
#define redef_msg BASE[117]
#define rest_key BASE[118]
#define savedef BASE[119]
#define string_char_sym BASE[120]
#define unset_var BASE[121]
#define work_symbol BASE[122]
#define lex_words BASE[123]
#define get_counts BASE[124]
#define fastget_names BASE[125]
#define input_libraries BASE[126]
#define output_library BASE[127]
#define current_file BASE[128]
#define break_function BASE[129]
#define lisp_work_stream BASE[130]
#define lisp_standard_output BASE[131]
#define lisp_standard_input BASE[132]
#define lisp_debug_io BASE[133]
#define lisp_error_output BASE[134]
#define lisp_query_io BASE[135]
#define lisp_terminal_io BASE[136]
#define lisp_trace_output BASE[137]
#define standard_output BASE[138]
#define standard_input BASE[139]
#define debug_io BASE[140]
#define error_output BASE[141]
#define query_io BASE[142]
#define terminal_io BASE[143]
#define trace_output BASE[144]
#define fasl_stream BASE[145]
#define native_code BASE[146]
#define native_symbol BASE[147]
#define traceprint_symbol BASE[148]
#define loadsource_symbol BASE[149]
#define hankaku_symbol BASE[150]
#define bytecoded_symbol BASE[151]
#define nativecoded_symbol BASE[152]
#define gchook BASE[153]
#define resources BASE[154]
#define callstack BASE[155]
#define procstack BASE[156]
#define procmem BASE[157]
#define trap_time BASE[158]
#define count_high BASE[159]
#ifdef COMMON
#define keyword_package BASE[170]
#define all_packages BASE[171]
#define package_symbol BASE[172]
#define internal_symbol BASE[173]
#define external_symbol BASE[174]
#define inherited_symbol BASE[175]
#define key_key BASE[176]
#define allow_other_keys BASE[177]
#define aux_key BASE[178]
#define format_symbol BASE[179]
#define expand_def_symbol BASE[180]
#define allow_key_key BASE[181]
#endif
#define declare_symbol BASE[182]
#define special_symbol BASE[183]
#define large_modulus BASE[184]
#define used_space BASE[185]
#define avail_space BASE[186]
#define eof_symbol BASE[187]
#define call_stack BASE[188]
extern LispObject user_base_0, user_base_1, user_base_2;
extern LispObject user_base_3, user_base_4, user_base_5;
extern LispObject user_base_6, user_base_7, user_base_8;
extern LispObject user_base_9;
#define work_0 BASE[200]
#define work_1 BASE[201]
#define mv_1 work_1
#define mv_2 BASE[202]
#define mv_3 BASE[203]
#define work_50 BASE[250]
#endif 
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
#else
#define Dmultiply(hi, lo, a, b, c) ((hi) = Imultiply(&(lo), (a), (b), (c)))
#define Ddivide(r, q, a, b, c) ((r) = Idivide(&(q), (a), (b), (c)))
#define Ddiv10_9(r, q, a, b) ((r) = Idiv10_9(&(q), (a), (b)))
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



// Code for simpexpt1

static LispObject CC_simpexpt1(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0099, v0100, v0101;
    LispObject fn;
    LispObject v0010, v0007, v0009;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "simpexpt1");
    va_start(aa, nargs);
    v0009 = va_arg(aa, LispObject);
    v0007 = va_arg(aa, LispObject);
    v0010 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for simpexpt1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0010,v0007,v0009);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0009,v0007,v0010);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[-4] = v0010;
    stack[-5] = v0007;
    stack[-6] = v0009;
// end of prologue
    stack[-7] = qvalue(elt(env, 1)); // !*allfac
    qvalue(elt(env, 1)) = nil; // !*allfac
    stack[-3] = qvalue(elt(env, 2)); // !*div
    qvalue(elt(env, 2)) = nil; // !*div
    v0099 = stack[-6];
    v0099 = Lonep(nil, v0099);
    env = stack[-8];
    if (v0099 == nil) goto v0102;
    v0100 = (LispObject)17; // 1
    v0099 = (LispObject)17; // 1
    v0099 = cons(v0100, v0099);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-8];
    goto v0104;

v0104:
    qvalue(elt(env, 2)) = stack[-3]; // !*div
    qvalue(elt(env, 1)) = stack[-7]; // !*allfac
    { popv(9); return onevalue(v0099); }

v0102:
    v0099 = qvalue(elt(env, 3)); // t
    qvalue(elt(env, 1)) = v0099; // !*allfac
    v0099 = stack[-5];
    v0099 = qcar(v0099);
    stack[-2] = v0099;
    v0100 = stack[-2];
    v0099 = (LispObject)17; // 1
    if (v0100 == v0099) goto v0105;
    v0099 = qvalue(elt(env, 4)); // nil
    goto v0106;

v0106:
    if (v0099 == nil) goto v0107;
    v0099 = stack[-6];
    fn = elt(env, 12); // simp
    v0099 = (*qfn1(fn))(qenv(fn), v0099);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-8];
    goto v0104;

v0107:
    v0100 = stack[-6];
    v0099 = elt(env, 5); // e
    if (v0100 == v0099) goto v0108;
    v0099 = qvalue(elt(env, 4)); // nil
    goto v0109;

v0109:
    if (v0099 == nil) goto v0110;
    v0099 = stack[-2];
    v0099 = qcar(v0099);
    v0099 = qcar(v0099);
    v0099 = qcar(v0099);
    v0099 = qcdr(v0099);
    v0099 = qcar(v0099);
    fn = elt(env, 13); // simp!*
    v0099 = (*qfn1(fn))(qenv(fn), v0099);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-8];
    fn = elt(env, 14); // prepsq!*
    stack[0] = (*qfn1(fn))(qenv(fn), v0099);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-8];
    v0099 = stack[-2];
    v0099 = qcar(v0099);
    v0100 = qcdr(v0099);
    v0099 = stack[-5];
    v0099 = qcdr(v0099);
    v0100 = cons(v0100, v0099);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-8];
    v0099 = qvalue(elt(env, 4)); // nil
    v0099 = CC_simpexpt1(env, 3, stack[0], v0100, v0099);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-8];
    goto v0104;

v0110:
    v0099 = stack[-2];
    if (!consp(v0099)) goto v0111;
    v0099 = stack[-2];
    v0099 = qcar(v0099);
    v0099 = (consp(v0099) ? nil : lisp_true);
    goto v0112;

v0112:
    if (v0099 == nil) goto v0113;
    v0099 = stack[-5];
    v0099 = qcdr(v0099);
    if (!consp(v0099)) goto v0114;
    v0099 = stack[-5];
    v0099 = qcdr(v0099);
    v0099 = qcar(v0099);
    v0099 = (consp(v0099) ? nil : lisp_true);
    goto v0115;

v0115:
    v0099 = (v0099 == nil ? lisp_true : nil);
    goto v0116;

v0116:
    if (v0099 == nil) goto v0117;
    v0101 = stack[-6];
    v0100 = stack[-5];
    v0099 = stack[-4];
    fn = elt(env, 15); // simpexpt11
    v0099 = (*qfnn(fn))(qenv(fn), 3, v0101, v0100, v0099);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-8];
    goto v0104;

v0117:
    v0099 = stack[-6];
    fn = elt(env, 12); // simp
    v0099 = (*qfn1(fn))(qenv(fn), v0099);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-8];
    stack[-1] = v0099;
    v0099 = stack[-2];
    if (v0099 == nil) goto v0118;
    v0099 = stack[-1];
    v0099 = qcar(v0099);
    if (v0099 == nil) goto v0119;
    v0099 = stack[-2];
    if (!consp(v0099)) goto v0120;
    v0099 = qvalue(elt(env, 4)); // nil
    goto v0121;

v0121:
    if (v0099 == nil) goto v0122;
    v0099 = stack[-1];
    v0099 = qcar(v0099);
    if (!consp(v0099)) goto v0123;
    v0099 = qvalue(elt(env, 4)); // nil
    goto v0124;

v0124:
    if (v0099 == nil) goto v0125;
    v0099 = stack[-1];
    v0100 = qcar(v0099);
    v0099 = stack[-2];
    v0099 = Lexpt(nil, v0100, v0099);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-8];
    fn = elt(env, 16); // !*d2q
    v0099 = (*qfn1(fn))(qenv(fn), v0099);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-8];
    goto v0104;

v0125:
    v0099 = stack[-1];
    v0100 = qcar(v0099);
    v0099 = stack[-2];
    fn = elt(env, 17); // !:expt
    v0100 = (*qfn2(fn))(qenv(fn), v0100, v0099);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-8];
    v0099 = (LispObject)17; // 1
    v0099 = cons(v0100, v0099);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-8];
    stack[-1] = v0099;
    v0099 = qvalue(elt(env, 10)); // !*mcd
    if (v0099 == nil) goto v0126;
    v0099 = stack[-1];
    fn = elt(env, 18); // resimp
    v0099 = (*qfn1(fn))(qenv(fn), v0099);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-8];
    goto v0104;

v0126:
    v0099 = stack[-1];
    goto v0104;

v0123:
    v0100 = stack[-2];
    v0099 = (LispObject)1; // 0
    v0099 = (LispObject)greaterp2(v0100, v0099);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    v0099 = v0099 ? lisp_true : nil;
    env = stack[-8];
    goto v0124;

v0122:
    stack[0] = elt(env, 11); // expt
    v0100 = stack[-1];
    v0099 = stack[-5];
    v0099 = list2(v0100, v0099);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-8];
    fn = elt(env, 19); // domainvalchk
    v0099 = (*qfn2(fn))(qenv(fn), stack[0], v0099);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-8];
    v0100 = v0099;
    if (v0099 == nil) goto v0127;
    v0099 = v0100;
    goto v0104;

v0127:
    v0099 = stack[-2];
    if (!consp(v0099)) goto v0128;
    v0099 = qvalue(elt(env, 4)); // nil
    goto v0129;

v0129:
    if (v0099 == nil) goto v0130;
    v0100 = stack[-2];
    v0099 = (LispObject)1; // 0
    v0099 = (LispObject)lessp2(v0100, v0099);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    v0099 = v0099 ? lisp_true : nil;
    env = stack[-8];
    if (v0099 == nil) goto v0131;
    v0099 = qvalue(elt(env, 10)); // !*mcd
    if (v0099 == nil) goto v0132;
    stack[0] = stack[-1];
    v0099 = stack[-2];
    v0099 = negate(v0099);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-8];
    fn = elt(env, 20); // exptsq
    v0099 = (*qfn2(fn))(qenv(fn), stack[0], v0099);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-8];
    fn = elt(env, 21); // invsq
    v0099 = (*qfn1(fn))(qenv(fn), v0099);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-8];
    goto v0104;

v0132:
    v0099 = stack[-1];
    v0100 = qcar(v0099);
    v0099 = stack[-2];
    fn = elt(env, 22); // expf
    stack[0] = (*qfn2(fn))(qenv(fn), v0100, v0099);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-8];
    v0099 = stack[-1];
    stack[-1] = qcdr(v0099);
    v0099 = stack[-2];
    v0099 = negate(v0099);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-8];
    fn = elt(env, 23); // mksfpf
    v0099 = (*qfn2(fn))(qenv(fn), stack[-1], v0099);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-8];
    fn = elt(env, 24); // multf
    v0100 = (*qfn2(fn))(qenv(fn), stack[0], v0099);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-8];
    v0099 = (LispObject)17; // 1
    v0099 = cons(v0100, v0099);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-8];
    goto v0104;

v0131:
    v0100 = stack[-1];
    v0099 = stack[-2];
    fn = elt(env, 20); // exptsq
    v0099 = (*qfn2(fn))(qenv(fn), v0100, v0099);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-8];
    goto v0104;

v0130:
    v0099 = stack[-4];
    if (v0099 == nil) goto v0133;
    v0099 = stack[-6];
    v0101 = v0099;
    goto v0134;

v0134:
    v0100 = stack[-5];
    v0099 = qvalue(elt(env, 3)); // t
    fn = elt(env, 15); // simpexpt11
    v0099 = (*qfnn(fn))(qenv(fn), 3, v0101, v0100, v0099);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-8];
    goto v0104;

v0133:
    v0099 = stack[-1];
    fn = elt(env, 25); // subs2!*
    v0099 = (*qfn1(fn))(qenv(fn), v0099);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-8];
    fn = elt(env, 14); // prepsq!*
    v0099 = (*qfn1(fn))(qenv(fn), v0099);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-8];
    v0101 = v0099;
    goto v0134;

v0128:
    v0099 = stack[-5];
    v0100 = qcdr(v0099);
    v0099 = (LispObject)17; // 1
    v0099 = (v0100 == v0099 ? lisp_true : nil);
    goto v0129;

v0120:
    v0099 = stack[-5];
    v0100 = qcdr(v0099);
    v0099 = (LispObject)17; // 1
    if (v0100 == v0099) goto v0135;
    v0099 = qvalue(elt(env, 4)); // nil
    goto v0121;

v0135:
    v0099 = stack[-1];
    v0099 = qcar(v0099);
    if (!consp(v0099)) goto v0136;
    v0099 = stack[-1];
    v0099 = qcar(v0099);
    v0099 = qcar(v0099);
    v0099 = (consp(v0099) ? nil : lisp_true);
    goto v0137;

v0137:
    if (v0099 == nil) goto v0138;
    v0099 = stack[-1];
    v0100 = qcdr(v0099);
    v0099 = (LispObject)17; // 1
    v0099 = (v0100 == v0099 ? lisp_true : nil);
    goto v0121;

v0138:
    v0099 = qvalue(elt(env, 4)); // nil
    goto v0121;

v0136:
    v0099 = qvalue(elt(env, 3)); // t
    goto v0137;

v0119:
    v0099 = stack[-2];
    if (!consp(v0099)) goto v0139;
    v0099 = stack[-2];
    v0099 = qcar(v0099);
    v0099 = (consp(v0099) ? nil : lisp_true);
    goto v0140;

v0140:
    if (v0099 == nil) goto v0141;
    v0099 = stack[-2];
    fn = elt(env, 26); // minusf
    v0099 = (*qfn1(fn))(qenv(fn), v0099);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-8];
    goto v0142;

v0142:
    if (v0099 == nil) goto v0143;
    v0101 = elt(env, 7); // alg
    v0100 = (LispObject)241; // 15
    v0099 = elt(env, 9); // "Zero divisor"
    fn = elt(env, 27); // rerror
    v0099 = (*qfnn(fn))(qenv(fn), 3, v0101, v0100, v0099);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-8];
    goto v0104;

v0143:
    v0100 = qvalue(elt(env, 4)); // nil
    v0099 = (LispObject)17; // 1
    v0099 = cons(v0100, v0099);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-8];
    goto v0104;

v0141:
    v0099 = qvalue(elt(env, 4)); // nil
    goto v0142;

v0139:
    v0099 = qvalue(elt(env, 3)); // t
    goto v0140;

v0118:
    v0099 = stack[-1];
    v0099 = qcar(v0099);
    if (v0099 == nil) goto v0144;
    v0100 = (LispObject)17; // 1
    v0099 = (LispObject)17; // 1
    v0099 = cons(v0100, v0099);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-8];
    goto v0104;

v0144:
    v0101 = elt(env, 7); // alg
    v0100 = (LispObject)225; // 14
    v0099 = elt(env, 8); // "0**0 formed"
    fn = elt(env, 27); // rerror
    v0099 = (*qfnn(fn))(qenv(fn), 3, v0101, v0100, v0099);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-8];
    goto v0104;

v0114:
    v0099 = qvalue(elt(env, 3)); // t
    goto v0115;

v0113:
    v0099 = qvalue(elt(env, 3)); // t
    goto v0116;

v0111:
    v0099 = qvalue(elt(env, 3)); // t
    goto v0112;

v0108:
    v0099 = stack[-5];
    v0099 = qcdr(v0099);
    if (!consp(v0099)) goto v0145;
    v0099 = stack[-5];
    v0099 = qcdr(v0099);
    v0099 = qcar(v0099);
    v0099 = (consp(v0099) ? nil : lisp_true);
    goto v0146;

v0146:
    if (v0099 == nil) goto v0147;
    v0099 = stack[-2];
    if (!consp(v0099)) goto v0148;
    v0099 = stack[-2];
    v0099 = qcar(v0099);
    v0099 = (consp(v0099) ? nil : lisp_true);
    goto v0149;

v0149:
    if (v0099 == nil) goto v0150;
    v0099 = qvalue(elt(env, 4)); // nil
    goto v0109;

v0150:
    v0099 = stack[-2];
    v0099 = qcar(v0099);
    v0099 = qcar(v0099);
    v0100 = qcdr(v0099);
    v0099 = (LispObject)17; // 1
    if (v0100 == v0099) goto v0151;
    v0099 = qvalue(elt(env, 4)); // nil
    goto v0109;

v0151:
    v0099 = stack[-2];
    v0099 = qcdr(v0099);
    if (v0099 == nil) goto v0152;
    v0099 = qvalue(elt(env, 4)); // nil
    goto v0109;

v0152:
    v0099 = stack[-2];
    v0099 = qcar(v0099);
    v0099 = qcar(v0099);
    v0100 = qcar(v0099);
    v0099 = elt(env, 6); // log
    v0099 = Leqcar(nil, v0100, v0099);
    env = stack[-8];
    goto v0109;

v0148:
    v0099 = qvalue(elt(env, 3)); // t
    goto v0149;

v0147:
    v0099 = qvalue(elt(env, 4)); // nil
    goto v0109;

v0145:
    v0099 = qvalue(elt(env, 3)); // t
    goto v0146;

v0105:
    v0099 = stack[-5];
    v0100 = qcdr(v0099);
    v0099 = (LispObject)17; // 1
    v0099 = (v0100 == v0099 ? lisp_true : nil);
    goto v0106;
// error exit handlers
v0103:
    env = stack[-8];
    qvalue(elt(env, 2)) = stack[-3]; // !*div
    qvalue(elt(env, 1)) = stack[-7]; // !*allfac
    popv(9);
    return nil;
}



// Code for mri_opn

static LispObject CC_mri_opn(LispObject env,
                         LispObject v0009)
{
    LispObject nil = C_nil;
    LispObject v0153, v0154;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mri_opn");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0009);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0153 = v0009;
// end of prologue
    fn = elt(env, 1); // mri_op
    v0153 = (*qfn1(fn))(qenv(fn), v0153);
    errexit();
    v0154 = v0153;
    v0153 = v0154;
    if (!consp(v0153)) return onevalue(v0154);
    v0153 = v0154;
    v0153 = qcar(v0153);
    return onevalue(v0153);
}



// Code for repr_n

static LispObject CC_repr_n(LispObject env,
                         LispObject v0009)
{
    LispObject nil = C_nil;
    LispObject v0157, v0158, v0159;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for repr_n");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0009);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// copy arguments values to proper place
    v0159 = v0009;
// end of prologue
    v0157 = v0159;
    v0157 = qcdr(v0157);
    v0157 = qcdr(v0157);
    v0157 = qcar(v0157);
    if (v0157 == nil) goto v0000;
    v0157 = v0159;
    v0157 = qcdr(v0157);
    v0157 = qcdr(v0157);
    v0157 = qcdr(v0157);
    v0157 = qcdr(v0157);
    v0158 = qcar(v0157);
    v0157 = (LispObject)1; // 0
    if (v0158 == v0157) goto v0160;
    v0157 = v0159;
    v0157 = qcdr(v0157);
    v0157 = qcdr(v0157);
    v0157 = qcar(v0157);
    v0157 = qcar(v0157);
    v0157 = qcar(v0157);
    { popv(1); return onevalue(v0157); }

v0160:
    v0157 = qvalue(elt(env, 2)); // nil
    { popv(1); return onevalue(v0157); }

v0000:
    v0157 = elt(env, 1); // "repr_n : invalid REPR structure"
    v0157 = ncons(v0157);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); // rederr
        return (*qfn1(fn))(qenv(fn), v0157);
    }
// error exit handlers
v0161:
    popv(1);
    return nil;
}



// Code for minusrd

static LispObject CC_minusrd(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0155, v0163;
    LispObject fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "minusrd");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for minusrd");
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
    v0155 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0164;
    env = stack[-1];
    stack[0] = v0155;
    fn = elt(env, 1); // mathml
    v0155 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0164;
    env = stack[-1];
    v0163 = v0155;
    if (v0163 == nil) goto v0002;
    v0163 = stack[0];
    fn = elt(env, 2); // alg_difference
    v0155 = (*qfn2(fn))(qenv(fn), v0163, v0155);
    nil = C_nil;
    if (exception_pending()) goto v0164;
    env = stack[-1];
    stack[0] = v0155;
    fn = elt(env, 3); // lex
    v0155 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0164;
    { LispObject res = stack[0]; popv(2); return onevalue(res); }

v0002:
    v0155 = stack[0];
    fn = elt(env, 4); // alg_minus
    v0155 = (*qfn1(fn))(qenv(fn), v0155);
    nil = C_nil;
    if (exception_pending()) goto v0164;
    stack[0] = v0155;
    { LispObject res = stack[0]; popv(2); return onevalue(res); }
// error exit handlers
v0164:
    popv(2);
    return nil;
}



// Code for vdpmember

static LispObject CC_vdpmember(LispObject env,
                         LispObject v0009, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0166, v0164;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vdpmember");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0007,v0009);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0009,v0007);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0007;
    stack[-1] = v0009;
// end of prologue

v0001:
    v0166 = stack[0];
    if (v0166 == nil) goto v0030;
    v0164 = stack[-1];
    v0166 = stack[0];
    v0166 = qcar(v0166);
    fn = elt(env, 2); // vdpequal
    v0166 = (*qfn2(fn))(qenv(fn), v0164, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-2];
    if (!(v0166 == nil)) { LispObject res = stack[0]; popv(3); return onevalue(res); }
    v0166 = stack[0];
    v0166 = qcdr(v0166);
    stack[0] = v0166;
    goto v0001;

v0030:
    v0166 = qvalue(elt(env, 1)); // nil
    { popv(3); return onevalue(v0166); }
// error exit handlers
v0092:
    popv(3);
    return nil;
}



// Code for simp!*sq

static LispObject CC_simpHsq(LispObject env,
                         LispObject v0009)
{
    LispObject nil = C_nil;
    LispObject v0167, v0165;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for simp*sq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0165 = v0009;
// end of prologue
    v0167 = v0165;
    v0167 = qcdr(v0167);
    v0167 = qcar(v0167);
    if (v0167 == nil) goto v0168;
    v0167 = qvalue(elt(env, 1)); // !*resimp
    if (!(v0167 == nil)) goto v0168;
    v0167 = v0165;
    v0167 = qcar(v0167);
    return onevalue(v0167);

v0168:
    v0167 = v0165;
    v0167 = qcar(v0167);
    {
        fn = elt(env, 2); // resimp1
        return (*qfn1(fn))(qenv(fn), v0167);
    }
}



// Code for z!-roads

static LispObject CC_zKroads(LispObject env,
                         LispObject v0009)
{
    LispObject nil = C_nil;
    LispObject v0146, v0145, v0172;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for z-roads");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0172 = v0009;
// end of prologue
    v0145 = (LispObject)1; // 0
    v0146 = v0172;
    v0146 = qcar(v0146);
    v0146 = qcar(v0146);
    v0146 = qcdr(v0146);
    if (v0145 == v0146) goto v0000;
    v0145 = (LispObject)1; // 0
    v0146 = v0172;
    v0146 = qcar(v0146);
    v0146 = qcdr(v0146);
    v0146 = qcar(v0146);
    v0146 = qcdr(v0146);
    if (v0145 == v0146) goto v0167;
    v0145 = (LispObject)1; // 0
    v0146 = v0172;
    v0146 = qcar(v0146);
    v0146 = qcdr(v0146);
    v0146 = qcdr(v0146);
    v0146 = qcar(v0146);
    v0146 = qcdr(v0146);
    if (v0145 == v0146) goto v0157;
    v0146 = qvalue(elt(env, 1)); // nil
    goto v0173;

v0173:
    v0145 = v0146;
    v0146 = v0145;
    if (v0146 == nil) goto v0079;
    v0146 = v0145;
    v0146 = qcar(v0146);
    v0145 = v0172;
    v0145 = qcdr(v0145);
    return cons(v0146, v0145);

v0079:
    v0146 = qvalue(elt(env, 1)); // nil
    return onevalue(v0146);

v0157:
    v0146 = v0172;
    v0146 = qcar(v0146);
    v0146 = qcdr(v0146);
    v0146 = qcdr(v0146);
    v0146 = qcar(v0146);
    goto v0173;

v0167:
    v0146 = v0172;
    v0146 = qcar(v0146);
    v0146 = qcdr(v0146);
    v0146 = qcar(v0146);
    goto v0173;

v0000:
    v0146 = v0172;
    v0146 = qcar(v0146);
    v0146 = qcar(v0146);
    goto v0173;
}



// Code for ordered!-gcd!-mod!-p

static LispObject CC_orderedKgcdKmodKp(LispObject env,
                         LispObject v0009, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0179, v0180;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ordered-gcd-mod-p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0007,v0009);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0009,v0007);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0007;
    stack[-1] = v0009;
// end of prologue
    v0179 = (LispObject)1; // 0
    stack[-2] = v0179;
    goto v0002;

v0002:
    v0180 = stack[-1];
    v0179 = stack[0];
    fn = elt(env, 3); // reduce!-degree!-mod!-p
    v0179 = (*qfn2(fn))(qenv(fn), v0180, v0179);
    nil = C_nil;
    if (exception_pending()) goto v0181;
    env = stack[-3];
    stack[-1] = v0179;
    v0179 = stack[-1];
    if (v0179 == nil) goto v0182;
    v0179 = stack[-2];
    v0179 = add1(v0179);
    nil = C_nil;
    if (exception_pending()) goto v0181;
    env = stack[-3];
    stack[-2] = v0179;
    v0179 = stack[-1];
    if (!consp(v0179)) goto v0170;
    v0179 = stack[-1];
    v0179 = qcar(v0179);
    v0179 = (consp(v0179) ? nil : lisp_true);
    goto v0183;

v0183:
    if (v0179 == nil) goto v0184;
    v0180 = qvalue(elt(env, 2)); // reduction!-count
    v0179 = stack[-2];
    v0179 = plus2(v0180, v0179);
    nil = C_nil;
    if (exception_pending()) goto v0181;
    env = stack[-3];
    qvalue(elt(env, 2)) = v0179; // reduction!-count
    v0179 = (LispObject)17; // 1
    { popv(4); return onevalue(v0179); }

v0184:
    v0179 = stack[-1];
    v0179 = qcar(v0179);
    v0179 = qcar(v0179);
    v0180 = qcdr(v0179);
    v0179 = stack[0];
    v0179 = qcar(v0179);
    v0179 = qcar(v0179);
    v0179 = qcdr(v0179);
    v0179 = (LispObject)lessp2(v0180, v0179);
    nil = C_nil;
    if (exception_pending()) goto v0181;
    v0179 = v0179 ? lisp_true : nil;
    env = stack[-3];
    if (v0179 == nil) goto v0002;
    v0180 = qvalue(elt(env, 2)); // reduction!-count
    v0179 = stack[-2];
    v0179 = plus2(v0180, v0179);
    nil = C_nil;
    if (exception_pending()) goto v0181;
    env = stack[-3];
    qvalue(elt(env, 2)) = v0179; // reduction!-count
    v0179 = (LispObject)1; // 0
    stack[-2] = v0179;
    v0179 = stack[-1];
    v0180 = v0179;
    v0179 = stack[0];
    stack[-1] = v0179;
    v0179 = v0180;
    stack[0] = v0179;
    goto v0002;

v0170:
    v0179 = qvalue(elt(env, 1)); // t
    goto v0183;

v0182:
    v0179 = stack[0];
    {
        popv(4);
        fn = elt(env, 4); // monic!-mod!-p
        return (*qfn1(fn))(qenv(fn), v0179);
    }
// error exit handlers
v0181:
    popv(4);
    return nil;
}



// Code for orddf

static LispObject CC_orddf(LispObject env,
                         LispObject v0009, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0186, v0175;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for orddf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0007,v0009);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0009,v0007);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0007;
    stack[-1] = v0009;
// end of prologue

v0001:
    v0186 = stack[-1];
    if (v0186 == nil) goto v0030;
    v0186 = stack[0];
    if (v0186 == nil) goto v0162;
    v0186 = stack[-1];
    v0175 = qcar(v0186);
    v0186 = stack[0];
    v0186 = qcar(v0186);
    fn = elt(env, 6); // exptcompare
    v0186 = (*qfn2(fn))(qenv(fn), v0175, v0186);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-2];
    if (v0186 == nil) goto v0105;
    v0186 = qvalue(elt(env, 4)); // t
    { popv(3); return onevalue(v0186); }

v0105:
    v0186 = stack[0];
    v0175 = qcar(v0186);
    v0186 = stack[-1];
    v0186 = qcar(v0186);
    fn = elt(env, 6); // exptcompare
    v0186 = (*qfn2(fn))(qenv(fn), v0175, v0186);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-2];
    if (v0186 == nil) goto v0187;
    v0186 = qvalue(elt(env, 5)); // nil
    { popv(3); return onevalue(v0186); }

v0187:
    v0186 = stack[-1];
    v0186 = qcdr(v0186);
    stack[-1] = v0186;
    v0186 = stack[0];
    v0186 = qcdr(v0186);
    stack[0] = v0186;
    goto v0001;

v0162:
    v0186 = elt(env, 3); // "Orddf u longer than v"
    {
        popv(3);
        fn = elt(env, 7); // interr
        return (*qfn1(fn))(qenv(fn), v0186);
    }

v0030:
    v0186 = stack[0];
    if (v0186 == nil) goto v0160;
    v0186 = elt(env, 2); // "Orddf v longer than u"
    {
        popv(3);
        fn = elt(env, 7); // interr
        return (*qfn1(fn))(qenv(fn), v0186);
    }

v0160:
    v0186 = elt(env, 1); // "Orddf = case"
    {
        popv(3);
        fn = elt(env, 7); // interr
        return (*qfn1(fn))(qenv(fn), v0186);
    }
// error exit handlers
v0108:
    popv(3);
    return nil;
}



// Code for rl_bnfsimpl

static LispObject CC_rl_bnfsimpl(LispObject env,
                         LispObject v0009, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0182, v0167;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rl_bnfsimpl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0007,v0009);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0009,v0007);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0182 = v0007;
    v0167 = v0009;
// end of prologue
    stack[0] = qvalue(elt(env, 1)); // rl_bnfsimpl!*
    v0182 = list2(v0167, v0182);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-1];
    {
        LispObject v0162 = stack[0];
        popv(2);
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(qenv(fn), v0162, v0182);
    }
// error exit handlers
v0189:
    popv(2);
    return nil;
}



// Code for ofsf_smordtable

static LispObject CC_ofsf_smordtable(LispObject env,
                         LispObject v0009, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0097, v0098, v0156;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_smordtable");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0097 = v0007;
    v0098 = v0009;
// end of prologue
    v0156 = elt(env, 1); // ((equal (equal . false) (neq equal . t) (geq equal . t) (leq . false) (greaterp equal . t) (lessp . false)) (neq (equal equal)
// (neq) (geq) (leq leq) (greaterp) (lessp lessp)) (geq (equal . false) (neq geq . t) (geq geq . t) (leq . false) (greaterp
// geq . t) (lessp . false)) (leq (equal equal) (neq) (geq) (leq leq) (greaterp) (lessp lessp)) (greaterp (equal . false) (neq
// greaterp . t) (geq greaterp . t) (leq . false) (greaterp greaterp . t) (lessp . false)) (lessp (equal equal) (neq) (geq)
// (leq leq) (greaterp) (lessp lessp)))
    v0098 = Latsoc(nil, v0098, v0156);
    v0097 = Latsoc(nil, v0097, v0098);
    v0097 = qcdr(v0097);
    return onevalue(v0097);
}



// Code for determinantrd

static LispObject CC_determinantrd(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0104;
    LispObject fn;
    CSL_IGNORE(nil);
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
    v0104 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-1];
    fn = elt(env, 2); // alg_det
    v0104 = (*qfn1(fn))(qenv(fn), v0104);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-1];
    stack[0] = v0104;
    fn = elt(env, 3); // lex
    v0104 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    { LispObject res = stack[0]; popv(2); return onevalue(res); }
// error exit handlers
v0102:
    popv(2);
    return nil;
}



// Code for simp_without_resimp

static LispObject CC_simp_without_resimp(LispObject env,
                         LispObject v0009)
{
    LispObject nil = C_nil;
    LispObject v0018, v0008;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for simp_without_resimp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0009);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0008 = v0009;
// end of prologue
    v0018 = qvalue(elt(env, 1)); // nil
    stack[0] = qvalue(elt(env, 2)); // !*resimp
    qvalue(elt(env, 2)) = v0018; // !*resimp
    v0018 = v0008;
    fn = elt(env, 3); // simp
    v0018 = (*qfn1(fn))(qenv(fn), v0018);
    nil = C_nil;
    if (exception_pending()) goto v0002;
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; // !*resimp
    { popv(2); return onevalue(v0018); }
// error exit handlers
v0002:
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; // !*resimp
    popv(2);
    return nil;
}



// Code for sc_columnscalarproduct

static LispObject CC_sc_columnscalarproduct(LispObject env,
                         LispObject v0009, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0192, v0193, v0194;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sc_columnscalarproduct");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0007,v0009);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0009,v0007);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-2] = v0007;
    stack[-3] = v0009;
// end of prologue
    v0192 = (LispObject)1; // 0
    fn = elt(env, 2); // sc_simp
    v0192 = (*qfn1(fn))(qenv(fn), v0192);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-5];
    stack[0] = v0192;
    v0192 = (LispObject)17; // 1
    stack[-4] = v0192;
    goto v0167;

v0167:
    v0192 = stack[-3];
    fn = elt(env, 3); // fast!-row!-dim
    v0193 = (*qfn1(fn))(qenv(fn), v0192);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-5];
    v0192 = stack[-4];
    v0192 = difference2(v0193, v0192);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-5];
    v0192 = Lminusp(nil, v0192);
    env = stack[-5];
    if (!(v0192 == nil)) { LispObject res = stack[0]; popv(6); return onevalue(res); }
    stack[-1] = stack[0];
    v0194 = stack[-3];
    v0193 = stack[-4];
    v0192 = (LispObject)17; // 1
    fn = elt(env, 4); // sc_getmat
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v0194, v0193, v0192);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-5];
    v0194 = stack[-2];
    v0193 = stack[-4];
    v0192 = (LispObject)17; // 1
    fn = elt(env, 4); // sc_getmat
    v0192 = (*qfnn(fn))(qenv(fn), 3, v0194, v0193, v0192);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-5];
    fn = elt(env, 5); // sc_multsq
    v0192 = (*qfn2(fn))(qenv(fn), stack[0], v0192);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-5];
    fn = elt(env, 6); // sc_addsq
    v0192 = (*qfn2(fn))(qenv(fn), stack[-1], v0192);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-5];
    stack[0] = v0192;
    v0192 = stack[-4];
    v0192 = add1(v0192);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-5];
    stack[-4] = v0192;
    goto v0167;
// error exit handlers
v0169:
    popv(6);
    return nil;
}



// Code for mkexdf

static LispObject CC_mkexdf(LispObject env,
                         LispObject v0009)
{
    LispObject nil = C_nil;
    LispObject v0156, v0155;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mkexdf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0009);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0156 = v0009;
// end of prologue
    v0155 = elt(env, 1); // d
    v0156 = list2(v0155, v0156);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-1];
    stack[0] = v0156;
    fn = elt(env, 2); // opmtch
    v0156 = (*qfn1(fn))(qenv(fn), v0156);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-1];
    v0155 = v0156;
    if (v0156 == nil) goto v0189;
    v0156 = v0155;
    {
        popv(2);
        fn = elt(env, 3); // partitop
        return (*qfn1(fn))(qenv(fn), v0156);
    }

v0189:
    v0156 = stack[0];
    {
        popv(2);
        fn = elt(env, 4); // mkupf
        return (*qfn1(fn))(qenv(fn), v0156);
    }
// error exit handlers
v0166:
    popv(2);
    return nil;
}



// Code for divide!-by!-power!-of!-ten

static LispObject CC_divideKbyKpowerKofKten(LispObject env,
                         LispObject v0009, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0179, v0180, v0196;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for divide-by-power-of-ten");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0007,v0009);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0009,v0007);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0007;
    stack[-1] = v0009;
// end of prologue
    v0180 = stack[0];
    v0179 = (LispObject)1; // 0
    v0179 = (LispObject)lessp2(v0180, v0179);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    v0179 = v0179 ? lisp_true : nil;
    env = stack[-3];
    if (v0179 == nil) goto v0188;
    v0179 = elt(env, 0); // divide!-by!-power!-of!-ten
    {
        popv(4);
        fn = elt(env, 4); // bflerrmsg
        return (*qfn1(fn))(qenv(fn), v0179);
    }

v0188:
    v0179 = qvalue(elt(env, 1)); // bften!*
    stack[-2] = v0179;
    goto v0164;

v0164:
    v0180 = stack[0];
    v0179 = (LispObject)1; // 0
    v0179 = (LispObject)greaterp2(v0180, v0179);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    v0179 = v0179 ? lisp_true : nil;
    env = stack[-3];
    if (v0179 == nil) { LispObject res = stack[-1]; popv(4); return onevalue(res); }
    v0179 = stack[0];
    v0179 = Levenp(nil, v0179);
    env = stack[-3];
    if (!(v0179 == nil)) goto v0198;
    v0196 = stack[-1];
    v0180 = stack[-2];
    v0179 = qvalue(elt(env, 3)); // !:bprec!:
    fn = elt(env, 5); // divide!:
    v0179 = (*qfnn(fn))(qenv(fn), 3, v0196, v0180, v0179);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-3];
    fn = elt(env, 6); // normbf
    v0179 = (*qfn1(fn))(qenv(fn), v0179);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-3];
    stack[-1] = v0179;
    goto v0198;

v0198:
    v0180 = stack[0];
    v0179 = (LispObject)-15; // -1
    fn = elt(env, 7); // lshift
    v0179 = (*qfn2(fn))(qenv(fn), v0180, v0179);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-3];
    stack[0] = v0179;
    v0180 = stack[-2];
    v0179 = stack[-2];
    fn = elt(env, 8); // times!:
    v0180 = (*qfn2(fn))(qenv(fn), v0180, v0179);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-3];
    v0179 = qvalue(elt(env, 3)); // !:bprec!:
    fn = elt(env, 9); // cut!:mt
    v0179 = (*qfn2(fn))(qenv(fn), v0180, v0179);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-3];
    fn = elt(env, 6); // normbf
    v0179 = (*qfn1(fn))(qenv(fn), v0179);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-3];
    stack[-2] = v0179;
    goto v0164;
// error exit handlers
v0197:
    popv(4);
    return nil;
}



// Code for rd!:difference

static LispObject CC_rdTdifference(LispObject env,
                         LispObject v0009, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0114, v0215, v0216;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rd:difference");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0007,v0009);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0009,v0007);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0007;
    stack[-2] = v0009;
// end of prologue
    v0114 = qvalue(elt(env, 1)); // nil
    stack[-3] = v0114;
    v0114 = qvalue(elt(env, 2)); // !*!*roundbf
    if (v0114 == nil) goto v0171;
    v0114 = qvalue(elt(env, 1)); // nil
    goto v0104;

v0104:
    if (v0114 == nil) goto v0079;
    v0215 = elt(env, 3); // !:rd!:
    v0114 = stack[-3];
    popv(5);
    return cons(v0215, v0114);

v0079:
    v0215 = stack[-2];
    v0114 = stack[0];
    fn = elt(env, 5); // convprc2
    v0114 = (*qfn2(fn))(qenv(fn), v0215, v0114);
    nil = C_nil;
    if (exception_pending()) goto v0217;
    env = stack[-4];
    stack[-1] = v0114;
    v0114 = qvalue(elt(env, 4)); // yy!!
    stack[0] = v0114;
    v0114 = stack[-1];
    if (!consp(v0114)) goto v0181;
    v0215 = stack[-1];
    v0114 = stack[0];
    fn = elt(env, 6); // difbf
    v0114 = (*qfn2(fn))(qenv(fn), v0215, v0114);
    nil = C_nil;
    if (exception_pending()) goto v0217;
    env = stack[-4];
    goto v0090;

v0090:
    stack[-2] = v0114;
    v0114 = stack[0];
    if (!consp(v0114)) goto v0218;
    v0114 = stack[0];
    fn = elt(env, 7); // minus!:
    v0114 = (*qfn1(fn))(qenv(fn), v0114);
    nil = C_nil;
    if (exception_pending()) goto v0217;
    env = stack[-4];
    goto v0112;

v0112:
    fn = elt(env, 8); // rdzchk
    v0114 = (*qfnn(fn))(qenv(fn), 3, stack[-2], stack[-1], v0114);
    nil = C_nil;
    if (exception_pending()) goto v0217;
    env = stack[-4];
    {
        popv(5);
        fn = elt(env, 9); // mkround
        return (*qfn1(fn))(qenv(fn), v0114);
    }

v0218:
    v0114 = stack[0];
    v0114 = negate(v0114);
    nil = C_nil;
    if (exception_pending()) goto v0217;
    env = stack[-4];
    goto v0112;

v0181:
    v0215 = stack[-1];
    v0114 = stack[0];
    v0114 = difference2(v0215, v0114);
    nil = C_nil;
    if (exception_pending()) goto v0217;
    env = stack[-4];
    stack[-3] = v0114;
    v0114 = stack[-3];
    fn = elt(env, 10); // fp!-infinite
    v0114 = (*qfn1(fn))(qenv(fn), v0114);
    nil = C_nil;
    if (exception_pending()) goto v0217;
    env = stack[-4];
    if (v0114 == nil) goto v0075;
    fn = elt(env, 11); // rndbfon
    v0114 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0217;
    env = stack[-4];
    v0114 = stack[-1];
    v0114 = Lfloatp(nil, v0114);
    env = stack[-4];
    if (v0114 == nil) goto v0219;
    v0114 = stack[-1];
    fn = elt(env, 12); // fl2bf
    v0114 = (*qfn1(fn))(qenv(fn), v0114);
    nil = C_nil;
    if (exception_pending()) goto v0217;
    env = stack[-4];
    stack[-2] = v0114;
    goto v0151;

v0151:
    stack[-1] = stack[-2];
    v0114 = stack[0];
    v0114 = Lfloatp(nil, v0114);
    env = stack[-4];
    if (v0114 == nil) goto v0220;
    v0114 = stack[0];
    fn = elt(env, 12); // fl2bf
    v0114 = (*qfn1(fn))(qenv(fn), v0114);
    nil = C_nil;
    if (exception_pending()) goto v0217;
    env = stack[-4];
    goto v0221;

v0221:
    stack[0] = v0114;
    fn = elt(env, 6); // difbf
    v0114 = (*qfn2(fn))(qenv(fn), stack[-2], v0114);
    nil = C_nil;
    if (exception_pending()) goto v0217;
    env = stack[-4];
    goto v0090;

v0220:
    v0114 = stack[0];
    if (!consp(v0114)) goto v0222;
    v0114 = stack[0];
    goto v0223;

v0223:
    fn = elt(env, 13); // normbf
    v0114 = (*qfn1(fn))(qenv(fn), v0114);
    nil = C_nil;
    if (exception_pending()) goto v0217;
    env = stack[-4];
    goto v0221;

v0222:
    v0114 = stack[0];
    v0114 = integerp(v0114);
    if (v0114 == nil) goto v0224;
    v0216 = elt(env, 3); // !:rd!:
    v0215 = stack[0];
    v0114 = (LispObject)1; // 0
    v0114 = list2star(v0216, v0215, v0114);
    nil = C_nil;
    if (exception_pending()) goto v0217;
    env = stack[-4];
    goto v0223;

v0224:
    v0114 = stack[0];
    fn = elt(env, 14); // read!:num
    v0114 = (*qfn1(fn))(qenv(fn), v0114);
    nil = C_nil;
    if (exception_pending()) goto v0217;
    env = stack[-4];
    goto v0223;

v0219:
    v0114 = stack[-1];
    if (!consp(v0114)) goto v0225;
    v0114 = stack[-1];
    goto v0087;

v0087:
    fn = elt(env, 13); // normbf
    v0114 = (*qfn1(fn))(qenv(fn), v0114);
    nil = C_nil;
    if (exception_pending()) goto v0217;
    env = stack[-4];
    stack[-2] = v0114;
    goto v0151;

v0225:
    v0114 = stack[-1];
    v0114 = integerp(v0114);
    if (v0114 == nil) goto v0226;
    v0216 = elt(env, 3); // !:rd!:
    v0215 = stack[-1];
    v0114 = (LispObject)1; // 0
    v0114 = list2star(v0216, v0215, v0114);
    nil = C_nil;
    if (exception_pending()) goto v0217;
    env = stack[-4];
    goto v0087;

v0226:
    v0114 = stack[-1];
    fn = elt(env, 14); // read!:num
    v0114 = (*qfn1(fn))(qenv(fn), v0114);
    nil = C_nil;
    if (exception_pending()) goto v0217;
    env = stack[-4];
    goto v0087;

v0075:
    v0114 = stack[-3];
    goto v0090;

v0171:
    v0114 = stack[-2];
    v0114 = qcdr(v0114);
    if (!consp(v0114)) goto v0154;
    v0114 = qvalue(elt(env, 1)); // nil
    goto v0104;

v0154:
    v0114 = stack[0];
    v0114 = qcdr(v0114);
    if (!consp(v0114)) goto v0163;
    v0114 = qvalue(elt(env, 1)); // nil
    goto v0104;

v0163:
    v0114 = stack[-2];
    stack[-1] = qcdr(v0114);
    v0114 = stack[0];
    v0114 = qcdr(v0114);
    fn = elt(env, 15); // safe!-fp!-minus
    v0114 = (*qfn1(fn))(qenv(fn), v0114);
    nil = C_nil;
    if (exception_pending()) goto v0217;
    env = stack[-4];
    fn = elt(env, 16); // safe!-fp!-plus
    v0114 = (*qfn2(fn))(qenv(fn), stack[-1], v0114);
    nil = C_nil;
    if (exception_pending()) goto v0217;
    env = stack[-4];
    stack[-3] = v0114;
    goto v0104;
// error exit handlers
v0217:
    popv(5);
    return nil;
}



// Code for open

static LispObject CC_open(LispObject env,
                         LispObject v0009, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0179, v0180, v0196, v0229;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for open");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0007,v0009);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0009,v0007);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0196 = v0007;
    v0229 = v0009;
// end of prologue
    v0180 = v0196;
    v0179 = elt(env, 1); // input
    if (v0180 == v0179) goto v0153;
    v0180 = v0196;
    v0179 = elt(env, 2); // output
    if (v0180 == v0179) goto v0092;
    v0180 = v0196;
    v0179 = elt(env, 3); // append
    if (v0180 == v0179) goto v0198;
    v0179 = elt(env, 4); // "bad direction ~A in open"
    v0180 = v0196;
    {
        popv(2);
        fn = elt(env, 5); // error
        return (*qfn2(fn))(qenv(fn), v0179, v0180);
    }

v0198:
    stack[0] = v0229;
    v0180 = (LispObject)33; // 2
    v0179 = (LispObject)641; // 40
    v0179 = plus2(v0180, v0179);
    nil = C_nil;
    if (exception_pending()) goto v0181;
    env = stack[-1];
    {
        LispObject v0197 = stack[0];
        popv(2);
        fn = elt(env, 6); // internal!-open
        return (*qfn2(fn))(qenv(fn), v0197, v0179);
    }

v0092:
    stack[0] = v0229;
    v0180 = (LispObject)33; // 2
    v0179 = (LispObject)833; // 52
    v0179 = plus2(v0180, v0179);
    nil = C_nil;
    if (exception_pending()) goto v0181;
    env = stack[-1];
    {
        LispObject v0230 = stack[0];
        popv(2);
        fn = elt(env, 6); // internal!-open
        return (*qfn2(fn))(qenv(fn), v0230, v0179);
    }

v0153:
    v0180 = v0229;
    v0179 = (LispObject)1041; // 65
    {
        popv(2);
        fn = elt(env, 6); // internal!-open
        return (*qfn2(fn))(qenv(fn), v0180, v0179);
    }
// error exit handlers
v0181:
    popv(2);
    return nil;
}



// Code for prepsq!*1

static LispObject CC_prepsqH1(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0325, v0326, v0327;
    LispObject fn;
    LispObject v0010, v0007, v0009;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "prepsq*1");
    va_start(aa, nargs);
    v0009 = va_arg(aa, LispObject);
    v0007 = va_arg(aa, LispObject);
    v0010 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for prepsq*1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0010,v0007,v0009);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0009,v0007,v0010);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[-4] = v0010;
    stack[-5] = v0007;
    stack[-6] = v0009;
// end of prologue
    v0325 = stack[-6];
    if (!consp(v0325)) goto v0167;
    v0325 = stack[-6];
    v0325 = qcar(v0325);
    v0325 = (consp(v0325) ? nil : lisp_true);
    goto v0182;

v0182:
    if (v0325 == nil) goto v0170;
    v0325 = qvalue(elt(env, 3)); // nil
    goto v0168;

v0168:
    if (v0325 == nil) goto v0104;
    v0326 = stack[-5];
    v0325 = (LispObject)17; // 1
    if (v0326 == v0325) goto v0204;
    v0325 = stack[-6];
    v0325 = qcar(v0325);
    v0325 = qcar(v0325);
    v0325 = qcdr(v0325);
    stack[-2] = v0325;
    v0325 = stack[-5];
    stack[-1] = v0325;
    v0325 = stack[-6];
    v0325 = qcar(v0325);
    v0325 = qcar(v0325);
    v0326 = qcar(v0325);
    v0325 = (LispObject)17; // 1
    fn = elt(env, 12); // to
    v0326 = (*qfn2(fn))(qenv(fn), v0326, v0325);
    nil = C_nil;
    if (exception_pending()) goto v0328;
    env = stack[-8];
    v0325 = (LispObject)17; // 1
    v0325 = cons(v0326, v0325);
    nil = C_nil;
    if (exception_pending()) goto v0328;
    env = stack[-8];
    v0325 = ncons(v0325);
    nil = C_nil;
    if (exception_pending()) goto v0328;
    env = stack[-8];
    stack[0] = v0325;
    goto v0329;

v0329:
    v0326 = stack[-1];
    v0325 = stack[0];
    fn = elt(env, 13); // quotfm
    v0325 = (*qfn2(fn))(qenv(fn), v0326, v0325);
    nil = C_nil;
    if (exception_pending()) goto v0328;
    env = stack[-8];
    stack[-7] = v0325;
    if (v0325 == nil) goto v0330;
    v0325 = stack[-7];
    stack[-1] = v0325;
    v0325 = stack[-2];
    v0325 = sub1(v0325);
    nil = C_nil;
    if (exception_pending()) goto v0328;
    env = stack[-8];
    stack[-2] = v0325;
    goto v0329;

v0330:
    v0325 = stack[-6];
    v0325 = qcar(v0325);
    v0326 = qcdr(v0325);
    v0325 = stack[-1];
    stack[0] = cons(v0326, v0325);
    nil = C_nil;
    if (exception_pending()) goto v0328;
    env = stack[-8];
    v0326 = stack[-2];
    v0325 = (LispObject)1; // 0
    v0325 = (LispObject)greaterp2(v0326, v0325);
    nil = C_nil;
    if (exception_pending()) goto v0328;
    v0325 = v0325 ? lisp_true : nil;
    env = stack[-8];
    if (v0325 == nil) goto v0331;
    v0325 = stack[-6];
    v0325 = qcar(v0325);
    v0325 = qcar(v0325);
    v0326 = qcar(v0325);
    v0325 = stack[-2];
    fn = elt(env, 12); // to
    v0326 = (*qfn2(fn))(qenv(fn), v0326, v0325);
    nil = C_nil;
    if (exception_pending()) goto v0328;
    env = stack[-8];
    v0325 = stack[-4];
    v0325 = cons(v0326, v0325);
    nil = C_nil;
    if (exception_pending()) goto v0328;
    env = stack[-8];
    goto v0332;

v0332:
    fn = elt(env, 14); // prepsq!*0
    v0325 = (*qfn2(fn))(qenv(fn), stack[0], v0325);
    nil = C_nil;
    if (exception_pending()) goto v0328;
    env = stack[-8];
    stack[0] = v0325;
    goto v0333;

v0333:
    v0325 = stack[-6];
    v0326 = qcdr(v0325);
    v0325 = stack[-5];
    v0326 = cons(v0326, v0325);
    nil = C_nil;
    if (exception_pending()) goto v0328;
    env = stack[-8];
    v0325 = stack[-4];
    fn = elt(env, 14); // prepsq!*0
    v0325 = (*qfn2(fn))(qenv(fn), v0326, v0325);
    nil = C_nil;
    if (exception_pending()) goto v0328;
    env = stack[-8];
    {
        LispObject v0334 = stack[0];
        popv(9);
        fn = elt(env, 15); // nconc!*
        return (*qfn2(fn))(qenv(fn), v0334, v0325);
    }

v0331:
    v0326 = stack[-2];
    v0325 = (LispObject)1; // 0
    v0325 = (LispObject)lessp2(v0326, v0325);
    nil = C_nil;
    if (exception_pending()) goto v0328;
    v0325 = v0325 ? lisp_true : nil;
    env = stack[-8];
    if (v0325 == nil) goto v0335;
    v0327 = elt(env, 4); // expt
    v0325 = stack[-6];
    v0325 = qcar(v0325);
    v0325 = qcar(v0325);
    v0326 = qcar(v0325);
    v0325 = stack[-2];
    v0326 = list3(v0327, v0326, v0325);
    nil = C_nil;
    if (exception_pending()) goto v0328;
    env = stack[-8];
    v0325 = (LispObject)17; // 1
    fn = elt(env, 16); // mksp
    v0326 = (*qfn2(fn))(qenv(fn), v0326, v0325);
    nil = C_nil;
    if (exception_pending()) goto v0328;
    env = stack[-8];
    v0325 = stack[-4];
    v0325 = cons(v0326, v0325);
    nil = C_nil;
    if (exception_pending()) goto v0328;
    env = stack[-8];
    goto v0332;

v0335:
    v0325 = stack[-4];
    goto v0332;

v0204:
    v0325 = stack[-6];
    v0325 = qcar(v0325);
    v0326 = qcdr(v0325);
    v0325 = stack[-5];
    stack[0] = cons(v0326, v0325);
    nil = C_nil;
    if (exception_pending()) goto v0328;
    env = stack[-8];
    v0325 = stack[-6];
    v0325 = qcar(v0325);
    v0326 = qcar(v0325);
    v0325 = stack[-4];
    v0325 = cons(v0326, v0325);
    nil = C_nil;
    if (exception_pending()) goto v0328;
    env = stack[-8];
    fn = elt(env, 14); // prepsq!*0
    v0325 = (*qfn2(fn))(qenv(fn), stack[0], v0325);
    nil = C_nil;
    if (exception_pending()) goto v0328;
    env = stack[-8];
    stack[0] = v0325;
    goto v0333;

v0104:
    v0325 = stack[-5];
    if (!consp(v0325)) goto v0142;
    v0325 = stack[-5];
    v0325 = qcar(v0325);
    v0325 = (consp(v0325) ? nil : lisp_true);
    goto v0060;

v0060:
    if (!(v0325 == nil)) goto v0054;
    v0325 = qvalue(elt(env, 5)); // kord!*
    stack[-3] = v0325;
    goto v0336;

v0336:
    v0325 = stack[-3];
    if (v0325 == nil) goto v0054;
    v0325 = stack[-3];
    v0325 = qcar(v0325);
    stack[-2] = v0325;
    v0325 = (LispObject)1; // 0
    stack[-1] = v0325;
    v0326 = stack[-2];
    v0325 = (LispObject)17; // 1
    fn = elt(env, 12); // to
    v0326 = (*qfn2(fn))(qenv(fn), v0326, v0325);
    nil = C_nil;
    if (exception_pending()) goto v0328;
    env = stack[-8];
    v0325 = (LispObject)17; // 1
    v0325 = cons(v0326, v0325);
    nil = C_nil;
    if (exception_pending()) goto v0328;
    env = stack[-8];
    v0325 = ncons(v0325);
    nil = C_nil;
    if (exception_pending()) goto v0328;
    env = stack[-8];
    stack[0] = v0325;
    goto v0337;

v0337:
    v0326 = stack[-5];
    v0325 = stack[0];
    fn = elt(env, 13); // quotfm
    v0325 = (*qfn2(fn))(qenv(fn), v0326, v0325);
    nil = C_nil;
    if (exception_pending()) goto v0328;
    env = stack[-8];
    stack[-7] = v0325;
    if (v0325 == nil) goto v0338;
    v0325 = stack[-1];
    v0325 = sub1(v0325);
    nil = C_nil;
    if (exception_pending()) goto v0328;
    env = stack[-8];
    stack[-1] = v0325;
    v0325 = stack[-7];
    stack[-5] = v0325;
    goto v0337;

v0338:
    v0326 = stack[-1];
    v0325 = (LispObject)1; // 0
    v0325 = (LispObject)lessp2(v0326, v0325);
    nil = C_nil;
    if (exception_pending()) goto v0328;
    v0325 = v0325 ? lisp_true : nil;
    env = stack[-8];
    if (v0325 == nil) goto v0339;
    v0327 = elt(env, 4); // expt
    v0326 = stack[-2];
    v0325 = stack[-1];
    v0326 = list3(v0327, v0326, v0325);
    nil = C_nil;
    if (exception_pending()) goto v0328;
    env = stack[-8];
    v0325 = (LispObject)17; // 1
    fn = elt(env, 16); // mksp
    v0326 = (*qfn2(fn))(qenv(fn), v0326, v0325);
    nil = C_nil;
    if (exception_pending()) goto v0328;
    env = stack[-8];
    v0325 = stack[-4];
    v0325 = cons(v0326, v0325);
    nil = C_nil;
    if (exception_pending()) goto v0328;
    env = stack[-8];
    stack[-4] = v0325;
    goto v0339;

v0339:
    v0325 = stack[-3];
    v0325 = qcdr(v0325);
    stack[-3] = v0325;
    goto v0336;

v0054:
    v0325 = stack[-6];
    fn = elt(env, 17); // kernlp
    v0325 = (*qfn1(fn))(qenv(fn), v0325);
    nil = C_nil;
    if (exception_pending()) goto v0328;
    env = stack[-8];
    if (v0325 == nil) goto v0340;
    v0326 = stack[-4];
    v0325 = stack[-6];
    fn = elt(env, 18); // mkkl
    v0325 = (*qfn2(fn))(qenv(fn), v0326, v0325);
    nil = C_nil;
    if (exception_pending()) goto v0328;
    env = stack[-8];
    stack[-6] = v0325;
    v0325 = qvalue(elt(env, 3)); // nil
    stack[-4] = v0325;
    goto v0340;

v0340:
    v0325 = qvalue(elt(env, 6)); // dnl!*
    if (v0325 == nil) goto v0341;
    v0325 = qvalue(elt(env, 7)); // !*allfac
    if (v0325 == nil) goto v0342;
    v0325 = stack[-6];
    fn = elt(env, 19); // ckrn
    v0325 = (*qfn1(fn))(qenv(fn), v0325);
    nil = C_nil;
    if (exception_pending()) goto v0328;
    env = stack[-8];
    goto v0042;

v0042:
    stack[-1] = v0325;
    v0326 = stack[-1];
    v0325 = qvalue(elt(env, 6)); // dnl!*
    fn = elt(env, 20); // ckrn!*
    v0325 = (*qfn2(fn))(qenv(fn), v0326, v0325);
    nil = C_nil;
    if (exception_pending()) goto v0328;
    env = stack[-8];
    stack[-7] = v0325;
    v0326 = stack[-1];
    v0325 = stack[-7];
    fn = elt(env, 21); // quotof
    v0325 = (*qfn2(fn))(qenv(fn), v0326, v0325);
    nil = C_nil;
    if (exception_pending()) goto v0328;
    env = stack[-8];
    v0326 = stack[-6];
    v0325 = stack[-7];
    fn = elt(env, 21); // quotof
    v0325 = (*qfn2(fn))(qenv(fn), v0326, v0325);
    nil = C_nil;
    if (exception_pending()) goto v0328;
    env = stack[-8];
    stack[-6] = v0325;
    v0326 = stack[-5];
    v0325 = stack[-7];
    fn = elt(env, 21); // quotof
    v0325 = (*qfn2(fn))(qenv(fn), v0326, v0325);
    nil = C_nil;
    if (exception_pending()) goto v0328;
    env = stack[-8];
    stack[-5] = v0325;
    goto v0341;

v0341:
    v0325 = qvalue(elt(env, 8)); // upl!*
    if (v0325 == nil) goto v0033;
    v0325 = stack[-5];
    fn = elt(env, 19); // ckrn
    v0325 = (*qfn1(fn))(qenv(fn), v0325);
    nil = C_nil;
    if (exception_pending()) goto v0328;
    env = stack[-8];
    stack[0] = v0325;
    v0326 = stack[0];
    v0325 = qvalue(elt(env, 8)); // upl!*
    fn = elt(env, 20); // ckrn!*
    v0325 = (*qfn2(fn))(qenv(fn), v0326, v0325);
    nil = C_nil;
    if (exception_pending()) goto v0328;
    env = stack[-8];
    stack[-7] = v0325;
    v0326 = stack[0];
    v0325 = stack[-7];
    fn = elt(env, 21); // quotof
    v0325 = (*qfn2(fn))(qenv(fn), v0326, v0325);
    nil = C_nil;
    if (exception_pending()) goto v0328;
    env = stack[-8];
    stack[0] = v0325;
    v0326 = stack[-6];
    v0325 = stack[-7];
    fn = elt(env, 21); // quotof
    v0325 = (*qfn2(fn))(qenv(fn), v0326, v0325);
    nil = C_nil;
    if (exception_pending()) goto v0328;
    env = stack[-8];
    stack[-6] = v0325;
    v0326 = stack[-5];
    v0325 = stack[-7];
    fn = elt(env, 21); // quotof
    v0325 = (*qfn2(fn))(qenv(fn), v0326, v0325);
    nil = C_nil;
    if (exception_pending()) goto v0328;
    env = stack[-8];
    stack[-5] = v0325;
    goto v0343;

v0343:
    stack[-1] = stack[-6];
    v0326 = stack[-5];
    v0325 = stack[0];
    fn = elt(env, 21); // quotof
    v0325 = (*qfn2(fn))(qenv(fn), v0326, v0325);
    nil = C_nil;
    if (exception_pending()) goto v0328;
    env = stack[-8];
    v0325 = cons(stack[-1], v0325);
    nil = C_nil;
    if (exception_pending()) goto v0328;
    env = stack[-8];
    fn = elt(env, 22); // canonsq
    v0325 = (*qfn1(fn))(qenv(fn), v0325);
    nil = C_nil;
    if (exception_pending()) goto v0328;
    env = stack[-8];
    stack[-6] = v0325;
    v0325 = stack[-6];
    v0326 = qcar(v0325);
    v0325 = stack[0];
    fn = elt(env, 21); // quotof
    v0326 = (*qfn2(fn))(qenv(fn), v0326, v0325);
    nil = C_nil;
    if (exception_pending()) goto v0328;
    env = stack[-8];
    v0325 = stack[-6];
    v0325 = qcdr(v0325);
    v0325 = cons(v0326, v0325);
    nil = C_nil;
    if (exception_pending()) goto v0328;
    env = stack[-8];
    stack[-6] = v0325;
    v0325 = qvalue(elt(env, 7)); // !*allfac
    if (v0325 == nil) goto v0015;
    v0325 = stack[-6];
    v0325 = qcar(v0325);
    fn = elt(env, 19); // ckrn
    v0325 = (*qfn1(fn))(qenv(fn), v0325);
    nil = C_nil;
    if (exception_pending()) goto v0328;
    env = stack[-8];
    stack[-1] = v0325;
    v0325 = stack[-6];
    v0325 = qcdr(v0325);
    fn = elt(env, 19); // ckrn
    v0325 = (*qfn1(fn))(qenv(fn), v0325);
    nil = C_nil;
    if (exception_pending()) goto v0328;
    env = stack[-8];
    stack[0] = v0325;
    v0326 = stack[-1];
    v0325 = (LispObject)17; // 1
    if (v0326 == v0325) goto v0005;
    v0325 = qvalue(elt(env, 1)); // t
    goto v0344;

v0344:
    if (v0325 == nil) goto v0345;
    v0326 = stack[-1];
    v0325 = stack[-6];
    v0325 = qcar(v0325);
    if (equal(v0326, v0325)) goto v0346;
    v0325 = qvalue(elt(env, 1)); // t
    goto v0347;

v0347:
    if (v0325 == nil) goto v0015;
    v0325 = stack[-6];
    v0326 = qcdr(v0325);
    v0325 = stack[0];
    fn = elt(env, 21); // quotof
    v0325 = (*qfn2(fn))(qenv(fn), v0326, v0325);
    nil = C_nil;
    if (exception_pending()) goto v0328;
    env = stack[-8];
    stack[-5] = v0325;
    v0325 = stack[-6];
    v0326 = qcar(v0325);
    v0325 = stack[-1];
    fn = elt(env, 21); // quotof
    v0325 = (*qfn2(fn))(qenv(fn), v0326, v0325);
    nil = C_nil;
    if (exception_pending()) goto v0328;
    env = stack[-8];
    stack[-6] = v0325;
    v0326 = stack[-4];
    v0325 = stack[-1];
    fn = elt(env, 18); // mkkl
    v0325 = (*qfn2(fn))(qenv(fn), v0326, v0325);
    nil = C_nil;
    if (exception_pending()) goto v0328;
    env = stack[-8];
    fn = elt(env, 23); // prepf
    v0325 = (*qfn1(fn))(qenv(fn), v0325);
    nil = C_nil;
    if (exception_pending()) goto v0328;
    env = stack[-8];
    stack[-4] = v0325;
    v0325 = stack[0];
    fn = elt(env, 23); // prepf
    v0325 = (*qfn1(fn))(qenv(fn), v0325);
    nil = C_nil;
    if (exception_pending()) goto v0328;
    env = stack[-8];
    stack[-1] = v0325;
    v0326 = stack[-4];
    v0325 = stack[-6];
    fn = elt(env, 24); // addfactors
    v0325 = (*qfn2(fn))(qenv(fn), v0326, v0325);
    nil = C_nil;
    if (exception_pending()) goto v0328;
    env = stack[-8];
    stack[-6] = v0325;
    v0326 = stack[-1];
    v0325 = stack[-5];
    fn = elt(env, 24); // addfactors
    v0325 = (*qfn2(fn))(qenv(fn), v0326, v0325);
    nil = C_nil;
    if (exception_pending()) goto v0328;
    env = stack[-8];
    stack[-5] = v0325;
    v0326 = stack[-5];
    v0325 = (LispObject)17; // 1
    if (v0326 == v0325) goto v0348;
    v0326 = stack[-6];
    v0325 = elt(env, 10); // minus
    if (!consp(v0326)) goto v0349;
    v0326 = qcar(v0326);
    if (!(v0326 == v0325)) goto v0349;
    stack[0] = elt(env, 10); // minus
    v0327 = elt(env, 11); // quotient
    v0325 = stack[-6];
    v0325 = qcdr(v0325);
    v0326 = qcar(v0325);
    v0325 = stack[-5];
    v0325 = list3(v0327, v0326, v0325);
    nil = C_nil;
    if (exception_pending()) goto v0328;
    env = stack[-8];
    v0325 = list2(stack[0], v0325);
    nil = C_nil;
    if (exception_pending()) goto v0328;
    goto v0350;

v0350:
    popv(9);
    return ncons(v0325);

v0349:
    v0327 = elt(env, 11); // quotient
    v0326 = stack[-6];
    v0325 = stack[-5];
    v0325 = list3(v0327, v0326, v0325);
    nil = C_nil;
    if (exception_pending()) goto v0328;
    goto v0350;

v0348:
    v0325 = stack[-6];
    {
        popv(9);
        fn = elt(env, 25); // rmplus
        return (*qfn1(fn))(qenv(fn), v0325);
    }

v0015:
    v0325 = stack[-4];
    if (v0325 == nil) goto v0351;
    v0325 = stack[-4];
    fn = elt(env, 26); // exchk
    stack[0] = (*qfn1(fn))(qenv(fn), v0325);
    nil = C_nil;
    if (exception_pending()) goto v0328;
    env = stack[-8];
    v0325 = stack[-6];
    fn = elt(env, 27); // prepsq
    v0325 = (*qfn1(fn))(qenv(fn), v0325);
    nil = C_nil;
    if (exception_pending()) goto v0328;
    env = stack[-8];
    fn = elt(env, 28); // aconc!*
    v0325 = (*qfn2(fn))(qenv(fn), stack[0], v0325);
    nil = C_nil;
    if (exception_pending()) goto v0328;
    env = stack[-8];
    fn = elt(env, 29); // retimes
    v0325 = (*qfn1(fn))(qenv(fn), v0325);
    nil = C_nil;
    if (exception_pending()) goto v0328;
    popv(9);
    return ncons(v0325);

v0351:
    v0325 = stack[-6];
    fn = elt(env, 27); // prepsq
    v0325 = (*qfn1(fn))(qenv(fn), v0325);
    nil = C_nil;
    if (exception_pending()) goto v0328;
    env = stack[-8];
    {
        popv(9);
        fn = elt(env, 25); // rmplus
        return (*qfn1(fn))(qenv(fn), v0325);
    }

v0346:
    v0326 = stack[0];
    v0325 = stack[-6];
    v0325 = qcdr(v0325);
    v0325 = Lneq(nil, v0326, v0325);
    nil = C_nil;
    if (exception_pending()) goto v0328;
    env = stack[-8];
    goto v0347;

v0345:
    v0325 = qvalue(elt(env, 3)); // nil
    goto v0347;

v0005:
    v0326 = stack[0];
    v0325 = (LispObject)17; // 1
    v0325 = Lneq(nil, v0326, v0325);
    nil = C_nil;
    if (exception_pending()) goto v0328;
    env = stack[-8];
    goto v0344;

v0033:
    v0325 = qvalue(elt(env, 9)); // !*div
    if (v0325 == nil) goto v0024;
    v0325 = stack[-5];
    fn = elt(env, 19); // ckrn
    v0325 = (*qfn1(fn))(qenv(fn), v0325);
    nil = C_nil;
    if (exception_pending()) goto v0328;
    env = stack[-8];
    stack[0] = v0325;
    goto v0343;

v0024:
    v0325 = (LispObject)17; // 1
    stack[0] = v0325;
    goto v0343;

v0342:
    v0325 = (LispObject)17; // 1
    goto v0042;

v0142:
    v0325 = qvalue(elt(env, 1)); // t
    goto v0060;

v0170:
    v0325 = stack[-6];
    v0325 = qcar(v0325);
    v0325 = qcar(v0325);
    v0326 = qcar(v0325);
    v0325 = qvalue(elt(env, 2)); // factors!*
    v0325 = Lmember(nil, v0326, v0325);
    if (!(v0325 == nil)) goto v0168;
    v0325 = stack[-6];
    v0325 = qcar(v0325);
    v0325 = qcar(v0325);
    v0325 = qcar(v0325);
    if (!consp(v0325)) goto v0109;
    v0325 = stack[-6];
    v0325 = qcar(v0325);
    v0325 = qcar(v0325);
    v0325 = qcar(v0325);
    v0326 = qcar(v0325);
    v0325 = qvalue(elt(env, 2)); // factors!*
    v0325 = Lmember(nil, v0326, v0325);
    goto v0168;

v0109:
    v0325 = qvalue(elt(env, 3)); // nil
    goto v0168;

v0167:
    v0325 = qvalue(elt(env, 1)); // t
    goto v0182;
// error exit handlers
v0328:
    popv(9);
    return nil;
}



// Code for num_signsort

static LispObject CC_num_signsort(LispObject env,
                         LispObject v0009)
{
    LispObject nil = C_nil;
    LispObject v0104, v0171;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for num_signsort");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0104 = v0009;
// end of prologue
    v0171 = v0104;
    v0104 = elt(env, 1); // lambda_u9iz36vfudu4
    {
        fn = elt(env, 2); // ad_signsort
        return (*qfn2(fn))(qenv(fn), v0171, v0104);
    }
}



// Code for lambda_u9iz36vfudu4

static LispObject CC_lambda_u9iz36vfudu4(LispObject env,
                         LispObject v0009, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0171, v0102;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lambda_u9iz36vfudu4");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0171 = v0007;
    v0102 = v0009;
// end of prologue
        return Lleq(nil, v0102, v0171);
}



// Code for msolve!-psys1

static LispObject CC_msolveKpsys1(LispObject env,
                         LispObject v0009, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0354, v0152;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for msolve-psys1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0007,v0009);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0009,v0007);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
// copy arguments values to proper place
    stack[-5] = v0007;
    stack[0] = v0009;
// end of prologue
    v0354 = qvalue(elt(env, 1)); // nil
    v0354 = ncons(v0354);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    env = stack[-7];
    v0152 = v0354;
    v0354 = stack[0];
    stack[-4] = v0354;
    goto v0168;

v0168:
    v0354 = stack[-4];
    if (v0354 == nil) { popv(8); return onevalue(v0152); }
    v0354 = stack[-4];
    v0354 = qcar(v0354);
    stack[-3] = v0354;
    v0354 = qvalue(elt(env, 1)); // nil
    stack[-6] = v0354;
    v0354 = v0152;
    stack[-2] = v0354;
    goto v0164;

v0164:
    v0354 = stack[-2];
    if (v0354 == nil) goto v0166;
    v0354 = stack[-2];
    v0354 = qcar(v0354);
    stack[-1] = v0354;
    v0152 = stack[-3];
    v0354 = stack[-1];
    fn = elt(env, 3); // subf
    v0354 = (*qfn2(fn))(qenv(fn), v0152, v0354);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    env = stack[-7];
    v0354 = qcar(v0354);
    fn = elt(env, 4); // moduntag
    v0354 = (*qfn1(fn))(qenv(fn), v0354);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    env = stack[-7];
    fn = elt(env, 5); // general!-reduce!-mod!-p
    v0354 = (*qfn1(fn))(qenv(fn), v0354);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    env = stack[-7];
    v0152 = v0354;
    v0354 = v0152;
    if (v0354 == nil) goto v0202;
    v0354 = v0152;
    if (!consp(v0354)) goto v0194;
    v0354 = v0152;
    v0354 = qcar(v0354);
    v0354 = (consp(v0354) ? nil : lisp_true);
    goto v0193;

v0193:
    if (!(v0354 == nil)) goto v0184;
    v0354 = stack[-5];
    fn = elt(env, 6); // msolve!-poly
    v0354 = (*qfn2(fn))(qenv(fn), v0152, v0354);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    env = stack[-7];
    stack[0] = v0354;
    goto v0229;

v0229:
    v0354 = stack[0];
    if (v0354 == nil) goto v0184;
    v0354 = stack[0];
    v0354 = qcar(v0354);
    v0152 = stack[-1];
    v0152 = Lappend(nil, v0152, v0354);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    env = stack[-7];
    v0354 = stack[-6];
    v0354 = cons(v0152, v0354);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    env = stack[-7];
    stack[-6] = v0354;
    v0354 = stack[0];
    v0354 = qcdr(v0354);
    stack[0] = v0354;
    goto v0229;

v0184:
    v0354 = stack[-2];
    v0354 = qcdr(v0354);
    stack[-2] = v0354;
    goto v0164;

v0194:
    v0354 = qvalue(elt(env, 2)); // t
    goto v0193;

v0202:
    v0152 = stack[-1];
    v0354 = stack[-6];
    v0354 = cons(v0152, v0354);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    env = stack[-7];
    stack[-6] = v0354;
    goto v0184;

v0166:
    v0354 = stack[-6];
    v0152 = v0354;
    v0354 = stack[-4];
    v0354 = qcdr(v0354);
    stack[-4] = v0354;
    goto v0168;
// error exit handlers
v0084:
    popv(8);
    return nil;
}



// Code for assoc2

static LispObject CC_assoc2(LispObject env,
                         LispObject v0009, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0164, v0183, v0170, v0092;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for assoc2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0170 = v0007;
    v0092 = v0009;
// end of prologue

v0001:
    v0164 = v0170;
    if (v0164 == nil) goto v0030;
    v0183 = v0092;
    v0164 = v0170;
    v0164 = qcar(v0164);
    v0164 = qcdr(v0164);
    if (equal(v0183, v0164)) goto v0102;
    v0164 = v0170;
    v0164 = qcdr(v0164);
    v0170 = v0164;
    goto v0001;

v0102:
    v0164 = v0170;
    v0164 = qcar(v0164);
    return onevalue(v0164);

v0030:
    v0164 = qvalue(elt(env, 1)); // nil
    return onevalue(v0164);
}



// Code for xquotient!-mod!-p

static LispObject CC_xquotientKmodKp(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0216, v0310, v0309;
    LispObject fn;
    LispObject v0010, v0007, v0009;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "xquotient-mod-p");
    va_start(aa, nargs);
    v0009 = va_arg(aa, LispObject);
    v0007 = va_arg(aa, LispObject);
    v0010 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for xquotient-mod-p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0010,v0007,v0009);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0009,v0007,v0010);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0010;
    stack[-1] = v0007;
    stack[-2] = v0009;
// end of prologue
    v0216 = stack[-2];
    if (v0216 == nil) goto v0018;
    v0216 = stack[-2];
    if (!consp(v0216)) goto v0182;
    v0216 = stack[-2];
    v0216 = qcar(v0216);
    v0216 = (consp(v0216) ? nil : lisp_true);
    goto v0188;

v0188:
    if (v0216 == nil) goto v0190;
    v0216 = qvalue(elt(env, 2)); // t
    goto v0160;

v0160:
    if (v0216 == nil) goto v0176;
    v0216 = qvalue(elt(env, 1)); // nil
    qvalue(elt(env, 3)) = v0216; // exact!-quotient!-flag
    { popv(5); return onevalue(v0216); }

v0176:
    v0216 = stack[-2];
    v0216 = qcar(v0216);
    v0216 = qcar(v0216);
    v0310 = qcdr(v0216);
    v0216 = stack[-1];
    v0216 = qcar(v0216);
    v0216 = qcar(v0216);
    v0216 = qcdr(v0216);
    if (equal(v0310, v0216)) goto v0180;
    v0216 = stack[-2];
    v0216 = qcar(v0216);
    v0216 = qcar(v0216);
    v0309 = qcar(v0216);
    v0216 = stack[-2];
    v0216 = qcar(v0216);
    v0216 = qcar(v0216);
    v0310 = qcdr(v0216);
    v0216 = stack[-1];
    v0216 = qcar(v0216);
    v0216 = qcar(v0216);
    v0216 = qcdr(v0216);
    v0216 = (LispObject)(int32_t)((int32_t)v0310 - (int32_t)v0216 + TAG_FIXNUM);
    fn = elt(env, 4); // mksp
    stack[-3] = (*qfn2(fn))(qenv(fn), v0309, v0216);
    nil = C_nil;
    if (exception_pending()) goto v0365;
    env = stack[-4];
    v0216 = stack[-2];
    v0216 = qcar(v0216);
    v0310 = qcdr(v0216);
    v0216 = stack[-1];
    v0216 = qcar(v0216);
    v0216 = qcdr(v0216);
    fn = elt(env, 5); // quotient!-mod!-p
    v0216 = (*qfn2(fn))(qenv(fn), v0310, v0216);
    nil = C_nil;
    if (exception_pending()) goto v0365;
    env = stack[-4];
    v0216 = cons(stack[-3], v0216);
    nil = C_nil;
    if (exception_pending()) goto v0365;
    env = stack[-4];
    stack[-3] = v0216;
    v0216 = stack[-2];
    stack[-2] = qcdr(v0216);
    v0216 = stack[-3];
    fn = elt(env, 6); // negate!-term
    v0310 = (*qfn1(fn))(qenv(fn), v0216);
    nil = C_nil;
    if (exception_pending()) goto v0365;
    env = stack[-4];
    v0216 = stack[-1];
    v0216 = qcdr(v0216);
    fn = elt(env, 7); // times!-term!-mod!-p
    v0216 = (*qfn2(fn))(qenv(fn), v0310, v0216);
    nil = C_nil;
    if (exception_pending()) goto v0365;
    env = stack[-4];
    fn = elt(env, 8); // plus!-mod!-p
    v0216 = (*qfn2(fn))(qenv(fn), stack[-2], v0216);
    nil = C_nil;
    if (exception_pending()) goto v0365;
    env = stack[-4];
    stack[-2] = v0216;
    v0309 = stack[-2];
    v0310 = stack[-1];
    v0216 = stack[0];
    v0216 = CC_xquotientKmodKp(env, 3, v0309, v0310, v0216);
    nil = C_nil;
    if (exception_pending()) goto v0365;
    {
        LispObject v0366 = stack[-3];
        popv(5);
        return cons(v0366, v0216);
    }

v0180:
    v0216 = stack[-2];
    v0216 = qcar(v0216);
    v0310 = qcdr(v0216);
    v0216 = stack[-1];
    v0216 = qcar(v0216);
    v0216 = qcdr(v0216);
    fn = elt(env, 5); // quotient!-mod!-p
    v0216 = (*qfn2(fn))(qenv(fn), v0310, v0216);
    nil = C_nil;
    if (exception_pending()) goto v0365;
    env = stack[-4];
    stack[0] = v0216;
    v0216 = stack[0];
    if (v0216 == nil) goto v0367;
    v0310 = stack[0];
    v0216 = stack[-1];
    fn = elt(env, 9); // times!-mod!-p
    v0216 = (*qfn2(fn))(qenv(fn), v0310, v0216);
    nil = C_nil;
    if (exception_pending()) goto v0365;
    env = stack[-4];
    fn = elt(env, 10); // difference!-mod!-p
    v0216 = (*qfn2(fn))(qenv(fn), stack[-2], v0216);
    nil = C_nil;
    if (exception_pending()) goto v0365;
    env = stack[-4];
    goto v0368;

v0368:
    if (v0216 == nil) { LispObject res = stack[0]; popv(5); return onevalue(res); }
    v0216 = qvalue(elt(env, 1)); // nil
    qvalue(elt(env, 3)) = v0216; // exact!-quotient!-flag
    { LispObject res = stack[0]; popv(5); return onevalue(res); }

v0367:
    v0216 = qvalue(elt(env, 2)); // t
    goto v0368;

v0190:
    v0216 = stack[-2];
    v0216 = qcar(v0216);
    v0216 = qcar(v0216);
    v0310 = qcar(v0216);
    v0216 = stack[0];
    if (equal(v0310, v0216)) goto v0178;
    v0216 = qvalue(elt(env, 2)); // t
    goto v0160;

v0178:
    v0216 = stack[-2];
    v0216 = qcar(v0216);
    v0216 = qcar(v0216);
    v0310 = qcdr(v0216);
    v0216 = stack[-1];
    v0216 = qcar(v0216);
    v0216 = qcar(v0216);
    v0216 = qcdr(v0216);
    v0216 = ((intptr_t)v0310 < (intptr_t)v0216) ? lisp_true : nil;
    goto v0160;

v0182:
    v0216 = qvalue(elt(env, 2)); // t
    goto v0188;

v0018:
    v0216 = qvalue(elt(env, 1)); // nil
    { popv(5); return onevalue(v0216); }
// error exit handlers
v0365:
    popv(5);
    return nil;
}



// Code for testord

static LispObject CC_testord(LispObject env,
                         LispObject v0009, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0170, v0092;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for testord");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0007,v0009);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0009,v0007);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0007;
    stack[-1] = v0009;
// end of prologue

v0001:
    v0170 = stack[-1];
    if (v0170 == nil) goto v0030;
    v0170 = stack[-1];
    v0092 = qcar(v0170);
    v0170 = stack[0];
    v0170 = qcar(v0170);
    v0170 = (LispObject)lesseq2(v0092, v0170);
    nil = C_nil;
    if (exception_pending()) goto v0191;
    v0170 = v0170 ? lisp_true : nil;
    env = stack[-2];
    if (v0170 == nil) goto v0166;
    v0170 = stack[-1];
    v0170 = qcdr(v0170);
    stack[-1] = v0170;
    v0170 = stack[0];
    v0170 = qcdr(v0170);
    stack[0] = v0170;
    goto v0001;

v0166:
    v0170 = qvalue(elt(env, 2)); // nil
    { popv(3); return onevalue(v0170); }

v0030:
    v0170 = qvalue(elt(env, 1)); // t
    { popv(3); return onevalue(v0170); }
// error exit handlers
v0191:
    popv(3);
    return nil;
}



// Code for ofsf_optsplitterm

static LispObject CC_ofsf_optsplitterm(LispObject env,
                         LispObject v0009, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0229, v0323, v0181;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_optsplitterm");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0007,v0009);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0009,v0007);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0007;
    stack[-3] = v0009;
// end of prologue
    v0323 = stack[-3];
    v0229 = stack[0];
    fn = elt(env, 5); // sfto_reorder
    v0229 = (*qfn2(fn))(qenv(fn), v0323, v0229);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-5];
    stack[-3] = v0229;
    v0323 = stack[-3];
    v0229 = stack[0];
    fn = elt(env, 6); // degr
    v0323 = (*qfn2(fn))(qenv(fn), v0323, v0229);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-5];
    stack[-4] = v0323;
    v0229 = (LispObject)1; // 0
    if (v0323 == v0229) goto v0154;
    v0323 = stack[-4];
    v0229 = (LispObject)17; // 1
    v0229 = (LispObject)greaterp2(v0323, v0229);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    v0229 = v0229 ? lisp_true : nil;
    env = stack[-5];
    if (v0229 == nil) goto v0091;
    stack[-2] = elt(env, 2); // "ofsf_optsplitterm:"
    stack[-1] = stack[0];
    stack[0] = elt(env, 3); // "has degree"
    v0181 = stack[-4];
    v0323 = elt(env, 4); // "in"
    v0229 = stack[-3];
    v0229 = list3(v0181, v0323, v0229);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-5];
    v0229 = list3star(stack[-2], stack[-1], stack[0], v0229);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-5];
    fn = elt(env, 7); // rederr
    v0229 = (*qfn1(fn))(qenv(fn), v0229);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-5];
    goto v0091;

v0091:
    v0229 = stack[-3];
    v0229 = qcar(v0229);
    v0229 = qcdr(v0229);
    fn = elt(env, 8); // reorder
    stack[0] = (*qfn1(fn))(qenv(fn), v0229);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-5];
    v0229 = stack[-3];
    v0229 = qcdr(v0229);
    fn = elt(env, 8); // reorder
    v0229 = (*qfn1(fn))(qenv(fn), v0229);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    {
        LispObject v0204 = stack[0];
        popv(6);
        return cons(v0204, v0229);
    }

v0154:
    v0229 = qvalue(elt(env, 1)); // nil
    { popv(6); return onevalue(v0229); }
// error exit handlers
v0214:
    popv(6);
    return nil;
}



// Code for omattrir

static LispObject CC_omattrir(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0090, v0091, v0080;
    LispObject fn;
    CSL_IGNORE(nil);
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
    v0090 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[-2];
    fn = elt(env, 7); // omatpir
    v0090 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[-2];
    stack[-1] = v0090;
    fn = elt(env, 6); // lex
    v0090 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[-2];
    fn = elt(env, 8); // omobj
    v0090 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[-2];
    stack[0] = v0090;
    fn = elt(env, 6); // lex
    v0090 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[-2];
    v0090 = elt(env, 1); // (!/ o m a t t r)
    fn = elt(env, 9); // checktag
    v0090 = (*qfn1(fn))(qenv(fn), v0090);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[-2];
    v0090 = stack[-1];
    v0090 = Lconsp(nil, v0090);
    env = stack[-2];
    if (v0090 == nil) goto v0160;
    v0090 = stack[-1];
    v0090 = qcar(v0090);
    v0090 = qcdr(v0090);
    v0091 = qcar(v0090);
    v0090 = elt(env, 2); // csymbol
    if (!(v0091 == v0090)) goto v0160;
    v0091 = stack[0];
    v0090 = qvalue(elt(env, 3)); // nil
    v0080 = qvalue(elt(env, 3)); // nil
    popv(3);
    return list2star(v0091, v0090, v0080);

v0160:
    v0090 = stack[0];
    if (is_number(v0090)) goto v0093;
    v0080 = elt(env, 5); // ci
    v0091 = stack[-1];
    v0090 = stack[0];
    popv(3);
    return list3(v0080, v0091, v0090);

v0093:
    v0080 = elt(env, 4); // cn
    v0091 = stack[-1];
    v0090 = stack[0];
    popv(3);
    return list3(v0080, v0091, v0090);
// error exit handlers
v0174:
    popv(3);
    return nil;
}



// Code for sptransmat

static LispObject CC_sptransmat(LispObject env,
                         LispObject v0009)
{
    LispObject nil = C_nil;
    LispObject v0374, v0076, v0375, v0376;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sptransmat");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0009);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
// copy arguments values to proper place
    stack[-1] = v0009;
// end of prologue
    v0374 = stack[-1];
    v0374 = Lconsp(nil, v0374);
    env = stack[-7];
    if (v0374 == nil) goto v0162;
    v0374 = stack[-1];
    stack[0] = v0374;
    v0374 = stack[-1];
    fn = elt(env, 3); // matlength
    v0374 = (*qfn1(fn))(qenv(fn), v0374);
    nil = C_nil;
    if (exception_pending()) goto v0330;
    env = stack[-7];
    v0374 = qcdr(v0374);
    goto v0160;

v0160:
    v0076 = (LispObject)1; // 0
    stack[-6] = v0076;
    v0076 = (LispObject)1; // 0
    stack[-5] = v0076;
    v0076 = v0374;
    stack[-1] = qcar(v0076);
    v0076 = elt(env, 1); // spm
    v0374 = cons(v0076, v0374);
    nil = C_nil;
    if (exception_pending()) goto v0330;
    env = stack[-7];
    fn = elt(env, 4); // mkempspmat
    v0374 = (*qfn2(fn))(qenv(fn), stack[-1], v0374);
    nil = C_nil;
    if (exception_pending()) goto v0330;
    env = stack[-7];
    stack[-2] = v0374;
    v0374 = qvalue(elt(env, 2)); // nil
    v0374 = ncons(v0374);
    nil = C_nil;
    if (exception_pending()) goto v0330;
    env = stack[-7];
    v0374 = ncons(v0374);
    nil = C_nil;
    if (exception_pending()) goto v0330;
    env = stack[-7];
    stack[-3] = v0374;
    v0374 = stack[0];
    v0374 = qcdr(v0374);
    stack[-1] = v0374;
    goto v0195;

v0195:
    v0374 = stack[-1];
    if (v0374 == nil) { LispObject res = stack[-2]; popv(8); return onevalue(res); }
    v0374 = stack[-1];
    v0374 = qcar(v0374);
    stack[0] = v0374;
    v0374 = stack[-6];
    v0374 = add1(v0374);
    nil = C_nil;
    if (exception_pending()) goto v0330;
    env = stack[-7];
    stack[-6] = v0374;
    v0374 = stack[0];
    stack[0] = v0374;
    goto v0080;

v0080:
    v0374 = stack[0];
    if (v0374 == nil) goto v0091;
    v0374 = stack[0];
    v0374 = qcar(v0374);
    stack[-4] = v0374;
    v0374 = stack[-5];
    v0374 = add1(v0374);
    nil = C_nil;
    if (exception_pending()) goto v0330;
    env = stack[-7];
    stack[-5] = v0374;
    v0076 = stack[-4];
    v0374 = (LispObject)1; // 0
    if (v0076 == v0374) goto v0230;
    v0375 = stack[-5];
    v0076 = stack[-4];
    v0374 = stack[-3];
    v0374 = acons(v0375, v0076, v0374);
    nil = C_nil;
    if (exception_pending()) goto v0330;
    env = stack[-7];
    stack[-3] = v0374;
    goto v0230;

v0230:
    v0374 = stack[0];
    v0374 = qcdr(v0374);
    stack[0] = v0374;
    goto v0080;

v0091:
    v0374 = stack[-3];
    v0374 = Lreverse(nil, v0374);
    nil = C_nil;
    if (exception_pending()) goto v0330;
    env = stack[-7];
    stack[-3] = v0374;
    stack[0] = stack[-3];
    v0374 = qvalue(elt(env, 2)); // nil
    v0374 = ncons(v0374);
    nil = C_nil;
    if (exception_pending()) goto v0330;
    env = stack[-7];
    v0374 = ncons(v0374);
    nil = C_nil;
    if (exception_pending()) goto v0330;
    env = stack[-7];
    if (equal(stack[0], v0374)) goto v0086;
    v0076 = stack[-2];
    v0374 = stack[-6];
    v0376 = list2(v0076, v0374);
    nil = C_nil;
    if (exception_pending()) goto v0330;
    env = stack[-7];
    v0375 = stack[-3];
    v0076 = stack[-2];
    v0374 = qvalue(elt(env, 2)); // nil
    fn = elt(env, 5); // letmtr3
    v0374 = (*qfnn(fn))(qenv(fn), 4, v0376, v0375, v0076, v0374);
    nil = C_nil;
    if (exception_pending()) goto v0330;
    env = stack[-7];
    goto v0086;

v0086:
    v0374 = (LispObject)1; // 0
    stack[-5] = v0374;
    v0374 = qvalue(elt(env, 2)); // nil
    v0374 = ncons(v0374);
    nil = C_nil;
    if (exception_pending()) goto v0330;
    env = stack[-7];
    v0374 = ncons(v0374);
    nil = C_nil;
    if (exception_pending()) goto v0330;
    env = stack[-7];
    stack[-3] = v0374;
    v0374 = stack[-1];
    v0374 = qcdr(v0374);
    stack[-1] = v0374;
    goto v0195;

v0162:
    v0374 = stack[-1];
    fn = elt(env, 6); // aeval
    v0374 = (*qfn1(fn))(qenv(fn), v0374);
    nil = C_nil;
    if (exception_pending()) goto v0330;
    env = stack[-7];
    stack[0] = v0374;
    v0374 = stack[-1];
    fn = elt(env, 6); // aeval
    v0374 = (*qfn1(fn))(qenv(fn), v0374);
    nil = C_nil;
    if (exception_pending()) goto v0330;
    env = stack[-7];
    fn = elt(env, 3); // matlength
    v0374 = (*qfn1(fn))(qenv(fn), v0374);
    nil = C_nil;
    if (exception_pending()) goto v0330;
    env = stack[-7];
    v0374 = qcdr(v0374);
    goto v0160;
// error exit handlers
v0330:
    popv(8);
    return nil;
}



// Code for greatertype

static LispObject CC_greatertype(LispObject env,
                         LispObject v0009, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0199, v0200, v0355;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for greatertype");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0007,v0009);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0009,v0007);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[-5] = v0007;
    stack[-6] = v0009;
// end of prologue
    stack[-4] = nil;
    stack[-3] = nil;
    stack[-2] = nil;
    stack[-1] = nil;
    v0199 = qvalue(elt(env, 1)); // optlang!*
    if (v0199 == nil) goto v0098;
    v0199 = qvalue(elt(env, 1)); // optlang!*
    v0200 = v0199;
    goto v0153;

v0153:
    v0199 = elt(env, 3); // conversion
    v0199 = get(v0200, v0199);
    env = stack[-8];
    fn = elt(env, 6); // eval
    v0199 = (*qfn1(fn))(qenv(fn), v0199);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-8];
    stack[-7] = v0199;
    v0199 = stack[-7];
    v0200 = qcar(v0199);
    v0199 = stack[-5];
    if (equal(v0200, v0199)) goto v0183;
    v0199 = stack[-7];
    v0200 = qcar(v0199);
    v0199 = stack[-6];
    if (!(equal(v0200, v0199))) goto v0198;
    v0199 = qvalue(elt(env, 5)); // nil
    stack[-1] = v0199;
    { LispObject res = stack[-1]; popv(9); return onevalue(res); }

v0198:
    v0199 = stack[-7];
    v0199 = qcdr(v0199);
    stack[-7] = v0199;
    if (v0199 == nil) { LispObject res = stack[-1]; popv(9); return onevalue(res); }
    v0199 = stack[-4];
    if (!(v0199 == nil)) { LispObject res = stack[-1]; popv(9); return onevalue(res); }
    v0199 = stack[-7];
    v0199 = qcar(v0199);
    v0355 = v0199;
    goto v0091;

v0091:
    v0199 = v0355;
    if (v0199 == nil) goto v0090;
    v0199 = stack[-2];
    if (!(v0199 == nil)) goto v0090;
    v0199 = v0355;
    v0200 = qcar(v0199);
    v0199 = stack[-6];
    if (!(equal(v0200, v0199))) goto v0367;
    v0199 = qvalue(elt(env, 4)); // t
    stack[-3] = v0199;
    goto v0367;

v0367:
    v0199 = v0355;
    v0200 = qcar(v0199);
    v0199 = stack[-5];
    if (equal(v0200, v0199)) goto v0361;
    v0199 = v0355;
    v0199 = qcdr(v0199);
    v0355 = v0199;
    goto v0091;

v0361:
    v0199 = qvalue(elt(env, 4)); // t
    stack[-2] = v0199;
    goto v0091;

v0090:
    v0199 = stack[-2];
    if (v0199 == nil) goto v0379;
    v0199 = v0355;
    v0199 = qcdr(v0199);
    v0355 = v0199;
    goto v0380;

v0380:
    v0199 = v0355;
    if (v0199 == nil) goto v0379;
    v0199 = stack[-1];
    if (!(v0199 == nil)) goto v0379;
    v0199 = v0355;
    v0200 = qcar(v0199);
    v0199 = stack[-6];
    if (equal(v0200, v0199)) goto v0358;
    v0199 = v0355;
    v0199 = qcdr(v0199);
    v0355 = v0199;
    goto v0380;

v0358:
    v0199 = qvalue(elt(env, 4)); // t
    stack[-1] = v0199;
    stack[-3] = v0199;
    goto v0380;

v0379:
    v0199 = stack[-3];
    if (v0199 == nil) goto v0207;
    v0199 = stack[-2];
    if (!(v0199 == nil)) goto v0207;

v0330:
    stack[0] = (LispObject)65; // 4
    v0200 = stack[-6];
    v0199 = stack[-5];
    v0199 = cons(v0200, v0199);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-8];
    fn = elt(env, 7); // typerror
    v0199 = (*qfn2(fn))(qenv(fn), stack[0], v0199);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-8];
    goto v0198;

v0207:
    v0199 = stack[-3];
    if (v0199 == nil) goto v0376;
    v0199 = qvalue(elt(env, 5)); // nil
    goto v0375;

v0375:
    if (!(v0199 == nil)) goto v0330;
    v0199 = stack[-3];
    if (v0199 == nil) goto v0198;
    v0199 = stack[-2];
    if (v0199 == nil) goto v0198;
    v0199 = qvalue(elt(env, 4)); // t
    stack[-4] = v0199;
    goto v0198;

v0376:
    v0199 = stack[-2];
    goto v0375;

v0183:
    v0199 = qvalue(elt(env, 4)); // t
    stack[-1] = v0199;
    { LispObject res = stack[-1]; popv(9); return onevalue(res); }

v0098:
    v0199 = elt(env, 2); // fortran
    v0200 = v0199;
    goto v0153;
// error exit handlers
v0115:
    popv(9);
    return nil;
}



// Code for vdpcleanup

static LispObject CC_vdpcleanup(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0173;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "vdpcleanup");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vdpcleanup");
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
    v0173 = qvalue(elt(env, 1)); // nil
    v0173 = ncons(v0173);
    nil = C_nil;
    if (exception_pending()) goto v0000;
    env = stack[0];
    qvalue(elt(env, 2)) = v0173; // dipevlist!*
    { popv(1); return onevalue(v0173); }
// error exit handlers
v0000:
    popv(1);
    return nil;
}



// Code for wedgef

static LispObject CC_wedgef(LispObject env,
                         LispObject v0009)
{
    LispObject nil = C_nil;
    LispObject v0387, v0388, v0389;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for wedgef");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0009);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0009;
// end of prologue
    v0387 = stack[-1];
    fn = elt(env, 8); // dim!<deg
    v0387 = (*qfn1(fn))(qenv(fn), v0387);
    nil = C_nil;
    if (exception_pending()) goto v0390;
    env = stack[-3];
    if (v0387 == nil) goto v0102;
    v0387 = qvalue(elt(env, 1)); // nil
    { popv(4); return onevalue(v0387); }

v0102:
    v0387 = stack[-1];
    v0388 = qcar(v0387);
    v0387 = elt(env, 2); // hodge
    if (!consp(v0388)) goto v0391;
    v0388 = qcar(v0388);
    if (!(v0388 == v0387)) goto v0391;
    v0387 = stack[-1];
    v0387 = qcar(v0387);
    v0387 = qcdr(v0387);
    v0387 = qcar(v0387);
    fn = elt(env, 9); // deg!*form
    v0387 = (*qfn1(fn))(qenv(fn), v0387);
    nil = C_nil;
    if (exception_pending()) goto v0390;
    env = stack[-3];
    stack[-2] = v0387;
    stack[0] = stack[-2];
    v0387 = stack[-1];
    v0387 = qcdr(v0387);
    fn = elt(env, 10); // deg!*farg
    v0387 = (*qfn1(fn))(qenv(fn), v0387);
    nil = C_nil;
    if (exception_pending()) goto v0390;
    env = stack[-3];
    if (equal(stack[0], v0387)) goto v0187;
    v0387 = stack[-1];
    {
        popv(4);
        fn = elt(env, 11); // mkwedge
        return (*qfn1(fn))(qenv(fn), v0387);
    }

v0187:
    v0387 = stack[-1];
    v0387 = qcar(v0387);
    v0387 = qcdr(v0387);
    v0389 = qcar(v0387);
    v0388 = (LispObject)17; // 1
    v0387 = (LispObject)17; // 1
    v0387 = list2star(v0389, v0388, v0387);
    nil = C_nil;
    if (exception_pending()) goto v0390;
    env = stack[-3];
    stack[0] = ncons(v0387);
    nil = C_nil;
    if (exception_pending()) goto v0390;
    env = stack[-3];
    v0387 = stack[-1];
    v0387 = qcdr(v0387);
    v0387 = qcdr(v0387);
    if (v0387 == nil) goto v0196;
    v0387 = stack[-1];
    v0387 = qcdr(v0387);
    fn = elt(env, 12); // mkuniquewedge1
    v0387 = (*qfn1(fn))(qenv(fn), v0387);
    nil = C_nil;
    if (exception_pending()) goto v0390;
    env = stack[-3];
    goto v0203;

v0203:
    fn = elt(env, 13); // hodgepf
    v0387 = (*qfn1(fn))(qenv(fn), v0387);
    nil = C_nil;
    if (exception_pending()) goto v0390;
    env = stack[-3];
    fn = elt(env, 14); // mkunarywedge
    v0387 = (*qfn1(fn))(qenv(fn), v0387);
    nil = C_nil;
    if (exception_pending()) goto v0390;
    env = stack[-3];
    fn = elt(env, 15); // wedgepf2
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[0], v0387);
    nil = C_nil;
    if (exception_pending()) goto v0390;
    env = stack[-3];
    stack[0] = stack[-2];
    v0387 = qvalue(elt(env, 3)); // dimex!*
    fn = elt(env, 16); // negf
    v0387 = (*qfn1(fn))(qenv(fn), v0387);
    nil = C_nil;
    if (exception_pending()) goto v0390;
    env = stack[-3];
    fn = elt(env, 17); // addf
    v0387 = (*qfn2(fn))(qenv(fn), stack[-2], v0387);
    nil = C_nil;
    if (exception_pending()) goto v0390;
    env = stack[-3];
    fn = elt(env, 18); // multf
    v0387 = (*qfn2(fn))(qenv(fn), stack[0], v0387);
    nil = C_nil;
    if (exception_pending()) goto v0390;
    env = stack[-3];
    fn = elt(env, 19); // mksgnsq
    v0387 = (*qfn1(fn))(qenv(fn), v0387);
    nil = C_nil;
    if (exception_pending()) goto v0390;
    env = stack[-3];
    {
        LispObject v0303 = stack[-1];
        popv(4);
        fn = elt(env, 20); // multpfsq
        return (*qfn2(fn))(qenv(fn), v0303, v0387);
    }

v0196:
    v0387 = stack[-1];
    v0387 = qcdr(v0387);
    v0389 = qcar(v0387);
    v0388 = (LispObject)17; // 1
    v0387 = (LispObject)17; // 1
    v0387 = list2star(v0389, v0388, v0387);
    nil = C_nil;
    if (exception_pending()) goto v0390;
    env = stack[-3];
    v0387 = ncons(v0387);
    nil = C_nil;
    if (exception_pending()) goto v0390;
    env = stack[-3];
    goto v0203;

v0391:
    v0387 = stack[-1];
    v0388 = qcar(v0387);
    v0387 = elt(env, 4); // d
    if (!consp(v0388)) goto v0313;
    v0388 = qcar(v0388);
    if (!(v0388 == v0387)) goto v0313;
    v0388 = elt(env, 4); // d
    v0387 = elt(env, 5); // noxpnd
    v0387 = Lflagp(nil, v0388, v0387);
    env = stack[-3];
    if (v0387 == nil) goto v0372;
    v0387 = qvalue(elt(env, 6)); // t
    goto v0083;

v0083:
    if (v0387 == nil) goto v0392;
    v0387 = stack[-1];
    v0387 = qcar(v0387);
    v0387 = qcdr(v0387);
    v0388 = qcar(v0387);
    v0387 = stack[-1];
    v0387 = qcdr(v0387);
    v0387 = cons(v0388, v0387);
    nil = C_nil;
    if (exception_pending()) goto v0390;
    env = stack[-3];
    fn = elt(env, 21); // dwedge
    v0387 = (*qfn1(fn))(qenv(fn), v0387);
    nil = C_nil;
    if (exception_pending()) goto v0390;
    env = stack[-3];
    fn = elt(env, 14); // mkunarywedge
    stack[-2] = (*qfn1(fn))(qenv(fn), v0387);
    nil = C_nil;
    if (exception_pending()) goto v0390;
    env = stack[-3];
    v0387 = stack[-1];
    v0387 = qcar(v0387);
    v0387 = qcdr(v0387);
    v0389 = qcar(v0387);
    v0388 = (LispObject)17; // 1
    v0387 = (LispObject)17; // 1
    v0387 = list2star(v0389, v0388, v0387);
    nil = C_nil;
    if (exception_pending()) goto v0390;
    env = stack[-3];
    stack[0] = ncons(v0387);
    nil = C_nil;
    if (exception_pending()) goto v0390;
    env = stack[-3];
    v0387 = stack[-1];
    v0387 = qcdr(v0387);
    v0387 = qcdr(v0387);
    if (v0387 == nil) goto v0393;
    v0387 = stack[-1];
    v0387 = qcdr(v0387);
    fn = elt(env, 21); // dwedge
    v0387 = (*qfn1(fn))(qenv(fn), v0387);
    nil = C_nil;
    if (exception_pending()) goto v0390;
    env = stack[-3];
    goto v0394;

v0394:
    fn = elt(env, 14); // mkunarywedge
    v0387 = (*qfn1(fn))(qenv(fn), v0387);
    nil = C_nil;
    if (exception_pending()) goto v0390;
    env = stack[-3];
    fn = elt(env, 15); // wedgepf2
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v0387);
    nil = C_nil;
    if (exception_pending()) goto v0390;
    env = stack[-3];
    v0387 = stack[-1];
    v0387 = qcar(v0387);
    v0387 = qcdr(v0387);
    v0387 = qcar(v0387);
    fn = elt(env, 9); // deg!*form
    v0387 = (*qfn1(fn))(qenv(fn), v0387);
    nil = C_nil;
    if (exception_pending()) goto v0390;
    env = stack[-3];
    fn = elt(env, 19); // mksgnsq
    v0387 = (*qfn1(fn))(qenv(fn), v0387);
    nil = C_nil;
    if (exception_pending()) goto v0390;
    env = stack[-3];
    fn = elt(env, 22); // negsq
    v0387 = (*qfn1(fn))(qenv(fn), v0387);
    nil = C_nil;
    if (exception_pending()) goto v0390;
    env = stack[-3];
    fn = elt(env, 20); // multpfsq
    v0387 = (*qfn2(fn))(qenv(fn), stack[0], v0387);
    nil = C_nil;
    if (exception_pending()) goto v0390;
    env = stack[-3];
    {
        LispObject v0304 = stack[-2];
        popv(4);
        fn = elt(env, 23); // addpf
        return (*qfn2(fn))(qenv(fn), v0304, v0387);
    }

v0393:
    v0387 = stack[-1];
    v0387 = qcdr(v0387);
    v0387 = qcar(v0387);
    fn = elt(env, 24); // exdfk
    v0387 = (*qfn1(fn))(qenv(fn), v0387);
    nil = C_nil;
    if (exception_pending()) goto v0390;
    env = stack[-3];
    goto v0394;

v0392:
    v0387 = stack[-1];
    {
        popv(4);
        fn = elt(env, 11); // mkwedge
        return (*qfn1(fn))(qenv(fn), v0387);
    }

v0372:
    v0388 = qvalue(elt(env, 7)); // lftshft!*
    v0387 = stack[-1];
    v0387 = qcar(v0387);
    v0387 = qcdr(v0387);
    v0387 = qcar(v0387);
    fn = elt(env, 25); // smemqlp
    v0387 = (*qfn2(fn))(qenv(fn), v0388, v0387);
    nil = C_nil;
    if (exception_pending()) goto v0390;
    env = stack[-3];
    goto v0083;

v0313:
    v0387 = qvalue(elt(env, 1)); // nil
    goto v0083;
// error exit handlers
v0390:
    popv(4);
    return nil;
}



// Code for bflessp

static LispObject CC_bflessp(LispObject env,
                         LispObject v0009, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0155, v0163, v0166;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for bflessp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0163 = v0007;
    v0166 = v0009;
// end of prologue
    v0155 = v0166;
    if (!consp(v0155)) goto v0002;
    v0155 = v0163;
    v0163 = v0166;
    {
        fn = elt(env, 1); // grpbf
        return (*qfn2(fn))(qenv(fn), v0155, v0163);
    }

v0002:
    v0155 = v0166;
        return Llessp(nil, v0155, v0163);
}



// Code for calc_den_tar

static LispObject CC_calc_den_tar(LispObject env,
                         LispObject v0009, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0166, v0164;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for calc_den_tar");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0007,v0009);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0009,v0007);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// copy arguments values to proper place
    v0166 = v0007;
    v0164 = v0009;
// end of prologue
    fn = elt(env, 1); // denlist
    v0166 = (*qfn2(fn))(qenv(fn), v0164, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[0];
    v0164 = v0166;
    v0166 = v0164;
    if (v0166 == nil) goto v0168;
    v0166 = v0164;
    v0166 = qcdr(v0166);
    if (v0166 == nil) goto v0182;
    v0166 = v0164;
    {
        popv(1);
        fn = elt(env, 2); // constimes
        return (*qfn1(fn))(qenv(fn), v0166);
    }

v0182:
    v0166 = v0164;
    v0166 = qcar(v0166);
    { popv(1); return onevalue(v0166); }

v0168:
    v0166 = (LispObject)17; // 1
    { popv(1); return onevalue(v0166); }
// error exit handlers
v0183:
    popv(1);
    return nil;
}



// Code for log_freevars

static LispObject CC_log_freevars(LispObject env,
                         LispObject v0009, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0400, v0401, v0402;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for log_freevars");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0007,v0009);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0009,v0007);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0007;
    v0401 = v0009;
// end of prologue
    v0400 = stack[0];
    if (!consp(v0400)) goto v0001;
    v0402 = stack[0];
    v0400 = elt(env, 7); // quote
    if (!consp(v0402)) goto v0219;
    v0402 = qcar(v0402);
    if (!(v0402 == v0400)) goto v0219;
    v0400 = qvalue(elt(env, 1)); // t
    goto v0213;

v0213:
    if (v0400 == nil) goto v0221;
    v0400 = qvalue(elt(env, 3)); // nil
    { popv(2); return onevalue(v0400); }

v0221:
    v0402 = stack[0];
    v0400 = elt(env, 10); // prog
    if (!consp(v0402)) goto v0224;
    v0402 = qcar(v0402);
    if (!(v0402 == v0400)) goto v0224;
    v0400 = stack[0];
    v0400 = qcdr(v0400);
    v0400 = qcar(v0400);
    v0402 = Lappend(nil, v0400, v0401);
    nil = C_nil;
    if (exception_pending()) goto v0403;
    env = stack[-1];
    v0400 = stack[0];
    v0401 = qcdr(v0400);
    v0400 = qvalue(elt(env, 1)); // t
    {
        popv(2);
        fn = elt(env, 13); // log_freevars_list
        return (*qfnn(fn))(qenv(fn), 3, v0402, v0401, v0400);
    }

v0224:
    v0402 = stack[0];
    v0400 = elt(env, 11); // lambda
    if (!consp(v0402)) goto v0216;
    v0402 = qcar(v0402);
    if (!(v0402 == v0400)) goto v0216;
    v0400 = stack[0];
    v0400 = qcdr(v0400);
    v0400 = qcar(v0400);
    v0402 = Lappend(nil, v0400, v0401);
    nil = C_nil;
    if (exception_pending()) goto v0403;
    env = stack[-1];
    v0400 = stack[0];
    v0401 = qcdr(v0400);
    v0400 = qvalue(elt(env, 3)); // nil
    {
        popv(2);
        fn = elt(env, 13); // log_freevars_list
        return (*qfnn(fn))(qenv(fn), 3, v0402, v0401, v0400);
    }

v0216:
    v0402 = stack[0];
    v0400 = elt(env, 12); // cond
    if (!consp(v0402)) goto v0114;
    v0402 = qcar(v0402);
    if (!(v0402 == v0400)) goto v0114;
    v0400 = stack[0];
    v0400 = qcdr(v0400);
    {
        popv(2);
        fn = elt(env, 14); // log_freevars_list_list
        return (*qfn2(fn))(qenv(fn), v0401, v0400);
    }

v0114:
    v0400 = stack[0];
    v0400 = qcar(v0400);
    if (!consp(v0400)) goto v0404;
    v0402 = v0401;
    v0401 = stack[0];
    v0400 = qvalue(elt(env, 3)); // nil
    {
        popv(2);
        fn = elt(env, 13); // log_freevars_list
        return (*qfnn(fn))(qenv(fn), 3, v0402, v0401, v0400);
    }

v0404:
    v0402 = v0401;
    v0400 = stack[0];
    v0401 = qcdr(v0400);
    v0400 = qvalue(elt(env, 3)); // nil
    {
        popv(2);
        fn = elt(env, 13); // log_freevars_list
        return (*qfnn(fn))(qenv(fn), 3, v0402, v0401, v0400);
    }

v0219:
    v0402 = stack[0];
    v0400 = elt(env, 8); // function
    if (!consp(v0402)) goto v0354;
    v0402 = qcar(v0402);
    if (!(v0402 == v0400)) goto v0354;
    v0400 = stack[0];
    v0400 = qcdr(v0400);
    v0400 = qcar(v0400);
    v0400 = (consp(v0400) ? nil : lisp_true);
    goto v0319;

v0319:
    if (v0400 == nil) goto v0405;
    v0400 = qvalue(elt(env, 1)); // t
    goto v0213;

v0405:
    v0402 = stack[0];
    v0400 = elt(env, 9); // go
    v0400 = Leqcar(nil, v0402, v0400);
    env = stack[-1];
    goto v0213;

v0354:
    v0400 = qvalue(elt(env, 3)); // nil
    goto v0319;

v0001:
    v0400 = stack[0];
    if (symbolp(v0400)) goto v0097;
    v0400 = qvalue(elt(env, 1)); // t
    goto v0160;

v0160:
    if (v0400 == nil) goto v0203;
    v0400 = qvalue(elt(env, 3)); // nil
    { popv(2); return onevalue(v0400); }

v0203:
    v0400 = Lposn(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0403;
    env = stack[-1];
    v0400 = (LispObject)zerop(v0400);
    v0400 = v0400 ? lisp_true : nil;
    env = stack[-1];
    if (!(v0400 == nil)) goto v0080;
    v0400 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0403;
    env = stack[-1];
    goto v0080;

v0080:
    v0400 = elt(env, 4); // "+++ Use of free variable in smacro/inline body: "
    v0400 = Lprinc(nil, v0400);
    nil = C_nil;
    if (exception_pending()) goto v0403;
    env = stack[-1];
    v0400 = stack[0];
    v0400 = Lprint(nil, v0400);
    nil = C_nil;
    if (exception_pending()) goto v0403;
    env = stack[-1];
    v0400 = elt(env, 5); // "+++ Macro was: "
    v0400 = Lprinc(nil, v0400);
    nil = C_nil;
    if (exception_pending()) goto v0403;
    env = stack[-1];
    v0400 = qvalue(elt(env, 6)); // inlineinfo
    v0400 = Lprint(nil, v0400);
    nil = C_nil;
    if (exception_pending()) goto v0403;
    env = stack[-1];
    v0400 = qvalue(elt(env, 1)); // t
    { popv(2); return onevalue(v0400); }

v0097:
    v0400 = stack[0];
    v0400 = Lmember(nil, v0400, v0401);
    if (!(v0400 == nil)) goto v0160;
    v0400 = stack[0];
    v0400 = Lsymbol_globalp(nil, v0400);
    env = stack[-1];
    if (!(v0400 == nil)) goto v0160;
    v0400 = stack[0];
    v0400 = Lsymbol_specialp(nil, v0400);
    nil = C_nil;
    if (exception_pending()) goto v0403;
    env = stack[-1];
    if (!(v0400 == nil)) goto v0160;
    v0401 = stack[0];
    v0400 = elt(env, 2); // constant!?
    v0400 = get(v0401, v0400);
    env = stack[-1];
    if (!(v0400 == nil)) goto v0160;
    v0400 = stack[0];
    if (v0400 == nil) goto v0195;
    v0401 = stack[0];
    v0400 = qvalue(elt(env, 1)); // t
    v0400 = (equal(v0401, v0400) ? lisp_true : nil);
    goto v0160;

v0195:
    v0400 = qvalue(elt(env, 1)); // t
    goto v0160;
// error exit handlers
v0403:
    popv(2);
    return nil;
}



// Code for dfp!-sub

static LispObject CC_dfpKsub(LispObject env,
                         LispObject v0009, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0382, v0117, v0377;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dfp-sub");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0007,v0009);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0009,v0007);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    stack[-3] = v0007;
    stack[-4] = v0009;
// end of prologue
    v0382 = stack[-3];
    v0382 = qcdr(v0382);
    v0382 = qcar(v0382);
    v0117 = v0382;
    v0382 = v0117;
    v0382 = qcdr(v0382);
    stack[-5] = v0382;
    v0382 = v0117;
    v0117 = qcar(v0382);
    stack[-2] = v0117;
    v0382 = elt(env, 1); // generic_function
    v0382 = get(v0117, v0382);
    env = stack[-6];
    stack[-1] = v0382;
    v0382 = stack[-5];
    if (!(v0382 == nil)) goto v0193;
    v0382 = qvalue(elt(env, 2)); // nil
    v0117 = stack[-1];
    v0377 = v0117;
    goto v0190;

v0190:
    v0117 = v0377;
    if (v0117 == nil) goto v0106;
    v0117 = v0377;
    v0117 = qcar(v0117);
    if (!(v0382 == nil)) goto v0177;
    v0382 = stack[-4];
    v0382 = Lassoc(nil, v0117, v0382);
    goto v0177;

v0177:
    v0117 = v0377;
    v0117 = qcdr(v0117);
    v0377 = v0117;
    goto v0190;

v0106:
    if (v0382 == nil) goto v0193;
    v0382 = stack[-1];
    stack[-5] = v0382;
    goto v0193;

v0193:
    stack[0] = stack[-4];
    v0117 = elt(env, 3); // list
    v0382 = stack[-5];
    v0382 = cons(v0117, v0382);
    nil = C_nil;
    if (exception_pending()) goto v0112;
    env = stack[-6];
    fn = elt(env, 5); // listsub
    v0382 = (*qfn2(fn))(qenv(fn), stack[0], v0382);
    nil = C_nil;
    if (exception_pending()) goto v0112;
    env = stack[-6];
    v0382 = qcdr(v0382);
    stack[-5] = v0382;
    v0117 = stack[-2];
    v0382 = stack[-4];
    v0117 = Lassoc(nil, v0117, v0382);
    v0382 = v0117;
    if (v0117 == nil) goto v0082;
    v0117 = qvalue(elt(env, 2)); // nil
    goto v0230;

v0230:
    if (v0117 == nil) goto v0229;
    stack[0] = elt(env, 4); // dfp
    v0117 = stack[-2];
    v0382 = stack[-5];
    v0117 = cons(v0117, v0382);
    nil = C_nil;
    if (exception_pending()) goto v0112;
    v0382 = stack[-3];
    v0382 = qcdr(v0382);
    v0382 = qcdr(v0382);
    v0382 = qcar(v0382);
    {
        LispObject v0111 = stack[0];
        popv(7);
        return list3(v0111, v0117, v0382);
    }

v0229:
    v0382 = qcdr(v0382);
    fn = elt(env, 6); // reval
    v0382 = (*qfn1(fn))(qenv(fn), v0382);
    nil = C_nil;
    if (exception_pending()) goto v0112;
    env = stack[-6];
    stack[0] = v0382;
    v0382 = stack[-5];
    if (v0382 == nil) goto v0223;
    v0117 = stack[-1];
    v0382 = stack[-5];
    fn = elt(env, 7); // pair
    v0382 = (*qfn2(fn))(qenv(fn), v0117, v0382);
    nil = C_nil;
    if (exception_pending()) goto v0112;
    env = stack[-6];
    v0117 = v0382;
    goto v0372;

v0372:
    v0382 = stack[-4];
    fn = elt(env, 8); // dfp!-sub1
    v0382 = (*qfnn(fn))(qenv(fn), 3, stack[0], v0117, v0382);
    nil = C_nil;
    if (exception_pending()) goto v0112;
    env = stack[-6];
    v0377 = elt(env, 4); // dfp
    v0117 = v0382;
    v0382 = stack[-3];
    v0382 = qcdr(v0382);
    v0382 = qcdr(v0382);
    v0382 = qcar(v0382);
    popv(7);
    return list3(v0377, v0117, v0382);

v0223:
    v0117 = nil;
    goto v0372;

v0082:
    v0117 = stack[-2];
    v0382 = stack[-1];
    v0117 = cons(v0117, v0382);
    nil = C_nil;
    if (exception_pending()) goto v0112;
    env = stack[-6];
    v0382 = stack[-4];
    v0117 = Lassoc(nil, v0117, v0382);
    v0382 = v0117;
    v0117 = (v0117 == nil ? lisp_true : nil);
    goto v0230;
// error exit handlers
v0112:
    popv(7);
    return nil;
}



// Code for lf!=zero

static LispObject CC_lfMzero(LispObject env,
                         LispObject v0009)
{
    LispObject nil = C_nil;
    LispObject v0001;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lf=zero");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0001 = v0009;
// end of prologue
    v0001 = qcdr(v0001);
    v0001 = (v0001 == nil ? lisp_true : nil);
    return onevalue(v0001);
}



// Code for bfminus

static LispObject CC_bfminus(LispObject env,
                         LispObject v0009)
{
    LispObject nil = C_nil;
    LispObject v0160, v0168;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for bfminus");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0168 = v0009;
// end of prologue
    v0160 = v0168;
    if (!consp(v0160)) goto v0000;
    v0160 = v0168;
    {
        fn = elt(env, 1); // minus!:
        return (*qfn1(fn))(qenv(fn), v0160);
    }

v0000:
    v0160 = v0168;
    return negate(v0160);
}



// Code for freeof!-dfl

static LispObject CC_freeofKdfl(LispObject env,
                         LispObject v0009, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0157, v0158;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for freeof-dfl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0007,v0009);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0009,v0007);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0007;
    stack[-1] = v0009;
// end of prologue

v0412:
    v0157 = stack[-1];
    if (!consp(v0157)) goto v0001;
    v0157 = stack[-1];
    v0158 = qcar(v0157);
    v0157 = stack[0];
    fn = elt(env, 3); // freeof!-df
    v0157 = (*qfn2(fn))(qenv(fn), v0158, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0324;
    env = stack[-2];
    if (v0157 == nil) goto v0160;
    v0157 = stack[-1];
    v0158 = qcdr(v0157);
    v0157 = stack[0];
    stack[-1] = v0158;
    stack[0] = v0157;
    goto v0412;

v0160:
    v0157 = qvalue(elt(env, 2)); // nil
    { popv(3); return onevalue(v0157); }

v0001:
    v0157 = qvalue(elt(env, 1)); // t
    { popv(3); return onevalue(v0157); }
// error exit handlers
v0324:
    popv(3);
    return nil;
}



// Code for mri_ofsf2mriat

static LispObject CC_mri_ofsf2mriat(LispObject env,
                         LispObject v0009, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0188, v0182, v0167;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mri_ofsf2mriat");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0188 = v0007;
    v0182 = v0009;
// end of prologue
    v0167 = v0182;
    v0167 = qcar(v0167);
    v0182 = qcdr(v0182);
    v0182 = qcar(v0182);
    {
        fn = elt(env, 1); // mri_0mk2
        return (*qfnn(fn))(qenv(fn), 3, v0167, v0182, v0188);
    }
}



// Code for cl_flip

static LispObject CC_cl_flip(LispObject env,
                         LispObject v0009)
{
    LispObject nil = C_nil;
    LispObject v0148, v0361, v0368;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cl_flip");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0009);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// copy arguments values to proper place
    v0368 = v0009;
// end of prologue
    v0361 = v0368;
    v0148 = elt(env, 1); // and
    if (v0361 == v0148) goto v0000;
    v0361 = v0368;
    v0148 = elt(env, 2); // or
    if (v0361 == v0148) goto v0168;
    v0361 = v0368;
    v0148 = elt(env, 3); // all
    if (v0361 == v0148) goto v0098;
    v0361 = v0368;
    v0148 = elt(env, 4); // ex
    if (v0361 == v0148) goto v0190;
    v0361 = v0368;
    v0148 = elt(env, 5); // ball
    if (v0361 == v0148) goto v0227;
    v0361 = v0368;
    v0148 = elt(env, 6); // bex
    if (v0361 == v0148) goto v0195;
    v0361 = v0368;
    v0148 = elt(env, 7); // true
    if (v0361 == v0148) goto v0176;
    v0361 = v0368;
    v0148 = elt(env, 8); // false
    if (v0361 == v0148) goto v0169;
    v0148 = elt(env, 9); // "cl_flip(): don't know"
    v0361 = v0368;
    v0148 = list2(v0148, v0361);
    nil = C_nil;
    if (exception_pending()) goto v0367;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 10); // rederr
        return (*qfn1(fn))(qenv(fn), v0148);
    }

v0169:
    v0148 = elt(env, 7); // true
    { popv(1); return onevalue(v0148); }

v0176:
    v0148 = elt(env, 8); // false
    { popv(1); return onevalue(v0148); }

v0195:
    v0148 = elt(env, 5); // ball
    { popv(1); return onevalue(v0148); }

v0227:
    v0148 = elt(env, 6); // bex
    { popv(1); return onevalue(v0148); }

v0190:
    v0148 = elt(env, 3); // all
    { popv(1); return onevalue(v0148); }

v0098:
    v0148 = elt(env, 4); // ex
    { popv(1); return onevalue(v0148); }

v0168:
    v0148 = elt(env, 1); // and
    { popv(1); return onevalue(v0148); }

v0000:
    v0148 = elt(env, 2); // or
    { popv(1); return onevalue(v0148); }
// error exit handlers
v0367:
    popv(1);
    return nil;
}



// Code for intervalom

static LispObject CC_intervalom(LispObject env,
                         LispObject v0009)
{
    LispObject nil = C_nil;
    LispObject v0204, v0088, v0149;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for intervalom");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0009);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-2] = v0009;
// end of prologue
    v0204 = stack[-2];
    v0204 = qcdr(v0204);
    v0204 = qcar(v0204);
    stack[-3] = v0204;
    v0204 = stack[-2];
    v0204 = qcar(v0204);
    stack[-1] = v0204;
    v0088 = stack[-1];
    v0204 = elt(env, 1); // lowupperlimit
    if (!(v0088 == v0204)) goto v0161;
    v0204 = elt(env, 2); // integer_interval
    stack[-1] = v0204;
    v0204 = qvalue(elt(env, 3)); // nil
    stack[-3] = v0204;
    v0204 = stack[-2];
    v0149 = qcar(v0204);
    v0088 = qvalue(elt(env, 3)); // nil
    v0204 = stack[-2];
    v0204 = qcdr(v0204);
    v0204 = list2star(v0149, v0088, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0321;
    env = stack[-4];
    stack[-2] = v0204;
    goto v0161;

v0161:
    v0088 = stack[-1];
    v0204 = qvalue(elt(env, 4)); // valid_om!*
    v0204 = Lassoc(nil, v0088, v0204);
    v0204 = qcdr(v0204);
    v0204 = qcar(v0204);
    stack[0] = v0204;
    v0204 = stack[-3];
    if (v0204 == nil) goto v0094;
    v0204 = stack[-3];
    v0204 = qcar(v0204);
    v0204 = qcdr(v0204);
    v0204 = qcar(v0204);
    v0088 = Lintern(nil, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0321;
    env = stack[-4];
    v0204 = qvalue(elt(env, 5)); // interval!*
    v0204 = Lassoc(nil, v0088, v0204);
    v0204 = qcdr(v0204);
    v0204 = qcar(v0204);
    stack[-1] = v0204;
    goto v0094;

v0094:
    v0204 = elt(env, 6); // "<OMA>"
    fn = elt(env, 12); // printout
    v0204 = (*qfn1(fn))(qenv(fn), v0204);
    nil = C_nil;
    if (exception_pending()) goto v0321;
    env = stack[-4];
    v0204 = qvalue(elt(env, 7)); // t
    fn = elt(env, 13); // indent!*
    v0204 = (*qfn1(fn))(qenv(fn), v0204);
    nil = C_nil;
    if (exception_pending()) goto v0321;
    env = stack[-4];
    v0204 = elt(env, 8); // "<OMS cd="""
    fn = elt(env, 12); // printout
    v0204 = (*qfn1(fn))(qenv(fn), v0204);
    nil = C_nil;
    if (exception_pending()) goto v0321;
    env = stack[-4];
    v0204 = stack[0];
    v0204 = Lprinc(nil, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0321;
    env = stack[-4];
    v0204 = elt(env, 9); // """ name="""
    v0204 = Lprinc(nil, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0321;
    env = stack[-4];
    v0204 = stack[-1];
    v0204 = Lprinc(nil, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0321;
    env = stack[-4];
    v0204 = elt(env, 10); // """/>"
    v0204 = Lprinc(nil, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0321;
    env = stack[-4];
    v0204 = stack[-2];
    v0204 = qcdr(v0204);
    v0204 = qcdr(v0204);
    fn = elt(env, 14); // multiom
    v0204 = (*qfn1(fn))(qenv(fn), v0204);
    nil = C_nil;
    if (exception_pending()) goto v0321;
    env = stack[-4];
    v0204 = qvalue(elt(env, 3)); // nil
    fn = elt(env, 13); // indent!*
    v0204 = (*qfn1(fn))(qenv(fn), v0204);
    nil = C_nil;
    if (exception_pending()) goto v0321;
    env = stack[-4];
    v0204 = elt(env, 11); // "</OMA>"
    fn = elt(env, 12); // printout
    v0204 = (*qfn1(fn))(qenv(fn), v0204);
    nil = C_nil;
    if (exception_pending()) goto v0321;
    v0204 = nil;
    { popv(5); return onevalue(v0204); }
// error exit handlers
v0321:
    popv(5);
    return nil;
}



// Code for remzzzz

static LispObject CC_remzzzz(LispObject env,
                         LispObject v0009, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0094, v0185, v0184;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for remzzzz");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0007,v0009);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0009,v0007);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0007;
    stack[-1] = v0009;
// end of prologue
    v0184 = nil;
    goto v0018;

v0018:
    v0094 = stack[-1];
    if (v0094 == nil) goto v0160;
    v0094 = stack[-1];
    v0094 = qcar(v0094);
    v0185 = qcar(v0094);
    v0094 = stack[0];
    v0094 = qcar(v0094);
    v0094 = qcar(v0094);
    if (equal(v0185, v0094)) goto v0165;
    v0094 = stack[0];
    v0094 = qcar(v0094);
    v0185 = v0184;
    v0094 = cons(v0094, v0185);
    nil = C_nil;
    if (exception_pending()) goto v0364;
    env = stack[-2];
    v0184 = v0094;
    v0094 = stack[0];
    v0094 = qcdr(v0094);
    stack[0] = v0094;
    goto v0018;

v0165:
    v0094 = stack[-1];
    v0094 = qcdr(v0094);
    stack[-1] = v0094;
    v0094 = stack[0];
    v0094 = qcdr(v0094);
    stack[0] = v0094;
    goto v0018;

v0160:
    v0185 = v0184;
    v0094 = stack[0];
    {
        popv(3);
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(qenv(fn), v0185, v0094);
    }
// error exit handlers
v0364:
    popv(3);
    return nil;
}



// Code for diplmon2sq

static LispObject CC_diplmon2sq(LispObject env,
                         LispObject v0009, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0156, v0155;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for diplmon2sq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0007,v0009);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0009,v0007);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0156 = v0007;
    v0155 = v0009;
// end of prologue
    stack[0] = v0155;
    v0155 = v0156;
    v0156 = qvalue(elt(env, 1)); // dipvars!*
    fn = elt(env, 2); // dipev2f
    v0155 = (*qfn2(fn))(qenv(fn), v0155, v0156);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-1];
    v0156 = (LispObject)17; // 1
    v0156 = cons(v0155, v0156);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-1];
    {
        LispObject v0164 = stack[0];
        popv(2);
        fn = elt(env, 3); // multsq
        return (*qfn2(fn))(qenv(fn), v0164, v0156);
    }
// error exit handlers
v0166:
    popv(2);
    return nil;
}



// Code for multiply!-by!-power!-of!-ten

static LispObject CC_multiplyKbyKpowerKofKten(LispObject env,
                         LispObject v0009, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0181, v0197;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for multiply-by-power-of-ten");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0007,v0009);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0009,v0007);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0007;
    stack[-1] = v0009;
// end of prologue
    v0197 = stack[0];
    v0181 = (LispObject)1; // 0
    v0181 = (LispObject)lessp2(v0197, v0181);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    v0181 = v0181 ? lisp_true : nil;
    env = stack[-3];
    if (v0181 == nil) goto v0188;
    v0181 = elt(env, 0); // multiply!-by!-power!-of!-ten
    {
        popv(4);
        fn = elt(env, 4); // bflerrmsg
        return (*qfn1(fn))(qenv(fn), v0181);
    }

v0188:
    v0181 = qvalue(elt(env, 1)); // bften!*
    stack[-2] = v0181;
    goto v0164;

v0164:
    v0197 = stack[0];
    v0181 = (LispObject)1; // 0
    v0181 = (LispObject)greaterp2(v0197, v0181);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    v0181 = v0181 ? lisp_true : nil;
    env = stack[-3];
    if (v0181 == nil) goto v0145;
    v0181 = stack[0];
    v0181 = Levenp(nil, v0181);
    env = stack[-3];
    if (!(v0181 == nil)) goto v0187;
    v0197 = stack[-1];
    v0181 = stack[-2];
    fn = elt(env, 5); // times!:
    v0181 = (*qfn2(fn))(qenv(fn), v0197, v0181);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-3];
    fn = elt(env, 6); // normbf
    v0181 = (*qfn1(fn))(qenv(fn), v0181);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-3];
    stack[-1] = v0181;
    goto v0187;

v0187:
    v0197 = stack[0];
    v0181 = (LispObject)-15; // -1
    fn = elt(env, 7); // lshift
    v0181 = (*qfn2(fn))(qenv(fn), v0197, v0181);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-3];
    stack[0] = v0181;
    v0197 = stack[-2];
    v0181 = stack[-2];
    fn = elt(env, 5); // times!:
    v0197 = (*qfn2(fn))(qenv(fn), v0197, v0181);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-3];
    v0181 = qvalue(elt(env, 3)); // !:bprec!:
    fn = elt(env, 8); // cut!:mt
    v0181 = (*qfn2(fn))(qenv(fn), v0197, v0181);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-3];
    fn = elt(env, 6); // normbf
    v0181 = (*qfn1(fn))(qenv(fn), v0181);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-3];
    stack[-2] = v0181;
    goto v0164;

v0145:
    v0197 = stack[-1];
    v0181 = qvalue(elt(env, 3)); // !:bprec!:
    fn = elt(env, 8); // cut!:mt
    v0181 = (*qfn2(fn))(qenv(fn), v0197, v0181);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-3];
    {
        popv(4);
        fn = elt(env, 6); // normbf
        return (*qfn1(fn))(qenv(fn), v0181);
    }
// error exit handlers
v0213:
    popv(4);
    return nil;
}



// Code for toolongassignp

static LispObject CC_toolongassignp(LispObject env,
                         LispObject v0009)
{
    LispObject nil = C_nil;
    LispObject v0008;
    LispObject fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for toolongassignp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
// copy arguments values to proper place
    v0008 = v0009;
// end of prologue
    v0008 = qcdr(v0008);
    v0008 = qcdr(v0008);
    v0008 = qcar(v0008);
    {
        fn = elt(env, 1); // toolongexpp
        return (*qfn1(fn))(qenv(fn), v0008);
    }
}



setup_type const u30_setup[] =
{
    {"simpexpt1",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_simpexpt1},
    {"mri_opn",                 CC_mri_opn,     too_many_1,    wrong_no_1},
    {"repr_n",                  CC_repr_n,      too_many_1,    wrong_no_1},
    {"minusrd",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_minusrd},
    {"vdpmember",               too_few_2,      CC_vdpmember,  wrong_no_2},
    {"simp*sq",                 CC_simpHsq,     too_many_1,    wrong_no_1},
    {"z-roads",                 CC_zKroads,     too_many_1,    wrong_no_1},
    {"ordered-gcd-mod-p",       too_few_2,      CC_orderedKgcdKmodKp,wrong_no_2},
    {"orddf",                   too_few_2,      CC_orddf,      wrong_no_2},
    {"rl_bnfsimpl",             too_few_2,      CC_rl_bnfsimpl,wrong_no_2},
    {"ofsf_smordtable",         too_few_2,      CC_ofsf_smordtable,wrong_no_2},
    {"determinantrd",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_determinantrd},
    {"simp_without_resimp",     CC_simp_without_resimp,too_many_1,wrong_no_1},
    {"sc_columnscalarproduct",  too_few_2,      CC_sc_columnscalarproduct,wrong_no_2},
    {"mkexdf",                  CC_mkexdf,      too_many_1,    wrong_no_1},
    {"divide-by-power-of-ten",  too_few_2,      CC_divideKbyKpowerKofKten,wrong_no_2},
    {"rd:difference",           too_few_2,      CC_rdTdifference,wrong_no_2},
    {"open",                    too_few_2,      CC_open,       wrong_no_2},
    {"prepsq*1",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_prepsqH1},
    {"num_signsort",            CC_num_signsort,too_many_1,    wrong_no_1},
    {"lambda_u9iz36vfudu4",     too_few_2,      CC_lambda_u9iz36vfudu4,wrong_no_2},
    {"msolve-psys1",            too_few_2,      CC_msolveKpsys1,wrong_no_2},
    {"assoc2",                  too_few_2,      CC_assoc2,     wrong_no_2},
    {"xquotient-mod-p",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_xquotientKmodKp},
    {"testord",                 too_few_2,      CC_testord,    wrong_no_2},
    {"ofsf_optsplitterm",       too_few_2,      CC_ofsf_optsplitterm,wrong_no_2},
    {"omattrir",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_omattrir},
    {"sptransmat",              CC_sptransmat,  too_many_1,    wrong_no_1},
    {"greatertype",             too_few_2,      CC_greatertype,wrong_no_2},
    {"vdpcleanup",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_vdpcleanup},
    {"wedgef",                  CC_wedgef,      too_many_1,    wrong_no_1},
    {"bflessp",                 too_few_2,      CC_bflessp,    wrong_no_2},
    {"calc_den_tar",            too_few_2,      CC_calc_den_tar,wrong_no_2},
    {"log_freevars",            too_few_2,      CC_log_freevars,wrong_no_2},
    {"dfp-sub",                 too_few_2,      CC_dfpKsub,    wrong_no_2},
    {"lf=zero",                 CC_lfMzero,     too_many_1,    wrong_no_1},
    {"bfminus",                 CC_bfminus,     too_many_1,    wrong_no_1},
    {"freeof-dfl",              too_few_2,      CC_freeofKdfl, wrong_no_2},
    {"mri_ofsf2mriat",          too_few_2,      CC_mri_ofsf2mriat,wrong_no_2},
    {"cl_flip",                 CC_cl_flip,     too_many_1,    wrong_no_1},
    {"intervalom",              CC_intervalom,  too_many_1,    wrong_no_1},
    {"remzzzz",                 too_few_2,      CC_remzzzz,    wrong_no_2},
    {"diplmon2sq",              too_few_2,      CC_diplmon2sq, wrong_no_2},
    {"multiply-by-power-of-ten",too_few_2,      CC_multiplyKbyKpowerKofKten,wrong_no_2},
    {"toolongassignp",          CC_toolongassignp,too_many_1,  wrong_no_1},
    {NULL, (one_args *)"u30", (two_args *)"19856 50179 3806969", 0}
};

// end of generated code
