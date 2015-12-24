
// $destdir/u41.c        Machine generated C code

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



// Code for markedvarp

static LispObject CC_markedvarp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0003, v0004;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for markedvarp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0003 = v0000;
// end of prologue
    v0004 = elt(env, 1); // !*marked!*
        return Lflagp(nil, v0003, v0004);
}



// Code for incident1

static LispObject CC_incident1(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0028, v0029, v0030, v0031, v0032;
    LispObject v0010, v0011, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "incident1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0011 = va_arg(aa, LispObject);
    v0010 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for incident1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0010,v0011,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0011,v0010);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    v0030 = v0010;
    v0031 = v0011;
    v0032 = v0000;
// end of prologue
    v0029 = v0032;
    v0028 = v0031;
    v0028 = qcar(v0028);
    v0028 = qcar(v0028);
    if (v0029 == v0028) goto v0033;
    v0029 = v0032;
    v0028 = v0031;
    v0028 = qcdr(v0028);
    v0028 = qcar(v0028);
    v0028 = qcar(v0028);
    if (v0029 == v0028) goto v0034;
    v0029 = v0032;
    v0028 = v0031;
    v0028 = qcdr(v0028);
    v0028 = qcdr(v0028);
    v0028 = qcar(v0028);
    v0028 = qcar(v0028);
    if (v0029 == v0028) goto v0035;
    v0028 = qvalue(elt(env, 1)); // nil
    { popv(3); return onevalue(v0028); }

v0035:
    v0028 = v0031;
    v0028 = qcar(v0028);
    stack[-1] = qcar(v0028);
    stack[0] = v0030;
    v0028 = v0031;
    v0028 = qcdr(v0028);
    v0028 = qcar(v0028);
    v0028 = qcar(v0028);
    v0029 = v0030;
    v0028 = cons(v0028, v0029);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-2];
    v0028 = ncons(v0028);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    {
        LispObject v0037 = stack[-1];
        LispObject v0038 = stack[0];
        popv(3);
        return acons(v0037, v0038, v0028);
    }

v0034:
    v0028 = v0031;
    v0028 = qcdr(v0028);
    v0028 = qcdr(v0028);
    v0028 = qcar(v0028);
    stack[-1] = qcar(v0028);
    stack[0] = v0030;
    v0028 = v0031;
    v0028 = qcar(v0028);
    v0028 = qcar(v0028);
    v0029 = v0030;
    v0028 = cons(v0028, v0029);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-2];
    v0028 = ncons(v0028);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    {
        LispObject v0039 = stack[-1];
        LispObject v0040 = stack[0];
        popv(3);
        return acons(v0039, v0040, v0028);
    }

v0033:
    v0028 = v0031;
    v0028 = qcdr(v0028);
    v0028 = qcar(v0028);
    stack[-1] = qcar(v0028);
    stack[0] = v0030;
    v0028 = v0031;
    v0028 = qcdr(v0028);
    v0028 = qcdr(v0028);
    v0028 = qcar(v0028);
    v0028 = qcar(v0028);
    v0029 = v0030;
    v0028 = cons(v0028, v0029);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-2];
    v0028 = ncons(v0028);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    {
        LispObject v0041 = stack[-1];
        LispObject v0042 = stack[0];
        popv(3);
        return acons(v0041, v0042, v0028);
    }
// error exit handlers
v0036:
    popv(3);
    return nil;
}



// Code for prepsq!*0

static LispObject CC_prepsqH0(LispObject env,
                         LispObject v0000, LispObject v0011)
{
    LispObject nil = C_nil;
    LispObject v0054, v0055, v0056;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for prepsq*0");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0011,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0011);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0011;
    stack[-2] = v0000;
// end of prologue
    v0054 = stack[-2];
    v0054 = qcar(v0054);
    if (v0054 == nil) goto v0002;
    v0054 = stack[-2];
    v0055 = qcar(v0054);
    v0054 = stack[-2];
    v0054 = qcdr(v0054);
    fn = elt(env, 2); // gcdf
    v0055 = (*qfn2(fn))(qenv(fn), v0055, v0054);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[-4];
    stack[-3] = v0055;
    v0054 = (LispObject)17; // 1
    if (v0055 == v0054) goto v0058;
    v0054 = stack[-2];
    v0055 = qcar(v0054);
    v0054 = stack[-3];
    fn = elt(env, 3); // quotf!-fail
    stack[0] = (*qfn2(fn))(qenv(fn), v0055, v0054);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[-4];
    v0054 = stack[-2];
    v0055 = qcdr(v0054);
    v0054 = stack[-3];
    fn = elt(env, 3); // quotf!-fail
    v0055 = (*qfn2(fn))(qenv(fn), v0055, v0054);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[-4];
    v0054 = stack[-1];
    {
        LispObject v0059 = stack[0];
        popv(5);
        fn = elt(env, 4); // prepsq!*1
        return (*qfnn(fn))(qenv(fn), 3, v0059, v0055, v0054);
    }

v0058:
    v0054 = stack[-2];
    v0056 = qcar(v0054);
    v0054 = stack[-2];
    v0055 = qcdr(v0054);
    v0054 = stack[-1];
    {
        popv(5);
        fn = elt(env, 4); // prepsq!*1
        return (*qfnn(fn))(qenv(fn), 3, v0056, v0055, v0054);
    }

v0002:
    v0054 = qvalue(elt(env, 1)); // nil
    { popv(5); return onevalue(v0054); }
// error exit handlers
v0057:
    popv(5);
    return nil;
}



// Code for derivative!-mod!-p

static LispObject CC_derivativeKmodKp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0050, v0051, v0046;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for derivative-mod-p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0046 = v0000;
// end of prologue
    v0050 = v0046;
    if (!consp(v0050)) goto v0002;
    v0050 = v0046;
    v0050 = qcar(v0050);
    v0050 = (consp(v0050) ? nil : lisp_true);
    goto v0062;

v0062:
    if (v0050 == nil) goto v0052;
    v0050 = qvalue(elt(env, 2)); // nil
    return onevalue(v0050);

v0052:
    v0050 = v0046;
    v0050 = qcar(v0050);
    v0050 = qcar(v0050);
    v0051 = qcdr(v0050);
    v0050 = (LispObject)17; // 1
    if (v0051 == v0050) goto v0033;
    v0050 = v0046;
    v0051 = v0046;
    v0051 = qcar(v0051);
    v0051 = qcar(v0051);
    v0051 = qcar(v0051);
    {
        fn = elt(env, 3); // derivative!-mod!-p!-1
        return (*qfn2(fn))(qenv(fn), v0050, v0051);
    }

v0033:
    v0050 = v0046;
    v0050 = qcar(v0050);
    v0050 = qcdr(v0050);
    return onevalue(v0050);

v0002:
    v0050 = qvalue(elt(env, 1)); // t
    goto v0062;
}



// Code for change!+int!+to!+sq

static LispObject CC_changeLintLtoLsq(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0063, v0026;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for change+int+to+sq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0063 = v0000;
// end of prologue
    v0026 = v0063;
    v0063 = (LispObject)17; // 1
    return cons(v0026, v0063);
}



// Code for cl_gand!-col

static LispObject CC_cl_gandKcol(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0087, v0088, v0089;
    LispObject fn;
    LispObject v0049, v0010, v0011, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "cl_gand-col");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0011 = va_arg(aa, LispObject);
    v0010 = va_arg(aa, LispObject);
    v0049 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cl_gand-col");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0049,v0010,v0011,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0011,v0010,v0049);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-4] = v0049;
    stack[-5] = v0010;
    stack[-6] = v0011;
    stack[-7] = v0000;
// end of prologue
    stack[-8] = nil;
    v0089 = elt(env, 1); // true
    v0088 = stack[-5];
    v0087 = elt(env, 2); // and
    v0087 = (v0088 == v0087 ? lisp_true : nil);
    fn = elt(env, 5); // cl_cflip
    v0087 = (*qfn2(fn))(qenv(fn), v0089, v0087);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-9];
    stack[-3] = v0087;
    v0087 = stack[-3];
    fn = elt(env, 6); // cl_flip
    v0087 = (*qfn1(fn))(qenv(fn), v0087);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-9];
    stack[-2] = v0087;
    goto v0023;

v0023:
    v0087 = stack[-7];
    if (v0087 == nil) goto v0021;
    v0087 = stack[-7];
    stack[-1] = qcar(v0087);
    stack[0] = stack[-4];
    v0087 = stack[-6];
    v0088 = sub1(v0087);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-9];
    v0087 = stack[-5];
    fn = elt(env, 7); // cl_simpl1
    v0087 = (*qfnn(fn))(qenv(fn), 4, stack[-1], stack[0], v0088, v0087);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-9];
    v0089 = v0087;
    v0087 = stack[-7];
    v0087 = qcdr(v0087);
    stack[-7] = v0087;
    v0088 = v0089;
    v0087 = stack[-2];
    if (v0088 == v0087) goto v0047;
    v0088 = v0089;
    v0087 = stack[-3];
    if (equal(v0088, v0087)) goto v0023;
    v0087 = v0089;
    if (!consp(v0087)) goto v0091;
    v0087 = v0089;
    v0087 = qcar(v0087);
    v0088 = v0087;
    goto v0092;

v0092:
    v0087 = stack[-5];
    if (v0088 == v0087) goto v0057;
    v0087 = qvalue(elt(env, 4)); // !*rlsichk
    if (v0087 == nil) goto v0093;
    v0088 = v0089;
    v0087 = stack[-8];
    v0087 = Lmember(nil, v0088, v0087);
    if (!(v0087 == nil)) goto v0023;

v0093:
    v0088 = v0089;
    v0087 = stack[-8];
    v0087 = cons(v0088, v0087);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-9];
    stack[-8] = v0087;
    goto v0023;

v0057:
    v0087 = qvalue(elt(env, 4)); // !*rlsichk
    if (v0087 == nil) goto v0094;
    v0087 = v0089;
    v0087 = qcdr(v0087);
    stack[0] = v0087;
    goto v0095;

v0095:
    v0087 = stack[0];
    if (v0087 == nil) goto v0023;
    v0087 = stack[0];
    v0087 = qcar(v0087);
    v0089 = v0087;
    v0088 = v0089;
    v0087 = stack[-8];
    v0087 = Lmember(nil, v0088, v0087);
    if (!(v0087 == nil)) goto v0096;
    v0088 = v0089;
    v0087 = stack[-8];
    v0087 = cons(v0088, v0087);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-9];
    stack[-8] = v0087;
    goto v0096;

v0096:
    v0087 = stack[0];
    v0087 = qcdr(v0087);
    stack[0] = v0087;
    goto v0095;

v0094:
    v0087 = v0089;
    v0087 = qcdr(v0087);
    stack[0] = v0087;
    goto v0097;

v0097:
    v0087 = stack[0];
    if (v0087 == nil) goto v0023;
    v0087 = stack[0];
    v0087 = qcar(v0087);
    v0088 = v0087;
    v0087 = stack[-8];
    v0087 = cons(v0088, v0087);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-9];
    stack[-8] = v0087;
    v0087 = stack[0];
    v0087 = qcdr(v0087);
    stack[0] = v0087;
    goto v0097;

v0091:
    v0087 = v0089;
    v0088 = v0087;
    goto v0092;

v0047:
    v0087 = stack[-2];
    v0087 = ncons(v0087);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-9];
    stack[-8] = v0087;
    v0087 = qvalue(elt(env, 3)); // nil
    stack[-7] = v0087;
    goto v0023;

v0021:
    v0087 = stack[-8];
    if (v0087 == nil) goto v0098;
    v0087 = stack[-8];
        popv(10);
        return Lnreverse(nil, v0087);

v0098:
    v0087 = stack[-3];
    popv(10);
    return ncons(v0087);
// error exit handlers
v0090:
    popv(10);
    return nil;
}



// Code for ev_mtest!?

static LispObject CC_ev_mtestW(LispObject env,
                         LispObject v0000, LispObject v0011)
{
    LispObject nil = C_nil;
    LispObject v0100, v0024, v0025, v0101, v0102;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ev_mtest?");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0025 = v0011;
    v0101 = v0000;
// end of prologue
    v0100 = qvalue(elt(env, 1)); // t
    v0102 = v0100;
    goto v0001;

v0001:
    v0100 = v0101;
    if (v0100 == nil) return onevalue(v0102);
    v0100 = v0102;
    if (v0100 == nil) return onevalue(v0102);
    v0100 = v0101;
    v0024 = qcar(v0100);
    v0100 = v0025;
    v0100 = qcar(v0100);
    if (((int32_t)(v0024)) < ((int32_t)(v0100))) goto v0103;
    v0100 = v0101;
    v0100 = qcdr(v0100);
    v0101 = v0100;
    v0100 = v0025;
    v0100 = qcdr(v0100);
    v0025 = v0100;
    goto v0001;

v0103:
    v0100 = qvalue(elt(env, 2)); // nil
    v0102 = v0100;
    v0101 = v0100;
    goto v0001;
}



// Code for numir

static LispObject CC_numir(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0130, v0131, v0132;
    LispObject fn;
    argcheck(nargs, 0, "numir");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for numir");
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
    push2(nil, nil);
// end of prologue
    v0131 = qvalue(elt(env, 1)); // atts
    v0130 = elt(env, 2); // name
    fn = elt(env, 12); // find
    v0130 = (*qfn2(fn))(qenv(fn), v0131, v0130);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-7];
    v0130 = Lintern(nil, v0130);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-7];
    stack[-1] = v0130;
    fn = elt(env, 13); // lex
    v0130 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-7];
    fn = elt(env, 14); // omobj
    v0130 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-7];
    stack[0] = v0130;
    fn = elt(env, 13); // lex
    v0130 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-7];
    fn = elt(env, 14); // omobj
    v0130 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-7];
    v0132 = stack[-1];
    v0131 = elt(env, 3); // complex_cartesian
    if (!(v0132 == v0131)) goto v0092;
    v0131 = stack[0];
    if (symbolp(v0131)) goto v0100;
    v0131 = v0130;
    if (!(symbolp(v0131))) goto v0092;

