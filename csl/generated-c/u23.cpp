
// $destdir/u23.c        Machine generated C code

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



// Code for poly!-multfnc

static LispObject CC_polyKmultfnc(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0039, v0040, v0041;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for poly-multfnc");
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
    v0039 = stack[-2];
    v0039 = qcar(v0039);
    stack[0] = qcdr(v0039);
    v0039 = stack[-1];
    v0039 = qcar(v0039);
    v0039 = ncons(v0039);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-4];
    fn = elt(env, 4); // poly!-multf
    v0039 = (*qfn2(fn))(qenv(fn), stack[0], v0039);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-4];
    stack[-3] = v0039;
    v0039 = stack[-3];
    if (v0039 == nil) goto v0043;
    v0039 = stack[-3];
    if (!consp(v0039)) goto v0044;
    v0039 = stack[-3];
    v0039 = qcar(v0039);
    v0039 = (consp(v0039) ? nil : lisp_true);
    goto v0045;

v0045:
    if (v0039 == nil) goto v0046;
    v0039 = qvalue(elt(env, 1)); // nil
    goto v0047;

v0047:
    if (v0039 == nil) goto v0048;
    v0039 = stack[-2];
    v0039 = qcar(v0039);
    v0039 = qcar(v0039);
    stack[0] = qcar(v0039);
    v0039 = stack[-2];
    v0039 = qcar(v0039);
    v0039 = qcar(v0039);
    v0040 = qcdr(v0039);
    v0039 = stack[-3];
    v0039 = qcar(v0039);
    v0039 = qcar(v0039);
    v0039 = qcdr(v0039);
    v0039 = plus2(v0040, v0039);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-4];
    fn = elt(env, 5); // mkspm
    v0039 = (*qfn2(fn))(qenv(fn), stack[0], v0039);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-4];
    v0041 = v0039;
    if (v0039 == nil) goto v0049;
    v0040 = v0041;
    v0039 = (LispObject)17; // 1
    if (v0040 == v0039) goto v0050;
    v0040 = v0041;
    v0039 = stack[-3];
    v0039 = qcar(v0039);
    v0039 = qcdr(v0039);
    v0039 = cons(v0040, v0039);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-4];
    v0039 = ncons(v0039);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-4];
    stack[0] = v0039;
    goto v0051;

v0051:
    v0039 = stack[-2];
    v0039 = qcar(v0039);
    v0040 = qcar(v0039);
    v0039 = (LispObject)17; // 1
    v0039 = cons(v0040, v0039);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-4];
    v0040 = ncons(v0039);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-4];
    v0039 = stack[-3];
    v0039 = qcdr(v0039);
    fn = elt(env, 4); // poly!-multf
    v0039 = (*qfn2(fn))(qenv(fn), v0040, v0039);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-4];
    fn = elt(env, 6); // addf
    v0039 = (*qfn2(fn))(qenv(fn), stack[0], v0039);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-4];
    stack[-3] = v0039;
    goto v0043;

v0043:
    v0039 = stack[-2];
    v0040 = qcdr(v0039);
    v0039 = stack[-1];
    fn = elt(env, 4); // poly!-multf
    stack[0] = (*qfn2(fn))(qenv(fn), v0040, v0039);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-4];
    v0039 = stack[-2];
    v0039 = qcar(v0039);
    v0040 = ncons(v0039);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-4];
    v0039 = stack[-1];
    v0039 = qcdr(v0039);
    fn = elt(env, 4); // poly!-multf
    v0039 = (*qfn2(fn))(qenv(fn), v0040, v0039);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-4];
    fn = elt(env, 6); // addf
    v0039 = (*qfn2(fn))(qenv(fn), stack[0], v0039);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-4];
    {
        LispObject v0052 = stack[-3];
        popv(5);
        fn = elt(env, 6); // addf
        return (*qfn2(fn))(qenv(fn), v0052, v0039);
    }

v0050:
    v0039 = stack[-3];
    v0039 = qcar(v0039);
    v0039 = qcdr(v0039);
    stack[0] = v0039;
    goto v0051;

v0049:
    v0039 = qvalue(elt(env, 1)); // nil
    stack[0] = v0039;
    goto v0051;

v0048:
    v0039 = stack[-2];
    v0039 = qcar(v0039);
    v0039 = qcar(v0039);
    v0039 = qcar(v0039);
    fn = elt(env, 7); // noncomp
    v0039 = (*qfn1(fn))(qenv(fn), v0039);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-4];
    if (v0039 == nil) goto v0053;
    v0039 = stack[-2];
    v0039 = qcar(v0039);
    v0040 = qcar(v0039);
    v0039 = stack[-3];
    v0039 = cons(v0040, v0039);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-4];
    v0039 = ncons(v0039);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-4];
    stack[-3] = v0039;
    goto v0043;

v0053:
    v0039 = qvalue(elt(env, 2)); // t
    stack[0] = qvalue(elt(env, 3)); // !*!*processed
    qvalue(elt(env, 3)) = v0039; // !*!*processed
    v0039 = stack[-2];
    v0039 = qcar(v0039);
    v0040 = qcar(v0039);
    v0039 = (LispObject)17; // 1
    v0039 = cons(v0040, v0039);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-4];
    v0040 = ncons(v0039);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-4];
    v0039 = stack[-3];
    fn = elt(env, 4); // poly!-multf
    v0039 = (*qfn2(fn))(qenv(fn), v0040, v0039);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-4];
    stack[-3] = v0039;
    qvalue(elt(env, 3)) = stack[0]; // !*!*processed
    goto v0043;

v0046:
    v0039 = stack[-3];
    v0039 = qcar(v0039);
    v0039 = qcar(v0039);
    v0040 = qcar(v0039);
    v0039 = stack[-2];
    v0039 = qcar(v0039);
    v0039 = qcar(v0039);
    v0039 = qcar(v0039);
    v0039 = (v0040 == v0039 ? lisp_true : nil);
    goto v0047;

v0044:
    v0039 = qvalue(elt(env, 2)); // t
    goto v0045;
// error exit handlers
v0054:
    env = stack[-4];
    qvalue(elt(env, 3)) = stack[0]; // !*!*processed
    popv(5);
    return nil;
v0042:
    popv(5);
    return nil;
}



// Code for pasf_sacat

static LispObject CC_pasf_sacat(LispObject env, int nargs, ...)
{
    LispObject v0055, v0056, v0057;
    LispObject v0058, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "pasf_sacat");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0058 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pasf_sacat");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0055 = v0058;
    v0056 = v0001;
    v0057 = v0000;
// end of prologue
    v0055 = qvalue(elt(env, 1)); // nil
    return onevalue(v0055);
}



// Code for unaryrd

static LispObject CC_unaryrd(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0059;
    LispObject fn;
    argcheck(nargs, 0, "unaryrd");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for unaryrd");
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
    v0059 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-1];
    stack[0] = v0059;
    fn = elt(env, 2); // lex
    v0059 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    v0059 = stack[0];
    popv(2);
    return ncons(v0059);
// error exit handlers
v0060:
    popv(2);
    return nil;
}



// Code for my_letmtr

static LispObject CC_my_letmtr(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0017, v0053, v0081;
    LispObject fn;
    LispObject v0058, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "my_letmtr");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0058 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for my_letmtr");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0058,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0058);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
// copy arguments values to proper place
    stack[-3] = v0058;
    stack[-4] = v0001;
    stack[-5] = v0000;
// end of prologue
    stack[-2] = nil;
    v0053 = stack[-3];
    v0017 = elt(env, 1); // mat
    if (!consp(v0053)) goto v0082;
    v0053 = qcar(v0053);
    if (!(v0053 == v0017)) goto v0082;
    v0017 = stack[-5];
    v0017 = qcdr(v0017);
    stack[-6] = v0017;
    v0017 = stack[-6];
    if (v0017 == nil) goto v0083;
    v0017 = stack[-6];
    v0017 = qcar(v0017);
    v0053 = v0017;
    v0017 = v0053;
    v0017 = integerp(v0017);
    if (v0017 == nil) goto v0084;
    v0017 = v0053;
    goto v0049;

v0049:
    v0017 = ncons(v0017);
    nil = C_nil;
    if (exception_pending()) goto v0085;
    env = stack[-7];
    stack[-1] = v0017;
    stack[-2] = v0017;
    goto v0086;

v0086:
    v0017 = stack[-6];
    v0017 = qcdr(v0017);
    stack[-6] = v0017;
    v0017 = stack[-6];
    if (v0017 == nil) goto v0087;
    stack[0] = stack[-1];
    v0017 = stack[-6];
    v0017 = qcar(v0017);
    v0053 = v0017;
    v0017 = v0053;
    v0017 = integerp(v0017);
    if (v0017 == nil) goto v0088;
    v0017 = v0053;
    goto v0089;

v0089:
    v0017 = ncons(v0017);
    nil = C_nil;
    if (exception_pending()) goto v0085;
    env = stack[-7];
    v0017 = Lrplacd(nil, stack[0], v0017);
    nil = C_nil;
    if (exception_pending()) goto v0085;
    env = stack[-7];
    v0017 = stack[-1];
    v0017 = qcdr(v0017);
    stack[-1] = v0017;
    goto v0086;

v0088:
    v0017 = v0053;
    fn = elt(env, 8); // reval
    v0017 = (*qfn1(fn))(qenv(fn), v0017);
    nil = C_nil;
    if (exception_pending()) goto v0085;
    env = stack[-7];
    goto v0089;

v0087:
    v0017 = stack[-2];
    goto v0090;

v0090:
    stack[-2] = v0017;
    fn = elt(env, 9); // numlis
    v0017 = (*qfn1(fn))(qenv(fn), v0017);
    nil = C_nil;
    if (exception_pending()) goto v0085;
    env = stack[-7];
    if (v0017 == nil) goto v0091;
    v0017 = stack[-2];
    v0053 = Llength(nil, v0017);
    nil = C_nil;
    if (exception_pending()) goto v0085;
    env = stack[-7];
    v0017 = (LispObject)33; // 2
    v0017 = Lneq(nil, v0053, v0017);
    nil = C_nil;
    if (exception_pending()) goto v0085;
    env = stack[-7];
    goto v0092;

v0092:
    if (v0017 == nil) goto v0093;
    v0053 = stack[-5];
    v0017 = elt(env, 7); // hold
    {
        popv(8);
        fn = elt(env, 10); // errpri2
        return (*qfn2(fn))(qenv(fn), v0053, v0017);
    }

v0093:
    v0017 = stack[-3];
    v0053 = qcdr(v0017);
    v0017 = stack[-2];
    v0017 = qcar(v0017);
    fn = elt(env, 11); // nth
    v0053 = (*qfn2(fn))(qenv(fn), v0053, v0017);
    nil = C_nil;
    if (exception_pending()) goto v0085;
    env = stack[-7];
    v0017 = stack[-2];
    v0017 = qcdr(v0017);
    v0017 = qcar(v0017);
    fn = elt(env, 12); // pnth
    v0053 = (*qfn2(fn))(qenv(fn), v0053, v0017);
    nil = C_nil;
    if (exception_pending()) goto v0085;
    env = stack[-7];
    v0017 = stack[-4];
    v0017 = Lrplaca(nil, v0053, v0017);
    nil = C_nil;
    if (exception_pending()) goto v0085;
    v0017 = nil;
    { popv(8); return onevalue(v0017); }

v0091:
    v0017 = qvalue(elt(env, 6)); // t
    goto v0092;

v0084:
    v0017 = v0053;
    fn = elt(env, 8); // reval
    v0017 = (*qfn1(fn))(qenv(fn), v0017);
    nil = C_nil;
    if (exception_pending()) goto v0085;
    env = stack[-7];
    goto v0049;

v0083:
    v0017 = qvalue(elt(env, 5)); // nil
    goto v0090;

v0082:
    stack[-1] = elt(env, 2); // matrix
    stack[0] = (LispObject)161; // 10
    v0081 = elt(env, 3); // "Matrix"
    v0017 = stack[-5];
    v0053 = qcar(v0017);
    v0017 = elt(env, 4); // "not set"
    v0017 = list3(v0081, v0053, v0017);
    nil = C_nil;
    if (exception_pending()) goto v0085;
    env = stack[-7];
    fn = elt(env, 13); // rerror
    v0017 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v0017);
    nil = C_nil;
    if (exception_pending()) goto v0085;
    env = stack[-7];
    goto v0093;
// error exit handlers
v0085:
    popv(8);
    return nil;
}



// Code for numlist_ordp

static LispObject CC_numlist_ordp(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0097, v0037, v0038;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for numlist_ordp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0097 = v0001;
    v0037 = v0000;
// end of prologue
    v0038 = v0037;
    v0037 = v0097;
    v0097 = elt(env, 1); // lambda_u9iz36vfudu4
    {
        fn = elt(env, 2); // cons_ordp
        return (*qfnn(fn))(qenv(fn), 3, v0038, v0037, v0097);
    }
}



// Code for lambda_u9iz36vfudu4

static LispObject CC_lambda_u9iz36vfudu4(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0094, v0095;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lambda_u9iz36vfudu4");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0094 = v0001;
    v0095 = v0000;
// end of prologue
        return Lleq(nil, v0095, v0094);
}



// Code for subf

static LispObject CC_subf(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0114, v0008;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for subf");
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
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-6] = v0001;
    stack[-7] = v0000;
// end of prologue
    stack[-8] = qvalue(elt(env, 1)); // alglist!*
    qvalue(elt(env, 1)) = nil; // alglist!*
    stack[-5] = nil;
    stack[-4] = nil;
    v0114 = qvalue(elt(env, 2)); // nil
    v0114 = ncons(v0114);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-9];
    qvalue(elt(env, 1)) = v0114; // alglist!*
    v0114 = stack[-7];
    if (!consp(v0114)) goto v0080;
    v0114 = stack[-7];
    v0114 = qcar(v0114);
    v0114 = (consp(v0114) ? nil : lisp_true);
    goto v0038;

v0038:
    if (v0114 == nil) goto v0097;
    v0114 = stack[-7];
    fn = elt(env, 7); // !*d2q
    v0114 = (*qfn1(fn))(qenv(fn), v0114);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-9];
    goto v0059;

v0059:
    qvalue(elt(env, 1)) = stack[-8]; // alglist!*
    { popv(10); return onevalue(v0114); }

