
// $destdir/u16.c        Machine generated C code

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



// Code for xread1

static LispObject CC_xread1(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0227, v0228, v0229;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for xread1");
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
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-7] = v0000;
// end of prologue
    stack[-8] = nil;
    stack[-6] = nil;
    stack[-5] = nil;
    stack[-4] = nil;
    stack[-2] = nil;
    stack[-1] = nil;
    v0227 = qvalue(elt(env, 1)); // commentlist!*
    if (v0227 == nil) goto v0230;
    v0227 = qvalue(elt(env, 1)); // commentlist!*
    stack[-1] = v0227;
    v0227 = qvalue(elt(env, 2)); // nil
    qvalue(elt(env, 1)) = v0227; // commentlist!*
    goto v0230;

v0230:
    v0227 = qvalue(elt(env, 3)); // cursym!*
    stack[-3] = v0227;
    goto v0231;

v0231:
    v0227 = stack[-3];
    if (!(symbolp(v0227))) goto v0232;
    v0228 = stack[-3];
    v0227 = elt(env, 4); // !*lpar!*
    if (v0228 == v0227) goto v0233;
    v0228 = stack[-3];
    v0227 = elt(env, 5); // !*rpar!*
    if (v0228 == v0227) goto v0234;
    v0227 = stack[-3];
    if (!symbolp(v0227)) v0227 = nil;
    else { v0227 = qfastgets(v0227);
           if (v0227 != nil) { v0227 = elt(v0227, 23); // infix
#ifdef RECORD_GET
             if (v0227 != SPID_NOPROP)
                record_get(elt(fastget_names, 23), 1);
             else record_get(elt(fastget_names, 23), 0),
                v0227 = nil; }
           else record_get(elt(fastget_names, 23), 0); }
#else
             if (v0227 == SPID_NOPROP) v0227 = nil; }}
#endif
    stack[-4] = v0227;
    if (!(v0227 == nil)) goto v0235;
    v0227 = stack[-3];
    if (!symbolp(v0227)) v0227 = nil;
    else { v0227 = qfastgets(v0227);
           if (v0227 != nil) { v0227 = elt(v0227, 55); // delim
#ifdef RECORD_GET
             if (v0227 == SPID_NOPROP)
                record_get(elt(fastget_names, 55), 0),
                v0227 = nil;
             else record_get(elt(fastget_names, 55), 1),
                v0227 = lisp_true; }
           else record_get(elt(fastget_names, 55), 0); }
#else
             if (v0227 == SPID_NOPROP) v0227 = nil; else v0227 = lisp_true; }}
#endif
    if (v0227 == nil) goto v0236;
    v0228 = qvalue(elt(env, 3)); // cursym!*
    v0227 = elt(env, 42); // !*semicol!*
    if (v0228 == v0227) goto v0237;
    fn = elt(env, 50); // eolcheck
    v0227 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    goto v0237;

v0237:
    v0228 = stack[-3];
    v0227 = elt(env, 43); // !*colon!*
    if (v0228 == v0227) goto v0239;
    v0227 = qvalue(elt(env, 2)); // nil
    goto v0240;

v0240:
    if (!(v0227 == nil)) goto v0241;
    v0228 = stack[-3];
    v0227 = elt(env, 46); // nodel
    v0227 = Lflagp(nil, v0228, v0227);
    env = stack[-9];
    if (v0227 == nil) goto v0242;
    v0227 = stack[-7];
    if (v0227 == nil) goto v0243;
    v0228 = stack[-7];
    v0227 = elt(env, 23); // group
    if (v0228 == v0227) goto v0244;
    v0227 = qvalue(elt(env, 2)); // nil
    goto v0245;

v0245:
    if (!(v0227 == nil)) goto v0241;
    v0227 = stack[-7];
    if (!(symbolp(v0227))) goto v0246;
    v0228 = stack[-7];
    v0227 = elt(env, 18); // paren
    if (v0228 == v0227) goto v0247;
    v0228 = stack[-7];
    v0227 = elt(env, 17); // struct
    v0227 = Lflagp(nil, v0228, v0227);
    env = stack[-9];
    goto v0248;

