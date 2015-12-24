
// $destdir/u09.c        Machine generated C code

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



// Code for token1

static LispObject CC_token1(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0141, v0142;
    LispObject fn;
    argcheck(nargs, 0, "token1");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for token1");
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
    stack[-2] = nil;
    v0141 = qvalue(elt(env, 1)); // crchar!*
    stack[-3] = v0141;
    goto v0143;

v0143:
    v0142 = stack[-3];
    v0141 = qvalue(elt(env, 2)); // !$eof!$
    if (v0142 == v0141) goto v0144;
    v0141 = stack[-3];
    fn = elt(env, 37); // id2string
    v0141 = (*qfn1(fn))(qenv(fn), v0141);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-4];
    fn = elt(env, 38); // string!-length
    v0142 = (*qfn1(fn))(qenv(fn), v0141);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-4];
    v0141 = (LispObject)17; // 1
    v0141 = (v0142 == v0141 ? lisp_true : nil);
    v0141 = (v0141 == nil ? lisp_true : nil);
    goto v0146;

v0146:
    if (!(v0141 == nil)) goto v0147;
    v0141 = stack[-3];
    v0141 = Lwhitespace_char_p(nil, v0141);
    env = stack[-4];
    if (v0141 == nil) goto v0148;
    v0142 = stack[-3];
    v0141 = qvalue(elt(env, 4)); // !$eol!$
    if (v0142 == v0141) goto v0149;
    v0141 = qvalue(elt(env, 6)); // nil
    goto v0150;

v0150:
    if (!(v0141 == nil)) goto v0148;
    fn = elt(env, 39); // readch1
    v0141 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-4];
    stack[-3] = v0141;
    goto v0143;

v0148:
    v0141 = stack[-3];
    v0141 = Ldigitp(nil, v0141);
    env = stack[-4];
    if (v0141 == nil) goto v0151;
    v0141 = stack[-3];
    {
        popv(5);
        fn = elt(env, 40); // token!-number
        return (*qfn1(fn))(qenv(fn), v0141);
    }

v0151:
    v0141 = stack[-3];
    v0141 = Lalpha_char_p(nil, v0141);
    env = stack[-4];
    if (!(v0141 == nil)) goto v0152;
    v0142 = stack[-3];
    v0141 = elt(env, 7); // tokprop
    v0141 = get(v0142, v0141);
    env = stack[-4];
    stack[-2] = v0141;
    if (v0141 == nil) goto v0153;
    v0142 = stack[-2];
    v0141 = qvalue(elt(env, 6)); // nil
    {
        popv(5);
        fn = elt(env, 41); // lispapply
        return (*qfn2(fn))(qenv(fn), v0142, v0141);
    }

v0153:
    v0142 = stack[-3];
    v0141 = elt(env, 8); // !%
    if (v0142 == v0141) goto v0154;
    v0141 = qvalue(elt(env, 6)); // nil
    goto v0155;

v0155:
    if (v0141 == nil) goto v0156;
    stack[-1] = qvalue(elt(env, 21)); // !*raise
    qvalue(elt(env, 21)) = nil; // !*raise
    stack[0] = qvalue(elt(env, 22)); // !*lower
    qvalue(elt(env, 22)) = nil; // !*lower
    goto v0157;

v0157:
    v0141 = qvalue(elt(env, 6)); // nil
    qvalue(elt(env, 35)) = v0141; // named!-character!*
    fn = elt(env, 39); // readch1
    v0142 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0158;
    env = stack[-4];
    stack[-3] = v0142;
    v0141 = qvalue(elt(env, 4)); // !$eol!$
    if (v0142 == v0141) goto v0159;
    v0142 = stack[-3];
    v0141 = qvalue(elt(env, 2)); // !$eof!$
    v0141 = (v0142 == v0141 ? lisp_true : nil);
    goto v0160;

v0160:
    if (v0141 == nil) goto v0161;
    v0141 = qvalue(elt(env, 35)); // named!-character!*
    goto v0162;

v0162:
    if (!(v0141 == nil)) goto v0157;
    qvalue(elt(env, 22)) = stack[0]; // !*lower
    qvalue(elt(env, 21)) = stack[-1]; // !*raise
    fn = elt(env, 39); // readch1
    v0141 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-4];
    stack[-3] = v0141;
    goto v0143;

v0161:
    v0141 = qvalue(elt(env, 3)); // t
    goto v0162;

v0159:
    v0141 = qvalue(elt(env, 3)); // t
    goto v0160;

v0156:
    v0142 = stack[-3];
    v0141 = elt(env, 10); // !!
    if (v0142 == v0141) goto v0163;
    v0141 = qvalue(elt(env, 6)); // nil
    goto v0164;

v0164:
    if (!(v0141 == nil)) goto v0165;
    v0142 = stack[-3];
    v0141 = elt(env, 13); // !"
    if (v0142 == v0141) goto v0166;
    v0142 = stack[-3];
    v0141 = elt(env, 14); // !\ (backslash)
    if (!(v0142 == v0141)) goto v0147;
    v0141 = elt(env, 31); // (!\ e n d !{ r e d u c e !})
    stack[-2] = v0141;
    v0141 = qvalue(elt(env, 6)); // nil
    stack[0] = v0141;
    goto v0167;

v0167:
    v0142 = stack[-3];
    v0141 = stack[0];
    v0141 = cons(v0142, v0141);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-4];
    stack[0] = v0141;
    fn = elt(env, 39); // readch1
    v0141 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-4];
    stack[-3] = v0141;
    v0141 = stack[-2];
    v0141 = qcdr(v0141);
    stack[-2] = v0141;
    v0141 = stack[-2];
    if (v0141 == nil) goto v0168;
    v0142 = stack[-3];
    v0141 = stack[-2];
    v0141 = qcar(v0141);
    if (v0142 == v0141) goto v0167;
    v0142 = stack[-3];
    v0141 = stack[0];
    v0141 = cons(v0142, v0141);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-4];
    v0141 = Lreverse(nil, v0141);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-4];
    v0141 = qcdr(v0141);
    qvalue(elt(env, 32)) = v0141; // peekchar!*
    v0141 = (LispObject)49; // 3
    qvalue(elt(env, 15)) = v0141; // ttype!*
    fn = elt(env, 39); // readch1
    v0141 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-4];
    qvalue(elt(env, 1)) = v0141; // crchar!*
    v0141 = elt(env, 14); // !\ (backslash)
    qvalue(elt(env, 17)) = v0141; // nxtsym!*
    v0141 = qvalue(elt(env, 17)); // nxtsym!*
    { popv(5); return onevalue(v0141); }

v0168:
    v0141 = elt(env, 33); // (!\ b e g i n !{ r e d u c e !})
    stack[-2] = v0141;
    v0141 = (LispObject)49; // 3
    qvalue(elt(env, 15)) = v0141; // ttype!*
    goto v0169;

v0169:
    v0142 = stack[-3];
    v0141 = elt(env, 8); // !%
    if (v0142 == v0141) goto v0170;
    v0142 = stack[-3];
    v0141 = qvalue(elt(env, 2)); // !$eof!$
    if (v0142 == v0141) goto v0171;
    v0141 = stack[-2];
    if (v0141 == nil) goto v0143;
    v0141 = stack[-3];
    stack[0] = v0141;
    fn = elt(env, 39); // readch1
    v0141 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-4];
    stack[-3] = v0141;
    v0142 = stack[0];
    v0141 = stack[-2];
    v0141 = qcar(v0141);
    if (!(v0142 == v0141)) goto v0168;
    v0141 = stack[-2];
    v0141 = qcdr(v0141);
    stack[-2] = v0141;
    goto v0169;

v0171:
    v0141 = elt(env, 16); // ! 
    qvalue(elt(env, 1)) = v0141; // crchar!*
    fn = elt(env, 42); // filenderr
    v0141 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-4];
    v0141 = stack[-3];
    qvalue(elt(env, 17)) = v0141; // nxtsym!*
    { LispObject res = stack[-3]; popv(5); return onevalue(res); }

v0170:
    fn = elt(env, 39); // readch1
    v0141 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-4];
    stack[-3] = v0141;
    v0142 = stack[-3];
    v0141 = qvalue(elt(env, 2)); // !$eof!$
    if (v0142 == v0141) goto v0169;
    v0142 = stack[-3];
    v0141 = qvalue(elt(env, 4)); // !$eol!$
    if (v0142 == v0141) goto v0168;
    else goto v0170;

v0147:
    v0141 = (LispObject)49; // 3
    qvalue(elt(env, 15)) = v0141; // ttype!*
    v0142 = stack[-3];
    v0141 = qvalue(elt(env, 2)); // !$eof!$
    if (!(v0142 == v0141)) goto v0172;
    v0141 = elt(env, 16); // ! 
    qvalue(elt(env, 1)) = v0141; // crchar!*
    fn = elt(env, 42); // filenderr
    v0141 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-4];
    goto v0172;

v0172:
    v0141 = stack[-3];
    qvalue(elt(env, 17)) = v0141; // nxtsym!*
    v0142 = stack[-3];
    v0141 = qvalue(elt(env, 2)); // !$eof!$
    if (v0142 == v0141) goto v0173;
    v0141 = stack[-3];
    fn = elt(env, 37); // id2string
    v0141 = (*qfn1(fn))(qenv(fn), v0141);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-4];
    fn = elt(env, 38); // string!-length
    v0142 = (*qfn1(fn))(qenv(fn), v0141);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-4];
    v0141 = (LispObject)17; // 1
    if (v0142 == v0141) goto v0174;
    v0141 = qvalue(elt(env, 6)); // nil
    goto v0175;

v0175:
    if (v0141 == nil) goto v0176;
    v0141 = elt(env, 16); // ! 
    qvalue(elt(env, 1)) = v0141; // crchar!*
    goto v0173;

v0173:
    v0142 = stack[-3];
    v0141 = elt(env, 18); // !-
    if (v0142 == v0141) goto v0177;
    v0141 = qvalue(elt(env, 6)); // nil
    goto v0178;

v0178:
    if (v0141 == nil) goto v0179;
    v0141 = qvalue(elt(env, 1)); // crchar!*
    fn = elt(env, 40); // token!-number
    v0141 = (*qfn1(fn))(qenv(fn), v0141);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-4];
    stack[-3] = v0141;
    v0141 = stack[-3];
    if (is_number(v0141)) goto v0180;
    v0141 = stack[-3];
    stack[0] = qcdr(v0141);
    v0142 = elt(env, 20); // minus
    v0141 = stack[-3];
    v0141 = qcdr(v0141);
    v0141 = qcar(v0141);
    v0141 = Lapply1(nil, v0142, v0141);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-4];
    v0141 = Lrplaca(nil, stack[0], v0141);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    { LispObject res = stack[-3]; popv(5); return onevalue(res); }

v0180:
    v0142 = elt(env, 20); // minus
    v0141 = stack[-3];
        popv(5);
        return Lapply1(nil, v0142, v0141);

v0179:
    v0141 = qvalue(elt(env, 17)); // nxtsym!*
    { popv(5); return onevalue(v0141); }

v0177:
    v0142 = qvalue(elt(env, 1)); // crchar!*
    v0141 = qvalue(elt(env, 2)); // !$eof!$
    if (v0142 == v0141) goto v0181;
    v0141 = qvalue(elt(env, 1)); // crchar!*
    fn = elt(env, 37); // id2string
    v0141 = (*qfn1(fn))(qenv(fn), v0141);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-4];
    fn = elt(env, 38); // string!-length
    v0142 = (*qfn1(fn))(qenv(fn), v0141);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-4];
    v0141 = (LispObject)17; // 1
    if (v0142 == v0141) goto v0182;
    v0141 = qvalue(elt(env, 6)); // nil
    goto v0178;

v0182:
    v0141 = qvalue(elt(env, 1)); // crchar!*
    v0141 = Ldigitp(nil, v0141);
    env = stack[-4];
    if (v0141 == nil) goto v0183;
    v0141 = qvalue(elt(env, 19)); // !*minusliter
    goto v0178;

v0183:
    v0141 = qvalue(elt(env, 6)); // nil
    goto v0178;

v0181:
    v0141 = qvalue(elt(env, 6)); // nil
    goto v0178;

v0176:
    fn = elt(env, 39); // readch1
    v0141 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-4];
    qvalue(elt(env, 1)) = v0141; // crchar!*
    goto v0173;

v0174:
    v0141 = stack[-3];
    fn = elt(env, 43); // delcp
    v0141 = (*qfn1(fn))(qenv(fn), v0141);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-4];
    goto v0175;

v0166:
    stack[-1] = qvalue(elt(env, 21)); // !*raise
    qvalue(elt(env, 21)) = nil; // !*raise
    stack[0] = qvalue(elt(env, 22)); // !*lower
    qvalue(elt(env, 22)) = nil; // !*lower
    goto v0184;

v0184:
    v0141 = stack[-3];
    fn = elt(env, 44); // wideid2list
    v0141 = (*qfn1(fn))(qenv(fn), v0141);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-4];
    stack[-3] = v0141;
    goto v0186;

v0186:
    v0141 = stack[-3];
    if (v0141 == nil) goto v0187;
    v0141 = stack[-3];
    v0142 = qcar(v0141);
    v0141 = stack[-2];
    v0141 = cons(v0142, v0141);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-4];
    stack[-2] = v0141;
    v0141 = stack[-3];
    v0141 = qcdr(v0141);
    stack[-3] = v0141;
    goto v0186;

v0187:
    v0141 = qvalue(elt(env, 6)); // nil
    qvalue(elt(env, 35)) = v0141; // named!-character!*
    fn = elt(env, 39); // readch1
    v0142 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-4];
    stack[-3] = v0142;
    v0141 = qvalue(elt(env, 2)); // !$eof!$
    if (v0142 == v0141) goto v0188;
    v0142 = stack[-3];
    v0141 = elt(env, 13); // !"
    if (v0142 == v0141) goto v0189;
    v0141 = qvalue(elt(env, 3)); // t
    goto v0190;

v0190:
    if (!(v0141 == nil)) goto v0184;

v0191:
    v0141 = qvalue(elt(env, 6)); // nil
    qvalue(elt(env, 35)) = v0141; // named!-character!*
    fn = elt(env, 39); // readch1
    v0141 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-4];
    stack[-3] = v0141;
    v0142 = stack[-3];
    v0141 = elt(env, 13); // !"
    if (v0142 == v0141) goto v0192;
    v0141 = qvalue(elt(env, 6)); // nil
    goto v0193;

v0193:
    if (!(v0141 == nil)) goto v0184;
    v0141 = stack[-2];
    fn = elt(env, 45); // reversip!*
    v0141 = (*qfn1(fn))(qenv(fn), v0141);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-4];
    v0141 = qcdr(v0141);
    fn = elt(env, 46); // list2widestring
    v0141 = (*qfn1(fn))(qenv(fn), v0141);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-4];
    qvalue(elt(env, 17)) = v0141; // nxtsym!*
    qvalue(elt(env, 22)) = stack[0]; // !*lower
    qvalue(elt(env, 21)) = stack[-1]; // !*raise
    v0141 = (LispObject)17; // 1
    qvalue(elt(env, 15)) = v0141; // ttype!*
    v0141 = stack[-3];
    qvalue(elt(env, 1)) = v0141; // crchar!*
    goto v0179;

v0192:
    v0141 = qvalue(elt(env, 35)); // named!-character!*
    v0141 = (v0141 == nil ? lisp_true : nil);
    goto v0193;

v0189:
    v0141 = qvalue(elt(env, 35)); // named!-character!*
    goto v0190;

v0188:
    v0141 = elt(env, 16); // ! 
    qvalue(elt(env, 1)) = v0141; // crchar!*
    v0142 = elt(env, 36); // "***** End-of-file in string"
    v0141 = qvalue(elt(env, 6)); // nil
    fn = elt(env, 47); // lpriw
    v0141 = (*qfn2(fn))(qenv(fn), v0142, v0141);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-4];
    fn = elt(env, 42); // filenderr
    v0141 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-4];
    goto v0191;

v0165:
    stack[-1] = qvalue(elt(env, 21)); // !*raise
    qvalue(elt(env, 21)) = nil; // !*raise
    stack[0] = qvalue(elt(env, 22)); // !*lower
    qvalue(elt(env, 22)) = nil; // !*lower
    v0141 = qvalue(elt(env, 3)); // t
    qvalue(elt(env, 23)) = v0141; // escaped!*
    fn = elt(env, 39); // readch1
    v0141 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0194;
    env = stack[-4];
    stack[-3] = v0141;
    v0141 = stack[-3];
    v0141 = Lalpha_char_p(nil, v0141);
    env = stack[-4];
    if (v0141 == nil) goto v0195;
    v0141 = qvalue(elt(env, 3)); // t
    qvalue(elt(env, 23)) = v0141; // escaped!*
    goto v0195;

