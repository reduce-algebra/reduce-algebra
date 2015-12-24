
// $destdir/u47.c        Machine generated C code

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



// Code for xadd!*

static LispObject CC_xaddH(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0042, v0043, v0044;
    LispObject fn;
    LispObject v0004, v0002, v0003;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "xadd*");
    va_start(aa, nargs);
    v0003 = va_arg(aa, LispObject);
    v0002 = va_arg(aa, LispObject);
    v0004 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for xadd*");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0004,v0002,v0003);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0003,v0002,v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[-9] = v0004;
    stack[-10] = v0002;
    stack[-11] = v0003;
// end of prologue
    v0042 = stack[-10];
    stack[-12] = v0042;
    goto v0045;

v0045:
    v0042 = stack[-12];
    if (v0042 == nil) goto v0046;
    v0042 = stack[-11];
    v0043 = qcar(v0042);
    v0042 = stack[-12];
    v0042 = qcar(v0042);
    v0042 = qcar(v0042);
    if (equal(v0043, v0042)) goto v0047;
    v0042 = qvalue(elt(env, 1)); // nil
    goto v0048;

v0048:
    if (!(v0042 == nil)) goto v0046;
    v0042 = stack[-12];
    v0042 = qcdr(v0042);
    stack[-12] = v0042;
    goto v0045;

v0046:
    v0042 = stack[-12];
    if (v0042 == nil) goto v0049;
    v0042 = stack[-12];
    v0043 = qcar(v0042);
    v0042 = stack[-10];
    v0042 = Ldelete(nil, v0043, v0042);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-13];
    stack[-10] = v0042;
    v0042 = stack[-12];
    v0042 = qcar(v0042);
    stack[-12] = v0042;
    v0042 = stack[-9];
    if (v0042 == nil) goto v0049;
    v0042 = qvalue(elt(env, 2)); // newrule!*
    if (v0042 == nil) goto v0049;
    v0042 = stack[-12];
    v0043 = qcar(v0042);
    v0042 = qvalue(elt(env, 2)); // newrule!*
    v0042 = qcar(v0042);
    stack[0] = v0042;
    if (equal(v0043, v0042)) goto v0051;
    v0042 = stack[-12];
    v0042 = qcar(v0042);
    fn = elt(env, 7); // powlisp
    v0042 = (*qfn1(fn))(qenv(fn), v0042);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-13];
    goto v0052;

v0052:
    if (v0042 == nil) goto v0053;
    stack[-8] = elt(env, 3); // plus
    stack[-7] = stack[0];
    stack[-6] = elt(env, 4); // difference
    v0042 = stack[-12];
    v0042 = qcdr(v0042);
    v0042 = qcdr(v0042);
    stack[-5] = qcar(v0042);
    stack[-4] = elt(env, 5); // times
    v0042 = stack[-12];
    v0042 = qcar(v0042);
    stack[-3] = v0042;
    v0042 = stack[-3];
    if (v0042 == nil) goto v0054;
    v0042 = stack[-3];
    v0042 = qcar(v0042);
    v0044 = elt(env, 6); // expt
    v0043 = v0042;
    v0043 = qcar(v0043);
    v0042 = qcdr(v0042);
    v0042 = list3(v0044, v0043, v0042);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-13];
    v0042 = ncons(v0042);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-13];
    stack[-1] = v0042;
    stack[-2] = v0042;
    goto v0055;

v0055:
    v0042 = stack[-3];
    v0042 = qcdr(v0042);
    stack[-3] = v0042;
    v0042 = stack[-3];
    if (v0042 == nil) goto v0056;
    stack[0] = stack[-1];
    v0042 = stack[-3];
    v0042 = qcar(v0042);
    v0044 = elt(env, 6); // expt
    v0043 = v0042;
    v0043 = qcar(v0043);
    v0042 = qcdr(v0042);
    v0042 = list3(v0044, v0043, v0042);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-13];
    v0042 = ncons(v0042);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-13];
    v0042 = Lrplacd(nil, stack[0], v0042);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-13];
    v0042 = stack[-1];
    v0042 = qcdr(v0042);
    stack[-1] = v0042;
    goto v0055;

v0056:
    v0042 = stack[-2];
    goto v0057;

v0057:
    v0042 = cons(stack[-4], v0042);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-13];
    v0042 = list3(stack[-6], stack[-5], v0042);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-13];
    v0042 = list3(stack[-8], stack[-7], v0042);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-13];
    fn = elt(env, 8); // simp
    v0042 = (*qfn1(fn))(qenv(fn), v0042);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-13];
    fn = elt(env, 9); // prepsq
    v0043 = (*qfn1(fn))(qenv(fn), v0042);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-13];
    v0042 = stack[-12];
    v0042 = qcdr(v0042);
    v0042 = qcar(v0042);
    v0042 = qcdr(v0042);
    fn = elt(env, 10); // updoldrules
    v0042 = (*qfn2(fn))(qenv(fn), v0043, v0042);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-13];
    goto v0049;

v0049:
    v0042 = stack[-9];
    if (v0042 == nil) { LispObject res = stack[-10]; popv(14); return onevalue(res); }
    v0043 = stack[-11];
    v0042 = stack[-10];
    v0042 = cons(v0043, v0042);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    stack[-10] = v0042;
    { LispObject res = stack[-10]; popv(14); return onevalue(res); }

v0054:
    v0042 = qvalue(elt(env, 1)); // nil
    goto v0057;

v0053:
    v0042 = stack[-12];
    v0042 = qcdr(v0042);
    v0042 = qcdr(v0042);
    v0043 = qcar(v0042);
    v0042 = stack[-12];
    v0042 = qcdr(v0042);
    v0042 = qcar(v0042);
    v0042 = qcdr(v0042);
    fn = elt(env, 10); // updoldrules
    v0042 = (*qfn2(fn))(qenv(fn), v0043, v0042);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-13];
    goto v0049;

v0051:
    v0042 = qvalue(elt(env, 1)); // nil
    goto v0052;

v0047:
    v0042 = stack[-11];
    v0042 = qcdr(v0042);
    v0043 = qcar(v0042);
    v0042 = stack[-12];
    v0042 = qcar(v0042);
    v0042 = qcdr(v0042);
    v0042 = qcar(v0042);
    v0042 = (equal(v0043, v0042) ? lisp_true : nil);
    goto v0048;
// error exit handlers
v0050:
    popv(14);
    return nil;
}



// Code for get!*order

static LispObject CC_getHorder(LispObject env,
                         LispObject v0003)
{
    LispObject nil = C_nil;
    LispObject v0058;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for get*order");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0003);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
// copy arguments values to proper place
    v0058 = v0003;
// end of prologue
    fn = elt(env, 1); // get!*elements
    v0058 = (*qfn1(fn))(qenv(fn), v0058);
    errexit();
        return Llength(nil, v0058);
}



// Code for qqe_length!-graph!-neighbors

static LispObject CC_qqe_lengthKgraphKneighbors(LispObject env,
                         LispObject v0003)
{
    LispObject nil = C_nil;
    LispObject v0046, v0045;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qqe_length-graph-neighbors");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0046 = v0003;
// end of prologue
    v0045 = elt(env, 1); // neighbors
    return get(v0046, v0045);
}



// Code for pasf_negateat

static LispObject CC_pasf_negateat(LispObject env,
                         LispObject v0003)
{
    LispObject nil = C_nil;
    LispObject v0088, v0089, v0090;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pasf_negateat");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0003);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0003;
// end of prologue
    v0089 = stack[0];
    v0088 = elt(env, 1); // true
    if (v0089 == v0088) goto v0060;
    v0089 = stack[0];
    v0088 = elt(env, 3); // false
    v0088 = (v0089 == v0088 ? lisp_true : nil);
    goto v0058;

v0058:
    if (v0088 == nil) goto v0091;
    v0089 = stack[0];
    v0088 = elt(env, 3); // false
    if (v0089 == v0088) goto v0092;
    v0088 = elt(env, 3); // false
    { popv(2); return onevalue(v0088); }

v0092:
    v0088 = elt(env, 1); // true
    { popv(2); return onevalue(v0088); }

v0091:
    v0089 = stack[0];
    v0088 = elt(env, 1); // true
    if (v0089 == v0088) goto v0093;
    v0089 = stack[0];
    v0088 = elt(env, 3); // false
    v0088 = (v0089 == v0088 ? lisp_true : nil);
    goto v0094;

v0094:
    if (v0088 == nil) goto v0049;
    v0088 = stack[0];
    v0089 = v0088;
    goto v0095;

v0095:
    v0088 = elt(env, 4); // (cong ncong)
    v0088 = Lmemq(nil, v0089, v0088);
    if (v0088 == nil) goto v0096;
    v0089 = stack[0];
    v0088 = elt(env, 1); // true
    if (v0089 == v0088) goto v0097;
    v0089 = stack[0];
    v0088 = elt(env, 3); // false
    v0088 = (v0089 == v0088 ? lisp_true : nil);
    goto v0098;

v0098:
    if (v0088 == nil) goto v0099;
    v0088 = stack[0];
    goto v0100;

v0100:
    fn = elt(env, 5); // pasf_lnegrel
    v0089 = (*qfn1(fn))(qenv(fn), v0088);
    nil = C_nil;
    if (exception_pending()) goto v0101;
    env = stack[-1];
    v0088 = stack[0];
    v0088 = qcar(v0088);
    v0088 = qcdr(v0088);
    fn = elt(env, 6); // pasf_mkop
    v0090 = (*qfn2(fn))(qenv(fn), v0089, v0088);
    nil = C_nil;
    if (exception_pending()) goto v0101;
    v0088 = stack[0];
    v0088 = qcdr(v0088);
    v0089 = qcar(v0088);
    v0088 = stack[0];
    v0088 = qcdr(v0088);
    v0088 = qcdr(v0088);
    v0088 = qcar(v0088);
    popv(2);
    return list3(v0090, v0089, v0088);

v0099:
    v0088 = stack[0];
    v0088 = qcar(v0088);
    v0088 = Lconsp(nil, v0088);
    env = stack[-1];
    if (v0088 == nil) goto v0102;
    v0088 = stack[0];
    v0088 = qcar(v0088);
    v0088 = qcar(v0088);
    goto v0100;

v0102:
    v0088 = stack[0];
    v0088 = qcar(v0088);
    goto v0100;

v0097:
    v0088 = qvalue(elt(env, 2)); // t
    goto v0098;

v0096:
    v0089 = stack[0];
    v0088 = elt(env, 1); // true
    if (v0089 == v0088) goto v0056;
    v0089 = stack[0];
    v0088 = elt(env, 3); // false
    v0088 = (v0089 == v0088 ? lisp_true : nil);
    goto v0103;

v0103:
    if (v0088 == nil) goto v0104;
    v0088 = stack[0];
    goto v0028;

v0028:
    fn = elt(env, 5); // pasf_lnegrel
    v0090 = (*qfn1(fn))(qenv(fn), v0088);
    nil = C_nil;
    if (exception_pending()) goto v0101;
    v0088 = stack[0];
    v0088 = qcdr(v0088);
    v0089 = qcar(v0088);
    v0088 = stack[0];
    v0088 = qcdr(v0088);
    v0088 = qcdr(v0088);
    v0088 = qcar(v0088);
    popv(2);
    return list3(v0090, v0089, v0088);

v0104:
    v0088 = stack[0];
    v0088 = qcar(v0088);
    v0088 = Lconsp(nil, v0088);
    env = stack[-1];
    if (v0088 == nil) goto v0105;
    v0088 = stack[0];
    v0088 = qcar(v0088);
    v0088 = qcar(v0088);
    goto v0028;

v0105:
    v0088 = stack[0];
    v0088 = qcar(v0088);
    goto v0028;

v0056:
    v0088 = qvalue(elt(env, 2)); // t
    goto v0103;

v0049:
    v0088 = stack[0];
    v0088 = qcar(v0088);
    v0088 = Lconsp(nil, v0088);
    env = stack[-1];
    if (v0088 == nil) goto v0106;
    v0088 = stack[0];
    v0088 = qcar(v0088);
    v0088 = qcar(v0088);
    v0089 = v0088;
    goto v0095;

v0106:
    v0088 = stack[0];
    v0088 = qcar(v0088);
    v0089 = v0088;
    goto v0095;

v0093:
    v0088 = qvalue(elt(env, 2)); // t
    goto v0094;

v0060:
    v0088 = qvalue(elt(env, 2)); // t
    goto v0058;
// error exit handlers
v0101:
    popv(2);
    return nil;
}



// Code for ldf!-deg

static LispObject CC_ldfKdeg(LispObject env,
                         LispObject v0003, LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0111, v0112;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ldf-deg");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0002,v0003);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0003,v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-3] = v0002;
    v0111 = v0003;
// end of prologue
    stack[-4] = v0111;
    v0111 = stack[-4];
    if (v0111 == nil) goto v0113;
    v0111 = stack[-4];
    v0111 = qcar(v0111);
    v0112 = qcdr(v0111);
    v0111 = stack[-3];
    fn = elt(env, 2); // degreef
    v0111 = (*qfn2(fn))(qenv(fn), v0112, v0111);
    nil = C_nil;
    if (exception_pending()) goto v0114;
    env = stack[-5];
    v0111 = ncons(v0111);
    nil = C_nil;
    if (exception_pending()) goto v0114;
    env = stack[-5];
    stack[-1] = v0111;
    stack[-2] = v0111;
    goto v0059;

v0059:
    v0111 = stack[-4];
    v0111 = qcdr(v0111);
    stack[-4] = v0111;
    v0111 = stack[-4];
    if (v0111 == nil) goto v0115;
    stack[0] = stack[-1];
    v0111 = stack[-4];
    v0111 = qcar(v0111);
    v0112 = qcdr(v0111);
    v0111 = stack[-3];
    fn = elt(env, 2); // degreef
    v0111 = (*qfn2(fn))(qenv(fn), v0112, v0111);
    nil = C_nil;
    if (exception_pending()) goto v0114;
    env = stack[-5];
    v0111 = ncons(v0111);
    nil = C_nil;
    if (exception_pending()) goto v0114;
    env = stack[-5];
    v0111 = Lrplacd(nil, stack[0], v0111);
    nil = C_nil;
    if (exception_pending()) goto v0114;
    env = stack[-5];
    v0111 = stack[-1];
    v0111 = qcdr(v0111);
    stack[-1] = v0111;
    goto v0059;

v0115:
    v0111 = stack[-2];
    goto v0060;

v0060:
    {
        popv(6);
        fn = elt(env, 3); // maxl
        return (*qfn1(fn))(qenv(fn), v0111);
    }

v0113:
    v0111 = qvalue(elt(env, 1)); // nil
    goto v0060;
// error exit handlers
v0114:
    popv(6);
    return nil;
}