v0248:
    if (v0227 == nil) goto v0246;
    v0228 = elt(env, 48); // "Too few right parentheses"
    v0227 = qvalue(elt(env, 2)); // nil
    fn = elt(env, 51); // symerr
    v0227 = (*qfn2(fn))(qenv(fn), v0228, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    goto v0246;

v0246:
    v0227 = stack[-4];
    if (v0227 == nil) goto v0249;
    v0228 = elt(env, 21); // "Improper delimiter"
    v0227 = qvalue(elt(env, 2)); // nil
    fn = elt(env, 51); // symerr
    v0227 = (*qfn2(fn))(qenv(fn), v0228, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    goto v0250;

v0250:
    v0227 = (LispObject)1; // 0
    stack[-4] = v0227;
    goto v0251;

v0251:
    v0227 = stack[-6];
    if (!(v0227 == nil)) goto v0252;
    v0228 = elt(env, 21); // "Improper delimiter"
    v0227 = qvalue(elt(env, 2)); // nil
    fn = elt(env, 51); // symerr
    v0227 = (*qfn2(fn))(qenv(fn), v0228, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    goto v0252;

v0252:
    v0227 = stack[-6];
    v0228 = qcar(v0227);
    v0227 = stack[-3];
    fn = elt(env, 52); // mkvar
    v0227 = (*qfn2(fn))(qenv(fn), v0228, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    stack[0] = v0227;
    goto v0253;

v0253:
    v0227 = stack[-6];
    v0227 = qcdr(v0227);
    stack[-6] = v0227;
    v0227 = stack[-6];
    if (v0227 == nil) goto v0254;
    v0227 = stack[-6];
    v0227 = qcar(v0227);
    if (!consp(v0227)) goto v0255;
    v0227 = qvalue(elt(env, 2)); // nil
    goto v0256;

v0256:
    if (v0227 == nil) goto v0257;
    v0228 = elt(env, 28); // "Missing operator"
    v0227 = qvalue(elt(env, 2)); // nil
    fn = elt(env, 51); // symerr
    v0227 = (*qfn2(fn))(qenv(fn), v0228, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    goto v0257;

v0257:
    v0227 = stack[-6];
    v0228 = qcar(v0227);
    v0227 = stack[0];
    v0227 = list2(v0228, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    stack[0] = v0227;
    goto v0253;

v0255:
    v0227 = stack[-6];
    v0227 = qcar(v0227);
    v0227 = Lsymbolp(nil, v0227);
    env = stack[-9];
    v0227 = (v0227 == nil ? lisp_true : nil);
    goto v0256;

v0254:
    v0228 = stack[0];
    v0227 = stack[-8];
    v0227 = cons(v0228, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    stack[-8] = v0227;
    goto v0258;

v0258:
    v0227 = stack[-5];
    if (v0227 == nil) goto v0259;
    v0227 = stack[-8];
    if (v0227 == nil) goto v0260;
    v0227 = stack[-8];
    v0228 = qcdr(v0227);
    v0227 = elt(env, 27); // !*!*un!*!*
    if (!consp(v0228)) goto v0261;
    v0228 = qcar(v0228);
    if (!(v0228 == v0227)) goto v0261;
    v0227 = stack[-5];
    v0227 = qcdr(v0227);
    if (v0227 == nil) goto v0262;
    v0228 = stack[-4];
    v0227 = stack[-5];
    v0227 = qcar(v0227);
    v0227 = qcar(v0227);
    v0227 = (LispObject)geq2(v0228, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    v0227 = v0227 ? lisp_true : nil;
    env = stack[-9];
    if (v0227 == nil) goto v0263;
    v0228 = stack[-4];
    v0227 = stack[-5];
    v0227 = qcdr(v0227);
    v0227 = qcar(v0227);
    v0227 = qcar(v0227);
    v0227 = (LispObject)lesseq2(v0228, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    v0227 = v0227 ? lisp_true : nil;
    env = stack[-9];
    goto v0264;

v0264:
    if (v0227 == nil) goto v0260;
    v0228 = elt(env, 29); // "Please use parentheses around use of the unary operator"
    v0227 = qvalue(elt(env, 2)); // nil
    fn = elt(env, 51); // symerr
    v0227 = (*qfn2(fn))(qenv(fn), v0228, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    goto v0265;

v0265:
    v0229 = stack[-4];
    v0228 = stack[-3];
    v0227 = stack[-5];
    v0227 = acons(v0229, v0228, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    stack[-5] = v0227;
    v0228 = stack[-3];
    v0227 = elt(env, 19); // !*comma!*
    if (!(v0228 == v0227)) goto v0266;
    v0227 = stack[-5];
    v0227 = qcdr(v0227);
    if (!(v0227 == nil)) goto v0267;
    v0227 = stack[-7];
    if (v0227 == nil) goto v0268;
    v0228 = stack[-7];
    v0227 = elt(env, 31); // (lambda paren)
    v0227 = Lmemq(nil, v0228, v0227);
    if (!(v0227 == nil)) goto v0269;
    v0228 = stack[-7];
    v0227 = elt(env, 17); // struct
    v0227 = Lflagp(nil, v0228, v0227);
    env = stack[-9];
    goto v0269;

v0269:
    if (!(v0227 == nil)) goto v0267;

v0270:
    v0227 = stack[-8];
    v0227 = qcdr(v0227);
    if (v0227 == nil) goto v0271;
    v0227 = elt(env, 49); // "Please send hearn@rand.org your program!!"
    v0227 = Lprint(nil, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    v0228 = elt(env, 21); // "Improper delimiter"
    v0227 = qvalue(elt(env, 2)); // nil
    fn = elt(env, 51); // symerr
    v0227 = (*qfn2(fn))(qenv(fn), v0228, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    v0227 = nil;
    { popv(10); return onevalue(v0227); }

v0271:
    v0227 = stack[-8];
    v0228 = qcar(v0227);
    v0227 = stack[-1];
    {
        popv(10);
        fn = elt(env, 53); // xcomment
        return (*qfn2(fn))(qenv(fn), v0228, v0227);
    }

v0267:
    fn = elt(env, 54); // scan
    v0227 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    stack[-3] = v0227;
    goto v0231;

v0268:
    v0227 = qvalue(elt(env, 22)); // t
    goto v0269;

v0266:
    v0227 = stack[-2];
    stack[-3] = v0227;
    goto v0231;

v0260:
    v0228 = stack[-4];
    v0227 = stack[-5];
    v0227 = qcar(v0227);
    v0227 = qcar(v0227);
    v0227 = (LispObject)lessp2(v0228, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    v0227 = v0227 ? lisp_true : nil;
    env = stack[-9];
    if (!(v0227 == nil)) goto v0272;
    v0228 = stack[-4];
    v0227 = stack[-5];
    v0227 = qcar(v0227);
    v0227 = qcar(v0227);
    if (equal(v0228, v0227)) goto v0273;
    v0227 = qvalue(elt(env, 2)); // nil
    goto v0274;

v0274:
    if (v0227 == nil) goto v0265;
    else goto v0272;

v0272:
    v0227 = stack[-8];
    v0227 = qcdr(v0227);
    v0228 = qcar(v0227);
    v0227 = elt(env, 32); // not
    if (!consp(v0228)) goto v0275;
    v0228 = qcar(v0228);
    if (!(v0228 == v0227)) goto v0275;
    v0227 = stack[-5];
    v0227 = qcar(v0227);
    v0228 = qcar(v0227);
    v0227 = elt(env, 33); // member
    if (!symbolp(v0227)) v0227 = nil;
    else { v0227 = qfastgets(v0227);
           if (v0227 != nil) { v0227 = elt(v0227, 23); // infix
#ifdef RECORD_GET
             if (v0227 != SPID_NOPROP)
                record_get(elt(fastget_names, 23), 1);
             else record_get(elt(fastget_names, 23), 0),
                v0227 = nil; }
           else record_get(elt(fastget_names, 23), 0); }
#else
             if (v0227 == SPID_NOPROP) v0227 = nil; }}
#endif
    v0227 = (LispObject)geq2(v0228, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    v0227 = v0227 ? lisp_true : nil;
    env = stack[-9];
    goto v0276;

v0276:
    if (v0227 == nil) goto v0277;
    v0228 = elt(env, 34); // "NOT"
    v0227 = elt(env, 35); // "infix operator"
    fn = elt(env, 55); // typerr
    v0227 = (*qfn2(fn))(qenv(fn), v0228, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    goto v0277;

v0277:
    v0227 = stack[-8];
    v0227 = qcdr(v0227);
    v0228 = qcar(v0227);
    v0227 = elt(env, 27); // !*!*un!*!*
    if (v0228 == v0227) goto v0278;
    v0227 = stack[-5];
    v0227 = qcar(v0227);
    stack[0] = qcdr(v0227);
    v0227 = stack[-8];
    v0228 = qcar(v0227);
    v0227 = stack[-5];
    v0227 = qcar(v0227);
    v0227 = qcdr(v0227);
    if (!consp(v0228)) goto v0279;
    v0228 = qcar(v0228);
    if (!(v0228 == v0227)) goto v0279;
    v0227 = stack[-5];
    v0227 = qcar(v0227);
    v0227 = qcdr(v0227);
    if (!symbolp(v0227)) v0227 = nil;
    else { v0227 = qfastgets(v0227);
           if (v0227 != nil) { v0227 = elt(v0227, 35); // nary
#ifdef RECORD_GET
             if (v0227 == SPID_NOPROP)
                record_get(elt(fastget_names, 35), 0),
                v0227 = nil;
             else record_get(elt(fastget_names, 35), 1),
                v0227 = lisp_true; }
           else record_get(elt(fastget_names, 35), 0); }
#else
             if (v0227 == SPID_NOPROP) v0227 = nil; else v0227 = lisp_true; }}
#endif
    goto v0280;

v0280:
    if (v0227 == nil) goto v0281;
    v0227 = stack[-8];
    v0227 = qcdr(v0227);
    v0228 = qcar(v0227);
    v0227 = stack[-8];
    v0227 = qcar(v0227);
    v0227 = qcdr(v0227);
    v0227 = cons(v0228, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    goto v0282;

v0282:
    v0227 = cons(stack[0], v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    stack[0] = v0227;
    goto v0283;

v0283:
    v0227 = stack[-5];
    v0227 = qcdr(v0227);
    stack[-5] = v0227;
    v0228 = stack[0];
    v0227 = stack[-8];
    v0227 = qcdr(v0227);
    v0227 = qcdr(v0227);
    v0227 = cons(v0228, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    stack[-8] = v0227;
    goto v0258;

v0281:
    v0227 = stack[-8];
    v0227 = qcdr(v0227);
    v0228 = qcar(v0227);
    v0227 = stack[-8];
    v0227 = qcar(v0227);
    v0227 = list2(v0228, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    goto v0282;

v0279:
    v0227 = qvalue(elt(env, 2)); // nil
    goto v0280;

v0278:
    v0227 = stack[-8];
    v0228 = qcar(v0227);
    v0227 = elt(env, 27); // !*!*un!*!*
    if (v0228 == v0227) goto v0265;
    v0227 = stack[-5];
    v0227 = qcar(v0227);
    v0228 = qcdr(v0227);
    v0227 = stack[-8];
    v0227 = qcar(v0227);
    v0227 = list2(v0228, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    stack[0] = v0227;
    goto v0283;

v0275:
    v0227 = qvalue(elt(env, 2)); // nil
    goto v0276;

v0273:
    v0228 = stack[-3];
    v0227 = stack[-5];
    v0227 = qcar(v0227);
    v0227 = qcdr(v0227);
    if (v0228 == v0227) goto v0284;
    v0227 = qvalue(elt(env, 2)); // nil
    goto v0285;

v0285:
    if (v0227 == nil) goto v0286;
    v0227 = qvalue(elt(env, 22)); // t
    goto v0274;

v0286:
    v0227 = stack[-5];
    v0227 = qcar(v0227);
    v0227 = qcdr(v0227);
    if (!symbolp(v0227)) v0227 = nil;
    else { v0227 = qfastgets(v0227);
           if (v0227 != nil) { v0227 = elt(v0227, 49); // alt
#ifdef RECORD_GET
             if (v0227 != SPID_NOPROP)
                record_get(elt(fastget_names, 49), 1);
             else record_get(elt(fastget_names, 49), 0),
                v0227 = nil; }
           else record_get(elt(fastget_names, 49), 0); }
#else
             if (v0227 == SPID_NOPROP) v0227 = nil; }}
#endif
    goto v0274;

v0284:
    v0227 = stack[-3];
    if (!symbolp(v0227)) v0227 = nil;
    else { v0227 = qfastgets(v0227);
           if (v0227 != nil) { v0227 = elt(v0227, 35); // nary
#ifdef RECORD_GET
             if (v0227 == SPID_NOPROP)
                record_get(elt(fastget_names, 35), 0),
                v0227 = nil;
             else record_get(elt(fastget_names, 35), 1),
                v0227 = lisp_true; }
           else record_get(elt(fastget_names, 35), 0); }
#else
             if (v0227 == SPID_NOPROP) v0227 = nil; else v0227 = lisp_true; }}
#endif
    if (v0227 == nil) goto v0287;
    v0227 = qvalue(elt(env, 2)); // nil
    goto v0285;

v0287:
    v0228 = stack[-3];
    v0227 = elt(env, 30); // right
    v0227 = Lflagp(nil, v0228, v0227);
    env = stack[-9];
    v0227 = (v0227 == nil ? lisp_true : nil);
    goto v0285;

v0263:
    v0227 = qvalue(elt(env, 2)); // nil
    goto v0264;

v0262:
    v0227 = qvalue(elt(env, 2)); // nil
    goto v0264;

v0261:
    v0227 = qvalue(elt(env, 2)); // nil
    goto v0264;

v0259:
    v0228 = stack[-4];
    v0227 = (LispObject)1; // 0
    if (v0228 == v0227) goto v0270;
    else goto v0265;

v0249:
    v0227 = stack[-8];
    if (v0227 == nil) goto v0288;
    v0227 = qvalue(elt(env, 2)); // nil
    goto v0289;

v0289:
    if (v0227 == nil) goto v0250;
    v0228 = qvalue(elt(env, 2)); // nil
    v0227 = stack[-1];
    {
        popv(10);
        fn = elt(env, 53); // xcomment
        return (*qfn2(fn))(qenv(fn), v0228, v0227);
    }

v0288:
    v0227 = stack[-6];
    if (v0227 == nil) goto v0290;
    v0227 = qvalue(elt(env, 2)); // nil
    goto v0289;

v0290:
    v0227 = stack[-5];
    v0227 = (v0227 == nil ? lisp_true : nil);
    goto v0289;

v0247:
    v0227 = qvalue(elt(env, 22)); // t
    goto v0248;

v0241:
    v0228 = elt(env, 21); // "Improper delimiter"
    v0227 = qvalue(elt(env, 2)); // nil
    fn = elt(env, 51); // symerr
    v0227 = (*qfn2(fn))(qenv(fn), v0228, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    goto v0246;

v0244:
    v0228 = stack[-3];
    v0227 = elt(env, 47); // (!*rsqbkt!* !*rcbkt!* !*rsqb!*)
    v0227 = Lmemq(nil, v0228, v0227);
    v0227 = (v0227 == nil ? lisp_true : nil);
    goto v0245;

v0243:
    v0227 = qvalue(elt(env, 22)); // t
    goto v0245;

v0242:
    v0227 = qvalue(elt(env, 2)); // nil
    goto v0245;

v0239:
    v0228 = stack[-7];
    v0227 = elt(env, 44); // for
    if (v0228 == v0227) goto v0291;
    v0227 = qvalue(elt(env, 45)); // !*blockp
    if (v0227 == nil) goto v0292;
    v0227 = stack[-6];
    if (v0227 == nil) goto v0293;
    v0227 = stack[-6];
    v0227 = qcar(v0227);
    if (!consp(v0227)) goto v0294;
    v0227 = qvalue(elt(env, 22)); // t
    goto v0240;

v0294:
    v0227 = stack[-6];
    v0227 = qcdr(v0227);
    goto v0240;

v0293:
    v0227 = qvalue(elt(env, 22)); // t
    goto v0240;

v0292:
    v0227 = qvalue(elt(env, 22)); // t
    goto v0240;

v0291:
    v0227 = qvalue(elt(env, 2)); // nil
    goto v0240;

v0236:
    v0227 = stack[-3];
    if (!symbolp(v0227)) v0227 = nil;
    else { v0227 = qfastgets(v0227);
           if (v0227 != nil) { v0227 = elt(v0227, 36); // stat
#ifdef RECORD_GET
             if (v0227 != SPID_NOPROP)
                record_get(elt(fastget_names, 36), 1);
             else record_get(elt(fastget_names, 36), 0),
                v0227 = nil; }
           else record_get(elt(fastget_names, 36), 0); }
#else
             if (v0227 == SPID_NOPROP) v0227 = nil; }}
#endif
    stack[-4] = v0227;
    if (v0227 == nil) goto v0295;
    v0228 = stack[-4];
    v0227 = elt(env, 36); // endstat
    if (v0228 == v0227) goto v0296;
    fn = elt(env, 50); // eolcheck
    v0227 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    goto v0296;

v0296:
    v0228 = stack[-3];
    v0227 = elt(env, 37); // go
    v0227 = Lflagp(nil, v0228, v0227);
    env = stack[-9];
    if (v0227 == nil) goto v0297;
    v0227 = qvalue(elt(env, 22)); // t
    goto v0298;

v0298:
    if (v0227 == nil) goto v0232;
    v0228 = stack[-3];
    v0227 = elt(env, 40); // procedure
    if (v0228 == v0227) goto v0299;
    v0227 = qvalue(elt(env, 2)); // nil
    goto v0300;

v0300:
    if (v0227 == nil) goto v0301;
    v0227 = stack[-6];
    if (v0227 == nil) goto v0302;
    v0227 = stack[-6];
    v0227 = qcdr(v0227);
    if (!(v0227 == nil)) goto v0303;
    v0227 = qvalue(elt(env, 6)); // !*reduce4
    if (!(v0227 == nil)) goto v0303;
    v0227 = stack[-6];
    v0227 = qcar(v0227);
    fn = elt(env, 56); // procstat1
    v0227 = (*qfn1(fn))(qenv(fn), v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    v0227 = ncons(v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    stack[-6] = v0227;
    goto v0304;

v0304:
    v0227 = qvalue(elt(env, 2)); // nil
    stack[-4] = v0227;
    goto v0230;

v0303:
    v0228 = elt(env, 41); // "proc form"
    v0227 = qvalue(elt(env, 2)); // nil
    fn = elt(env, 51); // symerr
    v0227 = (*qfn2(fn))(qenv(fn), v0228, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    goto v0304;

v0302:
    v0227 = qvalue(elt(env, 2)); // nil
    fn = elt(env, 56); // procstat1
    v0227 = (*qfn1(fn))(qenv(fn), v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    v0227 = ncons(v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    stack[-6] = v0227;
    goto v0304;

v0301:
    v0228 = stack[-4];
    v0227 = qvalue(elt(env, 2)); // nil
    fn = elt(env, 57); // lispapply
    v0228 = (*qfn2(fn))(qenv(fn), v0228, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    v0227 = stack[-6];
    v0227 = cons(v0228, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    stack[-6] = v0227;
    goto v0304;

v0299:
    v0227 = qvalue(elt(env, 6)); // !*reduce4
    goto v0300;

v0232:
    v0227 = qvalue(elt(env, 2)); // nil
    stack[-4] = v0227;
    goto v0305;

v0305:
    v0228 = stack[-3];
    v0227 = stack[-6];
    v0227 = cons(v0228, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    stack[-6] = v0227;
    v0227 = stack[-3];
    fn = elt(env, 58); // toknump
    v0227 = (*qfn1(fn))(qenv(fn), v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    if (v0227 == nil) goto v0306;
    v0228 = stack[-2];
    v0227 = qvalue(elt(env, 9)); // !$eol!$
    if (v0228 == v0227) goto v0307;
    v0227 = qvalue(elt(env, 10)); // nxtsym!*
    fn = elt(env, 59); // chknewnam
    v0227 = (*qfn1(fn))(qenv(fn), v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    stack[-2] = v0227;
    if (symbolp(v0227)) goto v0308;
    v0227 = qvalue(elt(env, 2)); // nil
    goto v0309;

v0309:
    if (v0227 == nil) goto v0306;
    v0227 = elt(env, 13); // times
    qvalue(elt(env, 3)) = v0227; // cursym!*
    v0227 = qvalue(elt(env, 2)); // nil
    qvalue(elt(env, 14)) = v0227; // curescaped!*
    goto v0230;

v0306:
    v0228 = stack[-7];
    v0227 = elt(env, 15); // proc
    if (v0228 == v0227) goto v0310;
    v0227 = qvalue(elt(env, 2)); // nil
    goto v0311;

v0311:
    if (v0227 == nil) goto v0267;
    v0228 = elt(env, 16); // "Syntax error in procedure header"
    v0227 = qvalue(elt(env, 2)); // nil
    fn = elt(env, 51); // symerr
    v0227 = (*qfn2(fn))(qenv(fn), v0228, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    goto v0267;

v0310:
    v0227 = stack[-6];
    v0228 = Llength(nil, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    v0227 = (LispObject)33; // 2
    v0227 = (LispObject)greaterp2(v0228, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    v0227 = v0227 ? lisp_true : nil;
    env = stack[-9];
    goto v0311;

v0308:
    v0227 = stack[-2];
    if (!symbolp(v0227)) v0227 = nil;
    else { v0227 = qfastgets(v0227);
           if (v0227 != nil) { v0227 = elt(v0227, 55); // delim
#ifdef RECORD_GET
             if (v0227 == SPID_NOPROP)
                record_get(elt(fastget_names, 55), 0),
                v0227 = nil;
             else record_get(elt(fastget_names, 55), 1),
                v0227 = lisp_true; }
           else record_get(elt(fastget_names, 55), 0); }
#else
             if (v0227 == SPID_NOPROP) v0227 = nil; else v0227 = lisp_true; }}
#endif
    if (v0227 == nil) goto v0312;
    v0227 = qvalue(elt(env, 2)); // nil
    goto v0309;

v0312:
    v0227 = stack[-2];
    if (!symbolp(v0227)) v0227 = nil;
    else { v0227 = qfastgets(v0227);
           if (v0227 != nil) { v0227 = elt(v0227, 11); // switch!*
#ifdef RECORD_GET
             if (v0227 != SPID_NOPROP)
                record_get(elt(fastget_names, 11), 1);
             else record_get(elt(fastget_names, 11), 0),
                v0227 = nil; }
           else record_get(elt(fastget_names, 11), 0); }
#else
             if (v0227 == SPID_NOPROP) v0227 = nil; }}
#endif
    if (v0227 == nil) goto v0313;
    v0228 = stack[-2];
    v0227 = elt(env, 11); // !(
    if (v0228 == v0227) goto v0313;
    v0227 = qvalue(elt(env, 2)); // nil
    goto v0309;

v0313:
    v0227 = stack[-2];
    if (!symbolp(v0227)) v0227 = nil;
    else { v0227 = qfastgets(v0227);
           if (v0227 != nil) { v0227 = elt(v0227, 23); // infix
#ifdef RECORD_GET
             if (v0227 != SPID_NOPROP)
                record_get(elt(fastget_names, 23), 1);
             else record_get(elt(fastget_names, 23), 0),
                v0227 = nil; }
           else record_get(elt(fastget_names, 23), 0); }
#else
             if (v0227 == SPID_NOPROP) v0227 = nil; }}
#endif
    if (v0227 == nil) goto v0314;
    v0227 = qvalue(elt(env, 2)); // nil
    goto v0309;

v0314:
    v0227 = qvalue(elt(env, 12)); // !*eoldelimp
    if (v0227 == nil) goto v0315;
    v0228 = stack[-2];
    v0227 = qvalue(elt(env, 9)); // !$eol!$
    v0227 = (v0228 == v0227 ? lisp_true : nil);
    goto v0316;

v0316:
    v0227 = (v0227 == nil ? lisp_true : nil);
    goto v0309;

v0315:
    v0227 = qvalue(elt(env, 2)); // nil
    goto v0316;

v0307:
    v0227 = qvalue(elt(env, 2)); // nil
    goto v0309;

v0297:
    v0228 = stack[-7];
    v0227 = elt(env, 15); // proc
    if (v0228 == v0227) goto v0317;
    v0228 = stack[-4];
    v0227 = elt(env, 38); // endstatfn
    v0227 = Lflagp(nil, v0228, v0227);
    env = stack[-9];
    if (v0227 == nil) goto v0318;
    v0227 = qvalue(elt(env, 22)); // t
    goto v0298;

v0318:
    v0227 = qvalue(elt(env, 10)); // nxtsym!*
    fn = elt(env, 60); // delcp
    v0227 = (*qfn1(fn))(qenv(fn), v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    if (v0227 == nil) goto v0319;
    v0227 = qvalue(elt(env, 2)); // nil
    goto v0298;

v0319:
    v0228 = qvalue(elt(env, 10)); // nxtsym!*
    v0227 = elt(env, 39); // !,
    v0227 = (v0228 == v0227 ? lisp_true : nil);
    v0227 = (v0227 == nil ? lisp_true : nil);
    goto v0298;

v0317:
    v0227 = qvalue(elt(env, 2)); // nil
    goto v0298;

v0295:
    v0227 = qvalue(elt(env, 6)); // !*reduce4
    if (v0227 == nil) goto v0320;
    v0227 = qvalue(elt(env, 2)); // nil
    goto v0321;

v0321:
    if (v0227 == nil) goto v0232;
    v0228 = elt(env, 8); // decstat
    v0227 = qvalue(elt(env, 2)); // nil
    fn = elt(env, 57); // lispapply
    v0228 = (*qfn2(fn))(qenv(fn), v0228, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    v0227 = stack[-6];
    v0227 = cons(v0228, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    stack[-6] = v0227;
    goto v0230;

v0320:
    v0228 = stack[-3];
    v0227 = elt(env, 7); // type
    v0227 = Lflagp(nil, v0228, v0227);
    env = stack[-9];
    goto v0321;

v0235:
    fn = elt(env, 50); // eolcheck
    v0227 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    v0228 = stack[-3];
    v0227 = elt(env, 19); // !*comma!*
    if (v0228 == v0227) goto v0322;
    fn = elt(env, 54); // scan
    v0227 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    stack[-2] = v0227;
    if (!consp(v0227)) goto v0323;
    v0227 = qvalue(elt(env, 22)); // t
    goto v0324;

v0324:
    if (!(v0227 == nil)) goto v0325;
    v0228 = stack[-2];
    v0227 = elt(env, 5); // !*rpar!*
    if (v0228 == v0227) goto v0326;
    v0228 = stack[-2];
    v0227 = elt(env, 19); // !*comma!*
    if (v0228 == v0227) goto v0327;
    v0227 = stack[-2];
    if (!symbolp(v0227)) v0227 = nil;
    else { v0227 = qfastgets(v0227);
           if (v0227 != nil) { v0227 = elt(v0227, 55); // delim
#ifdef RECORD_GET
             if (v0227 == SPID_NOPROP)
                record_get(elt(fastget_names, 55), 0),
                v0227 = nil;
             else record_get(elt(fastget_names, 55), 1),
                v0227 = lisp_true; }
           else record_get(elt(fastget_names, 55), 0); }
#else
             if (v0227 == SPID_NOPROP) v0227 = nil; else v0227 = lisp_true; }}
#endif
    goto v0328;

v0328:
    if (v0227 == nil) goto v0329;
    v0227 = stack[-4];
    if (v0227 == nil) goto v0330;
    v0227 = qvalue(elt(env, 2)); // nil
    stack[-4] = v0227;
    goto v0330;

v0330:
    v0228 = stack[-3];
    v0227 = stack[-6];
    v0227 = cons(v0228, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    stack[-6] = v0227;
    goto v0266;

v0329:
    v0228 = stack[-2];
    v0227 = elt(env, 4); // !*lpar!*
    if (v0228 == v0227) goto v0331;
    v0227 = qvalue(elt(env, 2)); // nil
    goto v0332;

v0332:
    if (!(v0227 == nil)) goto v0231;

v0325:
    v0227 = stack[-6];
    if (!(v0227 == nil)) goto v0251;
    v0228 = stack[-3];
    v0227 = elt(env, 25); // unary
    v0227 = get(v0228, v0227);
    env = stack[-9];
    stack[-3] = v0227;
    if (!(v0227 == nil)) goto v0333;
    v0228 = elt(env, 26); // "Redundant operator"
    v0227 = qvalue(elt(env, 2)); // nil
    fn = elt(env, 51); // symerr
    v0227 = (*qfn2(fn))(qenv(fn), v0228, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    goto v0333;

v0333:
    v0228 = elt(env, 27); // !*!*un!*!*
    v0227 = stack[-8];
    v0227 = cons(v0228, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    stack[-8] = v0227;
    goto v0265;

v0331:
    fn = elt(env, 50); // eolcheck
    v0227 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    if (v0227 == nil) goto v0334;
    v0227 = qvalue(elt(env, 2)); // nil
    goto v0332;

v0334:
    v0227 = elt(env, 18); // paren
    fn = elt(env, 61); // xread
    v0227 = (*qfn1(fn))(qenv(fn), v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    stack[-2] = v0227;
    if (!consp(v0227)) goto v0335;
    v0227 = stack[-2];
    v0228 = qcar(v0227);
    v0227 = elt(env, 19); // !*comma!*
    if (v0228 == v0227) goto v0336;
    v0227 = qvalue(elt(env, 2)); // nil
    goto v0332;

v0336:
    v0228 = stack[-3];
    v0227 = stack[-2];
    v0227 = qcdr(v0227);
    v0227 = cons(v0228, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    stack[-3] = v0227;
    goto v0332;

v0335:
    v0227 = qvalue(elt(env, 2)); // nil
    goto v0332;

v0327:
    v0227 = qvalue(elt(env, 22)); // t
    goto v0328;

v0326:
    v0227 = qvalue(elt(env, 22)); // t
    goto v0328;

v0323:
    v0227 = stack[-2];
    fn = elt(env, 58); // toknump
    v0227 = (*qfn1(fn))(qenv(fn), v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    goto v0324;

v0322:
    v0227 = qvalue(elt(env, 22)); // t
    goto v0324;

v0234:
    v0227 = stack[-7];
    if (v0227 == nil) goto v0337;
    v0228 = stack[-7];
    v0227 = elt(env, 23); // group
    if (v0228 == v0227) goto v0338;
    v0228 = stack[-7];
    v0227 = elt(env, 15); // proc
    v0227 = (v0228 == v0227 ? lisp_true : nil);
    goto v0339;

v0339:
    if (v0227 == nil) goto v0246;
    v0228 = elt(env, 24); // "Too many right parentheses"
    v0227 = qvalue(elt(env, 2)); // nil
    fn = elt(env, 51); // symerr
    v0227 = (*qfn2(fn))(qenv(fn), v0228, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    goto v0235;

v0338:
    v0227 = qvalue(elt(env, 22)); // t
    goto v0339;

v0337:
    v0227 = qvalue(elt(env, 22)); // t
    goto v0339;

v0233:
    fn = elt(env, 50); // eolcheck
    v0227 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    v0227 = qvalue(elt(env, 2)); // nil
    stack[-4] = v0227;
    fn = elt(env, 54); // scan
    v0228 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    v0227 = elt(env, 5); // !*rpar!*
    if (v0228 == v0227) goto v0340;
    v0228 = stack[-6];
    v0227 = elt(env, 17); // struct
    v0227 = Lflagpcar(nil, v0228, v0227);
    env = stack[-9];
    if (v0227 == nil) goto v0341;
    v0227 = stack[-6];
    v0227 = qcar(v0227);
    v0227 = CC_xread1(env, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    stack[-3] = v0227;
    goto v0342;

v0342:
    v0228 = stack[-7];
    v0227 = elt(env, 17); // struct
    v0227 = Lflagp(nil, v0228, v0227);
    env = stack[-9];
    if (v0227 == nil) goto v0343;
    v0227 = stack[-3];
    fn = elt(env, 62); // remcomma
    v0227 = (*qfn1(fn))(qenv(fn), v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    stack[-3] = v0227;
    goto v0305;

v0343:
    v0228 = stack[-3];
    v0227 = elt(env, 19); // !*comma!*
    if (!consp(v0228)) goto v0305;
    v0228 = qcar(v0228);
    if (!(v0228 == v0227)) goto v0305;
    v0227 = stack[-6];
    if (v0227 == nil) goto v0344;
    v0227 = stack[-6];
    v0229 = qcar(v0227);
    v0227 = stack[-3];
    v0228 = qcdr(v0227);
    v0227 = stack[-6];
    v0227 = qcdr(v0227);
    v0227 = acons(v0229, v0228, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    stack[-6] = v0227;
    goto v0267;

v0344:
    v0228 = stack[-7];
    v0227 = elt(env, 20); // lambda
    if (v0228 == v0227) goto v0305;
    v0228 = elt(env, 21); // "Improper delimiter"
    v0227 = qvalue(elt(env, 2)); // nil
    fn = elt(env, 51); // symerr
    v0227 = (*qfn2(fn))(qenv(fn), v0228, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    goto v0267;

v0341:
    v0227 = elt(env, 18); // paren
    v0227 = CC_xread1(env, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    stack[-3] = v0227;
    goto v0342;

v0340:
    v0227 = stack[-6];
    if (v0227 == nil) goto v0267;
    v0227 = stack[-6];
    v0227 = qcar(v0227);
    v0228 = ncons(v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    v0227 = stack[-6];
    v0227 = qcdr(v0227);
    v0227 = cons(v0228, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-9];
    stack[-6] = v0227;
    goto v0267;
// error exit handlers
v0238:
    popv(10);
    return nil;
}



// Code for qremf

static LispObject CC_qremf(LispObject env,
                         LispObject v0000, LispObject v0345)
{
    LispObject nil = C_nil;
    LispObject v0403, v0174;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qremf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0345,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0345);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[-5] = v0345;
    stack[-6] = v0000;
// end of prologue
    stack[-4] = qvalue(elt(env, 1)); // !*exp
    qvalue(elt(env, 1)) = nil; // !*exp
    v0403 = qvalue(elt(env, 2)); // t
    qvalue(elt(env, 1)) = v0403; // !*exp
    v0403 = stack[-5];
    if (!consp(v0403)) goto v0234;
    v0403 = stack[-5];
    v0403 = qcar(v0403);
    v0403 = (consp(v0403) ? nil : lisp_true);
    goto v0340;

v0340:
    if (v0403 == nil) goto v0232;
    v0174 = stack[-6];
    v0403 = stack[-5];
    fn = elt(env, 4); // qremd
    v0403 = (*qfn2(fn))(qenv(fn), v0174, v0403);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-8];
    goto v0005;

v0005:
    qvalue(elt(env, 1)) = stack[-4]; // !*exp
    { popv(9); return onevalue(v0403); }

v0232:
    v0403 = qvalue(elt(env, 3)); // nil
    v0403 = ncons(v0403);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-8];
    stack[-1] = v0403;
    goto v0404;

v0404:
    v0403 = stack[-6];
    if (!consp(v0403)) goto v0405;
    v0403 = stack[-6];
    v0403 = qcar(v0403);
    v0403 = (consp(v0403) ? nil : lisp_true);
    goto v0406;

v0406:
    if (v0403 == nil) goto v0407;
    stack[0] = stack[-1];
    v0174 = qvalue(elt(env, 3)); // nil
    v0403 = stack[-6];
    v0403 = cons(v0174, v0403);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-8];
    fn = elt(env, 5); // praddf
    v0403 = (*qfn2(fn))(qenv(fn), stack[0], v0403);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-8];
    goto v0005;

v0407:
    v0403 = stack[-6];
    v0403 = qcar(v0403);
    v0403 = qcar(v0403);
    v0174 = qcar(v0403);
    v0403 = stack[-5];
    v0403 = qcar(v0403);
    v0403 = qcar(v0403);
    v0403 = qcar(v0403);
    if (v0174 == v0403) goto v0408;
    v0403 = stack[-6];
    v0403 = qcar(v0403);
    v0403 = qcar(v0403);
    v0174 = qcar(v0403);
    v0403 = stack[-5];
    v0403 = qcar(v0403);
    v0403 = qcar(v0403);
    v0403 = qcar(v0403);
    fn = elt(env, 6); // ordop
    v0403 = (*qfn2(fn))(qenv(fn), v0174, v0403);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-8];
    if (v0403 == nil) goto v0409;
    v0403 = stack[-6];
    v0403 = qcar(v0403);
    v0174 = qcdr(v0403);
    v0403 = stack[-5];
    v0403 = CC_qremf(env, v0174, v0403);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-8];
    stack[-3] = v0403;
    v0403 = stack[-6];
    v0403 = qcar(v0403);
    v0174 = qcar(v0403);
    v0403 = (LispObject)17; // 1
    v0403 = cons(v0174, v0403);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-8];
    v0174 = ncons(v0403);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-8];
    v0403 = stack[-3];
    v0403 = qcar(v0403);
    fn = elt(env, 7); // multf
    stack[0] = (*qfn2(fn))(qenv(fn), v0174, v0403);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-8];
    v0403 = stack[-6];
    v0403 = qcar(v0403);
    v0174 = qcar(v0403);
    v0403 = (LispObject)17; // 1
    v0403 = cons(v0174, v0403);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-8];
    v0174 = ncons(v0403);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-8];
    v0403 = stack[-3];
    v0403 = qcdr(v0403);
    fn = elt(env, 7); // multf
    v0403 = (*qfn2(fn))(qenv(fn), v0174, v0403);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-8];
    v0403 = cons(stack[0], v0403);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-8];
    fn = elt(env, 5); // praddf
    v0403 = (*qfn2(fn))(qenv(fn), stack[-1], v0403);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-8];
    stack[-1] = v0403;
    v0403 = stack[-6];
    v0403 = qcdr(v0403);
    stack[-6] = v0403;
    goto v0404;

v0409:
    stack[0] = stack[-1];
    v0174 = qvalue(elt(env, 3)); // nil
    v0403 = stack[-6];
    v0403 = cons(v0174, v0403);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-8];
    fn = elt(env, 5); // praddf
    v0403 = (*qfn2(fn))(qenv(fn), stack[0], v0403);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-8];
    goto v0005;

v0408:
    v0403 = stack[-6];
    v0403 = qcar(v0403);
    v0403 = qcar(v0403);
    v0174 = qcdr(v0403);
    v0403 = stack[-5];
    v0403 = qcar(v0403);
    v0403 = qcar(v0403);
    v0403 = qcdr(v0403);
    v0174 = difference2(v0174, v0403);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-8];
    stack[-7] = v0174;
    v0403 = (LispObject)1; // 0
    v0403 = (LispObject)lessp2(v0174, v0403);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    v0403 = v0403 ? lisp_true : nil;
    env = stack[-8];
    if (v0403 == nil) goto v0410;
    stack[0] = stack[-1];
    v0174 = qvalue(elt(env, 3)); // nil
    v0403 = stack[-6];
    v0403 = cons(v0174, v0403);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-8];
    fn = elt(env, 5); // praddf
    v0403 = (*qfn2(fn))(qenv(fn), stack[0], v0403);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-8];
    goto v0005;

v0410:
    v0403 = stack[-6];
    v0403 = qcar(v0403);
    v0174 = qcdr(v0403);
    v0403 = stack[-5];
    v0403 = qcar(v0403);
    v0403 = qcdr(v0403);
    v0403 = CC_qremf(env, v0174, v0403);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-8];
    stack[-3] = v0403;
    v0403 = stack[-6];
    v0403 = qcar(v0403);
    v0174 = qcar(v0403);
    v0403 = (LispObject)17; // 1
    v0403 = cons(v0174, v0403);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-8];
    v0174 = ncons(v0403);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-8];
    v0403 = stack[-3];
    v0403 = qcdr(v0403);
    fn = elt(env, 7); // multf
    v0403 = (*qfn2(fn))(qenv(fn), v0174, v0403);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-8];
    stack[-2] = v0403;
    stack[0] = stack[-1];
    v0174 = stack[-7];
    v0403 = (LispObject)1; // 0
    if (v0174 == v0403) goto v0314;
    v0403 = stack[-6];
    v0403 = qcar(v0403);
    v0403 = qcar(v0403);
    v0174 = qcar(v0403);
    v0403 = stack[-7];
    fn = elt(env, 8); // to
    v0174 = (*qfn2(fn))(qenv(fn), v0174, v0403);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-8];
    v0403 = (LispObject)17; // 1
    v0403 = cons(v0174, v0403);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-8];
    v0174 = ncons(v0403);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-8];
    v0403 = stack[-3];
    v0403 = qcar(v0403);
    fn = elt(env, 7); // multf
    v0403 = (*qfn2(fn))(qenv(fn), v0174, v0403);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-8];
    v0174 = v0403;
    goto v0411;

v0411:
    v0403 = stack[-2];
    v0403 = cons(v0174, v0403);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-8];
    fn = elt(env, 5); // praddf
    v0403 = (*qfn2(fn))(qenv(fn), stack[0], v0403);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-8];
    stack[-1] = v0403;
    v0403 = stack[-3];
    v0403 = qcar(v0403);
    if (v0403 == nil) goto v0412;
    stack[0] = stack[-6];
    v0174 = stack[-7];
    v0403 = (LispObject)1; // 0
    if (v0174 == v0403) goto v0413;
    v0403 = stack[-6];
    v0403 = qcar(v0403);
    v0403 = qcar(v0403);
    v0174 = qcar(v0403);
    v0403 = stack[-7];
    fn = elt(env, 8); // to
    v0174 = (*qfn2(fn))(qenv(fn), v0174, v0403);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-8];
    v0403 = (LispObject)17; // 1
    v0403 = cons(v0174, v0403);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-8];
    v0174 = ncons(v0403);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-8];
    v0403 = stack[-5];
    fn = elt(env, 7); // multf
    v0403 = (*qfn2(fn))(qenv(fn), v0174, v0403);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-8];
    stack[-6] = v0403;
    goto v0196;