v0195:
    qvalue(elt(env, 22)) = stack[0]; // !*lower
    qvalue(elt(env, 21)) = stack[-1]; // !*raise
    goto v0152;

v0152:
    v0141 = (LispObject)1; // 0
    qvalue(elt(env, 15)) = v0141; // ttype!*
    goto v0196;

v0196:
    v0141 = stack[-3];
    fn = elt(env, 44); // wideid2list
    v0141 = (*qfn1(fn))(qenv(fn), v0141);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-4];
    stack[-3] = v0141;
    goto v0197;

v0197:
    v0141 = stack[-3];
    if (v0141 == nil) goto v0198;
    v0141 = stack[-3];
    v0142 = qcar(v0141);
    v0141 = stack[-2];
    v0141 = cons(v0142, v0141);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-4];
    stack[-2] = v0141;
    v0141 = stack[-3];
    v0141 = qcdr(v0141);
    stack[-3] = v0141;
    goto v0197;

v0198:
    fn = elt(env, 39); // readch1
    v0141 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-4];
    stack[-3] = v0141;
    v0142 = stack[-3];
    v0141 = qvalue(elt(env, 2)); // !$eof!$
    if (v0142 == v0141) goto v0199;
    v0141 = qvalue(elt(env, 1)); // crchar!*
    fn = elt(env, 37); // id2string
    v0141 = (*qfn1(fn))(qenv(fn), v0141);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-4];
    fn = elt(env, 38); // string!-length
    v0142 = (*qfn1(fn))(qenv(fn), v0141);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-4];
    v0141 = (LispObject)17; // 1
    v0141 = (v0142 == v0141 ? lisp_true : nil);
    v0141 = (v0141 == nil ? lisp_true : nil);
    goto v0200;

v0200:
    if (!(v0141 == nil)) goto v0201;
    v0141 = stack[-3];
    v0141 = Ldigitp(nil, v0141);
    env = stack[-4];
    if (!(v0141 == nil)) goto v0196;
    v0141 = stack[-3];
    v0141 = Lalpha_char_p(nil, v0141);
    env = stack[-4];
    if (!(v0141 == nil)) goto v0196;
    v0142 = stack[-3];
    v0141 = elt(env, 10); // !!
    if (v0142 == v0141) goto v0165;
    v0142 = stack[-3];
    v0141 = elt(env, 18); // !-
    if (v0142 == v0141) goto v0202;
    v0141 = qvalue(elt(env, 6)); // nil
    goto v0203;

v0203:
    if (!(v0141 == nil)) goto v0196;
    v0142 = stack[-3];
    v0141 = elt(env, 24); // !_
    if (v0142 == v0141) goto v0196;
    v0142 = stack[-3];
    v0141 = elt(env, 25); // !:
    if (!(v0142 == v0141)) goto v0201;
    fn = elt(env, 39); // readch1
    v0141 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-4];
    stack[-3] = v0141;
    v0142 = stack[-3];
    v0141 = elt(env, 25); // !:
    if (v0142 == v0141) goto v0204;
    v0141 = stack[-3];
    v0141 = ncons(v0141);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-4];
    qvalue(elt(env, 32)) = v0141; // peekchar!*
    v0141 = elt(env, 25); // !:
    stack[-3] = v0141;
    goto v0201;

v0201:
    v0141 = stack[-2];
    fn = elt(env, 45); // reversip!*
    v0141 = (*qfn1(fn))(qenv(fn), v0141);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-4];
    fn = elt(env, 48); // list2wideid
    v0141 = (*qfn1(fn))(qenv(fn), v0141);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-4];
    stack[-2] = v0141;
    v0142 = stack[-2];
    v0141 = qvalue(elt(env, 26)); // !*line!-marker
    if (equal(v0142, v0141)) goto v0205;
    v0142 = stack[-2];
    v0141 = qvalue(elt(env, 28)); // !*file!-marker
    if (equal(v0142, v0141)) goto v0206;
    v0141 = stack[-2];
    qvalue(elt(env, 17)) = v0141; // nxtsym!*
    goto v0207;

v0207:
    v0141 = stack[-3];
    qvalue(elt(env, 1)) = v0141; // crchar!*
    goto v0179;

v0206:
    v0141 = qvalue(elt(env, 29)); // ifl!*
    if (v0141 == nil) goto v0208;
    v0141 = qvalue(elt(env, 29)); // ifl!*
    v0141 = qcar(v0141);
    goto v0209;

v0209:
    qvalue(elt(env, 17)) = v0141; // nxtsym!*
    goto v0207;

v0208:
    v0141 = elt(env, 30); // "Terminal"
    goto v0209;

v0205:
    v0141 = qvalue(elt(env, 27)); // curline!*
    qvalue(elt(env, 17)) = v0141; // nxtsym!*
    goto v0207;

v0204:
    fn = elt(env, 39); // readch1
    v0141 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-4];
    stack[-3] = v0141;
    v0142 = stack[-3];
    v0141 = qvalue(elt(env, 2)); // !$eof!$
    if (v0142 == v0141) goto v0210;
    v0141 = qvalue(elt(env, 1)); // crchar!*
    fn = elt(env, 37); // id2string
    v0141 = (*qfn1(fn))(qenv(fn), v0141);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-4];
    fn = elt(env, 38); // string!-length
    v0142 = (*qfn1(fn))(qenv(fn), v0141);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-4];
    v0141 = (LispObject)17; // 1
    if (v0142 == v0141) goto v0211;
    v0141 = qvalue(elt(env, 6)); // nil
    goto v0212;

v0212:
    if (v0141 == nil) goto v0213;
    v0141 = stack[-2];
    v0141 = Lreverse(nil, v0141);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-4];
    fn = elt(env, 48); // list2wideid
    v0141 = (*qfn1(fn))(qenv(fn), v0141);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-4];
    v0141 = elt(env, 25); // !:
    fn = elt(env, 49); // string2list
    v0141 = (*qfn1(fn))(qenv(fn), v0141);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-4];
    stack[0] = qcar(v0141);
    v0141 = elt(env, 25); // !:
    fn = elt(env, 49); // string2list
    v0141 = (*qfn1(fn))(qenv(fn), v0141);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-4];
    v0142 = qcar(v0141);
    v0141 = stack[-2];
    v0141 = list2star(stack[0], v0142, v0141);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-4];
    stack[-2] = v0141;
    goto v0214;

v0214:
    v0141 = stack[-3];
    fn = elt(env, 44); // wideid2list
    v0141 = (*qfn1(fn))(qenv(fn), v0141);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-4];
    stack[-3] = v0141;
    goto v0215;

v0215:
    v0141 = stack[-3];
    if (v0141 == nil) goto v0216;
    v0141 = stack[-3];
    v0142 = qcar(v0141);
    v0141 = stack[-2];
    v0141 = cons(v0142, v0141);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-4];
    stack[-2] = v0141;
    v0141 = stack[-3];
    v0141 = qcdr(v0141);
    stack[-3] = v0141;
    goto v0215;

v0216:
    fn = elt(env, 39); // readch1
    v0141 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-4];
    stack[-3] = v0141;
    v0142 = stack[-3];
    v0141 = qvalue(elt(env, 2)); // !$eof!$
    if (v0142 == v0141) goto v0217;
    v0141 = qvalue(elt(env, 1)); // crchar!*
    fn = elt(env, 37); // id2string
    v0141 = (*qfn1(fn))(qenv(fn), v0141);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-4];
    fn = elt(env, 38); // string!-length
    v0142 = (*qfn1(fn))(qenv(fn), v0141);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-4];
    v0141 = (LispObject)17; // 1
    v0141 = (v0142 == v0141 ? lisp_true : nil);
    v0141 = (v0141 == nil ? lisp_true : nil);
    goto v0218;

v0218:
    if (!(v0141 == nil)) goto v0219;
    v0141 = stack[-3];
    v0141 = Ldigitp(nil, v0141);
    env = stack[-4];
    if (!(v0141 == nil)) goto v0214;
    v0141 = stack[-3];
    v0141 = Lalpha_char_p(nil, v0141);
    env = stack[-4];
    if (!(v0141 == nil)) goto v0214;
    v0142 = stack[-3];
    v0141 = elt(env, 10); // !!
    if (v0142 == v0141) goto v0220;
    v0142 = stack[-3];
    v0141 = elt(env, 18); // !-
    if (v0142 == v0141) goto v0221;
    v0141 = qvalue(elt(env, 6)); // nil
    goto v0222;

v0222:
    if (!(v0141 == nil)) goto v0214;
    v0142 = stack[-3];
    v0141 = elt(env, 24); // !_
    if (v0142 == v0141) goto v0214;
    else goto v0219;

v0219:
    v0141 = stack[-2];
    fn = elt(env, 45); // reversip!*
    v0141 = (*qfn1(fn))(qenv(fn), v0141);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-4];
    fn = elt(env, 48); // list2wideid
    v0141 = (*qfn1(fn))(qenv(fn), v0141);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-4];
    stack[-2] = v0141;
    v0142 = elt(env, 34); // "Name with double colon in detected:"
    v0141 = stack[-2];
    v0141 = list2(v0142, v0141);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-4];
    fn = elt(env, 50); // lprim
    v0141 = (*qfn1(fn))(qenv(fn), v0141);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-4];
    v0141 = stack[-2];
    qvalue(elt(env, 17)) = v0141; // nxtsym!*
    v0141 = stack[-3];
    qvalue(elt(env, 1)) = v0141; // crchar!*
    v0141 = qvalue(elt(env, 17)); // nxtsym!*
    { popv(5); return onevalue(v0141); }

v0221:
    v0141 = qvalue(elt(env, 19)); // !*minusliter
    goto v0222;

v0220:
    stack[-1] = qvalue(elt(env, 21)); // !*raise
    qvalue(elt(env, 21)) = nil; // !*raise
    stack[0] = qvalue(elt(env, 22)); // !*lower
    qvalue(elt(env, 22)) = nil; // !*lower
    v0141 = qvalue(elt(env, 3)); // t
    qvalue(elt(env, 23)) = v0141; // escaped!*
    fn = elt(env, 39); // readch1
    v0141 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0223;
    env = stack[-4];
    stack[-3] = v0141;
    qvalue(elt(env, 22)) = stack[0]; // !*lower
    qvalue(elt(env, 21)) = stack[-1]; // !*raise
    goto v0214;

v0217:
    v0141 = qvalue(elt(env, 3)); // t
    goto v0218;

v0213:
    v0142 = elt(env, 25); // !:
    v0141 = stack[-3];
    v0141 = list2(v0142, v0141);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-4];
    qvalue(elt(env, 32)) = v0141; // peekchar!*
    v0141 = elt(env, 25); // !:
    stack[-3] = v0141;
    goto v0201;

v0211:
    v0141 = stack[-3];
    v0141 = Lalpha_char_p(nil, v0141);
    env = stack[-4];
    goto v0212;

v0210:
    v0141 = qvalue(elt(env, 6)); // nil
    goto v0212;

v0202:
    v0141 = qvalue(elt(env, 19)); // !*minusliter
    goto v0203;

v0199:
    v0141 = qvalue(elt(env, 3)); // t
    goto v0200;

v0163:
    v0141 = qvalue(elt(env, 11)); // !*micro!-version
    if (v0141 == nil) goto v0224;
    v0141 = qvalue(elt(env, 12)); // !*defn
    v0141 = (v0141 == nil ? lisp_true : nil);
    goto v0225;

v0225:
    v0141 = (v0141 == nil ? lisp_true : nil);
    goto v0164;

v0224:
    v0141 = qvalue(elt(env, 6)); // nil
    goto v0225;

v0154:
    v0141 = qvalue(elt(env, 9)); // !*savecomments!*
    v0141 = (v0141 == nil ? lisp_true : nil);
    goto v0155;

v0149:
    v0141 = qvalue(elt(env, 5)); // !*eoldelimp
    goto v0150;

v0144:
    v0141 = qvalue(elt(env, 3)); // t
    goto v0146;
// error exit handlers
v0223:
    env = stack[-4];
    qvalue(elt(env, 22)) = stack[0]; // !*lower
    qvalue(elt(env, 21)) = stack[-1]; // !*raise
    popv(5);
    return nil;
v0194:
    env = stack[-4];
    qvalue(elt(env, 22)) = stack[0]; // !*lower
    qvalue(elt(env, 21)) = stack[-1]; // !*raise
    popv(5);
    return nil;
v0185:
    env = stack[-4];
    qvalue(elt(env, 22)) = stack[0]; // !*lower
    qvalue(elt(env, 21)) = stack[-1]; // !*raise
    popv(5);
    return nil;
v0158:
    env = stack[-4];
    qvalue(elt(env, 22)) = stack[0]; // !*lower
    qvalue(elt(env, 21)) = stack[-1]; // !*raise
    popv(5);
    return nil;
v0145:
    popv(5);
    return nil;
}



// Code for dp_sum

static LispObject CC_dp_sum(LispObject env,
                         LispObject v0226, LispObject v0006)
{
    LispObject nil = C_nil;
    LispObject v0249, v0250, v0251;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dp_sum");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0006,v0226);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0226,v0006);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0006;
    stack[-1] = v0226;
// end of prologue

v0252:
    v0249 = stack[-1];
    if (v0249 == nil) { LispObject res = stack[0]; popv(4); return onevalue(res); }
    v0249 = stack[0];
    if (v0249 == nil) { LispObject res = stack[-1]; popv(4); return onevalue(res); }
    v0249 = stack[-1];
    fn = elt(env, 1); // dp_lmon
    stack[-2] = (*qfn1(fn))(qenv(fn), v0249);
    nil = C_nil;
    if (exception_pending()) goto v0225;
    env = stack[-3];
    v0249 = stack[0];
    fn = elt(env, 1); // dp_lmon
    v0249 = (*qfn1(fn))(qenv(fn), v0249);
    nil = C_nil;
    if (exception_pending()) goto v0225;
    env = stack[-3];
    fn = elt(env, 2); // mo_compare
    v0249 = (*qfn2(fn))(qenv(fn), stack[-2], v0249);
    nil = C_nil;
    if (exception_pending()) goto v0225;
    env = stack[-3];
    v0251 = v0249;
    v0250 = v0251;
    v0249 = (LispObject)17; // 1
    if (v0250 == v0249) goto v0253;
    v0250 = v0251;
    v0249 = (LispObject)-15; // -1
    if (v0250 == v0249) goto v0150;
    v0249 = stack[-1];
    fn = elt(env, 3); // dp_lc
    stack[-2] = (*qfn1(fn))(qenv(fn), v0249);
    nil = C_nil;
    if (exception_pending()) goto v0225;
    env = stack[-3];
    v0249 = stack[0];
    fn = elt(env, 3); // dp_lc
    v0249 = (*qfn1(fn))(qenv(fn), v0249);
    nil = C_nil;
    if (exception_pending()) goto v0225;
    env = stack[-3];
    fn = elt(env, 4); // cali_bc_sum
    v0249 = (*qfn2(fn))(qenv(fn), stack[-2], v0249);
    nil = C_nil;
    if (exception_pending()) goto v0225;
    env = stack[-3];
    stack[-2] = v0249;
    v0249 = stack[-2];
    fn = elt(env, 5); // cali_bc_zero!?
    v0249 = (*qfn1(fn))(qenv(fn), v0249);
    nil = C_nil;
    if (exception_pending()) goto v0225;
    env = stack[-3];
    if (v0249 == nil) goto v0254;
    v0249 = stack[-1];
    v0250 = qcdr(v0249);
    v0249 = stack[0];
    v0249 = qcdr(v0249);
    stack[-1] = v0250;
    stack[0] = v0249;
    goto v0252;

v0254:
    v0249 = stack[-1];
    fn = elt(env, 1); // dp_lmon
    v0249 = (*qfn1(fn))(qenv(fn), v0249);
    nil = C_nil;
    if (exception_pending()) goto v0225;
    env = stack[-3];
    fn = elt(env, 6); // dp_term
    stack[-2] = (*qfn2(fn))(qenv(fn), stack[-2], v0249);
    nil = C_nil;
    if (exception_pending()) goto v0225;
    env = stack[-3];
    v0249 = stack[-1];
    v0250 = qcdr(v0249);
    v0249 = stack[0];
    v0249 = qcdr(v0249);
    v0249 = CC_dp_sum(env, v0250, v0249);
    nil = C_nil;
    if (exception_pending()) goto v0225;
    {
        LispObject v0224 = stack[-2];
        popv(4);
        return cons(v0224, v0249);
    }

v0150:
    v0249 = stack[0];
    stack[-2] = qcar(v0249);
    v0250 = stack[-1];
    v0249 = stack[0];
    v0249 = qcdr(v0249);
    v0249 = CC_dp_sum(env, v0250, v0249);
    nil = C_nil;
    if (exception_pending()) goto v0225;
    {
        LispObject v0255 = stack[-2];
        popv(4);
        return cons(v0255, v0249);
    }

v0253:
    v0249 = stack[-1];
    stack[-2] = qcar(v0249);
    v0249 = stack[-1];
    v0250 = qcdr(v0249);
    v0249 = stack[0];
    v0249 = CC_dp_sum(env, v0250, v0249);
    nil = C_nil;
    if (exception_pending()) goto v0225;
    {
        LispObject v0256 = stack[-2];
        popv(4);
        return cons(v0256, v0249);
    }
// error exit handlers
v0225:
    popv(4);
    return nil;
}



