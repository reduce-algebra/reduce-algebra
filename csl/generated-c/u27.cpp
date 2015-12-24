
// $destdir/u27.c        Machine generated C code

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



// Code for n_nary

static LispObject CC_n_nary(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0013, v0014;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for n_nary");
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
    v0013 = stack[-1];
    v0014 = qcar(v0013);
    v0013 = elt(env, 1); // e
    if (v0014 == v0013) goto v0015;
    v0013 = qvalue(elt(env, 3)); // nil
    goto v0016;

v0016:
    if (v0013 == nil) goto v0017;
    v0013 = stack[-1];
    v0014 = qcdr(v0013);
    v0013 = elt(env, 4); // exp
    fn = elt(env, 10); // unary
    v0013 = (*qfn2(fn))(qenv(fn), v0014, v0013);
    nil = C_nil;
    if (exception_pending()) goto v0018;
    goto v0019;

v0019:
    v0013 = nil;
    { popv(3); return onevalue(v0013); }

v0017:
    v0013 = elt(env, 5); // "<apply>"
    fn = elt(env, 11); // printout
    v0013 = (*qfn1(fn))(qenv(fn), v0013);
    nil = C_nil;
    if (exception_pending()) goto v0018;
    env = stack[-2];
    v0013 = elt(env, 6); // "<"
    v0013 = Lprinc(nil, v0013);
    nil = C_nil;
    if (exception_pending()) goto v0018;
    env = stack[-2];
    v0013 = stack[0];
    v0013 = Lprinc(nil, v0013);
    nil = C_nil;
    if (exception_pending()) goto v0018;
    env = stack[-2];
    v0013 = elt(env, 7); // "/>"
    v0013 = Lprinc(nil, v0013);
    nil = C_nil;
    if (exception_pending()) goto v0018;
    env = stack[-2];
    v0014 = qvalue(elt(env, 8)); // indent
    v0013 = (LispObject)49; // 3
    v0013 = plus2(v0014, v0013);
    nil = C_nil;
    if (exception_pending()) goto v0018;
    env = stack[-2];
    qvalue(elt(env, 8)) = v0013; // indent
    v0013 = stack[-1];
    fn = elt(env, 12); // multi_elem
    v0013 = (*qfn1(fn))(qenv(fn), v0013);
    nil = C_nil;
    if (exception_pending()) goto v0018;
    env = stack[-2];
    v0014 = qvalue(elt(env, 8)); // indent
    v0013 = (LispObject)49; // 3
    v0013 = difference2(v0014, v0013);
    nil = C_nil;
    if (exception_pending()) goto v0018;
    env = stack[-2];
    qvalue(elt(env, 8)) = v0013; // indent
    v0013 = elt(env, 9); // "</apply>"
    fn = elt(env, 11); // printout
    v0013 = (*qfn1(fn))(qenv(fn), v0013);
    nil = C_nil;
    if (exception_pending()) goto v0018;
    goto v0019;

v0015:
    v0014 = stack[0];
    v0013 = elt(env, 2); // power
    v0013 = (v0014 == v0013 ? lisp_true : nil);
    goto v0016;
// error exit handlers
v0018:
    popv(3);
    return nil;
}



// Code for gcd2

static LispObject CC_gcd2(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0027, v0028, v0029;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gcd2");
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
    stack[0] = v0001;
    v0028 = v0000;
// end of prologue

v0008:
    v0027 = stack[0];
    v0027 = Cremainder(v0028, v0027);
    nil = C_nil;
    if (exception_pending()) goto v0007;
    env = stack[-1];
    v0029 = v0027;
    v0028 = v0029;
    v0027 = (LispObject)1; // 0
    if (v0028 == v0027) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    v0028 = stack[0];
    v0027 = v0029;
    stack[0] = v0027;
    goto v0008;
// error exit handlers
v0007:
    popv(2);
    return nil;
}



// Code for meq

static LispObject CC_meq(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0033, v0034, v0035;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for meq");
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
    v0033 = stack[-1];
    fn = elt(env, 2); // binding
    v0033 = (*qfn1(fn))(qenv(fn), v0033);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-2];
    v0034 = v0033;
    v0033 = v0034;
    if (v0033 == nil) goto v0009;
    v0033 = v0034;
    v0035 = elt(env, 1); // unbound
    if (v0033 == v0035) goto v0009;
    v0033 = v0034;
    v0034 = v0033;
    goto v0036;

v0036:
    v0033 = stack[0];
    v0033 = (equal(v0034, v0033) ? lisp_true : nil);
    { popv(3); return onevalue(v0033); }

v0009:
    v0033 = stack[-1];
    v0034 = v0033;
    goto v0036;
// error exit handlers
v0027:
    popv(3);
    return nil;
}



// Code for groebnormalform

static LispObject CC_groebnormalform(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0042, v0011, v0012, v0015;
    LispObject fn;
    LispObject v0041, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "groebnormalform");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0041 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for groebnormalform");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0042 = v0041;
    v0011 = v0001;
    v0012 = v0000;
// end of prologue
    v0015 = v0012;
    v0012 = v0011;
    v0011 = v0042;
    v0042 = qvalue(elt(env, 1)); // nil
    {
        fn = elt(env, 2); // groebnormalform0
        return (*qfnn(fn))(qenv(fn), 4, v0015, v0012, v0011, v0042);
    }
}



// Code for memqcar

static LispObject CC_memqcar(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0012, v0015, v0043;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for memqcar");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0015 = v0001;
    v0043 = v0000;
// end of prologue
    v0012 = v0043;
    if (!consp(v0012)) goto v0040;
    v0012 = v0043;
    v0012 = qcar(v0012);
    v0012 = Lmemq(nil, v0012, v0015);
    return onevalue(v0012);

v0040:
    v0012 = qvalue(elt(env, 1)); // nil
    return onevalue(v0012);
}



// Code for equalreval

static LispObject CC_equalreval(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0050, v0051, v0052;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for equalreval");
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
    v0050 = stack[-1];
    v0050 = qcdr(v0050);
    v0050 = qcar(v0050);
    fn = elt(env, 5); // reval
    v0050 = (*qfn1(fn))(qenv(fn), v0050);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    env = stack[-3];
    stack[-2] = v0050;
    v0050 = qvalue(elt(env, 1)); // !*evallhseqp
    if (!(v0050 == nil)) goto v0027;
    v0050 = stack[-1];
    v0050 = qcar(v0050);
    if (!consp(v0050)) goto v0034;
    v0050 = stack[-1];
    v0050 = qcar(v0050);
    v0051 = qcar(v0050);
    v0050 = elt(env, 2); // immediate
    v0050 = Lflagp(nil, v0051, v0050);
    env = stack[-3];
    goto v0040;

v0040:
    if (!(v0050 == nil)) goto v0027;
    v0052 = elt(env, 4); // equal
    v0050 = stack[-1];
    v0051 = qcar(v0050);
    v0050 = stack[-2];
    popv(4);
    return list3(v0052, v0051, v0050);

v0027:
    stack[0] = elt(env, 4); // equal
    v0050 = stack[-1];
    v0050 = qcar(v0050);
    fn = elt(env, 5); // reval
    v0051 = (*qfn1(fn))(qenv(fn), v0050);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    v0050 = stack[-2];
    {
        LispObject v0053 = stack[0];
        popv(4);
        return list3(v0053, v0051, v0050);
    }

v0034:
    v0050 = qvalue(elt(env, 3)); // nil
    goto v0040;
// error exit handlers
v0003:
    popv(4);
    return nil;
}



// Code for can_be_proved

static LispObject CC_can_be_proved(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0054, v0030;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for can_be_proved");
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

v0032:
    v0054 = stack[-1];
    if (v0054 == nil) goto v0036;
    v0054 = stack[-1];
    v0030 = qcar(v0054);
    v0054 = stack[0];
    fn = elt(env, 3); // can_be_p
    v0054 = (*qfn2(fn))(qenv(fn), v0030, v0054);
    nil = C_nil;
    if (exception_pending()) goto v0034;
    env = stack[-2];
    if (v0054 == nil) goto v0055;
    v0054 = stack[-1];
    v0054 = qcdr(v0054);
    stack[-1] = v0054;
    goto v0032;

v0055:
    v0054 = qvalue(elt(env, 2)); // nil
    { popv(3); return onevalue(v0054); }

v0036:
    v0054 = qvalue(elt(env, 1)); // t
    { popv(3); return onevalue(v0054); }
// error exit handlers
v0034:
    popv(3);
    return nil;
}



// Code for log_assignment_list

static LispObject CC_log_assignment_list(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0054, v0030;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for log_assignment_list");
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

v0032:
    v0054 = stack[0];
    if (!consp(v0054)) goto v0036;
    v0030 = stack[-1];
    v0054 = stack[0];
    v0054 = qcar(v0054);
    fn = elt(env, 3); // log_assignment
    v0054 = (*qfn2(fn))(qenv(fn), v0030, v0054);
    nil = C_nil;
    if (exception_pending()) goto v0034;
    env = stack[-2];
    if (v0054 == nil) goto v0021;
    v0054 = qvalue(elt(env, 2)); // t
    { popv(3); return onevalue(v0054); }

v0021:
    v0054 = stack[0];
    v0054 = qcdr(v0054);
    stack[0] = v0054;
    goto v0032;

v0036:
    v0054 = qvalue(elt(env, 1)); // nil
    { popv(3); return onevalue(v0054); }
// error exit handlers
v0034:
    popv(3);
    return nil;
}



// Code for insert

static LispObject CC_insert(LispObject env,
                         LispObject v0001, LispObject v0041)
{
    LispObject nil = C_nil;
    LispObject v0044, v0045;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for insert");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0041,v0001);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0001,v0041);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    v0044 = v0041;
    stack[-1] = v0001;
// end of prologue
    stack[-2] = qvalue(elt(env, 1)); // gg!*
    qvalue(elt(env, 1)) = nil; // gg!*
    qvalue(elt(env, 1)) = v0044; // gg!*
    stack[0] = nil;
    goto v0024;

v0024:
    v0044 = qvalue(elt(env, 1)); // gg!*
    if (v0044 == nil) goto v0060;
    v0044 = stack[-1];
    v0045 = qcdr(v0044);
    v0044 = qvalue(elt(env, 1)); // gg!*
    v0044 = qcar(v0044);
    v0044 = qcdr(v0044);
    fn = elt(env, 3); // dless
    v0044 = (*qfn2(fn))(qenv(fn), v0045, v0044);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-3];
    if (v0044 == nil) goto v0060;
    v0044 = qvalue(elt(env, 1)); // gg!*
    v0045 = qcar(v0044);
    v0044 = stack[0];
    v0044 = cons(v0045, v0044);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-3];
    stack[0] = v0044;
    v0044 = qvalue(elt(env, 1)); // gg!*
    v0044 = qcdr(v0044);
    qvalue(elt(env, 1)) = v0044; // gg!*
    goto v0024;

v0060:
    v0044 = stack[0];
    stack[0] = Lnreverse(nil, v0044);
    env = stack[-3];
    v0045 = stack[-1];
    v0044 = qvalue(elt(env, 1)); // gg!*
    v0044 = cons(v0045, v0044);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-3];
    v0044 = Lappend(nil, stack[0], v0044);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-3];
    qvalue(elt(env, 1)) = stack[-2]; // gg!*
    { popv(4); return onevalue(v0044); }
// error exit handlers
v0061:
    env = stack[-3];
    qvalue(elt(env, 1)) = stack[-2]; // gg!*
    popv(4);
    return nil;
}



// Code for bndtst

static LispObject CC_bndtst(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0031, v0023;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for bndtst");
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
    fn = elt(env, 2); // abs!:
    v0023 = (*qfn1(fn))(qenv(fn), v0031);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[0];
    v0031 = qvalue(elt(env, 1)); // tentothetenth!*!*
    {
        popv(1);
        fn = elt(env, 3); // greaterp!:
        return (*qfn2(fn))(qenv(fn), v0023, v0031);
    }
// error exit handlers
v0024:
    popv(1);
    return nil;
}



// Code for gcd!-in!-vector

static LispObject CC_gcdKinKvector(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0113, v0114, v0115, v0116, v0117, v0118;
    LispObject fn;
    LispObject v0022, v0041, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "gcd-in-vector");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0041 = va_arg(aa, LispObject);
    v0022 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gcd-in-vector");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0022,v0041,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0001,v0041,v0022);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0022;
    stack[-1] = v0041;
    stack[-2] = v0001;
    stack[-3] = v0000;
// end of prologue
    v0114 = stack[-2];
    v0113 = (LispObject)1; // 0
    if (v0114 == v0113) goto v0038;
    v0114 = stack[0];
    v0113 = (LispObject)1; // 0
    v0113 = (v0114 == v0113 ? lisp_true : nil);
    goto v0037;

v0037:
    if (v0113 == nil) goto v0119;
    v0115 = stack[-3];
    v0114 = (LispObject)1; // 0
    v0113 = (LispObject)17; // 1
    *(LispObject *)((char *)v0115 + (CELL-TAG_VECTOR) + ((int32_t)v0114/(16/CELL))) = v0113;
    v0113 = (LispObject)1; // 0
    { popv(5); return onevalue(v0113); }

v0119:
    v0114 = stack[-2];
    v0113 = (LispObject)1; // 0
    if (((int32_t)(v0114)) < ((int32_t)(v0113))) goto v0120;
    v0114 = stack[0];
    v0113 = (LispObject)1; // 0
    if (!(((int32_t)(v0114)) < ((int32_t)(v0113)))) goto v0002;

v0120:
    v0113 = elt(env, 2); // "GCD with zero not allowed"
    fn = elt(env, 4); // errorf
    v0113 = (*qfn1(fn))(qenv(fn), v0113);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-4];
    goto v0002;

v0002:
    v0116 = stack[-3];
    v0115 = stack[-2];
    v0114 = stack[-1];
    v0113 = stack[0];
    fn = elt(env, 5); // remainder!-in!-vector
    v0113 = (*qfnn(fn))(qenv(fn), 4, v0116, v0115, v0114, v0113);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-4];
    stack[-2] = v0113;
    v0114 = stack[-2];
    v0113 = (LispObject)1; // 0
    if (v0114 == v0113) goto v0122;
    v0114 = stack[-2];
    v0113 = (LispObject)-15; // -1
    if (v0114 == v0113) goto v0123;
    v0116 = stack[-1];
    v0115 = stack[0];
    v0114 = stack[-3];
    v0113 = stack[-2];
    fn = elt(env, 5); // remainder!-in!-vector
    v0113 = (*qfnn(fn))(qenv(fn), 4, v0116, v0115, v0114, v0113);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-4];
    stack[0] = v0113;
    v0114 = stack[0];
    v0113 = (LispObject)1; // 0
    if (v0114 == v0113) goto v0124;
    v0114 = stack[0];
    v0113 = (LispObject)-15; // -1
    if (!(v0114 == v0113)) goto v0002;
    v0114 = stack[-3];
    v0113 = stack[-2];
    v0113 = *(LispObject *)((char *)v0114 + (CELL-TAG_VECTOR) + ((int32_t)v0113/(16/CELL)));
    v0113 = Lmodular_reciprocal(nil, v0113);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-4];
    v0118 = v0113;
    v0114 = v0118;
    v0113 = (LispObject)17; // 1
    if (v0114 == v0113) { LispObject res = stack[-2]; popv(5); return onevalue(res); }
    v0113 = (LispObject)1; // 0
    v0117 = v0113;
    goto v0125;

v0125:
    v0114 = stack[-2];
    v0113 = v0117;
    v0113 = (LispObject)(int32_t)((int32_t)v0114 - (int32_t)v0113 + TAG_FIXNUM);
    v0113 = ((intptr_t)(v0113) < 0 ? lisp_true : nil);
    if (!(v0113 == nil)) { LispObject res = stack[-2]; popv(5); return onevalue(res); }
    v0116 = stack[-3];
    v0115 = v0117;
    v0114 = stack[-3];
    v0113 = v0117;
    v0114 = *(LispObject *)((char *)v0114 + (CELL-TAG_VECTOR) + ((int32_t)v0113/(16/CELL)));
    v0113 = v0118;
    v0113 = Lmodular_times(nil, v0114, v0113);
    env = stack[-4];
    *(LispObject *)((char *)v0116 + (CELL-TAG_VECTOR) + ((int32_t)v0115/(16/CELL))) = v0113;
    v0113 = v0117;
    v0113 = (LispObject)((int32_t)(v0113) + 0x10);
    v0117 = v0113;
    goto v0125;

v0124:
    v0115 = stack[-3];
    v0114 = (LispObject)1; // 0
    v0113 = (LispObject)17; // 1
    *(LispObject *)((char *)v0115 + (CELL-TAG_VECTOR) + ((int32_t)v0114/(16/CELL))) = v0113;
    v0113 = (LispObject)1; // 0
    { popv(5); return onevalue(v0113); }