// Code for sprow_dim

static LispObject CC_sprow_dim(LispObject env,
                         LispObject v0003)
{
    LispObject nil = C_nil;
    LispObject v0116;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sprow_dim");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0003);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0003;
// end of prologue
    v0116 = qvalue(elt(env, 1)); // !*fast_la
    if (v0116 == nil) goto v0045;
    v0116 = qvalue(elt(env, 2)); // nil
    goto v0046;

v0046:
    if (v0116 == nil) goto v0083;
    v0116 = elt(env, 3); // "Error in sprow_dim: input should be a matrix."
    fn = elt(env, 4); // rederr
    v0116 = (*qfn1(fn))(qenv(fn), v0116);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    env = stack[-1];
    goto v0083;

v0083:
    v0116 = stack[0];
    fn = elt(env, 5); // spmatlength
    v0116 = (*qfn1(fn))(qenv(fn), v0116);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    v0116 = qcdr(v0116);
    v0116 = qcar(v0116);
    { popv(2); return onevalue(v0116); }

v0045:
    v0116 = stack[0];
    fn = elt(env, 6); // matrixp
    v0116 = (*qfn1(fn))(qenv(fn), v0116);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    env = stack[-1];
    v0116 = (v0116 == nil ? lisp_true : nil);
    goto v0046;
// error exit handlers
v0041:
    popv(2);
    return nil;
}



// Code for groebreduceonestepint

static LispObject CC_groebreduceonestepint(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0028, v0136, v0104;
    LispObject fn;
    LispObject v0007, v0134, v0004, v0002, v0003;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 5, "groebreduceonestepint");
    va_start(aa, nargs);
    v0003 = va_arg(aa, LispObject);
    v0002 = va_arg(aa, LispObject);
    v0004 = va_arg(aa, LispObject);
    v0134 = va_arg(aa, LispObject);
    v0007 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for groebreduceonestepint");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v0007,v0134,v0004,v0002,v0003);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0003,v0002,v0004,v0134,v0007);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0007;
    stack[-4] = v0134;
    stack[-3] = v0004;
    stack[-6] = v0002;
    stack[-2] = v0003;
// end of prologue
    v0028 = stack[-1];
    fn = elt(env, 8); // vdpred
    v0028 = (*qfn1(fn))(qenv(fn), v0028);
    nil = C_nil;
    if (exception_pending()) goto v0137;
    env = stack[-8];
    stack[0] = v0028;
    v0136 = v0028;
    v0028 = v0136;
    if (v0028 == nil) goto v0138;
    v0028 = v0136;
    v0028 = qcdr(v0028);
    v0028 = qcdr(v0028);
    v0028 = qcdr(v0028);
    v0028 = qcar(v0028);
    v0028 = (v0028 == nil ? lisp_true : nil);
    goto v0139;

v0139:
    if (v0028 == nil) goto v0038;
    v0028 = stack[-2];
    fn = elt(env, 8); // vdpred
    v0028 = (*qfn1(fn))(qenv(fn), v0028);
    nil = C_nil;
    if (exception_pending()) goto v0137;
    env = stack[-8];
    stack[-2] = v0028;
    v0028 = stack[-6];
    qvalue(elt(env, 2)) = v0028; // secondvalue!*
    { LispObject res = stack[-2]; popv(9); return onevalue(res); }

v0038:
    v0136 = stack[-4];
    v0028 = stack[-1];
    v0028 = qcdr(v0028);
    v0028 = qcar(v0028);
    fn = elt(env, 9); // vevdif
    v0028 = (*qfn2(fn))(qenv(fn), v0136, v0028);
    nil = C_nil;
    if (exception_pending()) goto v0137;
    env = stack[-8];
    stack[-7] = v0028;
    v0028 = stack[-1];
    v0028 = qcdr(v0028);
    v0028 = qcdr(v0028);
    v0028 = qcar(v0028);
    stack[-5] = v0028;
    v0028 = qvalue(elt(env, 3)); // !*groebdivide
    if (v0028 == nil) goto v0094;
    v0136 = stack[-3];
    v0028 = stack[-5];
    fn = elt(env, 10); // vbcgcd
    v0028 = (*qfn2(fn))(qenv(fn), v0136, v0028);
    nil = C_nil;
    if (exception_pending()) goto v0137;
    env = stack[-8];
    goto v0077;

v0077:
    stack[-4] = v0028;
    v0136 = stack[-5];
    v0028 = stack[-4];
    fn = elt(env, 11); // vbcquot
    v0028 = (*qfn2(fn))(qenv(fn), v0136, v0028);
    nil = C_nil;
    if (exception_pending()) goto v0137;
    env = stack[-8];
    stack[-5] = v0028;
    v0136 = stack[-3];
    v0028 = stack[-4];
    fn = elt(env, 11); // vbcquot
    v0028 = (*qfn2(fn))(qenv(fn), v0136, v0028);
    nil = C_nil;
    if (exception_pending()) goto v0137;
    env = stack[-8];
    stack[-4] = v0028;
    v0028 = stack[-6];
    if (v0028 == nil) goto v0140;
    v0028 = stack[-6];
    if (v0028 == nil) goto v0141;
    v0028 = stack[-6];
    v0028 = qcdr(v0028);
    v0028 = qcdr(v0028);
    v0028 = qcdr(v0028);
    v0028 = qcar(v0028);
    v0028 = (v0028 == nil ? lisp_true : nil);
    goto v0142;

v0142:
    if (!(v0028 == nil)) goto v0140;
    v0136 = stack[-6];
    v0028 = stack[-5];
    fn = elt(env, 12); // vdpvbcprod
    v0028 = (*qfn2(fn))(qenv(fn), v0136, v0028);
    nil = C_nil;
    if (exception_pending()) goto v0137;
    env = stack[-8];
    stack[-6] = v0028;
    goto v0140;

v0140:
    v0028 = qvalue(elt(env, 4)); // !*groebprot
    if (v0028 == nil) goto v0016;
    stack[-3] = stack[-5];
    v0028 = stack[-4];
    fn = elt(env, 13); // vbcneg
    v0104 = (*qfn1(fn))(qenv(fn), v0028);
    nil = C_nil;
    if (exception_pending()) goto v0137;
    env = stack[-8];
    v0136 = stack[-7];
    v0028 = stack[-1];
    fn = elt(env, 14); // groebreductionprotocol
    v0028 = (*qfnn(fn))(qenv(fn), 4, stack[-3], v0104, v0136, v0028);
    nil = C_nil;
    if (exception_pending()) goto v0137;
    env = stack[-8];
    goto v0016;

v0016:
    v0028 = stack[-2];
    fn = elt(env, 8); // vdpred
    stack[-3] = (*qfn1(fn))(qenv(fn), v0028);
    nil = C_nil;
    if (exception_pending()) goto v0137;
    env = stack[-8];
    stack[-2] = stack[-5];
    v0136 = qvalue(elt(env, 5)); // vdpvars!*
    v0028 = qvalue(elt(env, 6)); // nil
    fn = elt(env, 15); // vevmaptozero1
    stack[-1] = (*qfn2(fn))(qenv(fn), v0136, v0028);
    nil = C_nil;
    if (exception_pending()) goto v0137;
    env = stack[-8];
    v0028 = stack[-4];
    fn = elt(env, 13); // vbcneg
    v0136 = (*qfn1(fn))(qenv(fn), v0028);
    nil = C_nil;
    if (exception_pending()) goto v0137;
    env = stack[-8];
    v0028 = stack[-7];
    fn = elt(env, 16); // vdpilcomb1
    v0028 = (*qfnn(fn))(qenv(fn), 6, stack[-3], stack[-2], stack[-1], stack[0], v0136, v0028);
    nil = C_nil;
    if (exception_pending()) goto v0137;
    env = stack[-8];
    stack[-2] = v0028;
    v0028 = stack[-6];
    qvalue(elt(env, 2)) = v0028; // secondvalue!*
    v0028 = stack[-5];
    qvalue(elt(env, 7)) = v0028; // thirdvalue!*
    { LispObject res = stack[-2]; popv(9); return onevalue(res); }

v0141:
    v0028 = qvalue(elt(env, 1)); // t
    goto v0142;

v0094:
    v0028 = (LispObject)17; // 1
    fn = elt(env, 17); // vbcfi
    v0028 = (*qfn1(fn))(qenv(fn), v0028);
    nil = C_nil;
    if (exception_pending()) goto v0137;
    env = stack[-8];
    goto v0077;

v0138:
    v0028 = qvalue(elt(env, 1)); // t
    goto v0139;
// error exit handlers
v0137:
    popv(9);
    return nil;
}



// Code for mkunarywedge

static LispObject CC_mkunarywedge(LispObject env,
                         LispObject v0003)
{
    LispObject nil = C_nil;
    LispObject v0047, v0115, v0143;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mkunarywedge");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0003);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0003;
// end of prologue
    stack[-1] = nil;
    goto v0031;

v0031:
    v0047 = stack[0];
    if (v0047 == nil) goto v0060;
    v0047 = stack[0];
    v0047 = qcar(v0047);
    v0047 = qcar(v0047);
    v0143 = ncons(v0047);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-2];
    v0047 = stack[0];
    v0047 = qcar(v0047);
    v0115 = qcdr(v0047);
    v0047 = stack[-1];
    v0047 = acons(v0143, v0115, v0047);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-2];
    stack[-1] = v0047;
    v0047 = stack[0];
    v0047 = qcdr(v0047);
    stack[0] = v0047;
    goto v0031;

v0060:
    v0047 = stack[-1];
    {
        popv(3);
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(qenv(fn), v0047);
    }
// error exit handlers
v0082:
    popv(3);
    return nil;
}



// Code for positive!-powp

static LispObject CC_positiveKpowp(LispObject env,
                         LispObject v0003)
{
    LispObject nil = C_nil;
    LispObject v0135, v0139;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for positive-powp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0139 = v0003;
// end of prologue
    v0135 = v0139;
    v0135 = qcar(v0135);
    if (!consp(v0135)) goto v0144;
    v0135 = v0139;
    v0135 = qcar(v0135);
    v0135 = qcar(v0135);
    v0139 = elt(env, 1); // (abs norm)
    v0135 = Lmemq(nil, v0135, v0139);
    return onevalue(v0135);

v0144:
    v0135 = qvalue(elt(env, 2)); // nil
    return onevalue(v0135);
}



// Code for df!-chain!-rule

static LispObject CC_dfKchainKrule(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0133, v0150, v0151;
    LispObject fn;
    LispObject v0004, v0002, v0003;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "df-chain-rule");
    va_start(aa, nargs);
    v0003 = va_arg(aa, LispObject);
    v0002 = va_arg(aa, LispObject);
    v0004 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for df-chain-rule");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0004,v0002,v0003);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0003,v0002,v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    stack[0] = v0004;
    stack[-3] = v0002;
    stack[-4] = v0003;
// end of prologue
    v0150 = qvalue(elt(env, 1)); // nil
    v0133 = (LispObject)17; // 1
    v0133 = cons(v0150, v0133);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-6];
    v0150 = v0133;
    v0133 = stack[0];
    stack[-5] = v0133;
    goto v0144;

v0144:
    v0133 = stack[-5];
    if (v0133 == nil) { popv(7); return onevalue(v0150); }
    v0133 = stack[-5];
    v0133 = qcar(v0133);
    stack[-2] = v0133;
    stack[-1] = v0150;
    v0151 = elt(env, 2); // df
    v0150 = stack[-4];
    v0133 = stack[-2];
    v0133 = list3(v0151, v0150, v0133);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-6];
    fn = elt(env, 3); // simp
    stack[0] = (*qfn1(fn))(qenv(fn), v0133);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-6];
    v0151 = elt(env, 2); // df
    v0150 = stack[-2];
    v0133 = stack[-3];
    v0133 = list3(v0151, v0150, v0133);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-6];
    fn = elt(env, 3); // simp
    v0133 = (*qfn1(fn))(qenv(fn), v0133);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-6];
    fn = elt(env, 4); // multsq
    v0133 = (*qfn2(fn))(qenv(fn), stack[0], v0133);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-6];
    fn = elt(env, 5); // addsq
    v0133 = (*qfn2(fn))(qenv(fn), stack[-1], v0133);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-6];
    v0150 = v0133;
    v0133 = stack[-5];
    v0133 = qcdr(v0133);
    stack[-5] = v0133;
    goto v0144;
// error exit handlers
v0152:
    popv(7);
    return nil;
}



// Code for pst_d1

static LispObject CC_pst_d1(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0165;
    LispObject fn;
    LispObject v0004, v0002, v0003;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "pst_d1");
    va_start(aa, nargs);
    v0003 = va_arg(aa, LispObject);
    v0002 = va_arg(aa, LispObject);
    v0004 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pst_d1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0004,v0002,v0003);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0003,v0002,v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[-10] = v0004;
    stack[-11] = v0002;
    v0165 = v0003;