// Code for pneg

static LispObject CC_pneg(LispObject env,
                         LispObject v0226)
{
    LispObject nil = C_nil;
    LispObject v0259, v0148;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pneg");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0226);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0226);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    v0259 = v0226;
// end of prologue
    stack[-4] = v0259;
    v0259 = stack[-4];
    if (v0259 == nil) goto v0197;
    v0259 = stack[-4];
    v0259 = qcar(v0259);
    v0148 = v0259;
    v0259 = v0148;
    stack[0] = qcar(v0259);
    v0259 = v0148;
    v0259 = qcdr(v0259);
    fn = elt(env, 2); // cneg
    v0259 = (*qfn1(fn))(qenv(fn), v0259);
    nil = C_nil;
    if (exception_pending()) goto v0150;
    env = stack[-5];
    v0259 = cons(stack[0], v0259);
    nil = C_nil;
    if (exception_pending()) goto v0150;
    env = stack[-5];
    v0259 = ncons(v0259);
    nil = C_nil;
    if (exception_pending()) goto v0150;
    env = stack[-5];
    stack[-2] = v0259;
    stack[-3] = v0259;
    goto v0147;

v0147:
    v0259 = stack[-4];
    v0259 = qcdr(v0259);
    stack[-4] = v0259;
    v0259 = stack[-4];
    if (v0259 == nil) { LispObject res = stack[-3]; popv(6); return onevalue(res); }
    stack[-1] = stack[-2];
    v0259 = stack[-4];
    v0259 = qcar(v0259);
    v0148 = v0259;
    v0259 = v0148;
    stack[0] = qcar(v0259);
    v0259 = v0148;
    v0259 = qcdr(v0259);
    fn = elt(env, 2); // cneg
    v0259 = (*qfn1(fn))(qenv(fn), v0259);
    nil = C_nil;
    if (exception_pending()) goto v0150;
    env = stack[-5];
    v0259 = cons(stack[0], v0259);
    nil = C_nil;
    if (exception_pending()) goto v0150;
    env = stack[-5];
    v0259 = ncons(v0259);
    nil = C_nil;
    if (exception_pending()) goto v0150;
    env = stack[-5];
    v0259 = Lrplacd(nil, stack[-1], v0259);
    nil = C_nil;
    if (exception_pending()) goto v0150;
    env = stack[-5];
    v0259 = stack[-2];
    v0259 = qcdr(v0259);
    stack[-2] = v0259;
    goto v0147;

v0197:
    v0259 = qvalue(elt(env, 1)); // nil
    { popv(6); return onevalue(v0259); }
// error exit handlers
v0150:
    popv(6);
    return nil;
}



// Code for kernp

static LispObject CC_kernp(LispObject env,
                         LispObject v0226)
{
    LispObject nil = C_nil;
    LispObject v0265, v0237, v0236;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for kernp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0237 = v0226;
// end of prologue
    v0265 = v0237;
    v0236 = qcdr(v0265);
    v0265 = (LispObject)17; // 1
    if (v0236 == v0265) goto v0257;
    v0265 = qvalue(elt(env, 2)); // nil
    return onevalue(v0265);

v0257:
    v0265 = v0237;
    v0265 = qcar(v0265);
    v0237 = v0265;
    v0236 = v0265;
    v0265 = v0236;
    if (!consp(v0265)) goto v0214;
    v0265 = v0236;
    v0265 = qcar(v0265);
    v0265 = (consp(v0265) ? nil : lisp_true);
    goto v0266;

v0266:
    if (v0265 == nil) goto v0233;
    v0265 = qvalue(elt(env, 2)); // nil
    return onevalue(v0265);

v0233:
    v0265 = v0237;
    v0265 = qcdr(v0265);
    if (v0265 == nil) goto v0267;
    v0265 = qvalue(elt(env, 2)); // nil
    return onevalue(v0265);

v0267:
    v0265 = v0237;
    v0265 = qcar(v0265);
    v0236 = qcdr(v0265);
    v0265 = (LispObject)17; // 1
    if (v0236 == v0265) goto v0268;
    v0265 = qvalue(elt(env, 2)); // nil
    return onevalue(v0265);

v0268:
    v0265 = v0237;
    v0265 = qcar(v0265);
    v0265 = qcar(v0265);
    v0237 = qcdr(v0265);
    v0265 = (LispObject)17; // 1
    v0265 = (v0237 == v0265 ? lisp_true : nil);
    return onevalue(v0265);

v0214:
    v0265 = qvalue(elt(env, 1)); // t
    goto v0266;
}



// Code for conv!:bf2i

static LispObject CC_convTbf2i(LispObject env,
                         LispObject v0226)
{
    LispObject nil = C_nil;
    LispObject v0179, v0242;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for conv:bf2i");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0179 = v0226;
// end of prologue
    v0242 = v0179;
    v0242 = qcdr(v0242);
    v0242 = qcar(v0242);
    v0179 = qcdr(v0179);
    v0179 = qcdr(v0179);
    {
        fn = elt(env, 1); // ashift
        return (*qfn2(fn))(qenv(fn), v0242, v0179);
    }
}



// Code for carx

static LispObject CC_carx(LispObject env,
                         LispObject v0226, LispObject v0006)
{
    LispObject nil = C_nil;
    LispObject v0271, v0272, v0273;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for carx");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0006,v0226);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0226,v0006);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    v0272 = v0006;
    v0273 = v0226;
// end of prologue
    v0271 = v0273;
    v0271 = qcdr(v0271);
    if (v0271 == nil) goto v0274;
    stack[-1] = elt(env, 1); // alg
    stack[0] = (LispObject)81; // 5
    v0271 = elt(env, 2); // "Wrong number of arguments to"
    v0271 = list2(v0271, v0272);
    nil = C_nil;
    if (exception_pending()) goto v0146;
    env = stack[-2];
    {
        LispObject v0144 = stack[-1];
        LispObject v0247 = stack[0];
        popv(3);
        fn = elt(env, 3); // rerror
        return (*qfnn(fn))(qenv(fn), 3, v0144, v0247, v0271);
    }

v0274:
    v0271 = v0273;
    v0271 = qcar(v0271);
    { popv(3); return onevalue(v0271); }
// error exit handlers
v0146:
    popv(3);
    return nil;
}



// Code for comfac

static LispObject CC_comfac(LispObject env,
                         LispObject v0226)
{
    LispObject nil = C_nil;
    LispObject v0284, v0120;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for comfac");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0226);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0226);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-2] = v0226;
// end of prologue
    stack[-3] = nil;
    v0284 = qvalue(elt(env, 1)); // dmode!*
    if (!symbolp(v0284)) v0284 = nil;
    else { v0284 = qfastgets(v0284);
           if (v0284 != nil) { v0284 = elt(v0284, 3); // field
#ifdef RECORD_GET
             if (v0284 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v0284 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v0284 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v0284 == SPID_NOPROP) v0284 = nil; else v0284 = lisp_true; }}
#endif
    if (v0284 == nil) goto v0219;
    v0284 = stack[-2];
    fn = elt(env, 4); // lnc
    v0120 = (*qfn1(fn))(qenv(fn), v0284);
    nil = C_nil;
    if (exception_pending()) goto v0285;
    env = stack[-4];
    stack[-3] = v0120;
    v0284 = (LispObject)17; // 1
    v0284 = Lneq(nil, v0120, v0284);
    nil = C_nil;
    if (exception_pending()) goto v0285;
    env = stack[-4];
    goto v0198;

v0198:
    if (v0284 == nil) goto v0165;
    v0284 = stack[-3];
    fn = elt(env, 5); // !:recip
    v0120 = (*qfn1(fn))(qenv(fn), v0284);
    nil = C_nil;
    if (exception_pending()) goto v0285;
    env = stack[-4];
    v0284 = stack[-2];
    fn = elt(env, 6); // multd
    v0284 = (*qfn2(fn))(qenv(fn), v0120, v0284);
    nil = C_nil;
    if (exception_pending()) goto v0285;
    env = stack[-4];
    stack[-2] = v0284;
    goto v0165;

v0165:
    v0284 = stack[-2];
    v0284 = qcdr(v0284);
    if (v0284 == nil) goto v0286;
    v0284 = stack[-2];
    v0284 = qcar(v0284);
    v0284 = qcdr(v0284);
    stack[-3] = v0284;
    v0284 = stack[-2];
    v0284 = qcar(v0284);
    v0284 = qcar(v0284);
    v0284 = qcar(v0284);
    stack[-1] = v0284;
    goto v0287;

v0287:
    v0284 = stack[-2];
    v0284 = qcdr(v0284);
    stack[-2] = v0284;
    v0120 = stack[-2];
    v0284 = stack[-1];
    fn = elt(env, 7); // degr
    v0120 = (*qfn2(fn))(qenv(fn), v0120, v0284);
    nil = C_nil;
    if (exception_pending()) goto v0285;
    env = stack[-4];
    v0284 = (LispObject)1; // 0
    if (v0120 == v0284) goto v0265;
    v0284 = stack[-2];
    v0284 = qcdr(v0284);
    if (v0284 == nil) goto v0164;
    v0284 = stack[-2];
    v0284 = qcar(v0284);
    v0120 = qcdr(v0284);
    v0284 = stack[-3];
    fn = elt(env, 8); // gcdf
    v0284 = (*qfn2(fn))(qenv(fn), v0120, v0284);
    nil = C_nil;
    if (exception_pending()) goto v0285;
    env = stack[-4];
    stack[-3] = v0284;
    goto v0287;

v0164:
    v0284 = stack[-2];
    v0284 = qcar(v0284);
    stack[0] = qcar(v0284);
    v0120 = stack[-3];
    v0284 = stack[-2];
    v0284 = qcar(v0284);
    v0284 = qcdr(v0284);
    fn = elt(env, 8); // gcdf
    v0284 = (*qfn2(fn))(qenv(fn), v0120, v0284);
    nil = C_nil;
    if (exception_pending()) goto v0285;
    {
        LispObject v0288 = stack[0];
        popv(5);
        return cons(v0288, v0284);
    }

v0265:
    stack[0] = qvalue(elt(env, 2)); // nil
    v0284 = stack[-2];
    if (!consp(v0284)) goto v0289;
    v0284 = stack[-2];
    v0284 = qcar(v0284);
    v0284 = (consp(v0284) ? nil : lisp_true);
    goto v0290;

v0290:
    if (v0284 == nil) goto v0291;
    v0284 = qvalue(elt(env, 3)); // t
    goto v0151;

v0151:
    if (v0284 == nil) goto v0231;
    v0120 = stack[-3];
    v0284 = stack[-2];
    fn = elt(env, 8); // gcdf
    v0284 = (*qfn2(fn))(qenv(fn), v0120, v0284);
    nil = C_nil;
    if (exception_pending()) goto v0285;
    goto v0134;

v0134:
    {
        LispObject v0292 = stack[0];
        popv(5);
        return cons(v0292, v0284);
    }

v0231:
    v0284 = (LispObject)17; // 1
    goto v0134;

v0291:
    v0284 = stack[-1];
    fn = elt(env, 9); // noncomp
    v0284 = (*qfn1(fn))(qenv(fn), v0284);
    nil = C_nil;
    if (exception_pending()) goto v0285;
    env = stack[-4];
    if (v0284 == nil) goto v0293;
    v0284 = stack[-2];
    v0284 = qcar(v0284);
    v0284 = qcar(v0284);
    v0284 = qcar(v0284);
    fn = elt(env, 9); // noncomp
    v0284 = (*qfn1(fn))(qenv(fn), v0284);
    nil = C_nil;
    if (exception_pending()) goto v0285;
    env = stack[-4];
    goto v0132;

v0132:
    v0284 = (v0284 == nil ? lisp_true : nil);
    goto v0151;

v0293:
    v0284 = qvalue(elt(env, 2)); // nil
    goto v0132;

v0289:
    v0284 = qvalue(elt(env, 3)); // t
    goto v0290;

v0286:
    v0284 = stack[-2];
    v0284 = qcar(v0284);
    { popv(5); return onevalue(v0284); }

v0219:
    v0284 = qvalue(elt(env, 2)); // nil
    goto v0198;
// error exit handlers
v0285:
    popv(5);
    return nil;
}



// Code for cl_susiminlevel

static LispObject CC_cl_susiminlevel(LispObject env,
                         LispObject v0226, LispObject v0006)
{
    LispObject nil = C_nil;
    LispObject v0136, v0146, v0144, v0247;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cl_susiminlevel");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0144 = v0006;
    v0247 = v0226;
// end of prologue
    v0146 = v0247;
    v0136 = elt(env, 1); // ignore
    if (v0146 == v0136) return onevalue(v0144);
    v0146 = v0144;
    v0136 = elt(env, 1); // ignore
    if (v0146 == v0136) return onevalue(v0247);
    v0136 = v0247;
    v0146 = v0144;
    {
        fn = elt(env, 2); // min
        return (*qfn2(fn))(qenv(fn), v0136, v0146);
    }
}



// Code for ibalp_litlp

static LispObject CC_ibalp_litlp(LispObject env,
                         LispObject v0226)
{
    LispObject nil = C_nil;
    LispObject v0214;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_litlp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0226);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0226);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0226;
// end of prologue

v0252:
    v0214 = stack[0];
    if (v0214 == nil) goto v0257;
    v0214 = stack[0];
    v0214 = qcar(v0214);
    fn = elt(env, 3); // ibalp_litp
    v0214 = (*qfn1(fn))(qenv(fn), v0214);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-1];
    if (v0214 == nil) goto v0198;
    v0214 = stack[0];
    v0214 = qcdr(v0214);
    stack[0] = v0214;
    goto v0252;

v0198:
    v0214 = qvalue(elt(env, 2)); // nil
    { popv(2); return onevalue(v0214); }

v0257:
    v0214 = qvalue(elt(env, 1)); // t
    { popv(2); return onevalue(v0214); }
// error exit handlers
v0216:
    popv(2);
    return nil;
}



// Code for quotk

static LispObject CC_quotk(LispObject env,
                         LispObject v0226, LispObject v0006)
{
    LispObject nil = C_nil;
    LispObject v0282, v0297, v0265;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for quotk");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0006,v0226);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0226,v0006);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0006;
    stack[-1] = v0226;
// end of prologue
    v0282 = stack[-1];
    v0282 = qcar(v0282);
    v0297 = qcdr(v0282);
    v0282 = stack[0];
    fn = elt(env, 2); // quotf1
    v0282 = (*qfn2(fn))(qenv(fn), v0297, v0282);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    env = stack[-3];
    stack[-2] = v0282;
    v0282 = stack[-2];
    if (v0282 == nil) goto v0150;
    v0282 = stack[-1];
    v0282 = qcdr(v0282);
    if (v0282 == nil) goto v0220;
    v0282 = stack[-1];
    v0297 = qcdr(v0282);
    v0282 = stack[0];
    fn = elt(env, 2); // quotf1
    v0282 = (*qfn2(fn))(qenv(fn), v0297, v0282);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    env = stack[-3];
    v0297 = v0282;
    v0282 = v0297;
    if (v0282 == nil) goto v0240;
    v0282 = stack[-1];
    v0282 = qcar(v0282);
    v0265 = qcar(v0282);
    v0282 = stack[-2];
    popv(4);
    return acons(v0265, v0282, v0297);

v0240:
    v0282 = qvalue(elt(env, 1)); // nil
    { popv(4); return onevalue(v0282); }

v0220:
    v0282 = stack[-1];
    v0282 = qcar(v0282);
    v0297 = qcar(v0282);
    v0282 = stack[-2];
    v0282 = cons(v0297, v0282);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    popv(4);
    return ncons(v0282);

v0150:
    v0282 = qvalue(elt(env, 1)); // nil
    { popv(4); return onevalue(v0282); }
// error exit handlers
v0135:
    popv(4);
    return nil;
}



