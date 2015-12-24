
// $destdir/u56.c        Machine generated C code

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



// Code for partitpartdf

static LispObject CC_partitpartdf(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0003, v0004;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for partitpartdf");
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
    v0004 = v0000;
// end of prologue
    v0003 = v0004;
    v0003 = qcdr(v0003);
    if (v0003 == nil) goto v0005;
    stack[0] = (LispObject)17; // 1
    v0003 = v0004;
    fn = elt(env, 1); // simppartdf0
    v0003 = (*qfn1(fn))(qenv(fn), v0003);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-1];
    v0003 = cons(stack[0], v0003);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    popv(2);
    return ncons(v0003);

v0005:
    v0003 = v0004;
    v0003 = qcar(v0003);
    fn = elt(env, 2); // !*a2k
    v0003 = (*qfn1(fn))(qenv(fn), v0003);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 3); // mknatvec
        return (*qfn1(fn))(qenv(fn), v0003);
    }
// error exit handlers
v0006:
    popv(2);
    return nil;
}



// Code for calc_map_tar

static LispObject CC_calc_map_tar(LispObject env,
                         LispObject v0000, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0023, v0024, v0025;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for calc_map_tar");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0007,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0007);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-3] = v0007;
    v0024 = v0000;
// end of prologue
    v0023 = v0024;
    v0023 = qcar(v0023);
    stack[-4] = v0023;
    v0023 = v0024;
    v0023 = qcdr(v0023);
    v0023 = qcar(v0023);
    stack[-2] = v0023;
    v0023 = v0024;
    v0023 = qcdr(v0023);
    v0023 = qcdr(v0023);
    v0023 = qcar(v0023);
    stack[0] = v0023;
    v0023 = v0024;
    v0023 = qcdr(v0023);
    v0023 = qcdr(v0023);
    v0023 = qcdr(v0023);
    v0023 = qcar(v0023);
    stack[-1] = v0023;
    v0023 = v0024;
    v0023 = qcdr(v0023);
    v0023 = qcdr(v0023);
    v0023 = qcdr(v0023);
    v0023 = qcdr(v0023);
    v0023 = qcar(v0023);
    v0024 = v0023;
    v0023 = stack[-3];
    fn = elt(env, 1); // ev!-poles
    v0023 = (*qfn2(fn))(qenv(fn), v0024, v0023);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-5];
    if (v0023 == nil) goto v0027;
    v0023 = (LispObject)1; // 0
    { popv(6); return onevalue(v0023); }

v0027:
    v0023 = stack[-1];
    fn = elt(env, 2); // constimes
    stack[-1] = (*qfn1(fn))(qenv(fn), v0023);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-5];
    v0024 = stack[0];
    v0023 = stack[-3];
    fn = elt(env, 3); // ev!-tades
    v0023 = (*qfn2(fn))(qenv(fn), v0024, v0023);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-5];
    fn = elt(env, 2); // constimes
    stack[0] = (*qfn1(fn))(qenv(fn), v0023);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-5];
    v0023 = stack[-2];
    if (v0023 == nil) goto v0028;
    v0025 = stack[-4];
    v0024 = stack[-2];
    v0023 = stack[-3];
    fn = elt(env, 4); // strand!-alg!-top
    v0023 = (*qfnn(fn))(qenv(fn), 3, v0025, v0024, v0023);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-5];
    goto v0029;

v0029:
    v0023 = list3(stack[-1], stack[0], v0023);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-5];
    {
        popv(6);
        fn = elt(env, 2); // constimes
        return (*qfn1(fn))(qenv(fn), v0023);
    }

v0028:
    v0023 = (LispObject)17; // 1
    goto v0029;
// error exit handlers
v0026:
    popv(6);
    return nil;
}



// Code for simpabs

static LispObject CC_simpabs(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0037, v0038;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for simpabs");
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
    v0037 = stack[0];
    if (v0037 == nil) goto v0014;
    v0037 = stack[0];
    v0037 = qcdr(v0037);
    goto v0018;

v0018:
    if (v0037 == nil) goto v0039;
    stack[-1] = elt(env, 2); // abs
    v0037 = stack[0];
    fn = elt(env, 4); // revlis
    v0037 = (*qfn1(fn))(qenv(fn), v0037);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-2];
    v0038 = cons(stack[-1], v0037);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-2];
    v0037 = (LispObject)17; // 1
    {
        popv(3);
        fn = elt(env, 5); // mksq
        return (*qfn2(fn))(qenv(fn), v0038, v0037);
    }

v0039:
    v0037 = stack[0];
    v0037 = qcar(v0037);
    stack[0] = v0037;
    v0037 = stack[0];
    if (is_number(v0037)) goto v0041;
    v0037 = stack[0];
    fn = elt(env, 6); // sign!-abs
    v0037 = (*qfn1(fn))(qenv(fn), v0037);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-2];
    v0038 = v0037;
    if (!(v0037 == nil)) { popv(3); return onevalue(v0038); }
    v0037 = stack[0];
    fn = elt(env, 7); // simp!*
    v0037 = (*qfn1(fn))(qenv(fn), v0037);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-2];
    stack[0] = v0037;
    v0037 = stack[0];
    v0037 = qcar(v0037);
    if (v0037 == nil) goto v0042;
    v0037 = stack[0];
    v0037 = qcar(v0037);
    fn = elt(env, 8); // simpabs1
    stack[-1] = (*qfn1(fn))(qenv(fn), v0037);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-2];
    v0037 = stack[0];
    v0037 = qcdr(v0037);
    fn = elt(env, 8); // simpabs1
    v0037 = (*qfn1(fn))(qenv(fn), v0037);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-2];
    {
        LispObject v0043 = stack[-1];
        popv(3);
        fn = elt(env, 9); // quotsq
        return (*qfn2(fn))(qenv(fn), v0043, v0037);
    }

v0042:
    v0038 = qvalue(elt(env, 3)); // nil
    v0037 = (LispObject)17; // 1
    popv(3);
    return cons(v0038, v0037);

v0041:
    v0037 = stack[0];
    v0038 = Labsval(nil, v0037);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    v0037 = (LispObject)17; // 1
    popv(3);
    return cons(v0038, v0037);

v0014:
    v0037 = qvalue(elt(env, 1)); // t
    goto v0018;
// error exit handlers
v0040:
    popv(3);
    return nil;
}



// Code for mo_dlexcomp

static LispObject CC_mo_dlexcomp(LispObject env,
                         LispObject v0000, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0047, v0001;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mo_dlexcomp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0007,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0007);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
// copy arguments values to proper place
    v0047 = v0007;
    v0001 = v0000;
// end of prologue
    v0001 = qcar(v0001);
    v0047 = qcar(v0047);
    fn = elt(env, 1); // mo!=lexcomp
    v0001 = (*qfn2(fn))(qenv(fn), v0001, v0047);
    errexit();
    v0047 = (LispObject)17; // 1
    v0047 = (v0001 == v0047 ? lisp_true : nil);
    return onevalue(v0047);
}



// Code for partsym_zerop

static LispObject CC_partsym_zerop(LispObject env,
                         LispObject v0000, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0052, v0053, v0033;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for partsym_zerop");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0007,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0007);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0007;
    stack[-1] = v0000;
// end of prologue

v0054:
    v0052 = stack[-1];
    if (v0052 == nil) goto v0015;
    v0052 = stack[-1];
    v0052 = qcar(v0052);
    fn = elt(env, 3); // repeats
    v0052 = (*qfn1(fn))(qenv(fn), v0052);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-2];
    v0033 = v0052;
    v0052 = stack[0];
    v0053 = qcar(v0052);
    v0052 = elt(env, 2); // !-
    if (v0053 == v0052) goto v0001;
    v0052 = qvalue(elt(env, 1)); // nil
    goto v0047;

v0047:
    if (!(v0052 == nil)) { popv(3); return onevalue(v0033); }
    v0052 = stack[-1];
    v0053 = qcdr(v0052);
    v0052 = stack[0];
    v0052 = qcdr(v0052);
    stack[-1] = v0053;
    stack[0] = v0052;
    goto v0054;

v0001:
    v0052 = v0033;
    goto v0047;

v0015:
    v0052 = qvalue(elt(env, 1)); // nil
    { popv(3); return onevalue(v0052); }
// error exit handlers
v0010:
    popv(3);
    return nil;
}



// Code for sc_repkern

static LispObject CC_sc_repkern(LispObject env,
                         LispObject v0000, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0104, v0105, v0106;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sc_repkern");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0007,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0007);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
// copy arguments values to proper place
    stack[-5] = v0007;
    v0105 = v0000;
// end of prologue
    v0104 = v0105;
    v0106 = qcar(v0104);
    v0104 = elt(env, 1); // !*
    if (v0106 == v0104) goto v0015;
    stack[-1] = nil;
    stack[-6] = nil;
    stack[-4] = nil;
    v0104 = v0105;
    v0104 = qcdr(v0104);
    v0105 = v0104;
    v0104 = v0105;
    stack[-2] = v0104;
    goto v0107;

v0107:
    v0104 = stack[-2];
    if (v0104 == nil) goto v0108;
    v0104 = stack[-2];
    v0104 = qcar(v0104);
    v0105 = v0104;
    v0106 = v0105;
    v0104 = stack[-1];
    v0104 = Lassoc(nil, v0106, v0104);
    v0106 = v0104;
    if (v0104 == nil) goto v0109;
    stack[0] = v0106;
    v0104 = v0106;
    v0104 = qcdr(v0104);
    v0104 = add1(v0104);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-7];
    v0104 = Lrplacd(nil, stack[0], v0104);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-7];
    goto v0111;

v0111:
    v0104 = stack[-2];
    v0104 = qcdr(v0104);
    stack[-2] = v0104;
    goto v0107;

v0109:
    v0106 = v0105;
    v0105 = (LispObject)17; // 1
    v0104 = stack[-1];
    v0104 = acons(v0106, v0105, v0104);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-7];
    stack[-1] = v0104;
    goto v0111;

v0108:
    v0105 = stack[-1];
    v0104 = elt(env, 3); // lambda_pbthn8t73vcc
    fn = elt(env, 4); // sort
    v0104 = (*qfn2(fn))(qenv(fn), v0105, v0104);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-7];
    stack[-1] = v0104;
    v0104 = (LispObject)1; // 0
    stack[-3] = v0104;
    v0104 = stack[-1];
    stack[-2] = v0104;
    goto v0112;

v0112:
    v0104 = stack[-2];
    if (v0104 == nil) goto v0113;
    v0104 = stack[-2];
    v0104 = qcar(v0104);
    stack[-1] = v0104;
    v0104 = stack[-1];
    v0105 = qcdr(v0104);
    v0104 = stack[-3];
    if (equal(v0105, v0104)) goto v0114;
    v0104 = stack[-1];
    v0106 = qcdr(v0104);
    v0105 = (LispObject)17; // 1
    v0104 = stack[-6];
    v0104 = acons(v0106, v0105, v0104);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-7];
    stack[-6] = v0104;
    v0104 = stack[-1];
    v0104 = qcar(v0104);
    v0105 = ncons(v0104);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-7];
    v0104 = stack[-4];
    v0104 = cons(v0105, v0104);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-7];
    stack[-4] = v0104;
    v0104 = stack[-1];
    v0104 = qcdr(v0104);
    stack[-3] = v0104;
    goto v0115;

v0115:
    v0104 = stack[-2];
    v0104 = qcdr(v0104);
    stack[-2] = v0104;
    goto v0112;

v0114:
    v0104 = stack[-6];
    stack[0] = qcar(v0104);
    v0104 = stack[-6];
    v0104 = qcar(v0104);
    v0104 = qcdr(v0104);
    v0104 = add1(v0104);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-7];
    v0104 = Lrplacd(nil, stack[0], v0104);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-7];
    stack[0] = stack[-4];
    v0104 = stack[-1];
    v0105 = qcar(v0104);
    v0104 = stack[-4];
    v0104 = qcar(v0104);
    v0104 = cons(v0105, v0104);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-7];
    v0104 = Lrplaca(nil, stack[0], v0104);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-7];
    goto v0115;

v0113:
    stack[0] = stack[-6];
    v0105 = stack[-4];
    v0104 = stack[-5];
    fn = elt(env, 5); // pa_list2vect
    v0104 = (*qfn2(fn))(qenv(fn), v0105, v0104);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    {
        LispObject v0116 = stack[0];
        popv(8);
        return list2(v0116, v0104);
    }

v0015:
    stack[-6] = nil;
    v0104 = v0105;
    v0104 = qcdr(v0104);
    stack[0] = v0104;
    v0104 = (LispObject)1; // 0
    stack[-2] = v0104;
    goto v0036;

v0036:
    v0104 = stack[0];
    if (v0104 == nil) goto v0117;
    v0104 = stack[0];
    v0104 = qcar(v0104);
    stack[-3] = v0104;
    v0104 = stack[-3];
    v0105 = ncons(v0104);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-7];
    v0104 = stack[-6];
    v0104 = cons(v0105, v0104);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-7];
    stack[-6] = v0104;
    v0104 = stack[0];
    v0104 = qcdr(v0104);
    stack[0] = v0104;
    v0104 = qvalue(elt(env, 2)); // nil
    stack[-4] = v0104;
    v0105 = stack[-2];
    v0104 = (LispObject)33; // 2
    v0104 = times2(v0105, v0104);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-7];
    v0104 = add1(v0104);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-7];
    stack[-2] = v0104;
    v0104 = stack[0];
    stack[-1] = v0104;
    goto v0016;

v0016:
    v0104 = stack[-1];
    if (v0104 == nil) goto v0118;
    v0104 = stack[-1];
    v0104 = qcar(v0104);
    stack[0] = v0104;
    v0105 = stack[0];
    v0104 = stack[-3];
    if (v0105 == v0104) goto v0119;
    v0105 = stack[-2];
    v0104 = (LispObject)33; // 2
    v0104 = times2(v0105, v0104);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-7];
    stack[-2] = v0104;
    v0105 = stack[0];
    v0104 = stack[-4];
    v0104 = cons(v0105, v0104);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-7];
    stack[-4] = v0104;
    goto v0120;

v0120:
    v0104 = stack[-1];
    v0104 = qcdr(v0104);
    stack[-1] = v0104;
    goto v0016;

v0119:
    v0105 = stack[-2];
    v0104 = (LispObject)33; // 2
    v0104 = times2(v0105, v0104);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-7];
    v0104 = add1(v0104);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-7];
    stack[-2] = v0104;
    goto v0120;

v0118:
    v0104 = stack[-4];
    v0104 = Lreverse(nil, v0104);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-7];
    stack[0] = v0104;
    goto v0036;

v0117:
    stack[0] = stack[-2];
    v0104 = stack[-6];
    v0105 = Lreverse(nil, v0104);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-7];
    v0104 = stack[-5];
    fn = elt(env, 5); // pa_list2vect
    v0104 = (*qfn2(fn))(qenv(fn), v0105, v0104);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    {
        LispObject v0121 = stack[0];
        popv(8);
        return list2(v0121, v0104);
    }
// error exit handlers
v0110:
    popv(8);
    return nil;
}



// Code for lambda_pbthn8t73vcc

static LispObject CC_lambda_pbthn8t73vcc(LispObject env,
                         LispObject v0000, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0103, v0049;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lambda_pbthn8t73vcc");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0103 = v0007;
    v0049 = v0000;
// end of prologue
    v0049 = qcdr(v0049);
    v0103 = qcdr(v0103);
        return Lleq(nil, v0049, v0103);
}



// Code for spreadvar

static LispObject CC_spreadvar(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0119, v0128, v0037;
    LispObject v0124, v0007, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "spreadvar");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0007 = va_arg(aa, LispObject);
    v0124 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for spreadvar");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0124,v0007,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0007,v0124);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    v0128 = v0124;
    stack[0] = v0007;
    stack[-1] = v0000;
// end of prologue