v0097:
    v0114 = qvalue(elt(env, 4)); // ncmp!*
    if (v0114 == nil) goto v0091;
    v0114 = stack[-7];
    fn = elt(env, 8); // noncomexpf
    v0114 = (*qfn1(fn))(qenv(fn), v0114);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-9];
    if (v0114 == nil) goto v0091;
    v0008 = stack[-7];
    v0114 = stack[-6];
    fn = elt(env, 9); // subf1
    v0114 = (*qfn2(fn))(qenv(fn), v0008, v0114);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-9];
    goto v0059;

v0091:
    v0114 = stack[-6];
    stack[-3] = v0114;
    v0114 = stack[-3];
    if (v0114 == nil) goto v0116;
    v0114 = stack[-3];
    v0114 = qcar(v0114);
    v0114 = qcar(v0114);
    v0114 = ncons(v0114);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-9];
    stack[-1] = v0114;
    stack[-2] = v0114;
    goto v0117;

v0117:
    v0114 = stack[-3];
    v0114 = qcdr(v0114);
    stack[-3] = v0114;
    v0114 = stack[-3];
    if (v0114 == nil) goto v0084;
    stack[0] = stack[-1];
    v0114 = stack[-3];
    v0114 = qcar(v0114);
    v0114 = qcar(v0114);
    v0114 = ncons(v0114);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-9];
    v0114 = Lrplacd(nil, stack[0], v0114);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-9];
    v0114 = stack[-1];
    v0114 = qcdr(v0114);
    stack[-1] = v0114;
    goto v0117;

v0084:
    v0114 = stack[-2];
    stack[0] = v0114;
    goto v0118;

v0118:
    v0008 = stack[-7];
    v0114 = qvalue(elt(env, 2)); // nil
    fn = elt(env, 10); // kernord
    v0114 = (*qfn2(fn))(qenv(fn), v0008, v0114);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-9];
    fn = elt(env, 11); // intersection
    v0114 = (*qfn2(fn))(qenv(fn), stack[0], v0114);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-9];
    v0114 = Lreverse(nil, v0114);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-9];
    stack[0] = v0114;
    v0114 = stack[0];
    fn = elt(env, 12); // setkorder
    v0114 = (*qfn1(fn))(qenv(fn), v0114);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-9];
    stack[0] = v0114;
    v0114 = stack[-7];
    fn = elt(env, 13); // reorder
    v0008 = (*qfn1(fn))(qenv(fn), v0114);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-9];
    v0114 = stack[-6];
    fn = elt(env, 9); // subf1
    v0114 = (*qfn2(fn))(qenv(fn), v0008, v0114);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-9];
    stack[-7] = v0114;
    goto v0119;

v0119:
    v0008 = stack[-7];
    v0114 = stack[-4];
    v0114 = Lmember(nil, v0008, v0114);
    if (v0114 == nil) goto v0023;
    v0114 = qvalue(elt(env, 2)); // nil
    goto v0019;

v0019:
    if (v0114 == nil) goto v0120;
    v0008 = stack[-7];
    v0114 = stack[-4];
    v0114 = cons(v0008, v0114);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-9];
    stack[-4] = v0114;
    v0114 = stack[-5];
    fn = elt(env, 14); // simp
    v0114 = (*qfn1(fn))(qenv(fn), v0114);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-9];
    stack[-7] = v0114;
    goto v0119;

v0120:
    v0114 = stack[0];
    fn = elt(env, 12); // setkorder
    v0114 = (*qfn1(fn))(qenv(fn), v0114);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-9];
    v0114 = stack[-7];
    v0114 = qcar(v0114);
    fn = elt(env, 13); // reorder
    stack[0] = (*qfn1(fn))(qenv(fn), v0114);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-9];
    v0114 = stack[-7];
    v0114 = qcdr(v0114);
    fn = elt(env, 13); // reorder
    v0114 = (*qfn1(fn))(qenv(fn), v0114);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-9];
    v0114 = cons(stack[0], v0114);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-9];
    goto v0059;

v0023:
    stack[-1] = elt(env, 5); // expt
    v0114 = stack[-7];
    v0114 = qcar(v0114);
    fn = elt(env, 15); // kernels
    v0114 = (*qfn1(fn))(qenv(fn), v0114);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-9];
    v0114 = Latsoc(nil, stack[-1], v0114);
    if (!(v0114 == nil)) goto v0013;
    stack[-1] = elt(env, 5); // expt
    v0114 = stack[-7];
    v0114 = qcdr(v0114);
    fn = elt(env, 15); // kernels
    v0114 = (*qfn1(fn))(qenv(fn), v0114);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-9];
    v0114 = Latsoc(nil, stack[-1], v0114);
    if (!(v0114 == nil)) goto v0013;
    v0114 = qvalue(elt(env, 2)); // nil
    goto v0019;

v0013:
    v0114 = stack[-7];
    fn = elt(env, 16); // prepsq
    v0008 = (*qfn1(fn))(qenv(fn), v0114);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-9];
    stack[-5] = v0008;
    v0114 = qvalue(elt(env, 6)); // varstack!*
    v0114 = Lmember(nil, v0008, v0114);
    v0114 = (v0114 == nil ? lisp_true : nil);
    goto v0019;

v0116:
    v0114 = qvalue(elt(env, 2)); // nil
    stack[0] = v0114;
    goto v0118;

v0080:
    v0114 = qvalue(elt(env, 3)); // t
    goto v0038;
// error exit handlers
v0115:
    env = stack[-9];
    qvalue(elt(env, 1)) = stack[-8]; // alglist!*
    popv(10);
    return nil;
}



// Code for riv_mk

static LispObject CC_riv_mk(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0097, v0037, v0038;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for riv_mk");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0097 = v0001;
    v0037 = v0000;
// end of prologue
    v0038 = elt(env, 1); // iv
    return list3(v0038, v0037, v0097);
}



// Code for lex_basic_token

static LispObject CC_lex_basic_token(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0210, v0211, v0212;
    LispObject fn;
    argcheck(nargs, 0, "lex_basic_token");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lex_basic_token");
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
    v0210 = qvalue(elt(env, 1)); // lex_peeked
    if (v0210 == nil) goto v0056;
    v0210 = qvalue(elt(env, 1)); // lex_peeked
    stack[-3] = v0210;
    v0210 = qvalue(elt(env, 2)); // lex_peeked_yylval
    qvalue(elt(env, 3)) = v0210; // yylval
    v0210 = qvalue(elt(env, 4)); // lex_peeked_escaped
    qvalue(elt(env, 5)) = v0210; // lex_escaped
    v0210 = qvalue(elt(env, 6)); // nil
    qvalue(elt(env, 4)) = v0210; // lex_peeked_escaped
    qvalue(elt(env, 2)) = v0210; // lex_peeked_yylval
    qvalue(elt(env, 1)) = v0210; // lex_peeked
    { LispObject res = stack[-3]; popv(5); return onevalue(res); }

v0056:
    v0210 = qvalue(elt(env, 6)); // nil
    qvalue(elt(env, 5)) = v0210; // lex_escaped
    goto v0033;

v0033:
    v0211 = qvalue(elt(env, 7)); // lex_char
    v0210 = elt(env, 8); // ! 
    if (v0211 == v0210) goto v0213;
    v0211 = qvalue(elt(env, 7)); // lex_char
    v0210 = qvalue(elt(env, 10)); // !$eol!$
    if (equal(v0211, v0210)) goto v0076;
    v0211 = qvalue(elt(env, 7)); // lex_char
    v0210 = elt(env, 11); // !%
    if (v0211 == v0210) goto v0084;
    v0210 = qvalue(elt(env, 6)); // nil
    goto v0214;

v0214:
    if (v0210 == nil) goto v0080;
    fn = elt(env, 37); // yyreadch
    v0210 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-4];
    goto v0033;

v0080:
    v0210 = qvalue(elt(env, 7)); // lex_char
    v0210 = Lalpha_char_p(nil, v0210);
    env = stack[-4];
    if (!(v0210 == nil)) goto v0065;
    v0211 = qvalue(elt(env, 7)); // lex_char
    v0210 = elt(env, 13); // !!
    if (v0211 == v0210) goto v0216;
    v0210 = qvalue(elt(env, 6)); // nil
    goto v0107;

v0107:
    if (!(v0210 == nil)) goto v0065;
    v0210 = qvalue(elt(env, 7)); // lex_char
    v0210 = Ldigitp(nil, v0210);
    env = stack[-4];
    if (v0210 == nil) goto v0217;
    v0210 = qvalue(elt(env, 7)); // lex_char
    v0210 = ncons(v0210);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-4];
    stack[-3] = v0210;
    goto v0218;

v0218:
    fn = elt(env, 37); // yyreadch
    v0210 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-4];
    v0210 = qvalue(elt(env, 7)); // lex_char
    v0210 = Ldigitp(nil, v0210);
    env = stack[-4];
    if (v0210 == nil) goto v0219;
    v0211 = qvalue(elt(env, 7)); // lex_char
    v0210 = stack[-3];
    v0210 = cons(v0211, v0210);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-4];
    stack[-3] = v0210;
    goto v0218;

v0219:
    v0211 = qvalue(elt(env, 7)); // lex_char
    v0210 = elt(env, 19); // !.
    if (!(v0211 == v0210)) goto v0220;
    v0210 = qvalue(elt(env, 9)); // t
    stack[-2] = v0210;
    v0211 = qvalue(elt(env, 7)); // lex_char
    v0210 = stack[-3];
    v0210 = cons(v0211, v0210);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-4];
    stack[-3] = v0210;
    goto v0221;

v0221:
    fn = elt(env, 37); // yyreadch
    v0210 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-4];
    v0210 = qvalue(elt(env, 7)); // lex_char
    v0210 = Ldigitp(nil, v0210);
    env = stack[-4];
    if (v0210 == nil) goto v0220;
    v0211 = qvalue(elt(env, 7)); // lex_char
    v0210 = stack[-3];
    v0210 = cons(v0211, v0210);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-4];
    stack[-3] = v0210;
    goto v0221;

v0220:
    v0211 = qvalue(elt(env, 7)); // lex_char
    v0210 = elt(env, 20); // e
    if (v0211 == v0210) goto v0222;
    v0211 = qvalue(elt(env, 7)); // lex_char
    v0210 = elt(env, 21); // !E
    v0210 = (v0211 == v0210 ? lisp_true : nil);
    goto v0223;

v0223:
    if (v0210 == nil) goto v0224;
    v0210 = stack[-2];
    if (!(v0210 == nil)) goto v0225;
    v0212 = elt(env, 22); // !0
    v0211 = elt(env, 19); // !.
    v0210 = stack[-3];
    v0210 = list2star(v0212, v0211, v0210);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-4];
    stack[-3] = v0210;
    goto v0225;

v0225:
    v0211 = elt(env, 20); // e
    v0210 = stack[-3];
    v0210 = cons(v0211, v0210);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-4];
    stack[-3] = v0210;
    fn = elt(env, 37); // yyreadch
    v0210 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-4];
    v0211 = qvalue(elt(env, 7)); // lex_char
    v0210 = elt(env, 23); // !+
    if (v0211 == v0210) goto v0226;
    v0211 = qvalue(elt(env, 7)); // lex_char
    v0210 = elt(env, 24); // !-
    v0210 = (v0211 == v0210 ? lisp_true : nil);
    goto v0227;

v0227:
    if (v0210 == nil) goto v0228;
    v0211 = qvalue(elt(env, 7)); // lex_char
    v0210 = stack[-3];
    v0210 = cons(v0211, v0210);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-4];
    stack[-3] = v0210;
    fn = elt(env, 37); // yyreadch
    v0210 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-4];
    goto v0228;

v0228:
    v0210 = qvalue(elt(env, 7)); // lex_char
    v0210 = Ldigitp(nil, v0210);
    env = stack[-4];
    if (v0210 == nil) goto v0229;
    v0211 = qvalue(elt(env, 7)); // lex_char
    v0210 = stack[-3];
    v0210 = cons(v0211, v0210);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-4];
    stack[-3] = v0210;
    goto v0230;

v0230:
    fn = elt(env, 37); // yyreadch
    v0210 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-4];
    v0210 = qvalue(elt(env, 7)); // lex_char
    v0210 = Ldigitp(nil, v0210);
    env = stack[-4];
    if (v0210 == nil) goto v0224;
    v0211 = qvalue(elt(env, 7)); // lex_char
    v0210 = stack[-3];
    v0210 = cons(v0211, v0210);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-4];
    stack[-3] = v0210;
    goto v0230;

v0224:
    v0210 = stack[-3];
    v0210 = Lnreverse(nil, v0210);
    env = stack[-4];
    v0210 = Lcompress(nil, v0210);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-4];
    qvalue(elt(env, 3)) = v0210; // yylval
    v0210 = qvalue(elt(env, 25)); // lex_number_code
    { popv(5); return onevalue(v0210); }

v0229:
    v0211 = elt(env, 22); // !0
    v0210 = stack[-3];
    v0210 = cons(v0211, v0210);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-4];
    stack[-3] = v0210;
    goto v0224;

v0226:
    v0210 = qvalue(elt(env, 9)); // t
    goto v0227;

v0222:
    v0210 = qvalue(elt(env, 9)); // t
    goto v0223;

v0217:
    v0211 = qvalue(elt(env, 7)); // lex_char
    v0210 = elt(env, 26); // !"
    if (v0211 == v0210) goto v0231;
    v0211 = qvalue(elt(env, 7)); // lex_char
    v0210 = elt(env, 28); // !'
    if (v0211 == v0210) goto v0232;
    v0211 = qvalue(elt(env, 7)); // lex_char
    v0210 = elt(env, 31); // !`
    if (v0211 == v0210) goto v0233;
    v0210 = qvalue(elt(env, 7)); // lex_char
    qvalue(elt(env, 3)) = v0210; // yylval
    v0211 = qvalue(elt(env, 3)); // yylval
    v0210 = qvalue(elt(env, 12)); // !$eof!$
    if (equal(v0211, v0210)) goto v0234;
    v0211 = qvalue(elt(env, 3)); // yylval
    v0210 = elt(env, 34); // !#
    if (v0211 == v0210) goto v0235;
    v0211 = qvalue(elt(env, 3)); // yylval
    v0210 = elt(env, 35); // lex_dipthong
    v0210 = get(v0211, v0210);
    env = stack[-4];
    goto v0236;

v0236:
    if (v0210 == nil) goto v0237;
    fn = elt(env, 37); // yyreadch
    v0210 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-4];
    goto v0238;