v0196:
    v0403 = stack[-3];
    v0403 = qcar(v0403);
    fn = elt(env, 9); // negf
    v0403 = (*qfn1(fn))(qenv(fn), v0403);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-8];
    fn = elt(env, 7); // multf
    v0403 = (*qfn2(fn))(qenv(fn), stack[-6], v0403);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-8];
    fn = elt(env, 10); // addf
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v0403);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-8];
    v0403 = stack[-2];
    fn = elt(env, 9); // negf
    v0403 = (*qfn1(fn))(qenv(fn), v0403);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-8];
    fn = elt(env, 10); // addf
    v0403 = (*qfn2(fn))(qenv(fn), stack[0], v0403);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-8];
    goto v0414;

v0414:
    stack[-6] = v0403;
    goto v0404;

v0413:
    v0403 = stack[-5];
    stack[-6] = v0403;
    goto v0196;

v0412:
    v0403 = stack[-6];
    v0403 = qcdr(v0403);
    goto v0414;

v0314:
    v0403 = stack[-3];
    v0403 = qcar(v0403);
    v0174 = v0403;
    goto v0411;

v0405:
    v0403 = qvalue(elt(env, 2)); // t
    goto v0406;

v0234:
    v0403 = qvalue(elt(env, 2)); // t
    goto v0340;
// error exit handlers
v0170:
    env = stack[-8];
    qvalue(elt(env, 1)) = stack[-4]; // !*exp
    popv(9);
    return nil;
}



// Code for remove!-free!-vars!*

static LispObject CC_removeKfreeKvarsH(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0030, v0155;
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
    v0155 = v0000;
// end of prologue
    v0030 = qvalue(elt(env, 1)); // t
    stack[0] = qvalue(elt(env, 2)); // !*!*noremove!*!*
    qvalue(elt(env, 2)) = v0030; // !*!*noremove!*!*
    v0030 = v0155;
    fn = elt(env, 3); // remove!-free!-vars
    v0030 = (*qfn1(fn))(qenv(fn), v0030);
    nil = C_nil;
    if (exception_pending()) goto v0005;
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; // !*!*noremove!*!*
    { popv(2); return onevalue(v0030); }
// error exit handlers
v0005:
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; // !*!*noremove!*!*
    popv(2);
    return nil;
}



// Code for tmsf

static LispObject CC_tmsf(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0219, v0217, v0422;
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
    v0219 = (LispObject)1; // 0
    v0422 = v0219;
    goto v0005;

v0005:
    v0219 = stack[-1];
    if (!consp(v0219)) goto v0267;
    v0219 = stack[-1];
    v0219 = qcar(v0219);
    v0219 = (consp(v0219) ? nil : lisp_true);
    goto v0423;

v0423:
    if (v0219 == nil) goto v0258;
    v0219 = stack[-1];
    if (v0219 == nil) { popv(4); return onevalue(v0422); }
    v0219 = v0422;
    popv(4);
    return add1(v0219);

v0258:
    stack[-2] = v0422;
    v0219 = stack[-1];
    v0219 = qcar(v0219);
    v0219 = qcar(v0219);
    v0219 = qcar(v0219);
    stack[0] = v0219;
    fn = elt(env, 3); // sfp
    v0219 = (*qfn1(fn))(qenv(fn), v0219);
    nil = C_nil;
    if (exception_pending()) goto v0388;
    env = stack[-3];
    if (v0219 == nil) goto v0424;
    v0219 = stack[0];
    v0219 = CC_tmsf(env, v0219);
    nil = C_nil;
    if (exception_pending()) goto v0388;
    env = stack[-3];
    stack[0] = v0219;
    goto v0425;

v0425:
    v0219 = stack[-1];
    v0219 = qcar(v0219);
    v0219 = qcdr(v0219);
    fn = elt(env, 4); // tmsf!*
    v0219 = (*qfn1(fn))(qenv(fn), v0219);
    nil = C_nil;
    if (exception_pending()) goto v0388;
    env = stack[-3];
    v0219 = plus2(stack[0], v0219);
    nil = C_nil;
    if (exception_pending()) goto v0388;
    env = stack[-3];
    v0219 = plus2(stack[-2], v0219);
    nil = C_nil;
    if (exception_pending()) goto v0388;
    env = stack[-3];
    v0422 = v0219;
    v0219 = stack[-1];
    v0219 = qcar(v0219);
    v0219 = qcar(v0219);
    v0217 = qcdr(v0219);
    v0219 = (LispObject)17; // 1
    if (v0217 == v0219) goto v0426;
    v0219 = stack[-1];
    v0219 = qcar(v0219);
    v0219 = qcar(v0219);
    v0217 = qcdr(v0219);
    v0219 = (LispObject)33; // 2
    if (v0217 == v0219) goto v0427;
    v0217 = v0422;
    v0219 = (LispObject)33; // 2
    v0219 = plus2(v0217, v0219);
    nil = C_nil;
    if (exception_pending()) goto v0388;
    env = stack[-3];
    v0422 = v0219;
    goto v0426;

v0426:
    v0219 = stack[-1];
    v0219 = qcdr(v0219);
    stack[-1] = v0219;
    goto v0005;

v0427:
    v0219 = v0422;
    v0219 = add1(v0219);
    nil = C_nil;
    if (exception_pending()) goto v0388;
    env = stack[-3];
    v0422 = v0219;
    goto v0426;

v0424:
    v0219 = (LispObject)17; // 1
    stack[0] = v0219;
    goto v0425;

v0267:
    v0219 = qvalue(elt(env, 1)); // t
    goto v0423;
// error exit handlers
v0388:
    popv(4);
    return nil;
}



// Code for ibalp_simpterm

static LispObject CC_ibalp_simpterm(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0408, v0415;
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

v0435:
    v0408 = stack[0];
    if (!consp(v0408)) goto v0155;
    v0408 = stack[0];
    v0408 = qcar(v0408);
    stack[-1] = v0408;
    v0408 = stack[-1];
    fn = elt(env, 3); // ibalp_boolfp
    v0408 = (*qfn1(fn))(qenv(fn), v0408);
    nil = C_nil;
    if (exception_pending()) goto v0436;
    env = stack[-5];
    if (v0408 == nil) goto v0423;
    stack[-4] = stack[-1];
    v0408 = stack[0];
    v0408 = qcdr(v0408);
    stack[-3] = v0408;
    v0408 = stack[-3];
    if (v0408 == nil) goto v0437;
    v0408 = stack[-3];
    v0408 = qcar(v0408);
    v0408 = CC_ibalp_simpterm(env, v0408);
    nil = C_nil;
    if (exception_pending()) goto v0436;
    env = stack[-5];
    v0408 = ncons(v0408);
    nil = C_nil;
    if (exception_pending()) goto v0436;
    env = stack[-5];
    stack[-1] = v0408;
    stack[-2] = v0408;
    goto v0246;

v0246:
    v0408 = stack[-3];
    v0408 = qcdr(v0408);
    stack[-3] = v0408;
    v0408 = stack[-3];
    if (v0408 == nil) goto v0438;
    stack[0] = stack[-1];
    v0408 = stack[-3];
    v0408 = qcar(v0408);
    v0408 = CC_ibalp_simpterm(env, v0408);
    nil = C_nil;
    if (exception_pending()) goto v0436;
    env = stack[-5];
    v0408 = ncons(v0408);
    nil = C_nil;
    if (exception_pending()) goto v0436;
    env = stack[-5];
    v0408 = Lrplacd(nil, stack[0], v0408);
    nil = C_nil;
    if (exception_pending()) goto v0436;
    env = stack[-5];
    v0408 = stack[-1];
    v0408 = qcdr(v0408);
    stack[-1] = v0408;
    goto v0246;

v0438:
    v0408 = stack[-2];
    goto v0251;

v0251:
    {
        LispObject v0216 = stack[-4];
        popv(6);
        return cons(v0216, v0408);
    }

v0437:
    v0408 = qvalue(elt(env, 1)); // nil
    goto v0251;

v0423:
    v0408 = stack[0];
    fn = elt(env, 4); // reval
    v0408 = (*qfn1(fn))(qenv(fn), v0408);
    nil = C_nil;
    if (exception_pending()) goto v0436;
    env = stack[-5];
    stack[0] = v0408;
    v0415 = stack[0];
    v0408 = stack[-1];
    if (!consp(v0415)) goto v0427;
    v0415 = qcar(v0415);
    if (!(v0415 == v0408)) goto v0427;
    v0415 = stack[-1];
    v0408 = elt(env, 2); // "Boolean function"
    fn = elt(env, 5); // typerr
    v0408 = (*qfn2(fn))(qenv(fn), v0415, v0408);
    nil = C_nil;
    if (exception_pending()) goto v0436;
    env = stack[-5];
    goto v0427;

v0427:
    v0408 = stack[0];
    stack[0] = v0408;
    goto v0435;

v0155:
    v0408 = stack[0];
    {
        popv(6);
        fn = elt(env, 6); // ibalp_simpatom
        return (*qfn1(fn))(qenv(fn), v0408);
    }
// error exit handlers
v0436:
    popv(6);
    return nil;
}



// Code for vdp_zero!?

static LispObject CC_vdp_zeroW(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0015;
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
    v0015 = v0000;
// end of prologue
    fn = elt(env, 1); // vdp_poly
    v0015 = (*qfn1(fn))(qenv(fn), v0015);
    errexit();
    v0015 = (v0015 == nil ? lisp_true : nil);
    return onevalue(v0015);
}



// Code for omsir