v0018:
    v0119 = stack[-1];
    if (!consp(v0119)) goto v0049;
    v0119 = stack[-1];
    v0119 = qcar(v0119);
    v0119 = (consp(v0119) ? nil : lisp_true);
    goto v0103;

v0103:
    if (!(v0119 == nil)) { popv(4); return onevalue(v0128); }
    v0119 = stack[-1];
    v0119 = qcar(v0119);
    v0119 = qcar(v0119);
    v0037 = qcar(v0119);
    v0119 = stack[0];
    if (equal(v0037, v0119)) goto v0102;
    v0119 = qvalue(elt(env, 2)); // nil
    goto v0034;

v0034:
    if (v0119 == nil) goto v0006;
    v0119 = stack[-1];
    v0119 = qcar(v0119);
    v0119 = qcar(v0119);
    v0119 = qcdr(v0119);
    v0119 = cons(v0119, v0128);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-3];
    v0128 = v0119;
    goto v0006;

v0006:
    v0119 = stack[-1];
    v0119 = qcdr(v0119);
    stack[-2] = v0119;
    v0119 = stack[-1];
    v0119 = qcar(v0119);
    v0037 = qcdr(v0119);
    v0119 = stack[0];
    v0119 = CC_spreadvar(env, 3, v0037, v0119, v0128);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-3];
    v0128 = v0119;
    v0119 = stack[-2];
    stack[-1] = v0119;
    goto v0018;

v0102:
    v0119 = stack[-1];
    v0119 = qcar(v0119);
    v0119 = qcar(v0119);
    v0037 = qcdr(v0119);
    v0119 = v0128;
    v0119 = Lmember(nil, v0037, v0119);
    v0119 = (v0119 == nil ? lisp_true : nil);
    goto v0034;

v0049:
    v0119 = qvalue(elt(env, 1)); // t
    goto v0103;
// error exit handlers
v0040:
    popv(4);
    return nil;
}



// Code for i2cr!*

static LispObject CC_i2crH(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0047, v0001;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for i2cr*");
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
    v0047 = v0000;
// end of prologue
    fn = elt(env, 3); // chkint!*
    v0047 = (*qfn1(fn))(qenv(fn), v0047);
    nil = C_nil;
    if (exception_pending()) goto v0002;
    env = stack[0];
    v0001 = v0047;
    if (!consp(v0047)) goto v0103;
    v0047 = qvalue(elt(env, 2)); // bfz!*
    goto v0014;

v0014:
    {
        popv(1);
        fn = elt(env, 4); // mkcr
        return (*qfn2(fn))(qenv(fn), v0001, v0047);
    }

v0103:
    v0047 = elt(env, 1); // 0.0
    goto v0014;
// error exit handlers
v0002:
    popv(1);
    return nil;
}



// Code for extodd

static LispObject CC_extodd(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0040, v0043;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for extodd");
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
    v0040 = stack[0];
    v0043 = qcar(v0040);
    v0040 = elt(env, 1); // ext
    if (v0043 == v0040) goto v0018;
    v0040 = elt(env, 2); // "the argument of extodd must be an ext variable"
    fn = elt(env, 6); // rederr
    v0040 = (*qfn1(fn))(qenv(fn), v0040);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    env = stack[-2];
    goto v0018;

v0018:
    v0040 = stack[0];
    v0040 = qcdr(v0040);
    v0040 = qcar(v0040);
    stack[-1] = v0040;
    v0040 = stack[-1];
    if (is_number(v0040)) goto v0136;
    v0043 = stack[-1];
    v0040 = qvalue(elt(env, 5)); // all_parametric_odd!*
    v0040 = Lmember(nil, v0043, v0040);
    if (!(v0040 == nil)) { LispObject res = stack[-1]; popv(3); return onevalue(res); }
    v0043 = stack[-1];
    v0040 = qvalue(elt(env, 4)); // all_principal_odd!*
    v0040 = Lmember(nil, v0043, v0040);
    if (!(v0040 == nil)) { LispObject res = stack[-1]; popv(3); return onevalue(res); }
    v0040 = elt(env, 2); // "the argument of extodd must be an ext variable"
    fn = elt(env, 6); // rederr
    v0040 = (*qfn1(fn))(qenv(fn), v0040);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    v0040 = nil;
    { popv(3); return onevalue(v0040); }

v0136:
    v0043 = stack[-1];
    v0040 = qvalue(elt(env, 3)); // n_all_parametric_ext
    v0040 = (LispObject)greaterp2(v0043, v0040);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    v0040 = v0040 ? lisp_true : nil;
    env = stack[-2];
    if (v0040 == nil) goto v0100;
    stack[0] = qvalue(elt(env, 4)); // all_principal_odd!*
    v0043 = stack[-1];
    v0040 = qvalue(elt(env, 3)); // n_all_parametric_ext
    v0040 = difference2(v0043, v0040);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    env = stack[-2];
    {
        LispObject v0137 = stack[0];
        popv(3);
        fn = elt(env, 7); // nth
        return (*qfn2(fn))(qenv(fn), v0137, v0040);
    }

v0100:
    v0043 = qvalue(elt(env, 5)); // all_parametric_odd!*
    v0040 = stack[-1];
    {
        popv(3);
        fn = elt(env, 7); // nth
        return (*qfn2(fn))(qenv(fn), v0043, v0040);
    }
// error exit handlers
v0135:
    popv(3);
    return nil;
}



// Code for setqdeletedescendants

static LispObject CC_setqdeletedescendants(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0118, v0016;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for setqdeletedescendants");
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
    v0118 = qvalue(elt(env, 1)); // fluidbibasissetq
    stack[-1] = v0118;
    goto v0014;

v0014:
    v0118 = stack[-1];
    v0118 = qcar(v0118);
    if (v0118 == nil) goto v0018;
    v0118 = stack[-1];
    v0016 = qcar(v0118);
    v0118 = (LispObject)33; // 2
    v0016 = *(LispObject *)((char *)v0016 + (CELL-TAG_VECTOR) + ((int32_t)v0118/(16/CELL)));
    v0118 = stack[0];
    if (equal(v0016, v0118)) goto v0021;
    v0118 = stack[-1];
    v0118 = qcdr(v0118);
    stack[-1] = v0118;
    goto v0014;

v0021:
    v0016 = stack[-1];
    v0118 = stack[-1];
    v0118 = qcdr(v0118);
    v0118 = qcar(v0118);
    v0016 = Lrplaca(nil, v0016, v0118);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-2];
    v0118 = stack[-1];
    v0118 = qcdr(v0118);
    v0118 = qcdr(v0118);
    v0118 = Lrplacd(nil, v0016, v0118);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-2];
    goto v0014;

v0018:
    v0118 = nil;
    { popv(3); return onevalue(v0118); }
// error exit handlers
v0139:
    popv(3);
    return nil;
}



// Code for ofsf_facneq!*

static LispObject CC_ofsf_facneqH(LispObject env,
                         LispObject v0000, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0133, v0134, v0143;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_facneq*");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0134 = v0007;
    v0143 = v0000;
// end of prologue
    v0133 = qvalue(elt(env, 1)); // !*rlsifac
    if (v0133 == nil) goto v0035;
    v0133 = qvalue(elt(env, 2)); // !*rlsiexpla
    if (!(v0133 == nil)) goto v0015;
    v0133 = qvalue(elt(env, 3)); // !*rlsiexpl
    if (v0133 == nil) goto v0035;
    v0133 = elt(env, 4); // and
    if (!(v0134 == v0133)) goto v0035;

v0015:
    v0133 = v0143;
    {
        fn = elt(env, 7); // ofsf_facneq
        return (*qfn1(fn))(qenv(fn), v0133);
    }

v0035:
    v0133 = elt(env, 5); // neq
    v0134 = v0143;
    v0143 = qvalue(elt(env, 6)); // nil
    return list3(v0133, v0134, v0143);
}



// Code for mk_character

static LispObject CC_mk_character(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0147, v0026;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mk_character");
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
    v0147 = stack[-5];
    fn = elt(env, 2); // get_group_in
    v0147 = (*qfn1(fn))(qenv(fn), v0147);
    nil = C_nil;
    if (exception_pending()) goto v0148;
    env = stack[-7];
    stack[-6] = v0147;
    v0147 = stack[-6];
    fn = elt(env, 3); // get!*elements
    v0147 = (*qfn1(fn))(qenv(fn), v0147);
    nil = C_nil;
    if (exception_pending()) goto v0148;
    env = stack[-7];
    stack[-4] = v0147;
    v0147 = stack[-4];
    if (v0147 == nil) goto v0048;
    v0147 = stack[-4];
    v0147 = qcar(v0147);
    stack[0] = v0147;
    v0026 = v0147;
    v0147 = stack[-5];
    fn = elt(env, 4); // get_rep_matrix_in
    v0147 = (*qfn2(fn))(qenv(fn), v0026, v0147);
    nil = C_nil;
    if (exception_pending()) goto v0148;
    env = stack[-7];
    fn = elt(env, 5); // mk!+trace
    v0147 = (*qfn1(fn))(qenv(fn), v0147);
    nil = C_nil;
    if (exception_pending()) goto v0148;
    env = stack[-7];
    v0147 = list2(stack[0], v0147);
    nil = C_nil;
    if (exception_pending()) goto v0148;
    env = stack[-7];
    v0147 = ncons(v0147);
    nil = C_nil;
    if (exception_pending()) goto v0148;
    env = stack[-7];
    stack[-2] = v0147;
    stack[-3] = v0147;
    goto v0049;

v0049:
    v0147 = stack[-4];
    v0147 = qcdr(v0147);
    stack[-4] = v0147;
    v0147 = stack[-4];
    if (v0147 == nil) goto v0051;
    stack[-1] = stack[-2];
    v0147 = stack[-4];
    v0147 = qcar(v0147);
    stack[0] = v0147;
    v0026 = v0147;
    v0147 = stack[-5];
    fn = elt(env, 4); // get_rep_matrix_in
    v0147 = (*qfn2(fn))(qenv(fn), v0026, v0147);
    nil = C_nil;
    if (exception_pending()) goto v0148;
    env = stack[-7];
    fn = elt(env, 5); // mk!+trace
    v0147 = (*qfn1(fn))(qenv(fn), v0147);
    nil = C_nil;
    if (exception_pending()) goto v0148;
    env = stack[-7];
    v0147 = list2(stack[0], v0147);
    nil = C_nil;
    if (exception_pending()) goto v0148;
    env = stack[-7];
    v0147 = ncons(v0147);
    nil = C_nil;
    if (exception_pending()) goto v0148;
    env = stack[-7];
    v0147 = Lrplacd(nil, stack[-1], v0147);
    nil = C_nil;
    if (exception_pending()) goto v0148;
    env = stack[-7];
    v0147 = stack[-2];
    v0147 = qcdr(v0147);
    stack[-2] = v0147;
    goto v0049;

v0051:
    v0147 = stack[-3];
    goto v0103;

v0103:
    stack[0] = v0147;
    v0147 = stack[-6];
    v0026 = ncons(v0147);
    nil = C_nil;
    if (exception_pending()) goto v0148;
    v0147 = stack[0];
        popv(8);
        return Lappend(nil, v0026, v0147);

v0048:
    v0147 = qvalue(elt(env, 1)); // nil
    goto v0103;
// error exit handlers
v0148:
    popv(8);
    return nil;
}



// Code for unary

static LispObject CC_unary(LispObject env,
                         LispObject v0000, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0138, v0141;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for unary");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0007,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0007);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0007;
    stack[-1] = v0000;
// end of prologue
    v0138 = elt(env, 1); // "<apply>"
    fn = elt(env, 6); // printout
    v0138 = (*qfn1(fn))(qenv(fn), v0138);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-2];
    v0138 = elt(env, 2); // "<"
    v0138 = Lprinc(nil, v0138);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-2];
    v0138 = stack[0];
    v0138 = Lprinc(nil, v0138);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-2];
    v0138 = elt(env, 3); // "/>"
    v0138 = Lprinc(nil, v0138);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-2];
    v0141 = qvalue(elt(env, 4)); // indent
    v0138 = (LispObject)49; // 3
    v0138 = plus2(v0141, v0138);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-2];
    qvalue(elt(env, 4)) = v0138; // indent
    v0138 = stack[-1];
    v0138 = qcar(v0138);
    fn = elt(env, 7); // expression
    v0138 = (*qfn1(fn))(qenv(fn), v0138);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-2];
    v0141 = qvalue(elt(env, 4)); // indent
    v0138 = (LispObject)49; // 3
    v0138 = difference2(v0141, v0138);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-2];
    qvalue(elt(env, 4)) = v0138; // indent
    v0138 = elt(env, 5); // "</apply>"
    fn = elt(env, 6); // printout
    v0138 = (*qfn1(fn))(qenv(fn), v0138);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    v0138 = nil;
    { popv(3); return onevalue(v0138); }
// error exit handlers
v0133:
    popv(3);
    return nil;
}



// Code for !*s2arg

static LispObject CC_Hs2arg(LispObject env,
                         LispObject v0000, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0095, v0151, v0152;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *s2arg");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0007,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0007);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-3] = v0007;
    v0151 = v0000;
// end of prologue
    v0095 = v0151;
    if (!consp(v0095)) goto v0145;
    v0095 = v0151;
    v0152 = qcar(v0095);
    v0095 = elt(env, 2); // quote
    v0095 = (v0152 == v0095 ? lisp_true : nil);
    goto v0014;

v0014:
    if (!(v0095 == nil)) { popv(6); return onevalue(v0151); }
    v0095 = v0151;
    v0095 = qcar(v0095);
    if (symbolp(v0095)) goto v0142;
    v0095 = qvalue(elt(env, 1)); // t
    goto v0035;

v0035:
    if (v0095 == nil) goto v0153;
    v0095 = v0151;
    stack[-4] = v0095;
    v0095 = stack[-4];
    if (v0095 == nil) goto v0008;
    v0095 = stack[-4];
    v0095 = qcar(v0095);
    v0151 = v0095;
    v0095 = stack[-3];
    v0095 = CC_Hs2arg(env, v0151, v0095);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-5];
    v0095 = ncons(v0095);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-5];
    stack[-1] = v0095;
    stack[-2] = v0095;
    goto v0029;

v0029:
    v0095 = stack[-4];
    v0095 = qcdr(v0095);
    stack[-4] = v0095;
    v0095 = stack[-4];
    if (v0095 == nil) { LispObject res = stack[-2]; popv(6); return onevalue(res); }
    stack[0] = stack[-1];
    v0095 = stack[-4];
    v0095 = qcar(v0095);
    v0151 = v0095;
    v0095 = stack[-3];
    v0095 = CC_Hs2arg(env, v0151, v0095);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-5];
    v0095 = ncons(v0095);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-5];
    v0095 = Lrplacd(nil, stack[0], v0095);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-5];
    v0095 = stack[-1];
    v0095 = qcdr(v0095);
    stack[-1] = v0095;
    goto v0029;

v0008:
    v0095 = qvalue(elt(env, 4)); // nil
    { popv(6); return onevalue(v0095); }

v0153:
    v0095 = stack[-3];
    {
        popv(6);
        fn = elt(env, 5); // mkarg
        return (*qfn2(fn))(qenv(fn), v0151, v0095);
    }

v0142:
    v0095 = v0151;
    v0152 = qcar(v0095);
    v0095 = elt(env, 3); // nochange
    v0095 = Lflagp(nil, v0152, v0095);
    env = stack[-5];
    v0095 = (v0095 == nil ? lisp_true : nil);
    goto v0035;

v0145:
    v0095 = qvalue(elt(env, 1)); // t
    goto v0014;
// error exit handlers
v0154:
    popv(6);
    return nil;
}



// Code for p_eq_vertex