// end of prologue
    stack[0] = stack[-10];
    v0165 = sub1(v0165);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-13];
    v0165 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0165/(16/CELL)));
    stack[-12] = v0165;
    v0165 = stack[-12];
    if (v0165 == nil) goto v0135;
    v0165 = stack[-12];
    v0165 = qcar(v0165);
    stack[-6] = v0165;
    stack[0] = stack[-10];
    v0165 = stack[-11];
    v0165 = sub1(v0165);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-13];
    v0165 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0165/(16/CELL)));
    stack[-5] = v0165;
    v0165 = stack[-5];
    if (v0165 == nil) goto v0095;
    v0165 = stack[-5];
    v0165 = qcar(v0165);
    stack[-1] = v0165;
    v0165 = stack[-6];
    fn = elt(env, 2); // sc_kern
    stack[0] = (*qfn1(fn))(qenv(fn), v0165);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-13];
    v0165 = stack[-1];
    fn = elt(env, 2); // sc_kern
    v0165 = (*qfn1(fn))(qenv(fn), v0165);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-13];
    fn = elt(env, 3); // pa_coinc_split
    v0165 = (*qfn2(fn))(qenv(fn), stack[0], v0165);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-13];
    v0165 = qcar(v0165);
    fn = elt(env, 4); // ordn
    v0165 = (*qfn1(fn))(qenv(fn), v0165);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-13];
    v0165 = ncons(v0165);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-13];
    stack[-3] = v0165;
    stack[-4] = v0165;
    goto v0143;

v0143:
    v0165 = stack[-5];
    v0165 = qcdr(v0165);
    stack[-5] = v0165;
    v0165 = stack[-5];
    if (v0165 == nil) goto v0151;
    stack[-2] = stack[-3];
    v0165 = stack[-5];
    v0165 = qcar(v0165);
    stack[-1] = v0165;
    v0165 = stack[-6];
    fn = elt(env, 2); // sc_kern
    stack[0] = (*qfn1(fn))(qenv(fn), v0165);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-13];
    v0165 = stack[-1];
    fn = elt(env, 2); // sc_kern
    v0165 = (*qfn1(fn))(qenv(fn), v0165);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-13];
    fn = elt(env, 3); // pa_coinc_split
    v0165 = (*qfn2(fn))(qenv(fn), stack[0], v0165);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-13];
    v0165 = qcar(v0165);
    fn = elt(env, 4); // ordn
    v0165 = (*qfn1(fn))(qenv(fn), v0165);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-13];
    v0165 = ncons(v0165);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-13];
    v0165 = Lrplacd(nil, stack[-2], v0165);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-13];
    v0165 = stack[-3];
    v0165 = qcdr(v0165);
    stack[-3] = v0165;
    goto v0143;

v0151:
    v0165 = stack[-4];
    goto v0115;

v0115:
    fn = elt(env, 4); // ordn
    v0165 = (*qfn1(fn))(qenv(fn), v0165);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-13];
    v0165 = ncons(v0165);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-13];
    stack[-8] = v0165;
    stack[-9] = v0165;
    goto v0059;

v0059:
    v0165 = stack[-12];
    v0165 = qcdr(v0165);
    stack[-12] = v0165;
    v0165 = stack[-12];
    if (v0165 == nil) { LispObject res = stack[-9]; popv(14); return onevalue(res); }
    stack[-7] = stack[-8];
    v0165 = stack[-12];
    v0165 = qcar(v0165);
    stack[-6] = v0165;
    stack[0] = stack[-10];
    v0165 = stack[-11];
    v0165 = sub1(v0165);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-13];
    v0165 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0165/(16/CELL)));
    stack[-5] = v0165;
    v0165 = stack[-5];
    if (v0165 == nil) goto v0024;
    v0165 = stack[-5];
    v0165 = qcar(v0165);
    stack[-1] = v0165;
    v0165 = stack[-6];
    fn = elt(env, 2); // sc_kern
    stack[0] = (*qfn1(fn))(qenv(fn), v0165);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-13];
    v0165 = stack[-1];
    fn = elt(env, 2); // sc_kern
    v0165 = (*qfn1(fn))(qenv(fn), v0165);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-13];
    fn = elt(env, 3); // pa_coinc_split
    v0165 = (*qfn2(fn))(qenv(fn), stack[0], v0165);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-13];
    v0165 = qcar(v0165);
    fn = elt(env, 4); // ordn
    v0165 = (*qfn1(fn))(qenv(fn), v0165);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-13];
    v0165 = ncons(v0165);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-13];
    stack[-3] = v0165;
    stack[-4] = v0165;
    goto v0015;

v0015:
    v0165 = stack[-5];
    v0165 = qcdr(v0165);
    stack[-5] = v0165;
    v0165 = stack[-5];
    if (v0165 == nil) goto v0117;
    stack[-2] = stack[-3];
    v0165 = stack[-5];
    v0165 = qcar(v0165);
    stack[-1] = v0165;
    v0165 = stack[-6];
    fn = elt(env, 2); // sc_kern
    stack[0] = (*qfn1(fn))(qenv(fn), v0165);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-13];
    v0165 = stack[-1];
    fn = elt(env, 2); // sc_kern
    v0165 = (*qfn1(fn))(qenv(fn), v0165);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-13];
    fn = elt(env, 3); // pa_coinc_split
    v0165 = (*qfn2(fn))(qenv(fn), stack[0], v0165);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-13];
    v0165 = qcar(v0165);
    fn = elt(env, 4); // ordn
    v0165 = (*qfn1(fn))(qenv(fn), v0165);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-13];
    v0165 = ncons(v0165);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-13];
    v0165 = Lrplacd(nil, stack[-2], v0165);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-13];
    v0165 = stack[-3];
    v0165 = qcdr(v0165);
    stack[-3] = v0165;
    goto v0015;

v0117:
    v0165 = stack[-4];
    goto v0167;

v0167:
    fn = elt(env, 4); // ordn
    v0165 = (*qfn1(fn))(qenv(fn), v0165);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-13];
    v0165 = ncons(v0165);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-13];
    v0165 = Lrplacd(nil, stack[-7], v0165);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-13];
    v0165 = stack[-8];
    v0165 = qcdr(v0165);
    stack[-8] = v0165;
    goto v0059;

v0024:
    v0165 = qvalue(elt(env, 1)); // nil
    goto v0167;

v0095:
    v0165 = qvalue(elt(env, 1)); // nil
    goto v0115;

v0135:
    v0165 = qvalue(elt(env, 1)); // nil
    { popv(14); return onevalue(v0165); }
// error exit handlers
v0166:
    popv(14);
    return nil;
}



// Code for general!-difference!-mod!-p

static LispObject CC_generalKdifferenceKmodKp(LispObject env,
                         LispObject v0003, LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0168, v0113;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for general-difference-mod-p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0002,v0003);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0003,v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0168 = v0002;
    v0113 = v0003;
// end of prologue
    stack[0] = v0113;
    fn = elt(env, 1); // general!-minus!-mod!-p
    v0168 = (*qfn1(fn))(qenv(fn), v0168);
    nil = C_nil;
    if (exception_pending()) goto v0087;
    env = stack[-1];
    {
        LispObject v0086 = stack[0];
        popv(2);
        fn = elt(env, 2); // general!-plus!-mod!-p
        return (*qfn2(fn))(qenv(fn), v0086, v0168);
    }
// error exit handlers
v0087:
    popv(2);
    return nil;
}



// Code for merge_lists

static LispObject CC_merge_lists(LispObject env,
                         LispObject v0003, LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0023, v0175;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for merge_lists");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0002,v0003);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0003,v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
// copy arguments values to proper place
    stack[-4] = v0002;
    stack[-5] = v0003;
// end of prologue
    stack[-6] = nil;
    stack[-3] = nil;
    stack[-1] = nil;
    v0023 = (LispObject)17; // 1
    stack[0] = v0023;
    v0023 = stack[-5];
    v0023 = Lreverse(nil, v0023);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-7];
    stack[-5] = v0023;
    v0023 = stack[-5];
    if (v0023 == nil) goto v0168;
    v0023 = stack[-5];
    v0023 = qcar(v0023);
    stack[-6] = v0023;
    goto v0045;

v0045:
    v0023 = stack[-4];
    if (v0023 == nil) goto v0168;
    v0023 = stack[-4];
    v0023 = qcar(v0023);
    stack[-2] = v0023;
    v0175 = stack[-6];
    v0023 = stack[-2];
    v0023 = (LispObject)lessp2(v0175, v0023);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    v0023 = v0023 ? lisp_true : nil;
    env = stack[-7];
    if (!(v0023 == nil)) goto v0168;
    v0175 = stack[-2];
    v0023 = stack[-3];
    v0023 = cons(v0175, v0023);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-7];
    stack[-3] = v0023;
    v0023 = stack[-1];
    v0023 = (v0023 == nil ? lisp_true : nil);
    stack[-1] = v0023;
    v0023 = stack[-4];
    v0023 = qcdr(v0023);
    stack[-4] = v0023;
    goto v0045;

v0168:
    v0023 = stack[-5];
    if (v0023 == nil) goto v0176;
    v0023 = stack[-3];
    if (v0023 == nil) goto v0033;
    v0023 = stack[-3];
    v0023 = qcar(v0023);
    stack[-2] = v0023;
    v0175 = stack[-6];
    v0023 = stack[-2];
    if (equal(v0175, v0023)) goto v0011;
    v0023 = qvalue(elt(env, 1)); // nil
    goto v0071;

v0071:
    if (v0023 == nil) goto v0124;
    v0023 = qvalue(elt(env, 1)); // nil
    { popv(8); return onevalue(v0023); }

v0124:
    v0175 = stack[-6];
    v0023 = stack[-2];
    v0023 = (LispObject)greaterp2(v0175, v0023);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    v0023 = v0023 ? lisp_true : nil;
    env = stack[-7];
    if (v0023 == nil) goto v0102;
    v0175 = stack[-6];
    v0023 = stack[-4];
    v0023 = cons(v0175, v0023);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-7];
    stack[-4] = v0023;
    v0023 = stack[-5];
    v0023 = qcdr(v0023);
    stack[-5] = v0023;
    v0023 = stack[-1];
    if (v0023 == nil) goto v0029;
    v0175 = stack[-6];
    v0023 = (LispObject)1; // 0
    v0023 = (LispObject)greaterp2(v0175, v0023);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    v0023 = v0023 ? lisp_true : nil;
    env = stack[-7];
    if (v0023 == nil) goto v0029;
    v0023 = stack[0];
    v0023 = negate(v0023);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-7];
    stack[0] = v0023;
    goto v0029;

v0029:
    v0023 = stack[-5];
    if (v0023 == nil) goto v0168;
    v0023 = stack[-5];
    v0023 = qcar(v0023);
    stack[-6] = v0023;
    goto v0168;

v0102:
    v0175 = stack[-2];
    v0023 = stack[-4];
    v0023 = cons(v0175, v0023);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-7];
    stack[-4] = v0023;
    v0023 = stack[-3];
    v0023 = qcdr(v0023);
    stack[-3] = v0023;
    v0023 = stack[-1];
    v0023 = (v0023 == nil ? lisp_true : nil);
    stack[-1] = v0023;
    goto v0168;

v0011:
    v0175 = stack[-6];
    v0023 = (LispObject)1; // 0
    v0023 = (LispObject)greaterp2(v0175, v0023);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    v0023 = v0023 ? lisp_true : nil;
    env = stack[-7];
    goto v0071;

v0033:
    v0175 = stack[-5];
    v0023 = stack[-4];
    fn = elt(env, 2); // reversip2
    v0023 = (*qfn2(fn))(qenv(fn), v0175, v0023);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    {
        LispObject v0177 = stack[0];
        popv(8);
        return cons(v0177, v0023);
    }

v0176:
    v0175 = stack[-3];
    v0023 = stack[-4];
    fn = elt(env, 2); // reversip2
    v0023 = (*qfn2(fn))(qenv(fn), v0175, v0023);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    {
        LispObject v0020 = stack[0];
        popv(8);
        return cons(v0020, v0023);
    }
// error exit handlers
v0022:
    popv(8);
    return nil;
}



// Code for constructinvolutivebasis

static LispObject CC_constructinvolutivebasis(LispObject env,
                         LispObject v0003, LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0194, v0195, v0196;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for constructinvolutivebasis");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0002,v0003);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0003,v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
// copy arguments values to proper place
    stack[-5] = v0002;
    stack[0] = v0003;
// end of prologue
    v0195 = stack[0];
    v0194 = qvalue(elt(env, 1)); // t
    fn = elt(env, 6); // polynomlistautoreduce
    v0194 = (*qfn2(fn))(qenv(fn), v0195, v0194);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-7];
    stack[0] = v0194;
    goto v0135;

v0135:
    v0194 = stack[0];
    v0194 = qcar(v0194);
    if (v0194 == nil) goto v0039;
    stack[-1] = qvalue(elt(env, 3)); // fluidbibasissetq
    v0194 = stack[0];
    v0194 = qcar(v0194);
    fn = elt(env, 7); // createtriple
    v0194 = (*qfn1(fn))(qenv(fn), v0194);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-7];
    fn = elt(env, 8); // sortedtriplelistinsert
    v0194 = (*qfn2(fn))(qenv(fn), stack[-1], v0194);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-7];
    v0194 = stack[0];
    v0194 = qcdr(v0194);
    stack[0] = v0194;
    goto v0135;

v0039:
    v0194 = qvalue(elt(env, 3)); // fluidbibasissetq
    v0194 = qcar(v0194);
    if (v0194 == nil) goto v0198;
    fn = elt(env, 9); // setqget
    v0194 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-7];
    stack[-6] = v0194;
    v0195 = stack[-6];
    v0194 = (LispObject)17; // 1
    v0194 = *(LispObject *)((char *)v0195 + (CELL-TAG_VECTOR) + ((int32_t)v0194/(16/CELL)));
    v0194 = qcar(v0194);
    stack[-4] = v0194;
    v0195 = stack[-6];
    v0194 = (LispObject)17; // 1
    v0194 = *(LispObject *)((char *)v0195 + (CELL-TAG_VECTOR) + ((int32_t)v0194/(16/CELL)));
    fn = elt(env, 10); // normalform
    v0194 = (*qfn1(fn))(qenv(fn), v0194);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-7];
    stack[-3] = v0194;
    v0194 = stack[-3];
    v0194 = qcar(v0194);
    stack[-2] = v0194;
    v0194 = stack[-2];
    if (v0194 == nil) goto v0039;
    v0194 = qvalue(elt(env, 4)); // fluidbibasisnonzeronormalforms
    v0194 = (LispObject)((int32_t)(v0194) + 0x10);
    qvalue(elt(env, 4)) = v0194; // fluidbibasisnonzeronormalforms
    v0194 = qvalue(elt(env, 2)); // nil
    v0194 = ncons(v0194);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-7];
    stack[0] = v0194;
    v0194 = qvalue(elt(env, 5)); // fluidbibasissett
    stack[-1] = v0194;
    goto v0106;