v0100:
    stack[-4] = elt(env, 4); // plus
    stack[-3] = qvalue(elt(env, 5)); // nil
    stack[-2] = stack[0];
    stack[-1] = elt(env, 6); // times
    stack[0] = qvalue(elt(env, 5)); // nil
    v0132 = v0130;
    v0131 = elt(env, 7); // !&imaginaryi!;
    v0130 = qvalue(elt(env, 5)); // nil
    v0130 = list2star(v0132, v0131, v0130);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-7];
    v0131 = list2star(stack[-1], stack[0], v0130);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-7];
    v0130 = qvalue(elt(env, 5)); // nil
    v0130 = list2star(stack[-2], v0131, v0130);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    {
        LispObject v0134 = stack[-4];
        LispObject v0135 = stack[-3];
        popv(8);
        return list2star(v0134, v0135, v0130);
    }

v0092:
    v0132 = stack[-1];
    v0131 = elt(env, 8); // complex_polar
    if (!(v0132 == v0131)) goto v0136;
    v0131 = stack[0];
    if (symbolp(v0131)) goto v0137;
    v0131 = v0130;
    if (!(symbolp(v0131))) goto v0136;

v0137:
    stack[-6] = elt(env, 6); // times
    stack[-5] = qvalue(elt(env, 5)); // nil
    stack[-4] = stack[0];
    stack[-3] = elt(env, 9); // exp
    stack[-2] = qvalue(elt(env, 5)); // nil
    stack[-1] = elt(env, 6); // times
    stack[0] = qvalue(elt(env, 5)); // nil
    v0132 = v0130;
    v0131 = elt(env, 7); // !&imaginaryi!;
    v0130 = qvalue(elt(env, 5)); // nil
    v0130 = list2star(v0132, v0131, v0130);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-7];
    v0130 = list2star(stack[-1], stack[0], v0130);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-7];
    v0130 = ncons(v0130);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-7];
    v0131 = list2star(stack[-3], stack[-2], v0130);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-7];
    v0130 = qvalue(elt(env, 5)); // nil
    v0130 = list2star(stack[-4], v0131, v0130);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    {
        LispObject v0138 = stack[-6];
        LispObject v0139 = stack[-5];
        popv(8);
        return list2star(v0138, v0139, v0130);
    }

v0136:
    v0132 = stack[-1];
    v0131 = elt(env, 10); // rational
    if (!(v0132 == v0131)) goto v0140;
    v0131 = stack[0];
    if (symbolp(v0131)) goto v0141;
    v0131 = v0130;
    if (!(symbolp(v0131))) goto v0140;

v0141:
    stack[-2] = elt(env, 11); // divide
    stack[-1] = qvalue(elt(env, 5)); // nil
    v0132 = stack[0];
    v0131 = v0130;
    v0130 = qvalue(elt(env, 5)); // nil
    v0130 = list2star(v0132, v0131, v0130);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    {
        LispObject v0142 = stack[-2];
        LispObject v0143 = stack[-1];
        popv(8);
        return list2star(v0142, v0143, v0130);
    }

v0140:
    stack[-2] = stack[-1];
    stack[-1] = qvalue(elt(env, 5)); // nil
    v0132 = stack[0];
    v0131 = v0130;
    v0130 = qvalue(elt(env, 5)); // nil
    v0130 = list2star(v0132, v0131, v0130);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    {
        LispObject v0144 = stack[-2];
        LispObject v0145 = stack[-1];
        popv(8);
        return list2star(v0144, v0145, v0130);
    }
// error exit handlers
v0133:
    popv(8);
    return nil;
}



// Code for mkexpt

static LispObject CC_mkexpt(LispObject env,
                         LispObject v0000, LispObject v0011)
{
    LispObject nil = C_nil;
    LispObject v0022, v0021, v0023, v0099;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mkexpt");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0023 = v0011;
    v0099 = v0000;
// end of prologue
    v0021 = v0023;
    v0022 = (LispObject)17; // 1
    if (v0021 == v0022) return onevalue(v0099);
    v0022 = elt(env, 1); // expt
    v0021 = v0099;
    return list3(v0022, v0021, v0023);
}



// Code for evalmember

static LispObject CC_evalmember(LispObject env,
                         LispObject v0000, LispObject v0011)
{
    LispObject nil = C_nil;
    LispObject v0063, v0026;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evalmember");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0011,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0011);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0063 = v0011;
    v0026 = v0000;
// end of prologue
    stack[0] = v0026;
    fn = elt(env, 1); // getrlist
    v0063 = (*qfn1(fn))(qenv(fn), v0063);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    v0063 = Lmember(nil, stack[0], v0063);
    { popv(1); return onevalue(v0063); }
// error exit handlers
v0129:
    popv(1);
    return nil;
}



// Code for e!*

static LispObject CC_eH(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0049;
    LispObject fn;
    argcheck(nargs, 0, "e*");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for e*");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// end of prologue
    v0049 = qvalue(elt(env, 1)); // !:bprec!:
    {
        fn = elt(env, 2); // !:e
        return (*qfn1(fn))(qenv(fn), v0049);
    }
}



// Code for gpargp

static LispObject CC_gpargp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0128;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gpargp");
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
    v0128 = stack[0];
    v0128 = Lstringp(nil, v0128);
    env = stack[-1];
    if (!(v0128 == nil)) { popv(2); return onevalue(v0128); }
    v0128 = stack[0];
    fn = elt(env, 1); // gpexpp
    v0128 = (*qfn1(fn))(qenv(fn), v0128);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-1];
    if (!(v0128 == nil)) { popv(2); return onevalue(v0128); }
    v0128 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); // gplogexpp
        return (*qfn1(fn))(qenv(fn), v0128);
    }
// error exit handlers
v0027:
    popv(2);
    return nil;
}



// Code for indexvp

static LispObject CC_indexvp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0026, v0128;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for indexvp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0128 = v0000;
// end of prologue
    v0026 = v0128;
    if (!consp(v0026)) goto v0003;
    v0026 = v0128;
    v0026 = qcar(v0026);
    if (!symbolp(v0026)) v0026 = nil;
    else { v0026 = qfastgets(v0026);
           if (v0026 != nil) { v0026 = elt(v0026, 16); // indexvar
#ifdef RECORD_GET
             if (v0026 == SPID_NOPROP)
                record_get(elt(fastget_names, 16), 0),
                v0026 = nil;
             else record_get(elt(fastget_names, 16), 1),
                v0026 = lisp_true; }
           else record_get(elt(fastget_names, 16), 0); }
#else
             if (v0026 == SPID_NOPROP) v0026 = nil; else v0026 = lisp_true; }}
#endif
    return onevalue(v0026);

v0003:
    v0026 = qvalue(elt(env, 1)); // nil
    return onevalue(v0026);
}



// Code for ev!-edgeloop

static LispObject CC_evKedgeloop(LispObject env,
                         LispObject v0000, LispObject v0011)
{
    LispObject nil = C_nil;
    LispObject v0052, v0103, v0148;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ev-edgeloop");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0052 = v0011;
    v0103 = v0000;
// end of prologue
    v0148 = qvalue(elt(env, 1)); // ndim!*
    v0103 = qcar(v0103);
    v0052 = Lassoc(nil, v0103, v0052);
    v0052 = qcdr(v0052);
    {
        fn = elt(env, 2); // binc
        return (*qfn2(fn))(qenv(fn), v0148, v0052);
    }
}



// Code for applsmacro

static LispObject CC_applsmacro(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0192, v0193, v0194;
    LispObject fn;
    LispObject v0010, v0011, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "applsmacro");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0011 = va_arg(aa, LispObject);
    v0010 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for applsmacro");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0010,v0011,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0011,v0010);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-2] = v0010;
    stack[-7] = v0011;
    v0193 = v0000;
// end of prologue
    stack[-6] = nil;
    stack[-5] = qvalue(elt(env, 1)); // inlineinfo
    qvalue(elt(env, 1)) = nil; // inlineinfo
    v0192 = v0193;
    v0192 = qcdr(v0192);
    v0192 = qcar(v0192);
    stack[-3] = v0192;
    v0192 = v0193;
    v0192 = qcdr(v0192);
    v0192 = qcdr(v0192);
    v0192 = qcar(v0192);
    stack[-8] = v0192;
    v0194 = stack[-2];
    v0193 = stack[-3];
    v0192 = stack[-8];
    v0192 = list3(v0194, v0193, v0192);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-9];
    qvalue(elt(env, 1)) = v0192; // inlineinfo
    v0192 = stack[-3];
    stack[0] = Llength(nil, v0192);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-9];
    v0192 = stack[-7];
    v0192 = Llength(nil, v0192);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-9];
    if (equal(stack[0], v0192)) goto v0023;
    stack[-1] = elt(env, 2); // rlisp
    stack[0] = (LispObject)241; // 15
    v0193 = elt(env, 3); // "Argument mismatch for SMACRO"
    v0192 = stack[-2];
    v0192 = list2(v0193, v0192);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-9];
    fn = elt(env, 8); // rerror
    v0192 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v0192);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-9];
    goto v0023;

v0023:
    v0192 = qvalue(elt(env, 4)); // !*loginlines
    if (v0192 == nil) goto v0058;
    v0194 = stack[-3];
    v0193 = stack[-8];
    v0192 = stack[-7];
    fn = elt(env, 9); // log_inlines
    v0192 = (*qfnn(fn))(qenv(fn), 3, v0194, v0193, v0192);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-9];
    goto v0058;

v0058:
    v0192 = stack[-7];
    fn = elt(env, 10); // no!-side!-effect!-listp
    v0192 = (*qfn1(fn))(qenv(fn), v0192);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-9];
    if (!(v0192 == nil)) goto v0196;
    v0193 = stack[-3];
    v0192 = stack[-8];
    fn = elt(env, 11); // one!-entry!-listp
    v0192 = (*qfn2(fn))(qenv(fn), v0193, v0192);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-9];
    if (!(v0192 == nil)) goto v0196;
    v0192 = stack[-3];
    v0193 = Llength(nil, v0192);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-9];
    v0192 = (LispObject)17; // 1
    v0192 = (LispObject)greaterp2(v0193, v0192);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    v0192 = v0192 ? lisp_true : nil;
    env = stack[-9];
    if (v0192 == nil) goto v0078;
    v0192 = stack[-3];
    stack[-4] = v0192;
    v0192 = stack[-4];
    if (v0192 == nil) goto v0036;
    v0192 = stack[-4];
    v0192 = qcar(v0192);
    stack[0] = v0192;
    v0192 = elt(env, 6); // g
    v0192 = Lgensym1(nil, v0192);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-9];
    v0192 = cons(stack[0], v0192);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-9];
    v0192 = ncons(v0192);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-9];
    stack[-2] = v0192;
    stack[-3] = v0192;
    goto v0031;

v0031:
    v0192 = stack[-4];
    v0192 = qcdr(v0192);
    stack[-4] = v0192;
    v0192 = stack[-4];
    if (v0192 == nil) goto v0122;
    stack[-1] = stack[-2];
    v0192 = stack[-4];
    v0192 = qcar(v0192);
    stack[0] = v0192;
    v0192 = elt(env, 6); // g
    v0192 = Lgensym1(nil, v0192);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-9];
    v0192 = cons(stack[0], v0192);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-9];
    v0192 = ncons(v0192);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-9];
    v0192 = Lrplacd(nil, stack[-1], v0192);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-9];
    v0192 = stack[-2];
    v0192 = qcdr(v0192);
    stack[-2] = v0192;
    goto v0031;

v0122:
    v0192 = stack[-3];
    goto v0030;

v0030:
    stack[0] = v0192;
    v0193 = stack[0];
    v0192 = stack[-8];
    fn = elt(env, 12); // subla!-q
    v0192 = (*qfn2(fn))(qenv(fn), v0193, v0192);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-9];
    stack[-8] = v0192;
    v0192 = stack[0];
    stack[-3] = v0192;
    v0192 = stack[-3];
    if (v0192 == nil) goto v0197;
    v0192 = stack[-3];
    v0192 = qcar(v0192);
    v0192 = qcdr(v0192);
    v0192 = ncons(v0192);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-9];
    stack[-1] = v0192;
    stack[-2] = v0192;
    goto v0066;

v0066:
    v0192 = stack[-3];
    v0192 = qcdr(v0192);
    stack[-3] = v0192;
    v0192 = stack[-3];
    if (v0192 == nil) goto v0198;
    stack[0] = stack[-1];
    v0192 = stack[-3];
    v0192 = qcar(v0192);
    v0192 = qcdr(v0192);
    v0192 = ncons(v0192);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-9];
    v0192 = Lrplacd(nil, stack[0], v0192);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-9];
    v0192 = stack[-1];
    v0192 = qcdr(v0192);
    stack[-1] = v0192;
    goto v0066;

v0198:
    v0192 = stack[-2];
    goto v0065;

v0065:
    stack[-3] = v0192;
    goto v0078;

v0078:
    v0192 = stack[-7];
    stack[-1] = v0192;
    goto v0139;

v0139:
    v0192 = stack[-1];
    if (v0192 == nil) goto v0138;
    v0192 = stack[-1];
    v0192 = qcar(v0192);
    stack[0] = v0192;
    v0192 = stack[0];
    fn = elt(env, 13); // no!-side!-effectp
    v0192 = (*qfn1(fn))(qenv(fn), v0192);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-9];
    if (!(v0192 == nil)) goto v0199;
    v0192 = stack[-3];
    v0193 = qcar(v0192);
    v0192 = stack[-8];
    fn = elt(env, 14); // one!-entryp
    v0192 = (*qfn2(fn))(qenv(fn), v0193, v0192);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-9];
    if (!(v0192 == nil)) goto v0199;
    stack[-2] = stack[-6];
    v0192 = stack[-3];
    v0193 = qcar(v0192);
    v0192 = stack[0];
    v0192 = cons(v0193, v0192);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-9];
    fn = elt(env, 15); // aconc
    v0192 = (*qfn2(fn))(qenv(fn), stack[-2], v0192);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-9];
    stack[-6] = v0192;
    goto v0200;

v0200:
    v0192 = stack[-3];
    v0192 = qcdr(v0192);
    stack[-3] = v0192;
    v0192 = stack[-1];
    v0192 = qcdr(v0192);
    stack[-1] = v0192;
    goto v0139;

v0199:
    v0192 = stack[-3];
    v0193 = qcar(v0192);
    v0192 = stack[0];
    v0192 = cons(v0193, v0192);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-9];
    v0193 = ncons(v0192);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-9];
    v0192 = stack[-8];
    fn = elt(env, 12); // subla!-q
    v0192 = (*qfn2(fn))(qenv(fn), v0193, v0192);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-9];
    stack[-8] = v0192;
    goto v0200;