static LispObject CC_omsir(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0315, v0379;
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
    v0315 = qvalue(elt(env, 1)); // nil
    stack[-2] = v0315;
    v0379 = qvalue(elt(env, 2)); // atts
    v0315 = elt(env, 3); // name
    fn = elt(env, 12); // find
    v0315 = (*qfn2(fn))(qenv(fn), v0379, v0315);
    nil = C_nil;
    if (exception_pending()) goto v0445;
    env = stack[-6];
    v0315 = Lintern(nil, v0315);
    nil = C_nil;
    if (exception_pending()) goto v0445;
    env = stack[-6];
    stack[-5] = v0315;
    v0379 = qvalue(elt(env, 2)); // atts
    v0315 = elt(env, 4); // cd
    fn = elt(env, 12); // find
    v0315 = (*qfn2(fn))(qenv(fn), v0379, v0315);
    nil = C_nil;
    if (exception_pending()) goto v0445;
    env = stack[-6];
    v0315 = Lintern(nil, v0315);
    nil = C_nil;
    if (exception_pending()) goto v0445;
    env = stack[-6];
    stack[-3] = v0315;
    v0315 = stack[-5];
    v0379 = Lexplode(nil, v0315);
    nil = C_nil;
    if (exception_pending()) goto v0445;
    env = stack[-6];
    v0315 = elt(env, 5); // (v e c t o r)
    if (equal(v0379, v0315)) goto v0270;
    v0315 = stack[-5];
    v0379 = Lintern(nil, v0315);
    nil = C_nil;
    if (exception_pending()) goto v0445;
    env = stack[-6];
    v0315 = qvalue(elt(env, 7)); // mmleq!*
    v0315 = Lmember(nil, v0379, v0315);
    stack[-4] = v0315;
    goto v0246;

v0246:
    v0315 = stack[-4];
    if (!(v0315 == nil)) goto v0226;
    v0379 = stack[-5];
    v0315 = qvalue(elt(env, 8)); // special_cases!*
    v0315 = Lassoc(nil, v0379, v0315);
    stack[-4] = v0315;
    if (v0315 == nil) goto v0446;
    v0315 = stack[-4];
    v0315 = Lreverse(nil, v0315);
    nil = C_nil;
    if (exception_pending()) goto v0445;
    env = stack[-6];
    v0315 = qcar(v0315);
    stack[-2] = v0315;
    v0315 = stack[-2];
    if (v0315 == nil) goto v0418;
    v0315 = stack[-2];
    v0315 = ncons(v0315);
    nil = C_nil;
    if (exception_pending()) goto v0445;
    env = stack[-6];
    stack[-2] = v0315;
    goto v0418;

v0418:
    v0315 = stack[-4];
    v0315 = Lreverse(nil, v0315);
    nil = C_nil;
    if (exception_pending()) goto v0445;
    env = stack[-6];
    v0315 = qcdr(v0315);
    stack[0] = qcar(v0315);
    v0315 = stack[-4];
    v0315 = qcdr(v0315);
    v0315 = Lreverse(nil, v0315);
    nil = C_nil;
    if (exception_pending()) goto v0445;
    env = stack[-6];
    v0315 = qcdr(v0315);
    v0315 = qcdr(v0315);
    v0315 = Lreverse(nil, v0315);
    nil = C_nil;
    if (exception_pending()) goto v0445;
    env = stack[-6];
    v0315 = cons(stack[0], v0315);
    nil = C_nil;
    if (exception_pending()) goto v0445;
    env = stack[-6];
    stack[-4] = v0315;
    goto v0226;

v0226:
    v0315 = stack[-4];
    if (v0315 == nil) goto v0390;
    v0315 = stack[-4];
    v0379 = qcar(v0315);
    v0315 = qvalue(elt(env, 10)); // valid_om!*
    v0315 = Lassoc(nil, v0379, v0315);
    stack[-1] = v0315;
    goto v0390;

v0390:
    v0315 = stack[-1];
    if (v0315 == nil) goto v0386;
    v0315 = stack[-1];
    v0315 = qcdr(v0315);
    v0315 = qcar(v0315);
    stack[-1] = v0315;
    goto v0386;

v0386:
    v0315 = stack[-4];
    if (v0315 == nil) goto v0447;
    v0379 = stack[-3];
    v0315 = stack[-1];
    v0315 = (v0315 == nil ? lisp_true : nil);
    v0315 = (equal(v0379, v0315) ? lisp_true : nil);
    goto v0204;

v0204:
    if (v0315 == nil) goto v0206;
    v0315 = stack[-5];
    {
        popv(7);
        fn = elt(env, 13); // encodeir
        return (*qfn1(fn))(qenv(fn), v0315);
    }

v0206:
    v0315 = stack[-4];
    v0379 = qcar(v0315);
    v0315 = stack[-2];
    popv(7);
    return list2(v0379, v0315);

v0447:
    v0315 = qvalue(elt(env, 11)); // t
    goto v0204;

v0446:
    v0379 = stack[-5];
    v0315 = qvalue(elt(env, 9)); // special_cases2!*
    v0379 = Lassoc(nil, v0379, v0315);
    v0315 = v0379;
    if (v0379 == nil) goto v0226;
    v0379 = v0315;
    v0379 = qcdr(v0379);
    v0379 = qcar(v0379);
    v0315 = qcdr(v0315);
    v0315 = qcdr(v0315);
    {
        popv(7);
        fn = elt(env, 14); // apply
        return (*qfn2(fn))(qenv(fn), v0379, v0315);
    }

v0270:
    v0315 = elt(env, 6); // (vectorml linalg1)
    stack[-4] = v0315;
    goto v0246;
// error exit handlers
v0445:
    popv(7);
    return nil;
}



// Code for evallessp

static LispObject CC_evallessp(LispObject env,
                         LispObject v0000, LispObject v0345)
{
    LispObject nil = C_nil;
    LispObject v0448, v0230;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evallessp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0230 = v0345;
    v0448 = v0000;
// end of prologue
    {
        fn = elt(env, 1); // evalgreaterp
        return (*qfn2(fn))(qenv(fn), v0230, v0448);
    }
}



// Code for ldt!-tvar

static LispObject CC_ldtKtvar(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0251, v0253, v0430;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ldt-tvar");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0251 = v0000;
// end of prologue
    v0251 = qcar(v0251);
    v0251 = qcar(v0251);
    v0253 = v0251;
    v0251 = v0253;
    v0430 = elt(env, 1); // df
    if (!consp(v0251)) return onevalue(v0253);
    v0251 = qcar(v0251);
    if (!(v0251 == v0430)) return onevalue(v0253);
    v0251 = v0253;
    v0251 = qcdr(v0251);
    v0251 = qcar(v0251);
    return onevalue(v0251);
}



// Code for actual_alst

static LispObject CC_actual_alst(LispObject env,
                         LispObject v0000, LispObject v0345)
{
    LispObject nil = C_nil;
    LispObject v0449, v0400, v0406;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for actual_alst");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0345,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0345);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0345;
    stack[-1] = v0000;
// end of prologue
    v0406 = nil;
    goto v0030;

v0030:
    v0449 = stack[-1];
    if (v0449 == nil) goto v0005;
    v0449 = stack[-1];
    v0449 = qcar(v0449);
    v0400 = qcar(v0449);
    v0449 = stack[0];
    v0449 = Lmemq(nil, v0400, v0449);
    if (v0449 == nil) goto v0437;
    v0449 = stack[-1];
    v0449 = qcar(v0449);
    v0400 = v0406;
    v0449 = cons(v0449, v0400);
    nil = C_nil;
    if (exception_pending()) goto v0450;
    env = stack[-2];
    v0406 = v0449;
    v0449 = stack[-1];
    v0449 = qcdr(v0449);
    stack[-1] = v0449;
    goto v0030;

v0437:
    v0449 = stack[-1];
    v0449 = qcdr(v0449);
    stack[-1] = v0449;
    goto v0030;

v0005:
    v0449 = v0406;
    {
        popv(3);
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(qenv(fn), v0449);
    }
// error exit handlers
v0450:
    popv(3);
    return nil;
}



// Code for simp!-sign

static LispObject CC_simpKsign(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0030;
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
    v0030 = v0000;
// end of prologue
    v0030 = qcar(v0030);
    fn = elt(env, 1); // reval
    v0030 = (*qfn1(fn))(qenv(fn), v0030);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); // simp!-sign1
        return (*qfn1(fn))(qenv(fn), v0030);
    }
// error exit handlers
v0155:
    popv(1);
    return nil;
}



// Code for symbid

static LispObject CC_symbid(LispObject env,
                         LispObject v0000, LispObject v0345)
{
    LispObject nil = C_nil;
    LispObject v0217, v0422, v0457, v0305;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for symbid");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0345,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0345);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0457 = v0345;
    stack[0] = v0000;
// end of prologue
    v0217 = qvalue(elt(env, 1)); // fname!*
    if (v0217 == nil) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    v0422 = qvalue(elt(env, 2)); // ftype!*
    v0217 = elt(env, 3); // (macro smacro inline)
    v0217 = Lmemq(nil, v0422, v0217);
    if (v0217 == nil) goto v0253;
    v0217 = qvalue(elt(env, 8)); // nil
    goto v0448;

v0448:
    if (v0217 == nil) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    v0305 = elt(env, 9); // "nonlocal use of undeclared variable"
    v0457 = stack[0];
    v0422 = elt(env, 10); // "in procedure"
    v0217 = qvalue(elt(env, 1)); // fname!*
    v0217 = list4(v0305, v0457, v0422, v0217);
    nil = C_nil;
    if (exception_pending()) goto v0388;
    env = stack[-1];
    fn = elt(env, 11); // lprim
    v0217 = (*qfn1(fn))(qenv(fn), v0217);
    nil = C_nil;
    if (exception_pending()) goto v0388;
    { LispObject res = stack[0]; popv(2); return onevalue(res); }

v0253:
    v0217 = stack[0];
    v0422 = v0457;
    v0217 = Latsoc(nil, v0217, v0422);
    if (!(v0217 == nil)) goto v0266;
    v0217 = stack[0];
    v0217 = Lsymbol_specialp(nil, v0217);
    nil = C_nil;
    if (exception_pending()) goto v0388;
    env = stack[-1];
    if (!(v0217 == nil)) goto v0266;
    v0217 = stack[0];
    v0217 = Lsymbol_globalp(nil, v0217);
    env = stack[-1];
    if (!(v0217 == nil)) goto v0266;
    v0217 = stack[0];
    if (v0217 == nil) goto v0458;
    v0422 = stack[0];
    v0217 = qvalue(elt(env, 4)); // t
    if (v0422 == v0217) goto v0421;
    v0217 = stack[0];
    if (!symbolp(v0217)) v0217 = nil;
    else { v0217 = qfastgets(v0217);
           if (v0217 != nil) { v0217 = elt(v0217, 17); // share
#ifdef RECORD_GET
             if (v0217 == SPID_NOPROP)
                record_get(elt(fastget_names, 17), 0),
                v0217 = nil;
             else record_get(elt(fastget_names, 17), 1),
                v0217 = lisp_true; }
           else record_get(elt(fastget_names, 17), 0); }
#else
             if (v0217 == SPID_NOPROP) v0217 = nil; else v0217 = lisp_true; }}
#endif
    if (v0217 == nil) goto v0459;
    v0217 = qvalue(elt(env, 4)); // t
    goto v0266;

v0266:
    v0217 = (v0217 == nil ? lisp_true : nil);
    goto v0448;

v0459:
    v0217 = qvalue(elt(env, 5)); // !*comp
    if (!(v0217 == nil)) goto v0266;
    v0217 = qvalue(elt(env, 6)); // !*cref
    if (!(v0217 == nil)) goto v0266;
    v0422 = stack[0];
    v0217 = elt(env, 7); // constant!?
    v0217 = get(v0422, v0217);
    env = stack[-1];
    goto v0266;

v0421:
    v0217 = qvalue(elt(env, 4)); // t
    goto v0266;

v0458:
    v0217 = qvalue(elt(env, 4)); // t
    goto v0266;
// error exit handlers
v0388:
    popv(2);
    return nil;
}



// Code for getmatelem

static LispObject CC_getmatelem(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0472, v0473, v0376;
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

v0404:
    v0472 = stack[-2];
    v0473 = Llength(nil, v0472);
    nil = C_nil;
    if (exception_pending()) goto v0474;
    env = stack[-4];
    v0472 = (LispObject)49; // 3
    if (v0473 == v0472) goto v0155;
    v0473 = stack[-2];
    v0472 = elt(env, 1); // "matrix element"
    fn = elt(env, 9); // typerr
    v0472 = (*qfn2(fn))(qenv(fn), v0473, v0472);
    nil = C_nil;
    if (exception_pending()) goto v0474;
    env = stack[-4];
    goto v0155;

v0155:
    v0472 = stack[-2];
    v0472 = qcar(v0472);
    if (!symbolp(v0472)) v0472 = nil;
    else { v0472 = qfastgets(v0472);
           if (v0472 != nil) { v0472 = elt(v0472, 4); // avalue
#ifdef RECORD_GET
             if (v0472 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v0472 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v0472 == SPID_NOPROP) v0472 = nil; }}
#endif
    stack[-3] = v0472;
    v0472 = stack[-3];
    if (v0472 == nil) goto v0402;
    v0472 = stack[-3];
    v0473 = qcar(v0472);
    v0472 = elt(env, 3); // matrix
    v0472 = (v0473 == v0472 ? lisp_true : nil);
    v0472 = (v0472 == nil ? lisp_true : nil);
    goto v0401;

v0401:
    if (v0472 == nil) goto v0475;
    v0472 = stack[-2];
    v0473 = qcar(v0472);
    v0472 = elt(env, 4); // "matrix"
    fn = elt(env, 9); // typerr
    v0472 = (*qfn2(fn))(qenv(fn), v0473, v0472);
    nil = C_nil;
    if (exception_pending()) goto v0474;
    env = stack[-4];
    goto v0429;

v0429:
    v0472 = stack[-2];
    v0472 = qcdr(v0472);
    v0472 = qcar(v0472);
    fn = elt(env, 10); // reval_without_mod
    v0472 = (*qfn1(fn))(qenv(fn), v0472);
    nil = C_nil;
    if (exception_pending()) goto v0474;
    env = stack[-4];
    stack[0] = v0472;
    v0472 = stack[0];
    v0472 = integerp(v0472);
    if (v0472 == nil) goto v0389;
    v0473 = stack[0];
    v0472 = (LispObject)1; // 0
    v0472 = (LispObject)lesseq2(v0473, v0472);
    nil = C_nil;
    if (exception_pending()) goto v0474;
    v0472 = v0472 ? lisp_true : nil;
    env = stack[-4];
    goto v0476;

v0476:
    if (v0472 == nil) goto v0477;
    v0473 = stack[0];
    v0472 = elt(env, 8); // "positive integer"
    fn = elt(env, 9); // typerr
    v0472 = (*qfn2(fn))(qenv(fn), v0473, v0472);
    nil = C_nil;
    if (exception_pending()) goto v0474;
    env = stack[-4];
    goto v0477;

v0477:
    v0472 = stack[-3];
    v0473 = qcdr(v0472);
    v0472 = stack[0];
    fn = elt(env, 11); // nth
    v0472 = (*qfn2(fn))(qenv(fn), v0473, v0472);
    nil = C_nil;
    if (exception_pending()) goto v0474;
    env = stack[-4];
    stack[-3] = v0472;
    v0472 = stack[-2];
    v0472 = qcdr(v0472);
    v0472 = qcdr(v0472);
    v0472 = qcar(v0472);
    fn = elt(env, 10); // reval_without_mod
    v0472 = (*qfn1(fn))(qenv(fn), v0472);
    nil = C_nil;
    if (exception_pending()) goto v0474;
    env = stack[-4];
    stack[0] = v0472;
    v0472 = stack[0];
    v0472 = integerp(v0472);
    if (v0472 == nil) goto v0478;
    v0473 = stack[0];
    v0472 = (LispObject)1; // 0
    v0472 = (LispObject)lesseq2(v0473, v0472);
    nil = C_nil;
    if (exception_pending()) goto v0474;
    v0472 = v0472 ? lisp_true : nil;
    env = stack[-4];
    goto v0372;

v0372:
    if (v0472 == nil) goto v0208;
    v0473 = stack[0];
    v0472 = elt(env, 8); // "positive integer"
    fn = elt(env, 9); // typerr
    v0472 = (*qfn2(fn))(qenv(fn), v0473, v0472);
    nil = C_nil;
    if (exception_pending()) goto v0474;
    env = stack[-4];
    goto v0208;

v0208:
    v0473 = stack[-3];
    v0472 = stack[0];
    {
        popv(5);
        fn = elt(env, 11); // nth
        return (*qfn2(fn))(qenv(fn), v0473, v0472);
    }

v0478:
    v0472 = qvalue(elt(env, 2)); // t
    goto v0372;

v0389:
    v0472 = qvalue(elt(env, 2)); // t
    goto v0476;

v0475:
    v0472 = stack[-3];
    v0472 = qcdr(v0472);
    v0473 = qcar(v0472);
    stack[-3] = v0473;
    v0472 = elt(env, 5); // mat
    if (!consp(v0473)) goto v0397;
    v0473 = qcar(v0473);
    if (v0473 == v0472) goto v0429;
    else goto v0397;

v0397:
    v0472 = stack[-3];
    if (symbolp(v0472)) goto v0479;
    stack[-1] = elt(env, 3); // matrix
    stack[0] = (LispObject)17; // 1
    v0376 = elt(env, 6); // "Matrix"
    v0472 = stack[-2];
    v0473 = qcar(v0472);
    v0472 = elt(env, 7); // "not set"
    v0472 = list3(v0376, v0473, v0472);
    nil = C_nil;
    if (exception_pending()) goto v0474;
    env = stack[-4];
    fn = elt(env, 12); // rerror
    v0472 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v0472);
    nil = C_nil;
    if (exception_pending()) goto v0474;
    env = stack[-4];
    goto v0429;

v0479:
    v0473 = stack[-3];
    v0472 = stack[-2];
    v0472 = qcdr(v0472);
    v0472 = cons(v0473, v0472);
    nil = C_nil;
    if (exception_pending()) goto v0474;
    env = stack[-4];
    stack[-2] = v0472;
    goto v0404;

v0402:
    v0472 = qvalue(elt(env, 2)); // t
    goto v0401;
// error exit handlers
v0474:
    popv(5);
    return nil;
}



// Code for dl_get2

static LispObject CC_dl_get2(LispObject env,
                         LispObject v0000, LispObject v0345)
{
    LispObject nil = C_nil;
    LispObject v0437, v0452, v0420;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dl_get2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0345,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0345);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0437 = v0345;
    v0452 = v0000;
// end of prologue

v0030:
    v0420 = v0452;
    if (v0420 == nil) { popv(2); return onevalue(v0437); }
    v0420 = v0452;
    v0420 = qcar(v0420);
    if (!symbolp(v0420)) v0420 = nil;
    else { v0420 = qfastgets(v0420);
           if (v0420 != nil) { v0420 = elt(v0420, 32); // dummy
#ifdef RECORD_GET
             if (v0420 != SPID_NOPROP)
                record_get(elt(fastget_names, 32), 1);
             else record_get(elt(fastget_names, 32), 0),
                v0420 = nil; }
           else record_get(elt(fastget_names, 32), 0); }