static LispObject CC_p_eq_vertex(LispObject env,
                         LispObject v0000, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0142, v0133, v0134, v0143;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for p_eq_vertex");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0133 = v0007;
    v0134 = v0000;
// end of prologue

v0015:
    v0142 = v0134;
    if (v0142 == nil) goto v0014;
    v0142 = v0133;
    if (v0142 == nil) goto v0103;
    v0142 = v0134;
    v0142 = qcar(v0142);
    v0143 = qcar(v0142);
    v0142 = v0133;
    v0142 = qcar(v0142);
    v0142 = qcar(v0142);
    if (v0143 == v0142) goto v0046;
    v0142 = qvalue(elt(env, 1)); // nil
    return onevalue(v0142);

v0046:
    v0142 = v0134;
    v0142 = qcdr(v0142);
    v0134 = v0142;
    v0142 = v0133;
    v0142 = qcdr(v0142);
    v0133 = v0142;
    goto v0015;

v0103:
    v0142 = qvalue(elt(env, 1)); // nil
    return onevalue(v0142);

v0014:
    v0142 = v0133;
    v0142 = (v0142 == nil ? lisp_true : nil);
    return onevalue(v0142);
}



// Code for dp_content

static LispObject CC_dp_content(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0127;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dp_content");
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
    v0127 = stack[0];
    if (v0127 == nil) goto v0005;
    v0127 = stack[0];
    fn = elt(env, 2); // dp_lc
    v0127 = (*qfn1(fn))(qenv(fn), v0127);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-2];
    stack[-1] = v0127;
    v0127 = stack[0];
    v0127 = qcdr(v0127);
    stack[0] = v0127;
    goto v0047;

v0047:
    v0127 = stack[0];
    if (v0127 == nil) { LispObject res = stack[-1]; popv(3); return onevalue(res); }
    v0127 = stack[-1];
    fn = elt(env, 3); // cali_bc_inv
    v0127 = (*qfn1(fn))(qenv(fn), v0127);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-2];
    if (!(v0127 == nil)) { LispObject res = stack[-1]; popv(3); return onevalue(res); }
    v0127 = stack[0];
    fn = elt(env, 2); // dp_lc
    v0127 = (*qfn1(fn))(qenv(fn), v0127);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-2];
    fn = elt(env, 4); // cali_bc_gcd
    v0127 = (*qfn2(fn))(qenv(fn), stack[-1], v0127);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-2];
    stack[-1] = v0127;
    v0127 = stack[0];
    v0127 = qcdr(v0127);
    stack[0] = v0127;
    goto v0047;

v0005:
    v0127 = (LispObject)1; // 0
    {
        popv(3);
        fn = elt(env, 5); // cali_bc_fi
        return (*qfn1(fn))(qenv(fn), v0127);
    }
// error exit handlers
v0027:
    popv(3);
    return nil;
}



// Code for affinep

static LispObject CC_affinep(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0047, v0001;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for affinep");
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
    v0047 = v0000;
// end of prologue
    v0001 = qcar(v0047);
    v0047 = elt(env, 1); // belong_to_space
    v0047 = get(v0001, v0047);
    env = stack[0];
    v0001 = v0047;
    v0047 = v0001;
    if (v0047 == nil) goto v0045;
    v0047 = v0001;
    fn = elt(env, 2); // get_sign_space
    v0047 = (*qfn1(fn))(qenv(fn), v0047);
    nil = C_nil;
    if (exception_pending()) goto v0002;
    v0047 = (v0047 == nil ? lisp_true : nil);
    { popv(1); return onevalue(v0047); }

v0045:
    v0047 = nil;
    { popv(1); return onevalue(v0047); }
// error exit handlers
v0002:
    popv(1);
    return nil;
}



// Code for algebnp

static LispObject CC_algebnp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0041, v0027;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for algebnp");
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

v0054:
    v0041 = stack[0];
    if (!consp(v0041)) goto v0005;
    v0041 = stack[0];
    v0027 = qcar(v0041);
    v0041 = elt(env, 2); // !:ar!:
    if (v0027 == v0041) goto v0014;
    v0041 = stack[0];
    if (!consp(v0041)) goto v0155;
    v0041 = stack[0];
    v0041 = qcar(v0041);
    v0041 = (consp(v0041) ? nil : lisp_true);
    goto v0002;

v0002:
    if (v0041 == nil) goto v0136;
    v0041 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0041); }

v0136:
    v0041 = stack[0];
    v0041 = qcar(v0041);
    v0041 = qcdr(v0041);
    v0041 = CC_algebnp(env, v0041);
    nil = C_nil;
    if (exception_pending()) goto v0052;
    env = stack[-1];
    if (!(v0041 == nil)) { popv(2); return onevalue(v0041); }
    v0041 = stack[0];
    v0041 = qcdr(v0041);
    stack[0] = v0041;
    goto v0054;

v0155:
    v0041 = qvalue(elt(env, 3)); // t
    goto v0002;

v0014:
    v0041 = qvalue(elt(env, 3)); // t
    { popv(2); return onevalue(v0041); }

v0005:
    v0041 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0041); }
// error exit handlers
v0052:
    popv(2);
    return nil;
}



// Code for r2flbf

static LispObject CC_r2flbf(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0103, v0049;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for r2flbf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0049 = v0000;
// end of prologue
    v0103 = qvalue(elt(env, 1)); // !*bftag
    if (v0103 == nil) goto v0145;
    v0103 = v0049;
    {
        fn = elt(env, 2); // r2bf
        return (*qfn1(fn))(qenv(fn), v0103);
    }

v0145:
    v0103 = v0049;
    {
        fn = elt(env, 3); // r2fl
        return (*qfn1(fn))(qenv(fn), v0103);
    }
}



// Code for redmsg

static LispObject CC_redmsg(LispObject env,
                         LispObject v0000, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0156, v0031, v0030;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for redmsg");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0007,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0007);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0007;
    stack[-1] = v0000;
// end of prologue
    v0156 = qvalue(elt(env, 1)); // !*wsm
    if (v0156 == nil) goto v0145;
    v0156 = qvalue(elt(env, 3)); // nil
    goto v0014;

v0014:
    if (v0156 == nil) goto v0019;
    fn = elt(env, 8); // terminalp
    v0156 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-3];
    if (v0156 == nil) goto v0157;
    stack[-2] = elt(env, 5); // "Declare"
    v0156 = stack[-1];
    fn = elt(env, 9); // get!-print!-name
    v0030 = (*qfn1(fn))(qenv(fn), v0156);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-3];
    v0031 = stack[0];
    v0156 = elt(env, 6); // "?"
    v0156 = list4(stack[-2], v0030, v0031, v0156);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-3];
    fn = elt(env, 10); // yesp
    v0156 = (*qfn1(fn))(qenv(fn), v0156);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    if (!(v0156 == nil)) { popv(4); return onevalue(v0156); }
        popv(4);
        return Lerror0(nil, 0);

v0157:
    v0156 = stack[-1];
    fn = elt(env, 9); // get!-print!-name
    v0030 = (*qfn1(fn))(qenv(fn), v0156);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-3];
    v0031 = elt(env, 7); // "declared"
    v0156 = stack[0];
    v0156 = list3(v0030, v0031, v0156);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-3];
    {
        popv(4);
        fn = elt(env, 11); // lprim
        return (*qfn1(fn))(qenv(fn), v0156);
    }

v0019:
    v0156 = nil;
    { popv(4); return onevalue(v0156); }

v0145:
    v0156 = qvalue(elt(env, 2)); // !*msg
    if (v0156 == nil) goto v0049;
    v0031 = stack[0];
    v0156 = elt(env, 4); // ("operator" "predicate")
    v0156 = Lmember(nil, v0031, v0156);
    goto v0014;

v0049:
    v0156 = qvalue(elt(env, 3)); // nil
    goto v0014;
// error exit handlers
v0144:
    popv(4);
    return nil;
}



// Code for gcdk

static LispObject CC_gcdk(LispObject env,
                         LispObject v0000, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0187, v0188, v0189;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gcdk");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0007,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0007);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    stack[-9] = v0007;
    stack[0] = v0000;
// end of prologue
    stack[-10] = nil;
    stack[-8] = nil;
    v0188 = stack[0];
    v0187 = stack[-9];
    if (equal(v0188, v0187)) { LispObject res = stack[0]; popv(12); return onevalue(res); }
    v0187 = stack[0];
    if (!consp(v0187)) goto v0050;
    v0187 = stack[0];
    v0187 = qcar(v0187);
    v0187 = (consp(v0187) ? nil : lisp_true);
    goto v0036;

v0036:
    if (v0187 == nil) goto v0052;
    v0187 = qvalue(elt(env, 1)); // t
    goto v0004;

v0004:
    if (v0187 == nil) goto v0009;
    v0187 = (LispObject)17; // 1
    { popv(12); return onevalue(v0187); }

v0009:
    v0187 = stack[0];
    v0187 = qcar(v0187);
    v0187 = qcar(v0187);
    v0188 = qcdr(v0187);
    v0187 = stack[-9];
    v0187 = qcar(v0187);
    v0187 = qcar(v0187);
    v0187 = qcdr(v0187);
    v0187 = (LispObject)lessp2(v0188, v0187);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    v0187 = v0187 ? lisp_true : nil;
    env = stack[-11];
    if (v0187 == nil) goto v0025;
    v0187 = stack[0];
    stack[-7] = v0187;
    v0187 = stack[-9];
    stack[0] = v0187;
    v0187 = stack[-7];
    stack[-9] = v0187;
    goto v0025;

v0025:
    v0188 = stack[0];
    v0187 = stack[-9];
    fn = elt(env, 7); // quotf1
    v0187 = (*qfn2(fn))(qenv(fn), v0188, v0187);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-11];
    if (!(v0187 == nil)) { LispObject res = stack[-9]; popv(12); return onevalue(res); }
    v0187 = qvalue(elt(env, 2)); // !*heugcd
    if (v0187 == nil) goto v0191;
    v0188 = stack[0];
    v0187 = stack[-9];
    fn = elt(env, 8); // heu!-gcd
    v0187 = (*qfn2(fn))(qenv(fn), v0188, v0187);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-11];
    v0188 = v0187;
    if (!(v0187 == nil)) { popv(12); return onevalue(v0188); }

v0191:
    v0187 = stack[-9];
    v0187 = qcar(v0187);
    v0187 = qcar(v0187);
    v0188 = qcdr(v0187);
    v0187 = (LispObject)17; // 1
    if (v0188 == v0187) goto v0151;
    v0187 = elt(env, 3); // modular!-multicheck
    fn = elt(env, 9); // getd
    v0187 = (*qfn1(fn))(qenv(fn), v0187);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-11];
    if (v0187 == nil) goto v0093;
    v0189 = stack[0];
    v0188 = stack[-9];
    v0187 = stack[-8];
    fn = elt(env, 3); // modular!-multicheck
    v0187 = (*qfnn(fn))(qenv(fn), 3, v0189, v0188, v0187);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-11];
    goto v0192;

v0192:
    if (!(v0187 == nil)) goto v0095;
    v0187 = qvalue(elt(env, 5)); // !*mcd
    v0187 = (v0187 == nil ? lisp_true : nil);
    goto v0095;

v0095:
    if (v0187 == nil) goto v0193;
    v0187 = (LispObject)17; // 1
    { popv(12); return onevalue(v0187); }

v0193:
    v0188 = stack[0];
    v0187 = stack[-9];
    fn = elt(env, 10); // remk
    v0187 = (*qfn2(fn))(qenv(fn), v0188, v0187);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-11];
    stack[-7] = v0187;
    v0187 = stack[-7];
    if (v0187 == nil) { LispObject res = stack[-9]; popv(12); return onevalue(res); }
    v0188 = stack[-7];
    v0187 = stack[-8];
    fn = elt(env, 11); // degr
    v0188 = (*qfn2(fn))(qenv(fn), v0188, v0187);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-11];
    v0187 = (LispObject)1; // 0
    if (v0188 == v0187) goto v0194;
    v0188 = stack[-9];
    v0187 = stack[-10];
    fn = elt(env, 12); // addlc
    v0187 = (*qfn2(fn))(qenv(fn), v0188, v0187);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-11];
    stack[-10] = v0187;
    v0188 = stack[-7];
    v0187 = stack[-7];
    v0187 = qcar(v0187);
    v0187 = qcdr(v0187);
    fn = elt(env, 7); // quotf1
    v0187 = (*qfn2(fn))(qenv(fn), v0188, v0187);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-11];
    v0188 = v0187;
    if (v0187 == nil) goto v0195;
    v0187 = v0188;
    stack[-7] = v0187;
    goto v0081;

v0081:
    v0187 = stack[-9];
    stack[0] = v0187;
    v0187 = stack[-7];
    fn = elt(env, 13); // prim!-part
    v0187 = (*qfn1(fn))(qenv(fn), v0187);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-11];
    stack[-9] = v0187;
    v0188 = stack[-9];
    v0187 = stack[-8];
    fn = elt(env, 11); // degr
    v0188 = (*qfn2(fn))(qenv(fn), v0188, v0187);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-11];
    v0187 = (LispObject)1; // 0
    if (!(v0188 == v0187)) goto v0193;
    v0187 = (LispObject)17; // 1
    { popv(12); return onevalue(v0187); }

v0195:
    v0187 = stack[-10];
    stack[-6] = v0187;
    goto v0196;

v0196:
    v0187 = stack[-6];
    if (v0187 == nil) goto v0081;
    v0187 = stack[-6];
    v0187 = qcar(v0187);
    stack[-5] = v0187;
    v0187 = stack[-5];
    if (!consp(v0187)) goto v0197;
    v0187 = qvalue(elt(env, 4)); // nil
    goto v0198;

v0198:
    if (v0187 == nil) goto v0199;
    v0187 = qvalue(elt(env, 1)); // t
    goto v0200;

v0200:
    if (!(v0187 == nil)) goto v0201;

v0202:
    v0187 = stack[-6];
    v0187 = qcdr(v0187);
    stack[-6] = v0187;
    goto v0196;

v0201:
    v0188 = stack[-7];
    v0187 = stack[-5];
    fn = elt(env, 7); // quotf1
    v0187 = (*qfn2(fn))(qenv(fn), v0188, v0187);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-11];
    v0188 = v0187;
    if (v0187 == nil) goto v0202;
    v0187 = v0188;
    stack[-7] = v0187;
    goto v0201;

v0199:
    v0187 = stack[-5];
    if (!consp(v0187)) goto v0203;
    v0187 = stack[-5];
    v0187 = qcar(v0187);
    v0187 = (consp(v0187) ? nil : lisp_true);
    goto v0204;

v0204:
    if (v0187 == nil) goto v0205;
    v0187 = qvalue(elt(env, 6)); // dmode!*
    if (!symbolp(v0187)) v0187 = nil;
    else { v0187 = qfastgets(v0187);
           if (v0187 != nil) { v0187 = elt(v0187, 3); // field
#ifdef RECORD_GET
             if (v0187 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v0187 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v0187 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v0187 == SPID_NOPROP) v0187 = nil; else v0187 = lisp_true; }}
#endif
    if (v0187 == nil) goto v0206;
    v0187 = qvalue(elt(env, 1)); // t
    goto v0207;

v0207:
    v0187 = (v0187 == nil ? lisp_true : nil);
    goto v0200;

v0206:
    v0187 = stack[-5];
    v0187 = qcar(v0187);
    if (!symbolp(v0187)) v0187 = nil;
    else { v0187 = qfastgets(v0187);
           if (v0187 != nil) { v0187 = elt(v0187, 27); // units
#ifdef RECORD_GET
             if (v0187 != SPID_NOPROP)
                record_get(elt(fastget_names, 27), 1);
             else record_get(elt(fastget_names, 27), 0),
                v0187 = nil; }
           else record_get(elt(fastget_names, 27), 0); }
#else
             if (v0187 == SPID_NOPROP) v0187 = nil; }}