// Code for ps!:last!-term

static LispObject CC_psTlastKterm(LispObject env,
                         LispObject v0226)
{
    LispObject nil = C_nil;
    LispObject v0298, v0139, v0140;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ps:last-term");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0140 = v0226;
// end of prologue
    v0298 = v0140;
    if (!consp(v0298)) goto v0165;
    v0298 = v0140;
    v0139 = qcar(v0298);
    v0298 = elt(env, 2); // !:ps!:
    if (v0139 == v0298) goto v0269;
    v0298 = v0140;
    v0298 = qcar(v0298);
    if (!symbolp(v0298)) v0298 = nil;
    else { v0298 = qfastgets(v0298);
           if (v0298 != nil) { v0298 = elt(v0298, 8); // dname
#ifdef RECORD_GET
             if (v0298 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v0298 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v0298 == SPID_NOPROP) v0298 = nil; }}
#endif
    goto v0147;

v0147:
    if (v0298 == nil) goto v0146;
    v0298 = qvalue(elt(env, 4)); // ps!:max!-order
    return onevalue(v0298);

v0146:
    v0139 = v0140;
    v0298 = (LispObject)17; // 1
    {
        fn = elt(env, 5); // ps!:getv
        return (*qfn2(fn))(qenv(fn), v0139, v0298);
    }

v0269:
    v0298 = qvalue(elt(env, 3)); // nil
    goto v0147;

v0165:
    v0298 = qvalue(elt(env, 1)); // t
    goto v0147;
}



// Code for initbrsea

static LispObject CC_initbrsea(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0228, v0304, v0305;
    LispObject fn;
    argcheck(nargs, 0, "initbrsea");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for initbrsea");
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
    v0228 = (LispObject)3201; // 200
    stack[-2] = v0228;
    v0228 = qvalue(elt(env, 1)); // rowmin
    stack[-1] = v0228;
    goto v0233;

v0233:
    v0304 = qvalue(elt(env, 2)); // rowmax
    v0228 = stack[-1];
    v0228 = difference2(v0304, v0228);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    env = stack[-3];
    v0228 = Lminusp(nil, v0228);
    env = stack[-3];
    if (v0228 == nil) goto v0273;
    fn = elt(env, 8); // redcodmat
    v0228 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    env = stack[-3];
    v0228 = qvalue(elt(env, 6)); // codhisto
    if (v0228 == nil) goto v0234;
    v0228 = (LispObject)1; // 0
    stack[0] = v0228;
    goto v0283;

v0283:
    v0304 = (LispObject)3201; // 200
    v0228 = stack[0];
    v0228 = difference2(v0304, v0228);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    env = stack[-3];
    v0228 = Lminusp(nil, v0228);
    env = stack[-3];
    if (!(v0228 == nil)) goto v0246;
    v0305 = qvalue(elt(env, 6)); // codhisto
    v0304 = stack[0];
    v0228 = qvalue(elt(env, 3)); // nil
    *(LispObject *)((char *)v0305 + (CELL-TAG_VECTOR) + ((int32_t)v0304/(16/CELL))) = v0228;
    v0228 = stack[0];
    v0228 = add1(v0228);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    env = stack[-3];
    stack[0] = v0228;
    goto v0283;

v0246:
    v0228 = (LispObject)1; // 0
    qvalue(elt(env, 7)) = v0228; // headhisto
    v0228 = (LispObject)1; // 0
    stack[0] = v0228;
    goto v0306;

v0306:
    v0304 = qvalue(elt(env, 2)); // rowmax
    v0228 = stack[0];
    v0228 = difference2(v0304, v0228);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    env = stack[-3];
    v0228 = Lminusp(nil, v0228);
    env = stack[-3];
    if (v0228 == nil) goto v0131;
    v0228 = nil;
    { popv(4); return onevalue(v0228); }

v0131:
    v0228 = stack[0];
    fn = elt(env, 9); // inshisto
    v0228 = (*qfn1(fn))(qenv(fn), v0228);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    env = stack[-3];
    v0228 = stack[0];
    v0228 = add1(v0228);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    env = stack[-3];
    stack[0] = v0228;
    goto v0306;

v0234:
    v0228 = stack[-2];
    v0228 = Lmkvect(nil, v0228);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    env = stack[-3];
    qvalue(elt(env, 6)) = v0228; // codhisto
    goto v0246;

v0273:
    stack[0] = qvalue(elt(env, 4)); // codmat
    v0304 = qvalue(elt(env, 5)); // maxvar
    v0228 = stack[-1];
    v0228 = plus2(v0304, v0228);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    env = stack[-3];
    v0304 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0228/(16/CELL)));
    v0228 = (LispObject)1; // 0
    v0228 = *(LispObject *)((char *)v0304 + (CELL-TAG_VECTOR) + ((int32_t)v0228/(16/CELL)));
    if (v0228 == nil) goto v0216;
    v0228 = stack[-1];
    fn = elt(env, 10); // initwght
    v0228 = (*qfn1(fn))(qenv(fn), v0228);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    env = stack[-3];
    goto v0216;

v0216:
    v0228 = stack[-1];
    v0228 = add1(v0228);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    env = stack[-3];
    stack[-1] = v0228;
    goto v0233;
// error exit handlers
v0231:
    popv(4);
    return nil;
}



// Code for take!-impart

static LispObject CC_takeKimpart(LispObject env,
                         LispObject v0226)
{
    LispObject nil = C_nil;
    LispObject v0220, v0166;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for take-impart");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0226);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0226);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0226;
// end of prologue
    v0220 = stack[0];
    v0220 = qcar(v0220);
    fn = elt(env, 1); // impartf
    v0166 = (*qfn1(fn))(qenv(fn), v0220);
    nil = C_nil;
    if (exception_pending()) goto v0271;
    env = stack[-2];
    v0220 = (LispObject)17; // 1
    stack[-1] = cons(v0166, v0220);
    nil = C_nil;
    if (exception_pending()) goto v0271;
    env = stack[-2];
    v0166 = (LispObject)17; // 1
    v0220 = stack[0];
    v0220 = qcdr(v0220);
    v0220 = cons(v0166, v0220);
    nil = C_nil;
    if (exception_pending()) goto v0271;
    env = stack[-2];
    {
        LispObject v0272 = stack[-1];
        popv(3);
        fn = elt(env, 2); // multsq
        return (*qfn2(fn))(qenv(fn), v0272, v0220);
    }
// error exit handlers
v0271:
    popv(3);
    return nil;
}



// Code for errorset2

static LispObject CC_errorset2(LispObject env,
                         LispObject v0226)
{
    LispObject nil = C_nil;
    LispObject v0168, v0258, v0170;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for errorset2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0226);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0226);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0258 = v0226;
// end of prologue
    stack[0] = qvalue(elt(env, 1)); // !*protfg
    qvalue(elt(env, 1)) = nil; // !*protfg
    v0168 = qvalue(elt(env, 2)); // t
    qvalue(elt(env, 1)) = v0168; // !*protfg
    v0170 = v0258;
    v0258 = qvalue(elt(env, 3)); // nil
    v0168 = qvalue(elt(env, 3)); // nil
    fn = elt(env, 4); // errorset
    v0168 = (*qfnn(fn))(qenv(fn), 3, v0170, v0258, v0168);
    nil = C_nil;
    if (exception_pending()) goto v0204;
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; // !*protfg
    { popv(2); return onevalue(v0168); }
// error exit handlers
v0204:
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; // !*protfg
    popv(2);
    return nil;
}



// Code for mv!-pow!-!+

static LispObject CC_mvKpowKL(LispObject env,
                         LispObject v0226, LispObject v0006)
{
    LispObject nil = C_nil;
    LispObject v0144, v0247;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mv-pow-+");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0006,v0226);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0226,v0006);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0006;
    stack[-1] = v0226;
// end of prologue
    stack[-2] = nil;
    goto v0287;

v0287:
    v0144 = stack[-1];
    if (v0144 == nil) goto v0152;
    v0144 = stack[-1];
    v0247 = qcar(v0144);
    v0144 = stack[0];
    v0144 = qcar(v0144);
    v0247 = plus2(v0247, v0144);
    nil = C_nil;
    if (exception_pending()) goto v0267;
    env = stack[-3];
    v0144 = stack[-2];
    v0144 = cons(v0247, v0144);
    nil = C_nil;
    if (exception_pending()) goto v0267;
    env = stack[-3];
    stack[-2] = v0144;
    v0144 = stack[-1];
    v0144 = qcdr(v0144);
    stack[-1] = v0144;
    v0144 = stack[0];
    v0144 = qcdr(v0144);
    stack[0] = v0144;
    goto v0287;

v0152:
    v0144 = stack[-2];
    {
        popv(4);
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(qenv(fn), v0144);
    }
// error exit handlers
v0267:
    popv(4);
    return nil;
}



// Code for crprcd

static LispObject CC_crprcd(LispObject env,
                         LispObject v0226)
{
    LispObject nil = C_nil;
    LispObject v0264, v0204;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for crprcd");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0226);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0226);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0226;
// end of prologue
    v0264 = stack[0];
    v0264 = qcdr(v0264);
    v0264 = qcar(v0264);
    fn = elt(env, 1); // convprec!*
    stack[-1] = (*qfn1(fn))(qenv(fn), v0264);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-2];
    v0264 = stack[0];
    v0264 = qcdr(v0264);
    v0264 = qcdr(v0264);
    fn = elt(env, 1); // convprec!*
    v0264 = (*qfn1(fn))(qenv(fn), v0264);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    v0204 = stack[-1];
    popv(3);
    return cons(v0204, v0264);
// error exit handlers
v0215:
    popv(3);
    return nil;
}



// Code for wuorderp

static LispObject CC_wuorderp(LispObject env,
                         LispObject v0226, LispObject v0006)
{
    LispObject nil = C_nil;
    LispObject v0154, v0308, v0153, v0228, v0304, v0305;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for wuorderp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0006,v0226);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0226,v0006);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
// copy arguments values to proper place
    v0304 = v0006;
    v0305 = v0226;
// end of prologue
    v0153 = nil;
    v0308 = v0305;
    v0154 = v0304;
    if (v0308 == v0154) goto v0152;
    v0154 = qvalue(elt(env, 2)); // wukord!*
    v0228 = v0154;
    goto v0266;

v0266:
    v0154 = v0228;
    if (v0154 == nil) goto v0204;
    v0154 = v0153;
    if (!(v0154 == nil)) goto v0204;
    v0308 = v0305;
    v0154 = v0228;
    v0154 = qcar(v0154);
    if (v0308 == v0154) goto v0243;
    v0308 = v0304;
    v0154 = v0228;
    v0154 = qcar(v0154);
    if (v0308 == v0154) goto v0237;
    v0154 = v0228;
    v0154 = qcdr(v0154);
    v0228 = v0154;
    goto v0266;

v0237:
    v0308 = v0305;
    v0154 = v0228;
    v0154 = qcdr(v0154);
    v0154 = Lmemq(nil, v0308, v0154);
    if (v0154 == nil) goto v0151;
    v0154 = elt(env, 4); // no
    goto v0282;

v0282:
    v0153 = v0154;
    goto v0266;

v0151:
    v0154 = elt(env, 3); // yes
    goto v0282;

v0243:
    v0308 = v0304;
    v0154 = v0228;
    v0154 = qcdr(v0154);
    v0154 = Lmemq(nil, v0308, v0154);
    if (v0154 == nil) goto v0309;
    v0154 = elt(env, 3); // yes
    goto v0140;

v0140:
    v0153 = v0154;
    goto v0266;

v0309:
    v0154 = elt(env, 4); // no
    goto v0140;

v0204:
    v0154 = v0153;
    if (v0154 == nil) goto v0248;
    v0154 = v0153;
    v0308 = elt(env, 3); // yes
    v0154 = (v0154 == v0308 ? lisp_true : nil);
    return onevalue(v0154);

v0248:
    v0154 = v0305;
    v0308 = v0304;
    v0154 = Lorderp(nil, v0154, v0308);
    errexit();
    v0154 = (v0154 == nil ? lisp_true : nil);
    return onevalue(v0154);

v0152:
    v0154 = qvalue(elt(env, 1)); // nil
    return onevalue(v0154);
}



// Code for freevarinexptchk

static LispObject CC_freevarinexptchk(LispObject env,
                         LispObject v0226)
{
    LispObject nil = C_nil;
    LispObject v0253;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for freevarinexptchk");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0226);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0226);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0226;
// end of prologue

v0252:
    v0253 = stack[0];
    if (!consp(v0253)) goto v0165;
    v0253 = stack[0];
    v0253 = qcar(v0253);
    v0253 = (consp(v0253) ? nil : lisp_true);
    goto v0147;

v0147:
    if (v0253 == nil) goto v0257;
    v0253 = qvalue(elt(env, 2)); // nil
    { popv(2); return onevalue(v0253); }

v0257:
    v0253 = stack[0];
    v0253 = qcar(v0253);
    v0253 = qcar(v0253);
    v0253 = qcdr(v0253);
    if (is_number(v0253)) goto v0219;
    v0253 = qvalue(elt(env, 1)); // t
    { popv(2); return onevalue(v0253); }

v0219:
    v0253 = stack[0];
    v0253 = qcar(v0253);
    v0253 = qcdr(v0253);
    v0253 = CC_freevarinexptchk(env, v0253);
    nil = C_nil;
    if (exception_pending()) goto v0298;
    env = stack[-1];
    if (!(v0253 == nil)) { popv(2); return onevalue(v0253); }
    v0253 = stack[0];
    v0253 = qcdr(v0253);
    stack[0] = v0253;
    goto v0252;

v0165:
    v0253 = qvalue(elt(env, 1)); // t
    goto v0147;
// error exit handlers
v0298:
    popv(2);
    return nil;
}



// Code for searchtm

static LispObject CC_searchtm(LispObject env,
                         LispObject v0226)
{
    LispObject nil = C_nil;
    LispObject v0272, v0273;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for searchtm");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0226);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0226);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0273 = v0226;
// end of prologue
    v0272 = v0273;
    if (!consp(v0272)) goto v0165;
    v0272 = v0273;
    v0272 = qcar(v0272);
    v0272 = (consp(v0272) ? nil : lisp_true);
    goto v0147;

v0147:
    if (v0272 == nil) goto v0204;
    v0272 = qvalue(elt(env, 2)); // nil
    { popv(1); return onevalue(v0272); }

v0204:
    v0272 = v0273;
    v0272 = qcar(v0272);
    stack[0] = qcar(v0272);
    v0272 = v0273;
    v0272 = qcdr(v0272);
    fn = elt(env, 3); // searchpl
    v0272 = (*qfn1(fn))(qenv(fn), v0272);
    nil = C_nil;
    if (exception_pending()) goto v0136;
    {
        LispObject v0146 = stack[0];
        popv(1);
        return cons(v0146, v0272);
    }

v0165:
    v0272 = qvalue(elt(env, 1)); // t
    goto v0147;
// error exit handlers
v0136:
    popv(1);
    return nil;
}



// Code for ibalp_vequal

static LispObject CC_ibalp_vequal(LispObject env,
                         LispObject v0226, LispObject v0006)
{
    LispObject nil = C_nil;
    LispObject v0201, v0179;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_vequal");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0201 = v0006;
    v0179 = v0226;
// end of prologue
    v0179 = qcar(v0179);
    v0201 = qcar(v0201);
    v0201 = (v0179 == v0201 ? lisp_true : nil);
    return onevalue(v0201);
}



// Code for equal!:

static LispObject CC_equalT(LispObject env,
                         LispObject v0226, LispObject v0006)
{
    LispObject nil = C_nil;
    LispObject v0307, v0137;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for equal:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0006,v0226);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0226,v0006);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0006;
    stack[-1] = v0226;
// end of prologue
    v0307 = stack[-1];
    v0307 = qcdr(v0307);
    v0307 = qcar(v0307);
    v0307 = (LispObject)zerop(v0307);
    v0307 = v0307 ? lisp_true : nil;
    env = stack[-3];
    if (v0307 == nil) goto v0165;
    v0307 = stack[0];
    v0307 = qcdr(v0307);
    v0307 = qcar(v0307);
    v0307 = (LispObject)zerop(v0307);
    v0307 = v0307 ? lisp_true : nil;
    env = stack[-3];
    goto v0147;