#else
             if (v0420 == SPID_NOPROP) v0420 = nil; }}
#endif
    if (v0420 == nil) goto v0270;
    v0420 = v0452;
    v0420 = qcdr(v0420);
    stack[0] = v0420;
    v0420 = qcar(v0452);
    v0452 = v0437;
    v0437 = qvalue(elt(env, 1)); // nil
    fn = elt(env, 2); // di_insert
    v0437 = (*qfnn(fn))(qenv(fn), 3, v0420, v0452, v0437);
    nil = C_nil;
    if (exception_pending()) goto v0449;
    env = stack[-1];
    v0452 = stack[0];
    goto v0030;

v0270:
    v0452 = qcdr(v0452);
    goto v0030;
// error exit handlers
v0449:
    popv(2);
    return nil;
}



// Code for invbf

static LispObject CC_invbf(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0232, v0423, v0267;
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
    v0232 = v0000;
// end of prologue
    v0267 = qvalue(elt(env, 1)); // bfone!*
    v0423 = v0232;
    v0232 = qvalue(elt(env, 2)); // !:bprec!:
    fn = elt(env, 3); // divide!:
    v0232 = (*qfnn(fn))(qenv(fn), 3, v0267, v0423, v0232);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 4); // normbf
        return (*qfn1(fn))(qenv(fn), v0232);
    }
// error exit handlers
v0233:
    popv(1);
    return nil;
}



// Code for degree!-in!-variable

static LispObject CC_degreeKinKvariable(LispObject env,
                         LispObject v0000, LispObject v0345)
{
    LispObject nil = C_nil;
    LispObject v0295, v0480;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for degree-in-variable");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0345,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0345);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0345;
    stack[-1] = v0000;
// end of prologue
    v0295 = stack[-1];
    if (!consp(v0295)) goto v0005;
    v0295 = stack[-1];
    v0295 = qcar(v0295);
    v0295 = (consp(v0295) ? nil : lisp_true);
    goto v0071;

v0071:
    if (v0295 == nil) goto v0325;
    v0295 = (LispObject)1; // 0
    { popv(4); return onevalue(v0295); }

v0325:
    v0295 = stack[-1];
    v0295 = qcar(v0295);
    v0480 = qcdr(v0295);
    v0295 = (LispObject)1; // 0
    if (v0480 == v0295) goto v0234;
    v0480 = stack[0];
    v0295 = stack[-1];
    v0295 = qcar(v0295);
    v0295 = qcar(v0295);
    v0295 = qcar(v0295);
    if (equal(v0480, v0295)) goto v0246;
    v0295 = stack[-1];
    v0295 = qcar(v0295);
    v0480 = qcdr(v0295);
    v0295 = stack[0];
    stack[-2] = CC_degreeKinKvariable(env, v0480, v0295);
    nil = C_nil;
    if (exception_pending()) goto v0220;
    env = stack[-3];
    v0295 = stack[-1];
    v0480 = qcdr(v0295);
    v0295 = stack[0];
    v0295 = CC_degreeKinKvariable(env, v0480, v0295);
    nil = C_nil;
    if (exception_pending()) goto v0220;
    env = stack[-3];
    {
        LispObject v0321 = stack[-2];
        popv(4);
        fn = elt(env, 3); // max
        return (*qfn2(fn))(qenv(fn), v0321, v0295);
    }

v0246:
    v0295 = stack[-1];
    v0295 = qcar(v0295);
    v0295 = qcar(v0295);
    v0295 = qcdr(v0295);
    { popv(4); return onevalue(v0295); }

v0234:
    v0295 = elt(env, 2); // "Polynomial with a zero coefficient found"
    {
        popv(4);
        fn = elt(env, 4); // errorf
        return (*qfn1(fn))(qenv(fn), v0295);
    }

v0005:
    v0295 = qvalue(elt(env, 1)); // t
    goto v0071;
// error exit handlers
v0220:
    popv(4);
    return nil;
}



// Code for update_kc_list

static LispObject CC_update_kc_list(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0482, v0419;
    LispObject fn;
    LispObject v0006, v0345, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "update_kc_list");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0345 = va_arg(aa, LispObject);
    v0006 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for update_kc_list");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0006,v0345,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0345,v0006);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0006;
    stack[-1] = v0345;
    stack[-2] = v0000;
// end of prologue
    v0419 = stack[-1];
    v0482 = stack[-2];
    v0482 = qcdr(v0482);
    fn = elt(env, 1); // list_assoc
    v0482 = (*qfn2(fn))(qenv(fn), v0419, v0482);
    nil = C_nil;
    if (exception_pending()) goto v0453;
    env = stack[-4];
    v0419 = v0482;
    v0482 = v0419;
    if (v0482 == nil) goto v0483;
    stack[-3] = v0419;
    v0482 = v0419;
    v0482 = qcar(v0482);
    stack[-1] = qcar(v0482);
    v0482 = v0419;
    v0482 = qcar(v0482);
    v0419 = qcdr(v0482);
    v0482 = stack[0];
    fn = elt(env, 2); // addf
    v0482 = (*qfn2(fn))(qenv(fn), v0419, v0482);
    nil = C_nil;
    if (exception_pending()) goto v0453;
    env = stack[-4];
    v0482 = cons(stack[-1], v0482);
    nil = C_nil;
    if (exception_pending()) goto v0453;
    env = stack[-4];
    v0482 = Lrplaca(nil, stack[-3], v0482);
    nil = C_nil;
    if (exception_pending()) goto v0453;
    { LispObject res = stack[-2]; popv(5); return onevalue(res); }

v0483:
    v0482 = stack[-2];
    stack[-3] = qcar(v0482);
    v0419 = stack[-1];
    v0482 = stack[0];
    v0419 = cons(v0419, v0482);
    nil = C_nil;
    if (exception_pending()) goto v0453;
    v0482 = stack[-2];
    v0482 = qcdr(v0482);
    {
        LispObject v0295 = stack[-3];
        popv(5);
        return list2star(v0295, v0419, v0482);
    }
// error exit handlers
v0453:
    popv(5);
    return nil;
}



// Code for lalr_resolve_conflicts

static LispObject CC_lalr_resolve_conflicts(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0437, v0452;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lalr_resolve_conflicts");
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
    v0437 = v0000;
// end of prologue
    stack[-2] = nil;
    stack[-1] = v0437;
    goto v0071;

v0071:
    v0437 = stack[-1];
    if (v0437 == nil) goto v0155;
    v0437 = stack[-1];
    v0437 = qcar(v0437);
    v0452 = v0437;
    v0437 = v0452;
    stack[0] = qcar(v0437);
    v0437 = v0452;
    v0437 = qcdr(v0437);
    fn = elt(env, 2); // lalr_resolve_conflicts1
    v0452 = (*qfn1(fn))(qenv(fn), v0437);
    nil = C_nil;
    if (exception_pending()) goto v0400;
    env = stack[-3];
    v0437 = stack[-2];
    v0437 = acons(stack[0], v0452, v0437);
    nil = C_nil;
    if (exception_pending()) goto v0400;
    env = stack[-3];
    stack[-2] = v0437;
    v0437 = stack[-1];
    v0437 = qcdr(v0437);
    stack[-1] = v0437;
    goto v0071;

v0155:
    v0437 = stack[-2];
        popv(4);
        return Lreverse(nil, v0437);
// error exit handlers
v0400:
    popv(4);
    return nil;
}



// Code for sq2sspl

static LispObject CC_sq2sspl(LispObject env,
                         LispObject v0000, LispObject v0345)
{
    LispObject nil = C_nil;
    LispObject v0431, v0432;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sq2sspl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0345,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0345);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0345;
    stack[-1] = v0000;
// end of prologue
    stack[-2] = nil;
    goto v0155;

v0155:
    v0431 = stack[-1];
    if (!consp(v0431)) goto v0267;
    v0431 = stack[-1];
    v0431 = qcar(v0431);
    v0431 = (consp(v0431) ? nil : lisp_true);
    goto v0423;

v0423:
    if (v0431 == nil) goto v0246;
    v0431 = stack[-1];
    v0432 = v0431;
    goto v0005;

v0005:
    v0431 = stack[-2];
    if (v0431 == nil) { popv(4); return onevalue(v0432); }
    v0431 = stack[-2];
    v0431 = qcar(v0431);
    v0431 = Lappend(nil, v0431, v0432);
    nil = C_nil;
    if (exception_pending()) goto v0398;
    env = stack[-3];
    v0432 = v0431;
    v0431 = stack[-2];
    v0431 = qcdr(v0431);
    stack[-2] = v0431;
    goto v0005;

v0246:
    v0431 = stack[-1];
    v0432 = qcar(v0431);
    v0431 = stack[0];
    fn = elt(env, 2); // sq2sstm
    v0432 = (*qfn2(fn))(qenv(fn), v0432, v0431);
    nil = C_nil;
    if (exception_pending()) goto v0398;
    env = stack[-3];
    v0431 = stack[-2];
    v0431 = cons(v0432, v0431);
    nil = C_nil;
    if (exception_pending()) goto v0398;
    env = stack[-3];
    stack[-2] = v0431;
    v0431 = stack[-1];
    v0431 = qcdr(v0431);
    stack[-1] = v0431;
    goto v0155;

v0267:
    v0431 = qvalue(elt(env, 1)); // t
    goto v0423;
// error exit handlers
v0398:
    popv(4);
    return nil;
}



// Code for ibalp_lenisone

static LispObject CC_ibalp_lenisone(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0231, v0232;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_lenisone");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0232 = v0000;
// end of prologue
    v0231 = v0232;
    if (v0231 == nil) goto v0011;
    v0231 = v0232;
    v0231 = qcdr(v0231);
    v0231 = (v0231 == nil ? lisp_true : nil);
    return onevalue(v0231);

v0011:
    v0231 = qvalue(elt(env, 1)); // nil
    return onevalue(v0231);
}



// Code for dvfsf_mk2

static LispObject CC_dvfsf_mk2(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0423, v0267, v0233;
    LispObject v0006, v0345, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "dvfsf_mk2");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0345 = va_arg(aa, LispObject);
    v0006 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dvfsf_mk2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0423 = v0006;
    v0267 = v0345;
    v0233 = v0000;
// end of prologue
    return list3(v0233, v0267, v0423);
}



// Code for attributesml

static LispObject CC_attributesml(LispObject env,
                         LispObject v0000, LispObject v0345)
{
    LispObject nil = C_nil;
    LispObject v0220, v0321;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for attributesml");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0345,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0345);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0345;
    stack[-1] = v0000;
// end of prologue
    v0220 = stack[-1];
    if (v0220 == nil) goto v0155;
    v0220 = elt(env, 2); // " "
    v0220 = Lprinc(nil, v0220);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-2];
    v0220 = stack[-1];
    v0220 = qcar(v0220);
    v0220 = qcar(v0220);
    v0220 = Lprinc(nil, v0220);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-2];
    v0220 = elt(env, 3); // "="""
    v0220 = Lprinc(nil, v0220);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-2];
    v0220 = stack[-1];
    v0220 = qcar(v0220);
    v0321 = qcar(v0220);
    v0220 = elt(env, 4); // definitionurl
    if (v0321 == v0220) goto v0431;
    v0220 = stack[-1];
    v0220 = qcar(v0220);
    v0220 = qcdr(v0220);
    v0321 = qcar(v0220);
    v0220 = elt(env, 5); // vectorml
    if (v0321 == v0220) goto v0420;
    v0220 = stack[-1];
    v0220 = qcar(v0220);
    v0220 = qcdr(v0220);
    v0220 = qcar(v0220);
    v0220 = Lprinc(nil, v0220);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-2];
    goto v0253;

v0253:
    v0220 = elt(env, 8); // """"
    v0220 = Lprinc(nil, v0220);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-2];
    v0220 = stack[-1];
    v0321 = qcdr(v0220);
    v0220 = stack[0];
    v0220 = CC_attributesml(env, v0321, v0220);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    goto v0030;

v0030:
    v0220 = nil;
    { popv(3); return onevalue(v0220); }

v0420:
    v0220 = elt(env, 6); // "vector"
    v0220 = Lprinc(nil, v0220);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-2];
    goto v0253;

v0431:
    v0220 = stack[-1];
    v0220 = qcar(v0220);
    v0220 = qcdr(v0220);
    v0220 = qcar(v0220);
    fn = elt(env, 9); // mathml_list2string
    v0220 = (*qfn1(fn))(qenv(fn), v0220);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-2];
    goto v0253;

v0155:
    v0220 = stack[0];
    v0220 = Lprinc(nil, v0220);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-2];
    v0220 = elt(env, 1); // ">"
    v0220 = Lprinc(nil, v0220);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    goto v0030;
// error exit handlers
v0417:
    popv(3);
    return nil;
}



// Code for maprin

static LispObject CC_maprin(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0433, v0429, v0456;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for maprin");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0429 = v0000;
// end of prologue
    v0433 = qvalue(elt(env, 1)); // outputhandler!*
    if (v0433 == nil) goto v0015;
    v0433 = qvalue(elt(env, 1)); // outputhandler!*
    v0456 = elt(env, 0); // maprin
        return Lapply2(nil, 3, v0433, v0456, v0429);

v0015:
    v0433 = qvalue(elt(env, 2)); // overflowed!*
    if (v0433 == nil) goto v0251;
    v0433 = nil;
    return onevalue(v0433);

v0251:
    v0433 = (LispObject)1; // 0
    {
        fn = elt(env, 3); // maprint
        return (*qfn2(fn))(qenv(fn), v0429, v0433);
    }
}



// Code for dm!-eq

static LispObject CC_dmKeq(LispObject env,
                         LispObject v0000, LispObject v0345)
{
    LispObject nil = C_nil;
    LispObject v0230, v0231;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dm-eq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0345,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0345);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// copy arguments values to proper place
    v0230 = v0345;
    v0231 = v0000;
// end of prologue
    fn = elt(env, 1); // dm!-difference
    v0230 = (*qfn2(fn))(qenv(fn), v0231, v0230);
    nil = C_nil;
    if (exception_pending()) goto v0232;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); // !:zerop
        return (*qfn1(fn))(qenv(fn), v0230);
    }
// error exit handlers
v0232:
    popv(1);
    return nil;
}



// Code for modminusp!:

static LispObject CC_modminuspT(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0430, v0258;
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
    v0430 = v0000;
// end of prologue
    v0258 = qvalue(elt(env, 1)); // !*balanced_mod
    if (v0258 == nil) goto v0266;
    v0258 = (LispObject)33; // 2
    v0430 = qcdr(v0430);
    v0430 = times2(v0258, v0430);
    nil = C_nil;
    if (exception_pending()) goto v0434;
    env = stack[0];
    v0258 = qvalue(elt(env, 2)); // current!-modulus
        popv(1);
        return Lgreaterp(nil, v0430, v0258);

v0266:
    v0430 = qvalue(elt(env, 3)); // nil
    { popv(1); return onevalue(v0430); }
// error exit handlers
v0434:
    popv(1);
    return nil;
}



// Code for vbcgcd

static LispObject CC_vbcgcd(LispObject env,
                         LispObject v0000, LispObject v0345)
{
    LispObject nil = C_nil;
    LispObject v0390, v0485;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vbcgcd");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0345,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0345);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0345;
    stack[-1] = v0000;
// end of prologue
    v0485 = stack[-1];
    v0390 = (LispObject)-1599; // -100
    fn = elt(env, 4); // vbcsize
    v0390 = (*qfn2(fn))(qenv(fn), v0485, v0390);
    nil = C_nil;
    if (exception_pending()) goto v0410;
    env = stack[-2];
    if (v0390 == nil) goto v0230;
    v0485 = stack[0];
    v0390 = (LispObject)-1599; // -100
    fn = elt(env, 4); // vbcsize
    v0390 = (*qfn2(fn))(qenv(fn), v0485, v0390);
    nil = C_nil;
    if (exception_pending()) goto v0410;
    env = stack[-2];
    v0390 = (v0390 == nil ? lisp_true : nil);
    goto v0448;

v0448:
    if (v0390 == nil) goto v0406;
    v0390 = elt(env, 2); // (1 . 1)
    { popv(3); return onevalue(v0390); }

v0406:
    v0390 = stack[-1];
    v0485 = qcdr(v0390);
    v0390 = (LispObject)17; // 1
    if (v0485 == v0390) goto v0438;
    v0390 = qvalue(elt(env, 3)); // nil
    goto v0444;

v0444:
    if (v0390 == nil) goto v0387;
    v0390 = stack[-1];
    v0390 = qcar(v0390);
    v0390 = integerp(v0390);
    if (v0390 == nil) goto v0436;
    v0390 = stack[0];
    v0390 = qcar(v0390);
    v0390 = integerp(v0390);
    if (v0390 == nil) goto v0436;
    v0390 = stack[-1];
    v0485 = qcar(v0390);
    v0390 = stack[0];
    v0390 = qcar(v0390);
    v0485 = Lgcd(nil, v0485, v0390);
    nil = C_nil;
    if (exception_pending()) goto v0410;
    v0390 = (LispObject)17; // 1
    popv(3);
    return cons(v0485, v0390);

v0436:
    v0390 = stack[-1];
    v0485 = qcar(v0390);
    v0390 = stack[0];
    v0390 = qcar(v0390);
    fn = elt(env, 5); // gcdf!*
    v0485 = (*qfn2(fn))(qenv(fn), v0485, v0390);
    nil = C_nil;
    if (exception_pending()) goto v0410;
    v0390 = (LispObject)17; // 1
    popv(3);
    return cons(v0485, v0390);

v0387:
    v0485 = (LispObject)17; // 1
    v0390 = (LispObject)17; // 1
    popv(3);
    return cons(v0485, v0390);

v0438:
    v0390 = stack[0];
    v0485 = qcdr(v0390);
    v0390 = (LispObject)17; // 1
    v0390 = (v0485 == v0390 ? lisp_true : nil);
    goto v0444;

v0230:
    v0390 = qvalue(elt(env, 1)); // t
    goto v0448;
// error exit handlers
v0410:
    popv(3);
    return nil;
}



// Code for listeval