v0138:
    v0192 = stack[-6];
    if (v0192 == nil) goto v0201;
    stack[-4] = elt(env, 7); // lambda
    v0192 = stack[-6];
    stack[-3] = v0192;
    v0192 = stack[-3];
    if (v0192 == nil) goto v0202;
    v0192 = stack[-3];
    v0192 = qcar(v0192);
    v0192 = qcar(v0192);
    v0192 = ncons(v0192);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-9];
    stack[-1] = v0192;
    stack[-2] = v0192;
    goto v0203;

v0203:
    v0192 = stack[-3];
    v0192 = qcdr(v0192);
    stack[-3] = v0192;
    v0192 = stack[-3];
    if (v0192 == nil) goto v0204;
    stack[0] = stack[-1];
    v0192 = stack[-3];
    v0192 = qcar(v0192);
    v0192 = qcar(v0192);
    v0192 = ncons(v0192);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-9];
    v0192 = Lrplacd(nil, stack[0], v0192);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-9];
    v0192 = stack[-1];
    v0192 = qcdr(v0192);
    stack[-1] = v0192;
    goto v0203;

v0204:
    v0192 = stack[-2];
    v0193 = v0192;
    goto v0205;

v0205:
    v0192 = stack[-8];
    stack[-3] = list3(stack[-4], v0193, v0192);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-9];
    v0192 = stack[-6];
    stack[-4] = v0192;
    v0192 = stack[-4];
    if (v0192 == nil) goto v0206;
    v0192 = stack[-4];
    v0192 = qcar(v0192);
    v0192 = qcdr(v0192);
    v0192 = ncons(v0192);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-9];
    stack[-1] = v0192;
    stack[-2] = v0192;
    goto v0207;

v0207:
    v0192 = stack[-4];
    v0192 = qcdr(v0192);
    stack[-4] = v0192;
    v0192 = stack[-4];
    if (v0192 == nil) goto v0208;
    stack[0] = stack[-1];
    v0192 = stack[-4];
    v0192 = qcar(v0192);
    v0192 = qcdr(v0192);
    v0192 = ncons(v0192);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-9];
    v0192 = Lrplacd(nil, stack[0], v0192);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-9];
    v0192 = stack[-1];
    v0192 = qcdr(v0192);
    stack[-1] = v0192;
    goto v0207;

v0208:
    v0192 = stack[-2];
    goto v0209;

v0209:
    v0192 = cons(stack[-3], v0192);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-9];
    stack[0] = v0192;
    v0192 = stack[0];
    goto v0003;

v0003:
    qvalue(elt(env, 1)) = stack[-5]; // inlineinfo
    { popv(10); return onevalue(v0192); }

v0206:
    v0192 = qvalue(elt(env, 5)); // nil
    goto v0209;

v0202:
    v0192 = qvalue(elt(env, 5)); // nil
    v0193 = v0192;
    goto v0205;

v0201:
    v0192 = stack[-8];
    goto v0003;

v0197:
    v0192 = qvalue(elt(env, 5)); // nil
    goto v0065;

v0036:
    v0192 = qvalue(elt(env, 5)); // nil
    goto v0030;

v0196:
    v0193 = stack[-3];
    v0192 = stack[-7];
    fn = elt(env, 16); // pair
    v0193 = (*qfn2(fn))(qenv(fn), v0193, v0192);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-9];
    v0192 = stack[-8];
    fn = elt(env, 12); // subla!-q
    v0192 = (*qfn2(fn))(qenv(fn), v0193, v0192);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-9];
    goto v0003;
// error exit handlers
v0195:
    env = stack[-9];
    qvalue(elt(env, 1)) = stack[-5]; // inlineinfo
    popv(10);
    return nil;
}



// Code for extract_vars

static LispObject CC_extract_vars(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0100, v0024;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for extract_vars");
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
    goto v0064;

v0064:
    v0100 = stack[0];
    if (v0100 == nil) goto v0002;
    v0100 = stack[0];
    v0100 = qcar(v0100);
    fn = elt(env, 2); // raiseind!:
    v0024 = (*qfn1(fn))(qenv(fn), v0100);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-2];
    v0100 = elt(env, 1); // variable
    v0100 = Lflagp(nil, v0024, v0100);
    env = stack[-2];
    if (v0100 == nil) goto v0212;
    v0100 = stack[0];
    v0024 = qcar(v0100);
    v0100 = stack[-1];
    v0100 = cons(v0024, v0100);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-2];
    stack[-1] = v0100;
    v0100 = stack[0];
    v0100 = qcdr(v0100);
    stack[0] = v0100;
    goto v0064;

v0212:
    v0100 = stack[0];
    v0100 = qcdr(v0100);
    stack[0] = v0100;
    goto v0064;

v0002:
    v0100 = stack[-1];
    {
        popv(3);
        fn = elt(env, 3); // nreverse
        return (*qfn1(fn))(qenv(fn), v0100);
    }
// error exit handlers
v0102:
    popv(3);
    return nil;
}



// Code for gigcdsq

static LispObject CC_gigcdsq(LispObject env,
                         LispObject v0000, LispObject v0011)
{
    LispObject nil = C_nil;
    LispObject v0055, v0056;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gigcdsq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0011,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0011);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0011;
    stack[-1] = v0000;
// end of prologue
    v0055 = stack[-1];
    if (v0055 == nil) goto v0015;
    v0056 = stack[0];
    v0055 = (LispObject)1; // 0
    fn = elt(env, 2); // giintgcd
    v0055 = (*qfn2(fn))(qenv(fn), v0056, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0018;
    env = stack[-3];
    stack[-2] = v0055;
    v0056 = stack[-2];
    v0055 = (LispObject)17; // 1
    if (v0056 == v0055) goto v0051;
    v0056 = stack[-1];
    v0055 = stack[-2];
    fn = elt(env, 2); // giintgcd
    v0056 = (*qfn2(fn))(qenv(fn), v0056, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0018;
    env = stack[-3];
    stack[-2] = v0056;
    v0055 = (LispObject)17; // 1
    v0055 = Lneq(nil, v0056, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0018;
    env = stack[-3];
    goto v0148;

v0148:
    if (v0055 == nil) goto v0015;
    v0056 = stack[-1];
    v0055 = stack[-2];
    fn = elt(env, 3); // quotf
    v0055 = (*qfn2(fn))(qenv(fn), v0056, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0018;
    env = stack[-3];
    stack[-1] = v0055;
    v0056 = stack[0];
    v0055 = stack[-2];
    fn = elt(env, 3); // quotf
    v0055 = (*qfn2(fn))(qenv(fn), v0056, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0018;
    stack[0] = v0055;
    goto v0015;

v0015:
    v0056 = stack[-1];
    v0055 = stack[0];
    popv(4);
    return cons(v0056, v0055);

v0051:
    v0055 = qvalue(elt(env, 1)); // nil
    goto v0148;
// error exit handlers
v0018:
    popv(4);
    return nil;
}



// Code for pasf_coeflst

static LispObject CC_pasf_coeflst(LispObject env,
                         LispObject v0000, LispObject v0011)
{
    LispObject nil = C_nil;
    LispObject v0215, v0092, v0216;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pasf_coeflst");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0011,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0011);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0011;
    stack[-2] = v0000;
// end of prologue
    stack[0] = nil;
    v0215 = stack[-1];
    v0215 = ncons(v0215);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    env = stack[-4];
    fn = elt(env, 3); // setkorder
    v0215 = (*qfn1(fn))(qenv(fn), v0215);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    env = stack[-4];
    stack[-3] = v0215;
    v0215 = stack[-2];
    fn = elt(env, 4); // reorder
    v0215 = (*qfn1(fn))(qenv(fn), v0215);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    env = stack[-4];
    stack[-2] = v0215;
    goto v0129;

v0129:
    v0215 = stack[-2];
    if (!consp(v0215)) goto v0146;
    v0215 = stack[-2];
    v0215 = qcar(v0215);
    v0215 = (consp(v0215) ? nil : lisp_true);
    goto v0084;

v0084:
    if (v0215 == nil) goto v0217;
    v0215 = qvalue(elt(env, 2)); // nil
    goto v0103;

v0103:
    if (v0215 == nil) goto v0128;
    v0215 = stack[-2];
    v0215 = qcar(v0215);
    v0216 = qcdr(v0215);
    v0215 = stack[-2];
    v0215 = qcar(v0215);
    v0215 = qcar(v0215);
    v0092 = qcdr(v0215);
    v0215 = stack[0];
    v0215 = acons(v0216, v0092, v0215);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    env = stack[-4];
    stack[0] = v0215;
    v0215 = stack[-2];
    v0215 = qcdr(v0215);
    stack[-2] = v0215;
    goto v0129;

v0128:
    v0215 = stack[-3];
    fn = elt(env, 3); // setkorder
    v0215 = (*qfn1(fn))(qenv(fn), v0215);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    env = stack[-4];
    v0215 = stack[-2];
    fn = elt(env, 5); // negf
    v0216 = (*qfn1(fn))(qenv(fn), v0215);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    env = stack[-4];
    v0092 = (LispObject)1; // 0
    v0215 = stack[0];
    v0215 = acons(v0216, v0092, v0215);
    nil = C_nil;
    if (exception_pending()) goto v0125;
        popv(5);
        return Lnreverse(nil, v0215);

v0217:
    v0215 = stack[-2];
    v0215 = qcar(v0215);
    v0215 = qcar(v0215);
    v0092 = qcar(v0215);
    v0215 = stack[-1];
    v0215 = (v0092 == v0215 ? lisp_true : nil);
    goto v0103;

v0146:
    v0215 = qvalue(elt(env, 1)); // t
    goto v0084;
// error exit handlers
v0125:
    popv(5);
    return nil;
}



// Code for matrixml

static LispObject CC_matrixml(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0025, v0101;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for matrixml");
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
    v0025 = stack[0];
    v0101 = Llength(nil, v0025);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-1];
    v0025 = (LispObject)17; // 1
    if (v0101 == v0025) goto v0061;
    v0025 = elt(env, 1); // "<matrix>"
    fn = elt(env, 4); // printout
    v0025 = (*qfn1(fn))(qenv(fn), v0025);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-1];
    v0101 = qvalue(elt(env, 2)); // indent
    v0025 = (LispObject)49; // 3
    v0025 = plus2(v0101, v0025);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-1];
    qvalue(elt(env, 2)) = v0025; // indent
    v0025 = stack[0];
    fn = elt(env, 5); // matrix_rows
    v0025 = (*qfn1(fn))(qenv(fn), v0025);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-1];
    v0101 = qvalue(elt(env, 2)); // indent
    v0025 = (LispObject)49; // 3
    v0025 = difference2(v0101, v0025);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-1];
    qvalue(elt(env, 2)) = v0025; // indent
    v0025 = elt(env, 3); // "</matrix>"
    fn = elt(env, 4); // printout
    v0025 = (*qfn1(fn))(qenv(fn), v0025);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    goto v0064;

v0064:
    v0025 = nil;
    { popv(2); return onevalue(v0025); }

v0061:
    v0025 = stack[0];
    fn = elt(env, 6); // vectorml
    v0025 = (*qfn1(fn))(qenv(fn), v0025);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    goto v0064;
// error exit handlers
v0060:
    popv(2);
    return nil;
}



// Code for ps!:arg!-values

static LispObject CC_psTargKvalues(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0221, v0222, v0223;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ps:arg-values");
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
    v0222 = v0000;
// end of prologue
    v0221 = v0222;
    stack[-4] = qcar(v0221);
    v0221 = v0222;
    v0221 = qcdr(v0221);
    stack[-3] = v0221;
    v0221 = stack[-3];
    if (v0221 == nil) goto v0052;
    v0221 = stack[-3];
    v0221 = qcar(v0221);
    v0223 = v0221;
    v0221 = v0223;
    if (!consp(v0221)) goto v0224;
    v0221 = v0223;
    v0222 = qcar(v0221);
    v0221 = elt(env, 3); // !:ps!:
    if (v0222 == v0221) goto v0048;
    v0221 = v0223;
    v0221 = qcar(v0221);
    if (!symbolp(v0221)) v0221 = nil;
    else { v0221 = qfastgets(v0221);
           if (v0221 != nil) { v0221 = elt(v0221, 8); // dname
#ifdef RECORD_GET
             if (v0221 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v0221 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v0221 == SPID_NOPROP) v0221 = nil; }}
#endif
    goto v0211;

v0211:
    if (v0221 == nil) goto v0099;
    v0221 = v0223;
    goto v0021;

v0021:
    v0221 = ncons(v0221);
    nil = C_nil;
    if (exception_pending()) goto v0181;
    env = stack[-5];
    stack[-1] = v0221;
    stack[-2] = v0221;
    goto v0129;

v0129:
    v0221 = stack[-3];
    v0221 = qcdr(v0221);
    stack[-3] = v0221;
    v0221 = stack[-3];
    if (v0221 == nil) goto v0215;
    stack[0] = stack[-1];
    v0221 = stack[-3];
    v0221 = qcar(v0221);
    v0223 = v0221;
    v0221 = v0223;
    if (!consp(v0221)) goto v0005;
    v0221 = v0223;
    v0222 = qcar(v0221);
    v0221 = elt(env, 3); // !:ps!:
    if (v0222 == v0221) goto v0225;
    v0221 = v0223;
    v0221 = qcar(v0221);
    if (!symbolp(v0221)) v0221 = nil;
    else { v0221 = qfastgets(v0221);
           if (v0221 != nil) { v0221 = elt(v0221, 8); // dname
#ifdef RECORD_GET
             if (v0221 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v0221 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v0221 == SPID_NOPROP) v0221 = nil; }}
#endif
    goto v0006;

v0006:
    if (v0221 == nil) goto v0226;
    v0221 = v0223;
    goto v0196;

v0196:
    v0221 = ncons(v0221);
    nil = C_nil;
    if (exception_pending()) goto v0181;
    env = stack[-5];
    v0221 = Lrplacd(nil, stack[0], v0221);
    nil = C_nil;
    if (exception_pending()) goto v0181;
    env = stack[-5];
    v0221 = stack[-1];
    v0221 = qcdr(v0221);
    stack[-1] = v0221;
    goto v0129;

v0226:
    v0221 = v0223;
    v0221 = Lconsp(nil, v0221);
    env = stack[-5];
    if (v0221 == nil) goto v0097;
    v0221 = v0223;
    v0222 = qcar(v0221);
    v0221 = elt(env, 3); // !:ps!:
    if (!(v0222 == v0221)) goto v0097;
    v0221 = v0223;
    fn = elt(env, 4); // ps!:value
    v0221 = (*qfn1(fn))(qenv(fn), v0221);
    nil = C_nil;
    if (exception_pending()) goto v0181;
    env = stack[-5];
    goto v0196;

v0097:
    v0221 = v0223;
    v0221 = CC_psTargKvalues(env, v0221);
    nil = C_nil;
    if (exception_pending()) goto v0181;
    env = stack[-5];
    goto v0196;

v0225:
    v0221 = qvalue(elt(env, 1)); // nil
    goto v0006;

v0005:
    v0221 = qvalue(elt(env, 2)); // t
    goto v0006;

v0215:
    v0221 = stack[-2];
    goto v0061;

v0061:
    {
        LispObject v0112 = stack[-4];
        popv(6);
        return cons(v0112, v0221);
    }

v0099:
    v0221 = v0223;
    v0221 = Lconsp(nil, v0221);
    env = stack[-5];
    if (v0221 == nil) goto v0056;
    v0221 = v0223;
    v0222 = qcar(v0221);
    v0221 = elt(env, 3); // !:ps!:
    if (!(v0222 == v0221)) goto v0056;
    v0221 = v0223;
    fn = elt(env, 4); // ps!:value
    v0221 = (*qfn1(fn))(qenv(fn), v0221);
    nil = C_nil;
    if (exception_pending()) goto v0181;
    env = stack[-5];
    goto v0021;

v0056:
    v0221 = v0223;
    v0221 = CC_psTargKvalues(env, v0221);
    nil = C_nil;
    if (exception_pending()) goto v0181;
    env = stack[-5];
    goto v0021;

v0048:
    v0221 = qvalue(elt(env, 1)); // nil
    goto v0211;

v0224:
    v0221 = qvalue(elt(env, 2)); // t
    goto v0211;

v0052:
    v0221 = qvalue(elt(env, 1)); // nil
    goto v0061;
// error exit handlers
v0181:
    popv(6);
    return nil;
}