v0147:
    if (!(v0307 == nil)) { popv(4); return onevalue(v0307); }
    v0307 = stack[-1];
    fn = elt(env, 2); // normbf
    v0307 = (*qfn1(fn))(qenv(fn), v0307);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-3];
    stack[-1] = v0307;
    v0307 = qcdr(v0307);
    stack[-2] = qcdr(v0307);
    v0307 = stack[0];
    fn = elt(env, 2); // normbf
    v0307 = (*qfn1(fn))(qenv(fn), v0307);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-3];
    stack[0] = v0307;
    v0307 = qcdr(v0307);
    v0307 = qcdr(v0307);
    if (equal(stack[-2], v0307)) goto v0247;
    v0307 = qvalue(elt(env, 1)); // nil
    { popv(4); return onevalue(v0307); }

v0247:
    v0307 = stack[-1];
    v0307 = qcdr(v0307);
    v0137 = qcar(v0307);
    v0307 = stack[0];
    v0307 = qcdr(v0307);
    v0307 = qcar(v0307);
    v0307 = (equal(v0137, v0307) ? lisp_true : nil);
    { popv(4); return onevalue(v0307); }

v0165:
    v0307 = qvalue(elt(env, 1)); // nil
    goto v0147;
// error exit handlers
v0309:
    popv(4);
    return nil;
}



// Code for testred

static LispObject CC_testred(LispObject env,
                         LispObject v0226)
{
    LispObject nil = C_nil;
    LispObject v0156, v0230, v0249;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for testred");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0226);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0226);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0226;
// end of prologue
    stack[-1] = qvalue(elt(env, 1)); // codmat
    v0230 = qvalue(elt(env, 2)); // maxvar
    v0156 = stack[0];
    v0156 = plus2(v0230, v0156);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-2];
    v0230 = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v0156/(16/CELL)));
    v0156 = (LispObject)1; // 0
    v0156 = *(LispObject *)((char *)v0230 + (CELL-TAG_VECTOR) + ((int32_t)v0156/(16/CELL)));
    if (v0156 == nil) goto v0274;
    stack[-1] = qvalue(elt(env, 1)); // codmat
    v0230 = qvalue(elt(env, 2)); // maxvar
    v0156 = stack[0];
    v0156 = plus2(v0230, v0156);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-2];
    v0230 = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v0156/(16/CELL)));
    v0156 = (LispObject)17; // 1
    v0156 = *(LispObject *)((char *)v0230 + (CELL-TAG_VECTOR) + ((int32_t)v0156/(16/CELL)));
    v0156 = qcar(v0156);
    v0230 = qcar(v0156);
    v0156 = (LispObject)33; // 2
    v0156 = (LispObject)lessp2(v0230, v0156);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    v0156 = v0156 ? lisp_true : nil;
    env = stack[-2];
    if (v0156 == nil) goto v0274;
    stack[-1] = qvalue(elt(env, 1)); // codmat
    v0230 = qvalue(elt(env, 2)); // maxvar
    v0156 = stack[0];
    v0156 = plus2(v0230, v0156);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-2];
    v0249 = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v0156/(16/CELL)));
    v0230 = (LispObject)1; // 0
    v0156 = qvalue(elt(env, 3)); // nil
    *(LispObject *)((char *)v0249 + (CELL-TAG_VECTOR) + ((int32_t)v0230/(16/CELL))) = v0156;
    stack[-1] = qvalue(elt(env, 1)); // codmat
    v0230 = qvalue(elt(env, 2)); // maxvar
    v0156 = stack[0];
    v0156 = plus2(v0230, v0156);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-2];
    v0230 = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v0156/(16/CELL)));
    v0156 = (LispObject)65; // 4
    v0156 = *(LispObject *)((char *)v0230 + (CELL-TAG_VECTOR) + ((int32_t)v0156/(16/CELL)));
    stack[-1] = v0156;
    goto v0280;

v0280:
    v0156 = stack[-1];
    if (v0156 == nil) goto v0301;
    v0156 = stack[-1];
    v0156 = qcar(v0156);
    stack[0] = v0156;
    v0156 = stack[0];
    v0230 = qcar(v0156);
    v0156 = stack[0];
    v0156 = qcdr(v0156);
    v0156 = qcar(v0156);
    fn = elt(env, 4); // downwght1
    v0156 = (*qfn2(fn))(qenv(fn), v0230, v0156);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-2];
    v0156 = stack[0];
    v0156 = qcar(v0156);
    v0156 = CC_testred(env, v0156);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-2];
    v0156 = stack[-1];
    v0156 = qcdr(v0156);
    stack[-1] = v0156;
    goto v0280;

v0301:
    v0156 = qvalue(elt(env, 3)); // nil
    { popv(3); return onevalue(v0156); }

v0274:
    v0156 = nil;
    { popv(3); return onevalue(v0156); }
// error exit handlers
v0124:
    popv(3);
    return nil;
}



// Code for simpindexvar

static LispObject CC_simpindexvar(LispObject env,
                         LispObject v0226)
{
    LispObject nil = C_nil;
    LispObject v0274;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for simpindexvar");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0226);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0226);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// copy arguments values to proper place
    v0274 = v0226;
// end of prologue
    fn = elt(env, 1); // partitindexvar
    v0274 = (*qfn1(fn))(qenv(fn), v0274);
    nil = C_nil;
    if (exception_pending()) goto v0287;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); // !*pf2sq
        return (*qfn1(fn))(qenv(fn), v0274);
    }
// error exit handlers
v0287:
    popv(1);
    return nil;
}



// Code for dim!<deg

static LispObject CC_dimRdeg(LispObject env,
                         LispObject v0226)
{
    LispObject nil = C_nil;
    LispObject v0166, v0269;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dim<deg");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0226);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0226);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0166 = v0226;
// end of prologue
    stack[0] = qvalue(elt(env, 1)); // dimex!*
    fn = elt(env, 4); // deg!*farg
    v0166 = (*qfn1(fn))(qenv(fn), v0166);
    nil = C_nil;
    if (exception_pending()) goto v0271;
    env = stack[-1];
    fn = elt(env, 5); // negf
    v0166 = (*qfn1(fn))(qenv(fn), v0166);
    nil = C_nil;
    if (exception_pending()) goto v0271;
    env = stack[-1];
    fn = elt(env, 6); // addf
    v0166 = (*qfn2(fn))(qenv(fn), stack[0], v0166);
    nil = C_nil;
    if (exception_pending()) goto v0271;
    env = stack[-1];
    v0269 = v0166;
    v0166 = v0269;
    if (!(is_number(v0166))) goto v0216;
    v0166 = v0269;
    v0166 = Lminusp(nil, v0166);
    env = stack[-1];
    if (v0166 == nil) goto v0216;
    v0166 = qvalue(elt(env, 2)); // t
    { popv(2); return onevalue(v0166); }

v0216:
    v0166 = qvalue(elt(env, 3)); // nil
    { popv(2); return onevalue(v0166); }
// error exit handlers
v0271:
    popv(2);
    return nil;
}



// Code for opnum!*

static LispObject CC_opnumH(LispObject env,
                         LispObject v0226)
{
    LispObject nil = C_nil;
    LispObject v0241, v0133, v0150;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for opnum*");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0226);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0226);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    v0133 = v0226;
// end of prologue
    stack[-1] = nil;
    v0241 = v0133;
    if (symbolp(v0241)) goto v0165;
    stack[0] = v0133;
    v0241 = v0133;
    fn = elt(env, 3); // collectindices
    v0241 = (*qfn1(fn))(qenv(fn), v0241);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-2];
    fn = elt(env, 4); // removeindices
    v0241 = (*qfn2(fn))(qenv(fn), stack[0], v0241);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-2];
    v0133 = v0241;
    goto v0165;

v0165:
    v0241 = v0133;
    if (symbolp(v0241)) goto v0214;
    v0241 = v0133;
    v0241 = qcar(v0241);
    v0133 = qcdr(v0133);
    stack[-1] = v0133;
    goto v0136;

v0136:
    v0133 = v0241;
    v0241 = elt(env, 2); // opnum
    v0241 = get(v0133, v0241);
    env = stack[-2];
    v0150 = v0241;
    v0133 = stack[-1];
    v0241 = v0150;
    v0241 = Lassoc(nil, v0133, v0241);
    v0133 = v0241;
    if (v0241 == nil) goto v0309;
    v0241 = v0133;
    v0241 = qcdr(v0241);
    { popv(3); return onevalue(v0241); }

v0309:
    v0241 = qvalue(elt(env, 1)); // nil
    v0133 = v0150;
    v0241 = Lassoc(nil, v0241, v0133);
    v0241 = qcdr(v0241);
    { popv(3); return onevalue(v0241); }

v0214:
    v0241 = v0133;
    goto v0136;
// error exit handlers
v0282:
    popv(3);
    return nil;
}



// Code for assert_analyze

static LispObject CC_assert_analyze(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0330, v0331;
    LispObject fn;
    argcheck(nargs, 0, "assert_analyze");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for assert_analyze");
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
// end of prologue
    v0330 = (LispObject)1; // 0
    stack[0] = v0330;
    v0330 = (LispObject)1; // 0
    stack[-4] = v0330;
    v0330 = (LispObject)1; // 0
    stack[-2] = v0330;
    v0331 = qvalue(elt(env, 1)); // assertstatistics!*
    v0330 = elt(env, 2); // lambda_wrlijy187crc
    fn = elt(env, 8); // sort
    v0330 = (*qfn2(fn))(qenv(fn), v0331, v0330);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-5];
    qvalue(elt(env, 1)) = v0330; // assertstatistics!*
    v0330 = qvalue(elt(env, 1)); // assertstatistics!*
    stack[-3] = v0330;
    goto v0266;

v0266:
    v0330 = stack[-3];
    if (v0330 == nil) goto v0204;
    v0330 = stack[-3];
    v0330 = qcar(v0330);
    stack[-1] = v0330;
    v0331 = stack[0];
    v0330 = stack[-1];
    v0330 = qcdr(v0330);
    v0330 = qcar(v0330);
    v0330 = plus2(v0331, v0330);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-5];
    stack[0] = v0330;
    v0331 = stack[-4];
    v0330 = stack[-1];
    v0330 = qcdr(v0330);
    v0330 = qcdr(v0330);
    v0330 = qcar(v0330);
    v0330 = plus2(v0331, v0330);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-5];
    stack[-4] = v0330;
    v0331 = stack[-2];
    v0330 = stack[-1];
    v0330 = qcdr(v0330);
    v0330 = qcdr(v0330);
    v0330 = qcdr(v0330);
    v0330 = qcar(v0330);
    v0330 = plus2(v0331, v0330);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-5];
    stack[-2] = v0330;
    v0330 = stack[-3];
    v0330 = qcdr(v0330);
    stack[-3] = v0330;
    goto v0266;

v0204:
    v0330 = elt(env, 4); // (function !#calls !#bad! calls !#assertion! violations)
    stack[-3] = v0330;
    stack[-1] = elt(env, 5); // sum
    v0331 = stack[-4];
    v0330 = stack[-2];
    v0330 = list2(v0331, v0330);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-5];
    v0330 = list2star(stack[-1], stack[0], v0330);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-5];
    stack[-4] = qvalue(elt(env, 3)); // nil
    stack[-2] = qvalue(elt(env, 3)); // nil
    stack[-1] = qvalue(elt(env, 3)); // nil
    stack[0] = v0330;
    v0331 = qvalue(elt(env, 3)); // nil
    v0330 = qvalue(elt(env, 1)); // assertstatistics!*
    v0330 = cons(v0331, v0330);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-5];
    v0330 = list2star(stack[-1], stack[0], v0330);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-5];
    v0330 = Lnreverse(nil, v0330);
    env = stack[-5];
    v0330 = cons(stack[-2], v0330);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-5];
    v0330 = list2star(stack[-4], stack[-3], v0330);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-5];
    qvalue(elt(env, 1)) = v0330; // assertstatistics!*
    v0330 = qvalue(elt(env, 1)); // assertstatistics!*
    stack[-2] = v0330;
    goto v0232;

v0232:
    v0330 = stack[-2];
    if (v0330 == nil) goto v0231;
    v0330 = stack[-2];
    v0330 = qcar(v0330);
    stack[-1] = v0330;
    v0330 = stack[-1];
    if (v0330 == nil) goto v0333;
    v0330 = stack[-1];
    v0330 = qcar(v0330);
    v0330 = Lprinc(nil, v0330);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-5];
    v0330 = stack[-1];
    v0330 = qcar(v0330);
    v0330 = Lexplodec(nil, v0330);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-5];
    stack[0] = Llength(nil, v0330);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-5];
    v0330 = stack[-1];
    v0330 = qcdr(v0330);
    v0330 = qcar(v0330);
    v0330 = Lexplodec(nil, v0330);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-5];
    v0330 = Llength(nil, v0330);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-5];
    v0330 = plus2(stack[0], v0330);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-5];
    stack[0] = v0330;
    goto v0288;

v0288:
    v0331 = (LispObject)369; // 23
    v0330 = stack[0];
    v0330 = difference2(v0331, v0330);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-5];
    v0330 = Lminusp(nil, v0330);
    env = stack[-5];
    if (v0330 == nil) goto v0121;
    v0330 = stack[-1];
    v0330 = qcdr(v0330);
    v0330 = qcar(v0330);
    v0330 = Lprinc(nil, v0330);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-5];
    v0330 = stack[-1];
    v0330 = qcdr(v0330);
    v0330 = qcdr(v0330);
    v0330 = qcar(v0330);
    v0330 = Lexplodec(nil, v0330);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-5];
    v0330 = Llength(nil, v0330);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-5];
    stack[0] = v0330;
    goto v0334;

v0334:
    v0331 = (LispObject)369; // 23
    v0330 = stack[0];
    v0330 = difference2(v0331, v0330);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-5];
    v0330 = Lminusp(nil, v0330);
    env = stack[-5];
    if (v0330 == nil) goto v0335;
    v0330 = stack[-1];
    v0330 = qcdr(v0330);
    v0330 = qcdr(v0330);
    v0330 = qcar(v0330);
    v0330 = Lprinc(nil, v0330);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-5];
    v0330 = stack[-1];
    v0330 = qcdr(v0330);
    v0330 = qcdr(v0330);
    v0330 = qcdr(v0330);
    v0330 = qcar(v0330);
    v0330 = Lexplodec(nil, v0330);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-5];
    v0330 = Llength(nil, v0330);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-5];
    stack[0] = v0330;
    goto v0336;

v0336:
    v0331 = (LispObject)369; // 23
    v0330 = stack[0];
    v0330 = difference2(v0331, v0330);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-5];
    v0330 = Lminusp(nil, v0330);
    env = stack[-5];
    if (v0330 == nil) goto v0337;
    v0330 = stack[-1];
    v0330 = qcdr(v0330);
    v0330 = qcdr(v0330);
    v0330 = qcdr(v0330);
    v0330 = qcar(v0330);
    fn = elt(env, 9); // prin2t
    v0330 = (*qfn1(fn))(qenv(fn), v0330);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-5];
    goto v0249;

v0249:
    v0330 = stack[-2];
    v0330 = qcdr(v0330);
    stack[-2] = v0330;
    goto v0232;

v0337:
    v0330 = elt(env, 6); // " "
    v0330 = Lprinc(nil, v0330);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-5];
    v0330 = stack[0];
    v0330 = add1(v0330);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-5];
    stack[0] = v0330;
    goto v0336;

v0335:
    v0330 = elt(env, 6); // " "
    v0330 = Lprinc(nil, v0330);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-5];
    v0330 = stack[0];
    v0330 = add1(v0330);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-5];
    stack[0] = v0330;
    goto v0334;

v0121:
    v0330 = elt(env, 6); // " "
    v0330 = Lprinc(nil, v0330);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-5];
    v0330 = stack[0];
    v0330 = add1(v0330);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-5];
    stack[0] = v0330;
    goto v0288;

v0333:
    v0330 = (LispObject)17; // 1
    stack[0] = v0330;
    goto v0338;

v0338:
    v0331 = (LispObject)1153; // 72
    v0330 = stack[0];
    v0330 = difference2(v0331, v0330);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-5];
    v0330 = Lminusp(nil, v0330);
    env = stack[-5];
    if (v0330 == nil) goto v0339;
    v0330 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-5];
    goto v0249;

v0339:
    v0330 = elt(env, 7); // "-"
    v0330 = Lprinc(nil, v0330);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-5];
    v0330 = stack[0];
    v0330 = add1(v0330);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-5];
    stack[0] = v0330;
    goto v0338;

v0231:
    v0330 = qvalue(elt(env, 3)); // nil
    qvalue(elt(env, 1)) = v0330; // assertstatistics!*
    v0330 = nil;
    { popv(6); return onevalue(v0330); }