v0123:
    v0114 = stack[-1];
    v0113 = stack[0];
    v0113 = *(LispObject *)((char *)v0114 + (CELL-TAG_VECTOR) + ((int32_t)v0113/(16/CELL)));
    v0113 = Lmodular_reciprocal(nil, v0113);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-4];
    v0118 = v0113;
    v0113 = (LispObject)1; // 0
    v0117 = v0113;
    goto v0126;

v0126:
    v0114 = stack[0];
    v0113 = v0117;
    v0113 = (LispObject)(int32_t)((int32_t)v0114 - (int32_t)v0113 + TAG_FIXNUM);
    v0113 = ((intptr_t)(v0113) < 0 ? lisp_true : nil);
    if (!(v0113 == nil)) { LispObject res = stack[0]; popv(5); return onevalue(res); }
    v0116 = stack[-3];
    v0115 = v0117;
    v0114 = stack[-1];
    v0113 = v0117;
    v0114 = *(LispObject *)((char *)v0114 + (CELL-TAG_VECTOR) + ((int32_t)v0113/(16/CELL)));
    v0113 = v0118;
    v0113 = Lmodular_times(nil, v0114, v0113);
    env = stack[-4];
    *(LispObject *)((char *)v0116 + (CELL-TAG_VECTOR) + ((int32_t)v0115/(16/CELL))) = v0113;
    v0113 = v0117;
    v0113 = (LispObject)((int32_t)(v0113) + 0x10);
    v0117 = v0113;
    goto v0126;

v0122:
    v0115 = stack[-3];
    v0114 = (LispObject)1; // 0
    v0113 = (LispObject)17; // 1
    *(LispObject *)((char *)v0115 + (CELL-TAG_VECTOR) + ((int32_t)v0114/(16/CELL))) = v0113;
    v0113 = (LispObject)1; // 0
    { popv(5); return onevalue(v0113); }

v0038:
    v0113 = qvalue(elt(env, 1)); // t
    goto v0037;
// error exit handlers
v0121:
    popv(5);
    return nil;
}



// Code for procstat1

static LispObject CC_procstat1(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0160, v0161, v0162;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for procstat1");
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
    stack[-4] = nil;
    stack[0] = nil;
    stack[-3] = nil;
    stack[-2] = nil;
    v0160 = qvalue(elt(env, 1)); // erfg!*
    stack[-6] = v0160;
    v0160 = qvalue(elt(env, 2)); // fname!*
    if (v0160 == nil) goto v0021;
    v0160 = qvalue(elt(env, 3)); // t
    stack[-6] = v0160;
    goto v0163;

v0163:
    v0161 = elt(env, 21); // (symerr (quote procedure) t)
    v0160 = qvalue(elt(env, 9)); // nil
    fn = elt(env, 22); // errorset!*
    v0160 = (*qfn2(fn))(qenv(fn), v0161, v0160);
    nil = C_nil;
    if (exception_pending()) goto v0164;
    env = stack[-7];
    goto v0165;

v0165:
    v0161 = qvalue(elt(env, 17)); // eof!*
    v0160 = (LispObject)1; // 0
    v0160 = (LispObject)greaterp2(v0161, v0160);
    nil = C_nil;
    if (exception_pending()) goto v0164;
    v0160 = v0160 ? lisp_true : nil;
    env = stack[-7];
    if (v0160 == nil) goto v0166;
    v0160 = elt(env, 18); // !*semicol!*
    qvalue(elt(env, 4)) = v0160; // cursym!*
    v0160 = qvalue(elt(env, 9)); // nil
    qvalue(elt(env, 19)) = v0160; // curescaped!*
    goto v0167;

v0167:
    v0160 = qvalue(elt(env, 2)); // fname!*
    v0161 = ncons(v0160);
    nil = C_nil;
    if (exception_pending()) goto v0164;
    env = stack[-7];
    v0160 = elt(env, 16); // fnc
    v0160 = Lremflag(nil, v0161, v0160);
    env = stack[-7];
    v0160 = qvalue(elt(env, 9)); // nil
    qvalue(elt(env, 2)) = v0160; // fname!*
    v0160 = qvalue(elt(env, 1)); // erfg!*
    if (v0160 == nil) { LispObject res = stack[-2]; popv(8); return onevalue(res); }
    v0160 = qvalue(elt(env, 9)); // nil
    stack[-2] = v0160;
    v0160 = stack[-6];
    if (!(v0160 == nil)) { LispObject res = stack[-2]; popv(8); return onevalue(res); }
    v0160 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0164;
    { LispObject res = stack[-2]; popv(8); return onevalue(res); }

v0166:
    v0161 = elt(env, 20); // (xread t)
    v0160 = qvalue(elt(env, 9)); // nil
    fn = elt(env, 22); // errorset!*
    v0160 = (*qfn2(fn))(qenv(fn), v0161, v0160);
    nil = C_nil;
    if (exception_pending()) goto v0164;
    env = stack[-7];
    stack[-2] = v0160;
    v0160 = stack[-2];
    fn = elt(env, 23); // errorp
    v0160 = (*qfn1(fn))(qenv(fn), v0160);
    nil = C_nil;
    if (exception_pending()) goto v0164;
    env = stack[-7];
    if (!(v0160 == nil)) goto v0168;
    v0160 = stack[-2];
    v0160 = qcar(v0160);
    stack[-2] = v0160;
    goto v0168;

v0168:
    v0160 = qvalue(elt(env, 1)); // erfg!*
    if (!(v0160 == nil)) goto v0167;
    stack[-1] = elt(env, 5); // procedure
    v0160 = qvalue(elt(env, 7)); // !*reduce4
    if (v0160 == nil) goto v0169;
    v0160 = qvalue(elt(env, 2)); // fname!*
    stack[0] = v0160;
    goto v0170;

v0170:
    v0162 = stack[-4];
    v0161 = stack[-3];
    v0160 = stack[-2];
    v0160 = list3(v0162, v0161, v0160);
    nil = C_nil;
    if (exception_pending()) goto v0164;
    env = stack[-7];
    v0160 = list3star(stack[-1], stack[0], stack[-5], v0160);
    nil = C_nil;
    if (exception_pending()) goto v0164;
    env = stack[-7];
    stack[-2] = v0160;
    goto v0167;

v0169:
    v0160 = stack[0];
    v0160 = qcar(v0160);
    stack[0] = v0160;
    goto v0170;

v0021:
    v0161 = qvalue(elt(env, 4)); // cursym!*
    v0160 = elt(env, 5); // procedure
    if (v0161 == v0160) goto v0043;
    v0160 = qvalue(elt(env, 4)); // cursym!*
    stack[-4] = v0160;
    fn = elt(env, 24); // scan
    v0160 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0164;
    env = stack[-7];
    goto v0007;

v0007:
    v0161 = qvalue(elt(env, 4)); // cursym!*
    v0160 = elt(env, 5); // procedure
    if (!(v0161 == v0160)) goto v0163;
    v0160 = qvalue(elt(env, 7)); // !*reduce4
    if (v0160 == nil) goto v0171;
    fn = elt(env, 24); // scan
    v0160 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0164;
    env = stack[-7];
    qvalue(elt(env, 2)) = v0160; // fname!*
    v0160 = qvalue(elt(env, 2)); // fname!*
    if (symbolp(v0160)) goto v0090;
    v0161 = qvalue(elt(env, 2)); // fname!*
    v0160 = elt(env, 13); // "procedure name"
    fn = elt(env, 25); // typerr
    v0160 = (*qfn2(fn))(qenv(fn), v0161, v0160);
    nil = C_nil;
    if (exception_pending()) goto v0164;
    env = stack[-7];
    goto v0165;

v0090:
    fn = elt(env, 24); // scan
    v0160 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0164;
    env = stack[-7];
    stack[-1] = elt(env, 14); // read_param_list
    v0160 = stack[-5];
    v0160 = Lmkquote(nil, v0160);
    nil = C_nil;
    if (exception_pending()) goto v0164;
    env = stack[-7];
    v0161 = list2(stack[-1], v0160);
    nil = C_nil;
    if (exception_pending()) goto v0164;
    env = stack[-7];
    v0160 = qvalue(elt(env, 9)); // nil
    fn = elt(env, 22); // errorset!*
    v0160 = (*qfn2(fn))(qenv(fn), v0161, v0160);
    nil = C_nil;
    if (exception_pending()) goto v0164;
    env = stack[-7];
    stack[-3] = v0160;
    v0160 = stack[-3];
    fn = elt(env, 23); // errorp
    v0160 = (*qfn1(fn))(qenv(fn), v0160);
    nil = C_nil;
    if (exception_pending()) goto v0164;
    env = stack[-7];
    if (!(v0160 == nil)) goto v0165;
    v0160 = stack[-3];
    v0160 = qcar(v0160);
    stack[-3] = v0160;
    v0161 = qvalue(elt(env, 4)); // cursym!*
    v0160 = elt(env, 15); // !*colon!*
    if (!(v0161 == v0160)) goto v0031;
    fn = elt(env, 26); // read_type
    v0160 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0164;
    env = stack[-7];
    stack[-5] = v0160;
    goto v0031;

v0031:
    v0160 = qvalue(elt(env, 2)); // fname!*
    if (!(symbolp(v0160))) goto v0165;
    v0160 = qvalue(elt(env, 2)); // fname!*
    fn = elt(env, 27); // getd
    v0160 = (*qfn1(fn))(qenv(fn), v0160);
    nil = C_nil;
    if (exception_pending()) goto v0164;
    env = stack[-7];
    if (!(v0160 == nil)) goto v0165;
    v0160 = qvalue(elt(env, 2)); // fname!*
    v0161 = ncons(v0160);
    nil = C_nil;
    if (exception_pending()) goto v0164;
    env = stack[-7];
    v0160 = elt(env, 16); // fnc
    v0160 = Lflag(nil, v0161, v0160);
    nil = C_nil;
    if (exception_pending()) goto v0164;
    env = stack[-7];
    goto v0165;

v0171:
    v0161 = elt(env, 8); // (xread (quote proc))
    v0160 = qvalue(elt(env, 9)); // nil
    fn = elt(env, 22); // errorset!*
    v0160 = (*qfn2(fn))(qenv(fn), v0161, v0160);
    nil = C_nil;
    if (exception_pending()) goto v0164;
    env = stack[-7];
    stack[0] = v0160;
    v0160 = stack[0];
    fn = elt(env, 23); // errorp
    v0160 = (*qfn1(fn))(qenv(fn), v0160);
    nil = C_nil;
    if (exception_pending()) goto v0164;
    env = stack[-7];
    if (!(v0160 == nil)) goto v0165;
    v0160 = stack[0];
    v0160 = qcar(v0160);
    stack[0] = v0160;
    if (!(!consp(v0160))) goto v0045;
    v0160 = stack[0];
    v0160 = ncons(v0160);
    nil = C_nil;
    if (exception_pending()) goto v0164;
    env = stack[-7];
    stack[0] = v0160;
    goto v0045;

v0045:
    v0160 = stack[0];
    v0160 = qcar(v0160);
    qvalue(elt(env, 2)) = v0160; // fname!*
    v0160 = qvalue(elt(env, 2)); // fname!*
    if (!(symbolp(v0160))) goto v0018;
    v0160 = qvalue(elt(env, 2)); // fname!*
    if (v0160 == nil) goto v0172;
    v0161 = qvalue(elt(env, 2)); // fname!*
    v0160 = lisp_true;
    v0160 = (v0161 == v0160 ? lisp_true : nil);
    goto v0173;

v0173:
    if (v0160 == nil) goto v0174;
    v0160 = qvalue(elt(env, 2)); // fname!*
    fn = elt(env, 28); // rsverr
    v0160 = (*qfn1(fn))(qenv(fn), v0160);
    nil = C_nil;
    if (exception_pending()) goto v0164;
    env = stack[-7];
    goto v0165;

v0174:
    v0160 = qvalue(elt(env, 2)); // fname!*
    fn = elt(env, 29); // gettype
    v0160 = (*qfn1(fn))(qenv(fn), v0160);
    nil = C_nil;
    if (exception_pending()) goto v0164;
    env = stack[-7];
    stack[-2] = v0160;
    if (v0160 == nil) goto v0018;
    v0161 = stack[-2];
    v0160 = elt(env, 10); // (procedure operator)
    v0160 = Lmemq(nil, v0161, v0160);
    if (!(v0160 == nil)) goto v0018;
    v0161 = stack[-2];
    v0160 = qvalue(elt(env, 2)); // fname!*
    v0161 = list2(v0161, v0160);
    nil = C_nil;
    if (exception_pending()) goto v0164;
    env = stack[-7];
    v0160 = elt(env, 11); // "procedure"
    fn = elt(env, 25); // typerr
    v0160 = (*qfn2(fn))(qenv(fn), v0161, v0160);
    nil = C_nil;
    if (exception_pending()) goto v0164;
    env = stack[-7];
    goto v0165;

v0018:
    v0160 = stack[0];
    v0160 = qcdr(v0160);
    stack[-3] = v0160;
    v0160 = stack[-3];
    fn = elt(env, 30); // idlistp
    v0160 = (*qfn1(fn))(qenv(fn), v0160);
    nil = C_nil;
    if (exception_pending()) goto v0164;
    env = stack[-7];
    if (v0160 == nil) goto v0175;
    v0160 = stack[0];
    v0161 = qcar(v0160);
    v0160 = stack[-3];
    v0160 = cons(v0161, v0160);
    nil = C_nil;
    if (exception_pending()) goto v0164;
    env = stack[-7];
    stack[0] = v0160;
    goto v0031;

v0175:
    v0161 = stack[-3];
    v0160 = elt(env, 12); // "invalid as parameter list"
    v0160 = list2(v0161, v0160);
    nil = C_nil;
    if (exception_pending()) goto v0164;
    env = stack[-7];
    fn = elt(env, 31); // lprie
    v0160 = (*qfn1(fn))(qenv(fn), v0160);
    nil = C_nil;
    if (exception_pending()) goto v0164;
    env = stack[-7];
    goto v0031;

v0172:
    v0160 = qvalue(elt(env, 3)); // t
    goto v0173;

v0043:
    v0160 = elt(env, 6); // expr
    stack[-4] = v0160;
    goto v0007;
// error exit handlers
v0164:
    popv(8);
    return nil;
}



// Code for opmtchrevop

static LispObject CC_opmtchrevop(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0029, v0006;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for opmtchrevop");
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
    v0029 = qvalue(elt(env, 1)); // !*val
    if (v0029 == nil) goto v0036;
    v0006 = elt(env, 3); // cons
    v0029 = stack[0];
    v0029 = Lsmemq(nil, v0006, v0029);
    nil = C_nil;
    if (exception_pending()) goto v0112;
    env = stack[-2];
    goto v0129;

v0129:
    if (v0029 == nil) goto v0054;
    v0029 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); // opmtch
        return (*qfn1(fn))(qenv(fn), v0029);
    }

v0054:
    v0029 = stack[0];
    stack[-1] = qcar(v0029);
    v0029 = stack[0];
    v0029 = qcdr(v0029);
    fn = elt(env, 5); // revlis
    v0029 = (*qfn1(fn))(qenv(fn), v0029);
    nil = C_nil;
    if (exception_pending()) goto v0112;
    env = stack[-2];
    v0029 = cons(stack[-1], v0029);
    nil = C_nil;
    if (exception_pending()) goto v0112;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 4); // opmtch
        return (*qfn1(fn))(qenv(fn), v0029);
    }

v0036:
    v0029 = qvalue(elt(env, 2)); // t
    goto v0129;
// error exit handlers
v0112:
    popv(3);
    return nil;
}



// Code for ofsf_optsubstat

static LispObject CC_ofsf_optsubstat(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0059, v0044;
    LispObject fn;
    LispObject v0041, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "ofsf_optsubstat");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0041 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_optsubstat");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0041,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0041);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    v0059 = v0041;
    stack[-2] = v0001;
    stack[0] = v0000;
// end of prologue
    v0044 = stack[0];
    v0044 = qcdr(v0044);
    v0044 = qcar(v0044);
    fn = elt(env, 2); // ofsf_optsplitterm
    v0059 = (*qfn2(fn))(qenv(fn), v0044, v0059);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-4];
    stack[-3] = v0059;
    if (v0059 == nil) { LispObject res = stack[0]; popv(5); return onevalue(res); }
    v0059 = stack[0];
    stack[-1] = qcar(v0059);
    v0059 = stack[-3];
    v0044 = qcar(v0059);
    v0059 = stack[-2];
    v0059 = qcar(v0059);
    fn = elt(env, 3); // multf
    stack[0] = (*qfn2(fn))(qenv(fn), v0044, v0059);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-4];
    v0059 = stack[-3];
    v0044 = qcdr(v0059);
    v0059 = stack[-2];
    v0059 = qcdr(v0059);
    fn = elt(env, 3); // multf
    v0059 = (*qfn2(fn))(qenv(fn), v0044, v0059);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-4];
    fn = elt(env, 4); // addf
    v0059 = (*qfn2(fn))(qenv(fn), stack[0], v0059);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-4];
    v0044 = qvalue(elt(env, 1)); // nil
    {
        LispObject v0177 = stack[-1];
        popv(5);
        return list3(v0177, v0059, v0044);
    }