#endif
    v0188 = v0187;
    if (v0187 == nil) goto v0208;
    stack[-4] = stack[-5];
    v0187 = v0188;
    stack[-3] = v0187;
    v0187 = stack[-3];
    if (v0187 == nil) goto v0209;
    v0187 = stack[-3];
    v0187 = qcar(v0187);
    v0187 = qcar(v0187);
    v0187 = ncons(v0187);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-11];
    stack[-1] = v0187;
    stack[-2] = v0187;
    goto v0113;

v0113:
    v0187 = stack[-3];
    v0187 = qcdr(v0187);
    stack[-3] = v0187;
    v0187 = stack[-3];
    if (v0187 == nil) goto v0210;
    stack[0] = stack[-1];
    v0187 = stack[-3];
    v0187 = qcar(v0187);
    v0187 = qcar(v0187);
    v0187 = ncons(v0187);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-11];
    v0187 = Lrplacd(nil, stack[0], v0187);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-11];
    v0187 = stack[-1];
    v0187 = qcdr(v0187);
    stack[-1] = v0187;
    goto v0113;

v0210:
    v0187 = stack[-2];
    goto v0211;

v0211:
    v0187 = Lmember(nil, stack[-4], v0187);
    goto v0207;

v0209:
    v0187 = qvalue(elt(env, 4)); // nil
    goto v0211;

v0208:
    v0187 = qvalue(elt(env, 4)); // nil
    goto v0207;

v0205:
    v0187 = qvalue(elt(env, 4)); // nil
    goto v0207;

v0203:
    v0187 = qvalue(elt(env, 1)); // t
    goto v0204;

v0197:
    v0187 = qvalue(elt(env, 6)); // dmode!*
    if (!symbolp(v0187)) v0187 = nil;
    else { v0187 = qfastgets(v0187);
           if (v0187 != nil) { v0187 = elt(v0187, 3); // field
#ifdef RECORD_GET
             if (v0187 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v0187 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v0187 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v0187 == SPID_NOPROP) v0187 = nil; else v0187 = lisp_true; }}
#endif
    v0187 = (v0187 == nil ? lisp_true : nil);
    goto v0198;

v0194:
    v0187 = (LispObject)17; // 1
    { popv(12); return onevalue(v0187); }

v0093:
    v0187 = qvalue(elt(env, 4)); // nil
    goto v0192;

v0151:
    v0187 = qvalue(elt(env, 1)); // t
    goto v0095;

v0052:
    v0188 = stack[-9];
    v0187 = stack[0];
    v0187 = qcar(v0187);
    v0187 = qcar(v0187);
    v0187 = qcar(v0187);
    stack[-8] = v0187;
    fn = elt(env, 11); // degr
    v0188 = (*qfn2(fn))(qenv(fn), v0188, v0187);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-11];
    v0187 = (LispObject)1; // 0
    v0187 = (v0188 == v0187 ? lisp_true : nil);
    goto v0004;

v0050:
    v0187 = qvalue(elt(env, 1)); // t
    goto v0036;
// error exit handlers
v0190:
    popv(12);
    return nil;
}



// Code for clearrules

static LispObject CC_clearrules(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0122, v0103;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for clearrules");
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
    v0103 = v0000;
// end of prologue
    v0122 = qvalue(elt(env, 1)); // nil
    stack[0] = qvalue(elt(env, 2)); // !*sqrtrulep
    qvalue(elt(env, 2)) = v0122; // !*sqrtrulep
    v0122 = qvalue(elt(env, 1)); // nil
    fn = elt(env, 3); // rule!-list
    v0122 = (*qfn2(fn))(qenv(fn), v0103, v0122);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; // !*sqrtrulep
    { popv(2); return onevalue(v0122); }
// error exit handlers
v0045:
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; // !*sqrtrulep
    popv(2);
    return nil;
}



// Code for conjgd

static LispObject CC_conjgd(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0217, v0194;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for conjgd");
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
    v0194 = nil;
    v0217 = stack[-1];
    if (!consp(v0217)) { LispObject res = stack[-1]; popv(4); return onevalue(res); }
    v0217 = stack[-1];
    if (!consp(v0217)) goto v0048;
    v0217 = stack[-1];
    v0217 = qcar(v0217);
    v0217 = (consp(v0217) ? nil : lisp_true);
    goto v0044;

v0044:
    if (v0217 == nil) goto v0142;
    v0217 = stack[-1];
    v0194 = qcar(v0217);
    v0217 = elt(env, 2); // cmpxfn
    v0217 = get(v0194, v0217);
    env = stack[-3];
    v0194 = v0217;
    goto v0049;

v0049:
    if (v0217 == nil) goto v0122;
    stack[-2] = v0194;
    v0217 = stack[-1];
    v0217 = qcdr(v0217);
    stack[0] = qcar(v0217);
    v0217 = stack[-1];
    v0217 = qcdr(v0217);
    v0217 = qcdr(v0217);
    if (is_number(v0217)) goto v0132;
    v0217 = stack[-1];
    v0217 = qcdr(v0217);
    v0217 = qcdr(v0217);
    if (!consp(v0217)) goto v0156;
    v0217 = stack[-1];
    v0217 = qcdr(v0217);
    v0217 = qcdr(v0217);
    v0217 = qcar(v0217);
    v0217 = (consp(v0217) ? nil : lisp_true);
    goto v0150;

v0150:
    if (v0217 == nil) goto v0147;
    v0217 = stack[-1];
    v0217 = qcdr(v0217);
    v0217 = qcdr(v0217);
    v0217 = qcar(v0217);
    v0217 = (is_number(v0217) ? lisp_true : nil);
    v0217 = (v0217 == nil ? lisp_true : nil);
    goto v0028;

v0028:
    if (v0217 == nil) goto v0218;
    v0217 = stack[-1];
    v0217 = qcdr(v0217);
    v0217 = qcdr(v0217);
    fn = elt(env, 5); // !:minus
    v0217 = (*qfn1(fn))(qenv(fn), v0217);
    nil = C_nil;
    if (exception_pending()) goto v0219;
    goto v0027;

v0027:
    {
        LispObject v0220 = stack[-2];
        LispObject v0221 = stack[0];
        popv(4);
        return Lapply2(nil, 3, v0220, v0221, v0217);
    }

v0218:
    v0217 = stack[-1];
    v0194 = qcar(v0217);
    v0217 = elt(env, 4); // realtype
    v0194 = get(v0194, v0217);
    env = stack[-3];
    v0217 = stack[-1];
    v0217 = qcdr(v0217);
    v0217 = qcdr(v0217);
    v0217 = cons(v0194, v0217);
    nil = C_nil;
    if (exception_pending()) goto v0219;
    env = stack[-3];
    fn = elt(env, 5); // !:minus
    v0217 = (*qfn1(fn))(qenv(fn), v0217);
    nil = C_nil;
    if (exception_pending()) goto v0219;
    v0217 = qcdr(v0217);
    goto v0027;

v0147:
    v0217 = qvalue(elt(env, 3)); // nil
    goto v0028;

v0156:
    v0217 = qvalue(elt(env, 1)); // t
    goto v0150;

v0132:
    v0217 = stack[-1];
    v0217 = qcdr(v0217);
    v0217 = qcdr(v0217);
    v0217 = negate(v0217);
    nil = C_nil;
    if (exception_pending()) goto v0219;
    goto v0027;

v0122:
    v0217 = stack[-1];
    if (!consp(v0217)) goto v0090;
    v0217 = stack[-1];
    v0217 = qcar(v0217);
    v0217 = (consp(v0217) ? nil : lisp_true);
    goto v0091;

v0091:
    if (!(v0217 == nil)) { LispObject res = stack[-1]; popv(4); return onevalue(res); }
    v0217 = stack[-1];
    v0217 = qcar(v0217);
    v0194 = qcar(v0217);
    v0217 = (LispObject)17; // 1
    v0217 = cons(v0194, v0217);
    nil = C_nil;
    if (exception_pending()) goto v0219;
    env = stack[-3];
    stack[0] = ncons(v0217);
    nil = C_nil;
    if (exception_pending()) goto v0219;
    env = stack[-3];
    v0217 = stack[-1];
    v0217 = qcar(v0217);
    v0217 = qcdr(v0217);
    v0217 = CC_conjgd(env, v0217);
    nil = C_nil;
    if (exception_pending()) goto v0219;
    env = stack[-3];
    fn = elt(env, 6); // multf
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v0217);
    nil = C_nil;
    if (exception_pending()) goto v0219;
    env = stack[-3];
    v0217 = stack[-1];
    v0217 = qcdr(v0217);
    v0217 = CC_conjgd(env, v0217);
    nil = C_nil;
    if (exception_pending()) goto v0219;
    env = stack[-3];
    {
        LispObject v0178 = stack[0];
        popv(4);
        fn = elt(env, 7); // addf
        return (*qfn2(fn))(qenv(fn), v0178, v0217);
    }

v0090:
    v0217 = qvalue(elt(env, 1)); // t
    goto v0091;

v0142:
    v0217 = qvalue(elt(env, 3)); // nil
    goto v0049;

v0048:
    v0217 = qvalue(elt(env, 1)); // t
    goto v0044;
// error exit handlers
v0219:
    popv(4);
    return nil;
}



// Code for negdf

static LispObject CC_negdf(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0136, v0138;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for negdf");
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
    goto v0015;

v0015:
    v0136 = stack[-1];
    if (v0136 == nil) goto v0014;
    v0136 = stack[-1];
    v0136 = qcar(v0136);
    stack[0] = qcar(v0136);
    v0136 = stack[-1];
    v0136 = qcar(v0136);
    v0136 = qcdr(v0136);
    fn = elt(env, 1); // negsq
    v0138 = (*qfn1(fn))(qenv(fn), v0136);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-3];
    v0136 = stack[-2];
    v0136 = acons(stack[0], v0138, v0136);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-3];
    stack[-2] = v0136;
    v0136 = stack[-1];
    v0136 = qcdr(v0136);
    stack[-1] = v0136;
    goto v0015;

v0014:
    v0136 = stack[-2];
    {
        popv(4);
        fn = elt(env, 2); // nreverse
        return (*qfn1(fn))(qenv(fn), v0136);
    }
// error exit handlers
v0133:
    popv(4);
    return nil;
}



// Code for get!*generators

static LispObject CC_getHgenerators(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0122, v0103;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for get*generators");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0122 = v0000;
// end of prologue
    v0103 = elt(env, 1); // generators
    return get(v0122, v0103);
}



// Code for rl_cput

static LispObject CC_rl_cput(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0036, v0050, v0034, v0039;
    LispObject v0124, v0007, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "rl_cput");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0007 = va_arg(aa, LispObject);
    v0124 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rl_cput");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0124,v0007,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0007,v0124);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
// copy arguments values to proper place
    v0036 = v0124;
    v0034 = v0007;
    v0039 = v0000;
// end of prologue
    v0050 = v0036;
    v0036 = v0034;
    v0036 = get(v0050, v0036);
    v0050 = v0036;
    v0036 = v0050;
    if (v0036 == nil) goto v0101;
    v0036 = v0039;
        return Lputprop(nil, 3, v0036, v0034, v0050);

v0101:
    v0036 = nil;
    return onevalue(v0036);
}



// Code for dvfsf_qesubqat

static LispObject CC_dvfsf_qesubqat(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0147, v0026;
    LispObject fn;
    LispObject v0124, v0007, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "dvfsf_qesubqat");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0007 = va_arg(aa, LispObject);
    v0124 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dvfsf_qesubqat");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0124,v0007,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0007,v0124);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0124;
    stack[-1] = v0007;
    stack[-2] = v0000;
// end of prologue
    v0147 = stack[-2];
    fn = elt(env, 2); // dvfsf_op
    v0147 = (*qfn1(fn))(qenv(fn), v0147);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    env = stack[-4];
    stack[-3] = v0147;
    v0147 = stack[0];
    fn = elt(env, 3); // prepsq
    v0147 = (*qfn1(fn))(qenv(fn), v0147);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    env = stack[-4];
    v0147 = cons(stack[-1], v0147);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    env = stack[-4];
    v0147 = ncons(v0147);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    env = stack[-4];
    stack[0] = v0147;
    v0147 = stack[-2];
    fn = elt(env, 4); // dvfsf_arg2l
    v0026 = (*qfn1(fn))(qenv(fn), v0147);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    env = stack[-4];
    v0147 = stack[0];
    fn = elt(env, 5); // subf
    v0147 = (*qfn2(fn))(qenv(fn), v0026, v0147);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    env = stack[-4];
    stack[-1] = v0147;
    v0026 = stack[-3];
    v0147 = elt(env, 1); // (equal neq)
    v0147 = Lmemq(nil, v0026, v0147);
    if (v0147 == nil) goto v0010;
    v0026 = stack[-3];
    v0147 = stack[-1];
    v0147 = qcar(v0147);
    {
        popv(5);
        fn = elt(env, 6); // dvfsf_0mk2
        return (*qfn2(fn))(qenv(fn), v0026, v0147);
    }

v0010:
    v0147 = stack[-2];
    fn = elt(env, 7); // dvfsf_arg2r
    v0026 = (*qfn1(fn))(qenv(fn), v0147);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    env = stack[-4];
    v0147 = stack[0];
    fn = elt(env, 5); // subf
    v0147 = (*qfn2(fn))(qenv(fn), v0026, v0147);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    env = stack[-4];
    stack[-2] = v0147;
    v0147 = stack[-1];
    v0026 = qcar(v0147);
    v0147 = stack[-2];
    v0147 = qcdr(v0147);
    fn = elt(env, 8); // multf
    stack[0] = (*qfn2(fn))(qenv(fn), v0026, v0147);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    env = stack[-4];
    v0147 = stack[-2];
    v0026 = qcar(v0147);
    v0147 = stack[-1];
    v0147 = qcdr(v0147);
    fn = elt(env, 8); // multf
    v0147 = (*qfn2(fn))(qenv(fn), v0026, v0147);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    env = stack[-4];
    {
        LispObject v0137 = stack[-3];
        LispObject v0223 = stack[0];
        popv(5);
        fn = elt(env, 9); // dvfsf_mk2
        return (*qfnn(fn))(qenv(fn), 3, v0137, v0223, v0147);
    }
// error exit handlers
v0135:
    popv(5);
    return nil;
}



// Code for mkarg

static LispObject CC_mkarg(LispObject env,
                         LispObject v0000, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0038, v0147;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mkarg");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0007,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0007);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0007;
    stack[-1] = v0000;
// end of prologue
    v0038 = stack[-1];
    if (v0038 == nil) goto v0145;
    v0038 = stack[-1];
    v0038 = Lconstantp(nil, v0038);
    env = stack[-3];
    goto v0014;

v0014:
    if (!(v0038 == nil)) { LispObject res = stack[-1]; popv(4); return onevalue(res); }
    v0038 = stack[-1];
    if (!consp(v0038)) goto v0004;
    v0038 = stack[-1];
    v0147 = qcar(v0038);
    v0038 = elt(env, 2); // (quote !:dn!: !:int!:)
    v0038 = Lmemq(nil, v0147, v0038);
    if (v0038 == nil) goto v0029;
    v0038 = stack[-1];
        popv(4);
        return Lmkquote(nil, v0038);

v0029:
    stack[-2] = nil;
    goto v0224;

v0224:
    v0038 = stack[-1];
    if (v0038 == nil) goto v0017;
    v0038 = stack[-1];
    v0147 = qcar(v0038);
    v0038 = stack[0];
    v0147 = CC_mkarg(env, v0147, v0038);
    nil = C_nil;
    if (exception_pending()) goto v0225;
    env = stack[-3];
    v0038 = stack[-2];
    v0038 = cons(v0147, v0038);
    nil = C_nil;
    if (exception_pending()) goto v0225;
    env = stack[-3];
    stack[-2] = v0038;
    v0038 = stack[-1];
    v0038 = qcdr(v0038);
    stack[-1] = v0038;
    goto v0224;

v0017:
    stack[0] = elt(env, 3); // list
    v0038 = stack[-2];
    fn = elt(env, 4); // reversip!*
    v0038 = (*qfn1(fn))(qenv(fn), v0038);
    nil = C_nil;
    if (exception_pending()) goto v0225;
    {
        LispObject v0226 = stack[0];
        popv(4);
        return cons(v0226, v0038);
    }

v0004:
    v0147 = stack[-1];
    v0038 = stack[0];
    v0038 = Latsoc(nil, v0147, v0038);
    if (!(v0038 == nil)) { LispObject res = stack[-1]; popv(4); return onevalue(res); }
    v0038 = stack[-1];
        popv(4);
        return Lmkquote(nil, v0038);

v0145:
    v0038 = qvalue(elt(env, 1)); // t
    goto v0014;
// error exit handlers
v0225:
    popv(4);
    return nil;
}