// error exit handlers
v0332:
    popv(6);
    return nil;
}



// Code for lambda_wrlijy187crc

static LispObject CC_lambda_wrlijy187crc(LispObject env,
                         LispObject v0226, LispObject v0006)
{
    LispObject nil = C_nil;
    LispObject v0201, v0179;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lambda_wrlijy187crc");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0179 = v0006;
    v0201 = v0226;
// end of prologue
    v0179 = qcar(v0179);
    v0201 = qcar(v0201);
    {
        fn = elt(env, 1); // ordp
        return (*qfn2(fn))(qenv(fn), v0179, v0201);
    }
}



// Code for !*i2gi

static LispObject CC_Hi2gi(LispObject env,
                         LispObject v0226)
{
    LispObject nil = C_nil;
    LispObject v0201, v0179, v0242;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *i2gi");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0201 = v0226;
// end of prologue
    v0242 = elt(env, 1); // !:gi!:
    v0179 = v0201;
    v0201 = (LispObject)1; // 0
    return list2star(v0242, v0179, v0201);
}



// Code for exptf1

static LispObject CC_exptf1(LispObject env,
                         LispObject v0226, LispObject v0006)
{
    LispObject nil = C_nil;
    LispObject v0244, v0243;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for exptf1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0006,v0226);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0226,v0006);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0006;
    stack[-1] = v0226;
// end of prologue
    v0243 = stack[0];
    v0244 = (LispObject)1; // 0
    if (v0243 == v0244) goto v0274;
    v0244 = stack[-1];
    stack[-2] = v0244;
    goto v0269;

v0269:
    v0244 = stack[0];
    v0243 = sub1(v0244);
    nil = C_nil;
    if (exception_pending()) goto v0317;
    env = stack[-3];
    stack[0] = v0243;
    v0244 = (LispObject)1; // 0
    v0244 = (LispObject)greaterp2(v0243, v0244);
    nil = C_nil;
    if (exception_pending()) goto v0317;
    v0244 = v0244 ? lisp_true : nil;
    env = stack[-3];
    if (v0244 == nil) { LispObject res = stack[-2]; popv(4); return onevalue(res); }
    v0243 = stack[-1];
    v0244 = stack[-2];
    fn = elt(env, 2); // multf
    v0244 = (*qfn2(fn))(qenv(fn), v0243, v0244);
    nil = C_nil;
    if (exception_pending()) goto v0317;
    env = stack[-3];
    stack[-2] = v0244;
    goto v0269;

v0274:
    v0244 = (LispObject)17; // 1
    { popv(4); return onevalue(v0244); }
// error exit handlers
v0317:
    popv(4);
    return nil;
}



// Code for lalr_gensym

static LispObject CC_lalr_gensym(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0201;
    LispObject fn;
    argcheck(nargs, 0, "lalr_gensym");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lalr_gensym");
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
    stack[0] = elt(env, 1); // "lalr_action_function_"
    v0201 = qvalue(elt(env, 2)); // lalr_action_counter
    v0201 = add1(v0201);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-1];
    qvalue(elt(env, 2)) = v0201; // lalr_action_counter
    v0201 = Lexplode(nil, v0201);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-1];
    fn = elt(env, 3); // list2string
    v0201 = (*qfn1(fn))(qenv(fn), v0201);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-1];
    fn = elt(env, 4); // concat
    v0201 = (*qfn2(fn))(qenv(fn), stack[0], v0201);
    nil = C_nil;
    if (exception_pending()) goto v0242;
        popv(2);
        return Lintern(nil, v0201);
// error exit handlers
v0242:
    popv(2);
    return nil;
}



// Code for rmplus

static LispObject CC_rmplus(LispObject env,
                         LispObject v0226)
{
    LispObject nil = C_nil;
    LispObject v0264, v0204, v0266;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rmplus");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0204 = v0226;
// end of prologue
    v0264 = v0204;
    v0266 = elt(env, 1); // plus
    if (!consp(v0264)) goto v0233;
    v0264 = qcar(v0264);
    if (!(v0264 == v0266)) goto v0233;
    v0264 = v0204;
    v0264 = qcdr(v0264);
    return onevalue(v0264);

v0233:
    v0264 = v0204;
    return ncons(v0264);
}



// Code for ordpa

static LispObject CC_ordpa(LispObject env,
                         LispObject v0226, LispObject v0006)
{
    LispObject nil = C_nil;
    LispObject v0300, v0301, v0126, v0155;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ordpa");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0006,v0226);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0226,v0006);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// copy arguments values to proper place
    v0301 = v0006;
    v0126 = v0226;
// end of prologue

v0274:
    v0300 = v0126;
    if (v0300 == nil) goto v0165;
    v0300 = v0301;
    if (v0300 == nil) goto v0201;
    v0300 = v0126;
    v0300 = Lsimple_vectorp(nil, v0300);
    env = stack[0];
    if (v0300 == nil) goto v0258;
    v0300 = v0301;
    v0300 = Lsimple_vectorp(nil, v0300);
    env = stack[0];
    if (v0300 == nil) goto v0136;
    v0300 = v0126;
    {
        popv(1);
        fn = elt(env, 3); // ordpv
        return (*qfn2(fn))(qenv(fn), v0300, v0301);
    }

v0136:
    v0300 = v0301;
    v0300 = (consp(v0300) ? nil : lisp_true);
    { popv(1); return onevalue(v0300); }

v0258:
    v0300 = v0126;
    if (!consp(v0300)) goto v0143;
    v0300 = v0301;
    if (!consp(v0300)) goto v0303;
    v0300 = v0126;
    v0155 = qcar(v0300);
    v0300 = v0301;
    v0300 = qcar(v0300);
    if (equal(v0155, v0300)) goto v0234;
    v0300 = v0126;
    v0300 = qcar(v0300);
    v0126 = v0300;
    v0300 = v0301;
    v0300 = qcar(v0300);
    v0301 = v0300;
    goto v0274;

v0234:
    v0300 = v0126;
    v0300 = qcdr(v0300);
    v0126 = v0300;
    v0300 = v0301;
    v0300 = qcdr(v0300);
    v0301 = v0300;
    goto v0274;

v0303:
    v0300 = qvalue(elt(env, 1)); // t
    { popv(1); return onevalue(v0300); }

v0143:
    v0300 = v0301;
    if (!consp(v0300)) goto v0139;
    v0300 = qvalue(elt(env, 2)); // nil
    { popv(1); return onevalue(v0300); }

v0139:
    v0300 = v0126;
    if (is_number(v0300)) goto v0262;
    v0300 = v0301;
    if (symbolp(v0300)) goto v0297;
    v0300 = v0301;
    v0300 = (is_number(v0300) ? lisp_true : nil);
    { popv(1); return onevalue(v0300); }

v0297:
    v0300 = v0126;
        popv(1);
        return Lorderp(nil, v0300, v0301);

v0262:
    v0300 = v0301;
    if (is_number(v0300)) goto v0309;
    v0300 = qvalue(elt(env, 2)); // nil
    { popv(1); return onevalue(v0300); }

v0309:
    v0300 = v0126;
    v0300 = (LispObject)lessp2(v0300, v0301);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    v0300 = v0300 ? lisp_true : nil;
    v0300 = (v0300 == nil ? lisp_true : nil);
    { popv(1); return onevalue(v0300); }

v0201:
    v0300 = qvalue(elt(env, 1)); // t
    { popv(1); return onevalue(v0300); }

v0165:
    v0300 = v0301;
    v0300 = (v0300 == nil ? lisp_true : nil);
    { popv(1); return onevalue(v0300); }
// error exit handlers
v0154:
    popv(1);
    return nil;
}



// Code for wulessp!*

static LispObject CC_wulesspH(LispObject env,
                         LispObject v0226, LispObject v0006)
{
    LispObject nil = C_nil;
    LispObject v0144, v0247;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for wulessp*");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0006,v0226);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0226,v0006);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0006;
    stack[-1] = v0226;
// end of prologue
    v0247 = stack[-1];
    v0144 = stack[0];
    fn = elt(env, 3); // wulessp
    v0144 = (*qfn2(fn))(qenv(fn), v0247, v0144);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    env = stack[-2];
    if (v0144 == nil) goto v0170;
    v0144 = qvalue(elt(env, 1)); // t
    { popv(3); return onevalue(v0144); }

v0170:
    v0247 = stack[0];
    v0144 = stack[-1];
    fn = elt(env, 3); // wulessp
    v0144 = (*qfn2(fn))(qenv(fn), v0247, v0144);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    env = stack[-2];
    if (v0144 == nil) goto v0270;
    v0144 = qvalue(elt(env, 2)); // nil
    { popv(3); return onevalue(v0144); }

v0270:
    v0247 = stack[-1];
    v0144 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); // totallessp
        return (*qfn2(fn))(qenv(fn), v0247, v0144);
    }
// error exit handlers
v0253:
    popv(3);
    return nil;
}



// Code for matrix!+p

static LispObject CC_matrixLp(LispObject env,
                         LispObject v0226)
{
    LispObject nil = C_nil;
    LispObject v0246, v0138;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for matrix+p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0226);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0226);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0226;
// end of prologue
    v0246 = stack[0];
    v0138 = Llength(nil, v0246);
    nil = C_nil;
    if (exception_pending()) goto v0259;
    env = stack[-4];
    v0246 = (LispObject)17; // 1
    v0246 = (LispObject)lessp2(v0138, v0246);
    nil = C_nil;
    if (exception_pending()) goto v0259;
    v0246 = v0246 ? lisp_true : nil;
    env = stack[-4];
    if (v0246 == nil) goto v0165;
    v0246 = qvalue(elt(env, 1)); // nil
    { popv(5); return onevalue(v0246); }

v0165:
    v0246 = stack[0];
    v0246 = qcar(v0246);
    v0246 = Llength(nil, v0246);
    nil = C_nil;
    if (exception_pending()) goto v0259;
    env = stack[-4];
    stack[-3] = v0246;
    v0246 = qvalue(elt(env, 2)); // t
    stack[-2] = v0246;
    v0246 = stack[0];
    v0246 = qcdr(v0246);
    stack[-1] = v0246;
    goto v0166;

v0166:
    v0246 = stack[-1];
    if (v0246 == nil) { LispObject res = stack[-2]; popv(5); return onevalue(res); }
    v0246 = stack[-1];
    v0246 = qcar(v0246);
    stack[0] = stack[-3];
    v0246 = Llength(nil, v0246);
    nil = C_nil;
    if (exception_pending()) goto v0259;
    env = stack[-4];
    if (equal(stack[0], v0246)) goto v0253;
    v0246 = qvalue(elt(env, 1)); // nil
    stack[-2] = v0246;
    goto v0253;

v0253:
    v0246 = stack[-1];
    v0246 = qcdr(v0246);
    stack[-1] = v0246;
    goto v0166;
// error exit handlers
v0259:
    popv(5);
    return nil;
}



// Code for rat_sgn

static LispObject CC_rat_sgn(LispObject env,
                         LispObject v0226)
{
    LispObject nil = C_nil;
    LispObject v0274;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rat_sgn");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0226);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0226);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// copy arguments values to proper place
    v0274 = v0226;
// end of prologue
    fn = elt(env, 1); // rat_numrn
    v0274 = (*qfn1(fn))(qenv(fn), v0274);
    nil = C_nil;
    if (exception_pending()) goto v0287;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); // sgn
        return (*qfn1(fn))(qenv(fn), v0274);
    }
// error exit handlers
v0287:
    popv(1);
    return nil;
}



// Code for objectom

static LispObject CC_objectom(LispObject env,
                         LispObject v0226)
{
    LispObject nil = C_nil;
    LispObject v0296, v0244, v0243;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for objectom");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0226);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0226);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0244 = v0226;
// end of prologue
    v0296 = v0244;
    v0296 = Lconsp(nil, v0296);
    env = stack[-1];
    if (v0296 == nil) goto v0267;
    v0296 = v0244;
    v0243 = qcar(v0296);
    v0296 = qvalue(elt(env, 1)); // ir2mml!*
    v0296 = Lassoc(nil, v0243, v0296);
    v0243 = v0296;
    if (v0296 == nil) goto v0144;
    v0296 = v0243;
    v0296 = qcdr(v0296);
    v0296 = qcdr(v0296);
    v0296 = qcdr(v0296);
    stack[0] = qcar(v0296);
    v0296 = v0244;
    v0296 = ncons(v0296);
    nil = C_nil;
    if (exception_pending()) goto v0263;
    env = stack[-1];
    fn = elt(env, 3); // apply
    v0296 = (*qfn2(fn))(qenv(fn), stack[0], v0296);
    nil = C_nil;
    if (exception_pending()) goto v0263;
    goto v0287;

v0287:
    v0296 = nil;
    { popv(2); return onevalue(v0296); }

v0144:
    v0296 = v0244;
    fn = elt(env, 4); // fnom
    v0296 = (*qfn1(fn))(qenv(fn), v0296);
    nil = C_nil;
    if (exception_pending()) goto v0263;
    goto v0287;

v0267:
    v0296 = v0244;
    fn = elt(env, 5); // basicom
    v0296 = (*qfn1(fn))(qenv(fn), v0296);
    nil = C_nil;
    if (exception_pending()) goto v0263;
    goto v0287;
// error exit handlers
v0263:
    popv(2);
    return nil;
}



// Code for ident

static LispObject CC_ident(LispObject env,
                         LispObject v0226)
{
    LispObject v0061;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ident");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0061 = v0226;
// end of prologue
    return onevalue(v0061);
}



// Code for covposp

static LispObject CC_covposp(LispObject env,
                         LispObject v0226)
{
    LispObject nil = C_nil;
    LispObject v0266, v0214;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for covposp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0266 = v0226;
// end of prologue

v0252:
    v0214 = v0266;
    if (v0214 == nil) goto v0257;
    v0214 = v0266;
    v0214 = qcar(v0214);
    if (!consp(v0214)) goto v0170;
    v0266 = qcdr(v0266);
    goto v0252;

v0170:
    v0266 = qvalue(elt(env, 2)); // nil
    return onevalue(v0266);

v0257:
    v0266 = qvalue(elt(env, 1)); // t
    return onevalue(v0266);
}



// Code for statep!*

static LispObject CC_statepH(LispObject env,
                         LispObject v0226)
{
    LispObject nil = C_nil;
    LispObject v0197, v0198;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for statep*");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0226);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0226);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// copy arguments values to proper place
    v0197 = v0226;
// end of prologue
    fn = elt(env, 2); // getphystype
    v0197 = (*qfn1(fn))(qenv(fn), v0197);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[0];
    v0198 = elt(env, 1); // state
    v0197 = (v0197 == v0198 ? lisp_true : nil);
    { popv(1); return onevalue(v0197); }
// error exit handlers
v0201:
    popv(1);
    return nil;
}



// Code for maprint