v0106:
    v0194 = stack[-1];
    v0194 = qcar(v0194);
    if (v0194 == nil) goto v0096;
    v0194 = stack[-1];
    v0195 = qcar(v0194);
    v0194 = (LispObject)17; // 1
    v0194 = *(LispObject *)((char *)v0195 + (CELL-TAG_VECTOR) + ((int32_t)v0194/(16/CELL)));
    v0195 = qcar(v0194);
    v0194 = stack[-2];
    fn = elt(env, 11); // monomisdivisibleby
    v0194 = (*qfn2(fn))(qenv(fn), v0195, v0194);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-7];
    if (v0194 == nil) goto v0199;
    v0194 = stack[-1];
    v0195 = qcar(v0194);
    v0194 = (LispObject)1; // 0
    v0194 = *(LispObject *)((char *)v0195 + (CELL-TAG_VECTOR) + ((int32_t)v0194/(16/CELL)));
    fn = elt(env, 12); // setqdeletedescendants
    v0194 = (*qfn1(fn))(qenv(fn), v0194);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-7];
    v0195 = stack[0];
    v0194 = stack[-1];
    v0194 = qcar(v0194);
    fn = elt(env, 8); // sortedtriplelistinsert
    v0194 = (*qfn2(fn))(qenv(fn), v0195, v0194);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-7];
    v0194 = stack[-1];
    v0195 = qcar(v0194);
    v0194 = (LispObject)17; // 1
    v0194 = *(LispObject *)((char *)v0195 + (CELL-TAG_VECTOR) + ((int32_t)v0194/(16/CELL)));
    v0194 = qcar(v0194);
    fn = elt(env, 13); // janettreedelete
    v0194 = (*qfn1(fn))(qenv(fn), v0194);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-7];
    v0195 = stack[-1];
    v0194 = stack[-1];
    v0194 = qcdr(v0194);
    v0194 = qcar(v0194);
    v0195 = Lrplaca(nil, v0195, v0194);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-7];
    v0194 = stack[-1];
    v0194 = qcdr(v0194);
    v0194 = qcdr(v0194);
    v0194 = Lrplacd(nil, v0195, v0194);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-7];
    goto v0106;

v0199:
    v0194 = stack[-1];
    v0194 = qcdr(v0194);
    stack[-1] = v0194;
    goto v0106;

v0096:
    v0195 = stack[-4];
    v0194 = stack[-2];
    if (v0195 == v0194) goto v0019;
    v0194 = stack[-3];
    fn = elt(env, 7); // createtriple
    v0194 = (*qfn1(fn))(qenv(fn), v0194);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-7];
    fn = elt(env, 14); // settinsert
    v0194 = (*qfn1(fn))(qenv(fn), v0194);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-7];
    goto v0103;

v0103:
    v0194 = stack[0];
    fn = elt(env, 15); // settcollectnonmultiprolongations
    v0194 = (*qfn1(fn))(qenv(fn), v0194);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-7];
    v0195 = stack[-2];
    v0194 = (LispObject)1; // 0
    v0195 = *(LispObject *)((char *)v0195 + (CELL-TAG_VECTOR) + ((int32_t)v0194/(16/CELL)));
    v0194 = (LispObject)1; // 0
    v0194 = Leqn(nil, v0195, v0194);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-7];
    if (v0194 == nil) goto v0200;
    v0194 = qvalue(elt(env, 2)); // nil
    v0194 = ncons(v0194);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-7];
    qvalue(elt(env, 3)) = v0194; // fluidbibasissetq
    goto v0039;

v0200:
    v0194 = stack[0];
    fn = elt(env, 16); // setqinsertlist
    v0194 = (*qfn1(fn))(qenv(fn), v0194);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-7];
    goto v0039;

v0019:
    v0196 = stack[-3];
    v0195 = stack[-6];
    v0194 = (LispObject)33; // 2
    v0194 = *(LispObject *)((char *)v0195 + (CELL-TAG_VECTOR) + ((int32_t)v0194/(16/CELL)));
    fn = elt(env, 17); // createtriplewithancestor
    v0194 = (*qfn2(fn))(qenv(fn), v0196, v0194);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-7];
    fn = elt(env, 14); // settinsert
    v0194 = (*qfn1(fn))(qenv(fn), v0194);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-7];
    v0194 = qvalue(elt(env, 5)); // fluidbibasissett
    v0196 = qcar(v0194);
    v0195 = stack[-6];
    v0194 = (LispObject)49; // 3
    v0194 = *(LispObject *)((char *)v0195 + (CELL-TAG_VECTOR) + ((int32_t)v0194/(16/CELL)));
    fn = elt(env, 18); // triplesetprolongset
    v0194 = (*qfn2(fn))(qenv(fn), v0196, v0194);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-7];
    goto v0103;

v0198:
    v0194 = qvalue(elt(env, 2)); // nil
    v0194 = ncons(v0194);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-7];
    stack[0] = v0194;
    v0194 = qvalue(elt(env, 5)); // fluidbibasissett
    stack[-1] = v0194;
    goto v0201;

v0201:
    v0194 = stack[-1];
    v0194 = qcar(v0194);
    if (v0194 == nil) goto v0202;
    v0196 = stack[0];
    v0194 = stack[-1];
    v0195 = qcar(v0194);
    v0194 = (LispObject)17; // 1
    v0194 = *(LispObject *)((char *)v0195 + (CELL-TAG_VECTOR) + ((int32_t)v0194/(16/CELL)));
    fn = elt(env, 19); // sortedpolynomlistinsert
    v0194 = (*qfn2(fn))(qenv(fn), v0196, v0194);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-7];
    v0194 = stack[-1];
    v0194 = qcdr(v0194);
    stack[-1] = v0194;
    goto v0201;

v0202:
    v0195 = stack[0];
    v0194 = stack[-5];
    {
        popv(8);
        fn = elt(env, 6); // polynomlistautoreduce
        return (*qfn2(fn))(qenv(fn), v0195, v0194);
    }
// error exit handlers
v0197:
    popv(8);
    return nil;
}



// Code for ofsf_canegrel

static LispObject CC_ofsf_canegrel(LispObject env,
                         LispObject v0003, LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0113, v0149;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_canegrel");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0113 = v0002;
    v0149 = v0003;
// end of prologue
    if (!(v0113 == nil)) return onevalue(v0149);
    v0113 = v0149;
    {
        fn = elt(env, 1); // ofsf_anegrel
        return (*qfn1(fn))(qenv(fn), v0113);
    }
}



// Code for taymindegreel

static LispObject CC_taymindegreel(LispObject env,
                         LispObject v0003, LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0163, v0080;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for taymindegreel");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0002,v0003);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0003,v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0002;
    stack[-2] = v0003;
// end of prologue
    stack[-3] = nil;
    goto v0083;

v0083:
    v0163 = stack[-2];
    if (v0163 == nil) goto v0059;
    v0163 = stack[-2];
    v0163 = qcar(v0163);
    stack[0] = v0163;
    v0163 = (LispObject)1; // 0
    v0080 = v0163;
    goto v0040;

v0040:
    v0163 = stack[0];
    if (v0163 == nil) goto v0082;
    v0163 = stack[0];
    v0163 = qcar(v0163);
    fn = elt(env, 1); // tayexp!-plus2
    v0163 = (*qfn2(fn))(qenv(fn), v0163, v0080);
    nil = C_nil;
    if (exception_pending()) goto v0132;
    env = stack[-4];
    v0080 = v0163;
    v0163 = stack[0];
    v0163 = qcdr(v0163);
    stack[0] = v0163;
    goto v0040;

v0082:
    v0163 = v0080;
    v0080 = v0163;
    v0163 = stack[-1];
    v0163 = qcar(v0163);
    fn = elt(env, 2); // tayexp!-min2
    v0080 = (*qfn2(fn))(qenv(fn), v0080, v0163);
    nil = C_nil;
    if (exception_pending()) goto v0132;
    env = stack[-4];
    v0163 = stack[-3];
    v0163 = cons(v0080, v0163);
    nil = C_nil;
    if (exception_pending()) goto v0132;
    env = stack[-4];
    stack[-3] = v0163;
    v0163 = stack[-2];
    v0163 = qcdr(v0163);
    stack[-2] = v0163;
    v0163 = stack[-1];
    v0163 = qcdr(v0163);
    stack[-1] = v0163;
    goto v0083;

v0059:
    v0163 = stack[-3];
    {
        popv(5);
        fn = elt(env, 3); // nreverse
        return (*qfn1(fn))(qenv(fn), v0163);
    }
// error exit handlers
v0132:
    popv(5);
    return nil;
}



// Code for qqe_length!-graph!-marked

static LispObject CC_qqe_lengthKgraphKmarked(LispObject env,
                         LispObject v0003)
{
    LispObject nil = C_nil;
    LispObject v0046, v0045;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qqe_length-graph-marked");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0046 = v0003;
// end of prologue
    v0045 = elt(env, 1); // blockmark
    return get(v0046, v0045);
}



// Code for pasf_smordtable2

static LispObject CC_pasf_smordtable2(LispObject env,
                         LispObject v0003, LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0138, v0203, v0084;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pasf_smordtable2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0138 = v0002;
    v0203 = v0003;
// end of prologue
    v0084 = elt(env, 1); // ((lessp (lessp 2) (leq 2) (equal 2) (neq nil) (geq nil) (greaterp nil) (cong nil) (ncong nil)) (leq (lessp 2) (leq 2) (equal
// 2) (neq nil) (geq nil) (greaterp nil) (cong nil) (ncong nil)) (equal (lessp false) (leq false) (equal false) (neq 1) (geq
// 1) (greaterp 1) (cong nil) (ncong nil)) (neq (lessp 2) (leq 2) (equal 2) (neq nil) (geq nil) (greaterp nil) (cong nil) (ncong
// nil)) (geq (lessp false) (leq false) (equal false) (neq 1) (geq 1) (greaterp 1) (cong nil) (ncong nil)) (greaterp (lessp
// false) (leq false) (equal false) (neq 1) (geq 1) (greaterp 1) (cong nil) (ncong nil)))
    v0203 = Latsoc(nil, v0203, v0084);
    v0138 = Latsoc(nil, v0138, v0203);
    v0138 = qcdr(v0138);
    return onevalue(v0138);
}



// Code for sfto_kexp

static LispObject CC_sfto_kexp(LispObject env,
                         LispObject v0003, LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0204, v0038;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sfto_kexp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0002,v0003);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0003,v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0002;
    stack[-1] = v0003;
// end of prologue
    v0038 = stack[0];
    v0204 = (LispObject)1; // 0
    v0204 = Leqn(nil, v0038, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-2];
    if (v0204 == nil) goto v0162;
    v0204 = (LispObject)17; // 1
    { popv(3); return onevalue(v0204); }

v0162:
    v0038 = stack[-1];
    v0204 = stack[0];
    fn = elt(env, 2); // to
    v0038 = (*qfn2(fn))(qenv(fn), v0038, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-2];
    v0204 = (LispObject)17; // 1
    v0204 = cons(v0038, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    popv(3);
    return ncons(v0204);
// error exit handlers
v0198:
    popv(3);
    return nil;
}



// Code for ldf!-sep!-var

static LispObject CC_ldfKsepKvar(LispObject env,
                         LispObject v0003)
{
    LispObject nil = C_nil;
    LispObject v0048;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ldf-sep-var");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0003);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0003;
// end of prologue
    v0048 = stack[0];
    fn = elt(env, 1); // ldf!-pow!-var
    stack[-1] = (*qfn1(fn))(qenv(fn), v0048);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    env = stack[-2];
    v0048 = stack[0];
    fn = elt(env, 2); // ldf!-dep!-var
    v0048 = (*qfn1(fn))(qenv(fn), v0048);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    env = stack[-2];
    fn = elt(env, 3); // compl
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[-1], v0048);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    env = stack[-2];
    v0048 = stack[0];
    fn = elt(env, 4); // ldf!-spf!-var
    v0048 = (*qfn1(fn))(qenv(fn), v0048);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    env = stack[-2];
    {
        LispObject v0203 = stack[-1];
        popv(3);
        fn = elt(env, 3); // compl
        return (*qfn2(fn))(qenv(fn), v0203, v0048);
    }
// error exit handlers
v0138:
    popv(3);
    return nil;
}



// Code for groebmakepair