// Code for numberofoccs

static LispObject CC_numberofoccs(LispObject env,
                         LispObject v0000, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0227, v0222;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for numberofoccs");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0007,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0007);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0007;
    stack[-1] = v0000;
// end of prologue
    v0227 = stack[0];
    if (!consp(v0227)) goto v0122;
    v0227 = stack[0];
    v0227 = qcdr(v0227);
    if (v0227 == nil) goto v0027;
    v0222 = stack[-1];
    v0227 = stack[0];
    v0227 = qcdr(v0227);
    v0227 = CC_numberofoccs(env, v0222, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[-3];
    stack[-2] = v0227;
    goto v0010;

v0010:
    v0222 = stack[-1];
    v0227 = stack[0];
    v0227 = qcar(v0227);
    if (equal(v0222, v0227)) goto v0029;
    v0227 = stack[0];
    v0227 = qcar(v0227);
    if (!consp(v0227)) goto v0130;
    v0222 = stack[-1];
    v0227 = stack[0];
    v0227 = qcar(v0227);
    v0227 = CC_numberofoccs(env, v0222, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    goto v0036;

v0036:
    {
        LispObject v0024 = stack[-2];
        popv(4);
        return plus2(v0024, v0227);
    }

v0130:
    v0227 = (LispObject)1; // 0
    goto v0036;

v0029:
    v0227 = (LispObject)17; // 1
    goto v0036;

v0027:
    v0227 = (LispObject)1; // 0
    stack[-2] = v0227;
    goto v0010;

v0122:
    v0222 = stack[-1];
    v0227 = stack[0];
    if (equal(v0222, v0227)) goto v0123;
    v0227 = (LispObject)1; // 0
    { popv(4); return onevalue(v0227); }

v0123:
    v0227 = (LispObject)17; // 1
    { popv(4); return onevalue(v0227); }
// error exit handlers
v0023:
    popv(4);
    return nil;
}



// Code for xvarp

static LispObject CC_xvarp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0126, v0150;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for xvarp");
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
    v0150 = qvalue(elt(env, 1)); // xvars!*
    v0126 = qvalue(elt(env, 2)); // t
    if (equal(v0150, v0126)) goto v0015;
    v0126 = stack[0];
    fn = elt(env, 4); // xdegree
    v0150 = (*qfn1(fn))(qenv(fn), v0126);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    env = stack[-1];
    v0126 = (LispObject)1; // 0
    if (v0150 == v0126) goto v0035;
    v0126 = qvalue(elt(env, 2)); // t
    { popv(2); return onevalue(v0126); }

v0035:
    v0126 = stack[0];
    v0150 = qvalue(elt(env, 1)); // xvars!*
    v0126 = Lmemq(nil, v0126, v0150);
    { popv(2); return onevalue(v0126); }

v0015:
    v0126 = stack[0];
    if (!consp(v0126)) goto v0140;
    v0126 = stack[0];
    v0126 = qcar(v0126);
    if (!symbolp(v0126)) v0126 = nil;
    else { v0126 = qfastgets(v0126);
           if (v0126 != nil) { v0126 = elt(v0126, 16); // indexvar
#ifdef RECORD_GET
             if (v0126 == SPID_NOPROP)
                record_get(elt(fastget_names, 16), 0),
                v0126 = nil;
             else record_get(elt(fastget_names, 16), 1),
                v0126 = lisp_true; }
           else record_get(elt(fastget_names, 16), 0); }
#else
             if (v0126 == SPID_NOPROP) v0126 = nil; else v0126 = lisp_true; }}
#endif
    if (v0126 == nil) goto v0157;
    v0126 = stack[0];
    v0126 = qcdr(v0126);
    v0150 = Llength(nil, v0126);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    v0126 = stack[0];
    v0126 = qcar(v0126);
    if (!symbolp(v0126)) v0126 = nil;
    else { v0126 = qfastgets(v0126);
           if (v0126 != nil) { v0126 = elt(v0126, 25); // ifdegree
#ifdef RECORD_GET
             if (v0126 != SPID_NOPROP)
                record_get(elt(fastget_names, 25), 1);
             else record_get(elt(fastget_names, 25), 0),
                v0126 = nil; }
           else record_get(elt(fastget_names, 25), 0); }
#else
             if (v0126 == SPID_NOPROP) v0126 = nil; }}
#endif
    v0126 = Lassoc(nil, v0150, v0126);
    { popv(2); return onevalue(v0126); }

v0157:
    v0126 = stack[0];
    v0126 = qcar(v0126);
    v0150 = elt(env, 3); // (wedge d partdf hodge innerprod liedf)
    v0126 = Lmemq(nil, v0126, v0150);
    { popv(2); return onevalue(v0126); }

v0140:
    v0126 = stack[0];
    if (!symbolp(v0126)) v0126 = nil;
    else { v0126 = qfastgets(v0126);
           if (v0126 != nil) { v0126 = elt(v0126, 29); // fdegree
#ifdef RECORD_GET
             if (v0126 != SPID_NOPROP)
                record_get(elt(fastget_names, 29), 1);
             else record_get(elt(fastget_names, 29), 0),
                v0126 = nil; }
           else record_get(elt(fastget_names, 29), 0); }
#else
             if (v0126 == SPID_NOPROP) v0126 = nil; }}
#endif
    { popv(2); return onevalue(v0126); }
// error exit handlers
v0031:
    popv(2);
    return nil;
}



// Code for exp!:

static LispObject CC_expT(LispObject env,
                         LispObject v0000, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0210, v0249, v0250;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for exp:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0007,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0007);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[-10] = v0007;
    stack[-11] = v0000;
// end of prologue
    v0210 = stack[-10];
    v0210 = integerp(v0210);
    if (v0210 == nil) goto v0145;
    v0249 = stack[-10];
    v0210 = (LispObject)1; // 0
    v0210 = (LispObject)lesseq2(v0249, v0210);
    nil = C_nil;
    if (exception_pending()) goto v0251;
    v0210 = v0210 ? lisp_true : nil;
    env = stack[-13];
    goto v0014;

v0014:
    if (v0210 == nil) goto v0019;
    v0210 = elt(env, 0); // exp!:
    {
        popv(14);
        fn = elt(env, 6); // bflerrmsg
        return (*qfn1(fn))(qenv(fn), v0210);
    }

v0019:
    v0210 = stack[-11];
    fn = elt(env, 7); // bfzerop!:
    v0210 = (*qfn1(fn))(qenv(fn), v0210);
    nil = C_nil;
    if (exception_pending()) goto v0251;
    env = stack[-13];
    if (v0210 == nil) goto v0041;
    v0210 = qvalue(elt(env, 2)); // bfone!*
    { popv(14); return onevalue(v0210); }

v0041:
    stack[0] = elt(env, 3); // !:rd!:
    v0210 = stack[-11];
    fn = elt(env, 8); // abs!:
    v0210 = (*qfn1(fn))(qenv(fn), v0210);
    nil = C_nil;
    if (exception_pending()) goto v0251;
    env = stack[-13];
    stack[-1] = v0210;
    fn = elt(env, 9); // conv!:bf2i
    v0249 = (*qfn1(fn))(qenv(fn), v0210);
    nil = C_nil;
    if (exception_pending()) goto v0251;
    env = stack[-13];
    stack[-9] = v0249;
    v0210 = (LispObject)1; // 0
    v0210 = list2star(stack[0], v0249, v0210);
    nil = C_nil;
    if (exception_pending()) goto v0251;
    env = stack[-13];
    stack[0] = v0210;
    v0249 = stack[-1];
    v0210 = stack[0];
    fn = elt(env, 10); // difference!:
    v0210 = (*qfn2(fn))(qenv(fn), v0249, v0210);
    nil = C_nil;
    if (exception_pending()) goto v0251;
    env = stack[-13];
    stack[-2] = stack[-10];
    v0210 = stack[-9];
    fn = elt(env, 11); // msd
    v0249 = (*qfn1(fn))(qenv(fn), v0210);
    nil = C_nil;
    if (exception_pending()) goto v0251;
    env = stack[-13];
    v0210 = (LispObject)113; // 7
    v0210 = plus2(v0249, v0210);
    nil = C_nil;
    if (exception_pending()) goto v0251;
    env = stack[-13];
    v0210 = plus2(stack[-2], v0210);
    nil = C_nil;
    if (exception_pending()) goto v0251;
    env = stack[-13];
    stack[-12] = v0210;
    v0249 = stack[-1];
    v0210 = stack[0];
    fn = elt(env, 10); // difference!:
    v0210 = (*qfn2(fn))(qenv(fn), v0249, v0210);
    nil = C_nil;
    if (exception_pending()) goto v0251;
    env = stack[-13];
    stack[-8] = v0210;
    v0210 = stack[0];
    fn = elt(env, 7); // bfzerop!:
    v0210 = (*qfn1(fn))(qenv(fn), v0210);
    nil = C_nil;
    if (exception_pending()) goto v0251;
    env = stack[-13];
    if (v0210 == nil) goto v0135;
    v0210 = qvalue(elt(env, 2)); // bfone!*
    stack[-7] = v0210;
    goto v0147;

v0147:
    v0210 = stack[-8];
    fn = elt(env, 7); // bfzerop!:
    v0210 = (*qfn1(fn))(qenv(fn), v0210);
    nil = C_nil;
    if (exception_pending()) goto v0251;
    env = stack[-13];
    if (v0210 == nil) goto v0092;
    v0210 = qvalue(elt(env, 2)); // bfone!*
    stack[-6] = v0210;
    goto v0252;

v0252:
    v0249 = stack[-7];
    v0210 = stack[-6];
    fn = elt(env, 12); // times!:
    stack[0] = (*qfn2(fn))(qenv(fn), v0249, v0210);
    nil = C_nil;
    if (exception_pending()) goto v0251;
    env = stack[-13];
    v0210 = stack[-10];
    v0210 = add1(v0210);
    nil = C_nil;
    if (exception_pending()) goto v0251;
    env = stack[-13];
    fn = elt(env, 13); // cut!:mt
    v0210 = (*qfn2(fn))(qenv(fn), stack[0], v0210);
    nil = C_nil;
    if (exception_pending()) goto v0251;
    env = stack[-13];
    stack[-1] = v0210;
    v0210 = stack[-11];
    fn = elt(env, 14); // minusp!:
    v0210 = (*qfn1(fn))(qenv(fn), v0210);
    nil = C_nil;
    if (exception_pending()) goto v0251;
    env = stack[-13];
    if (v0210 == nil) goto v0253;
    v0250 = qvalue(elt(env, 2)); // bfone!*
    v0249 = stack[-1];
    v0210 = stack[-10];
    {
        popv(14);
        fn = elt(env, 15); // divide!:
        return (*qfnn(fn))(qenv(fn), 3, v0250, v0249, v0210);
    }

v0253:
    v0249 = stack[-1];
    v0210 = stack[-10];
    {
        popv(14);
        fn = elt(env, 16); // round!:mt
        return (*qfn2(fn))(qenv(fn), v0249, v0210);
    }

v0092:
    stack[-1] = elt(env, 3); // !:rd!:
    stack[0] = (LispObject)33; // 2
    v0210 = stack[-12];
    v0210 = negate(v0210);
    nil = C_nil;
    if (exception_pending()) goto v0251;
    env = stack[-13];
    v0210 = list2star(stack[-1], stack[0], v0210);
    nil = C_nil;
    if (exception_pending()) goto v0251;
    env = stack[-13];
    stack[-4] = v0210;
    v0210 = qvalue(elt(env, 2)); // bfone!*
    stack[0] = v0210;
    stack[-2] = v0210;
    stack[-6] = v0210;
    v0210 = (LispObject)17; // 1
    stack[-9] = v0210;
    v0210 = (LispObject)1; // 0
    stack[-5] = v0210;
    goto v0254;

v0254:
    v0249 = stack[0];
    v0210 = stack[-4];
    fn = elt(env, 17); // greaterp!:
    v0210 = (*qfn2(fn))(qenv(fn), v0249, v0210);
    nil = C_nil;
    if (exception_pending()) goto v0251;
    env = stack[-13];
    if (v0210 == nil) goto v0252;
    stack[0] = elt(env, 3); // !:rd!:
    stack[-1] = stack[-9];
    v0210 = stack[-5];
    v0210 = add1(v0210);
    nil = C_nil;
    if (exception_pending()) goto v0251;
    env = stack[-13];
    stack[-5] = v0210;
    v0249 = times2(stack[-1], v0210);
    nil = C_nil;
    if (exception_pending()) goto v0251;
    env = stack[-13];
    stack[-9] = v0249;
    v0210 = (LispObject)1; // 0
    v0210 = list2star(stack[0], v0249, v0210);
    nil = C_nil;
    if (exception_pending()) goto v0251;
    env = stack[-13];
    stack[-3] = v0210;
    v0249 = stack[-2];
    v0210 = stack[-8];
    fn = elt(env, 12); // times!:
    stack[0] = (*qfn2(fn))(qenv(fn), v0249, v0210);
    nil = C_nil;
    if (exception_pending()) goto v0251;
    env = stack[-13];
    v0210 = stack[-12];
    v0210 = negate(v0210);
    nil = C_nil;
    if (exception_pending()) goto v0251;
    env = stack[-13];
    fn = elt(env, 18); // cut!:ep
    v0210 = (*qfn2(fn))(qenv(fn), stack[0], v0210);
    nil = C_nil;
    if (exception_pending()) goto v0251;
    env = stack[-13];
    stack[-2] = v0210;
    stack[-1] = (LispObject)17; // 1
    stack[0] = stack[-12];
    v0210 = stack[-3];
    fn = elt(env, 19); // order!:
    v0210 = (*qfn1(fn))(qenv(fn), v0210);
    nil = C_nil;
    if (exception_pending()) goto v0251;
    env = stack[-13];
    stack[0] = difference2(stack[0], v0210);
    nil = C_nil;
    if (exception_pending()) goto v0251;
    env = stack[-13];
    v0210 = stack[-2];
    fn = elt(env, 19); // order!:
    v0210 = (*qfn1(fn))(qenv(fn), v0210);
    nil = C_nil;
    if (exception_pending()) goto v0251;
    env = stack[-13];
    v0210 = plus2(stack[0], v0210);
    nil = C_nil;
    if (exception_pending()) goto v0251;
    env = stack[-13];
    fn = elt(env, 20); // max
    v0210 = (*qfn2(fn))(qenv(fn), stack[-1], v0210);
    nil = C_nil;
    if (exception_pending()) goto v0251;
    env = stack[-13];
    v0250 = stack[-2];
    v0249 = stack[-3];
    fn = elt(env, 15); // divide!:
    v0210 = (*qfnn(fn))(qenv(fn), 3, v0250, v0249, v0210);
    nil = C_nil;
    if (exception_pending()) goto v0251;
    env = stack[-13];
    stack[0] = v0210;
    v0249 = stack[-6];
    v0210 = stack[0];
    fn = elt(env, 21); // plus!:
    v0210 = (*qfn2(fn))(qenv(fn), v0249, v0210);
    nil = C_nil;
    if (exception_pending()) goto v0251;
    env = stack[-13];
    stack[-6] = v0210;
    v0249 = stack[-5];
    v0210 = (LispObject)161; // 10
    v0249 = Cremainder(v0249, v0210);
    nil = C_nil;
    if (exception_pending()) goto v0251;
    env = stack[-13];
    v0210 = (LispObject)1; // 0
    if (!(v0249 == v0210)) goto v0254;
    stack[-1] = stack[-6];
    v0210 = stack[-12];
    v0210 = negate(v0210);
    nil = C_nil;
    if (exception_pending()) goto v0251;
    env = stack[-13];
    fn = elt(env, 18); // cut!:ep
    v0210 = (*qfn2(fn))(qenv(fn), stack[-1], v0210);
    nil = C_nil;
    if (exception_pending()) goto v0251;
    env = stack[-13];
    stack[-6] = v0210;
    goto v0254;