// Code for diford

static LispObject CC_diford(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0061;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for diford");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0061 = v0000;
// end of prologue
    v0061 = qcdr(v0061);
    v0061 = qcdr(v0061);
    {
        fn = elt(env, 1); // lengthn
        return (*qfn1(fn))(qenv(fn), v0061);
    }
}



// Code for specrd!:times

static LispObject CC_specrdTtimes(LispObject env,
                         LispObject v0000, LispObject v0011)
{
    LispObject nil = C_nil;
    LispObject v0091, v0125;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for specrd:times");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0011,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0011);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0011;
    stack[-1] = v0000;
// end of prologue
    stack[-2] = nil;
    v0091 = stack[-1];
    fn = elt(env, 3); // add_minus
    v0091 = (*qfn1(fn))(qenv(fn), v0091);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[-3];
    stack[-1] = v0091;
    v0091 = stack[0];
    fn = elt(env, 3); // add_minus
    v0091 = (*qfn1(fn))(qenv(fn), v0091);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[-3];
    stack[0] = v0091;
    v0125 = stack[-1];
    v0091 = elt(env, 1); // minus
    if (!consp(v0125)) goto v0099;
    v0125 = qcar(v0125);
    if (!(v0125 == v0091)) goto v0099;
    v0091 = stack[-1];
    v0091 = qcdr(v0091);
    v0091 = qcar(v0091);
    stack[-1] = v0091;
    v0091 = qvalue(elt(env, 2)); // t
    stack[-2] = v0091;
    goto v0099;

v0099:
    v0125 = stack[0];
    v0091 = elt(env, 1); // minus
    if (!consp(v0125)) goto v0053;
    v0125 = qcar(v0125);
    if (!(v0125 == v0091)) goto v0053;
    v0091 = stack[0];
    v0091 = qcdr(v0091);
    v0091 = qcar(v0091);
    stack[0] = v0091;
    v0091 = stack[-2];
    v0091 = (v0091 == nil ? lisp_true : nil);
    stack[-2] = v0091;
    goto v0053;

v0053:
    v0091 = stack[-1];
    if (!(!consp(v0091))) goto v0102;
    v0091 = stack[-1];
    v0091 = Lfloat(nil, v0091);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[-3];
    fn = elt(env, 4); // mkround
    v0091 = (*qfn1(fn))(qenv(fn), v0091);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[-3];
    stack[-1] = v0091;
    goto v0102;

v0102:
    v0091 = stack[0];
    if (!(!consp(v0091))) goto v0081;
    v0091 = stack[0];
    v0091 = Lfloat(nil, v0091);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[-3];
    fn = elt(env, 4); // mkround
    v0091 = (*qfn1(fn))(qenv(fn), v0091);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[-3];
    stack[0] = v0091;
    goto v0081;

v0081:
    v0091 = stack[-2];
    if (v0091 == nil) goto v0213;
    stack[-2] = elt(env, 1); // minus
    v0125 = stack[-1];
    v0091 = stack[0];
    fn = elt(env, 5); // rd!:times
    v0091 = (*qfn2(fn))(qenv(fn), v0125, v0091);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    {
        LispObject v0230 = stack[-2];
        popv(4);
        return list2(v0230, v0091);
    }

v0213:
    v0125 = stack[-1];
    v0091 = stack[0];
    {
        popv(4);
        fn = elt(env, 5); // rd!:times
        return (*qfn2(fn))(qenv(fn), v0125, v0091);
    }
// error exit handlers
v0035:
    popv(4);
    return nil;
}



// Code for remdiff

static LispObject CC_remdiff(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0005, v0007;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for remdiff");
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
    stack[-1] = v0000;
// end of prologue
    v0005 = stack[-1];
    if (symbolp(v0005)) { LispObject res = stack[-1]; popv(6); return onevalue(res); }
    v0005 = stack[-1];
    fn = elt(env, 5); // constp
    v0005 = (*qfn1(fn))(qenv(fn), v0005);
    nil = C_nil;
    if (exception_pending()) goto v0234;
    env = stack[-5];
    if (!(v0005 == nil)) { LispObject res = stack[-1]; popv(6); return onevalue(res); }
    v0005 = stack[-1];
    v0007 = qcar(v0005);
    v0005 = elt(env, 1); // difference
    if (v0007 == v0005) goto v0053;
    v0005 = stack[-1];
    stack[-4] = qcar(v0005);
    v0005 = stack[-1];
    v0005 = qcdr(v0005);
    stack[-3] = v0005;
    v0005 = stack[-3];
    if (v0005 == nil) goto v0043;
    v0005 = stack[-3];
    v0005 = qcar(v0005);
    v0005 = CC_remdiff(env, v0005);
    nil = C_nil;
    if (exception_pending()) goto v0234;
    env = stack[-5];
    v0005 = ncons(v0005);
    nil = C_nil;
    if (exception_pending()) goto v0234;
    env = stack[-5];
    stack[-1] = v0005;
    stack[-2] = v0005;
    goto v0127;

v0127:
    v0005 = stack[-3];
    v0005 = qcdr(v0005);
    stack[-3] = v0005;
    v0005 = stack[-3];
    if (v0005 == nil) goto v0216;
    stack[0] = stack[-1];
    v0005 = stack[-3];
    v0005 = qcar(v0005);
    v0005 = CC_remdiff(env, v0005);
    nil = C_nil;
    if (exception_pending()) goto v0234;
    env = stack[-5];
    v0005 = ncons(v0005);
    nil = C_nil;
    if (exception_pending()) goto v0234;
    env = stack[-5];
    v0005 = Lrplacd(nil, stack[0], v0005);
    nil = C_nil;
    if (exception_pending()) goto v0234;
    env = stack[-5];
    v0005 = stack[-1];
    v0005 = qcdr(v0005);
    stack[-1] = v0005;
    goto v0127;

v0216:
    v0005 = stack[-2];
    goto v0047;

v0047:
    {
        LispObject v0235 = stack[-4];
        popv(6);
        return cons(v0235, v0005);
    }

v0043:
    v0005 = qvalue(elt(env, 4)); // nil
    goto v0047;

v0053:
    stack[-3] = elt(env, 2); // plus
    v0005 = stack[-1];
    v0005 = qcdr(v0005);
    v0005 = qcar(v0005);
    stack[-2] = CC_remdiff(env, v0005);
    nil = C_nil;
    if (exception_pending()) goto v0234;
    env = stack[-5];
    stack[0] = elt(env, 3); // minus
    v0005 = stack[-1];
    v0005 = qcdr(v0005);
    v0005 = qcdr(v0005);
    v0005 = qcar(v0005);
    v0005 = CC_remdiff(env, v0005);
    nil = C_nil;
    if (exception_pending()) goto v0234;
    env = stack[-5];
    v0005 = list2(stack[0], v0005);
    nil = C_nil;
    if (exception_pending()) goto v0234;
    env = stack[-5];
    v0005 = list3(stack[-3], stack[-2], v0005);
    nil = C_nil;
    if (exception_pending()) goto v0234;
    { popv(6); return onevalue(v0005); }
// error exit handlers
v0234:
    popv(6);
    return nil;
}



// Code for remove_least_item

static LispObject CC_remove_least_item(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0146, v0053;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for remove_least_item");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0146 = v0000;
// end of prologue

v0106:
    v0053 = v0146;
    v0053 = qcdr(v0053);
    if (v0053 == nil) goto v0062;
    v0053 = v0146;
    v0053 = qcdr(v0053);
    v0053 = qcar(v0053);
    v0053 = qcdr(v0053);
    if (v0053 == nil) goto v0026;
    v0146 = qcdr(v0146);
    v0146 = qcar(v0146);
    goto v0106;

v0026:
    {
        fn = elt(env, 2); // remove_root_item
        return (*qfn1(fn))(qenv(fn), v0146);
    }

v0062:
    v0146 = elt(env, 1); // "How did we get here?"
    {
        fn = elt(env, 3); // rederr
        return (*qfn1(fn))(qenv(fn), v0146);
    }
}



// Code for nspaces

static LispObject CC_nspaces(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0100, v0024, v0025;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for nspaces");
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
    v0100 = (LispObject)17; // 1
    stack[0] = v0100;
    goto v0027;

v0027:
    v0024 = stack[-1];
    v0100 = stack[0];
    v0100 = difference2(v0024, v0100);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-3];
    v0100 = Lminusp(nil, v0100);
    env = stack[-3];
    if (v0100 == nil) goto v0084;
    v0100 = stack[-2];
    v0100 = Lcompress(nil, v0100);
    nil = C_nil;
    if (exception_pending()) goto v0050;
        popv(4);
        return Lintern(nil, v0100);

v0084:
    v0025 = elt(env, 2); // !!
    v0024 = elt(env, 3); // ! 
    v0100 = stack[-2];
    v0100 = list2star(v0025, v0024, v0100);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-3];
    stack[-2] = v0100;
    v0100 = stack[0];
    v0100 = add1(v0100);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-3];
    stack[0] = v0100;
    goto v0027;
// error exit handlers
v0050:
    popv(4);
    return nil;
}



// Code for listminimize

static LispObject CC_listminimize(LispObject env,
                         LispObject v0000, LispObject v0011)
{
    LispObject nil = C_nil;
    LispObject v0085, v0086, v0084;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for listminimize");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0011,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0011);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
// copy arguments values to proper place
    v0085 = v0011;
    v0086 = v0000;
// end of prologue
    v0084 = v0086;
    if (v0084 == nil) goto v0064;
    v0084 = qvalue(elt(env, 1)); // nil
    fn = elt(env, 2); // cali!=min
    v0085 = (*qfnn(fn))(qenv(fn), 3, v0084, v0086, v0085);
    errexit();
        return Lreverse(nil, v0085);

v0064:
    v0085 = qvalue(elt(env, 1)); // nil
    return onevalue(v0085);
}



// Code for mk_dummy_ids

static LispObject CC_mk_dummy_ids(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0024, v0025;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mk_dummy_ids");
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
    v0024 = v0000;
// end of prologue
    v0025 = v0024;
    v0025 = qcar(v0025);
    v0024 = qcdr(v0024);
    v0024 = qcar(v0024);
    fn = elt(env, 4); // intersection
    v0024 = (*qfn2(fn))(qenv(fn), v0025, v0024);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-1];
    fn = elt(env, 5); // clean_numid
    v0024 = (*qfn1(fn))(qenv(fn), v0024);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-1];
    stack[0] = v0024;
    v0025 = stack[0];
    v0024 = elt(env, 1); // dummy
    v0024 = Lflag(nil, v0025, v0024);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-1];
    v0025 = stack[0];
    v0024 = elt(env, 2); // reserved
    v0024 = Lflag(nil, v0025, v0024);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-1];
    v0025 = stack[0];
    v0024 = qvalue(elt(env, 3)); // dummy_id!*
    fn = elt(env, 6); // union
    v0024 = (*qfn2(fn))(qenv(fn), v0025, v0024);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-1];
    qvalue(elt(env, 3)) = v0024; // dummy_id!*
    v0024 = nil;
    { popv(2); return onevalue(v0024); }
// error exit handlers
v0102:
    popv(2);
    return nil;
}



// Code for mchsarg

static LispObject CC_mchsarg(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0069, v0070;
    LispObject fn;
    LispObject v0010, v0011, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "mchsarg");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0011 = va_arg(aa, LispObject);
    v0010 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mchsarg");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0010,v0011,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0011,v0010);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[-5] = v0010;
    stack[-6] = v0011;
    stack[-1] = v0000;
// end of prologue
    v0069 = stack[-6];
    fn = elt(env, 4); // mtp
    v0069 = (*qfn1(fn))(qenv(fn), v0069);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-8];
    if (v0069 == nil) goto v0092;
    v0070 = stack[-5];
    v0069 = elt(env, 1); // times
    if (v0070 == v0069) goto v0084;
    v0069 = qvalue(elt(env, 2)); // t
    goto v0128;

v0128:
    if (v0069 == nil) goto v0092;
    v0069 = stack[-6];
    fn = elt(env, 5); // noncomperm
    v0069 = (*qfn1(fn))(qenv(fn), v0069);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-8];
    stack[-4] = v0069;
    v0069 = stack[-4];
    if (v0069 == nil) goto v0045;
    v0069 = stack[-4];
    v0069 = qcar(v0069);
    v0070 = v0069;
    v0069 = stack[-1];
    fn = elt(env, 6); // pair
    v0069 = (*qfn2(fn))(qenv(fn), v0070, v0069);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-8];
    v0069 = ncons(v0069);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-8];
    stack[-2] = v0069;
    stack[-3] = v0069;
    goto v0224;