static LispObject CC_listeval(LispObject env,
                         LispObject v0000, LispObject v0345)
{
    LispObject nil = C_nil;
    LispObject v0379, v0380, v0494;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for listeval");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0345,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0345);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-3] = v0345;
    stack[0] = v0000;
// end of prologue
    v0379 = qvalue(elt(env, 1)); // simpcount!*
    v0380 = add1(v0379);
    nil = C_nil;
    if (exception_pending()) goto v0462;
    env = stack[-5];
    qvalue(elt(env, 1)) = v0380; // simpcount!*
    v0379 = qvalue(elt(env, 2)); // simplimit!*
    v0379 = (LispObject)greaterp2(v0380, v0379);
    nil = C_nil;
    if (exception_pending()) goto v0462;
    v0379 = v0379 ? lisp_true : nil;
    env = stack[-5];
    if (v0379 == nil) goto v0011;
    v0379 = (LispObject)1; // 0
    qvalue(elt(env, 1)) = v0379; // simpcount!*
    v0494 = elt(env, 3); // rlisp
    v0380 = (LispObject)289; // 18
    v0379 = elt(env, 4); // "Simplification recursion too deep"
    fn = elt(env, 9); // rerror
    v0379 = (*qfnn(fn))(qenv(fn), 3, v0494, v0380, v0379);
    nil = C_nil;
    if (exception_pending()) goto v0462;
    env = stack[-5];
    goto v0011;

v0011:
    v0379 = stack[0];
    if (!consp(v0379)) goto v0429;
    v0379 = stack[0];
    v0380 = qcar(v0379);
    v0379 = elt(env, 5); // list
    if (v0380 == v0379) goto v0399;
    v0379 = stack[0];
    v0380 = qcar(v0379);
    v0379 = elt(env, 7); // listfn
    v0379 = get(v0380, v0379);
    env = stack[-5];
    v0380 = v0379;
    v0379 = v0380;
    if (v0379 == nil) goto v0495;
    v0494 = v0380;
    v0379 = stack[0];
    v0380 = qcdr(v0379);
    v0379 = stack[-3];
    v0379 = Lapply2(nil, 3, v0494, v0380, v0379);
    nil = C_nil;
    if (exception_pending()) goto v0462;
    env = stack[-5];
    goto v0433;

v0433:
    stack[0] = v0379;
    v0379 = qvalue(elt(env, 1)); // simpcount!*
    v0379 = sub1(v0379);
    nil = C_nil;
    if (exception_pending()) goto v0462;
    env = stack[-5];
    qvalue(elt(env, 1)) = v0379; // simpcount!*
    { LispObject res = stack[0]; popv(6); return onevalue(res); }

v0495:
    v0494 = elt(env, 3); // rlisp
    v0380 = (LispObject)305; // 19
    v0379 = elt(env, 8); // "Illegal operation on lists"
    fn = elt(env, 9); // rerror
    v0379 = (*qfnn(fn))(qenv(fn), 3, v0494, v0380, v0379);
    nil = C_nil;
    if (exception_pending()) goto v0462;
    env = stack[-5];
    goto v0433;

v0399:
    v0379 = stack[0];
    v0379 = qcdr(v0379);
    stack[-4] = v0379;
    v0379 = stack[-4];
    if (v0379 == nil) goto v0454;
    v0379 = stack[-4];
    v0379 = qcar(v0379);
    v0380 = v0379;
    v0379 = stack[-3];
    fn = elt(env, 10); // reval1
    v0379 = (*qfn2(fn))(qenv(fn), v0380, v0379);
    nil = C_nil;
    if (exception_pending()) goto v0462;
    env = stack[-5];
    v0379 = ncons(v0379);
    nil = C_nil;
    if (exception_pending()) goto v0462;
    env = stack[-5];
    stack[-1] = v0379;
    stack[-2] = v0379;
    goto v0418;

v0418:
    v0379 = stack[-4];
    v0379 = qcdr(v0379);
    stack[-4] = v0379;
    v0379 = stack[-4];
    if (v0379 == nil) goto v0218;
    stack[0] = stack[-1];
    v0379 = stack[-4];
    v0379 = qcar(v0379);
    v0380 = v0379;
    v0379 = stack[-3];
    fn = elt(env, 10); // reval1
    v0379 = (*qfn2(fn))(qenv(fn), v0380, v0379);
    nil = C_nil;
    if (exception_pending()) goto v0462;
    env = stack[-5];
    v0379 = ncons(v0379);
    nil = C_nil;
    if (exception_pending()) goto v0462;
    env = stack[-5];
    v0379 = Lrplacd(nil, stack[0], v0379);
    nil = C_nil;
    if (exception_pending()) goto v0462;
    env = stack[-5];
    v0379 = stack[-1];
    v0379 = qcdr(v0379);
    stack[-1] = v0379;
    goto v0418;

v0218:
    v0379 = stack[-2];
    goto v0394;

v0394:
    fn = elt(env, 11); // makelist
    v0379 = (*qfn1(fn))(qenv(fn), v0379);
    nil = C_nil;
    if (exception_pending()) goto v0462;
    env = stack[-5];
    goto v0433;

v0454:
    v0379 = qvalue(elt(env, 6)); // nil
    goto v0394;

v0429:
    v0379 = stack[0];
    if (!symbolp(v0379)) v0379 = nil;
    else { v0379 = qfastgets(v0379);
           if (v0379 != nil) { v0379 = elt(v0379, 4); // avalue
#ifdef RECORD_GET
             if (v0379 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v0379 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v0379 == SPID_NOPROP) v0379 = nil; }}
#endif
    v0380 = v0379;
    v0379 = stack[0];
    if (!symbolp(v0379)) v0379 = nil;
    else { v0379 = qfastgets(v0379);
           if (v0379 != nil) { v0379 = elt(v0379, 17); // share
#ifdef RECORD_GET
             if (v0379 == SPID_NOPROP)
                record_get(elt(fastget_names, 17), 0),
                v0379 = nil;
             else record_get(elt(fastget_names, 17), 1),
                v0379 = lisp_true; }
           else record_get(elt(fastget_names, 17), 0); }
#else
             if (v0379 == SPID_NOPROP) v0379 = nil; else v0379 = lisp_true; }}
#endif
    if (v0379 == nil) goto v0458;
    v0379 = stack[0];
    fn = elt(env, 12); // eval
    v0379 = (*qfn1(fn))(qenv(fn), v0379);
    nil = C_nil;
    if (exception_pending()) goto v0462;
    env = stack[-5];
    v0380 = v0379;
    goto v0420;

v0420:
    v0379 = stack[-3];
    v0379 = CC_listeval(env, v0380, v0379);
    nil = C_nil;
    if (exception_pending()) goto v0462;
    env = stack[-5];
    goto v0433;

v0458:
    v0379 = v0380;
    if (v0379 == nil) goto v0396;
    v0379 = v0380;
    v0379 = qcdr(v0379);
    v0379 = qcar(v0379);
    v0380 = v0379;
    goto v0420;

v0396:
    v0380 = stack[0];
    v0379 = elt(env, 5); // list
    fn = elt(env, 13); // typerr
    v0379 = (*qfn2(fn))(qenv(fn), v0380, v0379);
    nil = C_nil;
    if (exception_pending()) goto v0462;
    env = stack[-5];
    v0380 = v0379;
    goto v0420;
// error exit handlers
v0462:
    popv(6);
    return nil;
}



// Code for simprepart

static LispObject CC_simprepart(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0071, v0005;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for simprepart");
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
    v0071 = qvalue(elt(env, 1)); // nil
    stack[0] = qvalue(elt(env, 2)); // !*factor
    qvalue(elt(env, 2)) = v0071; // !*factor
    v0071 = v0005;
    v0071 = qcar(v0071);
    fn = elt(env, 3); // simp!*
    v0071 = (*qfn1(fn))(qenv(fn), v0071);
    nil = C_nil;
    if (exception_pending()) goto v0448;
    env = stack[-1];
    fn = elt(env, 4); // repartsq
    v0071 = (*qfn1(fn))(qenv(fn), v0071);
    nil = C_nil;
    if (exception_pending()) goto v0448;
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; // !*factor
    { popv(2); return onevalue(v0071); }
// error exit handlers
v0448:
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; // !*factor
    popv(2);
    return nil;
}



// Code for mkprogn

static LispObject CC_mkprogn(LispObject env,
                         LispObject v0000, LispObject v0345)
{
    LispObject nil = C_nil;
    LispObject v0444, v0449, v0400, v0406;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mkprogn");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0400 = v0345;
    v0406 = v0000;
// end of prologue
    v0449 = v0400;
    v0444 = elt(env, 1); // progn
    if (!consp(v0449)) goto v0429;
    v0449 = qcar(v0449);
    if (!(v0449 == v0444)) goto v0429;
    v0444 = elt(env, 1); // progn
    v0449 = v0406;
    v0400 = qcdr(v0400);
    return list2star(v0444, v0449, v0400);

v0429:
    v0444 = elt(env, 1); // progn
    v0449 = v0406;
    return list3(v0444, v0449, v0400);
}



// Code for pv_times1

static LispObject CC_pv_times1(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0456, v0246, v0270;
    LispObject fn;
    LispObject v0006, v0345, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "pv_times1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0345 = va_arg(aa, LispObject);
    v0006 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pv_times1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0006,v0345,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0345,v0006);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    v0246 = v0006;
    stack[0] = v0345;
    v0456 = v0000;
// end of prologue

v0155:
    v0270 = v0456;
    if (v0270 == nil) { popv(3); return onevalue(v0246); }
    v0270 = v0456;
    v0270 = qcdr(v0270);
    stack[-1] = v0270;
    v0270 = qcar(v0456);
    v0456 = stack[0];
    fn = elt(env, 1); // pv_times2
    v0456 = (*qfnn(fn))(qenv(fn), 3, v0270, v0456, v0246);
    nil = C_nil;
    if (exception_pending()) goto v0425;
    env = stack[-2];
    v0246 = v0456;
    v0456 = stack[-1];
    goto v0155;
// error exit handlers
v0425:
    popv(3);
    return nil;
}



// Code for b!:ordexp

static LispObject CC_bTordexp(LispObject env,
                         LispObject v0000, LispObject v0345)
{
    LispObject nil = C_nil;
    LispObject v0424, v0438;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for b:ordexp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0345,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0345);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0345;
    stack[-1] = v0000;
// end of prologue

v0435:
    v0424 = stack[-1];
    if (v0424 == nil) goto v0015;
    v0424 = stack[-1];
    v0438 = qcar(v0424);
    v0424 = stack[0];
    v0424 = qcar(v0424);
    v0424 = (LispObject)greaterp2(v0438, v0424);
    nil = C_nil;
    if (exception_pending()) goto v0496;
    v0424 = v0424 ? lisp_true : nil;
    env = stack[-2];
    if (!(v0424 == nil)) { popv(3); return onevalue(v0424); }
    v0424 = stack[-1];
    v0438 = qcar(v0424);
    v0424 = stack[0];
    v0424 = qcar(v0424);
    if (equal(v0438, v0424)) goto v0452;
    v0424 = qvalue(elt(env, 2)); // nil
    { popv(3); return onevalue(v0424); }

v0452:
    v0424 = stack[-1];
    v0438 = qcdr(v0424);
    v0424 = stack[0];
    v0424 = qcdr(v0424);
    stack[-1] = v0438;
    stack[0] = v0424;
    goto v0435;

v0015:
    v0424 = qvalue(elt(env, 1)); // t
    { popv(3); return onevalue(v0424); }
// error exit handlers
v0496:
    popv(3);
    return nil;
}



// Code for simpatom

static LispObject CC_simpatom(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0508, v0188, v0187;
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
    v0508 = stack[-1];
    if (v0508 == nil) goto v0071;
    v0508 = stack[-1];
    if (is_number(v0508)) goto v0451;
    v0508 = stack[-1];
    v0508 = Lstringp(nil, v0508);
    env = stack[-3];
    if (v0508 == nil) goto v0388;
    v0188 = elt(env, 5); // "String"
    v0508 = stack[-1];
    v0188 = list2(v0188, v0508);
    nil = C_nil;
    if (exception_pending()) goto v0360;
    env = stack[-3];
    v0508 = elt(env, 6); // "identifier"
    {
        popv(4);
        fn = elt(env, 13); // typerr
        return (*qfn2(fn))(qenv(fn), v0188, v0508);
    }

v0388:
    v0508 = stack[-1];
    if (!symbolp(v0508)) v0508 = nil;
    else { v0508 = qfastgets(v0508);
           if (v0508 != nil) { v0508 = elt(v0508, 17); // share
#ifdef RECORD_GET
             if (v0508 == SPID_NOPROP)
                record_get(elt(fastget_names, 17), 0),
                v0508 = nil;
             else record_get(elt(fastget_names, 17), 1),
                v0508 = lisp_true; }
           else record_get(elt(fastget_names, 17), 0); }
#else
             if (v0508 == SPID_NOPROP) v0508 = nil; else v0508 = lisp_true; }}
#endif
    if (v0508 == nil) goto v0372;
    v0508 = stack[-1];
    fn = elt(env, 14); // lispeval
    v0508 = (*qfn1(fn))(qenv(fn), v0508);
    nil = C_nil;
    if (exception_pending()) goto v0360;
    env = stack[-3];
    v0187 = v0508;
    v0188 = v0187;
    v0508 = stack[-1];
    if (v0188 == v0508) goto v0383;
    v0508 = v0187;
    {
        popv(4);
        fn = elt(env, 15); // simp
        return (*qfn1(fn))(qenv(fn), v0508);
    }

v0383:
    v0188 = stack[-1];
    v0508 = (LispObject)17; // 1
    {
        popv(4);
        fn = elt(env, 16); // mksq
        return (*qfn2(fn))(qenv(fn), v0188, v0508);
    }

v0372:
    v0508 = stack[-1];
    if (!symbolp(v0508)) v0508 = nil;
    else { v0508 = qfastgets(v0508);
           if (v0508 != nil) { v0508 = elt(v0508, 56); // idvalfn
#ifdef RECORD_GET
             if (v0508 != SPID_NOPROP)
                record_get(elt(fastget_names, 56), 1);
             else record_get(elt(fastget_names, 56), 0),
                v0508 = nil; }
           else record_get(elt(fastget_names, 56), 0); }
#else
             if (v0508 == SPID_NOPROP) v0508 = nil; }}
#endif
    stack[-2] = v0508;
    if (v0508 == nil) goto v0314;
    v0188 = stack[-2];
    v0508 = stack[-1];
        popv(4);
        return Lapply1(nil, v0188, v0508);

v0314:
    v0508 = qvalue(elt(env, 7)); // !*numval
    if (v0508 == nil) goto v0509;
    v0508 = qvalue(elt(env, 2)); // dmode!*
    if (v0508 == nil) goto v0509;
    v0188 = stack[-1];
    v0508 = elt(env, 8); // constant
    v0508 = Lflagp(nil, v0188, v0508);
    env = stack[-3];
    if (v0508 == nil) goto v0510;
    v0188 = stack[-1];
    v0508 = qvalue(elt(env, 2)); // dmode!*
    v0508 = get(v0188, v0508);
    env = stack[-3];
    stack[-2] = v0508;
    if (v0508 == nil) goto v0511;
    stack[0] = elt(env, 9); // lispapply
    v0508 = stack[-2];
    v0188 = Lmkquote(nil, v0508);
    nil = C_nil;
    if (exception_pending()) goto v0360;
    env = stack[-3];
    v0508 = qvalue(elt(env, 1)); // nil
    v0188 = list3(stack[0], v0188, v0508);
    nil = C_nil;
    if (exception_pending()) goto v0360;
    env = stack[-3];
    v0508 = qvalue(elt(env, 1)); // nil
    fn = elt(env, 17); // errorset!*
    v0508 = (*qfn2(fn))(qenv(fn), v0188, v0508);
    nil = C_nil;
    if (exception_pending()) goto v0360;
    env = stack[-3];
    stack[-2] = v0508;
    fn = elt(env, 18); // errorp
    v0508 = (*qfn1(fn))(qenv(fn), v0508);
    nil = C_nil;
    if (exception_pending()) goto v0360;
    env = stack[-3];
    if (v0508 == nil) goto v0512;
    v0508 = qvalue(elt(env, 1)); // nil
    goto v0513;

v0513:
    if (v0508 == nil) goto v0509;
    v0508 = stack[-2];
    {
        popv(4);
        fn = elt(env, 19); // !*d2q
        return (*qfn1(fn))(qenv(fn), v0508);
    }

v0509:
    v0508 = stack[-1];
    fn = elt(env, 20); // getrtype
    v0508 = (*qfn1(fn))(qenv(fn), v0508);
    nil = C_nil;
    if (exception_pending()) goto v0360;
    env = stack[-3];
    if (v0508 == nil) goto v0362;
    v0188 = stack[-1];
    v0508 = elt(env, 12); // scalar
    fn = elt(env, 13); // typerr
    v0508 = (*qfn2(fn))(qenv(fn), v0188, v0508);
    nil = C_nil;
    if (exception_pending()) goto v0360;
    v0508 = nil;
    { popv(4); return onevalue(v0508); }

v0362:
    v0188 = stack[-1];
    v0508 = (LispObject)17; // 1
    {
        popv(4);
        fn = elt(env, 16); // mksq
        return (*qfn2(fn))(qenv(fn), v0188, v0508);
    }

v0512:
    v0508 = stack[-2];
    v0188 = qcar(v0508);
    stack[-2] = v0188;
    v0508 = elt(env, 10); // !:rd!:
    if (!consp(v0188)) goto v0413;
    v0188 = qcar(v0188);
    if (!(v0188 == v0508)) goto v0413;
    v0508 = stack[-2];
    v0508 = qcdr(v0508);
    fn = elt(env, 21); // complexp
    v0508 = (*qfn1(fn))(qenv(fn), v0508);
    nil = C_nil;
    if (exception_pending()) goto v0360;
    env = stack[-3];
    v0508 = (v0508 == nil ? lisp_true : nil);
    goto v0513;

v0413:
    v0508 = qvalue(elt(env, 11)); // t
    goto v0513;

v0511:
    v0508 = qvalue(elt(env, 1)); // nil
    goto v0513;

v0510:
    v0508 = qvalue(elt(env, 1)); // nil
    goto v0513;

v0451:
    v0188 = stack[-1];
    v0508 = (LispObject)1; // 0
    if (v0188 == v0508) goto v0429;
    v0508 = stack[-1];
    v0508 = integerp(v0508);
    if (v0508 == nil) goto v0437;
    v0188 = qvalue(elt(env, 2)); // dmode!*
    v0508 = elt(env, 3); // !:mod!:
    if (v0188 == v0508) goto v0226;
    v0508 = qvalue(elt(env, 1)); // nil
    goto v0450;

v0450:
    if (v0508 == nil) goto v0405;
    v0188 = qvalue(elt(env, 1)); // nil
    v0508 = (LispObject)17; // 1
    popv(4);
    return cons(v0188, v0508);