static LispObject CC_maprint(LispObject env,
                         LispObject v0006, LispObject v0011)
{
    LispObject nil = C_nil;
    LispObject v0354, v0355, v0356;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for maprint");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0011,v0006);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0006,v0011);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    v0354 = v0011;
    stack[-3] = v0006;
// end of prologue
    stack[-4] = qvalue(elt(env, 1)); // p!*!*
    qvalue(elt(env, 1)) = nil; // p!*!*
    qvalue(elt(env, 1)) = v0354; // p!*!*
    stack[0] = nil;
    v0354 = qvalue(elt(env, 1)); // p!*!*
    stack[-2] = v0354;
    v0354 = stack[-3];
    if (v0354 == nil) goto v0233;
    v0354 = stack[-3];
    if (!consp(v0354)) goto v0264;
    v0354 = stack[-3];
    v0354 = qcar(v0354);
    if (!consp(v0354)) goto v0315;
    v0354 = stack[-3];
    v0355 = qcar(v0354);
    v0354 = stack[-2];
    v0354 = CC_maprint(env, v0355, v0354);
    nil = C_nil;
    if (exception_pending()) goto v0106;
    env = stack[-5];
    goto v0242;

v0242:
    v0354 = elt(env, 5); // "("
    fn = elt(env, 12); // prin2!*
    v0354 = (*qfn1(fn))(qenv(fn), v0354);
    nil = C_nil;
    if (exception_pending()) goto v0106;
    env = stack[-5];
    v0354 = qvalue(elt(env, 2)); // nil
    qvalue(elt(env, 10)) = v0354; // obrkp!*
    v0354 = qvalue(elt(env, 8)); // orig!*
    stack[0] = v0354;
    v0355 = qvalue(elt(env, 9)); // posn!*
    v0354 = (LispObject)289; // 18
    v0354 = (LispObject)lessp2(v0355, v0354);
    nil = C_nil;
    if (exception_pending()) goto v0106;
    v0354 = v0354 ? lisp_true : nil;
    env = stack[-5];
    if (v0354 == nil) goto v0357;
    v0354 = qvalue(elt(env, 9)); // posn!*
    goto v0358;

v0358:
    qvalue(elt(env, 8)) = v0354; // orig!*
    v0354 = stack[-3];
    v0354 = qcdr(v0354);
    if (v0354 == nil) goto v0173;
    v0356 = elt(env, 11); // !*comma!*
    v0355 = (LispObject)1; // 0
    v0354 = stack[-3];
    v0354 = qcdr(v0354);
    fn = elt(env, 13); // inprint
    v0354 = (*qfnn(fn))(qenv(fn), 3, v0356, v0355, v0354);
    nil = C_nil;
    if (exception_pending()) goto v0106;
    env = stack[-5];
    goto v0173;

v0173:
    v0354 = qvalue(elt(env, 3)); // t
    qvalue(elt(env, 10)) = v0354; // obrkp!*
    v0354 = stack[0];
    qvalue(elt(env, 8)) = v0354; // orig!*
    v0354 = elt(env, 6); // ")"
    fn = elt(env, 12); // prin2!*
    v0354 = (*qfn1(fn))(qenv(fn), v0354);
    nil = C_nil;
    if (exception_pending()) goto v0106;
    env = stack[-5];
    v0354 = stack[-3];
    goto v0287;

v0287:
    qvalue(elt(env, 1)) = stack[-4]; // p!*!*
    { popv(6); return onevalue(v0354); }

v0357:
    v0355 = qvalue(elt(env, 8)); // orig!*
    v0354 = (LispObject)49; // 3
    v0354 = plus2(v0355, v0354);
    nil = C_nil;
    if (exception_pending()) goto v0106;
    env = stack[-5];
    goto v0358;

v0315:
    v0354 = stack[-3];
    v0354 = qcar(v0354);
    if (!symbolp(v0354)) v0354 = nil;
    else { v0354 = qfastgets(v0354);
           if (v0354 != nil) { v0354 = elt(v0354, 60); // pprifn
#ifdef RECORD_GET
             if (v0354 != SPID_NOPROP)
                record_get(elt(fastget_names, 60), 1);
             else record_get(elt(fastget_names, 60), 0),
                v0354 = nil; }
           else record_get(elt(fastget_names, 60), 0); }
#else
             if (v0354 == SPID_NOPROP) v0354 = nil; }}
#endif
    stack[-1] = v0354;
    if (v0354 == nil) goto v0328;
    v0356 = stack[-1];
    v0355 = stack[-3];
    v0354 = stack[-2];
    v0355 = Lapply2(nil, 3, v0356, v0355, v0354);
    nil = C_nil;
    if (exception_pending()) goto v0106;
    env = stack[-5];
    v0354 = elt(env, 7); // failed
    if (!(v0355 == v0354)) goto v0329;

v0328:
    v0354 = stack[-3];
    v0354 = qcar(v0354);
    if (!symbolp(v0354)) v0354 = nil;
    else { v0354 = qfastgets(v0354);
           if (v0354 != nil) { v0354 = elt(v0354, 57); // prifn
#ifdef RECORD_GET
             if (v0354 != SPID_NOPROP)
                record_get(elt(fastget_names, 57), 1);
             else record_get(elt(fastget_names, 57), 0),
                v0354 = nil; }
           else record_get(elt(fastget_names, 57), 0); }
#else
             if (v0354 == SPID_NOPROP) v0354 = nil; }}
#endif
    stack[-1] = v0354;
    if (v0354 == nil) goto v0299;
    v0355 = stack[-1];
    v0354 = stack[-3];
    v0355 = Lapply1(nil, v0355, v0354);
    nil = C_nil;
    if (exception_pending()) goto v0106;
    env = stack[-5];
    v0354 = elt(env, 7); // failed
    if (!(v0355 == v0354)) goto v0329;

v0299:
    v0354 = stack[-3];
    v0354 = qcar(v0354);
    if (!symbolp(v0354)) v0354 = nil;
    else { v0354 = qfastgets(v0354);
           if (v0354 != nil) { v0354 = elt(v0354, 23); // infix
#ifdef RECORD_GET
             if (v0354 != SPID_NOPROP)
                record_get(elt(fastget_names, 23), 1);
             else record_get(elt(fastget_names, 23), 0),
                v0354 = nil; }
           else record_get(elt(fastget_names, 23), 0); }
#else
             if (v0354 == SPID_NOPROP) v0354 = nil; }}
#endif
    stack[-1] = v0354;
    if (v0354 == nil) goto v0323;
    v0355 = stack[-1];
    v0354 = stack[-2];
    v0354 = (LispObject)greaterp2(v0355, v0354);
    nil = C_nil;
    if (exception_pending()) goto v0106;
    v0354 = v0354 ? lisp_true : nil;
    env = stack[-5];
    v0354 = (v0354 == nil ? lisp_true : nil);
    stack[-2] = v0354;
    v0354 = stack[-2];
    if (v0354 == nil) goto v0359;
    v0354 = qvalue(elt(env, 8)); // orig!*
    stack[0] = v0354;
    v0354 = elt(env, 5); // "("
    fn = elt(env, 12); // prin2!*
    v0354 = (*qfn1(fn))(qenv(fn), v0354);
    nil = C_nil;
    if (exception_pending()) goto v0106;
    env = stack[-5];
    v0355 = qvalue(elt(env, 9)); // posn!*
    v0354 = (LispObject)289; // 18
    v0354 = (LispObject)lessp2(v0355, v0354);
    nil = C_nil;
    if (exception_pending()) goto v0106;
    v0354 = v0354 ? lisp_true : nil;
    env = stack[-5];
    if (v0354 == nil) goto v0360;
    v0354 = qvalue(elt(env, 9)); // posn!*
    goto v0120;

v0120:
    qvalue(elt(env, 8)) = v0354; // orig!*
    goto v0359;

v0359:
    v0354 = stack[-3];
    v0356 = qcar(v0354);
    v0355 = stack[-1];
    v0354 = stack[-3];
    v0354 = qcdr(v0354);
    fn = elt(env, 13); // inprint
    v0354 = (*qfnn(fn))(qenv(fn), 3, v0356, v0355, v0354);
    nil = C_nil;
    if (exception_pending()) goto v0106;
    env = stack[-5];
    v0354 = stack[-2];
    if (v0354 == nil) goto v0361;
    v0354 = elt(env, 6); // ")"
    fn = elt(env, 12); // prin2!*
    v0354 = (*qfn1(fn))(qenv(fn), v0354);
    nil = C_nil;
    if (exception_pending()) goto v0106;
    env = stack[-5];
    v0354 = stack[0];
    qvalue(elt(env, 8)) = v0354; // orig!*
    goto v0361;

v0361:
    v0354 = stack[-3];
    goto v0287;

v0360:
    v0355 = qvalue(elt(env, 8)); // orig!*
    v0354 = (LispObject)49; // 3
    v0354 = plus2(v0355, v0354);
    nil = C_nil;
    if (exception_pending()) goto v0106;
    env = stack[-5];
    goto v0120;

v0323:
    v0354 = stack[-3];
    v0354 = qcar(v0354);
    fn = elt(env, 12); // prin2!*
    v0354 = (*qfn1(fn))(qenv(fn), v0354);
    nil = C_nil;
    if (exception_pending()) goto v0106;
    env = stack[-5];
    goto v0242;

v0329:
    v0354 = stack[-3];
    goto v0287;

v0264:
    v0354 = stack[-3];
    v0354 = Lsimple_vectorp(nil, v0354);
    env = stack[-5];
    if (v0354 == nil) goto v0219;
    v0355 = stack[-3];
    v0354 = qvalue(elt(env, 1)); // p!*!*
    fn = elt(env, 14); // vec!-maprin
    v0354 = (*qfn2(fn))(qenv(fn), v0355, v0354);
    nil = C_nil;
    if (exception_pending()) goto v0106;
    env = stack[-5];
    goto v0215;

v0215:
    v0354 = stack[-3];
    goto v0287;

v0219:
    v0354 = stack[-3];
    if (is_number(v0354)) goto v0317;
    v0354 = qvalue(elt(env, 3)); // t
    goto v0286;

v0286:
    if (v0354 == nil) goto v0297;
    v0354 = stack[-3];
    fn = elt(env, 12); // prin2!*
    v0354 = (*qfn1(fn))(qenv(fn), v0354);
    nil = C_nil;
    if (exception_pending()) goto v0106;
    env = stack[-5];
    goto v0215;

v0297:
    v0354 = elt(env, 5); // "("
    fn = elt(env, 12); // prin2!*
    v0354 = (*qfn1(fn))(qenv(fn), v0354);
    nil = C_nil;
    if (exception_pending()) goto v0106;
    env = stack[-5];
    v0354 = stack[-3];
    fn = elt(env, 12); // prin2!*
    v0354 = (*qfn1(fn))(qenv(fn), v0354);
    nil = C_nil;
    if (exception_pending()) goto v0106;
    env = stack[-5];
    v0354 = elt(env, 6); // ")"
    fn = elt(env, 12); // prin2!*
    v0354 = (*qfn1(fn))(qenv(fn), v0354);
    nil = C_nil;
    if (exception_pending()) goto v0106;
    env = stack[-5];
    goto v0215;

v0317:
    v0355 = stack[-3];
    v0354 = (LispObject)1; // 0
    v0354 = (LispObject)lessp2(v0355, v0354);
    nil = C_nil;
    if (exception_pending()) goto v0106;
    v0354 = v0354 ? lisp_true : nil;
    env = stack[-5];
    if (v0354 == nil) goto v0262;
    v0355 = stack[-2];
    v0354 = elt(env, 4); // minus
    if (!symbolp(v0354)) v0354 = nil;
    else { v0354 = qfastgets(v0354);
           if (v0354 != nil) { v0354 = elt(v0354, 23); // infix
#ifdef RECORD_GET
             if (v0354 != SPID_NOPROP)
                record_get(elt(fastget_names, 23), 1);
             else record_get(elt(fastget_names, 23), 0),
                v0354 = nil; }
           else record_get(elt(fastget_names, 23), 0); }
#else
             if (v0354 == SPID_NOPROP) v0354 = nil; }}
#endif
    v0354 = (LispObject)lesseq2(v0355, v0354);
    nil = C_nil;
    if (exception_pending()) goto v0106;
    v0354 = v0354 ? lisp_true : nil;
    env = stack[-5];
    goto v0286;

v0262:
    v0354 = qvalue(elt(env, 3)); // t
    goto v0286;

v0233:
    v0354 = qvalue(elt(env, 2)); // nil
    goto v0287;
// error exit handlers
v0106:
    env = stack[-5];
    qvalue(elt(env, 1)) = stack[-4]; // p!*!*
    popv(6);
    return nil;
}



// Code for split_ext

static LispObject CC_split_ext(LispObject env,
                         LispObject v0226, LispObject v0006)
{
    LispObject nil = C_nil;
    LispObject v0301, v0126, v0155;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for split_ext");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0006,v0226);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0226,v0006);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
// copy arguments values to proper place
    v0126 = v0006;
    v0155 = v0226;
// end of prologue
    v0301 = v0155;
    v0301 = qcdr(v0301);
    stack[-7] = v0301;
    v0301 = v0155;
    v0301 = qcar(v0301);
    fn = elt(env, 3); // split_form
    v0301 = (*qfn2(fn))(qenv(fn), v0301, v0126);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[-8];
    stack[0] = v0301;
    v0301 = elt(env, 1); // ext
    stack[-6] = ncons(v0301);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[-8];
    v0301 = stack[0];
    v0126 = qcar(v0301);
    v0301 = stack[-7];
    v0301 = cons(v0126, v0301);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[-8];
    fn = elt(env, 4); // cancel
    stack[-5] = (*qfn1(fn))(qenv(fn), v0301);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[-8];
    v0301 = stack[0];
    v0301 = qcdr(v0301);
    stack[-4] = v0301;
    v0301 = stack[-4];
    if (v0301 == nil) goto v0243;
    v0301 = stack[-4];
    v0301 = qcar(v0301);
    v0126 = v0301;
    v0301 = v0126;
    stack[0] = qcar(v0301);
    v0301 = v0126;
    v0126 = qcdr(v0301);
    v0301 = stack[-7];
    v0301 = cons(v0126, v0301);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[-8];
    fn = elt(env, 4); // cancel
    v0301 = (*qfn1(fn))(qenv(fn), v0301);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[-8];
    v0301 = cons(stack[0], v0301);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[-8];
    v0301 = ncons(v0301);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[-8];
    stack[-2] = v0301;
    stack[-3] = v0301;
    goto v0298;

v0298:
    v0301 = stack[-4];
    v0301 = qcdr(v0301);
    stack[-4] = v0301;
    v0301 = stack[-4];
    if (v0301 == nil) goto v0135;
    stack[-1] = stack[-2];
    v0301 = stack[-4];
    v0301 = qcar(v0301);
    v0126 = v0301;
    v0301 = v0126;
    stack[0] = qcar(v0301);
    v0301 = v0126;
    v0126 = qcdr(v0301);
    v0301 = stack[-7];
    v0301 = cons(v0126, v0301);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[-8];
    fn = elt(env, 4); // cancel
    v0301 = (*qfn1(fn))(qenv(fn), v0301);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[-8];
    v0301 = cons(stack[0], v0301);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[-8];
    v0301 = ncons(v0301);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[-8];
    v0301 = Lrplacd(nil, stack[-1], v0301);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[-8];
    v0301 = stack[-2];
    v0301 = qcdr(v0301);
    stack[-2] = v0301;
    goto v0298;

v0135:
    v0301 = stack[-3];
    goto v0215;

v0215:
    {
        LispObject v0231 = stack[-6];
        LispObject v0232 = stack[-5];
        popv(9);
        return acons(v0231, v0232, v0301);
    }

v0243:
    v0301 = qvalue(elt(env, 2)); // nil
    goto v0215;
// error exit handlers
v0128:
    popv(9);
    return nil;
}



// Code for sfto_qsub1

static LispObject CC_sfto_qsub1(LispObject env,
                         LispObject v0226, LispObject v0006)
{
    LispObject nil = C_nil;
    LispObject v0115, v0114, v0322;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sfto_qsub1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0006,v0226);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0226,v0006);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0006;
    stack[-2] = v0226;
// end of prologue
    v0115 = stack[-2];
    if (!consp(v0115)) goto v0242;
    v0115 = stack[-2];
    v0115 = qcar(v0115);
    v0115 = (consp(v0115) ? nil : lisp_true);
    goto v0179;

v0179:
    if (v0115 == nil) goto v0196;
    v0114 = stack[-2];
    v0115 = (LispObject)17; // 1
    popv(5);
    return cons(v0114, v0115);

v0196:
    v0115 = stack[-2];
    v0115 = qcar(v0115);
    v0115 = qcar(v0115);
    v0115 = qcar(v0115);
    stack[0] = v0115;
    goto v0247;

v0247:
    v0115 = stack[-1];
    if (v0115 == nil) goto v0144;
    v0115 = stack[-1];
    v0115 = qcar(v0115);
    v0114 = qcar(v0115);
    v0115 = stack[0];
    if (equal(v0114, v0115)) goto v0150;
    v0115 = stack[-1];
    v0115 = qcar(v0115);
    v0114 = qcar(v0115);
    v0115 = stack[0];
    fn = elt(env, 3); // ordop
    v0115 = (*qfn2(fn))(qenv(fn), v0114, v0115);
    nil = C_nil;
    if (exception_pending()) goto v0175;
    env = stack[-4];
    goto v0244;

v0244:
    if (v0115 == nil) goto v0144;
    v0115 = stack[-1];
    v0115 = qcdr(v0115);
    stack[-1] = v0115;
    goto v0247;