v0224:
    v0069 = stack[-4];
    v0069 = qcdr(v0069);
    stack[-4] = v0069;
    v0069 = stack[-4];
    if (v0069 == nil) goto v0190;
    stack[0] = stack[-2];
    v0069 = stack[-4];
    v0069 = qcar(v0069);
    v0070 = v0069;
    v0069 = stack[-1];
    fn = elt(env, 6); // pair
    v0069 = (*qfn2(fn))(qenv(fn), v0070, v0069);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-8];
    v0069 = ncons(v0069);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-8];
    v0069 = Lrplacd(nil, stack[0], v0069);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-8];
    v0069 = stack[-2];
    v0069 = qcdr(v0069);
    stack[-2] = v0069;
    goto v0224;

v0190:
    v0069 = stack[-3];
    goto v0061;

v0061:
    {
        popv(9);
        fn = elt(env, 7); // reversip!*
        return (*qfn1(fn))(qenv(fn), v0069);
    }

v0045:
    v0069 = qvalue(elt(env, 3)); // nil
    goto v0061;

v0092:
    v0069 = stack[-1];
    fn = elt(env, 5); // noncomperm
    v0069 = (*qfn1(fn))(qenv(fn), v0069);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-8];
    stack[-7] = v0069;
    goto v0188;

v0188:
    v0069 = stack[-7];
    if (v0069 == nil) goto v0076;
    v0069 = stack[-7];
    v0069 = qcar(v0069);
    stack[-1] = v0069;
    stack[0] = stack[-6];
    v0069 = qvalue(elt(env, 3)); // nil
    v0070 = ncons(v0069);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-8];
    v0069 = stack[-5];
    fn = elt(env, 8); // mcharg2
    v0069 = (*qfnn(fn))(qenv(fn), 4, stack[-1], stack[0], v0070, v0069);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-8];
    stack[-4] = v0069;
    v0069 = stack[-4];
    fn = elt(env, 9); // lastpair
    v0069 = (*qfn1(fn))(qenv(fn), v0069);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-8];
    stack[-3] = v0069;
    v0069 = stack[-7];
    v0069 = qcdr(v0069);
    stack[-7] = v0069;
    v0069 = stack[-3];
    if (!consp(v0069)) goto v0188;
    else goto v0013;

v0013:
    v0069 = stack[-7];
    if (v0069 == nil) goto v0039;
    stack[-2] = stack[-3];
    v0069 = stack[-7];
    v0069 = qcar(v0069);
    stack[-1] = v0069;
    stack[0] = stack[-6];
    v0069 = qvalue(elt(env, 3)); // nil
    v0070 = ncons(v0069);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-8];
    v0069 = stack[-5];
    fn = elt(env, 8); // mcharg2
    v0069 = (*qfnn(fn))(qenv(fn), 4, stack[-1], stack[0], v0070, v0069);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-8];
    v0069 = Lrplacd(nil, stack[-2], v0069);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-8];
    v0069 = stack[-3];
    fn = elt(env, 9); // lastpair
    v0069 = (*qfn1(fn))(qenv(fn), v0069);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-8];
    stack[-3] = v0069;
    v0069 = stack[-7];
    v0069 = qcdr(v0069);
    stack[-7] = v0069;
    goto v0013;

v0039:
    v0069 = stack[-4];
    goto v0061;

v0076:
    v0069 = qvalue(elt(env, 3)); // nil
    goto v0061;

v0084:
    v0069 = stack[-1];
    fn = elt(env, 10); // noncomfree
    v0069 = (*qfn1(fn))(qenv(fn), v0069);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-8];
    goto v0128;
// error exit handlers
v0242:
    popv(9);
    return nil;
}



// Code for createtriple

static LispObject CC_createtriple(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0189, v0081, v0241;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for createtriple");
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
    stack[0] = v0000;
// end of prologue
    v0189 = (LispObject)49; // 3
    v0189 = Lmkvect(nil, v0189);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-3];
    stack[-2] = v0189;
    v0241 = stack[-2];
    v0081 = (LispObject)1; // 0
    v0189 = qvalue(elt(env, 1)); // fluidbibasistripleid
    *(LispObject *)((char *)v0241 + (CELL-TAG_VECTOR) + ((int32_t)v0081/(16/CELL))) = v0189;
    v0241 = stack[-2];
    v0081 = (LispObject)17; // 1
    v0189 = stack[0];
    *(LispObject *)((char *)v0241 + (CELL-TAG_VECTOR) + ((int32_t)v0081/(16/CELL))) = v0189;
    v0241 = stack[-2];
    v0081 = (LispObject)33; // 2
    v0189 = qvalue(elt(env, 1)); // fluidbibasistripleid
    *(LispObject *)((char *)v0241 + (CELL-TAG_VECTOR) + ((int32_t)v0081/(16/CELL))) = v0189;
    stack[-1] = stack[-2];
    stack[0] = (LispObject)49; // 3
    v0189 = qvalue(elt(env, 2)); // nil
    v0189 = ncons(v0189);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-3];
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v0189;
    v0189 = qvalue(elt(env, 1)); // fluidbibasistripleid
    v0189 = (LispObject)((int32_t)(v0189) + 0x10);
    qvalue(elt(env, 1)) = v0189; // fluidbibasistripleid
    { LispObject res = stack[-2]; popv(4); return onevalue(res); }
// error exit handlers
v0047:
    popv(4);
    return nil;
}



// Code for totalcompareconstants

static LispObject CC_totalcompareconstants(LispObject env,
                         LispObject v0000, LispObject v0011)
{
    LispObject nil = C_nil;
    LispObject v0141, v0244, v0242;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for totalcompareconstants");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0011,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0011);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0011;
    stack[-2] = v0000;
// end of prologue
    v0244 = stack[-2];
    v0141 = stack[-1];
    if (equal(v0244, v0141)) goto v0064;
    v0141 = stack[-2];
    if (!consp(v0141)) goto v0147;
    v0141 = stack[-2];
    v0141 = qcar(v0141);
    v0141 = (consp(v0141) ? nil : lisp_true);
    goto v0033;

v0033:
    if (v0141 == nil) goto v0027;
    v0141 = stack[-1];
    if (!consp(v0141)) goto v0224;
    v0141 = stack[-1];
    v0141 = qcar(v0141);
    v0141 = (consp(v0141) ? nil : lisp_true);
    goto v0211;

v0211:
    if (v0141 == nil) goto v0056;
    v0141 = stack[-2];
    if (v0141 == nil) goto v0048;
    v0141 = stack[-2];
    v0244 = v0141;
    goto v0019;

v0019:
    v0141 = stack[-1];
    if (v0141 == nil) goto v0079;
    v0141 = stack[-1];
    goto v0189;

v0189:
    v0141 = (LispObject)lessp2(v0244, v0141);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    v0141 = v0141 ? lisp_true : nil;
    env = stack[-4];
    if (v0141 == nil) goto v0044;
    v0141 = elt(env, 3); // less
    { popv(5); return onevalue(v0141); }

v0044:
    v0141 = elt(env, 4); // greater
    { popv(5); return onevalue(v0141); }

v0079:
    v0141 = (LispObject)1; // 0
    goto v0189;

v0048:
    v0141 = (LispObject)1; // 0
    v0244 = v0141;
    goto v0019;

v0056:
    v0141 = elt(env, 3); // less
    { popv(5); return onevalue(v0141); }

v0224:
    v0141 = qvalue(elt(env, 2)); // t
    goto v0211;

v0027:
    v0141 = stack[-1];
    if (!consp(v0141)) goto v0213;
    v0141 = stack[-1];
    v0141 = qcar(v0141);
    v0141 = (consp(v0141) ? nil : lisp_true);
    goto v0059;

v0059:
    if (v0141 == nil) goto v0013;
    v0141 = elt(env, 4); // greater
    { popv(5); return onevalue(v0141); }

v0013:
    stack[-3] = qvalue(elt(env, 5)); // wukord!*
    qvalue(elt(env, 5)) = nil; // wukord!*
    stack[0] = qvalue(elt(env, 6)); // wuvarlist!*
    qvalue(elt(env, 6)) = nil; // wuvarlist!*
    v0141 = stack[-2];
    v0141 = qcar(v0141);
    v0141 = qcar(v0141);
    v0244 = qcar(v0141);
    v0141 = stack[-1];
    v0141 = qcar(v0141);
    v0141 = qcar(v0141);
    v0141 = qcar(v0141);
    fn = elt(env, 7); // symbollessp
    v0141 = (*qfn2(fn))(qenv(fn), v0244, v0141);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-4];
    if (v0141 == nil) goto v0029;
    v0141 = elt(env, 3); // less
    goto v0187;

v0187:
    qvalue(elt(env, 6)) = stack[0]; // wuvarlist!*
    qvalue(elt(env, 5)) = stack[-3]; // wukord!*
    { popv(5); return onevalue(v0141); }

v0029:
    v0141 = stack[-1];
    v0141 = qcar(v0141);
    v0141 = qcar(v0141);
    v0244 = qcar(v0141);
    v0141 = stack[-2];
    v0141 = qcar(v0141);
    v0141 = qcar(v0141);
    v0141 = qcar(v0141);
    fn = elt(env, 7); // symbollessp
    v0141 = (*qfn2(fn))(qenv(fn), v0244, v0141);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-4];
    if (v0141 == nil) goto v0120;
    v0141 = elt(env, 4); // greater
    goto v0187;

v0120:
    v0141 = stack[-2];
    v0141 = qcar(v0141);
    v0244 = qcdr(v0141);
    v0141 = stack[-1];
    v0141 = qcar(v0141);
    v0141 = qcdr(v0141);
    v0141 = CC_totalcompareconstants(env, v0244, v0141);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-4];
    v0242 = v0141;
    v0244 = v0242;
    v0141 = elt(env, 1); // equal
    if (v0244 == v0141) goto v0184;
    v0141 = v0242;
    goto v0187;

v0184:
    v0141 = stack[-2];
    v0244 = qcdr(v0141);
    v0141 = stack[-1];
    v0141 = qcdr(v0141);
    v0141 = CC_totalcompareconstants(env, v0244, v0141);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-4];
    goto v0187;

v0213:
    v0141 = qvalue(elt(env, 2)); // t
    goto v0059;

v0147:
    v0141 = qvalue(elt(env, 2)); // t
    goto v0033;

v0064:
    v0141 = elt(env, 1); // equal
    { popv(5); return onevalue(v0141); }
// error exit handlers
v0107:
    env = stack[-4];
    qvalue(elt(env, 6)) = stack[0]; // wuvarlist!*
    qvalue(elt(env, 5)) = stack[-3]; // wukord!*
    popv(5);
    return nil;
v0068:
    popv(5);
    return nil;
}



// Code for gcdlist