v0238:
    v0211 = qvalue(elt(env, 3)); // yylval
    v0210 = elt(env, 34); // !#
    if (v0211 == v0210) goto v0239;
    v0210 = qvalue(elt(env, 6)); // nil
    goto v0240;

v0240:
    if (!(v0210 == nil)) goto v0241;
    v0211 = qvalue(elt(env, 7)); // lex_char
    v0210 = elt(env, 13); // !!
    if (!(v0211 == v0210)) goto v0242;

v0241:
    v0210 = CC_lex_basic_token(env, 0);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-4];
    stack[-3] = v0210;
    v0211 = qvalue(elt(env, 3)); // yylval
    v0210 = elt(env, 36); // (if else elif endif define eval)
    v0210 = Lmemq(nil, v0211, v0210);
    if (v0210 == nil) goto v0243;
    stack[0] = elt(env, 34); // !#
    v0210 = qvalue(elt(env, 3)); // yylval
    v0210 = Lsymbol_name(nil, v0210);
    env = stack[-4];
    fn = elt(env, 38); // widestring2list
    v0210 = (*qfn1(fn))(qenv(fn), v0210);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-4];
    v0210 = cons(stack[0], v0210);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-4];
    fn = elt(env, 39); // list2widestring
    v0210 = (*qfn1(fn))(qenv(fn), v0210);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-4];
    v0210 = Lintern(nil, v0210);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-4];
    qvalue(elt(env, 3)) = v0210; // yylval
    goto v0242;

v0242:
    v0212 = qvalue(elt(env, 7)); // lex_char
    v0211 = qvalue(elt(env, 3)); // yylval
    v0210 = elt(env, 35); // lex_dipthong
    v0210 = get(v0211, v0210);
    env = stack[-4];
    v0210 = Latsoc(nil, v0212, v0210);
    stack[-2] = v0210;
    if (v0210 == nil) goto v0244;
    v0210 = stack[-2];
    v0210 = qcdr(v0210);
    qvalue(elt(env, 3)) = v0210; // yylval
    fn = elt(env, 37); // yyreadch
    v0210 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-4];
    goto v0242;

v0244:
    v0211 = qvalue(elt(env, 3)); // yylval
    v0210 = elt(env, 17); // lex_code
    v0210 = get(v0211, v0210);
    env = stack[-4];
    stack[-2] = v0210;
    if (!(v0210 == nil)) { LispObject res = stack[-2]; popv(5); return onevalue(res); }
    v0210 = qvalue(elt(env, 18)); // lex_symbol_code
    { popv(5); return onevalue(v0210); }

v0243:
    v0210 = stack[-3];
    qvalue(elt(env, 1)) = v0210; // lex_peeked
    v0210 = qvalue(elt(env, 3)); // yylval
    qvalue(elt(env, 2)) = v0210; // lex_peeked_yylval
    v0210 = qvalue(elt(env, 5)); // lex_escaped
    qvalue(elt(env, 4)) = v0210; // lex_peeked_escaped
    v0210 = elt(env, 34); // !#
    qvalue(elt(env, 3)) = v0210; // yylval
    v0210 = qvalue(elt(env, 6)); // nil
    qvalue(elt(env, 5)) = v0210; // lex_escaped
    goto v0242;

v0239:
    v0210 = qvalue(elt(env, 7)); // lex_char
    v0210 = Lalpha_char_p(nil, v0210);
    env = stack[-4];
    goto v0240;

v0237:
    v0210 = elt(env, 8); // ! 
    qvalue(elt(env, 7)) = v0210; // lex_char
    goto v0238;

v0235:
    v0210 = qvalue(elt(env, 9)); // t
    goto v0236;

v0234:
    v0210 = qvalue(elt(env, 33)); // lex_eof_code
    { popv(5); return onevalue(v0210); }

v0233:
    fn = elt(env, 37); // yyreadch
    v0210 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-4];
    fn = elt(env, 40); // read_s_expression
    v0210 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-4];
    v0211 = elt(env, 32); // backquote
    v0210 = qvalue(elt(env, 3)); // yylval
    v0210 = list2(v0211, v0210);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-4];
    qvalue(elt(env, 3)) = v0210; // yylval
    v0210 = qvalue(elt(env, 30)); // lex_list_code
    { popv(5); return onevalue(v0210); }

v0232:
    fn = elt(env, 37); // yyreadch
    v0210 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-4];
    fn = elt(env, 40); // read_s_expression
    v0210 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-4];
    v0211 = elt(env, 29); // quote
    v0210 = qvalue(elt(env, 3)); // yylval
    v0210 = list2(v0211, v0210);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-4];
    qvalue(elt(env, 3)) = v0210; // yylval
    v0210 = qvalue(elt(env, 30)); // lex_list_code
    { popv(5); return onevalue(v0210); }

v0231:
    stack[-1] = qvalue(elt(env, 14)); // !*raise
    qvalue(elt(env, 14)) = nil; // !*raise
    stack[0] = qvalue(elt(env, 15)); // !*lower
    qvalue(elt(env, 15)) = nil; // !*lower
    goto v0245;

v0245:
    fn = elt(env, 37); // yyreadch
    v0211 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0246;
    env = stack[-4];
    v0210 = elt(env, 26); // !"
    if (v0211 == v0210) goto v0247;
    v0211 = qvalue(elt(env, 7)); // lex_char
    v0210 = stack[-3];
    v0210 = cons(v0211, v0210);
    nil = C_nil;
    if (exception_pending()) goto v0246;
    env = stack[-4];
    stack[-3] = v0210;
    goto v0245;

v0247:
    v0211 = qvalue(elt(env, 7)); // lex_char
    v0210 = stack[-3];
    v0210 = cons(v0211, v0210);
    nil = C_nil;
    if (exception_pending()) goto v0246;
    env = stack[-4];
    stack[-3] = v0210;
    fn = elt(env, 37); // yyreadch
    v0210 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0246;
    env = stack[-4];
    v0211 = qvalue(elt(env, 7)); // lex_char
    v0210 = elt(env, 26); // !"
    if (v0211 == v0210) goto v0245;
    qvalue(elt(env, 15)) = stack[0]; // !*lower
    qvalue(elt(env, 14)) = stack[-1]; // !*raise
    v0210 = stack[-3];
    v0210 = qcdr(v0210);
    v0210 = Lnreverse(nil, v0210);
    env = stack[-4];
    fn = elt(env, 39); // list2widestring
    v0210 = (*qfn1(fn))(qenv(fn), v0210);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-4];
    qvalue(elt(env, 3)) = v0210; // yylval
    v0210 = stack[-2];
    qvalue(elt(env, 7)) = v0210; // lex_char
    v0210 = qvalue(elt(env, 27)); // lex_string_code
    { popv(5); return onevalue(v0210); }

v0065:
    v0211 = qvalue(elt(env, 7)); // lex_char
    v0210 = stack[-3];
    v0210 = cons(v0211, v0210);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-4];
    stack[-3] = v0210;
    goto v0248;

v0248:
    fn = elt(env, 37); // yyreadch
    v0211 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-4];
    v0210 = elt(env, 16); // !_
    if (v0211 == v0210) goto v0249;
    v0210 = qvalue(elt(env, 7)); // lex_char
    v0210 = Lalpha_char_p(nil, v0210);
    env = stack[-4];
    if (!(v0210 == nil)) goto v0250;
    v0210 = qvalue(elt(env, 7)); // lex_char
    v0210 = Ldigitp(nil, v0210);
    env = stack[-4];
    if (!(v0210 == nil)) goto v0250;
    v0211 = qvalue(elt(env, 7)); // lex_char
    v0210 = elt(env, 13); // !!
    if (v0211 == v0210) goto v0251;
    v0210 = qvalue(elt(env, 6)); // nil
    goto v0250;

v0250:
    if (v0210 == nil) goto v0252;
    v0211 = qvalue(elt(env, 7)); // lex_char
    v0210 = stack[-3];
    v0210 = cons(v0211, v0210);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-4];
    stack[-3] = v0210;
    goto v0248;

v0252:
    v0210 = stack[-3];
    v0210 = Lnreverse(nil, v0210);
    env = stack[-4];
    fn = elt(env, 39); // list2widestring
    v0210 = (*qfn1(fn))(qenv(fn), v0210);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-4];
    v0210 = Lintern(nil, v0210);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-4];
    qvalue(elt(env, 3)) = v0210; // yylval
    v0210 = qvalue(elt(env, 5)); // lex_escaped
    if (v0210 == nil) goto v0253;
    v0210 = qvalue(elt(env, 6)); // nil
    goto v0254;

v0254:
    if (!(v0210 == nil)) { LispObject res = stack[-2]; popv(5); return onevalue(res); }
    v0210 = qvalue(elt(env, 18)); // lex_symbol_code
    { popv(5); return onevalue(v0210); }

v0253:
    v0211 = qvalue(elt(env, 3)); // yylval
    v0210 = elt(env, 17); // lex_code
    v0210 = get(v0211, v0210);
    env = stack[-4];
    stack[-2] = v0210;
    goto v0254;

v0251:
    v0211 = qvalue(elt(env, 6)); // nil
    v0210 = qvalue(elt(env, 6)); // nil
    stack[-1] = qvalue(elt(env, 14)); // !*raise
    qvalue(elt(env, 14)) = v0211; // !*raise
    stack[0] = qvalue(elt(env, 15)); // !*lower
    qvalue(elt(env, 15)) = v0210; // !*lower
    fn = elt(env, 37); // yyreadch
    v0210 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0255;
    env = stack[-4];
    qvalue(elt(env, 15)) = stack[0]; // !*lower
    qvalue(elt(env, 14)) = stack[-1]; // !*raise
    v0210 = qvalue(elt(env, 9)); // t
    qvalue(elt(env, 5)) = v0210; // lex_escaped
    goto v0250;

v0249:
    v0210 = qvalue(elt(env, 9)); // t
    goto v0250;

v0216:
    v0211 = qvalue(elt(env, 6)); // nil
    v0210 = qvalue(elt(env, 6)); // nil
    stack[-1] = qvalue(elt(env, 14)); // !*raise
    qvalue(elt(env, 14)) = v0211; // !*raise
    stack[0] = qvalue(elt(env, 15)); // !*lower
    qvalue(elt(env, 15)) = v0210; // !*lower
    fn = elt(env, 37); // yyreadch
    v0210 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0256;
    env = stack[-4];
    qvalue(elt(env, 15)) = stack[0]; // !*lower
    qvalue(elt(env, 14)) = stack[-1]; // !*raise
    v0210 = qvalue(elt(env, 9)); // t
    qvalue(elt(env, 5)) = v0210; // lex_escaped
    goto v0107;

v0084:
    v0211 = qvalue(elt(env, 7)); // lex_char
    v0210 = qvalue(elt(env, 10)); // !$eol!$
    if (equal(v0211, v0210)) goto v0257;
    v0211 = qvalue(elt(env, 7)); // lex_char
    v0210 = qvalue(elt(env, 12)); // !$eof!$
    v0210 = (equal(v0211, v0210) ? lisp_true : nil);
    goto v0258;

v0258:
    if (v0210 == nil) goto v0074;
    v0210 = qvalue(elt(env, 9)); // t
    goto v0214;

v0074:
    fn = elt(env, 37); // yyreadch
    v0210 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-4];
    goto v0084;

v0257:
    v0210 = qvalue(elt(env, 9)); // t
    goto v0258;

v0076:
    v0210 = qvalue(elt(env, 9)); // t
    goto v0214;

v0213:
    v0210 = qvalue(elt(env, 9)); // t
    goto v0214;
// error exit handlers
v0256:
    env = stack[-4];
    qvalue(elt(env, 15)) = stack[0]; // !*lower
    qvalue(elt(env, 14)) = stack[-1]; // !*raise
    popv(5);
    return nil;
v0255:
    env = stack[-4];
    qvalue(elt(env, 15)) = stack[0]; // !*lower
    qvalue(elt(env, 14)) = stack[-1]; // !*raise
    popv(5);
    return nil;
v0246:
    env = stack[-4];
    qvalue(elt(env, 15)) = stack[0]; // !*lower
    qvalue(elt(env, 14)) = stack[-1]; // !*raise
    popv(5);
    return nil;
v0215:
    popv(5);
    return nil;
}



// Code for refprint