static LispObject CC_groebmakepair(LispObject env,
                         LispObject v0003, LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0172, v0173, v0070;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for groebmakepair");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0002,v0003);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0003,v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-2] = v0002;
    stack[-3] = v0003;
// end of prologue
    v0172 = stack[-3];
    v0172 = qcdr(v0172);
    v0173 = qcar(v0172);
    v0172 = stack[-2];
    v0172 = qcdr(v0172);
    v0172 = qcar(v0172);
    fn = elt(env, 2); // vevlcm
    v0172 = (*qfn2(fn))(qenv(fn), v0173, v0172);
    nil = C_nil;
    if (exception_pending()) goto v0008;
    env = stack[-5];
    stack[-4] = v0172;
    v0172 = qvalue(elt(env, 1)); // !*gsugar
    if (v0172 == nil) goto v0140;
    v0172 = stack[-3];
    fn = elt(env, 3); // gsugar
    stack[0] = (*qfn1(fn))(qenv(fn), v0172);
    nil = C_nil;
    if (exception_pending()) goto v0008;
    env = stack[-5];
    v0173 = stack[-4];
    v0172 = stack[-3];
    v0172 = qcdr(v0172);
    v0172 = qcar(v0172);
    fn = elt(env, 4); // vevdif
    v0172 = (*qfn2(fn))(qenv(fn), v0173, v0172);
    nil = C_nil;
    if (exception_pending()) goto v0008;
    env = stack[-5];
    fn = elt(env, 5); // vevtdeg
    v0172 = (*qfn1(fn))(qenv(fn), v0172);
    nil = C_nil;
    if (exception_pending()) goto v0008;
    env = stack[-5];
    v0172 = (LispObject)(int32_t)((int32_t)stack[0] + (int32_t)v0172 - TAG_FIXNUM);
    stack[-1] = v0172;
    v0172 = stack[-2];
    fn = elt(env, 3); // gsugar
    stack[0] = (*qfn1(fn))(qenv(fn), v0172);
    nil = C_nil;
    if (exception_pending()) goto v0008;
    env = stack[-5];
    v0173 = stack[-4];
    v0172 = stack[-2];
    v0172 = qcdr(v0172);
    v0172 = qcar(v0172);
    fn = elt(env, 4); // vevdif
    v0172 = (*qfn2(fn))(qenv(fn), v0173, v0172);
    nil = C_nil;
    if (exception_pending()) goto v0008;
    env = stack[-5];
    fn = elt(env, 5); // vevtdeg
    v0172 = (*qfn1(fn))(qenv(fn), v0172);
    nil = C_nil;
    if (exception_pending()) goto v0008;
    env = stack[-5];
    v0172 = (LispObject)(int32_t)((int32_t)stack[0] + (int32_t)v0172 - TAG_FIXNUM);
    stack[0] = stack[-4];
    v0173 = stack[-1];
    fn = elt(env, 6); // max
    v0172 = (*qfn2(fn))(qenv(fn), v0173, v0172);
    nil = C_nil;
    if (exception_pending()) goto v0008;
    {
        LispObject v0071 = stack[0];
        LispObject v0100 = stack[-3];
        LispObject v0208 = stack[-2];
        popv(6);
        return list4(v0071, v0100, v0208, v0172);
    }

v0140:
    v0070 = stack[-4];
    v0173 = stack[-3];
    v0172 = stack[-2];
    popv(6);
    return list3(v0070, v0173, v0172);
// error exit handlers
v0008:
    popv(6);
    return nil;
}



// Code for make_wedge_pair

static LispObject CC_make_wedge_pair(LispObject env,
                         LispObject v0003, LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0033, v0128, v0142;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for make_wedge_pair");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0002,v0003);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0003,v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0002;
    stack[-2] = v0003;
// end of prologue
    v0128 = stack[-2];
    v0033 = stack[-2];
    stack[0] = list2(v0128, v0033);
    nil = C_nil;
    if (exception_pending()) goto v0070;
    env = stack[-4];
    v0033 = stack[-1];
    fn = elt(env, 5); // xval
    v0033 = (*qfn1(fn))(qenv(fn), v0033);
    nil = C_nil;
    if (exception_pending()) goto v0070;
    env = stack[-4];
    fn = elt(env, 6); // xlcm
    v0033 = (*qfn2(fn))(qenv(fn), stack[0], v0033);
    nil = C_nil;
    if (exception_pending()) goto v0070;
    env = stack[-4];
    stack[-3] = v0033;
    v0033 = qvalue(elt(env, 1)); // !*twosided
    if (v0033 == nil) goto v0092;
    v0033 = qvalue(elt(env, 2)); // xtruncate!*
    if (!(v0033 == nil)) goto v0092;

v0095:
    v0128 = stack[-2];
    v0033 = stack[-1];
    fn = elt(env, 7); // overall_factor
    v0033 = (*qfn2(fn))(qenv(fn), v0128, v0033);
    nil = C_nil;
    if (exception_pending()) goto v0070;
    env = stack[-4];
    if (v0033 == nil) goto v0039;
    v0033 = qvalue(elt(env, 3)); // nil
    { popv(5); return onevalue(v0033); }

v0039:
    v0033 = stack[-3];
    fn = elt(env, 8); // mknwedge
    v0033 = (*qfn1(fn))(qenv(fn), v0033);
    nil = C_nil;
    if (exception_pending()) goto v0070;
    env = stack[-4];
    fn = elt(env, 9); // xdegreecheck
    v0033 = (*qfn1(fn))(qenv(fn), v0033);
    nil = C_nil;
    if (exception_pending()) goto v0070;
    env = stack[-4];
    if (v0033 == nil) goto v0035;
    v0033 = qvalue(elt(env, 3)); // nil
    { popv(5); return onevalue(v0033); }

v0035:
    stack[0] = elt(env, 4); // wedge_pair
    v0142 = stack[-2];
    v0128 = (LispObject)17; // 1
    v0033 = (LispObject)17; // 1
    v0033 = list2star(v0142, v0128, v0033);
    nil = C_nil;
    if (exception_pending()) goto v0070;
    env = stack[-4];
    v0128 = ncons(v0033);
    nil = C_nil;
    if (exception_pending()) goto v0070;
    v0033 = stack[-1];
    {
        LispObject v0209 = stack[-3];
        LispObject v0210 = stack[0];
        popv(5);
        return list4(v0209, v0210, v0128, v0033);
    }

v0092:
    stack[0] = stack[-2];
    v0033 = stack[-1];
    fn = elt(env, 5); // xval
    v0033 = (*qfn1(fn))(qenv(fn), v0033);
    nil = C_nil;
    if (exception_pending()) goto v0070;
    env = stack[-4];
    v0033 = Lmemq(nil, stack[0], v0033);
    if (!(v0033 == nil)) goto v0095;
    v0033 = qvalue(elt(env, 3)); // nil
    { popv(5); return onevalue(v0033); }
// error exit handlers
v0070:
    popv(5);
    return nil;
}



// Code for gbftimes

static LispObject CC_gbftimes(LispObject env,
                         LispObject v0003, LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0114, v0132, v0133;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gbftimes");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0002,v0003);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0003,v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    v0132 = v0002;
    v0133 = v0003;
// end of prologue
    v0114 = v0133;
    v0114 = qcar(v0114);
    stack[-4] = v0114;
    v0114 = v0133;
    v0114 = qcdr(v0114);
    stack[-3] = v0114;
    v0114 = v0132;
    v0114 = qcar(v0114);
    stack[-2] = v0114;
    v0114 = v0132;
    v0114 = qcdr(v0114);
    stack[-1] = v0114;
    v0132 = stack[-4];
    v0114 = stack[-2];
    fn = elt(env, 1); // csl_timbf
    stack[0] = (*qfn2(fn))(qenv(fn), v0132, v0114);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    env = stack[-5];
    v0132 = stack[-3];
    v0114 = stack[-1];
    fn = elt(env, 1); // csl_timbf
    v0114 = (*qfn2(fn))(qenv(fn), v0132, v0114);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    env = stack[-5];
    fn = elt(env, 2); // difbf
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v0114);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    env = stack[-5];
    v0132 = stack[-4];
    v0114 = stack[-1];
    fn = elt(env, 1); // csl_timbf
    stack[-1] = (*qfn2(fn))(qenv(fn), v0132, v0114);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    env = stack[-5];
    v0132 = stack[-3];
    v0114 = stack[-2];
    fn = elt(env, 1); // csl_timbf
    v0114 = (*qfn2(fn))(qenv(fn), v0132, v0114);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    env = stack[-5];
    fn = elt(env, 3); // plubf
    v0114 = (*qfn2(fn))(qenv(fn), stack[-1], v0114);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    {
        LispObject v0130 = stack[0];
        popv(6);
        return cons(v0130, v0114);
    }
// error exit handlers
v0205:
    popv(6);
    return nil;
}



// Code for gpexpp

static LispObject CC_gpexpp(LispObject env,
                         LispObject v0003)
{
    LispObject nil = C_nil;
    LispObject v0043, v0044;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gpexpp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0003);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0003;
// end of prologue

v0031:
    v0043 = stack[0];
    if (!consp(v0043)) goto v0060;
    v0043 = stack[0];
    v0044 = qcar(v0043);
    v0043 = elt(env, 2); // (!:rd!: !:cr!: !:crn!: !:gi!:)
    v0043 = Lmemq(nil, v0044, v0043);
    if (v0043 == nil) goto v0038;
    v0043 = qvalue(elt(env, 3)); // t
    { popv(2); return onevalue(v0043); }

v0038:
    v0043 = stack[0];
    v0044 = qcar(v0043);
    v0043 = elt(env, 4); // plus
    if (v0044 == v0043) goto v0049;
    v0043 = stack[0];
    v0044 = qcar(v0043);
    v0043 = elt(env, 5); // (minus recip)
    v0043 = Lmemq(nil, v0044, v0043);
    if (v0043 == nil) goto v0072;
    v0043 = stack[0];
    v0044 = Llength(nil, v0043);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-1];
    v0043 = (LispObject)33; // 2
    if (v0044 == v0043) goto v0033;
    v0043 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0043); }

v0033:
    v0043 = stack[0];
    v0043 = qcdr(v0043);
    v0043 = qcar(v0043);
    stack[0] = v0043;
    goto v0031;

v0072:
    v0043 = stack[0];
    v0044 = qcar(v0043);
    v0043 = elt(env, 6); // (difference quotient expt)
    v0043 = Lmemq(nil, v0044, v0043);
    if (v0043 == nil) goto v0120;
    v0043 = stack[0];
    v0044 = Llength(nil, v0043);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-1];
    v0043 = (LispObject)49; // 3
    if (v0044 == v0043) goto v0158;
    v0043 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0043); }

v0158:
    v0043 = stack[0];
    v0043 = qcdr(v0043);
    v0043 = qcar(v0043);
    v0043 = CC_gpexpp(env, v0043);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-1];
    if (v0043 == nil) goto v0217;
    v0043 = stack[0];
    v0043 = qcdr(v0043);
    v0043 = qcdr(v0043);
    v0043 = qcar(v0043);
    stack[0] = v0043;
    goto v0031;

v0217:
    v0043 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0043); }

v0120:
    v0043 = stack[0];
    v0044 = qcar(v0043);
    v0043 = elt(env, 7); // times
    if (v0044 == v0043) goto v0199;
    v0043 = stack[0];
    v0044 = qcar(v0043);
    v0043 = elt(env, 8); // !:rd!:
    if (v0044 == v0043) goto v0218;
    v0043 = stack[0];
    v0044 = qcar(v0043);
    v0043 = elt(env, 9); // (!:cr!: !:crn!: !:gi!:)
    v0043 = Lmemq(nil, v0044, v0043);
    if (v0043 == nil) goto v0219;
    v0043 = qvalue(elt(env, 3)); // t
    { popv(2); return onevalue(v0043); }

v0219:
    v0043 = stack[0];
    v0043 = qcar(v0043);
    fn = elt(env, 10); // unresidp
    v0043 = (*qfn1(fn))(qenv(fn), v0043);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-1];
    if (v0043 == nil) goto v0001;
    v0043 = stack[0];
    v0043 = qcdr(v0043);
    {
        popv(2);
        fn = elt(env, 11); // gparg1p
        return (*qfn1(fn))(qenv(fn), v0043);
    }

v0001:
    v0043 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0043); }

v0218:
    v0043 = qvalue(elt(env, 3)); // t
    { popv(2); return onevalue(v0043); }

v0199:
    v0043 = stack[0];
    v0044 = Llength(nil, v0043);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-1];
    v0043 = (LispObject)49; // 3
    v0043 = (LispObject)geq2(v0044, v0043);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    v0043 = v0043 ? lisp_true : nil;
    env = stack[-1];
    if (v0043 == nil) goto v0220;
    v0043 = stack[0];
    v0043 = qcdr(v0043);
    v0043 = qcar(v0043);
    v0043 = CC_gpexpp(env, v0043);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-1];
    if (v0043 == nil) goto v0020;
    v0043 = stack[0];
    v0043 = qcdr(v0043);
    v0043 = qcdr(v0043);
    v0043 = qcar(v0043);
    v0043 = CC_gpexpp(env, v0043);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-1];
    if (v0043 == nil) goto v0189;
    v0043 = stack[0];
    v0043 = qcdr(v0043);
    v0043 = qcdr(v0043);
    v0043 = qcdr(v0043);
    {
        popv(2);
        fn = elt(env, 12); // gpexp1p
        return (*qfn1(fn))(qenv(fn), v0043);
    }

v0189:
    v0043 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0043); }

v0020:
    v0043 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0043); }

v0220:
    v0043 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0043); }

v0049:
    v0043 = stack[0];
    v0044 = Llength(nil, v0043);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-1];
    v0043 = (LispObject)33; // 2
    v0043 = (LispObject)geq2(v0044, v0043);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    v0043 = v0043 ? lisp_true : nil;
    env = stack[-1];
    if (v0043 == nil) goto v0130;
    v0043 = stack[0];
    v0043 = qcdr(v0043);
    v0043 = qcar(v0043);
    v0043 = CC_gpexpp(env, v0043);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-1];
    if (v0043 == nil) goto v0078;
    v0043 = stack[0];
    v0043 = qcdr(v0043);
    v0043 = qcdr(v0043);
    {
        popv(2);
        fn = elt(env, 12); // gpexp1p
        return (*qfn1(fn))(qenv(fn), v0043);
    }

v0078:
    v0043 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0043); }

v0130:
    v0043 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0043); }

v0060:
    v0043 = stack[0];
    v0043 = Lsymbolp(nil, v0043);
    env = stack[-1];
    v0044 = v0043;
    if (!(v0043 == nil)) { popv(2); return onevalue(v0044); }
    v0043 = stack[0];
    v0043 = (is_number(v0043) ? lisp_true : nil);
    v0044 = v0043;
    if (!(v0043 == nil)) { popv(2); return onevalue(v0044); }
    v0043 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0043); }
// error exit handlers
v0185:
    popv(2);
    return nil;
}



// Code for chksymmetries!&sub1

static LispObject CC_chksymmetriesGsub1(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0164, v0146, v0198;
    LispObject fn;
    LispObject v0134, v0004, v0002, v0003;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "chksymmetries&sub1");
    va_start(aa, nargs);
    v0003 = va_arg(aa, LispObject);
    v0002 = va_arg(aa, LispObject);
    v0004 = va_arg(aa, LispObject);
    v0134 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for chksymmetries&sub1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0134,v0004,v0002,v0003);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0003,v0002,v0004,v0134);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0134;
    v0164 = v0004;
    v0146 = v0002;
    v0198 = v0003;