static LispObject CC_gcdlist(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0323, v0324, v0325;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gcdlist");
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
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0000;
// end of prologue
    v0323 = stack[0];
    if (v0323 == nil) goto v0106;
    v0323 = stack[0];
    v0323 = qcdr(v0323);
    if (v0323 == nil) goto v0002;
    v0323 = stack[0];
    v0323 = qcar(v0323);
    if (!consp(v0323)) goto v0147;
    v0323 = stack[0];
    v0323 = qcar(v0323);
    v0323 = qcar(v0323);
    v0323 = (consp(v0323) ? nil : lisp_true);
    goto v0033;

v0033:
    if (v0323 == nil) goto v0100;
    v0323 = stack[0];
    v0324 = qcdr(v0323);
    v0323 = stack[0];
    v0323 = qcar(v0323);
    {
        popv(15);
        fn = elt(env, 4); // gcdld
        return (*qfn2(fn))(qenv(fn), v0324, v0323);
    }

v0100:
    stack[-1] = nil;
    goto v0082;

v0082:
    v0323 = stack[0];
    if (v0323 == nil) goto v0046;
    v0323 = stack[0];
    v0323 = qcar(v0323);
    if (v0323 == nil) goto v0126;
    v0323 = stack[0];
    v0323 = qcar(v0323);
    if (!consp(v0323)) goto v0014;
    v0323 = stack[0];
    v0323 = qcar(v0323);
    v0323 = qcar(v0323);
    v0323 = (consp(v0323) ? nil : lisp_true);
    goto v0015;

v0015:
    if (v0323 == nil) goto v0006;
    v0323 = stack[0];
    stack[-2] = qcdr(v0323);
    v0323 = stack[-1];
    fn = elt(env, 5); // mapcarcar
    v0324 = (*qfn1(fn))(qenv(fn), v0323);
    nil = C_nil;
    if (exception_pending()) goto v0326;
    env = stack[-14];
    v0323 = stack[0];
    v0323 = qcar(v0323);
    fn = elt(env, 4); // gcdld
    v0323 = (*qfn2(fn))(qenv(fn), v0324, v0323);
    nil = C_nil;
    if (exception_pending()) goto v0326;
    env = stack[-14];
    fn = elt(env, 4); // gcdld
    v0323 = (*qfn2(fn))(qenv(fn), stack[-2], v0323);
    nil = C_nil;
    if (exception_pending()) goto v0326;
    env = stack[-14];
    v0323 = ncons(v0323);
    nil = C_nil;
    if (exception_pending()) goto v0326;
    env = stack[-14];
    v0323 = ncons(v0323);
    nil = C_nil;
    if (exception_pending()) goto v0326;
    env = stack[-14];
    stack[-1] = v0323;
    v0323 = qvalue(elt(env, 1)); // nil
    stack[0] = v0323;
    goto v0082;

v0006:
    v0323 = stack[0];
    stack[-2] = qcar(v0323);
    v0323 = stack[0];
    v0323 = qcar(v0323);
    fn = elt(env, 6); // powers1
    v0324 = (*qfn1(fn))(qenv(fn), v0323);
    nil = C_nil;
    if (exception_pending()) goto v0326;
    env = stack[-14];
    v0323 = stack[-1];
    v0323 = acons(stack[-2], v0324, v0323);
    nil = C_nil;
    if (exception_pending()) goto v0326;
    env = stack[-14];
    stack[-1] = v0323;
    v0323 = stack[0];
    v0323 = qcdr(v0323);
    stack[0] = v0323;
    goto v0082;

v0014:
    v0323 = qvalue(elt(env, 2)); // t
    goto v0015;

v0126:
    v0323 = stack[0];
    v0323 = qcdr(v0323);
    stack[0] = v0323;
    goto v0082;

v0046:
    v0323 = stack[-1];
    if (v0323 == nil) goto v0028;
    v0323 = stack[-1];
    v0323 = qcdr(v0323);
    if (v0323 == nil) goto v0032;
    v0323 = qvalue(elt(env, 1)); // nil
    stack[-13] = v0323;
    v0323 = qvalue(elt(env, 1)); // nil
    stack[-12] = v0323;
    v0323 = stack[-1];
    stack[-11] = v0323;
    v0323 = stack[-11];
    if (v0323 == nil) goto v0238;
    v0323 = stack[-11];
    v0323 = qcar(v0323);
    stack[-7] = v0323;
    stack[-6] = nil;
    v0323 = stack[-7];
    v0323 = qcdr(v0323);
    stack[-5] = v0323;
    v0323 = stack[-5];
    if (v0323 == nil) goto v0327;
    v0323 = stack[-5];
    v0323 = qcar(v0323);
    stack[-1] = v0323;
    v0323 = stack[-1];
    v0325 = qcar(v0323);
    v0323 = stack[-1];
    v0323 = qcdr(v0323);
    v0324 = qcdr(v0323);
    v0323 = stack[-6];
    v0323 = acons(v0325, v0324, v0323);
    nil = C_nil;
    if (exception_pending()) goto v0326;
    env = stack[-14];
    stack[-6] = v0323;
    v0323 = stack[-1];
    stack[0] = qcar(v0323);
    v0323 = stack[-1];
    v0323 = qcdr(v0323);
    v0324 = qcar(v0323);
    v0323 = stack[-1];
    v0323 = qcdr(v0323);
    v0323 = qcdr(v0323);
    v0323 = difference2(v0324, v0323);
    nil = C_nil;
    if (exception_pending()) goto v0326;
    env = stack[-14];
    v0323 = cons(stack[0], v0323);
    nil = C_nil;
    if (exception_pending()) goto v0326;
    env = stack[-14];
    v0323 = ncons(v0323);
    nil = C_nil;
    if (exception_pending()) goto v0326;
    env = stack[-14];
    stack[-3] = v0323;
    stack[-4] = v0323;
    goto v0113;

v0113:
    v0323 = stack[-5];
    v0323 = qcdr(v0323);
    stack[-5] = v0323;
    v0323 = stack[-5];
    if (v0323 == nil) goto v0090;
    stack[-2] = stack[-3];
    v0323 = stack[-5];
    v0323 = qcar(v0323);
    stack[-1] = v0323;
    v0323 = stack[-1];
    v0325 = qcar(v0323);
    v0323 = stack[-1];
    v0323 = qcdr(v0323);
    v0324 = qcdr(v0323);
    v0323 = stack[-6];
    v0323 = acons(v0325, v0324, v0323);
    nil = C_nil;
    if (exception_pending()) goto v0326;
    env = stack[-14];
    stack[-6] = v0323;
    v0323 = stack[-1];
    stack[0] = qcar(v0323);
    v0323 = stack[-1];
    v0323 = qcdr(v0323);
    v0324 = qcar(v0323);
    v0323 = stack[-1];
    v0323 = qcdr(v0323);
    v0323 = qcdr(v0323);
    v0323 = difference2(v0324, v0323);
    nil = C_nil;
    if (exception_pending()) goto v0326;
    env = stack[-14];
    v0323 = cons(stack[0], v0323);
    nil = C_nil;
    if (exception_pending()) goto v0326;
    env = stack[-14];
    v0323 = ncons(v0323);
    nil = C_nil;
    if (exception_pending()) goto v0326;
    env = stack[-14];
    v0323 = Lrplacd(nil, stack[-2], v0323);
    nil = C_nil;
    if (exception_pending()) goto v0326;
    env = stack[-14];
    v0323 = stack[-3];
    v0323 = qcdr(v0323);
    stack[-3] = v0323;
    goto v0113;

v0090:
    v0323 = stack[-4];
    goto v0112;

v0112:
    stack[0] = v0323;
    v0323 = stack[-7];
    v0323 = qcar(v0323);
    fn = elt(env, 7); // numeric!-content
    v0323 = (*qfn1(fn))(qenv(fn), v0323);
    nil = C_nil;
    if (exception_pending()) goto v0326;
    env = stack[-14];
    stack[-1] = v0323;
    v0323 = stack[-12];
    if (v0323 == nil) goto v0328;
    v0324 = stack[-13];
    v0323 = stack[-6];
    fn = elt(env, 8); // vintersection
    v0323 = (*qfn2(fn))(qenv(fn), v0324, v0323);
    nil = C_nil;
    if (exception_pending()) goto v0326;
    env = stack[-14];
    stack[-13] = v0323;
    v0324 = stack[-12];
    v0323 = stack[-1];
    fn = elt(env, 9); // gcddd
    v0323 = (*qfn2(fn))(qenv(fn), v0324, v0323);
    nil = C_nil;
    if (exception_pending()) goto v0326;
    env = stack[-14];
    stack[-12] = v0323;
    goto v0329;

v0329:
    v0323 = stack[-6];
    stack[-2] = v0323;
    goto v0330;

v0330:
    v0323 = stack[-2];
    if (v0323 == nil) goto v0160;
    v0323 = stack[-2];
    v0323 = qcar(v0323);
    v0325 = v0323;
    v0323 = v0325;
    v0324 = qcdr(v0323);
    v0323 = (LispObject)1; // 0
    if (v0324 == v0323) goto v0209;
    v0323 = v0325;
    v0323 = qcar(v0323);
    v0324 = v0325;
    v0324 = qcdr(v0324);
    fn = elt(env, 10); // mksp
    v0324 = (*qfn2(fn))(qenv(fn), v0323, v0324);
    nil = C_nil;
    if (exception_pending()) goto v0326;
    env = stack[-14];
    v0323 = (LispObject)17; // 1
    v0323 = cons(v0324, v0323);
    nil = C_nil;
    if (exception_pending()) goto v0326;
    env = stack[-14];
    v0323 = ncons(v0323);
    nil = C_nil;
    if (exception_pending()) goto v0326;
    env = stack[-14];
    fn = elt(env, 11); // multf
    v0323 = (*qfn2(fn))(qenv(fn), stack[-1], v0323);
    nil = C_nil;
    if (exception_pending()) goto v0326;
    env = stack[-14];
    stack[-1] = v0323;
    goto v0209;

v0209:
    v0323 = stack[-2];
    v0323 = qcdr(v0323);
    stack[-2] = v0323;
    goto v0330;

v0160:
    v0323 = stack[-7];
    v0325 = qcar(v0323);
    v0324 = stack[-1];
    v0323 = elt(env, 3); // "Term content division failed"
    fn = elt(env, 12); // quotfail1
    v0324 = (*qfnn(fn))(qenv(fn), 3, v0325, v0324, v0323);
    nil = C_nil;
    if (exception_pending()) goto v0326;
    env = stack[-14];
    v0323 = stack[0];
    v0323 = cons(v0324, v0323);
    nil = C_nil;
    if (exception_pending()) goto v0326;
    env = stack[-14];
    v0323 = ncons(v0323);
    nil = C_nil;
    if (exception_pending()) goto v0326;
    env = stack[-14];
    stack[-9] = v0323;
    stack[-10] = v0323;
    goto v0121;

v0121:
    v0323 = stack[-11];
    v0323 = qcdr(v0323);
    stack[-11] = v0323;
    v0323 = stack[-11];
    if (v0323 == nil) goto v0331;
    stack[-8] = stack[-9];
    v0323 = stack[-11];
    v0323 = qcar(v0323);
    stack[-7] = v0323;
    stack[-6] = nil;
    v0323 = stack[-7];
    v0323 = qcdr(v0323);
    stack[-5] = v0323;
    v0323 = stack[-5];
    if (v0323 == nil) goto v0332;
    v0323 = stack[-5];
    v0323 = qcar(v0323);
    stack[-1] = v0323;
    v0323 = stack[-1];
    v0325 = qcar(v0323);
    v0323 = stack[-1];
    v0323 = qcdr(v0323);
    v0324 = qcdr(v0323);
    v0323 = stack[-6];
    v0323 = acons(v0325, v0324, v0323);
    nil = C_nil;
    if (exception_pending()) goto v0326;
    env = stack[-14];
    stack[-6] = v0323;
    v0323 = stack[-1];
    stack[0] = qcar(v0323);
    v0323 = stack[-1];
    v0323 = qcdr(v0323);
    v0324 = qcar(v0323);
    v0323 = stack[-1];
    v0323 = qcdr(v0323);
    v0323 = qcdr(v0323);
    v0323 = difference2(v0324, v0323);
    nil = C_nil;
    if (exception_pending()) goto v0326;
    env = stack[-14];
    v0323 = cons(stack[0], v0323);
    nil = C_nil;
    if (exception_pending()) goto v0326;
    env = stack[-14];
    v0323 = ncons(v0323);
    nil = C_nil;
    if (exception_pending()) goto v0326;
    env = stack[-14];
    stack[-3] = v0323;
    stack[-4] = v0323;
    goto v0333;

v0333:
    v0323 = stack[-5];
    v0323 = qcdr(v0323);
    stack[-5] = v0323;
    v0323 = stack[-5];
    if (v0323 == nil) goto v0334;
    stack[-2] = stack[-3];
    v0323 = stack[-5];
    v0323 = qcar(v0323);
    stack[-1] = v0323;
    v0323 = stack[-1];
    v0325 = qcar(v0323);
    v0323 = stack[-1];
    v0323 = qcdr(v0323);
    v0324 = qcdr(v0323);
    v0323 = stack[-6];
    v0323 = acons(v0325, v0324, v0323);
    nil = C_nil;
    if (exception_pending()) goto v0326;
    env = stack[-14];
    stack[-6] = v0323;
    v0323 = stack[-1];
    stack[0] = qcar(v0323);
    v0323 = stack[-1];
    v0323 = qcdr(v0323);
    v0324 = qcar(v0323);
    v0323 = stack[-1];
    v0323 = qcdr(v0323);
    v0323 = qcdr(v0323);
    v0323 = difference2(v0324, v0323);
    nil = C_nil;
    if (exception_pending()) goto v0326;
    env = stack[-14];
    v0323 = cons(stack[0], v0323);
    nil = C_nil;
    if (exception_pending()) goto v0326;
    env = stack[-14];
    v0323 = ncons(v0323);
    nil = C_nil;
    if (exception_pending()) goto v0326;
    env = stack[-14];
    v0323 = Lrplacd(nil, stack[-2], v0323);
    nil = C_nil;
    if (exception_pending()) goto v0326;
    env = stack[-14];
    v0323 = stack[-3];
    v0323 = qcdr(v0323);
    stack[-3] = v0323;
    goto v0333;

v0334:
    v0323 = stack[-4];
    goto v0335;

v0335:
    stack[0] = v0323;
    v0323 = stack[-7];
    v0323 = qcar(v0323);
    fn = elt(env, 7); // numeric!-content
    v0323 = (*qfn1(fn))(qenv(fn), v0323);
    nil = C_nil;
    if (exception_pending()) goto v0326;
    env = stack[-14];
    stack[-1] = v0323;
    v0323 = stack[-12];
    if (v0323 == nil) goto v0336;
    v0324 = stack[-13];
    v0323 = stack[-6];
    fn = elt(env, 8); // vintersection
    v0323 = (*qfn2(fn))(qenv(fn), v0324, v0323);
    nil = C_nil;
    if (exception_pending()) goto v0326;
    env = stack[-14];
    stack[-13] = v0323;
    v0324 = stack[-12];
    v0323 = stack[-1];
    fn = elt(env, 9); // gcddd
    v0323 = (*qfn2(fn))(qenv(fn), v0324, v0323);
    nil = C_nil;
    if (exception_pending()) goto v0326;
    env = stack[-14];
    stack[-12] = v0323;
    goto v0337;

v0337:
    v0323 = stack[-6];
    stack[-2] = v0323;
    goto v0338;

v0338:
    v0323 = stack[-2];
    if (v0323 == nil) goto v0339;
    v0323 = stack[-2];
    v0323 = qcar(v0323);
    v0325 = v0323;
    v0323 = v0325;
    v0324 = qcdr(v0323);
    v0323 = (LispObject)1; // 0
    if (v0324 == v0323) goto v0340;
    v0323 = v0325;
    v0323 = qcar(v0323);
    v0324 = v0325;
    v0324 = qcdr(v0324);
    fn = elt(env, 10); // mksp
    v0324 = (*qfn2(fn))(qenv(fn), v0323, v0324);
    nil = C_nil;
    if (exception_pending()) goto v0326;
    env = stack[-14];
    v0323 = (LispObject)17; // 1
    v0323 = cons(v0324, v0323);
    nil = C_nil;
    if (exception_pending()) goto v0326;
    env = stack[-14];
    v0323 = ncons(v0323);
    nil = C_nil;
    if (exception_pending()) goto v0326;
    env = stack[-14];
    fn = elt(env, 11); // multf
    v0323 = (*qfn2(fn))(qenv(fn), stack[-1], v0323);
    nil = C_nil;
    if (exception_pending()) goto v0326;
    env = stack[-14];
    stack[-1] = v0323;
    goto v0340;

v0340:
    v0323 = stack[-2];
    v0323 = qcdr(v0323);
    stack[-2] = v0323;
    goto v0338;

v0339:
    v0323 = stack[-7];
    v0325 = qcar(v0323);
    v0324 = stack[-1];
    v0323 = elt(env, 3); // "Term content division failed"
    fn = elt(env, 12); // quotfail1
    v0324 = (*qfnn(fn))(qenv(fn), 3, v0325, v0324, v0323);
    nil = C_nil;
    if (exception_pending()) goto v0326;
    env = stack[-14];
    v0323 = stack[0];
    v0323 = cons(v0324, v0323);
    nil = C_nil;
    if (exception_pending()) goto v0326;
    env = stack[-14];
    v0323 = ncons(v0323);
    nil = C_nil;
    if (exception_pending()) goto v0326;
    env = stack[-14];
    v0323 = Lrplacd(nil, stack[-8], v0323);
    nil = C_nil;
    if (exception_pending()) goto v0326;
    env = stack[-14];
    v0323 = stack[-9];
    v0323 = qcdr(v0323);
    stack[-9] = v0323;
    goto v0121;

v0336:
    v0323 = stack[-6];
    stack[-13] = v0323;
    v0323 = stack[-1];
    stack[-12] = v0323;
    goto v0337;

v0332:
    v0323 = qvalue(elt(env, 1)); // nil
    goto v0335;

v0331:
    v0323 = stack[-10];
    goto v0120;

v0120:
    stack[0] = v0323;
    v0323 = stack[-13];
    stack[-1] = v0323;
    goto v0341;

v0341:
    v0323 = stack[-1];
    if (v0323 == nil) goto v0342;
    v0323 = stack[-1];
    v0323 = qcar(v0323);
    stack[-2] = stack[-12];
    v0324 = v0323;
    v0324 = qcar(v0324);
    v0323 = qcdr(v0323);
    fn = elt(env, 10); // mksp
    v0324 = (*qfn2(fn))(qenv(fn), v0324, v0323);
    nil = C_nil;
    if (exception_pending()) goto v0326;
    env = stack[-14];
    v0323 = (LispObject)17; // 1
    v0323 = cons(v0324, v0323);
    nil = C_nil;
    if (exception_pending()) goto v0326;
    env = stack[-14];
    v0323 = ncons(v0323);
    nil = C_nil;
    if (exception_pending()) goto v0326;
    env = stack[-14];
    fn = elt(env, 11); // multf
    v0323 = (*qfn2(fn))(qenv(fn), stack[-2], v0323);
    nil = C_nil;
    if (exception_pending()) goto v0326;
    env = stack[-14];
    stack[-12] = v0323;
    v0323 = stack[-1];
    v0323 = qcdr(v0323);
    stack[-1] = v0323;
    goto v0341;

v0342:
    stack[-1] = stack[-12];
    v0323 = stack[0];
    fn = elt(env, 13); // gcdlist1
    v0323 = (*qfn1(fn))(qenv(fn), v0323);
    nil = C_nil;
    if (exception_pending()) goto v0326;
    env = stack[-14];
    fn = elt(env, 11); // multf
    v0323 = (*qfn2(fn))(qenv(fn), stack[-1], v0323);
    nil = C_nil;
    if (exception_pending()) goto v0326;
    env = stack[-14];
    {
        popv(15);
        fn = elt(env, 14); // poly!-abs
        return (*qfn1(fn))(qenv(fn), v0323);
    }

v0328:
    v0323 = stack[-6];
    stack[-13] = v0323;
    v0323 = stack[-1];
    stack[-12] = v0323;
    goto v0329;

v0327:
    v0323 = qvalue(elt(env, 1)); // nil
    goto v0112;

v0238:
    v0323 = qvalue(elt(env, 1)); // nil
    goto v0120;

v0032:
    v0323 = stack[-1];
    v0323 = qcar(v0323);
    v0323 = qcar(v0323);
    {
        popv(15);
        fn = elt(env, 14); // poly!-abs
        return (*qfn1(fn))(qenv(fn), v0323);
    }

v0028:
    v0323 = qvalue(elt(env, 1)); // nil
    { popv(15); return onevalue(v0323); }

v0147:
    v0323 = qvalue(elt(env, 2)); // t
    goto v0033;

v0002:
    v0323 = stack[0];
    v0323 = qcar(v0323);
    {
        popv(15);
        fn = elt(env, 14); // poly!-abs
        return (*qfn1(fn))(qenv(fn), v0323);
    }

v0106:
    v0323 = qvalue(elt(env, 1)); // nil
    { popv(15); return onevalue(v0323); }
// error exit handlers
v0326:
    popv(15);
    return nil;
}