static LispObject CC_refprint(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0089, v0109;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for refprint");
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
    v0089 = qvalue(elt(env, 1)); // cloc!*
    if (v0089 == nil) goto v0096;
    v0089 = qvalue(elt(env, 1)); // cloc!*
    v0089 = qcar(v0089);
    goto v0057;

v0057:
    stack[-4] = v0089;
    v0109 = stack[-4];
    v0089 = qvalue(elt(env, 3)); // pfiles!*
    v0089 = Lassoc(nil, v0109, v0089);
    qvalue(elt(env, 4)) = v0089; // curfun!*
    if (v0089 == nil) goto v0262;
    v0089 = qvalue(elt(env, 4)); // curfun!*
    v0089 = qcar(v0089);
    stack[-4] = v0089;
    v0089 = qvalue(elt(env, 4)); // curfun!*
    v0089 = qcdr(v0089);
    qvalue(elt(env, 4)) = v0089; // curfun!*
    goto v0080;

v0080:
    v0089 = qvalue(elt(env, 1)); // cloc!*
    if (v0089 == nil) goto v0205;
    v0089 = qvalue(elt(env, 1)); // cloc!*
    v0089 = qcdr(v0089);
    if (v0089 == nil) goto v0205;
    v0109 = stack[-4];
    v0089 = qvalue(elt(env, 1)); // cloc!*
    v0089 = qcdr(v0089);
    v0089 = cons(v0109, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0263;
    env = stack[-5];
    goto v0264;

v0264:
    qvalue(elt(env, 8)) = v0089; // curlin!*
    v0089 = qvalue(elt(env, 7)); // nil
    qvalue(elt(env, 9)) = v0089; // locls!*
    qvalue(elt(env, 10)) = v0089; // globs!*
    qvalue(elt(env, 11)) = v0089; // calls!*
    v0089 = stack[-3];
    fn = elt(env, 12); // anform
    v0089 = (*qfn1(fn))(qenv(fn), v0089);
    nil = C_nil;
    if (exception_pending()) goto v0263;
    env = stack[-5];
    v0089 = qvalue(elt(env, 4)); // curfun!*
    fn = elt(env, 13); // outrefend
    v0089 = (*qfn1(fn))(qenv(fn), v0089);
    nil = C_nil;
    if (exception_pending()) goto v0263;
    v0089 = nil;
    { popv(6); return onevalue(v0089); }

v0205:
    v0089 = qvalue(elt(env, 7)); // nil
    goto v0264;

v0262:
    stack[0] = stack[-4];
    v0089 = elt(env, 5); // g
    v0109 = Lgensym1(nil, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0263;
    env = stack[-5];
    qvalue(elt(env, 4)) = v0109; // curfun!*
    v0089 = qvalue(elt(env, 3)); // pfiles!*
    v0089 = acons(stack[0], v0109, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0263;
    env = stack[-5];
    qvalue(elt(env, 3)) = v0089; // pfiles!*
    v0089 = stack[-4];
    v0089 = Lexplode(nil, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0263;
    env = stack[-5];
    v0089 = qcdr(v0089);
    v0089 = Lnreverse(nil, v0089);
    env = stack[-5];
    v0089 = qcdr(v0089);
    v0089 = Lnreverse(nil, v0089);
    env = stack[-5];
    stack[-2] = v0089;
    stack[-1] = qvalue(elt(env, 4)); // curfun!*
    stack[0] = elt(env, 6); // rccnam
    v0089 = stack[-2];
    v0109 = Llength(nil, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0263;
    env = stack[-5];
    v0089 = stack[-2];
    v0089 = cons(v0109, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0263;
    env = stack[-5];
    v0089 = Lputprop(nil, 3, stack[-1], stack[0], v0089);
    nil = C_nil;
    if (exception_pending()) goto v0263;
    env = stack[-5];
    goto v0080;

v0096:
    v0089 = elt(env, 2); // "*TTYINPUT*"
    goto v0057;
// error exit handlers
v0263:
    popv(6);
    return nil;
}



// Code for cl_pnf

static LispObject CC_cl_pnf(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0055;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cl_pnf");
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
    v0055 = v0000;
// end of prologue
    fn = elt(env, 1); // rl_nnf
    v0055 = (*qfn1(fn))(qenv(fn), v0055);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); // cl_pnf1
        return (*qfn1(fn))(qenv(fn), v0055);
    }
// error exit handlers
v0056:
    popv(1);
    return nil;
}



// Code for bc_zero!?

static LispObject CC_bc_zeroW(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0055;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for bc_zero?");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0055 = v0000;
// end of prologue
    v0055 = qcar(v0055);
    v0055 = (v0055 == nil ? lisp_true : nil);
    return onevalue(v0055);
}



// Code for row

static LispObject CC_row(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0038;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for row");
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
    v0038 = stack[0];
    if (v0038 == nil) goto v0055;
    v0038 = stack[0];
    v0038 = qcar(v0038);
    fn = elt(env, 2); // expression
    v0038 = (*qfn1(fn))(qenv(fn), v0038);
    nil = C_nil;
    if (exception_pending()) goto v0079;
    env = stack[-1];
    v0038 = stack[0];
    v0038 = qcdr(v0038);
    v0038 = CC_row(env, v0038);
    nil = C_nil;
    if (exception_pending()) goto v0079;
    goto v0055;

v0055:
    v0038 = nil;
    { popv(2); return onevalue(v0038); }
// error exit handlers
v0079:
    popv(2);
    return nil;
}



// Code for rd!:zerop!:

static LispObject CC_rdTzeropT(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0038, v0080;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rd:zerop:");
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
    v0080 = v0000;
// end of prologue
    v0038 = v0080;
    v0038 = qcdr(v0038);
    if (!consp(v0038)) goto v0026;
    v0038 = v0080;
    fn = elt(env, 1); // round!*
    v0038 = (*qfn1(fn))(qenv(fn), v0038);
    nil = C_nil;
    if (exception_pending()) goto v0079;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); // bfzerop!:
        return (*qfn1(fn))(qenv(fn), v0038);
    }

v0026:
    v0038 = v0080;
    v0038 = qcdr(v0038);
    {
        popv(1);
        fn = elt(env, 3); // ft!:zerop
        return (*qfn1(fn))(qenv(fn), v0038);
    }
// error exit handlers
v0079:
    popv(1);
    return nil;
}



// Code for dipev2f

static LispObject CC_dipev2f(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0260, v0267;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dipev2f");
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

v0055:
    v0260 = stack[-1];
    if (v0260 == nil) goto v0059;
    v0260 = stack[-1];
    v0267 = qcar(v0260);
    v0260 = (LispObject)1; // 0
    if (v0267 == v0260) goto v0095;
    v0260 = stack[0];
    v0267 = qcar(v0260);
    v0260 = stack[-1];
    v0260 = qcar(v0260);
    fn = elt(env, 1); // to
    v0267 = (*qfn2(fn))(qenv(fn), v0267, v0260);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-3];
    v0260 = (LispObject)17; // 1
    v0260 = cons(v0267, v0260);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-3];
    stack[-2] = ncons(v0260);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-3];
    v0260 = stack[-1];
    v0267 = qcdr(v0260);
    v0260 = stack[0];
    v0260 = qcdr(v0260);
    v0260 = CC_dipev2f(env, v0267, v0260);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-3];
    {
        LispObject v0261 = stack[-2];
        popv(4);
        fn = elt(env, 2); // multf
        return (*qfn2(fn))(qenv(fn), v0261, v0260);
    }

v0095:
    v0260 = stack[-1];
    v0260 = qcdr(v0260);
    stack[-1] = v0260;
    v0260 = stack[0];
    v0260 = qcdr(v0260);
    stack[0] = v0260;
    goto v0055;

v0059:
    v0260 = (LispObject)17; // 1
    { popv(4); return onevalue(v0260); }
// error exit handlers
v0049:
    popv(4);
    return nil;
}



// Code for gbfdot

static LispObject CC_gbfdot(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0075, v0269;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gbfdot");
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
    v0075 = stack[-1];
    v0269 = qcar(v0075);
    v0075 = stack[0];
    v0075 = qcar(v0075);
    fn = elt(env, 1); // csl_timbf
    stack[-2] = (*qfn2(fn))(qenv(fn), v0269, v0075);
    nil = C_nil;
    if (exception_pending()) goto v0265;
    env = stack[-3];
    v0075 = stack[-1];
    v0269 = qcdr(v0075);
    v0075 = stack[0];
    v0075 = qcdr(v0075);
    fn = elt(env, 1); // csl_timbf
    v0075 = (*qfn2(fn))(qenv(fn), v0269, v0075);
    nil = C_nil;
    if (exception_pending()) goto v0265;
    env = stack[-3];
    {
        LispObject v0262 = stack[-2];
        popv(4);
        fn = elt(env, 2); // plubf
        return (*qfn2(fn))(qenv(fn), v0262, v0075);
    }
// error exit handlers
v0265:
    popv(4);
    return nil;
}



// Code for red_totalred

static LispObject CC_red_totalred(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0079, v0268;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for red_totalred");
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
    v0079 = v0001;
    v0268 = v0000;
// end of prologue
    stack[0] = v0268;
    fn = elt(env, 1); // red_topred
    v0079 = (*qfn2(fn))(qenv(fn), v0268, v0079);
    nil = C_nil;
    if (exception_pending()) goto v0266;
    env = stack[-1];
    {
        LispObject v0270 = stack[0];
        popv(2);
        fn = elt(env, 2); // red_tailred
        return (*qfn2(fn))(qenv(fn), v0270, v0079);
    }
// error exit handlers
v0266:
    popv(2);
    return nil;
}



// Code for sfto_int2sf

static LispObject CC_sfto_int2sf(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0097, v0037, v0038;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sfto_int2sf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0037 = v0000;
// end of prologue
    v0038 = v0037;
    v0097 = (LispObject)1; // 0
    if (!(v0038 == v0097)) return onevalue(v0037);
    v0097 = nil;
    return onevalue(v0097);
}



// Code for lalr_set_grammar

static LispObject CC_lalr_set_grammar(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0330, v0331, v0332, v0333, v0334;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lalr_set_grammar");
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
    stack[-2] = v0000;
// end of prologue
    fn = elt(env, 23); // lex_cleanup
    v0330 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-9];
    v0330 = qvalue(elt(env, 1)); // nil
    qvalue(elt(env, 2)) = v0330; // non_terminals
    qvalue(elt(env, 3)) = v0330; // terminals
    v0331 = elt(env, 4); // !S!'
    v0330 = stack[-2];
    v0330 = Lassoc(nil, v0331, v0330);
    if (!(v0330 == nil)) goto v0095;
    stack[0] = elt(env, 4); // !S!'
    v0330 = stack[-2];
    v0330 = qcar(v0330);
    v0330 = qcar(v0330);
    v0330 = ncons(v0330);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-9];
    v0330 = ncons(v0330);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-9];
    v0331 = list2(stack[0], v0330);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-9];
    v0330 = stack[-2];
    v0330 = cons(v0331, v0330);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-9];
    stack[-2] = v0330;
    goto v0095;

v0095:
    v0330 = stack[-2];
    stack[0] = v0330;
    goto v0091;

v0091:
    v0330 = stack[0];
    if (v0330 == nil) goto v0092;
    v0330 = stack[0];
    v0330 = qcar(v0330);
    v0331 = v0330;
    v0330 = v0331;
    v0330 = qcar(v0330);
    stack[-3] = v0330;
    v0330 = v0331;
    v0330 = qcdr(v0330);
    stack[-1] = v0330;
    v0331 = stack[-3];
    v0330 = qvalue(elt(env, 2)); // non_terminals
    v0330 = Lmember(nil, v0331, v0330);
    if (v0330 == nil) goto v0336;
    v0332 = stack[-1];
    v0331 = stack[-3];
    v0330 = elt(env, 5); // produces
    v0330 = get(v0331, v0330);
    env = stack[-9];
    v0330 = Lappend(nil, v0332, v0330);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-9];
    stack[-1] = v0330;
    goto v0109;

v0109:
    v0332 = stack[-3];
    v0331 = elt(env, 5); // produces
    v0330 = stack[-1];
    v0330 = Lputprop(nil, 3, v0332, v0331, v0330);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-9];
    v0330 = stack[0];
    v0330 = qcdr(v0330);
    stack[0] = v0330;
    goto v0091;

v0336:
    v0331 = stack[-3];
    v0330 = qvalue(elt(env, 2)); // non_terminals
    v0330 = cons(v0331, v0330);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-9];
    qvalue(elt(env, 2)) = v0330; // non_terminals
    goto v0109;

v0092:
    v0330 = qvalue(elt(env, 1)); // nil
    qvalue(elt(env, 3)) = v0330; // terminals
    v0330 = stack[-2];
    stack[-2] = v0330;
    goto v0337;

v0337:
    v0330 = stack[-2];
    if (v0330 == nil) goto v0338;
    v0330 = stack[-2];
    v0330 = qcar(v0330);
    v0330 = qcdr(v0330);
    stack[-1] = v0330;
    goto v0065;

v0065:
    v0330 = stack[-1];
    if (v0330 == nil) goto v0051;
    v0330 = stack[-1];
    v0330 = qcar(v0330);
    v0330 = qcar(v0330);
    stack[0] = v0330;
    goto v0250;

v0250:
    v0330 = stack[0];
    if (v0330 == nil) goto v0093;
    v0330 = stack[0];
    v0330 = qcar(v0330);
    v0331 = v0330;
    v0330 = v0331;
    v0330 = Lstringp(nil, v0330);
    env = stack[-9];
    if (v0330 == nil) goto v0053;
    v0330 = v0331;
    v0331 = ncons(v0330);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-9];
    v0330 = qvalue(elt(env, 3)); // terminals
    fn = elt(env, 24); // union
    v0330 = (*qfn2(fn))(qenv(fn), v0331, v0330);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-9];
    qvalue(elt(env, 3)) = v0330; // terminals
    goto v0053;

v0053:
    v0330 = stack[0];
    v0330 = qcdr(v0330);
    stack[0] = v0330;
    goto v0250;

v0093:
    v0330 = stack[-1];
    v0330 = qcdr(v0330);
    stack[-1] = v0330;
    goto v0065;

v0051:
    v0330 = stack[-2];
    v0330 = qcdr(v0330);
    stack[-2] = v0330;
    goto v0337;

v0338:
    v0330 = qvalue(elt(env, 3)); // terminals
    fn = elt(env, 25); // lex_keywords
    v0330 = (*qfn1(fn))(qenv(fn), v0330);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-9];
    stack[0] = qvalue(elt(env, 2)); // non_terminals
    v0331 = elt(env, 6); // (!:eof !:symbol !:string !:number !:list)
    v0330 = qvalue(elt(env, 3)); // terminals
    v0330 = Lappend(nil, v0331, v0330);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-9];
    v0330 = Lappend(nil, stack[0], v0330);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-9];
    qvalue(elt(env, 7)) = v0330; // symbols
    v0330 = qvalue(elt(env, 7)); // symbols
    v0330 = Llength(nil, v0330);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-9];
    v0330 = sub1(v0330);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-9];
    v0330 = Lmkvect(nil, v0330);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-9];
    qvalue(elt(env, 8)) = v0330; // lalr_precedence_table
    v0330 = qvalue(elt(env, 9)); // lalr_precedence!*
    v0334 = v0330;
    goto v0005;

v0005:
    v0330 = v0334;
    if (v0330 == nil) goto v0009;
    v0330 = v0334;
    v0330 = qcar(v0330);
    v0332 = v0330;
    v0331 = elt(env, 10); // lex_code
    v0331 = get(v0332, v0331);
    env = stack[-9];
    stack[-5] = v0331;
    v0331 = stack[-5];
    if (v0331 == nil) goto v0054;
    v0333 = qvalue(elt(env, 8)); // lalr_precedence_table
    v0332 = stack[-5];
    v0331 = v0330;
    v0330 = elt(env, 11); // lalr_precedence
    v0330 = get(v0331, v0330);
    env = stack[-9];
    *(LispObject *)((char *)v0333 + (CELL-TAG_VECTOR) + ((int32_t)v0332/(16/CELL))) = v0330;
    goto v0054;

v0054:
    v0330 = v0334;
    v0330 = qcdr(v0330);
    v0334 = v0330;
    goto v0005;

v0009:
    v0330 = qvalue(elt(env, 2)); // non_terminals
    v0330 = Lnreverse(nil, v0330);
    env = stack[-9];
    qvalue(elt(env, 2)) = v0330; // non_terminals
    v0330 = (LispObject)-15; // -1
    stack[-5] = v0330;
    v0330 = qvalue(elt(env, 2)); // non_terminals
    stack[-2] = v0330;
    goto v0339;