// error exit handlers
v0061:
    popv(5);
    return nil;
}



// Code for lambdavar

static LispObject CC_lambdavar(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0008;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lambdavar");
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
    v0008 = v0000;
// end of prologue
    v0008 = qcdr(v0008);
    v0008 = qcdr(v0008);
    v0008 = Lreverse(nil, v0008);
    errexit();
    v0008 = qcdr(v0008);
    return onevalue(v0008);
}



// Code for rowdel

static LispObject CC_rowdel(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0108, v0109, v0106;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rowdel");
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
    v0108 = stack[0];
    fn = elt(env, 4); // delhisto
    v0108 = (*qfn1(fn))(qenv(fn), v0108);
    nil = C_nil;
    if (exception_pending()) goto v0181;
    env = stack[-2];
    stack[-1] = qvalue(elt(env, 1)); // codmat
    v0109 = qvalue(elt(env, 2)); // maxvar
    v0108 = stack[0];
    v0108 = plus2(v0109, v0108);
    nil = C_nil;
    if (exception_pending()) goto v0181;
    env = stack[-2];
    v0106 = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v0108/(16/CELL)));
    v0109 = (LispObject)1; // 0
    v0108 = qvalue(elt(env, 3)); // nil
    *(LispObject *)((char *)v0106 + (CELL-TAG_VECTOR) + ((int32_t)v0109/(16/CELL))) = v0108;
    stack[-1] = qvalue(elt(env, 1)); // codmat
    v0109 = qvalue(elt(env, 2)); // maxvar
    v0108 = stack[0];
    v0108 = plus2(v0109, v0108);
    nil = C_nil;
    if (exception_pending()) goto v0181;
    env = stack[-2];
    v0109 = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v0108/(16/CELL)));
    v0108 = (LispObject)65; // 4
    v0108 = *(LispObject *)((char *)v0109 + (CELL-TAG_VECTOR) + ((int32_t)v0108/(16/CELL)));
    stack[0] = v0108;
    goto v0033;

v0033:
    v0108 = stack[0];
    if (v0108 == nil) goto v0182;
    v0108 = stack[0];
    v0108 = qcar(v0108);
    v0109 = v0108;
    v0109 = qcar(v0109);
    v0108 = qcdr(v0108);
    v0108 = qcar(v0108);
    fn = elt(env, 5); // downwght
    v0108 = (*qfn2(fn))(qenv(fn), v0109, v0108);
    nil = C_nil;
    if (exception_pending()) goto v0181;
    env = stack[-2];
    v0108 = stack[0];
    v0108 = qcdr(v0108);
    stack[0] = v0108;
    goto v0033;

v0182:
    v0108 = qvalue(elt(env, 3)); // nil
    { popv(3); return onevalue(v0108); }
// error exit handlers
v0181:
    popv(3);
    return nil;
}



// Code for bfplusn

static LispObject CC_bfplusn(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0009, v0010, v0054;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for bfplusn");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0010 = v0001;
    v0054 = v0000;
// end of prologue
    v0009 = v0054;
    if (!consp(v0009)) goto v0008;
    v0009 = v0054;
    {
        fn = elt(env, 1); // plus!:
        return (*qfn2(fn))(qenv(fn), v0009, v0010);
    }

v0008:
    v0009 = v0054;
    return plus2(v0009, v0010);
}



// Code for fortranname

static LispObject CC_fortranname(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0061, v0177;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for fortranname");
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
    v0061 = stack[0];
    v0061 = Lstringp(nil, v0061);
    env = stack[-1];
    if (v0061 == nil) goto v0039;
    v0061 = stack[0];
    {
        popv(2);
        fn = elt(env, 9); // stringtoatom
        return (*qfn1(fn))(qenv(fn), v0061);
    }

v0039:
    v0177 = stack[0];
    v0061 = qvalue(elt(env, 1)); // !*notfortranfuns!*
    v0061 = Lmemq(nil, v0177, v0061);
    if (v0061 == nil) goto v0024;
    v0061 = qvalue(elt(env, 2)); // !*stdout!*
    v0061 = qcdr(v0061);
    v0061 = Lwrs(nil, v0061);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    env = stack[-1];
    v0061 = elt(env, 3); // "*** WARNING: "
    v0061 = Lprinc(nil, v0061);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    env = stack[-1];
    v0061 = stack[0];
    v0061 = Lprin(nil, v0061);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    env = stack[-1];
    v0061 = elt(env, 4); // " is not an intrinsic Fortran function"
    fn = elt(env, 10); // prin2t
    v0061 = (*qfn1(fn))(qenv(fn), v0061);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    env = stack[-1];
    goto v0024;

v0024:
    v0061 = qvalue(elt(env, 6)); // !*double
    if (v0061 == nil) goto v0004;
    v0177 = stack[0];
    v0061 = elt(env, 7); // !*doublename!*
    v0061 = get(v0177, v0061);
    if (v0061 == nil) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    else { popv(2); return onevalue(v0061); }

v0004:
    v0177 = stack[0];
    v0061 = elt(env, 8); // !*fortranname!*
    v0061 = get(v0177, v0061);
    if (v0061 == nil) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    else { popv(2); return onevalue(v0061); }
// error exit handlers
v0003:
    popv(2);
    return nil;
}



// Code for edge_new_parent

static LispObject CC_edge_new_parent(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0007, v0017, v0112;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for edge_new_parent");
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
    v0017 = v0000;
// end of prologue

v0183:
    v0007 = v0017;
    if (v0007 == nil) goto v0056;
    v0007 = v0017;
    v0112 = qcar(v0007);
    v0007 = qvalue(elt(env, 2)); // new_edge_list
    v0007 = Lassoc(nil, v0112, v0007);
    v0112 = v0007;
    v0007 = v0112;
    if (v0007 == nil) goto v0025;
    stack[0] = v0112;
    v0007 = v0017;
    v0007 = qcdr(v0007);
    v0007 = CC_edge_new_parent(env, v0007);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    {
        LispObject v0060 = stack[0];
        popv(1);
        return cons(v0060, v0007);
    }

v0025:
    v0007 = v0017;
    v0007 = qcdr(v0007);
    v0017 = v0007;
    goto v0183;

v0056:
    v0007 = qvalue(elt(env, 1)); // nil
    { popv(1); return onevalue(v0007); }
// error exit handlers
v0046:
    popv(1);
    return nil;
}



// Code for mksetq

static LispObject CC_mksetq(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0005, v0059, v0044, v0045;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mksetq");
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
    v0059 = v0001;
    v0044 = v0000;
// end of prologue
    v0005 = v0044;
    if (!consp(v0005)) goto v0008;
    v0005 = v0044;
    v0045 = qcar(v0005);
    v0005 = elt(env, 2); // setfn
    v0005 = get(v0045, v0005);
    env = stack[0];
    v0045 = v0005;
    if (v0005 == nil) goto v0180;
    v0005 = v0045;
        popv(1);
        return Lapply2(nil, 3, v0005, v0044, v0059);

v0180:
    v0059 = v0044;
    v0005 = elt(env, 3); // "assignment argument"
    fn = elt(env, 4); // typerr
    v0005 = (*qfn2(fn))(qenv(fn), v0059, v0005);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    v0005 = nil;
    { popv(1); return onevalue(v0005); }

v0008:
    v0005 = elt(env, 1); // setq
    popv(1);
    return list3(v0005, v0044, v0059);
// error exit handlers
v0050:
    popv(1);
    return nil;
}



// Code for ifstat

static LispObject CC_ifstat(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0104, v0122;
    LispObject fn;
    argcheck(nargs, 0, "ifstat");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ifstat");
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
    goto v0032;

v0032:
    v0104 = qvalue(elt(env, 1)); // t
    fn = elt(env, 8); // xread
    v0104 = (*qfn1(fn))(qenv(fn), v0104);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-2];
    stack[0] = v0104;
    v0122 = qvalue(elt(env, 2)); // cursym!*
    v0104 = elt(env, 3); // then
    if (v0122 == v0104) goto v0028;
    v0122 = elt(env, 4); // if
    v0104 = qvalue(elt(env, 1)); // t
    fn = elt(env, 9); // symerr
    v0104 = (*qfn2(fn))(qenv(fn), v0122, v0104);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-2];
    goto v0028;

v0028:
    v0104 = qvalue(elt(env, 1)); // t
    fn = elt(env, 8); // xread
    v0104 = (*qfn1(fn))(qenv(fn), v0104);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-2];
    v0104 = list2(stack[0], v0104);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-2];
    fn = elt(env, 10); // aconc!*
    v0104 = (*qfn2(fn))(qenv(fn), stack[-1], v0104);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-2];
    stack[-1] = v0104;
    v0122 = qvalue(elt(env, 2)); // cursym!*
    v0104 = elt(env, 5); // else
    if (!(v0122 == v0104)) goto v0157;
    fn = elt(env, 11); // scan
    v0122 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-2];
    v0104 = elt(env, 4); // if
    if (v0122 == v0104) goto v0032;
    stack[0] = qvalue(elt(env, 1)); // t
    v0104 = qvalue(elt(env, 1)); // t
    fn = elt(env, 12); // xread1
    v0104 = (*qfn1(fn))(qenv(fn), v0104);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-2];
    v0104 = list2(stack[0], v0104);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-2];
    fn = elt(env, 10); // aconc!*
    v0104 = (*qfn2(fn))(qenv(fn), stack[-1], v0104);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-2];
    stack[-1] = v0104;
    goto v0157;

v0157:
    v0122 = elt(env, 7); // cond
    v0104 = stack[-1];
    popv(3);
    return cons(v0122, v0104);
// error exit handlers
v0186:
    popv(3);
    return nil;
}



// Code for co_new

static LispObject CC_co_new(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0022;
    argcheck(nargs, 0, "co_new");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for co_new");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// end of prologue
    v0022 = qvalue(elt(env, 1)); // nil
    return ncons(v0022);
}



// Code for homogp

static LispObject CC_homogp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0105, v0104;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for homogp");
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
    v0105 = stack[0];
    if (!consp(v0105)) goto v0023;
    v0105 = stack[0];
    v0105 = qcar(v0105);
    v0105 = (consp(v0105) ? nil : lisp_true);
    goto v0031;

v0031:
    if (v0105 == nil) goto v0043;
    v0105 = qvalue(elt(env, 1)); // t
    goto v0129;

v0129:
    if (v0105 == nil) goto v0032;
    v0105 = qvalue(elt(env, 2)); // nil
    { popv(3); return onevalue(v0105); }

v0032:
    v0105 = stack[0];
    v0105 = qcdr(v0105);
    v0105 = qcar(v0105);
    v0105 = qcdr(v0105);
    if (v0105 == nil) goto v0029;
    v0105 = stack[0];
    v0105 = qcdr(v0105);
    v0105 = qcar(v0105);
    fn = elt(env, 3); // lastnondomain
    v0105 = (*qfn1(fn))(qenv(fn), v0105);
    nil = C_nil;
    if (exception_pending()) goto v0187;
    env = stack[-2];
    v0105 = qcdr(v0105);
    v0104 = v0105;
    v0105 = v0104;
    if (!consp(v0105)) goto v0110;
    v0105 = v0104;
    v0105 = qcar(v0105);
    v0105 = (consp(v0105) ? nil : lisp_true);
    goto v0111;

v0111:
    if (v0105 == nil) goto v0002;
    v0105 = qvalue(elt(env, 2)); // nil
    { popv(3); return onevalue(v0105); }

v0002:
    v0105 = stack[0];
    v0105 = qcdr(v0105);
    v0105 = qcar(v0105);
    v0105 = qcar(v0105);
    v0105 = qcar(v0105);
    fn = elt(env, 4); // listsum
    stack[-1] = (*qfn1(fn))(qenv(fn), v0105);
    nil = C_nil;
    if (exception_pending()) goto v0187;
    env = stack[-2];
    v0105 = stack[0];
    v0105 = qcdr(v0105);
    v0105 = qcar(v0105);
    fn = elt(env, 3); // lastnondomain
    v0105 = (*qfn1(fn))(qenv(fn), v0105);
    nil = C_nil;
    if (exception_pending()) goto v0187;
    env = stack[-2];
    v0105 = qcar(v0105);
    v0105 = qcar(v0105);
    fn = elt(env, 4); // listsum
    v0105 = (*qfn1(fn))(qenv(fn), v0105);
    nil = C_nil;
    if (exception_pending()) goto v0187;
    env = stack[-2];
    if (equal(stack[-1], v0105)) goto v0061;
    v0105 = qvalue(elt(env, 2)); // nil
    { popv(3); return onevalue(v0105); }

v0061:
    v0105 = qvalue(elt(env, 1)); // t
    { popv(3); return onevalue(v0105); }

v0110:
    v0105 = qvalue(elt(env, 1)); // t
    goto v0111;

v0029:
    v0105 = qvalue(elt(env, 2)); // nil
    { popv(3); return onevalue(v0105); }

v0043:
    v0105 = stack[0];
    v0105 = qcar(v0105);
    if (!consp(v0105)) goto v0009;
    v0105 = stack[0];
    v0105 = qcar(v0105);
    v0105 = qcar(v0105);
    v0105 = (consp(v0105) ? nil : lisp_true);
    goto v0129;

v0009:
    v0105 = qvalue(elt(env, 1)); // t
    goto v0129;

v0023:
    v0105 = qvalue(elt(env, 1)); // t
    goto v0031;
// error exit handlers
v0187:
    popv(3);
    return nil;
}



// Code for aex_mvar

static LispObject CC_aex_mvar(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0031;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for aex_mvar");
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
    fn = elt(env, 2); // aex_ex
    v0031 = (*qfn1(fn))(qenv(fn), v0031);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[0];
    v0031 = qcar(v0031);
    {
        popv(1);
        fn = elt(env, 3); // sfto_mvarx
        return (*qfn1(fn))(qenv(fn), v0031);
    }
// error exit handlers
v0023:
    popv(1);
    return nil;
}



// Code for dip2vdp

static LispObject CC_dip2vdp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0177, v0002;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dip2vdp");
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
    v0002 = v0000;
// end of prologue
    v0177 = qvalue(elt(env, 1)); // !*groebsubs
    if (v0177 == nil) goto v0008;
    v0177 = v0002;
    fn = elt(env, 4); // dipsubs2
    v0177 = (*qfn1(fn))(qenv(fn), v0177);
    nil = C_nil;
    if (exception_pending()) goto v0013;
    env = stack[-3];
    goto v0022;

v0022:
    v0002 = v0177;
    v0177 = v0002;
    if (v0177 == nil) goto v0011;
    stack[-2] = elt(env, 2); // vdp
    v0177 = v0002;
    stack[-1] = qcar(v0177);
    v0177 = v0002;
    v0177 = qcdr(v0177);
    stack[0] = qcar(v0177);
    v0177 = qvalue(elt(env, 3)); // nil
    v0177 = list2(v0002, v0177);
    nil = C_nil;
    if (exception_pending()) goto v0013;
    {
        LispObject v0014 = stack[-2];
        LispObject v0179 = stack[-1];
        LispObject v0188 = stack[0];
        popv(4);
        return list3star(v0014, v0179, v0188, v0177);
    }

v0011:
    stack[-2] = elt(env, 2); // vdp
    stack[-1] = qvalue(elt(env, 3)); // nil
    v0177 = (LispObject)1; // 0
    fn = elt(env, 5); // a2bc
    stack[0] = (*qfn1(fn))(qenv(fn), v0177);
    nil = C_nil;
    if (exception_pending()) goto v0013;
    env = stack[-3];
    v0002 = qvalue(elt(env, 3)); // nil
    v0177 = qvalue(elt(env, 3)); // nil
    v0177 = list2(v0002, v0177);
    nil = C_nil;
    if (exception_pending()) goto v0013;
    {
        LispObject v0018 = stack[-2];
        LispObject v0108 = stack[-1];
        LispObject v0109 = stack[0];
        popv(4);
        return list3star(v0018, v0108, v0109, v0177);
    }

v0008:
    v0177 = v0002;
    goto v0022;
// error exit handlers
v0013:
    popv(4);
    return nil;
}



// Code for assert_stat1