// Code for simpexpt2

static LispObject CC_simpexpt2(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0245, v0246, v0399;
    LispObject fn;
    LispObject v0010, v0011, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "simpexpt2");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0011 = va_arg(aa, LispObject);
    v0010 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for simpexpt2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0010,v0011,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0011,v0010);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0010;
    stack[-2] = v0011;
    stack[-3] = v0000;
// end of prologue

v0400:
    stack[0] = nil;
    v0246 = stack[-3];
    v0245 = (LispObject)17; // 1
    if (v0246 == v0245) goto v0103;
    v0245 = stack[-2];
    v0245 = qcar(v0245);
    stack[-4] = v0245;
    v0245 = stack[-3];
    v0245 = Lconsp(nil, v0245);
    env = stack[-5];
    if (v0245 == nil) goto v0099;
    v0245 = stack[-3];
    v0246 = qcar(v0245);
    v0245 = elt(env, 1); // expt
    if (v0246 == v0245) goto v0025;
    v0245 = qvalue(elt(env, 3)); // nil
    goto v0024;

v0024:
    if (v0245 == nil) goto v0008;
    v0245 = stack[-3];
    v0245 = qcdr(v0245);
    v0245 = qcdr(v0245);
    v0245 = qcar(v0245);
    fn = elt(env, 16); // simp
    v0246 = (*qfn1(fn))(qenv(fn), v0245);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-5];
    stack[-4] = v0246;
    v0245 = stack[-2];
    fn = elt(env, 17); // multsq
    v0245 = (*qfn2(fn))(qenv(fn), v0246, v0245);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-5];
    stack[-2] = v0245;
    v0245 = qvalue(elt(env, 4)); // !*precise
    if (v0245 == nil) goto v0218;
    v0245 = stack[-4];
    v0245 = qcar(v0245);
    if (!(is_number(v0245))) goto v0218;
    v0245 = stack[-4];
    v0245 = qcar(v0245);
    v0245 = Levenp(nil, v0245);
    env = stack[-5];
    if (v0245 == nil) goto v0218;
    v0246 = elt(env, 5); // abs
    v0245 = stack[-3];
    v0245 = qcdr(v0245);
    v0245 = qcar(v0245);
    v0245 = list2(v0246, v0245);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-5];
    stack[-3] = v0245;
    goto v0196;

v0196:
    v0399 = stack[-3];
    v0246 = stack[-2];
    v0245 = stack[-1];
    {
        popv(6);
        fn = elt(env, 18); // simpexpt1
        return (*qfnn(fn))(qenv(fn), 3, v0399, v0246, v0245);
    }

v0218:
    v0245 = stack[-3];
    v0245 = qcdr(v0245);
    v0245 = qcar(v0245);
    stack[-3] = v0245;
    goto v0196;

v0008:
    v0245 = stack[-3];
    v0246 = qcar(v0245);
    v0245 = elt(env, 6); // sqrt
    if (v0246 == v0245) goto v0402;
    v0245 = qvalue(elt(env, 3)); // nil
    goto v0235;

v0235:
    if (v0245 == nil) goto v0113;
    v0245 = stack[-3];
    v0245 = qcdr(v0245);
    stack[0] = qcar(v0245);
    v0246 = (LispObject)17; // 1
    v0245 = (LispObject)33; // 2
    v0246 = cons(v0246, v0245);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-5];
    v0245 = stack[-2];
    fn = elt(env, 17); // multsq
    v0246 = (*qfn2(fn))(qenv(fn), v0246, v0245);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-5];
    v0245 = stack[-1];
    stack[-3] = stack[0];
    stack[-2] = v0246;
    stack[-1] = v0245;
    goto v0400;

v0113:
    v0245 = stack[-3];
    v0246 = qcar(v0245);
    v0245 = elt(env, 8); // times
    if (v0246 == v0245) goto v0181;
    v0245 = qvalue(elt(env, 3)); // nil
    goto v0180;

v0180:
    if (v0245 == nil) goto v0403;
    v0246 = (LispObject)17; // 1
    v0245 = (LispObject)17; // 1
    v0245 = cons(v0246, v0245);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-5];
    stack[-4] = v0245;
    v0245 = stack[-3];
    v0245 = qcdr(v0245);
    stack[0] = v0245;
    goto v0140;

v0140:
    v0245 = stack[0];
    if (v0245 == nil) { LispObject res = stack[-4]; popv(6); return onevalue(res); }
    v0245 = stack[0];
    v0245 = qcar(v0245);
    v0399 = v0245;
    v0246 = stack[-2];
    v0245 = stack[-1];
    fn = elt(env, 18); // simpexpt1
    v0246 = (*qfnn(fn))(qenv(fn), 3, v0399, v0246, v0245);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-5];
    v0245 = stack[-4];
    fn = elt(env, 17); // multsq
    v0245 = (*qfn2(fn))(qenv(fn), v0246, v0245);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-5];
    stack[-4] = v0245;
    v0245 = stack[0];
    v0245 = qcdr(v0245);
    stack[0] = v0245;
    goto v0140;

v0403:
    v0245 = stack[-3];
    v0246 = qcar(v0245);
    v0245 = elt(env, 8); // times
    if (v0246 == v0245) goto v0144;
    v0245 = qvalue(elt(env, 3)); // nil
    goto v0143;

v0143:
    if (v0245 == nil) goto v0156;
    v0245 = stack[0];
    v0245 = qcdr(v0245);
    v0246 = qcar(v0245);
    v0245 = stack[0];
    v0245 = qcdr(v0245);
    v0245 = qcdr(v0245);
    v0245 = Lappend(nil, v0246, v0245);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-5];
    fn = elt(env, 19); // retimes
    v0399 = (*qfn1(fn))(qenv(fn), v0245);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-5];
    v0246 = stack[-2];
    v0245 = stack[-1];
    fn = elt(env, 18); // simpexpt1
    v0245 = (*qfnn(fn))(qenv(fn), 3, v0399, v0246, v0245);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-5];
    stack[-4] = v0245;
    v0245 = stack[0];
    v0245 = qcar(v0245);
    stack[0] = v0245;
    goto v0165;

v0165:
    v0245 = stack[0];
    if (v0245 == nil) { LispObject res = stack[-4]; popv(6); return onevalue(res); }
    v0245 = stack[0];
    v0245 = qcar(v0245);
    v0399 = v0245;
    v0246 = stack[-2];
    v0245 = stack[-1];
    fn = elt(env, 18); // simpexpt1
    v0246 = (*qfnn(fn))(qenv(fn), 3, v0399, v0246, v0245);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-5];
    v0245 = stack[-4];
    fn = elt(env, 17); // multsq
    v0245 = (*qfn2(fn))(qenv(fn), v0246, v0245);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-5];
    stack[-4] = v0245;
    v0245 = stack[0];
    v0245 = qcdr(v0245);
    stack[0] = v0245;
    goto v0165;

v0156:
    v0245 = stack[-3];
    v0246 = qcar(v0245);
    v0245 = elt(env, 10); // quotient
    if (v0246 == v0245) goto v0163;
    v0245 = qvalue(elt(env, 3)); // nil
    goto v0161;

v0161:
    if (v0245 == nil) goto v0298;
    v0245 = stack[-1];
    if (v0245 == nil) goto v0153;
    v0245 = qvalue(elt(env, 3)); // nil
    goto v0157;

v0157:
    if (v0245 == nil) goto v0404;
    v0245 = stack[-3];
    fn = elt(env, 20); // simp!*
    v0245 = (*qfn1(fn))(qenv(fn), v0245);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-5];
    fn = elt(env, 21); // prepsq
    v0399 = (*qfn1(fn))(qenv(fn), v0245);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-5];
    v0246 = stack[-2];
    v0245 = qvalue(elt(env, 11)); // t
    {
        popv(6);
        fn = elt(env, 18); // simpexpt1
        return (*qfnn(fn))(qenv(fn), 3, v0399, v0246, v0245);
    }

v0404:
    v0245 = stack[-2];
    fn = elt(env, 21); // prepsq
    v0245 = (*qfn1(fn))(qenv(fn), v0245);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-5];
    stack[-2] = v0245;
    v0245 = stack[-3];
    v0245 = qcdr(v0245);
    v0246 = qcar(v0245);
    v0245 = stack[-2];
    v0245 = list2(v0246, v0245);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-5];
    fn = elt(env, 22); // simpexpt
    stack[0] = (*qfn1(fn))(qenv(fn), v0245);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-5];
    v0245 = stack[-3];
    v0245 = qcdr(v0245);
    v0245 = qcdr(v0245);
    v0246 = qcar(v0245);
    v0245 = stack[-2];
    v0245 = list2(v0246, v0245);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-5];
    fn = elt(env, 22); // simpexpt
    v0245 = (*qfn1(fn))(qenv(fn), v0245);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-5];
    {
        LispObject v0405 = stack[0];
        popv(6);
        fn = elt(env, 23); // quotsq
        return (*qfn2(fn))(qenv(fn), v0405, v0245);
    }

v0153:
    v0245 = qvalue(elt(env, 12)); // !*mcd
    goto v0157;

v0298:
    v0245 = stack[-3];
    v0246 = qcar(v0245);
    v0245 = elt(env, 13); // minus
    if (v0246 == v0245) goto v0195;
    v0245 = qvalue(elt(env, 3)); // nil
    goto v0300;

v0300:
    if (v0245 == nil) goto v0099;
    v0245 = stack[-2];
    fn = elt(env, 21); // prepsq
    v0245 = (*qfn1(fn))(qenv(fn), v0245);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-5];
    stack[-1] = v0245;
    v0246 = (LispObject)-15; // -1
    v0245 = stack[-1];
    v0245 = list2(v0246, v0245);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-5];
    fn = elt(env, 22); // simpexpt
    stack[0] = (*qfn1(fn))(qenv(fn), v0245);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-5];
    v0245 = stack[-3];
    v0245 = qcdr(v0245);
    v0246 = qcar(v0245);
    v0245 = stack[-1];
    v0245 = list2(v0246, v0245);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-5];
    fn = elt(env, 22); // simpexpt
    v0245 = (*qfn1(fn))(qenv(fn), v0245);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-5];
    {
        LispObject v0406 = stack[0];
        popv(6);
        fn = elt(env, 17); // multsq
        return (*qfn2(fn))(qenv(fn), v0406, v0245);
    }

v0099:
    v0245 = stack[-1];
    if (v0245 == nil) goto v0407;
    v0245 = stack[-3];
    if (!(is_number(v0245))) goto v0408;
    v0245 = stack[-3];
    v0245 = (LispObject)zerop(v0245);
    v0245 = v0245 ? lisp_true : nil;
    env = stack[-5];
    if (v0245 == nil) goto v0408;
    v0246 = qvalue(elt(env, 3)); // nil
    v0245 = (LispObject)17; // 1
    popv(6);
    return cons(v0246, v0245);

v0408:
    v0245 = stack[-4];
    if (is_number(v0245)) goto v0409;
    v0245 = stack[-4];
    fn = elt(env, 24); // prepf
    v0245 = (*qfn1(fn))(qenv(fn), v0245);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-5];
    stack[-4] = v0245;
    goto v0409;