v0135:
    v0210 = stack[-12];
    stack[0] = qvalue(elt(env, 4)); // !:bprec!:
    qvalue(elt(env, 4)) = v0210; // !:bprec!:
    v0210 = stack[-12];
    fn = elt(env, 22); // !:e
    v0249 = (*qfn1(fn))(qenv(fn), v0210);
    nil = C_nil;
    if (exception_pending()) goto v0255;
    env = stack[-13];
    v0210 = stack[-9];
    fn = elt(env, 23); // texpt!:
    v0210 = (*qfn2(fn))(qenv(fn), v0249, v0210);
    nil = C_nil;
    if (exception_pending()) goto v0255;
    env = stack[-13];
    stack[-7] = v0210;
    qvalue(elt(env, 4)) = stack[0]; // !:bprec!:
    goto v0147;

v0145:
    v0210 = qvalue(elt(env, 1)); // t
    goto v0014;
// error exit handlers
v0255:
    env = stack[-13];
    qvalue(elt(env, 4)) = stack[0]; // !:bprec!:
    popv(14);
    return nil;
v0251:
    popv(14);
    return nil;
}



// Code for matcheq

static LispObject CC_matcheq(LispObject env,
                         LispObject v0000, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0243, v0244;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for matcheq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0007,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0007);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0007;
    stack[-2] = v0000;
// end of prologue
    v0243 = stack[-2];
    if (v0243 == nil) goto v0145;
    v0243 = stack[-1];
    v0243 = (v0243 == nil ? lisp_true : nil);
    goto v0014;

v0014:
    if (v0243 == nil) goto v0019;
    v0243 = qvalue(elt(env, 2)); // nil
    { popv(5); return onevalue(v0243); }

v0019:
    v0243 = stack[-2];
    if (is_number(v0243)) goto v0004;
    v0243 = stack[-2];
    if (!consp(v0243)) goto v0010;
    v0243 = stack[-1];
    if (!consp(v0243)) goto v0154;
    v0243 = stack[-2];
    v0243 = qcar(v0243);
    if (!consp(v0243)) goto v0192;
    v0243 = qvalue(elt(env, 2)); // nil
    goto v0265;

v0265:
    if (v0243 == nil) goto v0090;
    v0243 = stack[-2];
    v0244 = qcar(v0243);
    v0243 = elt(env, 0); // matcheq
    stack[0] = get(v0244, v0243);
    env = stack[-4];
    v0243 = stack[-2];
    v0243 = qcdr(v0243);
    stack[-2] = Lmkquote(nil, v0243);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-4];
    v0243 = stack[-1];
    v0243 = qcdr(v0243);
    v0243 = Lmkquote(nil, v0243);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-4];
    v0243 = list3(stack[0], stack[-2], v0243);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-4];
    {
        popv(5);
        fn = elt(env, 6); // eval
        return (*qfn1(fn))(qenv(fn), v0243);
    }

v0090:
    v0243 = qvalue(elt(env, 3)); // !*exp
    if (v0243 == nil) goto v0266;
    v0243 = qvalue(elt(env, 2)); // nil
    goto v0219;

v0219:
    if (v0243 == nil) goto v0267;
    v0244 = stack[-2];
    v0243 = stack[-1];
    {
        popv(5);
        fn = elt(env, 7); // matchlinear
        return (*qfn2(fn))(qenv(fn), v0244, v0243);
    }

v0267:
    v0243 = qvalue(elt(env, 2)); // nil
    { popv(5); return onevalue(v0243); }

v0266:
    v0243 = stack[-1];
    v0244 = qcar(v0243);
    v0243 = elt(env, 4); // (plus difference)
    v0243 = Lmemq(nil, v0244, v0243);
    if (v0243 == nil) goto v0084;
    v0243 = stack[-2];
    v0244 = qcar(v0243);
    v0243 = elt(env, 5); // diff
    v0243 = (v0244 == v0243 ? lisp_true : nil);
    goto v0219;

v0084:
    v0243 = qvalue(elt(env, 2)); // nil
    goto v0219;

v0192:
    v0243 = stack[-2];
    v0244 = qcar(v0243);
    v0243 = stack[-1];
    v0243 = qcar(v0243);
    v0243 = (v0244 == v0243 ? lisp_true : nil);
    goto v0265;

v0154:
    v0243 = qvalue(elt(env, 2)); // nil
    { popv(5); return onevalue(v0243); }

v0010:
    v0244 = stack[-2];
    v0243 = elt(env, 0); // matcheq
    stack[-3] = get(v0244, v0243);
    env = stack[-4];
    v0243 = stack[-2];
    stack[0] = Lmkquote(nil, v0243);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-4];
    v0243 = stack[-1];
    if (!consp(v0243)) goto v0139;
    v0243 = stack[-1];
    goto v0009;

v0009:
    v0243 = Lmkquote(nil, v0243);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-4];
    v0243 = list3(stack[-3], stack[0], v0243);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-4];
    fn = elt(env, 6); // eval
    v0243 = (*qfn1(fn))(qenv(fn), v0243);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-4];
    v0244 = v0243;
    v0243 = v0244;
    if (!(v0243 == nil)) { popv(5); return onevalue(v0244); }
    v0243 = qvalue(elt(env, 3)); // !*exp
    if (v0243 == nil) goto v0023;
    v0243 = qvalue(elt(env, 2)); // nil
    goto v0012;

v0012:
    if (v0243 == nil) goto v0268;
    v0244 = stack[-2];
    v0243 = stack[-1];
    {
        popv(5);
        fn = elt(env, 7); // matchlinear
        return (*qfn2(fn))(qenv(fn), v0244, v0243);
    }

v0268:
    v0243 = qvalue(elt(env, 2)); // nil
    { popv(5); return onevalue(v0243); }

v0023:
    v0243 = stack[-1];
    v0243 = Lconsp(nil, v0243);
    env = stack[-4];
    if (v0243 == nil) goto v0037;
    v0243 = stack[-1];
    v0244 = qcar(v0243);
    v0243 = elt(env, 4); // (plus difference)
    v0243 = Lmemq(nil, v0244, v0243);
    goto v0012;

v0037:
    v0243 = qvalue(elt(env, 2)); // nil
    goto v0012;

v0139:
    v0243 = stack[-1];
    v0243 = ncons(v0243);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-4];
    goto v0009;

v0004:
    v0244 = stack[-2];
    v0243 = stack[-1];
    if (equal(v0244, v0243)) goto v0155;
    v0243 = qvalue(elt(env, 2)); // nil
    { popv(5); return onevalue(v0243); }

v0155:
    v0243 = qvalue(elt(env, 1)); // t
    popv(5);
    return ncons(v0243);

v0145:
    v0243 = qvalue(elt(env, 1)); // t
    goto v0014;
// error exit handlers
v0115:
    popv(5);
    return nil;
}



// Code for kernelp

static LispObject CC_kernelp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0102, v0041;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for kernelp");
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
    v0102 = stack[0];
    if (v0102 == nil) goto v0014;
    v0102 = stack[0];
    fn = elt(env, 4); // domain!*p
    v0102 = (*qfn1(fn))(qenv(fn), v0102);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    env = stack[-1];
    goto v0018;

v0018:
    if (v0102 == nil) goto v0015;
    v0102 = qvalue(elt(env, 2)); // nil
    { popv(2); return onevalue(v0102); }

v0015:
    v0102 = stack[0];
    if (symbolp(v0102)) goto v0046;
    v0102 = stack[0];
    fn = elt(env, 5); // listp
    v0102 = (*qfn1(fn))(qenv(fn), v0102);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    env = stack[-1];
    if (v0102 == nil) goto v0020;
    v0102 = stack[0];
    v0102 = qcar(v0102);
    if (!(symbolp(v0102))) goto v0020;
    v0102 = stack[0];
    v0041 = qcar(v0102);
    v0102 = elt(env, 3); // (!*sq set setq plus minus difference times quotient)
    v0102 = Lmemq(nil, v0041, v0102);
    if (!(v0102 == nil)) goto v0020;
    v0102 = qvalue(elt(env, 1)); // t
    { popv(2); return onevalue(v0102); }

v0020:
    v0102 = qvalue(elt(env, 2)); // nil
    { popv(2); return onevalue(v0102); }

v0046:
    v0102 = qvalue(elt(env, 1)); // t
    { popv(2); return onevalue(v0102); }

v0014:
    v0102 = qvalue(elt(env, 1)); // t
    goto v0018;
// error exit handlers
v0051:
    popv(2);
    return nil;
}



// Code for actual_world

static LispObject CC_actual_world(LispObject env,
                         LispObject v0000, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0047, v0001, v0002;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for actual_world");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0007,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0007);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0001 = v0007;
    v0002 = v0000;
// end of prologue
    v0047 = v0002;
    stack[0] = qcar(v0047);
    v0047 = v0001;
    v0001 = v0002;
    v0001 = qcdr(v0001);
    fn = elt(env, 1); // exclude_edges
    v0047 = (*qfn2(fn))(qenv(fn), v0047, v0001);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    env = stack[-1];
    {
        LispObject v0004 = stack[0];
        popv(2);
        fn = elt(env, 2); // union_edges
        return (*qfn2(fn))(qenv(fn), v0004, v0047);
    }
// error exit handlers
v0003:
    popv(2);
    return nil;
}



// Code for red!=recover

static LispObject CC_redMrecover(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0156, v0031;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for red=recover");
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
    stack[-4] = nil;
    stack[-2] = nil;
    v0156 = stack[-3];
    fn = elt(env, 2); // bas_rep
    v0156 = (*qfn1(fn))(qenv(fn), v0156);
    nil = C_nil;
    if (exception_pending()) goto v0227;
    env = stack[-5];
    stack[-1] = v0156;
    goto v0145;

v0145:
    v0156 = stack[-1];
    if (v0156 == nil) goto v0224;
    v0156 = stack[-1];
    v0156 = qcar(v0156);
    stack[0] = v0156;
    v0156 = stack[0];
    v0156 = qcar(v0156);
    fn = elt(env, 3); // mo_comp
    v0031 = (*qfn1(fn))(qenv(fn), v0156);
    nil = C_nil;
    if (exception_pending()) goto v0227;
    env = stack[-5];
    v0156 = (LispObject)1; // 0
    v0156 = (LispObject)lessp2(v0031, v0156);
    nil = C_nil;
    if (exception_pending()) goto v0227;
    v0156 = v0156 ? lisp_true : nil;
    env = stack[-5];
    if (v0156 == nil) goto v0027;
    v0031 = stack[0];
    v0156 = stack[-4];
    v0156 = cons(v0031, v0156);
    nil = C_nil;
    if (exception_pending()) goto v0227;
    env = stack[-5];
    stack[-4] = v0156;
    goto v0002;

v0002:
    v0156 = stack[-1];
    v0156 = qcdr(v0156);
    stack[-1] = v0156;
    goto v0145;

v0027:
    v0031 = stack[0];
    v0156 = stack[-2];
    v0156 = cons(v0031, v0156);
    nil = C_nil;
    if (exception_pending()) goto v0227;
    env = stack[-5];
    stack[-2] = v0156;
    goto v0002;

v0224:
    v0156 = stack[-3];
    fn = elt(env, 4); // bas_nr
    stack[0] = (*qfn1(fn))(qenv(fn), v0156);
    nil = C_nil;
    if (exception_pending()) goto v0227;
    env = stack[-5];
    v0156 = stack[-4];
    fn = elt(env, 5); // red!=hide
    v0156 = (*qfn1(fn))(qenv(fn), v0156);
    nil = C_nil;
    if (exception_pending()) goto v0227;
    env = stack[-5];
    v0156 = Lnreverse(nil, v0156);
    env = stack[-5];
    fn = elt(env, 6); // dp_neworder
    v0031 = (*qfn1(fn))(qenv(fn), v0156);
    nil = C_nil;
    if (exception_pending()) goto v0227;
    env = stack[-5];
    v0156 = stack[-2];
    v0156 = Lnreverse(nil, v0156);
    env = stack[-5];
    {
        LispObject v0222 = stack[0];
        popv(6);
        fn = elt(env, 7); // bas_make1
        return (*qfnn(fn))(qenv(fn), 3, v0222, v0031, v0156);
    }
// error exit handlers
v0227:
    popv(6);
    return nil;
}



// Code for tensor_has_dummy_idx

static LispObject CC_tensor_has_dummy_idx(LispObject env,
                         LispObject v0000, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0035, v0036;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for tensor_has_dummy_idx");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0007,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0007);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0007;
    stack[-1] = v0000;
// end of prologue

v0015:
    v0035 = stack[-1];
    if (v0035 == nil) goto v0014;
    v0035 = stack[-1];
    v0036 = qcar(v0035);
    v0035 = stack[0];
    fn = elt(env, 3); // smember
    v0035 = (*qfn2(fn))(qenv(fn), v0036, v0035);
    nil = C_nil;
    if (exception_pending()) goto v0039;
    env = stack[-2];
    if (v0035 == nil) goto v0003;
    v0035 = qvalue(elt(env, 2)); // t
    { popv(3); return onevalue(v0035); }

v0003:
    v0035 = stack[-1];
    v0035 = qcdr(v0035);
    stack[-1] = v0035;
    goto v0015;

v0014:
    v0035 = qvalue(elt(env, 1)); // nil
    { popv(3); return onevalue(v0035); }
// error exit handlers
v0039:
    popv(3);
    return nil;
}



// Code for modroots2

static LispObject CC_modroots2(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0079, v0060, v0059, v0075;
    LispObject fn;
    LispObject v0124, v0007, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "modroots2");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0007 = va_arg(aa, LispObject);
    v0124 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for modroots2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0124,v0007,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0007,v0124);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    v0059 = v0124;
    stack[-3] = v0007;
    v0075 = v0000;
// end of prologue
    v0079 = v0075;
    if (!consp(v0079)) goto v0049;
    v0079 = v0075;
    v0079 = qcar(v0079);
    v0079 = (consp(v0079) ? nil : lisp_true);
    goto v0103;

v0103:
    if (v0079 == nil) goto v0003;
    v0079 = v0075;
    goto v0145;

v0145:
    if (v0079 == nil) goto v0018;
    v0079 = qvalue(elt(env, 2)); // nil
    { popv(6); return onevalue(v0079); }

v0018:
    v0079 = v0075;
    if (v0079 == nil) goto v0134;
    v0060 = stack[-3];
    v0079 = (LispObject)33; // 2
    if (v0060 == v0079) goto v0268;
    v0060 = v0075;
    v0079 = stack[-3];
    {
        popv(6);
        fn = elt(env, 4); // modroots3
        return (*qfn2(fn))(qenv(fn), v0060, v0079);
    }

v0268:
    v0060 = v0075;
    v0079 = qvalue(elt(env, 1)); // t
    {
        popv(6);
        fn = elt(env, 5); // modroots4
        return (*qfnn(fn))(qenv(fn), 3, v0060, v0079, v0059);
    }

v0134:
    v0060 = stack[-3];
    v0079 = (LispObject)33; // 2
    if (v0060 == v0079) goto v0142;
    v0079 = qvalue(elt(env, 2)); // nil
    goto v0140;

