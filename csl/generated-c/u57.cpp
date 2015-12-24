
// $destdir/u57.c        Machine generated C code

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



// Code for comcom3

static LispObject CC_comcom3(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0671, v0672, v0673, v0674;
    LispObject fn;
    argcheck(nargs, 0, "comcom3");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for comcom3");
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
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
// end of prologue
    v0673 = elt(env, 1); // l_k
    v0672 = (LispObject)49; // 3
    v0671 = (LispObject)49; // 3
    stack[0] = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0673 = elt(env, 2); // l_a
    v0672 = (LispObject)49; // 3
    v0671 = (LispObject)49; // 3
    v0671 = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0671 = list2(stack[0], v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    fn = elt(env, 32); // matrix
    v0671 = (*qfn1(fn))(qenv(fn), v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    fn = elt(env, 33); // aeval
    v0671 = (*qfn1(fn))(qenv(fn), v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0671 = (LispObject)1; // 0
    fn = elt(env, 33); // aeval
    v0671 = (*qfn1(fn))(qenv(fn), v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    stack[-15] = v0671;
    v0673 = elt(env, 1); // l_k
    v0672 = (LispObject)17; // 1
    v0671 = (LispObject)17; // 1
    stack[-5] = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    stack[-4] = elt(env, 3); // plus
    stack[0] = elt(env, 4); // expt
    v0673 = elt(env, 5); // ff
    v0672 = (LispObject)17; // 1
    v0671 = (LispObject)33; // 2
    v0672 = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0671 = (LispObject)33; // 2
    stack[-3] = list3(stack[0], v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    stack[-2] = elt(env, 6); // times
    stack[-1] = (LispObject)33; // 2
    v0673 = elt(env, 5); // ff
    v0672 = (LispObject)17; // 1
    v0671 = (LispObject)49; // 3
    stack[0] = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0673 = elt(env, 5); // ff
    v0672 = (LispObject)33; // 2
    v0671 = (LispObject)33; // 2
    v0671 = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    stack[-1] = list4(stack[-2], stack[-1], stack[0], v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    stack[0] = elt(env, 4); // expt
    v0673 = elt(env, 5); // ff
    v0672 = (LispObject)33; // 2
    v0671 = (LispObject)49; // 3
    v0672 = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0671 = (LispObject)33; // 2
    v0671 = list3(stack[0], v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0671 = list4(stack[-4], stack[-3], stack[-1], v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    fn = elt(env, 33); // aeval
    v0671 = (*qfn1(fn))(qenv(fn), v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    fn = elt(env, 34); // setk
    v0671 = (*qfn2(fn))(qenv(fn), stack[-5], v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0673 = elt(env, 1); // l_k
    v0672 = (LispObject)17; // 1
    v0671 = (LispObject)33; // 2
    stack[-6] = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    stack[-5] = elt(env, 3); // plus
    stack[-2] = elt(env, 7); // minus
    stack[-1] = elt(env, 6); // times
    v0673 = elt(env, 5); // ff
    v0672 = (LispObject)17; // 1
    v0671 = (LispObject)17; // 1
    stack[0] = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0673 = elt(env, 5); // ff
    v0672 = (LispObject)17; // 1
    v0671 = (LispObject)33; // 2
    v0671 = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0671 = list3(stack[-1], stack[0], v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    stack[-4] = list2(stack[-2], v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    stack[-3] = elt(env, 8); // difference
    stack[-1] = elt(env, 6); // times
    v0673 = elt(env, 5); // ff
    v0672 = (LispObject)17; // 1
    v0671 = (LispObject)49; // 3
    stack[0] = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0673 = elt(env, 5); // ff
    v0672 = (LispObject)49; // 3
    v0671 = (LispObject)33; // 2
    v0671 = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    stack[-2] = list3(stack[-1], stack[0], v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    stack[-1] = elt(env, 6); // times
    v0673 = elt(env, 5); // ff
    v0672 = (LispObject)33; // 2
    v0671 = (LispObject)17; // 1
    stack[0] = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0673 = elt(env, 5); // ff
    v0672 = (LispObject)17; // 1
    v0671 = (LispObject)49; // 3
    v0671 = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0671 = list3(stack[-1], stack[0], v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    stack[-2] = list3(stack[-3], stack[-2], v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    stack[-1] = elt(env, 6); // times
    v0673 = elt(env, 5); // ff
    v0672 = (LispObject)33; // 2
    v0671 = (LispObject)49; // 3
    stack[0] = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0673 = elt(env, 5); // ff
    v0672 = (LispObject)49; // 3
    v0671 = (LispObject)49; // 3
    v0671 = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0671 = list3(stack[-1], stack[0], v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0671 = list4(stack[-5], stack[-4], stack[-2], v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    fn = elt(env, 33); // aeval
    v0671 = (*qfn1(fn))(qenv(fn), v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    fn = elt(env, 34); // setk
    v0671 = (*qfn2(fn))(qenv(fn), stack[-6], v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0673 = elt(env, 1); // l_k
    v0672 = (LispObject)17; // 1
    v0671 = (LispObject)49; // 3
    stack[-5] = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    stack[-4] = elt(env, 8); // difference
    stack[-3] = elt(env, 8); // difference
    stack[-2] = elt(env, 8); // difference
    stack[-6] = elt(env, 7); // minus
    stack[-1] = elt(env, 6); // times
    v0673 = elt(env, 5); // ff
    v0672 = (LispObject)17; // 1
    v0671 = (LispObject)17; // 1
    stack[0] = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0673 = elt(env, 5); // ff
    v0672 = (LispObject)33; // 2
    v0671 = (LispObject)33; // 2
    v0671 = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0671 = list3(stack[-1], stack[0], v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    stack[-6] = list2(stack[-6], v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    stack[-1] = elt(env, 6); // times
    v0673 = elt(env, 5); // ff
    v0672 = (LispObject)17; // 1
    v0671 = (LispObject)33; // 2
    stack[0] = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0673 = elt(env, 5); // ff
    v0672 = (LispObject)49; // 3
    v0671 = (LispObject)33; // 2
    v0671 = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0671 = list3(stack[-1], stack[0], v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    stack[-2] = list3(stack[-2], stack[-6], v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    stack[-1] = elt(env, 6); // times
    v0673 = elt(env, 5); // ff
    v0672 = (LispObject)33; // 2
    v0671 = (LispObject)17; // 1
    stack[0] = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0673 = elt(env, 5); // ff
    v0672 = (LispObject)33; // 2
    v0671 = (LispObject)49; // 3
    v0671 = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0671 = list3(stack[-1], stack[0], v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    stack[-2] = list3(stack[-3], stack[-2], v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    stack[-1] = elt(env, 6); // times
    v0673 = elt(env, 5); // ff
    v0672 = (LispObject)33; // 2
    v0671 = (LispObject)33; // 2
    stack[0] = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0673 = elt(env, 5); // ff
    v0672 = (LispObject)49; // 3
    v0671 = (LispObject)49; // 3
    v0671 = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0671 = list3(stack[-1], stack[0], v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0671 = list3(stack[-4], stack[-2], v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    fn = elt(env, 33); // aeval
    v0671 = (*qfn1(fn))(qenv(fn), v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    fn = elt(env, 34); // setk
    v0671 = (*qfn2(fn))(qenv(fn), stack[-5], v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0673 = elt(env, 1); // l_k
    v0672 = (LispObject)33; // 2
    v0671 = (LispObject)17; // 1
    stack[0] = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0673 = elt(env, 1); // l_k
    v0672 = (LispObject)17; // 1
    v0671 = (LispObject)33; // 2
    v0671 = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    fn = elt(env, 33); // aeval
    v0671 = (*qfn1(fn))(qenv(fn), v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    fn = elt(env, 34); // setk
    v0671 = (*qfn2(fn))(qenv(fn), stack[0], v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0673 = elt(env, 1); // l_k
    v0672 = (LispObject)33; // 2
    v0671 = (LispObject)33; // 2
    stack[-6] = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    stack[-5] = elt(env, 3); // plus
    stack[-4] = elt(env, 8); // difference
    stack[0] = elt(env, 4); // expt
    v0673 = elt(env, 5); // ff
    v0672 = (LispObject)17; // 1
    v0671 = (LispObject)17; // 1
    v0672 = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0671 = (LispObject)33; // 2
    stack[-3] = list3(stack[0], v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    stack[-2] = elt(env, 6); // times
    stack[-1] = (LispObject)33; // 2
    v0673 = elt(env, 5); // ff
    v0672 = (LispObject)17; // 1
    v0671 = (LispObject)49; // 3
    stack[0] = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0673 = elt(env, 5); // ff
    v0672 = (LispObject)49; // 3
    v0671 = (LispObject)17; // 1
    v0671 = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0671 = list4(stack[-2], stack[-1], stack[0], v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    stack[-1] = list3(stack[-4], stack[-3], v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    stack[0] = elt(env, 4); // expt
    v0673 = elt(env, 5); // ff
    v0672 = (LispObject)49; // 3
    v0671 = (LispObject)49; // 3
    v0672 = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0671 = (LispObject)33; // 2
    v0671 = list3(stack[0], v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0671 = list3(stack[-5], stack[-1], v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    fn = elt(env, 33); // aeval
    v0671 = (*qfn1(fn))(qenv(fn), v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    fn = elt(env, 34); // setk
    v0671 = (*qfn2(fn))(qenv(fn), stack[-6], v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0673 = elt(env, 1); // l_k
    v0672 = (LispObject)33; // 2
    v0671 = (LispObject)49; // 3
    stack[-7] = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    stack[-6] = elt(env, 3); // plus
    stack[-1] = elt(env, 6); // times
    v0673 = elt(env, 5); // ff
    v0672 = (LispObject)17; // 1
    v0671 = (LispObject)17; // 1
    stack[0] = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0673 = elt(env, 5); // ff
    v0672 = (LispObject)33; // 2
    v0671 = (LispObject)17; // 1
    v0671 = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    stack[-5] = list3(stack[-1], stack[0], v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    stack[-4] = elt(env, 8); // difference
    stack[-3] = elt(env, 8); // difference
    stack[-1] = elt(env, 6); // times
    v0673 = elt(env, 5); // ff
    v0672 = (LispObject)17; // 1
    v0671 = (LispObject)33; // 2
    stack[0] = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0673 = elt(env, 5); // ff
    v0672 = (LispObject)49; // 3
    v0671 = (LispObject)17; // 1
    v0671 = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    stack[-2] = list3(stack[-1], stack[0], v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    stack[-1] = elt(env, 6); // times
    v0673 = elt(env, 5); // ff
    v0672 = (LispObject)49; // 3
    v0671 = (LispObject)17; // 1
    stack[0] = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0673 = elt(env, 5); // ff
    v0672 = (LispObject)33; // 2
    v0671 = (LispObject)49; // 3
    v0671 = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0671 = list3(stack[-1], stack[0], v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    stack[-2] = list3(stack[-3], stack[-2], v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    stack[-1] = elt(env, 6); // times
    v0673 = elt(env, 5); // ff
    v0672 = (LispObject)49; // 3
    v0671 = (LispObject)33; // 2
    stack[0] = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0673 = elt(env, 5); // ff
    v0672 = (LispObject)49; // 3
    v0671 = (LispObject)49; // 3
    v0671 = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0671 = list3(stack[-1], stack[0], v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0671 = list3(stack[-4], stack[-2], v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0671 = list3(stack[-6], stack[-5], v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    fn = elt(env, 33); // aeval
    v0671 = (*qfn1(fn))(qenv(fn), v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    fn = elt(env, 34); // setk
    v0671 = (*qfn2(fn))(qenv(fn), stack[-7], v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0673 = elt(env, 1); // l_k
    v0672 = (LispObject)49; // 3
    v0671 = (LispObject)17; // 1
    stack[0] = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0673 = elt(env, 1); // l_k
    v0672 = (LispObject)17; // 1
    v0671 = (LispObject)49; // 3
    v0671 = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    fn = elt(env, 33); // aeval
    v0671 = (*qfn1(fn))(qenv(fn), v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    fn = elt(env, 34); // setk
    v0671 = (*qfn2(fn))(qenv(fn), stack[0], v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0673 = elt(env, 1); // l_k
    v0672 = (LispObject)49; // 3
    v0671 = (LispObject)33; // 2
    stack[0] = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0673 = elt(env, 1); // l_k
    v0672 = (LispObject)33; // 2
    v0671 = (LispObject)49; // 3
    v0671 = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    fn = elt(env, 33); // aeval
    v0671 = (*qfn1(fn))(qenv(fn), v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    fn = elt(env, 34); // setk
    v0671 = (*qfn2(fn))(qenv(fn), stack[0], v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0673 = elt(env, 1); // l_k
    v0672 = (LispObject)49; // 3
    v0671 = (LispObject)49; // 3
    stack[-5] = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    stack[-4] = elt(env, 3); // plus
    stack[0] = elt(env, 4); // expt
    v0673 = elt(env, 5); // ff
    v0672 = (LispObject)33; // 2
    v0671 = (LispObject)17; // 1
    v0672 = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0671 = (LispObject)33; // 2
    stack[-3] = list3(stack[0], v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    stack[-2] = elt(env, 6); // times
    stack[-1] = (LispObject)33; // 2
    v0673 = elt(env, 5); // ff
    v0672 = (LispObject)33; // 2
    v0671 = (LispObject)33; // 2
    stack[0] = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0673 = elt(env, 5); // ff
    v0672 = (LispObject)49; // 3
    v0671 = (LispObject)17; // 1
    v0671 = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    stack[-1] = list4(stack[-2], stack[-1], stack[0], v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    stack[0] = elt(env, 4); // expt
    v0673 = elt(env, 5); // ff
    v0672 = (LispObject)49; // 3
    v0671 = (LispObject)33; // 2
    v0672 = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0671 = (LispObject)33; // 2
    v0671 = list3(stack[0], v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0671 = list4(stack[-4], stack[-3], stack[-1], v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    fn = elt(env, 33); // aeval
    v0671 = (*qfn1(fn))(qenv(fn), v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    fn = elt(env, 34); // setk
    v0671 = (*qfn2(fn))(qenv(fn), stack[-5], v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0673 = elt(env, 1); // l_k
    v0672 = (LispObject)17; // 1
    v0671 = (LispObject)17; // 1
    v0671 = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    fn = elt(env, 33); // aeval
    v0671 = (*qfn1(fn))(qenv(fn), v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    fn = elt(env, 35); // evalnumberp
    v0671 = (*qfn1(fn))(qenv(fn), v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    if (v0671 == nil) goto v0676;
    stack[-3] = elt(env, 8); // difference
    stack[-1] = elt(env, 6); // times
    v0673 = elt(env, 1); // l_k
    v0672 = (LispObject)17; // 1
    v0671 = (LispObject)17; // 1
    stack[0] = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0673 = elt(env, 1); // l_k
    v0672 = (LispObject)33; // 2
    v0671 = (LispObject)33; // 2
    v0671 = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    stack[-2] = list3(stack[-1], stack[0], v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    stack[-1] = elt(env, 6); // times
    v0673 = elt(env, 1); // l_k
    v0672 = (LispObject)17; // 1
    v0671 = (LispObject)33; // 2
    stack[0] = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0673 = elt(env, 1); // l_k
    v0672 = (LispObject)33; // 2
    v0671 = (LispObject)17; // 1
    v0671 = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0671 = list3(stack[-1], stack[0], v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0671 = list3(stack[-3], stack[-2], v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    fn = elt(env, 33); // aeval
    v0671 = (*qfn1(fn))(qenv(fn), v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    fn = elt(env, 35); // evalnumberp
    v0671 = (*qfn1(fn))(qenv(fn), v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    if (v0671 == nil) goto v0676;
    v0672 = elt(env, 9); // det
    v0671 = elt(env, 1); // l_k
    v0671 = list2(v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    fn = elt(env, 33); // aeval
    v0671 = (*qfn1(fn))(qenv(fn), v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    fn = elt(env, 35); // evalnumberp
    v0671 = (*qfn1(fn))(qenv(fn), v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    if (v0671 == nil) goto v0676;
    stack[0] = elt(env, 7); // minus
    v0673 = elt(env, 1); // l_k
    v0672 = (LispObject)17; // 1
    v0671 = (LispObject)17; // 1
    v0671 = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0671 = list2(stack[0], v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    fn = elt(env, 33); // aeval
    v0672 = (*qfn1(fn))(qenv(fn), v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0671 = (LispObject)1; // 0
    fn = elt(env, 36); // evalgreaterp
    v0671 = (*qfn2(fn))(qenv(fn), v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    if (v0671 == nil) goto v0677;
    stack[-3] = elt(env, 8); // difference
    stack[-1] = elt(env, 6); // times
    v0673 = elt(env, 1); // l_k
    v0672 = (LispObject)17; // 1
    v0671 = (LispObject)17; // 1
    stack[0] = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0673 = elt(env, 1); // l_k
    v0672 = (LispObject)33; // 2
    v0671 = (LispObject)33; // 2
    v0671 = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    stack[-2] = list3(stack[-1], stack[0], v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    stack[-1] = elt(env, 6); // times
    v0673 = elt(env, 1); // l_k
    v0672 = (LispObject)17; // 1
    v0671 = (LispObject)33; // 2
    stack[0] = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0673 = elt(env, 1); // l_k
    v0672 = (LispObject)33; // 2
    v0671 = (LispObject)17; // 1
    v0671 = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0671 = list3(stack[-1], stack[0], v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0671 = list3(stack[-3], stack[-2], v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    fn = elt(env, 33); // aeval
    v0672 = (*qfn1(fn))(qenv(fn), v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0671 = (LispObject)1; // 0
    fn = elt(env, 36); // evalgreaterp
    v0671 = (*qfn2(fn))(qenv(fn), v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    if (v0671 == nil) goto v0677;
    stack[0] = elt(env, 7); // minus
    v0672 = elt(env, 9); // det
    v0671 = elt(env, 1); // l_k
    v0671 = list2(v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0671 = list2(stack[0], v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    fn = elt(env, 33); // aeval
    v0672 = (*qfn1(fn))(qenv(fn), v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0671 = (LispObject)1; // 0
    fn = elt(env, 36); // evalgreaterp
    v0671 = (*qfn2(fn))(qenv(fn), v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    if (v0671 == nil) goto v0677;
    v0671 = (LispObject)17; // 1
    fn = elt(env, 33); // aeval
    v0671 = (*qfn1(fn))(qenv(fn), v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    stack[-15] = v0671;
    v0671 = elt(env, 17); // lie4so3
    v0671 = ncons(v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    fn = elt(env, 33); // aeval
    v0671 = (*qfn1(fn))(qenv(fn), v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    goto v0678;

v0678:
    stack[-6] = elt(env, 19); // liemat
    stack[-5] = elt(env, 6); // times
    stack[-4] = elt(env, 20); // mat
    v0673 = elt(env, 2); // l_a
    v0672 = (LispObject)17; // 1
    v0671 = (LispObject)17; // 1
    stack[-1] = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0673 = elt(env, 2); // l_a
    v0672 = (LispObject)17; // 1
    v0671 = (LispObject)33; // 2
    stack[0] = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0673 = elt(env, 2); // l_a
    v0672 = (LispObject)17; // 1
    v0671 = (LispObject)49; // 3
    v0672 = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0671 = (LispObject)1; // 0
    stack[-3] = list4(stack[-1], stack[0], v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0673 = elt(env, 2); // l_a
    v0672 = (LispObject)33; // 2
    v0671 = (LispObject)17; // 1
    stack[-1] = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0673 = elt(env, 2); // l_a
    v0672 = (LispObject)33; // 2
    v0671 = (LispObject)33; // 2
    stack[0] = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0673 = elt(env, 2); // l_a
    v0672 = (LispObject)33; // 2
    v0671 = (LispObject)49; // 3
    v0672 = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0671 = (LispObject)1; // 0
    stack[-2] = list4(stack[-1], stack[0], v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0673 = elt(env, 2); // l_a
    v0672 = (LispObject)49; // 3
    v0671 = (LispObject)17; // 1
    stack[-1] = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0673 = elt(env, 2); // l_a
    v0672 = (LispObject)49; // 3
    v0671 = (LispObject)33; // 2
    stack[0] = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0673 = elt(env, 2); // l_a
    v0672 = (LispObject)49; // 3
    v0671 = (LispObject)49; // 3
    v0672 = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0671 = (LispObject)1; // 0
    stack[0] = list4(stack[-1], stack[0], v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0674 = (LispObject)1; // 0
    v0673 = (LispObject)1; // 0
    v0672 = (LispObject)1; // 0
    v0671 = (LispObject)17; // 1
    v0671 = list4(v0674, v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0671 = list2(stack[0], v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0672 = list3star(stack[-4], stack[-3], stack[-2], v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0671 = elt(env, 19); // liemat
    v0671 = list3(stack[-5], v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    fn = elt(env, 33); // aeval
    v0671 = (*qfn1(fn))(qenv(fn), v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    fn = elt(env, 34); // setk
    v0671 = (*qfn2(fn))(qenv(fn), stack[-6], v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    stack[0] = elt(env, 21); // bb
    v0673 = elt(env, 22); // quotient
    v0672 = (LispObject)17; // 1
    v0671 = elt(env, 19); // liemat
    v0671 = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    fn = elt(env, 33); // aeval
    v0671 = (*qfn1(fn))(qenv(fn), v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    fn = elt(env, 34); // setk
    v0671 = (*qfn2(fn))(qenv(fn), stack[0], v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0671 = (LispObject)17; // 1
    stack[-12] = v0671;
    v0671 = (LispObject)1; // 0
    stack[-11] = v0671;
    goto v0679;

v0679:
    v0672 = (LispObject)65; // 4
    v0671 = stack[-12];
    v0671 = difference2(v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0671 = Lminusp(nil, v0671);
    env = stack[-16];
    if (v0671 == nil) goto v0680;
    v0671 = stack[-11];
    stack[-14] = v0671;
    v0671 = (LispObject)17; // 1
    stack[-12] = v0671;
    v0671 = (LispObject)1; // 0
    stack[-11] = v0671;
    goto v0681;

v0681:
    v0672 = (LispObject)65; // 4
    v0671 = stack[-12];
    v0671 = difference2(v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0671 = Lminusp(nil, v0671);
    env = stack[-16];
    if (v0671 == nil) goto v0682;
    v0671 = stack[-11];
    stack[-13] = v0671;
    v0671 = (LispObject)17; // 1
    stack[-12] = v0671;
    v0671 = (LispObject)1; // 0
    stack[-11] = v0671;
    goto v0683;

v0683:
    v0672 = (LispObject)65; // 4
    v0671 = stack[-12];
    v0671 = difference2(v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0671 = Lminusp(nil, v0671);
    env = stack[-16];
    if (v0671 == nil) goto v0684;
    v0671 = stack[-11];
    stack[0] = v0671;
    v0672 = stack[-15];
    v0671 = (LispObject)17; // 1
    if (v0672 == v0671) goto v0685;
    stack[-6] = elt(env, 19); // liemat
    stack[-5] = elt(env, 6); // times
    stack[-4] = elt(env, 20); // mat
    v0674 = (LispObject)17; // 1
    v0673 = (LispObject)1; // 0
    v0672 = (LispObject)1; // 0
    v0671 = (LispObject)1; // 0
    stack[-3] = list4(v0674, v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0674 = (LispObject)1; // 0
    v0673 = (LispObject)17; // 1
    v0672 = (LispObject)1; // 0
    v0671 = (LispObject)1; // 0
    stack[-2] = list4(v0674, v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0674 = (LispObject)1; // 0
    v0673 = (LispObject)1; // 0
    v0672 = (LispObject)17; // 1
    v0671 = (LispObject)1; // 0
    stack[-1] = list4(v0674, v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0672 = elt(env, 7); // minus
    v0671 = stack[-13];
    stack[-7] = list2(v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0672 = elt(env, 7); // minus
    v0671 = stack[-14];
    v0672 = list2(v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0671 = (LispObject)17; // 1
    v0671 = list4(stack[0], stack[-7], v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0671 = list2(stack[-1], v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0672 = list3star(stack[-4], stack[-3], stack[-2], v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0671 = elt(env, 19); // liemat
    v0671 = list3(stack[-5], v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    fn = elt(env, 33); // aeval
    v0671 = (*qfn1(fn))(qenv(fn), v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    fn = elt(env, 34); // setk
    v0671 = (*qfn2(fn))(qenv(fn), stack[-6], v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    goto v0686;

v0686:
    v0672 = stack[-15];
    v0671 = (LispObject)17; // 1
    if (v0672 == v0671) goto v0687;
    v0671 = qvalue(elt(env, 24)); // !*tr_lie
    fn = elt(env, 37); // revalx
    v0671 = (*qfn1(fn))(qenv(fn), v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    fn = elt(env, 38); // boolvalue!*
    v0671 = (*qfn1(fn))(qenv(fn), v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    if (v0671 == nil) goto v0688;
    v0671 = elt(env, 31); // "[W,X]=Y, [W,Y]=X, [X,Y]=W"
    fn = elt(env, 33); // aeval
    v0673 = (*qfn1(fn))(qenv(fn), v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0672 = qvalue(elt(env, 11)); // nil
    v0671 = elt(env, 26); // only
    fn = elt(env, 39); // assgnpri
    v0671 = (*qfnn(fn))(qenv(fn), 3, v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    goto v0688;

v0688:
    stack[-2] = elt(env, 27); // lie_class
    stack[-1] = elt(env, 28); // list
    v0672 = elt(env, 29); // liealg
    v0671 = (LispObject)65; // 4
    stack[0] = list2(v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0672 = elt(env, 30); // comtab
    v0671 = (LispObject)353; // 22
    v0671 = list2(v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0671 = list3(stack[-1], stack[0], v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    fn = elt(env, 33); // aeval
    v0671 = (*qfn1(fn))(qenv(fn), v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    fn = elt(env, 34); // setk
    v0671 = (*qfn2(fn))(qenv(fn), stack[-2], v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    goto v0689;

v0689:
    v0672 = elt(env, 1); // l_k
    v0671 = elt(env, 2); // l_a
    v0671 = list2(v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    fn = elt(env, 40); // clear
    v0671 = (*qfn1(fn))(qenv(fn), v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    fn = elt(env, 33); // aeval
    v0671 = (*qfn1(fn))(qenv(fn), v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    v0671 = nil;
    { popv(17); return onevalue(v0671); }

v0687:
    v0671 = qvalue(elt(env, 24)); // !*tr_lie
    fn = elt(env, 37); // revalx
    v0671 = (*qfn1(fn))(qenv(fn), v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    fn = elt(env, 38); // boolvalue!*
    v0671 = (*qfn1(fn))(qenv(fn), v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    if (v0671 == nil) goto v0690;
    v0671 = elt(env, 25); // "[W,X]=Y, [W,Y]=-X, [X,Y]=W"
    fn = elt(env, 33); // aeval
    v0673 = (*qfn1(fn))(qenv(fn), v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0672 = qvalue(elt(env, 11)); // nil
    v0671 = elt(env, 26); // only
    fn = elt(env, 39); // assgnpri
    v0671 = (*qfnn(fn))(qenv(fn), 3, v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    goto v0690;

v0690:
    stack[-2] = elt(env, 27); // lie_class
    stack[-1] = elt(env, 28); // list
    v0672 = elt(env, 29); // liealg
    v0671 = (LispObject)65; // 4
    stack[0] = list2(v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0672 = elt(env, 30); // comtab
    v0671 = (LispObject)337; // 21
    v0671 = list2(v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0671 = list3(stack[-1], stack[0], v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    fn = elt(env, 33); // aeval
    v0671 = (*qfn1(fn))(qenv(fn), v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    fn = elt(env, 34); // setk
    v0671 = (*qfn2(fn))(qenv(fn), stack[-2], v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    goto v0689;

v0685:
    stack[-6] = elt(env, 19); // liemat
    stack[-5] = elt(env, 6); // times
    stack[-4] = elt(env, 20); // mat
    v0674 = (LispObject)17; // 1
    v0673 = (LispObject)1; // 0
    v0672 = (LispObject)1; // 0
    v0671 = (LispObject)1; // 0
    stack[-3] = list4(v0674, v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0674 = (LispObject)1; // 0
    v0673 = (LispObject)17; // 1
    v0672 = (LispObject)1; // 0
    v0671 = (LispObject)1; // 0
    stack[-2] = list4(v0674, v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0674 = (LispObject)1; // 0
    v0673 = (LispObject)1; // 0
    v0672 = (LispObject)17; // 1
    v0671 = (LispObject)1; // 0
    stack[-1] = list4(v0674, v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0672 = elt(env, 7); // minus
    v0671 = stack[-13];
    v0673 = list2(v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0672 = stack[-14];
    v0671 = (LispObject)17; // 1
    v0671 = list4(stack[0], v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0671 = list2(stack[-1], v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0672 = list3star(stack[-4], stack[-3], stack[-2], v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0671 = elt(env, 19); // liemat
    v0671 = list3(stack[-5], v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    fn = elt(env, 33); // aeval
    v0671 = (*qfn1(fn))(qenv(fn), v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    fn = elt(env, 34); // setk
    v0671 = (*qfn2(fn))(qenv(fn), stack[-6], v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    goto v0686;

v0684:
    stack[-10] = elt(env, 3); // plus
    v0671 = (LispObject)17; // 1
    stack[-9] = v0671;
    v0671 = (LispObject)1; // 0
    stack[-8] = v0671;
    goto v0691;

v0691:
    v0672 = (LispObject)65; // 4
    v0671 = stack[-9];
    v0671 = difference2(v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0671 = Lminusp(nil, v0671);
    env = stack[-16];
    if (v0671 == nil) goto v0692;
    v0671 = stack[-8];
    v0672 = v0671;
    v0671 = stack[-11];
    v0671 = list3(stack[-10], v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    fn = elt(env, 41); // aeval!*
    v0671 = (*qfn1(fn))(qenv(fn), v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    stack[-11] = v0671;
    v0671 = stack[-12];
    v0671 = add1(v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    stack[-12] = v0671;
    goto v0683;

v0692:
    stack[-7] = elt(env, 3); // plus
    v0671 = (LispObject)17; // 1
    stack[-6] = v0671;
    v0671 = (LispObject)1; // 0
    stack[-5] = v0671;
    goto v0693;

v0693:
    v0672 = (LispObject)65; // 4
    v0671 = stack[-6];
    v0671 = difference2(v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0671 = Lminusp(nil, v0671);
    env = stack[-16];
    if (v0671 == nil) goto v0694;
    v0671 = stack[-5];
    v0672 = v0671;
    v0671 = stack[-8];
    v0671 = list3(stack[-7], v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    fn = elt(env, 41); // aeval!*
    v0671 = (*qfn1(fn))(qenv(fn), v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    stack[-8] = v0671;
    v0671 = stack[-9];
    v0671 = add1(v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    stack[-9] = v0671;
    goto v0691;

v0694:
    stack[-4] = elt(env, 3); // plus
    stack[-3] = elt(env, 6); // times
    v0673 = elt(env, 19); // liemat
    v0672 = (LispObject)33; // 2
    v0671 = stack[-12];
    stack[-2] = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0673 = elt(env, 19); // liemat
    v0672 = (LispObject)65; // 4
    v0671 = stack[-9];
    stack[-1] = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0674 = elt(env, 23); // cc
    v0673 = stack[-12];
    v0672 = stack[-9];
    v0671 = stack[-6];
    stack[0] = list4(v0674, v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0673 = elt(env, 21); // bb
    v0672 = stack[-6];
    v0671 = (LispObject)49; // 3
    v0671 = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0671 = list2(stack[0], v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0671 = list3star(stack[-3], stack[-2], stack[-1], v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    fn = elt(env, 41); // aeval!*
    v0672 = (*qfn1(fn))(qenv(fn), v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0671 = stack[-5];
    v0671 = list3(stack[-4], v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    fn = elt(env, 41); // aeval!*
    v0671 = (*qfn1(fn))(qenv(fn), v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    stack[-5] = v0671;
    v0671 = stack[-6];
    v0671 = add1(v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    stack[-6] = v0671;
    goto v0693;

v0682:
    stack[-10] = elt(env, 3); // plus
    v0671 = (LispObject)17; // 1
    stack[-9] = v0671;
    v0671 = (LispObject)1; // 0
    stack[-8] = v0671;
    goto v0695;

v0695:
    v0672 = (LispObject)65; // 4
    v0671 = stack[-9];
    v0671 = difference2(v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0671 = Lminusp(nil, v0671);
    env = stack[-16];
    if (v0671 == nil) goto v0696;
    v0671 = stack[-8];
    v0672 = v0671;
    v0671 = stack[-11];
    v0671 = list3(stack[-10], v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    fn = elt(env, 41); // aeval!*
    v0671 = (*qfn1(fn))(qenv(fn), v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    stack[-11] = v0671;
    v0671 = stack[-12];
    v0671 = add1(v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    stack[-12] = v0671;
    goto v0681;

v0696:
    stack[-7] = elt(env, 3); // plus
    v0671 = (LispObject)17; // 1
    stack[-6] = v0671;
    v0671 = (LispObject)1; // 0
    stack[-5] = v0671;
    goto v0697;

v0697:
    v0672 = (LispObject)65; // 4
    v0671 = stack[-6];
    v0671 = difference2(v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0671 = Lminusp(nil, v0671);
    env = stack[-16];
    if (v0671 == nil) goto v0698;
    v0671 = stack[-5];
    v0672 = v0671;
    v0671 = stack[-8];
    v0671 = list3(stack[-7], v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    fn = elt(env, 41); // aeval!*
    v0671 = (*qfn1(fn))(qenv(fn), v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    stack[-8] = v0671;
    v0671 = stack[-9];
    v0671 = add1(v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    stack[-9] = v0671;
    goto v0695;

v0698:
    stack[-4] = elt(env, 3); // plus
    stack[-3] = elt(env, 6); // times
    v0673 = elt(env, 19); // liemat
    v0672 = (LispObject)17; // 1
    v0671 = stack[-12];
    stack[-2] = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0673 = elt(env, 19); // liemat
    v0672 = (LispObject)65; // 4
    v0671 = stack[-9];
    stack[-1] = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0674 = elt(env, 23); // cc
    v0673 = stack[-12];
    v0672 = stack[-9];
    v0671 = stack[-6];
    stack[0] = list4(v0674, v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0673 = elt(env, 21); // bb
    v0672 = stack[-6];
    v0671 = (LispObject)49; // 3
    v0671 = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0671 = list2(stack[0], v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0671 = list3star(stack[-3], stack[-2], stack[-1], v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    fn = elt(env, 41); // aeval!*
    v0672 = (*qfn1(fn))(qenv(fn), v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0671 = stack[-5];
    v0671 = list3(stack[-4], v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    fn = elt(env, 41); // aeval!*
    v0671 = (*qfn1(fn))(qenv(fn), v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    stack[-5] = v0671;
    v0671 = stack[-6];
    v0671 = add1(v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    stack[-6] = v0671;
    goto v0697;

v0680:
    stack[-10] = elt(env, 3); // plus
    v0671 = (LispObject)17; // 1
    stack[-9] = v0671;
    v0671 = (LispObject)1; // 0
    stack[-8] = v0671;
    goto v0699;

v0699:
    v0672 = (LispObject)65; // 4
    v0671 = stack[-9];
    v0671 = difference2(v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0671 = Lminusp(nil, v0671);
    env = stack[-16];
    if (v0671 == nil) goto v0700;
    v0671 = stack[-8];
    v0672 = v0671;
    v0671 = stack[-11];
    v0671 = list3(stack[-10], v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    fn = elt(env, 41); // aeval!*
    v0671 = (*qfn1(fn))(qenv(fn), v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    stack[-11] = v0671;
    v0671 = stack[-12];
    v0671 = add1(v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    stack[-12] = v0671;
    goto v0679;

v0700:
    stack[-7] = elt(env, 3); // plus
    v0671 = (LispObject)17; // 1
    stack[-6] = v0671;
    v0671 = (LispObject)1; // 0
    stack[-5] = v0671;
    goto v0701;

v0701:
    v0672 = (LispObject)65; // 4
    v0671 = stack[-6];
    v0671 = difference2(v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0671 = Lminusp(nil, v0671);
    env = stack[-16];
    if (v0671 == nil) goto v0702;
    v0671 = stack[-5];
    v0672 = v0671;
    v0671 = stack[-8];
    v0671 = list3(stack[-7], v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    fn = elt(env, 41); // aeval!*
    v0671 = (*qfn1(fn))(qenv(fn), v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    stack[-8] = v0671;
    v0671 = stack[-9];
    v0671 = add1(v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    stack[-9] = v0671;
    goto v0699;

v0702:
    stack[-4] = elt(env, 3); // plus
    stack[-3] = elt(env, 6); // times
    v0673 = elt(env, 19); // liemat
    v0672 = (LispObject)17; // 1
    v0671 = stack[-12];
    stack[-2] = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0673 = elt(env, 19); // liemat
    v0672 = (LispObject)65; // 4
    v0671 = stack[-9];
    stack[-1] = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0674 = elt(env, 23); // cc
    v0673 = stack[-12];
    v0672 = stack[-9];
    v0671 = stack[-6];
    stack[0] = list4(v0674, v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0673 = elt(env, 21); // bb
    v0672 = stack[-6];
    v0671 = (LispObject)33; // 2
    v0671 = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0671 = list2(stack[0], v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0671 = list3star(stack[-3], stack[-2], stack[-1], v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    fn = elt(env, 41); // aeval!*
    v0672 = (*qfn1(fn))(qenv(fn), v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0671 = stack[-5];
    v0671 = list3(stack[-4], v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    fn = elt(env, 41); // aeval!*
    v0671 = (*qfn1(fn))(qenv(fn), v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    stack[-5] = v0671;
    v0671 = stack[-6];
    v0671 = add1(v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    stack[-6] = v0671;
    goto v0701;

v0677:
    v0671 = elt(env, 18); // lie4so21
    v0671 = ncons(v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    fn = elt(env, 33); // aeval
    v0671 = (*qfn1(fn))(qenv(fn), v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    goto v0678;

v0676:
    v0671 = elt(env, 10); // "Is "
    fn = elt(env, 33); // aeval
    v0673 = (*qfn1(fn))(qenv(fn), v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0672 = qvalue(elt(env, 11)); // nil
    v0671 = elt(env, 12); // first
    fn = elt(env, 39); // assgnpri
    v0671 = (*qfnn(fn))(qenv(fn), 3, v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    stack[0] = elt(env, 7); // minus
    v0673 = elt(env, 1); // l_k
    v0672 = (LispObject)17; // 1
    v0671 = (LispObject)17; // 1
    v0671 = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0671 = list2(stack[0], v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    fn = elt(env, 33); // aeval
    v0673 = (*qfn1(fn))(qenv(fn), v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0672 = qvalue(elt(env, 11)); // nil
    v0671 = qvalue(elt(env, 11)); // nil
    fn = elt(env, 39); // assgnpri
    v0671 = (*qfnn(fn))(qenv(fn), 3, v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0671 = elt(env, 13); // ">0 and "
    fn = elt(env, 33); // aeval
    v0673 = (*qfn1(fn))(qenv(fn), v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0672 = qvalue(elt(env, 11)); // nil
    v0671 = qvalue(elt(env, 11)); // nil
    fn = elt(env, 39); // assgnpri
    v0671 = (*qfnn(fn))(qenv(fn), 3, v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    stack[-3] = elt(env, 8); // difference
    stack[-1] = elt(env, 6); // times
    v0673 = elt(env, 1); // l_k
    v0672 = (LispObject)17; // 1
    v0671 = (LispObject)17; // 1
    stack[0] = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0673 = elt(env, 1); // l_k
    v0672 = (LispObject)33; // 2
    v0671 = (LispObject)33; // 2
    v0671 = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    stack[-2] = list3(stack[-1], stack[0], v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    stack[-1] = elt(env, 6); // times
    v0673 = elt(env, 1); // l_k
    v0672 = (LispObject)17; // 1
    v0671 = (LispObject)33; // 2
    stack[0] = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0673 = elt(env, 1); // l_k
    v0672 = (LispObject)33; // 2
    v0671 = (LispObject)17; // 1
    v0671 = list3(v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0671 = list3(stack[-1], stack[0], v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0671 = list3(stack[-3], stack[-2], v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    fn = elt(env, 33); // aeval
    v0673 = (*qfn1(fn))(qenv(fn), v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0672 = qvalue(elt(env, 11)); // nil
    v0671 = qvalue(elt(env, 11)); // nil
    fn = elt(env, 39); // assgnpri
    v0671 = (*qfnn(fn))(qenv(fn), 3, v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0671 = elt(env, 13); // ">0 and "
    fn = elt(env, 33); // aeval
    v0673 = (*qfn1(fn))(qenv(fn), v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0672 = qvalue(elt(env, 11)); // nil
    v0671 = qvalue(elt(env, 11)); // nil
    fn = elt(env, 39); // assgnpri
    v0671 = (*qfnn(fn))(qenv(fn), 3, v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    stack[0] = elt(env, 7); // minus
    v0672 = elt(env, 9); // det
    v0671 = elt(env, 1); // l_k
    v0671 = list2(v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0671 = list2(stack[0], v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    fn = elt(env, 33); // aeval
    v0673 = (*qfn1(fn))(qenv(fn), v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0672 = qvalue(elt(env, 11)); // nil
    v0671 = qvalue(elt(env, 11)); // nil
    fn = elt(env, 39); // assgnpri
    v0671 = (*qfnn(fn))(qenv(fn), 3, v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0671 = elt(env, 14); // ">0 ? (y/n) and press <RETURN>"
    fn = elt(env, 33); // aeval
    v0673 = (*qfn1(fn))(qenv(fn), v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0672 = qvalue(elt(env, 11)); // nil
    v0671 = elt(env, 15); // last
    fn = elt(env, 39); // assgnpri
    v0671 = (*qfnn(fn))(qenv(fn), 3, v0673, v0672, v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0671 = Lread(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    fn = elt(env, 33); // aeval
    v0671 = (*qfn1(fn))(qenv(fn), v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    fn = elt(env, 33); // aeval
    stack[0] = (*qfn1(fn))(qenv(fn), v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    v0671 = elt(env, 16); // y
    fn = elt(env, 33); // aeval
    v0671 = (*qfn1(fn))(qenv(fn), v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    fn = elt(env, 42); // evalequal
    v0671 = (*qfn2(fn))(qenv(fn), stack[0], v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    if (v0671 == nil) goto v0703;
    v0671 = (LispObject)17; // 1
    fn = elt(env, 33); // aeval
    v0671 = (*qfn1(fn))(qenv(fn), v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    stack[-15] = v0671;
    v0671 = elt(env, 17); // lie4so3
    v0671 = ncons(v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    fn = elt(env, 33); // aeval
    v0671 = (*qfn1(fn))(qenv(fn), v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    goto v0678;

v0703:
    v0671 = elt(env, 18); // lie4so21
    v0671 = ncons(v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    fn = elt(env, 33); // aeval
    v0671 = (*qfn1(fn))(qenv(fn), v0671);
    nil = C_nil;
    if (exception_pending()) goto v0675;
    env = stack[-16];
    goto v0678;
// error exit handlers
v0675:
    popv(17);
    return nil;
}



// Code for lexorder

static LispObject CC_lexorder(LispObject env,
                         LispObject v0704)
{
    LispObject nil = C_nil;
    LispObject v0711, v0712;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lexorder");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0704);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0704);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    v0711 = v0704;
// end of prologue
    stack[-4] = nil;
    stack[-3] = v0711;
    goto v0713;

v0713:
    v0711 = stack[-3];
    if (v0711 == nil) { LispObject res = stack[-4]; popv(6); return onevalue(res); }
    v0711 = stack[-3];
    v0711 = qcar(v0711);
    stack[-2] = v0711;
    stack[-1] = qvalue(elt(env, 2)); // gv!*
    v0711 = stack[-2];
    stack[0] = qcar(v0711);
    v0712 = qvalue(elt(env, 2)); // gv!*
    v0711 = stack[-2];
    v0711 = qcar(v0711);
    v0711 = *(LispObject *)((char *)v0712 + (CELL-TAG_VECTOR) + ((int32_t)v0711/(16/CELL)));
    fn = elt(env, 3); // !*g2lex
    v0711 = (*qfn1(fn))(qenv(fn), v0711);
    nil = C_nil;
    if (exception_pending()) goto v0637;
    env = stack[-5];
    fn = elt(env, 4); // gcdout
    v0711 = (*qfn1(fn))(qenv(fn), v0711);
    nil = C_nil;
    if (exception_pending()) goto v0637;
    env = stack[-5];
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v0711;
    fn = elt(env, 5); // ljet
    v0711 = (*qfn1(fn))(qenv(fn), v0711);
    nil = C_nil;
    if (exception_pending()) goto v0637;
    env = stack[-5];
    v0712 = stack[-2];
    v0712 = qcar(v0712);
    v0712 = cons(v0712, v0711);
    nil = C_nil;
    if (exception_pending()) goto v0637;
    env = stack[-5];
    v0711 = stack[-4];
    fn = elt(env, 6); // insert
    v0711 = (*qfn2(fn))(qenv(fn), v0712, v0711);
    nil = C_nil;
    if (exception_pending()) goto v0637;
    env = stack[-5];
    stack[-4] = v0711;
    v0711 = stack[-3];
    v0711 = qcdr(v0711);
    stack[-3] = v0711;
    goto v0713;
// error exit handlers
v0637:
    popv(6);
    return nil;
}



// Code for quotfail

static LispObject CC_quotfail(LispObject env,
                         LispObject v0704, LispObject v0028)
{
    LispObject nil = C_nil;
    LispObject v0716, v0717, v0718;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for quotfail");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0028,v0704);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0704,v0028);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0028;
    stack[-1] = v0704;
// end of prologue
    v0716 = stack[-1];
    if (v0716 == nil) goto v0050;
    v0717 = stack[-1];
    v0716 = stack[0];
    fn = elt(env, 3); // quotf
    v0716 = (*qfn2(fn))(qenv(fn), v0717, v0716);
    nil = C_nil;
    if (exception_pending()) goto v0632;
    env = stack[-2];
    v0717 = v0716;
    v0716 = v0717;
    if (!(v0716 == nil)) { popv(3); return onevalue(v0717); }
    v0718 = elt(env, 2); // "UNEXPECTED DIVISION FAILURE"
    v0717 = stack[-1];
    v0716 = stack[0];
    v0716 = list3(v0718, v0717, v0716);
    nil = C_nil;
    if (exception_pending()) goto v0632;
    env = stack[-2];
    fn = elt(env, 4); // errorf
    v0716 = (*qfn1(fn))(qenv(fn), v0716);
    nil = C_nil;
    if (exception_pending()) goto v0632;
    v0716 = nil;
    { popv(3); return onevalue(v0716); }

v0050:
    v0716 = qvalue(elt(env, 1)); // polyzero
    { popv(3); return onevalue(v0716); }
// error exit handlers
v0632:
    popv(3);
    return nil;
}



// Code for lto_hmember

static LispObject CC_lto_hmember(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0722, v0723, v0670;
    LispObject fn;
    LispObject v0314, v0028, v0704;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "lto_hmember");
    va_start(aa, nargs);
    v0704 = va_arg(aa, LispObject);
    v0028 = va_arg(aa, LispObject);
    v0314 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lto_hmember");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0314,v0028,v0704);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0704,v0028,v0314);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    v0722 = v0314;
    v0723 = v0028;
    v0670 = v0704;
// end of prologue
    stack[-2] = v0670;
    stack[-1] = v0723;
    stack[0] = v0722;
    v0722 = v0670;
    v0722 = ncons(v0722);
    nil = C_nil;
    if (exception_pending()) goto v0724;
    env = stack[-3];
    fn = elt(env, 1); // apply
    v0722 = (*qfn2(fn))(qenv(fn), stack[0], v0722);
    nil = C_nil;
    if (exception_pending()) goto v0724;
    env = stack[-3];
    {
        LispObject v0708 = stack[-2];
        LispObject v0707 = stack[-1];
        popv(4);
        fn = elt(env, 2); // lto_hmember1
        return (*qfnn(fn))(qenv(fn), 3, v0708, v0707, v0722);
    }
// error exit handlers
v0724:
    popv(4);
    return nil;
}



// Code for evalleq

static LispObject CC_evalleq(LispObject env,
                         LispObject v0704, LispObject v0028)
{
    LispObject nil = C_nil;
    LispObject v0719, v0720;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evalleq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0028,v0704);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0704,v0028);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
// copy arguments values to proper place
    v0719 = v0028;
    v0720 = v0704;
// end of prologue
    fn = elt(env, 1); // evalgreaterp
    v0719 = (*qfn2(fn))(qenv(fn), v0720, v0719);
    errexit();
    v0719 = (v0719 == nil ? lisp_true : nil);
    return onevalue(v0719);
}



// Code for taysimpsq!*

static LispObject CC_taysimpsqH(LispObject env,
                         LispObject v0704)
{
    LispObject nil = C_nil;
    LispObject v0710, v0726;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for taysimpsq*");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0704);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0704);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0726 = v0704;
// end of prologue
    v0710 = qvalue(elt(env, 1)); // nil
    stack[0] = qvalue(elt(env, 2)); // !*taylorautoexpand
    qvalue(elt(env, 2)) = v0710; // !*taylorautoexpand
    v0710 = v0726;
    fn = elt(env, 3); // taysimpsq
    v0710 = (*qfn1(fn))(qenv(fn), v0710);
    nil = C_nil;
    if (exception_pending()) goto v0713;
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; // !*taylorautoexpand
    { popv(2); return onevalue(v0710); }
// error exit handlers
v0713:
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; // !*taylorautoexpand
    popv(2);
    return nil;
}



// Code for pasf_exprng!-gball

static LispObject CC_pasf_exprngKgball(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0745, v0746, v0747, v0748;
    LispObject fn;
    LispObject v0050, v0049, v0046, v0314, v0028, v0704;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 6, "pasf_exprng-gball");
    va_start(aa, nargs);
    v0704 = va_arg(aa, LispObject);
    v0028 = va_arg(aa, LispObject);
    v0314 = va_arg(aa, LispObject);
    v0046 = va_arg(aa, LispObject);
    v0049 = va_arg(aa, LispObject);
    v0050 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pasf_exprng-gball");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push6(v0050,v0049,v0046,v0314,v0028,v0704);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v0704,v0028,v0314,v0046,v0049,v0050);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-4] = v0050;
    stack[-5] = v0049;
    stack[-6] = v0046;
    stack[-7] = v0314;
    stack[0] = v0028;
    stack[-8] = v0704;
// end of prologue
    stack[-2] = nil;
    v0745 = stack[0];
    fn = elt(env, 9); // cl_fvarl
    v0745 = (*qfn1(fn))(qenv(fn), v0745);
    nil = C_nil;
    if (exception_pending()) goto v0749;
    env = stack[-10];
    v0747 = v0745;
    v0746 = stack[-8];
    if (!consp(v0747)) goto v0722;
    v0747 = qcar(v0747);
    if (!(v0747 == v0746)) goto v0722;
    v0746 = v0745;
    v0746 = qcdr(v0746);
    goto v0750;

v0750:
    if (v0746 == nil) goto v0751;
    v0748 = elt(env, 2); // "pasf_exprng: bad bound "
    v0747 = stack[0];
    v0746 = elt(env, 3); // " with free variables "
    v0745 = list4(v0748, v0747, v0746, v0745);
    nil = C_nil;
    if (exception_pending()) goto v0749;
    env = stack[-10];
    fn = elt(env, 10); // rederr
    v0745 = (*qfn1(fn))(qenv(fn), v0745);
    nil = C_nil;
    if (exception_pending()) goto v0749;
    env = stack[-10];
    goto v0751;

v0751:
    v0745 = qvalue(elt(env, 4)); // !*rlexprngnatural
    if (v0745 == nil) goto v0752;
    v0745 = stack[-7];
    fn = elt(env, 11); // pasf_exprng
    v0745 = (*qfn1(fn))(qenv(fn), v0745);
    nil = C_nil;
    if (exception_pending()) goto v0749;
    env = stack[-10];
    stack[-7] = v0745;
    goto v0752;

v0752:
    v0745 = stack[0];
    fn = elt(env, 12); // pasf_qff2ivl
    v0745 = (*qfn1(fn))(qenv(fn), v0745);
    nil = C_nil;
    if (exception_pending()) goto v0749;
    env = stack[-10];
    stack[-1] = v0745;
    v0745 = qvalue(elt(env, 1)); // t
    stack[-9] = v0745;
    goto v0753;

v0753:
    v0745 = stack[-9];
    if (v0745 == nil) goto v0754;
    v0745 = stack[-1];
    if (v0745 == nil) goto v0754;
    v0745 = stack[-1];
    v0745 = qcar(v0745);
    v0746 = v0745;
    v0745 = stack[-1];
    v0745 = qcdr(v0745);
    stack[-1] = v0745;
    v0745 = v0746;
    stack[0] = v0745;
    v0745 = stack[0];
    v0745 = qcar(v0745);
    stack[-3] = v0745;
    goto v0657;

v0657:
    v0745 = stack[-9];
    if (v0745 == nil) goto v0753;
    v0746 = stack[-3];
    v0745 = stack[0];
    v0745 = qcdr(v0745);
    v0745 = (LispObject)lesseq2(v0746, v0745);
    nil = C_nil;
    if (exception_pending()) goto v0749;
    v0745 = v0745 ? lisp_true : nil;
    env = stack[-10];
    if (v0745 == nil) goto v0753;
    v0747 = stack[-7];
    v0746 = stack[-8];
    v0745 = stack[-3];
    fn = elt(env, 13); // pasf_sisub
    v0745 = (*qfnn(fn))(qenv(fn), 3, v0747, v0746, v0745);
    nil = C_nil;
    if (exception_pending()) goto v0749;
    env = stack[-10];
    v0746 = qvalue(elt(env, 4)); // !*rlexprngnatural
    if (!(v0746 == nil)) goto v0755;
    fn = elt(env, 11); // pasf_exprng
    v0745 = (*qfn1(fn))(qenv(fn), v0745);
    nil = C_nil;
    if (exception_pending()) goto v0749;
    env = stack[-10];
    goto v0755;

v0755:
    v0747 = v0745;
    v0746 = stack[-4];
    if (v0747 == v0746) goto v0756;
    v0747 = v0745;
    v0746 = stack[-5];
    if (equal(v0747, v0746)) goto v0757;
    v0746 = v0745;
    v0745 = stack[-2];
    v0745 = cons(v0746, v0745);
    nil = C_nil;
    if (exception_pending()) goto v0749;
    env = stack[-10];
    stack[-2] = v0745;
    goto v0757;

v0757:
    v0745 = stack[-3];
    v0745 = add1(v0745);
    nil = C_nil;
    if (exception_pending()) goto v0749;
    env = stack[-10];
    stack[-3] = v0745;
    goto v0657;

v0756:
    v0745 = qvalue(elt(env, 5)); // nil
    stack[-9] = v0745;
    goto v0657;

v0754:
    v0745 = stack[-9];
    if (v0745 == nil) { LispObject res = stack[-4]; popv(11); return onevalue(res); }
    v0745 = stack[-2];
    if (v0745 == nil) goto v0758;
    v0745 = stack[-2];
    v0745 = qcdr(v0745);
    if (v0745 == nil) goto v0758;
    v0746 = stack[-6];
    v0745 = stack[-2];
    popv(11);
    return cons(v0746, v0745);

v0758:
    v0745 = stack[-2];
    if (v0745 == nil) goto v0759;
    v0745 = stack[-2];
    v0745 = qcar(v0745);
    { popv(11); return onevalue(v0745); }

v0759:
    v0746 = stack[-6];
    v0745 = elt(env, 6); // and
    if (v0746 == v0745) goto v0760;
    v0745 = elt(env, 8); // false
    { popv(11); return onevalue(v0745); }

v0760:
    v0745 = elt(env, 7); // true
    { popv(11); return onevalue(v0745); }

v0722:
    v0746 = qvalue(elt(env, 1)); // t
    goto v0750;
// error exit handlers
v0749:
    popv(11);
    return nil;
}



// Code for aex_lc

static LispObject CC_aex_lc(LispObject env,
                         LispObject v0704, LispObject v0028)
{
    LispObject nil = C_nil;
    LispObject v0753, v0765;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for aex_lc");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0028,v0704);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0704,v0028);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    v0753 = v0028;
    stack[-1] = v0704;
// end of prologue
    v0765 = stack[-1];
    fn = elt(env, 1); // aex_mvartest
    v0753 = (*qfn2(fn))(qenv(fn), v0765, v0753);
    nil = C_nil;
    if (exception_pending()) goto v0636;
    env = stack[-3];
    if (v0753 == nil) { LispObject res = stack[-1]; popv(4); return onevalue(res); }
    v0753 = stack[-1];
    fn = elt(env, 2); // aex_ex
    v0753 = (*qfn1(fn))(qenv(fn), v0753);
    nil = C_nil;
    if (exception_pending()) goto v0636;
    env = stack[-3];
    stack[-2] = v0753;
    v0753 = stack[-2];
    v0753 = qcar(v0753);
    fn = elt(env, 3); // sfto_lcx
    v0765 = (*qfn1(fn))(qenv(fn), v0753);
    nil = C_nil;
    if (exception_pending()) goto v0636;
    env = stack[-3];
    v0753 = (LispObject)17; // 1
    stack[0] = cons(v0765, v0753);
    nil = C_nil;
    if (exception_pending()) goto v0636;
    env = stack[-3];
    v0753 = stack[-2];
    v0765 = qcdr(v0753);
    v0753 = (LispObject)17; // 1
    v0753 = cons(v0765, v0753);
    nil = C_nil;
    if (exception_pending()) goto v0636;
    env = stack[-3];
    fn = elt(env, 4); // quotsq
    v0753 = (*qfn2(fn))(qenv(fn), stack[0], v0753);
    nil = C_nil;
    if (exception_pending()) goto v0636;
    env = stack[-3];
    stack[-2] = v0753;
    v0753 = qcar(v0753);
    fn = elt(env, 5); // kernels
    stack[0] = (*qfn1(fn))(qenv(fn), v0753);
    nil = C_nil;
    if (exception_pending()) goto v0636;
    env = stack[-3];
    v0753 = stack[-1];
    fn = elt(env, 6); // aex_ctx
    v0753 = (*qfn1(fn))(qenv(fn), v0753);
    nil = C_nil;
    if (exception_pending()) goto v0636;
    env = stack[-3];
    fn = elt(env, 7); // ctx_filter
    v0753 = (*qfn2(fn))(qenv(fn), stack[0], v0753);
    nil = C_nil;
    if (exception_pending()) goto v0636;
    env = stack[-3];
    {
        LispObject v0766 = stack[-2];
        popv(4);
        fn = elt(env, 8); // aex_mk
        return (*qfn2(fn))(qenv(fn), v0766, v0753);
    }
// error exit handlers
v0636:
    popv(4);
    return nil;
}



// Code for rnfloor!*

static LispObject CC_rnfloorH(LispObject env,
                         LispObject v0704)
{
    LispObject nil = C_nil;
    LispObject v0764, v0767;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rnfloor*");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0704);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0704);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0704;
// end of prologue
    v0764 = stack[0];
    v0764 = qcdr(v0764);
    v0767 = qcar(v0764);
    v0764 = stack[0];
    v0764 = qcdr(v0764);
    v0764 = qcdr(v0764);
    v0764 = Ldivide(nil, v0767, v0764);
    nil = C_nil;
    if (exception_pending()) goto v0667;
    env = stack[-1];
    stack[0] = v0764;
    v0767 = qcdr(v0764);
    v0764 = (LispObject)1; // 0
    v0764 = (LispObject)lessp2(v0767, v0764);
    nil = C_nil;
    if (exception_pending()) goto v0667;
    v0764 = v0764 ? lisp_true : nil;
    if (v0764 == nil) goto v0724;
    v0764 = stack[0];
    v0764 = qcar(v0764);
    popv(2);
    return sub1(v0764);

v0724:
    v0764 = stack[0];
    v0764 = qcar(v0764);
    { popv(2); return onevalue(v0764); }
// error exit handlers
v0667:
    popv(2);
    return nil;
}



// Code for codfac

static LispObject CC_codfac(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0781, v0782;
    LispObject fn;
    argcheck(nargs, 0, "codfac");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for codfac");
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
    push4(nil, nil, nil, nil);
// end of prologue
    stack[-3] = nil;
    stack[-2] = nil;
    v0781 = qvalue(elt(env, 1)); // rowmin
    stack[-1] = v0781;
    goto v0783;

v0783:
    v0782 = (LispObject)-15; // -1
    v0781 = stack[-1];
    v0781 = difference2(v0782, v0781);
    nil = C_nil;
    if (exception_pending()) goto v0784;
    env = stack[-4];
    v0781 = Lminusp(nil, v0781);
    env = stack[-4];
    if (!(v0781 == nil)) { LispObject res = stack[-3]; popv(5); return onevalue(res); }
    stack[0] = qvalue(elt(env, 3)); // codmat
    v0782 = qvalue(elt(env, 4)); // maxvar
    v0781 = stack[-1];
    v0781 = plus2(v0782, v0781);
    nil = C_nil;
    if (exception_pending()) goto v0784;
    env = stack[-4];
    v0782 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0781/(16/CELL)));
    v0781 = (LispObject)49; // 3
    v0782 = *(LispObject *)((char *)v0782 + (CELL-TAG_VECTOR) + ((int32_t)v0781/(16/CELL)));
    v0781 = (LispObject)-15; // -1
    if (v0782 == v0781) goto v0767;
    stack[0] = qvalue(elt(env, 3)); // codmat
    v0782 = qvalue(elt(env, 4)); // maxvar
    v0781 = stack[-1];
    v0781 = plus2(v0782, v0781);
    nil = C_nil;
    if (exception_pending()) goto v0784;
    env = stack[-4];
    v0782 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0781/(16/CELL)));
    v0781 = (LispObject)49; // 3
    v0782 = *(LispObject *)((char *)v0782 + (CELL-TAG_VECTOR) + ((int32_t)v0781/(16/CELL)));
    v0781 = (LispObject)-31; // -2
    v0781 = (v0782 == v0781 ? lisp_true : nil);
    goto v0764;

v0764:
    if (v0781 == nil) goto v0785;
    v0781 = qvalue(elt(env, 2)); // nil
    goto v0724;

v0724:
    if (v0781 == nil) goto v0670;
    v0781 = qvalue(elt(env, 5)); // t
    stack[-3] = v0781;
    v0781 = stack[-2];
    stack[0] = v0781;
    goto v0786;

v0786:
    v0781 = stack[0];
    if (v0781 == nil) goto v0670;
    v0781 = stack[0];
    v0781 = qcar(v0781);
    v0782 = stack[-1];
    fn = elt(env, 7); // commonfac
    v0781 = (*qfn2(fn))(qenv(fn), v0782, v0781);
    nil = C_nil;
    if (exception_pending()) goto v0784;
    env = stack[-4];
    v0781 = stack[0];
    v0781 = qcdr(v0781);
    stack[0] = v0781;
    goto v0786;

v0670:
    v0781 = stack[-1];
    v0781 = add1(v0781);
    nil = C_nil;
    if (exception_pending()) goto v0784;
    env = stack[-4];
    stack[-1] = v0781;
    goto v0783;

v0785:
    stack[0] = qvalue(elt(env, 3)); // codmat
    v0782 = qvalue(elt(env, 4)); // maxvar
    v0781 = stack[-1];
    v0781 = plus2(v0782, v0781);
    nil = C_nil;
    if (exception_pending()) goto v0784;
    env = stack[-4];
    v0782 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0781/(16/CELL)));
    v0781 = (LispObject)33; // 2
    v0782 = *(LispObject *)((char *)v0782 + (CELL-TAG_VECTOR) + ((int32_t)v0781/(16/CELL)));
    v0781 = elt(env, 6); // times
    if (v0782 == v0781) goto v0787;
    v0781 = qvalue(elt(env, 2)); // nil
    goto v0724;

v0787:
    v0781 = stack[-1];
    fn = elt(env, 8); // samefar
    v0781 = (*qfn1(fn))(qenv(fn), v0781);
    nil = C_nil;
    if (exception_pending()) goto v0784;
    env = stack[-4];
    stack[-2] = v0781;
    goto v0724;

v0767:
    v0781 = qvalue(elt(env, 5)); // t
    goto v0764;
// error exit handlers
v0784:
    popv(5);
    return nil;
}



// Code for qsimpcomb_standard_qexp_part_sf

static LispObject CC_qsimpcomb_standard_qexp_part_sf(LispObject env,
                         LispObject v0704, LispObject v0028)
{
    LispObject nil = C_nil;
    LispObject v0795, v0796, v0650, v0648;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qsimpcomb_standard_qexp_part_sf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0028,v0704);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0704,v0028);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0028;
    stack[-1] = v0704;
// end of prologue
    v0795 = qvalue(elt(env, 1)); // nil
    fn = elt(env, 4); // simp
    v0795 = (*qfn1(fn))(qenv(fn), v0795);
    nil = C_nil;
    if (exception_pending()) goto v0773;
    env = stack[-3];
    v0648 = v0795;
    goto v0739;

v0739:
    v0795 = stack[-1];
    v0795 = Lconsp(nil, v0795);
    env = stack[-3];
    if (v0795 == nil) { popv(4); return onevalue(v0648); }
    v0795 = stack[-1];
    v0795 = qcdr(v0795);
    if (!(v0795 == nil)) { popv(4); return onevalue(v0648); }
    v0795 = stack[-1];
    v0795 = qcar(v0795);
    v0795 = qcar(v0795);
    v0796 = qcar(v0795);
    v0795 = stack[0];
    if (v0796 == v0795) goto v0666;
    v0795 = stack[-1];
    v0795 = qcar(v0795);
    v0795 = qcar(v0795);
    v0795 = qcar(v0795);
    v0650 = v0795;
    v0795 = v0650;
    v0795 = Lconsp(nil, v0795);
    env = stack[-3];
    if (v0795 == nil) goto v0723;
    v0795 = v0650;
    v0796 = qcar(v0795);
    v0795 = elt(env, 2); // expt
    if (v0796 == v0795) goto v0738;
    v0795 = qvalue(elt(env, 1)); // nil
    goto v0765;

v0765:
    if (v0795 == nil) goto v0723;
    stack[-2] = v0648;
    v0796 = elt(env, 3); // times
    v0795 = v0650;
    v0795 = qcdr(v0795);
    v0795 = qcdr(v0795);
    v0650 = qcar(v0795);
    v0795 = stack[-1];
    v0795 = qcar(v0795);
    v0795 = qcar(v0795);
    v0795 = qcdr(v0795);
    v0795 = list3(v0796, v0650, v0795);
    nil = C_nil;
    if (exception_pending()) goto v0773;
    env = stack[-3];
    fn = elt(env, 4); // simp
    v0795 = (*qfn1(fn))(qenv(fn), v0795);
    nil = C_nil;
    if (exception_pending()) goto v0773;
    env = stack[-3];
    fn = elt(env, 5); // addsq
    v0795 = (*qfn2(fn))(qenv(fn), stack[-2], v0795);
    nil = C_nil;
    if (exception_pending()) goto v0773;
    env = stack[-3];
    v0648 = v0795;
    goto v0723;

v0723:
    v0795 = stack[-1];
    v0795 = qcar(v0795);
    v0795 = qcdr(v0795);
    stack[-1] = v0795;
    goto v0739;

v0738:
    v0795 = v0650;
    v0795 = qcdr(v0795);
    v0796 = qcar(v0795);
    v0795 = stack[0];
    v0795 = (v0796 == v0795 ? lisp_true : nil);
    goto v0765;

v0666:
    stack[-2] = v0648;
    v0795 = stack[-1];
    v0795 = qcar(v0795);
    v0795 = qcar(v0795);
    v0795 = qcdr(v0795);
    fn = elt(env, 4); // simp
    v0795 = (*qfn1(fn))(qenv(fn), v0795);
    nil = C_nil;
    if (exception_pending()) goto v0773;
    env = stack[-3];
    fn = elt(env, 5); // addsq
    v0795 = (*qfn2(fn))(qenv(fn), stack[-2], v0795);
    nil = C_nil;
    if (exception_pending()) goto v0773;
    env = stack[-3];
    v0648 = v0795;
    goto v0723;
// error exit handlers
v0773:
    popv(4);
    return nil;
}



// Code for rm_neg_pow

static LispObject CC_rm_neg_pow(LispObject env,
                         LispObject v0704)
{
    LispObject nil = C_nil;
    LispObject v0650, v0648;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rm_neg_pow");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0704);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0704);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0704;
// end of prologue
    v0650 = stack[-1];
    if (!consp(v0650)) goto v0730;
    v0650 = stack[-1];
    v0650 = qcar(v0650);
    v0650 = (consp(v0650) ? nil : lisp_true);
    goto v0726;

v0726:
    if (v0650 == nil) goto v0050;
    v0648 = stack[-1];
    v0650 = (LispObject)17; // 1
    popv(4);
    return cons(v0648, v0650);

v0050:
    v0650 = stack[-1];
    v0650 = qcar(v0650);
    v0650 = qcar(v0650);
    v0650 = qcdr(v0650);
    v0650 = Lminusp(nil, v0650);
    env = stack[-3];
    if (v0650 == nil) goto v0801;
    stack[-2] = (LispObject)17; // 1
    v0650 = stack[-1];
    v0650 = qcar(v0650);
    v0650 = qcar(v0650);
    stack[0] = qcar(v0650);
    v0650 = stack[-1];
    v0650 = qcar(v0650);
    v0650 = qcar(v0650);
    v0650 = qcdr(v0650);
    v0650 = negate(v0650);
    nil = C_nil;
    if (exception_pending()) goto v0773;
    env = stack[-3];
    fn = elt(env, 3); // to
    v0648 = (*qfn2(fn))(qenv(fn), stack[0], v0650);
    nil = C_nil;
    if (exception_pending()) goto v0773;
    env = stack[-3];
    v0650 = (LispObject)17; // 1
    v0648 = cons(v0648, v0650);
    nil = C_nil;
    if (exception_pending()) goto v0773;
    env = stack[-3];
    v0650 = qvalue(elt(env, 2)); // nil
    stack[0] = list2star(stack[-2], v0648, v0650);
    nil = C_nil;
    if (exception_pending()) goto v0773;
    env = stack[-3];
    v0650 = stack[-1];
    v0650 = qcar(v0650);
    v0650 = qcdr(v0650);
    v0650 = CC_rm_neg_pow(env, v0650);
    nil = C_nil;
    if (exception_pending()) goto v0773;
    env = stack[-3];
    fn = elt(env, 4); // multsq
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v0650);
    nil = C_nil;
    if (exception_pending()) goto v0773;
    env = stack[-3];
    v0650 = stack[-1];
    v0650 = qcdr(v0650);
    v0650 = CC_rm_neg_pow(env, v0650);
    nil = C_nil;
    if (exception_pending()) goto v0773;
    env = stack[-3];
    {
        LispObject v0755 = stack[0];
        popv(4);
        fn = elt(env, 5); // addsq
        return (*qfn2(fn))(qenv(fn), v0755, v0650);
    }

v0801:
    v0650 = stack[-1];
    v0650 = qcar(v0650);
    v0648 = qcar(v0650);
    v0650 = (LispObject)17; // 1
    v0650 = cons(v0648, v0650);
    nil = C_nil;
    if (exception_pending()) goto v0773;
    env = stack[-3];
    v0648 = ncons(v0650);
    nil = C_nil;
    if (exception_pending()) goto v0773;
    env = stack[-3];
    v0650 = (LispObject)17; // 1
    stack[0] = cons(v0648, v0650);
    nil = C_nil;
    if (exception_pending()) goto v0773;
    env = stack[-3];
    v0650 = stack[-1];
    v0650 = qcar(v0650);
    v0650 = qcdr(v0650);
    v0650 = CC_rm_neg_pow(env, v0650);
    nil = C_nil;
    if (exception_pending()) goto v0773;
    env = stack[-3];
    fn = elt(env, 4); // multsq
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v0650);
    nil = C_nil;
    if (exception_pending()) goto v0773;
    env = stack[-3];
    v0650 = stack[-1];
    v0650 = qcdr(v0650);
    v0650 = CC_rm_neg_pow(env, v0650);
    nil = C_nil;
    if (exception_pending()) goto v0773;
    env = stack[-3];
    {
        LispObject v0802 = stack[0];
        popv(4);
        fn = elt(env, 5); // addsq
        return (*qfn2(fn))(qenv(fn), v0802, v0650);
    }

v0730:
    v0650 = qvalue(elt(env, 1)); // t
    goto v0726;
// error exit handlers
v0773:
    popv(4);
    return nil;
}



// Code for mkuniquewedge1

static LispObject CC_mkuniquewedge1(LispObject env,
                         LispObject v0704)
{
    LispObject nil = C_nil;
    LispObject v0666, v0803;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mkuniquewedge1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0704);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0704);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0704;
// end of prologue
    v0666 = stack[0];
    v0666 = qcdr(v0666);
    if (v0666 == nil) goto v0049;
    v0666 = qvalue(elt(env, 1)); // wedgemtch!*
    if (v0666 == nil) goto v0707;
    v0666 = stack[0];
    fn = elt(env, 3); // wedgemtch
    v0666 = (*qfn1(fn))(qenv(fn), v0666);
    nil = C_nil;
    if (exception_pending()) goto v0804;
    env = stack[-1];
    v0803 = v0666;
    if (v0666 == nil) goto v0707;
    v0666 = v0803;
    {
        popv(2);
        fn = elt(env, 4); // partitop
        return (*qfn1(fn))(qenv(fn), v0666);
    }

v0707:
    v0803 = elt(env, 2); // wedge
    v0666 = stack[0];
    v0666 = cons(v0803, v0666);
    nil = C_nil;
    if (exception_pending()) goto v0804;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 5); // mkupf
        return (*qfn1(fn))(qenv(fn), v0666);
    }

v0049:
    v0666 = stack[0];
    v0666 = qcar(v0666);
    {
        popv(2);
        fn = elt(env, 5); // mkupf
        return (*qfn1(fn))(qenv(fn), v0666);
    }
// error exit handlers
v0804:
    popv(2);
    return nil;
}



// Code for rand_functionp

static LispObject CC_rand_functionp(LispObject env,
                         LispObject v0704)
{
    LispObject nil = C_nil;
    LispObject v0805, v0783;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rand_functionp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0704);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0704);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0704;
// end of prologue
    v0805 = stack[0];
    fn = elt(env, 2); // getd
    v0805 = (*qfn1(fn))(qenv(fn), v0805);
    nil = C_nil;
    if (exception_pending()) goto v0751;
    env = stack[-1];
    if (!(v0805 == nil)) { popv(2); return onevalue(v0805); }
    v0805 = stack[0];
    v0783 = elt(env, 1); // lambda
        popv(2);
        return Leqcar(nil, v0805, v0783);
// error exit handlers
v0751:
    popv(2);
    return nil;
}



// Code for !:dmexpt

static LispObject CC_Tdmexpt(LispObject env,
                         LispObject v0704, LispObject v0028)
{
    LispObject nil = C_nil;
    LispObject v0743, v0742;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for :dmexpt");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0028,v0704);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0704,v0028);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0028;
    stack[-1] = v0704;
// end of prologue
    v0743 = stack[0];
    fn = elt(env, 2); // !:dm2fix
    v0743 = (*qfn1(fn))(qenv(fn), v0743);
    nil = C_nil;
    if (exception_pending()) goto v0761;
    env = stack[-2];
    v0742 = v0743;
    v0742 = integerp(v0742);
    if (v0742 == nil) goto v0714;
    v0742 = stack[-1];
    {
        popv(3);
        fn = elt(env, 3); // !:expt
        return (*qfn2(fn))(qenv(fn), v0742, v0743);
    }

v0714:
    v0743 = stack[-1];
    fn = elt(env, 4); // force!-to!-dm
    v0743 = (*qfn1(fn))(qenv(fn), v0743);
    nil = C_nil;
    if (exception_pending()) goto v0761;
    env = stack[-2];
    stack[-1] = v0743;
    v0743 = stack[0];
    fn = elt(env, 4); // force!-to!-dm
    v0743 = (*qfn1(fn))(qenv(fn), v0743);
    nil = C_nil;
    if (exception_pending()) goto v0761;
    env = stack[-2];
    stack[0] = v0743;
    v0743 = qvalue(elt(env, 1)); // !*complex
    if (v0743 == nil) goto v0716;
    v0742 = stack[-1];
    v0743 = stack[0];
    {
        popv(3);
        fn = elt(env, 5); // crexpt!*
        return (*qfn2(fn))(qenv(fn), v0742, v0743);
    }

v0716:
    v0742 = stack[-1];
    v0743 = stack[0];
    {
        popv(3);
        fn = elt(env, 6); // rdexpt!*
        return (*qfn2(fn))(qenv(fn), v0742, v0743);
    }
// error exit handlers
v0761:
    popv(3);
    return nil;
}



// Code for partdff

static LispObject CC_partdff(LispObject env,
                         LispObject v0704, LispObject v0028)
{
    LispObject nil = C_nil;
    LispObject v0808, v0643;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for partdff");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0028,v0704);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0704,v0028);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-2] = v0028;
    stack[-3] = v0704;
// end of prologue
    stack[-4] = nil;
    goto v0726;

v0726:
    v0808 = stack[-3];
    if (!consp(v0808)) goto v0783;
    v0808 = stack[-3];
    v0808 = qcar(v0808);
    v0808 = (consp(v0808) ? nil : lisp_true);
    goto v0805;

v0805:
    if (v0808 == nil) goto v0668;
    v0643 = qvalue(elt(env, 3)); // nil
    v0808 = (LispObject)17; // 1
    v0808 = cons(v0643, v0808);
    nil = C_nil;
    if (exception_pending()) goto v0734;
    env = stack[-5];
    v0643 = v0808;
    goto v0713;

v0713:
    v0808 = stack[-4];
    if (v0808 == nil) { popv(6); return onevalue(v0643); }
    v0808 = stack[-4];
    v0808 = qcar(v0808);
    fn = elt(env, 4); // addsq
    v0808 = (*qfn2(fn))(qenv(fn), v0808, v0643);
    nil = C_nil;
    if (exception_pending()) goto v0734;
    env = stack[-5];
    v0643 = v0808;
    v0808 = stack[-4];
    v0808 = qcdr(v0808);
    stack[-4] = v0808;
    goto v0713;

v0668:
    v0808 = qvalue(elt(env, 2)); // !*product!-rule
    if (v0808 == nil) goto v0665;
    v0808 = stack[-3];
    v0808 = qcar(v0808);
    v0643 = qcar(v0808);
    v0808 = (LispObject)17; // 1
    v0808 = cons(v0643, v0808);
    nil = C_nil;
    if (exception_pending()) goto v0734;
    env = stack[-5];
    v0643 = ncons(v0808);
    nil = C_nil;
    if (exception_pending()) goto v0734;
    env = stack[-5];
    v0808 = (LispObject)17; // 1
    stack[0] = cons(v0643, v0808);
    nil = C_nil;
    if (exception_pending()) goto v0734;
    env = stack[-5];
    v0808 = stack[-3];
    v0808 = qcar(v0808);
    v0643 = qcdr(v0808);
    v0808 = stack[-2];
    v0808 = CC_partdff(env, v0643, v0808);
    nil = C_nil;
    if (exception_pending()) goto v0734;
    env = stack[-5];
    fn = elt(env, 5); // multsq
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[0], v0808);
    nil = C_nil;
    if (exception_pending()) goto v0734;
    env = stack[-5];
    v0808 = stack[-3];
    v0808 = qcar(v0808);
    v0643 = qcar(v0808);
    v0808 = stack[-2];
    fn = elt(env, 6); // partdfpow
    stack[0] = (*qfn2(fn))(qenv(fn), v0643, v0808);
    nil = C_nil;
    if (exception_pending()) goto v0734;
    env = stack[-5];
    v0808 = stack[-3];
    v0808 = qcar(v0808);
    v0643 = qcdr(v0808);
    v0808 = (LispObject)17; // 1
    v0808 = cons(v0643, v0808);
    nil = C_nil;
    if (exception_pending()) goto v0734;
    env = stack[-5];
    fn = elt(env, 5); // multsq
    v0808 = (*qfn2(fn))(qenv(fn), stack[0], v0808);
    nil = C_nil;
    if (exception_pending()) goto v0734;
    env = stack[-5];
    fn = elt(env, 4); // addsq
    v0808 = (*qfn2(fn))(qenv(fn), stack[-1], v0808);
    nil = C_nil;
    if (exception_pending()) goto v0734;
    env = stack[-5];
    v0643 = v0808;
    goto v0664;

v0664:
    v0808 = stack[-4];
    v0808 = cons(v0643, v0808);
    nil = C_nil;
    if (exception_pending()) goto v0734;
    env = stack[-5];
    stack[-4] = v0808;
    v0808 = stack[-3];
    v0808 = qcdr(v0808);
    stack[-3] = v0808;
    goto v0726;

v0665:
    v0808 = stack[-3];
    v0643 = qcar(v0808);
    v0808 = stack[-2];
    fn = elt(env, 7); // partdft
    v0808 = (*qfn2(fn))(qenv(fn), v0643, v0808);
    nil = C_nil;
    if (exception_pending()) goto v0734;
    env = stack[-5];
    v0643 = v0808;
    goto v0664;

v0783:
    v0808 = qvalue(elt(env, 1)); // t
    goto v0805;
// error exit handlers
v0734:
    popv(6);
    return nil;
}



// Code for new_edge

static LispObject CC_new_edge(LispObject env,
                         LispObject v0704, LispObject v0028)
{
    LispObject nil = C_nil;
    LispObject v0740, v0741;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for new_edge");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0028,v0704);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0704,v0028);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0028;
    stack[-1] = v0704;
// end of prologue
    v0740 = stack[-1];
    v0741 = qcar(v0740);
    v0740 = stack[0];
    v0740 = qcar(v0740);
    fn = elt(env, 3); // mk_edge_name
    stack[-2] = (*qfn2(fn))(qenv(fn), v0741, v0740);
    nil = C_nil;
    if (exception_pending()) goto v0660;
    env = stack[-3];
    v0740 = stack[-1];
    v0741 = qcar(v0740);
    v0740 = stack[0];
    v0740 = qcar(v0740);
    v0741 = cons(v0741, v0740);
    nil = C_nil;
    if (exception_pending()) goto v0660;
    env = stack[-3];
    v0740 = qvalue(elt(env, 1)); // nil
    v0740 = list3(stack[-2], v0741, v0740);
    nil = C_nil;
    if (exception_pending()) goto v0660;
    env = stack[-3];
    stack[0] = v0740;
    v0741 = stack[0];
    v0740 = qvalue(elt(env, 2)); // new_edge_list
    v0740 = cons(v0741, v0740);
    nil = C_nil;
    if (exception_pending()) goto v0660;
    env = stack[-3];
    qvalue(elt(env, 2)) = v0740; // new_edge_list
    { LispObject res = stack[0]; popv(4); return onevalue(res); }
// error exit handlers
v0660:
    popv(4);
    return nil;
}



setup_type const u57_setup[] =
{
    {"comcom3",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_comcom3},
    {"lexorder",                CC_lexorder,    too_many_1,    wrong_no_1},
    {"quotfail",                too_few_2,      CC_quotfail,   wrong_no_2},
    {"lto_hmember",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_lto_hmember},
    {"evalleq",                 too_few_2,      CC_evalleq,    wrong_no_2},
    {"taysimpsq*",              CC_taysimpsqH,  too_many_1,    wrong_no_1},
    {"pasf_exprng-gball",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_pasf_exprngKgball},
    {"aex_lc",                  too_few_2,      CC_aex_lc,     wrong_no_2},
    {"rnfloor*",                CC_rnfloorH,    too_many_1,    wrong_no_1},
    {"codfac",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_codfac},
    {"qsimpcomb_standard_qexp_part_sf",too_few_2,CC_qsimpcomb_standard_qexp_part_sf,wrong_no_2},
    {"rm_neg_pow",              CC_rm_neg_pow,  too_many_1,    wrong_no_1},
    {"mkuniquewedge1",          CC_mkuniquewedge1,too_many_1,  wrong_no_1},
    {"rand_functionp",          CC_rand_functionp,too_many_1,  wrong_no_1},
    {":dmexpt",                 too_few_2,      CC_Tdmexpt,    wrong_no_2},
    {"partdff",                 too_few_2,      CC_partdff,    wrong_no_2},
    {"new_edge",                too_few_2,      CC_new_edge,   wrong_no_2},
    {NULL, (one_args *)"u57", (two_args *)"11840 2675529 4084844", 0}
};

// end of generated code