// end of prologue
    v0164 = Lsubst(nil, 3, v0198, v0146, v0164);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[-2];
    stack[-1] = v0164;
    v0164 = stack[0];
    if (v0164 == nil) goto v0138;
    v0146 = stack[-1];
    v0164 = stack[0];
    fn = elt(env, 3); // indxsymp
    v0164 = (*qfn2(fn))(qenv(fn), v0146, v0164);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[-2];
    goto v0139;

v0139:
    if (!(v0164 == nil)) { LispObject res = stack[-1]; popv(3); return onevalue(res); }
    v0164 = qvalue(elt(env, 2)); // nil
    { popv(3); return onevalue(v0164); }

v0138:
    v0164 = qvalue(elt(env, 1)); // t
    goto v0139;
// error exit handlers
v0174:
    popv(3);
    return nil;
}



// Code for cde_alglistp

static LispObject CC_cde_alglistp(LispObject env,
                         LispObject v0003)
{
    LispObject nil = C_nil;
    LispObject v0048, v0135;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cde_alglistp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0003);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0003;
// end of prologue
    v0048 = stack[0];
    fn = elt(env, 3); // listp
    v0048 = (*qfn1(fn))(qenv(fn), v0048);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    env = stack[-1];
    if (v0048 == nil) goto v0007;
    v0048 = stack[0];
    v0048 = qcar(v0048);
    v0135 = elt(env, 2); // list
    v0048 = (v0048 == v0135 ? lisp_true : nil);
    { popv(2); return onevalue(v0048); }

v0007:
    v0048 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0048); }
// error exit handlers
v0138:
    popv(2);
    return nil;
}



// Code for qroundup

static LispObject CC_qroundup(LispObject env,
                         LispObject v0003, LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0198, v0039;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qroundup");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0002,v0003);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0003,v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0002;
    stack[-1] = v0003;
// end of prologue
    v0039 = stack[-1];
    v0198 = (LispObject)1; // 0
    v0198 = (LispObject)lessp2(v0039, v0198);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    v0198 = v0198 ? lisp_true : nil;
    env = stack[-2];
    if (v0198 == nil) goto v0145;
    v0198 = stack[-1];
    v0039 = negate(v0198);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-2];
    v0198 = stack[0];
    v0198 = quot2(v0039, v0198);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    popv(3);
    return negate(v0198);

v0145:
    v0198 = stack[0];
    v0198 = sub1(v0198);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-2];
    v0039 = plus2(stack[-1], v0198);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    v0198 = stack[0];
    popv(3);
    return quot2(v0039, v0198);
// error exit handlers
v0095:
    popv(3);
    return nil;
}



// Code for even_action_pow

static LispObject CC_even_action_pow(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0027, v0063, v0028, v0136;
    LispObject fn;
    LispObject v0134, v0004, v0002, v0003;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "even_action_pow");
    va_start(aa, nargs);
    v0003 = va_arg(aa, LispObject);
    v0002 = va_arg(aa, LispObject);
    v0004 = va_arg(aa, LispObject);
    v0134 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for even_action_pow");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0134,v0004,v0002,v0003);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0003,v0002,v0004,v0134);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    stack[-2] = v0134;
    stack[-3] = v0004;
    stack[-4] = v0002;
    v0136 = v0003;
// end of prologue
    v0027 = stack[-4];
    v0027 = qcar(v0027);
    v0028 = v0027;
    v0027 = stack[-4];
    v0027 = qcdr(v0027);
    stack[-1] = v0027;
    v0063 = v0028;
    v0027 = v0136;
    v0027 = Lassoc(nil, v0063, v0027);
    stack[0] = v0027;
    if (v0027 == nil) goto v0051;
    v0063 = stack[-1];
    v0027 = (LispObject)17; // 1
    if (v0063 == v0027) goto v0164;
    stack[-4] = v0028;
    v0027 = stack[-1];
    v0027 = sub1(v0027);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-6];
    fn = elt(env, 2); // to
    v0063 = (*qfn2(fn))(qenv(fn), stack[-4], v0027);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-6];
    v0027 = stack[-1];
    v0028 = cons(v0063, v0027);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-6];
    v0063 = qvalue(elt(env, 1)); // nil
    v0027 = (LispObject)17; // 1
    v0027 = acons(v0028, v0063, v0027);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-6];
    goto v0131;

v0131:
    v0028 = stack[0];
    v0063 = stack[-3];
    fn = elt(env, 3); // component_action
    v0027 = (*qfnn(fn))(qenv(fn), 3, v0028, v0063, v0027);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-6];
    stack[0] = v0027;
    v0063 = stack[0];
    v0027 = stack[-2];
    {
        popv(7);
        fn = elt(env, 4); // multsq
        return (*qfn2(fn))(qenv(fn), v0063, v0027);
    }

v0164:
    v0063 = (LispObject)17; // 1
    v0027 = (LispObject)17; // 1
    v0027 = cons(v0063, v0027);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-6];
    goto v0131;

v0051:
    v0063 = v0028;
    v0028 = v0136;
    v0027 = qvalue(elt(env, 1)); // nil
    fn = elt(env, 5); // find_active_components
    v0027 = (*qfnn(fn))(qenv(fn), 3, v0063, v0028, v0027);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-6];
    stack[-1] = v0027;
    v0063 = qvalue(elt(env, 1)); // nil
    v0027 = (LispObject)17; // 1
    v0027 = cons(v0063, v0027);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-6];
    stack[0] = v0027;
    v0027 = stack[-1];
    stack[-5] = v0027;
    goto v0011;

v0011:
    v0027 = stack[-5];
    if (v0027 == nil) goto v0122;
    v0027 = stack[-5];
    v0027 = qcar(v0027);
    stack[-1] = v0027;
    v0063 = stack[-4];
    v0027 = stack[-1];
    v0027 = qcar(v0027);
    fn = elt(env, 6); // diffp
    v0027 = (*qfn2(fn))(qenv(fn), v0063, v0027);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-6];
    v0028 = stack[-1];
    v0063 = stack[-3];
    fn = elt(env, 3); // component_action
    v0027 = (*qfnn(fn))(qenv(fn), 3, v0028, v0063, v0027);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-6];
    fn = elt(env, 7); // addsq
    v0027 = (*qfn2(fn))(qenv(fn), stack[0], v0027);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-6];
    stack[0] = v0027;
    v0027 = stack[-5];
    v0027 = qcdr(v0027);
    stack[-5] = v0027;
    goto v0011;

v0122:
    v0063 = stack[0];
    v0027 = stack[-2];
    {
        popv(7);
        fn = elt(env, 4); // multsq
        return (*qfn2(fn))(qenv(fn), v0063, v0027);
    }
// error exit handlers
v0155:
    popv(7);
    return nil;
}



// Code for ofsf_smwrmknowl

static LispObject CC_ofsf_smwrmknowl(LispObject env,
                         LispObject v0003, LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0085, v0116, v0110;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_smwrmknowl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0116 = v0002;
    v0110 = v0003;
// end of prologue
    v0085 = qvalue(elt(env, 1)); // !*rlsusi
    if (v0085 == nil) goto v0037;
    v0085 = v0110;
    {
        fn = elt(env, 2); // ofsf_susirmknowl
        return (*qfn2(fn))(qenv(fn), v0085, v0116);
    }

v0037:
    v0085 = v0110;
    {
        fn = elt(env, 3); // ofsf_smrmknowl
        return (*qfn2(fn))(qenv(fn), v0085, v0116);
    }
}



// Code for !*multsq

static LispObject CC_Hmultsq(LispObject env,
                         LispObject v0003, LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0166, v0061;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *multsq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0002,v0003);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0003,v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-2] = v0002;
    stack[-3] = v0003;
// end of prologue
    v0166 = stack[-3];
    v0166 = qcar(v0166);
    if (v0166 == nil) goto v0059;
    v0166 = stack[-2];
    v0166 = qcar(v0166);
    v0166 = (v0166 == nil ? lisp_true : nil);
    goto v0060;

v0060:
    if (v0166 == nil) goto v0047;
    v0061 = qvalue(elt(env, 2)); // nil
    v0166 = (LispObject)17; // 1
    popv(6);
    return cons(v0061, v0166);

v0047:
    v0166 = stack[-3];
    v0061 = qcdr(v0166);
    v0166 = (LispObject)17; // 1
    if (v0061 == v0166) goto v0164;
    v0166 = qvalue(elt(env, 2)); // nil
    goto v0092;

v0092:
    if (v0166 == nil) goto v0152;
    v0166 = stack[-3];
    v0061 = qcar(v0166);
    v0166 = stack[-2];
    v0166 = qcar(v0166);
    fn = elt(env, 3); // !*multf
    v0061 = (*qfn2(fn))(qenv(fn), v0061, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    v0166 = (LispObject)17; // 1
    popv(6);
    return cons(v0061, v0166);

v0152:
    v0166 = stack[-3];
    v0061 = qcar(v0166);
    v0166 = stack[-2];
    v0166 = qcdr(v0166);
    fn = elt(env, 4); // gcdf
    v0166 = (*qfn2(fn))(qenv(fn), v0061, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-5];
    stack[-4] = v0166;
    v0166 = stack[-2];
    v0061 = qcar(v0166);
    v0166 = stack[-3];
    v0166 = qcdr(v0166);
    fn = elt(env, 4); // gcdf
    v0166 = (*qfn2(fn))(qenv(fn), v0061, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-5];
    stack[-1] = v0166;
    v0166 = stack[-3];
    v0061 = qcar(v0166);
    v0166 = stack[-4];
    fn = elt(env, 5); // quotf!-fail
    stack[0] = (*qfn2(fn))(qenv(fn), v0061, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-5];
    v0166 = stack[-2];
    v0061 = qcar(v0166);
    v0166 = stack[-1];
    fn = elt(env, 5); // quotf!-fail
    v0166 = (*qfn2(fn))(qenv(fn), v0061, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-5];
    fn = elt(env, 3); // !*multf
    v0166 = (*qfn2(fn))(qenv(fn), stack[0], v0166);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-5];
    stack[0] = v0166;
    v0166 = stack[-3];
    v0061 = qcdr(v0166);
    v0166 = stack[-1];
    fn = elt(env, 5); // quotf!-fail
    stack[-1] = (*qfn2(fn))(qenv(fn), v0061, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-5];
    v0166 = stack[-2];
    v0061 = qcdr(v0166);
    v0166 = stack[-4];
    fn = elt(env, 5); // quotf!-fail
    v0166 = (*qfn2(fn))(qenv(fn), v0061, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-5];
    fn = elt(env, 3); // !*multf
    v0166 = (*qfn2(fn))(qenv(fn), stack[-1], v0166);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-5];
    stack[-4] = v0166;
    v0166 = stack[-4];
    fn = elt(env, 6); // minusf
    v0166 = (*qfn1(fn))(qenv(fn), v0166);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-5];
    if (v0166 == nil) goto v0191;
    v0166 = stack[0];
    fn = elt(env, 7); // negf
    v0166 = (*qfn1(fn))(qenv(fn), v0166);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-5];
    stack[0] = v0166;
    v0166 = stack[-4];
    fn = elt(env, 7); // negf
    v0166 = (*qfn1(fn))(qenv(fn), v0166);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-5];
    stack[-4] = v0166;
    goto v0191;

v0191:
    v0061 = stack[0];
    v0166 = stack[-4];
    fn = elt(env, 4); // gcdf
    v0166 = (*qfn2(fn))(qenv(fn), v0061, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-5];
    stack[-1] = v0166;
    v0061 = stack[-1];
    v0166 = (LispObject)17; // 1
    if (v0061 == v0166) goto v0155;
    v0061 = stack[0];
    v0166 = stack[-1];
    fn = elt(env, 5); // quotf!-fail
    stack[0] = (*qfn2(fn))(qenv(fn), v0061, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-5];
    v0061 = stack[-4];
    v0166 = stack[-1];
    fn = elt(env, 5); // quotf!-fail
    v0166 = (*qfn2(fn))(qenv(fn), v0061, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    {
        LispObject v0090 = stack[0];
        popv(6);
        return cons(v0090, v0166);
    }

v0155:
    v0061 = stack[0];
    v0166 = stack[-4];
    popv(6);
    return cons(v0061, v0166);

v0164:
    v0166 = stack[-2];
    v0061 = qcdr(v0166);
    v0166 = (LispObject)17; // 1
    v0166 = (v0061 == v0166 ? lisp_true : nil);
    goto v0092;

v0059:
    v0166 = qvalue(elt(env, 1)); // t
    goto v0060;
// error exit handlers
v0089:
    popv(6);
    return nil;
}



// Code for cl_susimkatl

static LispObject CC_cl_susimkatl(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0241, v0242, v0243;
    LispObject fn;
    LispObject v0134, v0004, v0002, v0003;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "cl_susimkatl");
    va_start(aa, nargs);
    v0003 = va_arg(aa, LispObject);
    v0002 = va_arg(aa, LispObject);
    v0004 = va_arg(aa, LispObject);
    v0134 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cl_susimkatl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0134,v0004,v0002,v0003);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0003,v0002,v0004,v0134);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
// copy arguments values to proper place
    stack[-3] = v0134;
    v0241 = v0004;
    stack[-4] = v0002;
    stack[-5] = v0003;
// end of prologue
    stack[-6] = v0241;
    goto v0113;

v0113:
    v0241 = stack[-6];
    if (v0241 == nil) goto v0144;
    v0241 = stack[-6];
    v0241 = qcar(v0241);
    v0243 = v0241;
    v0241 = v0243;
    v0242 = qcdr(v0241);
    v0241 = stack[-3];
    if (equal(v0242, v0241)) goto v0116;
    v0241 = nil;
    goto v0085;

v0085:
    stack[-2] = v0241;
    v0241 = stack[-2];
    fn = elt(env, 8); // lastpair
    v0241 = (*qfn1(fn))(qenv(fn), v0241);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-7];
    stack[-1] = v0241;
    v0241 = stack[-6];
    v0241 = qcdr(v0241);
    stack[-6] = v0241;
    v0241 = stack[-1];
    if (!consp(v0241)) goto v0113;
    else goto v0149;