v0140:
    if (v0079 == nil) goto v0029;
    v0079 = elt(env, 3); // (-1 0 1)
    { popv(6); return onevalue(v0079); }

v0029:
    v0079 = (LispObject)1; // 0
    stack[-4] = v0079;
    v0079 = stack[-3];
    v0060 = sub1(v0079);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-5];
    v0079 = stack[-4];
    v0079 = difference2(v0060, v0079);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-5];
    v0079 = Lminusp(nil, v0079);
    env = stack[-5];
    if (v0079 == nil) goto v0118;
    v0079 = qvalue(elt(env, 2)); // nil
    { popv(6); return onevalue(v0079); }

v0118:
    v0079 = stack[-4];
    v0079 = ncons(v0079);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-5];
    stack[-1] = v0079;
    stack[-2] = v0079;
    goto v0100;

v0100:
    v0079 = stack[-4];
    v0079 = add1(v0079);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-5];
    stack[-4] = v0079;
    v0079 = stack[-3];
    v0060 = sub1(v0079);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-5];
    v0079 = stack[-4];
    v0079 = difference2(v0060, v0079);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-5];
    v0079 = Lminusp(nil, v0079);
    env = stack[-5];
    if (!(v0079 == nil)) { LispObject res = stack[-2]; popv(6); return onevalue(res); }
    stack[0] = stack[-1];
    v0079 = stack[-4];
    v0079 = ncons(v0079);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-5];
    v0079 = Lrplacd(nil, stack[0], v0079);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-5];
    v0079 = stack[-1];
    v0079 = qcdr(v0079);
    stack[-1] = v0079;
    goto v0100;

v0142:
    v0079 = v0059;
    goto v0140;

v0003:
    v0079 = qvalue(elt(env, 2)); // nil
    goto v0145;

v0049:
    v0079 = qvalue(elt(env, 1)); // t
    goto v0103;
// error exit handlers
v0089:
    popv(6);
    return nil;
}



// Code for ofsf_qesubq

static LispObject CC_ofsf_qesubq(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0002, v0155, v0003;
    LispObject fn;
    LispObject v0124, v0007, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "ofsf_qesubq");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0007 = va_arg(aa, LispObject);
    v0124 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_qesubq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0124,v0007,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0007,v0124);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    v0002 = v0124;
    v0155 = v0007;
    v0003 = v0000;
// end of prologue
    stack[-1] = v0003;
    stack[0] = elt(env, 1); // ofsf_qesubqat
    v0002 = list2(v0155, v0002);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-2];
    {
        LispObject v0035 = stack[-1];
        LispObject v0036 = stack[0];
        popv(3);
        fn = elt(env, 2); // cl_apply2ats1
        return (*qfnn(fn))(qenv(fn), 3, v0035, v0036, v0002);
    }
// error exit handlers
v0006:
    popv(3);
    return nil;
}



// Code for put!-avalue

static LispObject CC_putKavalue(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0152, v0191, v0216;
    LispObject fn;
    LispObject v0124, v0007, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "put-avalue");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0007 = va_arg(aa, LispObject);
    v0124 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for put-avalue");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0124,v0007,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0007,v0124);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0124;
    stack[-2] = v0007;
    stack[0] = v0000;
// end of prologue
    v0191 = stack[-2];
    v0152 = elt(env, 1); // scalar
    if (v0191 == v0152) goto v0003;
    v0191 = stack[0];
    v0152 = stack[-1];
    fn = elt(env, 7); // smember
    v0152 = (*qfn2(fn))(qenv(fn), v0191, v0152);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-4];
    if (v0152 == nil) goto v0226;
    v0152 = stack[0];
    {
        popv(5);
        fn = elt(env, 8); // recursiveerror
        return (*qfn1(fn))(qenv(fn), v0152);
    }

v0226:
    stack[-3] = stack[0];
    stack[0] = elt(env, 6); // avalue
    v0191 = stack[-2];
    v0152 = stack[-1];
    v0152 = list2(v0191, v0152);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    {
        LispObject v0248 = stack[-3];
        LispObject v0185 = stack[0];
        popv(5);
        return Lputprop(nil, 3, v0248, v0185, v0152);
    }

v0003:
    v0191 = stack[-1];
    v0152 = elt(env, 2); // !*sq
    if (!consp(v0191)) goto v0020;
    v0191 = qcar(v0191);
    if (!(v0191 == v0152)) goto v0020;
    v0191 = stack[0];
    v0152 = stack[-1];
    v0152 = qcdr(v0152);
    v0152 = qcar(v0152);
    fn = elt(env, 9); // sq_member
    v0152 = (*qfn2(fn))(qenv(fn), v0191, v0152);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-4];
    goto v0047;

v0047:
    if (v0152 == nil) goto v0044;
    v0152 = stack[0];
    {
        popv(5);
        fn = elt(env, 8); // recursiveerror
        return (*qfn1(fn))(qenv(fn), v0152);
    }

v0044:
    v0152 = qvalue(elt(env, 4)); // !*reduce4
    if (v0152 == nil) goto v0017;
    v0216 = stack[0];
    v0191 = stack[-1];
    v0152 = elt(env, 5); // generic
    {
        popv(5);
        fn = elt(env, 10); // putobject
        return (*qfnn(fn))(qenv(fn), 3, v0216, v0191, v0152);
    }

v0017:
    stack[-3] = stack[0];
    stack[0] = elt(env, 6); // avalue
    v0191 = stack[-2];
    v0152 = stack[-1];
    v0152 = list2(v0191, v0152);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    {
        LispObject v0091 = stack[-3];
        LispObject v0090 = stack[0];
        popv(5);
        return Lputprop(nil, 3, v0091, v0090, v0152);
    }

v0020:
    v0152 = qvalue(elt(env, 3)); // nil
    goto v0047;
// error exit handlers
v0240:
    popv(5);
    return nil;
}



// Code for cl_smsimpl!-junct1

static LispObject CC_cl_smsimplKjunct1(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0300, v0301, v0302, v0303, v0304, v0305;
    LispObject fn;
    LispObject v0019, v0015, v0005, v0022, v0124, v0007, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 7, "cl_smsimpl-junct1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0007 = va_arg(aa, LispObject);
    v0124 = va_arg(aa, LispObject);
    v0022 = va_arg(aa, LispObject);
    v0005 = va_arg(aa, LispObject);
    v0015 = va_arg(aa, LispObject);
    v0019 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cl_smsimpl-junct1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push6(v0019,v0015,v0005,v0022,v0124,v0007);
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v0000,v0007,v0124,v0022,v0005,v0015);
        pop(v0019);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    stack[-3] = v0019;
    stack[-4] = v0015;
    stack[-5] = v0005;
    stack[-6] = v0022;
    stack[-7] = v0124;
    v0300 = v0007;
    stack[-8] = v0000;
// end of prologue
    stack[-9] = nil;
    stack[-2] = nil;
    stack[-1] = nil;
    goto v0044;

v0044:
    v0300 = stack[-7];
    if (v0300 == nil) goto v0306;
    v0300 = stack[-7];
    v0300 = qcar(v0300);
    v0301 = v0300;
    v0300 = stack[-7];
    v0300 = qcdr(v0300);
    stack[-7] = v0300;
    v0300 = v0301;
    stack[-9] = v0300;
    stack[-10] = stack[-9];
    stack[0] = stack[-5];
    v0300 = stack[-4];
    v0301 = sub1(v0300);
    nil = C_nil;
    if (exception_pending()) goto v0307;
    env = stack[-11];
    v0300 = stack[-8];
    fn = elt(env, 16); // cl_simpl1
    v0300 = (*qfnn(fn))(qenv(fn), 4, stack[-10], stack[0], v0301, v0300);
    nil = C_nil;
    if (exception_pending()) goto v0307;
    env = stack[-11];
    stack[-10] = v0300;
    v0300 = stack[-10];
    if (!consp(v0300)) goto v0029;
    v0300 = stack[-10];
    v0300 = qcar(v0300);
    goto v0033;

v0033:
    v0302 = v0300;
    v0301 = v0302;
    v0300 = stack[-3];
    if (v0301 == v0300) goto v0118;
    v0301 = v0302;
    v0300 = stack[-8];
    if (v0301 == v0300) goto v0031;
    v0301 = v0302;
    v0300 = elt(env, 3); // true
    if (v0301 == v0300) goto v0308;
    v0301 = v0302;
    v0300 = elt(env, 5); // false
    v0300 = (v0301 == v0300 ? lisp_true : nil);
    goto v0309;

v0309:
    if (v0300 == nil) goto v0310;
    v0300 = qvalue(elt(env, 4)); // t
    goto v0075;

v0075:
    if (v0300 == nil) goto v0311;
    stack[0] = v0302;
    v0300 = stack[-3];
    fn = elt(env, 17); // cl_flip
    v0300 = (*qfn1(fn))(qenv(fn), v0300);
    nil = C_nil;
    if (exception_pending()) goto v0307;
    env = stack[-11];
    if (equal(stack[0], v0300)) goto v0157;
    v0301 = stack[-10];
    v0300 = stack[-2];
    v0300 = cons(v0301, v0300);
    nil = C_nil;
    if (exception_pending()) goto v0307;
    env = stack[-11];
    stack[-2] = v0300;
    goto v0157;

v0157:
    v0300 = stack[-1];
    if (v0300 == nil) goto v0044;
    v0303 = stack[-8];
    v0302 = stack[-1];
    v0301 = stack[-5];
    v0300 = stack[-4];
    fn = elt(env, 18); // rl_smupdknowl
    v0300 = (*qfnn(fn))(qenv(fn), 4, v0303, v0302, v0301, v0300);
    nil = C_nil;
    if (exception_pending()) goto v0307;
    env = stack[-11];
    stack[-5] = v0300;
    v0301 = stack[-5];
    v0300 = elt(env, 5); // false
    if (!(v0301 == v0300)) goto v0312;
    v0300 = stack[-3];
    stack[-9] = v0300;
    v0300 = qvalue(elt(env, 1)); // nil
    stack[-7] = v0300;
    goto v0312;

v0312:
    v0300 = qvalue(elt(env, 1)); // nil
    stack[-1] = v0300;
    goto v0044;

v0311:
    v0300 = qvalue(elt(env, 2)); // !*rlsiidem
    if (v0300 == nil) goto v0313;
    v0300 = stack[-2];
    v0301 = Lnreverse(nil, v0300);
    env = stack[-11];
    v0300 = stack[-7];
    v0300 = Lnconc(nil, v0301, v0300);
    nil = C_nil;
    if (exception_pending()) goto v0307;
    env = stack[-11];
    stack[-7] = v0300;
    v0300 = qvalue(elt(env, 1)); // nil
    stack[-2] = v0300;
    goto v0313;

v0313:
    v0300 = stack[-10];
    v0300 = ncons(v0300);
    nil = C_nil;
    if (exception_pending()) goto v0307;
    env = stack[-11];
    stack[-1] = v0300;
    goto v0157;

v0310:
    v0301 = v0302;
    v0300 = elt(env, 6); // or
    if (v0301 == v0300) goto v0180;
    v0301 = v0302;
    v0300 = elt(env, 7); // and
    v0300 = (v0301 == v0300 ? lisp_true : nil);
    goto v0179;

v0179:
    if (v0300 == nil) goto v0314;
    v0300 = qvalue(elt(env, 4)); // t
    goto v0247;

v0247:
    if (v0300 == nil) goto v0315;
    v0300 = qvalue(elt(env, 4)); // t
    goto v0220;

v0220:
    if (v0300 == nil) goto v0232;
    v0300 = qvalue(elt(env, 4)); // t
    goto v0075;

v0232:
    v0301 = v0302;
    v0300 = elt(env, 12); // ex
    if (v0301 == v0300) goto v0167;
    v0301 = v0302;
    v0300 = elt(env, 13); // all
    v0300 = (v0301 == v0300 ? lisp_true : nil);
    goto v0114;

v0114:
    if (v0300 == nil) goto v0316;
    v0300 = qvalue(elt(env, 4)); // t
    goto v0075;

v0316:
    v0301 = v0302;
    v0300 = elt(env, 14); // bex
    if (v0301 == v0300) goto v0317;
    v0301 = v0302;
    v0300 = elt(env, 15); // ball
    v0300 = (v0301 == v0300 ? lisp_true : nil);
    goto v0169;

v0169:
    if (v0300 == nil) goto v0250;
    v0300 = qvalue(elt(env, 4)); // t
    goto v0075;

v0250:
    v0300 = v0302;
    if (!symbolp(v0300)) v0300 = nil;
    else { v0300 = qfastgets(v0300);
           if (v0300 != nil) { v0300 = elt(v0300, 21); // rl_external
#ifdef RECORD_GET
             if (v0300 != SPID_NOPROP)
                record_get(elt(fastget_names, 21), 1);
             else record_get(elt(fastget_names, 21), 0),
                v0300 = nil; }
           else record_get(elt(fastget_names, 21), 0); }
#else
             if (v0300 == SPID_NOPROP) v0300 = nil; }}
#endif
    goto v0075;

v0317:
    v0300 = qvalue(elt(env, 4)); // t
    goto v0169;

v0167:
    v0300 = qvalue(elt(env, 4)); // t
    goto v0114;

v0315:
    v0301 = v0302;
    v0300 = elt(env, 9); // impl
    if (v0301 == v0300) goto v0242;
    v0301 = v0302;
    v0300 = elt(env, 10); // repl
    if (v0301 == v0300) goto v0174;
    v0301 = v0302;
    v0300 = elt(env, 11); // equiv
    v0300 = (v0301 == v0300 ? lisp_true : nil);
    goto v0220;

v0174:
    v0300 = qvalue(elt(env, 4)); // t
    goto v0220;

v0242:
    v0300 = qvalue(elt(env, 4)); // t
    goto v0220;

v0314:
    v0301 = v0302;
    v0300 = elt(env, 8); // not
    v0300 = (v0301 == v0300 ? lisp_true : nil);
    goto v0247;

v0180:
    v0300 = qvalue(elt(env, 4)); // t
    goto v0179;

v0308:
    v0300 = qvalue(elt(env, 4)); // t
    goto v0309;

v0031:
    v0300 = stack[-10];
    v0300 = qcdr(v0300);
    stack[0] = v0300;
    goto v0025;

v0025:
    v0300 = stack[0];
    if (v0300 == nil) goto v0024;
    v0300 = stack[0];
    v0300 = qcar(v0300);
    fn = elt(env, 19); // cl_atfp
    v0300 = (*qfn1(fn))(qenv(fn), v0300);
    nil = C_nil;
    if (exception_pending()) goto v0307;
    env = stack[-11];
    if (v0300 == nil) goto v0024;
    v0300 = stack[0];
    v0301 = qcar(v0300);
    v0300 = stack[-1];
    v0300 = cons(v0301, v0300);
    nil = C_nil;
    if (exception_pending()) goto v0307;
    env = stack[-11];
    stack[-1] = v0300;
    v0300 = stack[0];
    v0300 = qcdr(v0300);
    stack[0] = v0300;
    goto v0025;

v0024:
    v0300 = qvalue(elt(env, 2)); // !*rlsiidem
    if (v0300 == nil) goto v0092;
    v0300 = stack[-1];
    if (v0300 == nil) goto v0092;
    v0300 = stack[-2];
    v0301 = Lnreverse(nil, v0300);
    env = stack[-11];
    v0300 = stack[-7];
    v0300 = Lnconc(nil, v0301, v0300);
    nil = C_nil;
    if (exception_pending()) goto v0307;
    env = stack[-11];
    stack[-7] = v0300;
    v0300 = qvalue(elt(env, 1)); // nil
    stack[-2] = v0300;
    goto v0092;

v0092:
    v0300 = stack[0];
    v0300 = Lreverse(nil, v0300);
    nil = C_nil;
    if (exception_pending()) goto v0307;
    env = stack[-11];
    v0300 = Lnconc(nil, stack[-2], v0300);
    nil = C_nil;
    if (exception_pending()) goto v0307;
    env = stack[-11];
    stack[-2] = v0300;
    goto v0157;