v0339:
    v0330 = stack[-2];
    if (v0330 == nil) goto v0340;
    v0330 = stack[-2];
    v0330 = qcar(v0330);
    stack[-1] = v0330;
    stack[0] = elt(env, 12); // non_terminal_code
    v0330 = stack[-5];
    v0330 = add1(v0330);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-9];
    stack[-5] = v0330;
    v0330 = Lputprop(nil, 3, stack[-1], stack[0], v0330);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-9];
    v0330 = stack[-2];
    v0330 = qcdr(v0330);
    stack[-2] = v0330;
    goto v0339;

v0340:
    v0330 = qvalue(elt(env, 2)); // non_terminals
    v0332 = Llength(nil, v0330);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-9];
    v0331 = (LispObject)17; // 1
    v0330 = elt(env, 13); // 1.5
    fn = elt(env, 26); // mkhash
    v0330 = (*qfnn(fn))(qenv(fn), 3, v0332, v0331, v0330);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-9];
    qvalue(elt(env, 14)) = v0330; // goto_cache
    v0330 = qvalue(elt(env, 15)); // !*lalr_verbose
    if (v0330 == nil) goto v0341;
    fn = elt(env, 27); // lalr_display_symbols
    v0330 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-9];
    goto v0341;

v0341:
    v0330 = qvalue(elt(env, 1)); // nil
    stack[-8] = v0330;
    v0330 = qvalue(elt(env, 3)); // terminals
    stack[-1] = v0330;
    goto v0342;

v0342:
    v0330 = stack[-1];
    if (v0330 == nil) goto v0220;
    v0330 = stack[-1];
    v0330 = qcar(v0330);
    stack[0] = v0330;
    v0331 = Lintern(nil, v0330);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-9];
    v0330 = elt(env, 10); // lex_code
    v0331 = get(v0331, v0330);
    env = stack[-9];
    v0330 = stack[-8];
    v0330 = acons(stack[0], v0331, v0330);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-9];
    stack[-8] = v0330;
    v0330 = stack[-1];
    v0330 = qcdr(v0330);
    stack[-1] = v0330;
    goto v0342;

v0220:
    v0330 = elt(env, 6); // (!:eof !:symbol !:string !:number !:list)
    stack[0] = v0330;
    goto v0225;

v0225:
    v0330 = stack[0];
    if (v0330 == nil) goto v0343;
    v0330 = stack[0];
    v0330 = qcar(v0330);
    v0331 = v0330;
    v0332 = v0330;
    v0330 = elt(env, 16); // lex_fixed_code
    v0332 = get(v0332, v0330);
    env = stack[-9];
    v0330 = stack[-8];
    v0330 = acons(v0331, v0332, v0330);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-9];
    stack[-8] = v0330;
    v0330 = stack[0];
    v0330 = qcdr(v0330);
    stack[0] = v0330;
    goto v0225;

v0343:
    v0330 = qvalue(elt(env, 2)); // non_terminals
    stack[-7] = v0330;
    goto v0344;

v0344:
    v0330 = stack[-7];
    if (v0330 == nil) goto v0345;
    v0330 = stack[-7];
    v0330 = qcar(v0330);
    stack[-6] = v0330;
    stack[-5] = elt(env, 5); // produces
    v0331 = v0330;
    v0330 = elt(env, 5); // produces
    v0330 = get(v0331, v0330);
    env = stack[-9];
    stack[-4] = v0330;
    v0330 = stack[-4];
    if (v0330 == nil) goto v0346;
    v0330 = stack[-4];
    v0330 = qcar(v0330);
    stack[0] = v0330;
    v0331 = stack[-8];
    v0330 = stack[0];
    v0330 = qcar(v0330);
    v0331 = Lsublis(nil, v0331, v0330);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-9];
    v0330 = stack[0];
    v0330 = qcdr(v0330);
    v0330 = cons(v0331, v0330);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-9];
    v0330 = ncons(v0330);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-9];
    stack[-2] = v0330;
    stack[-3] = v0330;
    goto v0347;

v0347:
    v0330 = stack[-4];
    v0330 = qcdr(v0330);
    stack[-4] = v0330;
    v0330 = stack[-4];
    if (v0330 == nil) goto v0152;
    stack[-1] = stack[-2];
    v0330 = stack[-4];
    v0330 = qcar(v0330);
    stack[0] = v0330;
    v0331 = stack[-8];
    v0330 = stack[0];
    v0330 = qcar(v0330);
    v0331 = Lsublis(nil, v0331, v0330);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-9];
    v0330 = stack[0];
    v0330 = qcdr(v0330);
    v0330 = cons(v0331, v0330);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-9];
    v0330 = ncons(v0330);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-9];
    v0330 = Lrplacd(nil, stack[-1], v0330);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-9];
    v0330 = stack[-2];
    v0330 = qcdr(v0330);
    stack[-2] = v0330;
    goto v0347;

v0152:
    v0330 = stack[-3];
    goto v0348;

v0348:
    v0330 = Lputprop(nil, 3, stack[-6], stack[-5], v0330);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-9];
    v0330 = stack[-7];
    v0330 = qcdr(v0330);
    stack[-7] = v0330;
    goto v0344;

v0346:
    v0330 = qvalue(elt(env, 1)); // nil
    goto v0348;

v0345:
    v0330 = qvalue(elt(env, 1)); // nil
    qvalue(elt(env, 17)) = v0330; // action_map
    v0330 = (LispObject)-15; // -1
    stack[-5] = v0330;
    v0330 = qvalue(elt(env, 2)); // non_terminals
    stack[-4] = v0330;
    goto v0349;

v0349:
    v0330 = stack[-4];
    if (v0330 == nil) goto v0350;
    v0330 = stack[-4];
    v0330 = qcar(v0330);
    stack[-3] = v0330;
    v0331 = stack[-3];
    v0330 = elt(env, 5); // produces
    v0330 = get(v0331, v0330);
    env = stack[-9];
    stack[-2] = v0330;
    goto v0232;

v0232:
    v0330 = stack[-2];
    if (v0330 == nil) goto v0351;
    v0330 = stack[-2];
    v0330 = qcar(v0330);
    stack[-1] = v0330;
    stack[0] = stack[-3];
    v0330 = stack[-1];
    v0330 = qcar(v0330);
    v0331 = Llength(nil, v0330);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-9];
    v0330 = stack[-1];
    v0330 = qcdr(v0330);
    v0331 = acons(stack[0], v0331, v0330);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-9];
    v0330 = qvalue(elt(env, 17)); // action_map
    v0330 = Lassoc(nil, v0331, v0330);
    stack[-8] = v0330;
    v0330 = stack[-8];
    if (!(v0330 == nil)) goto v0352;
    stack[0] = stack[-3];
    v0330 = stack[-1];
    v0330 = qcar(v0330);
    v0330 = Llength(nil, v0330);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-9];
    stack[-6] = cons(stack[0], v0330);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-9];
    v0330 = stack[-1];
    stack[0] = qcdr(v0330);
    v0330 = stack[-5];
    v0330 = add1(v0330);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-9];
    stack[-5] = v0330;
    v0330 = acons(stack[-6], stack[0], v0330);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-9];
    stack[-8] = v0330;
    v0331 = stack[-8];
    v0330 = qvalue(elt(env, 17)); // action_map
    v0330 = cons(v0331, v0330);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-9];
    qvalue(elt(env, 17)) = v0330; // action_map
    goto v0352;

v0352:
    stack[0] = stack[-1];
    v0330 = stack[-8];
    v0330 = qcdr(v0330);
    v0330 = ncons(v0330);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-9];
    v0330 = Lrplacd(nil, stack[0], v0330);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-9];
    v0330 = stack[-2];
    v0330 = qcdr(v0330);
    stack[-2] = v0330;
    goto v0232;

v0351:
    v0330 = stack[-4];
    v0330 = qcdr(v0330);
    stack[-4] = v0330;
    goto v0349;

v0350:
    v0330 = qvalue(elt(env, 17)); // action_map
    v0330 = Lnreverse(nil, v0330);
    env = stack[-9];
    qvalue(elt(env, 17)) = v0330; // action_map
    v0330 = Lposn(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-9];
    v0330 = (LispObject)zerop(v0330);
    v0330 = v0330 ? lisp_true : nil;
    env = stack[-9];
    if (!(v0330 == nil)) goto v0240;
    v0330 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-9];
    goto v0240;

v0240:
    v0330 = stack[-5];
    v0330 = Lprinc(nil, v0330);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-9];
    v0330 = elt(env, 18); // " semantic actions"
    v0330 = Lprintc(nil, v0330);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-9];
    v0330 = stack[-5];
    v0330 = sub1(v0330);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-9];
    v0330 = Lmkvect(nil, v0330);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-9];
    qvalue(elt(env, 19)) = v0330; // action_fn
    v0330 = stack[-5];
    v0330 = sub1(v0330);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-9];
    fn = elt(env, 28); // mkvect8
    v0330 = (*qfn1(fn))(qenv(fn), v0330);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-9];
    qvalue(elt(env, 20)) = v0330; // action_n
    v0330 = stack[-5];
    v0330 = sub1(v0330);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-9];
    fn = elt(env, 29); // mkvect16
    v0330 = (*qfn1(fn))(qenv(fn), v0330);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-9];
    qvalue(elt(env, 21)) = v0330; // action_a
    v0330 = stack[-5];
    qvalue(elt(env, 22)) = v0330; // action_first_error
    v0330 = qvalue(elt(env, 15)); // !*lalr_verbose
    if (v0330 == nil) goto v0131;
    fn = elt(env, 30); // lalr_print_action_map
    v0330 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-9];
    goto v0131;

v0131:
    v0330 = qvalue(elt(env, 2)); // non_terminals
    fn = elt(env, 31); // lalr_calculate_first
    v0330 = (*qfn1(fn))(qenv(fn), v0330);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    v0330 = nil;
    { popv(10); return onevalue(v0330); }
// error exit handlers
v0335:
    popv(10);
    return nil;
}



// Code for ofsf_ignshift

static LispObject CC_ofsf_ignshift(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0205, v0336, v0069;
    LispObject fn;
    LispObject v0058, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "ofsf_ignshift");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0058 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_ignshift");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0058,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0058);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0058;
    stack[-1] = v0001;
    stack[-2] = v0000;
// end of prologue
    v0205 = stack[-2];
    v0205 = qcdr(v0205);
    v0336 = qcar(v0205);
    v0205 = stack[-1];
    fn = elt(env, 7); // sfto_reorder
    v0205 = (*qfn2(fn))(qenv(fn), v0336, v0205);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    env = stack[-3];
    v0069 = v0205;
    v0205 = v0069;
    if (!consp(v0205)) goto v0033;
    v0205 = v0069;
    v0205 = qcar(v0205);
    v0205 = (consp(v0205) ? nil : lisp_true);
    goto v0048;

v0048:
    if (v0205 == nil) goto v0203;
    v0205 = qvalue(elt(env, 2)); // nil
    goto v0270;

v0270:
    if (v0205 == nil) goto v0079;
    v0205 = qvalue(elt(env, 3)); // !*rlpos
    if (!(v0205 == nil)) goto v0207;
    v0205 = stack[0];
    if (!(v0205 == nil)) goto v0207;
    v0205 = stack[-2];
    v0336 = qcar(v0205);
    v0205 = elt(env, 4); // (equal neq)
    v0205 = Lmemq(nil, v0336, v0205);
    if (!(v0205 == nil)) goto v0207;
    v0205 = v0069;
    v0205 = qcar(v0205);
    v0205 = qcar(v0205);
    v0205 = qcdr(v0205);
    v0205 = Levenp(nil, v0205);
    env = stack[-3];
    if (!(v0205 == nil)) goto v0207;
    v0205 = elt(env, 6); // odd
    { popv(4); return onevalue(v0205); }

v0207:
    v0205 = elt(env, 5); // ignore
    { popv(4); return onevalue(v0205); }

v0079:
    v0205 = nil;
    { popv(4); return onevalue(v0205); }

v0203:
    v0205 = v0069;
    v0205 = qcdr(v0205);
    if (v0205 == nil) goto v0046;
    v0205 = qvalue(elt(env, 2)); // nil
    goto v0270;

v0046:
    v0205 = v0069;
    v0205 = qcar(v0205);
    v0205 = qcar(v0205);
    v0336 = qcar(v0205);
    v0205 = stack[-1];
    v0205 = (v0336 == v0205 ? lisp_true : nil);
    goto v0270;

v0033:
    v0205 = qvalue(elt(env, 1)); // t
    goto v0048;
// error exit handlers
v0071:
    popv(4);
    return nil;
}



// Code for tripleisprolongedby

static LispObject CC_tripleisprolongedby(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0206, v0207;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for tripleisprolongedby");
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
    v0206 = v0000;
// end of prologue
    v0207 = v0206;
    v0206 = (LispObject)49; // 3
    v0206 = *(LispObject *)((char *)v0207 + (CELL-TAG_VECTOR) + ((int32_t)v0206/(16/CELL)));
    stack[-1] = v0206;
    goto v0038;

v0038:
    v0206 = stack[-1];
    v0206 = qcar(v0206);
    if (v0206 == nil) goto v0037;
    v0206 = stack[-1];
    v0207 = qcar(v0206);
    v0206 = stack[0];
    v0206 = (LispObject)greaterp2(v0207, v0206);
    nil = C_nil;
    if (exception_pending()) goto v0355;
    v0206 = v0206 ? lisp_true : nil;
    env = stack[-2];
    if (v0206 == nil) goto v0037;
    v0206 = stack[-1];
    v0206 = qcdr(v0206);
    stack[-1] = v0206;
    goto v0038;

v0037:
    v0206 = stack[-1];
    v0206 = qcar(v0206);
    if (v0206 == nil) goto v0356;
    v0206 = stack[-1];
    v0207 = qcar(v0206);
    v0206 = stack[0];
    if (!(equal(v0207, v0206))) goto v0356;
    v0206 = qvalue(elt(env, 2)); // t
    { popv(3); return onevalue(v0206); }

v0356:
    v0206 = qvalue(elt(env, 1)); // nil
    { popv(3); return onevalue(v0206); }
// error exit handlers
v0355:
    popv(3);
    return nil;
}



// Code for ofsf_smupdknowl