v0409:
    v0245 = stack[-2];
    v0245 = qcdr(v0245);
    fn = elt(env, 24); // prepf
    v0245 = (*qfn1(fn))(qenv(fn), v0245);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-5];
    stack[-2] = v0245;
    v0246 = stack[-4];
    v0245 = qvalue(elt(env, 15)); // frlis!*
    v0245 = Lmemq(nil, v0246, v0245);
    if (v0245 == nil) goto v0340;
    v0246 = stack[-2];
    v0245 = (LispObject)17; // 1
    if (!(v0246 == v0245)) goto v0340;
    v0399 = stack[-3];
    v0246 = stack[-4];
    v0245 = (LispObject)17; // 1
    v0245 = acons(v0399, v0246, v0245);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-5];
    v0246 = ncons(v0245);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    v0245 = (LispObject)17; // 1
    popv(6);
    return cons(v0246, v0245);

v0340:
    v0245 = qvalue(elt(env, 12)); // !*mcd
    if (!(v0245 == nil)) goto v0249;
    v0245 = stack[-4];
    if (is_number(v0245)) goto v0410;
    v0245 = qvalue(elt(env, 11)); // t
    goto v0411;

v0411:
    if (!(v0245 == nil)) goto v0249;
    v0246 = stack[-3];
    v0245 = stack[-4];
    {
        popv(6);
        fn = elt(env, 25); // mksq
        return (*qfn2(fn))(qenv(fn), v0246, v0245);
    }

v0249:
    v0399 = stack[-3];
    v0246 = stack[-4];
    v0245 = stack[-2];
    {
        popv(6);
        fn = elt(env, 26); // simpx1
        return (*qfnn(fn))(qenv(fn), 3, v0399, v0246, v0245);
    }

v0410:
    v0246 = stack[-2];
    v0245 = (LispObject)17; // 1
    if (v0246 == v0245) goto v0412;
    v0245 = qvalue(elt(env, 11)); // t
    goto v0411;

v0412:
    v0245 = stack[-3];
    if (!consp(v0245)) goto v0413;
    v0245 = stack[-3];
    fn = elt(env, 20); // simp!*
    v0245 = (*qfn1(fn))(qenv(fn), v0245);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-5];
    v0246 = qcdr(v0245);
    v0245 = (LispObject)17; // 1
    v0245 = Lneq(nil, v0246, v0245);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-5];
    goto v0411;

v0413:
    v0245 = qvalue(elt(env, 11)); // t
    goto v0411;

v0407:
    v0245 = qvalue(elt(env, 14)); // dmode!*
    if (v0245 == nil) goto v0414;
    v0245 = stack[-3];
    if (!(symbolp(v0245))) goto v0414;
    v0246 = stack[-3];
    v0245 = qvalue(elt(env, 14)); // dmode!*
    v0245 = get(v0246, v0245);
    env = stack[-5];
    if (!(v0245 == nil)) goto v0415;

v0414:
    v0245 = stack[-3];
    fn = elt(env, 20); // simp!*
    v0245 = (*qfn1(fn))(qenv(fn), v0245);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-5];
    fn = elt(env, 21); // prepsq
    v0245 = (*qfn1(fn))(qenv(fn), v0245);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-5];
    stack[-3] = v0245;
    goto v0415;

v0415:
    v0399 = stack[-3];
    v0246 = stack[-2];
    v0245 = qvalue(elt(env, 11)); // t
    {
        popv(6);
        fn = elt(env, 18); // simpexpt1
        return (*qfnn(fn))(qenv(fn), 3, v0399, v0246, v0245);
    }

v0195:
    v0245 = qvalue(elt(env, 4)); // !*precise
    if (v0245 == nil) goto v0416;
    v0245 = qvalue(elt(env, 3)); // nil
    goto v0300;

v0416:
    v0245 = stack[-3];
    v0245 = qcdr(v0245);
    v0246 = qcar(v0245);
    v0245 = (LispObject)17; // 1
    v0245 = (v0246 == v0245 ? lisp_true : nil);
    v0245 = (v0245 == nil ? lisp_true : nil);
    goto v0300;

v0163:
    v0245 = qvalue(elt(env, 4)); // !*precise
    if (v0245 == nil) goto v0417;
    v0245 = stack[-3];
    v0245 = qcdr(v0245);
    v0245 = qcdr(v0245);
    v0245 = qcar(v0245);
    fn = elt(env, 27); // posnump
    v0245 = (*qfn1(fn))(qenv(fn), v0245);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-5];
    if (v0245 == nil) goto v0306;
    v0245 = stack[-2];
    fn = elt(env, 21); // prepsq
    v0245 = (*qfn1(fn))(qenv(fn), v0245);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-5];
    fn = elt(env, 27); // posnump
    v0245 = (*qfn1(fn))(qenv(fn), v0245);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-5];
    goto v0161;

v0306:
    v0245 = qvalue(elt(env, 3)); // nil
    goto v0161;

v0417:
    v0245 = qvalue(elt(env, 11)); // t
    goto v0161;

v0144:
    v0245 = stack[-3];
    v0245 = qcdr(v0245);
    fn = elt(env, 28); // split!-sign
    v0245 = (*qfn1(fn))(qenv(fn), v0245);
    nil = C_nil;
    if (exception_pending()) goto v0401;
    env = stack[-5];
    stack[0] = v0245;
    if (v0245 == nil) goto v0418;
    v0245 = stack[0];
    v0245 = qcar(v0245);
    goto v0143;

v0418:
    v0245 = qvalue(elt(env, 3)); // nil
    goto v0143;

v0181:
    v0245 = qvalue(elt(env, 4)); // !*precise
    if (v0245 == nil) goto v0141;
    v0245 = qvalue(elt(env, 3)); // nil
    goto v0180;

v0141:
    v0245 = qvalue(elt(env, 9)); // !*modular
    v0245 = (v0245 == nil ? lisp_true : nil);
    goto v0180;

v0402:
    v0245 = qvalue(elt(env, 7)); // !*keepsqrts
    v0245 = (v0245 == nil ? lisp_true : nil);
    goto v0235;

v0025:
    v0245 = qvalue(elt(env, 2)); // !*precise_complex
    v0245 = (v0245 == nil ? lisp_true : nil);
    goto v0024;

v0103:
    v0246 = (LispObject)17; // 1
    v0245 = (LispObject)17; // 1
    popv(6);
    return cons(v0246, v0245);
// error exit handlers
v0401:
    popv(6);
    return nil;
}



// Code for mk!+resimp!+mat

static LispObject CC_mkLresimpLmat(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0039;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mk+resimp+mat");
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
    v0039 = v0000;
// end of prologue
    stack[-7] = v0039;
    v0039 = stack[-7];
    if (v0039 == nil) goto v0027;
    v0039 = stack[-7];
    v0039 = qcar(v0039);
    stack[-3] = v0039;
    v0039 = stack[-3];
    if (v0039 == nil) goto v0211;
    v0039 = stack[-3];
    v0039 = qcar(v0039);
    fn = elt(env, 2); // resimp
    v0039 = (*qfn1(fn))(qenv(fn), v0039);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-8];
    v0039 = ncons(v0039);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-8];
    stack[-1] = v0039;
    stack[-2] = v0039;
    goto v0021;

v0021:
    v0039 = stack[-3];
    v0039 = qcdr(v0039);
    stack[-3] = v0039;
    v0039 = stack[-3];
    if (v0039 == nil) goto v0051;
    stack[0] = stack[-1];
    v0039 = stack[-3];
    v0039 = qcar(v0039);
    fn = elt(env, 2); // resimp
    v0039 = (*qfn1(fn))(qenv(fn), v0039);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-8];
    v0039 = ncons(v0039);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-8];
    v0039 = Lrplacd(nil, stack[0], v0039);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-8];
    v0039 = stack[-1];
    v0039 = qcdr(v0039);
    stack[-1] = v0039;
    goto v0021;

v0051:
    v0039 = stack[-2];
    goto v0022;

v0022:
    v0039 = ncons(v0039);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-8];
    stack[-5] = v0039;
    stack[-6] = v0039;
    goto v0063;

v0063:
    v0039 = stack[-7];
    v0039 = qcdr(v0039);
    stack[-7] = v0039;
    v0039 = stack[-7];
    if (v0039 == nil) { LispObject res = stack[-6]; popv(9); return onevalue(res); }
    stack[-4] = stack[-5];
    v0039 = stack[-7];
    v0039 = qcar(v0039);
    stack[-3] = v0039;
    v0039 = stack[-3];
    if (v0039 == nil) goto v0035;
    v0039 = stack[-3];
    v0039 = qcar(v0039);
    fn = elt(env, 2); // resimp
    v0039 = (*qfn1(fn))(qenv(fn), v0039);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-8];
    v0039 = ncons(v0039);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-8];
    stack[-1] = v0039;
    stack[-2] = v0039;
    goto v0125;

v0125:
    v0039 = stack[-3];
    v0039 = qcdr(v0039);
    stack[-3] = v0039;
    v0039 = stack[-3];
    if (v0039 == nil) goto v0114;
    stack[0] = stack[-1];
    v0039 = stack[-3];
    v0039 = qcar(v0039);
    fn = elt(env, 2); // resimp
    v0039 = (*qfn1(fn))(qenv(fn), v0039);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-8];
    v0039 = ncons(v0039);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-8];
    v0039 = Lrplacd(nil, stack[0], v0039);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-8];
    v0039 = stack[-1];
    v0039 = qcdr(v0039);
    stack[-1] = v0039;
    goto v0125;

v0114:
    v0039 = stack[-2];
    goto v0091;

v0091:
    v0039 = ncons(v0039);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-8];
    v0039 = Lrplacd(nil, stack[-4], v0039);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-8];
    v0039 = stack[-5];
    v0039 = qcdr(v0039);
    stack[-5] = v0039;
    goto v0063;

v0035:
    v0039 = qvalue(elt(env, 1)); // nil
    goto v0091;

v0211:
    v0039 = qvalue(elt(env, 1)); // nil
    goto v0022;

v0027:
    v0039 = qvalue(elt(env, 1)); // nil
    { popv(9); return onevalue(v0039); }
// error exit handlers
v0121:
    popv(9);
    return nil;
}



// Code for quotexf!*

static LispObject CC_quotexfH(LispObject env,
                         LispObject v0000, LispObject v0011)
{
    LispObject nil = C_nil;
    LispObject v0100, v0024;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for quotexf*");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0011,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0011);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0011;
    stack[-2] = v0000;
// end of prologue
    stack[-3] = nil;
    goto v0061;

v0061:
    v0100 = stack[-2];
    if (v0100 == nil) goto v0001;
    v0100 = stack[-2];
    v0100 = qcar(v0100);
    stack[0] = qcar(v0100);
    v0100 = stack[-2];
    v0100 = qcar(v0100);
    v0024 = qcdr(v0100);
    v0100 = stack[-1];
    fn = elt(env, 1); // quotfexf!*1
    v0024 = (*qfn2(fn))(qenv(fn), v0024, v0100);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-4];
    v0100 = stack[-3];
    v0100 = acons(stack[0], v0024, v0100);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-4];
    stack[-3] = v0100;
    v0100 = stack[-2];
    v0100 = qcdr(v0100);
    stack[-2] = v0100;
    goto v0061;

v0001:
    v0100 = stack[-3];
    {
        popv(5);
        fn = elt(env, 2); // nreverse
        return (*qfn1(fn))(qenv(fn), v0100);
    }
// error exit handlers
v0050:
    popv(5);
    return nil;
}



setup_type const u41_setup[] =
{
    {"markedvarp",              CC_markedvarp,  too_many_1,    wrong_no_1},
    {"incident1",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_incident1},
    {"prepsq*0",                too_few_2,      CC_prepsqH0,   wrong_no_2},
    {"derivative-mod-p",        CC_derivativeKmodKp,too_many_1,wrong_no_1},
    {"change+int+to+sq",        CC_changeLintLtoLsq,too_many_1,wrong_no_1},
    {"cl_gand-col",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_cl_gandKcol},
    {"ev_mtest?",               too_few_2,      CC_ev_mtestW,  wrong_no_2},
    {"numir",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_numir},
    {"mkexpt",                  too_few_2,      CC_mkexpt,     wrong_no_2},
    {"evalmember",              too_few_2,      CC_evalmember, wrong_no_2},
    {"e*",                      wrong_no_na,    wrong_no_nb,   (n_args *)CC_eH},
    {"gpargp",                  CC_gpargp,      too_many_1,    wrong_no_1},
    {"indexvp",                 CC_indexvp,     too_many_1,    wrong_no_1},
    {"ev-edgeloop",             too_few_2,      CC_evKedgeloop,wrong_no_2},
    {"applsmacro",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_applsmacro},
    {"extract_vars",            CC_extract_vars,too_many_1,    wrong_no_1},
    {"gigcdsq",                 too_few_2,      CC_gigcdsq,    wrong_no_2},
    {"pasf_coeflst",            too_few_2,      CC_pasf_coeflst,wrong_no_2},
    {"matrixml",                CC_matrixml,    too_many_1,    wrong_no_1},
    {"ps:arg-values",           CC_psTargKvalues,too_many_1,   wrong_no_1},
    {"diford",                  CC_diford,      too_many_1,    wrong_no_1},
    {"specrd:times",            too_few_2,      CC_specrdTtimes,wrong_no_2},
    {"remdiff",                 CC_remdiff,     too_many_1,    wrong_no_1},
    {"remove_least_item",       CC_remove_least_item,too_many_1,wrong_no_1},
    {"nspaces",                 CC_nspaces,     too_many_1,    wrong_no_1},
    {"listminimize",            too_few_2,      CC_listminimize,wrong_no_2},
    {"mk_dummy_ids",            CC_mk_dummy_ids,too_many_1,    wrong_no_1},
    {"mchsarg",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_mchsarg},
    {"createtriple",            CC_createtriple,too_many_1,    wrong_no_1},
    {"totalcompareconstants",   too_few_2,      CC_totalcompareconstants,wrong_no_2},
    {"gcdlist",                 CC_gcdlist,     too_many_1,    wrong_no_1},
    {"simpexpt2",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_simpexpt2},
    {"mk+resimp+mat",           CC_mkLresimpLmat,too_many_1,   wrong_no_1},
    {"quotexf*",                too_few_2,      CC_quotexfH,   wrong_no_2},
    {NULL, (one_args *)"u41", (two_args *)"13057 7175177 2817964", 0}
};

// end of generated code