v0149:
    v0241 = stack[-6];
    if (v0241 == nil) goto v0148;
    stack[0] = stack[-1];
    v0241 = stack[-6];
    v0241 = qcar(v0241);
    v0243 = v0241;
    v0241 = v0243;
    v0242 = qcdr(v0241);
    v0241 = stack[-3];
    if (equal(v0242, v0241)) goto v0114;
    v0241 = nil;
    goto v0192;

v0192:
    v0241 = Lrplacd(nil, stack[0], v0241);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-7];
    v0241 = stack[-1];
    fn = elt(env, 8); // lastpair
    v0241 = (*qfn1(fn))(qenv(fn), v0241);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-7];
    stack[-1] = v0241;
    v0241 = stack[-6];
    v0241 = qcdr(v0241);
    stack[-6] = v0241;
    goto v0149;

v0114:
    v0241 = v0243;
    v0241 = qcar(v0241);
    v0241 = ncons(v0241);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-7];
    goto v0192;

v0148:
    v0241 = stack[-2];
    goto v0168;

v0168:
    v0243 = v0241;
    v0241 = v0243;
    if (v0241 == nil) goto v0225;
    v0242 = v0243;
    v0241 = stack[-4];
    fn = elt(env, 9); // rl_susipost
    v0241 = (*qfn2(fn))(qenv(fn), v0242, v0241);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-7];
    v0243 = v0241;
    v0242 = v0243;
    v0241 = elt(env, 2); // true
    if (v0242 == v0241) goto v0223;
    v0242 = v0243;
    v0241 = elt(env, 4); // false
    v0241 = (v0242 == v0241 ? lisp_true : nil);
    goto v0224;

v0224:
    if (v0241 == nil) goto v0159;
    v0242 = stack[-5];
    v0241 = elt(env, 5); // and
    v0241 = (v0242 == v0241 ? lisp_true : nil);
    fn = elt(env, 10); // cl_cflip
    v0241 = (*qfn2(fn))(qenv(fn), v0243, v0241);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    popv(8);
    return ncons(v0241);

v0159:
    v0242 = v0243;
    v0241 = elt(env, 6); // inctheo
    if (v0242 == v0241) goto v0119;
    v0242 = stack[-5];
    v0241 = elt(env, 7); // or
    if (!(v0242 == v0241)) goto v0028;
    v0241 = v0243;
    stack[-3] = v0241;
    v0241 = stack[-3];
    if (v0241 == nil) goto v0023;
    v0241 = stack[-3];
    v0241 = qcar(v0241);
    fn = elt(env, 11); // rl_negateat
    v0241 = (*qfn1(fn))(qenv(fn), v0241);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-7];
    v0241 = ncons(v0241);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-7];
    stack[-1] = v0241;
    stack[-2] = v0241;
    goto v0018;

v0018:
    v0241 = stack[-3];
    v0241 = qcdr(v0241);
    stack[-3] = v0241;
    v0241 = stack[-3];
    if (v0241 == nil) goto v0220;
    stack[0] = stack[-1];
    v0241 = stack[-3];
    v0241 = qcar(v0241);
    fn = elt(env, 11); // rl_negateat
    v0241 = (*qfn1(fn))(qenv(fn), v0241);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-7];
    v0241 = ncons(v0241);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-7];
    v0241 = Lrplacd(nil, stack[0], v0241);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-7];
    v0241 = stack[-1];
    v0241 = qcdr(v0241);
    stack[-1] = v0241;
    goto v0018;

v0220:
    v0241 = stack[-2];
    goto v0227;

v0227:
    v0243 = v0241;
    goto v0028;

v0028:
    v0241 = v0243;
    stack[-3] = v0241;
    v0241 = stack[-3];
    if (v0241 == nil) goto v0244;
    v0241 = stack[-3];
    v0241 = qcar(v0241);
    v0242 = v0241;
    v0241 = stack[-4];
    fn = elt(env, 12); // rl_susitf
    v0241 = (*qfn2(fn))(qenv(fn), v0242, v0241);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-7];
    v0241 = ncons(v0241);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-7];
    stack[-1] = v0241;
    stack[-2] = v0241;
    goto v0245;

v0245:
    v0241 = stack[-3];
    v0241 = qcdr(v0241);
    stack[-3] = v0241;
    v0241 = stack[-3];
    if (v0241 == nil) { LispObject res = stack[-2]; popv(8); return onevalue(res); }
    stack[0] = stack[-1];
    v0241 = stack[-3];
    v0241 = qcar(v0241);
    v0242 = v0241;
    v0241 = stack[-4];
    fn = elt(env, 12); // rl_susitf
    v0241 = (*qfn2(fn))(qenv(fn), v0242, v0241);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-7];
    v0241 = ncons(v0241);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-7];
    v0241 = Lrplacd(nil, stack[0], v0241);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-7];
    v0241 = stack[-1];
    v0241 = qcdr(v0241);
    stack[-1] = v0241;
    goto v0245;

v0244:
    v0241 = qvalue(elt(env, 1)); // nil
    { popv(8); return onevalue(v0241); }

v0023:
    v0241 = qvalue(elt(env, 1)); // nil
    goto v0227;

v0119:
    v0243 = elt(env, 4); // false
    v0242 = stack[-5];
    v0241 = elt(env, 5); // and
    v0241 = (v0242 == v0241 ? lisp_true : nil);
    {
        popv(8);
        fn = elt(env, 10); // cl_cflip
        return (*qfn2(fn))(qenv(fn), v0243, v0241);
    }

v0223:
    v0241 = qvalue(elt(env, 3)); // t
    goto v0224;

v0225:
    v0241 = qvalue(elt(env, 1)); // nil
    { popv(8); return onevalue(v0241); }

v0116:
    v0241 = v0243;
    v0241 = qcar(v0241);
    v0241 = ncons(v0241);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-7];
    goto v0085;

v0144:
    v0241 = qvalue(elt(env, 1)); // nil
    goto v0168;
// error exit handlers
v0202:
    popv(8);
    return nil;
}



// Code for dipreplus

static LispObject CC_dipreplus(LispObject env,
                         LispObject v0003)
{
    LispObject nil = C_nil;
    LispObject v0203, v0084;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dipreplus");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0084 = v0003;
// end of prologue
    v0203 = v0084;
    if (!consp(v0203)) return onevalue(v0084);
    v0203 = v0084;
    v0203 = qcdr(v0203);
    if (v0203 == nil) goto v0060;
    v0203 = elt(env, 1); // plus
    return cons(v0203, v0084);

v0060:
    v0203 = v0084;
    v0203 = qcar(v0203);
    return onevalue(v0203);
}



// Code for latexprint

static LispObject CC_latexprint(LispObject env,
                         LispObject v0003)
{
    LispObject nil = C_nil;
    LispObject v0083;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for latexprint");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0003);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0003;
// end of prologue
    fn = elt(env, 1); // prinlabegin
    v0083 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-1];
    v0083 = stack[0];
    fn = elt(env, 2); // latexprin
    v0083 = (*qfn1(fn))(qenv(fn), v0083);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 3); // prinlaend
        return (*qfnn(fn))(qenv(fn), 0);
    }
// error exit handlers
v0060:
    popv(2);
    return nil;
}



// Code for decimal2internal

static LispObject CC_decimal2internal(LispObject env,
                         LispObject v0003, LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0112, v0163, v0080;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for decimal2internal");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0002,v0003);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0003,v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0002;
    stack[-1] = v0003;
// end of prologue
    v0163 = stack[0];
    v0112 = (LispObject)1; // 0
    v0112 = (LispObject)geq2(v0163, v0112);
    nil = C_nil;
    if (exception_pending()) goto v0114;
    v0112 = v0112 ? lisp_true : nil;
    env = stack[-3];
    if (v0112 == nil) goto v0207;
    stack[-2] = elt(env, 1); // !:rd!:
    v0163 = (LispObject)161; // 10
    v0112 = stack[0];
    v0112 = Lexpt(nil, v0163, v0112);
    nil = C_nil;
    if (exception_pending()) goto v0114;
    env = stack[-3];
    v0163 = times2(stack[-1], v0112);
    nil = C_nil;
    if (exception_pending()) goto v0114;
    v0112 = (LispObject)1; // 0
    {
        LispObject v0132 = stack[-2];
        popv(4);
        return list2star(v0132, v0163, v0112);
    }

v0207:
    v0080 = elt(env, 1); // !:rd!:
    v0163 = stack[-1];
    v0112 = (LispObject)1; // 0
    stack[-1] = list2star(v0080, v0163, v0112);
    nil = C_nil;
    if (exception_pending()) goto v0114;
    env = stack[-3];
    v0112 = stack[0];
    v0112 = negate(v0112);
    nil = C_nil;
    if (exception_pending()) goto v0114;
    env = stack[-3];
    {
        LispObject v0133 = stack[-1];
        popv(4);
        fn = elt(env, 2); // divide!-by!-power!-of!-ten
        return (*qfn2(fn))(qenv(fn), v0133, v0112);
    }
// error exit handlers
v0114:
    popv(4);
    return nil;
}



// Code for tidysqrtf

static LispObject CC_tidysqrtf(LispObject env,
                         LispObject v0003)
{
    LispObject nil = C_nil;
    LispObject v0165, v0249, v0189;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for tidysqrtf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0003);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0003;
// end of prologue
    v0165 = stack[-1];
    if (!consp(v0165)) goto v0060;
    v0165 = stack[-1];
    v0165 = qcar(v0165);
    v0165 = (consp(v0165) ? nil : lisp_true);
    goto v0058;

v0058:
    if (v0165 == nil) goto v0084;
    v0249 = stack[-1];
    v0165 = (LispObject)17; // 1
    popv(4);
    return cons(v0249, v0165);