static LispObject CC_ofsf_smupdknowl(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0088, v0263, v0327;
    LispObject fn;
    LispObject v0010, v0058, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "ofsf_smupdknowl");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0058 = va_arg(aa, LispObject);
    v0010 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_smupdknowl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0010,v0058,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0001,v0058,v0010);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    stack[-1] = v0010;
    stack[-2] = v0058;
    stack[-3] = v0001;
    stack[-4] = v0000;
// end of prologue

v0095:
    v0088 = stack[-3];
    if (v0088 == nil) { LispObject res = stack[-2]; popv(7); return onevalue(res); }
    v0263 = stack[-4];
    v0088 = elt(env, 2); // and
    if (v0263 == v0088) goto v0266;
    v0088 = stack[-3];
    v0088 = qcar(v0088);
    fn = elt(env, 4); // ofsf_negateat
    v0088 = (*qfn1(fn))(qenv(fn), v0088);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-6];
    goto v0082;

v0082:
    v0263 = v0088;
    v0088 = stack[-3];
    v0088 = qcdr(v0088);
    stack[-3] = v0088;
    v0088 = stack[-1];
    fn = elt(env, 5); // ofsf_at2ir
    v0088 = (*qfn2(fn))(qenv(fn), v0263, v0088);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-6];
    v0327 = v0088;
    v0088 = v0327;
    v0263 = qcar(v0088);
    v0088 = stack[-2];
    v0088 = Lassoc(nil, v0263, v0088);
    stack[-5] = v0088;
    if (v0088 == nil) goto v0071;
    stack[0] = stack[-5];
    v0088 = v0327;
    v0088 = qcdr(v0088);
    v0263 = qcar(v0088);
    v0088 = stack[-5];
    v0088 = qcdr(v0088);
    fn = elt(env, 6); // ofsf_sminsert
    v0088 = (*qfn2(fn))(qenv(fn), v0263, v0088);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-6];
    fn = elt(env, 7); // setcdr
    v0088 = (*qfn2(fn))(qenv(fn), stack[0], v0088);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-6];
    v0088 = stack[-5];
    v0263 = qcdr(v0088);
    v0088 = elt(env, 3); // false
    if (!(v0263 == v0088)) goto v0095;
    v0088 = qvalue(elt(env, 1)); // nil
    stack[-3] = v0088;
    v0088 = elt(env, 3); // false
    stack[-2] = v0088;
    goto v0095;

v0071:
    v0263 = v0327;
    v0088 = stack[-2];
    v0088 = cons(v0263, v0088);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-6];
    stack[-2] = v0088;
    goto v0095;

v0266:
    v0088 = stack[-3];
    v0088 = qcar(v0088);
    goto v0082;
// error exit handlers
v0120:
    popv(7);
    return nil;
}



// Code for pasf_smwcpknowl

static LispObject CC_pasf_smwcpknowl(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0096, v0097;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pasf_smwcpknowl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0097 = v0000;
// end of prologue
    v0096 = qvalue(elt(env, 1)); // !*rlsusi
    if (v0096 == nil) goto v0098;
    v0096 = v0097;
    {
        fn = elt(env, 2); // cl_susicpknowl
        return (*qfn1(fn))(qenv(fn), v0096);
    }

v0098:
    v0096 = v0097;
    {
        fn = elt(env, 3); // cl_smcpknowl
        return (*qfn1(fn))(qenv(fn), v0096);
    }
}



// Code for rl_updcache

static LispObject CC_rl_updcache(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0202, v0025;
    argcheck(nargs, 0, "rl_updcache");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rl_updcache");
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
    v0202 = qvalue(elt(env, 1)); // rl_bbl!*
    stack[0] = v0202;
    goto v0026;

v0026:
    v0202 = stack[0];
    if (v0202 == nil) goto v0269;
    v0202 = stack[0];
    v0202 = qcar(v0202);
    v0025 = v0202;
    v0202 = qvalue(elt(env, 2)); // nil
    v0202 = Lset(nil, v0025, v0202);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-1];
    v0202 = stack[0];
    v0202 = qcdr(v0202);
    stack[0] = v0202;
    goto v0026;

v0269:
    v0202 = qvalue(elt(env, 3)); // rl_cid!*
    v0025 = qcar(v0202);
    v0202 = elt(env, 4); // rl_params
    v0202 = get(v0025, v0202);
    env = stack[-1];
    stack[0] = v0202;
    goto v0047;

v0047:
    v0202 = stack[0];
    if (v0202 == nil) goto v0033;
    v0202 = stack[0];
    v0202 = qcar(v0202);
    v0025 = v0202;
    v0025 = qcar(v0025);
    v0202 = qcdr(v0202);
    v0202 = Lset(nil, v0025, v0202);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-1];
    v0202 = stack[0];
    v0202 = qcdr(v0202);
    stack[0] = v0202;
    goto v0047;

v0033:
    v0202 = qvalue(elt(env, 5)); // rl_servl!*
    stack[0] = v0202;
    goto v0260;

v0260:
    v0202 = stack[0];
    if (v0202 == nil) goto v0031;
    v0202 = stack[0];
    v0202 = qcar(v0202);
    v0025 = v0202;
    v0202 = qvalue(elt(env, 2)); // nil
    v0202 = Lset(nil, v0025, v0202);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-1];
    v0202 = stack[0];
    v0202 = qcdr(v0202);
    stack[0] = v0202;
    goto v0260;

v0031:
    v0202 = qvalue(elt(env, 3)); // rl_cid!*
    v0025 = qcar(v0202);
    v0202 = elt(env, 6); // rl_services
    v0202 = get(v0025, v0202);
    env = stack[-1];
    stack[0] = v0202;
    goto v0259;

v0259:
    v0202 = stack[0];
    if (v0202 == nil) goto v0109;
    v0202 = stack[0];
    v0202 = qcar(v0202);
    v0025 = v0202;
    v0025 = qcar(v0025);
    v0202 = qcdr(v0202);
    v0202 = Lset(nil, v0025, v0202);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-1];
    v0202 = stack[0];
    v0202 = qcdr(v0202);
    stack[0] = v0202;
    goto v0259;

v0109:
    v0202 = qvalue(elt(env, 2)); // nil
    { popv(2); return onevalue(v0202); }
// error exit handlers
v0067:
    popv(2);
    return nil;
}



// Code for diff!-k!-times!-mod!-p

static LispObject CC_diffKkKtimesKmodKp(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0003, v0371, v0372;
    LispObject fn;
    LispObject v0058, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "diff-k-times-mod-p");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0058 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for diff-k-times-mod-p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0058,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0058);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0058;
    stack[-2] = v0001;
    stack[-3] = v0000;
// end of prologue
    v0003 = stack[-3];
    if (!consp(v0003)) goto v0060;
    v0003 = stack[-3];
    v0003 = qcar(v0003);
    v0003 = (consp(v0003) ? nil : lisp_true);
    goto v0098;

v0098:
    if (v0003 == nil) goto v0270;
    v0003 = qvalue(elt(env, 2)); // nil
    { popv(6); return onevalue(v0003); }

v0270:
    v0003 = stack[-3];
    v0003 = qcar(v0003);
    v0003 = qcar(v0003);
    v0371 = qcar(v0003);
    v0003 = stack[-1];
    if (equal(v0371, v0003)) goto v0078;
    v0003 = stack[-3];
    v0003 = qcar(v0003);
    v0372 = qcdr(v0003);
    v0371 = stack[-2];
    v0003 = stack[-1];
    stack[0] = CC_diffKkKtimesKmodKp(env, 3, v0372, v0371, v0003);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-5];
    v0003 = stack[-3];
    v0372 = qcdr(v0003);
    v0371 = stack[-2];
    v0003 = stack[-1];
    v0003 = CC_diffKkKtimesKmodKp(env, 3, v0372, v0371, v0003);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    v0371 = stack[0];
    v0372 = v0371;
    if (v0372 == nil) { popv(6); return onevalue(v0003); }
    v0372 = stack[-3];
    v0372 = qcar(v0372);
    v0372 = qcar(v0372);
    popv(6);
    return acons(v0372, v0371, v0003);

v0078:
    v0003 = stack[-3];
    v0003 = qcar(v0003);
    v0003 = qcar(v0003);
    v0371 = qcdr(v0003);
    v0003 = stack[-2];
    v0003 = (LispObject)lessp2(v0371, v0003);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    v0003 = v0003 ? lisp_true : nil;
    env = stack[-5];
    if (v0003 == nil) goto v0034;
    v0003 = qvalue(elt(env, 2)); // nil
    { popv(6); return onevalue(v0003); }

v0034:
    v0003 = stack[-3];
    v0003 = qcar(v0003);
    v0003 = qcar(v0003);
    v0371 = qcdr(v0003);
    v0003 = stack[-2];
    if (equal(v0371, v0003)) goto v0072;
    v0003 = stack[-3];
    v0003 = qcar(v0003);
    v0003 = qcar(v0003);
    v0371 = qcdr(v0003);
    v0003 = stack[-2];
    fn = elt(env, 3); // binomial!-coefft!-mod!-p
    v0371 = (*qfn2(fn))(qenv(fn), v0371, v0003);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-5];
    v0003 = stack[-3];
    v0003 = qcar(v0003);
    v0003 = qcdr(v0003);
    fn = elt(env, 4); // times!-mod!-p
    stack[0] = (*qfn2(fn))(qenv(fn), v0371, v0003);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-5];
    v0003 = stack[-3];
    v0372 = qcdr(v0003);
    v0371 = stack[-2];
    v0003 = stack[-1];
    v0003 = CC_diffKkKtimesKmodKp(env, 3, v0372, v0371, v0003);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-5];
    stack[-4] = stack[0];
    stack[0] = v0003;
    v0003 = stack[-4];
    if (v0003 == nil) { LispObject res = stack[0]; popv(6); return onevalue(res); }
    v0003 = stack[-3];
    v0003 = qcar(v0003);
    v0003 = qcar(v0003);
    v0371 = qcdr(v0003);
    v0003 = stack[-2];
    v0003 = difference2(v0371, v0003);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-5];
    fn = elt(env, 5); // mksp
    v0372 = (*qfn2(fn))(qenv(fn), stack[-1], v0003);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    v0371 = stack[-4];
    v0003 = stack[0];
    popv(6);
    return acons(v0372, v0371, v0003);

v0072:
    v0003 = stack[-3];
    v0003 = qcar(v0003);
    v0003 = qcdr(v0003);
    { popv(6); return onevalue(v0003); }

v0060:
    v0003 = qvalue(elt(env, 1)); // t
    goto v0098;
// error exit handlers
v0197:
    popv(6);
    return nil;
}



// Code for bvarml

static LispObject CC_bvarml(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0265, v0262;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for bvarml");
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
    v0265 = elt(env, 1); // "<bvar>"
    fn = elt(env, 5); // printout
    v0265 = (*qfn1(fn))(qenv(fn), v0265);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-1];
    v0265 = qvalue(elt(env, 2)); // t
    fn = elt(env, 6); // indent!*
    v0265 = (*qfn1(fn))(qenv(fn), v0265);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-1];
    v0265 = stack[0];
    v0265 = qcar(v0265);
    fn = elt(env, 7); // expression
    v0265 = (*qfn1(fn))(qenv(fn), v0265);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-1];
    v0265 = stack[0];
    v0265 = qcdr(v0265);
    v0262 = qcar(v0265);
    v0265 = (LispObject)17; // 1
    if (v0262 == v0265) goto v0095;
    v0265 = stack[0];
    v0265 = qcdr(v0265);
    v0265 = qcar(v0265);
    v0265 = ncons(v0265);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-1];
    fn = elt(env, 8); // degreeml
    v0265 = (*qfn1(fn))(qenv(fn), v0265);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-1];
    goto v0095;

v0095:
    v0265 = qvalue(elt(env, 3)); // nil
    fn = elt(env, 6); // indent!*
    v0265 = (*qfn1(fn))(qenv(fn), v0265);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-1];
    v0265 = elt(env, 4); // "</bvar>"
    fn = elt(env, 5); // printout
    v0265 = (*qfn1(fn))(qenv(fn), v0265);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    v0265 = nil;
    { popv(2); return onevalue(v0265); }
// error exit handlers
v0078:
    popv(2);
    return nil;
}



// Code for ps!:get!-term

static LispObject CC_psTgetKterm(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0065, v0375, v0102;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ps:get-term");
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
    v0065 = stack[-2];
    fn = elt(env, 4); // ps!:order
    stack[0] = (*qfn1(fn))(qenv(fn), v0065);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[-4];
    v0065 = stack[-2];
    fn = elt(env, 5); // ps!:last!-term
    v0065 = (*qfn1(fn))(qenv(fn), v0065);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[-4];
    stack[-3] = stack[0];
    stack[0] = v0065;
    v0375 = stack[-1];
    v0065 = stack[-3];
    v0065 = (LispObject)lessp2(v0375, v0065);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    v0065 = v0065 ? lisp_true : nil;
    env = stack[-4];
    if (v0065 == nil) goto v0045;
    v0375 = qvalue(elt(env, 1)); // nil
    v0065 = (LispObject)17; // 1
    popv(5);
    return cons(v0375, v0065);

v0045:
    v0375 = stack[-1];
    v0065 = stack[0];
    v0065 = (LispObject)greaterp2(v0375, v0065);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    v0065 = v0065 ? lisp_true : nil;
    env = stack[-4];
    if (v0065 == nil) goto v0068;
    v0065 = qvalue(elt(env, 1)); // nil
    { popv(5); return onevalue(v0065); }

v0068:
    v0375 = stack[-1];
    v0065 = stack[-3];
    stack[0] = difference2(v0375, v0065);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[-4];
    v0065 = stack[-2];
    if (!consp(v0065)) goto v0355;
    v0065 = stack[-2];
    v0375 = qcar(v0065);
    v0065 = elt(env, 3); // !:ps!:
    if (v0375 == v0065) goto v0328;
    v0065 = stack[-2];
    v0065 = qcar(v0065);
    if (!symbolp(v0065)) v0065 = nil;
    else { v0065 = qfastgets(v0065);
           if (v0065 != nil) { v0065 = elt(v0065, 8); // dname
#ifdef RECORD_GET
             if (v0065 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v0065 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v0065 == SPID_NOPROP) v0065 = nil; }}
#endif
    goto v0267;

v0267:
    if (v0065 == nil) goto v0088;
    v0102 = (LispObject)1; // 0
    v0375 = stack[-2];
    v0065 = (LispObject)17; // 1
    v0065 = list2star(v0102, v0375, v0065);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[-4];
    v0065 = ncons(v0065);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[-4];
    goto v0072;

v0072:
    v0065 = Lassoc(nil, stack[0], v0065);
    v0375 = v0065;
    v0065 = v0375;
    if (v0065 == nil) goto v0368;
    v0065 = v0375;
    v0065 = qcdr(v0065);
    { popv(5); return onevalue(v0065); }

v0368:
    v0375 = qvalue(elt(env, 1)); // nil
    v0065 = (LispObject)17; // 1
    popv(5);
    return cons(v0375, v0065);

v0088:
    v0375 = stack[-2];
    v0065 = (LispObject)81; // 5
    fn = elt(env, 6); // ps!:getv
    v0065 = (*qfn2(fn))(qenv(fn), v0375, v0065);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[-4];
    goto v0072;

v0328:
    v0065 = qvalue(elt(env, 1)); // nil
    goto v0267;

v0355:
    v0065 = qvalue(elt(env, 2)); // t
    goto v0267;
// error exit handlers
v0023:
    popv(5);
    return nil;
}