v0405:
    v0508 = qvalue(elt(env, 2)); // dmode!*
    if (!symbolp(v0508)) v0508 = nil;
    else { v0508 = qfastgets(v0508);
           if (v0508 != nil) { v0508 = elt(v0508, 5); // convert
#ifdef RECORD_GET
             if (v0508 == SPID_NOPROP)
                record_get(elt(fastget_names, 5), 0),
                v0508 = nil;
             else record_get(elt(fastget_names, 5), 1),
                v0508 = lisp_true; }
           else record_get(elt(fastget_names, 5), 0); }
#else
             if (v0508 == SPID_NOPROP) v0508 = nil; else v0508 = lisp_true; }}
#endif
    if (v0508 == nil) goto v0221;
    v0188 = stack[-1];
    v0508 = (LispObject)17; // 1
    v0508 = Lneq(nil, v0188, v0508);
    nil = C_nil;
    if (exception_pending()) goto v0360;
    env = stack[-3];
    goto v0395;

v0395:
    if (v0508 == nil) goto v0392;
    v0508 = qvalue(elt(env, 2)); // dmode!*
    if (!symbolp(v0508)) v0188 = nil;
    else { v0188 = qfastgets(v0508);
           if (v0188 != nil) { v0188 = elt(v0188, 34); // i2d
#ifdef RECORD_GET
             if (v0188 != SPID_NOPROP)
                record_get(elt(fastget_names, 34), 1);
             else record_get(elt(fastget_names, 34), 0),
                v0188 = nil; }
           else record_get(elt(fastget_names, 34), 0); }
#else
             if (v0188 == SPID_NOPROP) v0188 = nil; }}
#endif
    v0508 = stack[-1];
    v0508 = Lapply1(nil, v0188, v0508);
    nil = C_nil;
    if (exception_pending()) goto v0360;
    env = stack[-3];
    {
        popv(4);
        fn = elt(env, 19); // !*d2q
        return (*qfn1(fn))(qenv(fn), v0508);
    }

v0392:
    v0188 = stack[-1];
    v0508 = (LispObject)17; // 1
    popv(4);
    return cons(v0188, v0508);

v0221:
    v0508 = qvalue(elt(env, 1)); // nil
    goto v0395;

v0226:
    v0188 = qvalue(elt(env, 4)); // current!-modulus
    v0508 = (LispObject)17; // 1
    v0508 = (v0188 == v0508 ? lisp_true : nil);
    goto v0450;

v0437:
    v0508 = stack[-1];
    {
        popv(4);
        fn = elt(env, 22); // rd!:simp
        return (*qfn1(fn))(qenv(fn), v0508);
    }

v0429:
    v0188 = qvalue(elt(env, 1)); // nil
    v0508 = (LispObject)17; // 1
    popv(4);
    return cons(v0188, v0508);

v0071:
    v0188 = qvalue(elt(env, 1)); // nil
    v0508 = (LispObject)17; // 1
    popv(4);
    return cons(v0188, v0508);
// error exit handlers
v0360:
    popv(4);
    return nil;
}



// Code for mkkl

static LispObject CC_mkkl(LispObject env,
                         LispObject v0000, LispObject v0345)
{
    LispObject nil = C_nil;
    LispObject v0434, v0433, v0429;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mkkl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0345,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0345);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0434 = v0345;
    v0433 = v0000;
// end of prologue

v0030:
    v0429 = v0433;
    if (v0429 == nil) { popv(2); return onevalue(v0434); }
    v0429 = v0433;
    v0429 = qcdr(v0429);
    stack[0] = v0429;
    v0433 = qcar(v0433);
    v0434 = cons(v0433, v0434);
    nil = C_nil;
    if (exception_pending()) goto v0246;
    env = stack[-1];
    v0434 = ncons(v0434);
    nil = C_nil;
    if (exception_pending()) goto v0246;
    env = stack[-1];
    v0433 = stack[0];
    goto v0030;
// error exit handlers
v0246:
    popv(2);
    return nil;
}



// Code for wureducedpolysp

static LispObject CC_wureducedpolysp(LispObject env,
                         LispObject v0000, LispObject v0345)
{
    LispObject nil = C_nil;
    LispObject v0425, v0437;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for wureducedpolysp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0345,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0345);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0345;
    stack[-1] = v0000;
// end of prologue

v0435:
    v0425 = stack[0];
    if (v0425 == nil) goto v0015;
    v0437 = stack[-1];
    v0425 = stack[0];
    v0425 = qcar(v0425);
    fn = elt(env, 3); // wureducedp
    v0425 = (*qfn2(fn))(qenv(fn), v0437, v0425);
    nil = C_nil;
    if (exception_pending()) goto v0444;
    env = stack[-2];
    if (v0425 == nil) goto v0231;
    v0437 = stack[-1];
    v0425 = stack[0];
    v0425 = qcdr(v0425);
    stack[-1] = v0437;
    stack[0] = v0425;
    goto v0435;

v0231:
    v0425 = qvalue(elt(env, 2)); // nil
    { popv(3); return onevalue(v0425); }

v0015:
    v0425 = qvalue(elt(env, 1)); // t
    { popv(3); return onevalue(v0425); }
// error exit handlers
v0444:
    popv(3);
    return nil;
}



// Code for qqe_simplat1

static LispObject CC_qqe_simplat1(LispObject env,
                         LispObject v0000, LispObject v0345)
{
    LispObject nil = C_nil;
    LispObject v0421, v0496, v0225;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qqe_simplat1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0345,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0345);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0345;
    stack[-1] = v0000;
// end of prologue
    v0421 = stack[-1];
    fn = elt(env, 3); // qqe_op
    v0421 = (*qfn1(fn))(qenv(fn), v0421);
    nil = C_nil;
    if (exception_pending()) goto v0426;
    env = stack[-2];
    v0225 = v0421;
    v0496 = v0225;
    v0421 = elt(env, 1); // (qequal qneq)
    v0421 = Lmemq(nil, v0496, v0421);
    if (v0421 == nil) goto v0234;
    v0496 = v0225;
    v0421 = elt(env, 2); // qequal
    if (v0496 == v0421) goto v0425;
    v0496 = stack[-1];
    v0421 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); // qqe_simplqneq
        return (*qfn2(fn))(qenv(fn), v0496, v0421);
    }

v0425:
    v0496 = stack[-1];
    v0421 = stack[0];
    {
        popv(3);
        fn = elt(env, 5); // qqe_simplqequal
        return (*qfn2(fn))(qenv(fn), v0496, v0421);
    }

v0234:
    v0496 = stack[-1];
    v0421 = stack[0];
    {
        popv(3);
        fn = elt(env, 6); // qqe_simplbtat
        return (*qfn2(fn))(qenv(fn), v0496, v0421);
    }
// error exit handlers
v0426:
    popv(3);
    return nil;
}



// Code for cl_fvarl

static LispObject CC_cl_fvarl(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0448, v0230;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cl_fvarl");
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
    v0448 = v0000;
// end of prologue
    fn = elt(env, 2); // cl_fvarl1
    v0230 = (*qfn1(fn))(qenv(fn), v0448);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    env = stack[0];
    v0448 = elt(env, 1); // ordp
    {
        popv(1);
        fn = elt(env, 3); // sort
        return (*qfn2(fn))(qenv(fn), v0230, v0448);
    }
// error exit handlers
v0231:
    popv(1);
    return nil;
}



// Code for constsml

static LispObject CC_constsml(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0417, v0515;
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
    v0417 = stack[0];
    if (!(is_number(v0417))) goto v0015;
    v0417 = elt(env, 1); // "<cn"
    fn = elt(env, 13); // printout
    v0417 = (*qfn1(fn))(qenv(fn), v0417);
    nil = C_nil;
    if (exception_pending()) goto v0516;
    env = stack[-1];
    v0417 = stack[0];
    v0417 = Lfloatp(nil, v0417);
    env = stack[-1];
    if (v0417 == nil) goto v0232;
    v0417 = elt(env, 2); // " type=""real""> "
    v0417 = Lprinc(nil, v0417);
    nil = C_nil;
    if (exception_pending()) goto v0516;
    env = stack[-1];
    goto v0230;

v0230:
    v0417 = stack[0];
    v0417 = Lprinc(nil, v0417);
    nil = C_nil;
    if (exception_pending()) goto v0516;
    env = stack[-1];
    v0417 = elt(env, 5); // " </cn>"
    v0417 = Lprinc(nil, v0417);
    nil = C_nil;
    if (exception_pending()) goto v0516;
    env = stack[-1];
    goto v0015;

v0015:
    v0417 = stack[0];
    if (!(symbolp(v0417))) goto v0401;
    v0417 = stack[0];
    v0515 = Lintern(nil, v0417);
    nil = C_nil;
    if (exception_pending()) goto v0516;
    env = stack[-1];
    v0417 = qvalue(elt(env, 6)); // constants!*
    v0417 = Lmember(nil, v0515, v0417);
    if (v0417 == nil) goto v0481;
    v0417 = elt(env, 7); // "<cn type=""constant""> "
    fn = elt(env, 13); // printout
    v0417 = (*qfn1(fn))(qenv(fn), v0417);
    nil = C_nil;
    if (exception_pending()) goto v0516;
    env = stack[-1];
    v0417 = stack[0];
    v0417 = Lprinc(nil, v0417);
    nil = C_nil;
    if (exception_pending()) goto v0516;
    env = stack[-1];
    v0417 = elt(env, 5); // " </cn>"
    v0417 = Lprinc(nil, v0417);
    nil = C_nil;
    if (exception_pending()) goto v0516;
    goto v0401;

v0401:
    v0417 = nil;
    { popv(2); return onevalue(v0417); }

v0481:
    v0417 = elt(env, 8); // "<ci"
    fn = elt(env, 13); // printout
    v0417 = (*qfn1(fn))(qenv(fn), v0417);
    nil = C_nil;
    if (exception_pending()) goto v0516;
    env = stack[-1];
    v0417 = stack[0];
    fn = elt(env, 14); // listp
    v0417 = (*qfn1(fn))(qenv(fn), v0417);
    nil = C_nil;
    if (exception_pending()) goto v0516;
    env = stack[-1];
    if (v0417 == nil) goto v0223;
    v0417 = elt(env, 9); // " type=""list""> "
    v0417 = Lprinc(nil, v0417);
    nil = C_nil;
    if (exception_pending()) goto v0516;
    env = stack[-1];
    goto v0432;

v0432:
    v0417 = stack[0];
    v0417 = Lprinc(nil, v0417);
    nil = C_nil;
    if (exception_pending()) goto v0516;
    env = stack[-1];
    v0417 = elt(env, 11); // " </ci>"
    v0417 = Lprinc(nil, v0417);
    nil = C_nil;
    if (exception_pending()) goto v0516;
    goto v0401;

v0223:
    v0417 = stack[0];
    v0417 = Lsimple_vectorp(nil, v0417);
    env = stack[-1];
    if (v0417 == nil) goto v0295;
    v0417 = elt(env, 10); // " type=""vector""> "
    v0417 = Lprinc(nil, v0417);
    nil = C_nil;
    if (exception_pending()) goto v0516;
    env = stack[-1];
    goto v0432;

v0295:
    v0417 = elt(env, 4); // "> "
    v0417 = Lprinc(nil, v0417);
    nil = C_nil;
    if (exception_pending()) goto v0516;
    env = stack[-1];
    goto v0432;

v0232:
    v0417 = stack[0];
    v0417 = integerp(v0417);
    if (v0417 == nil) goto v0253;
    v0417 = elt(env, 3); // " type=""integer""> "
    v0417 = Lprinc(nil, v0417);
    nil = C_nil;
    if (exception_pending()) goto v0516;
    env = stack[-1];
    goto v0230;

v0253:
    v0417 = elt(env, 4); // "> "
    v0417 = Lprinc(nil, v0417);
    nil = C_nil;
    if (exception_pending()) goto v0516;
    env = stack[-1];
    goto v0230;
// error exit handlers
v0516:
    popv(2);
    return nil;
}



// Code for sacar

static LispObject CC_sacar(LispObject env,
                         LispObject v0000, LispObject v0345)
{
    LispObject nil = C_nil;
    LispObject v0226, v0481;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sacar");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0345,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0345);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0345;
    stack[-1] = v0000;
// end of prologue
    v0226 = stack[0];
    if (!consp(v0226)) goto v0015;
    v0481 = stack[-1];
    v0226 = stack[0];
    v0226 = qcar(v0226);
    if (v0481 == v0226) goto v0231;
    v0226 = qvalue(elt(env, 1)); // nil
    goto v0230;

v0230:
    if (v0226 == nil) goto v0420;
    v0226 = stack[0];
    popv(4);
    return ncons(v0226);

v0420:
    v0481 = stack[-1];
    v0226 = stack[0];
    v0226 = qcar(v0226);
    stack[-2] = CC_sacar(env, v0481, v0226);
    nil = C_nil;
    if (exception_pending()) goto v0431;
    env = stack[-3];
    v0481 = stack[-1];
    v0226 = stack[0];
    v0226 = qcdr(v0226);
    v0226 = CC_sacar(env, v0481, v0226);
    nil = C_nil;
    if (exception_pending()) goto v0431;
    {
        LispObject v0432 = stack[-2];
        popv(4);
        return Lappend(nil, v0432, v0226);
    }

v0231:
    v0226 = stack[0];
    v0226 = qcdr(v0226);
    goto v0230;

v0015:
    v0226 = qvalue(elt(env, 1)); // nil
    { popv(4); return onevalue(v0226); }
// error exit handlers
v0431:
    popv(4);
    return nil;
}



// Code for findnewvars

static LispObject CC_findnewvars(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0407;
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
    v0407 = stack[0];
    if (!consp(v0407)) goto v0011;
    v0407 = stack[0];
    stack[-3] = v0407;
    goto v0253;

v0253:
    v0407 = stack[-3];
    if (v0407 == nil) goto v0429;
    v0407 = stack[-3];
    v0407 = qcar(v0407);
    v0407 = CC_findnewvars(env, v0407);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-4];
    stack[-2] = v0407;
    v0407 = stack[-2];
    fn = elt(env, 2); // lastpair
    v0407 = (*qfn1(fn))(qenv(fn), v0407);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-4];
    stack[-1] = v0407;
    v0407 = stack[-3];
    v0407 = qcdr(v0407);
    stack[-3] = v0407;
    v0407 = stack[-1];
    if (!consp(v0407)) goto v0253;
    else goto v0430;

v0430:
    v0407 = stack[-3];
    if (v0407 == nil) { LispObject res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v0407 = stack[-3];
    v0407 = qcar(v0407);
    v0407 = CC_findnewvars(env, v0407);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-4];
    v0407 = Lrplacd(nil, stack[0], v0407);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-4];
    v0407 = stack[-1];
    fn = elt(env, 2); // lastpair
    v0407 = (*qfn1(fn))(qenv(fn), v0407);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-4];
    stack[-1] = v0407;
    v0407 = stack[-3];
    v0407 = qcdr(v0407);
    stack[-3] = v0407;
    goto v0430;

v0429:
    v0407 = qvalue(elt(env, 1)); // nil
    { popv(5); return onevalue(v0407); }

v0011:
    v0407 = stack[0];
    fn = elt(env, 3); // genp
    v0407 = (*qfn1(fn))(qenv(fn), v0407);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-4];
    if (v0407 == nil) goto v0423;
    v0407 = stack[0];
    popv(5);
    return ncons(v0407);

v0423:
    v0407 = qvalue(elt(env, 1)); // nil
    { popv(5); return onevalue(v0407); }
// error exit handlers
v0295:
    popv(5);
    return nil;
}



// Code for bcquot

static LispObject CC_bcquot(LispObject env,
                         LispObject v0000, LispObject v0345)
{
    LispObject nil = C_nil;
    LispObject v0432, v0475, v0223;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for bcquot");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0345,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0345);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0345;
    stack[-1] = v0000;
// end of prologue
    v0432 = qvalue(elt(env, 1)); // !*grmod!*
    if (v0432 == nil) goto v0030;
    v0432 = stack[0];
    v0432 = Lmodular_reciprocal(nil, v0432);
    nil = C_nil;
    if (exception_pending()) goto v0399;
    env = stack[-2];
    v0432 = times2(stack[-1], v0432);
    nil = C_nil;
    if (exception_pending()) goto v0399;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 4); // bcfi
        return (*qfn1(fn))(qenv(fn), v0432);
    }

v0030:
    v0432 = qvalue(elt(env, 2)); // !*vdpinteger
    if (v0432 == nil) goto v0225;
    v0223 = stack[-1];
    v0475 = stack[0];
    v0432 = elt(env, 3); // quotientx
    fn = elt(env, 5); // bcint2op
    v0432 = (*qfnn(fn))(qenv(fn), 3, v0223, v0475, v0432);
    nil = C_nil;
    if (exception_pending()) goto v0399;
    env = stack[-2];
    if (!(v0432 == nil)) { popv(3); return onevalue(v0432); }
    v0432 = stack[-1];
    v0475 = qcar(v0432);
    v0432 = stack[0];
    v0432 = qcar(v0432);
    fn = elt(env, 6); // quotfx
    v0475 = (*qfn2(fn))(qenv(fn), v0475, v0432);
    nil = C_nil;
    if (exception_pending()) goto v0399;
    v0432 = (LispObject)17; // 1
    popv(3);
    return cons(v0475, v0432);

v0225:
    v0475 = stack[-1];
    v0432 = stack[0];
    {
        popv(3);
        fn = elt(env, 7); // quotsq
        return (*qfn2(fn))(qenv(fn), v0475, v0432);
    }
// error exit handlers
v0399:
    popv(3);
    return nil;
}



// Code for vdpred