v0084:
    v0165 = stack[-1];
    v0165 = qcar(v0165);
    v0165 = qcar(v0165);
    stack[-2] = v0165;
    v0165 = stack[-2];
    v0249 = qcar(v0165);
    v0165 = elt(env, 2); // i
    if (!(v0249 == v0165)) goto v0035;
    v0249 = elt(env, 3); // (sqrt -1)
    v0165 = stack[-2];
    v0165 = qcdr(v0165);
    fn = elt(env, 6); // mksp
    v0165 = (*qfn2(fn))(qenv(fn), v0249, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0226;
    env = stack[-3];
    stack[-2] = v0165;
    goto v0035;

v0035:
    v0165 = stack[-2];
    v0249 = qcar(v0165);
    v0165 = elt(env, 4); // sqrt
    if (!consp(v0249)) goto v0130;
    v0249 = qcar(v0249);
    if (!(v0249 == v0165)) goto v0130;
    v0165 = stack[-2];
    v0165 = qcdr(v0165);
    v0165 = Lonep(nil, v0165);
    env = stack[-3];
    v0165 = (v0165 == nil ? lisp_true : nil);
    goto v0111;

v0111:
    if (v0165 == nil) goto v0190;
    v0165 = stack[-2];
    v0249 = qcdr(v0165);
    v0165 = (LispObject)33; // 2
    v0165 = Ldivide(nil, v0249, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0226;
    env = stack[-3];
    stack[0] = v0165;
    v0165 = stack[-2];
    v0165 = qcar(v0165);
    v0165 = qcdr(v0165);
    v0165 = qcar(v0165);
    fn = elt(env, 7); // simp
    v0249 = (*qfn1(fn))(qenv(fn), v0165);
    nil = C_nil;
    if (exception_pending()) goto v0226;
    env = stack[-3];
    v0165 = stack[0];
    v0165 = qcar(v0165);
    fn = elt(env, 8); // exptsq
    v0165 = (*qfn2(fn))(qenv(fn), v0249, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0226;
    env = stack[-3];
    v0189 = v0165;
    v0165 = stack[0];
    v0249 = qcdr(v0165);
    v0165 = (LispObject)1; // 0
    if (v0249 == v0165) goto v0008;
    stack[0] = v0189;
    v0165 = stack[-2];
    v0249 = qcar(v0165);
    v0165 = (LispObject)17; // 1
    fn = elt(env, 6); // mksp
    v0249 = (*qfn2(fn))(qenv(fn), v0249, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0226;
    env = stack[-3];
    v0165 = (LispObject)17; // 1
    v0189 = cons(v0249, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0226;
    env = stack[-3];
    v0249 = qvalue(elt(env, 5)); // nil
    v0165 = (LispObject)17; // 1
    v0165 = acons(v0189, v0249, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0226;
    env = stack[-3];
    fn = elt(env, 9); // multsq
    v0165 = (*qfn2(fn))(qenv(fn), stack[0], v0165);
    nil = C_nil;
    if (exception_pending()) goto v0226;
    env = stack[-3];
    v0189 = v0165;
    goto v0008;

v0008:
    v0165 = v0189;
    fn = elt(env, 10); // tidysqrt
    v0165 = (*qfn1(fn))(qenv(fn), v0165);
    nil = C_nil;
    if (exception_pending()) goto v0226;
    env = stack[-3];
    v0189 = v0165;
    goto v0056;

v0056:
    stack[0] = v0189;
    v0165 = stack[-1];
    v0165 = qcar(v0165);
    v0165 = qcdr(v0165);
    v0165 = CC_tidysqrtf(env, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0226;
    env = stack[-3];
    fn = elt(env, 9); // multsq
    v0165 = (*qfn2(fn))(qenv(fn), stack[0], v0165);
    nil = C_nil;
    if (exception_pending()) goto v0226;
    env = stack[-3];
    stack[-2] = v0165;
    stack[0] = stack[-2];
    v0165 = stack[-1];
    v0165 = qcdr(v0165);
    v0165 = CC_tidysqrtf(env, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0226;
    env = stack[-3];
    {
        LispObject v0021 = stack[0];
        popv(4);
        fn = elt(env, 11); // addsq
        return (*qfn2(fn))(qenv(fn), v0021, v0165);
    }

v0190:
    v0249 = stack[-2];
    v0165 = (LispObject)17; // 1
    v0189 = cons(v0249, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0226;
    env = stack[-3];
    v0249 = qvalue(elt(env, 5)); // nil
    v0165 = (LispObject)17; // 1
    v0165 = acons(v0189, v0249, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0226;
    env = stack[-3];
    v0189 = v0165;
    goto v0056;

v0130:
    v0165 = qvalue(elt(env, 5)); // nil
    goto v0111;

v0060:
    v0165 = qvalue(elt(env, 1)); // t
    goto v0058;
// error exit handlers
v0226:
    popv(4);
    return nil;
}



// Code for df_ext

static LispObject CC_df_ext(LispObject env,
                         LispObject v0003, LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0135, v0139;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for df_ext");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0002,v0003);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0003,v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0135 = v0002;
    stack[0] = v0003;
// end of prologue
    v0139 = elt(env, 1); // svf_ext
    v0135 = qcdr(v0135);
    v0135 = qcar(v0135);
    fn = elt(env, 2); // mkid
    v0139 = (*qfn2(fn))(qenv(fn), v0139, v0135);
    nil = C_nil;
    if (exception_pending()) goto v0203;
    env = stack[-1];
    v0135 = stack[0];
    v0135 = list2(v0139, v0135);
    nil = C_nil;
    if (exception_pending()) goto v0203;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 3); // aeval
        return (*qfn1(fn))(qenv(fn), v0135);
    }
// error exit handlers
v0203:
    popv(2);
    return nil;
}



// Code for ofsf_smmkatl!-and

static LispObject CC_ofsf_smmkatlKand(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0221, v0030, v0250;
    LispObject fn;
    LispObject v0004, v0002, v0003;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "ofsf_smmkatl-and");
    va_start(aa, nargs);
    v0003 = va_arg(aa, LispObject);
    v0002 = va_arg(aa, LispObject);
    v0004 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_smmkatl-and");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0004,v0002,v0003);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0003,v0002,v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    stack[-3] = v0004;
    v0221 = v0002;
    stack[-4] = v0003;
// end of prologue
    v0030 = qvalue(elt(env, 1)); // !*rlsipw
    if (v0030 == nil) goto v0113;
    v0030 = qvalue(elt(env, 3)); // nil
    goto v0168;

v0168:
    if (v0030 == nil) goto v0060;
    v0250 = elt(env, 4); // and
    v0030 = v0221;
    v0221 = stack[-3];
    {
        popv(7);
        fn = elt(env, 5); // ofsf_irl2atl
        return (*qfnn(fn))(qenv(fn), 3, v0250, v0030, v0221);
    }

v0060:
    stack[-5] = v0221;
    goto v0145;

v0145:
    v0221 = stack[-5];
    if (v0221 == nil) goto v0164;
    v0221 = stack[-5];
    v0221 = qcar(v0221);
    v0030 = v0221;
    v0250 = qcar(v0030);
    v0030 = stack[-4];
    v0030 = Latsoc(nil, v0250, v0030);
    v0250 = v0030;
    v0030 = v0250;
    if (v0030 == nil) goto v0080;
    v0030 = v0221;
    v0221 = stack[-3];
    fn = elt(env, 6); // ofsf_smmkatl!-and1
    v0221 = (*qfnn(fn))(qenv(fn), 3, v0250, v0030, v0221);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-6];
    goto v0091;

v0091:
    stack[-2] = v0221;
    v0221 = stack[-2];
    fn = elt(env, 7); // lastpair
    v0221 = (*qfn1(fn))(qenv(fn), v0221);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-6];
    stack[-1] = v0221;
    v0221 = stack[-5];
    v0221 = qcdr(v0221);
    stack[-5] = v0221;
    v0221 = stack[-1];
    if (!consp(v0221)) goto v0145;
    else goto v0081;

v0081:
    v0221 = stack[-5];
    if (v0221 == nil) { LispObject res = stack[-2]; popv(7); return onevalue(res); }
    stack[0] = stack[-1];
    v0221 = stack[-5];
    v0221 = qcar(v0221);
    v0030 = v0221;
    v0250 = qcar(v0030);
    v0030 = stack[-4];
    v0030 = Latsoc(nil, v0250, v0030);
    v0250 = v0030;
    v0030 = v0250;
    if (v0030 == nil) goto v0251;
    v0030 = v0221;
    v0221 = stack[-3];
    fn = elt(env, 6); // ofsf_smmkatl!-and1
    v0221 = (*qfnn(fn))(qenv(fn), 3, v0250, v0030, v0221);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-6];
    goto v0008;

v0008:
    v0221 = Lrplacd(nil, stack[0], v0221);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-6];
    v0221 = stack[-1];
    fn = elt(env, 7); // lastpair
    v0221 = (*qfn1(fn))(qenv(fn), v0221);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-6];
    stack[-1] = v0221;
    v0221 = stack[-5];
    v0221 = qcdr(v0221);
    stack[-5] = v0221;
    goto v0081;

v0251:
    v0250 = elt(env, 4); // and
    v0030 = v0221;
    v0221 = stack[-3];
    fn = elt(env, 8); // ofsf_ir2atl
    v0221 = (*qfnn(fn))(qenv(fn), 3, v0250, v0030, v0221);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-6];
    goto v0008;

v0080:
    v0030 = elt(env, 4); // and
    v0250 = v0221;
    v0221 = stack[-3];
    fn = elt(env, 8); // ofsf_ir2atl
    v0221 = (*qfnn(fn))(qenv(fn), 3, v0030, v0250, v0221);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-6];
    goto v0091;

v0164:
    v0221 = qvalue(elt(env, 3)); // nil
    { popv(7); return onevalue(v0221); }

v0113:
    v0030 = qvalue(elt(env, 2)); // !*rlsipo
    goto v0168;
// error exit handlers
v0190:
    popv(7);
    return nil;
}



// Code for eval!-yetunknowntypeexpr

static LispObject CC_evalKyetunknowntypeexpr(LispObject env,
                         LispObject v0003, LispObject v0002)
{
    LispObject nil = C_nil;
    LispObject v0214, v0122;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for eval-yetunknowntypeexpr");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0002,v0003);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0003,v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    stack[-4] = v0002;
    stack[0] = v0003;
// end of prologue

v0252:
    v0214 = stack[0];
    if (!consp(v0214)) goto v0031;
    v0214 = stack[0];
    v0122 = qcar(v0214);
    v0214 = elt(env, 1); // !*sq
    if (v0122 == v0214) goto v0047;
    v0214 = stack[0];
    v0214 = qcar(v0214);
    if (!symbolp(v0214)) v0214 = nil;
    else { v0214 = qfastgets(v0214);
           if (v0214 != nil) { v0214 = elt(v0214, 8); // dname
#ifdef RECORD_GET
             if (v0214 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v0214 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v0214 == SPID_NOPROP) v0214 = nil; }}
#endif
    if (!(v0214 == nil)) goto v0040;
    v0214 = stack[0];
    v0122 = qcar(v0214);
    v0214 = elt(env, 3); // !:dn!:
    v0214 = (v0122 == v0214 ? lisp_true : nil);
    goto v0040;

v0040:
    if (!(v0214 == nil)) { LispObject res = stack[0]; popv(7); return onevalue(res); }
    v0214 = stack[0];
    v0214 = qcar(v0214);
    if (!symbolp(v0214)) v0214 = nil;
    else { v0214 = qfastgets(v0214);
           if (v0214 != nil) { v0214 = elt(v0214, 45); // psopfn
#ifdef RECORD_GET
             if (v0214 != SPID_NOPROP)
                record_get(elt(fastget_names, 45), 1);
             else record_get(elt(fastget_names, 45), 0),
                v0214 = nil; }
           else record_get(elt(fastget_names, 45), 0); }
#else
             if (v0214 == SPID_NOPROP) v0214 = nil; }}
#endif
    stack[-1] = v0214;
    v0214 = stack[-1];
    if (v0214 == nil) goto v0141;
    v0214 = stack[0];
    fn = elt(env, 6); // getrtype
    v0122 = (*qfn1(fn))(qenv(fn), v0214);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-6];
    v0214 = elt(env, 4); // yetunknowntype
    if (!(v0122 == v0214)) goto v0141;
    v0122 = stack[-1];
    v0214 = stack[0];
    v0214 = qcdr(v0214);
        popv(7);
        return Lapply1(nil, v0122, v0214);

v0141:
    v0214 = stack[0];
    stack[-5] = qcar(v0214);
    v0214 = stack[0];
    v0214 = qcdr(v0214);
    stack[-3] = v0214;
    v0214 = stack[-3];
    if (v0214 == nil) goto v0097;
    v0214 = stack[-3];
    v0214 = qcar(v0214);
    v0122 = v0214;
    v0214 = stack[-4];
    v0214 = CC_evalKyetunknowntypeexpr(env, v0122, v0214);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-6];
    v0214 = ncons(v0214);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-6];
    stack[-1] = v0214;
    stack[-2] = v0214;
    goto v0100;

v0100:
    v0214 = stack[-3];
    v0214 = qcdr(v0214);
    stack[-3] = v0214;
    v0214 = stack[-3];
    if (v0214 == nil) goto v0160;
    stack[0] = stack[-1];
    v0214 = stack[-3];
    v0214 = qcar(v0214);
    v0122 = v0214;
    v0214 = stack[-4];
    v0214 = CC_evalKyetunknowntypeexpr(env, v0122, v0214);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-6];
    v0214 = ncons(v0214);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-6];
    v0214 = Lrplacd(nil, stack[0], v0214);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-6];
    v0214 = stack[-1];
    v0214 = qcdr(v0214);
    stack[-1] = v0214;
    goto v0100;

v0160:
    v0214 = stack[-2];
    goto v0173;

v0173:
    {
        LispObject v0063 = stack[-5];
        popv(7);
        return cons(v0063, v0214);
    }

v0097:
    v0214 = qvalue(elt(env, 5)); // nil
    goto v0173;

v0047:
    v0214 = qvalue(elt(env, 2)); // t
    goto v0040;

v0031:
    v0214 = stack[0];
    if (!symbolp(v0214)) v0214 = nil;
    else { v0214 = qfastgets(v0214);
           if (v0214 != nil) { v0214 = elt(v0214, 4); // avalue
#ifdef RECORD_GET
             if (v0214 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v0214 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v0214 == SPID_NOPROP) v0214 = nil; }}
#endif
    v0122 = v0214;
    v0214 = v0122;
    if (v0214 == nil) { LispObject res = stack[0]; popv(7); return onevalue(res); }
    v0214 = v0122;
    v0214 = qcdr(v0214);
    v0122 = qcar(v0214);
    v0214 = stack[-4];
    stack[0] = v0122;
    stack[-4] = v0214;
    goto v0252;
// error exit handlers
v0027:
    popv(7);
    return nil;
}



setup_type const u47_setup[] =
{
    {"xadd*",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_xaddH},
    {"get*order",               CC_getHorder,   too_many_1,    wrong_no_1},
    {"qqe_length-graph-neighbors",CC_qqe_lengthKgraphKneighbors,too_many_1,wrong_no_1},
    {"pasf_negateat",           CC_pasf_negateat,too_many_1,   wrong_no_1},
    {"ldf-deg",                 too_few_2,      CC_ldfKdeg,    wrong_no_2},
    {"sprow_dim",               CC_sprow_dim,   too_many_1,    wrong_no_1},
    {"groebreduceonestepint",   wrong_no_na,    wrong_no_nb,   (n_args *)CC_groebreduceonestepint},
    {"mkunarywedge",            CC_mkunarywedge,too_many_1,    wrong_no_1},
    {"positive-powp",           CC_positiveKpowp,too_many_1,   wrong_no_1},
    {"df-chain-rule",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_dfKchainKrule},
    {"pst_d1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_pst_d1},
    {"general-difference-mod-p",too_few_2,      CC_generalKdifferenceKmodKp,wrong_no_2},
    {"merge_lists",             too_few_2,      CC_merge_lists,wrong_no_2},
    {"constructinvolutivebasis",too_few_2,      CC_constructinvolutivebasis,wrong_no_2},
    {"ofsf_canegrel",           too_few_2,      CC_ofsf_canegrel,wrong_no_2},
    {"taymindegreel",           too_few_2,      CC_taymindegreel,wrong_no_2},
    {"qqe_length-graph-marked", CC_qqe_lengthKgraphKmarked,too_many_1,wrong_no_1},
    {"pasf_smordtable2",        too_few_2,      CC_pasf_smordtable2,wrong_no_2},
    {"sfto_kexp",               too_few_2,      CC_sfto_kexp,  wrong_no_2},
    {"ldf-sep-var",             CC_ldfKsepKvar, too_many_1,    wrong_no_1},
    {"groebmakepair",           too_few_2,      CC_groebmakepair,wrong_no_2},
    {"make_wedge_pair",         too_few_2,      CC_make_wedge_pair,wrong_no_2},
    {"gbftimes",                too_few_2,      CC_gbftimes,   wrong_no_2},
    {"gpexpp",                  CC_gpexpp,      too_many_1,    wrong_no_1},
    {"chksymmetries&sub1",      wrong_no_na,    wrong_no_nb,   (n_args *)CC_chksymmetriesGsub1},
    {"cde_alglistp",            CC_cde_alglistp,too_many_1,    wrong_no_1},
    {"qroundup",                too_few_2,      CC_qroundup,   wrong_no_2},
    {"even_action_pow",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_even_action_pow},
    {"ofsf_smwrmknowl",         too_few_2,      CC_ofsf_smwrmknowl,wrong_no_2},
    {"*multsq",                 too_few_2,      CC_Hmultsq,    wrong_no_2},
    {"cl_susimkatl",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_cl_susimkatl},
    {"dipreplus",               CC_dipreplus,   too_many_1,    wrong_no_1},
    {"latexprint",              CC_latexprint,  too_many_1,    wrong_no_1},
    {"decimal2internal",        too_few_2,      CC_decimal2internal,wrong_no_2},
    {"tidysqrtf",               CC_tidysqrtf,   too_many_1,    wrong_no_1},
    {"df_ext",                  too_few_2,      CC_df_ext,     wrong_no_2},
    {"ofsf_smmkatl-and",        wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_smmkatlKand},
    {"eval-yetunknowntypeexpr", too_few_2,      CC_evalKyetunknowntypeexpr,wrong_no_2},
    {NULL, (one_args *)"u47", (two_args *)"13898 1088215 4747333", 0}
};

// end of generated code