// Code for mktails

static LispObject CC_mktails(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0049, v0261, v0204;
    LispObject fn;
    LispObject v0058, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "mktails");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0058 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mktails");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0058,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0058);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    v0261 = v0058;
    stack[-2] = v0001;
    v0204 = v0000;
// end of prologue
    stack[0] = nil;
    v0049 = v0204;
    if (v0049 == nil) goto v0038;
    v0049 = v0204;
    stack[-3] = v0049;
    v0049 = v0261;
    stack[-1] = v0049;
    goto v0033;

v0033:
    v0049 = stack[-3];
    if (v0049 == nil) goto v0206;
    v0049 = stack[-3];
    v0204 = qcar(v0049);
    v0261 = stack[-2];
    v0049 = stack[-1];
    fn = elt(env, 2); // mktails1
    v0049 = (*qfnn(fn))(qenv(fn), 3, v0204, v0261, v0049);
    nil = C_nil;
    if (exception_pending()) goto v0376;
    env = stack[-4];
    v0261 = v0049;
    v0049 = v0261;
    v0049 = qcdr(v0049);
    stack[-1] = v0049;
    v0049 = v0261;
    v0261 = qcar(v0049);
    v0049 = stack[0];
    v0049 = Lappend(nil, v0261, v0049);
    nil = C_nil;
    if (exception_pending()) goto v0376;
    env = stack[-4];
    stack[0] = v0049;
    v0049 = stack[-3];
    v0049 = qcdr(v0049);
    stack[-3] = v0049;
    goto v0033;

v0206:
    v0261 = stack[0];
    v0049 = stack[-1];
    popv(5);
    return cons(v0261, v0049);

v0038:
    v0049 = qvalue(elt(env, 1)); // nil
    popv(5);
    return cons(v0049, v0261);
// error exit handlers
v0376:
    popv(5);
    return nil;
}



// Code for splitcomplex

static LispObject CC_splitcomplex(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0117, v0356;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for splitcomplex");
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
    v0356 = qvalue(elt(env, 1)); // kord!*
    v0117 = qvalue(elt(env, 2)); // t
    stack[-3] = qvalue(elt(env, 1)); // kord!*
    qvalue(elt(env, 1)) = v0356; // kord!*
    stack[-2] = qvalue(elt(env, 3)); // !*exp
    qvalue(elt(env, 3)) = v0117; // !*exp
    v0117 = elt(env, 4); // i
    if (!symbolp(v0117)) v0117 = nil;
    else { v0117 = qfastgets(v0117);
           if (v0117 != nil) { v0117 = elt(v0117, 56); // idvalfn
#ifdef RECORD_GET
             if (v0117 != SPID_NOPROP)
                record_get(elt(fastget_names, 56), 1);
             else record_get(elt(fastget_names, 56), 0),
                v0117 = nil; }
           else record_get(elt(fastget_names, 56), 0); }
#else
             if (v0117 == SPID_NOPROP) v0117 = nil; }}
#endif
    if (v0117 == nil) goto v0214;
    v0117 = stack[0];
    fn = elt(env, 5); // expand!-imrepart
    v0117 = (*qfn1(fn))(qenv(fn), v0117);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    env = stack[-4];
    goto v0060;

v0060:
    stack[-1] = v0117;
    v0117 = stack[-1];
    fn = elt(env, 6); // take!-realpart
    stack[0] = (*qfn1(fn))(qenv(fn), v0117);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    env = stack[-4];
    v0117 = stack[-1];
    fn = elt(env, 7); // take!-impart
    v0117 = (*qfn1(fn))(qenv(fn), v0117);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    env = stack[-4];
    v0117 = cons(stack[0], v0117);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    env = stack[-4];
    qvalue(elt(env, 3)) = stack[-2]; // !*exp
    qvalue(elt(env, 1)) = stack[-3]; // kord!*
    { popv(5); return onevalue(v0117); }

v0214:
    v0356 = elt(env, 4); // i
    v0117 = stack[0];
    v0117 = Lsmemq(nil, v0356, v0117);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    env = stack[-4];
    if (v0117 == nil) goto v0082;
    v0356 = elt(env, 4); // i
    v0117 = qvalue(elt(env, 1)); // kord!*
    v0117 = cons(v0356, v0117);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    env = stack[-4];
    fn = elt(env, 8); // setkorder
    v0117 = (*qfn1(fn))(qenv(fn), v0117);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    env = stack[-4];
    v0117 = stack[0];
    fn = elt(env, 9); // reorder
    v0117 = (*qfn1(fn))(qenv(fn), v0117);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    env = stack[-4];
    stack[0] = v0117;
    goto v0082;

v0082:
    v0117 = stack[0];
    fn = elt(env, 5); // expand!-imrepart
    v0117 = (*qfn1(fn))(qenv(fn), v0117);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    env = stack[-4];
    fn = elt(env, 10); // subs2
    v0117 = (*qfn1(fn))(qenv(fn), v0117);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    env = stack[-4];
    goto v0060;
// error exit handlers
v0207:
    env = stack[-4];
    qvalue(elt(env, 3)) = stack[-2]; // !*exp
    qvalue(elt(env, 1)) = stack[-3]; // kord!*
    popv(5);
    return nil;
}



// Code for red_topredbe

static LispObject CC_red_topredbe(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0354, v0029;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for red_topredbe");
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
    v0354 = stack[-1];
    fn = elt(env, 4); // bas_dpoly
    v0354 = (*qfn1(fn))(qenv(fn), v0354);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    if (v0354 == nil) goto v0098;
    v0354 = stack[-2];
    v0354 = (v0354 == nil ? lisp_true : nil);
    goto v0059;

v0059:
    if (!(v0354 == nil)) { LispObject res = stack[-1]; popv(5); return onevalue(res); }
    fn = elt(env, 5); // cali_trace
    v0029 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    v0354 = (LispObject)1265; // 79
    v0354 = (LispObject)greaterp2(v0029, v0354);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    v0354 = v0354 ? lisp_true : nil;
    env = stack[-4];
    if (v0354 == nil) goto v0091;
    v0354 = elt(env, 2); // " reduce "
    v0354 = Lprinc(nil, v0354);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    v0354 = stack[-1];
    fn = elt(env, 4); // bas_dpoly
    v0354 = (*qfn1(fn))(qenv(fn), v0354);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    fn = elt(env, 6); // dp_print
    v0354 = (*qfn1(fn))(qenv(fn), v0354);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    goto v0091;

v0091:
    v0354 = stack[-1];
    fn = elt(env, 4); // bas_dpoly
    v0354 = (*qfn1(fn))(qenv(fn), v0354);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    v0029 = v0354;
    if (v0354 == nil) { LispObject res = stack[-1]; popv(5); return onevalue(res); }
    stack[-3] = stack[-2];
    v0354 = v0029;
    fn = elt(env, 7); // dp_lmon
    stack[0] = (*qfn1(fn))(qenv(fn), v0354);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    v0354 = stack[-1];
    fn = elt(env, 8); // bas_dpecart
    v0354 = (*qfn1(fn))(qenv(fn), v0354);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    fn = elt(env, 9); // red_divtestbe
    v0029 = (*qfnn(fn))(qenv(fn), 3, stack[-3], stack[0], v0354);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    v0354 = v0029;
    if (v0029 == nil) { LispObject res = stack[-1]; popv(5); return onevalue(res); }
    v0029 = stack[-1];
    fn = elt(env, 10); // red_subst
    v0354 = (*qfn2(fn))(qenv(fn), v0029, v0354);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    stack[-1] = v0354;
    goto v0091;

v0098:
    v0354 = qvalue(elt(env, 1)); // t
    goto v0059;
// error exit handlers
v0111:
    popv(5);
    return nil;
}



// Code for gcdout

static LispObject CC_gcdout(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0259, v0377, v0031;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gcdout");
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
    v0259 = qvalue(elt(env, 1)); // !*modular
    if (!(v0259 == nil)) { LispObject res = stack[0]; popv(3); return onevalue(res); }
    v0259 = stack[0];
    if (v0259 == nil) goto v0059;
    v0259 = stack[0];
    fn = elt(env, 3); // ljet
    v0259 = (*qfn1(fn))(qenv(fn), v0259);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-2];
    fn = elt(env, 4); // ord
    v0377 = (*qfn1(fn))(qenv(fn), v0259);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-2];
    v0259 = (LispObject)1; // 0
    if (v0377 == v0259) { LispObject res = stack[0]; popv(3); return onevalue(res); }
    v0259 = stack[0];
    stack[-1] = v0259;
    v0259 = stack[-1];
    v0259 = qcar(v0259);
    v0259 = qcdr(v0259);
    v0031 = v0259;
    goto v0329;

v0329:
    v0259 = stack[-1];
    if (v0259 == nil) goto v0261;
    v0377 = v0031;
    v0259 = (LispObject)17; // 1
    if (v0377 == v0259) goto v0261;
    v0377 = v0031;
    v0259 = stack[-1];
    v0259 = qcar(v0259);
    v0259 = qcdr(v0259);
    fn = elt(env, 5); // gcdf!*
    v0259 = (*qfn2(fn))(qenv(fn), v0377, v0259);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-2];
    v0031 = v0259;
    v0259 = stack[-1];
    v0259 = qcdr(v0259);
    stack[-1] = v0259;
    goto v0329;

v0261:
    v0377 = v0031;
    v0259 = (LispObject)17; // 1
    if (v0377 == v0259) { LispObject res = stack[0]; popv(3); return onevalue(res); }
    v0259 = stack[0];
    v0377 = v0031;
    {
        popv(3);
        fn = elt(env, 6); // pcdiv
        return (*qfn2(fn))(qenv(fn), v0259, v0377);
    }

v0059:
    v0259 = qvalue(elt(env, 2)); // nil
    { popv(3); return onevalue(v0259); }
// error exit handlers
v0069:
    popv(3);
    return nil;
}



// Code for ilog2

static LispObject CC_ilog2(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0051, v0065;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ilog2");
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
    v0065 = stack[-2];
    v0051 = (LispObject)1; // 0
    v0051 = (LispObject)lesseq2(v0065, v0051);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    v0051 = v0051 ? lisp_true : nil;
    env = stack[-4];
    if (v0051 == nil) goto v0059;
    v0065 = stack[-2];
    v0051 = elt(env, 0); // ilog2
    fn = elt(env, 2); // terrlst
    v0051 = (*qfn2(fn))(qenv(fn), v0065, v0051);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-4];
    goto v0059;

v0059:
    v0051 = (LispObject)33; // 2
    stack[0] = v0051;
    v0051 = stack[0];
    v0051 = ncons(v0051);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-4];
    stack[-1] = v0051;
    goto v0374;

v0374:
    v0065 = stack[-2];
    v0051 = stack[0];
    v0051 = (LispObject)greaterp2(v0065, v0051);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    v0051 = v0051 ? lisp_true : nil;
    env = stack[-4];
    if (v0051 == nil) goto v0036;
    v0065 = stack[0];
    v0051 = stack[-1];
    v0051 = cons(v0065, v0051);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-4];
    stack[-1] = v0051;
    v0065 = stack[0];
    v0051 = stack[0];
    v0051 = times2(v0065, v0051);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-4];
    stack[0] = v0051;
    goto v0374;

v0036:
    v0051 = (LispObject)1; // 0
    stack[-3] = v0051;
    goto v0258;

v0258:
    v0051 = stack[-1];
    v0065 = qcar(v0051);
    stack[0] = v0065;
    v0051 = (LispObject)33; // 2
    if (v0065 == v0051) goto v0202;
    v0051 = stack[-1];
    v0051 = qcdr(v0051);
    stack[-1] = v0051;
    v0065 = stack[-2];
    v0051 = stack[0];
    v0051 = (LispObject)geq2(v0065, v0051);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    v0051 = v0051 ? lisp_true : nil;
    env = stack[-4];
    if (v0051 == nil) goto v0327;
    v0065 = stack[-2];
    v0051 = stack[0];
    v0051 = quot2(v0065, v0051);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-4];
    stack[-2] = v0051;
    v0051 = stack[-3];
    v0051 = add1(v0051);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-4];
    stack[-3] = v0051;
    goto v0327;

v0327:
    v0065 = stack[-3];
    v0051 = (LispObject)33; // 2
    v0051 = times2(v0065, v0051);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-4];
    stack[-3] = v0051;
    goto v0258;

v0202:
    v0065 = stack[-2];
    v0051 = (LispObject)33; // 2
    v0051 = (LispObject)geq2(v0065, v0051);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    v0051 = v0051 ? lisp_true : nil;
    env = stack[-4];
    if (v0051 == nil) { LispObject res = stack[-3]; popv(5); return onevalue(res); }
    v0051 = stack[-3];
    v0051 = add1(v0051);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    stack[-3] = v0051;
    { LispObject res = stack[-3]; popv(5); return onevalue(res); }
// error exit handlers
v0199:
    popv(5);
    return nil;
}



// Code for lalr_make_gotos