static LispObject CC_assert_stat1(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0192, v0100;
    LispObject fn;
    argcheck(nargs, 0, "assert_stat1");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for assert_stat1");
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
    fn = elt(env, 8); // scan
    v0100 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-1];
    v0192 = elt(env, 1); // !*lpar!*
    if (v0100 == v0192) goto v0054;
    v0100 = elt(env, 2); // "expecting '(' in assert but found"
    v0192 = qvalue(elt(env, 3)); // cursym!*
    v0192 = list2(v0100, v0192);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-1];
    fn = elt(env, 9); // rederr
    v0192 = (*qfn1(fn))(qenv(fn), v0192);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-1];
    goto v0054;

v0054:
    fn = elt(env, 8); // scan
    v0100 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-1];
    v0192 = elt(env, 4); // !*rpar!*
    if (!(v0100 == v0192)) goto v0007;
    v0192 = qvalue(elt(env, 5)); // nil
    { popv(2); return onevalue(v0192); }

v0007:
    v0100 = qvalue(elt(env, 3)); // cursym!*
    v0192 = stack[0];
    v0192 = cons(v0100, v0192);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-1];
    stack[0] = v0192;
    fn = elt(env, 8); // scan
    v0192 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-1];
    v0100 = qvalue(elt(env, 3)); // cursym!*
    v0192 = elt(env, 6); // !*comma!*
    if (v0100 == v0192) goto v0013;
    v0100 = qvalue(elt(env, 3)); // cursym!*
    v0192 = elt(env, 4); // !*rpar!*
    v0192 = Lneq(nil, v0100, v0192);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-1];
    goto v0171;

v0171:
    if (v0192 == nil) goto v0194;
    v0100 = elt(env, 7); // "expecting ',' or ')' in assert but found"
    v0192 = qvalue(elt(env, 3)); // cursym!*
    v0192 = list2(v0100, v0192);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-1];
    fn = elt(env, 9); // rederr
    v0192 = (*qfn1(fn))(qenv(fn), v0192);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-1];
    goto v0194;

v0194:
    v0100 = qvalue(elt(env, 3)); // cursym!*
    v0192 = elt(env, 6); // !*comma!*
    if (!(v0100 == v0192)) goto v0103;
    fn = elt(env, 8); // scan
    v0192 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-1];
    goto v0103;

v0103:
    v0100 = qvalue(elt(env, 3)); // cursym!*
    v0192 = elt(env, 4); // !*rpar!*
    if (!(v0100 == v0192)) goto v0007;
    v0192 = stack[0];
        popv(2);
        return Lnreverse(nil, v0192);

v0013:
    v0192 = qvalue(elt(env, 5)); // nil
    goto v0171;
// error exit handlers
v0193:
    popv(2);
    return nil;
}



// Code for nf

static LispObject CC_nf(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0137, v0135, v0136;
    LispObject fn;
    LispObject v0022, v0041, v0001;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "nf");
    va_start(aa, nargs);
    v0001 = va_arg(aa, LispObject);
    v0041 = va_arg(aa, LispObject);
    v0022 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for nf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0022,v0041,v0001);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0001,v0041,v0022);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    stack[-9] = v0022;
    v0137 = v0041;
    v0135 = v0001;
// end of prologue
    stack[-10] = qvalue(elt(env, 1)); // gg!*
    qvalue(elt(env, 1)) = nil; // gg!*
    qvalue(elt(env, 1)) = v0137; // gg!*
    v0137 = qvalue(elt(env, 1)); // gg!*
    if (v0137 == nil) goto v0031;
    stack[-3] = nil;
    v0137 = (LispObject)1; // 0
    stack[0] = v0137;
    v0137 = v0135;
    stack[-8] = v0137;
    v0137 = qvalue(elt(env, 1)); // gg!*
    stack[-2] = v0137;
    goto v0049;

v0049:
    v0137 = stack[-8];
    if (v0137 == nil) goto v0209;
    v0137 = stack[-8];
    v0137 = qcar(v0137);
    v0137 = qcar(v0137);
    stack[-7] = v0137;
    goto v0060;

v0060:
    v0137 = stack[-2];
    if (v0137 == nil) goto v0061;
    v0135 = stack[-7];
    v0137 = stack[-2];
    v0137 = qcar(v0137);
    v0137 = qcdr(v0137);
    fn = elt(env, 13); // dless
    v0137 = (*qfn2(fn))(qenv(fn), v0135, v0137);
    nil = C_nil;
    if (exception_pending()) goto v0210;
    env = stack[-11];
    goto v0180;

v0180:
    if (v0137 == nil) goto v0046;
    v0137 = stack[-2];
    v0137 = qcdr(v0137);
    stack[-2] = v0137;
    goto v0060;

v0046:
    v0137 = stack[-2];
    if (v0137 == nil) goto v0209;
    v0137 = stack[-2];
    stack[-1] = v0137;
    goto v0107;

v0107:
    v0137 = stack[-1];
    if (v0137 == nil) goto v0106;
    v0137 = stack[-1];
    v0137 = qcar(v0137);
    v0135 = qcdr(v0137);
    v0137 = stack[-7];
    fn = elt(env, 14); // dd
    stack[-4] = (*qfn2(fn))(qenv(fn), v0135, v0137);
    nil = C_nil;
    if (exception_pending()) goto v0210;
    env = stack[-11];
    v0135 = stack[-9];
    v0137 = (LispObject)33; // 2
    v0137 = plus2(v0135, v0137);
    nil = C_nil;
    if (exception_pending()) goto v0210;
    env = stack[-11];
    if (!(((int32_t)(stack[-4])) < ((int32_t)(v0137)))) goto v0106;
    v0137 = stack[-1];
    v0137 = qcdr(v0137);
    stack[-1] = v0137;
    goto v0107;

v0106:
    v0137 = stack[-1];
    if (v0137 == nil) goto v0211;
    v0135 = qvalue(elt(env, 4)); // gv!*
    v0137 = stack[-1];
    v0137 = qcar(v0137);
    v0137 = qcar(v0137);
    v0137 = *(LispObject *)((char *)v0135 + (CELL-TAG_VECTOR) + ((int32_t)v0137/(16/CELL)));
    stack[-6] = v0137;
    v0137 = stack[-8];
    v0137 = qcar(v0137);
    v0135 = qcdr(v0137);
    v0137 = stack[-6];
    v0137 = qcar(v0137);
    v0137 = qcdr(v0137);
    fn = elt(env, 15); // gcdf!*
    v0137 = (*qfn2(fn))(qenv(fn), v0135, v0137);
    nil = C_nil;
    if (exception_pending()) goto v0210;
    env = stack[-11];
    stack[-4] = v0137;
    v0137 = stack[-8];
    v0137 = qcar(v0137);
    v0135 = qcdr(v0137);
    v0137 = stack[-4];
    fn = elt(env, 16); // cdiv
    v0137 = (*qfn2(fn))(qenv(fn), v0135, v0137);
    nil = C_nil;
    if (exception_pending()) goto v0210;
    env = stack[-11];
    stack[-5] = v0137;
    v0137 = stack[-6];
    v0137 = qcar(v0137);
    v0135 = qcdr(v0137);
    v0137 = stack[-4];
    fn = elt(env, 16); // cdiv
    v0137 = (*qfn2(fn))(qenv(fn), v0135, v0137);
    nil = C_nil;
    if (exception_pending()) goto v0210;
    env = stack[-11];
    stack[-4] = v0137;
    v0135 = stack[-8];
    v0137 = stack[-4];
    fn = elt(env, 17); // pcmult
    v0137 = (*qfn2(fn))(qenv(fn), v0135, v0137);
    nil = C_nil;
    if (exception_pending()) goto v0210;
    env = stack[-11];
    stack[-8] = v0137;
    v0135 = stack[-3];
    v0137 = stack[-4];
    fn = elt(env, 17); // pcmult
    v0137 = (*qfn2(fn))(qenv(fn), v0135, v0137);
    nil = C_nil;
    if (exception_pending()) goto v0210;
    env = stack[-11];
    stack[-3] = v0137;
    v0135 = stack[-6];
    v0137 = stack[-5];
    fn = elt(env, 17); // pcmult
    v0137 = (*qfn2(fn))(qenv(fn), v0135, v0137);
    nil = C_nil;
    if (exception_pending()) goto v0210;
    env = stack[-11];
    stack[-6] = v0137;
    v0137 = stack[-6];
    stack[-4] = qcdr(v0137);
    v0135 = stack[-7];
    v0137 = stack[-1];
    v0137 = qcar(v0137);
    v0137 = qcdr(v0137);
    fn = elt(env, 18); // dquot
    v0137 = (*qfn2(fn))(qenv(fn), v0135, v0137);
    nil = C_nil;
    if (exception_pending()) goto v0210;
    env = stack[-11];
    fn = elt(env, 19); // pdmult
    v0137 = (*qfn2(fn))(qenv(fn), stack[-4], v0137);
    nil = C_nil;
    if (exception_pending()) goto v0210;
    env = stack[-11];
    stack[-4] = v0137;
    v0137 = qvalue(elt(env, 5)); // tred
    if (v0137 == nil) goto v0143;
    v0137 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0210;
    env = stack[-11];
    v0137 = elt(env, 6); // "r e d u c t i o n :  "
    v0137 = Lprinc(nil, v0137);
    nil = C_nil;
    if (exception_pending()) goto v0210;
    env = stack[-11];
    v0137 = stack[-7];
    v0137 = Lprinc(nil, v0137);
    nil = C_nil;
    if (exception_pending()) goto v0210;
    env = stack[-11];
    v0137 = elt(env, 7); // "/"
    v0137 = Lprinc(nil, v0137);
    nil = C_nil;
    if (exception_pending()) goto v0210;
    env = stack[-11];
    v0137 = stack[-1];
    v0137 = qcar(v0137);
    v0137 = qcdr(v0137);
    v0137 = Lprinc(nil, v0137);
    nil = C_nil;
    if (exception_pending()) goto v0210;
    env = stack[-11];
    v0137 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0210;
    env = stack[-11];
    goto v0143;

v0143:
    v0137 = qvalue(elt(env, 8)); // stars
    if (v0137 == nil) goto v0071;
    v0137 = elt(env, 9); // "*"
    v0137 = Lprinc(nil, v0137);
    nil = C_nil;
    if (exception_pending()) goto v0210;
    env = stack[-11];
    goto v0071;

v0071:
    v0137 = stack[0];
    v0137 = (LispObject)((int32_t)(v0137) + 0x10);
    stack[0] = v0137;
    v0137 = stack[-8];
    v0135 = qcdr(v0137);
    v0137 = stack[-4];
    fn = elt(env, 20); // pdif
    v0137 = (*qfn2(fn))(qenv(fn), v0135, v0137);
    nil = C_nil;
    if (exception_pending()) goto v0210;
    env = stack[-11];
    stack[-8] = v0137;
    goto v0049;

v0211:
    v0137 = qvalue(elt(env, 3)); // redtails
    if (v0137 == nil) goto v0209;
    v0136 = stack[-7];
    v0137 = stack[-8];
    v0137 = qcar(v0137);
    v0135 = qcdr(v0137);
    v0137 = stack[-3];
    v0137 = acons(v0136, v0135, v0137);
    nil = C_nil;
    if (exception_pending()) goto v0210;
    env = stack[-11];
    stack[-3] = v0137;
    v0137 = stack[-8];
    v0137 = qcdr(v0137);
    stack[-8] = v0137;
    goto v0049;

v0209:
    v0135 = qvalue(elt(env, 10)); // reductions!*
    v0137 = stack[0];
    v0137 = (LispObject)(int32_t)((int32_t)v0135 + (int32_t)v0137 - TAG_FIXNUM);
    qvalue(elt(env, 10)) = v0137; // reductions!*
    v0137 = qvalue(elt(env, 11)); // nforms!*
    v0137 = (LispObject)((int32_t)(v0137) + 0x10);
    qvalue(elt(env, 11)) = v0137; // nforms!*
    v0137 = stack[-3];
    v0135 = Lnreverse(nil, v0137);
    env = stack[-11];
    v0137 = stack[-8];
    v0137 = Lappend(nil, v0135, v0137);
    nil = C_nil;
    if (exception_pending()) goto v0210;
    env = stack[-11];
    fn = elt(env, 21); // gcdout
    v0137 = (*qfn1(fn))(qenv(fn), v0137);
    nil = C_nil;
    if (exception_pending()) goto v0210;
    env = stack[-11];
    stack[-4] = v0137;
    v0137 = stack[-4];
    if (!(v0137 == nil)) goto v0170;
    v0137 = qvalue(elt(env, 12)); // zeros!*
    v0137 = (LispObject)((int32_t)(v0137) + 0x10);
    qvalue(elt(env, 12)) = v0137; // zeros!*
    goto v0170;

v0170:
    v0137 = stack[-4];
    goto v0129;

v0129:
    qvalue(elt(env, 1)) = stack[-10]; // gg!*
    { popv(12); return onevalue(v0137); }

v0061:
    v0137 = qvalue(elt(env, 2)); // nil
    goto v0180;

v0031:
    v0137 = v0135;
    goto v0129;
// error exit handlers
v0210:
    env = stack[-11];
    qvalue(elt(env, 1)) = stack[-10]; // gg!*
    popv(12);
    return nil;
}



// Code for prepreform1

static LispObject CC_prepreform1(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0079, v0080;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for prepreform1");
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
    stack[-5] = v0001;
    stack[0] = v0000;
// end of prologue

v0183:
    v0079 = stack[0];
    if (!consp(v0079)) goto v0008;
    v0079 = stack[0];
    v0079 = qcar(v0079);
    if (!symbolp(v0079)) v0079 = nil;
    else { v0079 = qfastgets(v0079);
           if (v0079 != nil) { v0079 = elt(v0079, 8); // dname
#ifdef RECORD_GET
             if (v0079 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v0079 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v0079 == SPID_NOPROP) v0079 = nil; }}
#endif
    goto v0036;

v0036:
    if (!(v0079 == nil)) { LispObject res = stack[0]; popv(8); return onevalue(res); }
    stack[-6] = nil;
    v0079 = stack[-5];
    stack[-1] = v0079;
    goto v0054;

v0054:
    v0079 = stack[-6];
    if (v0079 == nil) goto v0025;
    v0079 = qvalue(elt(env, 2)); // nil
    goto v0026;

v0026:
    if (v0079 == nil) goto v0010;
    v0079 = stack[-1];
    v0080 = qcar(v0079);
    v0079 = stack[0];
    v0079 = qcdr(v0079);
    v0079 = Lsmemq(nil, v0080, v0079);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-7];
    if (v0079 == nil) goto v0005;
    v0079 = qvalue(elt(env, 1)); // t
    stack[-6] = v0079;
    goto v0054;

v0005:
    v0079 = stack[-1];
    v0079 = qcdr(v0079);
    stack[-1] = v0079;
    goto v0054;

v0010:
    v0079 = stack[-6];
    if (v0079 == nil) { LispObject res = stack[0]; popv(8); return onevalue(res); }
    v0079 = stack[0];
    v0080 = qcar(v0079);
    v0079 = elt(env, 3); // (plus difference minus times quotient)
    v0079 = Lmemq(nil, v0080, v0079);
    if (!(v0079 == nil)) goto v0178;
    v0079 = stack[0];
    v0079 = qcar(v0079);
    if (!symbolp(v0079)) v0079 = nil;
    else { v0079 = qfastgets(v0079);
           if (v0079 != nil) { v0079 = elt(v0079, 22); // simpfn
#ifdef RECORD_GET
             if (v0079 != SPID_NOPROP)
                record_get(elt(fastget_names, 22), 1);
             else record_get(elt(fastget_names, 22), 0),
                v0079 = nil; }
           else record_get(elt(fastget_names, 22), 0); }
#else
             if (v0079 == SPID_NOPROP) v0079 = nil; }}
#endif
    if (!(v0079 == nil)) goto v0122;

v0178:
    v0079 = qvalue(elt(env, 2)); // nil
    stack[-6] = v0079;
    goto v0122;

v0122:
    v0079 = stack[0];
    v0080 = qcar(v0079);
    v0079 = elt(env, 4); // !*sq
    if (v0080 == v0079) goto v0101;
    v0079 = stack[0];
    stack[-4] = qcar(v0079);
    v0079 = stack[0];
    v0079 = qcdr(v0079);
    stack[-3] = v0079;
    v0079 = stack[-3];
    if (v0079 == nil) goto v0206;
    v0079 = stack[-3];
    v0079 = qcar(v0079);
    v0080 = v0079;
    v0079 = stack[-6];
    if (v0079 == nil) goto v0218;
    v0079 = v0080;
    fn = elt(env, 5); // simp!*
    v0079 = (*qfn1(fn))(qenv(fn), v0079);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-7];
    fn = elt(env, 6); // sqhorner!*
    v0079 = (*qfn1(fn))(qenv(fn), v0079);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-7];
    fn = elt(env, 7); // prepsq!*
    v0079 = (*qfn1(fn))(qenv(fn), v0079);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-7];
    v0080 = v0079;
    goto v0219;