v0118:
    v0300 = stack[-3];
    stack[-9] = v0300;
    v0300 = qvalue(elt(env, 1)); // nil
    stack[-7] = v0300;
    goto v0157;

v0029:
    v0300 = stack[-10];
    goto v0033;

v0306:
    v0301 = stack[-9];
    v0300 = stack[-3];
    if (v0301 == v0300) goto v0318;
    v0305 = stack[-8];
    v0304 = stack[-2];
    v0303 = stack[-6];
    v0302 = stack[-5];
    v0301 = stack[-4];
    v0300 = stack[-3];
    {
        popv(12);
        fn = elt(env, 20); // cl_smsimpl!-junct2
        return (*qfnn(fn))(qenv(fn), 6, v0305, v0304, v0303, v0302, v0301, v0300);
    }

v0318:
    v0300 = stack[-3];
    popv(12);
    return ncons(v0300);
// error exit handlers
v0307:
    popv(12);
    return nil;
}



// Code for rl_mk!*fof

static LispObject CC_rl_mkHfof(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0015;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rl_mk*fof");
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
    v0015 = v0000;
// end of prologue
    fn = elt(env, 1); // rl_csimpl
    v0015 = (*qfn1(fn))(qenv(fn), v0015);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); // rl_mk!*fof1
        return (*qfn1(fn))(qenv(fn), v0015);
    }
// error exit handlers
v0019:
    popv(1);
    return nil;
}



// Code for cl_atl

static LispObject CC_cl_atl(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0129, v0122;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cl_atl");
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
    v0129 = v0000;
// end of prologue
    fn = elt(env, 2); // cl_atl1
    v0122 = (*qfn1(fn))(qenv(fn), v0129);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[0];
    v0129 = elt(env, 1); // rl_ordatp
    {
        popv(1);
        fn = elt(env, 3); // sort
        return (*qfn2(fn))(qenv(fn), v0122, v0129);
    }
// error exit handlers
v0103:
    popv(1);
    return nil;
}



// Code for vp1

static LispObject CC_vp1(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0118, v0016, v0017;
    LispObject fn;
    LispObject v0124, v0007, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "vp1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0007 = va_arg(aa, LispObject);
    v0124 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vp1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0124,v0007,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0007,v0124);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0124;
    stack[-1] = v0007;
    stack[-2] = v0000;
// end of prologue
    v0017 = nil;
    goto v0018;

v0018:
    v0118 = stack[0];
    if (v0118 == nil) goto v0049;
    v0016 = stack[-2];
    v0118 = stack[0];
    v0118 = qcar(v0118);
    if (equal(v0016, v0118)) goto v0136;
    v0118 = (LispObject)1; // 0
    v0016 = v0017;
    v0118 = cons(v0118, v0016);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-3];
    v0017 = v0118;
    v0118 = stack[0];
    v0118 = qcdr(v0118);
    stack[0] = v0118;
    goto v0018;

v0136:
    stack[-2] = v0017;
    v0118 = stack[0];
    v0118 = qcdr(v0118);
    fn = elt(env, 2); // vp2
    v0118 = (*qfn1(fn))(qenv(fn), v0118);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-3];
    v0118 = cons(stack[-1], v0118);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-3];
    {
        LispObject v0125 = stack[-2];
        popv(4);
        fn = elt(env, 3); // nreverse
        return (*qfn2(fn))(qenv(fn), v0125, v0118);
    }

v0049:
    stack[0] = v0017;
    v0118 = elt(env, 1); // "Var not in z-list after all"
    fn = elt(env, 4); // interr
    v0118 = (*qfn1(fn))(qenv(fn), v0118);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-3];
    {
        LispObject v0126 = stack[0];
        popv(4);
        fn = elt(env, 3); // nreverse
        return (*qfn2(fn))(qenv(fn), v0126, v0118);
    }
// error exit handlers
v0042:
    popv(4);
    return nil;
}



// Code for ps!:depvar

static LispObject CC_psTdepvar(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0127, v0102, v0041;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ps:depvar");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0041 = v0000;
// end of prologue
    v0127 = v0041;
    if (!consp(v0127)) goto v0014;
    v0127 = v0041;
    v0102 = qcar(v0127);
    v0127 = elt(env, 2); // !:ps!:
    if (v0102 == v0127) goto v0036;
    v0127 = v0041;
    v0127 = qcar(v0127);
    if (!symbolp(v0127)) v0127 = nil;
    else { v0127 = qfastgets(v0127);
           if (v0127 != nil) { v0127 = elt(v0127, 8); // dname
#ifdef RECORD_GET
             if (v0127 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v0127 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v0127 == SPID_NOPROP) v0127 = nil; }}
#endif
    goto v0018;

v0018:
    if (v0127 == nil) goto v0140;
    v0127 = qvalue(elt(env, 3)); // nil
    return onevalue(v0127);

v0140:
    v0102 = v0041;
    v0127 = (LispObject)33; // 2
    {
        fn = elt(env, 4); // ps!:getv
        return (*qfn2(fn))(qenv(fn), v0102, v0127);
    }

v0036:
    v0127 = qvalue(elt(env, 3)); // nil
    goto v0018;

v0014:
    v0127 = qvalue(elt(env, 1)); // t
    goto v0018;
}



// Code for ldt!-dep

static LispObject CC_ldtKdep(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0002, v0155;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ldt-dep");
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
    v0002 = v0000;
// end of prologue
    fn = elt(env, 3); // ldt!-tvar
    v0155 = (*qfn1(fn))(qenv(fn), v0002);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    env = stack[0];
    v0002 = qvalue(elt(env, 1)); // depl!*
    v0002 = Lassoc(nil, v0155, v0002);
    v0155 = v0002;
    v0002 = v0155;
    if (v0002 == nil) goto v0048;
    v0002 = v0155;
    v0002 = qcdr(v0002);
    { popv(1); return onevalue(v0002); }

v0048:
    v0002 = qvalue(elt(env, 2)); // nil
    { popv(1); return onevalue(v0002); }
// error exit handlers
v0003:
    popv(1);
    return nil;
}



// Code for mod!-domainvalchk

static LispObject CC_modKdomainvalchk(LispObject env,
                         LispObject v0000, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0010, v0132, v0008;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mod-domainvalchk");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0007,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0007);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// copy arguments values to proper place
    v0008 = v0007;
    v0010 = v0000;
// end of prologue
    v0132 = v0010;
    v0010 = elt(env, 1); // expt
    if (v0132 == v0010) goto v0044;
    v0010 = qvalue(elt(env, 2)); // nil
    goto v0018;

v0018:
    v0008 = v0010;
    v0132 = v0008;
    v0010 = elt(env, 3); // failed
    if (v0132 == v0010) goto v0136;
    v0132 = v0008;
    v0010 = (LispObject)17; // 1
    popv(1);
    return cons(v0132, v0010);

v0136:
    v0010 = qvalue(elt(env, 2)); // nil
    { popv(1); return onevalue(v0010); }

v0044:
    v0010 = v0008;
    v0010 = qcar(v0010);
    v0132 = v0008;
    v0132 = qcdr(v0132);
    v0132 = qcar(v0132);
    fn = elt(env, 4); // mod!-expt!-fract
    v0010 = (*qfn2(fn))(qenv(fn), v0010, v0132);
    nil = C_nil;
    if (exception_pending()) goto v0224;
    env = stack[0];
    goto v0018;
// error exit handlers
v0224:
    popv(1);
    return nil;
}



// Code for idealp

static LispObject CC_idealp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0004, v0146, v0006;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for idealp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0006 = v0000;
// end of prologue
    v0146 = v0006;
    v0004 = elt(env, 1); // i
    if (!consp(v0146)) goto v0044;
    v0146 = qcar(v0146);
    if (!(v0146 == v0004)) goto v0044;
    v0004 = qvalue(elt(env, 2)); // t
    return onevalue(v0004);

v0044:
    v0004 = v0006;
    v0146 = elt(env, 3); // list
        return Leqcar(nil, v0004, v0146);
}



// Code for !:quotient

static LispObject CC_Tquotient(LispObject env,
                         LispObject v0000, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0091, v0090, v0264;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for :quotient");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0007,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0007);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0090 = v0007;
    stack[0] = v0000;
// end of prologue
    v0091 = stack[0];
    if (v0091 == nil) goto v0145;
    v0264 = stack[0];
    v0091 = (LispObject)1; // 0
    v0091 = (v0264 == v0091 ? lisp_true : nil);
    goto v0014;

v0014:
    if (v0091 == nil) goto v0019;
    v0091 = qvalue(elt(env, 2)); // nil
    { popv(2); return onevalue(v0091); }

v0019:
    v0091 = v0090;
    if (v0091 == nil) goto v0035;
    v0264 = v0090;
    v0091 = (LispObject)1; // 0
    v0091 = (v0264 == v0091 ? lisp_true : nil);
    goto v0006;

v0006:
    if (v0091 == nil) goto v0004;
    v0264 = elt(env, 3); // poly
    v0090 = (LispObject)193; // 12
    v0091 = elt(env, 4); // "Zero divisor"
    {
        popv(2);
        fn = elt(env, 8); // rerror
        return (*qfnn(fn))(qenv(fn), 3, v0264, v0090, v0091);
    }

v0004:
    v0091 = stack[0];
    if (!consp(v0091)) goto v0099;
    v0091 = qvalue(elt(env, 2)); // nil
    goto v0224;

v0224:
    if (v0091 == nil) goto v0152;
    v0091 = qvalue(elt(env, 5)); // dmode!*
    if (v0091 == nil) goto v0156;
    v0091 = v0090;
    fn = elt(env, 9); // !:recip
    v0091 = (*qfn1(fn))(qenv(fn), v0091);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-1];
    v0090 = v0091;
    if (!consp(v0090)) goto v0038;
    v0264 = stack[0];
    v0090 = v0091;
    v0091 = elt(env, 6); // times
    {
        popv(2);
        fn = elt(env, 10); // dcombine
        return (*qfnn(fn))(qenv(fn), 3, v0264, v0090, v0091);
    }

v0038:
    v0090 = stack[0];
    popv(2);
    return times2(v0090, v0091);

v0156:
    v0091 = stack[0];
    popv(2);
    return quot2(v0091, v0090);

v0152:
    v0264 = stack[0];
    v0091 = elt(env, 7); // quotient
    {
        popv(2);
        fn = elt(env, 10); // dcombine
        return (*qfnn(fn))(qenv(fn), 3, v0264, v0090, v0091);
    }

v0099:
    v0091 = v0090;
    v0091 = (consp(v0091) ? nil : lisp_true);
    goto v0224;

v0035:
    v0091 = qvalue(elt(env, 1)); // t
    goto v0006;

v0145:
    v0091 = qvalue(elt(env, 1)); // t
    goto v0014;
// error exit handlers
v0182:
    popv(2);
    return nil;
}



// Code for rep_parents

static LispObject CC_rep_parents(LispObject env,
                         LispObject v0000, LispObject v0007)
{
    LispObject nil = C_nil;
    LispObject v0122, v0103;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rep_parents");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0007,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0007);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0122 = v0007;
    stack[0] = v0000;
// end of prologue
    v0103 = stack[0];
    v0122 = Lrplacd(nil, v0103, v0122);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    { LispObject res = stack[0]; popv(1); return onevalue(res); }
// error exit handlers
v0045:
    popv(1);
    return nil;
}



setup_type const u56_setup[] =
{
    {"partitpartdf",            CC_partitpartdf,too_many_1,    wrong_no_1},
    {"calc_map_tar",            too_few_2,      CC_calc_map_tar,wrong_no_2},
    {"simpabs",                 CC_simpabs,     too_many_1,    wrong_no_1},
    {"mo_dlexcomp",             too_few_2,      CC_mo_dlexcomp,wrong_no_2},
    {"partsym_zerop",           too_few_2,      CC_partsym_zerop,wrong_no_2},
    {"sc_repkern",              too_few_2,      CC_sc_repkern, wrong_no_2},
    {"lambda_pbthn8t73vcc",     too_few_2,      CC_lambda_pbthn8t73vcc,wrong_no_2},
    {"spreadvar",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_spreadvar},
    {"i2cr*",                   CC_i2crH,       too_many_1,    wrong_no_1},
    {"extodd",                  CC_extodd,      too_many_1,    wrong_no_1},
    {"setqdeletedescendants",   CC_setqdeletedescendants,too_many_1,wrong_no_1},
    {"ofsf_facneq*",            too_few_2,      CC_ofsf_facneqH,wrong_no_2},
    {"mk_character",            CC_mk_character,too_many_1,    wrong_no_1},
    {"unary",                   too_few_2,      CC_unary,      wrong_no_2},
    {"*s2arg",                  too_few_2,      CC_Hs2arg,     wrong_no_2},
    {"p_eq_vertex",             too_few_2,      CC_p_eq_vertex,wrong_no_2},
    {"dp_content",              CC_dp_content,  too_many_1,    wrong_no_1},
    {"affinep",                 CC_affinep,     too_many_1,    wrong_no_1},
    {"algebnp",                 CC_algebnp,     too_many_1,    wrong_no_1},
    {"r2flbf",                  CC_r2flbf,      too_many_1,    wrong_no_1},
    {"redmsg",                  too_few_2,      CC_redmsg,     wrong_no_2},
    {"gcdk",                    too_few_2,      CC_gcdk,       wrong_no_2},
    {"clearrules",              CC_clearrules,  too_many_1,    wrong_no_1},
    {"conjgd",                  CC_conjgd,      too_many_1,    wrong_no_1},
    {"negdf",                   CC_negdf,       too_many_1,    wrong_no_1},
    {"get*generators",          CC_getHgenerators,too_many_1,  wrong_no_1},
    {"rl_cput",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_rl_cput},
    {"dvfsf_qesubqat",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_dvfsf_qesubqat},
    {"mkarg",                   too_few_2,      CC_mkarg,      wrong_no_2},
    {"numberofoccs",            too_few_2,      CC_numberofoccs,wrong_no_2},
    {"xvarp",                   CC_xvarp,       too_many_1,    wrong_no_1},
    {"exp:",                    too_few_2,      CC_expT,       wrong_no_2},
    {"matcheq",                 too_few_2,      CC_matcheq,    wrong_no_2},
    {"kernelp",                 CC_kernelp,     too_many_1,    wrong_no_1},
    {"actual_world",            too_few_2,      CC_actual_world,wrong_no_2},
    {"red=recover",             CC_redMrecover, too_many_1,    wrong_no_1},
    {"tensor_has_dummy_idx",    too_few_2,      CC_tensor_has_dummy_idx,wrong_no_2},
    {"modroots2",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_modroots2},
    {"ofsf_qesubq",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_qesubq},
    {"put-avalue",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_putKavalue},
    {"cl_smsimpl-junct1",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_cl_smsimplKjunct1},
    {"rl_mk*fof",               CC_rl_mkHfof,   too_many_1,    wrong_no_1},
    {"cl_atl",                  CC_cl_atl,      too_many_1,    wrong_no_1},
    {"vp1",                     wrong_no_na,    wrong_no_nb,   (n_args *)CC_vp1},
    {"ps:depvar",               CC_psTdepvar,   too_many_1,    wrong_no_1},
    {"ldt-dep",                 CC_ldtKdep,     too_many_1,    wrong_no_1},
    {"mod-domainvalchk",        too_few_2,      CC_modKdomainvalchk,wrong_no_2},
    {"idealp",                  CC_idealp,      too_many_1,    wrong_no_1},
    {":quotient",               too_few_2,      CC_Tquotient,  wrong_no_2},
    {"rep_parents",             too_few_2,      CC_rep_parents,wrong_no_2},
    {NULL, (one_args *)"u56", (two_args *)"6433 7983530 3298201", 0}
};

// end of generated code