static LispObject CC_lalr_make_gotos(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0186, v0187, v0341;
    LispObject fn;
    argcheck(nargs, 0, "lalr_make_gotos");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lalr_make_gotos");
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
    stack[-4] = nil;
    stack[-3] = nil;
    v0186 = (LispObject)1; // 0
    stack[-5] = v0186;
    v0186 = qvalue(elt(env, 1)); // goto_cache
    fn = elt(env, 15); // hashcontents
    v0187 = (*qfn1(fn))(qenv(fn), v0186);
    nil = C_nil;
    if (exception_pending()) goto v0220;
    env = stack[-7];
    v0186 = elt(env, 2); // ordp
    fn = elt(env, 16); // sort
    v0186 = (*qfn2(fn))(qenv(fn), v0187, v0186);
    nil = C_nil;
    if (exception_pending()) goto v0220;
    env = stack[-7];
    stack[-2] = v0186;
    goto v0094;

v0094:
    v0186 = stack[-2];
    if (v0186 == nil) goto v0060;
    v0186 = stack[-2];
    v0186 = qcar(v0186);
    stack[-1] = v0186;
    v0186 = stack[-1];
    v0186 = qcar(v0186);
    if (is_number(v0186)) goto v0036;
    v0186 = qvalue(elt(env, 4)); // !*lalr_verbose
    if (v0186 == nil) goto v0084;
    v0186 = stack[-1];
    v0186 = qcdr(v0186);
    stack[-6] = v0186;
    goto v0092;

v0092:
    v0186 = stack[-6];
    if (v0186 == nil) goto v0084;
    v0186 = stack[-6];
    v0186 = qcar(v0186);
    stack[0] = v0186;
    v0186 = stack[0];
    v0186 = qcar(v0186);
    v0186 = Lprin(nil, v0186);
    nil = C_nil;
    if (exception_pending()) goto v0220;
    env = stack[-7];
    v0186 = (LispObject)161; // 10
    v0186 = Lttab(nil, v0186);
    nil = C_nil;
    if (exception_pending()) goto v0220;
    env = stack[-7];
    v0186 = stack[-1];
    v0186 = qcar(v0186);
    fn = elt(env, 17); // lalr_prin_symbol
    v0186 = (*qfn1(fn))(qenv(fn), v0186);
    nil = C_nil;
    if (exception_pending()) goto v0220;
    env = stack[-7];
    v0186 = elt(env, 5); // " GOTO state "
    v0186 = Lprinc(nil, v0186);
    nil = C_nil;
    if (exception_pending()) goto v0220;
    env = stack[-7];
    v0186 = stack[0];
    v0186 = qcdr(v0186);
    v0186 = Lprin(nil, v0186);
    nil = C_nil;
    if (exception_pending()) goto v0220;
    env = stack[-7];
    v0186 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0220;
    env = stack[-7];
    v0186 = stack[-6];
    v0186 = qcdr(v0186);
    stack[-6] = v0186;
    goto v0092;

v0084:
    v0186 = stack[-1];
    v0187 = qcar(v0186);
    v0186 = elt(env, 6); // non_terminal_code
    v0186 = get(v0187, v0186);
    env = stack[-7];
    stack[-6] = v0186;
    v0186 = stack[-6];
    v0186 = integerp(v0186);
    if (!(v0186 == nil)) goto v0326;
    stack[0] = (LispObject)1585; // 99
    v0341 = elt(env, 0); // lalr_make_gotos
    v0187 = stack[-1];
    v0186 = stack[-6];
    v0186 = list3(v0341, v0187, v0186);
    nil = C_nil;
    if (exception_pending()) goto v0220;
    env = stack[-7];
    fn = elt(env, 18); // error
    v0186 = (*qfn2(fn))(qenv(fn), stack[0], v0186);
    nil = C_nil;
    if (exception_pending()) goto v0220;
    env = stack[-7];
    goto v0326;

v0326:
    v0341 = stack[-6];
    v0187 = stack[-5];
    v0186 = stack[-4];
    v0186 = acons(v0341, v0187, v0186);
    nil = C_nil;
    if (exception_pending()) goto v0220;
    env = stack[-7];
    stack[-4] = v0186;
    v0186 = stack[-1];
    v0186 = qcdr(v0186);
    if (v0186 == nil) goto v0036;
    v0186 = stack[-1];
    v0186 = qcdr(v0186);
    fn = elt(env, 19); // lalr_most_common_dest
    v0186 = (*qfn1(fn))(qenv(fn), v0186);
    nil = C_nil;
    if (exception_pending()) goto v0220;
    env = stack[-7];
    stack[-6] = v0186;
    v0186 = stack[-1];
    v0186 = qcdr(v0186);
    stack[0] = v0186;
    goto v0065;

v0065:
    v0186 = stack[0];
    if (v0186 == nil) goto v0085;
    v0186 = stack[0];
    v0186 = qcar(v0186);
    v0341 = v0186;
    v0186 = v0341;
    v0187 = qcdr(v0186);
    v0186 = stack[-6];
    if (equal(v0187, v0186)) goto v0061;
    v0187 = v0341;
    v0186 = stack[-3];
    v0186 = cons(v0187, v0186);
    nil = C_nil;
    if (exception_pending()) goto v0220;
    env = stack[-7];
    stack[-3] = v0186;
    v0186 = stack[-5];
    v0186 = add1(v0186);
    nil = C_nil;
    if (exception_pending()) goto v0220;
    env = stack[-7];
    stack[-5] = v0186;
    goto v0061;

v0061:
    v0186 = stack[0];
    v0186 = qcdr(v0186);
    stack[0] = v0186;
    goto v0065;

v0085:
    v0341 = (LispObject)-15; // -1
    v0187 = stack[-6];
    v0186 = stack[-3];
    v0186 = acons(v0341, v0187, v0186);
    nil = C_nil;
    if (exception_pending()) goto v0220;
    env = stack[-7];
    stack[-3] = v0186;
    v0186 = stack[-5];
    v0186 = add1(v0186);
    nil = C_nil;
    if (exception_pending()) goto v0220;
    env = stack[-7];
    stack[-5] = v0186;
    goto v0036;

v0036:
    v0186 = stack[-2];
    v0186 = qcdr(v0186);
    stack[-2] = v0186;
    goto v0094;

v0060:
    v0186 = qvalue(elt(env, 7)); // non_terminals
    v0186 = Llength(nil, v0186);
    nil = C_nil;
    if (exception_pending()) goto v0220;
    env = stack[-7];
    v0186 = sub1(v0186);
    nil = C_nil;
    if (exception_pending()) goto v0220;
    env = stack[-7];
    fn = elt(env, 20); // mkvect16
    v0186 = (*qfn1(fn))(qenv(fn), v0186);
    nil = C_nil;
    if (exception_pending()) goto v0220;
    env = stack[-7];
    qvalue(elt(env, 8)) = v0186; // goto_index
    v0186 = elt(env, 9); // "goto table size = "
    v0186 = Lprinc(nil, v0186);
    nil = C_nil;
    if (exception_pending()) goto v0220;
    env = stack[-7];
    v0186 = stack[-5];
    v0186 = Lprint(nil, v0186);
    nil = C_nil;
    if (exception_pending()) goto v0220;
    env = stack[-7];
    v0186 = stack[-5];
    v0186 = sub1(v0186);
    nil = C_nil;
    if (exception_pending()) goto v0220;
    env = stack[-7];
    fn = elt(env, 20); // mkvect16
    v0186 = (*qfn1(fn))(qenv(fn), v0186);
    nil = C_nil;
    if (exception_pending()) goto v0220;
    env = stack[-7];
    qvalue(elt(env, 10)) = v0186; // goto_old_state
    v0186 = stack[-5];
    v0186 = sub1(v0186);
    nil = C_nil;
    if (exception_pending()) goto v0220;
    env = stack[-7];
    fn = elt(env, 20); // mkvect16
    v0186 = (*qfn1(fn))(qenv(fn), v0186);
    nil = C_nil;
    if (exception_pending()) goto v0220;
    env = stack[-7];
    qvalue(elt(env, 11)) = v0186; // goto_new_state
    v0186 = stack[-4];
    stack[0] = v0186;
    goto v0390;

v0390:
    v0186 = stack[0];
    if (v0186 == nil) goto v0391;
    v0186 = stack[0];
    v0186 = qcar(v0186);
    v0341 = qvalue(elt(env, 8)); // goto_index
    v0187 = v0186;
    v0187 = qcar(v0187);
    v0186 = qcdr(v0186);
    fn = elt(env, 21); // putv16
    v0186 = (*qfnn(fn))(qenv(fn), 3, v0341, v0187, v0186);
    nil = C_nil;
    if (exception_pending()) goto v0220;
    env = stack[-7];
    v0186 = stack[0];
    v0186 = qcdr(v0186);
    stack[0] = v0186;
    goto v0390;

v0391:
    v0187 = stack[-5];
    v0186 = (LispObject)1; // 0
    v0186 = (LispObject)greaterp2(v0187, v0186);
    nil = C_nil;
    if (exception_pending()) goto v0220;
    v0186 = v0186 ? lisp_true : nil;
    env = stack[-7];
    if (v0186 == nil) goto v0392;
    v0186 = stack[-5];
    v0186 = sub1(v0186);
    nil = C_nil;
    if (exception_pending()) goto v0220;
    env = stack[-7];
    stack[-5] = v0186;
    v0341 = qvalue(elt(env, 10)); // goto_old_state
    v0187 = stack[-5];
    v0186 = stack[-3];
    v0186 = qcar(v0186);
    v0186 = qcar(v0186);
    fn = elt(env, 21); // putv16
    v0186 = (*qfnn(fn))(qenv(fn), 3, v0341, v0187, v0186);
    nil = C_nil;
    if (exception_pending()) goto v0220;
    env = stack[-7];
    v0341 = qvalue(elt(env, 11)); // goto_new_state
    v0187 = stack[-5];
    v0186 = stack[-3];
    v0186 = qcar(v0186);
    v0186 = qcdr(v0186);
    fn = elt(env, 21); // putv16
    v0186 = (*qfnn(fn))(qenv(fn), 3, v0341, v0187, v0186);
    nil = C_nil;
    if (exception_pending()) goto v0220;
    env = stack[-7];
    v0186 = stack[-3];
    v0186 = qcdr(v0186);
    stack[-3] = v0186;
    goto v0391;

v0392:
    v0186 = qvalue(elt(env, 4)); // !*lalr_verbose
    if (v0186 == nil) goto v0315;
    v0186 = elt(env, 12); // "goto_index: "
    v0186 = Lprinc(nil, v0186);
    nil = C_nil;
    if (exception_pending()) goto v0220;
    env = stack[-7];
    v0186 = qvalue(elt(env, 8)); // goto_index
    fn = elt(env, 22); // lalr_print_shortnum_vector
    v0186 = (*qfn1(fn))(qenv(fn), v0186);
    nil = C_nil;
    if (exception_pending()) goto v0220;
    env = stack[-7];
    v0186 = elt(env, 13); // "goto_old_state: "
    v0186 = Lprinc(nil, v0186);
    nil = C_nil;
    if (exception_pending()) goto v0220;
    env = stack[-7];
    v0186 = qvalue(elt(env, 10)); // goto_old_state
    fn = elt(env, 22); // lalr_print_shortnum_vector
    v0186 = (*qfn1(fn))(qenv(fn), v0186);
    nil = C_nil;
    if (exception_pending()) goto v0220;
    env = stack[-7];
    v0186 = elt(env, 14); // "goto_new_state: "
    v0186 = Lprinc(nil, v0186);
    nil = C_nil;
    if (exception_pending()) goto v0220;
    env = stack[-7];
    v0186 = qvalue(elt(env, 11)); // goto_new_state
    fn = elt(env, 22); // lalr_print_shortnum_vector
    v0186 = (*qfn1(fn))(qenv(fn), v0186);
    nil = C_nil;
    if (exception_pending()) goto v0220;
    goto v0315;

v0315:
    v0186 = nil;
    { popv(8); return onevalue(v0186); }
// error exit handlers
v0220:
    popv(8);
    return nil;
}



setup_type const u23_setup[] =
{
    {"poly-multfnc",            too_few_2,      CC_polyKmultfnc,wrong_no_2},
    {"pasf_sacat",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_pasf_sacat},
    {"unaryrd",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_unaryrd},
    {"my_letmtr",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_my_letmtr},
    {"numlist_ordp",            too_few_2,      CC_numlist_ordp,wrong_no_2},
    {"lambda_u9iz36vfudu4",     too_few_2,      CC_lambda_u9iz36vfudu4,wrong_no_2},
    {"subf",                    too_few_2,      CC_subf,       wrong_no_2},
    {"riv_mk",                  too_few_2,      CC_riv_mk,     wrong_no_2},
    {"lex_basic_token",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_lex_basic_token},
    {"refprint",                CC_refprint,    too_many_1,    wrong_no_1},
    {"cl_pnf",                  CC_cl_pnf,      too_many_1,    wrong_no_1},
    {"bc_zero?",                CC_bc_zeroW,    too_many_1,    wrong_no_1},
    {"row",                     CC_row,         too_many_1,    wrong_no_1},
    {"rd:zerop:",               CC_rdTzeropT,   too_many_1,    wrong_no_1},
    {"dipev2f",                 too_few_2,      CC_dipev2f,    wrong_no_2},
    {"gbfdot",                  too_few_2,      CC_gbfdot,     wrong_no_2},
    {"red_totalred",            too_few_2,      CC_red_totalred,wrong_no_2},
    {"sfto_int2sf",             CC_sfto_int2sf, too_many_1,    wrong_no_1},
    {"lalr_set_grammar",        CC_lalr_set_grammar,too_many_1,wrong_no_1},
    {"ofsf_ignshift",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_ignshift},
    {"tripleisprolongedby",     too_few_2,      CC_tripleisprolongedby,wrong_no_2},
    {"ofsf_smupdknowl",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_smupdknowl},
    {"pasf_smwcpknowl",         CC_pasf_smwcpknowl,too_many_1, wrong_no_1},
    {"rl_updcache",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_rl_updcache},
    {"diff-k-times-mod-p",      wrong_no_na,    wrong_no_nb,   (n_args *)CC_diffKkKtimesKmodKp},
    {"bvarml",                  CC_bvarml,      too_many_1,    wrong_no_1},
    {"ps:get-term",             too_few_2,      CC_psTgetKterm,wrong_no_2},
    {"mktails",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_mktails},
    {"splitcomplex",            CC_splitcomplex,too_many_1,    wrong_no_1},
    {"red_topredbe",            too_few_2,      CC_red_topredbe,wrong_no_2},
    {"gcdout",                  CC_gcdout,      too_many_1,    wrong_no_1},
    {"ilog2",                   CC_ilog2,       too_many_1,    wrong_no_1},
    {"lalr_make_gotos",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_lalr_make_gotos},
    {NULL, (one_args *)"u23", (two_args *)"1939 2814862 6949736", 0}
};

// end of generated code