v0219:
    v0079 = stack[-5];
    v0079 = CC_prepreform1(env, v0080, v0079);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-7];
    v0079 = ncons(v0079);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-7];
    stack[-1] = v0079;
    stack[-2] = v0079;
    goto v0220;

v0220:
    v0079 = stack[-3];
    v0079 = qcdr(v0079);
    stack[-3] = v0079;
    v0079 = stack[-3];
    if (v0079 == nil) goto v0091;
    stack[0] = stack[-1];
    v0079 = stack[-3];
    v0079 = qcar(v0079);
    v0080 = v0079;
    v0079 = stack[-6];
    if (v0079 == nil) goto v0221;
    v0079 = v0080;
    fn = elt(env, 5); // simp!*
    v0079 = (*qfn1(fn))(qenv(fn), v0079);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-7];
    fn = elt(env, 6); // sqhorner!*
    v0079 = (*qfn1(fn))(qenv(fn), v0079);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-7];
    fn = elt(env, 7); // prepsq!*
    v0079 = (*qfn1(fn))(qenv(fn), v0079);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-7];
    v0080 = v0079;
    goto v0146;

v0146:
    v0079 = stack[-5];
    v0079 = CC_prepreform1(env, v0080, v0079);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-7];
    v0079 = ncons(v0079);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-7];
    v0079 = Lrplacd(nil, stack[0], v0079);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-7];
    v0079 = stack[-1];
    v0079 = qcdr(v0079);
    stack[-1] = v0079;
    goto v0220;

v0221:
    v0079 = v0080;
    v0080 = v0079;
    goto v0146;

v0091:
    v0079 = stack[-2];
    goto v0097;

v0097:
    {
        LispObject v0145 = stack[-4];
        popv(8);
        return cons(v0145, v0079);
    }

v0218:
    v0079 = v0080;
    v0080 = v0079;
    goto v0219;

v0206:
    v0079 = qvalue(elt(env, 2)); // nil
    goto v0097;

v0101:
    v0079 = stack[0];
    v0079 = qcdr(v0079);
    v0079 = qcar(v0079);
    fn = elt(env, 6); // sqhorner!*
    v0079 = (*qfn1(fn))(qenv(fn), v0079);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-7];
    fn = elt(env, 7); // prepsq!*
    v0080 = (*qfn1(fn))(qenv(fn), v0079);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-7];
    v0079 = stack[-5];
    stack[0] = v0080;
    stack[-5] = v0079;
    goto v0183;

v0025:
    v0079 = stack[-1];
    goto v0026;

v0008:
    v0079 = qvalue(elt(env, 1)); // t
    goto v0036;
// error exit handlers
v0144:
    popv(8);
    return nil;
}



// Code for mksp!*

static LispObject CC_mkspH(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0061, v0177;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mksp*");
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
    v0061 = stack[-1];
    if (v0061 == nil) goto v0023;
    v0061 = stack[-1];
    fn = elt(env, 2); // kernlp
    v0061 = (*qfn1(fn))(qenv(fn), v0061);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-3];
    goto v0031;

v0031:
    if (v0061 == nil) goto v0008;
    v0177 = stack[-1];
    v0061 = stack[0];
    {
        popv(4);
        fn = elt(env, 3); // exptf
        return (*qfn2(fn))(qenv(fn), v0177, v0061);
    }

v0008:
    v0061 = stack[-1];
    fn = elt(env, 4); // minusf
    v0061 = (*qfn1(fn))(qenv(fn), v0061);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-3];
    if (v0061 == nil) goto v0047;
    v0061 = qvalue(elt(env, 1)); // t
    stack[-2] = v0061;
    v0061 = stack[-1];
    fn = elt(env, 5); // negf
    v0061 = (*qfn1(fn))(qenv(fn), v0061);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-3];
    stack[-1] = v0061;
    goto v0047;

v0047:
    v0177 = stack[-1];
    v0061 = stack[0];
    fn = elt(env, 6); // mksp
    v0177 = (*qfn2(fn))(qenv(fn), v0177, v0061);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-3];
    v0061 = (LispObject)17; // 1
    v0061 = cons(v0177, v0061);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-3];
    v0061 = ncons(v0061);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-3];
    stack[-1] = v0061;
    v0061 = stack[-2];
    if (v0061 == nil) { LispObject res = stack[-1]; popv(4); return onevalue(res); }
    v0061 = stack[0];
    v0061 = Levenp(nil, v0061);
    env = stack[-3];
    if (!(v0061 == nil)) { LispObject res = stack[-1]; popv(4); return onevalue(res); }
    v0061 = stack[-1];
    {
        popv(4);
        fn = elt(env, 5); // negf
        return (*qfn1(fn))(qenv(fn), v0061);
    }

v0023:
    v0061 = qvalue(elt(env, 1)); // t
    goto v0031;
// error exit handlers
v0178:
    popv(4);
    return nil;
}



// Code for bc_2sq

static LispObject CC_bc_2sq(LispObject env,
                         LispObject v0000)
{
    LispObject v0022;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for bc_2sq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0022 = v0000;
// end of prologue
    return onevalue(v0022);
}



// Code for ombindir

static LispObject CC_ombindir(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0034;
    LispObject fn;
    argcheck(nargs, 0, "ombindir");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ombindir");
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
    fn = elt(env, 2); // lex
    v0034 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-3];
    fn = elt(env, 3); // omobj
    v0034 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-3];
    stack[-1] = v0034;
    fn = elt(env, 2); // lex
    v0034 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-3];
    fn = elt(env, 4); // variablesir
    v0034 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-3];
    fn = elt(env, 5); // tobvarir
    v0034 = (*qfn1(fn))(qenv(fn), v0034);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-3];
    stack[0] = v0034;
    fn = elt(env, 2); // lex
    v0034 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-3];
    fn = elt(env, 3); // omobj
    v0034 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-3];
    stack[-2] = v0034;
    fn = elt(env, 2); // lex
    v0034 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-3];
    v0034 = elt(env, 1); // (!/ o m b i n d)
    fn = elt(env, 6); // checktag
    v0034 = (*qfn1(fn))(qenv(fn), v0034);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-3];
    v0034 = stack[-2];
    v0034 = ncons(v0034);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-3];
    v0034 = Lappend(nil, stack[0], v0034);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    {
        LispObject v0028 = stack[-1];
        popv(4);
        return Lappend(nil, v0028, v0034);
    }
// error exit handlers
v0027:
    popv(4);
    return nil;
}



// Code for simpdf!*

static LispObject CC_simpdfH(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0009, v0010, v0054;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for simpdf*");
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
    v0009 = v0000;
// end of prologue
    fn = elt(env, 1); // simpdf
    v0009 = (*qfn1(fn))(qenv(fn), v0009);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-1];
    stack[0] = v0009;
    v0009 = stack[0];
    fn = elt(env, 2); // rootextractsq
    v0009 = (*qfn1(fn))(qenv(fn), v0009);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-1];
    v0054 = v0009;
    v0010 = v0054;
    v0009 = stack[0];
    if (equal(v0010, v0009)) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    v0009 = v0054;
    {
        popv(2);
        fn = elt(env, 3); // resimp
        return (*qfn1(fn))(qenv(fn), v0009);
    }
// error exit handlers
v0049:
    popv(2);
    return nil;
}



// Code for nextcomb

static LispObject CC_nextcomb(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0089, v0087;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for nextcomb");
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
    stack[0] = v0001;
    v0087 = v0000;
// end of prologue
    stack[-2] = qvalue(elt(env, 1)); // i
    qvalue(elt(env, 1)) = nil; // i
    v0089 = (LispObject)1; // 0
    qvalue(elt(env, 1)) = v0089; // i
    v0089 = v0087;
    v0089 = qcar(v0089);
    stack[-3] = v0089;
    v0089 = v0087;
    v0089 = qcdr(v0089);
    stack[-1] = v0089;
    v0087 = stack[0];
    v0089 = (LispObject)1; // 0
    if (v0087 == v0089) goto v0039;
    v0089 = stack[-3];
    v0087 = Llength(nil, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0224;
    env = stack[-4];
    v0089 = stack[0];
    v0087 = difference2(v0087, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0224;
    env = stack[-4];
    qvalue(elt(env, 1)) = v0087; // i
    v0089 = (LispObject)1; // 0
    v0089 = (LispObject)lessp2(v0087, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0224;
    v0089 = v0089 ? lisp_true : nil;
    env = stack[-4];
    if (v0089 == nil) goto v0119;
    v0089 = qvalue(elt(env, 2)); // nil
    v0089 = ncons(v0089);
    nil = C_nil;
    if (exception_pending()) goto v0224;
    env = stack[-4];
    goto v0036;

v0036:
    qvalue(elt(env, 1)) = stack[-2]; // i
    { popv(5); return onevalue(v0089); }

v0119:
    v0087 = qvalue(elt(env, 1)); // i
    v0089 = (LispObject)1; // 0
    if (v0087 == v0089) goto v0048;
    v0089 = stack[-1];
    if (v0089 == nil) goto v0190;
    v0089 = stack[0];
    v0089 = sub1(v0089);
    nil = C_nil;
    if (exception_pending()) goto v0224;
    env = stack[-4];
    v0089 = CC_nextcomb(env, stack[-1], v0089);
    nil = C_nil;
    if (exception_pending()) goto v0224;
    env = stack[-4];
    v0087 = stack[-3];
    stack[-1] = qcar(v0087);
    v0087 = v0089;
    stack[0] = qcar(v0087);
    v0087 = v0089;
    v0087 = qcdr(v0087);
    if (v0087 == nil) goto v0159;
    v0087 = stack[-3];
    v0089 = qcdr(v0089);
    v0089 = cons(v0087, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0224;
    env = stack[-4];
    goto v0108;

v0108:
    v0089 = acons(stack[-1], stack[0], v0089);
    nil = C_nil;
    if (exception_pending()) goto v0224;
    env = stack[-4];
    goto v0036;

v0159:
    v0089 = stack[-3];
    v0089 = qcdr(v0089);
    v0089 = ncons(v0089);
    nil = C_nil;
    if (exception_pending()) goto v0224;
    env = stack[-4];
    goto v0108;

v0190:
    v0089 = stack[-3];
    v0089 = qcdr(v0089);
    fn = elt(env, 3); // initcomb
    stack[-1] = (*qfn1(fn))(qenv(fn), v0089);
    nil = C_nil;
    if (exception_pending()) goto v0224;
    env = stack[-4];
    v0089 = stack[0];
    v0089 = sub1(v0089);
    nil = C_nil;
    if (exception_pending()) goto v0224;
    env = stack[-4];
    v0089 = CC_nextcomb(env, stack[-1], v0089);
    nil = C_nil;
    if (exception_pending()) goto v0224;
    env = stack[-4];
    v0087 = stack[-3];
    stack[-1] = qcar(v0087);
    v0087 = v0089;
    stack[0] = qcar(v0087);
    v0087 = v0089;
    v0087 = qcdr(v0087);
    if (v0087 == nil) goto v0219;
    v0087 = stack[-3];
    v0089 = qcdr(v0089);
    v0089 = cons(v0087, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0224;
    env = stack[-4];
    goto v0153;

v0153:
    v0089 = acons(stack[-1], stack[0], v0089);
    nil = C_nil;
    if (exception_pending()) goto v0224;
    env = stack[-4];
    goto v0036;

v0219:
    v0089 = stack[-3];
    v0089 = qcdr(v0089);
    v0089 = ncons(v0089);
    nil = C_nil;
    if (exception_pending()) goto v0224;
    env = stack[-4];
    goto v0153;

v0048:
    v0089 = stack[-3];
    v0089 = ncons(v0089);
    nil = C_nil;
    if (exception_pending()) goto v0224;
    env = stack[-4];
    goto v0036;

v0039:
    v0089 = qvalue(elt(env, 2)); // nil
    v0089 = ncons(v0089);
    nil = C_nil;
    if (exception_pending()) goto v0224;
    env = stack[-4];
    goto v0036;
// error exit handlers
v0224:
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[-2]; // i
    popv(5);
    return nil;
}



// Code for dip!-nc!-ev!-prod1

static LispObject CC_dipKncKevKprod1(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0027, v0028, v0029, v0006;
    LispObject fn;
    LispObject v0041, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "dip-nc-ev-prod1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0041 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dip-nc-ev-prod1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0041,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0041);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    v0028 = v0041;
    v0029 = v0001;
    v0006 = v0000;
// end of prologue
    v0027 = v0006;
    if (v0027 == nil) { popv(3); return onevalue(v0028); }
    v0027 = v0006;
    stack[-1] = qcar(v0027);
    stack[0] = v0029;
    v0027 = v0006;
    v0027 = qcdr(v0027);
    v0029 = (LispObject)((int32_t)(v0029) + 0x10);
    v0027 = CC_dipKncKevKprod1(env, 3, v0027, v0029, v0028);
    nil = C_nil;
    if (exception_pending()) goto v0112;
    env = stack[-2];
    {
        LispObject v0047 = stack[-1];
        LispObject v0046 = stack[0];
        popv(3);
        fn = elt(env, 1); // dip!-nc!-ev!-prod2
        return (*qfnn(fn))(qenv(fn), 3, v0047, v0046, v0027);
    }
// error exit handlers
v0112:
    popv(3);
    return nil;
}



// Code for vevstrictlydivides!?

static LispObject CC_vevstrictlydividesW(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0055, v0009, v0010, v0054;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vevstrictlydivides?");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0010 = v0001;
    v0054 = v0000;
// end of prologue
    v0009 = v0054;
    v0055 = v0010;
    if (equal(v0009, v0055)) goto v0043;
    v0055 = v0010;
    v0009 = v0054;
    {
        fn = elt(env, 2); // vevmtest!?
        return (*qfn2(fn))(qenv(fn), v0055, v0009);
    }

v0043:
    v0055 = qvalue(elt(env, 1)); // nil
    return onevalue(v0055);
}



// Code for pterpri

static LispObject CC_pterpri(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0061, v0177, v0002;
    LispObject fn;
    argcheck(nargs, 0, "pterpri");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pterpri");
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
    v0061 = qvalue(elt(env, 1)); // nil
    v0061 = Lwrs(nil, v0061);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[-4];
    stack[-3] = v0061;
    v0061 = qvalue(elt(env, 2)); // !*pprinbuf!*
    v0061 = Lnreverse(nil, v0061);
    env = stack[-4];
    stack[-2] = v0061;
    v0061 = qvalue(elt(env, 3)); // !*outchanl!*
    stack[-1] = v0061;
    goto v0023;

v0023:
    v0061 = stack[-1];
    if (v0061 == nil) goto v0031;
    v0061 = stack[-1];
    v0061 = qcar(v0061);
    v0061 = Lwrs(nil, v0061);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[-4];
    v0061 = stack[-2];
    stack[0] = v0061;
    goto v0054;

v0054:
    v0061 = stack[0];
    if (v0061 == nil) goto v0010;
    v0061 = stack[0];
    v0061 = qcar(v0061);
    v0002 = v0061;
    v0177 = qvalue(elt(env, 4)); // gentranlang!*
    v0061 = elt(env, 5); // fortran
    if (v0177 == v0061) goto v0017;
    v0061 = v0002;
    v0061 = Lprinc(nil, v0061);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[-4];
    goto v0007;

v0007:
    v0061 = stack[0];
    v0061 = qcdr(v0061);
    stack[0] = v0061;
    goto v0054;

v0017:
    v0061 = v0002;
    fn = elt(env, 7); // fprin2
    v0061 = (*qfn1(fn))(qenv(fn), v0061);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[-4];
    goto v0007;

v0010:
    v0061 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[-4];
    v0061 = stack[-1];
    v0061 = qcdr(v0061);
    stack[-1] = v0061;
    goto v0023;

v0031:
    v0061 = (LispObject)1; // 0
    qvalue(elt(env, 6)) = v0061; // !*posn!*
    v0061 = qvalue(elt(env, 1)); // nil
    qvalue(elt(env, 2)) = v0061; // !*pprinbuf!*
    v0061 = stack[-3];
    v0061 = Lwrs(nil, v0061);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    v0061 = nil;
    { popv(5); return onevalue(v0061); }
// error exit handlers
v0014:
    popv(5);
    return nil;
}



// Code for getphystypeor

static LispObject CC_getphystypeor(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0011;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for getphystypeor");
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

v0183:
    v0011 = stack[0];
    if (!consp(v0011)) goto v0039;
    v0011 = stack[0];
    v0011 = qcar(v0011);
    fn = elt(env, 2); // getphystype
    v0011 = (*qfn1(fn))(qenv(fn), v0011);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    env = stack[-1];
    if (!(v0011 == nil)) { popv(2); return onevalue(v0011); }
    v0011 = stack[0];
    v0011 = qcdr(v0011);
    stack[0] = v0011;
    goto v0183;

v0039:
    v0011 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0011); }
// error exit handlers
v0015:
    popv(2);
    return nil;
}



// Code for mk!-numr

static LispObject CC_mkKnumr(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0004, v0005, v0059;
    LispObject fn;
    LispObject v0041, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "mk-numr");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0041 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mk-numr");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0041,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0041);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0041;
    stack[-1] = v0001;
    stack[-2] = v0000;
// end of prologue
    stack[-3] = nil;
    goto v0023;

v0023:
    v0005 = stack[-1];
    v0004 = stack[0];
    if (equal(v0005, v0004)) goto v0016;
    v0005 = stack[-1];
    v0004 = (LispObject)1; // 0
    if (v0005 == v0004) goto v0033;
    v0059 = elt(env, 1); // difference
    v0005 = stack[-2];
    v0004 = stack[-1];
    v0004 = list3(v0059, v0005, v0004);
    nil = C_nil;
    if (exception_pending()) goto v0052;
    env = stack[-4];
    v0005 = v0004;
    goto v0009;

v0009:
    v0004 = stack[-3];
    v0004 = cons(v0005, v0004);
    nil = C_nil;
    if (exception_pending()) goto v0052;
    env = stack[-4];
    stack[-3] = v0004;
    v0004 = stack[-1];
    v0004 = add1(v0004);
    nil = C_nil;
    if (exception_pending()) goto v0052;
    env = stack[-4];
    stack[-1] = v0004;
    goto v0023;

v0033:
    v0004 = stack[-2];
    v0005 = v0004;
    goto v0009;

v0016:
    v0004 = stack[-3];
    {
        popv(5);
        fn = elt(env, 2); // nreverse
        return (*qfn1(fn))(qenv(fn), v0004);
    }
// error exit handlers
v0052:
    popv(5);
    return nil;
}



// Code for nzero

static LispObject CC_nzero(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0033, v0034;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for nzero");
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
    goto v0016;

v0016:
    v0034 = stack[0];
    v0033 = (LispObject)1; // 0
    if (v0034 == v0033) goto v0036;
    v0034 = (LispObject)1; // 0
    v0033 = stack[-1];
    v0033 = cons(v0034, v0033);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[-2];
    stack[-1] = v0033;
    v0033 = stack[0];
    v0033 = sub1(v0033);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[-2];
    stack[0] = v0033;
    goto v0016;

v0036:
    v0033 = stack[-1];
    {
        popv(3);
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(qenv(fn), v0033);
    }
// error exit handlers
v0025:
    popv(3);
    return nil;
}



// Code for general!-evaluate!-mod!-p

static LispObject CC_generalKevaluateKmodKp(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0214, v0212, v0226, v0220, v0154;
    LispObject fn;
    LispObject v0041, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "general-evaluate-mod-p");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0041 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for general-evaluate-mod-p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0041,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0041);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0041;
    stack[-1] = v0001;
    stack[-2] = v0000;
// end of prologue

v0019:
    v0214 = stack[-2];
    if (!consp(v0214)) goto v0024;
    v0214 = stack[-2];
    v0214 = qcar(v0214);
    v0214 = (consp(v0214) ? nil : lisp_true);
    goto v0023;

v0023:
    if (!(v0214 == nil)) { LispObject res = stack[-2]; popv(5); return onevalue(res); }
    v0212 = stack[0];
    v0214 = (LispObject)1; // 0
    if (v0212 == v0214) goto v0020;
    v0214 = stack[-1];
    if (v0214 == nil) goto v0035;
    v0214 = stack[-2];
    v0214 = qcar(v0214);
    v0214 = qcar(v0214);
    v0212 = qcar(v0214);
    v0214 = stack[-1];
    if (equal(v0212, v0214)) goto v0180;
    v0214 = stack[-2];
    v0214 = qcar(v0214);
    v0226 = qcdr(v0214);
    v0212 = stack[-1];
    v0214 = stack[0];
    stack[-3] = CC_generalKevaluateKmodKp(env, 3, v0226, v0212, v0214);
    nil = C_nil;
    if (exception_pending()) goto v0227;
    env = stack[-4];
    v0214 = stack[-2];
    v0226 = qcdr(v0214);
    v0212 = stack[-1];
    v0214 = stack[0];
    v0214 = CC_generalKevaluateKmodKp(env, 3, v0226, v0212, v0214);
    nil = C_nil;
    if (exception_pending()) goto v0227;
    v0212 = stack[-3];
    v0226 = v0212;
    if (v0226 == nil) { popv(5); return onevalue(v0214); }
    v0226 = stack[-2];
    v0226 = qcar(v0226);
    v0226 = qcar(v0226);
    popv(5);
    return acons(v0226, v0212, v0214);

v0180:
    v0214 = stack[-2];
    v0214 = qcar(v0214);
    v0154 = qcdr(v0214);
    v0214 = stack[-2];
    v0214 = qcar(v0214);
    v0214 = qcar(v0214);
    v0220 = qcdr(v0214);
    v0214 = stack[-2];
    v0226 = qcdr(v0214);
    v0212 = stack[0];
    v0214 = stack[-1];
    {
        popv(5);
        fn = elt(env, 4); // general!-horner!-rule!-mod!-p
        return (*qfnn(fn))(qenv(fn), 5, v0154, v0220, v0226, v0212, v0214);
    }

v0035:
    v0214 = elt(env, 3); // "Variable=NIL in GENERAL-EVALUATE-MOD-P"
    {
        popv(5);
        fn = elt(env, 5); // errorf
        return (*qfn1(fn))(qenv(fn), v0214);
    }

v0020:
    v0214 = qvalue(elt(env, 2)); // nil
    stack[0] = v0214;
    goto v0019;

v0024:
    v0214 = qvalue(elt(env, 1)); // t
    goto v0023;
// error exit handlers
v0227:
    popv(5);
    return nil;
}