v0144:
    v0115 = stack[-1];
    if (v0115 == nil) goto v0316;
    v0115 = stack[-2];
    v0114 = qcdr(v0115);
    v0115 = stack[-1];
    v0115 = CC_sfto_qsub1(env, v0114, v0115);
    nil = C_nil;
    if (exception_pending()) goto v0175;
    env = stack[-4];
    stack[-3] = v0115;
    v0115 = stack[-1];
    v0115 = qcar(v0115);
    v0114 = qcar(v0115);
    v0115 = stack[0];
    if (v0114 == v0115) goto v0130;
    v0115 = stack[-2];
    v0115 = qcar(v0115);
    v0114 = qcdr(v0115);
    v0115 = stack[-1];
    v0115 = CC_sfto_qsub1(env, v0114, v0115);
    nil = C_nil;
    if (exception_pending()) goto v0175;
    env = stack[-4];
    stack[0] = v0115;
    v0115 = stack[-2];
    v0115 = qcar(v0115);
    v0115 = qcar(v0115);
    v0114 = qcar(v0115);
    v0115 = stack[-2];
    v0115 = qcar(v0115);
    v0115 = qcar(v0115);
    v0115 = qcdr(v0115);
    fn = elt(env, 4); // to
    v0114 = (*qfn2(fn))(qenv(fn), v0114, v0115);
    nil = C_nil;
    if (exception_pending()) goto v0175;
    env = stack[-4];
    v0115 = (LispObject)17; // 1
    v0322 = cons(v0114, v0115);
    nil = C_nil;
    if (exception_pending()) goto v0175;
    env = stack[-4];
    v0114 = qvalue(elt(env, 2)); // nil
    v0115 = (LispObject)17; // 1
    v0115 = acons(v0322, v0114, v0115);
    nil = C_nil;
    if (exception_pending()) goto v0175;
    env = stack[-4];
    v0114 = stack[0];
    fn = elt(env, 5); // multsq
    v0114 = (*qfn2(fn))(qenv(fn), v0114, v0115);
    nil = C_nil;
    if (exception_pending()) goto v0175;
    env = stack[-4];
    v0115 = stack[-3];
    {
        popv(5);
        fn = elt(env, 6); // addsq
        return (*qfn2(fn))(qenv(fn), v0114, v0115);
    }

v0130:
    v0115 = stack[-2];
    v0115 = qcar(v0115);
    v0114 = qcdr(v0115);
    v0115 = stack[-1];
    v0115 = qcdr(v0115);
    v0115 = CC_sfto_qsub1(env, v0114, v0115);
    nil = C_nil;
    if (exception_pending()) goto v0175;
    env = stack[-4];
    stack[0] = v0115;
    v0115 = stack[-1];
    v0115 = qcar(v0115);
    v0114 = qcdr(v0115);
    v0115 = stack[-2];
    v0115 = qcar(v0115);
    v0115 = qcar(v0115);
    v0115 = qcdr(v0115);
    fn = elt(env, 7); // exptsq
    v0115 = (*qfn2(fn))(qenv(fn), v0114, v0115);
    nil = C_nil;
    if (exception_pending()) goto v0175;
    env = stack[-4];
    v0114 = stack[0];
    fn = elt(env, 5); // multsq
    v0114 = (*qfn2(fn))(qenv(fn), v0114, v0115);
    nil = C_nil;
    if (exception_pending()) goto v0175;
    env = stack[-4];
    v0115 = stack[-3];
    {
        popv(5);
        fn = elt(env, 6); // addsq
        return (*qfn2(fn))(qenv(fn), v0114, v0115);
    }

v0316:
    v0114 = stack[-2];
    v0115 = (LispObject)17; // 1
    popv(5);
    return cons(v0114, v0115);

v0150:
    v0115 = qvalue(elt(env, 2)); // nil
    goto v0244;

v0242:
    v0115 = qvalue(elt(env, 1)); // t
    goto v0179;
// error exit handlers
v0175:
    popv(5);
    return nil;
}



// Code for remflagss

static LispObject CC_remflagss(LispObject env,
                         LispObject v0226, LispObject v0006)
{
    LispObject nil = C_nil;
    LispObject v0220, v0166, v0269, v0270;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for remflagss");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0006,v0226);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0226,v0006);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// copy arguments values to proper place
    v0220 = v0006;
    v0269 = v0226;
// end of prologue
    v0270 = v0220;
    goto v0287;

v0287:
    v0220 = v0270;
    if (v0220 == nil) goto v0196;
    v0220 = v0270;
    v0220 = qcar(v0220);
    v0166 = v0269;
    v0220 = Lremflag(nil, v0166, v0220);
    env = stack[0];
    v0220 = v0270;
    v0220 = qcdr(v0220);
    v0270 = v0220;
    goto v0287;

v0196:
    v0220 = qvalue(elt(env, 1)); // nil
    { popv(1); return onevalue(v0220); }
}



// Code for processcarpartitie1

static LispObject CC_processcarpartitie1(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0268, v0317, v0307;
    LispObject fn;
    LispObject v0257, v0061, v0011, v0006, v0226;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 5, "processcarpartitie1");
    va_start(aa, nargs);
    v0226 = va_arg(aa, LispObject);
    v0006 = va_arg(aa, LispObject);
    v0011 = va_arg(aa, LispObject);
    v0061 = va_arg(aa, LispObject);
    v0257 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for processcarpartitie1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v0257,v0061,v0011,v0006,v0226);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0226,v0006,v0011,v0061,v0257);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[-3] = v0257;
    stack[-4] = v0061;
    stack[-5] = v0011;
    v0268 = v0006;
    stack[-6] = v0226;
// end of prologue

v0152:
    v0317 = v0268;
    if (v0317 == nil) { LispObject res = stack[-3]; popv(9); return onevalue(res); }
    v0317 = v0268;
    v0317 = qcdr(v0317);
    stack[-7] = v0317;
    stack[-2] = stack[-5];
    stack[-1] = stack[-6];
    stack[0] = v0268;
    v0317 = stack[-4];
    v0307 = qcar(v0317);
    v0317 = qcar(v0268);
    v0268 = stack[-4];
    v0268 = qcdr(v0268);
    v0317 = list2star(v0307, v0317, v0268);
    nil = C_nil;
    if (exception_pending()) goto v0259;
    env = stack[-8];
    v0268 = stack[-3];
    fn = elt(env, 1); // processpartitie1
    v0268 = (*qfnn(fn))(qenv(fn), 5, stack[-2], stack[-1], stack[0], v0317, v0268);
    nil = C_nil;
    if (exception_pending()) goto v0259;
    env = stack[-8];
    stack[-3] = v0268;
    v0268 = stack[-7];
    goto v0152;
// error exit handlers
v0259:
    popv(9);
    return nil;
}



// Code for ofsf_smwupdknowl

static LispObject CC_ofsf_smwupdknowl(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0286, v0253, v0267, v0298, v0139;
    LispObject fn;
    LispObject v0061, v0011, v0006, v0226;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "ofsf_smwupdknowl");
    va_start(aa, nargs);
    v0226 = va_arg(aa, LispObject);
    v0006 = va_arg(aa, LispObject);
    v0011 = va_arg(aa, LispObject);
    v0061 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_smwupdknowl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0253 = v0061;
    v0267 = v0011;
    v0298 = v0006;
    v0139 = v0226;
// end of prologue
    v0286 = qvalue(elt(env, 1)); // !*rlsusi
    if (v0286 == nil) goto v0220;
    v0286 = v0139;
    {
        fn = elt(env, 2); // cl_susiupdknowl
        return (*qfnn(fn))(qenv(fn), 4, v0286, v0298, v0267, v0253);
    }

v0220:
    v0286 = v0139;
    {
        fn = elt(env, 3); // ofsf_smupdknowl
        return (*qfnn(fn))(qenv(fn), 4, v0286, v0298, v0267, v0253);
    }
}



// Code for removeg

static LispObject CC_removeg(LispObject env,
                         LispObject v0226, LispObject v0006)
{
    LispObject nil = C_nil;
    LispObject v0379, v0380, v0348, v0346;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for removeg");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0006,v0226);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0226,v0006);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0006;
    stack[-1] = v0226;
// end of prologue
    v0379 = stack[-1];
    v0380 = qcdr(v0379);
    v0379 = stack[0];
    v0379 = qcdr(v0379);
    v0379 = qcdr(v0379);
    v0379 = qcdr(v0379);
    v0379 = qcar(v0379);
    fn = elt(env, 8); // finde
    v0379 = (*qfn2(fn))(qenv(fn), v0380, v0379);
    nil = C_nil;
    if (exception_pending()) goto v0361;
    env = stack[-3];
    stack[-2] = v0379;
    v0379 = stack[-2];
    v0380 = qcar(v0379);
    v0379 = stack[0];
    if (!(v0380 == v0379)) goto v0264;
    v0379 = stack[-2];
    v0380 = qcdr(v0379);
    v0379 = stack[0];
    v0379 = qcdr(v0379);
    v0379 = qcdr(v0379);
    v0379 = qcdr(v0379);
    v0379 = qcar(v0379);
    fn = elt(env, 8); // finde
    v0379 = (*qfn2(fn))(qenv(fn), v0380, v0379);
    nil = C_nil;
    if (exception_pending()) goto v0361;
    env = stack[-3];
    stack[-2] = v0379;
    goto v0264;

v0264:
    v0379 = stack[-2];
    if (!(v0379 == nil)) goto v0140;
    v0346 = elt(env, 1); // "Free edge"
    v0379 = stack[0];
    v0379 = qcdr(v0379);
    v0379 = qcdr(v0379);
    v0379 = qcdr(v0379);
    v0348 = qcar(v0379);
    v0380 = elt(env, 2); // "in vertex"
    v0379 = stack[0];
    v0379 = list4(v0346, v0348, v0380, v0379);
    nil = C_nil;
    if (exception_pending()) goto v0361;
    env = stack[-3];
    fn = elt(env, 9); // cerror
    v0379 = (*qfn1(fn))(qenv(fn), v0379);
    nil = C_nil;
    if (exception_pending()) goto v0361;
    env = stack[-3];
    goto v0140;

v0140:
    v0379 = stack[-2];
    v0379 = qcar(v0379);
    stack[-2] = v0379;
    v0379 = stack[-2];
    v0379 = qcdr(v0379);
    v0380 = qcar(v0379);
    v0379 = stack[-2];
    v0379 = qcdr(v0379);
    v0379 = qcdr(v0379);
    v0379 = qcar(v0379);
    if (v0380 == v0379) goto v0236;
    v0379 = stack[-2];
    v0379 = qcdr(v0379);
    v0380 = qcar(v0379);
    v0379 = stack[-2];
    v0379 = qcdr(v0379);
    v0379 = qcdr(v0379);
    v0379 = qcdr(v0379);
    v0379 = qcar(v0379);
    if (v0380 == v0379) goto v0329;
    v0379 = stack[-2];
    v0379 = qcdr(v0379);
    v0379 = qcdr(v0379);
    v0380 = qcar(v0379);
    v0379 = stack[-2];
    v0379 = qcdr(v0379);
    v0379 = qcdr(v0379);
    v0379 = qcdr(v0379);
    v0379 = qcar(v0379);
    v0379 = (v0380 == v0379 ? lisp_true : nil);
    goto v0237;

v0237:
    if (v0379 == nil) goto v0125;
    v0380 = qvalue(elt(env, 4)); // nil
    v0379 = (LispObject)17; // 1
    v0379 = cons(v0380, v0379);
    nil = C_nil;
    if (exception_pending()) goto v0361;
    env = stack[-3];
    v0379 = ncons(v0379);
    nil = C_nil;
    if (exception_pending()) goto v0361;
    popv(4);
    return ncons(v0379);

v0125:
    v0379 = stack[-2];
    v0380 = qcar(v0379);
    v0379 = elt(env, 5); // qg
    if (v0380 == v0379) goto v0381;
    v0379 = stack[-2];
    v0380 = qcar(v0379);
    v0379 = elt(env, 6); // g3
    if (v0380 == v0379) goto v0382;
    v0380 = elt(env, 7); // "Invalid type of vertex"
    v0379 = stack[0];
    v0379 = list2(v0380, v0379);
    nil = C_nil;
    if (exception_pending()) goto v0361;
    env = stack[-3];
    fn = elt(env, 9); // cerror
    v0379 = (*qfn1(fn))(qenv(fn), v0379);
    nil = C_nil;
    if (exception_pending()) goto v0361;
    v0379 = nil;
    { popv(4); return onevalue(v0379); }

v0382:
    v0348 = stack[-1];
    v0380 = stack[0];
    v0379 = stack[-2];
    {
        popv(4);
        fn = elt(env, 10); // removeg2
        return (*qfnn(fn))(qenv(fn), 3, v0348, v0380, v0379);
    }

v0381:
    v0348 = stack[-1];
    v0380 = stack[0];
    v0379 = stack[-2];
    {
        popv(4);
        fn = elt(env, 11); // removeg1
        return (*qfnn(fn))(qenv(fn), 3, v0348, v0380, v0379);
    }

v0329:
    v0379 = qvalue(elt(env, 3)); // t
    goto v0237;

v0236:
    v0379 = qvalue(elt(env, 3)); // t
    goto v0237;
// error exit handlers
v0361:
    popv(4);
    return nil;
}



setup_type const u09_setup[] =
{
    {"token1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_token1},
    {"dp_sum",                  too_few_2,      CC_dp_sum,     wrong_no_2},
    {"pneg",                    CC_pneg,        too_many_1,    wrong_no_1},
    {"kernp",                   CC_kernp,       too_many_1,    wrong_no_1},
    {"conv:bf2i",               CC_convTbf2i,   too_many_1,    wrong_no_1},
    {"carx",                    too_few_2,      CC_carx,       wrong_no_2},
    {"comfac",                  CC_comfac,      too_many_1,    wrong_no_1},
    {"cl_susiminlevel",         too_few_2,      CC_cl_susiminlevel,wrong_no_2},
    {"ibalp_litlp",             CC_ibalp_litlp, too_many_1,    wrong_no_1},
    {"quotk",                   too_few_2,      CC_quotk,      wrong_no_2},
    {"ps:last-term",            CC_psTlastKterm,too_many_1,    wrong_no_1},
    {"initbrsea",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_initbrsea},
    {"take-impart",             CC_takeKimpart, too_many_1,    wrong_no_1},
    {"errorset2",               CC_errorset2,   too_many_1,    wrong_no_1},
    {"mv-pow-+",                too_few_2,      CC_mvKpowKL,   wrong_no_2},
    {"crprcd",                  CC_crprcd,      too_many_1,    wrong_no_1},
    {"wuorderp",                too_few_2,      CC_wuorderp,   wrong_no_2},
    {"freevarinexptchk",        CC_freevarinexptchk,too_many_1,wrong_no_1},
    {"searchtm",                CC_searchtm,    too_many_1,    wrong_no_1},
    {"ibalp_vequal",            too_few_2,      CC_ibalp_vequal,wrong_no_2},
    {"equal:",                  too_few_2,      CC_equalT,     wrong_no_2},
    {"testred",                 CC_testred,     too_many_1,    wrong_no_1},
    {"simpindexvar",            CC_simpindexvar,too_many_1,    wrong_no_1},
    {"dim<deg",                 CC_dimRdeg,     too_many_1,    wrong_no_1},
    {"opnum*",                  CC_opnumH,      too_many_1,    wrong_no_1},
    {"assert_analyze",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_assert_analyze},
    {"lambda_wrlijy187crc",     too_few_2,      CC_lambda_wrlijy187crc,wrong_no_2},
    {"*i2gi",                   CC_Hi2gi,       too_many_1,    wrong_no_1},
    {"exptf1",                  too_few_2,      CC_exptf1,     wrong_no_2},
    {"lalr_gensym",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_lalr_gensym},
    {"rmplus",                  CC_rmplus,      too_many_1,    wrong_no_1},
    {"ordpa",                   too_few_2,      CC_ordpa,      wrong_no_2},
    {"wulessp*",                too_few_2,      CC_wulesspH,   wrong_no_2},
    {"matrix+p",                CC_matrixLp,    too_many_1,    wrong_no_1},
    {"rat_sgn",                 CC_rat_sgn,     too_many_1,    wrong_no_1},
    {"objectom",                CC_objectom,    too_many_1,    wrong_no_1},
    {"ident",                   CC_ident,       too_many_1,    wrong_no_1},
    {"covposp",                 CC_covposp,     too_many_1,    wrong_no_1},
    {"statep*",                 CC_statepH,     too_many_1,    wrong_no_1},
    {"maprint",                 too_few_2,      CC_maprint,    wrong_no_2},
    {"split_ext",               too_few_2,      CC_split_ext,  wrong_no_2},
    {"sfto_qsub1",              too_few_2,      CC_sfto_qsub1, wrong_no_2},
    {"remflagss",               too_few_2,      CC_remflagss,  wrong_no_2},
    {"processcarpartitie1",     wrong_no_na,    wrong_no_nb,   (n_args *)CC_processcarpartitie1},
    {"ofsf_smwupdknowl",        wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_smwupdknowl},
    {"removeg",                 too_few_2,      CC_removeg,    wrong_no_2},
    {NULL, (one_args *)"u09", (two_args *)"3510 3978978 6477787", 0}
};

// end of generated code