static LispObject CC_vdpred(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0454, v0455;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vdpred");
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
    v0454 = stack[-3];
    v0454 = qcdr(v0454);
    v0454 = qcdr(v0454);
    v0454 = qcdr(v0454);
    v0454 = qcar(v0454);
    v0454 = qcdr(v0454);
    v0454 = qcdr(v0454);
    stack[-4] = v0454;
    v0454 = stack[-4];
    if (v0454 == nil) goto v0234;
    stack[-2] = elt(env, 1); // vdp
    v0454 = stack[-4];
    stack[-1] = qcar(v0454);
    v0454 = stack[-4];
    v0454 = qcdr(v0454);
    stack[0] = qcar(v0454);
    v0455 = stack[-4];
    v0454 = qvalue(elt(env, 2)); // nil
    v0454 = list2(v0455, v0454);
    nil = C_nil;
    if (exception_pending()) goto v0415;
    env = stack[-5];
    v0454 = list3star(stack[-2], stack[-1], stack[0], v0454);
    nil = C_nil;
    if (exception_pending()) goto v0415;
    env = stack[-5];
    stack[-4] = v0454;
    v0454 = qvalue(elt(env, 3)); // !*gsugar
    if (v0454 == nil) { LispObject res = stack[-4]; popv(6); return onevalue(res); }
    v0455 = stack[-3];
    v0454 = elt(env, 4); // sugar
    fn = elt(env, 5); // vdpgetprop
    v0455 = (*qfn2(fn))(qenv(fn), v0455, v0454);
    nil = C_nil;
    if (exception_pending()) goto v0415;
    env = stack[-5];
    v0454 = v0455;
    if (v0455 == nil) { LispObject res = stack[-4]; popv(6); return onevalue(res); }
    v0455 = stack[-4];
    fn = elt(env, 6); // gsetsugar
    v0454 = (*qfn2(fn))(qenv(fn), v0455, v0454);
    nil = C_nil;
    if (exception_pending()) goto v0415;
    { LispObject res = stack[-4]; popv(6); return onevalue(res); }

v0234:
    stack[-2] = elt(env, 1); // vdp
    stack[-1] = qvalue(elt(env, 2)); // nil
    v0454 = qvalue(elt(env, 2)); // nil
    stack[0] = ncons(v0454);
    nil = C_nil;
    if (exception_pending()) goto v0415;
    env = stack[-5];
    v0455 = qvalue(elt(env, 2)); // nil
    v0454 = qvalue(elt(env, 2)); // nil
    v0454 = list2(v0455, v0454);
    nil = C_nil;
    if (exception_pending()) goto v0415;
    {
        LispObject v0416 = stack[-2];
        LispObject v0469 = stack[-1];
        LispObject v0467 = stack[0];
        popv(6);
        return list3star(v0416, v0469, v0467, v0454);
    }
// error exit handlers
v0415:
    popv(6);
    return nil;
}



// Code for xord_gradlex

static LispObject CC_xord_gradlex(LispObject env,
                         LispObject v0000, LispObject v0345)
{
    LispObject nil = C_nil;
    LispObject v0426, v0396;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for xord_gradlex");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0345,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0345);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0345;
    stack[-1] = v0000;
// end of prologue
    v0426 = stack[-1];
    v0396 = qcar(v0426);
    v0426 = (LispObject)17; // 1
    if (v0396 == v0426) goto v0015;
    v0426 = stack[0];
    v0396 = qcar(v0426);
    v0426 = (LispObject)17; // 1
    if (v0396 == v0426) goto v0267;
    v0426 = stack[-1];
    stack[-2] = Llength(nil, v0426);
    nil = C_nil;
    if (exception_pending()) goto v0475;
    env = stack[-3];
    v0426 = stack[0];
    v0426 = Llength(nil, v0426);
    nil = C_nil;
    if (exception_pending()) goto v0475;
    env = stack[-3];
    if (equal(stack[-2], v0426)) goto v0420;
    v0426 = stack[-1];
    stack[-1] = Llength(nil, v0426);
    nil = C_nil;
    if (exception_pending()) goto v0475;
    env = stack[-3];
    v0426 = stack[0];
    v0426 = Llength(nil, v0426);
    nil = C_nil;
    if (exception_pending()) goto v0475;
    {
        LispObject v0223 = stack[-1];
        popv(4);
        return Lgreaterp(nil, v0223, v0426);
    }

v0420:
    v0396 = stack[-1];
    v0426 = stack[0];
    {
        popv(4);
        fn = elt(env, 3); // xord_lex
        return (*qfn2(fn))(qenv(fn), v0396, v0426);
    }

v0267:
    v0426 = qvalue(elt(env, 2)); // t
    { popv(4); return onevalue(v0426); }

v0015:
    v0426 = qvalue(elt(env, 1)); // nil
    { popv(4); return onevalue(v0426); }
// error exit handlers
v0475:
    popv(4);
    return nil;
}



// Code for removeindices

static LispObject CC_removeindices(LispObject env,
                         LispObject v0000, LispObject v0345)
{
    LispObject nil = C_nil;
    LispObject v0381, v0491;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for removeindices");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0345,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0345);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-2] = v0345;
    stack[-3] = v0000;
// end of prologue
    v0381 = elt(env, 0); // removeindices
    if (!symbolp(v0381)) v0381 = nil;
    else { v0381 = qfastgets(v0381);
           if (v0381 != nil) { v0381 = elt(v0381, 53); // tracing
#ifdef RECORD_GET
             if (v0381 == SPID_NOPROP)
                record_get(elt(fastget_names, 53), 0),
                v0381 = nil;
             else record_get(elt(fastget_names, 53), 1),
                v0381 = lisp_true; }
           else record_get(elt(fastget_names, 53), 0); }
#else
             if (v0381 == SPID_NOPROP) v0381 = nil; else v0381 = lisp_true; }}
#endif
    if (v0381 == nil) goto v0155;
    stack[-4] = elt(env, 0); // removeindices
    stack[-1] = elt(env, 1); // "u= "
    stack[0] = stack[-3];
    v0491 = elt(env, 2); // " x= "
    v0381 = stack[-2];
    v0381 = list2(v0491, v0381);
    nil = C_nil;
    if (exception_pending()) goto v0312;
    env = stack[-5];
    v0381 = list3star(stack[-4], stack[-1], stack[0], v0381);
    nil = C_nil;
    if (exception_pending()) goto v0312;
    env = stack[-5];
    fn = elt(env, 6); // trwrite
    v0381 = (*qfn1(fn))(qenv(fn), v0381);
    nil = C_nil;
    if (exception_pending()) goto v0312;
    env = stack[-5];
    goto v0155;

v0155:
    v0381 = stack[-2];
    if (v0381 == nil) goto v0444;
    v0381 = stack[-3];
    v0381 = Lsymbolp(nil, v0381);
    env = stack[-5];
    if (!(v0381 == nil)) goto v0420;
    v0381 = stack[-3];
    fn = elt(env, 7); // !*physopp
    v0381 = (*qfn1(fn))(qenv(fn), v0381);
    nil = C_nil;
    if (exception_pending()) goto v0312;
    env = stack[-5];
    v0381 = (v0381 == nil ? lisp_true : nil);
    goto v0420;

v0420:
    if (!(v0381 == nil)) { LispObject res = stack[-3]; popv(6); return onevalue(res); }
    v0381 = stack[-2];
    if (!(symbolp(v0381))) goto v0396;
    v0381 = stack[-2];
    fn = elt(env, 8); // isanindex
    v0381 = (*qfn1(fn))(qenv(fn), v0381);
    nil = C_nil;
    if (exception_pending()) goto v0312;
    env = stack[-5];
    if (!(v0381 == nil)) goto v0396;

v0427:
    v0491 = elt(env, 0); // removeindices
    v0381 = elt(env, 4); // "invalid arguments to removeindices"
    fn = elt(env, 9); // rederr2
    v0381 = (*qfn2(fn))(qenv(fn), v0491, v0381);
    nil = C_nil;
    if (exception_pending()) goto v0312;
    env = stack[-5];
    goto v0226;

v0226:
    v0381 = stack[-3];
    v0381 = qcar(v0381);
    stack[0] = v0381;
    v0381 = stack[-3];
    v0381 = qcdr(v0381);
    stack[-3] = v0381;
    v0381 = stack[-3];
    if (v0381 == nil) { LispObject res = stack[0]; popv(6); return onevalue(res); }
    v0381 = stack[-2];
    if (symbolp(v0381)) goto v0408;
    v0381 = stack[-2];
    stack[-1] = v0381;
    goto v0393;

v0393:
    v0381 = stack[-1];
    if (v0381 == nil) goto v0515;
    v0381 = stack[-1];
    v0381 = qcar(v0381);
    v0491 = v0381;
    v0381 = stack[-3];
    v0381 = Ldelete(nil, v0491, v0381);
    nil = C_nil;
    if (exception_pending()) goto v0312;
    env = stack[-5];
    stack[-3] = v0381;
    v0381 = stack[-1];
    v0381 = qcdr(v0381);
    stack[-1] = v0381;
    goto v0393;

v0515:
    v0381 = stack[-3];
    if (v0381 == nil) { LispObject res = stack[0]; popv(6); return onevalue(res); }
    v0491 = stack[0];
    v0381 = stack[-3];
    popv(6);
    return cons(v0491, v0381);

v0408:
    v0491 = stack[-2];
    v0381 = stack[-3];
    v0381 = Ldelete(nil, v0491, v0381);
    nil = C_nil;
    if (exception_pending()) goto v0312;
    stack[-3] = v0381;
    goto v0515;

v0396:
    v0381 = stack[-2];
    fn = elt(env, 10); // idlistp
    v0381 = (*qfn1(fn))(qenv(fn), v0381);
    nil = C_nil;
    if (exception_pending()) goto v0312;
    env = stack[-5];
    if (v0381 == nil) goto v0226;
    v0381 = stack[-2];
    fn = elt(env, 11); // areallindices
    v0381 = (*qfn1(fn))(qenv(fn), v0381);
    nil = C_nil;
    if (exception_pending()) goto v0312;
    env = stack[-5];
    if (v0381 == nil) goto v0427;
    else goto v0226;

v0444:
    v0381 = qvalue(elt(env, 3)); // t
    goto v0420;
// error exit handlers
v0312:
    popv(6);
    return nil;
}



// Code for dpmat_coldegs

static LispObject CC_dpmat_coldegs(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0404, v0448;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dpmat_coldegs");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0404 = v0000;
// end of prologue
    v0448 = v0404;
    v0404 = (LispObject)81; // 5
    {
        fn = elt(env, 1); // nth
        return (*qfn2(fn))(qenv(fn), v0448, v0404);
    }
}



// Code for lalr_rename_gotos

static LispObject CC_lalr_rename_gotos(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0221, v0222;
    LispObject fn;
    argcheck(nargs, 0, "lalr_rename_gotos");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lalr_rename_gotos");
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
    v0221 = qvalue(elt(env, 1)); // symbols
    stack[-2] = v0221;
    goto v0071;

v0071:
    v0221 = stack[-2];
    if (v0221 == nil) goto v0155;
    v0221 = stack[-2];
    v0221 = qcar(v0221);
    stack[0] = v0221;
    v0221 = stack[0];
    v0221 = Lstringp(nil, v0221);
    env = stack[-3];
    if (v0221 == nil) goto v0251;
    v0221 = stack[0];
    v0222 = Lintern(nil, v0221);
    nil = C_nil;
    if (exception_pending()) goto v0416;
    env = stack[-3];
    v0221 = elt(env, 3); // lex_code
    v0221 = get(v0222, v0221);
    env = stack[-3];
    goto v0266;

v0266:
    if (!(v0221 == nil)) goto v0235;
    v0221 = stack[0];
    if (symbolp(v0221)) goto v0483;
    v0221 = qvalue(elt(env, 2)); // nil
    goto v0235;

v0235:
    stack[-1] = v0221;
    v0221 = stack[-1];
    if (!(v0221 == nil)) goto v0475;
    v0221 = stack[0];
    stack[-1] = v0221;
    goto v0475;

v0475:
    stack[0] = qvalue(elt(env, 5)); // renamings
    v0222 = stack[-1];
    v0221 = qvalue(elt(env, 6)); // goto_cache
    fn = elt(env, 7); // gethash
    v0221 = (*qfn2(fn))(qenv(fn), v0222, v0221);
    nil = C_nil;
    if (exception_pending()) goto v0416;
    env = stack[-3];
    v0221 = Lsublis(nil, stack[0], v0221);
    nil = C_nil;
    if (exception_pending()) goto v0416;
    env = stack[-3];
    stack[0] = qvalue(elt(env, 6)); // goto_cache
    fn = elt(env, 8); // lalr_remove_duplicates
    v0221 = (*qfn1(fn))(qenv(fn), v0221);
    nil = C_nil;
    if (exception_pending()) goto v0416;
    env = stack[-3];
    fn = elt(env, 9); // puthash
    v0221 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v0221);
    nil = C_nil;
    if (exception_pending()) goto v0416;
    env = stack[-3];
    v0221 = stack[-2];
    v0221 = qcdr(v0221);
    stack[-2] = v0221;
    goto v0071;

v0483:
    v0222 = stack[0];
    v0221 = elt(env, 4); // lex_fixed_code
    v0221 = get(v0222, v0221);
    env = stack[-3];
    goto v0235;

v0251:
    v0221 = qvalue(elt(env, 2)); // nil
    goto v0266;

v0155:
    v0221 = nil;
    { popv(4); return onevalue(v0221); }
// error exit handlers
v0416:
    popv(4);
    return nil;
}



// Code for qcputx

static LispObject CC_qcputx(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0405, v0458, v0450;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qcputx");
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
    v0458 = v0000;
// end of prologue
    v0450 = v0458;
    v0405 = elt(env, 1); // quote
    if (!consp(v0450)) goto v0449;
    v0450 = qcar(v0450);
    if (!(v0450 == v0405)) goto v0449;
    v0405 = v0458;
    v0405 = qcdr(v0405);
    v0450 = qcar(v0405);
    v0405 = elt(env, 2); // cref
    v0405 = Lflagp(nil, v0450, v0405);
    env = stack[0];
    if (v0405 == nil) goto v0246;
    v0405 = qvalue(elt(env, 3)); // t
    { popv(1); return onevalue(v0405); }

v0246:
    v0405 = v0458;
    v0405 = qcdr(v0405);
    v0405 = qcar(v0405);
    v0458 = elt(env, 4); // compile
        popv(1);
        return Lflagp(nil, v0405, v0458);

v0449:
    v0405 = qvalue(elt(env, 5)); // nil
    { popv(1); return onevalue(v0405); }
}



// Code for rl_bestgaussp

static LispObject CC_rl_bestgaussp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0448;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rl_bestgaussp");
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
    v0448 = v0000;
// end of prologue
    stack[0] = qvalue(elt(env, 1)); // rl_bestgaussp!*
    v0448 = ncons(v0448);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    env = stack[-1];
    {
        LispObject v0232 = stack[0];
        popv(2);
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(qenv(fn), v0232, v0448);
    }
// error exit handlers
v0231:
    popv(2);
    return nil;
}



// Code for prepreform

static LispObject CC_prepreform(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0233, v0340;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for prepreform");
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
    v0233 = v0000;
// end of prologue
    stack[0] = v0233;
    v0340 = qvalue(elt(env, 1)); // ordl!*
    v0233 = qvalue(elt(env, 2)); // factors!*
    v0233 = Lappend(nil, v0340, v0233);
    nil = C_nil;
    if (exception_pending()) goto v0235;
    env = stack[-1];
    {
        LispObject v0325 = stack[0];
        popv(2);
        fn = elt(env, 3); // prepreform1
        return (*qfn2(fn))(qenv(fn), v0325, v0233);
    }
// error exit handlers
v0235:
    popv(2);
    return nil;
}



setup_type const u16_setup[] =
{
    {"xread1",                  CC_xread1,      too_many_1,    wrong_no_1},
    {"qremf",                   too_few_2,      CC_qremf,      wrong_no_2},
    {"remove-free-vars*",       CC_removeKfreeKvarsH,too_many_1,wrong_no_1},
    {"tmsf",                    CC_tmsf,        too_many_1,    wrong_no_1},
    {"ibalp_simpterm",          CC_ibalp_simpterm,too_many_1,  wrong_no_1},
    {"vdp_zero?",               CC_vdp_zeroW,   too_many_1,    wrong_no_1},
    {"omsir",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_omsir},
    {"evallessp",               too_few_2,      CC_evallessp,  wrong_no_2},
    {"ldt-tvar",                CC_ldtKtvar,    too_many_1,    wrong_no_1},
    {"actual_alst",             too_few_2,      CC_actual_alst,wrong_no_2},
    {"simp-sign",               CC_simpKsign,   too_many_1,    wrong_no_1},
    {"symbid",                  too_few_2,      CC_symbid,     wrong_no_2},
    {"getmatelem",              CC_getmatelem,  too_many_1,    wrong_no_1},
    {"dl_get2",                 too_few_2,      CC_dl_get2,    wrong_no_2},
    {"invbf",                   CC_invbf,       too_many_1,    wrong_no_1},
    {"degree-in-variable",      too_few_2,      CC_degreeKinKvariable,wrong_no_2},
    {"update_kc_list",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_update_kc_list},
    {"lalr_resolve_conflicts",  CC_lalr_resolve_conflicts,too_many_1,wrong_no_1},
    {"sq2sspl",                 too_few_2,      CC_sq2sspl,    wrong_no_2},
    {"ibalp_lenisone",          CC_ibalp_lenisone,too_many_1,  wrong_no_1},
    {"dvfsf_mk2",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_dvfsf_mk2},
    {"attributesml",            too_few_2,      CC_attributesml,wrong_no_2},
    {"maprin",                  CC_maprin,      too_many_1,    wrong_no_1},
    {"dm-eq",                   too_few_2,      CC_dmKeq,      wrong_no_2},
    {"modminusp:",              CC_modminuspT,  too_many_1,    wrong_no_1},
    {"vbcgcd",                  too_few_2,      CC_vbcgcd,     wrong_no_2},
    {"listeval",                too_few_2,      CC_listeval,   wrong_no_2},
    {"simprepart",              CC_simprepart,  too_many_1,    wrong_no_1},
    {"mkprogn",                 too_few_2,      CC_mkprogn,    wrong_no_2},
    {"pv_times1",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_pv_times1},
    {"b:ordexp",                too_few_2,      CC_bTordexp,   wrong_no_2},
    {"simpatom",                CC_simpatom,    too_many_1,    wrong_no_1},
    {"mkkl",                    too_few_2,      CC_mkkl,       wrong_no_2},
    {"wureducedpolysp",         too_few_2,      CC_wureducedpolysp,wrong_no_2},
    {"qqe_simplat1",            too_few_2,      CC_qqe_simplat1,wrong_no_2},
    {"cl_fvarl",                CC_cl_fvarl,    too_many_1,    wrong_no_1},
    {"constsml",                CC_constsml,    too_many_1,    wrong_no_1},
    {"sacar",                   too_few_2,      CC_sacar,      wrong_no_2},
    {"findnewvars",             CC_findnewvars, too_many_1,    wrong_no_1},
    {"bcquot",                  too_few_2,      CC_bcquot,     wrong_no_2},
    {"vdpred",                  CC_vdpred,      too_many_1,    wrong_no_1},
    {"xord_gradlex",            too_few_2,      CC_xord_gradlex,wrong_no_2},
    {"removeindices",           too_few_2,      CC_removeindices,wrong_no_2},
    {"dpmat_coldegs",           CC_dpmat_coldegs,too_many_1,   wrong_no_1},
    {"lalr_rename_gotos",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_lalr_rename_gotos},
    {"qcputx",                  CC_qcputx,      too_many_1,    wrong_no_1},
    {"rl_bestgaussp",           CC_rl_bestgaussp,too_many_1,   wrong_no_1},
    {"prepreform",              CC_prepreform,  too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u16", (two_args *)"11401 4302008 1449062", 0}
};

// end of generated code