// Code for string!-of!-list

static LispObject CC_stringKofKlist(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0108, v0109;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for string-of-list");
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
    v0109 = v0000;
// end of prologue
    v0108 = v0109;
    if (v0108 == nil) goto v0056;
    v0108 = v0109;
    stack[-4] = v0108;
    goto v0039;

v0039:
    v0108 = stack[-4];
    if (v0108 == nil) goto v0015;
    v0108 = stack[-4];
    v0108 = qcar(v0108);
    stack[0] = elt(env, 3); // !;
    v0108 = Lexplode(nil, v0108);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    env = stack[-5];
    v0108 = cons(stack[0], v0108);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    env = stack[-5];
    stack[-3] = v0108;
    v0108 = stack[-3];
    fn = elt(env, 4); // lastpair
    v0108 = (*qfn1(fn))(qenv(fn), v0108);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    env = stack[-5];
    stack[-2] = v0108;
    v0108 = stack[-4];
    v0108 = qcdr(v0108);
    stack[-4] = v0108;
    v0108 = stack[-2];
    if (!consp(v0108)) goto v0039;
    else goto v0040;

v0040:
    v0108 = stack[-4];
    if (v0108 == nil) goto v0176;
    stack[-1] = stack[-2];
    v0108 = stack[-4];
    v0108 = qcar(v0108);
    stack[0] = elt(env, 3); // !;
    v0108 = Lexplode(nil, v0108);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    env = stack[-5];
    v0108 = cons(stack[0], v0108);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    env = stack[-5];
    v0108 = Lrplacd(nil, stack[-1], v0108);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    env = stack[-5];
    v0108 = stack[-2];
    fn = elt(env, 4); // lastpair
    v0108 = (*qfn1(fn))(qenv(fn), v0108);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    env = stack[-5];
    stack[-2] = v0108;
    v0108 = stack[-4];
    v0108 = qcdr(v0108);
    stack[-4] = v0108;
    goto v0040;

v0176:
    v0108 = stack[-3];
    goto v0038;

v0038:
    v0108 = qcdr(v0108);
    {
        popv(6);
        fn = elt(env, 5); // list2string
        return (*qfn1(fn))(qenv(fn), v0108);
    }

v0015:
    v0108 = qvalue(elt(env, 2)); // nil
    goto v0038;

v0056:
    v0108 = elt(env, 1); // ""
    { popv(6); return onevalue(v0108); }
// error exit handlers
v0157:
    popv(6);
    return nil;
}



// Code for sfto_lessq

static LispObject CC_sfto_lessq(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0037, v0038;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sfto_lessq");
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
    v0037 = v0001;
    v0038 = v0000;
// end of prologue
    stack[0] = v0038;
    fn = elt(env, 1); // negsq
    v0037 = (*qfn1(fn))(qenv(fn), v0037);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-1];
    fn = elt(env, 2); // addsq
    v0037 = (*qfn2(fn))(qenv(fn), stack[0], v0037);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-1];
    v0037 = qcar(v0037);
    {
        popv(2);
        fn = elt(env, 3); // minusf
        return (*qfn1(fn))(qenv(fn), v0037);
    }
// error exit handlers
v0040:
    popv(2);
    return nil;
}



// Code for mkfil!*

static LispObject CC_mkfilH(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0112, v0047;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mkfil*");
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
    v0047 = nil;
    v0112 = stack[0];
    v0112 = Lstringp(nil, v0112);
    env = stack[-1];
    if (!(v0112 == nil)) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    v0112 = stack[0];
    if (symbolp(v0112)) goto v0024;
    v0047 = stack[0];
    v0112 = elt(env, 1); // "file name"
    {
        popv(2);
        fn = elt(env, 3); // typerr
        return (*qfn2(fn))(qenv(fn), v0047, v0112);
    }

v0024:
    v0112 = stack[0];
    if (!symbolp(v0112)) v0112 = nil;
    else { v0112 = qfastgets(v0112);
           if (v0112 != nil) { v0112 = elt(v0112, 17); // share
#ifdef RECORD_GET
             if (v0112 == SPID_NOPROP)
                record_get(elt(fastget_names, 17), 0),
                v0112 = nil;
             else record_get(elt(fastget_names, 17), 1),
                v0112 = lisp_true; }
           else record_get(elt(fastget_names, 17), 0); }
#else
             if (v0112 == SPID_NOPROP) v0112 = nil; else v0112 = lisp_true; }}
#endif
    if (v0112 == nil) goto v0026;
    v0112 = stack[0];
    fn = elt(env, 4); // eval
    v0112 = (*qfn1(fn))(qenv(fn), v0112);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-1];
    v0047 = v0112;
    v0112 = Lstringp(nil, v0112);
    env = stack[-1];
    goto v0009;

v0009:
    if (!(v0112 == nil)) { popv(2); return onevalue(v0047); }
    v0112 = stack[0];
    {
        popv(2);
        fn = elt(env, 5); // string!-downcase
        return (*qfn1(fn))(qenv(fn), v0112);
    }

v0026:
    v0112 = qvalue(elt(env, 2)); // nil
    goto v0009;
// error exit handlers
v0060:
    popv(2);
    return nil;
}



// Code for normalform

static LispObject CC_normalform(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0050, v0051, v0052;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for normalform");
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
    stack[0] = v0001;
    v0052 = v0000;
// end of prologue
    v0051 = qvalue(elt(env, 1)); // !*mode
    v0050 = elt(env, 2); // algebraic
    if (v0051 == v0050) goto v0042;
    v0051 = v0052;
    v0050 = stack[0];
    {
        popv(5);
        fn = elt(env, 4); // normalform!*
        return (*qfn2(fn))(qenv(fn), v0051, v0050);
    }

v0042:
    v0050 = v0052;
    fn = elt(env, 5); // reval
    v0050 = (*qfn1(fn))(qenv(fn), v0050);
    nil = C_nil;
    if (exception_pending()) goto v0053;
    env = stack[-4];
    fn = elt(env, 6); // dpmat_from_a
    stack[-1] = (*qfn1(fn))(qenv(fn), v0050);
    nil = C_nil;
    if (exception_pending()) goto v0053;
    env = stack[-4];
    v0050 = stack[0];
    fn = elt(env, 5); // reval
    v0050 = (*qfn1(fn))(qenv(fn), v0050);
    nil = C_nil;
    if (exception_pending()) goto v0053;
    env = stack[-4];
    fn = elt(env, 6); // dpmat_from_a
    v0050 = (*qfn1(fn))(qenv(fn), v0050);
    nil = C_nil;
    if (exception_pending()) goto v0053;
    env = stack[-4];
    fn = elt(env, 4); // normalform!*
    v0050 = (*qfn2(fn))(qenv(fn), stack[-1], v0050);
    nil = C_nil;
    if (exception_pending()) goto v0053;
    env = stack[-4];
    stack[-3] = v0050;
    stack[-2] = elt(env, 3); // list
    v0050 = stack[-3];
    v0050 = qcar(v0050);
    fn = elt(env, 7); // dpmat_2a
    stack[-1] = (*qfn1(fn))(qenv(fn), v0050);
    nil = C_nil;
    if (exception_pending()) goto v0053;
    env = stack[-4];
    v0050 = stack[-3];
    v0050 = qcdr(v0050);
    v0050 = qcar(v0050);
    fn = elt(env, 7); // dpmat_2a
    stack[0] = (*qfn1(fn))(qenv(fn), v0050);
    nil = C_nil;
    if (exception_pending()) goto v0053;
    env = stack[-4];
    v0050 = stack[-3];
    v0050 = qcdr(v0050);
    v0050 = qcdr(v0050);
    v0050 = qcar(v0050);
    fn = elt(env, 7); // dpmat_2a
    v0050 = (*qfn1(fn))(qenv(fn), v0050);
    nil = C_nil;
    if (exception_pending()) goto v0053;
    {
        LispObject v0178 = stack[-2];
        LispObject v0013 = stack[-1];
        LispObject v0014 = stack[0];
        popv(5);
        return list4(v0178, v0013, v0014, v0050);
    }
// error exit handlers
v0053:
    popv(5);
    return nil;
}



// Code for wureducedp

static LispObject CC_wureducedp(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0047, v0046;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for wureducedp");
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
    v0047 = stack[0];
    fn = elt(env, 2); // wuconstantp
    v0047 = (*qfn1(fn))(qenv(fn), v0047);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-2];
    if (!(v0047 == nil)) { popv(3); return onevalue(v0047); }
    v0047 = stack[-1];
    fn = elt(env, 2); // wuconstantp
    v0047 = (*qfn1(fn))(qenv(fn), v0047);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-2];
    if (!(v0047 == nil)) { popv(3); return onevalue(v0047); }
    v0047 = stack[0];
    fn = elt(env, 2); // wuconstantp
    v0047 = (*qfn1(fn))(qenv(fn), v0047);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-2];
    if (v0047 == nil) goto v0035;
    v0047 = qvalue(elt(env, 1)); // nil
    goto v0020;

v0020:
    fn = elt(env, 3); // deginvar
    v0046 = (*qfn2(fn))(qenv(fn), stack[-1], v0047);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    v0047 = stack[0];
    v0047 = qcar(v0047);
    v0047 = qcar(v0047);
    v0047 = qcdr(v0047);
        popv(3);
        return Llessp(nil, v0046, v0047);

v0035:
    v0047 = stack[0];
    v0047 = qcar(v0047);
    v0047 = qcar(v0047);
    v0047 = qcar(v0047);
    goto v0020;
// error exit handlers
v0048:
    popv(3);
    return nil;
}



// Code for get!-denom!-ll

static LispObject CC_getKdenomKll(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0029, v0006;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for get-denom-ll");
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
    stack[-3] = nil;
    goto v0019;

v0019:
    v0029 = stack[-2];
    if (v0029 == nil) goto v0008;
    v0029 = stack[-2];
    stack[0] = qcar(v0029);
    v0029 = stack[-1];
    v0029 = qcar(v0029);
    fn = elt(env, 1); // get!-denom!-l
    v0029 = (*qfn1(fn))(qenv(fn), v0029);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-4];
    fn = elt(env, 2); // lcmn
    v0006 = (*qfn2(fn))(qenv(fn), stack[0], v0029);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-4];
    v0029 = stack[-3];
    v0029 = cons(v0006, v0029);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-4];
    stack[-3] = v0029;
    v0029 = stack[-2];
    v0029 = qcdr(v0029);
    stack[-2] = v0029;
    v0029 = stack[-1];
    v0029 = qcdr(v0029);
    stack[-1] = v0029;
    goto v0019;

v0008:
    v0029 = stack[-3];
    {
        popv(5);
        fn = elt(env, 3); // nreverse
        return (*qfn1(fn))(qenv(fn), v0029);
    }
// error exit handlers
v0046:
    popv(5);
    return nil;
}



// Code for mk!+conjugate!+sq

static LispObject CC_mkLconjugateLsq(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0019;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mk+conjugate+sq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0019 = v0000;
// end of prologue
    {
        fn = elt(env, 1); // conjsq
        return (*qfn1(fn))(qenv(fn), v0019);
    }
}



// Code for pasf_varlat

static LispObject CC_pasf_varlat(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0208, v0207;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pasf_varlat");
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
    v0208 = stack[0];
    v0208 = qcdr(v0208);
    v0208 = qcar(v0208);
    fn = elt(env, 4); // kernels
    stack[-1] = (*qfn1(fn))(qenv(fn), v0208);
    nil = C_nil;
    if (exception_pending()) goto v0228;
    env = stack[-4];
    v0208 = stack[0];
    v0208 = Lconsp(nil, v0208);
    env = stack[-4];
    if (v0208 == nil) goto v0112;
    v0208 = stack[0];
    v0208 = qcar(v0208);
    v0208 = Lconsp(nil, v0208);
    env = stack[-4];
    if (v0208 == nil) goto v0112;
    v0208 = stack[0];
    v0208 = qcar(v0208);
    v0207 = qcar(v0208);
    v0208 = elt(env, 1); // (cong ncong)
    v0208 = Lmemq(nil, v0207, v0208);
    if (v0208 == nil) goto v0112;
    v0208 = stack[0];
    v0208 = qcar(v0208);
    v0208 = qcdr(v0208);
    fn = elt(env, 4); // kernels
    v0208 = (*qfn1(fn))(qenv(fn), v0208);
    nil = C_nil;
    if (exception_pending()) goto v0228;
    env = stack[-4];
    goto v0008;

v0008:
    v0208 = Lappend(nil, stack[-1], v0208);
    nil = C_nil;
    if (exception_pending()) goto v0228;
    env = stack[-4];
    v0207 = v0208;
    v0208 = qvalue(elt(env, 3)); // !*rlbrkcxk
    if (v0208 == nil) { popv(5); return onevalue(v0207); }
    v0208 = v0207;
    stack[-3] = v0208;
    goto v0110;

v0110:
    v0208 = stack[-3];
    if (v0208 == nil) goto v0044;
    v0208 = stack[-3];
    v0208 = qcar(v0208);
    fn = elt(env, 5); // rltools_lpvarl
    v0208 = (*qfn1(fn))(qenv(fn), v0208);
    nil = C_nil;
    if (exception_pending()) goto v0228;
    env = stack[-4];
    stack[-2] = v0208;
    v0208 = stack[-2];
    fn = elt(env, 6); // lastpair
    v0208 = (*qfn1(fn))(qenv(fn), v0208);
    nil = C_nil;
    if (exception_pending()) goto v0228;
    env = stack[-4];
    stack[-1] = v0208;
    v0208 = stack[-3];
    v0208 = qcdr(v0208);
    stack[-3] = v0208;
    v0208 = stack[-1];
    if (!consp(v0208)) goto v0110;
    else goto v0182;

v0182:
    v0208 = stack[-3];
    if (v0208 == nil) goto v0185;
    stack[0] = stack[-1];
    v0208 = stack[-3];
    v0208 = qcar(v0208);
    fn = elt(env, 5); // rltools_lpvarl
    v0208 = (*qfn1(fn))(qenv(fn), v0208);
    nil = C_nil;
    if (exception_pending()) goto v0228;
    env = stack[-4];
    v0208 = Lrplacd(nil, stack[0], v0208);
    nil = C_nil;
    if (exception_pending()) goto v0228;
    env = stack[-4];
    v0208 = stack[-1];
    fn = elt(env, 6); // lastpair
    v0208 = (*qfn1(fn))(qenv(fn), v0208);
    nil = C_nil;
    if (exception_pending()) goto v0228;
    env = stack[-4];
    stack[-1] = v0208;
    v0208 = stack[-3];
    v0208 = qcdr(v0208);
    stack[-3] = v0208;
    goto v0182;

v0185:
    v0208 = stack[-2];
    goto v0111;

v0111:
    v0207 = v0208;
    { popv(5); return onevalue(v0207); }

v0044:
    v0208 = qvalue(elt(env, 2)); // nil
    goto v0111;

v0112:
    v0208 = qvalue(elt(env, 2)); // nil
    goto v0008;
// error exit handlers
v0228:
    popv(5);
    return nil;
}



// Code for dipnumcontent

static LispObject CC_dipnumcontent(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0035, v0026;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dipnumcontent");
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

v0019:
    v0035 = stack[0];
    fn = elt(env, 1); // bcone!?
    v0035 = (*qfn1(fn))(qenv(fn), v0035);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-3];
    if (!(v0035 == nil)) { LispObject res = stack[0]; popv(4); return onevalue(res); }
    v0035 = stack[-1];
    if (v0035 == nil) { LispObject res = stack[0]; popv(4); return onevalue(res); }
    v0035 = stack[-1];
    v0035 = qcdr(v0035);
    v0035 = qcdr(v0035);
    stack[-2] = v0035;
    v0026 = stack[0];
    v0035 = stack[-1];
    v0035 = qcdr(v0035);
    v0035 = qcar(v0035);
    fn = elt(env, 2); // vbcgcd
    v0035 = (*qfn2(fn))(qenv(fn), v0026, v0035);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-3];
    stack[0] = v0035;
    v0035 = stack[-2];
    stack[-1] = v0035;
    goto v0019;
// error exit handlers
v0029:
    popv(4);
    return nil;
}



// Code for groebsavelterm

static LispObject CC_groebsavelterm(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0054, v0030;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for groebsavelterm");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0030 = v0000;
// end of prologue
    v0054 = qvalue(elt(env, 1)); // !*groelterms
    if (v0054 == nil) goto v0032;
    v0054 = v0030;
    if (v0054 == nil) goto v0031;
    v0054 = v0030;
    v0054 = qcdr(v0054);
    v0054 = qcdr(v0054);
    v0054 = qcdr(v0054);
    v0054 = qcar(v0054);
    v0054 = (v0054 == nil ? lisp_true : nil);
    goto v0016;

v0016:
    if (!(v0054 == nil)) goto v0032;
    v0054 = v0030;
    v0054 = qcdr(v0054);
    v0054 = qcdr(v0054);
    v0054 = qcar(v0054);
    {
        fn = elt(env, 3); // groebsaveltermbc
        return (*qfn1(fn))(qenv(fn), v0054);
    }

v0032:
    v0054 = nil;
    return onevalue(v0054);

v0031:
    v0054 = qvalue(elt(env, 2)); // t
    goto v0016;
}



// Code for ordexp

static LispObject CC_ordexp(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0119, v0057, v0180, v0058;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ordexp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0057 = v0001;
    v0180 = v0000;
// end of prologue

v0032:
    v0119 = v0180;
    if (v0119 == nil) goto v0036;
    v0119 = v0180;
    v0058 = qcar(v0119);
    v0119 = v0057;
    v0119 = qcar(v0119);
    if (v0058 == v0119) goto v0023;
    v0119 = v0180;
    v0119 = qcar(v0119);
    if (v0119 == nil) goto v0010;
    v0119 = v0057;
    v0119 = qcar(v0119);
    if (v0119 == nil) goto v0034;
    v0119 = v0180;
    v0119 = qcar(v0119);
    v0057 = qcar(v0057);
    {
        fn = elt(env, 3); // ordop
        return (*qfn2(fn))(qenv(fn), v0119, v0057);
    }

v0034:
    v0119 = qvalue(elt(env, 1)); // t
    return onevalue(v0119);

v0010:
    v0119 = qvalue(elt(env, 2)); // nil
    return onevalue(v0119);

v0023:
    v0119 = v0180;
    v0119 = qcdr(v0119);
    v0180 = v0119;
    v0119 = v0057;
    v0119 = qcdr(v0119);
    v0057 = v0119;
    goto v0032;

v0036:
    v0119 = qvalue(elt(env, 1)); // t
    return onevalue(v0119);
}



// Code for contr!-strand

static LispObject CC_contrKstrand(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0055, v0009;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for contr-strand");
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
    stack[0] = v0001;
    v0055 = v0000;
// end of prologue

v0032:
    v0009 = stack[0];
    if (v0009 == nil) { popv(2); return onevalue(v0055); }
    v0009 = v0055;
    v0055 = stack[0];
    v0055 = qcar(v0055);
    fn = elt(env, 1); // contr1!-strand
    v0055 = (*qfn2(fn))(qenv(fn), v0009, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-1];
    v0009 = stack[0];
    v0009 = qcdr(v0009);
    stack[0] = v0009;
    goto v0032;
// error exit handlers
v0054:
    popv(2);
    return nil;
}



// Code for formde

static LispObject CC_formde(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0053, v0178, v0013;
    LispObject fn;
    LispObject v0041, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "formde");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0041 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for formde");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0041,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0041);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
// copy arguments values to proper place
    stack[-4] = v0041;
    stack[-5] = v0001;
    v0053 = v0000;
// end of prologue
    stack[-6] = elt(env, 1); // procedure
    v0178 = v0053;
    v0178 = qcdr(v0178);
    stack[-3] = qcar(v0178);
    stack[-2] = elt(env, 2); // symbolic
    stack[-1] = elt(env, 3); // expr
    v0178 = v0053;
    v0178 = qcdr(v0178);
    v0178 = qcdr(v0178);
    stack[0] = qcar(v0178);
    v0178 = v0053;
    v0178 = qcdr(v0178);
    v0178 = qcdr(v0178);
    v0178 = qcdr(v0178);
    v0178 = qcdr(v0178);
    if (v0178 == nil) goto v0112;
    v0178 = elt(env, 4); // progn
    v0053 = qcdr(v0053);
    v0053 = qcdr(v0053);
    v0053 = qcdr(v0053);
    v0053 = cons(v0178, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-7];
    goto v0035;

v0035:
    v0053 = list3(stack[-1], stack[0], v0053);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-7];
    v0013 = list3star(stack[-6], stack[-3], stack[-2], v0053);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-7];
    v0178 = stack[-5];
    v0053 = stack[-4];
    {
        popv(8);
        fn = elt(env, 5); // formproc
        return (*qfnn(fn))(qenv(fn), 3, v0013, v0178, v0053);
    }

v0112:
    v0053 = qcdr(v0053);
    v0053 = qcdr(v0053);
    v0053 = qcdr(v0053);
    v0053 = qcar(v0053);
    goto v0035;
// error exit handlers
v0107:
    popv(8);
    return nil;
}



// Code for sqhorner!*

static LispObject CC_sqhornerH(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0035, v0026;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sqhorner*");
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
    v0035 = qvalue(elt(env, 1)); // !*horner
    if (v0035 == nil) { LispObject res = stack[-1]; popv(4); return onevalue(res); }
    v0026 = qvalue(elt(env, 2)); // ordl!*
    v0035 = qvalue(elt(env, 3)); // kord!*
    v0035 = Lappend(nil, v0026, v0035);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-3];
    stack[-2] = qvalue(elt(env, 3)); // kord!*
    qvalue(elt(env, 3)) = v0035; // kord!*
    v0035 = stack[-1];
    v0035 = qcar(v0035);
    fn = elt(env, 4); // reorder
    stack[0] = (*qfn1(fn))(qenv(fn), v0035);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-3];
    v0035 = stack[-1];
    v0035 = qcdr(v0035);
    fn = elt(env, 4); // reorder
    v0035 = (*qfn1(fn))(qenv(fn), v0035);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-3];
    fn = elt(env, 5); // hornerf
    v0035 = (*qfn1(fn))(qenv(fn), v0035);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-3];
    v0035 = cons(stack[0], v0035);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-3];
    fn = elt(env, 6); // hornersq
    v0035 = (*qfn1(fn))(qenv(fn), v0035);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-3];
    qvalue(elt(env, 3)) = stack[-2]; // kord!*
    { popv(4); return onevalue(v0035); }
// error exit handlers
v0006:
    env = stack[-3];
    qvalue(elt(env, 3)) = stack[-2]; // kord!*
    popv(4);
    return nil;
v0029:
    popv(4);
    return nil;
}



// Code for no_dum_varp

static LispObject CC_no_dum_varp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0027, v0028;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for no_dum_varp");
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
    v0027 = stack[0];
    v0027 = qcdr(v0027);
    if (v0027 == nil) goto v0036;
    v0027 = stack[0];
    v0028 = qcdr(v0027);
    v0027 = elt(env, 2); // list
    fn = elt(env, 4); // splitlist!:
    v0028 = (*qfn2(fn))(qenv(fn), v0028, v0027);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-1];
    v0027 = stack[0];
    v0027 = qcdr(v0027);
    v0027 = (equal(v0028, v0027) ? lisp_true : nil);
    goto v0129;

v0129:
    if (v0027 == nil) goto v0035;
    v0027 = qvalue(elt(env, 1)); // t
    { popv(2); return onevalue(v0027); }

v0035:
    v0027 = qvalue(elt(env, 3)); // nil
    { popv(2); return onevalue(v0027); }

v0036:
    v0027 = qvalue(elt(env, 1)); // t
    goto v0129;
// error exit handlers
v0006:
    popv(2);
    return nil;
}



// Code for proper!-simpsqrt

static LispObject CC_properKsimpsqrt(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0031, v0023;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for proper-simpsqrt");
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
    v0023 = v0031;
    v0031 = elt(env, 0); // proper!-simpsqrt
    fn = elt(env, 1); // carx
    v0031 = (*qfn2(fn))(qenv(fn), v0023, v0031);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); // simpsqrti
        return (*qfn1(fn))(qenv(fn), v0031);
    }
// error exit handlers
v0024:
    popv(1);
    return nil;
}



// Code for open

static LispObject CC_open(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0185, v0181, v0174, v0157;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for open");
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
    v0174 = v0001;
    v0157 = v0000;
// end of prologue
    v0181 = v0174;
    v0185 = elt(env, 1); // input
    if (v0181 == v0185) goto v0038;
    v0181 = v0174;
    v0185 = elt(env, 2); // output
    if (v0181 == v0185) goto v0034;
    v0181 = v0174;
    v0185 = elt(env, 3); // append
    if (v0181 == v0185) goto v0182;
    v0185 = elt(env, 4); // "bad direction ~A in open"
    v0181 = v0174;
    {
        popv(2);
        fn = elt(env, 5); // error
        return (*qfn2(fn))(qenv(fn), v0185, v0181);
    }

v0182:
    stack[0] = v0157;
    v0181 = (LispObject)33; // 2
    v0185 = (LispObject)641; // 40
    v0185 = plus2(v0181, v0185);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    env = stack[-1];
    {
        LispObject v0225 = stack[0];
        popv(2);
        fn = elt(env, 6); // internal!-open
        return (*qfn2(fn))(qenv(fn), v0225, v0185);
    }

v0034:
    stack[0] = v0157;
    v0181 = (LispObject)33; // 2
    v0185 = (LispObject)833; // 52
    v0185 = plus2(v0181, v0185);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    env = stack[-1];
    {
        LispObject v0194 = stack[0];
        popv(2);
        fn = elt(env, 6); // internal!-open
        return (*qfn2(fn))(qenv(fn), v0194, v0185);
    }

v0038:
    v0181 = v0157;
    v0185 = (LispObject)1041; // 65
    {
        popv(2);
        fn = elt(env, 6); // internal!-open
        return (*qfn2(fn))(qenv(fn), v0181, v0185);
    }
// error exit handlers
v0172:
    popv(2);
    return nil;
}



// Code for ofsf_posvarp

static LispObject CC_ofsf_posvarp(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0241, v0063, v0064, v0062;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_posvarp");
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
    v0064 = nil;
    v0241 = stack[-1];
    if (!consp(v0241)) goto v0031;
    v0241 = stack[-1];
    v0241 = qcar(v0241);
    goto v0020;

v0020:
    v0063 = v0241;
    v0241 = elt(env, 1); // and
    if (v0063 == v0241) goto v0015;
    v0063 = stack[-1];
    v0241 = stack[0];
    {
        popv(4);
        fn = elt(env, 15); // ofsf_posvarpat
        return (*qfn2(fn))(qenv(fn), v0063, v0241);
    }

v0015:
    v0241 = stack[-1];
    v0241 = qcdr(v0241);
    stack[-2] = v0241;
    goto v0026;

v0026:
    v0241 = v0064;
    if (v0241 == nil) goto v0017;
    v0241 = qvalue(elt(env, 2)); // nil
    goto v0007;

v0007:
    if (v0241 == nil) { popv(4); return onevalue(v0064); }
    v0241 = stack[-2];
    v0241 = qcar(v0241);
    v0063 = v0241;
    v0241 = stack[-2];
    v0241 = qcdr(v0241);
    stack[-2] = v0241;
    v0241 = v0063;
    v0062 = v0241;
    v0063 = stack[-1];
    v0241 = elt(env, 3); // true
    if (v0063 == v0241) goto v0003;
    v0063 = stack[-1];
    v0241 = elt(env, 5); // false
    v0241 = (v0063 == v0241 ? lisp_true : nil);
    goto v0002;

v0002:
    if (v0241 == nil) goto v0228;
    v0241 = qvalue(elt(env, 4)); // t
    goto v0051;

v0051:
    if (!(v0241 == nil)) goto v0026;
    v0063 = v0062;
    v0241 = stack[0];
    fn = elt(env, 15); // ofsf_posvarpat
    v0241 = (*qfn2(fn))(qenv(fn), v0063, v0241);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[-3];
    v0064 = v0241;
    goto v0026;

v0228:
    v0063 = stack[-1];
    v0241 = elt(env, 6); // or
    if (v0063 == v0241) goto v0190;
    v0063 = stack[-1];
    v0241 = elt(env, 1); // and
    v0241 = (v0063 == v0241 ? lisp_true : nil);
    goto v0189;

v0189:
    if (v0241 == nil) goto v0155;
    v0241 = qvalue(elt(env, 4)); // t
    goto v0101;

v0101:
    if (v0241 == nil) goto v0242;
    v0241 = qvalue(elt(env, 4)); // t
    goto v0158;

v0158:
    if (v0241 == nil) goto v0147;
    v0241 = qvalue(elt(env, 4)); // t
    goto v0051;

v0147:
    v0063 = stack[-1];
    v0241 = elt(env, 11); // ex
    if (v0063 == v0241) goto v0243;
    v0063 = stack[-1];
    v0241 = elt(env, 12); // all
    v0241 = (v0063 == v0241 ? lisp_true : nil);
    goto v0202;

v0202:
    if (v0241 == nil) goto v0197;
    v0241 = qvalue(elt(env, 4)); // t
    goto v0051;

v0197:
    v0063 = stack[-1];
    v0241 = elt(env, 13); // bex
    if (v0063 == v0241) goto v0244;
    v0063 = stack[-1];
    v0241 = elt(env, 14); // ball
    v0241 = (v0063 == v0241 ? lisp_true : nil);
    goto v0245;

v0245:
    if (v0241 == nil) goto v0246;
    v0241 = qvalue(elt(env, 4)); // t
    goto v0051;

v0246:
    v0241 = stack[-1];
    if (!symbolp(v0241)) v0241 = nil;
    else { v0241 = qfastgets(v0241);
           if (v0241 != nil) { v0241 = elt(v0241, 21); // rl_external
#ifdef RECORD_GET
             if (v0241 != SPID_NOPROP)
                record_get(elt(fastget_names, 21), 1);
             else record_get(elt(fastget_names, 21), 0),
                v0241 = nil; }
           else record_get(elt(fastget_names, 21), 0); }
#else
             if (v0241 == SPID_NOPROP) v0241 = nil; }}
#endif
    goto v0051;

v0244:
    v0241 = qvalue(elt(env, 4)); // t
    goto v0245;

v0243:
    v0241 = qvalue(elt(env, 4)); // t
    goto v0202;

v0242:
    v0063 = stack[-1];
    v0241 = elt(env, 8); // impl
    if (v0063 == v0241) goto v0223;
    v0063 = stack[-1];
    v0241 = elt(env, 9); // repl
    if (v0063 == v0241) goto v0247;
    v0063 = stack[-1];
    v0241 = elt(env, 10); // equiv
    v0241 = (v0063 == v0241 ? lisp_true : nil);
    goto v0158;

v0247:
    v0241 = qvalue(elt(env, 4)); // t
    goto v0158;

v0223:
    v0241 = qvalue(elt(env, 4)); // t
    goto v0158;

v0155:
    v0063 = stack[-1];
    v0241 = elt(env, 7); // not
    v0241 = (v0063 == v0241 ? lisp_true : nil);
    goto v0101;

v0190:
    v0241 = qvalue(elt(env, 4)); // t
    goto v0189;

v0003:
    v0241 = qvalue(elt(env, 4)); // t
    goto v0002;

v0017:
    v0241 = stack[-2];
    goto v0007;

v0031:
    v0241 = stack[-1];
    goto v0020;
// error exit handlers
v0196:
    popv(4);
    return nil;
}



// Code for sortedtriplelistinsert

static LispObject CC_sortedtriplelistinsert(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0107, v0185, v0181;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sortedtriplelistinsert");
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
    v0181 = v0000;
// end of prologue
    v0185 = stack[-1];
    v0107 = (LispObject)17; // 1
    v0107 = *(LispObject *)((char *)v0185 + (CELL-TAG_VECTOR) + ((int32_t)v0107/(16/CELL)));
    v0107 = qcar(v0107);
    stack[0] = v0107;
    v0107 = v0181;
    stack[-2] = v0107;
    goto v0011;

v0011:
    v0107 = stack[-2];
    v0107 = qcar(v0107);
    if (v0107 == nil) goto v0050;
    v0107 = stack[-2];
    v0185 = qcar(v0107);
    v0107 = (LispObject)17; // 1
    v0107 = *(LispObject *)((char *)v0185 + (CELL-TAG_VECTOR) + ((int32_t)v0107/(16/CELL)));
    v0185 = qcar(v0107);
    v0107 = stack[0];
    fn = elt(env, 2); // monomcompare
    v0185 = (*qfn2(fn))(qenv(fn), v0185, v0107);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    env = stack[-3];
    v0107 = (LispObject)17; // 1
    if (v0185 == v0107) goto v0050;
    v0107 = stack[-2];
    v0107 = qcdr(v0107);
    stack[-2] = v0107;
    goto v0011;

v0050:
    stack[0] = stack[-2];
    v0107 = stack[-2];
    v0185 = qcar(v0107);
    v0107 = stack[-2];
    v0107 = qcdr(v0107);
    v0107 = cons(v0185, v0107);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    env = stack[-3];
    v0185 = Lrplacd(nil, stack[0], v0107);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    env = stack[-3];
    v0107 = stack[-1];
    v0107 = Lrplaca(nil, v0185, v0107);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    v0107 = nil;
    { popv(4); return onevalue(v0107); }
// error exit handlers
v0172:
    popv(4);
    return nil;
}



// Code for add!-degrees

static LispObject CC_addKdegrees(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0003, v0053;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for add-degrees");
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
    goto v0031;

v0031:
    v0003 = stack[-4];
    if (v0003 == nil) goto v0016;
    v0003 = stack[-4];
    v0003 = qcar(v0003);
    stack[-2] = v0003;
    v0003 = stack[-3];
    v0003 = qcar(v0003);
    stack[-1] = v0003;
    v0003 = qvalue(elt(env, 1)); // nil
    stack[0] = v0003;
    goto v0055;

v0055:
    v0003 = stack[-2];
    if (v0003 == nil) goto v0111;
    v0003 = stack[-2];
    v0053 = qcar(v0003);
    v0003 = stack[-1];
    v0003 = qcar(v0003);
    fn = elt(env, 2); // tayexp!-plus2
    v0053 = (*qfn2(fn))(qenv(fn), v0053, v0003);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-6];
    v0003 = stack[0];
    v0003 = cons(v0053, v0003);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-6];
    stack[0] = v0003;
    v0003 = stack[-2];
    v0003 = qcdr(v0003);
    stack[-2] = v0003;
    v0003 = stack[-1];
    v0003 = qcdr(v0003);
    stack[-1] = v0003;
    goto v0055;

v0111:
    v0003 = stack[0];
    v0053 = Lnreverse(nil, v0003);
    env = stack[-6];
    v0003 = stack[-5];
    v0003 = cons(v0053, v0003);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-6];
    stack[-5] = v0003;
    v0003 = stack[-4];
    v0003 = qcdr(v0003);
    stack[-4] = v0003;
    v0003 = stack[-3];
    v0003 = qcdr(v0003);
    stack[-3] = v0003;
    goto v0031;

v0016:
    v0003 = stack[-5];
        popv(7);
        return Lnreverse(nil, v0003);
// error exit handlers
v0108:
    popv(7);
    return nil;
}



// Code for qqe_arg!-check!-q

static LispObject CC_qqe_argKcheckKq(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0058;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qqe_arg-check-q");
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
    v0058 = stack[0];
    fn = elt(env, 3); // qqe_id!-nyt!-branchq
    v0058 = (*qfn1(fn))(qenv(fn), v0058);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-1];
    if (v0058 == nil) goto v0019;
    v0058 = stack[0];
    if (!consp(v0058)) goto v0038;
    v0058 = qvalue(elt(env, 1)); // nil
    goto v0037;

v0037:
    if (v0058 == nil) goto v0023;
    v0058 = stack[0];
    fn = elt(env, 4); // qqe_btidp
    v0058 = (*qfn1(fn))(qenv(fn), v0058);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-1];
    if (v0058 == nil) goto v0010;
    v0058 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0058); }

v0010:
    v0058 = stack[0];
    fn = elt(env, 5); // qqe_nytidp
    v0058 = (*qfn1(fn))(qenv(fn), v0058);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-1];
    if (v0058 == nil) goto v0017;
    v0058 = stack[0];
    fn = elt(env, 6); // qqe_qtid
    v0058 = (*qfn1(fn))(qenv(fn), v0058);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-1];
    v0058 = stack[0];
    fn = elt(env, 7); // qqe_add2rollbackids
    v0058 = (*qfn1(fn))(qenv(fn), v0058);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-1];
    v0058 = qvalue(elt(env, 2)); // t
    { popv(2); return onevalue(v0058); }

v0017:
    v0058 = qvalue(elt(env, 2)); // t
    { popv(2); return onevalue(v0058); }

v0023:
    v0058 = stack[0];
    if (is_number(v0058)) goto v0032;
    v0058 = stack[0];
    fn = elt(env, 8); // qqe_arg!-check
    v0058 = (*qfn1(fn))(qenv(fn), v0058);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-1];
    v0058 = qvalue(elt(env, 2)); // t
    { popv(2); return onevalue(v0058); }

v0032:
    v0058 = nil;
    { popv(2); return onevalue(v0058); }

v0038:
    v0058 = stack[0];
    v0058 = (is_number(v0058) ? lisp_true : nil);
    v0058 = (v0058 == nil ? lisp_true : nil);
    goto v0037;

v0019:
    v0058 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0058); }
// error exit handlers
v0111:
    popv(2);
    return nil;
}



// Code for cl_susiupdknowl

static LispObject CC_cl_susiupdknowl(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0051, v0052, v0061, v0177;
    LispObject fn;
    LispObject v0022, v0041, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "cl_susiupdknowl");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0041 = va_arg(aa, LispObject);
    v0022 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cl_susiupdknowl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0022,v0041,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0001,v0041,v0022);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0022;
    v0051 = v0041;
    stack[-1] = v0001;
    stack[-2] = v0000;
// end of prologue
    stack[-3] = nil;
    goto v0016;

v0016:
    v0052 = stack[-1];
    if (v0052 == nil) goto v0058;
    v0052 = stack[-1];
    v0052 = qcar(v0052);
    stack[-3] = v0052;
    v0052 = stack[-1];
    v0052 = qcdr(v0052);
    stack[-1] = v0052;
    v0177 = stack[-2];
    v0061 = stack[-3];
    v0052 = v0051;
    v0051 = stack[0];
    fn = elt(env, 4); // cl_susiupdknowl1
    v0051 = (*qfnn(fn))(qenv(fn), 4, v0177, v0061, v0052, v0051);
    nil = C_nil;
    if (exception_pending()) goto v0013;
    env = stack[-4];
    v0061 = v0051;
    v0052 = elt(env, 2); // false
    if (!(v0061 == v0052)) goto v0016;
    v0052 = qvalue(elt(env, 1)); // nil
    stack[-1] = v0052;
    v0052 = elt(env, 3); // break
    stack[-3] = v0052;
    goto v0016;

v0058:
    v0061 = stack[-3];
    v0052 = elt(env, 3); // break
    if (!(v0061 == v0052)) { popv(5); return onevalue(v0051); }
    v0051 = elt(env, 2); // false
    { popv(5); return onevalue(v0051); }
// error exit handlers
v0013:
    popv(5);
    return nil;
}



setup_type const u27_setup[] =
{
    {"n_nary",                  too_few_2,      CC_n_nary,     wrong_no_2},
    {"gcd2",                    too_few_2,      CC_gcd2,       wrong_no_2},
    {"meq",                     too_few_2,      CC_meq,        wrong_no_2},
    {"groebnormalform",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_groebnormalform},
    {"memqcar",                 too_few_2,      CC_memqcar,    wrong_no_2},
    {"equalreval",              CC_equalreval,  too_many_1,    wrong_no_1},
    {"can_be_proved",           too_few_2,      CC_can_be_proved,wrong_no_2},
    {"log_assignment_list",     too_few_2,      CC_log_assignment_list,wrong_no_2},
    {"insert",                  too_few_2,      CC_insert,     wrong_no_2},
    {"bndtst",                  CC_bndtst,      too_many_1,    wrong_no_1},
    {"gcd-in-vector",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_gcdKinKvector},
    {"procstat1",               CC_procstat1,   too_many_1,    wrong_no_1},
    {"opmtchrevop",             CC_opmtchrevop, too_many_1,    wrong_no_1},
    {"ofsf_optsubstat",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_optsubstat},
    {"lambdavar",               CC_lambdavar,   too_many_1,    wrong_no_1},
    {"rowdel",                  CC_rowdel,      too_many_1,    wrong_no_1},
    {"bfplusn",                 too_few_2,      CC_bfplusn,    wrong_no_2},
    {"fortranname",             CC_fortranname, too_many_1,    wrong_no_1},
    {"edge_new_parent",         CC_edge_new_parent,too_many_1, wrong_no_1},
    {"mksetq",                  too_few_2,      CC_mksetq,     wrong_no_2},
    {"ifstat",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_ifstat},
    {"co_new",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_co_new},
    {"homogp",                  CC_homogp,      too_many_1,    wrong_no_1},
    {"aex_mvar",                CC_aex_mvar,    too_many_1,    wrong_no_1},
    {"dip2vdp",                 CC_dip2vdp,     too_many_1,    wrong_no_1},
    {"assert_stat1",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_assert_stat1},
    {"nf",                      wrong_no_na,    wrong_no_nb,   (n_args *)CC_nf},
    {"prepreform1",             too_few_2,      CC_prepreform1,wrong_no_2},
    {"mksp*",                   too_few_2,      CC_mkspH,      wrong_no_2},
    {"bc_2sq",                  CC_bc_2sq,      too_many_1,    wrong_no_1},
    {"ombindir",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_ombindir},
    {"simpdf*",                 CC_simpdfH,     too_many_1,    wrong_no_1},
    {"nextcomb",                too_few_2,      CC_nextcomb,   wrong_no_2},
    {"dip-nc-ev-prod1",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_dipKncKevKprod1},
    {"vevstrictlydivides?",     too_few_2,      CC_vevstrictlydividesW,wrong_no_2},
    {"pterpri",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_pterpri},
    {"getphystypeor",           CC_getphystypeor,too_many_1,   wrong_no_1},
    {"mk-numr",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_mkKnumr},
    {"nzero",                   CC_nzero,       too_many_1,    wrong_no_1},
    {"general-evaluate-mod-p",  wrong_no_na,    wrong_no_nb,   (n_args *)CC_generalKevaluateKmodKp},
    {"string-of-list",          CC_stringKofKlist,too_many_1,  wrong_no_1},
    {"sfto_lessq",              too_few_2,      CC_sfto_lessq, wrong_no_2},
    {"mkfil*",                  CC_mkfilH,      too_many_1,    wrong_no_1},
    {"normalform",              too_few_2,      CC_normalform, wrong_no_2},
    {"wureducedp",              too_few_2,      CC_wureducedp, wrong_no_2},
    {"get-denom-ll",            too_few_2,      CC_getKdenomKll,wrong_no_2},
    {"mk+conjugate+sq",         CC_mkLconjugateLsq,too_many_1, wrong_no_1},
    {"pasf_varlat",             CC_pasf_varlat, too_many_1,    wrong_no_1},
    {"dipnumcontent",           too_few_2,      CC_dipnumcontent,wrong_no_2},
    {"groebsavelterm",          CC_groebsavelterm,too_many_1,  wrong_no_1},
    {"ordexp",                  too_few_2,      CC_ordexp,     wrong_no_2},
    {"contr-strand",            too_few_2,      CC_contrKstrand,wrong_no_2},
    {"formde",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_formde},
    {"sqhorner*",               CC_sqhornerH,   too_many_1,    wrong_no_1},
    {"no_dum_varp",             CC_no_dum_varp, too_many_1,    wrong_no_1},
    {"proper-simpsqrt",         CC_properKsimpsqrt,too_many_1, wrong_no_1},
    {"open",                    too_few_2,      CC_open,       wrong_no_2},
    {"ofsf_posvarp",            too_few_2,      CC_ofsf_posvarp,wrong_no_2},
    {"sortedtriplelistinsert",  too_few_2,      CC_sortedtriplelistinsert,wrong_no_2},
    {"add-degrees",             too_few_2,      CC_addKdegrees,wrong_no_2},
    {"qqe_arg-check-q",         CC_qqe_argKcheckKq,too_many_1, wrong_no_1},
    {"cl_susiupdknowl",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_cl_susiupdknowl},
    {NULL, (one_args *)"u27", (two_args *)"22797 6421170 934470", 0}
};

// end of generated code
